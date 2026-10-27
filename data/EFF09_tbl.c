/*
 * EFF09_TBL.C  character prop settings
 *
 * eff09_data2 holds one row per prop kind for effect_09_init2: colour, offset from the owner,
 * priority, animation and sync settings. eff09_2000_data, eff09_add_tbl0 .. eff09_add_tbl2 and
 * eff09_13_tbl are the speeds and accelerations of the thrown and moving props, and
 * sean_ball_hit is the hit box of the bouncing ball. Read by EFF09.C, the character props for
 * appearances and win poses.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 eff09_data2[][8];
extern const s32 eff09_2000_data[][4];
extern const s32 eff09_add_tbl0[][2];
extern const s32 eff09_add_tbl1[][2];
extern const s32 eff09_add_tbl2[][2];
extern const s16 sean_ball_hit[];
extern const s32 eff09_13_tbl[][4];

/*
 * One row per effect_09_init2 kind, read in order: routine_no[0], colour code (added to
 * the owner's), x offset from the owner (mirrored by rl_flag), y offset, priority (added
 * to the owner's), animation number, hit_stop and sync_suzi.
 */
const s16 eff09_data2[24][8] = {
    { 1, 0, 0, 4, 1, 25, 1, 0 },
    { 2, 0, -34, 153, -10, 26, 1, 0 },
    { 3, 6, 48, 240, -1, 99, 1, 0 },
    { 4, 0, 48, -4, -10, 28, 1, 0 },
    { 5, 0, 10, 96, -20, 46, 1, 0 },
    { 6, 0, 0, 0, -20, 47, 1, 0 },
    { 7, 0, 0, 80, -10, 43, 1, 0 },
    { 0, 0, -38, 84, -2, 41, 1, 0 },
    { 8, 0, 0, 0, -2, 55, 1, 0 },
    { 8, 0, 0, 0, -2, 56, 1, 0 },
    { 9, 0, 0, 0, -12, 71, 1, 0 },
    { 9, 0, 0, 0, -12, 72, 1, 0 },
    { 10, 0, 0, 0, -12, 73, 1, 0 },
    { 11, 0, 48, -10, -10, 28, 1, 0 },
    { 12, 0, 0, 74, 2, 75, 1, 0 },
    { 13, 0, -4, 154, -2, 80, 1, 0 },
    { 13, 0, -32, 112, -2, 81, 1, 0 },
    { 13, 0, 16, 122, -2, 82, 1, 0 },
    { 14, 26, 45, 0, -16, 84, 1, 0 },
    { 14, 26, 12, 0, -16, 84, 1, 0 },
    { 15, 0, -18, 62, -2, 85, 1, 0 },
    { 17, 0, -32, 72, -2, 85, 1, 0 },
    { 16, 0, 0, 0, -12, 87, 1, 0 },
    { 18, 0, 0, 0, 1, 96, 1, 0 },
};

const s32 eff09_2000_data[2][4] = {
    { -65536, 327680, -4096, -24576 },
    { -327680, 393216, -3072, -24576 },
};

const s32 eff09_add_tbl0[2][2] = {
    { 2048, -2048 }, { 2048, -4096 },
};

const s32 eff09_add_tbl1[2][2] = {
    { -2048, 2048 }, { -4608, 4096 },
};

const s32 eff09_add_tbl2[2][2] = {
    { -2048, 2048 }, { -4096, 4608 },
};

const s16 sean_ball_hit[4] = {
    -16, 32, -11, 22,
};

const s32 eff09_13_tbl[3][4] = {
    { 0, 4096, 196608, 0 },
    { 294912, 4096, 163840, 0 },
    { -294912, -4096, 163840, 0 },
};
