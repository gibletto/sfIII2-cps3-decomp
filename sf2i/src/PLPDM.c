/*
 * PLPDM.C  Player damage process
 *
 * Runs a player who has been hit or is guarding. Player_damage dispatches Damage_00000 to
 * Damage_31000 by damage routine: standing and crouching hit and guard staggers, air hits and
 * air guard, knock-downs, blow-aways (buttobi), bounces, crumples and KO.
 * Helpers choose the damage animation from posture (set_dm_char_by_pat_status), run the first
 * flight and landing (first_flight_union, buttobi_chakuchi_cg_type_check), slide with
 * dm_step_tbl and dust (setup_smoke_type), and set screen-edge correction (set_dm_hos_flag_*).
 * subtract_dm_vital applies the damage to vitality, awarding score and super gauge and handling
 * KO; get_damage_reaction_data and get_catch_off_data look up dm_reaction_table.
 * check_bullet_damage handles projectile hits. Called from the player main routine (PLMAIN).
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
#include "PLS02.h"
#include "PLSGAUGE.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLS01.h"
#include "cmb_cont.h"
#include "EFFA7.h"
#include "effa8.h"
#include "effa9.h"
#include "EFFD9.h"
#include "EFFG6.h"
#include "EFFI3.h"
#include "Grade.h"
#include "EFFE2.h"
#include "PLPCA.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLPDM.h"
#include "fighter.h"

extern const s16 hissatsu_dageki_00[];
extern const s16 hissatsu_dageki_01[];
extern const s16 hissatsu_dageki_02[];
extern const s16 super_arts_nage_00[];
extern const s16 super_arts_nage_01[];
extern const s16 super_arts_nage_02[];
extern const s16 tsuujyou_dageki_00[];
extern const s16 tsuujyou_dageki_01[];
extern const s16 tsuujyou_dageki_02[];
extern const s16 tsuujyou_nage_00[];
extern const s16 tsuujyou_nage_01[];
extern const s16 tsuujyou_nage_02[112];

const s16* kizetsu_timer_table_0[4] = {
    tsuujyou_dageki_00, tsuujyou_dageki_01, tsuujyou_dageki_02, tsuujyou_dageki_02,
};
const s16* kizetsu_timer_table_1[4] = {
    hissatsu_dageki_00, hissatsu_dageki_01, hissatsu_dageki_02, hissatsu_dageki_02,
};
const s16* kizetsu_timer_table_2[4] = {
    tsuujyou_nage_00, tsuujyou_nage_01, tsuujyou_nage_02, tsuujyou_nage_02,
};
const s16* kizetsu_timer_table_3[4] = {
    &tsuujyou_nage_02[16], &tsuujyou_nage_02[32], &tsuujyou_nage_02[48], &tsuujyou_nage_02[48],
};
const s16* kizetsu_timer_table_4[4] = {
    &tsuujyou_nage_02[64], &tsuujyou_nage_02[80], &tsuujyou_nage_02[96], &tsuujyou_nage_02[96],
};
const s16* kizetsu_timer_table_5[4] = {
    super_arts_nage_00, super_arts_nage_01, super_arts_nage_02, super_arts_nage_02,
};
/* 02007A64 */
const s16** kizetsu_timer_table[9] = {
    kizetsu_timer_table_0,
    kizetsu_timer_table_1,
    kizetsu_timer_table_2,
    kizetsu_timer_table_3,
    kizetsu_timer_table_4,
    kizetsu_timer_table_5,
    kizetsu_timer_table_4,
    kizetsu_timer_table_5,
    kizetsu_timer_table_4,
};


static void damage_atemi_setup(PLW* wk, PLW* ek);

#pragma inline(check_dmpat_to_dmpat)



/* 2i 0600FC98, 3s-near: sf3 src/PLPDM.c:95 Player_damage */
void Player_damage(PLW* wk) {
    wk->wu.next_z = wk->wu.my_priority;
    wk->running_f = 0;
    wk->guard_flag = 3;
    wk->guard_chuu = 0;
    wk->tsukami_f = 0;
    wk->tsukamare_f = 0;
    wk->scr_pos_set_flag = 1;
    wk->dm_hos_flag = 0;
    wk->sa_stop_flag = 0;
    wk->caution_flag = 0;
    wk->sa->saeff_ok = 0;
    wk->sa->saeff_mp = 0;
    wk->cancel_timer = 0;
    wk->hazusenai_flag = 0;
    wk->cat_break_reserve = 0;
    wk->cmd_request = 0;
    if (wk->wu.routine_no[3] == 0) {
        get_damage_reaction_data(wk);
        if (wk->wu.dm_koa & 0x980) {
            wk->ukemi_ok_timer = 0;
        } else {
            wk->ukemi_ok_timer = 6;
        }
        wk->uot_cd_ok_flag = 0;
        wk->ukemi_success = 0;
        check_bullet_damage(wk);
    }
    if (wk->atemi_flag == 9) {
        wk->atemi_flag = 0;
    } else {
        plpdm_lv_00[(wk->wu.routine_no[2])](wk);
    }
    set_hit_stop_hit_quake(&wk->wu);
}



