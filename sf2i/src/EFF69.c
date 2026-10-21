/*
 * EFF69.C  Effect 69: select-screen object driven by the scene orders
 *
 * 2nd Impact's version. effect_69_init (from sel_pl) places the object at its height from
 * Pos_Data_69. Order[] then picks a state: EFF69_WAIT waits for an order, EFF69_RISE_IN and
 * EFF69_RISE_OUT move it vertically, EFF69_SLIDE_IN brings it in from the side given by
 * Order_Dir, EFF69_SLIDE_OUT takes it out again and EFF69_KILL releases it.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFF69.h"

s32 Ck_Range_Out_Y(WORK_Other* ewk, s16 BG_No, s16 R);    /* provisional name */

void EFF69_WAIT(WORK_Other* ewk);
void EFF69_RISE_IN(WORK_Other* ewk);
void EFF69_RISE_OUT(WORK_Other* ewk);
void EFF69_SLIDE_IN(WORK_Other* ewk);
void EFF69_SLIDE_OUT(WORK_Other* ewk);
void EFF69_KILL(WORK_Other* ewk);

/* 06179CB8 */
const s16 Pos_Data_69[6] = { 288, 221, 221, 221, 221, -1 };

/* 06179CC4 */
void (*const EFF69_Jmp_Tbl[6])() = {
    EFF69_WAIT,
    EFF69_RISE_IN,
    EFF69_RISE_OUT,
    EFF69_SLIDE_IN,
    EFF69_SLIDE_OUT,
    EFF69_KILL,
};



void effect_69_move(WORK_Other* ewk) {
    EFF69_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



void EFF69_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_step])) {
        ewk->wu.routine_no[1] = 0;
    }
}



/* provisional name */
void EFF69_RISE_IN(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_step]) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos = DE_X[10] + 0x2C0;
        ewk->wu.mvxy.a[1].sp = -0x100000;
        ewk->wu.hit_quake = 216;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_old + 1, 0);
        break;
    default:
        ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
        if (ewk->wu.hit_quake >= ewk->wu.xyz[1].disp.pos) {
            Order[ewk->wu.dir_step] = 0;
            ewk->wu.routine_no[0] = 0;
            ewk->wu.xyz[1].disp.pos = ewk->wu.hit_quake;
        }
        break;
    }
}



/* provisional name */
void EFF69_RISE_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_step]) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos = DE_X[10] + 0x2C0;
        ewk->wu.mvxy.a[1].sp = 0x100000;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_old + 1, 0);
        break;
    case 1:
        ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
        if (Ck_Range_Out_Y(ewk, 2, 32)) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void EFF69_SLIDE_IN(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_step]) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.position_z = 69;
        if (Order_Dir[ewk->wu.dir_step] == 4) {
            ewk->wu.xyz[0].disp.pos = DE_X[5] + 0x3C0;
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.hit_quake = DE_X[5] + 0x340;
        } else {
            ewk->wu.xyz[0].disp.pos = 0x1C0;
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0x8000;
            ewk->wu.hit_quake = 0x240;
        }
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_old + 1, 0);
        break;
    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                if (Order[ewk->wu.dir_step] == ewk->wu.routine_no[0]) {
                    Order[ewk->wu.dir_step] = 0;
                }
                ewk->wu.routine_no[0] = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
                ewk->wu.position_z = 70;
            }
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            if (Order[ewk->wu.dir_step] == ewk->wu.routine_no[0]) {
                Order[ewk->wu.dir_step] = 0;
            }
            ewk->wu.routine_no[0] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            ewk->wu.position_z = 70;
        }
        break;
    }
}



void EFF69_SLIDE_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_step]) {
            break;
        }
        ewk->wu.routine_no[1]++;
        if (Order_Dir[ewk->wu.dir_step] == 4) {
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = -0x8000;
        } else {
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0x8000;
        }
        break;
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (Ck_Range_Out_S(ewk, 2, 128)) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void EFF69_KILL(WORK_Other* ewk) {
    all_cgps_put_back(&ewk->wu);
    push_effect_work(&ewk->wu);
}



s32 effect_69_init(s16 dir_old) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 69;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->wu.char_index = 12;
    ewk->wu.dir_old = dir_old;
    ewk->wu.xyz[1].disp.pos = Pos_Data_69[dir_old];
    ewk->wu.position_z = 70;
    ewk->wu.dir_step = dir_old;
}
