/*
 * CALDIR.C  Direction and trajectory calculation library
 *
 * caldir_pos_128/64/32/16/8 return the direction from one point to another in 128, 64, 32,
 * 16 or 8 steps; caldir_wk_* do the same between two works' display positions.
 * cal_move_quantity* project a work's position a number of frames ahead from its speed and
 * acceleration. The cmsd_* and cal_*_speed routines work out initial speeds and
 * accelerations so that a work reaches a given point in a given number of frames
 * (cal_all_speed_data, cal_initial_speed, cal_delta_speed, cal_initial_speed_y0), and
 * cal_top_of_position_y / cal_time_of_sign_change / cal_move_dir_forecast predict the top
 * of a jump and its timing.
 * Used by effects and stage objects that fly to target positions.
 * remake_2_10 packs numbers into BCD.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CALDIR.h"

/* 2i 06082E30, 3s-exact: sf3 src/CALDIR.c:22 caldir_pos_256 */
s32 caldir_pos_256(x1, x2, y1, y2)
s16 x1;
s16 x2;
s16 y1;
s16 y2;
{
    s16 yhan;
    s16 tent = yhan = 0;
    switch (((y1 -= x1) < 0) + (((y2 -= x2) < 0) << 1)) {
    case 1:
        y1 = -y1;
        yhan = 1;
        break;
    case 2:
        y2 = -y2;
        yhan = 1;
        tent = 0x80;
        break;
    case 3:
        y1 = -y1;
        y2 = -y2;
        tent = 0x80;
        break;
    }
    if (y1 > y2) {
        while (y1 > 0x7F) {
            y1 >>= 1;
            y2 >>= 1;
        }
    } else {
        while (y2 > 0x7F) {
            y1 >>= 1;
            y2 >>= 1;
        }
    }
    tent += dir_sel_table[y1][y2];
    if (yhan) {
        tent = -tent;
        tent &= 0xFF;
    }
    return tent;
}



/* provisional name */
/* 2i 06082ED6, 3s-exact: sf3 src/CALDIR.c:68 caldir_pos_128 */
s16 caldir_pos_128(s16 x1, s16 x2, s16 y1, s16 y2) {
    return caldir_pos_256(x1, x2, y1, y2) >> 1;
}



/* provisional name */
/* 2i 06082F02, 3s-exact: sf3 src/CALDIR.c:75 caldir_pos_64 */
s16 caldir_pos_64(s16 x1, s16 x2, s16 y1, s16 y2) {
    return (caldir_pos_256(x1, x2, y1, y2) + 2) >> 2 & 0x3F;
}



/* 2i 06082F34, 3s-reloc: sf3 src/CALDIR.c:81 caldir_pos_032 */
s16 caldir_pos_032(x1, x2, y1, y2)
s16 x1;
s16 x2;
s16 y1;
s16 y2;
{
    return (caldir_pos_256(x1, x2, y1, y2) + 4) >> 3 & 0x1F;
}



/* provisional name */
/* 2i 06082F70, 3s-exact: sf3 src/CALDIR.c:93 caldir_pos_16 */
s16 caldir_pos_16(s16 x1, s16 x2, s16 y1, s16 y2) {
    return (caldir_pos_256(x1, x2, y1, y2) + 8) >> 4 & 0xF;
}



/* provisional name */
/* 2i 06082FA6, 3s-exact: sf3 src/CALDIR.c:100 caldir_pos_8 */
s16 caldir_pos_8(s16 x1, s16 x2, s16 y1, s16 y2) {
    return (caldir_pos_256(x1, x2, y1, y2) + 16) >> 5 & 7;
}



/* provisional name: unreferenced */
/* 2i 06082FDE, 3s-exact: sf3 src/CALDIR.c:107 caldir_wk_256 */
s32 caldir_wk_256(WORK* wk, WORK* emwk) {
    return caldir_pos_256(wk->xyz[0].disp.pos, wk->xyz[1].disp.pos, emwk->xyz[0].disp.pos, emwk->xyz[1].disp.pos);
}



