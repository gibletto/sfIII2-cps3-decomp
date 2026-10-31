/*
 * EFFI9.C  Effect I9: after-image trail of a shell
 *
 * effect_I9_init is called for a shell (for example the homing shell kotp_06000 in EFF13.C) with
 * the number of images, the spacing and a life time. It copies the shell's colour and frame and
 * takes a second work from list 7 as a position buffer. effect_I9_move keeps the last 17 shell
 * positions in that buffer (push_image_buff / init_image_buff) and on its first frame spawns the
 * J0 images that draw from it. The trail ends when the life runs out or the shell is finishing,
 * and both works are then freed.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFJ0.h"
#include "effj1.h"
#include "effj2_code.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFI9.h"

/* routine_no[0] */
#define R0_INIT         0       /* fill the buffer, start the images */
#define R0_MOVE         1       /* record the shell's positions */
#define R0_END          2       /* one more frame */
#define R0_KILL         3       /* (default) put both works back */


void effect_I9_move(WORK_Other* ewk) {
    WORK* sub_w = (WORK*)ewk->wu.target_adrs;
    ImageBuff* image_buff = (ImageBuff*)sub_w + 9;
    WORK_Other* mwk = (WORK_Other*)ewk->my_master;
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        init_image_buff(mwk, image_buff);
        push_image_buff(mwk, image_buff);
        for (i = ewk->wu.dmcal_d; i > 0; i--) {
            effect_J0_init(ewk, mwk, i * ewk->wu.dmcal_m);
        }
        break;
    case R0_MOVE:
        push_image_buff(mwk, image_buff);
        if (ewk->wu.dead_f == 1) {
            ewk->wu.routine_no[0]++;
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
            }
        }
        return;
    case R0_END:
        ewk->wu.routine_no[0] = R0_KILL;
        break;
    default:
        push_effect_work(&ewk->wu);
        push_effect_work(sub_w);
        break;
    }
}


void push_image_buff(WORK_Other* wk, ImageBuff* image_buff) {
    s16 i;
    for (i = 16; i > 0; i--) {
        image_buff[i] = image_buff[i - 1];
    }
    image_buff->pos_x = wk->wu.position_x;
    image_buff->pos_y = wk->wu.position_y;
}



void init_image_buff(WORK_Other* wk, ImageBuff* image_buff) {
    s16 i;
    ImageBuff* p;
    for (i = 16; i >= 0; i--) {
        p = &image_buff[i];
        image_buff[i].pos_x = wk->wu.position_x;
        p->pos_y = wk->wu.position_y;
    }
}



s32 effect_I9_init(WORK_Other* wk, s16 total, s16 interval, s16 life) {
    WORK_Other* ewk;
    s16 ix;
    s16 ix2;
    WORK* sub_w;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 189;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = wk->wu.my_family;
    ewk->wu.cgromtype = wk->wu.cgromtype;
    ewk->wu.my_col_mode = wk->wu.my_col_mode;
    ewk->wu.my_col_code = wk->wu.my_col_code;
    ewk->wu.extra_col = wk->wu.current_colcd;
    ewk->wu.cg_number = wk->wu.cg_number;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_id = wk->wu.id;
    ewk->master_player = wk->master_player;
    ewk->wu.dmcal_d = total;
    ewk->wu.dmcal_m = interval;
    ewk->wu.dir_timer = life;
    ewk->wu.blink_timing = ewk->master_id;
    if ((ix2 = pull_effect_work(7)) == -1) {
        push_effect_work(&ewk->wu);
        return;
    }
    sub_w = (WORK*)frw[ix2];
    ewk->wu.target_adrs = (u32*)sub_w;
    return 0;
}
