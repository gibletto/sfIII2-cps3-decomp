/*
 * PLPAT03.C  Player 03 (Yun) special attack routines
 *
 * Character-specific attack routines for player number 3. pl03_extra_attack dispatches attack
 * routine numbers 16 and up through pl03_exatt_table.
 * Att_PL03_TOKUSHUKOUDOU is the personal action: it lands the player, adds super gauge on
 * cg_type 40 and raises the strike and throw power boosts on cg_type 20/30 (capped 16/8).
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
#include "PLPAT03.h"

/* routine_no[3], Att_PL03_TOKUSHUKOUDOU */
#define TOKUSHUKOUDOU_ACTION 1  /* the personal action, filling the super art gauge */


void pl03_extra_attack(PLW* wk) {
    pl03_exatt_table[wk->wu.routine_no[2] - ATTACK_SPECIAL](wk);
}



void Att_PL03_TOKUSHUKOUDOU(PLW* wk) {
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
        switch (wk->wu.cg_type) {
        case 20:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 2;
            wk->tk_nage += 2;
            break;
        case 30:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 2;
            wk->tk_nage++;
        default:
            break;
        }
        if (wk->tk_dageki > 16) {
            wk->tk_dageki = 16;
        }
        if (wk->tk_nage > 8) {
            wk->tk_nage = 8;
        }
        break;
    }
}
