/*
 * POW_DATA.C  score award table
 *
 * Score_Data is the list of the 18 score amounts a player can be awarded (0, 100, 200, ...),
 * indexed by score kind. Read by POW_POW.C, which adds them to the players' scores.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s32 Score_Data[];

const s32 Score_Data[18] = {
    0, 100, 200, 300,
    400, 500, 1000, 1500,
    2000, 2500, 3000, 4000,
    5000, 6000, 7000, 8000,
    9000, 10000,
};
