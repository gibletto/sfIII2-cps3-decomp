/*
 * END_3_TBL.C  Yun and Yang's ending tables (ending 3)
 *
 * end_300_panel lists the BG cells (map offset, cell number) written at the start of the
 * ending, end_3_pos the BG x and y of its scenes and timer_3_tbl the length in frames of each
 * scene. Read by END_3.C, which plays the ending for both Yun and Yang.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_300_panel[];
extern const s16 end_3_pos[][2];
extern const s16 timer_3_tbl[];

/* provisional name */
const PANEL end_300_panel[8] = {
    { 0, 3 }, { 0x40, 4 }, { 0x80, 5 }, { 0xC0, 6 },
    { 0x1000, 7 }, { 0x1040, 8 }, { 0x1080, 0xA }, { 0x10C0, 0xB },
};

/* provisional name */
const s16 end_3_pos[9][2] = {
    { 0xB0, 0x310 }, { 0x2E0, 0x300 }, { 0x100, 0x200 }, { 0x100, 0x100 },
    { 0x100, 0x200 }, { 0xB0, 0x300 }, { 0x2F0, 0x300 }, { 0x100, 0x200 },
    { 0x300, 0x200 },
};

/* provisional name */
const s16 timer_3_tbl[10] = {
    0xBE, 0xBE, 0x168, 0x1A4, 0x168, 0xB4, 0xB4, 0xB4,
    0x1E0, -1,
};

