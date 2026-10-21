/*
 * plpat10.c  Character 10 (Yang) special attack routines
 *
 * The entry routine pl10_extra_attack runs the routine for attack numbers 16 and up
 * (routine_no[2]) through pl10_exatt_table; each routine is a small state machine on
 * routine_no[3] that starts the animation and then follows its cg_type markers to apply motion
 * data, effects and gauge changes.
 * This character has only one: Att_PL10_TOKUSHUKOUDOU, the personal action (taunt). Its animation
 * markers add to the super art gauge and raise the personal-action strike and throw bonuses
 * (tk_dageki, tk_nage, capped at 10 and 2).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLPAT.h"
#include "plpat10.h"



void pl10_extra_attack(PLW* wk) {
    pl10_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_PL10_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }
        if (wk->wu.cg_type == 20) {
            wk->wu.cg_type = 0;
            wk->tk_dageki += 10;
            wk->tk_nage += 2;
        }
        if (wk->tk_dageki > 10) {
            wk->tk_dageki = 10;
        }
        if (wk->tk_nage > 2) {
            wk->tk_nage = 2;
        }
        break;
    }
}

