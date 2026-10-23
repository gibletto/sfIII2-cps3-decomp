/*
 * SC_DATA4_C.C  a table nothing reads, kept for the layout
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 hud_cell_pos_tbl[][2];

/* provisional name */
/* Eight (x, y) cell positions on row 5. Nothing in the program refers to it by name or address. */
const s16 hud_cell_pos_tbl[8][2] = {
    { 3, 5 },
    { 7, 5 },
    { 11, 5 },
    { 19, 5 },
    { 31, 5 },
    { 47, 5 },
    { 51, 5 },
    { 55, 5 },
};
