/*
 * DEMO02_CODE_DATA.C  demonstration play character table
 *
 * Demo_PL_Play_Data gives the two characters of each of the four attract mode demonstration
 * fights, picked by Demo_PL_Index. Read by Setup_Demo_PL in DEMO02_CODE.C.
 */

#include "types.h"
#include "structs.h"
#include "fighter.h"

#pragma section TBL

extern const s8 Demo_PL_Play_Data[][2];

const s8 Demo_PL_Play_Data[4][2] = {
    { PL_ALEX, PL_RYU },
    { PL_KEN, PL_YANG },
    { PL_HUGO, PL_ORO },
    { PL_URIEN, PL_IBUKI },
};
