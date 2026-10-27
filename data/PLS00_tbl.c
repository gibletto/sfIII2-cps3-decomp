/*
 * PLS00_TBL.C  player state check dispatch tables
 *
 * process_ndcca lists the lever and button check for each routine class (normal, damage,
 * catch, caught, attack), plpnm_xxxxx the per-state checks (nm_00000 onward) of the normal
 * routines and plpdm_xxxxx those of the damage routines; these are read by PLS00.C. about_rno
 * groups the routine classes (1 for damage and caught) for check_em_tk_power_off,
 * sel_hd_fg_hos gives each character the offsets and direction window of check_attbox_dir, and
 * dir32_rl_conv mirrors a 32-way direction; these are read by PLS01.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const process_ndcca[])();
extern void (*const plpnm_xxxxx[])();
extern void (*const plpdm_xxxxx[])();
extern const u8 about_rno[];
extern const s16 sel_hd_fg_hos[][4];
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
    process_normal,
    process_damage,
    process_catch,
    process_caught,
    process_attack,
};

void (*const plpnm_xxxxx[51])() = {
    nm_00000,
    nm_01000,
    nm_02000,
    nm_03000,
    nm_03000,
    nm_05000,
    nm_05000,
    nm_07000,
    nm_08000,
    nm_09000,
    nm_10000,
    nm_11000,
    nm_11000,
    nm_13000,
    nm_13000,
    nm_13000,
    nm_16000,
    nm_17000,
    nm_18000,
    nm_18000,
    nm_18000,
    nm_18000,
    nm_18000,
    nm_18000,
    nm_18000,
    nm_18000,
    nm_18000,
    nm_27000,
    nm_27000,
    nm_29000,
    nm_27000,
    nm_31000,
    nm_31000,
    nm_31000,
    nm_34000,
    nm_34000,
    nm_36000,
    nm_37000,
    nm_38000,
    nm_39000,
    nm_40000,
    nm_40000,
    nm_42000,
    nm_42000,
    nm_42000,
    nm_45000,
    nm_45000,
    nm_47000,
    nm_48000,
    nm_49000,
    nm_49000,
};

void (*const plpdm_xxxxx[38])() = {
    dm_00000,
    dm_04000,
    dm_04000,
    dm_04000,
    dm_04000,
    dm_04000,
    dm_04000,
    dm_04000,
    dm_08000,
    dm_08000,
    dm_08000,
    dm_08000,
    dm_04000,
    dm_04000,
    dm_18000,
    dm_18000,
    dm_04000,
    dm_17000,
    dm_18000,
    dm_18000,
    dm_18000,
    dm_18000,
    dm_18000,
    dm_18000,
    dm_00000,
    dm_25000,
    dm_18000,
    dm_18000,
    dm_18000,
    dm_18000,
    dm_18000,
    nm_91000,
    nm_91000,
    nm_91000,
    nm_91000,
    nm_95000,
    nm_95000,
    nm_95000,
};

const u8 about_rno[6] = {
    0, 1, 2, 1, 2, 0,
};

const s16 sel_hd_fg_hos[16][4] = {
    { 0, 0, 8, 0 },  /* Gill */
    { 48, 88, 8, 6 },  /* Alex */
    { 36, 76, 8, 5 },  /* Ryu */
    { 40, 64, 8, 4 },  /* Yun */
    { 44, 76, 8, 5 },  /* Dudley */
    { 40, 68, 8, 5 },  /* Necro */
    { 0, 0, 8, 0 },  /* Hugo */
    { 36, 68, 8, 6 },  /* Ibuki */
    { 24, 72, 8, 5 },  /* Elena */
    { 16, 60, 8, 4 },  /* Oro */
    { 40, 64, 8, 4 },  /* Yang */
    { 36, 76, 8, 5 },  /* Ken */
    { 36, 76, 8, 5 },  /* Sean */
    { 0, 0, 8, 0 },  /* Urien */
    { 0, 0, 8, 0 },  /* Gouki */
    { 0, 0, 8, 0 },  /* Shin Gouki */
};

const s16 dir32_rl_conv[11] = {
    0, 31, 30, 29, 28, 27, 26, 25,
    24, 23, 22,
};
