/*
 * ENDBG13.C  Ending background 13 (2i)
 *
 * end_BG130 (entry 13) runs layer 1 (graphics, no move step) and layer 0, then the zoom check, position
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
#include "color3rd.h"

/* trial declarations */
void zoom_ud_check(void);
void bg_x_move_check(void);
void bg_y_move_check(void);

void end_bg130_layer0(void);
void end_bg130_layer0_init00(void);
void end_bg130_layer0_move(void);
void end_bg130_layer1(void);
void end_bg130_layer1_init00(void);
void end_bg130_none(void);
#pragma inline(end_bg130_layer1, end_bg130_layer0)


/* provisional name */
/* 2i 060AAA54 */
void end_BG130(void) {
    bgw_ptr = &bg_w.bgw[1];
    end_bg130_layer1();
    bgw_ptr = &bg_w.bgw[0];
    end_bg130_layer0();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
/* 2i 060AAAB0 */
void end_bg130_layer1(void) {
    void (*end_bg1301_jmp[2])() = { end_bg130_layer1_init00, end_bg130_none };
    end_bg1301_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060AAADA */
void end_bg130_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x9060, 1);
}



/* provisional name */
/* 2i 060AAB1A */
void end_bg130_none(void) {
}



/* provisional name */
/* 2i 060AAB1E */
void end_bg130_layer0(void) {
    void (*end_bg1300_jmp[2])() = { end_bg130_layer0_init00, end_bg130_layer0_move };
    end_bg1300_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060AAB46 */
void end_bg130_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
/* 2i 060AAB7C */
void end_bg130_layer0_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}
