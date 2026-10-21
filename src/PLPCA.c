/*
 * PLPCA.C  Player catch (throwing) process
 *
 * Runs a player who is throwing the opponent. Player_catch resets the per-frame state flags,
 * marks the player as holding (tsukami_f), dispatches the catch routine by routine_no[2] and
 * then checks for a throw escape with check_nagenuke, sending both players to the throw-break
 * routines when the victim inputs a tech inside the thrower's cat_break_ok_timer window.
 * Catch_00000 to Catch_08000 are the kinds of throw: each plays the throw animation, moves by
 * mvxy data and reacts to cg_type marks through catch_cg_type_check (damage, release, landing).
 * subtract_cu_vital applies throw damage to the victim; cat07_running_check handles a running
 * throw reaching the stage edge. Player_catch is called from the player main routine (PLMAIN).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "SLOWF.h"
#include "PLS03ATT.h"
#include "HITCHECK.h"
#include "PLS02.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLS01.h"
#include "EFF02.h"
#include "Grade.h"
#include "PLPCA.h"



void Player_catch(PLW* wk) {
    wk->wu.next_z = wk->wu.my_priority;
    wk->running_f = 0;
    wk->py->flag = 0;
    wk->guard_flag = 3;
    wk->guard_chuu = 0;
    wk->tsukami_f = 1;
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
    check_em_tk_power_off(wk, (PLW*)wk->wu.target_adrs);
    plpca_lv_00[wk->wu.routine_no[2]](wk);
    check_nagenuke(wk, (PLW*)wk->wu.hit_adrs);
    if (((WORK*)wk->wu.target_adrs)->routine_no[2] == 3) {
        return;
    }
    if (wk->wu.cg_prio) {
        wk->wu.next_z = ((WORK*)wk->wu.target_adrs)->my_priority;
        if (wk->wu.cg_prio == 1) {
            wk->wu.next_z++;
        } else {
            wk->wu.next_z -= 3;
        }
    }
}



/* A reserved throw break skips the hazusenai test. */
void check_nagenuke(PLW* wk, PLW* tk) {
    if (tk->wu.work_id != 1) {
        return;
    }
    if (tk->cat_break_reserve) {
        goto ok;
    }
    if (tk->hazusenai_flag) {
        return;
    }
ok:
    if (wk->cat_break_ok_timer && wk->wu.routine_no[1] == 2 && check_nagenuke_cmd(tk)) {
        if (wk->wu.xyz[1].disp.pos > 8) {
            wk->wu.routine_no[2] = 50;
        } else {
            wk->wu.routine_no[2] = 48;
        }
        wk->wu.routine_no[1] = 0;
        wk->wu.routine_no[3] = 0;
        wk->wu.hit_stop = 0;
        wk->wu.dm_stop = 0;
        if (tk->wu.xyz[1].disp.pos > 8) {
            tk->wu.routine_no[2] = 49;
        } else {
            tk->wu.routine_no[2] = 47;
        }
        tk->wu.routine_no[1] = 0;
        tk->wu.routine_no[3] = 0;
        tk->wu.hit_stop = 1;
        tk->wu.dm_stop = 0;
    }
}



void Catch_00000(PLW* wk) {}


void Catch_01000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init_ca(wk, 2, wk->wu.char_index);
        break;
    case 1:
        char_move(&wk->wu);
        catch_cg_type_check(wk);
        break;
    }
}



void Catch_02000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init_ca(wk, 2, wk->wu.char_index + ((WORK*)wk->wu.hit_adrs)->weight_level);
        break;
    case 1:
        char_move((WORK*)wk);
        catch_cg_type_check(wk);
        break;
    }
}



void Catch_03000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init_ca(wk, 2, wk->wu.char_index);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 7) {
            setup_mvxy_data(&wk->wu, wk->as->data_ix);
        }
        catch_cg_type_check(wk);
        break;
    }
}



void Catch_04000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init_ca(wk, 2, wk->wu.char_index);
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->data_ix;
        break;
    case 1:
        char_move(&wk->wu);
        if ((u8)wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
        }
        catch_cg_type_check(wk);
        break;
    case 2:
        jumping_union_process(&wk->wu, 1);
        if ((u8)wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
        }
        catch_cg_type_check(wk);
        break;
    case 3:
        jumping_union_process(&wk->wu, 4);
        catch_cg_type_check(wk);
        break;
    case 4:
        char_move(&wk->wu);
        catch_cg_type_check(wk);
        return;
    }
}



