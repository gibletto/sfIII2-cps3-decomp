/*
 * SEL_DATA.C  tables read by sel_pl.c: player (character) select screen
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 Sel_Data_0615A814[];
extern const s8 Face_Cursor_Data[][13];

/* provisional name */
const s8 Sel_Data_0615A814[13] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9,
};

const s8 Face_Cursor_Data[2][13] = {
    { 2, 1, 3, 5, 7, 6, 12, 13, 8, 9, 10, 4, 11 },
    { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 },
};
