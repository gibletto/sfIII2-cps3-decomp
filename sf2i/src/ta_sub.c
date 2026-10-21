/*
 * ta_sub.c  Stage background object helpers
 *
 * Shared routines for the stage background tasks and their objects (effects that live in the
 * stage). sync_fam_set / sync_fam_set2 / sync_fam_set3 set a plane's family position from its BG
 * position. range_x_check / range_x_check2 decide whether an object is on screen, and the
 * disp_pos_trans_entry_* family converts an object's position to screen coordinates and draws it
 * only when it is visible (and background objects are not switched off). eff_hit_check and
 * eff_hit_check_sub test each player against the object's hit box using pl_hit_eff /
 * eff_hit_data and count contacts in eff_hit_flag. Small state checks used by stage objects:
 * complete_victory_check, either_pl_hissatsu_check (a player is doing a special move),
 * compel_dead_check, pl_shot_on_check (a button is down) and range_abs_check.
 * 2nd Impact: range_x_check allows 272 pixels each side, eff_hit_check skips type 5 objects, and
 * the add_*_sub movers apply the acceleration before the speed.
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
#include "fifo.h"
#include "aboutspr.h"
#include "HITCHECK.h"
#include "ta_sub.h"
#include "bg000.h"
#include "PLS02.h"
#include "ta_sub2.h"
#include "tate00.h"

#pragma inline(obr_no_disp_check)


struct PLW_tag;/* provisional name */
void sw_dummy_1(void) {}


/* provisional name */
void sw_dummy_2(void) {}



/* provisional name */
/* 2i 0609F924, 3s-exact: sf3 src/ta_sub.c:50 sync_fam_set */
void sync_fam_set(s16 num_of_bg) {
    s16 x;
    s16 y;
    bg_pos_hosei_sub3(num_of_bg);
    x = bg_w.bgw[num_of_bg].position_x;
    y = bg_w.bgw[num_of_bg].position_y;
    x = -x & 0x3FF;
    y = (0x300 - (y & 0x3FF)) & 0x3FF;
    Family_Set_W(num_of_bg + 1, x, y);
}



/* provisional name */
/* 2i 0609F974, 3s-near: sf3 src/ta_sub.c:64 sync_fam_set2 */
void sync_fam_set2(s16 num_of_bg) {
    s16 x;
    s16 y;
    bg_pos_hosei_sub2(num_of_bg);
    x = bg_w.bgw[num_of_bg].position_x;
    y = bg_w.bgw[num_of_bg].position_y;
    x = -x & 0x3FF;
    y += 12;
    y = (0x300 - (y & 0x3FF)) & 0x3FF;
    Family_Set_W(num_of_bg + 1, x, y);
}



/* 2i 0609F9C6, 3s-reloc: sf3 src/ta_sub.c:78 sync_fam_set3 */
void sync_fam_set3(bg_no)
s16 bg_no;
{
    s16 pos_work_x;
    s16 pos_work_y;
    s16 pos_x_w;
    s16 pos_y_w;
    if (bg_w.chase_flag & 0xF) {
        pos_x_w = bg_w.bgw[bg_no].chase_xy[0].disp.pos;
    } else {
        pos_x_w = bg_w.bgw[bg_no].wxy[0].disp.pos;
    }
    if (bg_w.chase_flag & 0xF0) {
        pos_y_w = bg_w.bgw[bg_no].chase_xy[1].disp.pos;
    } else {
        pos_y_w = bg_w.bgw[bg_no].xy[1].disp.pos;
    }
    pos_work_x = pos_x_w & 0x3FF;
    pos_work_x -= bg_w.pos_offset;
    pos_x_w -= bg_w.pos_offset;
    pos_work_x &= 0x3FF;
    if (bg_w.quake_x_index > 0) {
        pos_work_x += quake_x_tbl[bg_w.quake_x_index];
        pos_x_w += quake_x_tbl[bg_w.quake_x_index];
    }
    bg_w.bgw[bg_no].position_x = pos_work_x & 0x3FF;
    bg_w.bgw[bg_no].abs_x = pos_x_w;
    pos_work_y = pos_y_w & 0x3FF;
    pos_work_y += quake_y_tbl[bg_w.quake_y_index];
    pos_y_w += quake_y_tbl[bg_w.quake_y_index];
    bg_w.bgw[bg_no].position_y = pos_work_y & 0x3FF;
    bg_w.bgw[bg_no].abs_y = pos_y_w;
    pos_work_x = -pos_work_x & 0x3FF;
    pos_work_y = (0x300 - (pos_work_y & 0x3FF)) & 0x3FF;
    Family_Set_W(bg_no + 1, pos_work_x, pos_work_y);
}



