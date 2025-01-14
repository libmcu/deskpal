/*******************************************************************************
 * Size: 30 px
 * Bpp: 1
 * Opts: --bpp 1 --size 30 --font /Users/kwon/SquareLine/assets/georgia bold.ttf -o /Users/kwon/SquareLine/assets/ui_font_Georgia30.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_GEORGIA30
#define UI_FONT_GEORGIA30 1
#endif

#if UI_FONT_GEORGIA30

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x23, 0xbf, 0xff, 0xff, 0xee, 0x73, 0x9c, 0xe2,
    0x10, 0x80, 0x3, 0xbf, 0xff, 0xb8,

    /* U+0022 "\"" */
    0x70, 0xef, 0x9f, 0xf9, 0xff, 0x9f, 0xf9, 0xf7,
    0xe, 0x70, 0xe7, 0xe, 0x20, 0x42, 0x4,

    /* U+0023 "#" */
    0x1, 0xc6, 0x0, 0xc3, 0x0, 0x63, 0x80, 0x31,
    0x80, 0x38, 0xc0, 0x18, 0x61, 0xff, 0xfe, 0xff,
    0xff, 0x6, 0x18, 0x3, 0x1c, 0x3, 0x8c, 0x1,
    0x86, 0xf, 0xff, 0xf7, 0xff, 0xf8, 0x61, 0x80,
    0x31, 0xc0, 0x18, 0xc0, 0x18, 0x60, 0xc, 0x30,
    0x0,

    /* U+0024 "$" */
    0x0, 0x80, 0x0, 0x80, 0x0, 0x80, 0x0, 0x80,
    0x7, 0xf8, 0x1c, 0x8e, 0x38, 0x9f, 0x70, 0x9f,
    0x70, 0x9f, 0x78, 0x8e, 0x7c, 0x80, 0x7f, 0xf0,
    0x7f, 0xfc, 0x3f, 0xfe, 0xf, 0xfe, 0x0, 0xff,
    0x70, 0x8f, 0xf8, 0x87, 0xf8, 0x87, 0xf8, 0x86,
    0x78, 0x8e, 0x38, 0x9c, 0xf, 0xf0, 0x0, 0x80,
    0x0, 0x80, 0x0, 0x80, 0x0, 0x80,

    /* U+0025 "%" */
    0x4, 0x0, 0x0, 0x3f, 0x80, 0x1c, 0x71, 0xc0,
    0x38, 0xf1, 0xe0, 0x70, 0xf1, 0xe0, 0xe0, 0xf1,
    0xe0, 0xc0, 0xf1, 0xe1, 0x80, 0xf1, 0xe3, 0x80,
    0x71, 0xc7, 0x0, 0x3b, 0x8e, 0x0, 0x1f, 0xc,
    0x0, 0x0, 0x18, 0x0, 0x0, 0x31, 0xf8, 0x0,
    0x73, 0x9c, 0x0, 0xe7, 0xe, 0x1, 0xcf, 0xf,
    0x1, 0x8f, 0xf, 0x3, 0xf, 0xf, 0x6, 0xf,
    0xf, 0xe, 0xf, 0xf, 0x1c, 0x7, 0x9e, 0x38,
    0x3, 0xfc, 0x0, 0x0, 0x40,

    /* U+0026 "&" */
    0x0, 0x0, 0x0, 0xf, 0xe0, 0x0, 0x3c, 0x20,
    0x0, 0xf8, 0x60, 0x1, 0xf0, 0xc0, 0x3, 0xe1,
    0x80, 0x7, 0xe3, 0x0, 0xf, 0xcc, 0x0, 0xf,
    0xf0, 0x0, 0xf, 0xc3, 0xfc, 0xf, 0x81, 0xe0,
    0x7f, 0x83, 0x83, 0xdf, 0x86, 0xf, 0x1f, 0x88,
    0x1e, 0x1f, 0x30, 0x7c, 0x3f, 0x40, 0xf8, 0x3f,
    0x81, 0xf0, 0x3f, 0x3, 0xf0, 0x3f, 0x3, 0xf0,
    0x7f, 0x7, 0xff, 0xff, 0x7, 0xfc, 0x7f, 0xc0,
    0x80, 0x0, 0x0,

    /* U+0027 "'" */
    0x77, 0xff, 0xff, 0xb9, 0xce, 0x21, 0x0,

    /* U+0028 "(" */
    0x0, 0x20, 0x3c, 0x1e, 0x7, 0x81, 0xe0, 0x78,
    0xf, 0x3, 0xe0, 0x78, 0xf, 0x3, 0xe0, 0x7c,
    0xf, 0x81, 0xf0, 0x3e, 0x7, 0xc0, 0xf8, 0x1f,
    0x3, 0xe0, 0x3c, 0x7, 0xc0, 0x78, 0xf, 0x0,
    0xf0, 0xe, 0x0, 0xe0, 0xf, 0x80, 0x30,

    /* U+0029 ")" */
    0x80, 0x1e, 0x0, 0xf0, 0xf, 0x0, 0xf0, 0xf,
    0x1, 0xe0, 0x3e, 0x3, 0xc0, 0x78, 0xf, 0x81,
    0xf0, 0x3e, 0x7, 0xc0, 0xf8, 0x1f, 0x3, 0xe0,
    0x7c, 0xf, 0x81, 0xe0, 0x7c, 0xf, 0x1, 0xe0,
    0x78, 0xe, 0x3, 0x83, 0xe0, 0x60, 0x0,

    /* U+002A "*" */
    0x0, 0x1, 0x8c, 0x1d, 0xc0, 0xd8, 0x5, 0xf,
    0xaf, 0xff, 0xf0, 0x50, 0xd, 0x81, 0xdc, 0x18,
    0xc0, 0x0,

    /* U+002B "+" */
    0x1, 0x80, 0x1, 0x80, 0x1, 0x80, 0x1, 0x80,
    0x1, 0x80, 0x1, 0x80, 0x1, 0x80, 0x1, 0x80,
    0xff, 0xff, 0xff, 0xff, 0x1, 0x80, 0x1, 0x80,
    0x1, 0x80, 0x1, 0x80, 0x1, 0x80, 0x1, 0x80,
    0x1, 0x80,

    /* U+002C "," */
    0x73, 0xef, 0xff, 0x7c, 0x30, 0x86, 0x33, 0x80,
    0x0,

    /* U+002D "-" */
    0xff, 0xff, 0xff, 0xe0,

    /* U+002E "." */
    0x7b, 0xff, 0xff, 0xfd, 0xe0,

    /* U+002F "/" */
    0x0, 0x38, 0x1, 0xc0, 0xc, 0x0, 0xe0, 0x7,
    0x0, 0x30, 0x3, 0x80, 0x1c, 0x0, 0xc0, 0xe,
    0x0, 0x70, 0x3, 0x0, 0x38, 0x1, 0xc0, 0xc,
    0x0, 0xe0, 0x7, 0x0, 0x30, 0x3, 0x80, 0x1c,
    0x0, 0xc0, 0xe, 0x0, 0x70, 0x3, 0x0, 0x38,
    0x1, 0xc0, 0xc, 0x0, 0xe0, 0x7, 0x0, 0x30,
    0x0,

    /* U+0030 "0" */
    0x3, 0xf0, 0x3, 0x87, 0x1, 0xc0, 0xe0, 0xf0,
    0x3c, 0x7c, 0xf, 0x9e, 0x1, 0xef, 0x80, 0x7f,
    0xe0, 0x1f, 0xf8, 0x7, 0xfe, 0x1, 0xff, 0x80,
    0x7f, 0xe0, 0x1f, 0xf8, 0x7, 0xde, 0x1, 0xe7,
    0x80, 0x79, 0xf0, 0x3e, 0x3c, 0xf, 0x7, 0x87,
    0x80, 0x7f, 0x80, 0x3, 0x0,

    /* U+0031 "1" */
    0x3, 0x80, 0x78, 0xf, 0x8f, 0xf8, 0xf, 0x80,
    0xf8, 0xf, 0x80, 0xf8, 0xf, 0x80, 0xf8, 0xf,
    0x80, 0xf8, 0xf, 0x80, 0xf8, 0xf, 0x80, 0xf8,
    0xf, 0x81, 0xfc, 0xff, 0xf0,

    /* U+0032 "2" */
    0xf, 0xe0, 0x30, 0xf8, 0x78, 0x7c, 0xf8, 0x3e,
    0xf8, 0x3e, 0xf8, 0x3e, 0x20, 0x3e, 0x0, 0x3e,
    0x0, 0x7c, 0x0, 0xfc, 0x1, 0xf0, 0x3, 0xe0,
    0x7, 0x80, 0xe, 0x0, 0x30, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

    /* U+0033 "3" */
    0x7, 0xe0, 0x18, 0x78, 0x3c, 0x7c, 0x7c, 0x3e,
    0x7c, 0x3e, 0x7c, 0x3e, 0x38, 0x3e, 0x0, 0x3e,
    0x0, 0x7c, 0x0, 0xf8, 0x7, 0xe0, 0x7, 0xf8,
    0x0, 0x7e, 0x0, 0x3e, 0x0, 0x1f, 0x0, 0x1f,
    0xf8, 0x1f, 0xf8, 0x1f, 0xf8, 0x1e, 0xf8, 0x3c,
    0x70, 0x78, 0x1f, 0xe0,

    /* U+0034 "4" */
    0x0, 0x3e, 0x0, 0xf, 0x80, 0x7, 0xe0, 0x3,
    0xf8, 0x1, 0xbe, 0x0, 0xcf, 0x80, 0x33, 0xe0,
    0x18, 0xf8, 0xc, 0x3e, 0x6, 0xf, 0x83, 0x3,
    0xe0, 0xc0, 0xf8, 0x60, 0x3e, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x0, 0x3e, 0x0, 0xf,
    0x80, 0x3, 0xe0, 0x0, 0xf8, 0x0, 0x3e, 0x0,
    0xf, 0x80,

    /* U+0035 "5" */
    0x1f, 0xfe, 0x1f, 0xfe, 0x3f, 0xfe, 0x3f, 0xfe,
    0x30, 0x0, 0x30, 0x0, 0x30, 0x0, 0x20, 0x0,
    0x2f, 0xf0, 0x30, 0x7c, 0x60, 0x3e, 0x0, 0x1e,
    0x0, 0x1f, 0x0, 0x1f, 0x20, 0x1f, 0xf8, 0x1f,
    0xf8, 0x1f, 0xf8, 0x3e, 0x78, 0x3c, 0x30, 0xf8,
    0xf, 0xe0,

    /* U+0036 "6" */
    0x0, 0x38, 0x1, 0xf8, 0x3, 0xc0, 0xf, 0x0,
    0x1e, 0x0, 0x3e, 0x0, 0x3c, 0x0, 0x7c, 0x0,
    0x79, 0xf8, 0xfb, 0xfc, 0xfc, 0x7e, 0xf8, 0x3e,
    0xf8, 0x1f, 0xf8, 0x1f, 0xf8, 0x1f, 0xf8, 0x1f,
    0x78, 0x1f, 0x78, 0x1e, 0x3c, 0x3e, 0x1c, 0x3c,
    0xf, 0xf0, 0x1, 0x0,

    /* U+0037 "7" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xec,
    0x0, 0xd8, 0x3, 0x20, 0x6, 0x0, 0x18, 0x0,
    0x20, 0x0, 0xc0, 0x1, 0x0, 0x6, 0x0, 0x18,
    0x0, 0x30, 0x0, 0xc0, 0x1, 0x80, 0x6, 0x0,
    0xc, 0x0, 0x30, 0x0, 0x60, 0x1, 0x80, 0x3,
    0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x0, 0x7, 0xfc, 0x7, 0x8f, 0x87, 0x83,
    0xc7, 0xc1, 0xf3, 0xe0, 0xf9, 0xf0, 0x7c, 0xfc,
    0x3e, 0x7f, 0x1e, 0x1f, 0xfc, 0x7, 0xfc, 0x1,
    0xff, 0x81, 0xff, 0xe1, 0xe7, 0xf9, 0xe0, 0xff,
    0xf0, 0x3f, 0xf8, 0xf, 0xfc, 0x7, 0xfe, 0x3,
    0xcf, 0x81, 0xe3, 0xc1, 0xe0, 0xff, 0xc0, 0x6,
    0x0,

    /* U+0039 "9" */
    0x7, 0xf0, 0xf, 0x1e, 0xf, 0x7, 0x8f, 0x3,
    0xe7, 0x80, 0xf7, 0xc0, 0x7f, 0xe0, 0x3f, 0xf0,
    0x1f, 0xf8, 0xf, 0xfc, 0x7, 0xdf, 0x3, 0xef,
    0xc3, 0xf3, 0xfe, 0xf8, 0x7e, 0x78, 0x0, 0x7c,
    0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x3c,
    0x0, 0x7c, 0x1, 0xf8, 0x0, 0xc0, 0x0,

    /* U+003A ":" */
    0x7b, 0xff, 0xff, 0xfd, 0xe0, 0x0, 0x1, 0xef,
    0xff, 0xff, 0xf7, 0x80,

    /* U+003B ";" */
    0x7b, 0xff, 0xff, 0xfd, 0xe0, 0x0, 0x0, 0x7,
    0x3e, 0xff, 0xf7, 0xc3, 0x8, 0x63, 0x38, 0x0,

    /* U+003C "<" */
    0x0, 0x2, 0x0, 0x1c, 0x0, 0xf8, 0x7, 0xc0,
    0x3e, 0x1, 0xf0, 0xf, 0x80, 0x7c, 0x0, 0xe0,
    0x1, 0xf0, 0x0, 0xf8, 0x0, 0x7c, 0x0, 0x3e,
    0x0, 0x1f, 0x0, 0xf, 0x80, 0x7, 0x0, 0x2,

    /* U+003D "=" */
    0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff,

    /* U+003E ">" */
    0x80, 0x1, 0xc0, 0x3, 0xe0, 0x3, 0xf0, 0x1,
    0xf8, 0x0, 0xfc, 0x0, 0x7c, 0x0, 0x3f, 0x0,
    0x1e, 0x0, 0xfc, 0x7, 0xe0, 0x3f, 0x1, 0xf8,
    0xf, 0xc0, 0x3e, 0x0, 0x70, 0x0, 0x80, 0x0,

    /* U+003F "?" */
    0x0, 0x0, 0xff, 0x87, 0x8f, 0x3e, 0x1e, 0xf8,
    0x7f, 0xe1, 0xf7, 0x7, 0xc0, 0x1f, 0x0, 0xfc,
    0xf, 0xe0, 0x7f, 0x81, 0xfc, 0x7, 0xc0, 0x18,
    0x0, 0x40, 0x1, 0x0, 0x0, 0x0, 0x38, 0x1,
    0xf0, 0x7, 0xc0, 0x1f, 0x0, 0x38, 0x0,

    /* U+0040 "@" */
    0x0, 0x3f, 0xc0, 0x0, 0x70, 0x3c, 0x0, 0xe0,
    0x3, 0x1, 0xc0, 0x0, 0xc1, 0xc0, 0x0, 0x30,
    0xc0, 0x0, 0x18, 0xe0, 0x7b, 0xc6, 0xe0, 0xf3,
    0xe3, 0x70, 0xf1, 0xe1, 0xb0, 0x70, 0xf0, 0xf8,
    0x78, 0x78, 0x7c, 0x78, 0x78, 0x3e, 0x3c, 0x3c,
    0x1f, 0x1e, 0x1c, 0x1b, 0x8f, 0x1e, 0xd, 0xc7,
    0x8f, 0xc, 0xe1, 0xfb, 0x8c, 0x38, 0x78, 0xf8,
    0x1c, 0x0, 0x0, 0x7, 0x0, 0x0, 0x3, 0x80,
    0x0, 0x0, 0xe0, 0x0, 0x40, 0x18, 0x0, 0x60,
    0x7, 0x80, 0xc0, 0x0, 0x7f, 0x80, 0x0,

    /* U+0041 "A" */
    0x0, 0x1c, 0x0, 0x0, 0x3c, 0x0, 0x0, 0x3e,
    0x0, 0x0, 0x3e, 0x0, 0x0, 0x7f, 0x0, 0x0,
    0x7f, 0x0, 0x0, 0xdf, 0x0, 0x0, 0xdf, 0x80,
    0x0, 0xcf, 0x80, 0x1, 0x8f, 0x80, 0x1, 0x87,
    0xc0, 0x3, 0x7, 0xc0, 0x3, 0x7, 0xe0, 0x7,
    0xff, 0xe0, 0x6, 0x3, 0xe0, 0x6, 0x1, 0xf0,
    0xc, 0x1, 0xf0, 0xc, 0x1, 0xf8, 0x1c, 0x0,
    0xf8, 0x3c, 0x1, 0xfc, 0xff, 0x87, 0xff,

    /* U+0042 "B" */
    0xff, 0xff, 0x3, 0xf0, 0xfc, 0x1f, 0x7, 0xe1,
    0xf0, 0x3e, 0x1f, 0x3, 0xe1, 0xf0, 0x3e, 0x1f,
    0x3, 0xe1, 0xf0, 0x7c, 0x1f, 0xf, 0x1, 0xff,
    0xc0, 0x1f, 0xf, 0x81, 0xf0, 0x7e, 0x1f, 0x3,
    0xe1, 0xf0, 0x3f, 0x1f, 0x3, 0xf1, 0xf0, 0x3f,
    0x1f, 0x3, 0xf1, 0xf0, 0x3f, 0x1f, 0x7, 0xe1,
    0xf8, 0xfc, 0xff, 0xff, 0x0,

    /* U+0043 "C" */
    0x0, 0x10, 0x0, 0x3f, 0xfe, 0x7, 0x81, 0xe1,
    0xf0, 0xe, 0x3e, 0x0, 0xe3, 0xe0, 0x6, 0x7c,
    0x0, 0x67, 0xc0, 0x2, 0xfc, 0x0, 0xf, 0xc0,
    0x0, 0xfc, 0x0, 0xf, 0xc0, 0x0, 0xfc, 0x0,
    0xf, 0xc0, 0x0, 0xfc, 0x0, 0x7, 0xe0, 0x0,
    0x7e, 0x0, 0x37, 0xe0, 0x2, 0x3f, 0x0, 0x61,
    0xf8, 0xc, 0xf, 0xff, 0x80, 0x3f, 0xe0, 0x0,
    0x20, 0x0,

    /* U+0044 "D" */
    0xff, 0xfe, 0x0, 0x7e, 0xf, 0x80, 0x7c, 0xf,
    0x80, 0xf8, 0xf, 0x81, 0xf0, 0xf, 0x83, 0xe0,
    0x1f, 0x87, 0xc0, 0x3f, 0xf, 0x80, 0x3f, 0x1f,
    0x0, 0x7e, 0x3e, 0x0, 0xfc, 0x7c, 0x1, 0xf8,
    0xf8, 0x3, 0xf1, 0xf0, 0x7, 0xe3, 0xe0, 0xf,
    0xc7, 0xc0, 0x1f, 0xf, 0x80, 0x7e, 0x1f, 0x0,
    0xf8, 0x3e, 0x1, 0xe0, 0x7c, 0x7, 0x81, 0xfc,
    0x3e, 0xf, 0xff, 0xe0, 0x0,

    /* U+0045 "E" */
    0xff, 0xff, 0xe3, 0xf0, 0x3e, 0x1f, 0x0, 0xe1,
    0xf0, 0xe, 0x1f, 0x0, 0x61, 0xf0, 0x0, 0x1f,
    0x2, 0x1, 0xf0, 0x60, 0x1f, 0x6, 0x1, 0xf0,
    0xe0, 0x1f, 0xfe, 0x1, 0xf0, 0xe0, 0x1f, 0x6,
    0x1, 0xf0, 0x20, 0x1f, 0x0, 0x11, 0xf0, 0x3,
    0x1f, 0x0, 0x31, 0xf0, 0x7, 0x1f, 0x0, 0xf1,
    0xf8, 0x1f, 0xff, 0xff, 0xf0,

    /* U+0046 "F" */
    0xff, 0xff, 0xe7, 0xe0, 0x3c, 0x7c, 0x3, 0x8f,
    0x80, 0x71, 0xf0, 0x6, 0x3e, 0x0, 0xc7, 0xc0,
    0x80, 0xf8, 0x30, 0x1f, 0x6, 0x3, 0xe1, 0xc0,
    0x7f, 0xf8, 0xf, 0x87, 0x1, 0xf0, 0x60, 0x3e,
    0xc, 0x7, 0xc0, 0x80, 0xf8, 0x0, 0x1f, 0x0,
    0x3, 0xe0, 0x0, 0x7c, 0x0, 0x1f, 0xc0, 0xf,
    0xfe, 0x0,

    /* U+0047 "G" */
    0x0, 0x10, 0x0, 0x7, 0xff, 0xc0, 0x3e, 0x7,
    0x80, 0xf8, 0x7, 0x3, 0xe0, 0xe, 0x7, 0xc0,
    0xc, 0x1f, 0x80, 0x18, 0x3e, 0x0, 0x10, 0xfc,
    0x0, 0x1, 0xf8, 0x0, 0x3, 0xf0, 0x0, 0x7,
    0xe0, 0x0, 0xf, 0xc0, 0xff, 0xff, 0x80, 0xff,
    0x3f, 0x0, 0x7c, 0x3e, 0x0, 0xf8, 0x7e, 0x1,
    0xf0, 0xfc, 0x3, 0xe0, 0xf8, 0x7, 0xc0, 0xf8,
    0xf, 0x80, 0xf8, 0x3f, 0x0, 0x7f, 0xf0, 0x0,
    0x8, 0x0, 0x0,

    /* U+0048 "H" */
    0xff, 0xe3, 0xff, 0x9f, 0xc0, 0x7f, 0x7, 0xc0,
    0x1f, 0x3, 0xe0, 0xf, 0x81, 0xf0, 0x7, 0xc0,
    0xf8, 0x3, 0xe0, 0x7c, 0x1, 0xf0, 0x3e, 0x0,
    0xf8, 0x1f, 0x0, 0x7c, 0xf, 0x80, 0x3e, 0x7,
    0xff, 0xff, 0x3, 0xe0, 0xf, 0x81, 0xf0, 0x7,
    0xc0, 0xf8, 0x3, 0xe0, 0x7c, 0x1, 0xf0, 0x3e,
    0x0, 0xf8, 0x1f, 0x0, 0x7c, 0xf, 0x80, 0x3e,
    0x7, 0xc0, 0x1f, 0x7, 0xf0, 0x1f, 0xcf, 0xfe,
    0x3f, 0xf8,

    /* U+0049 "I" */
    0xff, 0xf3, 0xf8, 0x1f, 0x1, 0xf0, 0x1f, 0x1,
    0xf0, 0x1f, 0x1, 0xf0, 0x1f, 0x1, 0xf0, 0x1f,
    0x1, 0xf0, 0x1f, 0x1, 0xf0, 0x1f, 0x1, 0xf0,
    0x1f, 0x1, 0xf0, 0x1f, 0x1, 0xf8, 0xff, 0xf0,

    /* U+004A "J" */
    0x3, 0xff, 0x80, 0xff, 0x0, 0x1f, 0x0, 0xf,
    0x80, 0x7, 0xc0, 0x3, 0xe0, 0x1, 0xf0, 0x0,
    0xf8, 0x0, 0x7c, 0x0, 0x3e, 0x0, 0x1f, 0x0,
    0xf, 0x80, 0x7, 0xc0, 0x3, 0xe1, 0xc1, 0xf1,
    0xf0, 0xf8, 0xf8, 0x7c, 0x7c, 0x3c, 0x3c, 0x3e,
    0xc, 0x1e, 0x3, 0xfc, 0x0, 0x30, 0x0,

    /* U+004B "K" */
    0xff, 0xe3, 0xfe, 0x3f, 0x80, 0xf0, 0x1f, 0x0,
    0xe0, 0x1f, 0x1, 0x80, 0x1f, 0x3, 0x0, 0x1f,
    0x6, 0x0, 0x1f, 0xc, 0x0, 0x1f, 0x18, 0x0,
    0x1f, 0x38, 0x0, 0x1f, 0x7c, 0x0, 0x1f, 0xfe,
    0x0, 0x1f, 0x7e, 0x0, 0x1f, 0x3f, 0x0, 0x1f,
    0x1f, 0x80, 0x1f, 0xf, 0xc0, 0x1f, 0xf, 0xc0,
    0x1f, 0x7, 0xe0, 0x1f, 0x3, 0xf0, 0x1f, 0x3,
    0xf8, 0x3f, 0x81, 0xfc, 0xff, 0xe0, 0xff,

    /* U+004C "L" */
    0xff, 0xe0, 0x7, 0xf8, 0x0, 0x1f, 0x0, 0x1,
    0xf0, 0x0, 0x1f, 0x0, 0x1, 0xf0, 0x0, 0x1f,
    0x0, 0x1, 0xf0, 0x0, 0x1f, 0x0, 0x1, 0xf0,
    0x0, 0x1f, 0x0, 0x1, 0xf0, 0x0, 0x1f, 0x0,
    0x1, 0xf0, 0x0, 0x1f, 0x0, 0x1, 0xf0, 0x3,
    0x1f, 0x0, 0x31, 0xf0, 0x7, 0x1f, 0x0, 0xf1,
    0xf8, 0x1f, 0xff, 0xff, 0xf0,

    /* U+004D "M" */
    0xff, 0xc0, 0xf, 0xf9, 0xfe, 0x0, 0x7f, 0x7,
    0xf8, 0x7, 0xf0, 0x37, 0xc0, 0x2f, 0x81, 0xbe,
    0x3, 0x7c, 0xd, 0xf8, 0x1b, 0xe0, 0x67, 0xc0,
    0x9f, 0x3, 0x3f, 0xc, 0xf8, 0x18, 0xf8, 0x67,
    0xc0, 0xc7, 0xc2, 0x3e, 0x6, 0x3f, 0x31, 0xf0,
    0x30, 0xf9, 0x8f, 0x81, 0x87, 0xc8, 0x7c, 0xc,
    0x3f, 0xc3, 0xe0, 0x60, 0xfc, 0x1f, 0x3, 0x7,
    0xe0, 0xf8, 0x18, 0x1f, 0x7, 0xc0, 0xc0, 0xf0,
    0x3e, 0x7, 0x7, 0x81, 0xf0, 0x7c, 0x1c, 0x1f,
    0xcf, 0xf8, 0xc3, 0xff, 0x80,

    /* U+004E "N" */
    0xff, 0x1, 0xff, 0x7f, 0x80, 0xfc, 0x3f, 0xc0,
    0x38, 0x1f, 0xe0, 0x18, 0x1f, 0xe0, 0x18, 0x1b,
    0xf0, 0x18, 0x1b, 0xf8, 0x18, 0x19, 0xfc, 0x18,
    0x18, 0xfe, 0x18, 0x18, 0x7e, 0x18, 0x18, 0x3f,
    0x18, 0x18, 0x3f, 0x98, 0x18, 0x1f, 0xd8, 0x18,
    0xf, 0xf8, 0x18, 0x7, 0xf8, 0x18, 0x3, 0xf8,
    0x18, 0x3, 0xf8, 0x18, 0x1, 0xf8, 0x1c, 0x0,
    0xf8, 0x7f, 0x0, 0x78, 0xff, 0x80, 0x38,

    /* U+004F "O" */
    0x0, 0x0, 0x0, 0x7, 0xff, 0x0, 0x1e, 0xf,
    0x0, 0xf8, 0xf, 0x83, 0xe0, 0xf, 0x87, 0xc0,
    0x1f, 0x1f, 0x80, 0x3f, 0x3e, 0x0, 0x3e, 0xfc,
    0x0, 0x7f, 0xf8, 0x0, 0xff, 0xf0, 0x1, 0xff,
    0xe0, 0x3, 0xff, 0xc0, 0x7, 0xff, 0x80, 0xf,
    0xff, 0x0, 0x1f, 0xbe, 0x0, 0x3e, 0x7e, 0x0,
    0xfc, 0x7c, 0x1, 0xf0, 0xf8, 0x3, 0xe0, 0xf8,
    0xf, 0x80, 0x78, 0x3c, 0x0, 0x7f, 0xf0, 0x0,
    0x4, 0x0, 0x0,

    /* U+0050 "P" */
    0xff, 0xfe, 0x7, 0xe1, 0xf0, 0x7c, 0x1f, 0xf,
    0x81, 0xf1, 0xf0, 0x3e, 0x3e, 0x7, 0xc7, 0xc0,
    0xf8, 0xf8, 0x1f, 0x1f, 0x3, 0xc3, 0xe0, 0xf0,
    0x7c, 0x7c, 0xf, 0xfe, 0x1, 0xf0, 0x0, 0x3e,
    0x0, 0x7, 0xc0, 0x0, 0xf8, 0x0, 0x1f, 0x0,
    0x3, 0xe0, 0x0, 0x7c, 0x0, 0x1f, 0xc0, 0xf,
    0xfe, 0x0,

    /* U+0051 "Q" */
    0x0, 0x0, 0x0, 0x3, 0xfe, 0x0, 0x1e, 0xf,
    0x0, 0xf8, 0xf, 0x81, 0xe0, 0xf, 0x87, 0xc0,
    0x1f, 0x1f, 0x80, 0x3f, 0x3e, 0x0, 0x3e, 0xfc,
    0x0, 0x7f, 0xf8, 0x0, 0xff, 0xf0, 0x1, 0xff,
    0xe0, 0x3, 0xff, 0xc0, 0x7, 0xff, 0x80, 0xf,
    0xff, 0x0, 0x1f, 0xfe, 0x0, 0x3e, 0x7c, 0x0,
    0xfc, 0xfc, 0x1, 0xf8, 0xf8, 0x3, 0xe0, 0xf8,
    0xf, 0x80, 0xf0, 0x3e, 0x0, 0xf8, 0xf8, 0x0,
    0x7f, 0xc0, 0x0, 0x1f, 0x80, 0x0, 0x3f, 0x0,
    0x0, 0x3f, 0x0, 0x0, 0x7f, 0x0, 0x0, 0x7f,
    0xe0, 0x0, 0x3f, 0x0,

    /* U+0052 "R" */
    0xff, 0xff, 0x0, 0x3f, 0xf, 0xc0, 0x1f, 0x7,
    0xe0, 0x1f, 0x3, 0xf0, 0x1f, 0x3, 0xf0, 0x1f,
    0x3, 0xf0, 0x1f, 0x3, 0xf0, 0x1f, 0x3, 0xe0,
    0x1f, 0x7, 0xe0, 0x1f, 0xf, 0x80, 0x1f, 0xfe,
    0x0, 0x1f, 0x7f, 0x0, 0x1f, 0x3f, 0x0, 0x1f,
    0x1f, 0x80, 0x1f, 0xf, 0xc0, 0x1f, 0xf, 0xe0,
    0x1f, 0x7, 0xe0, 0x1f, 0x3, 0xf0, 0x1f, 0x3,
    0xf8, 0x3f, 0xc1, 0xfe, 0xff, 0xe0, 0xff,

    /* U+0053 "S" */
    0x0, 0x0, 0x3, 0xff, 0xe1, 0xe0, 0xf8, 0xf0,
    0x1e, 0x3c, 0x3, 0x9f, 0x0, 0xe7, 0xe0, 0x19,
    0xfc, 0x6, 0x7f, 0xc0, 0x1f, 0xfe, 0x3, 0xff,
    0xe0, 0x7f, 0xfc, 0xf, 0xff, 0x80, 0x7f, 0xf0,
    0x3, 0xff, 0x0, 0x3f, 0xc0, 0x7, 0xf8, 0x1,
    0xff, 0x0, 0x7b, 0xe0, 0x1e, 0xfc, 0xf, 0x3f,
    0xff, 0x0, 0xc, 0x0,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0x87, 0xc3, 0xf8, 0x3e, 0xf,
    0xc1, 0xf0, 0x3c, 0xf, 0x81, 0xe0, 0x7c, 0x4,
    0x3, 0xe0, 0x0, 0x1f, 0x0, 0x0, 0xf8, 0x0,
    0x7, 0xc0, 0x0, 0x3e, 0x0, 0x1, 0xf0, 0x0,
    0xf, 0x80, 0x0, 0x7c, 0x0, 0x3, 0xe0, 0x0,
    0x1f, 0x0, 0x0, 0xf8, 0x0, 0x7, 0xc0, 0x0,
    0x3e, 0x0, 0x3, 0xfc, 0x0, 0x7f, 0xf8, 0x0,

    /* U+0055 "U" */
    0xff, 0xe1, 0xff, 0x3f, 0x80, 0x7c, 0x1f, 0x0,
    0x38, 0x1f, 0x0, 0x18, 0x1f, 0x0, 0x18, 0x1f,
    0x0, 0x18, 0x1f, 0x0, 0x18, 0x1f, 0x0, 0x18,
    0x1f, 0x0, 0x18, 0x1f, 0x0, 0x18, 0x1f, 0x0,
    0x18, 0x1f, 0x0, 0x18, 0x1f, 0x0, 0x18, 0x1f,
    0x0, 0x18, 0x1f, 0x0, 0x18, 0x1f, 0x0, 0x18,
    0x1f, 0x0, 0x38, 0xf, 0x80, 0x30, 0xf, 0xc0,
    0x70, 0x7, 0xff, 0xe0, 0x1, 0xff, 0x80, 0x0,
    0x8, 0x0,

    /* U+0056 "V" */
    0xff, 0xe0, 0xff, 0x7f, 0x80, 0x3e, 0x1f, 0x0,
    0x18, 0x1f, 0x80, 0x18, 0xf, 0x80, 0x30, 0xf,
    0xc0, 0x30, 0x7, 0xc0, 0x20, 0x7, 0xc0, 0x60,
    0x7, 0xe0, 0x60, 0x3, 0xe0, 0x40, 0x3, 0xf0,
    0xc0, 0x1, 0xf0, 0x80, 0x1, 0xf9, 0x80, 0x1,
    0xf9, 0x80, 0x0, 0xf9, 0x0, 0x0, 0xff, 0x0,
    0x0, 0x7e, 0x0, 0x0, 0x7e, 0x0, 0x0, 0x7e,
    0x0, 0x0, 0x3c, 0x0, 0x0, 0x3c, 0x0,

    /* U+0057 "W" */
    0xff, 0xe0, 0x78, 0x1f, 0xef, 0xf0, 0xf, 0x0,
    0xf8, 0x7c, 0x1, 0xf0, 0xc, 0xf, 0xc0, 0x7e,
    0x1, 0x80, 0xf8, 0xf, 0xc0, 0x30, 0x1f, 0x1,
    0xfc, 0xc, 0x3, 0xf0, 0x6f, 0x81, 0x80, 0x3e,
    0xd, 0xf0, 0x30, 0x7, 0xc1, 0x3f, 0x4, 0x0,
    0xfc, 0x63, 0xe1, 0x80, 0xf, 0x8c, 0x7e, 0x30,
    0x1, 0xf1, 0x7, 0xc4, 0x0, 0x3f, 0x60, 0xf9,
    0x80, 0x3, 0xec, 0x1f, 0xb0, 0x0, 0x7d, 0x1,
    0xf4, 0x0, 0xf, 0xe0, 0x3f, 0x80, 0x0, 0xfc,
    0x7, 0xf0, 0x0, 0x1f, 0x0, 0x7c, 0x0, 0x3,
    0xe0, 0xf, 0x80, 0x0, 0x3c, 0x1, 0xf0, 0x0,
    0x7, 0x0, 0x1c, 0x0,

    /* U+0058 "X" */
    0xff, 0xf9, 0xfe, 0x3f, 0xc0, 0x78, 0x1f, 0xc0,
    0x70, 0xf, 0xc0, 0x60, 0x7, 0xe0, 0xc0, 0x3,
    0xf1, 0x80, 0x3, 0xf3, 0x0, 0x1, 0xfa, 0x0,
    0x0, 0xfe, 0x0, 0x0, 0xfc, 0x0, 0x0, 0x7e,
    0x0, 0x0, 0x7f, 0x0, 0x0, 0xff, 0x0, 0x0,
    0x9f, 0x80, 0x1, 0x9f, 0xc0, 0x3, 0xf, 0xc0,
    0x6, 0x7, 0xe0, 0xc, 0x3, 0xf0, 0x1c, 0x3,
    0xf8, 0x3c, 0x3, 0xfc, 0xff, 0x1f, 0xff,

    /* U+0059 "Y" */
    0xff, 0xf0, 0xff, 0x3f, 0x80, 0x1c, 0x1f, 0x80,
    0x18, 0xf, 0xc0, 0x30, 0xf, 0xc0, 0x20, 0x7,
    0xe0, 0x60, 0x3, 0xe0, 0xc0, 0x3, 0xf0, 0x80,
    0x1, 0xf1, 0x80, 0x1, 0xfb, 0x0, 0x0, 0xfa,
    0x0, 0x0, 0xfe, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x7c, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x7c, 0x0,
    0x0, 0x7c, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x7c,
    0x0, 0x0, 0xff, 0x0, 0x3, 0xff, 0xc0,

    /* U+005A "Z" */
    0x3f, 0xff, 0xf3, 0xc0, 0x7e, 0x78, 0xf, 0xe7,
    0x0, 0xfc, 0x60, 0x1f, 0x86, 0x3, 0xf8, 0x0,
    0x3f, 0x0, 0x7, 0xe0, 0x0, 0xfe, 0x0, 0xf,
    0xc0, 0x1, 0xf8, 0x0, 0x3f, 0x0, 0x7, 0xf0,
    0x0, 0x7e, 0x0, 0xf, 0xc0, 0x11, 0xfc, 0x1,
    0x1f, 0x80, 0x33, 0xf0, 0x3, 0x7f, 0x0, 0x77,
    0xe0, 0xf, 0xff, 0xff, 0xf0,

    /* U+005B "[" */
    0xff, 0xfe, 0xf, 0x83, 0xe0, 0xf8, 0x3e, 0xf,
    0x83, 0xe0, 0xf8, 0x3e, 0xf, 0x83, 0xe0, 0xf8,
    0x3e, 0xf, 0x83, 0xe0, 0xf8, 0x3e, 0xf, 0x83,
    0xe0, 0xf8, 0x3e, 0xf, 0x83, 0xe0, 0xf8, 0x3f,
    0xf0,

    /* U+005C "\\" */
    0xe0, 0x3, 0x0, 0x1c, 0x0, 0xe0, 0x3, 0x0,
    0x1c, 0x0, 0xe0, 0x3, 0x0, 0x1c, 0x0, 0xe0,
    0x3, 0x0, 0x1c, 0x0, 0xe0, 0x3, 0x0, 0x1c,
    0x0, 0xe0, 0x3, 0x0, 0x1c, 0x0, 0xe0, 0x3,
    0x0, 0x1c, 0x0, 0xe0, 0x3, 0x0, 0x1c, 0x0,
    0xe0, 0x3, 0x0, 0x1c, 0x0, 0xe0, 0x3, 0x0,
    0x1c,

    /* U+005D "]" */
    0xff, 0xc1, 0xf0, 0x7c, 0x1f, 0x7, 0xc1, 0xf0,
    0x7c, 0x1f, 0x7, 0xc1, 0xf0, 0x7c, 0x1f, 0x7,
    0xc1, 0xf0, 0x7c, 0x1f, 0x7, 0xc1, 0xf0, 0x7c,
    0x1f, 0x7, 0xc1, 0xf0, 0x7c, 0x1f, 0x7, 0xff,
    0xf0,

    /* U+005E "^" */
    0x3, 0x80, 0x7, 0x80, 0x1f, 0x0, 0x77, 0x0,
    0xc7, 0x3, 0x8e, 0xe, 0xe, 0x18, 0xc, 0x70,
    0x1d, 0xc0, 0x1c,

    /* U+005F "_" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+0060 "`" */
    0xf0, 0xf0, 0xf8, 0x3c, 0x1e, 0x6, 0x0,

    /* U+0061 "a" */
    0xf, 0xe0, 0x1c, 0x7c, 0x1f, 0x1f, 0xf, 0x8f,
    0x87, 0xc7, 0xc0, 0x3, 0xe0, 0xf, 0xf0, 0x3c,
    0xf8, 0x7c, 0x7c, 0x7c, 0x3e, 0x3e, 0x1f, 0x1f,
    0xf, 0x8f, 0xcf, 0xc3, 0xfb, 0xfc, 0xf8, 0xfc,

    /* U+0062 "b" */
    0xff, 0x0, 0x7, 0xe0, 0x0, 0x7c, 0x0, 0xf,
    0x80, 0x1, 0xf0, 0x0, 0x3e, 0x0, 0x7, 0xc0,
    0x0, 0xf8, 0x0, 0x1f, 0x3e, 0x3, 0xef, 0xf0,
    0x7e, 0x3f, 0xf, 0x83, 0xe1, 0xf0, 0x7e, 0x3e,
    0x7, 0xc7, 0xc0, 0xf8, 0xf8, 0x1f, 0x1f, 0x3,
    0xe3, 0xe0, 0x7c, 0x7c, 0xf, 0xf, 0x83, 0xe1,
    0xf0, 0x78, 0x3f, 0x1e, 0x6, 0x3f, 0x0,

    /* U+0063 "c" */
    0x7, 0xe0, 0x3c, 0xf0, 0xf1, 0xf3, 0xe3, 0xe7,
    0x87, 0xdf, 0x7, 0x3e, 0x0, 0x7c, 0x0, 0xf8,
    0x1, 0xf0, 0x3, 0xf0, 0x13, 0xe0, 0x23, 0xe1,
    0xc3, 0xff, 0x1, 0xf8, 0x0,

    /* U+0064 "d" */
    0x0, 0xff, 0x0, 0x1f, 0xc0, 0x1, 0xf0, 0x0,
    0x7c, 0x0, 0x1f, 0x0, 0x7, 0xc0, 0x1, 0xf0,
    0x0, 0x7c, 0x7, 0xff, 0x7, 0x8f, 0xc3, 0xc1,
    0xf1, 0xf0, 0x7c, 0x78, 0x1f, 0x3e, 0x7, 0xcf,
    0x81, 0xf3, 0xe0, 0x7c, 0xf8, 0x1f, 0x3e, 0x7,
    0xcf, 0x81, 0xf1, 0xf0, 0x7c, 0x3e, 0x3f, 0xf,
    0xff, 0xc0, 0xf9, 0xfc,

    /* U+0065 "e" */
    0x7, 0xe0, 0x38, 0xf0, 0xf0, 0xf3, 0xc1, 0xf7,
    0x83, 0xff, 0x7, 0xff, 0xff, 0xfc, 0x0, 0xf8,
    0x1, 0xf0, 0x1, 0xf0, 0x3, 0xe0, 0x33, 0xe0,
    0xc3, 0xff, 0x1, 0xf8, 0x0,

    /* U+0066 "f" */
    0x0, 0xf8, 0x7, 0xf8, 0x1c, 0xf0, 0x79, 0xe0,
    0xf1, 0xc3, 0xe0, 0x7, 0xc0, 0xf, 0x80, 0xff,
    0xf0, 0x3e, 0x0, 0x7c, 0x0, 0xf8, 0x1, 0xf0,
    0x3, 0xe0, 0x7, 0xc0, 0xf, 0x80, 0x1f, 0x0,
    0x3e, 0x0, 0x7c, 0x0, 0xf8, 0x1, 0xf0, 0x7,
    0xf0, 0x1f, 0xf8, 0x0,

    /* U+0067 "g" */
    0x7, 0xff, 0x8f, 0x3e, 0xf, 0xf, 0x8f, 0x87,
    0xc7, 0xc3, 0xe3, 0xe1, 0xf1, 0xf0, 0xf8, 0x78,
    0x78, 0x1e, 0x78, 0x3, 0xf0, 0x7, 0x0, 0x7,
    0x80, 0x3, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xfe,
    0xf8, 0x3f, 0xf8, 0xf, 0xfc, 0x7, 0xfe, 0x3,
    0xff, 0x1, 0xe7, 0xc1, 0xe0, 0x7f, 0x80,

    /* U+0068 "h" */
    0xff, 0x0, 0x3, 0xf0, 0x0, 0x1f, 0x0, 0x1,
    0xf0, 0x0, 0x1f, 0x0, 0x1, 0xf0, 0x0, 0x1f,
    0x0, 0x1, 0xf0, 0x0, 0x1f, 0x1f, 0x1, 0xf7,
    0xf8, 0x1f, 0xdf, 0xc1, 0xf8, 0x7c, 0x1f, 0x7,
    0xc1, 0xf0, 0x7c, 0x1f, 0x7, 0xc1, 0xf0, 0x7c,
    0x1f, 0x7, 0xc1, 0xf0, 0x7c, 0x1f, 0x7, 0xc1,
    0xf0, 0x7c, 0x1f, 0x7, 0xc1, 0xf8, 0x7e, 0x7f,
    0xdf, 0xf0,

    /* U+0069 "i" */
    0x1c, 0x1f, 0xf, 0x87, 0xc1, 0xc0, 0x0, 0x0,
    0x0, 0xfe, 0x7f, 0xf, 0x87, 0xc3, 0xe1, 0xf0,
    0xf8, 0x7c, 0x3e, 0x1f, 0xf, 0x87, 0xc3, 0xe1,
    0xfb, 0xfe,

    /* U+006A "j" */
    0x1, 0xe0, 0x3f, 0x3, 0xf0, 0x3f, 0x1, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xf0, 0x7f, 0x1,
    0xf0, 0x1f, 0x1, 0xf0, 0x1f, 0x1, 0xf0, 0x1f,
    0x1, 0xf0, 0x1f, 0x1, 0xf0, 0x1f, 0x1, 0xf0,
    0x1f, 0x1, 0xf0, 0x1f, 0x1, 0xf7, 0x1e, 0xf9,
    0xef, 0x9c, 0xff, 0x87, 0xe0,

    /* U+006B "k" */
    0xff, 0x0, 0x3, 0xf0, 0x0, 0x1f, 0x0, 0x1,
    0xf0, 0x0, 0x1f, 0x0, 0x1, 0xf0, 0x0, 0x1f,
    0x0, 0x1, 0xf0, 0x0, 0x1f, 0xf, 0xe1, 0xf0,
    0x7c, 0x1f, 0x3, 0x1, 0xf0, 0x40, 0x1f, 0x8,
    0x1, 0xf3, 0x80, 0x1f, 0x7c, 0x1, 0xff, 0xe0,
    0x1f, 0x7e, 0x1, 0xf3, 0xf0, 0x1f, 0x1f, 0x81,
    0xf1, 0xf8, 0x1f, 0xf, 0xc1, 0xf8, 0x7e, 0x7f,
    0xc7, 0xf0,

    /* U+006C "l" */
    0xff, 0xf, 0xc1, 0xf0, 0x7c, 0x1f, 0x7, 0xc1,
    0xf0, 0x7c, 0x1f, 0x7, 0xc1, 0xf0, 0x7c, 0x1f,
    0x7, 0xc1, 0xf0, 0x7c, 0x1f, 0x7, 0xc1, 0xf0,
    0x7c, 0x1f, 0x7, 0xe7, 0xfc,

    /* U+006D "m" */
    0xfe, 0x3e, 0xf, 0x83, 0xf7, 0xf9, 0xfe, 0xf,
    0xc7, 0xf1, 0xf8, 0x7c, 0x1f, 0x7, 0xc3, 0xe0,
    0xf8, 0x3e, 0x1f, 0x7, 0xc1, 0xf0, 0xf8, 0x3e,
    0xf, 0x87, 0xc1, 0xf0, 0x7c, 0x3e, 0xf, 0x83,
    0xe1, 0xf0, 0x7c, 0x1f, 0xf, 0x83, 0xe0, 0xf8,
    0x7c, 0x1f, 0x7, 0xc3, 0xe0, 0xf8, 0x3e, 0x1f,
    0x87, 0xe1, 0xfb, 0xfe, 0x7f, 0xbf, 0xe0,

    /* U+006E "n" */
    0xfe, 0x3e, 0xf, 0xdf, 0xe0, 0xfc, 0x7e, 0x1f,
    0x7, 0xc3, 0xe0, 0xf8, 0x7c, 0x1f, 0xf, 0x83,
    0xe1, 0xf0, 0x7c, 0x3e, 0xf, 0x87, 0xc1, 0xf0,
    0xf8, 0x3e, 0x1f, 0x7, 0xc3, 0xe0, 0xf8, 0x7e,
    0x1f, 0xbf, 0xef, 0xf8,

    /* U+006F "o" */
    0x7, 0xf0, 0xf, 0x1e, 0xf, 0x7, 0x8f, 0x1,
    0xe7, 0x80, 0xf7, 0xc0, 0x7f, 0xe0, 0x3f, 0xf0,
    0x1f, 0xf8, 0xf, 0xfc, 0x7, 0xde, 0x3, 0xcf,
    0x3, 0xe3, 0xc1, 0xe0, 0xf1, 0xe0, 0x1f, 0xc0,

    /* U+0070 "p" */
    0xfe, 0x7c, 0x1f, 0xff, 0xc3, 0xf1, 0xf8, 0xf8,
    0x3e, 0x3e, 0x7, 0xcf, 0x81, 0xf3, 0xe0, 0x7c,
    0xf8, 0x1f, 0x3e, 0x7, 0xcf, 0x81, 0xf3, 0xe0,
    0x78, 0xf8, 0x3e, 0x3e, 0xf, 0xf, 0xc7, 0x83,
    0xff, 0x80, 0xf8, 0x0, 0x3e, 0x0, 0xf, 0x80,
    0x3, 0xe0, 0x0, 0xf8, 0x0, 0x3f, 0x0, 0x3f,
    0xf8, 0x0,

    /* U+0071 "q" */
    0x7, 0xf3, 0x3, 0xc7, 0xe0, 0xf0, 0x7c, 0x3e,
    0xf, 0x87, 0x81, 0xf1, 0xf0, 0x3e, 0x3e, 0x7,
    0xc7, 0xc0, 0xf8, 0xf8, 0x1f, 0x1f, 0x3, 0xe3,
    0xe0, 0x7c, 0x3c, 0xf, 0x87, 0xc1, 0xf0, 0x7c,
    0x7e, 0x3, 0xf7, 0xc0, 0x0, 0xf8, 0x0, 0x1f,
    0x0, 0x3, 0xe0, 0x0, 0x7c, 0x0, 0xf, 0x80,
    0x3, 0xfc, 0x0, 0xff, 0xc0,

    /* U+0072 "r" */
    0xfe, 0x3d, 0xfd, 0xfc, 0xfe, 0xf9, 0xf1, 0xf3,
    0xe3, 0xe7, 0xc3, 0x8f, 0x80, 0x1f, 0x0, 0x3e,
    0x0, 0x7c, 0x0, 0xf8, 0x1, 0xf0, 0x3, 0xe0,
    0x7, 0xe0, 0x3f, 0xf0, 0x0,

    /* U+0073 "s" */
    0xf, 0xf8, 0xf8, 0xe3, 0xc1, 0x9f, 0x6, 0x7e,
    0x9, 0xff, 0x7, 0xff, 0xf, 0xfe, 0x1f, 0xfc,
    0xf, 0xfc, 0xf, 0xf8, 0x1f, 0xe0, 0x7b, 0xe3,
    0xcc, 0xfe, 0x0,

    /* U+0074 "t" */
    0x1f, 0x1, 0xf0, 0x1f, 0x1, 0xf0, 0x1f, 0xf,
    0xff, 0x1f, 0x1, 0xf0, 0x1f, 0x1, 0xf0, 0x1f,
    0x1, 0xf0, 0x1f, 0x1, 0xf0, 0x1f, 0x1, 0xf0,
    0x1f, 0x1, 0xf8, 0xf, 0xf0, 0x7e,

    /* U+0075 "u" */
    0xfe, 0x3f, 0x8f, 0xc3, 0xf0, 0xf8, 0x3e, 0x1f,
    0x7, 0xc3, 0xe0, 0xf8, 0x7c, 0x1f, 0xf, 0x83,
    0xe1, 0xf0, 0x7c, 0x3e, 0xf, 0x87, 0xc1, 0xf0,
    0xf8, 0x3e, 0x1f, 0x7, 0xc3, 0xe1, 0xf8, 0x3f,
    0xff, 0x3, 0xf3, 0xf8,

    /* U+0076 "v" */
    0xff, 0x8f, 0xdf, 0x81, 0xe3, 0xe0, 0x30, 0x7c,
    0x8, 0x1f, 0x6, 0x3, 0xe1, 0x0, 0xf8, 0xc0,
    0x3f, 0x20, 0x7, 0xc8, 0x1, 0xf6, 0x0, 0x3f,
    0x0, 0xf, 0xc0, 0x1, 0xe0, 0x0, 0x78, 0x0,
    0x1e, 0x0,

    /* U+0077 "w" */
    0xff, 0x87, 0xf, 0xdf, 0x81, 0xe0, 0xe3, 0xe0,
    0xf8, 0x30, 0xfc, 0x3e, 0xc, 0x1f, 0xf, 0xc2,
    0x7, 0xc7, 0xf1, 0x80, 0xf9, 0xbc, 0x60, 0x3e,
    0x4f, 0x90, 0xf, 0xb3, 0xec, 0x1, 0xfc, 0x7f,
    0x0, 0x7e, 0x1f, 0x80, 0xf, 0x83, 0xe0, 0x3,
    0xe0, 0xf0, 0x0, 0xf0, 0x3c, 0x0, 0x1c, 0x7,
    0x0,

    /* U+0078 "x" */
    0xff, 0x9f, 0x9f, 0x87, 0x87, 0xc3, 0x3, 0xf3,
    0x0, 0xf9, 0x0, 0x3f, 0x80, 0x1f, 0x80, 0x7,
    0xc0, 0x3, 0xf0, 0x3, 0xfc, 0x3, 0x3e, 0x1,
    0x8f, 0x81, 0x87, 0xe3, 0x81, 0xf3, 0xf3, 0xfe,

    /* U+0079 "y" */
    0xff, 0x8f, 0xdf, 0x81, 0xe3, 0xe0, 0x30, 0x7c,
    0x8, 0x1f, 0x6, 0x3, 0xe1, 0x0, 0xf8, 0xc0,
    0x1f, 0x20, 0x7, 0xc8, 0x0, 0xfe, 0x0, 0x3f,
    0x0, 0xf, 0xc0, 0x1, 0xe0, 0x0, 0x78, 0x0,
    0xc, 0x0, 0x3, 0x0, 0x0, 0xc0, 0x1c, 0x20,
    0x7, 0xd0, 0x1, 0xfc, 0x0, 0x7e, 0x0, 0xf,
    0x0, 0x0,

    /* U+007A "z" */
    0xff, 0xff, 0x3, 0xec, 0x1f, 0xa0, 0x7c, 0x83,
    0xf0, 0x1f, 0x80, 0x7c, 0x3, 0xf0, 0x1f, 0x80,
    0x7c, 0x13, 0xf0, 0x4f, 0x81, 0x7c, 0xf, 0xf0,
    0x3f, 0xff, 0xc0,

    /* U+007B "{" */
    0x0, 0xf8, 0x1f, 0x1, 0xf0, 0x1f, 0x0, 0xf8,
    0x7, 0xc0, 0x3e, 0x1, 0xf0, 0xf, 0x80, 0x7c,
    0x3, 0xc0, 0x3e, 0xf, 0xc0, 0x78, 0x3, 0xe0,
    0x3, 0xc0, 0xf, 0x0, 0x7c, 0x3, 0xe0, 0x1f,
    0x0, 0xf8, 0x7, 0xc0, 0x3e, 0x1, 0xf0, 0x7,
    0x80, 0x1e, 0x0, 0x3e,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xf8, 0x1, 0xf0, 0x7, 0xc0, 0x1f, 0x0, 0xf8,
    0x7, 0xc0, 0x3e, 0x1, 0xf0, 0xf, 0x80, 0x7c,
    0x1, 0xe0, 0xf, 0x80, 0x1f, 0x80, 0x3c, 0x3,
    0xe0, 0x78, 0x7, 0x80, 0x7c, 0x3, 0xe0, 0x1f,
    0x0, 0xf8, 0x7, 0xc0, 0x3e, 0x1, 0xf0, 0xf,
    0x0, 0xf0, 0x3f, 0x0,

    /* U+007E "~" */
    0xf, 0x1, 0x9f, 0xe1, 0x98, 0xff, 0xcc, 0x1f,
    0xcc, 0x7, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 122, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 181, .box_w = 5, .box_h = 22, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 15, .adv_w = 245, .box_w = 12, .box_h = 10, .ofs_x = 2, .ofs_y = 13},
    {.bitmap_index = 30, .adv_w = 338, .box_w = 17, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 308, .box_w = 16, .box_h = 27, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 125, .adv_w = 422, .box_w = 24, .box_h = 23, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 194, .adv_w = 384, .box_w = 23, .box_h = 23, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 261, .adv_w = 129, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 13},
    {.bitmap_index = 268, .adv_w = 214, .box_w = 11, .box_h = 28, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 307, .adv_w = 214, .box_w = 11, .box_h = 28, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 346, .adv_w = 231, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 364, .adv_w = 338, .box_w = 16, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 398, .adv_w = 158, .box_w = 6, .box_h = 11, .ofs_x = 2, .ofs_y = -6},
    {.bitmap_index = 407, .adv_w = 182, .box_w = 9, .box_h = 3, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 411, .adv_w = 158, .box_w = 6, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 416, .adv_w = 226, .box_w = 13, .box_h = 30, .ofs_x = 0, .ofs_y = -7},
    {.bitmap_index = 465, .adv_w = 337, .box_w = 18, .box_h = 20, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 510, .adv_w = 235, .box_w = 12, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 539, .adv_w = 301, .box_w = 16, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 577, .adv_w = 300, .box_w = 16, .box_h = 22, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 621, .adv_w = 312, .box_w = 18, .box_h = 22, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 671, .adv_w = 288, .box_w = 16, .box_h = 21, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 713, .adv_w = 311, .box_w = 16, .box_h = 22, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 757, .adv_w = 266, .box_w = 15, .box_h = 22, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 799, .adv_w = 325, .box_w = 17, .box_h = 23, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 848, .adv_w = 311, .box_w = 17, .box_h = 22, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 895, .adv_w = 176, .box_w = 6, .box_h = 15, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 907, .adv_w = 176, .box_w = 6, .box_h = 21, .ofs_x = 3, .ofs_y = -6},
    {.bitmap_index = 923, .adv_w = 338, .box_w = 15, .box_h = 17, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 955, .adv_w = 338, .box_w = 16, .box_h = 8, .ofs_x = 3, .ofs_y = 4},
    {.bitmap_index = 971, .adv_w = 338, .box_w = 15, .box_h = 17, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1003, .adv_w = 263, .box_w = 14, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1042, .adv_w = 464, .box_w = 25, .box_h = 25, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1121, .adv_w = 364, .box_w = 24, .box_h = 21, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1184, .adv_w = 364, .box_w = 20, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1237, .adv_w = 343, .box_w = 20, .box_h = 23, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1295, .adv_w = 400, .box_w = 23, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1356, .adv_w = 346, .box_w = 20, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1409, .adv_w = 322, .box_w = 19, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1459, .adv_w = 387, .box_w = 23, .box_h = 23, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1526, .adv_w = 438, .box_w = 25, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1592, .adv_w = 214, .box_w = 12, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1624, .adv_w = 286, .box_w = 17, .box_h = 22, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1671, .adv_w = 392, .box_w = 24, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1734, .adv_w = 329, .box_w = 20, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1787, .adv_w = 491, .box_w = 29, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1864, .adv_w = 403, .box_w = 24, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1927, .adv_w = 394, .box_w = 23, .box_h = 23, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1994, .adv_w = 337, .box_w = 19, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2044, .adv_w = 394, .box_w = 23, .box_h = 29, .ofs_x = 1, .ofs_y = -7},
    {.bitmap_index = 2128, .adv_w = 383, .box_w = 24, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2191, .adv_w = 311, .box_w = 18, .box_h = 23, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 2243, .adv_w = 328, .box_w = 21, .box_h = 21, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2299, .adv_w = 400, .box_w = 24, .box_h = 22, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 2365, .adv_w = 366, .box_w = 24, .box_h = 21, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 2428, .adv_w = 541, .box_w = 35, .box_h = 21, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2520, .adv_w = 388, .box_w = 24, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2583, .adv_w = 351, .box_w = 24, .box_h = 21, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 2646, .adv_w = 331, .box_w = 20, .box_h = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2699, .adv_w = 214, .box_w = 10, .box_h = 26, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 2732, .adv_w = 226, .box_w = 13, .box_h = 30, .ofs_x = 1, .ofs_y = -7},
    {.bitmap_index = 2781, .adv_w = 214, .box_w = 10, .box_h = 26, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 2814, .adv_w = 338, .box_w = 15, .box_h = 10, .ofs_x = 3, .ofs_y = 11},
    {.bitmap_index = 2833, .adv_w = 338, .box_w = 21, .box_h = 2, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 2839, .adv_w = 240, .box_w = 8, .box_h = 7, .ofs_x = 3, .ofs_y = 16},
    {.bitmap_index = 2846, .adv_w = 286, .box_w = 17, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2878, .adv_w = 310, .box_w = 19, .box_h = 23, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 2933, .adv_w = 255, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2962, .adv_w = 318, .box_w = 18, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3014, .adv_w = 274, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3043, .adv_w = 189, .box_w = 15, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3087, .adv_w = 277, .box_w = 17, .box_h = 22, .ofs_x = 1, .ofs_y = -7},
    {.bitmap_index = 3134, .adv_w = 326, .box_w = 20, .box_h = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3192, .adv_w = 170, .box_w = 9, .box_h = 23, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3218, .adv_w = 166, .box_w = 12, .box_h = 30, .ofs_x = -3, .ofs_y = -7},
    {.bitmap_index = 3263, .adv_w = 303, .box_w = 20, .box_h = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3321, .adv_w = 165, .box_w = 10, .box_h = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3350, .adv_w = 488, .box_w = 29, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3405, .adv_w = 331, .box_w = 19, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3441, .adv_w = 305, .box_w = 17, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3473, .adv_w = 316, .box_w = 18, .box_h = 22, .ofs_x = 1, .ofs_y = -7},
    {.bitmap_index = 3523, .adv_w = 311, .box_w = 19, .box_h = 22, .ofs_x = 1, .ofs_y = -7},
    {.bitmap_index = 3576, .adv_w = 250, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3605, .adv_w = 246, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3632, .adv_w = 191, .box_w = 12, .box_h = 20, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3662, .adv_w = 325, .box_w = 19, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3698, .adv_w = 272, .box_w = 18, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3732, .adv_w = 414, .box_w = 26, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3781, .adv_w = 282, .box_w = 17, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3813, .adv_w = 270, .box_w = 18, .box_h = 22, .ofs_x = 0, .ofs_y = -7},
    {.bitmap_index = 3863, .adv_w = 252, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3890, .adv_w = 240, .box_w = 13, .box_h = 27, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 3934, .adv_w = 186, .box_w = 3, .box_h = 30, .ofs_x = 5, .ofs_y = -7},
    {.bitmap_index = 3946, .adv_w = 240, .box_w = 13, .box_h = 27, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 3990, .adv_w = 338, .box_w = 17, .box_h = 5, .ofs_x = 2, .ofs_y = 6}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_Georgia30 = {
#else
lv_font_t ui_font_Georgia30 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 30,          /*The maximum line height required by the font*/
    .base_line = 7,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_GEORGIA30*/

