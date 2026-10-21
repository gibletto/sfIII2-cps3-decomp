/*
 * EFF95.C  Effect 95: the win and ranking screen characters (2nd Impact only)
 *
 * 3rd Strike effect 95 is the continue screen character. 2nd Impact rewrote it: effect_95_init (called from Win_2nd
 * with kind 16 for the winner and 0 for the loser) puts the player's character on BG1 through
 * eff95_set_obj, adding the extra parts some characters have (types 1, -1, 16, 0x80, 32, 48: by My_char
 * and, for one pair, Country); eff95_set_position and eff95_set_speed place it by WINNER and
 * Game_setting.mode and give it its slide speed, eff95_rl_check its facing. effect_95_rank_init
 * (Ranking_Sub) makes the ranking screen's character on BG0.
 * effect_95_move shows the object and moves it in x by mvxy.a[0], which is zeroed unless
 * stop_flag_02014400 (a 2nd Impact word after Demo_Time_Stop) is set.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Eff95.h"

/* 2nd Impact tables (CTBL 0617A12C / 0617A13C / 0617A14C), provisional names */
extern const s8 eff95_col_tbl_win[16];
extern const s8 eff95_col_tbl_lose[16];
extern const s16 eff95_ofs_tbl[16][2];





/* an object drifting in x (speed held only while stop_flag_02014400) */
void effect_95_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_timer + 1, 0);
        break;
    default:
        if (stop_flag_02014400 == 0) {
            ewk->wu.mvxy.a[0].sp = 0;
        }
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    }
}



s32 effect_95_init(s16 kind, s16 pl) {
    eff95_set_obj(kind, pl, 0);
    if (kind == 0 && My_char[pl] == 8) {
        eff95_set_obj(kind, pl, 1);
    }
    if (kind == 16 && My_char[pl] == 4) {
        eff95_set_obj(kind, pl, -1);
    }
    if (kind == 16 && My_char[pl] == 6) {
        eff95_set_obj(kind, pl, 16);
    }
    if (kind == 16 && My_char[pl] == 12) {
        eff95_set_obj(kind, pl, 0x80);
    }
    if (kind == 0 && My_char[pl] == 12) {
        eff95_set_obj(kind, pl, 0x80);
    }
    if (kind == 0 && Country != 1 && (My_char[pl] == 14 || My_char[pl] == 15)) {
        eff95_set_obj(kind, pl, 32);
    }
    if (kind == 0 && My_char[pl] == 0) {
        eff95_set_obj(kind, pl, 48);
    }
    return 0;
}



/* provisional name */
s32 eff95_set_obj(s16 kind, s16 pl, s16 type) {
    WORK_Other* ewk;
    s16 ix;
    s16 col;
    s16 ofs;
    s32 player;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 95;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    player = pl;
    eff95_set_position(ewk, player);
    ewk->wu.rl_flag = eff95_rl_check(player);
    if (kind == 0) {
        ewk->wu.position_z = 51;
        ofs = 0x90;
        col = eff95_col_tbl_lose[My_char[pl]];
        ewk->wu.my_col_code = col * Player_Color[LOSER] + ofs;
        if (My_char[LOSER] == 0) {
            if (pl == 0) {
                ewk->wu.my_col_code = col + ofs;
            } else {
                ewk->wu.my_col_code = ofs;
            }
        }
    } else {
        ewk->wu.position_z = 60;
        col = eff95_col_tbl_win[My_char[pl]];
        ewk->wu.my_col_code = col * Player_Color[WINNER] + 112;
        if (My_char[WINNER] == 0) {
            if (pl == 0) {
                ewk->wu.my_col_code = 112;
            } else {
                ewk->wu.my_col_code = col + 112;
            }
        }
    }
    ewk->wu.dir_timer = (My_char[pl] & 0x7F) + kind;
    ewk->wu.char_index = 9;
    ewk->wu.char_table[0] = sel_pl_char_table;
    switch (type) {
    case 0:
        break;
    case 1:
        ewk->wu.position_z = 50;
        ewk->wu.dir_timer = 32;
        break;
    case 16:
        ewk->wu.position_z = 59;
        ewk->wu.dir_timer = 34;
        ewk->wu.mvxy.a[0].sp = ewk->wu.mvxy.a[0].sp * 5 / 4;
        ewk->wu.my_col_code = 0x2066;
        if (Player_Color[WINNER] == 6) {
            ewk->wu.my_col_code += 2;
            break;
        }
        if (WINNER == 0) {
            ewk->wu.xyz[0].disp.pos += 24;
        } else {
            ewk->wu.xyz[0].disp.pos -= 24;
            ewk->wu.my_col_code++;
        }
        break;
    case 0x80:
        if (kind == 0) {
            ewk->wu.position_z = 50;
            ewk->wu.dir_timer = 35;
        } else {
            ewk->wu.my_priority = 59;
            ewk->wu.position_z = 59;
            ewk->wu.dir_timer = 36;
        }
        break;
    case 32:
        ewk->wu.position_z = 50;
        ewk->wu.dir_timer = 37;
        break;
    case 48:
        ewk->wu.position_z = 50;
        ewk->wu.dir_timer = 38;
        break;
    default:
        ewk->wu.position_z = 61;
        ewk->wu.dir_timer = 33;
        ewk->wu.mvxy.a[0].sp /= 2;
        if (WINNER == 0) {
            ewk->wu.xyz[0].disp.pos += 32;
        } else {
            ewk->wu.xyz[0].disp.pos -= 32;
        }
        break;
    }
    return 0;
}



