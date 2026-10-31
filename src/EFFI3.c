/*
 * EFFI3.C  Effect I2 (182): stage colour cycling
 *
 * effect_I2_init starts the work; effect_I2_move steps through effI2_col_tbl, holding each colour
 * for its effI2_timer_tbl entry.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "charmove_2.h"
#include "color3rd.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFFI3.h"

/* routine_no[0] */
#define R0_INIT         0       /* start the cycle */
#define R0_MOVE         1       /* step the colours until told to end */
#define R0_KILL         2       /* put the work back */



s32 effect_I2_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 182;
    ewk->wu.operator = 0;
    ewk->wu.type = effI2_timer_tbl[0];
    return 0;
}



void effect_I2_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        /* fall through */
    case R0_MOVE:
        if (Suicide) {
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            return;
        }
        ewk->wu.type--;
        if (ewk->wu.type == 0) {
            ewk->wu.operator++;
            if (ewk->wu.operator > 9) {
                ewk->wu.operator = 0;
            }
            ewk->wu.type = effI2_timer_tbl[ewk->wu.operator];
            load_any_color(effI2_col_tbl[ewk->wu.operator]);
            return;
        }
        break;
    case R0_KILL:
    default:
        push_effect_work(&ewk->wu);
        return;
    }
}
