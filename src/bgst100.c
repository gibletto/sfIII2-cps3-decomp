/*
 * BGST100.C  Stage 10 background
 *
 * BG100 runs stage 10's three layers (Oro's stage): layer 1 (bg0902,
 * the chasing base layer: gfx, palette and the effects for bg_w.compel_flag), layer 0 (bg0901) and layer 2
 * (bg0903, a table form of bg_fam0900), then the zoom check, position correction and family set. The file also
 * holds the entrance demo (bg090_demo_check, demo90_base) and Oro's win scene (jijii_win_bg / jijii_win_bg2).
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
#include "fighter.h"
#include "eff06.h"
#include "EFF71.h"
#include "EFF72.h"
#include "EFF74.h"
#include "eff56.h"

/* bgw r_no_0 of a layer with an entrance demo: its bg*_jmp routine */
#define R0_INIT         0       /* set up the layer */
#define R0_WAIT         1       /* wait or colour step, then the entrance demo */
#define R0_DEMO         2       /* the entrance demo */
#define R0_MOVE         3       /* follow the fight */

/* bgw r_no_1 in demo90_base */
#define DEMO_WAIT       0       /* until Appear_free */
#define DEMO_SCROLL     1       /* scroll the Y down to 0 */
#define DEMO_APPEAR     2       /* until Appear_end is 2, then the next r_no_0 */

/* bg_w.bgw[1].r_no_1 in jijii_win_bg; jijii_win_bg2 follows it */
#define JW_RISE         0       /* at win_sp_flag 2, scroll the layer up, then set the flag to 3 */
#define JW_DONE         1       /* finished */

/* declarations the headers do not give */
s32 Check_Shin_Gouki_Next(void);
void load_any_color();
s32 effect_12_init();
s32 effect_18_init();

#include "EFF44.h"

void bg0901(void);
void bg0901_init00(void);
void bg0901_wait(void);
void bg0902(void);
void bg0902_init00(void);
void bg0902_color(void);
void bg0903(void);
void bg0903_init00(void);
void bg0903_wait(void);
void bg0903_move(void);
void bg090_demo_check(void);
void demo90_base(void);
void jijii_win_bg(void);
void jijii_win_bg2(void);
static void bg_move_common(void);
static void bg_base_move_common(void);


