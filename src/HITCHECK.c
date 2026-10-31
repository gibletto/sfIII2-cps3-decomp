/*
 * HITCHECK.C  Hit detection and damage resolution
 *
 * Players and effects queue themselves each frame with hit_push_request; hit_check_main_process
 * (from Game_Main and end_sub) then runs catch_hit_check (throws), attack_hit_check (attack boxes
 * against damage boxes), set_judge_result and check_result_extra, and clears the queue.
 * The judged pairs go to the per-pair routines in HITPLPL, HITPLEF, HITEFPL and HITEFEF.
 * This module sets the resulting states: struck (set_struck_status), caught, guard (set_guard_status) and
 * blocking (parry: set_paring_status, which the hit judgement's parried label calls), damage and stun
 * (set_damage_and_piyo), combo work and damage reduction (add_combo_work, cal_combo_waribiki), hit stop
 * and hit mark positions.
 * It also provides the damage routine lookups by damage index and general helpers used by many
 * effects and moves: hit_check_subroutine and get_target_att_position.
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
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLS01.h"
#include "Grade.h"
#include "PLS02.h"
#include "EFF02.h"
#include "HITEFEF.h"
#include "HITEFPL.h"
#include "HITPLEF.h"
#include "HITPLPL.h"
#include "ta_sub.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "HITCHECK.h"
#include "fighter.h"

/* hit_mark_hosei_table[att.mkh_ix] columns */
#define MARK_HOSEI_X    0       /* x offset, mirrored by facing */
#define MARK_HOSEI_Y    1       /* y offset */

void tilemap_print_hex();

WORK * q_hit_push[32];  /* 0200FE58 */
HS hs[32];  /* 0200FED8 */
s8 ca_check_flag;  /* 020100D8 */
const s16 * dmdat_adrs[9];  /* 020100DC */
s16 mkm_wk[32];  /* 02010100 */
s16 hpq_in;  /* 02010140 */

#pragma inline(get_sky_nm_damage, get_sky_nm2_damage, get_sky_sp_damage, get_kagami_damage, get_kagami2_damage, get_grd_hand_damage, check_head_damage, check_trunk_damage)

void hit_check_main_process(void) {
    aiuchi_flag = 0;
    if (hpq_in > 1) {
        if (ca_check_flag) {
            catch_hit_check();
        }
        attack_hit_check();
        if (set_judge_result()) {
            check_result_extra();
        }
    }
    clear_hit_queue();
}


s32 set_judge_result(void) {
    s16 i;
    s16 rnum = 0;
    for (i = 0; i < hpq_in; i++) {
        if (hs[i].flag.results & 0x101) {
            rnum = 1;
            if (hs[i].flag.results & 0x100) {
                set_caught_status(i);
            } else {
                set_struck_status(i);
            }
        }
    }
    return rnum;
}


void check_result_extra(void) {
    WORK_Other* dm1p;
    WORK_Other* dm2p;
    if (plw[0].wu.routine_no[1] == PLAYER_DAMAGE && plw[0].wu.routine_no[3] == RN3_START) {
        if (plw[1].wu.routine_no[1] == PLAYER_DAMAGE && plw[1].wu.routine_no[3] == RN3_START) {
            dm1p = (WORK_Other*)plw[0].wu.dmg_adrs;
            dm2p = (WORK_Other*)plw[1].wu.dmg_adrs;
            switch ((dm1p->wu.work_id == 1) + ((dm2p->wu.work_id == 1) * 2)) {
            case 3:
                aiuchi_flag = 1;
                plw[0].wu.hit_stop = plw[0].wu.hit_quake = 0;
                plw[1].wu.hit_stop = plw[1].wu.hit_quake = 0;
                plw[0].wu.dm_stop = plw[0].wu.dm_quake = 4;
                plw[1].wu.dm_stop = plw[1].wu.dm_quake = 4;
                break;
            }
            return;
        }
    }
}


void set_caught_status(ix)
s16 ix;
{
    s16 ix2 = hs[ix].dm_me;
    PLW* as = (PLW*)q_hit_push[ix2];
    PLW* ds = (PLW*)q_hit_push[ix];
    s8 gddir;
wait_hit:
    if (ix != hs[ix2].my_hit) {
        goto wait_hit;
    }
wait_dm:
    if (hs[ix2].flag.results & 0x100) {
        if (ix != hs[ix2].dm_me) {
            goto wait_dm;
        }
        if (as->wu.att.at_free4 & 0x80) {
            if (!(ds->wu.att.at_free4 & 0x80)) {
                goto two;
            }
            goto timer;
        }
        if (as->wu.att.at_free4 & 0x40) {
            if (ds->wu.att.at_free4 & 0x80) {
                goto one;
            }
            if (!(ds->wu.att.at_free4 & 0x40)) {
                goto two;
            }
            goto timer;
        }
        if (ds->wu.att.at_free4 & 0xC0) {
            goto one;
        }
        ds->cat_break_reserve = 1;
        as->cat_break_reserve = 1;
    timer:
        if (Game_timer & 1) {
            goto two;
        }
    one:
        hs[ix2].flag.results &= 0x111;
        hs[ix].flag.results &= 0x1011;
        return;
    two:
        hs[ix2].flag.results &= 0x1011;
        hs[ix].flag.results &= 0x111;
    }
    as->wu.hit_adrs = (u32*)ds;
    ds->wu.dmg_adrs = (u32*)as;
    as->wu.hit_work_id = ds->wu.work_id;
    ds->wu.dmg_work_id = as->wu.work_id;
    ds->dm_point = 1;
    gddir = get_guard_direction(&as->wu, &ds->wu);
    setup_saishin_lvdir(ds, gddir);
    setup_dm_rl(&as->wu, &ds->wu);
    set_catch_hit_mark_pos(&as->wu, &ds->wu);
    set_damage_and_piyo(as, ds);
    ds->wu.dm_guard_success = -1;
    if (ds->guard_flag == 3 || as->wu.att.guard == 0 || ds->py->flag != 0) {
        if (ds->wu.xyz[1].disp.pos > 0) {
            goto three;
        }
        goto four;
    } else if (ds->wu.xyz[1].disp.pos > 0) {
        switch (defense_sky(as, ds, gddir)) {
        case 0:
            goto blocking;
        case 1:
            goto guard;
        default:
            break;
        }
    three:
        as->wu.hf.hit.player = 2;
        ds->wu.routine_no[2] = as->wu.att.reaction;
        goto react;
    } else {
        switch (defense_ground(as, ds, gddir)) {
        case 0:
            goto blocking;
        case 1:
            goto guard;
        }
    four:
        as->wu.hf.hit.player = 1;
        ds->wu.routine_no[2] = as->wu.att.reaction;
    }
react:
    switch ((ds->wu.routine_no[1] == PLAYER_DAMAGE && ds->wu.cg_type == 10) + (((as->wu.rl_flag + ds->wu.rl_flag) & 1) * 2)) {
    case 0:
    case 3:
        as->wu.routine_no[1] = as->wu.cmcr.koc;
        as->wu.routine_no[2] = as->wu.cmcr.ix;
        as->wu.char_index = as->wu.cmcr.pat;
        break;
    default:
        as->wu.routine_no[1] = as->wu.cmcf.koc;
        as->wu.routine_no[2] = as->wu.cmcf.ix;
        as->wu.char_index = as->wu.cmcf.pat;
        break;
    }
    as->wu.routine_no[3] = RN3_START;
    if (ds->guard_flag == 3) {
        ds->hazusenai_flag = 1;
    }
    as->tsukami_num = ds->player_number;
    as->tsukami_f = 1;
    ds->tsukamare_f = 1;
    ds->wu.routine_no[1] = PLAYER_CAUGHT;
    ds->wu.routine_no[2] = as->wu.att.ng_type;
    ds->wu.routine_no[3] = RN3_START;
    if (as->wu.att.ng_type == 2) {
        ds->wu.xyz[1].disp.pos = as->wu.xyz[1].disp.pos;
    }
    effect_02_init(&as->wu, ds->dm_point, 1, ds->wu.dm_rl);
    dm_status_copy(&as->wu, &ds->wu);
    ds->wu.dm_vital = 0;
    as->wu.hit_stop = ds->wu.dm_stop = 0;
    as->wu.cmwk[8]++;
    as->wu.cmwk[0xF]++;
    ds->wu.dm_count_up++;
    hit_pattern_extdat_check(&as->wu);
    paring_ctr_vs[Play_Type][ds->wu.id] = 0;
    paring_counter[ds->wu.id] = 0;
    paring_bonus_r[ds->wu.id] = 0;
    return;
guard:
    set_guard_status(as, ds);
    return;
blocking:
    set_paring_status(as, ds);
}


