/*
 * EFF62_TBL.C  alternate background scrolling parts
 *
 * eff62_data_tbl gives the x, y position and speed number of each of the 24 parts, and
 * eff62_speed_tbl the scroll speed of each speed number. Read by EFF62.C, the parts of the
 * alternate background.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 eff62_data_tbl[][3];
extern const s32 eff62_speed_tbl[];

const s16 eff62_data_tbl[24][3] = {
    { -416, 0, 0 },
    { -480, 512, 0 },
    { -384, 0, 1 },
    { -448, 512, 1 },
    { -288, 0, 2 },
    { -352, 512, 2 },
    { -272, 0, 3 },
    { -336, 512, 3 },
    { -128, 0, 4 },
    { -192, 512, 4 },
    { -96, 0, 5 },
    { -48, 512, 5 },
    { 416, 0, 0 },
    { 480, 512, 0 },
    { 384, 0, 1 },
    { 448, 512, 1 },
    { 288, 0, 2 },
    { 352, 512, 2 },
    { 272, 0, 3 },
    { 336, 512, 3 },
    { 128, 0, 4 },
    { 192, 512, 4 },
    { 96, 0, 5 },
    { 48, 512, 5 },
};

const s32 eff62_speed_tbl[7] = {
    4718592, 3932160, 2293760, 1966080,
    1179648, 786432, 786432,
};
