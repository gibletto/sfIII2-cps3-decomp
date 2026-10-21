/*
 * PLPNM.C  Player normal (free movement) process
 *
 * Player_normal runs a player who is not attacking, damaged or throwing: standing, walking,
 * crouching, jumping, dashing, turning and the like. It clears the per-frame guard, throw, parry
 * and cancel flags itself (2i has no setup_normal_process_flags), the combo power counters are
 * checked, a parry state (31 - 35) entered while dm_fushin is set becomes its routine 42 - 46
 * counterpart, and the routine for routine_no[2] is dispatched through the normal routine table;
 * the draw priority is then set relative to the opponent when the animation asks for it.
 * Normal_00000 is the entry routine that runs appear_player for the round introduction;
 * Normal_01000 is the standing routine (pcon_dp_flag holds it in pose 9/60); Normal_02000, the
 * first of 3s PLNORMAL.C, is part of this module in 2i (one literal pool with Normal_01000).
 * Called from the player main routine (PLMAIN/PLMAIN2).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS01.h"
#include "appear.h"
#include "PLPNM.h"
#include "CHARMOVE.h"
#include "charmove_2.h"



/* 2i 0600EA40, 3s-near: sf3 src/PLPNM.c:26 Player_normal */
void Player_normal(wk)
PLW* wk;
{
    wk->wu.next_z = wk->wu.my_priority;
    wk->running_f = 0;
    wk->py->flag = 0;
    wk->guard_flag = 0;
    wk->guard_chuu = 0;
    wk->tsukami_f = 0;
    wk->tsukamare_f = 0;
    wk->scr_pos_set_flag = 1;
    wk->dm_hos_flag = 0;
    wk->ukemi_success = 0;
    wk->zuru_timer = 0;
    wk->zuru_ix_counter = 0;
    wk->sa_stop_flag = 0;
    wk->atemi_flag = 0;
    wk->caution_flag = 0;
    wk->sa->saeff_ok = 0;
    wk->sa->saeff_mp = 0;
    wk->ukemi_success = 0;
    wk->ukemi_ok_timer = 0;
    wk->uot_cd_ok_flag = 0;
    wk->cancel_timer = 0;
    wk->hazusenai_flag = 0;
    wk->cat_break_reserve = 0;
    wk->cmd_request = 0;
    check_my_tk_power_off(wk, (PLW*)wk->wu.target_adrs);
    check_em_tk_power_off(wk, (PLW*)wk->wu.target_adrs);
    if (wk->wu.routine_no[3] == 0 && (u32)(wk->wu.routine_no[2] - 31) < 5 && wk->wu.dm_fushin) {
        wk->wu.routine_no[2] = wk->wu.routine_no[2] + 11;
    }
    plpnm_lv_00[wk->wu.routine_no[2]](wk);
    if (wk->wu.cg_prio) {
        wk->wu.next_z = ((WORK*)wk->wu.target_adrs)->my_priority;
        if (wk->wu.cg_prio == 1) {
            wk->wu.next_z++;
        } else {
            wk->wu.next_z -= 3;
        }
    }
}



/* 2i 0600EB2E, 3s-reloc: sf3 src/PLPNM.c:78 Normal_00000 */
void Normal_00000(PLW* wk) {
    appear_player(wk);
}


/* 2i 0600EB34, 3s-near: sf3 src/PLPNM.c:83 Normal_01000 */
void Normal_01000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        if (pcon_dp_flag) {
            if (wk->wu.now_koc == 0 && wk->wu.char_index == 0) {
                exset_char_move_init((WORK*)wk, 9, 60);
            } else {
                set_char_move_init((WORK*)wk, 0, 0);
            }
        } else {
            set_char_move_init((WORK*)wk, 0, 0);
            wk->scr_pos_set_flag = 0;
        }
    case 1:
        if (pcon_dp_flag) {
            if (wk->wu.now_koc != 9 || wk->wu.char_index != 60) {
                exset_char_move_init((WORK*)wk, 9, 60);
            }
        } else if (wk->wu.now_koc == 9 && wk->wu.char_index == 60) {
            exset_char_move_init((WORK*)wk, 0, 0);
            wk->scr_pos_set_flag = 0;
        }
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600EC24, 3s-near: sf3 src/PLNORMAL.c:28 Normal_02000 */
void Normal_02000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 1);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}
