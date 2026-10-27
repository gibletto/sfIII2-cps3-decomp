/*
 * PLPAT07_TBL.C  Ibuki's special attack table
 *
 * pl07_exatt_table is the list of Ibuki's special attack routines, indexed by attack routine
 * number minus 16. Read by PLPAT07.C, which dispatches through it from pl07_extra_attack.
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
    Att_SHOURYUUKEN,
    Att_PL07_AT1,
    Att_CHOUCHUURENGEKI,
    Att_CHOUCHUURENGEKI,
    Att_CHOUCHUURENGEKI,
    Att_PL07_SA2,
    Att_PL07_AT2,
    Att_PL07_AT3,
    Att_PL07_SA3,
    Att_DUMMY,
    Att_HOMING_JUMP,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL07_TOKUSHUKOUDOU,
};
