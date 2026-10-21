/*
 * EFF79_TBL.C  tables read by effect 79 (eff79_plate_pos, Pos_Z_Data_79), and Time_Data, read by Com_Sub.c and effect 84
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 eff79_plate_pos[][6];
extern const s32 Pos_Z_Data_79[];
extern const s8 Time_Data[];

/* provisional name */
const s16 eff79_plate_pos[2][6] = {
    { 608, 124, 620, 152, 608, 180 },
    { 798, 124, 786, 152, 798, 180 },
};

const s32 Pos_Z_Data_79[3] = {
    10, 0, 5,
};

const s8 Time_Data[8] = {
    80, 90, 50, 50, 50, -1, -1, -1,
};
