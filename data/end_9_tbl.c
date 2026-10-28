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
    { 8192, 1 },
    { 8256, 2 },
    { 8320, 3 },
    { 12288, 4 },
    { 12352, 5 },
    { 12416, 6 },
    { 12480, 7 },
};

/* provisional name */
const s16 timer_9_tbl[7] = {
    0xF0, 0xF0, 0xF0, 0xB4, 0xB4, 0xB4, 0x294,
};

/* provisional name */
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
