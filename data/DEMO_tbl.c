/*
 * DEMO_TBL.C  tables read by Game_Main.c: game phase dispatcher: title, select, fight, bonus, continue, ending
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 Game_Data_msg[];
extern const s8 Income_msg[];
extern const s8 Service_msg[];
extern const s8 Card_msg[];

const s8 Game_Data_msg[12] = {
    71, 65, 77, 69, 32, 68, 65, 84, 65, 0, -1, -1,
};

const s8 Income_msg[8] = {
    73, 78, 67, 79, 77, 69, 0, -1,
};

const s8 Service_msg[8] = {
    83, 69, 82, 86, 73, 67, 69, 0,
};

const s8 Card_msg[5] = {
    67, 65, 82, 68, 0,
};