/* provisional name */
/* 2i 06083004, 3s-exact: sf3 src/CALDIR.c:114 caldir_wk_128 */
s16 caldir_wk_128(WORK* wk, WORK* emwk) {
    return caldir_pos_256(wk->xyz[0].disp.pos, wk->xyz[1].disp.pos, emwk->xyz[0].disp.pos, emwk->xyz[1].disp.pos) >> 1;
}



/* provisional name */
/* 2i 06083032, 3s-exact: sf3 src/CALDIR.c:121 caldir_wk_64 */
s16 caldir_wk_64(WORK* wk, WORK* emwk) {
    return (caldir_pos_256(wk->xyz[0].disp.pos, wk->xyz[1].disp.pos, emwk->xyz[0].disp.pos, emwk->xyz[1].disp.pos) + 2) >>
           2 & 0x3F;
}



/* provisional name */
/* 2i 06083066, 3s-exact: sf3 src/CALDIR.c:129 caldir_wk_32 */
s16 caldir_wk_32(WORK* wk, WORK* emwk) {
    return (caldir_pos_256(wk->xyz[0].disp.pos, wk->xyz[1].disp.pos, emwk->xyz[0].disp.pos, emwk->xyz[1].disp.pos) + 4) >>
           3 & 0x1F;
}



/* provisional name */
/* 2i 0608309C, 3s-exact: sf3 src/CALDIR.c:137 caldir_wk_16 */
s16 caldir_wk_16(WORK* wk, WORK* emwk) {
    return (caldir_pos_256(wk->xyz[0].disp.pos, wk->xyz[1].disp.pos, emwk->xyz[0].disp.pos, emwk->xyz[1].disp.pos) + 8) >>
           4 & 0xF;
}



/* provisional name */
/* 2i 060830D4, 3s-exact: sf3 src/CALDIR.c:145 caldir_wk_8 */
s16 caldir_wk_8(WORK* wk, WORK* emwk) {
    return (caldir_pos_256(wk->xyz[0].disp.pos, wk->xyz[1].disp.pos, emwk->xyz[0].disp.pos, emwk->xyz[1].disp.pos) +
            16) >>
           5 & 7;
}



/* provisional name */
/* 2i 0608310E, 3s-exact: sf3 src/CALDIR.c:154 add_pos_dir_256 */
void add_pos_dir_256(WORK* wk, s16 sp) {
    wk->xyz[0].cal += (rate_256_table[wk->direction][0] * sp) >> 8;
    wk->xyz[1].cal += (rate_256_table[wk->direction][1] * sp) >> 8;
}



/* provisional name */
/* 2i 06083172, 3s-exact: sf3 src/CALDIR.c:162 add_pos_dir_128 */
void add_pos_dir_128(WORK* wk, s16 sp) {
    wk->xyz[0].cal += (rate_256_table[wk->direction * 2][0] * sp) >> 8;
    wk->xyz[1].cal += (rate_256_table[wk->direction * 2][1] * sp) >> 8;
}



/* 2i 060831DA, 3s-exact: sf3 src/CALDIR.c:169 add_pos_dir_064 */
void add_pos_dir_064(WORK* wk, s16 sp) {
    wk->xyz[0].cal += (rate_256_table[wk->direction * 4][0] * sp) >> 8;
    wk->xyz[1].cal += (rate_256_table[wk->direction * 4][1] * sp) >> 8;
}



/* provisional name */
/* 2i 06083242, 3s-reloc: sf3 src/CALDIR.c:177 add_pos_dir_032 */
void add_pos_dir_032(WORK* wk, s16 sp) {
    wk->xyz[0].cal += (rate_256_table[wk->direction * 8][0] * sp) >> 8;
    wk->xyz[1].cal += (rate_256_table[wk->direction * 8][1] * sp) >> 8;
}



/* provisional name */
/* 2i 060832B4, 3s-exact: sf3 src/CALDIR.c:185 add_pos_dir_016 */
void add_pos_dir_016(WORK* wk, s16 sp) {
    wk->xyz[0].cal += (rate_256_table[wk->direction * 16][0] * sp) >> 8;
    wk->xyz[1].cal += (rate_256_table[wk->direction * 16][1] * sp) >> 8;
}



