/*
 * EFF59.C  Effect 59: country name letters; effect 60: flashing stage object (2nd Impact only)
 *
 * 2nd Impact rewrote effect 59 (3rd Strike: parts attached to a select-screen master). effect_59_init lays out
 * the letters of the Battle_Country name from eff59_name_tbl, one effect 59 per letter, each
 * starting after its own delay; effect_59_move waits that delay (or a cut), opens the letter
 * with a shrinking window, waits, and on the last letter starts effect 58 type 7 and then
 * Next_Step. Effect 60 is the 3rd Strike flashing stage object, now blinking through disp_flag 2.
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
#include "color3rd.h"
#include "ta_sub.h"
#include "bg_sub_5.h"
#include "Eff59.h"
#include "EFF58.h"
#include "EFF61.h"

extern const u8 eff59_country_tbl[16][2];
extern const s16 eff59_name_x_tbl[14];
extern const u8 eff59_name_tbl[14][39];
extern const s16 flash_obj_data61_0[];
extern const s16 flash_obj_data61_1[];

static void effect_59_open_end(WORK_Other* ewk);

const s16* flash_obj_data61[2] = {
    flash_obj_data61_0,
    flash_obj_data61_1,
};



void effect_59_move(WORK_Other* ewk) {
    if (Suicide) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = 6;
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Cut_Cut_Sub(3) == 3) {
            ewk->wu.dir_timer = 1;
        }
        if (--ewk->wu.dir_timer) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        if (Cut_Cut_Sub(3) == 3) {
            effect_59_open_end(ewk);
            break;
        }
        ewk->wu.xyz[2].disp.pos++;
        if ((ewk->wu.my_mr.size.x -= 6) <= 63) {
            ewk->wu.my_mr.size.x = 63;
        }
        if ((ewk->wu.my_mr.size.y -= 6) <= 63) {
            ewk->wu.my_mr.size.y = 63;
        }
        if (ewk->wu.my_mr.size.x <= 63 && ewk->wu.my_mr.size.y <= 63) {
            effect_59_open_end(ewk);
        }
        break;
    case 2:
        if (Break_Into) {
            break;
        }
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case 3:
        if (ewk->master_id) {
            ewk->wu.routine_no[0]++;
            Explosion = 1;
            effect_58_init(7, 3, -1);
        }
        break;
    case 4:
        break;
    case 5:
        if (ewk->master_id) {
            Next_Step = 1;
        }
        if (Suicide == 1) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            return;
        }
        break;
    case 6:
        ewk->wu.routine_no[0]++;
        return;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



/* provisional name */
static void effect_59_open_end(WORK_Other* ewk) {
    ewk->wu.routine_no[0]++;
    ewk->wu.dir_timer = 5;
    ewk->wu.my_mr.size.x = 63;
    ewk->wu.my_mr.size.y = 63;
}



/* one letter per name character (3rd Strike: one part per master) */
s32 effect_59_init(s16 timer) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    s16 x;
    u16 no;
    u16 num;
    s32 n;
    const u8* name;
    const u8* p;
    no = eff59_country_tbl[Battle_Country][0];
    num = eff59_country_tbl[Battle_Country][1];
    i = 0;
    x = eff59_name_x_tbl[no];
    n = num * 2;
    name = eff59_name_tbl[no];
    for (; i < n; i += 2) {
        if (name[i] == 0xFF) {
            x += 8;
        } else {
            if ((ix = pull_effect_work(4)) == -1) {
                return -1;
            }
            ewk = (WORK_Other*)frw[ix];
            ewk->wu.be_flag = 1;
            ewk->wu.id = 59;
            ewk->wu.work_id = 16;
            ewk->wu.cgromtype = 1;
            ewk->wu.rl_flag = 0;
            ewk->wu.my_col_mode = 0x4200;
            ewk->wu.my_col_code = 0x2080;
            ewk->wu.my_family = 3;
            ewk->wu.xyz[0].disp.pos = DE_X[10] + x;
            ewk->wu.xyz[1].disp.pos = 82;
            ewk->wu.xyz[2].disp.pos = 1;
            ewk->wu.dir_timer = timer;
            ewk->wu.char_index = 4;
            p = &eff59_name_tbl[no][i];
            ewk->wu.dir_step = p[0];
            x += p[1];
            ewk->wu.char_table[0] = sel_pl_char_table;
            if (i == n - 2) {
                ewk->master_id = 1;
            } else {
                ewk->master_id = 0;
            }
            timer = timer + 4;
            ewk->wu.my_mr_flag = 1;
            ewk->wu.my_mr.size.y = 127;
            ewk->wu.my_mr.size.x = 127;
        }
    }
    load_any_color(7);
    return 0;
}



/* disp_flag 2 blinks, no old_rno timer */
void effect_60_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.disp_flag = 2;
        ewk->wu.blink_timing = 1;
        break;
    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (!EXE_flag && !Game_pause && ewk->wu.hit_stop) {
            char_move(&ewk->wu);
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* char_add by stage and area */
s32 effect_60_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    data_ptr = flash_obj_data61[type];
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 60;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.type = type;
    ewk->wu.dead_f = *data_ptr++;
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.my_col_code = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.hit_stop = *data_ptr++;
    ewk->wu.sync_suzi = *data_ptr;
    ewk->wu.char_table[0] = char_add[bg_w.stage][bg_w.area];
    suzi_offset_set(&ewk->wu);
    return 0;
}
