/*
 * SEL_DATA.C  select screen face cursor table
 *
 * Face_Cursor_Data gives the character at each face position of the select screen, copied into
 * ID_of_Face by Setup_Face_ID in SEL_PL.C. Face_Cursor_Data_unref, the row before it, is not
 * referred to.
 */

#include "types.h"
#include "structs.h"
#include "fighter.h"

#pragma section TBL

extern const s8 Face_Cursor_Data_unref[];
extern const s8 Face_Cursor_Data[][13];

/* provisional name */
/* A row stored before Face_Cursor_Data. Nothing in the program refers to it by name or address. */
const s8 Face_Cursor_Data_unref[13] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9,
};

const s8 Face_Cursor_Data[2][13] = {
    { PL_RYU, PL_ALEX, PL_YUN, PL_NECRO, PL_IBUKI, PL_HUGO, PL_SEAN, PL_URIEN, PL_ELENA, PL_ORO, PL_YANG, PL_DUDLEY, PL_KEN },
    { PL_GOUKI1, PL_GOUKI1, PL_GOUKI1, PL_GOUKI1, PL_GOUKI1, PL_GOUKI1, PL_GOUKI1, PL_GOUKI1, PL_GOUKI1, PL_GOUKI1, PL_GOUKI1, PL_GOUKI1, PL_GOUKI1 },
};
