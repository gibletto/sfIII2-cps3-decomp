/*
 * EFFC7_TBL.C  parry mark positions and entrance prop throw speeds
 *
 * paring_mark_data gives the offset of the parry mark from the player for each parry type and
 * character; read by EFFC7.C, the parry (blocking) mark. effc8_data_tbl gives the speeds with
 * which the entrance prop is thrown clear at the end of the entrance; read by EFFC8.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 paring_mark_data[][16][2];
extern const u16 effc8_data_tbl[];

const s16 paring_mark_data[3][16][2] = {
    {
        { 64, 96 }, { 66, 82 }, { 50, 72 }, { 32, 60 },
        { 36, 82 }, { 42, 70 }, { 34, 100 }, { 44, 74 },
        { 38, 52 }, { 50, 72 }, { 32, 60 }, { 50, 72 },
        { 50, 72 }, { 64, 96 }, { 50, 72 }, { 50, 72 },
    },
    {
        { 60, 40 }, { 32, 44 }, { 28, 34 }, { 22, 40 },
        { 30, 40 }, { 28, 44 }, { 36, 40 }, { 22, 36 },
        { 32, 36 }, { 40, 36 }, { 22, 40 }, { 28, 34 },
        { 28, 34 }, { 60, 40 }, { 28, 34 }, { 28, 34 },
    },
    {
        { 40, 92 }, { 42, 62 }, { 28, 76 }, { 28, 76 },
        { 38, 68 }, { 30, 84 }, { 28, 116 }, { 28, 56 },
        { 38, 52 }, { 40, 60 }, { 28, 76 }, { 32, 48 },
        { 32, 48 }, { 40, 92 }, { 28, 76 }, { 28, 76 },
    },
};

/* provisional name */
const u16 effc8_data_tbl[8] = {
    3, 0, 0, 0x200, 0, 0, 0xFFFF, 0xE800,
};
