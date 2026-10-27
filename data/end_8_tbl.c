/*
 * END_8_TBL.C  Elena's ending tables (ending 8)
 *
 * end_800_panel0 and end_800_panel1 are BG cell lists (map offset, cell number), reached
 * through end_8_panel_p in OP_END_WORK.C; timer_8_tbl is the length in frames of each scene
 * and end_8_pos the BG x and y of each scene; these are read by END_8.C. end_7_anm_tbl, the
 * steps of a layer's cell animation in Ibuki's ending, is read by END_7.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 end_7_anm_tbl[];
extern const PANEL end_800_panel0[];
extern const PANEL end_800_panel1[];
extern const u16 timer_8_tbl[];
extern const u16 end_8_pos[];

/* provisional name */
const u16 end_7_anm_tbl[8] = {
    0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51,
};

/* provisional name */
const PANEL end_800_panel0[8] = {
    { 4096, 86 },
    { 4160, 87 },
    { 8192, 92 },
    { 8256, 93 },
    { 8320, 96 },
    { 8384, 97 },
    { 12416, 30 },
    { 12480, 31 },
};

/* provisional name */
const PANEL end_800_panel1[8] = {
    { 4096, 94 },
    { 4160, 95 },
    { 8192, 90 },
    { 8256, 91 },
    { 8320, 94 },
    { 8384, 95 },
    { 12416, 98 },
    { 12480, 99 },
};

/* provisional name */
const u16 timer_8_tbl[4] = {
    0x30C, 0x12C, 0x1E0, 0x1E0,
};

/* provisional name */
const u16 end_8_pos[8] = {
    0x100, 0x100, 0x300, 0x100, 0x100, 0x200, 0x300, 0,
};