/* provisional name */
/* 2i 06083320, 3s-exact: sf3 src/CALDIR.c:193 add_pos_dir_008 */
void add_pos_dir_008(WORK* wk, s16 sp) {
    wk->xyz[0].cal += (rate_256_table[wk->direction * 32][0] * sp) >> 8;
    wk->xyz[1].cal += (rate_256_table[wk->direction * 32][1] * sp) >> 8;
}



/* provisional name */
/* 2i 06083390, 3s-exact: sf3 src/CALDIR.c:201 dir256_to_128 */
s16 dir256_to_128(s16 dir) {
    return dir >> 1;
}



/* provisional name */
/* 2i 06083396, 3s-exact: sf3 src/CALDIR.c:208 dir256_to_064 */
s16 dir256_to_064(s16 dir) {
    return (dir + 2) >> 2 & 63;
}



/* provisional name */
/* 2i 060833A2, 3s-exact: sf3 src/CALDIR.c:215 dir256_to_032 */
s16 dir256_to_032(s16 dir) {
    return (dir + 4) >> 3 & 31;
}



/* provisional name */
/* 2i 060833B0, 3s-exact: sf3 src/CALDIR.c:222 dir256_to_016 */
s16 dir256_to_016(s16 dir) {
    return (dir + 8) >> 4 & 15;
}



/* provisional name */
/* 2i 060833C0, 3s-exact: sf3 src/CALDIR.c:229 dir256_to_008 */
s16 dir256_to_008(s16 dir) {
    return (dir + 16) >> 5 & 7;
}



/* provisional name */
/* 2i 060833D2, 3s-reloc: sf3 src/CALDIR.c:236 cal_move_quantity */
s16 cal_move_quantity(WORK* wk, s16 t) {
    XY pos[2];
    s32 time;
    if (t == 0) {
        return 0;
    }
    time = t;
    pos[0].cal = time * time / 2 * wk->mvxy.d[0].sp;
    pos[0].cal = wk->mvxy.a[0].sp * time + pos[0].cal + wk->xyz[0].cal;
    pos[1].cal = time * time / 2 * wk->mvxy.d[1].sp;
    pos[1].cal = wk->mvxy.a[1].sp * time + pos[1].cal + wk->xyz[1].cal;
    return cal_move_quantity2(wk->xyz[0].disp.pos, wk->xyz[1].disp.pos, pos[0].disp.pos, pos[1].disp.pos);
}


/* 2i 06083468, 3s-exact: sf3 src/CALDIR.c:251 cal_move_quantity2 */
s16 cal_move_quantity2(s16 x1, s16 x2, s16 y1, s16 y2) {
    s16 kakudo;
    MS ms;
    if ((y1 -= x1) < 0) {
        y1 = -y1;
    }
    if ((y2 -= x2) < 0) {
        y2 = -y2;
    }
    x1 = y1;
    x2 = y2;
    if (y1 > y2) {
        while (y1 > 0x7F) {
            y1 >>= 1;
            y2 >>= 1;
        }
    } else {
        while (y2 > 0x7F) {
            y1 >>= 1;
            y2 >>= 1;
        }
    }
    kakudo = dir_sel_table[y1][y2];
    ms.psi = (x1 * rate_256_table[kakudo][0]);
    ms.psi += x2 * rate_256_table[kakudo][1];
    return ms.pss.h;
}


/* 2i 06083502, 3s-exact: sf3 src/CALDIR.c:280 cal_move_quantity3 */
s16 cal_move_quantity3(WORK* wk, s16 tm) {
    s32 ltm;
    PS_DY ps;
    if (tm == 0) {
        return wk->xyz[1].disp.pos;
    }
    ltm = tm;
    ps.dy = ltm * ltm / 2 * wk->mvxy.d[1].sp;
    ps.dy = (wk->mvxy.a[1].sp * ltm) + ps.dy + wk->xyz[1].cal;
    return ps.ry.h;
}


/* provisional name */
/* 2i 06083548, 3s-exact: sf3 src/CALDIR.c:294 cal_move_quantity_dummy */
void cal_move_quantity_dummy(void) {}



