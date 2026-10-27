/*
 * EFF58_TBL.C  palette step tables
 *
 * eff56_color_tbl gives the eight palette numbers of each of the two cycles and
 * eff56_timer_tbl the time of each step. Read by EFF56.C, the palette steps.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u8 eff56_color_tbl[][8];
extern const u8 eff56_timer_tbl[][8];

const u8 eff56_color_tbl[2][8] = {
    { 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA3, 0xA2, 0xA1 },
    { 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xA8, 0xA7, 0xA6 },
};

const u8 eff56_timer_tbl[2][8] = {
    { 4, 3, 2, 3, 4, 3, 2, 3 },
    { 2, 1, 1, 1, 2, 1, 1, 1 },
};
