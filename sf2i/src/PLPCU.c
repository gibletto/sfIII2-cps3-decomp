/*
 * PLPCU.C  Player caught (being thrown) process
 *
 * Runs a player who is held by the opponent's throw. Player_caught clears the state flags and
 * dispatches Caught_00000-Caught_03000: the victim follows the thrower's catch rectangle (index,
 * flip, offset, priority) each frame, or moves the thrower relative to itself for the second
 * catch kind. check_tsukamare_keizoku_check decides whether the hold continues.
 * caught_cg_type_check and the scdmd_12000-scdmd_31000 routines set up the damage state the
 * victim is released into (blow-away data, vertical speed from buttobi_time_table).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "CALDIR.h"
#include "EFFA7.h"
#include "effa8.h"
#include "effa9.h"
#include "EFFD9.h"
#include "PLS02.h"
#include "EFFE2.h"
#include "PLPCU.h"

/* 2i 060126C4, 3s-near: sf3 src/PLPCU.c:28 Player_caught */
void Player_caught(PLW* wk) {
    PLW* emwk = (PLW*)wk->wu.dmg_adrs;
    wk->wu.next_z = wk->wu.my_priority;
    wk->running_f = 0;
    wk->guard_flag = 3;
    wk->guard_chuu = 0;
    wk->tsukami_f = 0;
    wk->tsukamare_f = 1;
    wk->scr_pos_set_flag = 0;
    wk->dm_hos_flag = 0;
    wk->zuru_timer = 0;
    wk->zuru_ix_counter = 0;
    wk->sa_stop_flag = 0;
    wk->atemi_flag = 0;
    wk->caution_flag = 0;
    wk->sa->saeff_ok = 0;
    wk->sa->saeff_mp = 0;
    wk->cancel_timer = 0;
    wk->cmd_request = 0;
    if (wk->wu.routine_no[3] == 0) {
        wk->ukemi_ok_timer = wk->backup_ok_timer = emwk->wu.cmyd.koc;
        wk->uot_cd_ok_flag = 0;
        wk->ukemi_success = 0;
        wk->wu.dir_old = 1;
    }
    plpcu_lv_00[wk->wu.routine_no[2]](wk, emwk);
}



/* 2i 06012750, 3s-exact: sf3 src/PLPCU.c:60 Caught_00000 */
void Caught_00000(PLW* wk) {}



/* 2i 06012754, 3s-near: sf3 src/PLPCU.c:64 Caught_01000 */
void Caught_01000(PLW* wk, PLW* emwk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 3, emwk->wu.cmyd.ix);
        emwk->kind_of_catch = 0;
        wk->wu.cmwk[11] = 0;
    case 1:
        if (check_tsukamare_keizoku_check(wk, emwk) != 0) {
            break;
        }
        if (emwk->wu.curr_rca == 0) {
            break;
        }
        if (emwk->wu.curr_rca->catch_nix == wk->wu.dir_old) {
            char_move(&wk->wu);
        } else {
            char_move_index(&wk->wu, emwk->wu.curr_rca->catch_nix);
            wk->wu.dir_old = emwk->wu.curr_rca->catch_nix;
        }
        wk->wu.rl_flag = emwk->wu.rl_flag ^ emwk->wu.curr_rca->catch_flip;
        if (emwk->wu.rl_flag) {
            wk->wu.xyz[0].disp.pos = emwk->wu.xyz[0].disp.pos - emwk->wu.curr_rca->catch_hos_x;
        } else {
            wk->wu.xyz[0].disp.pos = emwk->wu.xyz[0].disp.pos + emwk->wu.curr_rca->catch_hos_x;
        }
        wk->wu.xyz[1].disp.pos = emwk->wu.xyz[1].disp.pos + emwk->wu.curr_rca->catch_hos_y;
        if (emwk->wu.curr_rca->catch_prio == 2) {
            wk->wu.next_z = emwk->wu.next_z - 1;
        } else {
            wk->wu.next_z = emwk->wu.next_z + 1;
        }
        caught_cg_type_check(wk, emwk);
    }
}



