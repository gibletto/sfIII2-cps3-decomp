/*
 * POW_DATA.C  tables read by pow_pow.c: damage and score (2nd Impact version)
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
