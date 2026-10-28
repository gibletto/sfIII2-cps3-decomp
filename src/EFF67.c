/*
 * EFF67.C  Effect 67: the message balloon beside a player
 *
 * effect_67_init (master) puts the balloon of the player's character (My_char) beside the master.
 * The page comes from Break_Into_CPU: 1 gives page 0, or 6, 2 or 4 when the player is character 6
 * and the CPU is character 0, 2 or 8; 2 gives page 9; anything else page 10. effect_67_move picks
 * eff67_msg_a / _b / _c / _d by Country and Language, loads the page's graphics and connected
 * cells, then follows the master until it goes behind (position_z < 0) or is hidden, and purges
 * the graphics when it dies. With extra switch 2 bit 2 on, player 1's buttons step through
 * characters and pages (eff67_spawn makes the next one).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF67.h"
#include "fighter.h"

/* routine_no[0] */
#define R0_INIT         0       /* load the page and show */
#define R0_MOVE         1       /* follow the master */
#define R0_END          2       /* hidden for a frame */
#define R0_KILL         3       /* (default) free the graphics and the work */

typedef struct {
    const CONN* conn;
    const u16* gfx;
} EFF67_MSG;

extern const EFFA6_MESSAGE effA6_mes_en_0[];
extern const EFFA6_MESSAGE effA6_mes_en_10[];
extern const EFFA6_MESSAGE effA6_mes_en_11[];
extern const EFFA6_MESSAGE effA6_mes_en_12[];
extern const EFFA6_MESSAGE effA6_mes_en_13[];
extern const EFFA6_MESSAGE effA6_mes_en_14[];
extern const EFFA6_MESSAGE effA6_mes_en_2[];
extern const EFFA6_MESSAGE effA6_mes_en_3[];
extern const EFFA6_MESSAGE effA6_mes_en_4[];
extern const EFFA6_MESSAGE effA6_mes_en_5[];
extern const EFFA6_MESSAGE effA6_mes_en_6[];
extern const EFFA6_MESSAGE effA6_mes_en_7[];
extern const EFFA6_MESSAGE effA6_mes_en_8[];
extern const EFFA6_MESSAGE effA6_mes_en_9[];
extern const EFFA6_MESSAGE effA6_mes_es_0[];
extern const EFFA6_MESSAGE effA6_mes_es_10[];
extern const EFFA6_MESSAGE effA6_mes_es_11[];
extern const EFFA6_MESSAGE effA6_mes_es_12[];
extern const EFFA6_MESSAGE effA6_mes_es_13[];
extern const EFFA6_MESSAGE effA6_mes_es_14[];
extern const EFFA6_MESSAGE effA6_mes_es_2[];
extern const EFFA6_MESSAGE effA6_mes_es_3[];
extern const EFFA6_MESSAGE effA6_mes_es_4[];
extern const EFFA6_MESSAGE effA6_mes_es_5[];
extern const EFFA6_MESSAGE effA6_mes_es_6[];
extern const EFFA6_MESSAGE effA6_mes_es_7[];
extern const EFFA6_MESSAGE effA6_mes_es_8[];
extern const EFFA6_MESSAGE effA6_mes_es_9[];
extern const EFFA6_MESSAGE effA6_mes_jp_0[];
extern const EFFA6_MESSAGE effA6_mes_jp_10[];
extern const EFFA6_MESSAGE effA6_mes_jp_11[];
extern const EFFA6_MESSAGE effA6_mes_jp_12[];
extern const EFFA6_MESSAGE effA6_mes_jp_13[];
extern const EFFA6_MESSAGE effA6_mes_jp_14[];
extern const EFFA6_MESSAGE effA6_mes_jp_2[];
extern const EFFA6_MESSAGE effA6_mes_jp_3[];
extern const EFFA6_MESSAGE effA6_mes_jp_4[];
extern const EFFA6_MESSAGE effA6_mes_jp_5[];
extern const EFFA6_MESSAGE effA6_mes_jp_6[];
extern const EFFA6_MESSAGE effA6_mes_jp_7[];
extern const EFFA6_MESSAGE effA6_mes_jp_8[];
extern const EFFA6_MESSAGE effA6_mes_jp_9[];
extern const EFFA6_MESSAGE effA6_mes_pt_0[];
extern const EFFA6_MESSAGE effA6_mes_pt_10[];
extern const EFFA6_MESSAGE effA6_mes_pt_11[];
extern const EFFA6_MESSAGE effA6_mes_pt_12[];
extern const EFFA6_MESSAGE effA6_mes_pt_13[];
extern const EFFA6_MESSAGE effA6_mes_pt_14[];
extern const EFFA6_MESSAGE effA6_mes_pt_2[];
extern const EFFA6_MESSAGE effA6_mes_pt_3[];
extern const EFFA6_MESSAGE effA6_mes_pt_4[];
extern const EFFA6_MESSAGE effA6_mes_pt_5[];
extern const EFFA6_MESSAGE effA6_mes_pt_6[];
extern const EFFA6_MESSAGE effA6_mes_pt_7[];
extern const EFFA6_MESSAGE effA6_mes_pt_8[];
extern const EFFA6_MESSAGE effA6_mes_pt_9[];