void BG100(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0902();
    bgw_ptr = &bg_w.bgw[0];
    bg0901();
    bgw_ptr = &bg_w.bgw[2];
    bg0903();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0901(void) {
    void (*bg0901_jmp[4])() = { bg0901_init00, bg0901_wait, demo90_base, bg_move_common };
    if (win_sp_flag) {
        jijii_win_bg2();
    } else {
        bg0901_jmp[bgw_ptr->r_no_0]();
    }
}



/* The demo check comes first. */
void bg0901_init00(void) {
    bg090_demo_check();
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
void bg0901_wait(void) {
    bgw_ptr->r_no_0++;
}



/* Each stage file has its own copy. */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



void bg0902(void) {
    void (*bg0902_jmp[4])() = { bg0902_init00, bg0902_color, demo90_base, bg_base_move_common };
    if (win_sp_flag) {
        jijii_win_bg();
    } else {
        bg0902_jmp[bgw_ptr->r_no_0]();
    }
}



/* The palette, and the effects by compel_flag. */
void bg0902_init00(void) {
    u8 lv;
    bg090_demo_check();
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    lv = bg_fade_level_tbl[bg_w.bg_index];
    if (Check_Shin_Gouki_Next()) {
        load_any_color_fade(108, lv, lv, lv);
    } else {
        load_any_color(108);
    }
    load_char_gfx(0x8BC0, 1);
    effect_06_init();
    effect_74_init();
    effect_44_init(6);
    effect_55_init();
    switch (bg_w.compel_flag) {
    case 0:
        effect_71_init();
        break;
    case 1:
        effect_12_init(7);
        effect_18_init(4);
        effect_72_init();
        effect_71_init();
        break;
    case 2:
        effect_12_init(7);
        effect_18_init(4);
        effect_72_init();
        break;
    case 3:
        effect_71_init();
        break;
    }
}



/* provisional name */
void bg0902_color(void) {
    u8 lv;
    bgw_ptr->r_no_0++;
    lv = bg_fade_level_tbl[bg_w.bg_index];
    if (Check_Shin_Gouki_Next()) {
        load_any_color_fade(108, lv, lv, lv);
    } else {
        load_any_color(108);
    }
}



/* Move the base layer and chase the players; each stage file has its own copy. */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



/* provisional name */
void bg0903(void) {
    void (*bg0903_jmp[4])() = { bg0903_init00, bg0903_wait, demo90_base, bg0903_move };
    if (win_sp_flag) {
        jijii_win_bg2();
    } else {
        bg0903_jmp[bgw_ptr->r_no_0]();
    }
}



/* provisional name */
void bg0903_init00(void) {
    bg090_demo_check();
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
void bg0903_wait(void) {
    bgw_ptr->r_no_0++;
}



/* provisional name */
void bg0903_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* The entrance demo (step 1, raised by speed_y * 200) runs only with Oro playing in the first area; otherwise step 3. */
void bg090_demo_check(void) {
    if ((plw->player_number != PL_ORO) && (plw[1].player_number != PL_ORO)) {
        bgw_ptr->r_no_0 = R0_MOVE;
    } else if (bg_w.area != 0) {
        bgw_ptr->r_no_0 = R0_MOVE;
    } else {
        bgw_ptr->r_no_0 = R0_WAIT;
        bgw_ptr->xy[1].cal = bgw_ptr->wxy[1].cal = bgw_ptr->speed_y * 200;
    }
}



void demo90_base(void) {
    s16 chk_pl;
    if (EXE_flag || Game_pause) {
        return;
    }
    switch (bgw_ptr->r_no_1) {
    case DEMO_WAIT:
        chk_pl = 0;
        if (plw->player_number == PL_ORO && plw[1].player_number == PL_ORO) {
            if (Appear_hv[0]) {
                chk_pl = 1;
            }
        } else if (plw[1].player_number == PL_ORO) {
            chk_pl = 1;
        }
        if (Appear_free[chk_pl]) {
            bgw_ptr->r_no_1++;
        }
        break;
    case DEMO_SCROLL:
        bgw_ptr->xy[1].cal -= bgw_ptr->speed_y * 0xA;
        bgw_ptr->wxy[1].cal -= bgw_ptr->speed_y * 0xA;
        if (bgw_ptr->xy[1].disp.pos <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0;
            bgw_ptr->wxy[1].cal = 0;
            break;
        }
        break;
    case DEMO_APPEAR:
        if (Appear_end != 2) {
            break;
        }
        bgw_ptr->r_no_0++;
        bgw_ptr->r_no_1 = 0;
        bgw_ptr->xy[1].cal = 0;
        bgw_ptr->wxy[1].cal = 0;
    }
}



/* Raise the base layer until its height passes 0xC0. */
void jijii_win_bg(void) {
    if (EXE_flag || Game_pause) {
        return;
    }
    switch (bgw_ptr->r_no_1) {
    case JW_RISE:
        if (win_sp_flag == 2) {
            bgw_ptr->xy[1].cal += 0xA0000;
            bgw_ptr->wxy[1].cal += 0xA0000;
            if (bgw_ptr->xy[1].disp.pos > 0xC0) {
                bgw_ptr->r_no_1++;
                win_sp_flag = 3;
            }
        }
        /* fall through */
    case JW_DONE:
        break;
    }
}



void jijii_win_bg2(void) {
    s16 zuu_work;
    s32 sp_work;
    if (EXE_flag || Game_pause) {
        return;
    }
    switch (bg_w.bgw[1].r_no_1) {
    case JW_RISE:
        if (win_sp_flag == 2) {
            zuu_work = 0xA;
            sp_work = bgw_ptr->speed_y * zuu_work;
            bgw_ptr->xy[1].cal += sp_work;
            bgw_ptr->wxy[1].cal += sp_work;
        }
        /* fall through */
    case JW_DONE:
        break;
    }
}
