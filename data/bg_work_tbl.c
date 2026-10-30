/*
 * BG_WORK_TBL.C  background layer 0 cell list
 *
 * end_1100_bg0_cell_tbl is a cell list (map offset, cell number) for background layer 0,
 * reached through bg_rewrite_cell_tbl in BG_WORK.C and written by bg_scr_write in BG000.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const HUD_CELL end_1100_bg0_cell_tbl[];

const HUD_CELL end_1100_bg0_cell_tbl[8] = {
    { 0x2000, 1 },
    { 0x2040, 2 },
    { 0x2080, 3 },
    { 0x20C0, 4 },
    { 0x3000, 5 },
    { 0x3040, 6 },
    { 0x3080, 7 },
    { 0x30C0, 8 },
};