s16 eff67_cnt0;  
s16 eff67_cnt1;  
s16 eff67_flag;  

EFF67_MSG* eff67_msg_a[15] = {
    (EFF67_MSG*)effA6_mes_jp_0,
    (EFF67_MSG*)effA6_mes_jp_0,
    (EFF67_MSG*)effA6_mes_jp_2,
    (EFF67_MSG*)effA6_mes_jp_3,
    (EFF67_MSG*)effA6_mes_jp_4,
    (EFF67_MSG*)effA6_mes_jp_5,
    (EFF67_MSG*)effA6_mes_jp_6,
    (EFF67_MSG*)effA6_mes_jp_7,
    (EFF67_MSG*)effA6_mes_jp_8,
    (EFF67_MSG*)effA6_mes_jp_9,
    (EFF67_MSG*)effA6_mes_jp_10,
    (EFF67_MSG*)effA6_mes_jp_11,
    (EFF67_MSG*)effA6_mes_jp_12,
    (EFF67_MSG*)effA6_mes_jp_13,
    (EFF67_MSG*)effA6_mes_jp_14,
};
EFF67_MSG* eff67_msg_b[15] = {
    (EFF67_MSG*)effA6_mes_en_0,
    (EFF67_MSG*)effA6_mes_en_0,
    (EFF67_MSG*)effA6_mes_en_2,
    (EFF67_MSG*)effA6_mes_en_3,
    (EFF67_MSG*)effA6_mes_en_4,
    (EFF67_MSG*)effA6_mes_en_5,
    (EFF67_MSG*)effA6_mes_en_6,
    (EFF67_MSG*)effA6_mes_en_7,
    (EFF67_MSG*)effA6_mes_en_8,
    (EFF67_MSG*)effA6_mes_en_9,
    (EFF67_MSG*)effA6_mes_en_10,
    (EFF67_MSG*)effA6_mes_en_11,
    (EFF67_MSG*)effA6_mes_en_12,
    (EFF67_MSG*)effA6_mes_en_13,
    (EFF67_MSG*)effA6_mes_en_14,
};
EFF67_MSG* eff67_msg_c[15] = {
    (EFF67_MSG*)effA6_mes_es_0,
    (EFF67_MSG*)effA6_mes_es_0,
    (EFF67_MSG*)effA6_mes_es_2,
    (EFF67_MSG*)effA6_mes_es_3,
    (EFF67_MSG*)effA6_mes_es_4,
    (EFF67_MSG*)effA6_mes_es_5,
    (EFF67_MSG*)effA6_mes_es_6,
    (EFF67_MSG*)effA6_mes_es_7,
    (EFF67_MSG*)effA6_mes_es_8,
    (EFF67_MSG*)effA6_mes_es_9,
    (EFF67_MSG*)effA6_mes_es_10,
    (EFF67_MSG*)effA6_mes_es_11,
    (EFF67_MSG*)effA6_mes_es_12,
    (EFF67_MSG*)effA6_mes_es_13,
    (EFF67_MSG*)effA6_mes_es_14,
};
EFF67_MSG* eff67_msg_d[15] = {
    (EFF67_MSG*)effA6_mes_pt_0,
    (EFF67_MSG*)effA6_mes_pt_0,
    (EFF67_MSG*)effA6_mes_pt_2,
    (EFF67_MSG*)effA6_mes_pt_3,
    (EFF67_MSG*)effA6_mes_pt_4,
    (EFF67_MSG*)effA6_mes_pt_5,
    (EFF67_MSG*)effA6_mes_pt_6,
    (EFF67_MSG*)effA6_mes_pt_7,
    (EFF67_MSG*)effA6_mes_pt_8,
    (EFF67_MSG*)effA6_mes_pt_9,
    (EFF67_MSG*)effA6_mes_pt_10,
    (EFF67_MSG*)effA6_mes_pt_11,
    (EFF67_MSG*)effA6_mes_pt_12,
    (EFF67_MSG*)effA6_mes_pt_13,
    (EFF67_MSG*)effA6_mes_pt_14,
};

