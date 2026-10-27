/*
 * EFF14_TBL.C  background colour-cycle scripts
 *
 * eff14_ofs_tbl is the map offset of each id's cell rectangle; eff14_data_tbl points each id
 * at its script (eff14_script_n: rows of timer and colour, looping at a -1 timer), its cell
 * pattern mask (eff14_pattern_n, 1 = recolour) and its size in columns and rows
 * (eff14_size_n). Read by EFF14.C, the colour animation started by the stage 07, 08, 09 and 15
 * backgrounds.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

/* a script step: the frames it lasts, then the colour, a big-endian word (EFF14.C reads it with *(s16*)) */
#define EFF14_STEP(time, col)   0, (time), (s8)((col) >> 8), (s8)(col)
#define EFF14_END               -1, -1

extern const u16 eff14_ofs_tbl[];
extern const s8 eff14_script_0[];
extern const s8 eff14_script_1[];
extern const s8 eff14_script_2[];
extern const s8 eff14_script_3[];
extern const s8 eff14_script_4[];
extern const s8 eff14_script_6[];
extern const s8 eff14_script_7[];
extern const s8 eff14_script_8[];
extern const s8 eff14_script_9[];
extern const s8 eff14_script_10[];
extern const s8 eff14_script_11[];
extern const s8 eff14_pattern_0[];
extern const s8 eff14_size_0[];
extern const s8 eff14_pattern_1[];
extern const s8 eff14_size_1[];
extern const s8 eff14_pattern_2[];
extern const s8 eff14_size_2[];
extern const s8 eff14_pattern_3[];
extern const s8 eff14_size_3[];
extern const s8 eff14_pattern_4[];
extern const s8 eff14_size_4[];
extern const s8 eff14_pattern_5[];
extern const s8 eff14_size_5[];
extern const s8 eff14_pattern_6[];
extern const s8 eff14_size_6[];
extern const s8 eff14_pattern_7[];
extern const s8 eff14_size_7[];
extern const s8 eff14_pattern_8[];
extern const s8 eff14_size_8[];
extern const s8 eff14_pattern_9[];
extern const s8 eff14_size_9[];
extern const s8 eff14_pattern_10[];
extern const s8 eff14_size_10[];
extern const s8 eff14_pattern_11[];
extern const s8 eff14_size_11[];
extern const u32 eff14_data_tbl[][5];

const u16 eff14_ofs_tbl[12] = {
    0x1660, 0x197C, 0x1894, 0x1584, 0x95C, 0x1538, 0x1A68, 0x1B58,
    0x1424, 0x1164, 0x14AC, 0x161C,
};

const s8 eff14_script_0[52] = {
    EFF14_STEP(5, 0x50), EFF14_STEP(5, 0x51), EFF14_STEP(5, 0x52), EFF14_STEP(5, 0x53),
    EFF14_STEP(5, 0x54), EFF14_STEP(5, 0x55), EFF14_STEP(5, 0x56), EFF14_STEP(5, 0x57),
    EFF14_STEP(5, 0x58), EFF14_STEP(5, 0x59), EFF14_STEP(5, 0x5A), EFF14_STEP(5, 0x5B),
    EFF14_END, 0, 0,
};

const s8 eff14_script_1[16] = {
    EFF14_STEP(3, 0x59), EFF14_STEP(3, 0x60), EFF14_STEP(3, 0x61),
    EFF14_END, 0, 0,
};

const s8 eff14_script_2[16] = {
    EFF14_STEP(3, 0x52), EFF14_STEP(3, 0x5C), EFF14_STEP(3, 0x5D),
    EFF14_END, 0, 0,
};

const s8 eff14_script_3[16] = {
    EFF14_STEP(3, 0x41), EFF14_STEP(3, 0x5E), EFF14_STEP(3, 0x5F),
    EFF14_END, 0, 0,
};

const s8 eff14_script_4[28] = {
    EFF14_STEP(4, 0x45), EFF14_STEP(4, 0x49), EFF14_STEP(4, 0x4A), EFF14_STEP(4, 0x4B),
    EFF14_STEP(4, 0x4C), EFF14_STEP(4, 0x4D),
    EFF14_END, 0, 0,
};

const s8 eff14_script_6[76] = {
    EFF14_STEP(6, 0x49), EFF14_STEP(5, 0x4D), EFF14_STEP(6, 0x4E), EFF14_STEP(6, 0x4F),
    EFF14_STEP(7, 0x4E), EFF14_STEP(6, 0x4D), EFF14_STEP(5, 0x49), EFF14_STEP(6, 0x4D),
    EFF14_STEP(5, 0x4E), EFF14_STEP(6, 0x4F), EFF14_STEP(5, 0x4E), EFF14_STEP(5, 0x4D),
    EFF14_STEP(6, 0x49), EFF14_STEP(7, 0x4D), EFF14_STEP(6, 0x4E), EFF14_STEP(7, 0x4F),
    EFF14_STEP(6, 0x4E), EFF14_STEP(6, 0x4D),
    EFF14_END, 0, 0,
};

