/*
 * EFFD5.C  Effect D5: the thrown rose
 *
 * Effect D5 is a rose thrown by a player (only one per player; my_rose_live_check). effect_D5_init
 * places it in front of the player and sets cmwk[0]; effect_D5_move aims it at the opponent with
 * cal_speeds (range_isp_table / range_time_table) and flies it as a hit-capable object (pattern
 * 0x7C) with a shadow. effD5_main_process handles hits: struck by the opponent it bursts into
 * petals, is knocked back (or reflected by certain hits), and on hitting it plays sound 0x10B and
 * scatters petals by the attack's direction.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "HITCHECK.h"
#include "PLS01.h"
#include "CHARID.h"
#include "EFFD5.h"

/* routine_no[0] */
#define R0_INIT         0       /* aim at the opponent */
#define R0_MOVE         1       /* fly and take hits */
#define R0_END          2       /* one more frame */
#define R0_KILL         3       /* (default) put the work back */

/* routine_no[1] */
#define R1_FLY          0       /* fly, settle on the floor */
#define R1_HIT          1       /* sort out the hit */
#define R1_SCATTER      2       /* scatter the petals, then end */

/* dm_sp_sel_tbl columns */
#define DMSP_SET        0       /* petal set, index into num_of_hana */
#define DMSP_ACC        1       /* petal acceleration */



void effect_D5_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.charset_id = 11;
        set_char_base_data(&ewk->wu);
        ewk->wu.my_col_code = ewk->wu.dm_vital;
        *ewk->wu.char_table = plef_char_table;
        ewk->wu.type = 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.blink_timing = ewk->master_id;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 0;
        cal_speeds(ewk, (PLW*)ewk->my_master, (PLW*)ewk->wu.target_adrs);
        add_mvxy_speed(&ewk->wu);
        set_char_move_init(&ewk->wu, 0, 0x7C);
        sort_push_request(&ewk->wu);
        break;
    case R0_MOVE:
        if (ewk->wu.dead_f == 1 || Suicide != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (sa_stop_check()) {
            /* frozen while a super art holds the screen */
        } else {
            if (ewk->wu.hit_stop < 0) {
                ewk->wu.hit_stop = -ewk->wu.hit_stop;
            }
            if (EXE_flag == 0 && Game_pause == 0) {
                effD5_main_process(ewk);
                if (ewk->wu.cg_type == 0xFF) {
                    ewk->wu.routine_no[0]++;
                    ewk->wu.disp_flag = 0;
                    break;
                }
            }
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
            if (ewk->wu.type) {
                hit_push_request(&ewk->wu);
            }
        }
        sort_push_request(&ewk->wu);
        break;
    case R0_END:
        ewk->wu.routine_no[0] = R0_KILL;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effD5_main_process(WORK_Other* ewk) {
    s16 dsst;
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = R1_HIT;
    }
    switch (ewk->wu.routine_no[1]) {
    case R1_FLY:
        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
            break;
        }
        char_move(&ewk->wu);
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        if (ewk->wu.xyz[1].disp.pos < 0) {
            ewk->wu.xyz[1].disp.pos = 0;
            char_move_cmja(&ewk->wu);
            ewk->wu.mvxy.a[0].sp = ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[0].sp = ewk->wu.mvxy.d[1].sp = 0;
        }
        break;
    case R1_HIT:
        if (ewk->wu.hf.hit.player) {
            if (ewk->wu.hf.hit.player & 0x33) {
                ewk->wu.routine_no[1] = R1_FLY;
                ewk->wu.mvxy.d[0].sp = 0;
                ewk->wu.mvxy.a[0].sp = 0;
                ewk->wu.mvxy.a[1].sp = 0;
                ewk->wu.direction = 2;
                if (ewk->wu.rl_flag) {
                    ewk->wu.direction = cal_attdir_flip(ewk->wu.direction);
                }
                setup_hana_extra(&ewk->wu, 0, 8);
            } else if (ewk->wu.hf.hit.player & 0xC0) {
                ewk->wu.routine_no[1] = R1_FLY;
                ewk->refrected = 1;
                ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
                ewk->wu.mvxy.a[0].sp = 0x60000;
                ewk->wu.mvxy.d[0].sp = -0x3000;
                ewk->wu.mvxy.a[1].sp /= 3;
                ewk->wu.mvxy.a[1].sp = -ewk->wu.mvxy.a[1].sp;
                ewk->wu.hit_stop = 4;
                ewk->wu.direction = 0xD;
                if (ewk->wu.rl_flag) {
                    ewk->wu.direction = cal_attdir_flip(ewk->wu.direction);
                }
                setup_hana_extra(&ewk->wu, 1, 0x18);
            }
        } else {
            sound_effect_request[0x10B](ewk, 0x10B);
            ewk->wu.routine_no[1] = R1_SCATTER;
            ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
            ewk->wu.disp_flag = 2;
            ewk->wu.type = 0;
            ewk->wu.kage_flag = 0;
            ewk->wu.dir_timer = 16;
            ewk->wu.hit_stop = 2;
            ewk->wu.direction = ewk->wu.dm_dir;
            dsst = 3;
            if (!(ewk->wu.dm_kind_of_waza & 0xF8)) {
                dsst = (ewk->wu.dm_kind_of_waza / 2) & 3;
            }
            setup_hana_extra(&ewk->wu, dm_sp_sel_tbl[dsst][DMSP_SET], dm_sp_sel_tbl[dsst][DMSP_ACC]);
        }
        ewk->wu.hf.hit_flag = 0;
        break;
    case R1_SCATTER:
        ewk->wu.dir_timer--;
        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = R0_END;
        }
        break;
    }
}



