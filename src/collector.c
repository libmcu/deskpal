#include "collector.h"

#include <semaphore.h>
#include <string.h>
#include <stdbool.h>

#include "pwifi/wifi.h"
#include "http_client.h"
#include "jsmn.h"

#include "libmcu/logging.h"
#include "libmcu/assert.h"

#define DEFAULT_SSID		""
#define DEFAULT_PASS		""

#define AQI_TOKEN		""
#define AQI_URL			"https://api.waqi.info/feed/@4497/?token="AQI_TOKEN
#define XCHG_URL		"https://quotation-api-cdn.dunamu.com/v1/forex/recent?codes=FRX.KRWUSD"

#define REQUEST_TIMEOUT_MS	5000UL

#if !defined(MAX)
#define MAX(a, b)		(((a) < (b))? (b) : (a))
#endif
#if !defined(MIN)
#define MIN(a, b)		(((a) > (b))? (b) : (a))
#endif

static volatile enum status {
	NET_UNKNOWN,
	NET_INITIALIZED,
	NET_ASSOCIATING,
	NET_ASSOCIATED,
	NET_MAX,
} current_status;

typedef void (*http_response_callback_t)
	(const struct http_client_buffer *response, void *ctx);

static struct wifi *wifi_iface;

static void set_status(enum status new_status)
{
	current_status = new_status;
}

static enum status status(void)
{
	return current_status;
}

static void print_scan_result(const struct wifi_scan_result *entry)
{
	(void)entry;
}

static void on_wifi_events(const struct wifi *iface,
			   enum wifi_event evt, const void *data)
{
	unused(iface);

	switch (evt) {
	case WIFI_EVT_SCAN_RESULT:
		print_scan_result((const struct wifi_scan_result *)data);
		break;
	case WIFI_EVT_SCAN_DONE: /* fall through */
		break;
	case WIFI_EVT_STARTED: /* fall through */
		set_status(NET_INITIALIZED);
		break;
	case WIFI_EVT_DISCONNECTED: /* fall through */
		set_status(NET_INITIALIZED);
		break;
	case WIFI_EVT_CONNECTED: /* fall through */
		set_status(NET_ASSOCIATED);
		break;
	default:
		info("WIFI event: %x", evt);
		break;
	}
}

static collector_err_t initialize(void *ctx)
{
	unused(ctx);

	if (status() != NET_UNKNOWN) {
		return COLLECTOR_UNKNOWN_STATE;
	}

	if ((wifi_iface = wifi_create_default()) == NULL) {
		error("No WiFi");
		return COLLECTOR_FAULT;
	}

	if (wifi_register_event_callback(wifi_iface, on_wifi_events) != 0) {
		return COLLECTOR_FAULT;
	}

	if (wifi_enable(wifi_iface) != 0) {
		return COLLECTOR_FAULT;
	}

	set_status(NET_INITIALIZED);

	return COLLECTOR_BUSY;
}

static collector_err_t associate_with_ap(void *ctx)
{
	unused(ctx);

	if (status() != NET_INITIALIZED) {
		return COLLECTOR_UNKNOWN_STATE;
	}

	struct wifi_conn_param param = {
		.ssid = (const uint8_t *)DEFAULT_SSID,
		.ssid_len = (uint8_t)(sizeof(DEFAULT_SSID)-1),
		.psk = (const uint8_t *)DEFAULT_PASS,
		.psk_len = sizeof(DEFAULT_PASS)-1,
		.security = WIFI_SEC_TYPE_PSK,
	};

	wifi_connect(wifi_iface, &param);

	set_status(NET_ASSOCIATING);

	return COLLECTOR_BUSY;
}

static void on_http_response(const struct http_client_response *response, void *ctx)
{
	debug("HTTP status code=%u", response->status_code);
}

static void request_get(const char *url, uint32_t timeout_ms,
		http_response_callback_t callback, void *ctx)
{
	static uint8_t tmp[1024];
	static struct http_client_buffer buf = {
		.space = tmp,
		.cap = sizeof(tmp),
	};

	buf.len = 0;

	struct http_client *client =
		http_client_create(&(const struct http_client_conn_param) {
				.addr = url,
				.timeout_ms = timeout_ms,
			}, &buf);
	http_client_request(client, on_http_response, 0);
	http_client_destroy(client);

	if (callback) {
		(*callback)(&buf, ctx);
	}
}

