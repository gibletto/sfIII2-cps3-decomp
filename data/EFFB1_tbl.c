/*
 * EFFB1_TBL.C  tables read by effects B1 and B3
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 effB1_wait_table[];
extern const s16 effB1_wait_tbl_2[];
extern const CONN bbbs_clear[];
extern const CONN bbbs_blocking[][20];
extern const s16 effb3_round_tbl[][4];
extern const s16 effb3_final_tbl[][3];
extern const s16 effb3_fight_tbl[][5];
extern const s32 effb3_fight_speed_tbl[][2];

const s16 effB1_wait_table[4] = {
    2, 2, 2, 2,
};

const s16 effB1_wait_tbl_2[4] = {
    2, 2, 2, 2,
};

const CONN bbbs_clear[1] = {
    { 0, 0, 2, 0xB2DC },
};

const CONN bbbs_blocking[2][20] = {
    { { -172, -12, 0, 0xB2D8 }, { -154, -12, 0, 0xB2D8 }, { -136, -12, 0, 0xB2D8 }, { -118, -12, 0, 0xB2D8 }, { -100, -12, 0, 0xB2D8 }, { -82, -12, 0, 0xB2D8 }, { -64, -12, 0, 0xB2D8 }, { -46, -12, 0, 0xB2D8 }, { -28, -12, 0, 0xB2D8 }, { -10, -12, 0, 0xB2D8 }, { -172, 4, 0, 0xB2D8 }, { -154, 4, 0, 0xB2D8 }, { -136, 4, 0, 0xB2D8 }, { -118, 4, 0, 0xB2D8 }, { -100, 4, 0, 0xB2D8 }, { -82, 4, 0, 0xB2D8 }, { -172, 20, 0, 0xB2D8 }, { -154, 20, 0, 0xB2D8 }, { -136, 20, 0, 0xB2D8 }, { -172, 36, 0, 0xB2D8 } },
    { { -228, -12, 0, 0xB2D8 }, { -204, -12, 0, 0xB2D8 }, { -180, -12, 0, 0xB2D8 }, { -156, -12, 0, 0xB2D8 }, { -132, -12, 0, 0xB2D8 }, { -108, -12, 0, 0xB2D8 }, { -84, -12, 0, 0xB2D8 }, { -60, -12, 0, 0xB2D8 }, { -36, -12, 0, 0xB2D8 }, { -12, -12, 0, 0xB2D8 }, { -228, 4, 0, 0xB2D8 }, { -204, 4, 0, 0xB2D8 }, { -180, 4, 0, 0xB2D8 }, { -156, 4, 0, 0xB2D8 }, { -132, 4, 0, 0xB2D8 }, { -108, 4, 0, 0xB2D8 }, { -228, 20, 0, 0xB2D8 }, { -204, 20, 0, 0xB2D8 }, { -180, 20, 0, 0xB2D8 }, { -228, 36, 0, 0xB2D8 } },
};

const s16 effb3_round_tbl[5][4] = {
    { 1, -112, -70, 128 },
    { 2, -56, -39, 128 },
    { 3, 2, -8, 128 },
    { 4, 64, 22, 128 },
    { 5, 120, 52, 128 },
};

const s16 effb3_final_tbl[10][3] = {
    { 1, -60, 136 },
    { 2, -37, 136 },
    { 3, -14, 136 },
    { 4, 9, 136 },
    { 5, 32, 136 },
    { 6, -41, 108 },
    { 7, -18, 108 },
    { 8, 4, 108 },
    { 9, 27, 108 },
    { 10, 49, 108 },
};

const s16 effb3_fight_tbl[6][5] = {
    { 1, 0, 80, -74, 128 },
    { 2, 0, 80, -34, 128 },
    { 3, 0, 80, 0, 128 },
    { 4, 0, 80, 44, 128 },
    { 5, 0, 80, 92, 128 },
    { -76, -36, 0, 42, 90 },
};

const s32 effb3_fight_speed_tbl[5][2] = {
    { -393216, -32768 },
    { -262144, -8192 },
    { 0, 0 },
    { 262144, 8192 },
    { 524288, 16384 },
};
