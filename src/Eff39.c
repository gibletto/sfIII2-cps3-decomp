/*
 * EFF39.C  Effect 39: the player's name plate on the character select screen
 *
 * Effect 39 is EFF38's partner. effect_39_init places the plate off screen on the
 * player's side; effect_39_move waits for the timer, slides it in, follows the cursor until
 * Order[0] is 2, then slides it out. eff39_pattern shows face 16 for faces 14 and 15 outside
 * Japan. A plate made with Kind 2 is dropped when Suicide is set.
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
#include "Eff39.h"



void effect_39_move(WORK_Other* ewk) {
    Cut_Cut_Sub(3);
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        ewk->wu.dir_timer = 10;
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, eff39_pattern(ewk) + 1, 0);
        break;
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp * 3;
        if (ewk->wu.mvxy.a[0].sp > 0) {
            if (ewk->wu.hit_quake < ewk->wu.xyz[0].disp.pos) {
                eff39_slide_in_end(ewk);
            }
        } else if (ewk->wu.hit_quake > ewk->wu.xyz[0].disp.pos) {
            eff39_slide_in_end(ewk);
        }
        break;
    case 2:
        if (Order[0] == 2) {
            ewk->wu.routine_no[0] = 4;
        }
        if (ewk->wu.dir_step != ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]]) {
            ewk->wu.dir_step = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, eff39_pattern(ewk) + 1, 0);
        }
        break;
    case 3:
        if (Order[0] == 2) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case 4:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case 5:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        if (Ck_Range_Out_S(ewk, 2, 80)) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 8;
        }
        break;
    case 6:
        break;
    case 7:
        if (Suicide) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 8;
            return;
        }
        break;
    case 8:
        ewk->wu.routine_no[0]++;
        return;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



/* (no caller): the player's (or else the partner's) super art choice flag */
/* provisional name */
s32 eff39_arts_flag(WORK_Other* ewk) {
    if (Sel_Arts_Complete[ewk->master_id] != -1) {
        return Sel_Arts_Complete[ewk->master_id] & 0x8000;
    }
    return Sel_Arts_Complete[ewk->master_id ^ 1] & 0x8000;
}



/* faces 14 and 15 show pattern 16 outside Japan */
/* provisional name */
s16 eff39_pattern(WORK_Other* ewk) {
    if (Country != 1 && (ewk->wu.dir_step == 14 || ewk->wu.dir_step == 15)) {
        return 16;
    }
    return ewk->wu.dir_step;
}



/* ending of the slide in */
/* provisional name */
void eff39_slide_in_end(WORK_Other* ewk) {
    ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
    Select_Start[ewk->master_id]--;
    ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
    if (ewk->wu.dm_vital == 3) {
        ewk->wu.routine_no[0] = 6;
    } else if (Sel_PL_Complete[ewk->master_id] || plw[ewk->master_id].wu.operator == 0) {
        ewk->wu.routine_no[0] = 2;
    } else {
        ewk->wu.routine_no[0]++;
    }
}



s32 effect_39_init(s16 PL_id, s16 Wait, s16 Kind, s16 Face_Set, s16 Your_Char) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 39;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    ewk->wu.xyz[1].disp.pos = 88;
    ewk->wu.position_z = 10;
    ewk->wu.char_index = 1;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->wu.dir_timer = Wait;
    ewk->wu.dm_vital = Kind;
    if (PL_id) {
        ewk->wu.xyz[0].disp.pos = DE_X[5] + 0x3D0;
        ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos - 160;
        ewk->wu.mvxy.a[0].sp = -0xF0000;
    } else {
        ewk->wu.xyz[0].disp.pos = 0x1B0;
        ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos + 148;
        ewk->wu.mvxy.a[0].sp = 0xF0000;
    }
    if (Face_Set == 0) {
        ewk->wu.dir_step = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
    } else {
        ewk->wu.dir_step = Your_Char;
    }
    if (Kind == 3) {
        return 0;
    }
    if (Kind != 0) {
        ewk->wu.routine_no[0] = 6;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        if (ewk->wu.dm_vital == 2) {
            ewk->wu.routine_no[0] = 7;
        }
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, eff39_pattern(ewk) + 1, 0);
    }
    return 0;
}
