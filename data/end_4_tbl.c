/*
 * END_4_TBL.C  tables read by end_4.c: ending 4, 2nd Impact version
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 end_4_panel_data[];
extern const u16 timer_4_tbl[];
extern const u16 end_4_tbl_06165488[];
extern const u16 end_4_pos[];

/* provisional name: the two panels of end_4_panel_p (op_end_work.c) */
const u16 end_4_panel_data[80] = {
    0, 0, 0, 0x52, 0, 0x40, 0, 0x53,
    0, 0x80, 0, 0x54, 0, 0xC0, 0, 0x55,
    0, 0x1000, 0, 0x50, 0, 0x1040, 0, 0x51,
    0, 0x1080, 0, 0, 0, 0x10C0, 0, 0,
    0, 0x2000, 0, 0x4E, 0, 0x2040, 0, 0x4F,
    0, 0, 0, 0x4C, 0, 0x40, 0, 0x4D,
    0, 0x80, 0, 0x34, 0, 0xC0, 0, 0x35,
    0, 0x1000, 0, 0x34, 0, 0x1040, 0, 0x35,
    0, 0x1080, 0, 0, 0, 0x10C0, 0, 0,
    0, 0x2000, 0, 0, 0, 0x2040, 0, 0,
};

/* provisional name */
const u16 timer_4_tbl[2] = {
    0x21C, 0x168,
};

/* provisional name */
const u16 end_4_tbl_06165488[3] = {
    0xB4, 0x258, 0x1E0,
};

/* provisional name */
const u16 end_4_pos[11] = {
    0x100, 0x300, 0x100, 0x200, 0x300, 0x300, 0x100, 0x100,
    0x100, 0x100, 0xFFFF,
};
