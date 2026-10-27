/*
 * SYS_SUB_TBL.C  copyright messages, text animation and win mark tables
 *
 * Capcom_Rights_msg, Capcom_Rights_msg2 and Capcom_USA_Rights_msg are the copyright lines put
 * on screen by SYS_SUB.C, chosen by country. EFF89_Init_Data and EFF91_Init_Data give, per
 * object type, the first entry in EFF89_Step_Data or EFF91_Step_Data, whether the steps start
 * again, and the step count; they are read by EFF89.C (blinking text rectangle) and by EFF91.C
 * and EFFA3.C (text-layer cell animation). win_mark_pos_tbl and win_mark_blink_tbl place and
 * blink the round win marks, read by SC_SUB.C; color_flash_tbl is the timer and colour
 * sequence of Flash_Violent in EFF49.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 Capcom_Rights_msg[];
extern const s8 Capcom_Rights_msg2[];
extern const s8 Capcom_USA_Rights_msg[];
extern const s16 EFF89_Init_Data[][3];
extern const s8 EFF91_Init_Data[];
extern const s16 EFF89_Step_Data[];
extern const s8 EFF91_Step_Data[];
extern const s16 win_mark_pos_tbl[][8];
extern const s16 win_mark_blink_tbl[];
extern const s16 color_flash_tbl[];

/* Messages whose digits are the font's glyph numbers 0-9 (not ASCII) are written as numbers; the comment
   after each name is the text it shows. */
const s8 Capcom_Rights_msg[44] = {  /* "@CAPCOM CO., LTD. 1997 ALL RIGHTS RESERVED." */
    64, 67, 65, 80, 67, 79, 77, 32, 67, 79, 46, 44, 32, 76, 84, 68,
    46, 32, 1, 9, 9, 7, 32, 65, 76, 76, 32, 82, 73, 71, 72, 84,
    83, 32, 82, 69, 83, 69, 82, 86, 69, 68, 46, 0,
};

const s8 Capcom_Rights_msg2[24] = {  /* "@CAPCOM CO., LTD. 1997," */
    64, 67, 65, 80, 67, 79, 77, 32, 67, 79, 46, 44, 32, 76, 84, 68,
    46, 32, 1, 9, 9, 7, 44, 0,
};

const s8 Capcom_USA_Rights_msg[48] = {  /* "@CAPCOM U.S.A., INC. 1997 ALL RIGHTS RESERVED." */
    64, 67, 65, 80, 67, 79, 77, 32, 85, 46, 83, 46, 65, 46, 44, 32,
    73, 78, 67, 46, 32, 1, 9, 9, 7, 32, 65, 76, 76, 32, 82, 73,
    71, 72, 84, 83, 32, 82, 69, 83, 69, 82, 86, 69, 68, 46, 0, -1,
};

/*
 * One row per effect 89 type: first entry in EFF89_Step_Data, whether the steps start
 * again when they run out, and the number of steps in one pass.
 */
const s16 EFF89_Init_Data[10][3] = {
    { 0, 0, 11 },
    { 22, 0, 11 },
    { 44, 0, 11 },
    { 66, 0, 11 },
    { 88, 0, 11 },
    { 110, 1, 2 },
    { 114, 0, 1 },
    { 116, 0, 1 },
    { 118, 0, 7 },
    { 134, 0, 11 },
};

/*
 * Read as three s16 entries per effect 91 / A3 type: first entry in EFF91_Step_Data,
 * whether the steps start again when they run out, and the number of steps in one pass.
 */
const s8 EFF91_Init_Data[18] = {
    0, 0, 0, 1, 0, 4, 0, 100, 0, 1, 0, 4, 0, -56, 0, 1,
    0, 3,
};

const s16 EFF89_Step_Data[154] = {
    50, 2, 60, 2, 50, 2, 60, 2,
    50, 2, 60, 2, 50, 2, 60, 2,
    50, 2, 60, 2, 50, -1, 44, 2,
    60, 2, 44, 2, 60, 2, 44, 2,
    60, 2, 44, 2, 60, 2, 44, 2,
    60, 2, 44, -1, 46, 2, 60, 2,
    46, 2, 60, 2, 46, 2, 60, 2,
    46, 2, 60, 2, 46, 2, 60, 2,
    46, -1, 48, 2, 60, 2, 48, 2,
    60, 2, 48, 2, 60, 2, 48, 2,
    60, 2, 48, 2, 60, 2, 48, -1,
    26, 2, 60, 2, 26, 2, 60, 2,
    26, 2, 60, 2, 26, 2, 60, 2,
    26, 2, 60, 2, 26, -1, 16, 111,
    14, 3, 60, 1, 58, 1, 42, 3,
    60, 3, 42, 3, 60, 3, 42, 3,
    60, 3, 42, -1, 0, 2, 60, 2,
    0, 2, 60, 2, 0, 2, 60, 2,
    0, 2, 60, 2, 0, 2, 60, 2,
    0, -1,
};

