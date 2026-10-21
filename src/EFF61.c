/*
 * EFF61.C  Effect 61: a part of the alternate background (2nd Impact only)
 *
 * Effect 61 is a part of the alternate background (another_bg): hidden normally, it slides
 * into view vertically or horizontally while the another-BG mode is active. 2nd Impact has it in a file
 * of its own (its literal pool closes at 060D0F1C, before effect_62_move), and a real
 * effect_61_init that makes 44 parts for a parent from eff61_data_tbl, where 3rd Strike keeps an empty
 * effect_61_dummy in EFF62.C.
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
#include "EFF62.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF61.h"

void effect_61_move(WORK_Other_CONN* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;
    if (!akebono_flag) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            ewk->wu.be_flag = 1;
            ewk->wu.disp_flag = 0;
            ewk->wu.xyz[0].disp.pos += bg_w.bgw[1].pos_x_work;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_old + 1, 0);
        case 1:
            if (!another_bg[0] && !another_bg[1]) {
                break;
            }
            ewk->wu.routine_no[0]++;
        case 2:
            if (another_bg[0] || another_bg[1]) {
                switch (another_bg[mwk->type]) {
                case 1:
                    if (ewk->wu.dir_old <= 8) {
                        ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
                        ewk->wu.disp_flag = 1;
                        ewk->wu.cg_number = eff61_data_tbl[ewk->wu.old_rno[0]][3];
                        disp_pos_trans_entry_seraph((WORK_Other*)ewk, ewk->wu.dir_old);
                    }
                    break;
                case 2:
                    if (ewk->wu.dir_old > 8) {
                        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[1].sp;
                        ewk->wu.disp_flag = 1;
                        ewk->wu.cg_number = eff61_data_tbl[ewk->wu.old_rno[0]][3];
                        ewk->wu.cg_number += 32;
                        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                        sort_push_request4((WORK*)ewk);
                    }
                    break;
                case 3:
                    if (ewk->wu.dir_old <= 8) {
                        break;
                    }
                    ewk->wu.xyz[0].cal -= ewk->wu.mvxy.a[1].sp;
                    ewk->wu.disp_flag = 1;
                    ewk->wu.cg_number = eff61_data_tbl[ewk->wu.old_rno[0]][3];
                    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                    sort_push_request4((WORK*)ewk);
                    break;
                case 4:
                    if (ewk->wu.dir_old > 8) {
                        break;
                    }
                    ewk->wu.xyz[1].cal -= ewk->wu.mvxy.a[1].sp;
                    ewk->wu.disp_flag = 1;
                    ewk->wu.cg_number = eff61_data_tbl[ewk->wu.old_rno[0]][3];
                    ewk->wu.cg_number += 32;
                    disp_pos_trans_entry_seraph((WORK_Other*)ewk, ewk->wu.dir_old);
                    break;
                default:
                    ewk->wu.disp_flag = 0;
                    break;
                }
            } else {
                ewk->wu.routine_no[0] = 3;
            }
            break;
        case 3:
            ewk->wu.routine_no[0] = 1;
            break;
        default:
            all_cgps_put_back((WORK_Other*)ewk);
            push_effect_work(&ewk->wu);
            break;
        }
    }
}


/* provisional name */
/* 2nd Impact's effect_61_init (3rd Strike keeps an empty effect_61_dummy): 44 works for its master */
s32 effect_61_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = eff61_data_tbl[0];
    for (i = 0; i < 44; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->my_master = (u32*)oya;
        ewk->wu.be_flag = 1;
        ewk->wu.id = 61;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.old_rno[0] = i;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 0xC0;
        ewk->wu.my_priority = ewk->wu.position_z = 69;
        ewk->wu.char_table[0] = etc2_char_table;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.dir_old = *data_ptr++;
        ewk->wu.cg_number = *data_ptr++;
        ewk->wu.char_index = 30;
        ewk->wu.mvxy.a[1].sp = eff61_speed_tbl[ewk->wu.dir_old];
        ewk->wu.mvxy.d[1].sp = 0;
        ewk->wu.sync_suzi = 0;
        suzi_offset_set(&ewk->wu);
    }
    return 0;
}
