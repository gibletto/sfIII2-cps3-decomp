/*
 * EFFE1.C  Effect E1: opening scene windows
 *
 * effect_E1_init makes a window of kind id (0-2) that either flies to its place or, with the third argument
 * set, starts there.
 * effE1_0000 waits for scene 12 and opens; effE1_1000 and effE1_2000 shrink in from a large
 * window, fly to their point and open (effE1_1000 also sounds 124 and sets effE1_end_flag).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "se_3.h"
#include "EFFE1.h"



extern s8 effE1_end_flag;                  /* provisional name */

static void effE1_0000(WORK_Other* ewk);
static void effE1_1000(WORK_Other* ewk);
static void effE1_2000(WORK_Other* ewk);



void effect_E1_move(WORK_Other* ewk) {
    switch (ewk->wu.old_rno[0]) {
    case 0:
        effE1_0000(ewk);
        break;
    case 1:
        effE1_1000(ewk);
        break;
    case 2:
        effE1_2000(ewk);
        break;
    }
}



static void effE1_0000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.xyz[1].disp.low = 0;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[0] + 1, 0);
        break;
    case 1:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (op_w.r_no_1 != 12) {
                break;
            }
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr_flag = 1;
            ewk->wu.my_mr.size.x = 63;
            ewk->wu.my_mr.size.y = 63;
            set_char_move_init(&ewk->wu, 0, 95);
            break;
        case 1:
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[0]++;
                ewk->wu.xyz[0].disp.pos = 0x1B8;
                ewk->wu.xyz[1].disp.pos = 0x94;
            } else {
                char_move(&ewk->wu);
            }
            break;
        }
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 89);
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        break;
    default:
        break;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



static void effE1_1000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
    e1_open1:;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[0] + 1, 0);
        break;
    case 1:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (ewk->wu.my_mr.size.x >= 67) {
                ewk->wu.my_mr.size.x -= 4;
                ewk->wu.my_mr.size.y -= 4;
            }
            ewk->wu.old_rno[1] -= 1;
            if (ewk->wu.old_rno[1] <= 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[2];
                ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[3];
                ewk->wu.my_mr.size.x = 63;
                ewk->wu.my_mr.size.y = 63;
                ewk->wu.old_rno[1] = 60;
                Sound_SE(124);
            } else {
                add_x_sub(ewk);
                add_y_sub(ewk);
            }
            break;
        case 1:
            ewk->wu.old_rno[1] -= 1;
            if (ewk->wu.old_rno[1] <= 0) {
                ewk->wu.routine_no[1]++;
                effE1_end_flag = 1;
            }
            break;
        case 2:
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.low = 0;
            set_char_move_init(&ewk->wu, 0, 94);
            break;
        case 3:
            if (ewk->wu.cg_type == 9) {
                effE1_end_flag = 1;
                ewk->wu.cg_type = 0;
            }
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[0]++;
                ewk->wu.xyz[0].disp.pos = 0x1B8;
                ewk->wu.xyz[1].disp.pos = 0x94;
            } else {
                char_move(&ewk->wu);
            }
            break;
        }
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 90);
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        break;
    default:
        char_move(&ewk->wu);
        break;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



static void effE1_2000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
    e1_open2:;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[0] + 1, 0);
        break;
    case 1:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (ewk->wu.my_mr.size.x >= 67) {
                ewk->wu.my_mr.size.x -= 4;
                ewk->wu.my_mr.size.y -= 4;
            }
            ewk->wu.old_rno[1] -= 1;
            if (ewk->wu.old_rno[1] <= 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[2];
                ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[3];
                ewk->wu.my_mr.size.x = 63;
                ewk->wu.my_mr.size.y = 63;
                ewk->wu.old_rno[1] = 60;
            } else {
                add_x_sub(ewk);
                add_y_sub(ewk);
            }
            break;
        case 1:
            ewk->wu.old_rno[1] -= 1;
            if (ewk->wu.old_rno[1] <= 0) {
                ewk->wu.routine_no[1]++;
            }
            break;
        case 2:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.low = 0;
            break;
        case 3:
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[0]++;
                ewk->wu.xyz[0].disp.pos = 0x1B8;
                ewk->wu.xyz[1].disp.pos = 0x94;
            } else {
                char_move(&ewk->wu);
            }
            break;
        }
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        ewk->wu.disp_flag = 0;
        break;
    default:
        char_move(&ewk->wu);
        break;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



s32 effect_E1_init(s16 id, s16 Time, s16 _p2) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x8D;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0xC0;
    ewk->wu.my_family = 1;
    ewk->wu.dir_timer = Time;
    ewk->wu.char_table[0] = etc_char_table;
    ewk->wu.char_index = 48;
    ewk->wu.old_rno[0] = id;
    ewk->wu.my_mr.size.x = 63;
    ewk->wu.my_mr.size.y = 63;
    switch (id) {
    case 0:
        ewk->wu.old_rno[2] = ewk->wu.xyz[0].disp.pos = 0x200;
        ewk->wu.old_rno[3] = 48;
        ewk->wu.my_priority = ewk->wu.position_z = 51;
        ewk->wu.old_rno[4] = 61;
        if (_p2) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.old_rno[4] = 89;
            ewk->wu.xyz[0].disp.pos = 0x1B8;
            ewk->wu.xyz[1].disp.pos = 0x94;
        } else {
            ewk->wu.old_rno[1] = 30;
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.old_rno[2] = ewk->wu.xyz[0].disp.pos = 0x200;
            ewk->wu.xyz[1].disp.pos = 128;
        }
        break;
    case 1:
        ewk->wu.my_priority = ewk->wu.position_z = 50;
        ewk->wu.old_rno[4] = 59;
        if (_p2) {
            ewk->wu.xyz[0].disp.pos = 0x1B8;
            ewk->wu.xyz[1].disp.pos = 0x94;
            ewk->wu.routine_no[0] = 2;
            ewk->wu.old_rno[4] = 90;
        } else {
            ewk->wu.xyz[0].disp.pos = 0x100;
            ewk->wu.xyz[1].disp.pos = 128;
            ewk->wu.old_rno[2] = 0x200;
            ewk->wu.old_rno[3] = 128;
            ewk->wu.old_rno[1] = 8;
            cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[1], ewk->wu.old_rno[2], ewk->wu.old_rno[3], 1, 1);
        }
        break;
    case 2:
        ewk->wu.my_priority = ewk->wu.position_z = 50;
        ewk->wu.old_rno[4] = 60;
        if (_p2) {
            ewk->wu.xyz[0].disp.pos = 0x200;
            ewk->wu.xyz[1].disp.pos = 0xA0;
            ewk->wu.routine_no[0] = 2;
            ewk->wu.char_index = 60;
        } else {
            ewk->wu.old_rno[2] = 0x200;
            ewk->wu.old_rno[3] = 128;
            ewk->wu.xyz[0].disp.pos = 0x300;
            ewk->wu.xyz[1].disp.pos = 128;
            ewk->wu.old_rno[1] = 8;
            cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[1], ewk->wu.old_rno[2], ewk->wu.old_rno[3], 1, 1);
        }
        break;
    }
    return 0;
}