const s8 EFF91_Step_Data[514] = {
    0, 1, 0, 32, 0, 26, 0, 32, 0, 26, 1, -32, 0, 26, 1, -31,
    0, 26, 1, -30, 0, 26, 1, -29, 0, 26, 0, 32, 0, 26, 0, 32,
    0, 26, 1, -28, 0, 26, 1, -27, 0, 26, 1, -26, 0, 26, 1, -25,
    0, 26, 0, 1, 0, 32, 0, 26, 0, 32, 0, 26, 1, -16, 0, 26,
    1, -15, 0, 26, 1, -14, 0, 26, 1, -13, 0, 26, 0, 32, 0, 26,
    0, 32, 0, 26, 1, -12, 0, 26, 1, -11, 0, 26, 1, -10, 0, 26,
    1, -9, 0, 26, 0, 1, 0, 32, 0, 26, 0, 32, 0, 26, 1, -24,
    0, 26, 1, -23, 0, 26, 1, -22, 0, 26, 1, -21, 0, 26, 0, 32,
    0, 26, 0, 32, 0, 26, 1, -20, 0, 26, 1, -19, 0, 26, 1, -18,
    0, 26, 1, -17, 0, 26, 0, 1, 0, 32, 0, 26, 0, 32, 0, 26,
    1, -8, 0, 26, 1, -7, 0, 26, 1, -6, 0, 26, 1, -5, 0, 26,
    0, 32, 0, 26, 0, 32, 0, 26, 1, -4, 0, 26, 1, -3, 0, 26,
    1, -2, 0, 26, 1, -1, 0, 26, 0, 1, 0, 32, 0, 90, 0, 32,
    0, 90, 1, -28, 0, 90, 1, -27, 0, 90, 1, -26, 0, 90, 1, -25,
    0, 90, 0, 32, 0, 90, 0, 32, 0, 90, 1, -32, 0, 90, 1, -31,
    0, 90, 1, -30, 0, 90, 1, -29, 0, 90, 0, 1, 0, 32, 0, 90,
    0, 32, 0, 90, 1, -12, 0, 90, 1, -11, 0, 90, 1, -10, 0, 90,
    1, -9, 0, 90, 0, 32, 0, 90, 0, 32, 0, 90, 1, -16, 0, 90,
    1, -15, 0, 90, 1, -14, 0, 90, 1, -13, 0, 90, 0, 1, 0, 32,
    0, 90, 0, 32, 0, 90, 1, -20, 0, 90, 1, -19, 0, 90, 1, -18,
    0, 90, 1, -17, 0, 90, 0, 32, 0, 90, 0, 32, 0, 90, 1, -24,
    0, 90, 1, -23, 0, 90, 1, -22, 0, 90, 1, -21, 0, 90, 0, 1,
    0, 32, 0, 90, 0, 32, 0, 90, 1, -4, 0, 90, 1, -3, 0, 90,
    1, -2, 0, 90, 1, -1, 0, 90, 0, 32, 0, 90, 0, 32, 0, 90,
    1, -8, 0, 90, 1, -7, 0, 90, 1, -6, 0, 90, 1, -5, 0, 90,
    0, 2, 0, 32, 0, 18, 0, 32, 0, 18, 0, 32, 0, 18, 0, 32,
    0, 18, 0, 0, 0, 18, 0, 32, 0, 18, 0, 32, 0, 18, 0, 32,
    0, 18, 0, 32, 0, 18, 0, 2, 0, 32, 0, 18, 0, 32, 0, 18,
    0, 32, 0, 18, 0, 32, 0, 18, 0, 1, 0, 18, 0, 32, 0, 18,
    0, 32, 0, 18, 0, 32, 0, 18, 0, 32, 0, 18, 0, 2, 0, 32,
    0, 18, 0, 32, 0, 18, 0, 32, 0, 18, 0, 32, 0, 18, 0, 2,
    0, 18, 0, 32, 0, 18, 0, 32, 0, 18, 0, 32, 0, 18, 0, 32,
    0, 18,
};

const s16 win_mark_pos_tbl[2][8] = {
    { 19, 17, 15, 13, 27, 29, 31, 33 },
    { 26, 24, 22, 20, 34, 36, 38, 40 },
};

const s16 win_mark_blink_tbl[36] = {
    14, 111, 60, 3, 14, 111, 60, 3,
    14, 111, 60, 3, 14, 111, 60, 3,
    14, 111, 60, 3, 14, 111, 60, 3,
    14, 111, 60, 3, 14, 111, 60, 3,
    0, 0, 0, 0,
};

const s16 color_flash_tbl[65] = {
    2, 8261, 2, 8259, 2, 8261, 2, 8259,
    2, 8261, -1, 8259, 2, 0, 2, 0,
    2, 0, -1, 0, 2, 0, 2, 0,
    2, 0, 8, 0, 4, 0, -1, 0,
    2, 8257, 2, 8258, 2, 8256, 2, 8257,
    2, 8258, 2, 8256, 2, 8257, 2, 8258,
    2, 8256, 2, 8257, 2, 8258, 2, 8256,
    2, 8257, 2, 8258, 1, 8256, -1, 8256,
    255,
};
