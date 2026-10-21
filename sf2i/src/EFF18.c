/*
 * EFF18.C  Effect 17 (zoom-in pieces) and effect 18 (reacting stage objects)
 *
 * effect_17_init creates the nine pieces used by effect 04 from eff17_data_tbl. Each piece
 * follows its master's state: after its delay it appears and shrinks from double size to
 * normal (eff17_zoom_in), takes the master's colour, is displayed, and finally squashes
 * away (eff17_close); piece 8 reports each finished stage back to the master.
 * Effect 18 is a stage object with a behaviour routine: eff18_00 idles until a player
 * performs a special move and then hops, eff18_01 idles until a perfect victory and then
 * plays its celebration animation.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF18.h"



/* 2i: eleven object lists, named by their order in the ROM (provisional names; 3s has one, scr_obj_data18_0) */
extern const s16 scr_obj_data18_0[];
extern const s16 scr_obj_data18_1[];
extern const s16 scr_obj_data18_2[];
extern const s16 scr_obj_data18_3[];
extern const s16 scr_obj_data18_4[];
extern const s16 scr_obj_data18_5[];
extern const s16 scr_obj_data18_6[];
extern const s16 scr_obj_data18_7[];
extern const s16 scr_obj_data18_8[];
extern const s16 scr_obj_data18_9[];
extern const s16 scr_obj_data18_10[];

/* 2i 02007BEC (3s 02006C2C: one row) */
const s16* scr_obj_data18[8][4] = {
    { scr_obj_data18_0, scr_obj_data18_0, scr_obj_data18_0, scr_obj_data18_0 },
    { scr_obj_data18_1, scr_obj_data18_1, scr_obj_data18_1, scr_obj_data18_1 },
    { scr_obj_data18_2, scr_obj_data18_3, scr_obj_data18_2, scr_obj_data18_3 },
    { scr_obj_data18_4, scr_obj_data18_5, scr_obj_data18_6, scr_obj_data18_5 },
    { scr_obj_data18_7, scr_obj_data18_7, scr_obj_data18_7, scr_obj_data18_7 },
    { scr_obj_data18_8, scr_obj_data18_8, scr_obj_data18_8, scr_obj_data18_8 },
    { scr_obj_data18_9, scr_obj_data18_9, scr_obj_data18_9, scr_obj_data18_9 },
    { scr_obj_data18_10, scr_obj_data18_10, scr_obj_data18_10, scr_obj_data18_10 },
};
/* 2i 02007C6C (3s 02006C3C) */
void (*eff18_jp_tbl[2])(WORK_Other*) = {
    eff18_00,
    eff18_01,
};


/* 2i 060C7794, 3s-exact: sf3 src/EFF18.c:45 effect_17_move */
void effect_17_move(WORK_Other* ewk) {
    WORK* oya = (WORK*)ewk->my_master;
    switch (oya->routine_no[0]) {
    case 1:
        eff17_zoom_in(ewk);
        break;
    case 2:
        ewk->wu.extra_col = oya->extra_col;
    case 3:
        disp_pos_trans_entry5(ewk);
        break;
    case 4:
        eff17_close(ewk);
        break;
    case 5:
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* provisional name */
/* 2i 060C77F2, 3s-near: sf3 src/EFF18.c:71 eff17_zoom_in */
void eff17_zoom_in(WORK_Other* ewk) {
    WORK* oya = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 0;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        break;
    case 1:
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] < 0) {
            ewk->wu.disp_flag = 1;
            ewk->wu.routine_no[1]++;
        }
        break;
    case 2:
        ewk->wu.my_mr.size.x -= 7;
        ewk->wu.my_mr.size.y -= 7;
        if (ewk->wu.my_mr.size.x <= 63) {
            ewk->wu.my_mr.size.x = 63;
            ewk->wu.routine_no[1]++;
            if (ewk->wu.type == 8) {
                oya->old_rno[2] = 1;
            }
        }
    case 3:
        disp_pos_trans_entry5(ewk);
        break;
    }
}



/* provisional name */
/* 2i 060C78C6, 3s-exact: sf3 src/EFF18.c:108 eff17_close */
void eff17_close(WORK_Other* ewk) {
    WORK* oya = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.my_mr.size.y = ewk->wu.my_mr.size.y + -7;
        if (ewk->wu.my_mr.size.y <= 0) {
            ewk->wu.my_mr.size.y = 0;
            ewk->wu.routine_no[2]++;
            if ((u8)ewk->wu.type == 8) {
                oya->old_rno[2] = 1;
            }
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 1:
        break;
    }
}



