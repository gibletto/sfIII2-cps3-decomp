/*
 * EFF56.C  Effect 56: palette steps
 *
 * Effect 56 steps through eight palette steps.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "Eff59.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "sc_trans.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "aboutspr.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "eff56.h"
#include "sc_logo.h"

void load_any_color();



/* 2i 060CFD80, 3s-exact: sf3 src/eff56.c:59 effect_56_init */
s32 effect_56_init(s8 side)
{
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 56;
    ewk->wu.rl_flag = side;
    ewk->wu.operator = 0;
    ewk->wu.type = eff56_timer_tbl[side][0];
    return 0;
}



/* 2i 060CFDCE, 3s-reloc: sf3 src/eff56.c:78 effect_56_move */
void effect_56_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
    case 1:
        ewk->wu.type--;
        if (ewk->wu.type == 0) {
            ewk->wu.operator++;
            if (ewk->wu.operator > 7) {
                ewk->wu.operator = 0;
            }
            ewk->wu.type = eff56_timer_tbl[ewk->wu.rl_flag][ewk->wu.operator];
            load_any_color(eff56_color_tbl[ewk->wu.rl_flag][ewk->wu.operator]);
        }
        break;
    default:
    case 2:
        push_effect_work(&ewk->wu);
        break;
    }
}



