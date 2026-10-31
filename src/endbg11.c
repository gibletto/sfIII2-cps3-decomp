/*
 * ENDBG11.C  Ending background 11
 *
 * end_BG110 (entry 11) runs layer 1 (palette, no move step) and layer 0, both placed against
 * bg_w.pos_offset, then the zoom check, position correction and family set.
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

void end_bg110_layer0(void);
void end_bg110_layer0_init00(void);
void end_bg110_layer0_move(void);
void end_bg110_layer1(void);
void end_bg110_layer1_init00(void);
void end_bg110_none(void);
#pragma inline(end_bg110_layer1, end_bg110_layer0)


/* provisional name */
void end_BG110(void) {
    bgw_ptr = &bg_w.bgw[1];
    end_bg110_layer1();
    bgw_ptr = &bg_w.bgw[0];
    end_bg110_layer0();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
void end_bg110_layer0(void) {
    void (*end_bg1100_jmp[2])() = { end_bg110_layer0_init00, end_bg110_layer0_move };
    end_bg1100_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void end_bg110_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
}



/* provisional name */
void end_bg110_layer0_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
void end_bg110_layer1(void) {
    void (*end_bg1101_jmp[2])() = { end_bg110_layer1_init00, end_bg110_none };
    end_bg1101_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void end_bg110_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    load_any_color_fade(107, 15, 15, 15);
}



/* provisional name */
void end_bg110_none(void) {
}
