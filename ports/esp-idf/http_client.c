#include "http_client.h"

#include "esp_http_client.h"
#include "esp_https_ota.h"
#include "esp_wifi.h"

#include "libmcu/logging.h"

#define MIN(a, b)		(((a) > (b))? (b) : (a))

static esp_err_t on_http_event(esp_http_client_event_t *evt)
{
	struct http_client_buffer *buf =
		(struct http_client_buffer *)evt->user_data;

	switch (evt->event_id) {
	case HTTP_EVENT_DISCONNECTED:
		debug("HTTP_EVENT_DISCONNECTED");
		break;
	case HTTP_EVENT_ON_CONNECTED:
		debug("HTTP_EVENT_ON_CONNECTED");
		break;
	case HTTP_EVENT_ON_HEADER:
		debug("key=%s, value=%s", evt->header_key, evt->header_value);
		break;
	case HTTP_EVENT_ON_DATA:
		debug("len=%d", evt->data_len);
		if (buf && buf->space) {
			size_t len = MIN(evt->data_len, buf->cap - buf->len);
			memcpy(&buf->space[buf->len], evt->data, len);
			buf->len += len;
		}
		break;
	case HTTP_EVENT_ON_FINISH:
		debug("HTTP_EVENT_ON_FINISH");
		break;
	case HTTP_EVENT_HEADER_SENT: /* fall through */
	case HTTP_EVENT_ERROR: /* fall through */
	default:
		break;
      }

	return ESP_OK;
}

struct http_client *http_client_create(const struct http_client_conn_param *param,
		struct http_client_buffer *buf)
{
	const esp_http_client_config_t config = {
		.event_handler = on_http_event,
		.url = param->addr,
		.timeout_ms = param->timeout_ms,
		.cert_pem = param->ca_cert,
		.client_cert_pem = param->client_cert,
		.client_key_pem = param->client_key,
		.user_data = buf,
	};

	esp_http_client_handle_t handle = esp_http_client_init(&config);

	return (struct http_client *)handle;
}

int http_client_request(struct http_client *handle,
		http_client_request_callback_t callback, void *ctx)
{
	esp_http_client_handle_t client = (esp_http_client_handle_t)handle;

	//esp_http_client_set_url(client, url);
	esp_http_client_set_method(client, HTTP_METHOD_GET);
	//esp_http_client_set_header(client, "Accept", "application/json");

	//esp_http_client_set_post_field(client, buffer, read_size);
	//esp_http_client_set_header(client, "Content-Type", "application/octet-stream");
	//esp_http_client_set_user_data(client, buf);

	esp_err_t err = esp_http_client_perform(client);

	const struct http_client_response response = {
		.status_code = (uint16_t)esp_http_client_get_status_code(client),
	};

	if (callback) {
		(*callback)(&response, ctx);
	}

	return err;
}

int http_client_destroy(struct http_client *handle)
{
	esp_http_client_handle_t client = (esp_http_client_handle_t)handle;
	esp_err_t err = esp_http_client_close(client);

	if (err == ESP_OK) {
		err = esp_http_client_cleanup(client);
	}

	return err;
}
