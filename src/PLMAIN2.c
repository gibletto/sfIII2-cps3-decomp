/*
 * PLMAIN2.C  Player move routine for the bonus stage
 *
 * Player_move_bonus (called from PLCNT2) is the bonus-stage version of Player_move: it takes the
 * operator's input, or runs the bonus-stage CPU (bbbs_com_execute) for a
 * computer player, and dispatches on routine_no[0] to player_mvbs_0000 - 4000, which initialise
 * the player, place him at the start position (plmv_b_1020, facing the screen centre) and
 * then run the game routines with hit stop and timers.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLPNM.h"
#include "PLMAIN.h"
#include "appear.h"
#include "BBBSCOM.h"
#include "BBBSCOM2.h"
#include "PLS01.h"
#include "PLS00.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "PLSGAUGE.h"
#include "EFFG3.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "PLMAIN2.h"
#include "fighter.h"



void Player_move_bonus(PLW* wk, u16 lv_data) {
    s16 i;
    if (wk->wu.operator) {
        wk->cp->sw_lvbt = lv_data;
    } else {
        bbbs_com_execute(wk);
        wk->cp->sw_lvbt = 0;
    }
    if (wk->dead_flag) {
        wk->cp->sw_lvbt = 0;
    }
    if (wk->wkey_flag) {
        wk->cp->sw_lvbt = 0;
    }
    if ((wk->dead_flag + wk->wkey_flag) == 0) {
        wk->hurimukenai_flag = 0;
    }
    for (i = 0; i < 8; i++) {
        wk->wu.old_rno[i] = wk->wu.routine_no[i];
    }
    for (i = 0; i < 3; i++) {
        wk->wu.old_pos[i] = wk->wu.xyz[i].disp.pos;
    }
    get_saikinnno_idouryou(wk);
    wk->old_gdflag = wk->guard_flag;
    wk->wu.renew_attack = 0;
    wk->wu.vital_old = wk->wu.vital_new;
    set_rl_waza(wk);
    if (wk->sa_stop_flag != 1) {
        waza_check(wk);
    }
    wk->wu.cmwk[10] = wk->cp->lgp;
    wk->wu.cmwk[11] += wk->cp->lgp;
    wk->wu.cmwk[11] &= 0x7FFF;
    wk->wu.cmwk[12] = wk->cp->sw_new;
    wk->wu.cmwk[13] = wk->cp->sw_now;
    plmain_b_lv_00[wk->wu.routine_no[0]](wk);
}



void player_mvbs_0000(PLW* wk) {
    s16 i;
    s32 k;

    for (i = 0, k = 0; i < 8; i++, k += 2) {
        *(s16*)((s32)wk->old_pos_data + k) = 0;
    }
    setup_vitality(&wk->wu, wk->player_number);
    set_player_shadow(wk);
    wk->bhcnt_timer = 0;
    wk->bullet_hcnt = 0;
    wk->auto_guard = 1;
    wk->wu.dm_stop = 0;
    wk->wu.hit_stop = 0;
    wk->wu.dm_quake = 0;
    wk->wu.hit_quake = 0;
    wk->tsukamarenai_flag = 0;
    wk->zuru_timer = 0;
    wk->zuru_flag = 0;
    wk->tsukamare_f = 0;
    wk->tsukami_f = 0;
    clear_kizetsu_point(wk);
    wk->ukemi_ok_timer = 0;
    wk->uot_cd_ok_flag = 0;
    wk->ukemi_success = 0;
    clear_my_shell_ix(&wk->wu);
    wk->sa->mp_rno = 0;
    wk->sa->mp = 0;
    wk->sa->sa_rno = 0;
    wk->sa->ok = 0;
    wk->sa->ex_rno = 0;
    wk->sa->ex = 0;
    wk->sa_healing = 0;
    demo_set_sa_full(wk->sa);
    wk->dm_hos_flag = 0;
    wk->kezurijini_flag = 0;
    wk->wu.extra_col_2 = 0;
    wk->wu.extra_col = 0;
    wk->sa_stop_flag = 0;
    clear_tk_flags(wk);
    wk->wu.routine_no[0] = PLAYER_MV_PLACE;
    if (wk->player_number == PL_ELENA) {
        effect_G1_init(wk);
    }
    wk->wu.routine_no[6] = 0;
    wk->wu.cmwk[0] = 0;
    about_gauge_process(wk);
}




void player_mvbs_1000(PLW* wk) {
    const APPEAR_DATA* dtbl;
    s16 ap_work;
    switch (appear_type) {
    case APPEAR_STAND:
        plmv_b_1010(wk);
        plmv_b_1020(wk, 96);
        Appear_end++;
        break;
    case APPEAR_JUDGE:
        plmv_b_1010(wk);
        plmv_b_1020(wk, 128);
        break;
    case APPEAR_ENTRY:
    case APPEAR_ROUND:
        wk->wu.routine_no[0] = PLAYER_MV_APPEAR;
        wk->wu.routine_no[1] = PLAYER_NORMAL;
        wk->wu.routine_no[2] = NORMAL_APPEAR;
        wk->wu.routine_no[3] = RN3_START;
        wk->wu.disp_flag = 1;
        Appear_hv[wk->wu.id] = home_visitor_check(wk);
        if (Appear_hv[wk->wu.id]) {
            ap_work = appear_type_hv_tbl[wk->player_number][bg_w.stage][bg_w.area];
        } else {
            ap_work = appear_type_tbl[wk->player_number][bg_w.stage][bg_w.area];
        }
        dtbl = &appear_data[ap_work];
        appear_data_set(wk, dtbl);
        break;
    }
    if (!wk->wu.operator) {
        /* no computer-side start position */
    }
    Player_normal(wk);
}



