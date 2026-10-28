/*
 * BG_DATA2.C  screen quake, stage colour and finish screen cell tables
 *
 * quake_x_tbl and quake_y_tbl are the screen shake offsets stepped by the quake index; read by
 * BG000.C and TA_SUB.C, quake_y_tbl also by END_5.C. bg_palette_no_tbl, bg_color2_tbl and
 * bg_color3_tbl are each background's colour loads, read by GAME_MAIN.C and MANAGE_2.C (the
 * first two also by BG000.C and CMD_MAIN.C); etc_bg_color_tbl is the colour load of each
 * special screen, read by BG000.C, and bg_fade_level_tbl each background's colour fade level,
 * read by BG000.C and the stage modules BGST020.C - BGST110.C (all but BGST070.C). mark_cg_tbl
 * lists the mark graphics loaded by ABOUTSPR.C, and ake_cell0_data - ake_cell4_data are the
 * finish screen cell panels written by akebono_scr_write in BG000.C. The str_ strings are the
 * text of bg_test_menu_scr in BG_DATA.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 quake_x_tbl[];
extern const s16 quake_y_tbl[];
extern const u16 bg_color2_tbl[];
extern const u16 bg_palette_no_tbl[];
extern const u16 etc_bg_color_tbl[];
extern const u16 bg_color3_tbl[];
extern const u8 bg_fade_level_tbl[];
extern const u16 mark_cg_tbl[];
extern const PANEL ake_cell1_data[];
extern const PANEL ake_cell0_data[];
extern const PANEL ake_cell4_data[];
extern const PANEL ake_cell3_data[];
extern const PANEL ake_cell2_data[];
extern const s8 str_BG_1_POS_X[];
extern const s8 str_BG_1_POS_Y[];
extern const s8 str_BG_2_POS_X[];
extern const s8 str_BG_2_POS_Y[];
extern const s8 str_BG_3_POS_X[];
extern const s8 str_BG_3_POS_Y[];
extern const s8 str_BG_4_POS_X[];
extern const s8 str_BG_4_POS_Y[];
extern const s8 str_BG_1[];
extern const s8 str_BG_2[];
extern const s8 str_BG_3[];
extern const s8 str_BG_4[];
extern const s8 str_STAGE[];
extern const s8 str_AREA[];

const s16 quake_x_tbl[130] = {
    0, -1, 1, -1, 1, -1, 1, -2,
    2, -2, 2, -2, 2, -3, 3, -3,
    3, -3, 3, -4, 4, -4, 4, -4,
    4, -5, 5, -5, 5, -5, 5, -6,
    6, -6, 6, -6, 6, -7, 7, -7,
    7, -7, 7, -8, 8, -8, 8, -8,
    8, -9, 9, -9, 9, -9, 9, -10,
    10, -10, 10, -10, 10, -11, 11, -11,
    11, -12, 12, -12, 12, -13, 13, -13,
    13, -14, 14, -14, 14, -15, 15, -15,
    15, -15, 15, -15, 15, -15, 15, -15,
    15, -15, 15, -15, 15, -15, 15, -15,
    15, -15, 15, -15, 15, -15, 15, -15,
    15, -15, 15, -15, 15, -15, 15, -15,
    15, -15, 15, -15, 15, -15, 15, -15,
    15, -15, 15, -15, 15, -15, 15, -15,
    15, -15,
};

const s16 quake_y_tbl[130] = {
    0, -1, 1, -2, 2, -2, 2, -3,
    3, -3, 3, -4, 4, -4, 4, -5,
    5, -5, 5, -6, 6, -6, 6, -7,
    7, -7, 7, -8, 8, -8, 8, -9,
    9, -9, 9, -10, 10, -10, 10, -10,
    10, -11, 11, -11, 11, -12, 12, -12,
    12, -13, 13, -11, 11, -11, 11, -12,
    12, -12, 12, -13, 13, -11, 11, -11,
    11, -12, 12, -12, 12, -13, 13, -13,
    13, -14, 14, -14, 14, -15, 15, -15,
    15, -15, 15, -15, 15, -15, 15, -15,
    15, -15, 15, -15, 15, -15, 15, -15,
    15, -15, 15, -15, 15, -15, 15, -15,
    15, -15, 15, -15, 15, -15, 15, -15,
    15, -15, 15, -15, 15, -15, 15, -15,
    15, -15, 15, -15, 15, -15, 15, -15,
    15, -15,
};

/* provisional name */
const u16 bg_color2_tbl[18] = {
    0x45, 0x46, 0x49, 0x4A, 0x4C, 0x4E, 0x4F, 0x50,
    0x53, 0x54, 0x55, 0x4B, 0x9A, 0x9E, 0x98, 0x96,
    0x4F, 8,
};

