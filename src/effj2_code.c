/*
 * EFFJ2_CODE.C  Effect J2: bonus-stage level plate
 *
 * Effect J2 is the bonus-stage level plate: effect_J2_init (from Game_Main.c) builds a six-part
 * connected sprite (id 192) from bbbs_nando_large; after its delay it shows its connected sprites
 * with the digit for Bonus_Stage_Level fixed to the BG1 screen position (effJ2_trans) for 60
 * frames. The digit cell's pattern is set directly.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "effj2_code.h"

/* routine_no[0] */
#define R0_WAIT         0       /* wait for the delay */
#define R0_SHOW         1       /* show the plate for a second */
#define R0_END          2       /* hidden for a frame */
#define R0_KILL         3       /* (default) put the work back */

/* routine_no[1] */
#define R1_INIT         0       /* hide on the first frame */



void effect_J2_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        switch (ewk->wu.routine_no[1]) {
        case R1_INIT:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            ewk->wu.old_cgnum = 0;
            /* fall through */
        default:
            if (--ewk->wu.dir_timer > 0) {
                break;
            }
            ewk->wu.routine_no[0]++;
            ewk->wu.routine_no[1] = R1_INIT;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_cgnum = 0;
            ewk->wu.dir_timer = 60;
            ewk->wu.position_z = ewk->wu.my_priority = 27;
            ewk->conn[0].chr = Bonus_Stage_Level % 10 + 0xB2EB;
            break;
        }
        break;
    case R0_SHOW:
        if (ewk->wu.dead_f == 1) {
            goto end;
        }
        if (--ewk->wu.dir_timer <= 0) {
        end:
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = R0_END;
            break;
        }
        effJ2_trans(&ewk->wu);
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



void effJ2_trans(WORK* ewk) {
    ewk->cg_number = (ewk->cg_number + 1) & 0x7FFF;
    if (ewk->cg_number == 0) {
        ewk->cg_number = 1;
    }
    ewk->position_x = bg_w.bgw[1].wxy[0].disp.pos;
    ewk->position_y = bg_w.bgw[1].wxy[1].disp.pos;
    sort_push_request3(ewk);
}


s32 effect_J2_init(s16 delay) {
    WORK_Other_CONN* ewk;
    s16 ix;
    s16 i;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 192;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2080;
    ewk->wu.dir_timer = delay;
    ewk->num_of_conn = 6;
    for (i = 0; i < 6; i++) {
        ewk->conn[i] = bbbs_nando_large[i];
    }
    return 0;
}
