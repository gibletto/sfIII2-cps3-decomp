/*
 * PLPAT02.C  Player 02 (Ryu) special attack routines
 *
 * Character-specific attack routines for player number 2. pl02_extra_attack dispatches attack
 * routine numbers 16 and up through pl02_exatt_table.
 * Att_DENJINHADOUKEN runs the charged fireball super: while the charge animation is held it
 * skips extra animation frames according to the charge count (cp->lgp, lgix_table).
 * Att_PL02_TOKUSHUKOUDOU is the personal action: super gauge on cg_type 40 and, up to three
 * times, a 10% increase of the stun recovery rate (py->recover) on cg_type 64.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Grade.h"
#include "PLPAT.h"
#include "PLPAT02.h"

/* routine_no[3], Att_DENJINHADOUKEN */
#define DENJINHADOUKEN_RUN 1    /* run the animation */

/* routine_no[3], Att_PL02_TOKUSHUKOUDOU */
#define TOKUSHUKOUDOU_ACTION 1  /* the personal action, filling the super art gauge */


void pl02_extra_attack(PLW* wk) {
    pl02_exatt_table[wk->wu.routine_no[2] - ATTACK_SPECIAL](wk);
}



void Att_DENJINHADOUKEN(PLW* wk) {
    s16 i;
    s16 lgix;
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 5, wk->as->char_ix);
        break;
    case DENJINHADOUKEN_RUN:
        char_move((WORK*)wk);
        if (wk->wu.now_koc == 8 && wk->wu.char_index == 13) {
            if (wk->cp->lgp > 13) {
                lgix = 5;
            } else {
                lgix = lgix_table[wk->cp->lgp / 2];
            }
            if (lgix) {
                for (i = 0; i < lgix; i++) {
                    char_move((WORK*)wk);
                }
            }
        }
        break;
    }
}



void Att_PL02_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case TOKUSHUKOUDOU_ACTION:
        char_move(&wk->wu);
        if ((u8)wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }
        if ((u8)wk->wu.cg_type == 64) {
            wk->wu.routine_no[3]++;
            if (wk->tk_success > 2) {
            } else {
                wk->tk_success++;
                wk->py->recover = wk->py->recover * 110 / 100;
                return;
            }
        }
        break;
    default:
        char_move(&wk->wu);
        return;
    }
}