/* 2i 0608354C, 3s-exact: sf3 src/CALDIR.c:298 cmsd_all_x_speed_data */
void cmsd_all_x_speed_data(MotionState* cc) {
    switch (cc->swx) {
    case 1:
        cmsd_swx_1(cc);
        break;
    case 2:
        cmsd_swx_2(cc);
        break;
    default:
        cmsd_swx_0(cc);
        break;
    }
}



/* 2i 06083568, 3s-reloc: sf3 src/CALDIR.c:314 cmsd_all_y_speed_data */
void cmsd_all_y_speed_data(MotionState* cc) {
    switch (cc->swy) {
    case 1:
        cmsd_swy_1(cc);
        break;
    case 2:
        cmsd_swy_2(cc);
        break;
    default:
        cmsd_swy_0(cc);
        break;
    }
}



/* 2i 06083590, 3s-reloc: sf3 src/CALDIR.c:330 cmsd_swx_0 */
void cmsd_swx_0(MotionState* cc) {
    cc->amx = cc->x.pl % cc->timer;
    cc->spx = cc->x.pl / cc->timer;
    cc->dlx = 0;
}



/* 2i 060835AE, 3s-reloc: sf3 src/CALDIR.c:338 cmsd_swy_0 */
void cmsd_swy_0(MotionState* cc) {
    cc->amy = cc->y.pl % cc->timer;
    cc->spy = cc->y.pl / cc->timer;
    cc->dly = 0;
}



/* 2i 060835CC, 3s-reloc: sf3 src/CALDIR.c:346 cmsd_swx_1 */
void cmsd_swx_1(MotionState* cc) {
    cc->amx = cc->x.pl % cc->timer2;
    cc->spx = cc->dlx = cc->x.pl / cc->timer2;
}



/* 2i 060835E8, 3s-reloc: sf3 src/CALDIR.c:353 cmsd_swy_1 */
void cmsd_swy_1(MotionState* cc) {
    cc->amy = cc->y.pl % cc->timer2;
    cc->spy = cc->dly = cc->y.pl / cc->timer2;
}



/* 2i 06083604, 3s-reloc: sf3 src/CALDIR.c:360 cmsd_swx_2 */
void cmsd_swx_2(MotionState* cc) {
    cc->amx = cc->x.pl % cc->timer2;
    cc->dlx = cc->x.pl / cc->timer2;
    cc->spx = cc->dlx * cc->timer;
    cc->dlx = -cc->dlx;
}



/* 2i 06083634, 3s-reloc: sf3 src/CALDIR.c:369 cmsd_swy_2 */
void cmsd_swy_2(MotionState* cc) {
    cc->amy = cc->y.pl % cc->timer2;
    cc->dly = cc->y.pl / cc->timer2;
    cc->spy = cc->dly * cc->timer;
    cc->dly = -cc->dly;
}



/* 2i 06083664, 3s-reloc: sf3 src/CALDIR.c:378 cmsd_x_initial_speed */
void cmsd_x_initial_speed(MotionState* cc) {
    cc->amx = cc->x.pl - (cc->timer2 * cc->dlx);
    cc->spx = cc->dlx + (cc->amx / cc->timer);
    cc->amx %= cc->timer;
}



/* 2i 06083694, 3s-reloc: sf3 src/CALDIR.c:386 cmsd_y_initial_speed */
void cmsd_y_initial_speed(MotionState* cc) {
    cc->amy = cc->y.pl - cc->timer2 * cc->dly;
    cc->spy = cc->amy / cc->timer + cc->dly;
    cc->amy %= cc->timer;
}



/* 2i 060836C6, 3s-reloc: sf3 src/CALDIR.c:394 cmsd_x_delta_speed */
void cmsd_x_delta_speed(MotionState* cc) {
    if (cc->spx != 0) {
        cc->amx = cc->x.pl - cc->timer * cc->spx;
        cc->dlx = cc->amx / cc->timer2;
        cc->amx %= cc->timer2;
        cc->spx += cc->dlx;
    } else {
        cmsd_all_x_speed_data(cc);
    }
}



