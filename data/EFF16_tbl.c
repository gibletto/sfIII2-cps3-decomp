/*
 * EFF16_TBL.C  bonus stage score display and zoom piece tables
 *
 * bunkai_table holds the powers of ten used to split the score into digits, bunkai_numobj the
 * character of each digit, and bbbs_score the screen position and character of each digit of
 * the score display of each type; read by EFF16.C, the bonus-stage score display.
 * eff17_data_tbl gives the settings of the nine zoom-in pieces of effect 17, read by EFF18.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u32 bunkai_table[];
extern const u16 bunkai_numobj[];
extern const CONN bbbs_score[][7];
extern const s16 eff17_data_tbl[][5];

const u32 bunkai_table[7] = {
    1, 0xA, 0x64, 0x3E8,
    0x2710, 0x186A0, 0xF4240,
};

const u16 bunkai_numobj[10] = {
    0xB2CD, 0xB2CE, 0xB2CF, 0xB2D0, 0xB2D1, 0xB2D2, 0xB2D3, 0xB2D4,
    0xB2D5, 0xB2D6,
};

const CONN bbbs_score[4][7] = {
    { { -80, 164, 0, 0xB2CD }, { -96, 164, 0, 0xB2CD }, { -112, 164, 0, 0xB2CD }, { -128, 164, 0, 0xB2CD }, { -144, 164, 0, 0xB2CD }, { -160, 164, 0, 0xB2CD }, { -176, 164, 0, 0xB2CD } },
    { { 176, 164, 0, 0xB2CD }, { 160, 164, 0, 0xB2CD }, { 144, 164, 0, 0xB2CD }, { 128, 164, 0, 0xB2CD }, { 112, 164, 0, 0xB2CD }, { 96, 164, 0, 0xB2CD }, { 80, 164, 0, 0xB2CD } },
    { { -120, 164, 0, 0xB2CD }, { -136, 164, 0, 0xB2CD }, { -152, 164, 0, 0xB2CD }, { -168, 164, 0, 0xB2CD }, { -184, 164, 0, 0xB2CD }, { -200, 164, 0, 0xB2CD }, { -216, 164, 0, 0xB2CD } },
    { { 216, 164, 0, 0xB2CD }, { 200, 164, 0, 0xB2CD }, { 184, 164, 0, 0xB2CD }, { 168, 164, 0, 0xB2CD }, { 152, 164, 0, 0xB2CD }, { 136, 164, 0, 0xB2CD }, { 120, 164, 0, 0xB2CD } },
};

const s16 eff17_data_tbl[9][5] = {
    { 396, 144, 28, 1, 0 },
    { 422, 144, 27, 2, 3 },
    { 451, 144, 26, 3, 6 },
    { 478, 144, 25, 4, 9 },
    { 505, 144, 24, 5, 12 },
    { 543, 144, 23, 6, 15 },
    { 569, 144, 22, 7, 18 },
    { 599, 144, 21, 8, 21 },
    { 629, 144, 20, 9, 24 },
};

/* end mark of eff17_data_tbl (nothing reads it) */
static const s16 eff17_data_tbl_end = -1;
