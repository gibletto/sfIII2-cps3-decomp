/*
 * ENDBG01.C  Ending background 01
 *
 * end_BG010 (entry 1) runs layer 1 (graphics, no move step), layer 0 and a synced layer 2 (at X 0x200),
 * then the zoom check, position correction and family set.
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

/* declarations the headers do not give */
void zoom_ud_check(void);
void bg_x_move_check(void);
void bg_y_move_check(void);

void end_bg010_layer0(void);
void end_bg010_layer0_init00(void);
void end_bg010_layer0_move(void);
void end_bg010_layer1(void);
void end_bg010_layer1_init00(void);
void end_bg010_none(void);
void end_bg010_sync(void);
#pragma inline(end_bg010_layer1, end_bg010_layer0)


/* provisional name */
void end_BG010(void) {
    bgw_ptr = &bg_w.bgw[1];
    end_bg010_layer1();
    bgw_ptr = &bg_w.bgw[0];
    end_bg010_layer0();
    bgw_ptr = &bg_w.bgw[2];
    end_bg010_sync();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
void end_bg010_layer0(void) {
    void (*end_bg0100_jmp[2])() = { end_bg010_layer0_init00, end_bg010_layer0_move };
    end_bg0100_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void end_bg010_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
void end_bg010_layer0_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
void end_bg010_layer1(void) {
    void (*end_bg0101_jmp[2])() = { end_bg010_layer1_init00, end_bg010_none };
    end_bg0101_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void end_bg010_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x8E20, 1);
}



/* provisional name */
void end_bg010_none(void) {
}



/* provisional name */
void end_bg010_sync(void) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->speed_x = 0xD000;
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
