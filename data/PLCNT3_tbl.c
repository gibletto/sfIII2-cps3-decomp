/*
 * PLCNT3_TBL.C  tables read by PLCNT2.c: player control for the bonus stage
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const player_bonus_process[])();
extern void plcnt_b_die();
extern void plcnt_b_init();
extern void plcnt_b_move();

void (*const player_bonus_process[3])() = {
    (void (*)())plcnt_b_init,
    (void (*)())plcnt_b_move,
    (void (*)())plcnt_b_die,
};
