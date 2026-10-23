/*
 * PLS00_TBL.C  tables read by PLS00.c and PLS01.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const process_ndcca[])();
extern void (*const plpnm_xxxxx[])();
extern void (*const plpdm_xxxxx[])();
extern const u8 about_rno[];
extern const s16 sel_hd_fg_hos[][2];
extern const s16 dir32_rl_conv[];
extern void dm_00000();
extern void dm_04000();
extern void dm_08000();
extern void dm_17000();
extern void dm_18000();
extern void dm_25000();
extern void nm_00000();
extern void nm_01000();
extern void nm_02000();
extern void nm_03000();
extern void nm_05000();
extern void nm_07000();
extern void nm_08000();
extern void nm_09000();
extern void nm_10000();
extern void nm_11000();
extern void nm_13000();
extern void nm_16000();
extern void nm_17000();
extern void nm_18000();
extern void nm_27000();
extern void nm_29000();
extern void nm_31000();
extern void nm_34000();
extern void nm_36000();
extern void nm_37000();
extern void nm_38000();
extern void nm_39000();
extern void nm_40000();
extern void nm_42000();
extern void nm_45000();
extern void nm_47000();
extern void nm_48000();
extern void nm_49000();
extern void nm_91000();
extern void nm_95000();
extern void process_attack();
extern void process_catch();
extern void process_caught();
extern void process_damage();
extern void process_normal();

void (*const process_ndcca[5])() = {
    (void (*)())process_normal,
    (void (*)())process_damage,
    (void (*)())process_catch,
    (void (*)())process_caught,
    (void (*)())process_attack,
};

void (*const plpnm_xxxxx[51])() = {
    (void (*)())nm_00000,
    (void (*)())nm_01000,
    (void (*)())nm_02000,
    (void (*)())nm_03000,
    (void (*)())nm_03000,
    (void (*)())nm_05000,
    (void (*)())nm_05000,
    (void (*)())nm_07000,
    (void (*)())nm_08000,
    (void (*)())nm_09000,
    (void (*)())nm_10000,
    (void (*)())nm_11000,
    (void (*)())nm_11000,
    (void (*)())nm_13000,
    (void (*)())nm_13000,
    (void (*)())nm_13000,
    (void (*)())nm_16000,
    (void (*)())nm_17000,
    (void (*)())nm_18000,
    (void (*)())nm_18000,
    (void (*)())nm_18000,
    (void (*)())nm_18000,
    (void (*)())nm_18000,
    (void (*)())nm_18000,
    (void (*)())nm_18000,
    (void (*)())nm_18000,
    (void (*)())nm_18000,
    (void (*)())nm_27000,
    (void (*)())nm_27000,
    (void (*)())nm_29000,
    (void (*)())nm_27000,
    (void (*)())nm_31000,
    (void (*)())nm_31000,
    (void (*)())nm_31000,
    (void (*)())nm_34000,
    (void (*)())nm_34000,
    (void (*)())nm_36000,
    (void (*)())nm_37000,
    (void (*)())nm_38000,
    (void (*)())nm_39000,
    (void (*)())nm_40000,
    (void (*)())nm_40000,
    (void (*)())nm_42000,
    (void (*)())nm_42000,
    (void (*)())nm_42000,
    (void (*)())nm_45000,
    (void (*)())nm_45000,
    (void (*)())nm_47000,
    (void (*)())nm_48000,
    (void (*)())nm_49000,
    (void (*)())nm_49000,
};

void (*const plpdm_xxxxx[38])() = {
    (void (*)())dm_00000,
    (void (*)())dm_04000,
    (void (*)())dm_04000,
    (void (*)())dm_04000,
    (void (*)())dm_04000,
    (void (*)())dm_04000,
    (void (*)())dm_04000,
    (void (*)())dm_04000,
    (void (*)())dm_08000,
    (void (*)())dm_08000,
    (void (*)())dm_08000,
    (void (*)())dm_08000,
    (void (*)())dm_04000,
    (void (*)())dm_04000,
    (void (*)())dm_18000,
    (void (*)())dm_18000,
    (void (*)())dm_04000,
    (void (*)())dm_17000,
    (void (*)())dm_18000,
    (void (*)())dm_18000,
    (void (*)())dm_18000,
    (void (*)())dm_18000,
    (void (*)())dm_18000,
    (void (*)())dm_18000,
    (void (*)())dm_00000,
    (void (*)())dm_25000,
    (void (*)())dm_18000,
    (void (*)())dm_18000,
    (void (*)())dm_18000,
    (void (*)())dm_18000,
    (void (*)())dm_18000,
    (void (*)())nm_91000,
    (void (*)())nm_91000,
    (void (*)())nm_91000,
    (void (*)())nm_91000,
    (void (*)())nm_95000,
    (void (*)())nm_95000,
    (void (*)())nm_95000,
};

const u8 about_rno[6] = {
    0, 1, 2, 1, 2, 0,
};

const s16 sel_hd_fg_hos[32][2] = {
    { 0, 0 },
    { 8, 0 },
    { 48, 88 },
    { 8, 6 },
    { 36, 76 },
    { 8, 5 },
    { 40, 64 },
    { 8, 4 },
    { 44, 76 },
    { 8, 5 },
    { 40, 68 },
    { 8, 5 },
    { 0, 0 },
    { 8, 0 },
    { 36, 68 },
    { 8, 6 },
    { 24, 72 },
    { 8, 5 },
    { 16, 60 },
    { 8, 4 },
    { 40, 64 },
    { 8, 4 },
    { 36, 76 },
    { 8, 5 },
    { 36, 76 },
    { 8, 5 },
    { 0, 0 },
    { 8, 0 },
    { 0, 0 },
    { 8, 0 },
    { 0, 0 },
    { 8, 0 },
};

const s16 dir32_rl_conv[11] = {
    0, 31, 30, 29, 28, 27, 26, 25,
    24, 23, 22,
};
