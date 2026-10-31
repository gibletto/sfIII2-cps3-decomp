/*
 * EFFJ0.C  Effect J0: shell after-image
 *
 * Effect J0 is one image of a shell's after-image trail. effect_J0_init is called by effect I9
 * (EFFI9.C) with the image's delay in the trail; effect_J0_move draws the shell's current frame,
 * flip and graphics at the position the shell had that many frames ago (read from I9's image
 * buffer), and ends with its timer or when the shell starts to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFJ0.h"

/* routine_no[0] */
#define R0_INIT         0       /* show */
#define R0_MOVE         1       /* draw the shell's old position */
#define R0_END          2       /* hidden for a frame */
#define R0_KILL         3       /* (default) put the work back */



void effect_J0_move(WORK_Other* ewk) {
    WORK_Other* mwk = (WORK_Other*)ewk->my_master;
    WORK_Other* cwk = (WORK_Other*)ewk->wu.target_adrs;
    WORK* sub_w = (WORK*)cwk->wu.target_adrs;
    ImageBuff* image_buff = (ImageBuff*)sub_w + 9;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.cg_att_ix = 0;
        ewk->wu.cg_hit_ix = 0;
        sort_push_request(&ewk->wu);
        break;
    case R0_MOVE:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = R0_END;
            break;
        }
        if (mwk->wu.routine_no[0] >= 2 || mwk->wu.routine_no[1] >= 2) {
            ewk->wu.routine_no[0] = R0_END;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (!EXE_flag && !Game_pause && mwk->wu.hit_stop <= 0) {
            if (--ewk->wu.dir_timer == 0) {
                ewk->wu.routine_no[0] = R0_END;
                break;
            }
            ewk->wu.position_x = image_buff[ewk->wu.dir_step].pos_x;
            ewk->wu.position_y = image_buff[ewk->wu.dir_step].pos_y;
        }
        ewk->wu.old_cgnum = ewk->wu.cg_number = mwk->wu.cg_number;
        ewk->wu.rl_flag = mwk->wu.rl_flag;
        ewk->wu.spr.gfx_ofs = mwk->wu.spr.gfx_ofs;
        ewk->wu.spr.gfx_cells = mwk->wu.spr.gfx_cells;
        ewk->wu.spr.sprite_flip = mwk->wu.spr.sprite_flip;
        ewk->wu.cg_flip = mwk->wu.cg_flip;
        ewk->wu.done_rl = mwk->wu.done_rl;
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



s32 effect_J0_init(WORK_Other* ek, WORK_Other* mk, s16 data) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = 2;
    ewk->wu.id = 190;
    ewk->wu.old_cgnum = ek->wu.cg_number = mk->wu.cg_number;
    ewk->wu.dir_step = data;
    ewk->wu.position_x = ewk->wu.old_pos[0] = mk->wu.position_x;
    ewk->wu.position_y = ewk->wu.old_pos[1] = mk->wu.position_y;
    ewk->wu.rl_flag = mk->wu.rl_flag;
    ewk->wu.cg_flip = mk->wu.cg_flip;
    ewk->wu.blink_timing = mk->wu.blink_timing;
    ewk->wu.spr.gfx_ofs = mk->wu.spr.gfx_ofs;
    ewk->wu.spr.gfx_cells = mk->wu.spr.gfx_cells;
    ewk->wu.spr.sprite_flip = mk->wu.spr.sprite_flip;
    ewk->wu.done_rl = mk->wu.done_rl;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = mk->wu.my_family;
    ewk->wu.cgromtype = mk->wu.cgromtype;
    ewk->wu.my_col_mode = mk->wu.my_col_mode;
    ewk->wu.my_col_code = mk->wu.my_col_code;
    ewk->wu.extra_col = mk->wu.current_colcd;
    ewk->my_master = (u32*)mk;
    ewk->wu.target_adrs = (u32*)ek;
    ewk->master_id = mk->wu.id;
    ewk->master_player = mk->master_player;
    ewk->wu.dir_timer = ek->wu.dir_timer;
    return 0;
}



