/*
 * EFF14_TBL.C  tables read by effect 14
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

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
    0, 5, 0, 80, 0, 5, 0, 81, 0, 5, 0, 82, 0, 5, 0, 83,
    0, 5, 0, 84, 0, 5, 0, 85, 0, 5, 0, 86, 0, 5, 0, 87,
    0, 5, 0, 88, 0, 5, 0, 89, 0, 5, 0, 90, 0, 5, 0, 91,
    -1, -1, 0, 0,
};

const s8 eff14_script_1[16] = {
    0, 3, 0, 89, 0, 3, 0, 96, 0, 3, 0, 97, -1, -1, 0, 0,
};

const s8 eff14_script_2[16] = {
    0, 3, 0, 82, 0, 3, 0, 92, 0, 3, 0, 93, -1, -1, 0, 0,
};

const s8 eff14_script_3[16] = {
    0, 3, 0, 65, 0, 3, 0, 94, 0, 3, 0, 95, -1, -1, 0, 0,
};

const s8 eff14_script_4[28] = {
    0, 4, 0, 69, 0, 4, 0, 73, 0, 4, 0, 74, 0, 4, 0, 75,
    0, 4, 0, 76, 0, 4, 0, 77, -1, -1, 0, 0,
};

const s8 eff14_script_6[76] = {
    0, 6, 0, 73, 0, 5, 0, 77, 0, 6, 0, 78, 0, 6, 0, 79,
    0, 7, 0, 78, 0, 6, 0, 77, 0, 5, 0, 73, 0, 6, 0, 77,
    0, 5, 0, 78, 0, 6, 0, 79, 0, 5, 0, 78, 0, 5, 0, 77,
    0, 6, 0, 73, 0, 7, 0, 77, 0, 6, 0, 78, 0, 7, 0, 79,
    0, 6, 0, 78, 0, 6, 0, 77, -1, -1, 0, 0,
};

const s8 eff14_script_7[76] = {
    0, 5, 0, 75, 0, 4, 0, 80, 0, 4, 0, 81, 0, 5, 0, 82,
    0, 4, 0, 81, 0, 3, 0, 80, 0, 4, 0, 75, 0, 3, 0, 80,
    0, 5, 0, 81, 0, 4, 0, 82, 0, 4, 0, 81, 0, 3, 0, 80,
    0, 4, 0, 75, 0, 4, 0, 80, 0, 5, 0, 81, 0, 4, 0, 82,
    0, 4, 0, 81, 0, 3, 0, 80, -1, -1, 0, 0,
};

const s8 eff14_script_8[28] = {
    0, 4, 0, 69, 0, 4, 0, 70, 0, 4, 0, 71, 0, 4, 0, 72,
    0, 4, 0, 73, 0, 4, 0, 74, -1, -1, 0, 0,
};

const s8 eff14_script_9[20] = {
    0, 4, 0, 65, 0, 4, 0, 76, 0, 4, 0, 77, 0, 4, 0, 78,
    -1, -1, 0, 0,
};

const s8 eff14_script_10[12] = {
    0, 4, 0, 67, 0, 4, 0, 75, -1, -1, 0, 0,
};

const s8 eff14_script_11[108] = {
    0, 4, 0, 64, 0, 4, 0, 71, 0, 4, 0, 64, 0, 4, 0, 71,
    0, 3, 0, 64, 0, 3, 0, 71, 0, 2, 0, 64, 0, 3, 0, 71,
    0, 4, 0, 64, 0, 5, 0, 71, 0, 4, 0, 64, 0, 4, 0, 71,
    0, 4, 0, 64, 0, 4, 0, 71, 0, 2, 0, 64, 0, 3, 0, 71,
    0, 4, 0, 64, 0, 5, 0, 71, 0, 4, 0, 64, 0, 4, 0, 71,
    0, 4, 0, 64, 0, 4, 0, 71, 0, 5, 0, 64, 0, 6, 0, 71,
    0, 5, 0, 64, 0, 4, 0, 71, -1, -1, 0, 0,
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
