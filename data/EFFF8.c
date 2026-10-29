/*
 * EFFF8.C  second parry mark offsets, ending scene lists and judge scene tables
 *
 * paring_b_mark_data is indexed by parry type and character and gives the { x, y } offset of
 * the parry mark from the player; read by EFFF8_CODE.C. efff9_no_scene (an empty list) and
 * pl01txt1 .. pl16txt1 are each character's ending scene lists of { message number, time }
 * pairs, each scene ended by 0, -1, reached through the txt_no_ tables of EFFF9_MES.C.
 * effg0_col_tbl, effg0_pos_tbl and effg0_flash_tbl give the colour, position and flashing sign
 * of each judge character of an ending scene, and effg0_name_tbl the name signs { pattern, x,
 * y } ended by -1; read by EFFG0.C. effg0_name_tbl2 .. effg0_name_tbl4 are further sign lists
 * not referred to by name.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 paring_b_mark_data[][16][2];
extern const u16 efff9_no_scene[];
extern const u16 pl01txt1[];
extern const u16 pl02txt1[];
extern const u16 pl03txt1[];
extern const u16 pl04txt1[];
extern const u16 pl05txt1[];
extern const u16 pl06txt1[];
extern const u16 pl07txt1[];
extern const u16 pl08txt1[];
extern const u16 pl09txt1[];
extern const u16 pl11txt1[];
extern const u16 pl12txt1[];
extern const u16 pl13txt1[];
extern const u16 pl14txt1[];
extern const u16 pl16txt1[];
extern const s16 effg0_col_tbl[];
extern const s16 effg0_pos_tbl[][3];
extern const s16 effg0_flash_tbl[][4];
extern const s16 effg0_name_tbl[][3];
extern const s16 effg0_name_tbl2[][3];
extern const s16 effg0_name_tbl3[][3];
extern const s16 effg0_name_tbl4[];

const s16 paring_b_mark_data[3][16][2] = {
    {
        { 28, 100 }, { 12, 88 }, { 10, 84 }, { 8, 76 },
        { 14, 88 }, { 16, 86 }, { 24, 104 }, { 8, 70 },
        { 20, 82 }, { 28, 70 }, { 8, 76 }, { 10, 84 },
        { 10, 84 }, { 28, 100 }, { 10, 84 }, { 10, 84 },
    },
    {
        { 12, 52 }, { 26, 52 }, { 16, 50 }, { 10, 48 },
        { 24, 60 }, { 24, 66 }, { 26, 68 }, { 16, 46 },
        { 28, 44 }, { 26, 44 }, { 10, 48 }, { 16, 50 },
        { 16, 50 }, { 12, 52 }, { 16, 50 }, { 16, 50 },
    },
    {
        { 40, 92 }, { 42, 62 }, { 28, 76 }, { 28, 76 },
        { 38, 68 }, { 30, 84 }, { 28, 108 }, { 28, 56 },
        { 38, 52 }, { 40, 60 }, { 28, 76 }, { 32, 48 },
        { 32, 48 }, { 40, 92 }, { 28, 76 }, { 28, 76 },
    },
};

/* provisional name */
const u16 efff9_no_scene[2] = {
    0, 0xFFFF,
};

/* provisional name */
const u16 pl01txt1[50] = {
    1, 160, 2, 200, 3, 180, 4, 220,
    5, 220, 6, 280, 0, -1, 7, 512,
    0, -1, 8, 240, 9, 90, 0, -1,
    10, 180, 0, -1, 11, 140, 12, 180,
    13, 380, 0, -1, 14, 280, 15, 300,
    0, -1, 0, -1, 16, 240, 17, 360,
    0, -1,
};

/* provisional name */
const u16 pl02txt1[20] = {
    1, 260, 2, 220, 0, -1, 3, 130,
    4, 230, 0, -1, 5, 180, 0, -1,
    6, 400, 0, -1,
};

/* provisional name */
const u16 pl03txt1[48] = {
    1, 256, 0, -1, 2, 256, 0, -1,
    3, 90, 4, 120, 5, 288, 0, -1,
    6, 90, 7, 180, 8, 288, 0, -1,
    9, 120, 10, 240, 0, -1, 11, 256,
    0, -1, 12, 288, 0, -1, 13, 288,
    0, -1, 14, 240, 15, 288, 0, -1,
};

/* provisional name */
const u16 pl04txt1[30] = {
    1, 170, 2, 200, 3, 256, 0, -1,
    4, 180, 0, -1, 5, 256, 0, -1,
    6, 154, 7, 180, 8, 256, 0, -1,
    9, 64, 10, 512, 0, -1,
};

/* provisional name */
const u16 pl05txt1[36] = {
    1, 342, 0, -1, 2, 256, 3, 276,
    0, -1, 4, 512, 0, -1, 5, 292,
    9, 60, 10, 60, 11, 60, 12, 60,
    6, 60, 0, -1, 0, -1, 7, 212,
    8, 330, 0, -1,
};

