/*
 * EFF16.C  Effect 16: bonus-stage score display
 *
 * Effect 16 shows a player's score in the bonus stage as a row of digit characters. The
 * total is split into digits with bunkai_table / bunkai_numobj
 * (score_bunkai_eff16), the digits appear one at a time every 3 frames and are
 * then redrawn every frame in front of the background (eff16_trans).
 * effect_16_init is called from BBBSCOM.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "EFF16.h"

/* routine_no[0] */
#define R0_APPEAR       0       /* show the digits one by one */
#define R0_MOVE         1       /* redraw the score every frame */
#define R0_END          2       /* hidden for a frame */
#define R0_KILL         3       /* (default) put the work back */

/* routine_no[1] */
#define R1_INIT         0       /* split the score into digits */
#define R1_ADD          1       /* add a digit every 3 frames */




void effect_16_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_APPEAR:
        switch (ewk->wu.routine_no[1]) {
        case R1_INIT:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_cgnum = 0;
            ewk->wu.my_priority = ewk->wu.position_z = 67;
            ewk->wu.next_z = 29;
            ((WORK_Other_CONN*)ewk)->num_of_conn = score_bunkai_eff16((WORK_Other_CONN*)ewk, Score[ewk->wu.type][0]);
            ewk->wu.direction = ((WORK_Other_CONN*)ewk)->num_of_conn;
            ((WORK_Other_CONN*)ewk)->num_of_conn = 0;
            ewk->wu.dir_timer = 0;
            break;
        case R1_ADD:
            if (--ewk->wu.dir_timer <= 0) {
                ewk->wu.dir_timer = 3;
                ((WORK_Other_CONN*)ewk)->num_of_conn++;
                if (((WORK_Other_CONN*)ewk)->num_of_conn < ewk->wu.direction) {
                    break;
                }
                ewk->wu.routine_no[0] = R0_MOVE;
                ewk->wu.routine_no[1] = R1_INIT;
            }
            break;
        }
        eff16_trans(&ewk->wu);
        break;
    case R0_MOVE:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = R0_END;
            break;
        }
        ((WORK_Other_CONN*)ewk)->num_of_conn = score_bunkai_eff16((WORK_Other_CONN*)ewk, Score[ewk->wu.type][0]);
        eff16_trans(&ewk->wu);
        break;
    case R0_END:
        ewk->wu.routine_no[0] = R0_KILL;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff16_trans(WORK* ewk) {
    ewk->cg_number = (ewk->cg_number + 1) & 0x7FFF;
    if (ewk->cg_number == 0) {
        ewk->cg_number = 1;
    }
    ewk->position_x = bg_w.bgw[1].wxy[0].disp.pos;
    ewk->position_y = bg_w.bgw[1].wxy[1].disp.pos;
    if (ewk->position_z == ewk->next_z) {
        ewk->position_z = ewk->my_priority;
    } else {
        ewk->position_z = ewk->next_z;
    }
    sort_push_request3(ewk);
}



s32 score_bunkai_eff16(WORK_Other_CONN* ewk, u32 tsc) {
    s16 noobjans = 0;
    s16 i;
    s16 ixs[8];
    s16 ixa[8];
    for (i = 6; i > 0; i--) {
        ixa[i] = tsc / bunkai_table[i];
        ixs[i] = tsc = tsc % bunkai_table[i];
    }
    ixa[i] = tsc;
    for (i = 0; i < 7; i++) {
        if ((ewk->conn[i].chr = bunkai_numobj[ixa[i]]) != 0xB2CD) {
            noobjans = i + 1;
        }
    }
    return noobjans;
}



s32 effect_16_init(wk, flag)
    PLW* wk;
    s16 flag;
{
    WORK_Other_CONN* ewk;
    s16 ix;
    s16 i;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 16;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.type = wk->wu.rl_flag;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2080;
    ewk->num_of_conn = 7;
    ix = Game_setting.Screen_Mode != 0;
    ix *= 2;
    if (wk->wu.rl_flag) {
        ix++;
    }
    for (i = 0; i < 7; i++) {
        ewk->conn[i] = bbbs_score[ix][i];
    }
    return 0;
}
