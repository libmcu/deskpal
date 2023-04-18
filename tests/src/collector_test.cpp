#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "collector.h"
#include "pwifi/wifi.h"
#include "http_client.h"
#include "libmcu/timext.h"

#if !defined(MIN)
#define MIN(a, b)		(((a) > (b))? (b) : (a))
#endif

#define DUMMY_AQI_RESPONSE	"{\"status\":\"ok\",\"data\":{\"aqi\":134,\"idx\":4497,\"attributions\":[{\"url\":\"https://www.airkorea.or.kr/\",\"name\":\"SouthAirKoreaEnvironmentCorporation(대기오염실시간공개시스템)\",\"logo\":\"SouthKorea-AirKorea.png\"},{\"url\":\"http://cleanair.seoul.go.kr/\",\"name\":\"SeoulCleanAirPollutionInformation(서울특별시기후대기환경정보)\",\"logo\":\"SouthKorea-Seoul.png\"},{\"url\":\"https://waqi.info/\",\"name\":\"WorldAirQualityIndexProject\"}],\"city\":{\"geo\":[37.482867,127.035621],\"name\":\"Yangjaejungangcharo,Seoul,SouthKorea(강남대로서울)\",\"url\":\"https://aqicn.org/city/korea/seoul/yangjaejungangcharo\",\"location\":\"\"},\"dominentpol\":\"pm25\",\"iaqi\":{\"co\":{\"v\":8.9},\"dew\":{\"v\":-1},\"h\":{\"v\":69},\"no2\":{\"v\":52.2},\"o3\":{\"v\":8},\"p\":{\"v\":1020.3},\"pm10\":{\"v\":69},\"pm25\":{\"v\":134},\"so2\":{\"v\":4.3},\"t\":{\"v\":4},\"w\":{\"v\":1},\"wg\":{\"v\":1}},\"time\":{\"s\":\"2023-03-3106:00:00\",\"tz\":\"+09:00\",\"v\":1680242400,\"iso\":\"2023-03-31T06:00:00+09:00\"},"
#define DUMMY_XCHG_RESPONSE	"[{\"code\":\"FRX.KRWUSD\",\"currencyCode\":\"USD\",\"currencyName\":\"달러\",\"country\":\"미국\",\"name\":\"미국(KRW/USD)\",\"date\":\"2023-03-30\",\"time\":\"23:58:00\",\"recurrenceCount\":587,\"basePrice\":1298,\"openingPrice\":1299.3,\"highPrice\":1310.2,\"lowPrice\":1297.6,\"change\":\"FALL\",\"changePrice\":7,\"cashBuyingPrice\":1320.71,\"cashSellingPrice\":1275.29,\"ttBuyingPrice\":1285.3,\"ttSellingPrice\":1310.7,\"tcBuyingPrice\":null,\"fcSellingPrice\":null,\"exchangeCommission\":6.657,\"usDollarRate\":1,\"high52wPrice\":1445,\"high52wDate\":\"2022-10-13\",\"low52wPrice\":1216.6,\"low52wDate\":\"2023-02-02\",\"currencyUnit\":1,\"provider\":\"하나은행\",\"timestamp\":1680201834074,\"id\":79,\"modifiedAt\":\"2023-03-30T18:43:54.000+0000\",\"createdAt\":\"2016-10-21T06:13:34.000+0000\",\"signedChangePrice\":-7,\"changeRate\":0.0053639847,\"signedChangeRate\":-0.0053639847}]"

static wifi_event_callback_t wifi_callback;
static struct http_client_buffer *wifi_buffer;
static bool is_aqi_requst;

static int fake_wifi_enable(struct wifi *iface) {
	return mock().actualCall(__func__)
		.withParameter("iface", iface)
		.returnIntValue();
}

static int fake_wifi_register_event_callback(struct wifi *iface, const wifi_event_callback_t cb) {
	wifi_callback = cb;

	return mock().actualCall(__func__)
		.withParameter("iface", iface)
		.withParameter("cb", cb)
		.returnIntValue();
}

static int fake_wifi_connect(struct wifi *iface, const struct wifi_conn_param *param) {
	return mock().actualCall(__func__)
		.withParameter("iface", iface)
		.withParameter("param", param)
		.returnIntValue();
}

struct wifi *fake_wifi_create(void) {
	return (struct wifi *)mock().actualCall(__func__).returnPointerValue();
}

struct http_client *http_client_create(const struct http_client_conn_param *param,
		struct http_client_buffer *buf) {
	wifi_buffer = buf;

	if (strncmp(param->addr, "https://api.waqi.info", 21) == 0) {
		is_aqi_requst = true;
	} else {
		is_aqi_requst = false;
	}

	return (struct http_client *)mock().actualCall(__func__)
		.withParameter("param", param)
		.withParameter("buf", buf)
		.returnPointerValue();
}

int http_client_request(struct http_client *handle,
		http_client_request_callback_t callback, void *ctx) {
	if (wifi_buffer && wifi_buffer->space) {
		const char *resp;

		if (is_aqi_requst) {
			resp = DUMMY_AQI_RESPONSE;
		} else {
			resp = DUMMY_XCHG_RESPONSE;
		}

		size_t len = MIN(wifi_buffer->cap, strlen(resp));
		memcpy(&wifi_buffer->space[wifi_buffer->len], resp, len);
		wifi_buffer->len = len;
	}

	return mock().actualCall(__func__)
		.withParameter("handle", handle)
		.withParameter("callback", callback)
		.withParameter("ctx", ctx)
		.returnIntValue();
}