/* 2i 06012870, 3s-near: sf3 src/PLPCU.c:102 Caught_02000 */
void Caught_02000(PLW* wk, PLW* emwk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 3, emwk->wu.cmyd.ix);
        emwk->kind_of_catch = 1;
        wk->wu.cmwk[11] = 0;
    case 1:
        if (check_tsukamare_keizoku_check(wk, emwk) != 0) {
            break;
        }
        if (emwk->wu.curr_rca == 0) {
            break;
        }
        if (emwk->wu.curr_rca->catch_nix == wk->wu.dir_old) {
            char_move(&wk->wu);
        } else {
            char_move_index(&wk->wu, emwk->wu.curr_rca->catch_nix);
            wk->wu.dir_old = emwk->wu.curr_rca->catch_nix;
        }
        wk->wu.rl_flag = emwk->wu.rl_flag ^ emwk->wu.curr_rca->catch_flip;
        if (emwk->wu.rl_flag) {
            emwk->wu.xyz[0].disp.pos = wk->wu.xyz[0].disp.pos + emwk->wu.curr_rca->catch_hos_x;
        } else {
            emwk->wu.xyz[0].disp.pos = wk->wu.xyz[0].disp.pos - emwk->wu.curr_rca->catch_hos_x;
        }
        emwk->wu.xyz[1].disp.pos = wk->wu.xyz[1].disp.pos - emwk->wu.curr_rca->catch_hos_y;
        if (emwk->wu.curr_rca->catch_prio == 2) {
            wk->wu.next_z = emwk->wu.next_z - 1;
        } else {
            wk->wu.next_z = emwk->wu.next_z + 1;
        }
        caught_cg_type_check(wk, emwk);
    }
}



/* 2i 0601297E, 3s-exact: sf3 src/PLPCU.c:140 Caught_03000 */
void Caught_03000(PLW* wk) {}


/* provisional name */
/* 2i 06012982, 3s-exact: sf3 src/PLPCU.c:144 Caught_04000 */
void Caught_04000(PLW* wk) {}


/* provisional name */
/* 2i 06012986, 3s-exact: sf3 src/PLPCU.c:148 Caught_05000 */
void Caught_05000(PLW* wk) {}


/* provisional name */
/* 2i 0601298A, 3s-exact: sf3 src/PLPCU.c:152 Caught_06000 */
void Caught_06000(PLW* wk) {}


/* provisional name */
/* 2i 0601298E, 3s-exact: sf3 src/PLPCU.c:156 Caught_07000 */
void Caught_07000(PLW* wk) {}


/* provisional name */
/* 2i 06012992, 3s-near: sf3 src/PLPCU.c:160 Caught_08000 */
void Caught_08000(PLW* wk) {}



/* 2i 06012996, 3s-near: sf3 src/PLPCU.c:164 caught_cg_type_check */
void caught_cg_type_check(PLW* wk, PLW* emwk) {
    switch (wk->wu.cg_type) {
    case 2:
        wk->wu.hit_quake = wk->wu.dm_quake;
        wk->wu.dm_quake = 0;
        wk->wu.cg_type = 0;
        break;
    case 3:
        effect_A7_init(wk);
        wk->wu.cg_type = 0;
        break;
    case 9:
        if (wk->dead_flag == 0) {
            char_move_z((WORK*)wk);
        } else {
            char_move_cmms((WORK*)wk);
        }
        wk->wu.routine_no[1] = wk->wu.cmmd.koc;
        wk->wu.routine_no[2] = wk->wu.cmmd.ix;
        wk->wu.routine_no[3] = wk->wu.cmmd.pat;
        switch (wk->wu.now_koc) {
        case 1:
            if (caught_dm_chg_tbl1[wk->wu.char_index][0]) {
                wk->wu.char_index = caught_dm_chg_tbl1[wk->wu.char_index][1] + wk->wu.dm_attlv;
                exset_char_move_init(&wk->wu, 1, wk->wu.char_index);
            }
            break;
        case 6:
            if (caught_dm_chg_tbl6[wk->wu.char_index][0]) {
                wk->wu.char_index = caught_dm_chg_tbl6[wk->wu.char_index][1] + wk->wu.dm_attlv;
                exset_char_move_init(&wk->wu, 6, wk->wu.char_index);
            }
            break;
        }
        wk->dm_ix = wk->wu.char_index;
        if (wk->wu.xyz[1].disp.pos < 0) {
            wk->wu.xyz[1].cal = 0;
        }
        setup_cu_dm_init_data[wk->wu.routine_no[2] - 12](wk);
        get_catch_off_data(wk, emwk->wu.att.reaction);
        if (wk->ukemi_success == 0) {
            wk->ukemi_ok_timer = wk->backup_ok_timer;
            wk->uot_cd_ok_flag = 0;
        }
        break;
    }
}



