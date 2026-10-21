/*
 * PLPAT01.C  Player 01 (Alex) special attack routines
 *
 * Character-specific attack routines for player number 1. pl01_extra_attack dispatches attack
 * routine numbers 16 and up through pl01_exatt_table.
 * Att_PL01_TOKUSHUKOUDOU is the personal action (taunt): super gauge on cg_type 40, and strike
 * and throw power boosts (tk_dageki/tk_nage, capped 12/16) on cg_type 20/30.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLSGAUGE.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Grade.h"
#include "PLPAT.h"
#include "PLS01.h"
#include "PLS02.h"
#include "PLPAT01.h"



void pl01_extra_attack(PLW* wk) {
    pl01_exatt_table[wk->wu.routine_no[2] - 16](wk);
}




void Att_PL01_TOKUSHUKOUDOU(PLW* wk) {
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
        switch (wk->wu.cg_type) {
        case 20:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 3;
            wk->tk_nage += 2;
            break;
        case 30:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 2;
            wk->tk_nage += 2;
        default:
            break;
        }
        if (wk->tk_dageki > 12) {
            wk->tk_dageki = 12;
        }
        if (wk->tk_nage > 16) {
            wk->tk_nage = 16;
        }
        break;
    }
}
