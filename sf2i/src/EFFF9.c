/*
 * EFFF9.C  Effect F9: ending message window
 *
 * Effect F9 is the ending message window. effect_F9_move picks the message by Country and
 * Language (effF9_mes_jp / _en / _es / _pt), loads its graphics, types it out a few characters
 * every three frames and calls Next_Talk_Message when its display time runs out. The ending
 * scripts (end_*.c) drive it through Rewrite_End_Message, Rewrite_Talk_Message,
 * Set_Direct_Message and Next_Talk_Message, which read the per-character scene lists in
 * txt_no_tbl (message + time pairs); effF9_talk_init opens the window on BG3.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "EFFF9.h"



s16 efff9_suicide;  /* 2i 020644C0 (3s 02068C40) */
s32 * efff9_txt_no_adrs;  /* 2i 020644C4 */
u16 * efff9_txt_scene_adrs;  /* 2i 020644C8 */
s16 efff9_PL_NO;  /* 2i 020644CC */
s16 efff9_txt_point;  /* 2i 020644CE */
s16 efff9_message;  /* 2i 020644D0 */
s16 keep_mes_no;  /* 2i 020644D2 (3s 02068C52): in 2i the frames left on the current line (3s old_rno[3]) */
s16 efff9_mes_no;  /* 2i 020644D4: the ending message number (3s keep_mes_no), provisional name */
s16 efff9_mes_len;  /* 2i 020644D6: the line's cell count (3s old_rno[4]), provisional name */
s16 efff9_mes_show;  /* 2i 020644D8: cells shown so far (3s old_rno[5]), provisional name */
s16 efff9_mes_wait;  /* 2i 020644DA: frames to the next cell (3s old_rno[6]), provisional name */

/* the message tables are initialised RAM in 2i, still in the D blob (02008138 / 0200817C / 020081C0 / 02008204;
   txt_no_tbl at 020083E8) */
extern const EFFF9_MESSAGE* effF9_mes_jp[];
extern const EFFF9_MESSAGE* effF9_mes_en[];
extern const EFFF9_MESSAGE* effF9_mes_es[];
extern const EFFF9_MESSAGE* effF9_mes_pt[];
extern s32* txt_no_tbl[];


