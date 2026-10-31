/*
 * BGST020.C  Stage 02 background
 *
 * BG020 runs stage 02's three scroll layers: layer 1 (bg0202: the line-scroll base layer, with the
 * stage's effects and its palette, faded when Shin Gouki is next), layer 0 (bg0201) and layer 2
 * (bg0203), then the zoom check, position correction and family set. Layers 0 and 2 wait one frame
 * after their init before they scroll.
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
#include "aboutspr.h"
#include "sys_config.h"
#include "sys_test.h"
#include "meta_col_mem.h"
#include "color3rd.h"
#include "eff05.h"
#include "eff06.h"
#include "eff88.h"

s32 Check_Shin_Gouki_Next(void);
void load_any_color();
#include "eff12.h"
s32 effect_18_init();
s32 effect_44_init();
void bg0201(void);
void bg0202(void);
void bg0203(void);
void bg0201_init00(void);
void bg0201_wait(void);
void bg0202_init00(void);
void bg0202_color(void);
void bg0202_move(void);
void bg0203_init00(void);
void bg0203_wait(void);
void bg0203_move(void);
static void bg_move_common(void);
#pragma inline(bg0201, bg0202, bg0203)


void BG020(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0202();
    bgw_ptr = &bg_w.bgw[0];
    bg0201();
    bgw_ptr = &bg_w.bgw[2];
    bg0203();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0201(void) {
    void (*bg0201_jmp[3])() = { bg0201_init00, bg0201_wait, bg_move_common };
    bg0201_jmp[bgw_ptr->r_no_0]();
}



void bg0201_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
/* one frame before layer 0 scrolls */
void bg0201_wait(void) {
    bgw_ptr->r_no_0++;
}



/* each stage file has its own copy */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



void bg0202(void) {
    void (*bg0202_jmp[3])() = { bg0202_init00, bg0202_color, bg0202_move };
    bg0202_jmp[bgw_ptr->r_no_0]();
}



/* a line-scroll layer, then the stage effects */
void bg0202_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->suzi_c_no = simmram_small_page_alloc_40(1);
    bgw_ptr->suzi_adrs = (u16*)simmram_slot_addr(bgw_ptr->suzi_c_no);
    scrn_linescroll_set_now(1, bgw_ptr->suzi_adrs);
    memset(bgw_ptr->suzi_adrs, 0, 0x1000);
    Bg_On_R(32);
    bgw_ptr->zuubun = 0x100;
    bgw_ptr->no_suzi_line = 967;
    bgw_ptr->u_line = 17;
    bgw_ptr->d_line = 16;
    bgw_ptr->start_suzi = bgw_ptr->suzi_adrs + 1932;
    suzi_line_clear(1);
    load_char_gfx(0x7BA0, 1);
    effect_05_init();
    effect_06_init();
    effect_12_init(0);
    effect_44_init(0);
    effect_18_init(1);
    if (Country == 8) {
        effect_88_init(0);
    }
}



/* provisional name */
/* the stage palette, faded to the level of the stage when Shin Gouki is next */
void bg0202_color(void) {
    u8 lv;
    bgw_ptr->r_no_0++;
    lv = bg_fade_level_tbl[bg_w.bg_index];
    if (Check_Shin_Gouki_Next()) {
        load_any_color_fade(103, lv, lv, lv);
    } else {
        load_any_color(103);
    }
}



/* provisional name */
/* base layer move and its line scroll */
void bg0202_move(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
    suzi_line_calc_fill(1);
}



/* provisional name */
/* layer 2 */
void bg0203(void) {
    void (*bg0203_jmp[3])() = { bg0203_init00, bg0203_wait, bg0203_move };
    bg0203_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg0203_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
void bg0203_wait(void) {
    bgw_ptr->r_no_0++;
}



/* provisional name */
void bg0203_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}