/* 2i 0600FD50, 3s-near: sf3 src/PLPDM.c:135 Damage_00000 */
void Damage_00000(PLW* wk) {
    wk->wu.next_z = 30;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        set_char_move_init(&wk->wu, 1, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
        }
    case 2:
        break;
    }
}



/* 2i 0600FDE8, 3s-near: sf3 src/PLPDM.c:156 Damage_01000 */
void Damage_01000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] = 1;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        reset_mvxy_data(&wk->wu);
        set_char_move_init(&wk->wu, 1, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed(&wk->wu);
            cal_mvxy_speed(&wk->wu);
        }
        break;
    case 2:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
        }
        break;
    case 3:
        jumping_union_process(&wk->wu, 4);
        break;
    case 4:
        char_move(&wk->wu);
        break;
    }
    if (wk->wu.cg_type == 0xFF || wk->wu.cg_type == 64) {
        wk->guard_flag = 0;
    }
}



/* 2i 0600FECC, 3s-near: sf3 src/PLPDM.c:194 Damage_04000 */
void Damage_04000(PLW* wk) {
    s32 z = 0;
    wk->guard_flag = z;
    wk->guard_chuu = guard_kind[wk->wu.routine_no[2] - 4];
    set_dm_hos_flag_grd(wk);
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        if ((wk->wu.dm_quake /= 2) < 4) {
            wk->wu.dm_quake = 4;
        }
        set_char_move_init(&wk->wu, 1, wk->as->char_ix);
        wk->dm_step_tbl = dm_step_data[select_grd_dsd[wk->wu.dm_impact][get_weight_point(&wk->wu)]];
        wk->zuru_timer = z;
        wk->zuru_ix_counter = z;
        break;
    case 1:
        wk->wu.routine_no[3]++;
        setup_smoke_type(wk);
        wk->wu.cmwk[14] = guard_pause_table[0][wk->wu.dm_attlv];
        char_move_wca(&wk->wu);
        add_dm_step_tbl(wk);
        break;
    case 2:
        add_dm_step_tbl(wk);
        if (--wk->wu.cmwk[14] <= 0) {
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
            break;
        }
    default:
        char_move(&wk->wu);
        break;
    }
}



/* 2i 06010020, 3s-near: sf3 src/PLPDM.c:233 Damage_07000 */
void Damage_07000(PLW* wk) {
    wk->guard_flag = 0;
    wk->guard_chuu = guard_kind[wk->wu.routine_no[2] - 4];
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        if ((wk->wu.dm_quake /= 2) < 4) {
            wk->wu.dm_quake = 4;
        }
        set_char_move_init(&wk->wu, 1, wk->as->char_ix);
        wk->wu.cmwk[14] = guard_pause_table[1][wk->wu.dm_attlv];
        if (wk->wu.dm_butt_type) {
            setup_butt_own_data(&wk->wu);
        } else {
            setup_butt_own_data_ex2(&wk->wu, 1);
        }
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca(&wk->wu);
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        set_dm_hos_flag_sky(wk);
        wk->wu.cmwk[14]--;
        if (wk->wu.routine_no[3] != 3) {
            if (wk->wu.cmwk[14] <= 0) {
                wk->wu.routine_no[1] = 0;
                wk->wu.routine_no[2] = 38;
                wk->wu.routine_no[3] = 1;
                wk->wu.cg_type = 0;
                wk->wu.cg_next_ix = 0;
                char_move_wca(&wk->wu);
            }
        } else if (wk->wu.cmwk[14] <= 0) {
            wk->wu.cmwk[14] = 1;
        }
        break;
    case 3:
        wk->wu.routine_no[3]++;
        wk->wu.dead_f = wk->wu.cmwk[14] * 3 / 4;
        if (wk->wu.dead_f <= 0) {
            wk->wu.dead_f = 1;
        }
        wk->wu.mvxy.d[0].sp = wk->wu.mvxy.a[0].sp / wk->wu.dead_f;
        wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
        wk->wu.dead_f = 0;
    case 4:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        set_dm_hos_flag_sky(wk);
        wk->wu.cmwk[14]--;
        if (wk->wu.cmwk[14] <= 0) {
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
            break;
        }
    case 5:
        char_move(&wk->wu);
        break;
    }
    if (wk->wu.cg_type == 0xFF || wk->wu.cg_type == 64) {
        wk->guard_flag = 0;
    }
}



/* 2i 06010222, 3s-near: sf3 src/PLPDM.c:301 Damage_08000 */
void Damage_08000(PLW* wk) {
    wk->guard_flag = 1;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        set_char_move_init(&wk->wu, 1, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->data_ix);
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type != 1) {
            break;
        }
        wk->wu.routine_no[3]++;
    case 2:
        jumping_union_process(&wk->wu, 3);
        set_dm_hos_flag_sky(wk);
        break;
    case 3:
        char_move(&wk->wu);
        break;
    }
    if (wk->wu.cg_type == 0xFF || wk->wu.cg_type == 64) {
        wk->guard_flag = 0;
    }
}