/* 2i 0609FABC, 3s-near: sf3 src/ta_sub.c:117 range_x_check */
s32 range_x_check(WORK* wk) {
    s16 x;
    s16 w;
    if ((s8)bg_w.chase_flag & 0xF) {
        x = bg_w.bgw[wk->my_family - 1].chase_xy[0].disp.pos;
    } else {
        x = bg_w.bgw[wk->my_family - 1].wxy[0].disp.pos;
    }
    w = 272;
    x -= w;
    if (x > wk->xyz[0].disp.pos) {
        return 0;
    }
    x = bg_w.bgw[wk->my_family - 1].wxy[0].disp.pos + w;
    if (wk->xyz[0].disp.pos > x) {
        return 0;
    }
    return 1;
}



/* provisional name */
/* 2i 0609FB48, 3s-near: sf3 src/ta_sub.c:139 range_x_check2 */
s32 range_x_check2(WORK* wk) {
    s16 left;
    register s16 right;
    s16 w;
    left = bg_w.bgw[wk->my_family - 1].abs_x;
    w = 320;
    left -= w;
    if (left > wk->xyz[0].disp.pos) {
        return 0;
    }
    right = bg_w.bgw[wk->my_family - 1].wxy[0].disp.pos;
    right += w;
    if (wk->xyz[0].disp.pos > right) {
        return 0;
    }
    return 1;
}



/* 2i 0609FBCC, inferred: sf3 src/ta_sub.c:241 add_x_sub */
void add_x_sub(WORK_Other* ewk) {
    ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
    ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
}



void add_x_sub2(WORK_Other* ewk) {
    ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
    ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
}



/* provisional name */
/* 2i 0609FC0C, 3s-near: sf3 src/ta_sub.c:256 add_x_sub_flip */
void add_x_sub_flip(WORK_Other* ewk) {
    if (ewk->wu.rl_flag) {
        ewk->wu.mvxy.a[0].sp -= ewk->wu.mvxy.d[0].sp;
        ewk->wu.xyz[0].cal -= ewk->wu.mvxy.a[0].sp;
    } else {
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
    }
}



/* 2i 0609FC50, 3s-near: sf3 src/ta_sub.c:268 add_y_sub */
void add_y_sub(WORK_Other* ewk) {
    ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;
    ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
}



/* 2i 0609FC72, 3s-near: sf3 src/ta_sub.c:275 add_y_sub2 */
void add_y_sub2(WORK_Other* ewk) {
    ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
    ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;
}



/* 2i 0609FC92, 3s-near: sf3 src/ta_sub.c:282 obr_no_disp_check */
s32 obr_no_disp_check(void) {
    if (seraph_flag | akebono_flag | sa_pa_flag) {
        return 1;
    }
    return 0;
}




/* 2i 0609FCB0, 3s-near: sf3 src/ta_sub.c:292 disp_pos_trans_entry */
void disp_pos_trans_entry(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



/* 2i 0609FD04, 3s-near: sf3 src/ta_sub.c:303 disp_pos_trans_entry5 */
void disp_pos_trans_entry5(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



/* 2i 0609FD40, 3s-near: sf3 src/ta_sub.c:314 disp_pos_trans_entry_r */
void disp_pos_trans_entry_r(WORK_Other* ewk) {
    if (obr_no_disp_check() == 0) {
        if (range_x_check((WORK*)ewk) != 0) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4(&ewk->wu);
        }
    }
}



/* 2i 0609FD92, 3s-near: sf3 src/ta_sub.c:362 disp_pos_trans_entry_s */
void disp_pos_trans_entry_s(WORK_Other* ewk) {
    if (obr_no_disp_check() == 0) {
        suzi_sync_pos_set(ewk);
        sort_push_request4(&ewk->wu);
    }
}



/* 2i 0609FDD0, 3s-near: sf3 src/ta_sub.c:371 disp_pos_trans_entry_rs */
void disp_pos_trans_entry_rs(WORK_Other* ewk) {
    if (obr_no_disp_check() == 0) {
        if (range_x_check((WORK*)ewk) != 0) {
            suzi_sync_pos_set(ewk);
            sort_push_request4(&ewk->wu);
        }
    }
}

/* provisional name */
/* 2i 0609FE28, 3s-reloc: sf3 src/ta_sub.c:381 disp_pos_trans_entry_seraph */
void disp_pos_trans_entry_seraph(WORK_Other* ewk)
{
    if (seraph_flag) {
        suzi_sync_pos_set(ewk);
        sort_push_request4(&ewk->wu);
    }
}



/* 2i 0609FE50, 3s-near: sf3 src/ta_sub.c:391 pl_eff_trans_entry */
void pl_eff_trans_entry(WORK_Other* ewk) {
    if (obr_no_disp_check() == 0) {
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request(&ewk->wu);
    }
}



/* provisional name */
void pl_eff_trans_entry_r(WORK_Other* ewk) {
    if (obr_no_disp_check() == 0) {
        if (range_x_check((WORK*)ewk) != 0) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request(&ewk->wu);
        }
    }
}



