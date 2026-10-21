/*
 * EFFI0_TBL.C  tables read by effects I0 and I3
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 char_of_koishi[];
extern const s16 num_of_koishi[];
extern const s16 koishi_area_hosei[];
extern const s16 koishi_app_area[][16];
extern const s16 koishi_speed_x[][8];
extern const s16 koishi_speed_y[][8];
extern const s16 EFFI0_tbl_0617E71A[];
extern const u8 effI2_col_tbl[];
extern const u8 effI2_timer_tbl[];

const s16 char_of_koishi[8] = {
    85, 86, 87, 85, 86, 87, 85, 86,
};

const s16 num_of_koishi[8] = {
    6, 7, 8, 10, 12, 14, 15, 16,
};

const s16 koishi_area_hosei[5] = {
    0, 20, -20, 40, -40,
};

const s16 koishi_app_area[8][16] = {
    { 0, 1, 2, 3, 4, 3, 2, 1, 0, 1, 2, 3, 4, 3, 2, 1 },
    { 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0 },
    { 3, 4, 3, 4, 1, 2, 1, 2, 0, 0, 1, 2, 3, 4, 3, 4 },
    { 3, 4, 3, 0, 1, 2, 4, 3, 4, 3, 0, 1, 2, 4, 3, 4 },
    { 1, 2, 1, 2, 3, 4, 3, 4, 0, 0, 1, 2, 1, 2, 3, 4 },
    { 0, 2, 4, 1, 3, 1, 3, 2, 4, 0, 1, 2, 3, 4, 1, 2 },
    { 2, 3, 1, 2, 0, 0, 4, 4, 0, 2, 3, 1, 4, 2, 4, 3 },
    { 2, 4, 2, 4, 0, 1, 3, 0, 1, 3, 2, 2, 4, 0, 1, 3 },
};

const s16 koishi_speed_x[5][8] = {
    { 64, -64, 128, -128, 256, -256, 384, -384 },
    { -256, -384, -512, -640, -768, -896, -1024, -1280 },
    { 384, 512, 640, 768, 896, 1024, 1152, 1408 },
    { -768, -896, -1024, -1152, -1280, -1408, -1536, -1664 },
    { 896, 1024, 1152, 1280, 1408, 1536, 1664, 2048 },
};

const s16 koishi_speed_y[5][8] = {
    { 768, 1024, 1152, 1280, 1408, 1536, 1792, 2048 },
    { 640, 704, 768, 832, 896, 1024, 1280, 1536 },
    { 576, 640, 704, 768, 832, 896, 1152, 1408 },
    { 512, 576, 640, 704, 768, 896, 1024, 1152 },
    { 512, 448, 512, 576, 640, 704, 896, 1024 },
};

/* provisional name */
const s16 EFFI0_tbl_0617E71A[1] = {
    -1,
};

const u8 effI2_col_tbl[10] = {
    8, 0xD, 0xE, 0xF, 0x10, 0x11, 0x10, 0xF, 0xE, 0xD,
};

const u8 effI2_timer_tbl[10] = {
    9, 8, 7, 6, 5, 4, 5, 6, 7, 8,
};