/* provisional name */
const u16 pl06txt1[66] = {
    1, 0xB4, 2, 0x900, 0, 0xFFFF, 3, 0xB4,
    4, 0x96, 5, 0x96, 6, 0x96, 7, 0x900,
    0, 0xFFFF, 8, 0xB4, 9, 0xF0, 0xA, 0x900,
    0, 0xFFFF, 0xB, 0xF0, 0xC, 0x96, 0xD, 0x900,
    0, 0xFFFF, 0xE, 0xF0, 0xF, 0x96, 0x10, 0x900,
    0, 0xFFFF, 0x11, 0xF0, 0x12, 0x96, 0x13, 0x900,
    0, 0xFFFF, 0x14, 0xF0, 0x15, 0x96, 0x16, 0x900,
    0, 0xFFFF, 0x17, 0xB4, 0x18, 0xF0, 0xA, 0x900,
    0, 0xFFFF,
};

/* provisional name */
const u16 pl07txt1[48] = {
    0, -1, 1, 120, 2, 90, 3, 160,
    4, 196, 5, 100, 6, 196, 7, 256,
    0, -1, 0, -1, 0, -1, 0, -1,
    8, 512, 0, -1, 9, 512, 0, -1,
    0, -1, 10, 512, 0, -1, 11, 176,
    12, 230, 13, 134, 14, 512, 0, -1,
};

/* provisional name */
const u16 pl08txt1[20] = {
    1, 160, 2, 280, 3, 768, 0, -1,
    4, 768, 0, -1, 5, 180, 6, 768,
    0, -1, 0, -1,
};

/* provisional name */
const u16 pl09txt1[20] = {
    1, 0x200, 0, 0xFFFF, 2, 0x340, 0, 0xFFFF,
    0, 0xFFFF, 3, 0x300, 0, 0xFFFF, 4, 0xF0,
    5, 0x300, 0, 0xFFFF,
};

/* provisional name */
const u16 pl11txt1[24] = {
    1, 0xF0, 2, 0x200, 0, 0xFFFF, 3, 0x200,
    0, 0xFFFF, 4, 0x200, 0, 0xFFFF, 0, 0xFFFF,
    5, 0x200, 0, 0xFFFF, 6, 0x200, 0, 0xFFFF,
};

/* provisional name */
const u16 pl12txt1[26] = {
    1, 0x300, 0, 0xFFFF, 2, 0x5A, 3, 0xB4,
    4, 0x78, 5, 0x300, 0, 0xFFFF, 6, 0x300,
    0, 0xFFFF, 7, 0x300, 0, 0xFFFF, 8, 0x300,
    0, 0xFFFF,
};

/* provisional name */
const u16 pl13txt1[34] = {
    1, 360, 2, 2304, 0, -1, 3, 180,
    4, 2304, 0, -1, 5, 240, 6, 150,
    7, 300, 8, 2304, 0, -1, 9, 144,
    10, 180, 11, 240, 12, 300, 13, 2304,
    0, -1,
};

/* provisional name */
const u16 pl14txt1[26] = {
    1, 2304, 0, -1, 2, 180, 3, 2304,
    0, -1, 4, 2304, 0, -1, 0, 240,
    5, 2304, 0, -1, 6, 240, 7, 2304,
    0, -1,
};

/* provisional name */
const u16 pl16txt1[12] = {
    0, 128, 1, 192, 2, 144, 3, 128,
    4, 384, 0, -1,
};

const s16 effg0_col_tbl[7] = {
    8320, 8321, 8322, 8323, 8324, 8325, 8326,
};

const s16 effg0_pos_tbl[7][3] = {
    { 72, -6, -2 },
    { 320, -6, -2 },
    { 168, -6, -2 },
    { 208, -6, -2 },
    { 248, -6, -2 },
    { 16, -6, -3 },
    { 120, -6, -2 },
};

const s16 effg0_flash_tbl[7][4] = {
    { 25, 101, 17, 32 },
    { 42, 107, 37, 85 },
    { 18, 116, 23, 35 },
    { 18, 116, 20, 35 },
    { 18, 116, 28, 35 },
    { 30, 90, 29, 30 },
    { 23, 112, 10, 34 },
};