/* Accumulates this effect's hits on the players; returns its hit count. */
/* 2i 0609FEDE, 3s-near: sf3 src/ta_sub.c:415 eff_hit_check */
s32 eff_hit_check(WORK_Other* ewk, s16 type) {
    if (ewk->wu.type == 5) {
        return 0;
    }
    if (!EXE_obroll) {
        if (type) {
            if (pcon_dp_flag) {
                eff_hit_flag[ewk->wu.type] += eff_hit_check_sub(ewk, &plw[0]);
                eff_hit_flag[ewk->wu.type] += eff_hit_check_sub(ewk, &plw[1]);
            }
        } else {
            eff_hit_flag[ewk->wu.type] += eff_hit_check_sub(ewk, &plw[0]);
            eff_hit_flag[ewk->wu.type] += eff_hit_check_sub(ewk, &plw[1]);
        }
    }
    return eff_hit_flag[ewk->wu.type];
}



/* 2i 0609FFA8, 3s-near: sf3 src/ta_sub.c:432 eff_hit_check_sub */
s32 eff_hit_check_sub(WORK_Other* ewk, PLW* pl) {
    if (pl->wu.routine_no[1] == 1) {
        if (pl->wu.routine_no[2] < 14 || pl->wu.routine_no[2] >= 24) {
            return 0;
        }
        if (hit_check_subroutine(
                &pl->wu, &ewk->wu, &pl_hit_eff[pl->player_number][0], &eff_hit_data[ewk->wu.type][0])) {
            return 1;
        }
    }
    return 0;
}


/* 2i 060A000E, 3s-near: sf3 src/ta_sub.c:515 eff_hit_flag_clear */
void eff_hit_flag_clear(void) {
    s16 i;
    s16* ptr;
    ptr = &eff_hit_flag[0];
    for (i = 0; i < 0xB; i++) {
        *ptr++ = 0;
    }
}



/* provisional name */
/* 2i 060A0048, 3s-reloc: sf3 src/ta_sub.c:527 complete_victory_check */
s32 complete_victory_check(void) {
    if (!Allow_a_battle_f && Conclusion_Flag == 1 && C_No0 >= 2 && Complete_Victory) {
        return 1;
    }
    return 0;
}


/* provisional name */
/* 2i 060A0074, 3s-near: sf3 src/ta_sub.c:536 get_winner_player_number */
s16 get_winner_player_number(void) {
    return plw[Winner_id].player_number;
}


/* provisional name */
s8 get_winner_id(void) {
    return Winner_id;
}

/* provisional name */
/* 2i 060A0090, 3s-reloc: sf3 src/ta_sub.c:547 range_abs_check */
u32 range_abs_check(s16 a, s16 b, s16 range)
{
    s16 dist;
    dist = a - b;
    if (dist < 0) {
        dist = -dist;
    }
    if (dist < range) {
        return 1;
    }
    return 0;
}



/* provisional name */
/* 2i 060A00AC, 3s-near: sf3 src/ta_sub.c:563 either_pl_hissatsu_check */
s32 either_pl_hissatsu_check(void) {
    if (plw[0].wu.routine_no[1] == 4 && plw[0].wu.routine_no[2] >= 16) {
        return 1;
    }
    if (plw[1].wu.routine_no[1] == 4 && plw[1].wu.routine_no[2] >= 16) {
        return 1;
    }
    return 0;
}



/* 2i 060A00E0, 3s-reloc: sf3 src/ta_sub.c:575 compel_dead_check */
s32 compel_dead_check(WORK_Other* ewk) {
    if (bg_w.compel_on && ewk->wu.dead_f) {
        return 1;
    }
    return 0;
}

/* provisional name */
/* 2i 060A00FA, 3s-near: sf3 src/ta_sub.c:583 pl_shot_on_check */
s32 pl_shot_on_check(pl)
s16 pl;
{
    if (pl) {
        if (p2sw_0 & 0x7F0) {
            return 1;
        }
        return 0;
    }
    if (p1sw_0 & 0x7F0) {
        return 1;
    }
    return 0;
}