/* 2i 06012AFA, 3s-near: sf3 src/PLPCU.c:200 check_tsukamare_keizoku_check */
s32 check_tsukamare_keizoku_check(PLW* wk, PLW* emwk) {
    if (emwk->tsukami_f == 0) {
        wk->wu.routine_no[1] = 1;
        wk->wu.routine_no[2] = 88;
        wk->wu.routine_no[3] = 0;
        wk->wu.dm_stop = wk->wu.hit_stop = 0;
        return 1;
    }
    return 0;
}



/* 2i 06012B26, 3s-near: sf3 src/PLPCU.c:213 scdmd_12000 */
void scdmd_12000(PLW* wk) {
    wk->dm_step_tbl = dm_step_data[select_hit_dsd[wk->wu.dm_impact][get_weight_point(&wk->wu)]];
    wk->wu.cmwk[14] = damage_pause_table[0][wk->wu.dm_attlv];
}



/* 2i 06012B68, 3s-reloc: sf3 src/PLPCU.c:226 scdmd_14000 */
void scdmd_14000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
}



/* 2i 06012B88, 3s-near: sf3 src/PLPCU.c:233 scdmd_16000 */
void scdmd_16000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], 0);
}



/* 2i 06012BEC, 3s-near: sf3 src/PLPCU.c:240 scdmd_17000 */
void scdmd_17000(PLW* wk) {
    if (wk->wu.dm_butt_type) {
        setup_butt_own_data(&wk->wu);
    } else {
        setup_butt_own_data_ex(&wk->wu, 0);
    }
    cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], wk->wu.xyz[1].disp.pos);
}



/* 2i 06012C24, 3s-near: sf3 src/PLPCU.c:247 scdmd_18000 */
void scdmd_18000(PLW* wk) {
    if (wk->wu.dm_butt_type) {
        setup_butt_own_data(&wk->wu);
    } else {
        setup_butt_own_data_ex(&wk->wu, 0);
    }
    cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], wk->wu.xyz[1].disp.pos);
}



/* 2i 06012C5C, 3s-near: sf3 src/PLPCU.c:260 scdmd_19000 */
void scdmd_19000(PLW* wk) {
    if (wk->wu.dm_butt_type) {
        setup_butt_own_data(&wk->wu);
    } else {
        setup_butt_own_data_ex(&wk->wu, 0);
    }
    cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], 0);
}



/* 2i 06012C92, 3s-reloc: sf3 src/PLPCU.c:267 scdmd_20000 */
void scdmd_20000(void) { setup_butt_own_data(); }



/* 2i 06012C98, 3s-reloc: sf3 src/PLPCU.c:271 scdmd_21000 */
void scdmd_21000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
}



/* 2i 06012CB8, 3s-reloc: sf3 src/PLPCU.c:278 scdmd_23000 */
void scdmd_23000(WORK* wk) {
    if (wk->xyz[1].disp.pos < 0) {
        wk->xyz[1].cal = 0;
    }
    setup_butt_own_data(wk);
}


/* 2i 06012CCC, 3s-exact: sf3 src/PLPCU.c:286 scdmd_24000 */
void scdmd_24000(PLW* wk) {
    wk->wu.routine_no[2] = 0;
    wk->wu.routine_no[3] = 1;
}



/* 2i 06012CDA, 3s-exact: sf3 src/PLPCU.c:293 scdmd_25000 */
void scdmd_25000(PLW* wk) {}



/* 2i 06012CDE, 3s-near: sf3 src/PLPCU.c:None scdmd_26000 */
void scdmd_26000(PLW* wk) {
    if (wk->wu.dm_butt_type) {
        setup_butt_own_data(&wk->wu);
    } else {
        setup_butt_own_data_ex(&wk->wu, 0);
    }
}


/* 2i 06012CF2, 3s-near: sf3 src/PLPCU.c:300 scdmd_27000 */
void scdmd_27000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
}



/* 2i 06012D28, 3s-near: sf3 src/PLPCU.c:307 scdmd_28000 */
void scdmd_28000(PLW* wk) {
    if (wk->wu.dm_butt_type) {
        setup_butt_own_data(&wk->wu);
    } else {
        setup_butt_own_data_ex(&wk->wu, 0);
    }
    cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], wk->wu.xyz[1].disp.pos);
}



/* 2i 06012D60, 3s-exact: sf3 src/PLPCU.c:314 scdmd_29000 */
void scdmd_29000(PLW* wk) {}



/* 2i 06012D64, 3s-near: sf3 src/PLPCU.c:318 scdmd_30000 */
void scdmd_30000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    cal_initial_speed_y(&wk->wu, buttobi_time_table[wk->dm_ix], 0);
}
