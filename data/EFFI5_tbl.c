/*
 * EFFI5_TBL.C  ending object, stage object, attack sign and blocking bonus stage tables
 *
 * effI5_fade_tbl is the 16 palette steps the ending object of effect I5 fades in through
 * (EFFI5.C). scr_obj_numI6 holds the counts and object rows of the stage objects of effect I6,
 * reached by stage through scr_obj_dataI6 (EFFI6.C). ex_sign_data gives the x and y offset,
 * pattern and follow flag of each sign shown beside a player during an attack (EFFI7.C).
 * effI8_hit_box is the box in which the thrower catches a ball of the blocking bonus stage and
 * bbbs_emtall the height the ball is aimed at for each character (EFFI8.C). effj1_col_tbl is
 * the { timer, colour } cycle of the ending object of effect J1 (EFFJ1.C), and
 * bbbs_nando_large the six-part bonus-stage level plate (EFFJ2_CODE.C).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 effI5_fade_tbl[];
extern const s16 scr_obj_numI6[];
extern const s16 ex_sign_data[][4];
extern const s16 effI8_hit_box[][4];
extern const s16 bbbs_emtall[];
extern const s16 effj1_col_tbl[][2];
extern const CONN bbbs_nando_large[];

const s16 effI5_fade_tbl[16] = {
    16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29, 30, 31,
};

/* provisional name */
const s16 scr_obj_numI6[224] = {
    0, 3, 5, 4, 1, 1, 5, 0,
    1, 2, 1, 3, 4, 3, 1, 0,
    0, 0, 0, 3, 8256, 704, 80, 86,
    1, 3, 8256, 384, 112, 86, 0, 2,
    8256, 480, 48, 83, 2, 2, 64, 528,
    80, 80, 2, 2, 64, 224, 80, 83,
    4, 2, 64, 591, 129, 82, 0, 2,
    64, 720, 65, 82, 6, 2, 64, 416,
    112, 82, 7, 2, 8256, 413, 69, 81,
    1, 2, 8256, 479, 64, 84, 2, 2,
    64, 576, 64, 87, 3, 2, 8256, 640,
    64, 93, 4, 2, 8256, 288, 32, 88,
    2, 2, 8256, 512, 128, 103, 9, 2,
    8256, 736, 24, 23, 62, 2, 8256, 255,
    48, 79, 1, 2, 8256, 663, 136, 75,
    8, 2, 8256, 606, 105, 83, 28, 2,
    8256, 666, 62, 74, 26, 2, 8256, 686,
    25, 19, 27, 2, 64, 624, 145, 82,
    24, 2, 8256, 512, 144, 82, 17, 0,
    2, 8256, 512, 32, 76, 0, 3, 8256,
    384, 96, 86, 2, 2, 64, 511, 0,
    82, 1, 2, 8256, 656, 128, 74, 7,
    2, 8256, 687, 176, 76, 0, 2, 8256,
    560, 0, 76, 4, 2, 8256, 511, 0,
    76, 2, 2, 8256, 511, 0, 76, 3,
    2, 8256, 431, 176, 72, 4, 2, 8256,
    575, 128, 72, 3, 2, 8256, 655, 48,
    72, 2, 3, 64, 600, 48, 86, 32,
};

const s16 ex_sign_data[48][4] = {
    { 28, 70, 121, 1 }, { -44, 60, 121, 0 },
    { -24, 40, 121, 1 }, { -12, 52, 121, 1 },
    { -40, 68, 121, 1 }, { -32, 64, 121, 0 },
    { -32, 64, 121, 1 }, { -20, 88, 121, 0 },
    { -16, 72, 121, 1 }, { 40, 60, 121, 0 },
    { -36, 39, 121, 1 }, { 0, 112, 121, 1 },
    { -20, 60, 121, 1 }, { -16, 56, 121, 1 },
    { -40, 60, 121, 1 }, { 0, 24, 121, 1 },
    { 16, 68, 121, 1 }, { -44, 60, 121, 0 },
    { -24, 40, 121, 1 }, { -40, 68, 121, 1 },
    { 16, 32, 121, 1 }, { -8, 40, 121, 1 },
    { 20, 36, 121, 1 }, { -8, 72, 121, 1 },
    { 0, 40, 121, 1 }, { 24, 80, 121, 0 },
    { 8, 56, 121, 0 }, { 20, 20, 121, 0 },
    { 20, 24, 121, 1 }, { 8, 48, 121, 1 },
    { -32, 48, 121, 1 }, { -32, 52, 121, 1 },
    { -22, 60, 121, 0 }, { -32, 64, 121, 1 },
    { 0, 16, 121, 1 }, { -8, 36, 121, 1 },
    { -24, 36, 121, 1 }, { -16, 40, 121, 1 },
    { -16, 32, 121, 0 }, { -12, 20, 121, 0 },
    { 0, 80, 121, 0 }, { 0, 24, 121, 1 },
    { -32, 80, 121, 0 }, { -8, 100, 121, 1 },
    { -16, 96, 121, 1 }, { -4, 76, 121, 1 },
    { -8, 120, 121, 1 }, { -16, 112, 121, 1 },
};

const s16 effI8_hit_box[2][4] = {
    { -9, 17, -6, 12 }, { -4, 10, 114, 9 },
};

const s16 bbbs_emtall[16] = {
    84, 76, 68, 60, 76, 68, 88, 60,
    60, 56, 60, 68, 68, 84, 68, 68,
};

const s16 effj1_col_tbl[4][2] = {
    { 2, 8480 },
    { 2, 8481 },
    { 2, 8480 },
    { 2, 8482 },
};

const CONN bbbs_nando_large[6] = {
    { 56, 88, 0, 0xB2EB },
    { 24, 88, 0, 0xB2EA },
    { 24, 88, 0, 0xB2E9 },
    { 24, 88, 0, 0xB2E8 },
    { 24, 88, 0, 0xB2E7 },
    { 24, 88, 0, 0xB2E6 },
};
