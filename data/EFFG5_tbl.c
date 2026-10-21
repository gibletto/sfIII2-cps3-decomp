/*
 * EFFG5_TBL.C  tables read by effect G5
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 num_of_ase[];
extern const s16 ase_dir_hosei[][6];
extern const s16 ase_speed_hosei[][6];
extern const s16 ase_delta_hosei[][6];

const s16 num_of_ase[4] = {
    0, 3, 5, 6,
};

const s16 ase_dir_hosei[4][6] = {
    { -2, 3, -1, 30, 1, 33 },
    { 2, -3, 1, 33, -1, 30 },
    { 1, -2, 2, 34, 0, 31 },
    { -1, 2, -2, 31, 0, 34 },
};

const s16 ase_speed_hosei[4][6] = {
    { 1152, 1280, 1664, 1024, 1792, 1280 },
    { 1152, 1280, 1664, 1024, 1792, 1280 },
    { 1152, 1280, 1664, 1024, 1792, 1280 },
    { 1152, 1280, 1664, 1024, 1792, 1280 },
};

const s16 ase_delta_hosei[4][6] = {
    { -88, -96, -112, -80, -128, -88 },
    { -88, -96, -112, -80, -128, -88 },
    { -88, -96, -112, -80, -128, -88 },
    { -88, -96, -112, -80, -128, -88 },
};
