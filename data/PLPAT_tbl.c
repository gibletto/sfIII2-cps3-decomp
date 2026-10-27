/*
 * PLPAT_TBL.C  player attack dispatch tables
 *
 * plpat_lv_00 is the common attack routines Attack_00000 .. Attack_10000, indexed by attack
 * routine number (the last five entries repeat Attack_00000). plxx_extra_attack_table is each
 * character's special attack dispatcher (pl00_extra_attack .. pl15_extra_attack, by player
 * number). Read by PLPAT.C. ahj_empos_hos gives, per leaping move and per opponent character,
 * the target-relative x/y point the jump aims at; read by PLPATUNI.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const plpat_lv_00[])();
extern void (*const plxx_extra_attack_table[])();
extern const s16 ahj_empos_hos[][16][2];
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
    Attack_00000,
    Attack_01000,
    Attack_02000,
    Attack_03000,
    Attack_04000,
    Attack_05000,
    Attack_06000,
    Attack_07000,
    Attack_08000,
    Attack_09000,
    Attack_10000,
    Attack_00000,
    Attack_00000,
    Attack_00000,
    Attack_00000,
    Attack_00000,
};

void (*const plxx_extra_attack_table[16])() = {
    pl00_extra_attack,
    pl01_extra_attack,
    pl02_extra_attack,
    pl03_extra_attack,
    pl04_extra_attack,
    pl05_extra_attack,
    pl06_extra_attack,
    pl07_extra_attack,
    pl08_extra_attack,
    pl09_extra_attack,
    pl10_extra_attack,
    pl11_extra_attack,
    pl12_extra_attack,
    pl13_extra_attack,
    pl14_extra_attack,
    pl15_extra_attack,
};

const s16 ahj_empos_hos[5][16][2] = {
    { { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 }, { 16, 192 } },
    { { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 }, { 27, -8 } },
    { { 48, 56 }, { 48, 48 }, { 40, 32 }, { 40, 28 }, { 24, 44 }, { 40, 40 }, { 52, 64 }, { 48, 32 }, { 44, 32 }, { 44, 28 }, { 40, 28 }, { 40, 32 }, { 40, 32 }, { 48, 56 }, { 40, 32 }, { 40, 32 } },
    { { 48, 32 }, { 48, 24 }, { 40, 8 }, { 40, 4 }, { 24, 20 }, { 40, 16 }, { 64, 44 }, { 48, 8 }, { 44, 8 }, { 44, 4 }, { 40, 4 }, { 40, 8 }, { 40, 8 }, { 48, 32 }, { 40, 8 }, { 40, 8 } },
    { { 24, 86 }, { 28, 68 }, { 16, 62 }, { 16, 52 }, { 20, 72 }, { 20, 58 }, { 18, 82 }, { 18, 52 }, { 28, 45 }, { 25, 42 }, { 16, 52 }, { 16, 62 }, { 16, 62 }, { 24, 86 }, { 16, 62 }, { 16, 62 } },
};
