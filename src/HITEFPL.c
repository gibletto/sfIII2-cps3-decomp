/*
 * HITEFPL.C  Effect attack against player
 *
 * effect_at_vs_player_dm is called from HITCHECK when an effect's attack hits a player. It works
 * out guard or damage for the player and applies combo damage reduction (cal_combo_waribiki), the
 * score index, the hit mark position and the damage facing (setup_dm_rl_pldm).
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
#include "PLS02.h"
#include "HITEFPL.h"
#include "HITCHECK.h"



void effect_at_vs_player_dm(ix2, ix)
s16 ix2;
s16 ix;
{
    WORK_Other* as = (WORK_Other*)q_hit_push[ix2];
    PLW* ds = (PLW*)q_hit_push[ix];
    PLW* ms;
    s8 gddir;
    ds->dm_point = hs[ix].dm_body;
    gddir = get_guard_direction(&as->wu, &ds->wu);
    setup_saishin_lvdir(ds, gddir);
    setup_dm_rl_pldm(&as->wu, &ds->wu);
    cal_hit_mark_pos(&as->wu, &ds->wu, ix2, ix);
    cal_damage_vitality_eff(as, ds);
    ds->wu.dm_piyo = add_piyo_gauge[as->master_player][as->wu.att.piyo];
    if (ds->wu.pat_status == 32) {
        ds->wu.dm_vital = (ds->wu.dm_vital * 125) / 100;
    } else if (ds->wu.pat_status == 1 || ds->wu.pat_status == 21 || ds->wu.pat_status == 37) {
        ds->wu.dm_vital *= 2;
    }
    ms = (PLW*)as->my_master;
    if (ms->wu.work_id == 1) {
        if (as->wu.olc_work_ix[3] == 2) {
            ds->wu.dm_vital = ds->wu.dm_vital * (as->wu.olc_work_ix[1] + 32) / 32;
        }
        if (as->wu.olc_work_ix[3] == 4) {
            ds->wu.dm_vital = ds->wu.dm_vital * (as->wu.olc_work_ix[0] + 32) / 32;
        }
        ds->utk_dageki = as->wu.olc_work_ix[0];
        ds->utk_nage = as->wu.olc_work_ix[1];
        ds->wu.dm_piyo = ds->wu.dm_piyo * (as->wu.olc_work_ix[2] + 32) / 32;
        ds->utk_kizetsu = as->wu.olc_work_ix[2];
    }
    as->wu.at_ten_ix = remake_score_index(ds->wu.dm_vital);
    cal_combo_waribiki((PLW*)as, ds);
    cal_dm_vital_gauge_hosei(ds);
    cal_combo_waribiki2(ds);
    as->wu.dm_vital = 256;
    ds->atemi_flag = 0;
    plef_at_vs_player_damage_union((PLW*)as, ds, gddir);
}


void setup_dm_rl_pldm(WORK* as, WORK* ds) {
    s16 pw;
    ds->dm_rl = as->rl_flag;
    if (ds->xyz[1].disp.pos <= 0) {
        return;
    }
    if (!(as->att.dipsw & 2)) {
        return;
    }
    pw = ds->xyz[0].disp.pos - as->xyz[0].disp.pos;
    if (pw) {
        if (pw > 0) {
            ds->dm_rl = 1;
        } else {
            ds->dm_rl = 0;
        }
    } else {
        ds->dm_rl = as->rl_flag;
    }
}