/* 2i 0608370A, 3s-reloc: sf3 src/CALDIR.c:407 cmsd_y_delta_speed */
void cmsd_y_delta_speed(MotionState* cc) {
    if (cc->spy != 0) {
        cc->amy = cc->y.pl - (cc->timer * cc->spy);
        cc->dly = cc->amy / cc->timer2;
        cc->amy %= cc->timer2;
        cc->spy += cc->dly;
    } else {
        cmsd_all_y_speed_data(cc);
    }
}



/* 2i 0608374C, 3s-near: sf3 src/CALDIR.c:420 cal_all_speed_data */
void cal_all_speed_data(wk, tm, x1, y1, xsw, ysw)
WORK* wk;
s16 tm;
s16 x1;
s16 y1;
s8 xsw;
s8 ysw;
{
    MotionState bb;
    wk->xyz[0].disp.low = wk->xyz[1].disp.low = 0;
    bb.timer = tm;
    bb.timer2 = bb.timer + (bb.timer * (bb.timer - 1) / 2);
    bb.x.ps.h = x1 - wk->xyz[0].disp.pos;
    bb.y.ps.h = y1 - wk->xyz[1].disp.pos;
    bb.x.ps.l = bb.y.ps.l = 0;
    bb.swx = xsw;
    bb.swy = ysw;
    if (bb.timer == 0) {
        bb.amy = 0;
        bb.amx = 0;
        bb.dly = 0;
        bb.spy = 0;
        bb.dlx = 0;
        bb.spx = 0;
    } else {
        cmsd_all_x_speed_data(&bb);
        cmsd_all_y_speed_data(&bb);
    }
    wk->mvxy.a[0].sp = bb.spx;
    wk->mvxy.d[0].sp = bb.dlx;
    wk->mvxy.a[1].sp = bb.spy;
    wk->mvxy.d[1].sp = bb.dly;
    wk->xyz[0].cal += bb.amx;
    wk->xyz[1].cal += bb.amy;
    wk->mvxy.kop[0] = wk->mvxy.kop[1] = 0;
}



/* 2i 06083816, 3s-near: sf3 src/CALDIR.c:459 cal_initial_speed */
void cal_initial_speed(wk, tm, x1, y1)
WORK* wk;
s16 tm;
s16 x1;
s16 y1;
{
    MotionState bb;
    wk->xyz[0].disp.low = wk->xyz[1].disp.low = 0;
    bb.timer = tm;
    bb.timer2 = bb.timer + bb.timer * (bb.timer - 1) / 2;
    bb.x.ps.h = x1 - wk->xyz[0].disp.pos;
    bb.y.ps.h = y1 - wk->xyz[1].disp.pos;
    bb.x.ps.l = bb.y.ps.l = 0;
    bb.dlx = wk->mvxy.d[0].sp;
    bb.dly = wk->mvxy.d[1].sp;
    if (bb.timer == 0) {
        bb.amy = 0;
        bb.amx = 0;
        bb.spy = 0;
        bb.spx = 0;
    } else {
        cmsd_x_initial_speed(&bb);
        cmsd_y_initial_speed(&bb);
    }
    wk->mvxy.a[0].sp = bb.spx;
    wk->mvxy.a[1].sp = bb.spy;
    wk->xyz[0].cal += bb.amx;
    wk->xyz[1].cal += bb.amy;
}



/* 2i 060838C2, 3s-reloc: sf3 src/CALDIR.c:491 cal_initial_speed_y */
void cal_initial_speed_y(WORK* wk, s16 tm, s16 y1) {
    MotionState bb;
    wk->xyz[1].disp.low = 0;
    bb.timer = tm + 0;
    bb.timer2 = bb.timer + bb.timer * (bb.timer - 1) / 2;
    bb.y.ps.h = y1 - wk->xyz[1].disp.pos;
    bb.y.ps.l = 0;
    bb.dly = wk->mvxy.d[1].sp;
    if (bb.timer == 0) {
        bb.amy = 0;
        bb.spy = 0;
    } else {
        cmsd_y_initial_speed(&bb);
    }
    wk->mvxy.a[1].sp = bb.spy;
    wk->xyz[1].cal += bb.amy;
}



