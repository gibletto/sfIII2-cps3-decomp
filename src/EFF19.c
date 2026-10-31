/*
 * EFF19.C  Effect 19: a scaled stage object
 *
 * effect_19_init (no caller) creates one object (with a shadow) at 288, 24, and
 * effect_19_move plays the animation of its char_index, scaled (my_mr 58 x 58), until
 * compel_dead_check ends it.
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
#include "PLS02.h"
#include "aboutspr.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "color3rd.h"
#include "EFF19.h"

/* routine_no[0] */
#define R0_INIT         0       /* start the scaled animation */
#define R0_MOVE         1       /* animate until the stage ends */
#define R0_KILL         99      /* (default) put the work back */

/* Play the object's animation, scaled to 58 x 58, until the stage retires it. */
void effect_19_move(WORK_Other* ewk) {
    if (compel_dead_check(ewk)) {
        ewk->wu.routine_no[0] = R0_KILL;
    } else {
        switch (ewk->wu.routine_no[0]) {
        case R0_INIT:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.my_mr_flag = 1;
            ewk->wu.my_mr.size.x = 58;
            ewk->wu.my_mr.size.y = 58;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            break;
        case R0_MOVE:
            if (!EXE_flag && !Game_pause) {
                char_move(&ewk->wu);
            }
            sort_push_request(&ewk->wu);
            break;
        default:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    }
}



/* Create the scaled stage object, with its shadow, at (288, 24); nothing calls it. */
s32 effect_19_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    load_any_color(156);
    ewk->wu.be_flag = 1;
    ewk->wu.id = 19;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.work_id = 16;
    ewk->wu.char_index = 5;
    ewk->wu.my_family = 2;
    ewk->wu.position_x = 288;
    ewk->wu.position_y = 24;
    ewk->wu.my_priority = ewk->wu.position_z = 72;
    ewk->wu.char_table[0] = eff19_char_table;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2054;
    ewk->wu.sync_suzi = 0;
    ewk->wu.cg_ix = 0;
    ewk->wu.rl_flag = 1;
    ewk->wu.kage_flag = 1;
    ewk->wu.kage_hx = 8;
    ewk->wu.kage_hy = 24;
    ewk->wu.kage_char = 13;
    ewk->wu.kage_prio = ewk->wu.my_priority + 1;
    return 0;
}
