/*
 * EFFH6_CODE.C  Effect H6: staff-roll text
 *
 * Effect H6 is one staff-roll line. effect_H6_init builds its character sprites from the string
 * through code_tab ('#' lines are one picture) and entry type 0-5 sets how it slides in, holds
 * and leaves at roll_rate; there is one character bank. end_cut_check reports whether the winner is holding an attack button
 * to speed the roll up, unless end_no_cut is set.
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
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "end_main.h"
#include "effh6_code.h"

/* routine_no[0] */
#define R0_INIT         0       /* show the line */
#define R0_MOVE         1       /* roll the line */
#define R0_HIDE         2       /* hide the line */
#define R0_END          3       /* one more frame */

/* routine_no[1], how a text line comes and goes */
#define R1_RIGHT        0       /* in from the right, hold, back out */
#define R1_RISE         1       /* rise into place, hold, rise away */
#define R1_LEFT         2       /* in from the left, hold, back out */
#define R1_HOLD         3       /* show until the timer runs out */
#define R1_RISE_LONG    4       /* rise, hold longer, rise away */
#define R1_STILL        5       /* show until the roll ends */

/* routine_no[2], steps of R1_RIGHT, R1_RISE, R1_LEFT, R1_RISE_LONG */
#define R2_IN           0       /* move into place */
#define R2_HOLD         1       /* hold until the timer runs out */
#define R2_OUT          2       /* move off the screen */

s16 roll_rate;
s16 roll_rate_t;

s32 end_cut_check(void) {
    u16 sw;
    if (!end_no_cut) {
        if (WINNER) {
            sw = p2sw_0;
        } else {
            sw = p1sw_0;
        }
        if (sw & 0x7F0) {
            return 1;
        }
    }
    return 0;
}

void effect_H6_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        if (!ewk->wu.dir_step) {
            ewk->wu.old_cgnum = ewk->wu.cg_number = 0;
            ewk->wu.cg_number++;
            ewk->wu.cg_number &= 0x7FFF;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        break;
    case R0_MOVE:
        if (end_cut_check()) {
            roll_rate = 60;
            roll_rate_t = 5;
        } else {
            roll_rate = 12;
            roll_rate_t = 1;
        }
        if (ewk->wu.dir_step) {
            sort_push_request4(&ewk->wu);
            return;
        }
        switch (ewk->wu.routine_no[1]) {
        case R1_RIGHT:
            switch (ewk->wu.routine_no[2]) {
            case R2_IN:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos - roll_rate;
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                if (ewk->wu.routine_no[5] >= ewk->wu.xyz[0].disp.pos) {
                    ewk->wu.xyz[0].disp.pos = ewk->wu.routine_no[5];
                    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                    ewk->wu.routine_no[2]++;
                    ewk->wu.dir_timer = ewk->wu.dir_timer - 48;
                }
                break;
            case R2_HOLD:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                if (ewk->wu.dir_timer <= 0) {
                    ewk->wu.routine_no[2]++;
                }
                break;
            case R2_OUT:
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos + roll_rate;
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                if (ewk->wu.xyz[0].disp.pos >= 0x200) {
                    ewk->wu.routine_no[0]++;
                }
                break;
            }
            break;
        case R1_RISE:
            switch (ewk->wu.routine_no[2]) {
            case R2_IN:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                ewk->wu.xyz[1].disp.pos = ewk->wu.xyz[1].disp.pos + roll_rate;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                if (ewk->wu.routine_no[6] <= ewk->wu.xyz[1].disp.pos) {
                    ewk->wu.xyz[1].disp.pos = ewk->wu.routine_no[6];
                    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                    ewk->wu.routine_no[2]++;
                    ewk->wu.dir_timer = ewk->wu.dir_timer - 30;
                }
                break;
            case R2_HOLD:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                if (ewk->wu.dir_timer <= 0) {
                    ewk->wu.routine_no[2]++;
                }
                break;
            case R2_OUT:
                ewk->wu.xyz[1].disp.pos = ewk->wu.xyz[1].disp.pos + roll_rate;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                if (ewk->wu.xyz[1].disp.pos >= 0x100) {
                    ewk->wu.routine_no[0]++;
                }
                break;
            }
            break;
        case R1_LEFT:
            switch (ewk->wu.routine_no[2]) {
            case R2_IN:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos + roll_rate;
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                if (ewk->wu.routine_no[5] <= ewk->wu.xyz[0].disp.pos) {
                    ewk->wu.xyz[0].disp.pos = ewk->wu.routine_no[5];
                    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                    ewk->wu.routine_no[2]++;
                    ewk->wu.dir_timer = ewk->wu.dir_timer - 48;
                }
                break;
            case R2_HOLD:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                if (ewk->wu.dir_timer <= 0) {
                    ewk->wu.routine_no[2]++;
                }
                break;
            case R2_OUT:
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos - roll_rate;
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                if (ewk->wu.xyz[0].disp.pos <= -128) {
                    ewk->wu.routine_no[0]++;
                }
                break;
            }
            break;
        case R1_HOLD:
            ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
            if (ewk->wu.dir_timer <= 0) {
                ewk->wu.routine_no[0]++;
            }
            break;
        case R1_RISE_LONG:
            switch (ewk->wu.routine_no[2]) {
            case R2_IN:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                ewk->wu.xyz[1].disp.pos = ewk->wu.xyz[1].disp.pos + roll_rate;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                if (ewk->wu.routine_no[6] <= ewk->wu.xyz[1].disp.pos) {
                    ewk->wu.xyz[1].disp.pos = ewk->wu.routine_no[6];
                    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                    ewk->wu.routine_no[2]++;
                    ewk->wu.dir_timer = ewk->wu.dir_timer - 60;
                }
                break;
            case R2_HOLD:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                if (ewk->wu.dir_timer <= 0) {
                    ewk->wu.routine_no[2]++;
                }
                break;
            case R2_OUT:
                ewk->wu.xyz[1].disp.pos = ewk->wu.xyz[1].disp.pos + roll_rate;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                if (ewk->wu.xyz[1].disp.pos >= 0x100) {
                    ewk->wu.routine_no[0]++;
                }
                break;
            }
            break;
        case R1_STILL:
            break;
        }
        sort_push_request3(&ewk->wu);
        break;
    case R0_HIDE:
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0]++;
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}


