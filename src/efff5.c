/*
 * EFFF5.C  Opening demo picture objects (effect F5)
 *
 * Sprites used by the attract-mode opening. effect_F5_init(type) reads routine, position,
 * priority and animation from efff5_data_tbl; effect_F5_move dispatches to efff5_0000-0011:
 * play once and raise a completion flag, loop an animation, scroll downward with wrap,
 * still frames, triple-speed playback, and three objects that glide over ten frames to
 * fixed screen positions. Created from the opening scene routines in end_main.c.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "efff5.h"

/* routine_no[1]: states of the picture routines */
#define R1_INIT         0       /* start the animation */
#define R1_MOVE         1       /* the type's main state */
#define R1_KILL         2       /* (default) put the work back */

/* routine_no[1], efff5_0009 */
#define R1_WAIT         1       /* wait four frames */
#define R1_GLIDE        2       /* glide to its place over ten frames */
#define R1_STAY         3       /* stay at its place */


void effect_F5_move(WORK_Other* ewk) {
    void (*efff5_jp[12])(WORK_Other*) = { efff5_0000, efff5_0001, efff5_0002, efff5_0003, efff5_0004, efff5_0005, efff5_0006, efff5_0007, efff5_0008, efff5_0009, efff5_0010, efff5_0011 };
    efff5_jp[ewk->wu.routine_no[0]](ewk);
}



void efff5_0000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R1_MOVE:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            op_w.free_work = 1;
            ewk->wu.disp_flag = 0;
        } else {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4(&ewk->wu);
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void efff5_0001(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R1_MOVE:
        char_move(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void efff5_0002(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R1_MOVE:
        ewk->wu.xyz[1].disp.pos += 2;
        if (ewk->wu.xyz[1].disp.pos > 96) {
            ewk->wu.xyz[1].disp.pos = 0;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    }
}



void efff5_0003(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R1_MOVE:
        char_move(&ewk->wu);
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void efff5_0004(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        break;
    case R1_MOVE:
        sort_push_request4(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void efff5_0005(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R1_MOVE:
        char_move(&ewk->wu);
        char_move(&ewk->wu);
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            op_w.free_work = 1;
            ewk->wu.disp_flag = 0;
        } else {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4(&ewk->wu);
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void efff5_0006(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case R1_MOVE:
        if (op_w.r_no_1 == 0) {
            sort_push_request4(&ewk->wu);
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 0;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void efff5_0007(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        break;
    case R1_MOVE:
        if (op_w.r_no_1 == 6) {
            sort_push_request4(&ewk->wu);
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 0;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



/* provisional name */
void efff5_0008(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R1_MOVE:
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void efff5_0009(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[1] = 4;
        break;
    case R1_WAIT:
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            return;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[1] = 10;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[1], 512, 72, 1, 1);
        break;
    case R1_GLIDE:
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = 512;
            ewk->wu.xyz[1].disp.pos = 72;
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case R1_STAY:
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void efff5_0010(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[1] = 4;
        break;
    case R1_WAIT:
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            return;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[1] = 10;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[1], 608, 168, 1, 1);
        break;
    case R1_GLIDE:
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = 608;
            ewk->wu.xyz[1].disp.pos = 168;
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case R1_STAY:
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void efff5_0011(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[1] = 4;
        break;
    case R1_WAIT:
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            return;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[1] = 10;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[1], 608, 120, 1, 1);
        break;
    case R1_GLIDE:
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = 608;
            ewk->wu.xyz[1].disp.pos = 120;
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case R1_STAY:
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_F5_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;
    ix = pull_effect_work(3);
    if (ix == -1) {
        return -1;
    }
    data_ptr = efff5_data_tbl[type];
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.id = 155;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    switch (type) {
    case 14:
        ewk->wu.my_family = 3;
        break;
    case 15:
        ewk->wu.my_family = 6;
        break;
    default:
        ewk->wu.my_family = 1;
        break;
    }
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 192;
    ewk->wu.char_table[0] = etc_char_table;
    ewk->wu.old_rno[0] = type;
    ewk->wu.routine_no[0] = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.hit_stop = *data_ptr;
    return 0;
}
