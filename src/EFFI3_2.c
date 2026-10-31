/*
 * EFFI3_2.C  Effect I3: stop the background for a while
 *
 * effect_I3_init(wk, tm) starts a work that holds bg_stop for tm frames, or until the work is
 * killed or a Suicide request comes; then it clears bg_stop and frees itself.
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
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFFI3.h"

/* routine_no[0] */
#define R0_INIT         0       /* stop the background */
#define R0_HOLD         1       /* hold until the time runs out */
#define R0_KILL         2       /* restart the background and free */



void effect_I3_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        bg_stop = 1;
        /* fall through */
    case R0_HOLD:
        if (ewk->wu.dead_f == 1 || Suicide != 0) {
            ewk->wu.routine_no[0]++;
            break;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
            if (--ewk->wu.type <= 0) {
                ewk->wu.routine_no[0]++;
            }
        }
        break;
    case R0_KILL:
    default:
        bg_stop = 0;
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_I3_init(wk, tm)
WORK* wk;
u8 tm;
{
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 183;
    ewk->wu.work_id = 16;
    ewk->wu.type = tm;
    return 0;
}
