/*
 * ENDBG00.C  Ending background 00 (2nd Impact only)
 *
 * end_BG000 (the ending table's entry 0) runs layer 1 (graphics, no move step), layer 0 and two synced
 * layers (2 and 6, end_bg000_sync with the family number; speed_x from bg_sync_speed_tbl), then the zoom
 * check, position correction and family set.
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
/* provisional name */
extern const s32 bg_sync_speed_tbl[];     /* the synced layers' speed_x by family (bgst000's table) */

void end_bg000_layer1(void);
void end_bg000_layer1_init00(void);
void end_bg000_none(void);
void end_bg000_layer0(void);
void end_bg000_layer0_init00(void);
void end_bg000_layer0_move(void);
void end_bg000_sync(s16 fam);
#pragma inline(end_bg000_layer1, end_bg000_layer0)


/* provisional name */
void end_BG000(void) {
    bgw_ptr = &bg_w.bgw[1];
    end_bg000_layer1();
    bgw_ptr = &bg_w.bgw[0];
    end_bg000_layer0();
    bgw_ptr = &bg_w.bgw[2];
    end_bg000_sync(2);
    bgw_ptr = &bg_w.bgw[6];
    end_bg000_sync(6);
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
void end_bg000_layer1(void) {
    void (*end_bg0001_jmp[2])() = { end_bg000_layer1_init00, end_bg000_none };
    end_bg0001_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void end_bg000_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    load_char_gfx(0x9B90, 1);
}



/* provisional name */
void end_bg000_none(void) {
}



/* provisional name */
void end_bg000_layer0(void) {
    void (*end_bg0000_jmp[2])() = { end_bg000_layer0_init00, end_bg000_layer0_move };
    end_bg0000_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void end_bg000_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
}



/* provisional name */
void end_bg000_layer0_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
void end_bg000_sync(s16 fam) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->xy[1].cal = 0;
        bgw_ptr->xy[0].disp.low = 0;
        bgw_ptr->pos_y_work = 0;
        bgw_ptr->zuubun = 0;
        bgw_ptr->fam_no = fam;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 216;
        bgw_ptr->speed_x = bg_sync_speed_tbl[fam];
        bgw_ptr->speed_y = 0xE000;
        bgw_ptr->xy[1].cal = 0;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->hos_xy[1].disp.pos = bgw_ptr->wxy[1].cal = bgw_ptr->xy[1].cal;
        sync_fam_set3(fam);
        break;
    default:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(fam);
        break;
    }
}
