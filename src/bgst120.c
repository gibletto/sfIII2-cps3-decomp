/*
 * BGST120.C  Stage 12 background
 *
 * BG120 runs stage 12's two layers: layer 1 (the chasing base layer, which loads the stage graphics and
 * starts effect 05) and layer 0, then the zoom check, position correction and family set.
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

void bg120_layer1(void);
void bg120_layer1_init00(void);
void bg120_layer0(void);
void bg120_layer0_init00(void);
static void bg_base_move_common(void);
static void bg_move_common(void);
#pragma inline(bg120_layer1, bg120_layer0)


void BG120(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg120_layer1();
    bgw_ptr = &bg_w.bgw[0];
    bg120_layer0();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
void bg120_layer1(void) {
    void (*bg120_layer1_jmp[2])() = { bg120_layer1_init00, bg_base_move_common };
    bg120_layer1_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg120_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x79C0, 1);
    effect_05_init();
}



/* each stage file has its own copy */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



/* provisional name */
void bg120_layer0(void) {
    void (*bg120_layer0_jmp[2])() = { bg120_layer0_init00, bg_move_common };
    bg120_layer0_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg120_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* each stage file has its own copy */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}
