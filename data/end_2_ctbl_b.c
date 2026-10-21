/*
 * END_2_CTBL_B.C  tables read by end_3.c: ending 3
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u32 end_300_panel[];
extern const u16 end_3_pos[];
extern const u16 timer_3_tbl[];
extern const u16 end_2_ctbl_06165398[];

/* provisional name */
const u32 end_300_panel[16] = {
    0, 3, 0x40, 4,
    0x80, 5, 0xC0, 6,
    0x1000, 7, 0x1040, 8,
    0x1080, 0xA, 0x10C0, 0xB,
};

/* provisional name */
const u16 end_3_pos[18] = {
    0xB0, 0x310, 0x2E0, 0x300, 0x100, 0x200, 0x100, 0x100,
    0x100, 0x200, 0xB0, 0x300, 0x2F0, 0x300, 0x100, 0x200,
    0x300, 0x200,
};

/* provisional name */
const u16 timer_3_tbl[8] = {
    0xBE, 0xBE, 0x168, 0x1A4, 0x168, 0xB4, 0xB4, 0xB4,
};

/* provisional name */
const u16 end_2_ctbl_06165398[2] = {
    0x1E0, 0xFFFF,
};
