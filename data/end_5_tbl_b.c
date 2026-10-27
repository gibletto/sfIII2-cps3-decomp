/*
 * END_5_TBL_B.C  Necro's ending tables (ending 5)
 *
 * end_500_bg1_cell_tbl lists the BG1 cells (map offset, cell number) written at the start of
 * the ending, timer_5_tbl is the length in frames of each scene and end_5_pos the BG x and y
 * of each scene; read by END_5.C. end_2000_bg0_cell_tbl and end_2000_ake_cell_tbl are not
 * referred to.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_2000_bg0_cell_tbl[];
extern const PANEL end_2000_ake_cell_tbl[];
extern const PANEL end_500_bg1_cell_tbl[];
extern const s16 timer_5_tbl[];
extern const s16 end_5_pos[][2];

const PANEL end_2000_bg0_cell_tbl[4] = {
    { 4224, 1 },
    { 4288, 2 },
    { 8192, 3 },
    { 8256, 4 },
};

const PANEL end_2000_ake_cell_tbl[4] = {
    { 12288, 5 },
    { 12352, 6 },
    { 12416, 5 },
    { 12480, 6 },
};

/* provisional name */
const PANEL end_500_bg1_cell_tbl[8] = {
    { 0x80, 0xB }, { 0xC0, 0xC }, { 0x1000, 0xF }, { 0x1040, 0x10 },
    { 0x2000, 1 }, { 0x2040, 2 }, { 0x3000, 7 }, { 0x3040, 8 },
};

/* provisional name */
const s16 timer_5_tbl[6] = {
    0x12C, 0x258, 0x168, 0x30C, 0x96, 0x3FC,
};

/* provisional name */
const s16 end_5_pos[6][2] = {
    { 0x100, 0x300 }, { 0x300, 0x300 }, { 0x100, 0x200 }, { 0x300, 0x200 },
    { 0x100, 0x100 }, { 0x100, 0 },
};