/* 2i 060C790E, 3s-near: sf3 src/EFF18.c:129 effect_17_init */
s32 effect_17_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data = eff17_data_tbl[0];
    for (i = 0; i < 9; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.id = 17;
        ewk->wu.be_flag = 1;
        ewk->my_master = (u32*)wk;
        ewk->wu.type = i;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.char_table[0] = etc2_char_table;
        ewk->wu.my_col_code = 0x2080;
        ewk->wu.char_index = 50;
        ewk->wu.my_family = 2;
        ewk->wu.xyz[0].disp.pos = *data++;
        ewk->wu.xyz[1].disp.pos = *data++;
        ewk->wu.my_priority = ewk->wu.position_z = *data++;
        ewk->wu.old_rno[3] = *data++;
        ewk->wu.old_rno[1] = *data++;
    }
    return 0;
}



/* 2i 060C79E4, 3s-exact: sf3 src/EFF18.c:161 effect_18_move */
void effect_18_move(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }
    if (compel_dead_check(ewk)) {
        ewk->wu.routine_no[0] = 99;
        ewk->wu.disp_flag = 0;
    } else {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
        case 1:
            if (!EXE_flag && !Game_pause) {
                eff18_jp_tbl[ewk->wu.routine_no[1]](ewk);
            }
            if (ewk->wu.old_rno[0]) {
                disp_pos_trans_entry_rs(ewk);
            } else {
                disp_pos_trans_entry_s(ewk);
            }
            break;
        default:
            all_cgps_put_back(ewk);
            push_effect_work((WORK*)ewk);
        }
    }
}



/* provisional name */
/* 2i 060C7A78, 3s-near: sf3 src/EFF18.c:192 eff18_00 */
void eff18_00(WORK* wk) {
    switch (wk->routine_no[2]) {
    case 0:
        wk->routine_no[2]++;
        wk->disp_flag = 1;
        set_char_move_init(wk, 0, wk->dir_old);
    case 1:
        if (either_pl_hissatsu_check()) {
            wk->routine_no[2]++;
            wk->dir_timer = 5;
            wk->direction = 0;
        }
        if (wk->hit_stop && !EXE_obroll) {
            char_move(wk);
        }
        break;
    case 2:
        wk->direction++;
        if (wk->cg_type) {
            wk->cg_type = 0;
            wk->dir_timer -= wk->direction;
            if (wk->dir_timer < 0) {
                wk->routine_no[2] = 4;
                set_char_move_init(wk, 0, wk->dir_step);
            } else {
                wk->routine_no[2]++;
            }
        }
        if (wk->hit_stop && !EXE_obroll) {
            char_move(wk);
        }
        break;
    case 3:
        wk->dir_timer--;
        if (wk->dir_timer < 0) {
            wk->routine_no[2]++;
            set_char_move_init(wk, 0, wk->dir_step);
        }
        if (wk->hit_stop && !EXE_obroll) {
            char_move(wk);
        }
        break;
    case 4:
        if (!EXE_obroll) {
            char_move(wk);
        }
        if (wk->cg_type) {
            wk->cg_type = 0;
            wk->routine_no[2] = 0;
        }
        break;
    }
}



/* provisional name */
/* 2i 060C7BF0, 3s-exact: sf3 src/EFF18.c:249 eff18_01 */
void eff18_01(WORK* wk) {
    switch (wk->routine_no[2]) {
    case 0:
        wk->routine_no[2]++;
        wk->disp_flag = 1;
        set_char_move_init(wk, 0, wk->dir_old);
    case 1:
        if (complete_victory_check()) {
            wk->routine_no[2]++;
        }
        if (wk->hit_stop && !EXE_obroll) {
            char_move(wk);
        }
        break;
    case 2:
        wk->routine_no[2]++;
        set_char_move_init(wk, 0, wk->dir_step);
        break;
    case 3:
        if (!EXE_obroll) {
            char_move(wk);
        }
        break;
    }
}



/* 2i 060C7C82, 3s-near: sf3 src/EFF18.c:277 effect_18_init; 2i: char_add by stage and area */
s32 effect_18_init(s16 disp_index, s16 cursor_id, s16 sync_bg, s16 master_player) {
    s16 i;
    s16 ix;
    s16 lp_cnt;
    const s16* data_ptr;
    WORK_Other* ewk;

    lp_cnt = scr_obj_num18[disp_index][bg_w.compel_flag];
    if (!lp_cnt) {
        return;
    }
    data_ptr = scr_obj_data18[disp_index][bg_w.compel_flag];
    for (i = 0; i < lp_cnt; i++) {
        ix = pull_effect_work(4);
        if (ix == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 18;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.dead_f = *data_ptr++;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.dir_old = *data_ptr++;
        ewk->wu.dir_step = *data_ptr++;
        ewk->wu.hit_stop = *data_ptr++;
        ewk->wu.sync_suzi = *data_ptr++;
        ewk->wu.routine_no[1] = *data_ptr++;
        ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.char_table[0] = char_add[bg_w.stage][bg_w.area];
        suzi_offset_set(&ewk->wu);
    }
    return 0;
}
