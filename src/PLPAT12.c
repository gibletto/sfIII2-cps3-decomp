/*
 * PLPAT12.C  Player 12 (Sean) special attack routines
 *
 * Character-specific attack routines for player number 12, dispatched by pl12_extra_attack
 * through pl12_exatt_table.
 * Att_PL12_TOKUSHUKOUDOU is the personal action: it throws the ball effect (effect_D7_init),
 * jumps through mvxy data, adds super gauge when the effect signals and raises the stun power
 * boost (capped 12) on cg_type 30.
 * Att_PL12_BONUS_STAGE is the character's special action on the bonus stage: an animation that
 * launches a jump on cg_type 20 and follows the effect's signal while airborne.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "effd6_code.h"
#include "EFFD7.h"
#include "Grade.h"
#include "PLPAT.h"
#include "PLS01.h"
#include "PLS02.h"
#include "PLPAT12.h"


void pl12_extra_attack(PLW* wk) {
    pl12_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_PL12_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->wu.mvxy.index = wk->as->data_ix;
        wk->wu.cmwk[6] = 0;
        wk->wu.cmwk[7] = 0;
        wk->tk_success++;
        if (effect_D7_init(wk)) {
            set_char_move_init(&wk->wu, 5, wk->as->char_ix + 1);
        } else {
            set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        }
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }
        break;
    case 2:
        if (wk->wu.cmwk[7] != 0) {
            char_move_cmj4(&wk->wu);
            wk->wu.cmwk[7] = 0;
            wk->wu.mvxy.index++;
            add_sp_arts_gauge_tokushu(wk);
        }
        jumping_union_process(&wk->wu, 3);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
        }
        if (wk->wu.cg_type == 30) {
            wk->wu.cg_type = 0;
            wk->tk_kizetsu += 4;
            if (wk->tk_kizetsu > 12) {
                wk->tk_kizetsu = 12;
            }
        }
        break;
    case 3:
        char_move(&wk->wu);
        break;
    }
}



void Att_PL12_BONUS_STAGE(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->wu.mvxy.index = wk->as->data_ix;
        wk->wu.cmwk[6] = 0;
        wk->wu.cmwk[7] = 0;
        set_char_move_init((WORK*)wk, 5, wk->wu.char_index);
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
        }
        break;
    case 2:
        if (wk->wu.cmwk[7] != 0) {
            char_move_cmj4((WORK*)wk);
            wk->wu.cmwk[7] = 0;
        }
        jumping_union_process((WORK*)wk, 3);
        break;
    case 3:
        char_move((WORK*)wk);
        break;
    }
}
