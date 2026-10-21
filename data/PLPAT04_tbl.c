/*
 * PLPAT04_TBL.C  tables read by PLPAT04.c, PLPAT05.c and PLPAT06.c
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
    (void (*)())Att_SENPUUKYAKU,
    (void (*)())Att_SENPUUKYAKU,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_SHOURYUUREPPA,
    (void (*)())Att_HADOUKEN2,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_NM_OKIAGARI,
    (void (*)())Att_DUMMY,
    (void (*)())Att_HOMING_JUMP,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL04_TOKUSHUKOUDOU,
};

void (*const pl05_exatt_table[15])() = {
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_SENPUUKYAKU,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_JINNCHUUWATARI,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL05_TOKUSHUKOUDOU,
};

void (*const pl06_exatt_table[15])() = {
    (void (*)())Att_HADOUKEN2,
    (void (*)())Att_HADOUKEN2,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_HADOUKEN2,
    (void (*)())Att_SHOURYUUKEN,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_HADOUKEN2,
    (void (*)())Att_SHOURYUUKEN,
    (void (*)())Att_DUMMY,
    (void (*)())Att_TENSHINSENKYUUTAI,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL06_TOKUSHUKOUDOU,
};
