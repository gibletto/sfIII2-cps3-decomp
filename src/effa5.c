/*
 * EFFA5.C  Effect A5: select timer
 *
 * Effect A5 (effect_A5_entry, started by sel_pl.c and next_cpu.c) is the select-screen timer:
 * it counts Select_Timer down in BCD every 50 frames, holds while Time_Stop or Break_Into is set,
 * and sets Time_Over 30 frames after the timer reaches zero.
 * 2nd Impact: no Break_Into hold; the timer ends while Exit_No is set (no Check_Sleep_A5 routine).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "Eff93.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "sc_trans.h"
#include "effa5.h"

extern s16 Exit_No;



/* no Break_Into hold; the timer ends while Exit_No is set (3rd Strike's Check_Sleep_A5 has no code of its own in 2nd Impact) */
void effect_A5_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Exit_No) {
            ewk->wu.routine_no[0] = 4;
            Time_Stop = -1;
            break;
        }
        if (Time_Stop == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case 1:
        if (Exit_No) {
            ewk->wu.routine_no[0] = 4;
            Time_Stop = -1;
            break;
        }
        if (--Unit_Of_Timer) {
            break;
        }
        Unit_Of_Timer = 50;
        bcdext = 0;
        if ((Select_Timer = sbcd(1, Select_Timer)) == 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 30;
        }
        break;
    case 2:
        if (Exit_No) {
            ewk->wu.routine_no[0] = 4;
            Time_Stop = -1;
            break;
        }
        if (Select_Timer) {
            ewk->wu.routine_no[0] = 1;
            Unit_Of_Timer = 50;
        } else if (--ewk->wu.dir_timer == 0) {
            Time_Over = 1;
            ewk->wu.routine_no[0]++;
        }
        break;
    case 3:
        Time_Over = 1;
        if (Exit_No) {
            ewk->wu.routine_no[0] = 4;
            Time_Stop = -1;
            break;
        }
        if (Select_Timer) {
            ewk->wu.routine_no[0] = 1;
            Unit_Of_Timer = 50;
        }
        break;
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}



u32 effect_A5_entry(void)
{
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 105;
    return 0;
}
