/*
 * ENDBG14.C  Ending background 14 (2i)
 *
 * end_BG140 (entry 14) runs layer 1 (graphics, no move step), layer 0 and a synced layer 2 (as stage
 * 14's sync_bg14_common), then the zoom check, position correction and family set.
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

void end_bg140_layer0(void);
void end_bg140_layer0_init00(void);
void end_bg140_layer0_move(void);
void end_bg140_layer1(void);
void end_bg140_layer1_init00(void);
void end_bg140_none(void);
void end_bg140_sync(void);
#pragma inline(end_bg140_layer1, end_bg140_layer0)


/* provisional name */
/* 2i 060AABBC */
void end_BG140(void) {
    bgw_ptr = &bg_w.bgw[1];
    end_bg140_layer1();
    bgw_ptr = &bg_w.bgw[0];
    end_bg140_layer0();
    bgw_ptr = &bg_w.bgw[2];
    end_bg140_sync();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
/* 2i 060AAC34 */
void end_bg140_layer1(void) {
    void (*end_bg1401_jmp[2])() = { end_bg140_layer1_init00, end_bg140_none };
    end_bg1401_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060AAC5C */
void end_bg140_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xB158, 1);
}



/* provisional name */
/* 2i 060AAC9C */
void end_bg140_none(void) {
}



/* provisional name */
/* 2i 060AACA0 */
void end_bg140_layer0(void) {
    void (*end_bg1400_jmp[2])() = { end_bg140_layer0_init00, end_bg140_layer0_move };
    end_bg1400_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060AACC8 */
void end_bg140_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
/* 2i 060AACFE */
void end_bg140_layer0_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
/* 2i 060AAD40 */
void end_bg140_sync(void) {
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
