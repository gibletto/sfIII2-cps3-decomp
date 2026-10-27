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
extern const u16 eff54_move_tbl[];

const s16 eff48_num_tbl[6] = {
    1, 1, 1, 1, 1, 1,
};

const s16 eff49_pos_tbl[10] = {
    -116, -93, -64, -36, -18, 0, 28, 55,
    80, 110,
};

const u16 eff54_move_tbl[30] = {
    0, 0xC, 2, 0, 1, 0x8000, 0, 0x4000,
    0, 0x6000, 0, 0x1E, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0xFFFF, 0xFF00, 0xFFFF, 0xFF00, 0xFFFF, 0xFE00,
};
