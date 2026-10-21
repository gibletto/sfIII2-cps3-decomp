/*
 * HITEFEF.C  Effect attack against effect
 *
 * effect_at_vs_effect_dm is called from HITCHECK for a judged hit where both the attacker and the
 * defender are effects (for example two projectiles). It checks the extended hit data
 * (hit_pattern_extdat_check), applies the result to both works and sets the hit mark position.
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
#include "HITCHECK.h"
#include "EFF02.h"
#include "HITEFEF.h"


/* 2i 0608205C, 3s-near: sf3 src/HITEFEF.c:23 effect_at_vs_effect_dm */
void effect_at_vs_effect_dm(ix2, ix)
s16 ix2;
s16 ix;
{
    WORK_Other* as = (WORK_Other*)q_hit_push[ix2];
    WORK_Other* ds = (WORK_Other*)q_hit_push[ix];
    ds->wu.dm_rl = as->wu.rl_flag;
    as->wu.dm_rl = ds->wu.rl_flag;
    cal_hit_mark_pos(&as->wu, &ds->wu, ix2, ix);
    if (ds->wu.att.dipsw & 2) {
        if (as->wu.att.dipsw & 2) {
            ds->wu.dm_vital = 128;
            as->wu.dm_vital = 128;
        } else {
            ds->wu.dm_vital = 128;
            as->wu.dm_vital = 128;
            if (as->wu.waku_work_index == 0) {
                as->dm_refrect = 1;
                as->refrected = 1;
                as->wu.att_hit_ok = 1;
            }
        }
    } else if (ds->wu.id == 13) {
        switch (as->wu.work_id) {
        case 4:
            ds->wu.dm_vital = as->wu.vital_new;
            as->wu.dm_vital = ds->wu.vital_new;
            break;
        }
    } else {
        ds->wu.dm_vital = 256;
    }
    if (ds->wu.xyz[1].disp.pos > 0) {
        as->wu.hf.hit.effect = 2;
    } else {
        as->wu.hf.hit.effect = 1;
    }
    ds->wu.routine_no[1] = 1;
    ds->wu.routine_no[2] = 0;
    as->wu.hit_stop = ds->wu.hit_stop = 6;
    ds->wu.dm_dir = as->wu.dir_atthit;
    ds->wu.dm_kind_of_waza = as->wu.kind_of_waza;
    hit_pattern_extdat_check(&as->wu);
}
