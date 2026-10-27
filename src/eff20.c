/*
 * EFF20.C  Finish-screen overlay sprite (effect 20)
 *
 * A single sprite created by the Shun Goku Satsu finish screen (syungoku_finish in EFFD3).
 * effect_20_init places it at BG1's X position + 8, using the etc2 character table with
 * animation 49 (not flipped like the winner, colour 0x20, Y 72); effect_20_move plays the
 * animation once, keeps it locked to BG1's X position, and clears its parent's old_rno[0] while
 * running and sets it again when the animation ends so the parent can continue. Its hit
 * box grows from 47 to 90, and it first flies for (90 - 47) / 3 frames by cal_all_speed_data.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "eff20.h"

/* routine_no[1] */
#define R1_INIT         0       /* show it, hold the parent, aim the flight */
#define R1_FLY          1       /* fly in while the box grows */
#define R1_MOVE         2       /* grow the box and animate once */
#define R1_END          3       /* hidden for a frame */
#define R1_KILL         4       /* (default) put the work back */



/* growing hit box and a flight first */
void effect_20_move(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 47;
        ewk->wu.my_mr.size.y = 47;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        oya->wu.old_rno[0] = 0;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 8;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        ewk->wu.old_rno[7] = (90 - ewk->wu.my_mr.size.x) / 3;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[7], ewk->wu.xyz[0].disp.pos, ewk->wu.xyz[1].disp.pos - 32, 0, 0);
        break;
    case R1_FLY:
        ewk->wu.old_rno[7]--;
        if (ewk->wu.old_rno[7] < 0) {
            ewk->wu.routine_no[1]++;
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        /* fall through */
    case R1_MOVE:
        ewk->wu.my_mr.size.x += 3;
        ewk->wu.my_mr.size.y += 3;
        if (ewk->wu.my_mr.size.x > 90) {
            ewk->wu.my_mr.size.x = 90;
            ewk->wu.my_mr.size.y = 90;
        }
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            oya->wu.old_rno[0] = 1;
        }
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 8;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case R1_END:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* rl_flag 0, colour 0x20, at BG1 + 8 and Y 72 */
s32 effect_20_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->my_master = (u32*)oya;
    ewk->master_id = oya->wu.id;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 20;
    ewk->wu.work_id = 16;
    ewk->wu.my_priority = 0x40;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = etc2_char_table;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x20;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 8;
    ewk->wu.xyz[1].disp.pos = 72;
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    ewk->wu.my_priority = ewk->wu.position_z = 16;
    ewk->wu.char_index = 49;
    return 0;
}
