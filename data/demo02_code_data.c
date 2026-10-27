/*
 * DEMO02_CODE_DATA.C  demonstration play character table
 *
 * Demo_PL_Play_Data gives the two characters of each of the four attract mode demonstration
 * fights, picked by Demo_PL_Index. Read by Setup_Demo_PL in DEMO02_CODE.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 Demo_PL_Play_Data[][2];

const s8 Demo_PL_Play_Data[4][2] = {
    { 1, 2 },
    { 11, 10 },
    { 6, 9 },
    { 13, 7 },
};
