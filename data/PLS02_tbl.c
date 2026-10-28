/*
 * PLS02_TBL.C  player movement, damage and super art gauge tables
 *
 * satse is each character's body half-width, used by the screen-edge checks of PLS02.C and the
 * scroll limits of BG000.C; jump_pat_status_data, the jump posture by lever direction and
 * facing, is read by PLS00.C and PLS03.C. The rest are read by PLS02.C: the CPU random number
 * sequences (random_tbl_32_com, random_tbl_16_com, random_tbl_32_ex, random_tbl_16_ex_com);
 * dir16_rl_conv (mirrors a 16-way direction), dir16_hddm and dir16_trdm (head and body damage
 * routine by attack direction) and dir32_skydm and dir32_grddm (air and ground blow-away
 * routine by flight direction); konjyou_tbl (damage scaling by character and remaining
 * vitality); apagt_table, ukemi_apagt_table and nagenuke_apagt_table (super art gauge gains
 * for special actions, recovery rolls and throw escapes) with asagh_zuru and asagh_zuru2
 * (their adjustment by game level against the computer); dead_voice_table and
 * voice_select_table (character voices); convert_saishin_lvdir (lever left/right to
 * forward/back by facing) and gauge_rank_table (the bands of gauge_rank_value).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 asagh_zuru[];
extern const s16 asagh_zuru2[];
extern const s16 satse[];
extern const s16 random_tbl_32_com[];
extern const s16 random_tbl_16_com[];
extern const s16 random_tbl_32_ex[];
extern const s16 random_tbl_16_ex_com[];
extern const s16 dir16_rl_conv[];
extern const s16 dir16_hddm[];
extern const s16 dir16_trdm[];
extern const s16 konjyou_tbl[][6];
extern const s16 apagt_table[];
extern const s16 ukemi_apagt_table[];
extern const s16 nagenuke_apagt_table[];
extern const s16 dir32_skydm[];
extern const s16 dir32_grddm[];
extern const s16 dead_voice_table[][2];
extern const s16 voice_select_table[][4];
extern const u8 convert_saishin_lvdir[][16];
extern const s16 gauge_rank_table[][2];
extern const u8 jump_pat_status_data[][4];

const s16 asagh_zuru[8] = {
    -2, -1, 0, 0, 1, 2, 3, 4,
};

const s16 asagh_zuru2[44] = {
    1, 2, 3, 4, 5, 6, 7, 8,
    500, 250, 166, 125, 120, 100, 100, 87,
    88, 80, 72, 66, 400, 200, 166, 150,
    140, 116, 114, 100, 100, 80, 81, 75,
    500, 250, 200, 150, 120, 100, 100, 87,
    77, 70, 72, 66,
};

const s16 satse[16] = {
    36, 36, 32, 28, 36, 40, 44, 28,
    32, 32, 28, 32, 32, 36, 34, 34,
};

const s16 random_tbl_32_com[128] = {
    15, 5, 23, 18, 2, 13, 29, 17,
    1, 22, 31, 16, 13, 3, 21, 30,
    24, 18, 11, 30, 0, 21, 4, 26,
    19, 7, 10, 27, 1, 24, 16, 6,
    4, 8, 28, 7, 16, 3, 29, 8,
    24, 11, 15, 6, 20, 28, 25, 12,
    17, 22, 19, 10, 23, 14, 0, 26,
    3, 30, 19, 29, 13, 8, 2, 9,
    9, 25, 20, 2, 14, 27, 4, 12,
    28, 9, 7, 18, 27, 1, 31, 14,
    27, 4, 10, 29, 2, 25, 17, 6,
    31, 19, 11, 22, 5, 15, 6, 20,
    13, 23, 8, 18, 21, 12, 25, 10,
    22, 1, 24, 31, 0, 3, 26, 7,
    20, 5, 0, 11, 28, 16, 5, 15,
    14, 26, 9, 17, 21, 30, 12, 23,
};

const s16 random_tbl_16_com[64] = {
    5, 4, 9, 7, 10, 1, 6, 12,
    9, 14, 0, 13, 2, 11, 15, 2,
    12, 15, 3, 11, 8, 0, 3, 11,
    10, 1, 7, 5, 13, 6, 11, 4,
    3, 8, 13, 9, 5, 10, 14, 1,
    7, 4, 15, 6, 9, 14, 2, 0,
    13, 1, 6, 14, 3, 12, 8, 4,
    5, 10, 2, 15, 8, 0, 7, 12,
};

const s16 random_tbl_32_ex[32] = {
    16, 24, 5, 22, 10, 27, 14, 1,
    20, 8, 29, 3, 26, 11, 18, 0,
    31, 15, 28, 7, 12, 23, 4, 30,
    9, 19, 2, 25, 13, 17, 21, 6,
};

const s16 random_tbl_16_ex_com[16] = {
    9, 0, 5, 12, 3, 14, 7, 10,
    1, 15, 6, 11, 2, 8, 13, 4,
};

const s16 dir16_rl_conv[16] = {
    0, 15, 14, 13, 12, 11, 10, 9,
    8, 7, 6, 5, 4, 3, 2, 1,
};

const s16 dir16_hddm[16] = {
    35, 35, 35, 32, 32, 32, 36, 36,
    36, 36, 36, 32, 32, 32, 35, 35,
};

const s16 dir16_trdm[16] = {
    38, 38, 38, 37, 37, 37, 36, 36,
    36, 36, 36, 37, 37, 37, 38, 38,
};

const s16 konjyou_tbl[16][6] = {
    { 24, 28, 28, 32, 32, 32 },  /* Gill */
    { 24, 28, 28, 32, 32, 32 },  /* Alex */
    { 24, 28, 28, 32, 32, 32 },  /* Ryu */
    { 24, 28, 28, 32, 32, 32 },  /* Yun */
    { 24, 28, 28, 32, 32, 32 },  /* Dudley */
    { 24, 28, 28, 32, 32, 32 },  /* Necro */
    { 24, 28, 28, 32, 32, 32 },  /* Hugo */
    { 24, 28, 28, 32, 32, 32 },  /* Ibuki */
    { 24, 28, 28, 32, 32, 32 },  /* Elena */
    { 24, 28, 28, 32, 32, 32 },  /* Oro */
    { 24, 28, 28, 32, 32, 32 },  /* Yang */
    { 24, 28, 28, 32, 32, 32 },  /* Ken */
    { 24, 28, 28, 32, 32, 32 },  /* Sean */
    { 24, 28, 28, 32, 32, 32 },  /* Urien */
    { 24, 28, 28, 32, 32, 32 },  /* Gouki */
    { 24, 28, 28, 32, 32, 32 },  /* Shin Gouki */
};

