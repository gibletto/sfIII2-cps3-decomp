/*
 * EFF48.C  Effect 48: opening scene objects
 *
 * effect_48_init creates the objects of eff48_data_tbl for a type; each waits its start time, plays its
 * pattern while op_w.r_no_1 is still its scene (eff48_0000, eff48_2000 shrink a window,
 * eff48_1000 clears op_obj_disp after its time) and then removes itself.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFF48.h"



extern const s16 eff48_data_tbl[6][5][6];
extern s16 op_obj_disp;

void eff48_2000(WORK_Other* ewk);
void eff48_3000(WORK_Other* ewk);
void eff48_4000(WORK_Other* ewk);



void effect_48_move(WORK_Other* ewk) {
    void (*eff48_jp[5])(WORK_Other*) = { eff48_0000, eff48_1000, eff48_2000, eff48_3000, eff48_4000 };
    eff48_jp[ewk->wu.routine_no[0]](ewk);
}



void eff48_0000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[2] -= 1;
        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[1], 0);
        }
        break;
    case 1:
        if (ewk->wu.old_rno[3] != op_w.r_no_1) {
            ewk->wu.routine_no[1]++;
        } else {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4(&ewk->wu);
        }
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff48_1000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[2] -= 1;
        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        break;
    case 1:
        if (ewk->wu.old_rno[3] != op_w.r_no_1) {
            ewk->wu.routine_no[1] = 3;
            break;
        }
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case 2:
        ewk->wu.old_rno[4] -= 1;
        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            op_obj_disp = 0;
        } else {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4(&ewk->wu);
        }
        break;
    case 3:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff48_2000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[2] -= 1;
        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[1], 0);
        }
        break;
    case 1:
        ewk->wu.old_rno[4] -= 1;
        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr_flag = 1;
            ewk->wu.my_mr.size.x = 63;
            ewk->wu.my_mr.size.y = 63;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case 2:
        ewk->wu.my_mr.size.x--;
        ewk->wu.my_mr.size.y -= 1;
        if (ewk->wu.my_mr.size.y <= 0) {
            ewk->wu.routine_no[1]++;
        } else {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4(&ewk->wu);
        }
        break;
    case 3:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff48_3000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[2] -= 1;
        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[1], 0);
        }
        break;
    case 1:
        ewk->wu.old_rno[4] -= 1;
        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            break;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff48_4000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[2] -= 1;
        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case 2:
        if (ewk->wu.old_rno[3] != op_w.r_no_1) {
            ewk->wu.routine_no[1]++;
        } else {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4(&ewk->wu);
        }
        break;
    case 3:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_48_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr;
    for (i = 0; i < eff48_num_tbl[type]; i++) {
        data_ptr = eff48_data_tbl[type][i];
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 48;
        ewk->wu.work_id = 16;
        ewk->wu.old_rno[0] = type;
        ewk->wu.my_family = 6;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0xC0;
        ewk->wu.char_table[0] = etc_char_table;
        if (type >= 3) {
            if (Game_setting.mode) {
                ewk->wu.xyz[0].disp.pos = 0x2C0;
            } else {
                ewk->wu.xyz[0].disp.pos = 0x2B0;
            }
        } else {
            ewk->wu.xyz[0].disp.pos = 0x200;
        }
        ewk->wu.xyz[1].disp.pos = 112;
        ewk->wu.my_priority = ewk->wu.position_z = 10;
        ewk->wu.routine_no[0] = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.old_rno[1] = *data_ptr++;
        ewk->wu.old_rno[2] = *data_ptr++;
        ewk->wu.old_rno[4] = *data_ptr++;
        ewk->wu.old_rno[3] = *data_ptr;
    }
    (void)((WORK*)etc_char_table)->id;
    return 0;
}
