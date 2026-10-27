/*
 * EFFA8.C  Effect A8: result-screen fade controller
 *
 * Effect A8 puts screen picture 7, requests fade 69 and runs the fade with skipping forbidden.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "aboutspr.h"
#include "sc_trans.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Eff59.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "sc_sub.h"
#include "sc_sub_2.h"
#include "PLS02.h"
#include "effa8.h"

/* routine_no[0] */
#define R0_INIT         0       /* put the picture and start the fade */
#define R0_FADE         1       /* run the fade */
#define R0_DONE         2       /* finished */



void effect_A8_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        sc_picture_put(7, 0, 0);
        Request_Fade(69, 0);
        end_no_cut = 1;
        break;
    case R0_FADE:
        if (Fade_Flag) {
            fade_cont_main();
        } else {
            ewk->wu.routine_no[0]++;
            end_no_cut = 0;
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    case R0_DONE:
        break;
    }
}

u32 effect_A8_init(void)
{
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 108;
    ewk->wu.work_id = 16;
    return 0;
}
