/*
 * BGST130.C  Stage 13 background
 *
 * BG130 runs stage 13's two layers: layer 1 (bg130_layer1, the chasing base layer: stage graphics, effects 05, 06,
 * 18 and 44) and layer 0 (bg130_layer0), then the zoom check, position correction and family set.
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

/* declarations the headers do not give */
s32 effect_18_init();

#include "EFF44.h"

void bg130_layer1(void);
void bg130_layer1_init00(void);
void bg130_layer0(void);
void bg130_layer0_init00(void);
static void bg_base_move_common(void);
static void bg_move_common(void);
#pragma inline(bg130_layer1, bg130_layer0)


void BG130(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg130_layer1();
    bgw_ptr = &bg_w.bgw[0];
    bg130_layer0();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
void bg130_layer1(void) {
    void (*bg130_layer1_jmp[2])() = { bg130_layer1_init00, bg_base_move_common };
    bg130_layer1_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg130_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x9060, 1);
    effect_05_init();
    effect_06_init();
    effect_18_init(7);
    effect_44_init(8);
}



/* Move the base layer and chase the players; each stage file has its own copy. */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



/* provisional name */
void bg130_layer0(void) {
    void (*bg130_layer0_jmp[2])() = { bg130_layer0_init00, bg_move_common };
    bg130_layer0_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg130_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* Each stage file has its own copy. */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}