static bool proc_aqi(const char *key, int key_len,
		const char *value, int value_len, void *ctx)
{
	struct air_quality *air_quality = (struct air_quality *)ctx;

	if (strncmp(key, "status", (size_t)MAX(key_len, 6)) == 0 &&
			strncmp(value, "ok", (size_t)MAX(value_len, 2))) {
		/* stop parsing if status is not ok */
		return true;
	}

	if (strncmp(key, "aqi", (size_t)MAX(key_len, 3)) == 0) {
		air_quality->aqi = (uint16_t)strtol(value, 0, 10);
		return false;
	}

	if (strncmp(key, "iso", (size_t)MAX(key_len, 3)) == 0) {
		strncpy(air_quality->updated_time, value, MIN(value_len,
				(int)sizeof(air_quality->updated_time)));
		return true;
	}

	return false;
}

static bool proc_xchg(const char *key, int key_len,
		const char *value, int value_len, void *ctx)
{
	if (strncmp(key, "basePrice", (size_t)MAX(key_len, 9)) == 0) {
		uint32_t *rate = (uint32_t *)ctx;
		*rate = (uint32_t)strtol(value, 0, 10);
		return true;
	}

	return false;
}

static void parse_json(const char *json, size_t json_len,
		bool (*proc)(const char *key, int key_len,
				const char *value, int value_len, void *ctx),
		void *ctx)
{
	static jsmntok_t tokens[128];
	int max_token_len = (int)(sizeof(tokens) / sizeof(*tokens));
	jsmn_parser parser;
	jsmn_init(&parser);

	int nr_token = jsmn_parse(&parser, json, json_len,
			tokens, (unsigned int)max_token_len);
	if (nr_token <= 0) {
		if (nr_token != JSMN_ERROR_PART) {
			return;
		}
		nr_token = max_token_len;
	}

	for (int i = 0; i < nr_token; i++) {
		if (tokens[i].type != JSMN_STRING || tokens[i].size < 1) {
			continue;
		}

		const char *key = &json[tokens[i].start];
		int key_len = tokens[i].end - tokens[i].start;
		const char *value = &json[tokens[i+1].start];
		int value_len = tokens[i+1].end - tokens[i+1].start;

		if ((*proc)(key, key_len, value, value_len, ctx)) {
			break;
		}
	}
}

static void on_aiq_response(const struct http_client_buffer *response, void *ctx)
{
	struct air_quality *air_quality = (struct air_quality *)ctx;
	air_quality->aqi = 0;

	if (response->len) {
		parse_json((const char *)response->space, response->len,
				proc_aqi, ctx);
	}
}

static void on_xchg_response(const struct http_client_buffer *response, void *ctx)
{
	uint32_t *xchg = (uint32_t *)ctx;
	*xchg = 0;

	if (response->len) {
		parse_json((const char *)response->space, response->len,
				proc_xchg, ctx);
	}
}

static uint16_t get_air_quality(struct air_quality *air_quality)
{
	request_get(AQI_URL, REQUEST_TIMEOUT_MS, on_aiq_response, air_quality);
	return air_quality->aqi;
}

static uint32_t get_exchange_rate(void)
{
	uint32_t xchg_rate;
	request_get(XCHG_URL, REQUEST_TIMEOUT_MS, on_xchg_response, &xchg_rate);
	return xchg_rate;
}

static collector_err_t collect(void *ctx)
{
	struct deskpal *deskpal = (struct deskpal *)ctx;
	uint16_t aqi = get_air_quality(&deskpal->air_quality);
	uint32_t xchg_rate = get_exchange_rate();

	if (!deskpal || !aqi || !xchg_rate) {
		return COLLECTOR_INVALID;
	}

	deskpal->air_quality.aqi = aqi;
	deskpal->won_dollar_exchange_rate = xchg_rate;

	return COLLECTOR_SUCCESS;
}

static collector_err_t do_nothing(void *ctx)
{
	unused(ctx);
	return COLLECTOR_BUSY;
}

collector_err_t collector_aggregate(struct deskpal *deskpal)
{
	collector_err_t (*run[NET_MAX])(void *ctx) = {
		initialize,
		associate_with_ap,
		do_nothing,
		collect,
	};

	assert(status() < NET_MAX);
	return run[status()](deskpal);
}

void collector_init(void)
{
	set_status(NET_UNKNOWN);
}