/* provisional name */
const u16 bg_palette_no_tbl[18] = {
    0x34, 0x35, 0x38, 0x39, 0x3B, 0x3D, 0x3E, 0x3F,
    0x42, 0x43, 0x44, 0x3A, 0x99, 0x9D, 0x97, 0x95,
    0x3E, 8,
};

/* provisional name */
const u16 etc_bg_color_tbl[5] = {
    6, 6, 6, 10, 10,
};

/* provisional name */
const u16 bg_color3_tbl[17] = {
    0x35, 0x67, 0x6A, 0x65, 0x61, 0x60, 0x3F, 0x62,
    0x63, 0x6C, 0x6B, 0x99, 0x9D, 0x97, 0x95, 0x60,
    8,
};

/* provisional name */
const u8 bg_fade_level_tbl[18] = {
    0x13, 0xF, 0xF, 0xF, 0xF, 0x13, 0xF, 0xF, 0x11, 0x11, 0xF, 0x13, 0xF, 0xF, 0xF, 0xF,
    0xF, 0xF,
};

/* provisional name */
const u16 mark_cg_tbl[45] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x18, 0x19, 0x1A, 0x40, 0x41, 0x42, 0x43, 0x44,
    0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C,
    0x4D, 0x4E, 0x4F, 0x50, 0x50,
};

/* provisional name */
const PANEL ake_cell1_data[8] = {
    { 0x2000, 5 }, { 0x2040, 6 }, { 0x2080, 7 }, { 0x20C0, 8 },
    { 0x3000, 1 }, { 0x3040, 2 }, { 0x3080, 3 }, { 0x30C0, 4 },
};

/* provisional name */
const PANEL ake_cell0_data[16] = {
    { 0x0, 15 }, { 0x40, 16 }, { 0x80, 17 }, { 0xC0, 18 },
    { 0x1000, 19 }, { 0x1040, 20 }, { 0x1080, 21 }, { 0x10C0, 22 },
    { 0x2000, 15 }, { 0x2040, 16 }, { 0x2080, 17 }, { 0x20C0, 18 },
    { 0x3000, 19 }, { 0x3040, 20 }, { 0x3080, 21 }, { 0x30C0, 22 },
};

/* provisional name */
const PANEL ake_cell4_data[16] = {
    { 0x0, 39 }, { 0x40, 40 }, { 0x80, 41 }, { 0xC0, 42 },
    { 0x1000, 43 }, { 0x1040, 44 }, { 0x1080, 45 }, { 0x10C0, 46 },
    { 0x2000, 39 }, { 0x2040, 40 }, { 0x2080, 41 }, { 0x20C0, 42 },
    { 0x3000, 43 }, { 0x3040, 44 }, { 0x3080, 45 }, { 0x30C0, 46 },
};

/* provisional name */
const PANEL ake_cell3_data[16] = {
    { 0x0, 31 }, { 0x40, 32 }, { 0x80, 33 }, { 0xC0, 34 },
    { 0x1000, 35 }, { 0x1040, 36 }, { 0x1080, 37 }, { 0x10C0, 38 },
    { 0x2000, 23 }, { 0x2040, 24 }, { 0x2080, 25 }, { 0x20C0, 26 },
    { 0x3000, 27 }, { 0x3040, 28 }, { 0x3080, 29 }, { 0x30C0, 30 },
};

/* provisional name */
const PANEL ake_cell2_data[8] = {
    { 0x2000, 9 }, { 0x2040, 10 }, { 0x2080, 11 }, { 0x20C0, 12 },
    { 0x3000, 11 }, { 0x3040, 12 }, { 0x3080, 13 }, { 0x30C0, 14 },
};

const s8 str_BG_1_POS_X[16] = "BG 1 POS X = \n\0\xFF";

const s8 str_BG_1_POS_Y[16] = "BG 1 POS Y = \n\0\xFF";

const s8 str_BG_2_POS_X[16] = "BG 2 POS X = \n\0\xFF";

const s8 str_BG_2_POS_Y[16] = "BG 2 POS Y = \n\0\xFF";

const s8 str_BG_3_POS_X[16] = "BG 3 POS X = \n\0\xFF";

const s8 str_BG_3_POS_Y[16] = "BG 3 POS Y = \n\0\xFF";

const s8 str_BG_4_POS_X[16] = "BG 4 POS X = \n\0\xFF";

const s8 str_BG_4_POS_Y[16] = "BG 4 POS Y = \0\xFF\xFF";

const s8 str_BG_1[12] = "BG 1 = \n\0\xFF\xFF\xFF";

const s8 str_BG_2[12] = "BG 2 = \n\0\xFF\xFF\xFF";

const s8 str_BG_3[12] = "BG 3 = \n\0\xFF\xFF\xFF";

const s8 str_BG_4[8] = "BG 4 = ";

const s8 str_STAGE[12] = "STAGE = \n\0\xFF\xFF";

const s8 str_AREA[12] = "AREA  = \0\xFF\xFF\xFF";