void setup_catch_atthit(WORK* as, WORK* ds) {
    set_damage_and_piyo((PLW*)as, (PLW*)ds);
    dm_status_copy(as, ds);
    as->hit_stop = ds->dm_stop = 0;
}


void set_catch_hit_mark_pos(WORK* as, WORK* ds) {
    if (as->att.mkh_ix) {
        if (as->rl_flag) {
            as->hit_mark_x = as->xyz[0].disp.pos - hit_mark_hosei_table[as->att.mkh_ix][MARK_HOSEI_X];
        } else {
            as->hit_mark_x = as->xyz[0].disp.pos + hit_mark_hosei_table[as->att.mkh_ix][MARK_HOSEI_X];
        }
        as->hit_mark_y = as->xyz[1].disp.pos + hit_mark_hosei_table[as->att.mkh_ix][MARK_HOSEI_Y];
    } else {
        cal_hit_mark_position(ds, as, (const s16*)ds->h_cau, (const s16*)as->h_cat);
    }
}


void set_struck_status(ix)
s16 ix;
{
    WORK* as;
    WORK* ds;
    s16 ix2;
    ix2 = hs[ix].dm_me;
wait_hit:
    if (ix != hs[ix2].my_hit) {
        goto wait_hit;
    }
    as = q_hit_push[ix2];
    ds = q_hit_push[ix];
    as->hit_adrs = (u32*)ds;
    ds->dmg_adrs = (u32*)as;
    as->hit_work_id = ds->work_id;
    ds->dmg_work_id = as->work_id;
    switch ((as->work_id == 1) + ((ds->work_id == 1) * 2)) {
    case 3:
        player_at_vs_player_dm(ix2, ix);
        break;
    case 2:
        if (hs[ix].flag.results & 0x10) {
            if (hs[ix].my_hit == ix2) {
                break;
            }
        }
        effect_at_vs_player_dm(ix2, ix);
        break;
    case 1:
        player_at_vs_effect_dm(ix2, ix);
        break;
    default:
        effect_at_vs_effect_dm(ix2, ix);
        break;
    }
}


void cal_hit_mark_pos(as, ds, ix2, ix)
WORK* as;
WORK* ds;
s16 ix2;
s16 ix;
{
    if (as->att.mkh_ix) {
        if (as->rl_flag) {
            as->hit_mark_x = as->xyz[0].disp.pos - hit_mark_hosei_table[as->att.mkh_ix][MARK_HOSEI_X];
        } else {
            as->hit_mark_x = as->xyz[0].disp.pos + hit_mark_hosei_table[as->att.mkh_ix][MARK_HOSEI_X];
        }
        as->hit_mark_y = as->xyz[1].disp.pos + hit_mark_hosei_table[as->att.mkh_ix][MARK_HOSEI_Y];
    } else {
        cal_hit_mark_position(ds, as, hs[ix].dh, hs[ix2].ah);
    }
    as->hit_mark_z = as->position_z - 8;
}


