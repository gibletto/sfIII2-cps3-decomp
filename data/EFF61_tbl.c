/*
 * EFF61_TBL.C  alternate background sliding part tables
 *
 * eff61_data_tbl has a row for each of the 44 parts of the alternate background; the pattern
 * number in its last column is set when the part slides. eff61_speed_tbl gives the slide speed
 * by speed number. Read by EFF61.C, a part of the alternate background.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 eff61_data_tbl[][4];
extern const s32 eff61_speed_tbl[];

const s16 eff61_data_tbl[44][4] = {
    { -384, 0, 0, 0x9A40 },
    { -256, 0, 1, 0x9A41 },
    { -128, 0, 2, 0x9A42 },
    { -64, 0, 7, 0x9A54 },
    { 64, 0, 3, 0x9A43 },
    { 64, 0, 8, 0x9A55 },
    { 128, 0, 6, 0x9A46 },
    { 256, 0, 5, 0x9A45 },
    { 384, 0, 4, 0x9A44 },
    { -384, 512, 0, 0x9A40 },
    { -256, 512, 1, 0x9A41 },
    { -128, 512, 2, 0x9A42 },
    { -64, 512, 7, 0x9A54 },
    { 64, 512, 3, 0x9A43 },
    { 64, 512, 8, 0x9A55 },
    { 128, 512, 6, 0x9A46 },
    { 256, 512, 5, 0x9A45 },
    { 384, 512, 4, 0x9A44 },
    { 0, 96, 9, 0x9A4D },
    { 512, 96, 9, 0x9A4D },
    { 0, 160, 10, 0x9A4E },
    { 512, 160, 10, 0x9A4E },
    { 0, 224, 11, 0x9A4F },
    { 512, 224, 11, 0x9A4F },
    { 0, 288, 12, 0x9A50 },
    { 512, 288, 12, 0x9A50 },
    { 0, 352, 13, 0x9A51 },
    { 512, 352, 13, 0x9A51 },
    { 0, 416, 14, 0x9A52 },
    { 512, 416, 14, 0x9A52 },
    { 0, 496, 15, 0x9A53 },
    { 512, 496, 15, 0x9A53 },
    { 0, 496, 9, 0x9A4D },
    { 512, 496, 9, 0x9A4D },
    { 0, 560, 10, 0x9A4E },
    { 512, 560, 10, 0x9A4E },
    { 0, 624, 11, 0x9A4F },
    { 512, 624, 11, 0x9A4F },
    { 0, 752, 12, 0x9A50 },
    { 512, 752, 12, 0x9A50 },
    { 0, 816, 13, 0x9A51 },
    { 512, 816, 13, 0x9A51 },
    { 0, 880, 14, 0x9A52 },
    { 512, 880, 14, 0x9A52 },
};

/* provisional name */
const s32 eff61_speed_tbl[16] = {
    0x300000, 0x180000, 0xF0000, 0x60000,
    0x300000, 0x180000, 0xF0000, 0x90000,
    0x90000, 0x140000, 0xD0000, 0xA0000,
    0x80000, 0xB0000, 0xC0000, 0x120000,
};