/* 2i 060102F4, 3s-near: sf3 src/PLPDM.c:333 Damage_12000 */
void Damage_12000(PLW* wk) {
    set_dm_hos_flag_grd(wk);
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init((WORK*)wk, 1, wk->dm_ix);
        wk->dm_step_tbl = dm_step_data[select_hit_dsd[wk->wu.dm_impact][get_weight_point(&wk->wu)]];
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        if (wk->wu.dm_attribute) {
            setup_accessories(wk, wk->wu.pat_status);
            if (wk->wu.dm_attribute != 2) {
                effect_D9_init(wk, (u8)wk->wu.dm_attribute);
            }
        }
        break;
    case 1:
        wk->wu.routine_no[3]++;
        setup_smoke_type(wk);
        if (wk->wu.pat_status == 32) {
            wk->wu.cmwk[14] = damage_pause_table[1][wk->wu.dm_attlv];
        } else {
            wk->wu.cmwk[14] = damage_pause_table[0][wk->wu.dm_attlv];
        }
        if (wk->wu.dm_jump_att_flag > 0) {
            wk->wu.cmwk[14] = damage_pause_table[2][wk->wu.dm_attlv];
        }
        char_move_wca((WORK*)wk);
        add_dm_step_tbl(wk);
        break;
    case 2:
        add_dm_step_tbl(wk);
        if (--wk->wu.cmwk[14] <= 0) {
            wk->wu.routine_no[3]++;
            char_move_wca((WORK*)wk);
            break;
        }
    default:
        char_move((WORK*)wk);
        break;
    }
    if (wk->wu.cg_type == 0xFF || wk->wu.cg_type == 0x40) {
        wk->guard_flag = 0;
    }
}



/* 2i 060104BE, 3s-near: sf3 src/PLPDM.c:383 Damage_14000 */
void Damage_14000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK*)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 1, wk->dm_ix);
        setup_butt_own_data(&wk->wu);
        wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
    case 2:
        wk->dm_hos_flag = 1;
        first_TtktV_union(wk, 3, 4);
        break;
    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}



/* 2i 0601056E, 3s-near: sf3 src/PLPDM.c:412 Damage_16000 */
void Damage_16000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 6, wk->dm_ix);
        wk->wu.xyz[1].disp.pos += buttobi_add_y_table[wk->dm_ix];
        setup_butt_own_data(&wk->wu);
        cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], 0);
        get_sky_dm_timer(wk);
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
    case 2:
        wk->dm_hos_flag = 1;
        first_flight_union(wk, 3, 3);
        break;
    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
    if (wk->wu.cg_type == 0xFF || wk->wu.cg_type == 0x40) {
        wk->guard_flag = 0;
    }
}



/* 2i 0601066C, 3s-near: sf3 src/PLPDM.c:442 Damage_17000 */
void Damage_17000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 6, wk->dm_ix);
        wk->wu.xyz[1].disp.pos += buttobi_add_y_table[wk->dm_ix];
        if (wk->wu.dm_butt_type) {
            setup_butt_own_data(&wk->wu);
        } else {
            setup_butt_own_data_ex(&wk->wu, 0);
        }
        cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], wk->wu.xyz[1].disp.pos);
        get_sky_dm_timer(wk);
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
    case 2:
        jumping_union_process(&wk->wu, 3);
        set_dm_hos_flag_sky(wk);
        if (wk->wu.cg_ja.boix == 0) {
            wk->guard_flag = 0;
        }
        if (wk->wu.routine_no[3] == 3) {
            wk->guard_flag = 0;
            wk->tsukamarenai_flag = 5;
        }
        break;
    case 3:
        char_move(&wk->wu);
        wk->guard_flag = 0;
        break;
    }
}



/* 2i 06010796, 3s-near: sf3 src/PLPDM.c:495 Damage_18000 */
void Damage_18000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init((WORK*)wk, 6, wk->dm_ix);
        wk->wu.xyz[1].disp.pos += buttobi_add_y_table[wk->dm_ix];
        if (wk->wu.dm_butt_type) {
            setup_butt_own_data((WORK*)wk);
        } else {
            setup_butt_own_data_ex((WORK*)wk, 0);
        }
        cal_initial_speed_y((WORK*)wk, buttobi_time_table[wk->dm_ix], wk->wu.xyz[1].disp.pos);
        get_sky_dm_timer(wk);
        if (wk->wu.dm_attribute) {
            setup_accessories(wk, wk->wu.pat_status);
            if (wk->wu.dm_attribute != 2) {
                effect_D9_init(wk, (u8)wk->wu.dm_attribute);
            }
        }
        break;
    case 1:
        if (setup_kuuchuu_nmdm(wk)) {
            return;
        }
        wk->wu.routine_no[3]++;
        char_move_wca_init((WORK*)wk);
    case 2:
        set_dm_hos_flag_sky(wk);
        first_flight_union(wk, 3, 3);
        break;
    case 3:
        char_move((WORK*)wk);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}



