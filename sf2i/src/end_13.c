/*
 * END_13.C  Ending 13, 2nd Impact version
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
#include "end_13.h"



extern const s16 timer_13_tbl[9];
extern const s16 end_13_pos[9][2];
extern const PANEL end_1300_panel0[8];
extern const PANEL end_1300_panel1[8];
extern const u32 end_1300_scrn_data[];



/* 2i 060B8B58 */
void end_13000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xB188, 1);
        end_w.timer = timer_13_tbl[end_w.r_no_2];
        common_end_init01();
        end_1300_cell_set();
        bgm_request(21);
        break;
    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 == 9) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
            } else {
                end_w.timer = timer_13_tbl[end_w.r_no_2];
            }
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        } else {
            end_1300_move();
            end_1301_move();
        }
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



/* 2i 060B8C1C */
void end_1300_move(void) {
    void (*end_1300_jp[9])() = { end_1300_0000, end_1300_1000, end_1300_0000, end_1300_3000, end_1300_0000, end_1300_0000, end_1300_0000, end_1300_0000, end_1300_8000 };
    bgw_ptr = &bg_w.bgw[0];
    end_1300_jp[end_w.r_no_2]();
}



/* 2i 060B8CA8 */
void end_1300_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if ((scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000) == 0) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_13_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_13_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 0x200;
        bgw_ptr->abs_y = 0;
        switch (end_w.r_no_2) {
        case 0:
            Rewrite_End_Message(1);
            break;
        case 2:
            Rewrite_End_Message(3);
            break;
        case 4:
            effect_E6_init(72);
            break;
        case 5:
            Rewrite_End_Message(4);
            break;
        case 6:
            effect_E6_init(75);
            break;
        case 7:
            effect_E6_init(76);
            end_fade_flag = 1;
            end_fade_timer = timer_13_tbl[7] - 120;
            break;
        }
        break;
    case 1:
        break;
    }
}



/* 2i 060B8D7C */
void end_1300_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if ((scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000) == 0) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_13_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_13_pos[end_w.r_no_2][1];
        bgw_ptr->xy[1].disp.pos += 24;
        effect_E6_init(70);
        Rewrite_End_Message(2);
        break;
    case 1:
        break;
    }
}



/* 2i 060B8E34 */
void end_1300_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if ((scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000) == 0) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_13_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_13_pos[end_w.r_no_2][1];
        bgw_ptr->free = 4;
        bgw_ptr->rewrite_flag = 0;
        effect_E6_init(71);
        Rewrite_End_Message(0);
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 2;
            bgw_ptr->rewrite_flag ^= 1;
            if (bgw_ptr->rewrite_flag) {
                bgw_ptr->xy[0].disp.pos += 1;
                bgw_ptr->abs_x += 1;
                bgw_ptr->xy[1].disp.pos += 2;
                bgw_ptr->abs_y += 2;
            } else {
                bgw_ptr->xy[0].disp.pos -= 1;
                bgw_ptr->abs_x -= 1;
                bgw_ptr->xy[1].disp.pos -= 2;
                bgw_ptr->abs_y -= 2;
            }
        }
        break;
    }
}



/* 2i 060B8F5E */
void end_1300_8000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_13_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_13_pos[end_w.r_no_2][1];
        bgw_ptr->xy[1].disp.pos += 48;
        effect_E6_init(77);
        Rewrite_End_Message(5);
        bgm_request(23);
        break;
    case 1:
        if (bgw_ptr->xy[1].disp.pos > 0xC0) {
            bgw_ptr->xy[1].cal -= 0x8000;
        }
        break;
    }
}



/* 2i 060B8FC4 */
void end_1301_move(void) {
    void (*end_1301_jp[9])() = { end_X_com01, end_X_com01, end_1301_2000, end_X_com01, end_X_com01, end_X_com01, end_X_com01, end_X_com01, end_X_com01 };
    bgw_ptr = &bg_w.bgw[1];
    end_1301_jp[end_w.r_no_2]();
}



/* 2i 060B903C */
void end_1301_2000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(2);
        bgw_ptr->xy[0].disp.pos = end_13_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_13_pos[end_w.r_no_2][1];
        break;
    case 1:
        break;
    }
}



/* 2i 060B907E */
void end_1300_cell_set(void) {
    s16 i;
    const PANEL* p;
    p = end_1300_panel0;
    for (i = 0; i < 8; i++, p++) {
        bg_cell_write(0, p->ofs, p->cell, (u32)end_1300_scrn_data, 0, 0x220);
    }
    p = end_1300_panel1;
    for (i = 0; i < 8; i++, p++) {
        bg_cell_write(1, p->ofs, p->cell, (u32)end_1300_scrn_data, 0, 0x220);
    }
}
