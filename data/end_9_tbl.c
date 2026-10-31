/*
 * END_9_TBL.C  Oro's ending tables (ending 9)
 *
 * end_900_bg0_cell_tbl lists the BG0 cells (map offset, cell number) written at the start of
 * the ending, timer_9_tbl is the length in frames of each scene and end_9_pos the BG x and y
 * of each scene. Read by END_9.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_900_bg0_cell_tbl[];
extern const s16 timer_9_tbl[];
extern const s16 end_9_pos[][2];

const PANEL end_900_bg0_cell_tbl[7] = {
    { 0x2000, 1 },
    { 0x2040, 2 },
    { 0x2080, 3 },
    { 0x3000, 4 },
    { 0x3040, 5 },
    { 0x3080, 6 },
    { 0x30C0, 7 },
};

const s16 timer_9_tbl[7] = {
    240, 240, 240, 180, 180, 180, 660,
};

const s16 end_9_pos[7][2] = {
    { 768, 256 },
    { 768, 256 },
    { 768, 256 },
    { 768, 256 },
    { 768, 256 },
    { 768, 256 },
    { 768, 48 },
};

/* end mark of end_9_pos (nothing reads it) */
static const s16 end_9_pos_end = -1;