/* 2i 060108E2, 3s-near: sf3 src/PLPDM.c:531 Damage_19000 */
void Damage_19000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK*)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 6, wk->dm_ix);
        wk->wu.xyz[1].disp.pos += buttobi_add_y_table[wk->dm_ix];
        if (wk->wu.dm_butt_type) {
            setup_butt_own_data(&wk->wu);
        } else {
            setup_butt_own_data_ex(&wk->wu, 0);
        }
        cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], 0);
        get_sky_dm_timer(wk);
        break;
    case 1:
        if (setup_kuuchuu_nmdm(wk)) {
            return;
        }
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
    case 2:
        set_dm_hos_flag_sky(wk);
        first_flight_union(wk, 3, 3);
        break;
    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}



/* 2i 06010A0A, 3s-near: sf3 src/PLPDM.c:563 Damage_20000 */
void Damage_20000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK*)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        setup_butt_own_data(&wk->wu);
        wk->dm_ix = wk->as->char_ix + get_buttobi_attlv(wk);
        wk->wu.xyz[1].disp.pos += buttobi_add_y_table[wk->dm_ix];
        set_char_move_init(&wk->wu, 6, wk->dm_ix);
        get_sky_dm_timer(wk);
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
    case 2:
        set_dm_hos_flag_sky(wk);
        first_flight_union(wk, 3, 4);
        break;
    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}



/* 2i 06010AF6, 3s-near: sf3 src/PLPDM.c:591 Damage_21000 */
void Damage_21000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK*)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 1, wk->dm_ix);
        setup_butt_own_data(&wk->wu);
        wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
    case 2:
        wk->dm_hos_flag = 1;
        first_TtktV_union(wk, 3, 2);
        break;
    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}



/* 2i 06010BC8, 3s-near: sf3 src/PLPDM.c:620 Damage_23000 */
void Damage_23000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK*)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        setup_butt_own_data(&wk->wu);
        wk->dm_ix = wk->as->char_ix + get_buttobi_attlv(wk);
        wk->wu.xyz[1].disp.pos += buttobi_add_y_table[wk->dm_ix];
        set_char_move_init(&wk->wu, 6, wk->dm_ix);
        get_sky_dm_timer(wk);
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
    case 2:
        set_dm_hos_flag_sky(wk);
        first_flight_union(wk, 3, 2);
        break;
    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}



/* 2i 06010C82, 3s-near: sf3 src/PLPDM.c:648 Damage_24000 */
void Damage_24000(PLW* wk) {
    s32 char_ix;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_step_tbl = dm_step_data[select_hit_dsd[wk->wu.dm_impact][get_weight_point(&wk->wu)]];
        if (wk->as->char_ix == 0x44) {
            s32 k = wk->dm_point;
            if (k == 2 || k == 3) {
                char_ix = 0x45;
                goto call;
            }
        }
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        char_ix = wk->as->char_ix;
    call:
        set_char_move_init(&wk->wu, 1, char_ix);
        break;
    case 1:
        wk->wu.routine_no[3]++;
        wk->wu.cmwk[14] = damage_pause_table[0][wk->wu.dm_attlv];
        char_move_wca(&wk->wu);
        add_dm_step_tbl(wk);
        break;
    case 2:
        add_dm_step_tbl(wk);
        if (--wk->wu.cmwk[14] <= 0) {
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
            break;
        }
    default:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[2] = 0;
            wk->wu.routine_no[3] = 1;
        }
        break;
    }
}



/* 2i 06010DAC, 3s-near: sf3 src/PLPDM.c:693 Damage_25000 */
void Damage_25000(PLW* wk) {
    s16 i;
    s16 hok;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 1, wk->as->char_ix);
        wk->py->flag = 0;
        wk->py->time = kizetsu_timer_table[(wk->kizetsu_kow & 0xF8) / 8][(wk->kizetsu_kow & 7) / 2][random_16_com()];
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        work_init_zero((s32*)wk->rp, sizeof(ComboType));
        check_em_tk_power_off(wk, (PLW*)wk->wu.target_adrs);
        break;
    case 1:
        if ((pcon_dp_flag != 0) && (wk->py->time > 48)) {
            wk->py->time = 48;
        }
        wk->py->time -= wk->cp->lgp / 2;
        if (wk->cp->lgp > 13) {
            hok = 5;
        } else {
            hok = hok_table[wk->cp->lgp / 2];
        }
        for (i = 0; i < hok; i++) {
            char_move((WORK*)wk);
        }
        break;
    }
}



/* 2i 06010F30, 3s-near: sf3 src/PLPDM.c:727 Damage_26000 */
void Damage_26000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 6, wk->dm_ix);
        wk->wu.xyz[1].disp.pos += buttobi_add_y_table[wk->dm_ix];
        if (wk->wu.dm_butt_type) {
            setup_butt_own_data(&wk->wu);
        } else {
            setup_butt_own_data_ex(&wk->wu, 0);
        }
        wk->wu.mvxy.d[1].sp = (wk->wu.mvxy.d[1].sp * 80) / 100;
        cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], 0);
        *(s16*)&wk->wu.mvxy.a[0] = wk->move_power;
        wk->wu.mvxy.a[0].real.l = 0;
        wk->wu.mvxy.a[0].sp *= 3;
        wk->wu.mvxy.a[0].sp /= 4;
        wk->wu.mvxy.d[0].sp = 0;
        if (*(s16*)&wk->wu.mvxy.a[0] > 4) {
            *(s16*)&wk->wu.mvxy.a[0] = 4;
        }
        if (*(s16*)&wk->wu.mvxy.a[0] < 1) {
            *(s16*)&wk->wu.mvxy.a[0] = 1;
        }
        get_sky_dm_timer(wk);
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
    case 2:
        set_dm_hos_flag_sky(wk);
        first_flight_union(wk, 3, 3);
        if (wk->wu.routine_no[3] == 3 && wk->player_number == PL_ELENA) {
            wk->wu.rl_flag = (wk->wu.rl_flag + 1) & 1;
        }
        break;
    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}