const s16 effg0_name_tbl[54][3] = {
    { 29, 32, 192 },
    { 17, 48, 192 },
    { 10, 64, 192 },
    { 23, 80, 192 },
    { 20, 96, 192 },
    { 34, 128, 192 },
    { 24, 144, 192 },
    { 30, 160, 192 },
    { 15, 192, 192 },
    { 24, 208, 192 },
    { 27, 224, 192 },
    { 25, 256, 192 },
    { 21, 272, 192 },
    { 10, 288, 192 },
    { 34, 304, 192 },
    { 18, 320, 192 },
    { 23, 336, 192 },
    { 16, 352, 192 },
    { 37, 368, 192 },
    { 28, 48, 160 },
    { 29, 64, 160 },
    { 27, 80, 160 },
    { 14, 96, 160 },
    { 14, 112, 160 },
    { 29, 128, 160 },
    { 15, 160, 160 },
    { 18, 176, 160 },
    { 16, 192, 160 },
    { 17, 208, 160 },
    { 29, 224, 160 },
    { 14, 240, 160 },
    { 27, 256, 160 },
    { 41, 288, 160 },
    { 2, 208, 144 },
    { 23, 224, 144 },
    { 13, 240, 144 },
    { 18, 272, 144 },
    { 22, 288, 144 },
    { 25, 304, 144 },
    { 10, 320, 144 },
    { 12, 336, 144 },
    { 29, 352, 144 },
    { 12, 112, 112 },
    { 24, 128, 112 },
    { 22, 144, 112 },
    { 18, 160, 112 },
    { 23, 176, 112 },
    { 16, 192, 112 },
    { 28, 224, 112 },
    { 24, 240, 112 },
    { 24, 256, 112 },
    { 23, 272, 112 },
    { 37, 288, 112 },
    { -1, 0, 0 },
};

/* provisional name */
/* Name signs (pattern, x, y) ended by -1, like effg0_name_tbl. Nothing in the program refers to it by name or
   address. */
const s16 effg0_name_tbl2[53][3] = {
    { 22, 80, 208 },
    { 14, 96, 208 },
    { 27, 112, 208 },
    { 27, 128, 208 },
    { 34, 144, 208 },
    { 33, 176, 208 },
    { 42, 192, 208 },
    { 22, 208, 208 },
    { 10, 224, 208 },
    { 28, 240, 208 },
    { 10, 272, 208 },
    { 23, 288, 208 },
    { 13, 304, 208 },
    { 10, 64, 192 },
    { 17, 96, 192 },
    { 10, 112, 192 },
    { 25, 128, 192 },
    { 25, 144, 192 },
    { 34, 160, 192 },
    { 23, 192, 192 },
    { 14, 208, 192 },
    { 32, 224, 192 },
    { 34, 256, 192 },
    { 14, 272, 192 },
    { 10, 288, 192 },
    { 27, 304, 192 },
    { 37, 320, 192 },
    { 28, 64, 48 },
    { 29, 80, 48 },
    { 27, 96, 48 },
    { 14, 112, 48 },
    { 14, 128, 48 },
    { 29, 144, 48 },
    { 15, 176, 48 },
    { 18, 192, 48 },
    { 16, 208, 48 },
    { 17, 224, 48 },
    { 29, 240, 48 },
    { 14, 256, 48 },
    { 27, 272, 48 },
    { 41, 304, 48 },
    { 12, 96, 32 },
    { 24, 112, 32 },
    { 22, 128, 32 },
    { 18, 144, 32 },
    { 23, 160, 32 },
    { 16, 176, 32 },
    { 28, 208, 32 },
    { 24, 224, 32 },
    { 24, 240, 32 },
    { 23, 256, 32 },
    { 37, 272, 32 },
    { -1, 0, 0 },
};

/* provisional name */
/* Name signs ended by -1. Nothing in the program refers to it by name or address. */
const s16 effg0_name_tbl3[44][3] = {
    { 10, 64, 208 },
    { 17, 96, 208 },
    { 10, 112, 208 },
    { 25, 128, 208 },
    { 25, 144, 208 },
    { 34, 160, 208 },
    { 23, 192, 208 },
    { 14, 208, 208 },
    { 32, 224, 208 },
    { 34, 256, 208 },
    { 14, 272, 208 },
    { 10, 288, 208 },
    { 27, 304, 208 },
    { 37, 320, 208 },
    { 1, 144, 192 },
    { 9, 176, 192 },
    { 9, 208, 192 },
    { 7, 240, 192 },
    { 28, 64, 48 },
    { 29, 80, 48 },
    { 27, 96, 48 },
    { 14, 112, 48 },
    { 14, 128, 48 },
    { 29, 144, 48 },
    { 15, 176, 48 },
    { 18, 192, 48 },
    { 16, 208, 48 },
    { 17, 224, 48 },
    { 29, 240, 48 },
    { 14, 256, 48 },
    { 27, 272, 48 },
    { 41, 304, 48 },
    { 12, 96, 32 },
    { 24, 112, 32 },
    { 22, 128, 32 },
    { 18, 144, 32 },
    { 23, 160, 32 },
    { 16, 176, 32 },
    { 28, 208, 32 },
    { 24, 224, 32 },
    { 24, 240, 32 },
    { 23, 256, 32 },
    { 37, 272, 32 },
    { -1, 0, 0 },
};

/* provisional name */
/* An empty sign list (-1). Nothing in the program refers to it by name or address. */
const s16 effg0_name_tbl4[1] = {
    -1,
};
