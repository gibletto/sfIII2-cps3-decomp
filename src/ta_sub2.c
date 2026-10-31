/*
 * TA_SUB2.C  Stage background speed helpers
 *
 * win_lose_work_clear clears the win/lose pose routine numbers of both players.
 * cal_bg_speed_data, cal_bg_speed_data_x and cal_bg_speed_data_y compute the speed and deceleration
 * that bring a BG plane's chase position to the target (chase_x / chase_y) in a given number of
 * frames, spreading the remainder so the plane arrives exactly. pl_shot_trg_check reports whether an
 * operated player has just pressed an attack button.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg000.h"
#include "PLS02.h"
#include "ta_sub2.h"

/* Clear a_rno and the win and lose works, looping over the players. */
void win_lose_work_clear(void) {
    s16 i;
    a_rno = 0;
    lose_rno[2] = 0;
    for (i = 0; i < 2; i++) {
        win_rno[i] = 0;
        win_free[i] = 0;
        lose_rno[i] = 0;
        lose_free[i] = 0;
    }
}



void cal_bg_speed_data(bg_num, tm)
s16 bg_num;
s16 tm;
{
    MotionState ms;
    bg_w.bgw[bg_num].chase_xy[0].disp.low = bg_w.bgw[bg_num].chase_xy[1].disp.low = 0;
    ms.timer = tm;
    ms.timer2 = (((ms.timer - 1) * ms.timer) / 2) + ms.timer;
    ms.x.ps.h = chase_x - bg_w.bgw[bg_num].chase_xy[0].disp.pos;
    ms.y.ps.h = chase_y - bg_w.bgw[bg_num].chase_xy[1].disp.pos;
    ms.x.ps.l = ms.y.ps.l = 0;
    if (!ms.timer) {
        ms.spx = ms.dlx = ms.spy = ms.dly = ms.amx = ms.amy = 0;
    } else {
        ms.amx = ms.x.pl % ms.timer2;
        ms.spx = ms.dlx = ms.x.pl / ms.timer2;
        ms.amy = ms.y.pl % ms.timer2;
        ms.spy = ms.dly = ms.y.pl / ms.timer2;
    }
    bg_mvxy.a[0].sp = ms.spx;
    bg_mvxy.d[0].sp = ms.dlx;
    bg_mvxy.a[1].sp = ms.spy;
    bg_mvxy.d[1].sp = ms.dly;
    bg_w.bgw[bg_num].chase_xy[0].cal += ms.amx;
    bg_w.bgw[bg_num].chase_xy[1].cal += ms.amy;
    bg_mvxy.kop[0] = bg_mvxy.kop[1] = 0;
}



void cal_bg_speed_data_x(bg_num, tm, dummy)
s16 bg_num;
s16 tm;
s16 dummy;
{
    MotionState ms;
    bg_w.bgw[bg_num].chase_xy[0].disp.low = 0;
    ms.timer = tm;
    ms.timer2 = (ms.timer - 1) * ms.timer / 2 + ms.timer;
    ms.x.ps.h = chase_x - bg_w.bgw[bg_num].chase_xy[0].disp.pos;
    ms.x.ps.l = 0;
    if (!ms.timer) {
        ms.amx = 0;
        ms.dlx = 0;
        ms.spx = 0;
    } else {
        ms.amx = ms.x.pl % ms.timer2;
        ms.spx = ms.dlx = ms.x.pl / ms.timer2;
    }
    bg_mvxy.a[0].sp = ms.spx;
    bg_mvxy.d[0].sp = ms.dlx;
    bg_w.bgw[bg_num].chase_xy[0].cal += ms.amx;
    bg_mvxy.kop[0] = 0;
}


void cal_bg_speed_data_y(bg_num, tm, dummy)
s16 bg_num;
s16 tm;
s16 dummy;
{
    MotionState ms;
    bg_w.bgw[bg_num].chase_xy[1].disp.low = 0;
    ms.timer = tm;
    ms.timer2 = (ms.timer - 1) * ms.timer / 2 + ms.timer;
    ms.y.ps.h = chase_y - bg_w.bgw[bg_num].chase_xy[1].disp.pos;
    ms.y.ps.l = 0;
    if (!ms.timer) {
        ms.amy = 0;
        ms.dly = 0;
        ms.spy = 0;
    } else {
        ms.amy = ms.y.pl % ms.timer2;
        ms.spy = ms.dly = ms.y.pl / ms.timer2;
    }
    bg_mvxy.a[1].sp = ms.spy;
    bg_mvxy.d[1].sp = ms.dly;
    bg_w.bgw[bg_num].chase_xy[1].cal += ms.amy;
    bg_mvxy.kop[1] = 0;
}



/* provisional name: a human player has just pressed a button, unreferenced */
s32 pl_shot_trg_check(void) {
    u16 sw;
    if (plw[0].wu.operator) {
        sw = ~p1sw_1 & p1sw_0;
        if (sw & BUTTON_SHOTS) return 1;
    }
    if (plw[1].wu.operator) {
        sw = ~p2sw_1 & p2sw_0;
        if (sw & BUTTON_SHOTS) return 1;
    }
    return 0;
}