void effect_67_move(WORK_Other_CONN* ewk) {
    EFF67_MSG* msg;
    const CONN* conn;
    const u16* gfx;
    s16 i;
    s16 n;
    u16 sw;
    u16 chr;
    WORK* mwk;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        switch (Country) {
        case 1:
            msg = eff67_msg_a[ewk->master_player];
            break;
        case 4:
            msg = eff67_msg_b[ewk->master_player];
            break;
        default:
            msg = eff67_msg_a[ewk->master_player];
        }
        msg += mes_already;
        conn = msg->conn;
        gfx = msg->gfx;
        if (0) {
        }
        switch (Country) {
        case 1:
            conn = eff67_msg_a[ewk->master_player][mes_already].conn;
            gfx = eff67_msg_a[ewk->master_player][mes_already].gfx;
            break;
        case 3:
            switch (Language) {
            case 0:
                conn = eff67_msg_b[ewk->master_player][mes_already].conn;
                gfx = eff67_msg_b[ewk->master_player][mes_already].gfx;
                break;
            case 1:
                conn = eff67_msg_c[ewk->master_player][mes_already].conn;
                gfx = eff67_msg_c[ewk->master_player][mes_already].gfx;
                break;
            case 2:
                conn = eff67_msg_d[ewk->master_player][mes_already].conn;
                gfx = eff67_msg_d[ewk->master_player][mes_already].gfx;
                break;
            }
            break;
        case 5:
            conn = eff67_msg_c[ewk->master_player][mes_already].conn;
            gfx = eff67_msg_c[ewk->master_player][mes_already].gfx;
            break;
        case 6:
            conn = eff67_msg_d[ewk->master_player][mes_already].conn;
            gfx = eff67_msg_d[ewk->master_player][mes_already].gfx;
            break;
        case 7:
            switch (Language) {
            case 0:
                conn = eff67_msg_b[ewk->master_player][mes_already].conn;
                gfx = eff67_msg_b[ewk->master_player][mes_already].gfx;
                break;
            case 1:
                conn = eff67_msg_c[ewk->master_player][mes_already].conn;
                gfx = eff67_msg_c[ewk->master_player][mes_already].gfx;
                break;
            case 2:
                conn = eff67_msg_d[ewk->master_player][mes_already].conn;
                gfx = eff67_msg_d[ewk->master_player][mes_already].gfx;
                break;
            }
            break;
        case 2:
            conn = eff67_msg_b[ewk->master_player][mes_already].conn;
            gfx = eff67_msg_b[ewk->master_player][mes_already].gfx;
            break;
        case 4:
            conn = eff67_msg_b[ewk->master_player][mes_already].conn;
            gfx = eff67_msg_b[ewk->master_player][mes_already].gfx;
            break;
        default:
            conn = eff67_msg_b[ewk->master_player][mes_already].conn;
            gfx = eff67_msg_b[ewk->master_player][mes_already].gfx;
        }
        for (i = 0; i < gfx[0]; i++) {
            load_char_gfx(gfx[i + 1], 1);
        }
        ewk->num_of_conn = gfx[i + 1];
        ewk->wu.disp_flag = 1;
        ewk->wu.cg_number = 0;
        ewk->wu.old_cgnum = 0;
        for (i = 0; i < ewk->num_of_conn; i++) {
            ewk->conn[i].nx = conn[i].nx;
            ewk->conn[i].ny = conn[i].ny;
            ewk->conn[i].col = conn[i].col;
            ewk->conn[i].chr = conn[i].chr;
        }
        ewk->wu.vitality = 240;
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        break;
    case R0_MOVE:
        mwk = (WORK*)ewk->my_master;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = mwk->position_x - 124;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = mwk->cg_type + mwk->position_y - 22;
        ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = mwk->position_z - 1;
        if (ewk->wu.position_z < 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (!mwk->disp_flag) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (exsw_2 & 4) {
            sw = ~p1sw_1 & p1sw_0;
            if (sw & 0x180) {
                ewk->wu.routine_no[0]++;
                eff67_flag = 1;
                if (sw & BUTTON_LK) {
                    eff67_cnt0++;
                    if (eff67_cnt0 > 14) {
                        eff67_cnt0 = 0;
                    }
                }
                if (sw & BUTTON_MK) {
                    eff67_cnt1++;
                    if (eff67_cnt1 > 9) {
                        eff67_cnt1 = 0;
                    }
                }
                eff67_spawn(eff67_cnt0, eff67_cnt1);
            }
        }
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        break;
    default:
        if (eff67_flag == 0) {
            switch (Country) {
            case 1:
                gfx = eff67_msg_a[ewk->master_player][mes_already].gfx;
                break;
            case 4:
                gfx = eff67_msg_b[ewk->master_player][mes_already].gfx;
                break;
            default:
                gfx = eff67_msg_a[ewk->master_player][mes_already].gfx;
                break;
            }
            n = gfx[0];
            gfx++;
            for (i = 0; i < n; i++) {
                chr = *gfx;
                purge_char_gfx(chr);
                gfx++;
            }
        }
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}





s32 effect_67_init(WORK* master) {
    WORK_Other_CONN* ewk;
    s16 ix;
    s16 page;
    eff67_flag = 0;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.routine_no[0] = R0_INIT;
    eff67_setup(ewk);
    ewk->master_player = My_char[Player_id];
    eff67_cnt0 = My_char[Player_id];
    ewk->my_master = master;
    switch (Break_Into_CPU) {
    case 1:
        if (Player_id == 0) {
            if (Game_setting.mode == 0) {
                ewk->wu.position_x = 0x1F8;
            } else {
                ewk->wu.position_x = 0x240;
            }
        } else if (Game_setting.mode == 0) {
            ewk->wu.position_x = 0x278;
        } else {
            ewk->wu.position_x = 0x2C0;
        }
        if (My_char[Player_id] == PL_HUGO) {
            switch (My_char[COM_id]) {
            case PL_GILL:
                page = 6;
                break;
            case PL_RYU:
                page = 2;
                break;
            case PL_ELENA:
                page = 4;
                break;
            case PL_NECRO:
            default:
                page = 0;
                break;
            }
        } else {
            page = 0;
        }
        break;
    case 2:
        if (Player_id == 0) {
            if (Game_setting.mode == 0) {
                ewk->wu.position_x = 0x1F8;
            } else {
                ewk->wu.position_x = 0x240;
            }
        } else if (Game_setting.mode == 0) {
            ewk->wu.position_x = 0x278;
        } else {
            ewk->wu.position_x = 0x2C0;
        }
        page = 9;
        break;
    default:
        page = 10;
        break;
    }
    ewk->wu.position_y = 24;
    ewk->wu.position_z = 35;
    eff67_cnt1 = mes_already = page;
    return 0;
}

void eff67_setup(WORK_Other_CONN* ewk) {
    ewk->wu.be_flag = 1;
    ewk->wu.id = 67;
    ewk->wu.work_id = 16;
    ewk->wu.rl_flag = 0;
    ewk->wu.cgromtype = 1;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 88;
    ewk->wu.my_family = 3;
    ewk->wu.my_priority = 35;
    if (Game_setting.mode == 0) {
        ewk->wu.position_x = 0x238;
    } else {
        ewk->wu.position_x = 0x280;
    }
    ewk->wu.position_y = 24;
    ewk->wu.position_z = 35;
}

s32 eff67_spawn(s16 player, s16 page) {
    WORK_Other_CONN* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.routine_no[0] = R0_INIT;
    eff67_setup(ewk);
    ewk->master_player = player;
    mes_already = page;
    return 0;
}
