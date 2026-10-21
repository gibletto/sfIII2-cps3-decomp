/*
 * PLPNM_TBL.C  tables read by PLNORMAL.c and PLPNM.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 nmPB_data[][3];
extern const s16 nmCE_data[][3];
extern void (*const plpnm_lv_00[])();
extern void (*const normal_05[])();
extern void (*const normal_06[])();
extern const u16 jpdat_tbl[][2];
extern void Normal_00000();
extern void Normal_01000();
extern void Normal_02000();
extern void Normal_03000();
extern void Normal_04000();
extern void Normal_05000();
extern void Normal_06000();
extern void Normal_07000();
extern void Normal_08000();
extern void Normal_09000();
extern void Normal_10000();
extern void Normal_11000();
extern void Normal_12000();
extern void Normal_13000();
extern void Normal_16000();
extern void Normal_17000();
extern void Normal_18000();
extern void Normal_27000();
extern void Normal_31000();
extern void Normal_35000();
extern void Normal_36000();
extern void Normal_37000();
extern void Normal_38000();
extern void Normal_39000();
extern void Normal_40000();
extern void Normal_41000();
extern void Normal_42000();
extern void Normal_47000();
extern void Normal_48000();
extern void Normal_50000();
extern void Normal_air_paring();
extern void nm_05_0000();
extern void nm_05_0100();
extern void nm_06_0000();
extern void nm_06_0100();
extern void nm_06_0200();

const s16 nmPB_data[5][3] = {
    { 38, 23, 1 },
    { 39, 23, 1 },
    { 40, 24, 1 },
    { 41, 25, 0 },
    { 42, 25, 0 },
};

const s16 nmCE_data[4][3] = {
    { 43, 26, 1 },
    { 44, 27, 1 },
    { 45, 28, 0 },
    { 46, 29, 0 },
};

void (*const plpnm_lv_00[51])() = {
    (void (*)())Normal_00000,
    (void (*)())Normal_01000,
    (void (*)())Normal_02000,
    (void (*)())Normal_03000,
    (void (*)())Normal_04000,
    (void (*)())Normal_05000,
    (void (*)())Normal_06000,
    (void (*)())Normal_07000,
    (void (*)())Normal_08000,
    (void (*)())Normal_09000,
    (void (*)())Normal_10000,
    (void (*)())Normal_11000,
    (void (*)())Normal_12000,
    (void (*)())Normal_13000,
    (void (*)())Normal_13000,
    (void (*)())Normal_13000,
    (void (*)())Normal_16000,
    (void (*)())Normal_17000,
    (void (*)())Normal_18000,
    (void (*)())Normal_18000,
    (void (*)())Normal_18000,
    (void (*)())Normal_18000,
    (void (*)())Normal_18000,
    (void (*)())Normal_18000,
    (void (*)())Normal_18000,
    (void (*)())Normal_18000,
    (void (*)())Normal_18000,
    (void (*)())Normal_27000,
    (void (*)())Normal_27000,
    (void (*)())Normal_27000,
    (void (*)())Normal_27000,
    (void (*)())Normal_31000,
    (void (*)())Normal_31000,
    (void (*)())Normal_31000,
    (void (*)())Normal_35000,
    (void (*)())Normal_air_paring,
    (void (*)())Normal_36000,
    (void (*)())Normal_37000,
    (void (*)())Normal_38000,
    (void (*)())Normal_39000,
    (void (*)())Normal_40000,
    (void (*)())Normal_41000,
    (void (*)())Normal_42000,
    (void (*)())Normal_42000,
    (void (*)())Normal_42000,
    (void (*)())Normal_42000,
    (void (*)())Normal_42000,
    (void (*)())Normal_47000,
    (void (*)())Normal_48000,
    (void (*)())Normal_47000,
    (void (*)())Normal_50000,
};

void (*const normal_05[16])() = {
    (void (*)())nm_05_0000,
    (void (*)())nm_05_0000,
    (void (*)())nm_05_0100,
    (void (*)())nm_05_0000,
    (void (*)())nm_05_0000,
    (void (*)())nm_05_0000,
    (void (*)())nm_05_0000,
    (void (*)())nm_05_0000,
    (void (*)())nm_05_0100,
    (void (*)())nm_05_0000,
    (void (*)())nm_05_0000,
    (void (*)())nm_05_0100,
    (void (*)())nm_05_0100,
    (void (*)())nm_05_0000,
    (void (*)())nm_05_0100,
    (void (*)())nm_05_0100,
};

void (*const normal_06[16])() = {
    (void (*)())nm_06_0100,
    (void (*)())nm_06_0100,
    (void (*)())nm_06_0200,
    (void (*)())nm_06_0000,
    (void (*)())nm_06_0100,
    (void (*)())nm_06_0100,
    (void (*)())nm_06_0100,
    (void (*)())nm_06_0100,
    (void (*)())nm_06_0000,
    (void (*)())nm_06_0100,
    (void (*)())nm_06_0000,
    (void (*)())nm_06_0200,
    (void (*)())nm_06_0200,
    (void (*)())nm_06_0100,
    (void (*)())nm_06_0200,
    (void (*)())nm_06_0200,
};

const u16 jpdat_tbl[9][2] = {
    { 0x11, 6 },
    { 0x12, 7 },
    { 0x13, 8 },
    { 0xE, 9 },
    { 0xF, 0xA },
    { 0x10, 0xB },
    { 0x14, 0xC },
    { 0x15, 0xD },
    { 0x16, 0xE },
};