void cal_speeds(WORK_Other* ewk, PLW* _p1, PLW* twk) {
    s16 tx = twk->wu.position_x;
    s16 rix = 0;
    if (ewk->wu.rl_flag) {
        tx -= 16;
        if (tx > ewk->wu.position_x) {
            rix = (tx - ewk->wu.position_x) / 32;
        } else {
            tx = ewk->wu.position_x + 16;
        }
    } else {
        tx += 16;
        if (tx < ewk->wu.position_x) {
            rix = (ewk->wu.position_x - tx) / 32;
        } else {
            tx = ewk->wu.position_x - 16;
        }
    }
    ewk->wu.mvxy.a[0].sp = 0;
    ewk->wu.mvxy.a[1].real.h = range_isp_table[rix];
    cal_delta_speed(&ewk->wu, range_time_table[rix][0], tx, 0, 2, 1);
    ewk->wu.mvxy.kop[0] = 1;
    if (ewk->wu.rl_flag == 0) {
        ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.d[0].sp = -ewk->wu.mvxy.d[0].sp;
    }
}



s32 effect_D5_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;
    if (my_rose_live_check((PLW*)wk) != 0) {
        return -1;
    }
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 135;
    ewk->wu.work_id = 2;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.dm_vital = wk->my_col_code + 6;
    ewk->my_master = (u32*)wk;
    ewk->wu.target_adrs = wk->target_adrs;
    ewk->master_work_id = wk->work_id;
    ewk->master_id = wk->id;
    if (ewk->wu.rl_flag) {
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = wk->position_x + 28;
    } else {
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = wk->position_x - 28;
    }
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = wk->position_y + 124;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = 28;
    wk->cmwk[0] = 1;
    return 0;
}



s32 my_rose_live_check(PLW* wk) {
    WORK_Other* twk;
    s16 ix;
    ix = search_effect_index(3, 0, 0x87);
    if (ix == -1) {
        return 0;
    }
    twk = (WORK_Other*)frw[ix];
    if (twk->master_id == wk->wu.id) {
        return 1;
    }
    ix = search_effect_index(3, 1, 0x87);
    if (ix == -1) {
        return 0;
    }
    twk = (WORK_Other*)frw[ix];
    if (twk->master_id == wk->wu.id) {
        return 1;
    }
    return 0;
}



