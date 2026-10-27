/*
 * PLCNT3_TBL.C  player control phases for the bonus stage
 *
 * player_bonus_process is the three phases (plcnt_b_init, plcnt_b_move, plcnt_b_die) of player
 * control in the bonus stage. Read by PLCNT2.C, the player control for the bonus stage.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const player_bonus_process[])();
extern void plcnt_b_die();
extern void plcnt_b_init();
extern void plcnt_b_move();

void (*const player_bonus_process[3])() = {
    plcnt_b_init,
    plcnt_b_move,
    plcnt_b_die,
};