void plef_at_vs_player_damage_union(as, ds, gddir)
PLW* as;
PLW* ds;
char gddir;
{
    s32 lim = 6;
    ds->wu.dm_guard_success = -1;
    if (ds->guard_flag == 3 || as->wu.att.guard == 0 || ds->py->flag != 0) {
        if (ds->wu.pat_status == 10) {
            ds->wu.xyz[1].cal = 0;
            goto switch_defense_ground;
        } else if (ds->wu.pat_status == 12 && ds->wu.xyz[1].disp.pos < lim) {
            ds->wu.xyz[1].cal = 0;
            goto switch_defense_ground;
        }
        if (ds->wu.routine_no[1] == PLAYER_DAMAGE) {
            if (ds->wu.xyz[1].disp.pos > 0) {
                goto jump_one;
            } else {
                goto jump_two;
            }
        }
    }
    if (ds->wu.xyz[1].disp.pos > 0) {
        switch (defense_sky(as, ds, gddir)) {
        case 0:
            goto parried;
        case 1:
            goto set_guard_status;
        }
    jump_one:
        as->wu.hf.hit.player = 2;
        dm_reaction_init_set(as, ds);
        if (as->wu.att.at_free4 & 0x40) {
            ds->wu.routine_no[2] = get_sky_sp_damage(ds->wu.routine_no[2]);
        } else {
            if (ds->dm_point > lim) {
                ds->wu.routine_no[2] = get_sky_nm2_damage(ds->wu.routine_no[2]);
            }
            ds->wu.routine_no[2] = get_sky_nm_damage(ds->wu.routine_no[2]);
        }
    } else {
    switch_defense_ground:
        switch (defense_ground(as, ds, gddir)) {
        case 0:
            goto parried;
        case 1:
            goto set_guard_status;
        default:
            break;
        }
    jump_two:
        as->wu.hf.hit.player = 1;
        dm_reaction_init_set(as, ds);
        if (as->wu.zu_flag == 0) {
            if (ds->wu.pat_status >= 32) {
                if (ds->dm_point > lim && ds->player_number == PL_NECRO) {
                    ds->wu.routine_no[2] = get_kagami2_damage(ds->wu.routine_no[2]);
                }
                ds->wu.routine_no[2] = get_kagami_damage(ds->wu.routine_no[2]);
            } else {
                switch (ds->dm_point) {
                case 0:
                case 1:
                case 5:
                case 6:
                    if (check_head_damage(ds->wu.routine_no[2])) {
                        ds->wu.routine_no[2] = get_kind_of_head_dm(as->wu.dir_atthit, ds->wu.dm_rl);
                    }
                    break;
                case 7:
                case 8:
                    if (ds->player_number == PL_NECRO) {
                        ds->wu.routine_no[2] = get_grd_hand_damage(ds->wu.routine_no[2]);
                    }
                    /* fall through */
                default:
                    if (check_trunk_damage(ds->wu.routine_no[2])) {
                        ds->wu.routine_no[2] = get_kind_of_trunk_dm(as->wu.dir_atthit, ds->wu.dm_rl);
                    }
                    break;
                }
            }
        }
    }
    ds->wu.routine_no[1] = PLAYER_DAMAGE;
    ds->wu.routine_no[3] = RN3_START;
    if (DEBUG_DISP) {
        tilemap_print_hex(2, 2, 2, gddir, 4, 0);
    }
    effect_02_init(&as->wu, ds->dm_point, 1, ds->wu.dm_rl);
    dm_status_copy(&as->wu, &ds->wu);
    same_dm_stop(&as->wu, &ds->wu);
    as->wu.cmwk[8]++;
    as->wu.cmwk[15]++;
    ds->wu.dm_count_up++;
    if (ds->wu.xyz[1].disp.pos < 0) {
        ds->wu.xyz[1].cal = 0;
    }
    add_combo_work(as, ds);
    hit_pattern_extdat_check(&as->wu);
    if (ds->atemi_flag && ds->atemi_point != ds->dm_point) {
        ds->atemi_flag = 0;
    }
    paring_ctr_vs[Play_Type][ds->wu.id] = 0;
    paring_counter[ds->wu.id] = 0;
    paring_bonus_r[ds->wu.id] = 0;
    return;
set_guard_status:
    set_guard_status(as, ds);
    return;
parried:
    set_paring_status(as, ds);
}


void dm_reaction_init_set(PLW* as, PLW* ds) {
    ds->wu.routine_no[2] = as->wu.att.reaction;
    if (ds->wu.routine_no[2] == 89 || ds->wu.routine_no[2] == 90) {
        if (ds->running_f == 1) {
            if (Dsas_dir_table[as->wu.att.dir]) {
                if (check_work_position(&as->wu, &ds->wu)) {
                    if (ds->move_distance > 0) {
                        ds->wu.routine_no[2] = 99;
                    }
                } else if (ds->move_distance < 0) {
                    ds->wu.routine_no[2] = 99;
                }
            }
        }
    }
    ds->wu.routine_no[2] = change_damage_attribute(as, as->wu.at_attribute, ds->wu.routine_no[2]);
}


void set_guard_status(PLW* as, PLW* ds) {
    if (as->wu.att.hs_you == 0 && as->wu.att.hs_me == 0) {
        ds->wu.routine_no[2] = ds->wu.old_rno[2];
    } else {
        ds->wu.routine_no[1] = PLAYER_DAMAGE;
        ds->wu.routine_no[3] = RN3_START;
        effect_02_init(&as->wu, ds->dm_point, 2, ds->wu.dm_rl);
        dm_status_copy(&as->wu, &ds->wu);
        same_dm_stop(&as->wu, &ds->wu);
        if (ds->wu.xyz[1].disp.pos < 0) {
            ds->wu.xyz[1].cal = 0;
        }
        ds->wu.dm_piyo = 0;
        as->wu.cmwk[8]++;
        add_sp_arts_gauge_guard(as);
        ds->wu.dm_arts_point = 0;
    }
    hit_pattern_extdat_check(&as->wu);
}


/* provisional name */
#define PARING_PLAYER_ID(row, player, hsadix, player_copy) \
    (((row) ? (player) : ((hsadix) & 1)) | ((player_copy) != 0))