/* provisional name */
s8 eff95_rl_check(s16 pl) {
    if (pl == 1 && WINNER == 1 && (My_char[pl] == 14 || My_char[pl] == 15)) {
        return 0;
    }
    if (WINNER == 0) {
        return 0;
    }
    return 1;
}



s32 effect_95_rank_init(s16 kind, s16 pl, s16 flag, s16 color) {
    WORK_Other* ewk;
    s16 ix;
    s16 col;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 95;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 1;
    ewk->wu.mvxy.a[0].sp = 0;
    ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[0].xy[0].disp.pos - DE_X[14] - 32;
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].xy[1].disp.pos - 48;
    ewk->wu.position_z = 85;
    ewk->wu.dir_timer = pl + kind;
    ewk->wu.char_index = 9;
    ewk->wu.char_table[0] = sel_pl_char_table;
    col = eff95_col_tbl_win[pl];
    ewk->wu.my_col_code = col * color + 112;
    return 0;
}



/* provisional name */
void eff95_set_position(WORK_Other* ewk, s16 pl) {
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].xy[1].disp.pos;
    if (Game_setting.mode) {
        if (pl == 0) {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos + DE_X[10] + 0xA0;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos + DE_X[10] + 0xE0;
        }
        eff95_set_speed(ewk, pl);
        ewk->wu.mvxy.a[0].sp = 0;
    } else {
        if (WINNER == 0) {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos + DE_X[10] + 0x80;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos + DE_X[10] + 0x100;
        }
        eff95_set_speed(ewk, pl);
    }
}



/* provisional name */
void eff95_set_speed(WORK_Other* ewk, s16 pl) {
    if (WINNER == 0) {
        if (pl) {
            ewk->wu.mvxy.a[0].sp = 0x8000;
            ewk->wu.xyz[0].disp.pos += eff95_ofs_tbl[My_char[pl]][1];
        } else {
            ewk->wu.mvxy.a[0].sp = 0x4000;
            ewk->wu.xyz[0].disp.pos += eff95_ofs_tbl[My_char[pl]][0];
        }
    } else {
        if (pl) {
            ewk->wu.mvxy.a[0].sp = -0x4000;
            if (My_char[pl] == 14 || My_char[pl] == 15) {
                ewk->wu.xyz[0].disp.pos += 128;
            } else {
                ewk->wu.xyz[0].disp.pos -= eff95_ofs_tbl[My_char[pl]][0];
            }
        } else {
            ewk->wu.mvxy.a[0].sp = -0x8000;
            ewk->wu.xyz[0].disp.pos -= eff95_ofs_tbl[My_char[pl]][1];
        }
    }
}
