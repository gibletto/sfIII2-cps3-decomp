/*
 * PLPAT_TBL.C  tables read by PLPAT.c and PLPATUNI.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const plpat_lv_00[])();
extern void (*const plxx_extra_attack_table[])();
extern const s16 ahj_empos_hos[][24][2];
extern const u16 PLPAT_tbl_06102100[];
extern const s16 PLPAT_tbl_06102140[][24][2];
extern const u16 PLPAT_tbl_061021A0[];
extern void Attack_00000();
extern void Attack_01000();
extern void Attack_02000();
extern void Attack_03000();
extern void Attack_04000();
extern void Attack_05000();
extern void Attack_06000();
extern void Attack_07000();
extern void Attack_08000();
extern void Attack_09000();
extern void Attack_10000();
extern void pl00_extra_attack();
extern void pl01_extra_attack();
extern void pl02_extra_attack();
extern void pl03_extra_attack();
extern void pl04_extra_attack();
extern void pl05_extra_attack();
extern void pl06_extra_attack();
extern void pl07_extra_attack();
extern void pl08_extra_attack();
extern void pl09_extra_attack();
extern void pl10_extra_attack();
extern void pl11_extra_attack();
extern void pl12_extra_attack();
extern void pl13_extra_attack();
extern void pl14_extra_attack();
extern void pl15_extra_attack();

void (*const plpat_lv_00[16])() = {
    (void (*)())Attack_00000,
    (void (*)())Attack_01000,
    (void (*)())Attack_02000,
    (void (*)())Attack_03000,
    (void (*)())Attack_04000,
    (void (*)())Attack_05000,
    (void (*)())Attack_06000,
    (void (*)())Attack_07000,
    (void (*)())Attack_08000,
    (void (*)())Attack_09000,
    (void (*)())Attack_10000,
    (void (*)())Attack_00000,
    (void (*)())Attack_00000,
    (void (*)())Attack_00000,
    (void (*)())Attack_00000,
    (void (*)())Attack_00000,
};

void (*const plxx_extra_attack_table[16])() = {
    (void (*)())pl00_extra_attack,
    (void (*)())pl01_extra_attack,
    (void (*)())pl02_extra_attack,
    (void (*)())pl03_extra_attack,
    (void (*)())pl04_extra_attack,
    (void (*)())pl05_extra_attack,
    (void (*)())pl06_extra_attack,
    (void (*)())pl07_extra_attack,
    (void (*)())pl08_extra_attack,
    (void (*)())pl09_extra_attack,
    (void (*)())pl10_extra_attack,
    (void (*)())pl11_extra_attack,
    (void (*)())pl12_extra_attack,
    (void (*)())pl13_extra_attack,
    (void (*)())pl14_extra_attack,
    (void (*)())pl15_extra_attack,
};

const s16 ahj_empos_hos[1][24][2] = {
    { { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 } },
};

/* provisional name */
const u16 PLPAT_tbl_06102100[32] = {
    0x1B, 0xFFF8, 0x1B, 0xFFF8, 0x1B, 0xFFF8, 0x1B, 0xFFF8,
    0x1B, 0xFFF8, 0x1B, 0xFFF8, 0x1B, 0xFFF8, 0x1B, 0xFFF8,
    0x30, 0x38, 0x30, 0x30, 0x28, 0x20, 0x28, 0x1C,
    0x18, 0x2C, 0x28, 0x28, 0x34, 0x40, 0x30, 0x20,
};

/* provisional name */
const s16 PLPAT_tbl_06102140[1][24][2] = {
    { { 44, 32 }, { 44, 28 }, { 40, 28 }, { 40, 32 }, { 40, 32 }, { 48, 56 }, { 40, 32 }, { 40, 32 }, { 48, 32 }, { 48, 24 }, { 40, 8 }, { 40, 4 }, { 24, 20 }, { 40, 16 }, { 64, 44 }, { 48, 8 }, { 44, 8 }, { 44, 4 }, { 40, 4 }, { 40, 8 }, { 40, 8 }, { 48, 32 }, { 40, 8 }, { 40, 8 } },
};

/* provisional name */
const u16 PLPAT_tbl_061021A0[32] = {
    0x18, 0x56, 0x1C, 0x44, 0x10, 0x3E, 0x10, 0x34,
    0x14, 0x48, 0x14, 0x3A, 0x12, 0x52, 0x12, 0x34,
    0x1C, 0x2D, 0x19, 0x2A, 0x10, 0x34, 0x10, 0x3E,
    0x10, 0x3E, 0x18, 0x56, 0x10, 0x3E, 0x10, 0x3E,
};