void set_paring_status(PLW* as, PLW* defender) {
    PLW* ds = defender;
    u8 (*row)[2];
    u8 (*row_copy)[2];
    s32 player;
    s32 player_copy;
    if ((as->wu.att.hs_you == 0) && (as->wu.att.hs_me == 0)) {
        ds->wu.routine_no[2] = ds->wu.old_rno[2];
    } else {
        ds->wu.routine_no[1] = PLAYER_NORMAL;
        ds->wu.routine_no[3] = RN3_START;
        waza_compel_all_init2(ds);
        dm_status_copy(&as->wu, &ds->wu);
        ds->wu.dm_vital = 0;
        ds->wu.dm_piyo = 0;
        ds->wu.cg_type = 0;
        switch ((ds->wu.routine_no[2] - 31) * 2 + (as->wu.xyz[1].disp.pos > 0)) {
        case 0:
        case 2:
        case 4:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 22;
            as->wu.hit_quake = 22;
            break;
        case 1:
        case 3:
        case 5:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 14;
            as->wu.hit_quake = 14;
            break;
        case 6:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 18;
            as->wu.hit_quake = 18;
            break;
        case 7:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;
        case 8:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 18;
            as->wu.hit_quake = 18;
            break;
        case 9:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;
        default:
            ds->wu.dm_stop = 0;
            as->wu.hit_stop = 0;
            as->wu.hit_quake = 0;
            break;
        }
        ds->wu.dm_quake = 0;
        if (ds->wu.xyz[1].disp.pos < 0) {
            ds->wu.xyz[1].cal = 0;
        }
        ds->wu.dm_arts_point = 0;
        if (as->wu.xyz[1].disp.pos > 0 && as->wu.work_id == 1 && sel_sp_ch_tbl[as->wu.kind_of_waza >> 3] == 0) {
            remake_mvxy_PoGR(&as->wu);
        }
        if (Bonus_Game_Flag == 0) {
            paring_bonus_r[ds->wu.id] = 1;
            paring_ctr_vs[Play_Type][ds->wu.id]++;
            if (paring_ctr_vs[Play_Type][ds->wu.id] > 39) {
                row = &paring_ctr_vs[Play_Type];
                row_copy = row;
                (*row_copy)[ds->wu.id] = 39;
                player = 0;
                player_copy = player;
                (void)plw[(row ? player : 1) | (player_copy != 0)].wu.id;
            }
            paring_counter[ds->wu.id] = parisucc_pts[Play_Type][paring_ctr_vs[Play_Type][ds->wu.id] - 1];
        }
        as->wu.cmwk[8]++;
    }
    hit_pattern_extdat_check(&as->wu);
}

#undef PARING_PLAYER_ID


void hit_pattern_extdat_check(WORK* as) {
    switch ((as->cg_extdat & 0xC0) + ((as->cg_extdat & 0x3F) != 0)) {
    case 0x80:
        char_move_z(as);
        break;
    case 0x40:
        as->cg_ctr = 1;
        break;
    case 0x81:
        setup_comm_abbak(as);
        as->cg_ix = ((as->cg_extdat & 0x3F) - 1) * as->cgd_type - as->cgd_type;
        as->cg_next_ix = 0;
        char_move_z(as);
        break;
    case 0x41:
        as->cg_ctr = 1;
        /* fall through */
    case 0x1:
        setup_comm_abbak(as);
        as->cg_ix = ((as->cg_extdat & 0x3F) - 1) * as->cgd_type - as->cgd_type;
        as->cg_next_ix = 0;
        break;
    }
}


s32 check_dm_att_guard(WORK* as, WORK* ds) {
    s16 rnum;
    rnum = 0;
    if (as->att.at_free4 & 0x1F) {
        if (ds->dm_vital != 0) {
            ds->dm_vital = ds->dm_vital / (as->att.at_free4 & 0x1F);
            if (ds->dm_vital == 0) {
                ds->dm_vital = 1;
            }
            if (ds->dm_vital > ds->vital_new) {
                ds->dm_guard_success = ds->routine_no[2];
                rnum = 1;
            }
        }
    } else {
        ds->dm_vital = 0;
    }
    return rnum;
}


void set_damage_and_piyo(PLW* as, PLW* ds) {
    cal_damage_vitality(as, ds);
    ds->wu.dm_piyo = add_piyo_gauge[as->player_number][as->wu.att.piyo];
    if (ds->wu.pat_status == 32) {
        ds->wu.dm_vital = ds->wu.dm_vital * 125 / 100;
    } else if (ds->wu.pat_status == 1 || ds->wu.pat_status == 21 || ds->wu.pat_status == 37) {
        ds->wu.dm_vital *= 2;
    }
    if (ds->wu.dm_vital) {
        if (as->wu.routine_no[1] == PLAYER_CATCH) {
            ds->wu.dm_vital = ds->wu.dm_vital * (as->tk_nage + 32) / 32;
            if ((as->tk_nage -= 2) < 0) {
                as->tk_nage = 0;
            }
        }
        if (as->wu.routine_no[1] == PLAYER_ATTACK) {
            ds->wu.dm_vital = ds->wu.dm_vital * (as->tk_dageki + 32) / 32;
            if ((as->tk_dageki -= 2) < 0) {
                as->tk_dageki = 0;
            }
        }
        ds->utk_nage = as->tk_nage;
        ds->utk_dageki = as->tk_dageki;
    }
    if (ds->wu.dm_piyo) {
        ds->wu.dm_piyo = ds->wu.dm_piyo * (as->tk_kizetsu + 32) / 32;
        if ((as->tk_kizetsu -= 2) < 0) {
            as->tk_kizetsu = 0;
        }
        ds->utk_kizetsu = as->tk_kizetsu;
    }
    as->wu.at_ten_ix = remake_score_index(ds->wu.dm_vital);
    cal_combo_waribiki(as, ds);
    cal_dm_vital_gauge_hosei(ds);
    cal_combo_waribiki2(ds);
    if (as->wu.work_id != 1) {
        return;
    }
    switch (as->dm_vital_use) {
    case 1:
        ds->wu.dm_vital += as->dm_vital_backup;
        as->dm_vital_backup = 0;
        break;
    case 2:
        as->dm_vital_backup /= 2;
        ds->wu.dm_vital += as->dm_vital_backup;
        break;
    }
}


s16 remake_score_index(s16 dmv) {
    s16 i;
    for (i = 0; i < 16; i++) {
        if (dmv < rsix_r_table[i][0]) {
            break;
        }
    }
    return rsix_r_table[i][1];
}


void same_dm_stop(WORK* as, WORK* ds) {
    if (as->work_id == 1 && as->att.dipsw & 1 && (ds->xyz[1].disp.pos > 0 || (ds->vital_new - ds->dm_vital) <= -3)) {
        switch ((ds->dm_stop < 0) + ((as->att.hs_me < 0) * 2)) {
        case 1:
            ds->dm_stop = -as->att.hs_me;
            /* fall through */
        case 2:
            ds->dm_stop = -as->att.hs_me;
            break;
        default:
            ds->dm_stop = as->att.hs_me;
            break;
        }
    }
}


