/*
 * ENDBG09.C  Ending background 09 (2i)
 *
 * end_BG090 (entry 9) runs layer 1 (no move step), layer 0 (graphics and palette) and a synced layer 2
 * (as stage 09's bg0603), then the zoom check, position correction and Bg_Family_Set_2.
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
void Bg_Family_Set_2(void);

void end_bg090_layer0(void);
void end_bg090_layer0_init00(void);
void end_bg090_layer0_move(void);
void end_bg090_layer1(void);
void end_bg090_layer1_init00(void);
void end_bg090_none(void);
void end_bg090_sync(void);
#pragma inline(end_bg090_layer1, end_bg090_layer0)


/* provisional name */
/* 2i 060AA46C */
void end_BG090(void) {
    bgw_ptr = &bg_w.bgw[1];
    end_bg090_layer1();
    bgw_ptr = &bg_w.bgw[0];
    end_bg090_layer0();
    bgw_ptr = &bg_w.bgw[2];
    end_bg090_sync();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set_2();
}



/* provisional name */
/* 2i 060AA4E4 */
void end_bg090_layer0(void) {
    void (*end_bg0900_jmp[2])() = { end_bg090_layer0_init00, end_bg090_layer0_move };
    end_bg0900_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060AA50C */
void end_bg090_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x88B0, 1);
    load_any_color_fade(99, 15, 15, 15);
}



/* provisional name */
/* 2i 060AA562 */
void end_bg090_layer0_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
/* 2i 060AA570 */
void end_bg090_layer1(void) {
    void (*end_bg0901_jmp[2])() = { end_bg090_layer1_init00, end_bg090_none };
    end_bg0901_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060AA598 */
void end_bg090_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
/* 2i 060AA5D4 */
void end_bg090_none(void) {
}



/* provisional name */
/* 2i 060AA610 */
void end_bg090_sync(void) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->zuubun = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->speed_x = 0xC000;
        bgw_ptr->speed_y = 0xC000;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        sync_fam_set3(2);
        break;
    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(2);
        break;
    }
}