const s16 apagt_table[16] = {
    10, 8, 8, 8, 8, 8, 10, 8,
    10, 6, 8, 8, 8, 8, 8, 10,
};

const s16 ukemi_apagt_table[16] = {
    3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3,
};

const s16 nagenuke_apagt_table[16] = {
    6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6,
};

const s16 dir32_skydm[32] = {
    88, 88, 88, 88, 88, 88, 88, 88,
    88, 88, 88, 97, 97, 97, 97, 98,
    98, 98, 97, 97, 97, 97, 88, 88,
    88, 88, 88, 88, 88, 88, 88, 88,
};

const s16 dir32_grddm[32] = {
    91, 91, 91, 91, 91, 91, 91, 91,
    91, 91, 91, 39, 39, 39, 39, 40,
    40, 40, 39, 39, 39, 39, 91, 91,
    91, 91, 91, 91, 91, 91, 91, 91,
};

const s16 dead_voice_table[16][2] = {
    { 479, 480 },  /* Gill */
    { 448, 449 },  /* Alex */
    { 375, 376 },  /* Ryu */
    { 400, 401 },  /* Yun */
    { 462, 463 },  /* Dudley */
    { 492, 493 },  /* Necro */
    { 544, 545 },  /* Hugo */
    { 352, 353 },  /* Ibuki */
    { 364, 365 },  /* Elena */
    { 424, 425 },  /* Oro */
    { 412, 413 },  /* Yang */
    { 387, 388 },  /* Ken */
    { 436, 437 },  /* Sean */
    { 688, 689 },  /* Urien */
    { 624, 625 },  /* Gouki */
    { 624, 625 },  /* Shin Gouki */
};

/* provisional name */
const s16 voice_select_table[16][4] = {
    { 484, 481, 488, 480 },  /* Gill */
    { 455, 451, 456, 449 },  /* Alex */
    { 380, 378, 381, 376 },  /* Ryu */
    { 408, 402, 406, 401 },  /* Yun */
    { 466, 464, 468, 463 },  /* Dudley */
    { 498, 494, 499, 493 },  /* Necro */
    { 479, 480, 480, 480 },  /* Hugo */
    { 357, 354, 356, 353 },  /* Ibuki */
    { 369, 367, 373, 365 },  /* Elena */
    { 429, 426, 428, 425 },  /* Oro */
    { 417, 415, 421, 413 },  /* Yang */
    { 391, 390, 398, 388 },  /* Ken */
    { 440, 438, 445, 437 },  /* Sean */
    { 479, 480, 480, 480 },  /* Urien */
    { 479, 480, 480, 480 },  /* Gouki */
    { 479, 480, 480, 480 },  /* Shin Gouki */
};

const u8 convert_saishin_lvdir[2][16] = {
    { 0, 0, 0, 0, 1, 1, 1, 0, 2, 2, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 2, 2, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
};

const s16 gauge_rank_table[6][2] = {
    { 90, 1000 },
    { 80, 600 },
    { 60, 400 },
    { 40, 300 },
    { 20, 200 },
    { 0, 100 },
};

const u8 jump_pat_status_data[2][4] = {
    { 22, 20, 24, 0 },
    { 22, 24, 20, 0 },
};