s32 defense_sky(as, ds, gddir)
PLW* as;
PLW* ds;
char gddir;
{
    s32 gc;
    if (ds->py->flag == 0 && !(ds->guard_flag & 2) && as->wu.att.guard & 4) {
        gc = ds->guard_chuu;
        if (gc && gc < 5) {
            goto guard;
        }
        if (!(ds->spmv_ng_flag & 0x400)) {
            if (ds->cp->waza_flag[5] != 0) {
                as->wu.hf.hit.player = 0x80;
                ds->wu.routine_no[2] = 34;
                return 0;
            }
        }
        if (!(ds->spmv_ng_flag & 0x800)) {
            if (ds->cp->waza_flag[6] != 0) {
                as->wu.hf.hit.player = 0x80;
                ds->wu.routine_no[2] = 35;
                return 0;
            }
        }
    }
guard:
    if (!(as->wu.att.guard & 0x20)) {
        return 2;
    }
    if (ds->guard_flag & 1) {
        goto miss;
    } else {
        if (ds->spmv_ng_flag & 0x20) {
            goto miss;
        } else {
            if (ds->saishin_lvdir & gddir) {
                as->wu.hf.hit.player = 0x20;
                ds->wu.routine_no[2] = 7;
                if (check_dm_att_guard(&as->wu, &ds->wu)) {
                    return 2;
                }
                return 1;
            }
        }
    }
miss:
    return 2;
}


s32 defense_ground(as, ds, gddir)
PLW* as;
PLW* ds;
char gddir;
{
    s32 gc;
    if (ds->py->flag == 0 && !(ds->guard_flag & 2) && as->wu.att.guard & 3) {
        gc = ds->guard_chuu;
        if (gc && gc < 5) {
            goto guard;
        }
        if (as->wu.att.guard & 2) {
            if (!(ds->spmv_ng_flag & 0x100)) {
                if (as->wu.xyz[1].disp.pos > 1 && as->wu.work_id == 1) {
                    if (ds->cp->waza_flag[12] != 0) {
                        as->wu.hf.hit.player = 64;
                        if (check_attbox_dir(ds) == 0) {
                            ds->wu.routine_no[2] = 31;
                        } else {
                            ds->wu.routine_no[2] = 32;
                        }
                        return 0;
                    }
                } else if (ds->cp->waza_flag[3] != 0) {
                    as->wu.hf.hit.player = 64;
                    if (check_attbox_dir(ds) == 0) {
                        ds->wu.routine_no[2] = 31;
                    } else {
                        ds->wu.routine_no[2] = 32;
                    }
                    return 0;
                }
            }
        }
        if (as->wu.att.guard & 1) {
            if (!(ds->spmv_ng_flag & 0x200)) {
                if (ds->cp->waza_flag[4] != 0) {
                    as->wu.hf.hit.player = 64;
                    ds->wu.routine_no[2] = 33;
                    return 0;
                }
            }
        }
    }
guard:
    if (!(as->wu.att.guard & 0x18)) {
        return 2;
    }
    if (ds->guard_flag & 1) {
        return 2;
    }
    if (ds->spmv_ng_flag & 0x10) {
        return 2;
    }
    if (ds->auto_guard) {
    } else {
        if (!(ds->saishin_lvdir & gddir)) {
            return 2;
        }
    }
    switch (as->wu.att.guard & 0x18) {
    case 8:
        if (!(ds->cp->sw_lvbt & LEVER_DOWN)) {
            return 2;
        }
        ds->wu.routine_no[2] = 6;
        break;
    case 16:
        if (ds->cp->sw_lvbt & LEVER_DOWN) {
            return 2;
        }
        ds->wu.routine_no[2] = 5;
        break;
    default:
        if (ds->cp->sw_lvbt & LEVER_DOWN) {
            ds->wu.routine_no[2] = 6;
        } else {
            ds->wu.routine_no[2] = 5;
        }
        break;
    }
    as->wu.hf.hit.player = 16;
    if (ds->wu.routine_no[2] == 5 && check_attbox_dir(ds) == 0) {
        ds->wu.routine_no[2] = 4;
    }
    if (check_dm_att_guard(&as->wu, &ds->wu)) {
        return 2;
    }
    return 1;
}


void setup_dm_rl(WORK* as, WORK* ds) {
    s16 dx;
    if (as->work_id != 1 || check_ttk_damage_request(as->att.reaction) != 0) {
        ds->dm_rl = as->rl_flag;
        return;
    }
    dx = ds->xyz[0].disp.pos - as->xyz[0].disp.pos;
    switch ((ds->xyz[1].disp.pos > 0) + (as->xyz[1].disp.pos > 0) * 2) {
    case 0:
    case 2:
        if (!(as->att.at_free4 & 0xC0)) {
            ds->dm_rl = as->rl_flag;
            break;
        }
        /* fall through */
    default:
        if (dx) {
            if (dx > 0) {
                ds->dm_rl = 1;
            } else {
                ds->dm_rl = 0;
            }
        } else {
            ds->dm_rl = as->rl_flag;
        }
    }
}


void dm_status_copy(WORK* as, WORK* ds) {
    ds->dm_fushin = as->att.at_free4 & 0x20;
    ds->dm_attlv = as->kezuri_pow;
    ds->dm_impact = as->att.impact;
    ds->dm_dir = as->dir_atthit;
    ds->dm_stop = as->att.hs_you;
    ds->dm_quake = as->att.hs_you;
    if (ds->dm_quake < 0) {
        ds->dm_quake = -ds->dm_quake;
    }
    ds->dm_weight = as->weight_level;
    ds->dm_butt_type = as->buttobi_type;
    ds->dm_zuru = as->att_zuru;
    ds->dm_attribute = as->at_attribute;
    ds->dm_ten_ix = as->at_ten_ix;
    ds->dm_koa = as->at_koa;
    ds->hm_dm_side = as->att.dmg_mark;
    ds->dm_work_id = as->work_id;
    as->hit_stop = as->att.hs_me;
    ds->dm_arts_point = as->add_arts_point;
    ds->dm_kind_of_waza = as->kind_of_waza;
    ds->dm_nodeathattack = as->no_death_attack;
    if (as->work_id == 1) {
        ds->dm_exdm_ix = ((PLW*)as)->exdm_ix;
        ds->dm_plnum = ((PLW*)as)->player_number;
    } else {
        ds->dm_plnum = ((PLW*)((WORK_Other*)as)->my_master)->player_number;
    }
    ds->dm_jump_att_flag = as->xyz[1].disp.pos;
    as->meoshi_hit_flag = 1;
}


