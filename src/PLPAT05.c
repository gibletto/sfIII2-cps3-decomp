/*
 * PLPAT05.C  Player 05 (Necro) special attack routines
 *
 * Character-specific attack routines for player number 5. pl05_extra_attack dispatches attack
 * routine numbers 16 and up through pl05_exatt_table.
 * Att_PL05_TOKUSHUKOUDOU is the personal action: super gauge on cg_type 40 and a strike power
 * boost of 10 (capped 10) on cg_type 20.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLPAT.h"
#include "PLPAT05.h"

/* routine_no[3], Att_PL05_TOKUSHUKOUDOU */
#define TOKUSHUKOUDOU_ACTION 1  /* the personal action, filling the super art gauge */



void pl05_extra_attack(PLW* wk) {
    pl05_exatt_table[wk->wu.routine_no[2] - ATTACK_SPECIAL](wk);
}



void Att_PL05_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 5, wk->as->char_ix);
        break;
    case TOKUSHUKOUDOU_ACTION:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }
        if (wk->wu.cg_type == 20) {
            wk->wu.cg_type = 0;
            wk->tk_dageki += 10;
            if (wk->tk_dageki > 10) {
                wk->tk_dageki = 10;
            }
        }
        break;
    }
}
