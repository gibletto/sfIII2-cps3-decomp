/*
 * EFF38.C  Effect 38: the player's face on the character select screen
 *
 * effect_38_init places the face off screen on the player's side with its pattern from the face
 * under the cursor (or the given character); effect_38_move waits for the timer, slides the face in
 * at the cut speed, then follows the cursor until Order[0] is 2, and finally slides it out. A face
 * made with Dir 2 is dropped as soon as Suicide is set.
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
#include "EFF38.h"
#include "fighter.h"

/* routine_no[0] */
#define R0_WAIT         0       /* count the start wait down, then show */
#define R0_SLIDE_IN     1       /* slide in to the place */
#define R0_FOLLOW       2       /* follow the cursor until chosen */
#define R0_READY        3       /* wait for the select to end */
#define R0_PAUSE        4       /* count down before leaving */
#define R0_SLIDE_OUT    5       /* slide off the screen */
#define R0_STAY         6       /* stay in place */
#define R0_END          7       /* one more frame */
#define R0_KILL         99      /* (default) put the work back */

extern const s16 eff38_z_tbl[2][16];    /* provisional name */



void effect_38_move(WORK_Other* ewk) {
    u16 cut;
    if (ewk->wu.direction == 2 && Suicide != 0) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = R0_END;
        return;
    }
    cut = Cut_Cut_Sub(3);
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        ewk->wu.dir_timer = 30;
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case R0_SLIDE_IN:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp * cut;
        if (ewk->wu.mvxy.a[0].sp > 0) {
            if (ewk->wu.hit_quake < ewk->wu.xyz[0].disp.pos) {
                if (plw[ewk->master_id].wu.operator) {
                    ewk->wu.routine_no[0]++;
                } else {
                    ewk->wu.routine_no[0] = R0_KILL;
                }
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
                Select_Start[ewk->master_id]--;
                ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
                if (ewk->wu.dm_vital) {
                    ewk->wu.routine_no[0] = R0_STAY;
                }
            }
        } else if (ewk->wu.hit_quake > ewk->wu.xyz[0].disp.pos) {
            if (plw[ewk->master_id].wu.operator) {
                ewk->wu.routine_no[0]++;
            } else {
                ewk->wu.routine_no[0] = R0_KILL;
            }
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            Select_Start[ewk->master_id]--;
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
            if (ewk->wu.dm_vital) {
                ewk->wu.routine_no[0] = R0_STAY;
            }
        }
        break;
    case R0_FOLLOW:
        if (Order[0] == 2) {
            ewk->wu.routine_no[0] = R0_PAUSE;
            break;
        }
        if (ewk->wu.dir_step != ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]]) {
            ewk->wu.dir_step = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
            eff38_set_z(ewk);
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }
        break;
    case R0_READY:
        if (Order[0] == 2) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case R0_PAUSE:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case R0_SLIDE_OUT:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        if (Ck_Range_Out_S(ewk, 2, 80)) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = R0_END;
        }
        break;
    case R0_STAY:
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        return;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



s32 effect_38_init(s16 PL_id, s16 Wait, s16 Kind, s16 Face_Set, s16 Your_Char, s16 Dir) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 38;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    ewk->wu.xyz[1].disp.pos = 16;
    ewk->wu.char_index = 2;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->wu.dm_vital = Kind;
    ewk->wu.dir_timer = Wait;
    ewk->wu.direction = Dir;
    if (Face_Set == 0) {
        ewk->wu.dir_step = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
    } else {
        ewk->wu.dir_step = Your_Char;
        if (plw[PL_id].wu.operator == 0 && EM_id == PL_GILL) {
            ewk->wu.dir_step = 0;
            ewk->wu.rl_flag = PL_id ^ 1;
            if (PL_id == 1) {
                ewk->wu.my_col_code = 0x2068;
            }
        }
    }
    eff38_set_z(ewk);
    ewk->wu.rl_flag = PL_id ^ 1;
    if (PL_id) {
        ewk->wu.xyz[0].disp.pos = DE_X[5] + 0x3D0;
        ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos - DE_X[2] - 168;
        ewk->wu.mvxy.a[0].sp = -0xF0000;
    } else {
        ewk->wu.xyz[0].disp.pos = 0x1B0;
        ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos + DE_X[2] + 168;
        ewk->wu.mvxy.a[0].sp = 0xF0000;
    }
    if (Kind == 1) {
        ewk->wu.routine_no[0] = R0_STAY;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
    }
    return 0;
}



/* the face's priority for its pattern */
/* provisional name */
void eff38_set_z(WORK_Other* ewk) {
    ewk->wu.xyz[2].disp.pos = eff38_z_tbl[ewk->master_id][ewk->wu.dir_step];
}
