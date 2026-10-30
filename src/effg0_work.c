/*
 * EFFG0_WORK.C  effect G0's work
 *
 * Initialised work RAM (section D).
 */

#include "types.h"
#include "structs.h"

extern const u32 effg0_char_table_0[], effg0_char_table_1[], effg0_char_table_2[], effg0_char_table_3[], effg0_char_table_4[], effg0_char_table_5[], effg0_char_table_6[], effg0_char_table_7[], effg0_char_table_8[];

/* provisional name */
s16 effg0_judge_count = 0;  /* 0200842C */
/* 0200842E */
/* Stored after effg0_judge_count. Nothing in the program refers to it by name or address. */
u16 effg0_judge_count_tail[1] = {
    0xFFFF,
};

/* provisional name */
/* provisional name */
/* 02008430 */
const u32* effg0_char_tbl[7] = {
    effg0_char_table_0,
    effg0_char_table_1,
    effg0_char_table_2,
    effg0_char_table_3,
    effg0_char_table_4,
    effg0_char_table_5,
    effg0_char_table_6,
};
