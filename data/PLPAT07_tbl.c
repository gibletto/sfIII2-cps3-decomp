/*
 * PLPAT07_TBL.C  tables read by PLPAT07.c: player 07 (Ibuki) special attack routines
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const pl07_exatt_table[])();
extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HOMING_JUMP();
extern void Att_PL07_AT1();
extern void Att_PL07_AT2();
extern void Att_PL07_AT3();
extern void Att_PL07_SA2();
extern void Att_PL07_SA3();
extern void Att_PL07_TOKUSHUKOUDOU();
extern void Att_SHOURYUUKEN();

void (*const pl07_exatt_table[15])() = {
    (void (*)())Att_SHOURYUUKEN,
    (void (*)())Att_PL07_AT1,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_PL07_SA2,
    (void (*)())Att_PL07_AT2,
    (void (*)())Att_PL07_AT3,
    (void (*)())Att_PL07_SA3,
    (void (*)())Att_DUMMY,
    (void (*)())Att_HOMING_JUMP,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL07_TOKUSHUKOUDOU,
};
