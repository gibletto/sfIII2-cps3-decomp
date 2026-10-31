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
extern const s16 timer_8_tbl[];
extern const s16 end_8_pos[][2];

/* provisional name */
const u16 end_7_anm_tbl[8] = {
    0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51,
};

/* provisional name */
const PANEL end_800_panel0[8] = {
    { 0x1000, 86 },
    { 0x1040, 87 },
    { 0x2000, 92 },
    { 0x2040, 93 },
    { 0x2080, 96 },
    { 0x20C0, 97 },
    { 0x3080, 30 },
    { 0x30C0, 31 },
};

/* provisional name */
const PANEL end_800_panel1[8] = {
    { 0x1000, 94 },
    { 0x1040, 95 },
    { 0x2000, 90 },
    { 0x2040, 91 },
    { 0x2080, 94 },
    { 0x20C0, 95 },
    { 0x3080, 98 },
    { 0x30C0, 99 },
};

const s16 timer_8_tbl[4] = {
    780, 300, 480, 480,
};

const s16 end_8_pos[4][2] = {
    { 256, 256 }, { 768, 256 }, { 256, 512 }, { 768, 0 },
};
