/*
 * END_6.C  Ending 6 (end_06000)
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "fighter.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "SYS_sub.h"
#include "efff7.h"
#include "efff8_code.h"
#include "EFFF9.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "end_main.h"
#include "effe6.h"
#include "aboutspr.h"
#include "end_6.h"



extern const s8 EM_Candidate_Data[][4][8];
extern u16 End_Course;



void end_06000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case END1_INIT:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xB248, 1);
        end_w.timer = timer_6_tbl[end_w.r_no_2];
        common_end_init01();
        end_600_cell_set();
        BGM_Request(21);
        break;
    case END1_SCENES:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 == 4) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
            } else {
                end_w.timer = timer_6_tbl[end_w.r_no_2];
            }
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        } else {
            end_600_move();
            end_601_move();
        }
        /* fall through */
    case END1_DONE:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_600_move(void) {
    void (*end_600_jp[4])() = { end_600_0000, end_600_0000, end_600_0000, end_600_0003 };
    bgw_ptr = &bg_w.bgw[0];
    end_600_jp[end_w.r_no_2]();
}



void end_600_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if ((scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000) == 0) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        switch (end_w.r_no_2) {
        case 0:
            Rewrite_End_Message(1);
            break;
        case 1:
            end_fade_flag = 1;
            end_fade_timer = timer_6_tbl[1] - 120;
            Rewrite_End_Message(2);
            break;
        case 2:
            if (EM_Candidate_Data[PL_HUGO][End_Course][7] != PL_ELENA) {
                Rewrite_End_Message(3);
            } else {
                Rewrite_End_Message(8);
            }
            BGM_Request(23);
            break;
        }
        break;
    case 1:
        break;
    }
}



void end_600_0003(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if ((scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000) == 0) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        effect_E6_init(84);
        effect_E6_init(88);
        effect_E6_init(89);
        switch (EM_Candidate_Data[PL_HUGO][End_Course][7]) {
        case PL_GILL:
            effect_E6_init(94);
            Rewrite_End_Message(7);
            break;
        case PL_RYU:
            effect_E6_init(91);
            Rewrite_End_Message(5);
            break;
        case PL_NECRO:
            effect_E6_init(92);
            effect_E6_init(93);
            Rewrite_End_Message(4);
            break;
        case PL_ELENA:
        default:
            effect_E6_init(90);
            Rewrite_End_Message(6);
            break;
        }
        break;
    case 1:
        break;
    }
}



void end_601_move(void) {
    void (*end_601_jp[4])() = { end_601_0000, end_601_0000, end_X_com01, end_X_com01 };
    bgw_ptr = &bg_w.bgw[1];
    end_601_jp[end_w.r_no_2]();
}



void end_601_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if ((scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000) == 0) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        break;
    case 1:
        break;
    }
}



void end_600_cell_set(void) {
    s16 i;
    const PANEL* p;
    p = end_600_bg0_cell_tbl;
    for (i = 0; i < 8; i++, p++) {
        bg_cell_write(0, p->ofs, p->cell, (u32)end_600_scrn_data, 0, 0x220);
    }
    p = end_600_bg1_cell_tbl;
    for (i = 0; i < 4; i++, p++) {
        bg_cell_write(1, p->ofs, p->cell, (u32)end_600_scrn_data, 0, 0x220);
    }
}
