/*
 * SE_TBL.C  screen wipe and sound tables
 *
 * wipe_clear_pattern_tbl gives, per wipe kind, the clearing bitmap (wipe_clear_bitmap_0 - 4 in
 * SLOWF_TBL.C, one 32-byte row per step), and wipe_column_tbl the column order of each step
 * (wipe_column_map_0 - 3); these are read by SE.C and SE_2.C. stage_bgm_tbl is the BGM code of
 * each stage, init_fade_voice_tbl the sound channels stopped at sound start-up, SE_Shock_Data
 * the hit sound codes Se_Shock checks for on a knockout, and Finish_SE_Data the finishing
 * sound replacements; these are read by SE_3.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const BitmapSrc wipe_clear_pattern_tbl[];
extern const u8 wipe_column_map_0[];
extern const u8 wipe_column_map_1[];
extern const u8 wipe_column_map_2[];
extern const u8 wipe_column_map_3[];
extern const ByteMapSrc wipe_column_tbl[];
extern const s16 stage_bgm_tbl[];
extern const s8 init_fade_voice_tbl[];
extern const s16 SE_Shock_Data[];
extern const s16 Finish_SE_Data[][7];
extern const u8 wipe_clear_bitmap_0[];
extern const u8 wipe_clear_bitmap_1[];
extern const u8 wipe_clear_bitmap_2[];
extern const u8 wipe_clear_bitmap_3[];
extern const u8 wipe_clear_bitmap_4[];

const BitmapSrc wipe_clear_pattern_tbl[6] = {
    { wipe_clear_bitmap_0, 0, 8, 0 },
    { wipe_clear_bitmap_1, 0, 3, 0 },
    { wipe_clear_bitmap_1, 0, 3, 0 },
    { wipe_clear_bitmap_2, 0, 8, 0 },
    { wipe_clear_bitmap_3, 0, 4, 0 },
    { wipe_clear_bitmap_4, 0, 4, 0 },
};

const u8 wipe_column_map_0[64] = {
    0, 4, 9, 13, 18, 22, 27, 31, 0, 5, 9, 14, 18, 23, 27, 28,
    1, 5, 10, 14, 19, 23, 24, 28, 1, 6, 10, 15, 19, 20, 24, 29,
    2, 6, 11, 15, 16, 20, 25, 29, 2, 7, 11, 12, 16, 21, 25, 30,
    3, 7, 8, 12, 17, 21, 26, 30, 3, 4, 8, 13, 17, 22, 26, 31,
};

const u8 wipe_column_map_1[32] = {
    28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19,
    12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3,
};

const u8 wipe_column_map_2[64] = {
    0, 4, 8, 12, 16, 20, 24, 28, 0, 4, 8, 12, 16, 20, 24, 28,
    1, 5, 9, 13, 17, 21, 25, 29, 1, 5, 9, 13, 17, 21, 25, 29,
    2, 6, 10, 14, 18, 22, 26, 30, 2, 6, 10, 14, 18, 22, 26, 30,
    3, 7, 11, 15, 19, 23, 27, 31, 3, 7, 11, 15, 19, 23, 27, 31,
};

const u8 wipe_column_map_3[64] = {
    0, 2, 5, 7, 8, 10, 13, 15, 16, 18, 21, 23, 24, 26, 29, 31,
    0, 2, 5, 7, 8, 10, 13, 15, 16, 18, 21, 23, 24, 26, 29, 31,
    1, 3, 4, 6, 9, 11, 12, 14, 17, 19, 20, 22, 25, 27, 28, 30,
    1, 3, 4, 6, 9, 11, 12, 14, 17, 19, 20, 22, 25, 27, 28, 30,
};

const ByteMapSrc wipe_column_tbl[6] = {
    { wipe_column_map_0, 8, 0 },
    { wipe_column_map_0, 8, 0 },
    { wipe_column_map_0, 8, 0 },
    { wipe_column_map_1, 4, 0 },
    { wipe_column_map_2, 8, 0 },
    { wipe_column_map_3, 16, 0 },
};

const s16 stage_bgm_tbl[17] = {
    19, 11, 12, 13, 14, 15, 32, 16,
    17, 18, 34, 33, 29, 35, 36, 37,
    41,
};

const s8 init_fade_voice_tbl[14] = {
    0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 14, 15,
};

const s16 SE_Shock_Data[7] = {
    285, 286, 287, 288, 289, 305, 306,
};

const s16 Finish_SE_Data[2][7] = {
    { 305, 306, 285, 286, 287, 288, 272 },
    { 292, 293, 290, 291, 287, 288, 272 },
};
