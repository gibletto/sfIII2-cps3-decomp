/*
 * PLPAT14_TBL.C  tables read by plpat14.c and plpat15.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const pl14_exatt_table[])();
extern void (*const pl15_exatt_table[])();
extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_KUUCHUUJINNCHUUWATARI();
extern void Att_KUUCHUUNICHIRINSHOU();
extern void Att_PL14_AT1();
extern void Att_PL14_AT2();
extern void Att_PL14_TOKUSHUKOUDOU();
extern void Att_PL15_AT1();
extern void Att_PL15_AT2();
extern void Att_PL15_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUKEN();
extern void Att_SHOURYUUREPPA();
extern void Att_SLIDE_and_JUMP();

void (*const pl14_exatt_table[15])() = {
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_SHOURYUUKEN,
    (void (*)())Att_SENPUUKYAKU,
    (void (*)())Att_KUUCHUUJINNCHUUWATARI,
    (void (*)())Att_SHOURYUUREPPA,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_KUUCHUUNICHIRINSHOU,
    (void (*)())Att_PL14_AT1,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_PL14_AT2,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL14_TOKUSHUKOUDOU,
};

/* provisional name */
void (*const pl15_exatt_table[15])() = {
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_SHOURYUUKEN,
    (void (*)())Att_SENPUUKYAKU,
    (void (*)())Att_KUUCHUUJINNCHUUWATARI,
    (void (*)())Att_SHOURYUUREPPA,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_KUUCHUUNICHIRINSHOU,
    (void (*)())Att_PL15_AT1,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_PL15_AT2,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL15_TOKUSHUKOUDOU,
};
