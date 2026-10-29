/*
 * EFF18_TBL.C  reacting stage objects and breakable stage object parts
 *
 * scr_obj_num18 gives the number of effect 18 objects for each stage setting and compel flag,
 * and scr_obj_data18_0 .. scr_obj_data18_10 their settings, reached through scr_obj_data18;
 * read by EFF18.C, which holds effects 17 and 18. eff21_data_adrs_0 gives the pattern,
 * position, priority and flip of the three breakable parts of effect 21, and eff21_sp_tbl
 * their speeds and accelerations (EFF21.C). eff23_data_tbl holds the three broken pieces of
 * the effect 23 object (EFF23.C), used only by effect_23_parts_init, which nothing calls.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 scr_obj_num18[][4];
extern const s16 scr_obj_data18_0[][12];
extern const s16 scr_obj_data18_1[][12];
extern const s16 scr_obj_data18_2[][12];
extern const s16 scr_obj_data18_3[][12];
extern const s16 scr_obj_data18_4[][12];
extern const s16 scr_obj_data18_5[][12];
extern const s16 scr_obj_data18_6[][12];
extern const s16 scr_obj_data18_7[][12];
extern const s16 scr_obj_data18_8[][12];
extern const s16 scr_obj_data18_9[][12];
extern const s16 scr_obj_data18_10[][12];
extern const s16 eff21_data_adrs_0[];
extern const s32 eff21_sp_tbl[][4];
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
/* one row per object: { dead_f, my_family, colour code, x, y, priority, dir_old, dir_step, hit_stop,
   sync_suzi, routine_no[1], old_rno[0] } */
const s16 scr_obj_data18_0[1][12] = {
    { 1, 2, 0x2063, -224, 64, 74, 18, 19, 1, 0, 0, 1 },
};

const s16 scr_obj_data18_1[2][12] = {
    { 1, 2, 0x5B, 336, 80, 75, 20, 21, 1, 1, 0, 1 },
    { 1, 2, 0x205B, -112, 57, 76, 8, 9, 1, 1, 0, 1 },
};

const s16 scr_obj_data18_2[2][12] = {
    { 1, 2, 0x2055, 608, 64, 85, 19, 20, 1, 0, 0, 1 },
    { 0, 2, 0x2055, 488, 48, 77, 21, 22, 1, 0, 0, 1 },
};

const s16 scr_obj_data18_3[2][12] = {
    { 0, 2, 0x2055, 496, 48, 75, 32, 33, 1, 0, 0, 1 },
    { 1, 2, 0x2055, 552, 56, 76, 30, 31, 1, 0, 0, 1 },
};

const s16 scr_obj_data18_4[3][12] = {
    { 0, 2, 0x64, 528, 66, 75, 7, 8, 1, 0, 0, 1 },
    { 1, 2, 0x2064, 319, 56, 74, 9, 10, 1, 0, 0, 1 },
    { 0, 2, 0x2064, 399, 66, 75, 11, 12, 1, 0, 0, 1 },
};

const s16 scr_obj_data18_5[3][12] = {
    { 0, 2, 0x64, 528, 66, 75, 7, 8, 1, 0, 0, 1 },
    { 1, 2, 0x2064, 223, 61, 76, 5, 6, 1, 0, 0, 1 },
    { 0, 2, 0x2064, 399, 66, 75, 11, 12, 1, 0, 0, 1 },
};

const s16 scr_obj_data18_6[3][12] = {
    { 0, 2, 0x64, 528, 66, 75, 7, 8, 1, 0, 0, 1 },
    { 0, 2, 0x2064, 399, 66, 75, 11, 12, 1, 0, 0, 1 },
    { 1, 2, 0x2064, 596, 66, 75, 13, 14, 1, 0, 0, 1 },
};

const s16 scr_obj_data18_7[1][12] = {
    { 0, 2, 0x2058, 464, 104, 77, 15, 16, 1, 0, 0, 1 },
};

const s16 scr_obj_data18_8[1][12] = {
    { 1, 2, 0x2059, 304, 48, 75, 24, 25, 1, 0, 0, 1 },
};

const s16 scr_obj_data18_9[1][12] = {
    { 0, 2, 0x205A, 496, 48, 75, 2, 3, 1, 0, 0, 0 },
};

const s16 scr_obj_data18_10[1][12] = {
    { 0, 2, 0x2040, 735, 48, 72, 8, 9, 1, 0, 0, 0 },
};

const s16 eff21_data_adrs_0[16] = {
    0, 696, 64, 74, 0, 2, 752, 84,
    74, 0, 4, 752, 63, 74, 1, -1,
};

const s32 eff21_sp_tbl[3][4] = {
    { 0, 0, -0x1000, 0x480 }, { 0, 0, -0x1800, 0x400 },
    { 0x10000, 0, 0x2400, 0x480 },
};

/* provisional name */
const s16 eff23_data_tbl[34] = {
    8, 752, 104, 2, 0x8000, 0, 12288, 8,
    0, -1, 0x8000, 9, 752, 96, 3, 0x8000,
    0, 12288, 3, 0, -1, 0x8000, 11, 672,
    80, 4, 0x8000, 0, 16384, 5, 0x8000, -1,
    0x8000, -1,
};
