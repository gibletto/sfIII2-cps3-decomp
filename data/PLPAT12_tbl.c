/*
 * PLPAT12_TBL.C  tables read by PLPAT12.c: player 12 (Sean) special attack routines
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const pl12_exatt_table[])();
extern void Att_ABISEGERI();
extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_HOMING_JUMP();
extern void Att_KUUCHUUNICHIRINSHOU();
extern void Att_PL12_BONUS_STAGE();
extern void Att_PL12_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUKEN();
extern void Att_SHOURYUUREPPA();
extern void Att_SLIDE_and_JUMP();

void (*const pl12_exatt_table[16])() = {
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_SHOURYUUREPPA,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_ABISEGERI,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_SHOURYUUKEN,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_KUUCHUUNICHIRINSHOU,
    (void (*)())Att_SENPUUKYAKU,
    (void (*)())Att_HOMING_JUMP,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL12_TOKUSHUKOUDOU,
    (void (*)())Att_PL12_BONUS_STAGE,
};