void add_combo_work(PLW* as, PLW* ds) {
    s16* hit_cnt;
    s16* kind_cnt;
    if (ds->kezurijini_flag) {
        return;
    }
    ds->kizetsu_kow = ds->cb->new_dm = as->wu.kind_of_waza;
    kind_cnt = &ds->cb->kind_of[0][0][0];
    hit_cnt = calc_hit[ds->wu.id];
    kind_cnt[as->wu.kind_of_waza]++;
    hit_cnt[(as->wu.kind_of_waza & 0x78) / 8]++;
    ds->cb->total++;
    kind_cnt = &ds->rp->kind_of[0][0][0];
    kind_cnt[as->wu.kind_of_waza]++;
    ds->rp->total++;
}


void nise_combo_work(PLW* as, PLW* ds, s16 num) {
    s16* kow;
    s16* cal;
    s16 i;
    for (i = 0; i < num; i++) {
        ds->kizetsu_kow = ds->cb->new_dm = as->wu.kind_of_waza;
        kow = &ds->cb->kind_of[0][0][0];
        cal = &calc_hit[ds->wu.id][0];
        kow[as->wu.kind_of_waza]++;
        cal[(as->wu.kind_of_waza & 0x78) / 8]++;
        ds->cb->total++;
        kow = &ds->rp->kind_of[0][0][0];
        kow[as->wu.kind_of_waza]++;
        ds->rp->total++;
    }
}


void cal_combo_waribiki(PLW* as, PLW* ds) {
    const POWER* power;
    const KOATT* koatt;
    s16 i;
    s16 j;
    s16 k;
    TBL tbl;
    if (ds->wu.dm_vital == 0) {
        return;
    }
    if (ds->rp->total == 0) {
        return;
    }
    koatt = exchange_koa[as->wu.kind_of_waza >> 1];
    tbl.ixl = 0;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            k = ds->rp->kind_of[i][j][0];
            k += ds->rp->kind_of[i][j][1];
            if (k) {
                tbl.ixl += koatt->step[i][j] * k * 256;
            }
        }
    }
    if (tbl.ixs.l) {
        tbl.ixs.h++;
    }
    power = exchange_pow[as->wu.kind_of_waza >> 1];
    if (as->player_number == PL_YUN || as->player_number == PL_YANG) {
        if (as->sa->kind_of_arts == 2 && as->sa->ok == -1) {
            power = exchange_pow_pl03_sa3[as->wu.kind_of_waza >> 1];
        }
    }
    if (tbl.ixs.h > 31) {
        tbl.ixs.h = 31;
    }
    ds->wu.dm_vital *= power[0].data[tbl.ixs.h];
    ds->wu.dm_vital >>= 5;
    if (ds->wu.dm_vital <= 0) {
        ds->wu.dm_vital = 1;
    }
}


void cal_combo_waribiki2(PLW* ds) {
    s16 num;
    if (ds->wu.dm_piyo == 0) {
        return;
    }
    if (ds->cb->total == 0) {
        return;
    }
    num = 32 - ds->cb->total * 2;
    if (num <= 0) {
        num = 1;
    }
    ds->wu.dm_piyo = ds->wu.dm_piyo * num / 32;
    if (ds->wu.dm_piyo == 0) {
        ds->wu.dm_piyo = 1;
    }
}


void catch_hit_check(void) {
    WORK* mad;
    WORK* sad;
    const s16* mh;
    const s16* sh;
    s16 mi;
    s16 si;

    mi = 0;
    goto next_mi;
loop_mi:
    {
        if (hs[mi].flag.results & 0x1000) {
            goto cont_mi;
        }
        mad = q_hit_push[mi];
        if (mad->work_id != 1) {
            goto cont_mi;
        }
        if (mad->att_hit_ok == 0) {
            goto cont_mi;
        }
        if ((mh = (s16*)mad->h_cat)[0] == 0) {
            goto cont_mi;
        }
        si = 0;
        goto next_si;
    loop_si:
            if (si == mi) {
                goto cont_si;
            }
            if (hs[si].flag.results & 0x100) {
                goto cont_si;
            }
            sad = q_hit_push[si];
            if (sad->work_id != 1) {
                goto cont_si;
            }
            if ((sh = (s16*)sad->h_cau)[0] == 0) {
                goto cont_si;
            }
            if (mad->att.guard & 0x18) {
                goto hit;
            }
            if (((PLW*)sad)->tsukamarenai_flag) {
                goto cont_si;
            }
            if (!(mad->att.at_free4 & 0xC0)) {
                if ((sad->routine_no[1] == PLAYER_DAMAGE) && (sad->routine_no[3] != RN3_START)) {
                    if (sad->routine_no[2] != DAMAGE_STUN) {
                        goto cont_si;
                    }
                }
            } else {
                if (!((sad->routine_no[1] == PLAYER_DAMAGE) && (sad->routine_no[3] != RN3_START) && (sad->cg_type != 10))) {
                    goto hit;
                }
                if (!dm_oiuchi_catch[sad->routine_no[2]]) {
                    goto cont_si;
                }
            }
        hit:
            if (hit_check_subroutine(mad, sad, mh, sh)) {
                hs[mi].flag.results |= 0x1000;
                hs[mi].my_hit = (u16)si;
                hs[si].flag.results |= 0x100;
                hs[si].dm_me = (u16)mi;
                mad->att_hit_ok = 0;
                hs[mi].ah = mh;
                hs[si].dh = sh;
                mad->att_hit_ok = 0;
            } else {
                goto cont_si;
            }
            goto cont_mi;
    cont_si:
        si++;
    next_si:
        if (si < hpq_in) {
            goto loop_si;
        }
    }
cont_mi:
    mi++;
next_mi:
    if (mi < hpq_in) {
        goto loop_mi;
    }
}


