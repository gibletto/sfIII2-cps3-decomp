/*
 * EFF48_TBL.C  opening scene object counts, continue digit offsets and a flight course
 *
 * eff48_num_tbl gives the number of opening scene objects of each type (EFF48.C).
 * eff49_pos_tbl is the x offset of each continue count digit (EFF49.C). eff54_move_tbl is the
 * timer and speed rows of the stage object that flies a fixed course (EFF54.C).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 eff48_num_tbl[];
extern const s16 eff49_pos_tbl[];
extern const s32 eff54_move_tbl[][5];

const s16 eff48_num_tbl[6] = {
    1, 1, 1, 1, 1, 1,
};

const s16 eff49_pos_tbl[10] = {
    -116, -93, -64, -36, -18, 0, 28, 55,
    80, 110,
};

const s32 eff54_move_tbl[3][5] = {
    { 12, 0x20000, 0x18000, 0x4000, 0x6000 },
    { 30, 0, 0, 0, 0 },
    { 0, 0, -256, -256, -512 },
};
