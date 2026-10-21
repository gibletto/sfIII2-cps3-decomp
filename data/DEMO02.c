/*
 * DEMO02.C  tables read by demo02_code.c: attract mode: demonstration play
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u8 Arts_Rnd_Demo_Data[];
extern const u8 Demo_Stage_Play_Data[];
extern const s8 Demo_PL_Data[];

const u8 Arts_Rnd_Demo_Data[8] = {
    0, 0, 0, 1, 1, 1, 2, 2,
};

const u8 Demo_Stage_Play_Data[4] = {
    1, 0xB, 6, 0xD,
};

const s8 Demo_PL_Data[4] = {
    0, 1, 0, 1,
};
