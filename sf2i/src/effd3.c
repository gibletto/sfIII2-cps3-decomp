/*
 * EFFD3.C  Effect D3: special finish screens
 *
 * effect_D3 runs the special finish screens (created from PLCNTSET): akebono_finish flashes a
 * sequence of BG3 pictures on the timings of ake_timer_tbl and then starts the effect G8 sparkles;
 * syungoku_finish hides the fighters, shows the finishing picture with effect 20 and two effect L9
 * sprites, then sets the conclusion and requests the center message.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "SYS_sub.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "aboutspr.h"
#include "eff20.h"
#include "effg8.h"
#include "effect_L9_move.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Manage.h"
#include "manage_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "effd3.h"



/* 2i 060DEC34, 3s-reloc: sf3 src/effd3.c:47 effect_D3_move */
void effect_D3_move(WORK_Other* ewk) {
    if (ewk->wu.type) {
        syungoku_finish(ewk);
        return;
    }
    akebono_finish(ewk);
    return;
}



void akebono_finish(WORK_Other* ewk) {
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.old_rno[1] = 0;
        ewk->wu.dir_timer = ake_timer_tbl[0];
        ewk->wu.old_rno[0] = 64;
        ewk->wu.old_rno[2] = 0;
        ewk->wu.disp_flag = 0;
        for (i = 0; i < bg_w.scno; i++) {
            Bg_Off_R(1 << i);
        }
        Bg_On_R(8);
        akebono_flag = 1;
        Sound_SE(117);
        Bg_Off_R(0x80);
        scrn_map_set(3, ake_scrl_w[1].adrs);
        Scrn_Move_Set(3, ake_pos_tbl[0][0] - bg_w.pos_offset, ake_pos_tbl[0][1]);
        bg_w.bgw[3].position_x = ake_pos_tbl[0][0] - bg_w.pos_offset;
        bg_w.bgw[3].position_y = ake_pos_tbl[0][1];
        break;
    case 1:
        ewk->wu.dir_timer -= 1;
        if (ewk->wu.dir_timer < 0) {
            ewk->wu.old_rno[1] += 1;
            if (ewk->wu.old_rno[1] < ewk->wu.old_rno[0]) {
                ewk->wu.old_rno[2] += 1;
                ewk->wu.old_rno[2] &= 3;
                ewk->wu.dir_timer = ake_timer_tbl[ewk->wu.old_rno[1]];
                for (i = 0; i < bg_w.scno; i++) {
                    Bg_Off_W(1 << i);
                }
                Bg_On_W(8);
                akebono_flag = 1;
            } else {
                ewk->wu.routine_no[0] += 1;
                ewk->wu.old_rno[0] = 8;
                ewk->wu.old_rno[1] = 0;
                for (i = 0; i < bg_w.scno; i++) {
                    Bg_On_W(1 << i);
                }
                if (scrn_reg_w[3].ctrl & 0x8000) {
                    Bg_Off_W(8);
                }
                akebono_flag = 0;
            }
        }
        scrn_map_set(3, ake_scrl_w[1].adrs);
        bg_w.bgw[3].position_x = ake_pos_tbl[ewk->wu.old_rno[2]][0] - bg_w.pos_offset;
        bg_w.bgw[3].position_y = ake_pos_tbl[ewk->wu.old_rno[2]][1];
        ake_Family_Set();
        break;
    default:
        akebono_flag = 0;
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void syungoku_finish(WORK_Other* ewk) {
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        akebono_flag = 1;
        Extra_Break = 1;
        Sound_SE(126);
        plw[0].wu.disp_flag = 0;
        plw[1].wu.disp_flag = 0;
        Pause_Hit_Marks = 1;
        for (i = 0; i < bg_w.scno; i++) {
            Bg_Off_W(1 << i);
        }
        Bg_On_W(8);
        bg_w.bgw[3].position_x = 256 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        ewk->wu.dir_timer = 2;
        scrn_map_set(3, ake_scrl_w[2].adrs);
        ake_Family_Set();
        break;
    case 1:
        ewk->wu.dir_timer -= 1;
        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[0] += 1;
            ewk->wu.old_rno[0] = 0;
            effect_20_init(ewk);
        }
        scrn_map_set(3, ake_scrl_w[2].adrs);
        bg_w.bgw[3].position_x = 768 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        ake_Family_Set();
        break;
    case 2:
        if (ewk->wu.old_rno[0]) {
            ewk->wu.routine_no[0] += 1;
            akebono_flag = 0;
            plw[0].wu.disp_flag = 1;
            plw[1].wu.disp_flag = 1;
            Pause_Hit_Marks = 0;
        }
        scrn_map_set(3, ake_scrl_w[2].adrs);
        bg_w.bgw[3].position_x = 768 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        ake_Family_Set();
        break;
    case 3:
        ewk->wu.routine_no[0] += 1;
        for (i = 0; i < bg_w.scno; i++) {
            Bg_On_W(1 << i);
        }
        Bg_Off_W(8);
        Conclusion_Flag = 1;
        Conclusion_Type = 0;
        request_center_message(0);
        scrn_map_set(3, ake_scrl_w[2].adrs);
        bg_w.bgw[3].position_x = 256 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        ake_Family_Set();
        break;
    default:
        akebono_flag = 0;
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* 2i 060DF0AA, 3s-near: sf3 src/effd3.c:213 effect_D3_init */
s32 effect_D3_init(u8 ake_type) {
    WORK_Other* ewk;
    s16 ix;
    if (!Combo_Demo_Flag) {
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.id = 133;
        ewk->wu.be_flag = 1;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.old_rno[1] = 0;
        ewk->wu.type = ake_type;
        return 0;
    }
}
