/*
 * EFF92.C  win mark redraw sequence and colours
 *
 * Rewrite_Mark_Data is the sequence of mark kinds and times drawn when a win mark is earned:
 * 0x8000 stands for the mark earned, and a time of -1 ends the sequence. win_mark_col_tbl
 * gives the colour of each mark kind. Read by EFF92_CODE.C, the win marks.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 Rewrite_Mark_Data[];
extern const s16 win_mark_col_tbl[];

const s16 Rewrite_Mark_Data[26] = {
    0x8000, 2, 8, 2, 0x8000, 2, 8, 2,
    0x8000, 2, 8, 2, 0x8000, 2, 8, 2,
    0x8000, 2, 8, 2, 0x8000, 2, 8, 3,
    0x8000, -1,
};

const s16 win_mark_col_tbl[10] = {
    14, 14, 14, 14, 14, 14, 14, 14,
    14, -1,
};
