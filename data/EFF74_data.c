/*
 * EFF74_DATA.C  tables read by Com_Sub.c, EFF75_ORDER.c and 3 other modules
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s32 eff75_speed_tbl[][4];
extern const s16 eff77_data_tbl[][3];
extern const u16 EFF74_06179EA2[];
extern const s16 eff79_plate_pos[][6];
extern const s32 Pos_Z_Data_79[];
extern const s8 Time_Data[];

const s32 eff75_speed_tbl[6][4] = {
    { -2621440, 163840, 524288, -32768 },
    { 131072, 0, 1703936, -106496 },
    { 2621440, -163840, 524288, -32768 },
    { -2621440, 163840, -524288, 32768 },
    { -131072, 0, -1703936, 106496 },
    { 2621440, -163840, -524288, 32768 },
};

const s16 eff77_data_tbl[3][3] = {
    { 64, 256, 256 },
    { 2, 768, 256 },
    { 1, 256, 0 },
};

/* provisional name */
const u16 EFF74_06179EA2[1] = {
    0xFFFF,
};

/* provisional name */
const s16 eff79_plate_pos[2][6] = {
    { 608, 124, 620, 152, 608, 180 },
    { 798, 124, 786, 152, 798, 180 },
};

const s32 Pos_Z_Data_79[3] = {
    10, 0, 5,
};

const s8 Time_Data[8] = {
    80, 90, 50, 50, 50, -1, -1, -1,
};
