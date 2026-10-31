/*
 * BGST050.C  Stage 05 background
 *
 * BG050 runs stage 05's three layers: layer 1 (bg0502, the chasing base layer), layer 0 (bg0501: the stage
 * graphics and effects; bg050_check picks the start position and bg050_demo scrolls it to 0x200) and layer 2
 * (bg0503, scrolled left with layer 1's movement, plus the stage's sound effect).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "SYS_sub.h"
#include "ta_sub.h"
#include "ta_sub2.h"
#include "aboutspr.h"
#include "eff05.h"
#include "EFF11.h"
#include "sys_config.h"
#include "sys_test.h"
#include "meta_col_mem.h"
#include "color3rd.h"
#include "eff06.h"
#include "SE.h"
#include "EFF07.h"
#include "fighter.h"

/* declarations the headers do not give */
s32 Check_Shin_Gouki_Next(void);
void load_any_color();
void Bg_Family_Set_3(void);
s32 effect_12_init();
s32 effect_18_init();

#include "EFF44.h"

void bg0501(void);
void bg0502(void);
void bg0503(void);
void bg0501_init01(void);
void bg0502_init01(void);
void bg0503_init01(void);
void bg0503_move(void);
void bg050_init00(void);
s32 bg050_check(void);
void bg050_demo(void);
static void bg_move_common(void);
static void bg_base_move_common(void);
#pragma inline(bg0501, bg0502, bg0503)


void BG050(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0502();
    bgw_ptr = &bg_w.bgw[0];
    bg0501();
    bgw_ptr = &bg_w.bgw[2];
    bg0503();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set_3();
}



void bg0501(void) {
    void (*bg0501_jmp[4])() = { bg050_init00, bg0501_init01, bg050_demo, bg_move_common };
    bg0501_jmp[bgw_ptr->r_no_0]();
}



void bg0501_init01(void) {
    bgw_ptr->r_no_0++;
    if (bg_w.area == 0) {
        bg_app = 1;
        if (bg050_check()) {
            bg_w.dmm0[0] = 1;
            bgw_ptr->xy[0].disp.pos = 250;
            bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        } else {
            bg_w.dmm0[0] = 0;
            bgw_ptr->xy[0].disp.pos = 776;
            bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        }
    } else {
        bgw_ptr->r_no_0++;
    }
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x8400, 1);
    effect_05_init();
    effect_06_init();
    effect_12_init(2);
    effect_44_init(3);
    effect_07_init();
    effect_18_init(5);
}



static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



void bg0502(void) {
    void (*bg0502_jmp[4])() = { bg050_init00, bg0502_init01, bg050_demo, bg_base_move_common };
    bg0502_jmp[bgw_ptr->r_no_0]();
}



void bg0502_init01(void) {
    bgw_ptr->r_no_0++;
    if (bg_w.area == 0) {
        if (bg050_check()) {
            bgw_ptr->xy[0].disp.pos = 250;
            bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        } else {
            bgw_ptr->xy[0].disp.pos = 776;
            bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        }
    } else {
        bgw_ptr->r_no_0++;
    }
    bgw_ptr->zuubun = 0;
}



static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



void bg0503(void) {
    void (*bg0503_jmp[4])() = { bg050_init00, bg0503_init01, bg050_demo, bg0503_move };
    bg0503_jmp[bgw_ptr->r_no_0]();
}



void bg0503_init01(void) {
    bgw_ptr->r_no_0++;
    Sound_SE(110);
}



void bg0503_move(void) {
    s16 d;
    if (EXE_flag == 0 && Game_pause == 0) {
        d = bg_w.bgw[1].wxy[0].disp.pos - bg_w.bgw[1].old_pos_x;
        if (d < 0) {
            bgw_ptr->xy[0].disp.pos += d;
            bgw_ptr->wxy[0].disp.pos += d;
        }
        if (!EXE_obroll) {
            bgw_ptr->xy[0].disp.pos -= 5;
            bgw_ptr->wxy[0].disp.pos -= 5;
        }
    }
    bg_y_move_check();
}



void bg050_init00(void) {
    u8 lv;
    if (!bgw_ptr->fam_no) {
        lv = bg_fade_level_tbl[bg_w.bg_index];
        if (Check_Shin_Gouki_Next()) {
            load_any_color_fade(97, lv, lv, lv);
        } else {
            load_any_color(97);
        }
    }
    bgw_ptr->r_no_0++;
    bgw_ptr->xy[0].disp.pos = bgw_ptr->old_pos_x = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
}



s32 bg050_check(void) {
    if (plw[0].player_number == PL_NECRO && plw[1].player_number == PL_NECRO) {
        if (Appear_hv[0]) {
            return 0;
        }
        return 1;
    }
    if (plw[0].player_number != PL_NECRO && plw[1].player_number == PL_NECRO) {
        return 0;
    }
    return 1;
}



void bg050_demo(void) {
    s32 (*fp)(void);
    if (EXE_flag || Game_pause) {
        return;
    }
    if (bg_w.dmm0[0]) {
        if ((fp = Cut_Cut_Cut)()) {
            bgw_ptr->wxy[0].cal += bgw_ptr->speed_x * 4;
        } else {
            bgw_ptr->wxy[0].cal += bgw_ptr->speed_x * 4;
        }
        if (bgw_ptr->wxy[0].disp.pos > 0x200) {
            bgw_ptr->xy[0].cal = bgw_ptr->wxy[0].cal = 0x2000000;
            bgw_ptr->r_no_0++;
            bg_app = 0;
        }
    } else {
        if (Cut_Cut_Cut()) {
            bgw_ptr->wxy[0].cal -= bgw_ptr->speed_x * 4;
        } else {
            bgw_ptr->wxy[0].cal -= bgw_ptr->speed_x * 4;
        }
        if (bgw_ptr->wxy[0].disp.pos < 0x200) {
            bgw_ptr->xy[0].cal = bgw_ptr->wxy[0].cal = 0x2000000;
            bgw_ptr->r_no_0++;
            bg_app = 0;
        }
    }
}
