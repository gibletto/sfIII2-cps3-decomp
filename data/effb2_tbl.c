/*
 * EFFB2_TBL.C  FIGHT flash colour table
 *
 * fight_col_move_tbl holds the colour steps of the FIGHT flash. Nothing reads it; it is kept
 * for the layout.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 fight_col_move_tbl[];

const s16 fight_col_move_tbl[4] = {
    15, 15, 15, 15,
};
