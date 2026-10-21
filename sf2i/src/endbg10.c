/*
 * ENDBG10.C  Ending background 10 (2i)
 *
 * end_BG100 (entry 10) runs layer 1 (palette and graphics, no move step), layer 0 and layer 2, then the
 * zoom check, position correction and family set.
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

void end_bg100_layer0(void);
void end_bg100_layer0_init00(void);
void end_bg100_layer0_move(void);
void end_bg100_layer1(void);
void end_bg100_layer1_init00(void);
void end_bg100_none(void);
void end_bg100_layer2(void);
void end_bg100_layer2_init00(void);
void end_bg100_layer2_move(void);
#pragma inline(end_bg100_layer1, end_bg100_layer0, end_bg100_layer2)


/* provisional name */
/* 2i 060AA6B8 */
void end_BG100(void) {
    bgw_ptr = &bg_w.bgw[1];
    end_bg100_layer1();
    bgw_ptr = &bg_w.bgw[0];
    end_bg100_layer0();
    bgw_ptr = &bg_w.bgw[2];
    end_bg100_layer2();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
/* 2i 060AA748 */
void end_bg100_layer0(void) {
    void (*end_bg1000_jmp[2])() = { end_bg100_layer0_init00, end_bg100_layer0_move };
    end_bg1000_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060AA770 */
void end_bg100_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
/* 2i 060AA7A6 */
void end_bg100_layer0_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
/* 2i 060AA7B4 */
void end_bg100_layer1(void) {
    void (*end_bg1001_jmp[2])() = { end_bg100_layer1_init00, end_bg100_none };
    end_bg1001_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060AA7DC */
void end_bg100_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_any_color_fade(108, 15, 15, 15);
    load_char_gfx(0x8BC0, 1);
}



/* provisional name */
/* 2i 060AA82C */
void end_bg100_none(void) {
}



/* provisional name */
/* 2i 060AA86C */
void end_bg100_layer2(void) {
    void (*end_bg1002_jmp[2])() = { end_bg100_layer2_init00, end_bg100_layer2_move };
    end_bg1002_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060AA894 */
void end_bg100_layer2_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
/* 2i 060AA8CA */
void end_bg100_layer2_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}
