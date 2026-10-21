/*
 * BGST140.C  Stage 14 background (2nd Impact only)
 *
 * BG140 runs stage 14's three layers: layer 1 (bg140_layer1, the chasing base layer: stage graphics and effect
 * 05), layer 0 (bg140_layer0) and layer 2 (sync_bg14_common, a synced layer), then the zoom check, position
 * correction and family set.
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
#include "aboutspr.h"
#include "eff05.h"
#include "eff06.h"

/* trial declarations */
void zoom_ud_check(void);
void bg_x_move_check(void);
void bg_y_move_check(void);
void bg_base_x_move_check(void);
void bg_base_y_move_check(void);
void bg140_layer1(void);
void bg140_layer1_init00(void);
void bg140_layer0(void);
void bg140_layer0_init00(void);
void sync_bg14_common(void);
static void bg_base_move_common(void);
static void bg_move_common(void);
#pragma inline(bg140_layer1, bg140_layer0)


void BG140(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg140_layer1();
    bgw_ptr = &bg_w.bgw[0];
    bg140_layer0();
    bgw_ptr = &bg_w.bgw[2];
    sync_bg14_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
void bg140_layer1(void) {
    void (*bg140_layer1_jmp[2])() = { bg140_layer1_init00, bg_base_move_common };
    bg140_layer1_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg140_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xB158, 1);
    effect_05_init();
}



/* (2nd Impact: a copy per stage file) */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



/* provisional name */
void bg140_layer0(void) {
    void (*bg140_layer0_jmp[2])() = { bg140_layer0_init00, bg_move_common };
    bg140_layer0_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg140_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* (2nd Impact: a copy per stage file) */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* (2nd Impact: y limits 208, speed_x 0xC000) */
void sync_bg14_common(void) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->zuubun = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 208;
        bgw_ptr->speed_x = 0xC000;
        bgw_ptr->speed_y = 0xE000;
        sync_fam_set3(2);
        break;
    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(2);
        break;
    }
}
