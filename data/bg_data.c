/*
 * BG_DATA.C  stage background index table
 *
 * bg_index_tbl gives the background number (bg_index) for each stage and area, and every other
 * stage background table is indexed by it; etc_bg_pos_tbl is the starting x and y of each
 * layer of the special screens. Read by BG000.C (bg_initialize, bg_end_initialize,
 * bg_etc_write). bg_index_tbl_tail, which follows bg_index_tbl, and bg_test_menu_scr, the
 * position lines of the background test (strings in BG_DATA2.C), are not referred to.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 bg_index_tbl[][3];
extern const s16 bg_index_tbl_tail[];
extern const s32 etc_bg_pos_tbl[][4][2];
extern const TM_STRING bg_test_menu_scr[];
extern const char str_BG_1_POS_X[];
extern const char str_BG_1_POS_Y[];
extern const char str_BG_2_POS_X[];
extern const char str_BG_2_POS_Y[];
extern const char str_BG_3_POS_X[];
extern const char str_BG_3_POS_Y[];
extern const char str_BG_4_POS_X[];
extern const char str_BG_4_POS_Y[];
extern const char str_BG_1[];
extern const char str_BG_2[];
extern const char str_BG_3[];
extern const char str_BG_4[];
extern const char str_STAGE[];
extern const char str_AREA[];

const s16 bg_index_tbl[18][3] = {
    { 0, 0, 0 },
    { 1, 1, 1 },
    { 2, 2, 2 },
    { 3, 3, 3 },
    { 4, 4, 4 },
    { 5, 5, 5 },
    { 6, 6, 6 },
    { 7, 7, 7 },
    { 8, 9, 9 },
    { 10, 10, 10 },
    { 11, 11, 11 },
    { 12, 12, 12 },
    { 13, 13, 13 },
    { 14, 14, 14 },
    { 15, 15, 15 },
    { 15, 15, 15 },
    { 16, 16, 16 },
    { 17, 17, 17 },
};

const s16 bg_index_tbl_tail[30] = {
    256, 256, 312, 0, 0, 0, 256, 256,
    312, 0, 0, 0, 256, 256, 312, 0,
    0, 0, 256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
};

/* provisional name */
const s32 etc_bg_pos_tbl[5][4][2] = {
    { { 0x2000000, -0x300000 }, { 0x2000000, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0x1D80000, 0 }, { 0x2000000, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0x2000000, 0 }, { 0x2000000, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0x2000000, 0 }, { 0x2000000, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0x2000000, 0 }, { 0x2000000, 0 }, { 0, 0 }, { 0, 0 } },
};

/* the text lines of the background test's position display; nothing in the program refers to them (provisional name) */
const TM_STRING bg_test_menu_scr[14] = {
    { 0x1E, 0x14, 0xE, (const s8 *)str_BG_1_POS_X },
    { 0x1E, 0x15, 0xE, (const s8 *)str_BG_1_POS_Y },
    { 0x1E, 0x16, 0xE, (const s8 *)str_BG_2_POS_X },
    { 0x1E, 0x17, 0xE, (const s8 *)str_BG_2_POS_Y },
    { 0x1E, 0x18, 0xE, (const s8 *)str_BG_3_POS_X },
    { 0x1E, 0x19, 0xE, (const s8 *)str_BG_3_POS_Y },
    { 0x1E, 0x1A, 0xE, (const s8 *)str_BG_4_POS_X },
    { 0x1E, 0x1B, 0xE, (const s8 *)str_BG_4_POS_Y },
    { 3, 0x16, 0xE, (const s8 *)str_BG_1 },
    { 3, 0x17, 0xE, (const s8 *)str_BG_2 },
    { 3, 0x18, 0xE, (const s8 *)str_BG_3 },
    { 3, 0x19, 0xE, (const s8 *)str_BG_4 },
    { 3, 0x13, 0xE, (const s8 *)str_STAGE },
    { 3, 0x14, 0xE, (const s8 *)str_AREA },
};
