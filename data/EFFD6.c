/*
 * EFFD6.C  rose petal, thrown ball and select cursor tables
 *
 * num_of_hana gives the number of petals in each petal set, and hana_dir_hosei,
 * hana_speed_hosei and hana_delta_hosei the direction offset, speed and slowdown of each
 * petal, picked at random; read by EFFD6_CODE.C, the rose petals. effD7_hit_box is the box in
 * which a player catches the thrown ball (EFFD7.C), and effD8_char_tbl the patterns of the
 * face cursor of each player on the character select screen (EFFD8.C).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 num_of_hana[];
extern const s16 hana_dir_hosei[][6];
extern const s16 hana_speed_hosei[][6];
extern const s16 hana_delta_hosei[][6];
extern const s16 effD7_hit_box[][4];
extern const u8 effD8_char_tbl[][2];

const s16 num_of_hana[4] = {
    3, 4, 5, 6,
};

const s16 hana_dir_hosei[4][6] = {
    { -3, 2, -1, 1, -2, 0 },
    { -3, 1, -2, 3, 0, 2 },
    { -1, 2, -3, 4, -2, 0 },
    { -1, 3, -3, 1, 0, 2 },
};

const s16 hana_speed_hosei[4][6] = {
    { 960, 1216, 1408, 1472, 1728, 1792 },
    { 1024, 1152, 1536, 1600, 1824, 1920 },
    { 960, 1216, 1344, 1408, 1664, 1856 },
    { 1024, 1088, 1600, 1728, 1920, 1792 },
};

const s16 hana_delta_hosei[4][6] = {
    { -64, -72, -80, -72, -88, -80 },
    { -64, -72, -80, -72, -88, -80 },
    { -64, -72, -80, -72, -88, -80 },
    { -64, -72, -80, -72, -88, -80 },
};

const s16 effD7_hit_box[2][4] = {
    { -9, 17, -6, 12 },
    { -4, 10, 114, 9 },
};

/* provisional name */
const u8 effD8_char_tbl[3][2] = {
    { 0x40, 0x3F },
    { 0x42, 0x41 },
    { 0x44, 0x43 },
};
