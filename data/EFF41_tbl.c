/*
 * EFF41_TBL.C  super art sign, zoom object and animated stage object tables
 *
 * sa_sign_data has one row of four per super art sign: offset from the player, animation
 * number and gauge used (super art or EX); read by EFF41.C, the super art sign.
 * eff40_pos_x_tbl gives the x position of the select-screen zoom object for each direction
 * (EFF40.C). scr_obj_num44 holds the counts of the animated stage objects by type, and
 * scr_obj_data44_N the object rows of type N, named by scr_obj_data44 (EFF44.C). eff45_pos_x_tbl, eff45_pos_y_tbl and
 * eff45_pos_y_tbl2 are the random x and y positions of the stage objects of effect 45
 * (EFF45.C); eff45_pos_y_tbl3 is not referred to by name. eff46_char_tbl is the eight patterns
 * the object beside the winner picks from (EFF46.C).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 eff40_pos_x_tbl[];
extern const s16 sa_sign_data[][4];
extern const s16 scr_obj_num44[];
extern const s16 eff44_data_tbl0[];
extern const s16 eff44_data_tbl1[];
extern const s16 eff44_data_tbl2[];
extern const s16 eff44_data_tbl3[];
extern const s16 eff44_data_tbl4[];
extern const s16 eff44_data_tbl5[];
extern const s16 eff44_data_tbl6[];
extern const s16 eff44_data_tbl7[];
extern const s16 eff44_data_tbl8[];
extern const s16 eff45_pos_x_tbl[];
extern const s16 eff45_pos_y_tbl[];
extern const s16 eff45_pos_y_tbl2[];
extern const s16 eff45_pos_y_tbl3[];
extern const s16 eff46_char_tbl[];

const s16 eff40_pos_x_tbl[8] = {
    -109, -83, -54, -24, 24, 48, 72, 96,
};

/*
 * Four entries per super art sign (effect_41_init's data): x offset from the player
 * (mirrored by rl_flag), y offset, animation number and gauge used (1 super art, 2 EX).
 */
const s16 sa_sign_data[49][4] = {
    { 28, 70, 156, 1 }, { -41, 37, 156, 1 },
    { 12, 56, 156, 1 }, { -14, 80, 156, 1 },
    { -14, 48, 156, 1 }, { -28, 56, 156, 1 },
    { -12, 56, 156, 1 }, { -20, 84, 156, 1 },
    { -38, 44, 156, 1 }, { 48, 92, 156, 1 },
    { -43, 52, 156, 1 }, { -41, 37, 156, 1 },
    { -41, 37, 156, 1 }, { 28, 70, 156, 1 },
    { -32, 42, 156, 1 }, { 0, 72, 156, 1 },
    { 14, 65, 156, 1 }, { -41, 37, 156, 1 },
    { -58, 60, 156, 1 }, { -20, 64, 156, 1 },
    { -22, 66, 156, 1 }, { 22, 66, 156, 1 },
    { 0, 48, 156, 1 }, { -22, 74, 156, 1 },
    { -36, 52, 156, 1 }, { -32, 48, 156, 1 },
    { -12, 40, 156, 1 }, { -24, 68, 156, 1 },
    { -3, 72, 156, 1 }, { 2, 72, 156, 1 },
    { -74, 64, 156, 1 }, { 0, 72, 156, 1 },
    { 28, 10, 156, 1 }, { -48, 144, 156, 2 },
    { -16, 88, 156, 1 }, { -58, 74, 156, 1 },
    { -16, 88, 156, 1 }, { -9, 100, 156, 2 },
    { -57, 48, 156, 1 }, { 25, 53, 156, 0 },
    { -28, 44, 156, 1 }, { -22, 72, 156, 1 },
    { -22, 72, 156, 1 }, { -21, 123, 156, 1 },
    { -13, 67, 156, 1 }, { -22, 56, 156, 1 },
    { 32, 24, 156, 1 }, { -64, 62, 156, 1 },
    { -32, 64, 156, 1 },
};

const s16 scr_obj_num44[9] = {
    6, 2, 1, 10, 3, 1, 8, 1,
    2,
};