/* 2i 060110A8, 3s-near: sf3 src/PLPDM.c:768 Damage_27000 */
void Damage_27000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 1, wk->dm_ix);
        setup_butt_own_data(&wk->wu);
        wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
    default:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}



/* 2i 06011126, 3s-near: sf3 src/PLPDM.c:791 Damage_28000 */
void Damage_28000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 6, wk->dm_ix);
        wk->wu.xyz[1].disp.pos += buttobi_add_y_table[wk->dm_ix];
        if (wk->wu.dm_butt_type) {
            setup_butt_own_data(&wk->wu);
        } else {
            setup_butt_own_data_ex(&wk->wu, 0);
        }
        cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], wk->wu.xyz[1].disp.pos);
        get_sky_dm_timer(wk);
        break;
    case 1:
        set_dm_hos_flag_sky(wk);
        first_flight_union(wk, 2, 3);
        break;
    case 2:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}



/* 2i 060111F2, 3s-near: sf3 src/PLPDM.c:814 Damage_29000 */
void Damage_29000(PLW* wk) {
    PLW* twk = (PLW*)wk->wu.target_adrs;
    const s16* datadrs;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.dm_rl = twk->wu.rl_flag;
        if (wk->dm_point > 2) {
            wk->wu.routine_no[2] = wk->as->data_ix;
            plpdm_lv_00[wk->wu.routine_no[2]](wk);
            break;
        }
        wk->wu.routine_no[3]++;
        datadrs = (const s16*)exdm_ix_data[wk->wu.dm_exdm_ix][wk->player_number];
        if (twk->wu.rl_flag) {
            wk->wu.xyz[0].disp.pos = twk->wu.xyz[0].disp.pos - datadrs[0];
        } else {
            wk->wu.xyz[0].disp.pos = twk->wu.xyz[0].disp.pos + datadrs[0];
        }
        wk->wu.xyz[1].disp.pos = twk->wu.xyz[1].disp.pos + datadrs[1];
        wk->wu.rl_flag = (wk->wu.dm_rl + datadrs[2]) & 1;
        wk->wu.cg_olc_ix = datadrs[3];
        wk->wu.cg_olc = wk->wu.olc_ix_table[wk->wu.cg_olc_ix];
        wk->wu.cg_number = datadrs[4];
        wk->wu.cg_ctr = 0xFA;
        wk->wu.cg_flip = 0;
        wk->wu.cg_type = 0;
        break;
    case 1:
        wk->wu.routine_no[2] = wk->as->data_ix;
        wk->wu.routine_no[3]++;
        if (wk->wu.routine_no[2] == 18) {
            wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
            set_char_move_init(&wk->wu, 6, wk->dm_ix);
            char_move_wca_init(&wk->wu);
            wk->wu.xyz[1].disp.pos += buttobi_add_y_table[wk->dm_ix];
            if (wk->wu.dm_butt_type) {
                setup_butt_own_data(&wk->wu);
            } else {
                setup_butt_own_data_ex(&wk->wu, 0);
            }
            cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], wk->wu.xyz[1].disp.pos);
        } else {
            setup_butt_own_data(&wk->wu);
            wk->dm_ix = wk->as->char_ix + get_buttobi_attlv(wk);
            set_char_move_init(&wk->wu, 6, wk->dm_ix);
            char_move_wca_init(&wk->wu);
            wk->wu.xyz[1].disp.pos += buttobi_add_y_table[wk->dm_ix];
        }
        get_sky_dm_timer(wk);
        plpdm_lv_00[wk->wu.routine_no[2]](wk);
        break;
    }
}



/* 2i 06011448, 3s-near: sf3 src/PLPDM.c:867 Damage_30000 */
void Damage_30000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK*)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 6, wk->dm_ix);
        wk->wu.xyz[1].disp.pos += buttobi_add_y_table[wk->dm_ix];
        setup_butt_own_data(&wk->wu);
        cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], 0);
        return;
    case 1:
        if (setup_kuuchuu_nmdm(wk)) {
            return;
        }
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
    case 2:
        set_dm_hos_flag_sky(wk);
        first_flight_union(wk, 3, 3);
        if (wk->wu.routine_no[3] == 3 || !wk->hos_fi_flag) {
            return;
        }
        wk->wu.routine_no[2] = 18;
        wk->wu.routine_no[3] = 1;
        wk->dm_ix = wk->as->data_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 6, wk->dm_ix);
        wk->wu.dm_butt_type++;
        setup_butt_own_data(&wk->wu);
        cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], wk->wu.xyz[1].disp.pos);
        get_sky_dm_timer(wk);
        if (wk->wu.dm_attribute) {
            setup_accessories(wk, wk->wu.pat_status);
            if (wk->wu.dm_attribute != 2) {
                effect_D9_init(wk, (u8)wk->wu.dm_attribute);
            }
        }
        wk->wu.hit_stop = 3;
        wk->wu.hit_quake = 0;
        bg_w.quake_x_index = 6;
        effect_I3_init(&wk->wu, (s8)wk->wu.hit_stop);
        subtract_cu_vital(wk);
        break;
    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        return;
    }
}



