/*
 * EFF79_TBL.C  super art plate positions and centre message times
 *
 * eff79_plate_pos gives the x and y position of each of the three super art plate slots of
 * each player, and Pos_Z_Data_79 the depth of each slot; read by EFF79.C, the super art
 * selection plates. Time_Data gives how long each centre-screen message stays up, read by
 * EFF84.C, the centre-screen message controller.
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