void Catch_05000(PLW* wk) {
    s8 zero = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init_ca(wk, 2, wk->wu.char_index);
        break;
    case 1:
        char_move(&wk->wu);
        switch ((u8)wk->wu.cg_type) {
        case 1:
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = zero;
            break;
        case 0x14:
            add_to_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = zero;
            break;
        case 0x16:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = zero;
            goto next1;
        }
    next1:
        catch_cg_type_check(wk);
        break;
    case 2:
        jumping_union_process(&wk->wu, 1);
        switch ((u8)wk->wu.cg_type) {
        case 1:
            wk->wu.routine_no[3] = 1;
            wk->wu.cg_type = zero;
            goto next2;
        case 0x14:
            add_to_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = zero;
            break;
        }
    next2:
        catch_cg_type_check(wk);
        break;
    case 3:
        char_move(&wk->wu);
        catch_cg_type_check(wk);
        return;
    }
}



void Catch_06000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init_ca(wk, 2, wk->wu.char_index);
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 20) {
            nise_combo_work(wk, (PLW*)wk->wu.target_adrs, 14);
            wk->wu.cg_type = 0;
        }
        catch_cg_type_check(wk);
        break;
    }
}



/* provisional name */
void Catch_09000(void) {}



#pragma inline(check_dm_vital)

s32 check_dm_vital(PLW* wk);

void subtract_cu_vital(PLW* wk) {
    if (check_dm_vital(wk)) {
        if (wk->dead_flag == 0) {
            if (wk->wu.dm_vital) {
                Additinal_Score_DM((WORK_Other*)wk->wu.dmg_adrs, wk->wu.dm_ten_ix);
                add_sp_arts_gauge_hit_dm(wk);
            }
            wk->wu.vital_new -= wk->wu.dm_vital;
            if (wk->wu.dm_nodeathattack && wk->wu.vital_new < 0) {
                wk->wu.vital_new = 0;
            }
            if (wk->wu.vital_new < 0) {
                wk->wu.vital_new = -1;
                wk->dead_flag = 1;
                dead_voice_flag = 1;
                if (round_slow_flag == 0) {
                    set_conclusion_slow();
                    round_slow_flag = 1;
                }
            } else if (wk->py->flag == 0) {
                wk->py->now.quantity.h += wk->wu.dm_piyo;
                if (wk->py->now.quantity.h >= wk->py->genkai) {
                    wk->py->now.timer = 0;
                    wk->py->flag = 1;
                }
            }
        }
    }
    wk->wu.dm_vital = 0;
    wk->wu.dm_piyo = 0;
}



/* provisional name */
s32 check_dm_vital(PLW* wk) {
    if (wk->wu.dm_vital == 0) {
        return 0;
    }
    return 1;
}



void catch_cg_type_check(PLW* wk) {
    PLW* emwk = (PLW*)wk->wu.hit_adrs;
    switch (wk->wu.cg_type) {
    case 2:
        wk->wu.cg_type = 0;
        setup_catch_atthit(&wk->wu, &emwk->wu);
        add_combo_work(wk, emwk);
        break;
    case 3:
        wk->wu.cg_type = 4;
        subtract_cu_vital(emwk);
        set_catch_hit_mark_pos(&wk->wu, &emwk->wu);
        effect_02_init(&wk->wu, 0, 1, wk->wu.rl_flag);
        if (emwk->backup_ok_timer) {
            emwk->uot_cd_ok_flag = 1;
            emwk->ukemi_ok_timer = emwk->backup_ok_timer;
        } else {
            emwk->uot_cd_ok_flag = 0;
            emwk->ukemi_ok_timer = 0;
        }
        emwk->ukemi_success = 0;
        return;
    case 4:
        break;
    case 5:
        subtract_cu_vital(emwk);
        wk->wu.cg_type = 0;
        emwk->ukemi_ok_timer = 0;
        emwk->uot_cd_ok_flag = 0;
        emwk->ukemi_success = 0;
        return;
    case 6:
        wk->wu.cg_type = 0;
        wk->wu.rl_flag ^= 1;
        break;
    case 7:
        wk->wu.cg_type = 0;
        wk->wu.routine_no[1] = wk->wu.cmmd.koc;
        wk->wu.routine_no[2] = wk->wu.cmmd.ix;
        wk->wu.routine_no[3] = wk->wu.cmmd.pat;
        break;
    case 8:
        wk->wu.cg_type = 0;
        emwk->wu.routine_no[1] = wk->wu.cmyd.koc;
        emwk->wu.routine_no[2] = wk->wu.cmyd.ix;
        emwk->wu.routine_no[3] = wk->wu.cmyd.pat;
    }
}



void set_char_move_init_ca(wk, koc, index)
PLW* wk;
s16 koc;
s16 index;
{
    set_char_move_init(&wk->wu, koc, index);
    wk->cat_break_ok_timer = wk->wu.cmyd.koc >> 8;
    wk->wu.cmyd.koc &= 0xFF;
}
