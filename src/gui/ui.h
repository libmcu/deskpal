// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.1
// LVGL VERSION: 8.3.4
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "lvgl.h"

extern lv_obj_t *ui_aq;
extern lv_obj_t *ui_airquality;
extern lv_obj_t *ui_symbol;
extern lv_obj_t *ui_index;
extern lv_obj_t *ui_footer;
extern lv_obj_t *ui_Label1;
extern lv_obj_t *ui_header;
extern lv_obj_t *ui_exchangerate1;
extern lv_obj_t *ui_won1;
extern lv_obj_t *ui_dollar1;
extern lv_obj_t *ui_Label2;
extern lv_obj_t *ui_battery;
extern lv_obj_t *ui_gauge;
extern lv_obj_t *ui_Bar2;


LV_IMG_DECLARE( ui_img_stars_png);   // assets/good.png
LV_IMG_DECLARE( ui_img_good_png);   // assets/good.png
LV_IMG_DECLARE( ui_img_notgood_png);   // assets/good.png
LV_IMG_DECLARE( ui_img_bad_png);   // assets/good.png
LV_IMG_DECLARE( ui_img_verybad_png);   // assets/good.png
LV_IMG_DECLARE( ui_img_dead_png);   // assets/good.png
LV_IMG_DECLARE( ui_img_nobattery_png);   // assets/good.png
LV_IMG_DECLARE( ui_img_nowifi_png);   // assets/good.png
LV_IMG_DECLARE( ui_img_won_png);   // assets/won.png
LV_IMG_DECLARE( ui_img_dollar_png);   // assets/dollar.png
LV_IMG_DECLARE( ui_img_battery_png);   // assets/battery.png
LV_IMG_DECLARE( ui_img_53718616);   // assets/battery-full.png


LV_FONT_DECLARE( ui_font_Georgia30);


void ui_init(void);
void ui_update_screen(int aqi, int exchange_rate, int battery_pct, const char *date);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
