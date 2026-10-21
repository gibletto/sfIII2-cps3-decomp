/*
 * PLPAT00_TBL.C  tables read by PLPAT00.c: character 0 (Gill) special attack routines
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 mnd_em_tall[][2];
extern const s16 glap_table[];
extern void (*const pl00_exatt_table[])();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_MOONSALT_KNEE_DROP();
extern void Att_PL00_TOKUSHUKOUDOU();
extern void Att_RESURRECTION();
extern void Att_SENPUUKYAKU();
extern void Att_SLIDE_and_JUMP();

const s16 mnd_em_tall[16][2] = {
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

const s16 glap_table[6] = {
    1, 2, 3, 4, 0, -1,
};

void (*const pl00_exatt_table[15])() = {
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_MOONSALT_KNEE_DROP,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_SENPUUKYAKU,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_RESURRECTION,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL00_TOKUSHUKOUDOU,
};
