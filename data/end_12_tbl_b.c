/*
 * END_12_TBL_B.C  tables read by end_12.c: ending 12, 2nd Impact version
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_1200_panel1[];
extern const s16 timer_12_tbl[];
extern const u16 end_12_tbl_06165C56[];
extern const u16 end_12_pos[];

const PANEL end_1200_panel1[8] = {
    { 8192, 0 },
    { 8256, 0 },
    { 8320, 3 },
    { 8384, 4 },
    { 12288, 7 },
    { 12352, 8 },
    { 12416, 0 },
    { 12480, 0 },
};

const s16 timer_12_tbl[3] = {
    600, 420, 900,
};

/* provisional name */
const u16 end_12_tbl_06165C56[1] = {
    0x3FC,
};

/* provisional name */
const u16 end_12_pos[8] = {
    0x100, 0x100, 0x300, 0x100, 0x100, 0, 0x300, 0,
};
