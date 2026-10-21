/*
 * END_2_CTBL.C  tables read by end_2.c: ending 2 (end_02000), 2nd Impact version
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u32 end_200_panel0[];
extern const s16 timer_2_tbl[];

/* provisional name */
const u32 end_200_panel0[16] = {
    0, 3, 0x40, 4,
    0x80, 5, 0xC0, 6,
    0x1000, 7, 0x1040, 8,
    0x1080, 0xA, 0x10C0, 0xB,
};

const s16 timer_2_tbl[4] = {
    420, 360, 180, 1200,
};
