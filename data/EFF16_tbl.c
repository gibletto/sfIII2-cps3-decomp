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
extern const u32 eff17_data_tbl[];

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

const u32 eff17_data_tbl[23] = {
    0x18C0090, 0x1C0001, 0x1A6, 0x90001B,
    0x20003, 0x1C30090, 0x1A0003, 0x601DE,
    0x900019, 0x40009, 0x1F90090, 0x180005,
    0xC021F, 0x900017, 0x6000F, 0x2390090,
    0x160007, 0x120257, 0x900015, 0x80015,
    0x2750090, 0x140009, 0x18FFFF,
};