const s8 eff14_script_7[76] = {
    EFF14_STEP(5, 0x4B), EFF14_STEP(4, 0x50), EFF14_STEP(4, 0x51), EFF14_STEP(5, 0x52),
    EFF14_STEP(4, 0x51), EFF14_STEP(3, 0x50), EFF14_STEP(4, 0x4B), EFF14_STEP(3, 0x50),
    EFF14_STEP(5, 0x51), EFF14_STEP(4, 0x52), EFF14_STEP(4, 0x51), EFF14_STEP(3, 0x50),
    EFF14_STEP(4, 0x4B), EFF14_STEP(4, 0x50), EFF14_STEP(5, 0x51), EFF14_STEP(4, 0x52),
    EFF14_STEP(4, 0x51), EFF14_STEP(3, 0x50),
    EFF14_END, 0, 0,
};

const s8 eff14_script_8[28] = {
    EFF14_STEP(4, 0x45), EFF14_STEP(4, 0x46), EFF14_STEP(4, 0x47), EFF14_STEP(4, 0x48),
    EFF14_STEP(4, 0x49), EFF14_STEP(4, 0x4A),
    EFF14_END, 0, 0,
};

const s8 eff14_script_9[20] = {
    EFF14_STEP(4, 0x41), EFF14_STEP(4, 0x4C), EFF14_STEP(4, 0x4D), EFF14_STEP(4, 0x4E),
    EFF14_END, 0, 0,
};

const s8 eff14_script_10[12] = {
    EFF14_STEP(4, 0x43), EFF14_STEP(4, 0x4B),
    EFF14_END, 0, 0,
};

const s8 eff14_script_11[108] = {
    EFF14_STEP(4, 0x40), EFF14_STEP(4, 0x47), EFF14_STEP(4, 0x40), EFF14_STEP(4, 0x47),
    EFF14_STEP(3, 0x40), EFF14_STEP(3, 0x47), EFF14_STEP(2, 0x40), EFF14_STEP(3, 0x47),
    EFF14_STEP(4, 0x40), EFF14_STEP(5, 0x47), EFF14_STEP(4, 0x40), EFF14_STEP(4, 0x47),
    EFF14_STEP(4, 0x40), EFF14_STEP(4, 0x47), EFF14_STEP(2, 0x40), EFF14_STEP(3, 0x47),
    EFF14_STEP(4, 0x40), EFF14_STEP(5, 0x47), EFF14_STEP(4, 0x40), EFF14_STEP(4, 0x47),
    EFF14_STEP(4, 0x40), EFF14_STEP(4, 0x47), EFF14_STEP(5, 0x40), EFF14_STEP(6, 0x47),
    EFF14_STEP(5, 0x40), EFF14_STEP(4, 0x47),
    EFF14_END, 0, 0,
};

const s8 eff14_pattern_0[190] = {
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const s8 eff14_size_0[2] = {
    19, 10,
};

const s8 eff14_pattern_1[35] = {
    0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1,
};

const s8 eff14_size_1[2] = {
    7, 5,
};

const s8 eff14_pattern_2[2] = {
    1, 1,
};

const s8 eff14_size_2[2] = {
    2, 1,
};

const s8 eff14_pattern_3[21] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
};

const s8 eff14_size_3[2] = {
    7, 3,
};

const s8 eff14_pattern_4[162] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1,
};

const s8 eff14_size_4[2] = {
    9, 18,
};

const s8 eff14_pattern_5[54] = {
    0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0,
    0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1,
};

const s8 eff14_size_5[2] = {
    9, 6,
};

const s8 eff14_pattern_6[9] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const s8 eff14_size_6[2] = {
    9, 1,
};

const s8 eff14_pattern_7[80] = {
    0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
    1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const s8 eff14_size_7[2] = {
    16, 4,
};

const s8 eff14_pattern_8[171] = {
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const s8 eff14_size_8[2] = {
    19, 9,
};

const s8 eff14_pattern_9[24] = {
    0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1,
    1, 0, 1, 1, 0, 1, 1, 0,
};

const s8 eff14_size_9[2] = {
    3, 8,
};

const s8 eff14_pattern_10[16] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const s8 eff14_size_10[2] = {
    4, 4,
};

const s8 eff14_pattern_11[20] = {
    1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    1, 1, 0, 0,
};

const s8 eff14_size_11[2] = {
    5, 4,
};

const u32 eff14_data_tbl[12][5] = {
    { 0, 0, (u32)eff14_script_0, (u32)eff14_pattern_0, (u32)eff14_size_0 },
    { 0, 0, (u32)eff14_script_1, (u32)eff14_pattern_1, (u32)eff14_size_1 },
    { 0, 1, (u32)eff14_script_2, (u32)eff14_pattern_2, (u32)eff14_size_2 },
    { 2, 2, (u32)eff14_script_3, (u32)eff14_pattern_3, (u32)eff14_size_3 },
    { 0, 0, (u32)eff14_script_4, (u32)eff14_pattern_4, (u32)eff14_size_4 },
    { 0, 1, (u32)eff14_script_4, (u32)eff14_pattern_5, (u32)eff14_size_5 },
    { 0, 0, (u32)eff14_script_6, (u32)eff14_pattern_6, (u32)eff14_size_6 },
    { 0, 1, (u32)eff14_script_7, (u32)eff14_pattern_7, (u32)eff14_size_7 },
    { 0, 0, (u32)eff14_script_8, (u32)eff14_pattern_8, (u32)eff14_size_8 },
    { 0, 1, (u32)eff14_script_9, (u32)eff14_pattern_9, (u32)eff14_size_9 },
    { 1, 2, (u32)eff14_script_10, (u32)eff14_pattern_10, (u32)eff14_size_10 },
    { 1, 2, (u32)eff14_script_11, (u32)eff14_pattern_11, (u32)eff14_size_11 },
};
