/*
 * EFF18_TBL.C  tables read by effects 18, 21 and 23
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 scr_obj_num18[][4];
extern const u16 scr_obj_data18_0[];
extern const u16 scr_obj_data18_1[];
extern const u16 scr_obj_data18_2[];
extern const u16 scr_obj_data18_3[];
extern const u16 scr_obj_data18_4[];
extern const u16 scr_obj_data18_5[];
extern const u16 scr_obj_data18_6[];
extern const u16 scr_obj_data18_7[];
extern const u16 scr_obj_data18_8[];
extern const u16 scr_obj_data18_9[];
extern const u16 scr_obj_data18_10[];
extern const s16 eff21_data_adrs_0[];
extern const s32 eff21_sp_tbl[];
extern const s16 eff23_data_tbl[];

const s16 scr_obj_num18[8][4] = {
    { 1, 1, 1, 1 },
    { 2, 2, 2, 2 },
    { 2, 2, 2, 2 },
    { 3, 3, 3, 3 },
    { 1, 1, 1, 1 },
    { 1, 1, 1, 1 },
    { 1, 1, 1, 1 },
    { 1, 1, 1, 1 },
};

/* provisional name */
const u16 scr_obj_data18_0[12] = {
    1, 2, 0x2063, 0xFF20, 0x40, 0x4A, 0x12, 0x13,
    1, 0, 0, 1,
};

const u16 scr_obj_data18_1[24] = {
    1, 2, 0x5B, 0x150, 0x50, 0x4B, 0x14, 0x15,
    1, 1, 0, 1, 1, 2, 0x205B, 0xFF90,
    0x39, 0x4C, 8, 9, 1, 1, 0, 1,
};

const u16 scr_obj_data18_2[24] = {
    1, 2, 0x2055, 0x260, 0x40, 0x55, 0x13, 0x14,
    1, 0, 0, 1, 0, 2, 0x2055, 0x1E8,
    0x30, 0x4D, 0x15, 0x16, 1, 0, 0, 1,
};

const u16 scr_obj_data18_3[24] = {
    0, 2, 0x2055, 0x1F0, 0x30, 0x4B, 0x20, 0x21,
    1, 0, 0, 1, 1, 2, 0x2055, 0x228,
    0x38, 0x4C, 0x1E, 0x1F, 1, 0, 0, 1,
};

const u16 scr_obj_data18_4[36] = {
    0, 2, 0x64, 0x210, 0x42, 0x4B, 7, 8,
    1, 0, 0, 1, 1, 2, 0x2064, 0x13F,
    0x38, 0x4A, 9, 0xA, 1, 0, 0, 1,
    0, 2, 0x2064, 0x18F, 0x42, 0x4B, 0xB, 0xC,
    1, 0, 0, 1,
};

const u16 scr_obj_data18_5[36] = {
    0, 2, 0x64, 0x210, 0x42, 0x4B, 7, 8,
    1, 0, 0, 1, 1, 2, 0x2064, 0xDF,
    0x3D, 0x4C, 5, 6, 1, 0, 0, 1,
    0, 2, 0x2064, 0x18F, 0x42, 0x4B, 0xB, 0xC,
    1, 0, 0, 1,
};

const u16 scr_obj_data18_6[36] = {
    0, 2, 0x64, 0x210, 0x42, 0x4B, 7, 8,
    1, 0, 0, 1, 0, 2, 0x2064, 0x18F,
    0x42, 0x4B, 0xB, 0xC, 1, 0, 0, 1,
    1, 2, 0x2064, 0x254, 0x42, 0x4B, 0xD, 0xE,
    1, 0, 0, 1,
};

const u16 scr_obj_data18_7[12] = {
    0, 2, 0x2058, 0x1D0, 0x68, 0x4D, 0xF, 0x10,
    1, 0, 0, 1,
};

const u16 scr_obj_data18_8[12] = {
    1, 2, 0x2059, 0x130, 0x30, 0x4B, 0x18, 0x19,
    1, 0, 0, 1,
};

const u16 scr_obj_data18_9[12] = {
    0, 2, 0x205A, 0x1F0, 0x30, 0x4B, 2, 3,
    1, 0, 0, 0,
};

const u16 scr_obj_data18_10[12] = {
    0, 2, 0x2040, 0x2DF, 0x30, 0x48, 8, 9,
    1, 0, 0, 0,
};

const s16 eff21_data_adrs_0[16] = {
    0, 696, 64, 74, 0, 2, 752, 84,
    74, 0, 4, 752, 63, 74, 1, -1,
};

const s32 eff21_sp_tbl[12] = {
    0, 0, -4096, 1152,
    0, 0, -6144, 1024,
    65536, 0, 9216, 1152,
};

/* provisional name */
const s16 eff23_data_tbl[34] = {
    8, 752, 104, 2, -32768, 0, 12288, 8,
    0, -1, -32768, 9, 752, 96, 3, -32768,
    0, 12288, 3, 0, -1, -32768, 11, 672,
    80, 4, -32768, 0, 16384, 5, -32768, -1,
    -32768, -1,
};
