/*
 * EFFI1.C  Effect I1 (181): the select-screen side banner (2nd Impact)
 *
 * 2nd Impact's own effect: it waits dir_timer frames, starts the side's effect (effect_67_init for the
 * current player, effect_A6_init for the other), slides in to hit_quake, waits for Next_Step to
 * reach 8 and slides out, setting Next_Step when direction asks for it. An object of its own
 * (060EB0E4-060EB3B0): its literal pool closes the unit before EFFI3's effect_I2_init.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "charmove_2.h"
#include "color3rd.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFFA6.h"
#include "EFFI3.h"

void set_char_move_init2();
s32 effect_67_init();                   /* 060D20A0, in EFF67 */



void effect_I1_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        if (ewk->master_id == Player_id) {
            effect_67_init(ewk);
        } else {
            effect_A6_init(ewk);
        }
        break;
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.mvxy.a[0].sp > 0) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[0]++;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
                ewk->wu.mvxy.a[0].sp = 0xFFE80009;
            }
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            ewk->wu.mvxy.a[0].sp = 0x17FFF7;
        }
        break;
    case 2:
        if (Next_Step >= 8) {
            if (0) {
            }
            ewk->wu.routine_no[0]++;
            Next_Step -= 8;
        }
        break;
    case 3:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        if (Ck_Range_Out_S(ewk, 2, 152)) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            if (ewk->wu.direction) {
                Next_Step = 1;
            }
            return;
        }
        break;
    case 4:
        return;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
    sort_push_request4(&ewk->wu);
}



s32 effect_I1_init(s16 PL_id, s16 Wait, s16 Pos_Y, s16 Prio, s16 Dir) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 181;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->wu.dir_timer = Wait;
    ewk->wu.direction = Dir;
    if ((ewk->master_id = PL_id) != 0) {
        ewk->wu.xyz[0].disp.pos = DE_X[5] + 0x420;
        ewk->wu.mvxy.a[0].sp = 0xFFEB0006;
        ewk->wu.mvxy.d[0].sp = -0x8000;
        ewk->wu.hit_quake = DE_X[5] + 0x2F8;
    } else {
        ewk->wu.xyz[0].disp.pos = 0x160;
        ewk->wu.mvxy.a[0].sp = 0x14FFFA;
        ewk->wu.mvxy.d[0].sp = 0x8000;
        ewk->wu.hit_quake = 0x288;
    }
    ewk->wu.xyz[1].disp.pos = Pos_Y;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = Prio;
    ewk->wu.char_index = 6;
    ewk->wu.dir_step = PL_id;
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
    return 0;
}
