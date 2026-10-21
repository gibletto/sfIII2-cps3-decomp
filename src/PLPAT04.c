/*
 * PLPAT04.C  Player 04 (Dudley) special attack routines
 *
 * Character-specific attack routines for player number 4. pl04_extra_attack dispatches attack
 * routine numbers 16 and up through pl04_exatt_table.
 * Att_PL04_TOKUSHUKOUDOU is the personal action: super gauge on cg_type 40 and a strike power
 * boost of 8 (capped 8) on cg_type 20.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLPAT.h"
#include "PLPAT04.h"



void pl04_extra_attack(PLW* wk) {
    pl04_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_PL04_TOKUSHUKOUDOU(PLW* wk) {
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
            wk->tk_dageki += 8;
        }
        if (wk->tk_dageki > 8) {
            wk->tk_dageki = 8;
        }
        break;
    }
}