void plmv_b_1010(PLW* wk) {
    wk->wu.routine_no[0] = PLAYER_MV_READY;
    wk->wu.routine_no[1] = PLAYER_NORMAL;
    wk->wu.routine_no[2] = NORMAL_STAND;
    wk->wu.routine_no[3] = RN3_START;
    wk->wu.disp_flag = 1;
}



void plmv_b_1020(PLW* wk, s16 step) {
    if (wk->wu.id) {
        wk->wu.rl_flag = 0;
        wk->wu.xyz[0].disp.pos = step + get_center_position();
        wk->wu.xyz[1].disp.pos = 0;
    } else {
        wk->wu.rl_flag = 1;
        wk->wu.xyz[0].disp.pos = get_center_position() - step;
        wk->wu.xyz[1].disp.pos = 0;
    }
}




void player_mvbs_2000(PLW* wk) {
    if (wk->wu.routine_no[2] == NORMAL_STAND) {
        wk->wu.routine_no[0] = PLAYER_MV_READY;
        wk->wu.disp_flag = 1;
        wk->wu.cg_type = 0;
    }
    Player_normal(wk);
}



void player_mvbs_3000(PLW* wk) {
    Player_normal(wk);
}



void player_mvbs_4000(PLW* wk) {
    wk->permited_koa = 0;
    check_lever_data(wk);
    if (wk->tsukamare_f) {
        wk->wu.dm_stop = 0;
        wk->wu.hit_stop = 0;
    }
    if (check_hit_stop(wk) != 0) {
    } else {
        plmain_lv_02[wk->wu.routine_no[1]](wk);
        if (Timer_Freeze == 0 && wk->wu.hit_stop == 0 && wk->zuru_timer > 0) {
            wk->zuru_timer -= 2;
        }
        if (wk->zuru_timer < 0) {
            wk->zuru_flag = 1;
        } else {
            wk->zuru_flag = 0;
        }
    }
    if (Timer_Freeze == 0) {
        look_after_timers(wk);
    }
    about_gauge_process(wk);
}