void attack_hit_check(void) {
    WORK* mad;
    WORK* sad;
    const s16* sh;
    s16* ah;
    s16 mi;
    s16 si;
    s16 lp;
    s16 lp2;
    s16 mw;
    si = 0;
    goto test1;
    loop1:
    {
        if (hs[si].flag.results & 0x1101) {
            goto next1;
        }
        sad = q_hit_push[si];
        sh = sad->h_bod->body_dm[0];
        lp = 0;
        goto test2;
        loop2:
        {
            dmdat_adrs[lp] = sh;
            sh += 4;
        }
        lp++;
        test2:
        if (lp >= 4) {
            goto body_end;
        }
        goto loop2;
    body_end:
        dmdat_adrs[4] = (const s16*)sad->h_hos;
        sh = (s16*)sad->h_att;
        lp = 0;
        goto test3;
        loop3:
        {
            dmdat_adrs[lp + 5] = sh;
            sh += 4;
        }
        lp++;
        test3:
        if (lp < 2) {
            goto loop3;
        }
        sh = (s16*)sad->h_han;
        lp = 0;
        goto test4;
        loop4:
        {
            dmdat_adrs[lp + 7] = sh;
            sh += 4;
        }
        lp++;
        test4:
        if (lp >= 2) {
            goto hand_end;
        }
        goto loop4;
    hand_end:
        mi = 0;
        goto test5;
        loop5:
        {
            if (mi == si) {
                goto next5;
            }
            if (hs[mi].flag.results & 0x1110) {
                goto next5;
            }
            mad = q_hit_push[mi];
            if (mad->att_hit_ok == 0) {
                goto next5;
            }
            if (!(mad->att.dipsw & 2) || (!(sad->att.dipsw & 2) && (sad->work_id == 1 || !(((WORK_Other*)sad)->refrected)))) {
                if ((mad->work_id == 1 || mad->work_id == 8) && (sad->att.dipsw & 2)) {
                    goto owner_check;
                }
                if (!(mad->vs_id & sad->work_id)) {
                    goto next5;
                }
            }
        owner_check:
            if (mad->work_id != 1) {
                if (sad->work_id == 1) {
                    if (((WORK_Other*)mad)->master_id == sad->id) {
                        goto next5;
                    }
                } else if (((WORK_Other*)mad)->master_id == ((WORK_Other*)sad)->master_id) {
                    goto next5;
                }
            } else if ((sad->work_id != 1 && ((WORK_Other*)sad)->refrected == 0) && (mad->id == ((WORK_Other*)sad)->master_id)) {
                goto next5;
            }
            if ((ah = (s16*)mad->h_eat)[0] != 0) {
                lp = 0;
                goto test6;
                loop6:
                {
                    if (ah[0] == 0) {
                        goto next6;
                    }
                    lp2 = 0;
                    goto test7;
                    loop7:
                    {
                        if (dmdat_adrs[lp2][0] == 0) {
                            goto next7;
                        }
                        if (lp2 > 6) {
                            if (mad->att_hit_ok == 0) {
                                goto next7;
                            }
                            if (mad->att.dipsw & 4) {
                                goto next7;
                            }
                            if (!((mad->rl_flag + sad->rl_flag) & 1)) {
                                if (mad->rl_flag) {
                                    if (mad->xyz[0].disp.pos > sad->xyz[0].disp.pos) {
                                        goto next7;
                                    }
                                } else if (mad->xyz[0].disp.pos < sad->xyz[0].disp.pos) {
                                    goto next7;
                                }
                            }
                        }
                        if (lp2 == 4) {
                            if (!(mad->att.at_free4 & 0x80)) {
                                goto next7;
                            }
                            if (hs[mi].flag.results & 0x10) {
                                goto next7;
                            }
                            if (sad->kind_of_waza & 0x20) {
                                goto next7;
                            }
                            if (pcon_dp_flag) {
                                goto next7;
                            }
                            if (sad->pat_status == 38) {
                                goto next7;
                            }
                        }
                        mw = hit_check_subroutine(mad, sad, ah, dmdat_adrs[lp2]);
                        if (mw > mkm_wk[si]) {
                            hs[mi].flag.results |= 0x10;
                            hs[mi].my_hit = si;
                            hs[mi].my_att = lp;
                            hs[si].flag.results |= 1;
                            hs[si].dm_me = mi;
                            hs[si].dm_body = lp2;
                            mad->att_hit_ok = 0;
                            mkm_wk[si] = mw;
                            hs[mi].ah = ah;
                            hs[si].dh = dmdat_adrs[lp2];
                        }
                    }
                    next7:
                        lp2++;
                    test7:
                    if (lp2 < 9) {
                        goto loop7;
                    } else if (mad->att_hit_ok == 0) {
                        goto next1;
                    }
                }
                next6:
                    lp++;
                    ah += 4;
                test6:
                if (lp >= 2) {
                    goto eat_end;
                }
                goto loop6;
            eat_end:
                if (mad->att_hit_ok == 0) {
                    goto next1;
                }
            }
            if ((ah = (s16*)mad->h_att)[0] == 0) {
                goto next5;
            }
            lp = 0;
            goto test8;
            loop8:
            {
                if (ah[0] == 0) {
                    goto next8;
                }
                lp2 = 0;
                goto test9;
                loop9:
                {
                    if (dmdat_adrs[lp2][0] == 0) {
                        goto next9;
                    }
                    if (lp2 > 6) {
                        if (mad->att_hit_ok == 0) {
                            goto next9;
                        }
                        if (mad->att.dipsw & 4) {
                            goto next9;
                        }
                        if (!((mad->rl_flag + sad->rl_flag) & 1)) {
                            if (mad->rl_flag) {
                                if (mad->xyz[0].disp.pos > sad->xyz[0].disp.pos) {
                                    goto next9;
                                }
                            } else if (mad->xyz[0].disp.pos < sad->xyz[0].disp.pos) {
                                goto next9;
                            }
                        }
                    }
                    if (lp2 == 5 || lp2 == 6) {
                        goto next9;
                    }
                    if (lp2 == 4) {
                        if (!(mad->att.at_free4 & 0x80)) {
                            goto next9;
                        }
                        if (hs[mi].flag.results & 0x10) {
                            goto next9;
                        }
                        if (sad->kind_of_waza & 0x20) {
                            goto next9;
                        }
                        if (pcon_dp_flag) {
                            goto next9;
                        }
                        if (sad->pat_status == 38) {
                            goto next9;
                        }
                    }
                    mw = hit_check_subroutine(mad, sad, ah, dmdat_adrs[lp2]);
                    if (mw > mkm_wk[si]) {
                        hs[mi].flag.results |= 0x10;
                        hs[mi].my_hit = si;
                        hs[mi].my_att = lp;
                        hs[si].flag.results |= 1;
                        hs[si].dm_me = mi;
                        hs[si].dm_body = lp2;
                        mad->att_hit_ok = 0;
                        mkm_wk[si] = mw;
                        hs[mi].ah = ah;
                        hs[si].dh = dmdat_adrs[lp2];
                    }
                }
                next9:
                    lp2++;
                test9:
                if (lp2 < 9) {
                    goto loop9;
                } else if (mad->att_hit_ok == 0) {
                    goto next1;
                }
            }
            next8:
                lp++;
                ah += 4;
            test8:
            if (lp >= 2) {
                goto att_end;
            }
            goto loop8;
        att_end:
            if (mad->att_hit_ok == 0) {
                goto next1;
            }
        }
        next5:
            mi++;
        test5:
        if (mi < hpq_in) {
            goto loop5;
        }
    }
    next1:
        si++;
    test1:
    if (si < hpq_in) {
        goto loop1;
    }
}


