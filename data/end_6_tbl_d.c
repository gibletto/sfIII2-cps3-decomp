/*
 * END_6_TBL_D.C  tables read by end_6.c: ending 6 (end_06000)
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_200_panel1[];
extern const u16 timer_6_tbl[];
extern const u16 end_6_pos[];

const PANEL end_200_panel1[2] = {
    { 8320, 5 },
    { 8384, 6 },
};

/* provisional name */
const u16 timer_6_tbl[4] = {
    0x1A4, 0x30C, 0x294, 0x2D0,
};

/* provisional name */
const u16 end_6_pos[8] = {
    0x100, 0x100, 0x300, 0x100, 0x100, 0, 0x300, 0,
};
