/*
 * PLPAT01_TBL.C  tables read by PLPAT01.c, PLPAT02.c and PLPAT03.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const pl01_exatt_table[])();
extern const s16 lgix_table[];
extern void (*const pl02_exatt_table[])();
extern void (*const pl03_exatt_table[])();
extern void Att_CHOUCHUURENGEKI();
extern void Att_DENJINHADOUKEN();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_HADOUKEN2();
extern void Att_HOMING_JUMP();
extern void Att_KUUCHUUNICHIRINSHOU();
extern void Att_NM_OKIAGARI();
extern void Att_PL01_TOKUSHUKOUDOU();
extern void Att_PL02_TOKUSHUKOUDOU();
extern void Att_PL03_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SENPUUKYAKU2();
extern void Att_SHINSHOURYUUKEN();
extern void Att_SHOURYUUKEN();
extern void Att_SLIDE_and_JUMP();
extern void Att_TENSHINSENKYUUTAI();

void (*const pl01_exatt_table[15])() = {
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_SHOURYUUKEN,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_HADOUKEN2,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_SENPUUKYAKU2,
    (void (*)())Att_SENPUUKYAKU,
    (void (*)())Att_NM_OKIAGARI,
    (void (*)())Att_DUMMY,
    (void (*)())Att_HOMING_JUMP,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL01_TOKUSHUKOUDOU,
};

const s16 lgix_table[8] = {
    0, 1, 2, 3, 3, 4, 4, 5,
};

void (*const pl02_exatt_table[15])() = {
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_SHOURYUUKEN,
    (void (*)())Att_SENPUUKYAKU,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_SHINSHOURYUUKEN,
    (void (*)())Att_DENJINHADOUKEN,
    (void (*)())Att_KUUCHUUNICHIRINSHOU,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL02_TOKUSHUKOUDOU,
};

void (*const pl03_exatt_table[15])() = {
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_TENSHINSENKYUUTAI,
    (void (*)())Att_SENPUUKYAKU,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_DUMMY,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL03_TOKUSHUKOUDOU,
};