s32 effect_H6_init(s16 timer, s8* str, s16 X, s16 Y, s16 Original_Color) {
    WORK_Other_CONN* ewk;
    s16 ix;
    s16 x;
    s16 i;
    s16 c;
    s8* su = str;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 176;
    ewk->wu.type = 0;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_family = 6;
    ewk->wu.my_priority = ewk->wu.position_z = 25;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.dir_timer = timer;
    if (*su == '#') {
        ewk->wu.dir_step = 1;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.xyz[0].disp.pos = X;
        ewk->wu.xyz[1].disp.pos = Y;
        ewk->wu.my_col_code = Original_Color + 0x2090;
        ewk->wu.cg_number = 0x9C9E;
    } else {
        switch (Original_Color) {
        case 0:
            ewk->wu.routine_no[1] = R1_RIGHT;
            ewk->wu.routine_no[5] = X;
            ewk->wu.xyz[0].disp.pos = 384;
            ewk->wu.xyz[1].disp.pos = Y;
            break;
        case 1:
            ewk->wu.routine_no[1] = R1_RISE;
            ewk->wu.routine_no[6] = Y;
            ewk->wu.xyz[0].disp.pos = X;
            ewk->wu.xyz[1].disp.pos = 0;
            break;
        case 2:
            Original_Color = 0;
            ewk->wu.routine_no[1] = R1_LEFT;
            ewk->wu.routine_no[5] = X;
            ewk->wu.xyz[0].disp.pos = -64;
            ewk->wu.xyz[1].disp.pos = Y;
            break;
        case 3:
            Original_Color = 1;
            ewk->wu.routine_no[1] = R1_HOLD;
            ewk->wu.xyz[0].disp.pos = X;
            ewk->wu.xyz[1].disp.pos = Y;
            break;
        case 4:
            Original_Color = 1;
            ewk->wu.routine_no[1] = R1_RISE_LONG;
            ewk->wu.routine_no[6] = Y;
            ewk->wu.xyz[0].disp.pos = X;
            ewk->wu.xyz[1].disp.pos = 0;
            break;
        case 5:
            Original_Color = 1;
            ewk->wu.routine_no[1] = R1_STILL;
            ewk->wu.xyz[0].disp.pos = X;
            ewk->wu.xyz[1].disp.pos = Y;
            break;
        }
        ewk->wu.dir_step = 0;
        ewk->wu.my_col_code = 0;
        for (x = 0, i = 0; *su != '\0'; i += 9, su++) {
            if ((c = code_tab[*su]) == -1) {
                continue;
            }
            ewk->conn[x].nx = i;
            ewk->conn[x].ny = 0;
            ewk->conn[x].chr = c + 0xAEC8;
            ewk->conn[x].col = 0x8B + Original_Color;
            x++;
        }
        ewk->num_of_conn = x;
    }
    return 0;
}


