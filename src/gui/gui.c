#include "gui.h"
#include <time.h>
#include "ui_helpers.h"
#include "lvgl.h"
#include "libmcu/board.h"
#include "libmcu/logging.h"

static bool first_drawing = true; /* the first flush is always clearing screen. */

static void on_flush(lv_disp_drv_t *drv, const lv_area_t *area,
		lv_color_t *color_map)
{
	size_t len = ((area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1)) / 8;
	uint8_t *buf = (uint8_t *)color_map;

	info("%d %d %d %d %lu", area->x1, area->x2, area->y1, area->y2, len);

	if (!first_drawing) {
		gui_flush(buf);
	}

	lv_disp_flush_ready(drv);
	first_drawing = false;
}

static void set_pixel(lv_disp_drv_t *disp_drv, uint8_t *buf, lv_coord_t buf_w,
		lv_coord_t x, lv_coord_t y, lv_color_t color, lv_opa_t opa)
{
	uint16_t byte_index = (x >> 3u) + (y * (LV_VER_RES_MAX/8));
	uint8_t bit_index = x & 0x07u;

	if (color.full) {
		buf[byte_index] |= 1U << (7 - bit_index);
	} else {
		buf[byte_index] &= ~(1U << (7 - bit_index));
	}
}

static void initialize_lvgl(void)
{
	static lv_disp_drv_t disp_drv;
	static lv_disp_draw_buf_t disp_buf;
	static uint8_t buf1[LV_HOR_RES_MAX * LV_VER_RES_MAX * sizeof(lv_color_t)];
	static uint8_t buf2[LV_HOR_RES_MAX * LV_VER_RES_MAX * sizeof(lv_color_t)];

	lv_init();
	lv_disp_draw_buf_init(&disp_buf, (lv_color_t *)buf1, (lv_color_t *)buf2,
			LV_HOR_RES_MAX * LV_VER_RES_MAX);
	lv_disp_drv_init(&disp_drv);
	disp_drv.hor_res = LV_HOR_RES_MAX;
	disp_drv.ver_res = LV_VER_RES_MAX;
	disp_drv.flush_cb = on_flush;
	//disp_drv.drv_update_cb = on_drv_update;
	disp_drv.set_px_cb = set_pixel;
	disp_drv.draw_buf = &disp_buf;
	//disp_drv.rotated = LV_DISP_ROT_90;

	lv_disp_drv_register(&disp_drv);
}

void gui_step(const struct deskpal *deskpal)
{
	static uint32_t t0;
	uint32_t t1 = board_get_time_since_boot_ms();
	uint32_t elapsed = t1 - t0;

	if (deskpal) {
		struct tm tim;
		char timestr[32];
		strcpy(timestr, deskpal->air_quality.updated_time);
		if (strptime(timestr, "%Y-%m-%dT%H:%M:%S", &tim) != NULL) {
			strftime(timestr, sizeof(timestr), "%b %d, %Y at %H:%M",
					&tim);
		}

		ui_update_screen(deskpal->air_quality.aqi,
				deskpal->won_dollar_exchange_rate,
				deskpal->battery_pct, timestr);
		lv_disp_load_scr(ui_aq);
	}

	lv_tick_inc(elapsed);
	lv_timer_handler();

	t0 = t1;
}

void gui_init(void)
{
	gui_port_init();
	initialize_lvgl();
	//ui_init();
}
