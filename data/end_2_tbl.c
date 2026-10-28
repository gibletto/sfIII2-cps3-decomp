/*
 * END_2_TBL.C  Ryu's ending tables (ending 2)
 *
 * timer_2_tbl is the length in frames of each of the ending's four scenes; read by END_2.C.
 * end_200_panel0 lists BG0 cells (map offset, cell number) for end_200_cell_set in END_2.C,
 * which nothing calls.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_200_panel0[];
extern const s16 timer_2_tbl[];

/* provisional name */
const PANEL end_200_panel0[8] = {
    { 0, 3 }, { 0x40, 4 }, { 0x80, 5 }, { 0xC0, 6 },
    { 0x1000, 7 }, { 0x1040, 8 }, { 0x1080, 10 }, { 0x10C0, 11 },
};

const s16 timer_2_tbl[4] = {
    420, 360, 180, 1200,
};
