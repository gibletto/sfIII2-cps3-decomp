/*
 * EFF48_TBL.C  tables read by effects 48, 49 and 54
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
