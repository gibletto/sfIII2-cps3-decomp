/*
 * PLPAT04_TBL.C  Dudley, Necro and Hugo special attack tables
 *
 * pl04_exatt_table, pl05_exatt_table and pl06_exatt_table are the special attack routines of
 * characters 4 (Dudley), 5 (Necro) and 6 (Hugo), indexed by attack routine number minus 16.
 * Read by PLPAT04.C, PLPAT05.C and PLPAT06.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const pl04_exatt_table[])();
extern void (*const pl05_exatt_table[])();
extern void (*const pl06_exatt_table[])();
extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_HADOUKEN2();
extern void Att_HOMING_JUMP();
extern void Att_JINNCHUUWATARI();
extern void Att_NM_OKIAGARI();
extern void Att_PL04_TOKUSHUKOUDOU();
extern void Att_PL05_TOKUSHUKOUDOU();
extern void Att_PL06_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUKEN();
extern void Att_SHOURYUUREPPA();
extern void Att_SLIDE_and_JUMP();
extern void Att_TENSHINSENKYUUTAI();

void (*const pl04_exatt_table[15])() = {
    Att_SENPUUKYAKU,
    Att_SENPUUKYAKU,
    Att_HADOUKEN,
    Att_SHOURYUUREPPA,
    Att_HADOUKEN2,
    Att_CHOUCHUURENGEKI,
    Att_CHOUCHUURENGEKI,
    Att_SLIDE_and_JUMP,
    Att_SLIDE_and_JUMP,
    Att_HADOUKEN,
    Att_NM_OKIAGARI,
    Att_DUMMY,
    Att_HOMING_JUMP,
    Att_DUMMY,
    Att_PL04_TOKUSHUKOUDOU,
};

void (*const pl05_exatt_table[15])() = {
    Att_CHOUCHUURENGEKI,
    Att_HADOUKEN,
    Att_HADOUKEN,
    Att_HADOUKEN,
    Att_HADOUKEN,
    Att_SENPUUKYAKU,
    Att_HADOUKEN,
    Att_HADOUKEN,
    Att_HADOUKEN,
    Att_JINNCHUUWATARI,
    Att_SLIDE_and_JUMP,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL05_TOKUSHUKOUDOU,
};

void (*const pl06_exatt_table[15])() = {
    Att_HADOUKEN2,
    Att_HADOUKEN2,
    Att_CHOUCHUURENGEKI,
    Att_HADOUKEN2,
    Att_SHOURYUUKEN,
    Att_SLIDE_and_JUMP,
    Att_HADOUKEN2,
    Att_SHOURYUUKEN,
    Att_DUMMY,
    Att_TENSHINSENKYUUTAI,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL06_TOKUSHUKOUDOU,
};