/* provisional name */
/* 2i 060115DA, 3s-near: sf3 src/PLPDM.c:990 set_dm_char_dummy */
void set_dm_char_dummy(void) {}



/* 2i 0601161C, 3s-exact: sf3 src/PLPDM.c:994 first_flight_union */
void first_flight_union(PLW* wk, s16 num, s16 dv) {
    jumping_union_process(&wk->wu, num);
    if (wk->wu.routine_no[3] != num) {
        return;
    }
    wk->wu.mvxy.a[0].sp /= dv;
    wk->wu.mvxy.d[0].sp = wk->wu.mvxy.kop[0] = 0;
    wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
    if (wk->ukemi_ok_timer) {
        wk->uot_cd_ok_flag = 1;
    } else {
        wk->uot_cd_ok_flag = 0;
    }
    subtract_cu_vital(wk);
    effect_A7_init(wk);
    buttobi_chakuchi_cg_type_check(wk);
    if (wk->ukemi_ok_timer != 0 && wk->ukemi_success == 0) {
        wk->uot_cd_ok_flag = 1;
    }
}



/* 2i 060116AA, 3s-near: sf3 src/PLPDM.c:1017 first_TtktV_union */
void first_TtktV_union(PLW* wk, s16 num, s16 dv) {
    char_move(&wk->wu);
    if (wk->wu.cg_type) {
        wk->wu.routine_no[3] = num;
        wk->wu.mvxy.a[0].sp /= dv;
        wk->wu.mvxy.d[0].sp = wk->wu.mvxy.kop[0] = 0;
        if (wk->ukemi_ok_timer) {
            wk->uot_cd_ok_flag = 1;
        } else {
            wk->uot_cd_ok_flag = 0;
        }
        subtract_cu_vital(wk);
        effect_A7_init(wk);
        buttobi_chakuchi_cg_type_check(wk);
        if (wk->ukemi_ok_timer != 0 && wk->ukemi_success == 0) {
            wk->uot_cd_ok_flag = 1;
        }
    } else {
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
    }
}



/* 2i 0601175E, 3s-near: sf3 src/PLPDM.c:1042 buttobi_chakuchi_cg_type_check */
void buttobi_chakuchi_cg_type_check(PLW* wk) {
    switch (wk->wu.cg_type) {
    case 9:
        break;
    case 1:
        add_mvxy_speed(&wk->wu);
        break;
    case 2:
        if (*(s16*)&wk->wu.mvxy.a[0] > 0) {
            add_mvxy_speed_direct(&wk->wu, 96, 0);
            break;
        }
        if (*(s16*)&wk->wu.mvxy.a[0] < 0) {
            add_mvxy_speed_direct(&wk->wu, -96, 0);
        }
        break;
    case 5:
        if (wk->ukemi_success && (wk->dead_flag == 0) && (wk->py->flag == 0) && (wk->wu.vital_new > 0) &&
            (pcon_dp_flag == 0)) {
            wk->wu.routine_no[2] = oki_select_table2[(wk->wu.rl_flag * 2) + wk->wu.rl_waza];
            wk->wu.routine_no[3] = 0;
            add_sp_arts_gauge_ukemi(wk);
        }
        if (*(s16*)&wk->wu.mvxy.a[0] > 0) {
            add_mvxy_speed_direct(&wk->wu, 48, 0);
            break;
        }
        if (*(s16*)&wk->wu.mvxy.a[0] < 0) {
            add_mvxy_speed_direct(&wk->wu, -48, 0);
        }
        break;
    }
}




/* 2i 06011850, 3s-reloc: sf3 src/PLPDM.c:1088 setup_smoke_type */
void setup_smoke_type(PLW* wk) {
    s8* step_tbl;
    u8 ix;
    s16 i;
    s16 total;
    total = 0;
    step_tbl = wk->dm_step_tbl;
    for (i = 0; i < 32; i++) {
        total += *step_tbl++;
    }
    if (total < 0) {
        total = -total;
    }
    if (total >= 32) {
        ix = 0;
        if (total < 48) {
            goto set;
        }
        ix = 1;
        if (total < 64) {
            goto set;
        }
        ix = 2;
        if (total < 80) {
            goto set;
        }
        ix = 3;
set:
        effect_G6_init((WORK*)wk, ix);
    }
}



/* 2i 060118A8, 3s-reloc: sf3 src/PLPDM.c:1122 add_dm_step_tbl */
void add_dm_step_tbl(PLW* wk) {
    if (wk->wu.dm_rl) {
        wk->wu.xyz[0].disp.pos += *wk->dm_step_tbl++;
    } else {
        wk->wu.xyz[0].disp.pos -= *wk->dm_step_tbl++;
    }
}


