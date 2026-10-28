/*
 * END_6_TBL.C  Hugo's ending BG0 cell list (ending 6)
 *
 * end_600_bg0_cell_tbl lists the BG0 cells (map offset, cell number) written at the start of
 * Hugo's ending. Read by END_6.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_600_bg0_cell_tbl[];

const PANEL end_600_bg0_cell_tbl[8] = {
    { 0x2000, 7 },
    { 0x2040, 8 },
    { 0x2080, 9 },
    { 0x20C0, 10 },
    { 0x3000, 1 },
    { 0x3040, 2 },
    { 0x3080, 3 },
    { 0x30C0, 4 },
};
