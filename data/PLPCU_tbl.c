/*
 * PLPCU_TBL.C  thrown player routine tables
 *
 * plpcu_lv_00 is the list of caught routines Caught_00000 .. Caught_03000, indexed by caught
 * routine number; setup_cu_dm_init_data lists the scdmd_ routines that set up the damage state
 * a thrown player is released into, indexed by routine number minus 12. caught_dm_chg_tbl1 and
 * caught_dm_chg_tbl6 give, by animation number, whether the animation a released player goes
 * on with is replaced, and the first replacement animation, to which the attack level is
 * added. Read by PLPCU.C, the player caught process.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const setup_cu_dm_init_data[])();
extern void (*const plpcu_lv_00[])();
extern const u8 caught_dm_chg_tbl1[][2];
extern const u8 caught_dm_chg_tbl6[][2];
extern void Caught_00000();
extern void Caught_01000();
extern void Caught_02000();
extern void Caught_03000();
extern void scdmd_12000();
extern void scdmd_14000();
extern void scdmd_16000();
extern void scdmd_17000();
extern void scdmd_18000();
extern void scdmd_19000();
extern void scdmd_20000();
extern void scdmd_21000();
extern void scdmd_23000();
extern void scdmd_24000();
extern void scdmd_25000();
extern void scdmd_26000();
extern void scdmd_27000();
extern void scdmd_28000();
extern void scdmd_29000();
extern void scdmd_30000();

void (*const setup_cu_dm_init_data[19])() = {
    scdmd_12000,
    scdmd_12000,
    scdmd_14000,
    scdmd_14000,
    scdmd_16000,
    scdmd_17000,
    scdmd_18000,
    scdmd_19000,
    scdmd_20000,
    scdmd_21000,
    scdmd_21000,
    scdmd_23000,
    scdmd_24000,
    scdmd_25000,
    scdmd_26000,
    scdmd_27000,
    scdmd_28000,
    scdmd_29000,
    scdmd_30000,
};

void (*const plpcu_lv_00[4])() = {
    Caught_00000,
    Caught_01000,
    Caught_02000,
    Caught_03000,
};

const u8 caught_dm_chg_tbl1[97][2] = {
    { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 },
    { 0, 4 }, { 0, 5 }, { 0, 6 }, { 0, 7 },
    { 1, 8 }, { 1, 8 }, { 1, 8 }, { 1, 8 },
    { 1, 0xC }, { 1, 0xC }, { 1, 0xC }, { 1, 0xC },
    { 1, 0x10 }, { 1, 0x10 }, { 1, 0x10 }, { 1, 0x10 },
    { 1, 0x14 }, { 1, 0x14 }, { 1, 0x14 }, { 1, 0x14 },
    { 1, 0x18 }, { 1, 0x18 }, { 1, 0x18 }, { 1, 0x18 },
    { 1, 0x1C }, { 1, 0x1C }, { 1, 0x1C }, { 1, 0x1C },
    { 1, 0x20 }, { 1, 0x20 }, { 1, 0x20 }, { 1, 0x20 },
    { 1, 0x24 }, { 1, 0x24 }, { 1, 0x24 }, { 1, 0x24 },
    { 1, 0x28 }, { 1, 0x28 }, { 1, 0x28 }, { 1, 0x28 },
    { 1, 0x2C }, { 1, 0x2C }, { 1, 0x2C }, { 1, 0x2C },
    { 1, 0x30 }, { 1, 0x30 }, { 1, 0x30 }, { 1, 0x30 },
    { 1, 0x34 }, { 1, 0x34 }, { 1, 0x34 }, { 1, 0x34 },
    { 1, 0x38 }, { 1, 0x38 }, { 1, 0x38 }, { 1, 0x38 },
    { 1, 0x3C }, { 1, 0x3C }, { 1, 0x3C }, { 1, 0x3C },
    { 0, 0x40 }, { 0, 0x41 }, { 0, 0x42 }, { 0, 0x43 },
    { 0, 0x44 }, { 0, 0x45 }, { 0, 0x46 }, { 0, 0x47 },
    { 0, 0x48 }, { 0, 0x49 }, { 1, 0x4A }, { 1, 0x4A },
    { 1, 0x4A }, { 1, 0x4A }, { 1, 0x4E }, { 1, 0x4E },
    { 1, 0x4E }, { 1, 0x4E }, { 1, 0x52 }, { 1, 0x52 },
    { 1, 0x52 }, { 1, 0x52 }, { 1, 0x56 }, { 1, 0x56 },
    { 1, 0x56 }, { 1, 0x56 }, { 0, 0x5A }, { 0, 0x5B },
    { 1, 0x5C }, { 1, 0x5C }, { 1, 0x5C }, { 1, 0x5C },
    { 0, 0x60 },
};

const u8 caught_dm_chg_tbl6[141][2] = {
    { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 },
    { 1, 4 }, { 1, 4 }, { 1, 4 }, { 1, 4 },
    { 1, 8 }, { 1, 8 }, { 1, 8 }, { 1, 8 },
    { 1, 0xC }, { 1, 0xC }, { 1, 0xC }, { 1, 0xC },
    { 1, 0x10 }, { 1, 0x10 }, { 1, 0x10 }, { 1, 0x10 },
    { 1, 0x14 }, { 1, 0x14 }, { 1, 0x14 }, { 1, 0x14 },
    { 1, 0x18 }, { 1, 0x18 }, { 1, 0x18 }, { 1, 0x18 },
    { 1, 0x1C }, { 1, 0x1C }, { 1, 0x1C }, { 1, 0x1C },
    { 1, 0x20 }, { 1, 0x20 }, { 1, 0x20 }, { 1, 0x20 },
    { 1, 0x24 }, { 1, 0x24 }, { 1, 0x24 }, { 1, 0x24 },
    { 1, 0x28 }, { 1, 0x28 }, { 1, 0x28 }, { 1, 0x28 },
    { 1, 0x2C }, { 1, 0x2C }, { 1, 0x2C }, { 1, 0x2C },
    { 1, 0x30 }, { 1, 0x30 }, { 1, 0x30 }, { 1, 0x30 },
    { 1, 0x34 }, { 1, 0x34 }, { 1, 0x34 }, { 1, 0x34 },
    { 1, 0x38 }, { 1, 0x38 }, { 1, 0x38 }, { 1, 0x38 },
    { 1, 0x3C }, { 1, 0x3C }, { 1, 0x3C }, { 1, 0x3C },
    { 1, 0x40 }, { 1, 0x40 }, { 1, 0x40 }, { 1, 0x40 },
    { 1, 0x44 }, { 1, 0x44 }, { 1, 0x44 }, { 1, 0x44 },
    { 1, 0x48 }, { 1, 0x48 }, { 1, 0x48 }, { 1, 0x48 },
    { 1, 0x4C }, { 1, 0x4C }, { 1, 0x4C }, { 1, 0x4C },
    { 1, 0x50 }, { 1, 0x50 }, { 1, 0x50 }, { 1, 0x50 },
    { 1, 0x54 }, { 1, 0x54 }, { 1, 0x54 }, { 1, 0x54 },
    { 1, 0x58 }, { 1, 0x58 }, { 1, 0x58 }, { 1, 0x58 },
    { 1, 0x5C }, { 1, 0x5C }, { 1, 0x5C }, { 1, 0x5C },
    { 1, 0x60 }, { 1, 0x60 }, { 1, 0x60 }, { 1, 0x60 },
    { 1, 0x64 }, { 1, 0x64 }, { 1, 0x64 }, { 1, 0x64 },
    { 1, 0x68 }, { 1, 0x68 }, { 1, 0x68 }, { 1, 0x68 },
    { 1, 0x6C }, { 1, 0x6C }, { 1, 0x6C }, { 1, 0x6C },
    { 1, 0x70 }, { 1, 0x70 }, { 1, 0x70 }, { 1, 0x70 },
    { 1, 0x74 }, { 1, 0x74 }, { 1, 0x74 }, { 1, 0x74 },
    { 1, 0x78 }, { 1, 0x78 }, { 1, 0x78 }, { 1, 0x78 },
    { 1, 0x7C }, { 1, 0x7C }, { 1, 0x7C }, { 1, 0x7C },
    { 1, 0x80 }, { 1, 0x80 }, { 1, 0x80 }, { 1, 0x80 },
    { 1, 0x84 }, { 1, 0x84 }, { 1, 0x84 }, { 1, 0x84 },
    { 1, 0x88 }, { 1, 0x88 }, { 1, 0x88 }, { 1, 0x88 },
    { 0xFF, 0xFF },
};