/* 2i 060118E0, 3s-exact: sf3 src/PLPDM.c:1131 check_dmpat_to_dmpat */
void check_dmpat_to_dmpat(PLW* wk) {}



/* 2i 060118E4, 3s-near: sf3 src/PLPDM.c:1135 set_dm_hos_flag_sky */
void set_dm_hos_flag_sky(PLW* wk) {
    s16 disx = wk->wu.xyz[0].disp.pos - ((WORK*)wk->wu.target_adrs)->xyz[0].disp.pos;
    if (disx < 0) {
        disx = -disx;
    }
    if (wk->wu.dm_work_id & 8) {
        if (wk->wu.mvxy.a[1].real.h <= 0) {
            if (disx > 96) {
                return;
            }
        } else if (disx > 160) {
            return;
        }
        wk->dm_hos_flag = 1;
        return;
    }
    if (!(wk->wu.dm_work_id & 1)) {
        return;
    }
    if (wk->wu.mvxy.a[1].real.h <= 0) {
        if (disx > 80) {
            return;
        }
    } else if (disx > 128) {
        return;
    }
    wk->dm_hos_flag = 1;
}



/* 2i 0601195E, 3s-reloc: sf3 src/PLPDM.c:1166 set_dm_hos_flag_grd */
void set_dm_hos_flag_grd(PLW* wk) {
    s16 disx = wk->wu.xyz[0].disp.pos - ((WORK*)wk->wu.target_adrs)->xyz[0].disp.pos;
    if (disx < 0) {
        disx = -disx;
    }
    if (wk->wu.dm_work_id & 8) {
        if (disx <= 128) {
            wk->dm_hos_flag = 1;
        }
        return;
    }
    if (wk->wu.dm_work_id & 1) {
        wk->dm_hos_flag = 1;
    }
}



/* 2i 06011998, 3s-near: sf3 src/PLPDM.c:1184 get_sky_dm_timer */
void get_sky_dm_timer(PLW* wk) {
    if (wk->wu.dm_zuru == 7) {
        wk->zuru_ix_counter = 0;
    } else {
        wk->zuru_ix_counter += sky_dm_zuru_ix[wk->wu.dm_zuru];
    }
    if (wk->zuru_ix_counter > 15) {
        wk->zuru_ix_counter = 15;
    }
    wk->zuru_timer = sky_dm_zuru_table[wk->zuru_ix_counter];
}