/* 2i 060E6E14, 3s-near: sf3 src/EFFF9.c:401 effect_F9_move */
void effect_F9_move(WORK_Other_CONN* ewk) {
    const u16* chr_data;
    const CONN* conn_data;
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        switch (Country) {
        case 1:
            conn_data = effF9_mes_jp[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_jp[ewk->master_player][mes_already].chr;
            break;
        case 2:
            conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
            break;
        case 3:
            switch (Language) {
            case 0:
                conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
                break;
            case 1:
                conn_data = effF9_mes_es[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_es[ewk->master_player][mes_already].chr;
                break;
            case 2:
                conn_data = effF9_mes_pt[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_pt[ewk->master_player][mes_already].chr;
                break;
            }
            break;
        case 4:
            conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
            break;
        case 5:
            conn_data = effF9_mes_es[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_es[ewk->master_player][mes_already].chr;
            break;
        case 6:
            conn_data = effF9_mes_pt[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_pt[ewk->master_player][mes_already].chr;
            break;
        case 7:
            switch (Language) {
            case 0:
                conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
                break;
            case 1:
                conn_data = effF9_mes_es[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_es[ewk->master_player][mes_already].chr;
                break;
            case 2:
                conn_data = effF9_mes_pt[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_pt[ewk->master_player][mes_already].chr;
                break;
            }
            break;
        default:
            conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
            break;
        }
        for (i = 0; i < chr_data[0]; i++) {
            load_char_gfx(chr_data[i + 1], 1);
        }
        ewk->num_of_conn = chr_data[i + 1];
        efff9_mes_len = chr_data[i + 1];
        if (efff9_mes_len == 0) {
            efff9_mes_show = 0;
        } else {
            efff9_mes_show = 1;
        }
        efff9_mes_wait = 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_cgnum = ewk->wu.cg_number = 0;
        for (i = 0; i < ewk->num_of_conn; i++) {
            ewk->conn[i].nx = conn_data[i].nx;
            ewk->conn[i].ny = conn_data[i].ny;
            ewk->conn[i].col = conn_data[i].col;
            ewk->conn[i].chr = conn_data[i].chr;
        }
        efff9_suicide = 0;
        ewk->wu.vitality = 240;
        ewk->num_of_conn = efff9_mes_show;
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        ewk->wu.routine_no[0]++;
        break;
    case 5:
        efff9_mes_wait--;
        if (efff9_mes_wait == 0) {
            efff9_mes_wait = 2;
            if (efff9_mes_len == efff9_mes_show) {
                efff9_mes_wait = 2;
            } else {
                efff9_mes_show++;
                if (Country != 1) {
                    efff9_mes_show++;
                    if (efff9_mes_len < efff9_mes_show) {
                        efff9_mes_show = efff9_mes_len;
                    }
                }
                ewk->num_of_conn = efff9_mes_show;
            }
        }
        if (keep_mes_no == 0) {
            Next_Talk_Message();
            ewk->wu.cg_number++;
            ewk->wu.cg_number &= 0x7FFF;
            sort_push_request3(&ewk->wu);
            break;
        }
        keep_mes_no--;
        if (efff9_suicide == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] += 2;
            break;
        }
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;
    case 6:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

/* Start the ending text effect for character pl_no. */
/* 2i 060E7130, 3s-near: sf3 src/EFFF9.c:549 effect_F9_init */
s32 effect_F9_init(s16 pl_no)
{
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    mes_already = 0;
    efff9_suicide = 0;
    efff9_txt_point = 0;
    efff9_wk_set((WORK_Other_CONN*)ewk);
    efff9_PL_NO = pl_no;
    ewk->master_player = efff9_PL_NO;
    return 0;
}



/* 2i 060E71AE, 3s-near: sf3 src/EFFF9.c:571 efff9_wk_set */
void efff9_wk_set(WORK_Other_CONN* ewk) {
    ewk->wu.be_flag = 1;
    ewk->wu.id = 159;
    ewk->wu.work_id = 16;
    ewk->wu.rl_flag = 0;
    ewk->wu.cgromtype = 1;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0;
    ewk->wu.my_family = 4;
    ewk->wu.my_priority = 5;
    ewk->wu.position_x = 312;
    ewk->wu.position_y = 24;
    ewk->wu.position_z = 5;
}



/* provisional name */
/* 2i 060E71F0, 3s-near: sf3 src/EFFF9.c:590 effF9_talk_init */
s32 effF9_talk_init(s16 pl) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    mes_already = 0;
    efff9_suicide = 0;
    efff9_txt_point = 0;
    effF9_talk_wk_set(ewk);
    efff9_PL_NO = pl;
    ewk->master_player = efff9_PL_NO;
    load_any_color(0x8D);
    return 0;
}



/* provisional name */
/* 2i 060E7250, 3s-near: sf3 src/EFFF9.c:611 effF9_talk_wk_set */
void effF9_talk_wk_set(WORK_Other* ewk) {
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x9F;
    ewk->wu.work_id = 0x10;
    ewk->wu.rl_flag = 0;
    ewk->wu.cgromtype = 1;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0;
    ewk->wu.my_family = 3;
    ewk->wu.my_priority = 5;
    if (Game_setting.mode == 0) {
        ewk->wu.position_x = 0x280;
    } else {
        ewk->wu.position_x = 0x2E8;
    }
    ewk->wu.position_y = 0x18;
    ewk->wu.position_z = 5;
}



/* 2i 060E72A0, 3s-near: sf3 src/EFFF9.c:633 Rewrite_End_Message */
s32 Rewrite_End_Message(u16 mes_no) {
    WORK_Other* ewk;
    s16 ix;
    ix = pull_effect_work(4);
    if (ix == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    efff9_mes_no = mes_no;
    ewk->wu.routine_no[0] = 0;
    efff9_suicide = 1;
    ewk->master_player = efff9_PL_NO;
    efff9_wk_set((WORK_Other_CONN*)ewk);
    efff9_txt_point = 2;
    efff9_txt_no_adrs = txt_no_tbl[efff9_PL_NO];
    efff9_txt_scene_adrs = (u16*)efff9_txt_no_adrs[mes_no];
    efff9_message = efff9_txt_scene_adrs[0];
    keep_mes_no = *(s16*)(efff9_txt_scene_adrs + 1);
    mes_already = efff9_message;
    return 0;
}



/* provisional name */
/* 2i 060E735A, 3s-near: sf3 src/EFFF9.c:658 Rewrite_Talk_Message */
s32 Rewrite_Talk_Message(u16 mes_no) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    efff9_mes_no = mes_no;
    ewk->wu.routine_no[0] = 0;
    efff9_suicide = 1;
    ewk->master_player = efff9_PL_NO;
    effF9_talk_wk_set(ewk);
    efff9_txt_point = 2;
    efff9_txt_no_adrs = txt_no_tbl[efff9_PL_NO];
    efff9_txt_scene_adrs = (u16*)efff9_txt_no_adrs[mes_no];
    efff9_message = efff9_txt_scene_adrs[0];
    keep_mes_no = *(s16*)(efff9_txt_scene_adrs + 1);
    mes_already = efff9_message;
    return 0;
}



/* provisional name */
/* 2i 060E73E4, 3s-near: sf3 src/EFFF9.c:682 Set_Direct_Message */
s32 Set_Direct_Message(s16 mes) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    efff9_suicide = 0;
    ewk->master_player = efff9_PL_NO;
    efff9_wk_set((WORK_Other_CONN*)ewk);
    mes_already = mes;
    return 0;
}



/* provisional name */
s32 Next_Talk_Message(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    efff9_suicide = 1;
    ewk->master_player = efff9_PL_NO;
    if (efff9_PL_NO >= 15) {
        effF9_talk_wk_set(ewk);
    } else {
        efff9_wk_set((WORK_Other_CONN*)ewk);
    }
    efff9_txt_no_adrs = txt_no_tbl[efff9_PL_NO];
    efff9_txt_scene_adrs = (u16*)efff9_txt_no_adrs[efff9_mes_no];
    efff9_message = efff9_txt_scene_adrs[efff9_txt_point];
    keep_mes_no = efff9_txt_scene_adrs[efff9_txt_point + 1];
    efff9_txt_point += 2;
    mes_already = efff9_message;
    return 0;
}
