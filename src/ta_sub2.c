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

/* a loop over the players */
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



static void bg_speed_disp(s8 r1, s8 r2, s8 stage, s8 area) {}

static void chase_xy_disp(s32 cal, s16 pos, s16 low) {}

void cal_bg_speed_data(bg_num, tm)
s16 bg_num;
s16 tm;
{
    MotionState ms;
    XY* xy = bg_w.bgw[bg_num].chase_xy;
    bg_speed_disp(bg_w.bg_r_1, bg_w.bg_r_2, bg_w.stage, bg_w.area);
    if (0) {
        return;
    }
    chase_xy_disp(xy->cal, xy->disp.pos, xy->disp.low);
    xy[0].disp.low = xy[1].disp.low = 0;
    (void)&((WORK*)bg_num)->be_flag;
    ms.timer = tm;
    ms.timer2 = (((ms.timer - 1) * ms.timer) / 2) + ms.timer;
    ms.x.ps.h = chase_x - bg_w.bgw[bg_num].chase_xy[0].disp.pos;
    ms.y.ps.h = chase_y - bg_w.bgw[bg_num].chase_xy[1].disp.pos;
    ms.y.ps.l = 0;
    ms.x.ps.l = 0;
    if (!ms.timer) {
        ms.amy = 0;
        ms.amx = 0;
        ms.spy = ms.dly = 0;
        ms.dlx = 0;
        ms.spx = 0;
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



/* provisional name */


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


/* provisional name */
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
        if (sw & 0x3F0) return 1;
    }
    if (plw[1].wu.operator) {
        sw = ~p2sw_1 & p2sw_0;
        if (sw & 0x3F0) return 1;
    }
    return 0;
}



