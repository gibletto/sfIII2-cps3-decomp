/*
 * PLPAT13_TBL.C  tables read by PLPAT13.c: player 13 (Urien) special attack routines
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 mnd_em_tall2[][2];
extern const s16 glap_table2[];
extern void (*const pl13_exatt_table[])();
extern void Att_ABISEGERI();
extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_MOONSALT_KNEE_DROP2();
extern void Att_PL13_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SLIDE_and_JUMP();

const s16 mnd_em_tall2[16][2] = {
    { 28, 56 },
    { 24, 44 },
    { 24, 40 },
    { 20, 32 },
    { 24, 48 },
    { 24, 40 },
    { 28, 60 },
    { 16, 44 },
    { 32, 32 },
    { 28, 24 },
    { 20, 32 },
    { 24, 40 },
    { 24, 40 },
    { 28, 56 },
    { 24, 40 },
    { 24, 40 },
};

const s16 glap_table2[6] = {
    1, 2, 3, 4, 0, -1,
};

void (*const pl13_exatt_table[15])() = {
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_MOONSALT_KNEE_DROP2,
    (void (*)())Att_ABISEGERI,
    (void (*)())Att_SENPUUKYAKU,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL13_TOKUSHUKOUDOU,
};
