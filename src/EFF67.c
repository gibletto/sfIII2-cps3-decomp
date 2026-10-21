/*
 * EFF67.C  Effect 67: the message balloon beside a player (2nd Impact only)
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

typedef struct {
    const CONN* conn;
    const u16* gfx;
} EFF67_MSG;

extern s16 mes_already;
extern const u32 eff67_mes_0650AF20[];
extern const u32 eff67_mes_0650B484[];
extern const u32 eff67_mes_0650B960[];
extern const u32 eff67_mes_0650BE5C[];
extern const u32 eff67_mes_0650C3C4[];
extern const u32 eff67_mes_0650C930[];
extern const u32 eff67_mes_0650D200[];
extern const u32 eff67_mes_0650D698[];
extern const u32 eff67_mes_0650DB54[];
extern const u32 eff67_mes_0650E098[];
extern const u32 eff67_mes_0650E51C[];
extern const u32 eff67_mes_0650EA04[];
extern const u32 eff67_mes_0650EEA8[];
extern const u32 eff67_mes_0650F350[];
extern const u32 eff67_mes_0650F6CC[];
extern const u32 eff67_mes_0650FF70[];
extern const u32 eff67_mes_06510774[];
extern const u32 eff67_mes_06510F88[];
extern const u32 eff67_mes_065117EC[];
extern const u32 eff67_mes_06512038[];
extern const u32 eff67_mes_06512FE0[];
extern const u32 eff67_mes_06513804[];
extern const u32 eff67_mes_06513FD8[];
extern const u32 eff67_mes_06514834[];
extern const u32 eff67_mes_065150A0[];
extern const u32 eff67_mes_06515874[];
extern const u32 eff67_mes_06516118[];
extern const u32 eff67_mes_06516894[];
extern const u32 eff67_mes_06516FE0[];
extern const u32 eff67_mes_065178D0[];
extern const u32 eff67_mes_065180DC[];
extern const u32 eff67_mes_06518910[];
extern const u32 eff67_mes_065191A8[];
extern const u32 eff67_mes_065199E0[];
extern const u32 eff67_mes_0651AA40[];
extern const u32 eff67_mes_0651B230[];
extern const u32 eff67_mes_0651B9FC[];
extern const u32 eff67_mes_0651C28C[];
extern const u32 eff67_mes_0651CAF4[];
extern const u32 eff67_mes_0651D2DC[];
extern const u32 eff67_mes_0651DBA4[];
extern const u32 eff67_mes_0651E318[];
extern const u32 eff67_mes_0651EA9C[];
extern const u32 eff67_mes_0651F2D4[];
extern const u32 eff67_mes_0651FAE8[];
extern const u32 eff67_mes_06520280[];
extern const u32 eff67_mes_06520A3C[];
extern const u32 eff67_mes_06521284[];
extern const u32 eff67_mes_065222B8[];
extern const u32 eff67_mes_06522A70[];
extern const u32 eff67_mes_06523240[];
extern const u32 eff67_mes_06523A18[];
extern const u32 eff67_mes_06524248[];
extern const u32 eff67_mes_06524A00[];
extern const u32 eff67_mes_06525288[];
extern const u32 eff67_mes_06525A40[];

s16 eff67_cnt0;  
s16 eff67_cnt1;  
s16 eff67_flag;  

EFF67_MSG* eff67_msg_a[15] = { (EFF67_MSG*)eff67_mes_0650AF20, (EFF67_MSG*)eff67_mes_0650AF20, (EFF67_MSG*)eff67_mes_0650B484, (EFF67_MSG*)eff67_mes_0650B960, (EFF67_MSG*)eff67_mes_0650BE5C, (EFF67_MSG*)eff67_mes_0650C3C4, (EFF67_MSG*)eff67_mes_0650C930, (EFF67_MSG*)eff67_mes_0650D200, (EFF67_MSG*)eff67_mes_0650D698, (EFF67_MSG*)eff67_mes_0650DB54, (EFF67_MSG*)eff67_mes_0650E098, (EFF67_MSG*)eff67_mes_0650E51C, (EFF67_MSG*)eff67_mes_0650EA04, (EFF67_MSG*)eff67_mes_0650EEA8, (EFF67_MSG*)eff67_mes_0650F350 };
EFF67_MSG* eff67_msg_b[15] = { (EFF67_MSG*)eff67_mes_0650F6CC, (EFF67_MSG*)eff67_mes_0650F6CC, (EFF67_MSG*)eff67_mes_0650FF70, (EFF67_MSG*)eff67_mes_06510774, (EFF67_MSG*)eff67_mes_06510F88, (EFF67_MSG*)eff67_mes_065117EC, (EFF67_MSG*)eff67_mes_06512038, (EFF67_MSG*)eff67_mes_06512FE0, (EFF67_MSG*)eff67_mes_06513804, (EFF67_MSG*)eff67_mes_06513FD8, (EFF67_MSG*)eff67_mes_06514834, (EFF67_MSG*)eff67_mes_065150A0, (EFF67_MSG*)eff67_mes_06515874, (EFF67_MSG*)eff67_mes_06516118, (EFF67_MSG*)eff67_mes_06516894 };
EFF67_MSG* eff67_msg_c[15] = { (EFF67_MSG*)eff67_mes_06516FE0, (EFF67_MSG*)eff67_mes_06516FE0, (EFF67_MSG*)eff67_mes_065178D0, (EFF67_MSG*)eff67_mes_065180DC, (EFF67_MSG*)eff67_mes_06518910, (EFF67_MSG*)eff67_mes_065191A8, (EFF67_MSG*)eff67_mes_065199E0, (EFF67_MSG*)eff67_mes_0651AA40, (EFF67_MSG*)eff67_mes_0651B230, (EFF67_MSG*)eff67_mes_0651B9FC, (EFF67_MSG*)eff67_mes_0651C28C, (EFF67_MSG*)eff67_mes_0651CAF4, (EFF67_MSG*)eff67_mes_0651D2DC, (EFF67_MSG*)eff67_mes_0651DBA4, (EFF67_MSG*)eff67_mes_0651E318 };
EFF67_MSG* eff67_msg_d[15] = { (EFF67_MSG*)eff67_mes_0651EA9C, (EFF67_MSG*)eff67_mes_0651EA9C, (EFF67_MSG*)eff67_mes_0651F2D4, (EFF67_MSG*)eff67_mes_0651FAE8, (EFF67_MSG*)eff67_mes_06520280, (EFF67_MSG*)eff67_mes_06520A3C, (EFF67_MSG*)eff67_mes_06521284, (EFF67_MSG*)eff67_mes_065222B8, (EFF67_MSG*)eff67_mes_06522A70, (EFF67_MSG*)eff67_mes_06523240, (EFF67_MSG*)eff67_mes_06523A18, (EFF67_MSG*)eff67_mes_06524248, (EFF67_MSG*)eff67_mes_06524A00, (EFF67_MSG*)eff67_mes_06525288, (EFF67_MSG*)eff67_mes_06525A40 };

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
    case 0:
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
    case 1:
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
                if (sw & 0x80) {
                    eff67_cnt0++;
                    if (eff67_cnt0 > 14) {
                        eff67_cnt0 = 0;
                    }
                }
                if (sw & 0x100) {
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
    case 2:
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
    ewk->wu.routine_no[0] = 0;
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
        if (My_char[Player_id] == 6) {
            switch (My_char[COM_id]) {
            case 0:
                page = 6;
                break;
            case 2:
                page = 2;
                break;
            case 8:
                page = 4;
                break;
            case 5:
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
    ewk->wu.routine_no[0] = 0;
    eff67_setup(ewk);
    ewk->master_player = player;
    mes_already = page;
    return 0;
}