s32 hit_check_subroutine(WORK* wk1, WORK* wk2, const s16* hd1, const s16* hd2) {
    s16 d0;
    s16 d1;
    s16 d2;
    s16 d3;
    s16 flag;
    d0 = *hd1++;
    d1 = *hd1++;
    if (wk1->rl_flag) {
        d0 = -d0;
        d0 -= d1;
    }
    d0 += wk1->xyz[0].disp.pos;
    d2 = *hd2++;
    d3 = *hd2++;
    if (wk2->rl_flag) {
        d2 = -d2;
        d2 -= d3;
    }
    d2 += wk2->xyz[0].disp.pos;
    flag = d0 < d2;
    d2 += d3 - d0;
    d3 += d1;
    if ((u32)d2 >= d3) {
        return 0;
    }
    d0 = wk1->xyz[1].disp.pos + *hd1++ - wk2->xyz[1].disp.pos - *hd2++;
    d0 += d1 = *hd1;
    d1 += *hd2;
    if ((u32)d0 >= d1) {
        return 0;
    }
    if (flag) {
        d2 = d3 - d2;
    }
    return d2;
}


void cal_hit_mark_position(WORK* wk1, WORK* wk2, const s16* hd1, const s16* hd2) {
    s16 d0 = *hd1++;
    s16 d1 = *hd1++;
    s16 d2;
    s16 d3;
    if (wk1->rl_flag) {
        d0 = -d0;
        d0 -= d1;
    }
    d0 += wk1->xyz[0].disp.pos;
    d1 += d0;
    d2 = *hd2++;
    d3 = *hd2++;
    if (wk2->rl_flag) {
        d2 = -d2;
        d2 -= d3;
    }
    d2 += wk2->xyz[0].disp.pos;
    d3 += d2;
    if (d0 < d2) {
        d0 = d2;
    }
    if (d1 > d3) {
        d1 = d3;
    }
    wk2->hit_mark_x = (d0 + d1) >> 1;
    d0 = wk1->xyz[1].disp.pos + *hd1++;
    d1 = *hd1 + d0;
    d2 = wk2->xyz[1].disp.pos + *hd2++;
    d3 = *hd2 + d2;
    if (d0 < d2) {
        d0 = d2;
    }
    if (d1 > d3) {
        d1 = d3;
    }
    wk2->hit_mark_y = (d0 + d1) >> 1;
}


void get_target_att_position(WORK* wk, s16* tx, s16* ty) {
    s16 i;
    const s16* ta;
    *tx = wk->xyz[0].disp.pos;
    *ty = wk->xyz[1].disp.pos;
    ta = wk->h_att->att_box[0];
    for (i = 0; i < 3; ta += 4, i++) {
        if (ta[0]) {
            if (wk->rl_flag) {
                *tx -= ta[0] + (ta[1] / 2);
            } else {
                *tx += ta[0] + (ta[1] / 2);
            }
            *ty += ta[2] + (ta[3] / 2);
            break;
        }
    }
}


void hit_push_request(WORK* hpr_wk) {
    if (hpq_in < 31 && hpr_wk->cg_hit_ix != 0) {
        q_hit_push[hpq_in++] = hpr_wk;
    }
}


void clear_hit_queue(void) {
    s16 i;
    s16* p;
    WORK** q;
    hpq_in = 0;
    p = mkm_wk;
    i = 0;
    do {
        *p = 0;
        i += 2;
        p++;
        *p = 0;
        p++;
    } while (i < 0x20);
    q = q_hit_push;
    i = 0;
    do {
        *q = 0;
        i += 2;
        q++;
        *q = 0;
        q++;
    } while (i < 0x20);
    work_init_zero((s32*)hs, sizeof(hs));
}


/*
 * The damage reaction ix (32 and up) as hit by an attack of attribute atr: 1 flame, 2 thunder,
 * 3 freeze. Gill turned one way (rl_flag set) swaps flame and freeze, and the attack takes the
 * swapped attribute.
 */
s32 change_damage_attribute(as, atr, ix)
PLW* as;
u16 atr;
u16 ix;
{
    switch (atr) {
    case 1:
        if (as->wu.work_id == 1 && as->player_number == PL_GILL && as->wu.rl_flag) {
            ix = attr_freeze_tbl[ix - 32];
            as->wu.at_attribute = 3;
        } else {
            ix = attr_flame_tbl[ix - 32];
        }
        break;
    case 2:
        ix = attr_thunder_tbl[ix - 32];
        break;
    case 3:
        if (as->wu.work_id == 1 && as->player_number == PL_GILL && as->wu.rl_flag) {
            ix = attr_flame_tbl[ix - 32];
            as->wu.at_attribute = 1;
        } else {
            ix = attr_freeze_tbl[ix - 32];
        }
        break;
    }
    return ix;
}


s16 get_sky_nm_damage(u16 ix) {
    ix -= 32;
    return sky_nm_damage_tbl[ix];
}


/* provisional name */
s16 get_sky_nm2_damage(u16 ix) {
    ix -= 32;
    return sky_nm2_damage_tbl[ix];
}


s16 get_sky_sp_damage(u16 ix) {
    ix -= 32;
    return sky_sp_damage_tbl[ix];
}


s16 get_kagami_damage(u16 ix) {
    ix -= 32;
    return kagami_damage_tbl[ix];
}


/* provisional name */
s16 get_kagami2_damage(u16 ix) {
    ix -= 32;
    return kagami2_damage_tbl[ix];
}


s16 get_grd_hand_damage(u16 ix) {
    ix -= 32;
    return grd_hand_damage_tbl[ix];
}


s32 check_head_damage(s16 ix) {
    ix -= 32;
    return hddm_damage_tbl[ix];
}


s32 check_trunk_damage(s16 ix) {
    ix -= 32;
    return trdm_damage_tbl[ix];
}


s32 check_ttk_damage_request(s16 pat) {
    pat -= 32;
    return ttk_damage_req_tbl[pat];
}
