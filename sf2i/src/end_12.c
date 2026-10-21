/*
 * END_12.C  Ending 12, 2nd Impact version
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
#include "end_12.h"



extern const s16 timer_12_tbl[4];
extern const s16 end_12_pos[4][2];
extern const PANEL end_1200_panel0[8];
extern const PANEL end_1200_panel1[8];
extern s16 end_cnt;
extern const u32 end_1200_scrn_data[];



/* 2i 060B86D4 */
void end_12000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xB208, 1);
        end_w.timer = timer_12_tbl[end_w.r_no_2];
        common_end_init01();
        end_1200_cell_set();
        bgm_request(22);
        break;
    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 == 4) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                bgm_request(27);
            } else {
                end_w.timer = timer_12_tbl[end_w.r_no_2];
            }
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        } else {
            end_1200_move();
            end_1201_move();
        }
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



/* 2i 060B879E */
void end_1200_move(void) {
    void (*end_1200_jp[4])() = { end_1200_0000, end_1200_0000, end_1200_0000, end_1200_3000 };
    bgw_ptr = &bg_w.bgw[0];
    end_1200_jp[end_w.r_no_2]();
}



/* 2i 060B8814 */
void end_1200_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if ((scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000) == 0) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_12_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_12_pos[end_w.r_no_2][1];
        switch (end_w.r_no_2) {
        case 0:
            effect_E6_init(78);
            Rewrite_End_Message(1);
            break;
        case 1:
            effect_E6_init(79);
            effect_E6_init(80);
            effect_E6_init(58);
            effect_E6_init(59);
            effect_E6_init(85);
            effect_E6_init(86);
            effect_E6_init(87);
            Rewrite_End_Message(2);
            break;
        case 2:
            Rewrite_End_Message(3);
            break;
        }
        break;
    case 1:
        break;
    }
}



/* 2i 060B88C6 */
void end_1200_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if ((scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000) == 0) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_12_pos[end_w.r_no_2][0];
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos = 0;
        effect_E6_init(81);
        effect_E6_init(82);
        end_cnt = 60;
        Rewrite_End_Message(4);
        end_fade_flag = 1;
        end_fade_timer = timer_12_tbl[3] - 120;
        break;
    case 1:
        end_cnt--;
        if (end_cnt < 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 2:
        bgw_ptr->xy[1].cal += 0x6000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        bg_w.bgw[1].xy[1].cal -= 0x4000;
        bg_w.bgw[1].abs_y = bgw_ptr->xy[1].disp.pos;
        if (bgw_ptr->xy[1].disp.pos > 48) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 3:
        break;
    }
}



/* 2i 060B89FC */
void end_1201_move(void) {
    void (*end_1201_jp[4])() = { end_X_com01, end_1201_0000, end_1201_0000, end_X_com01 };
    bgw_ptr = &bg_w.bgw[1];
    end_1201_jp[end_w.r_no_2]();
}



/* 2i 060B8A32 */
void end_1201_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(2);
        bgw_ptr->xy[0].disp.pos = end_12_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_12_pos[end_w.r_no_2][1];
        break;
    case 1:
        break;
    }
}



/* 2i 060B8AB8 */
void end_1200_cell_set(void) {
    s16 i;
    const PANEL* p;
    p = end_1200_panel0;
    for (i = 0; i < 8; i++, p++) {
        bg_cell_write(0, p->ofs, p->cell, (u32)end_1200_scrn_data, 0, 0x220);
    }
    p = end_1200_panel1;
    for (i = 0; i < 8; i++, p++) {
        bg_cell_write(1, p->ofs, p->cell, (u32)end_1200_scrn_data, 0, 0x220);
    }
}