/* 2i 060119E4, 3s-near: sf3 src/PLPDM.c:1198 subtract_dm_vital */
void subtract_dm_vital(PLW* wk) {
    if (wk->dead_flag == 0) {
        if (wk->wu.dm_vital != 0) {
            s16* p = wk->wu.routine_no;
            if (p[1] != 1 || p[2] > 11 || p[3] != 0) {
                Additinal_Score_DM((WORK_Other*)wk->wu.dmg_adrs, wk->wu.dm_ten_ix);
            }
        }
        add_sp_arts_gauge_hit_dm(wk);
        if (wk->atemi_flag) {
            wk->dm_vital_backup = wk->wu.dm_vital;
        } else {
            wk->dm_vital_backup = 0;
        }
        wk->dm_vital_use = 0;
        wk->wu.vital_new -= wk->wu.dm_vital;
        if (wk->wu.dm_guard_success == -1 && wk->wu.vital_old > 0 && wk->wu.vital_new < 0 && wk->wu.vital_new > -3) {
            wk->wu.vital_new = 0;
        }
        if (wk->wu.dm_nodeathattack && wk->wu.vital_new < 0) {
            wk->wu.vital_new = 0;
        }
        if (wk->wu.vital_new < 0) {
            wk->wu.vital_new = -1;
            wk->dead_flag = 1;
            dead_voice_flag = 1;
            if (wk->wu.dm_guard_success != -1) {
                wk->kezurijini_flag = 1;
            }
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
    wk->wu.dm_vital = 0;
    wk->wu.dm_piyo = 0;
}



/* 2i 06011B58, 3s-near: sf3 src/PLPDM.c:1245 subtract_dm_vital_aiuchi */
void subtract_dm_vital_aiuchi(PLW* wk) {
    if (wk->dead_flag == 0) {
        if (wk->wu.dm_vital != 0) {
            s16* p = wk->wu.routine_no;
            if (p[1] != 1 || p[2] > 11 || p[3] != 0) {
                Additinal_Score_DM((WORK_Other*)wk->wu.dmg_adrs, wk->wu.dm_ten_ix);
            }
        }
        if (wk->atemi_flag) {
            wk->dm_vital_backup = wk->wu.dm_vital;
        } else {
            wk->dm_vital_backup = 0;
        }
        wk->dm_vital_use = 0;
        wk->wu.vital_new -= wk->wu.dm_vital;
        if (wk->wu.dm_guard_success == -1 && wk->wu.vital_old > 0 && wk->wu.vital_new < 0 && wk->wu.vital_new > -3) {
            wk->wu.vital_new = 0;
        }
        if (wk->wu.dm_nodeathattack && wk->wu.vital_new < 0) {
            wk->wu.vital_new = 0;
        }
        if (wk->wu.vital_new < 0) {
            wk->wu.vital_new = -1;
            wk->dead_flag = 1;
            dead_voice_flag = 1;
            if (wk->wu.dm_guard_success != -1) {
                wk->kezurijini_flag = 1;
            }
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
    wk->wu.dm_vital = 0;
    wk->wu.dm_piyo = 0;
}



/* 2i 06011CA2, 3s-near: sf3 src/PLPDM.c:1291 get_damage_reaction_data */
void get_damage_reaction_data(PLW* wk) {
    if (wk->atemi_flag == 2) {
        wk->wu.dm_vital = 0;
        damage_atemi_setup(wk, (PLW*)wk->wu.dmg_adrs);
        return;
    }
    subtract_dm_vital(wk);
    if (wk->wu.routine_no[2] == 88) {
        wk->wu.routine_no[2] = check_buttobi_type(wk);
    }
    if (wk->py->flag && wk->wu.routine_no[2] == 88) {
        wk->wu.routine_no[2] = 91;
    }
    if (wk->dead_flag) {
        wk->wu.routine_no[2] = dd_convert[wk->wu.routine_no[2]][wk->wu.dm_attlv];
        if (wk->wu.routine_no[2] > 19 && wk->wu.routine_no[2] < 88) {
            if (wk->wu.routine_no[2] != 70) {
                wk->wu.routine_no[2] = check_buttobi_type2(&wk->wu);
            }
        }
    }
    if (wk->atemi_flag == 1) {
        damage_atemi_setup(wk, (PLW*)wk->wu.dmg_adrs);
        return;
    }
    wk->as = (AS*)&dm_reaction_table[wk->wu.routine_no[2]];
    wk->wu.routine_no[2] = wk->as->r_no;
    if (wk->wu.dm_stop) {
        if (wk->wu.dm_stop > 0) {
            wk->wu.dm_stop--;
        }
        if (wk->wu.dm_stop < 0) {
            wk->wu.dm_stop++;
        }
    }
}



/* 2i 06011DAE, 3s-near: sf3 src/PLPDM.c:1334 damage_atemi_setup */
static void damage_atemi_setup(PLW* wk, PLW* ek) {
    wk->wu.routine_no[1] = wk->wu.cmmd.koc;
    wk->wu.routine_no[2] = wk->wu.cmmd.ix;
    wk->wu.routine_no[3] = wk->wu.cmmd.pat;
    char_move_cmms(&wk->wu);
    wk->atemi_flag = 9;
    wk->wu.dm_stop = wk->wu.dm_quake = 0;
    wk->wu.hit_stop = wk->wu.hit_quake = 0;
    ek->wu.dm_stop = ek->wu.dm_quake = 0;
    ek->wu.hit_stop = wk->wu.att.hs_you;
    ek->wu.hit_quake = wk->wu.att.hs_you / 2;
}




/* 2i 06011E16, 3s-near: sf3 src/PLPDM.c:1349 setup_kuzureochi */
s32 setup_kuzureochi(PLW* wk) {
    if (wk->wu.vital_new >= 0) {
        return 0;
    }
    wk->wu.routine_no[1] = 1;
    wk->wu.routine_no[2] = 0;
    wk->wu.routine_no[3] = 1;
    wk->zuru_timer = 0;
    wk->zuru_ix_counter = 0;
    set_char_move_init(&wk->wu, 1, 73);
    wk->wu.dm_stop = wk->wu.hit_stop = 0;
    wk->wu.dm_quake = wk->wu.hit_quake = 0;
    return 1;
}



/* 2i 06011E66, 3s-near: sf3 src/PLPDM.c:1366 setup_kuuchuu_nmdm */
s32 setup_kuuchuu_nmdm(PLW* wk) {
    if (wk->dead_flag) {
        return 0;
    }
    if (((PLW*)wk->wu.target_adrs)->dead_flag == 0) {
        return 0;
    }
    wk->wu.routine_no[2] = 17;
    wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
    wk->dm_ix = wk->wu.dm_attlv;
    set_char_move_init(&wk->wu, 6, wk->dm_ix);
    if (wk->wu.dm_butt_type) {
        setup_butt_own_data(&wk->wu);
    } else {
        setup_butt_own_data_ex(&wk->wu, 0);
    }
    cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], wk->wu.xyz[1].disp.pos);
    return 1;
}



/* 2i 06011F08, 3s-near: sf3 src/PLPDM.c:1384 get_catch_off_data */
void get_catch_off_data(PLW* wk, s16 ix) {
    wk->as = (const AS*)&dm_reaction_table[ix];
}



/* 2i 06011F18, 3s-near: sf3 src/PLPDM.c:1390 check_bullet_damage */
void check_bullet_damage(PLW* wk) {
    WORK* tk = (WORK*)wk->wu.dmg_adrs;
    if (tk->work_id != 1 && tk->id == 13) {
        if (tama_select[tk->type] != 0) {
            wk->bullet_hcnt += tama_select[tk->type];
            wk->bhcnt_timer = 800;
        }
    }
}