int http_client_destroy(struct http_client *handle) {
	return mock().actualCall(__func__)
		.withParameter("handle", handle)
		.returnIntValue();
}

void timeout_set(unsigned long *goal, unsigned long msec) {
	mock().actualCall(__func__).withParameter("msec", msec);
	*goal += msec;
}

bool timeout_is_expired(unsigned long goal) {
	return mock().actualCall(__func__).withParameter("goal", goal)
		.returnBoolValue();
}

TEST_GROUP(Collector) {
	struct wifi wifi;
	uint8_t buffer[8192];

	void setup(void) {
		wifi_callback = NULL;
		wifi_buffer = NULL;
		wifi = (struct wifi) {
			.api = {
				.enable = fake_wifi_enable,
				.connect = fake_wifi_connect,
				.register_event_callback = fake_wifi_register_event_callback,
			},
		};

		collector_init();
	}
	void teardown(void) {
		mock().checkExpectations();
		mock().clear();
	}

	void connect_to_wifi(void) {
		mock().expectOneCall("fake_wifi_create")
			.andReturnValue((void *)&wifi);
		mock().expectOneCall("fake_wifi_register_event_callback")
			.ignoreOtherParameters()
			.andReturnValue(0);
		mock().expectOneCall("fake_wifi_enable")
			.ignoreOtherParameters().andReturnValue(0);

		LONGS_EQUAL(COLLECTOR_BUSY, collector_aggregate(0));

		(*wifi_callback)(0, WIFI_EVT_STARTED, 0);

		mock().expectOneCall("fake_wifi_connect")
			.ignoreOtherParameters().andReturnValue(0);

		LONGS_EQUAL(COLLECTOR_BUSY, collector_aggregate(0));

		(*wifi_callback)(0, WIFI_EVT_CONNECTED, 0);
	}
};

TEST(Collector, ShouldReturnFault_WhenNoWiFiInterfaceExists) {
	mock().expectOneCall("fake_wifi_create").andReturnValue((void *)NULL);
	LONGS_EQUAL(COLLECTOR_FAULT, collector_aggregate(0));
}

TEST(Collector, ShouldReturnFault_WhenRegisteringEventCallbackFailed) {
	mock().expectOneCall("fake_wifi_create").andReturnValue((void *)&wifi);
	mock().expectOneCall("fake_wifi_register_event_callback")
		.ignoreOtherParameters()
		.andReturnValue(-1);
	LONGS_EQUAL(COLLECTOR_FAULT, collector_aggregate(0));
}

TEST(Collector, ShouldReturnFault_WhenEnablingWifiFailed) {
	mock().expectOneCall("fake_wifi_create").andReturnValue((void *)&wifi);
	mock().expectOneCall("fake_wifi_register_event_callback")
		.ignoreOtherParameters()
		.andReturnValue(0);
	mock().expectOneCall("fake_wifi_enable")
		.ignoreOtherParameters().andReturnValue(-1);
	LONGS_EQUAL(COLLECTOR_FAULT, collector_aggregate(0));
}

TEST(Collector, ShouldReturnBusy_WhenWiFiBeingReady) {
	mock().expectOneCall("fake_wifi_create").andReturnValue((void *)&wifi);
	mock().expectOneCall("fake_wifi_register_event_callback")
		.ignoreOtherParameters()
		.andReturnValue(0);
	mock().expectOneCall("fake_wifi_enable")
		.ignoreOtherParameters().andReturnValue(0);
	LONGS_EQUAL(COLLECTOR_BUSY, collector_aggregate(0));
}

TEST(Collector, ShouldReturnBusy_WhenNotInPeriod) {
	connect_to_wifi();

	mock().expectOneCall("timeout_is_expired")
		.ignoreOtherParameters()
		.andReturnValue(false);

	LONGS_EQUAL(COLLECTOR_BUSY, collector_aggregate(0));
}

TEST(Collector, ShouldReturnInvalid_WhenNullParamGiven) {
	connect_to_wifi();

	mock().expectOneCall("timeout_is_expired")
		.ignoreOtherParameters().andReturnValue(true);
	mock().expectOneCall("timeout_set").ignoreOtherParameters();
	mock().expectNCalls(2, "http_client_create")
		.ignoreOtherParameters().andReturnValue((void *)0);
	mock().expectNCalls(2, "http_client_request")
		.ignoreOtherParameters().andReturnValue(0);
	mock().expectNCalls(2, "http_client_destroy")
		.ignoreOtherParameters().andReturnValue(0);

	LONGS_EQUAL(COLLECTOR_INVALID, collector_aggregate(0));
}

TEST(Collector, ShouldReturnSuccess_WhenAllProperlyGiven) {
	struct deskpal result;
	connect_to_wifi();

	mock().expectOneCall("timeout_is_expired")
		.ignoreOtherParameters().andReturnValue(true);
	mock().expectOneCall("timeout_set").ignoreOtherParameters();
	mock().expectNCalls(2, "http_client_create")
		.ignoreOtherParameters().andReturnValue((void *)0);
	mock().expectNCalls(2, "http_client_request")
		.ignoreOtherParameters().andReturnValue(0);
	mock().expectNCalls(2, "http_client_destroy")
		.ignoreOtherParameters().andReturnValue(0);

	LONGS_EQUAL(COLLECTOR_SUCCESS, collector_aggregate(&result));
}
