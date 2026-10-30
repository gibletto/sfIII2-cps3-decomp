/*
 * EFF00.C  Effect 00 (judgement box display)
 *
 * Effect 00 draws a character's judgement boxes (body, hand, catch, caught, attack, hosei)
 * over it. Which boxes are shown is chosen by the extra DIP switches or judge_disp_all; in
 * the debug editors it shows the edited or looked-up box set instead. effect_00_init is
 * called from the debug screens in CMD_MAIN.
 * There are 13 box rows (two hand rows, h_dumm, h_eat, one catch, one caught); the DIP bit is chosen by
 * master_id, and the boxes are cleared when no box set is shown.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFF00.h"
#include "fighter.h"

/* routine_no[0] */
#define R0_INIT         0       /* set up from the master */
#define R0_MOVE         1       /* follow the master and show its boxes */
#define R0_END          2       /* hidden for a frame */
#define R0_KILL         3       /* (default) put the work back */

void effect_00_move(WORK_Other_JUDGE* ewk) {
    u16 dip;
    ewk->fade_cja.l += 0x2000;
    ewk->fade_cja.w = ewk->fade_cja.w & 3;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        renewal_table_address(ewk, ewk->my_master);
        ewk->wu.cgromtype = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = ewk->wu.spr.disp_colcd = 0x203F;
        ewk->wu.my_priority = ewk->wu.position_z = 16;
        ewk->wu.cg_number = 0x7800;
        ewk->curr_ja = ewk->look_up_flag = 0;
        break;
    case R0_MOVE:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = R0_END;
            break;
        }
        if (ewk->my_master->waku_work_index != ewk->wu.myself) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = R0_END;
            break;
        }
        dip = exsw_1 & 0x3F00;
        if ((ewk->master_id == 0 && (dip & 0x1000) != 0) || (ewk->master_id == 1 && (dip & 0x2000) != 0) || judge_disp_all != 0) {
            if (judge_disp_all) {
                ewk->ja_disp_bit = jdb[15];
                ewk->wu.spr.gfx_cells = jdb2[15];
            } else {
                dip = (dip >> 8) & 0xF;
                ewk->ja_disp_bit = jdb[dip];
                ewk->wu.spr.gfx_cells = jdb2[dip];
            }
        } else {
            ewk->wu.spr.gfx_cells = 0;
            ewk->ja_disp_bit = 0;
        }
        renewal_table_address(ewk, ewk->my_master);
        renewal_table_data(ewk);
        sort_push_request2((WORK_Other*)ewk);
        break;
    case R0_END:
        ewk->wu.routine_no[0] = R0_KILL;
        break;
    default:
        all_cgps_put_back((WORK_Other*)ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void renewal_table_address(WORK_Other_JUDGE* ewk, WORK* twk) {
    ewk->wu.rl_flag = twk->rl_flag;
    if (judge_disp_all == 0) {
        if (twk->disp_flag) {
            ewk->wu.disp_flag = 1;
        } else {
            ewk->wu.disp_flag = 0;
        }
    }
    if (Debug_Box_Edit) {
        ewk->wu.h_bod = dbg_copy_buf.h_bod;
        ewk->wu.h_han = dbg_copy_buf.h_han;
        ewk->wu.h_dumm = dbg_copy_buf.h_dumm;
        ewk->wu.h_att = dbg_copy_buf.h_att;
        ewk->wu.h_eat = dbg_copy_buf.h_eat;
        ewk->wu.h_cat = dbg_copy_buf.h_cat;
        ewk->wu.h_cau = dbg_copy_buf.h_cau;
        ewk->wu.h_hos = dbg_copy_buf.h_hos;
    } else if (ewk->look_up_flag) {
        ewk->wu.h_bod = dbg_look_buf.h_bod;
        ewk->wu.h_han = dbg_look_buf.h_han;
        ewk->wu.h_dumm = dbg_look_buf.h_dumm;
        ewk->wu.h_att = dbg_look_buf.h_att;
        ewk->wu.h_eat = dbg_look_buf.h_eat;
        ewk->wu.h_cat = dbg_look_buf.h_cat;
        ewk->wu.h_cau = dbg_look_buf.h_cau;
        ewk->wu.h_hos = dbg_look_buf.h_hos;
    } else {
        ewk->wu.h_bod = twk->h_bod;
        ewk->wu.h_han = twk->h_han;
        ewk->wu.h_dumm = twk->h_dumm;
        ewk->wu.h_cat = twk->h_cat;
        ewk->wu.h_cau = twk->h_cau;
        ewk->wu.h_att = twk->h_att;
        ewk->wu.h_eat = twk->h_eat;
        ewk->wu.h_hos = twk->h_hos;
    }
    if (test_flag) {
        ewk->wu.position_x = twk->position_x;
        ewk->wu.position_y = twk->position_y;
    } else {
        ewk->wu.position_x = twk->xyz[0].disp.pos;
        ewk->wu.position_y = twk->xyz[1].disp.pos;
    }
}



void renewal_table_data(WORK_Other_JUDGE* ewk) {
    u16* mm;
    s16 i;
    s16 j;
    for (mm = (u16*)ewk->wu.h_bod, i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            *(&ewk->jx[i][0] + j) = *mm++;
        }
    }
    for (mm = (u16*)ewk->wu.h_han, i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            ewk->jx[i + 4][j] = *mm++;
        }
    }
    for (mm = (u16*)ewk->wu.h_cat, j = 0; j < 4; j++) {
        ewk->jx[6][j] = *mm++;
    }
    for (mm = (u16*)ewk->wu.h_cau, j = 0; j < 4; j++) {
        ewk->jx[7][j] = *mm++;
    }
    for (mm = (u16*)ewk->wu.h_att, i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            ewk->jx[i + 8][j] = *mm++;
        }
    }
    for (mm = (u16*)ewk->wu.h_eat, i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            ewk->jx[i + 10][j] = *mm++;
        }
    }
    for (mm = (u16*)ewk->wu.h_hos, j = 0; j < 4; j++) {
        ewk->jx[12][j] = *mm++;
    }
    for (i = 0; i < 13; i++) {
        ewk->ja[i * 4][0] = ewk->ja[i * 4 + 2][0] = ewk->jx[i][0];
        ewk->ja[i * 4 + 1][0] = ewk->ja[i * 4 + 3][0] = ewk->jx[i][0] + ewk->jx[i][1];
        ewk->ja[i * 4 + 2][1] = ewk->ja[i * 4 + 3][1] = ewk->jx[i][2];
        ewk->ja[i * 4][1] = ewk->ja[i * 4 + 1][1] = ewk->jx[i][2] + ewk->jx[i][3];
    }
    ewk->ja[52][0] = ewk->ja[52][1] = 0;
    ewk->ja[53][0] = 0;
    ewk->ja[53][1] = -ewk->wu.position_y;
}



s32 effect_00_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(0)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0;
    ewk->wu.work_id = 128;
    ewk->wu.charset_id = wk->charset_id;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.my_ext_pri = wk->my_ext_pri;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->work_id;
    ewk->master_id = wk->id;
    wk->waku_work_index = ewk->wu.myself;
    return 0;
}
