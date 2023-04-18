// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.1
// LVGL VERSION: 8.3.4
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_aq;
lv_obj_t *ui_airquality;
lv_obj_t *ui_symbol;
lv_obj_t *ui_index;
lv_obj_t *ui_footer;
lv_obj_t *ui_Label1;
lv_obj_t *ui_header;
lv_obj_t *ui_exchangerate1;
lv_obj_t *ui_wondollar;
lv_obj_t *ui_exchangeRate;
lv_obj_t *ui_battery;
lv_obj_t *ui_gauge;
lv_obj_t *ui_Bar2;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////

void ui_update_screen(int aqi, int exchange_rate, int battery_pct, const char *date)
{
	const lv_img_dsc_t *imgs[] = {
		&ui_img_stars_png,
		&ui_img_good_png,
		&ui_img_notgood_png,
		&ui_img_bad_png,
		&ui_img_verybad_png,
		&ui_img_dead_png,
	};
	const int aqimg = (aqi-1) / 50;
	char buf[8] = { 0, };
	snprintf(buf, sizeof(buf), "%d", aqi);

ui_aq = lv_obj_create(NULL);
lv_obj_clear_flag( ui_aq, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_airquality = lv_obj_create(ui_aq);
lv_obj_set_height( ui_airquality, 150);
lv_obj_set_width( ui_airquality, lv_pct(100));
lv_obj_set_align( ui_airquality, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_airquality, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_symbol = lv_img_create(ui_airquality);
lv_img_set_src(ui_symbol, imgs[aqimg]);
lv_obj_set_width( ui_symbol, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_symbol, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_symbol, 5 );
lv_obj_set_y( ui_symbol, -18 );
lv_obj_set_align( ui_symbol, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_symbol, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_symbol, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_index = lv_label_create(ui_airquality);
lv_obj_set_width( ui_index, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_index, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_index, 0 );
lv_obj_set_y( ui_index, 56 );
lv_obj_set_align( ui_index, LV_ALIGN_CENTER );
lv_label_set_text(ui_index, buf);
lv_obj_set_style_text_align(ui_index, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_index, &ui_font_Georgia30, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_footer = lv_obj_create(ui_aq);
lv_obj_set_height( ui_footer, 19);
lv_obj_set_width( ui_footer, lv_pct(100));
lv_obj_set_x( ui_footer, 0 );
lv_obj_set_y( ui_footer, 87 );
lv_obj_set_align( ui_footer, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_footer, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label1 = lv_label_create(ui_footer);
lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label1, 10 );
lv_obj_set_y( ui_Label1, 0 );
lv_obj_set_align( ui_Label1, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_Label1, date);

ui_header = lv_obj_create(ui_aq);
lv_obj_set_height( ui_header, 28);
lv_obj_set_width( ui_header, lv_pct(100));
lv_obj_set_x( ui_header, 0 );
lv_obj_set_y( ui_header, -83 );
lv_obj_set_align( ui_header, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_header, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_exchangerate1 = lv_obj_create(ui_header);
lv_obj_set_height( ui_exchangerate1, 28);
lv_obj_set_width( ui_exchangerate1, lv_pct(47));
lv_obj_set_x( ui_exchangerate1, -13 );
lv_obj_set_y( ui_exchangerate1, 0 );
lv_obj_set_align( ui_exchangerate1, LV_ALIGN_LEFT_MID );
lv_obj_clear_flag( ui_exchangerate1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_wondollar = lv_img_create(ui_exchangerate1);
lv_img_set_src(ui_wondollar, &ui_img_dollar_png);
lv_obj_set_width( ui_wondollar, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_wondollar, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_wondollar, -10 );
lv_obj_set_y( ui_wondollar, 0 );
lv_obj_set_align( ui_wondollar, LV_ALIGN_LEFT_MID );
lv_obj_add_flag( ui_wondollar, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_wondollar, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_exchangeRate = lv_label_create(ui_exchangerate1);
lv_obj_set_width( ui_exchangeRate, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_exchangeRate, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_exchangeRate, LV_ALIGN_RIGHT_MID );
snprintf(buf, sizeof(buf),  "%d", exchange_rate);
lv_label_set_text(ui_exchangeRate, buf);

ui_battery = lv_obj_create(ui_header);
lv_obj_set_height( ui_battery, 25);
lv_obj_set_width( ui_battery, lv_pct(40));
lv_obj_set_x( ui_battery, 10 );
lv_obj_set_y( ui_battery, 0 );
lv_obj_set_align( ui_battery, LV_ALIGN_RIGHT_MID );
lv_obj_clear_flag( ui_battery, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_gauge = lv_img_create(ui_battery);
lv_img_set_src(ui_gauge, &ui_img_battery_png);
lv_obj_set_width( ui_gauge, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_gauge, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_gauge, 15 );
lv_obj_set_y( ui_gauge, 0 );
lv_obj_set_align( ui_gauge, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_gauge, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_gauge, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Bar2 = lv_bar_create(ui_gauge);
lv_bar_set_range(ui_Bar2, 0,130);
lv_bar_set_value(ui_Bar2, battery_pct,LV_ANIM_OFF);
lv_obj_set_width( ui_Bar2, 30);
lv_obj_set_height( ui_Bar2, 16);
lv_obj_set_align( ui_Bar2, LV_ALIGN_CENTER );

lv_obj_set_style_bg_color(ui_Bar2, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Bar2, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Bar2, &ui_img_53718616, LV_PART_INDICATOR | LV_STATE_DEFAULT );

}

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_update_screen(0, 0, 0, "Booting...");
lv_disp_load_scr( ui_aq);
}
