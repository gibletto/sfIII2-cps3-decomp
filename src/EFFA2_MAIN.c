/*
 * EFFA2_MAIN.C  Effect A2: break-in banner tilemap wipe
 *
 * effect_A2_init (called from Entry.c when a new challenger breaks in) creates the effect for a
 * tilemap row (3rd Strike also switches the effect 76 priorities there; 2nd Impact does not).
 * effect_A2_move clears Disp_PERFECT and the banner area of the text layer on its first frame,
 * then each frame draws two more columns of the break-in banner with break_into_banner_trans,
 * and frees itself after 48 columns.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub2.h"
#include "EffA2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "sc_trans.h"
#include "sc_clear.h"
#include "EFFA2_MAIN.h"



void effect_A2_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        Disp_PERFECT = 0;
        tilemap_clear_rect(1, 8, DE_X[1] + 47, 21);
        break_into_banner_trans(ewk->wu.dir_timer, 0);
        break;
    }
    break_into_banner_trans(ewk->wu.dir_timer, ewk->wu.direction);
    ewk->wu.direction++;
    break_into_banner_trans(ewk->wu.dir_timer, ewk->wu.direction);
    if (ewk->wu.direction < 48) {
        ewk->wu.direction++;
    } else {
        push_effect_work(&ewk->wu);
    }
}



/* no Switch_Priority_76 call */
s32 effect_A2_init(timer)
s16 timer;
{
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 102;
    ewk->wu.dir_timer = timer;
    ewk->wu.direction = 1;
    return 0;
}
