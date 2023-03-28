#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "libmcu/timext.h"

#if defined(esp32)
#define LCD_HOST		HSPI_HOST
#else
#define LCD_HOST		SPI2_HOST
#endif

#define PIN_SCLK		12
#define PIN_MOSI		11
#define PIN_CS			10
#define PIN_DC			37
#define PIN_RST			38
#define PIN_BUSY		2

#define HEIGHT			200
#define WIDTH			200

static spi_device_handle_t spi_handle;

static void reset_panel(void)
{
	gpio_set_level(PIN_RST, 1);
	sleep_ms(200);
	gpio_set_level(PIN_RST, 0);
	sleep_ms(2);
	gpio_set_level(PIN_RST, 1);
	sleep_ms(200);
}

static bool is_busy(void)
{
	return gpio_get_level(PIN_BUSY);
}

static void send_command(const uint8_t cmd)
{
	spi_transaction_t t = {
		.length = 8,
		.tx_buffer = &cmd,
		.user = (void *)0,
	};

	if (spi_device_polling_transmit(spi_handle, &t) != ESP_OK) {
	}
}

static void send_data_byte(const uint8_t data)
{
	spi_transaction_t t = {
		.length = 8,
		.tx_buffer = &data,
		.user = (void *)1,
	};

	if (spi_device_polling_transmit(spi_handle, &t) != ESP_OK) {
	}
}

static void send_data(const uint8_t *data, size_t len)
{
	if (!data || len == 0) {
		return;
	}

	spi_transaction_t t = {
		.length = len * 8,
		.tx_buffer = data,
		.user = (void *)1,
	};

	if (spi_device_polling_transmit(spi_handle, &t) != ESP_OK) {
	}
}

static void epd_start(void)
{
	reset_panel();

	send_command(0x01);
	send_data_byte((HEIGHT - 1) & 0xff);
	send_data_byte(((HEIGHT - 1) >> 8) & 0xff);
	send_data_byte(0x00);

	send_command(0x0C);
	send_data_byte(0xD7);
	send_data_byte(0xD6);
	send_data_byte(0x9D);

	send_command(0x2C);
	send_data_byte(0xA8);

	send_command(0x3A);
	send_data_byte(0x1A);

	send_command(0x3B);
	send_data_byte(0x08);

	send_command(0x11);
	send_data_byte(0x03);

	send_command(0x32);
#if 1
	const uint8_t lut_full_update[] = {
		0x02, 0x02, 0x01, 0x11, 0x12, 0x12, 0x22, 0x22,
		0x66, 0x69, 0x69, 0x59, 0x58, 0x99, 0x99, 0x88,
		0x00, 0x00, 0x00, 0x00, 0xF8, 0xB4, 0x13, 0x51,
		0x35, 0x51, 0x51, 0x19, 0x01, 0x00
	};
	send_data(lut_full_update, sizeof(lut_full_update));
#else
	const uint8_t lut_partial_update[] = {
		0x10, 0x18, 0x18, 0x08, 0x18, 0x18, 0x08, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x13, 0x14, 0x44, 0x12,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	send_data(lut_partial_update, sizeof(lut_partial_update));
#endif
}

static void full_update(uint8_t *buf)
{
	// window
	send_command(0x44); // x pos
	send_data_byte(0); // x start
	send_data_byte(WIDTH >> 3); // x end

	send_command(0x45); // y pos
	send_data_byte(0); // y start
	send_data_byte(0); // y start
	send_data_byte(HEIGHT & 0xff); // y end
	send_data_byte(HEIGHT >> 8); // y end

	// set pixel with cursor
	for (int y = 0; y < HEIGHT; y++) {
		send_command(0x4E); // cursor
		send_data_byte(0x00); // x start
		send_command(0x4F); // cursor
		send_data_byte(y & 0xff); // y start
		send_data_byte(y >> 8); // y start

		send_command(0x24);
		for (int x = 0; x < WIDTH/8; x++) {
			send_data_byte(*buf++);
		}
	}

	// draw
	send_command(0x22);
	send_data_byte(0xC4);
	send_command(0x20);
	send_command(0xFF);

	while (is_busy());
}

static void initialize_gpio(void)
{
	gpio_config_t io_conf = {
		.intr_type = GPIO_INTR_DISABLE,
		.mode = GPIO_MODE_OUTPUT,
		.pin_bit_mask = (1ULL << PIN_CS) | (1ULL << PIN_DC) | (1ULL << PIN_RST),
	};
	gpio_config(&io_conf);

	io_conf.mode = GPIO_MODE_INPUT;
	io_conf.pin_bit_mask = 1ULL << PIN_BUSY;
	gpio_config(&io_conf);
}

static void lcd_spi_pre_transfer_callback(spi_transaction_t *t)
{
	int dc = (int)t->user;
	gpio_set_level(PIN_DC, dc);
}

void gui_flush(void *ctx)
{
	full_update(ctx);
}

void gui_hw_init(void)
{
	initialize_gpio();

	spi_bus_config_t buscfg = {
		.miso_io_num = -1,
		.mosi_io_num = PIN_MOSI,
		.sclk_io_num = PIN_SCLK,
		.quadwp_io_num = -1,
		.quadhd_io_num = -1,
	};
	esp_err_t ret = spi_bus_initialize(LCD_HOST, &buscfg, SPI_DMA_CH_AUTO);
	ESP_ERROR_CHECK(ret);

	spi_device_interface_config_t devcfg = {
		.clock_speed_hz = 1*1000*1000,
		.mode = 0,
		.spics_io_num = PIN_CS,
		.queue_size = 1,
		.pre_cb = lcd_spi_pre_transfer_callback,
	};

	ret = spi_bus_add_device(LCD_HOST, &devcfg, &spi_handle);
	ESP_ERROR_CHECK(ret);

	epd_start();
}