/* 2i 06083934, 3s-reloc: sf3 src/CALDIR.c:511 cal_delta_speed */
void cal_delta_speed(wk, tm, x1, y1, xsw, ysw)
WORK* wk;
s16 tm;
s16 x1;
s16 y1;
s8 xsw;
s8 ysw;
{
    MotionState bb;
    wk->xyz[0].disp.low = wk->xyz[1].disp.low = 0;
    bb.timer = tm + 0;
    bb.timer2 = bb.timer + bb.timer * (bb.timer - 1) / 2;
    bb.x.ps.h = x1 - wk->xyz[0].disp.pos;
    bb.y.ps.h = y1 - wk->xyz[1].disp.pos;
    bb.x.ps.l = bb.y.ps.l = 0;
    bb.swx = xsw;
    bb.swy = ysw;
    bb.spx = wk->mvxy.a[0].sp;
    bb.spy = wk->mvxy.a[1].sp;
    if (bb.timer == 0) {
        bb.amy = 0;
        bb.amx = 0;
        bb.dly = 0;
        bb.dlx = 0;
    } else {
        cmsd_x_delta_speed(&bb);
        cmsd_y_delta_speed(&bb);
    }
    wk->mvxy.a[0].sp = bb.spx;
    wk->mvxy.d[0].sp = bb.dlx;
    wk->mvxy.a[1].sp = bb.spy;
    wk->mvxy.d[1].sp = bb.dly;
    wk->xyz[0].cal += bb.amx;
    wk->xyz[1].cal += bb.amy;
}



/* provisional name */
/* 2i 060839FC, 3s-near: sf3 src/CALDIR.c:550 cal_initial_speed_y0 */
void cal_initial_speed_y0(WORK* wk, s16 tm) {
    MotionState bb;
    wk->xyz[0].disp.low = wk->xyz[1].disp.low = 0;
    bb.timer = tm;
    bb.timer2 = bb.timer + bb.timer * (bb.timer - 1) / 2;
    bb.y.ps.h = 0;
    bb.y.ps.l = 0;
    bb.dly = wk->mvxy.d[1].sp;
    if (bb.timer) {
        cmsd_y_initial_speed(&bb);
    } else {
        bb.spy = 0;
    }
    wk->mvxy.a[1].sp = bb.spy;
}



/* 2i 06083A5A, 3s-near: sf3 src/CALDIR.c:568 cal_top_of_position_y */
s16 cal_top_of_position_y(WORK* wk) {
    register s32 num;
    s32 num2;
    PS_UNI ps_uni;
    if ((num = cal_time_of_sign_change(wk)) == 0) {
        return wk->xyz[1].disp.pos;
    }
    num2 = num * (num - 1) / 2 + num;
    ps_uni.psy = num * wk->mvxy.a[1].sp + num2 * wk->mvxy.d[1].sp + wk->xyz[1].cal;
    return ps_uni.psys.h;
}



/* 2i 06083AB2, 3s-near: sf3 src/CALDIR.c:582 cal_time_of_sign_change */
s32 cal_time_of_sign_change(WORK* wk) {
    s16 num;

    if (wk->mvxy.d[1].sp != 0) {
        num = wk->mvxy.a[1].sp / -wk->mvxy.d[1].sp;
        return num;
    }
    return 0;
}



/* 2i 06083ADC, 3s-near: sf3 src/CALDIR.c:591 cal_move_dir_forecast */
s32 cal_move_dir_forecast(WORK* wk, s16 tm) {
    PS_DP ps[2];
    s32 time;
    s16 direction;
    if (tm == 0) {
        return 0;
    }
    time = tm;
    ps[0].dp = time * time / 2 * wk->mvxy.d[0].sp;
    ps[0].dp = wk->mvxy.a[0].sp * time + ps[0].dp + wk->xyz[0].cal;
    ps[1].dp = time * time / 2 * wk->mvxy.d[1].sp;
    ps[1].dp = wk->mvxy.a[1].sp * time + ps[1].dp + wk->xyz[1].cal;
    direction = caldir_pos_032(wk->xyz[0].disp.pos, wk->xyz[1].disp.pos, ps[0].rp.h, ps[1].rp.h);
    return direction;
}

