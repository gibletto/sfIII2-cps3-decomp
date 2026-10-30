/*
 * WIN_PL_TBL.C  round winner type table
 *
 * winner_type_tbl selects, by character, which winner routine (Win_00000 .. Win_09000) plays at
 * the end of a won round. Read by WIN_PL.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 winner_type_tbl[];

const s16 winner_type_tbl[20] = {
    6, 0, 0, 6, 2, 7, 9, 3,
    4, 1, 0, 0, 5, 6, 8, 8,
    0, 0, 0, -1,
};