/* type 0 */
const s16 eff44_data_tbl0[48] = {
    1, 2, 8256, -368, 64, 82, 1, 1,
    0, 2, 64, 208, 96, 80, 3, 1,
    1, 2, 64, -128, 80, 83, 5, 1,
    0, 2, 8283, -145, 64, 77, 10, 1,
    1, 2, 8283, -233, 81, 79, 14, 1,
    1, 2, 8283, 273, 65, 74, 18, 1,
};

/* type 1 */
const s16 eff44_data_tbl1[16] = {
    1, 2, 8277, 272, 95, 76, 26, 0,
    1, 2, 8277, 336, 47, 77, 16, 0,
};

/* type 2 */
const s16 eff44_data_tbl2[8] = {
    1, 2, 8256, 239, 160, 78, 0, 0,
};

/* type 3 */
const s16 eff44_data_tbl3[80] = {
    0, 2, 8256, 663, 136, 75, 8, 0,
    0, 2, 8256, 683, 123, 75, 9, 0,
    1, 2, 8256, 775, 144, 75, 10, 0,
    1, 2, 8256, 640, 48, 75, 11, 0,
    1, 2, 8256, 360, 104, 75, 13, 0,
    1, 2, 8256, 372, 104, 75, 20, 0,
    1, 2, 8256, 908, 101, 75, 6, 0,
    1, 2, 8256, 53, 145, 75, 7, 0,
    1, 2, 8281, 352, 225, 75, 26, 0,
    0, 2, 8281, 368, 147, 75, 27, 0,
};

/* type 4 */
const s16 eff44_data_tbl4[24] = {
    1, 2, 8292, 295, 66, 75, 1, 0,
    1, 2, 8292, 175, 61, 76, 2, 0,
    1, 2, 64, 688, 73, 83, 18, 0,
};

/* type 5 */
const s16 eff44_data_tbl5[8] = {
    1, 2, 64, 688, 73, 83, 18, 0,
};

/* type 6 */
const s16 eff44_data_tbl6[64] = {
    1, 2, 8256, 816, 112, 79, 0, 0,
    1, 2, 8256, 800, 112, 81, 2, 0,
    1, 2, 8256, 792, 176, 80, 3, 0,
    1, 1, 8256, 224, 192, 95, 4, 0,
    1, 1, 8256, 320, 176, 95, 5, 0,
    1, 1, 8256, 352, 176, 95, 6, 0,
    0, 2, 8256, 840, 160, 83, 8, 0,
    1, 2, 8256, 720, 96, 90, 9, 0,
};

/* type 7 */
const s16 eff44_data_tbl7[8] = {
    1, 2, 8256, 272, 96, 87, 61, 0,
};

/* type 8 */
const s16 eff44_data_tbl8[17] = {
    0, 2, 8256, 224, 64, 72, 6, 0,
    0, 2, 64, 736, 208, 72, 7, 0,
    -1,
};

const s16 eff45_pos_x_tbl[32] = {
    512, 360, 480, 376, 384, 392, 400, 408,
    416, 424, 432, 440, 448, 456, 464, 512,
    528, 536, 544, 552, 560, 568, 576, 584,
    592, 600, 608, 616, 624, 648, 656, 672,
};

const s16 eff45_pos_y_tbl[16] = {
    216, 218, 220, 222, 240, 242, 244, 246,
    248, 250, 252, 254, 255, 245, 247, 256,
};

const s16 eff45_pos_y_tbl2[16] = {
    200, 202, 204, 206, 208, 210, 212, 214,
    217, 219, 221, 223, 209, 211, 213, 215,
};

/* provisional name */
/* A third y table after eff45_pos_y_tbl2 (168..198 by 2). Nothing in the program refers to it by name or address. */
const s16 eff45_pos_y_tbl3[16] = {
    168, 170, 172, 174, 176, 178, 180, 182,
    184, 186, 188, 190, 192, 194, 196, 198,
};

const s16 eff46_char_tbl[8] = {
    2, 1, 4, 6, 3, 1, 5, 2,
};
