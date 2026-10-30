/*
 * EFFA6.C  Effect A6: VS-screen speech line
 *
 * Effect A6 is one speech line beside a portrait: effect_A6_init (called with the parent
 * plate) records the speaking character (My_char of Player_id), places the line by side and
 * Game_setting.Screen_Mode and picks the message (mmes_already) from Break_Into_CPU and, for character
 * 6, from the opponent. effect_A6_move loads the line once, choosing the message table by
 * Country and Language (effA6_mes_jp / _en / _es / _pt, pointer tables in RAM), builds its
 * connected sprites and then follows the parent until it hides or goes behind.
 * wwwk_set fills the fixed fields of the work (id 106).
 */

#include "EFFA6.h"

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "next_cpu.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "fighter.h"

/* routine_no[0] */
#define R0_INIT         0       /* load the line and build its sprites */
#define R0_MOVE         1       /* follow the parent plate */
#define R0_HIDE         2       /* hide the line */
#define R0_END          3       /* one more frame */
#define R0_KILL         4       /* (default) put the work back */



void effect_A6_move(WORK_Other_CONN* wk) {
    WORK_Other_CONN* ewk = wk;
    WORK_Other* mwk;
    const EFFA6_MESSAGE* mes;
    const CONN* conn_data;
    const u16* chr_data;
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        switch (Country) {
        case 1:
            mes = effA6_mes_jp[ewk->master_player];
            mes += mmes_already;
            conn_data = mes->conn;
            chr_data = mes->chr;
            break;
        case 4:
            mes = effA6_mes_en[ewk->master_player];
            mes += mmes_already;
            conn_data = mes->conn;
            chr_data = mes->chr;
            break;
        default:
            mes = effA6_mes_jp[ewk->master_player];
            mes += mmes_already;
            conn_data = mes->conn;
            chr_data = mes->chr;
            break;
        }
        switch (Country) {
        case 1:
            conn_data = effA6_mes_jp[ewk->master_player][mmes_already].conn;
            chr_data = effA6_mes_jp[ewk->master_player][mmes_already].chr;
            break;
        case 3:
            switch (Language) {
            case 0:
                conn_data = effA6_mes_en[ewk->master_player][mmes_already].conn;
                chr_data = effA6_mes_en[ewk->master_player][mmes_already].chr;
                break;
            case 1:
                conn_data = effA6_mes_es[ewk->master_player][mmes_already].conn;
                chr_data = effA6_mes_es[ewk->master_player][mmes_already].chr;
                break;
            case 2:
                conn_data = effA6_mes_pt[ewk->master_player][mmes_already].conn;
                chr_data = effA6_mes_pt[ewk->master_player][mmes_already].chr;
                break;
            }
            break;
        case 5:
            conn_data = effA6_mes_es[ewk->master_player][mmes_already].conn;
            chr_data = effA6_mes_es[ewk->master_player][mmes_already].chr;
            break;
        case 6:
            conn_data = effA6_mes_pt[ewk->master_player][mmes_already].conn;
            chr_data = effA6_mes_pt[ewk->master_player][mmes_already].chr;
            break;
        case 7:
            switch (Language) {
            case 0:
                conn_data = effA6_mes_en[ewk->master_player][mmes_already].conn;
                chr_data = effA6_mes_en[ewk->master_player][mmes_already].chr;
                break;
            case 1:
                conn_data = effA6_mes_es[ewk->master_player][mmes_already].conn;
                chr_data = effA6_mes_es[ewk->master_player][mmes_already].chr;
                break;
            case 2:
                conn_data = effA6_mes_pt[ewk->master_player][mmes_already].conn;
                chr_data = effA6_mes_pt[ewk->master_player][mmes_already].chr;
                break;
            }
            break;
        default:
        case 2:
        case 4:
            conn_data = effA6_mes_en[ewk->master_player][mmes_already].conn;
            chr_data = effA6_mes_en[ewk->master_player][mmes_already].chr;
            break;
        }
        for (i = 0; i < chr_data[0]; i = i + 1) {
            load_char_gfx(chr_data[i + 1], 1);
        }
        ewk->num_of_conn = chr_data[i + 1];
        ewk->wu.disp_flag = 1;
        ewk->wu.cg_number = 0;
        ewk->wu.old_cgnum = 0;
        for (i = 0; i < ewk->num_of_conn; i++) {
            ewk->conn[i].nx = conn_data[i].nx;
            ewk->conn[i].ny = conn_data[i].ny;
            ewk->conn[i].col = conn_data[i].col;
            ewk->conn[i].chr = conn_data[i].chr;
        }
        ewk->wu.vitality = 0xF0;
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        break;
    case R0_MOVE:
        mwk = (WORK_Other*)ewk->my_master;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = mwk->wu.position_x - 124;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = mwk->wu.position_y + mwk->wu.cg_type - 22;
        ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = mwk->wu.position_z - 1;
        if (ewk->wu.position_z < 0) {
            ewk->wu.routine_no[0]++;
            break;
        }
        if (mwk->wu.disp_flag == 0) {
            ewk->wu.routine_no[0]++;
            break;
        }
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;
    case R0_HIDE:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back((WORK_Other*)ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_A6_init(WORK_Other* mwk) {
    WORK_Other_CONN* ewk;
    register s16 ix;
    s16 mes_no;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.routine_no[0] = R0_INIT;
    wwwk_set(&ewk->wu);
    ewk->master_player = My_char[Player_id];
    ewk->my_master = (u32*)mwk;
    switch (Break_Into_CPU) {
    case 1:
        if (Player_id == 0) {
            if (Game_setting.Screen_Mode == 0) {
                ewk->wu.position_x = 0x1F8;
            } else {
                ewk->wu.position_x = 0x240;
            }
        } else {
            if (Game_setting.Screen_Mode == 0) {
                ewk->wu.position_x = 0x278;
            } else {
                ewk->wu.position_x = 0x2C0;
            }
        }
        if (My_char[Player_id] == PL_HUGO) {
            switch (My_char[COM_id]) {
            case PL_GILL:
                mes_no = 7;
                break;
            case PL_RYU:
                mes_no = 3;
                break;
            case PL_ELENA:
                mes_no = 5;
                break;
            case PL_NECRO:
            default:
                mes_no = 1;
            }
        } else {
            mes_no = 1;
        }
        break;
    case 2:
        if (Player_id == 0) {
            if (Game_setting.Screen_Mode == 0) {
                ewk->wu.position_x = 0x1F8;
            } else {
                ewk->wu.position_x = 0x240;
            }
        } else {
            if (Game_setting.Screen_Mode == 0) {
                ewk->wu.position_x = 0x278;
            } else {
                ewk->wu.position_x = 0x2C0;
            }
        }
        mes_no = 8;
        break;
    default:
        mes_no = 11;
        break;
    }
    ewk->wu.position_y = 0xC0;
    ewk->wu.position_z = 35;
    mmes_already = mes_no;
    return 0;
}



void wwwk_set(WORK* wk) {
    wk->be_flag = 1;
    wk->id = 106;
    wk->work_id = 16;
    wk->rl_flag = 0;
    wk->cgromtype = 1;
    wk->sync_suzi = 0;
    wk->my_col_mode = 0x4200;
    wk->my_col_code = 88;
    wk->my_family = 3;
    wk->my_priority = 35;
    if (Game_setting.Screen_Mode == 0) {
        wk->position_x = 0x238;
    } else {
        wk->position_x = 0x280;
    }
    wk->position_y = 24;
    wk->position_z = 35;
}
