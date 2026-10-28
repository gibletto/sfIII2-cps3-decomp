/*
 * END_6_TBL_C.C  Hugo's ending BG1 cell list (ending 6)
 *
 * end_600_bg1_cell_tbl lists the BG1 cells (map offset, cell number) written at the start of
 * Hugo's ending. Read by END_6.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_600_bg1_cell_tbl[];

const PANEL end_600_bg1_cell_tbl[2] = {
    { 0x2000, 5 },
    { 0x2040, 6 },
};
