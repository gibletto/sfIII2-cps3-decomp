/*
 * END_SUB_2.C  Ending support: prize cards, CD checks, staff roll, debug fights and colour loads (part 2)
 *
 * Routines: cd_keep_spinning_tick, cd_selftest_periodic, cd_error_fatal_hang, staff_roll_skip_check,
 * staff_roll_put, staff_roll_main.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "VITAL.h"
#include "count.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFH3.h"
#include "effh4.h"
#include "effh5.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "Manage.h"
#include "manage_2.h"
#include "EFFM7.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "HITCHECK.h"
#include "cmb_cont.h"
#include "SLOWF.h"
#include "Entry.h"
#include "entry_2.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "fifo.h"
#include "ta_sub2.h"
#include "tate00.h"
#include "ta_sub.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "cps3.h"

/* staff_r_no: the staff roll (staff_roll_main) */
#define STAFF_INIT      0       /* set up the staff roll */
#define STAFF_ROLL      1       /* roll the names */
#define STAFF_WAIT      2       /* wait end_w.timer, then on */
#define STAFF_LAST      3       /* after the last name: wait end_w.timer */
#define STAFF_END       4       /* (default) finished */

s16 cd_ready_flag;  /* 02028284 */
s16 cd_spin_timer;  /* 02028286 */
s16 roll_rate2;  /* 02028288 */
s16 roll_rate_t2;  /* 0202828A */
s16 roll_stop;  /* 0202828C */
s16 name_timer;  /* 0202828E */


static s16 staff_name_ptr = 0;  /* 020069A4 */
static s32 staffroll_end = 0;  /* 020069A8 */
/* 020069AC */
/* Stored after staffroll_end. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of staffroll_end. */
u32 staffroll_end_tail[1] = {
    0,
};


s32 effect_H6_init(s16 timer, s8* str, s16 X, s16 Y, s16 Original_Color, s32 unused);

extern s32 staff_r_no;

#pragma inline(card_pl_work_clear)



/* provisional name */
void cd_keep_spinning_tick(void) {
    if (cd_ready_flag) {
        if (!cd_spin_timer) {
            scsi_start_stop_unit(1, 1);
            cd_spin_timer = 600;
        }
        cd_spin_timer--;
    }
}



/* provisional name */
void cd_selftest_periodic(void) {
    if (cd_ready_flag) {
        _builtin_set_imask(15);
        if (cd_check_drive_inquiry() != 0) {
            cd_error_fatal_hang(0);
        }
        if (cd_check_disc_id() != 0) {
            cd_error_fatal_hang(1);
        }
        _builtin_set_imask(1);
    }
}



/* provisional name */
void cd_error_fatal_hang(s32 kind) {
    coin_lock_set(-1);
    set_screen_mode(3);
    screen_flip_offsets_set();
    Scr_all_clear_Wait();
    coin_work_init();
    Cd_Error_Flag = 1;
    palette_bank_set(0);
    palette_write(0, sys_palette, 0x100);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x8000), (char*)sys_font_cg, 0x8C);
    clear_scroll_layer_state_and_mask();
    sound_driver_init();
    kill_tasks_by_priority(3, 1);
    switch (kind) {
    case 0:
        tilemap_print_string_attr(18, 16, 40, no_cd_drive_mes);
        break;
    case 1:
        tilemap_print_string_attr(21, 16, 40, no_cd_rom_mes);
        break;
    }
    while (1) {
    }
}



/* provisional name */
s32 staff_roll_skip_check(void) {
    u16 v;
    if (!end_no_cut) {
        if (WINNER) {
            v = p2sw_0;
        } else {
            v = p1sw_0;
        }
        if (v & 0x7F0) {
            return 1;
        }
    }
    return 0;
}



/* provisional name */
void staff_roll_put(id, x, y, a, b)
s32 id;
s32 x;
s32 y;
s32 a;
s8* b;
{
    s8* su;
    s16 xu;
    s16 yu;
    su = b;
    xu = x;
    yu = y;
    xu += bg_w.bgw[5].xy[0].disp.pos - 192;
    yu += bg_w.bgw[5].position_y;
    effect_H6_init(id, su, xu, yu, a, -1);
}




/* provisional name */
s32 staff_roll_main(void) {
    s32 fx;
    s32 fy;
    switch (staff_r_no) {
    case STAFF_INIT:
        staff_r_no++;
        staffroll_end = 0;
        bg_w.bgw[5].wxy[0].cal = bg_w.bgw[5].xy[0].cal = 0x1000000;
        bg_w.bgw[5].xy[1].cal = 0;
        bg_w.bgw[5].position_x = 0x100 - bg_w.pos_offset;
        bg_w.bgw[5].position_y = 0;
        fx = bg_w.bgw[5].position_x;
        fy = bg_w.bgw[5].position_y;
        fx = -fx & 0x3FF;
        fy = (0x300 - (fy & 0x3FF)) & 0x3FF;
        Family_Set_R(6, fx, fy);
        roll_rate2 = 1;
        staff_name_ptr = roll_stop = 0;
        end_w.timer = 0;
        name_timer = 0;
        staff_roll_timer = 7830;
        break;
    case STAFF_ROLL:
        if (staff_roll_skip_check()) {
            roll_rate_t2 = 5;
        } else {
            roll_rate_t2 = 1;
        }
        if (end_w.timer >= 0) {
            end_w.timer -= roll_rate_t2;
            staff_roll_timer = staff_roll_timer - roll_rate_t2;
        } else if (staff_roll_tbl[staff_name_ptr].str == 0) {
            staff_r_no = STAFF_LAST;
            end_w.timer = staff_roll_tbl[staff_name_ptr].wait;
            break;
        } else {
            name_timer = -1;
            {
                s16 w, x, y, attr;
                w = staff_roll_tbl[staff_name_ptr].wait;
                x = staff_roll_tbl[staff_name_ptr].x;
                y = staff_roll_tbl[staff_name_ptr].y;
                attr = staff_roll_tbl[staff_name_ptr].attr;
                staff_roll_put(w, x, y, attr, staff_roll_tbl[staff_name_ptr].str);
            }
            end_w.timer = staff_roll_tbl[staff_name_ptr].wait;
            staff_name_ptr++;
        }
        if (name_timer >= 0) {
            name_timer = name_timer - roll_rate_t2;
            break;
        }
        {
            s16 x, y, attr;
            x = staff_roll_tbl[staff_name_ptr].x;
            y = staff_roll_tbl[staff_name_ptr].y;
            attr = staff_roll_tbl[staff_name_ptr].attr;
            staff_roll_put(270, x, y, attr, staff_roll_tbl[staff_name_ptr].str);
        }
        name_timer = staff_roll_tbl[staff_name_ptr].wait;
        staff_name_ptr++;
        {
            s16 x, y, attr;
            x = staff_roll_tbl[staff_name_ptr].x;
            y = staff_roll_tbl[staff_name_ptr].y;
            attr = staff_roll_tbl[staff_name_ptr].attr;
            staff_roll_put(270, x, y, attr, staff_roll_tbl[staff_name_ptr].str);
        }
        staff_name_ptr++;
        if (staff_roll_tbl[staff_name_ptr].wait == 0) {
            {
                s16 x, y, attr;
                x = staff_roll_tbl[staff_name_ptr].x;
                y = staff_roll_tbl[staff_name_ptr].y;
                attr = staff_roll_tbl[staff_name_ptr].attr;
                staff_roll_put(270, x, y, attr, staff_roll_tbl[staff_name_ptr].str);
            }
            staff_name_ptr++;
            {
                s16 x, y, attr;
                x = staff_roll_tbl[staff_name_ptr].x;
                y = staff_roll_tbl[staff_name_ptr].y;
                attr = staff_roll_tbl[staff_name_ptr].attr;
                staff_roll_put(270, x, y, attr, staff_roll_tbl[staff_name_ptr].str);
            }
            staff_name_ptr++;
        } else {
e1: break;
        }
        if (staff_roll_tbl[staff_name_ptr].wait == 0) {
            {
                s16 x, y, attr;
                x = staff_roll_tbl[staff_name_ptr].x;
                y = staff_roll_tbl[staff_name_ptr].y;
                attr = staff_roll_tbl[staff_name_ptr].attr;
                staff_roll_put(270, x, y, attr, staff_roll_tbl[staff_name_ptr].str);
            }
            staff_name_ptr++;
            {
                s16 x, y, attr;
                x = staff_roll_tbl[staff_name_ptr].x;
                y = staff_roll_tbl[staff_name_ptr].y;
                attr = staff_roll_tbl[staff_name_ptr].attr;
                staff_roll_put(270, x, y, attr, staff_roll_tbl[staff_name_ptr].str);
            }
            staff_name_ptr++;
        } else {
e2: goto e1;
        }
        if (staff_roll_tbl[staff_name_ptr].wait == 0) {
            {
                s16 x, y, attr;
                x = staff_roll_tbl[staff_name_ptr].x;
                y = staff_roll_tbl[staff_name_ptr].y;
                attr = staff_roll_tbl[staff_name_ptr].attr;
                staff_roll_put(270, x, y, attr, staff_roll_tbl[staff_name_ptr].str);
            }
            staff_name_ptr++;
            {
                s16 x, y, attr;
                x = staff_roll_tbl[staff_name_ptr].x;
                y = staff_roll_tbl[staff_name_ptr].y;
                attr = staff_roll_tbl[staff_name_ptr].attr;
                staff_roll_put(270, x, y, attr, staff_roll_tbl[staff_name_ptr].str);
            }
            staff_name_ptr++;
        } else {
e3: goto e2;
        }
        if (staff_roll_tbl[staff_name_ptr].wait == 0) {
            {
                s16 x, y, attr;
                x = staff_roll_tbl[staff_name_ptr].x;
                y = staff_roll_tbl[staff_name_ptr].y;
                attr = staff_roll_tbl[staff_name_ptr].attr;
                staff_roll_put(270, x, y, attr, staff_roll_tbl[staff_name_ptr].str);
            }
            staff_name_ptr++;
            {
                s16 x, y, attr;
                x = staff_roll_tbl[staff_name_ptr].x;
                y = staff_roll_tbl[staff_name_ptr].y;
                attr = staff_roll_tbl[staff_name_ptr].attr;
                staff_roll_put(270, x, y, attr, staff_roll_tbl[staff_name_ptr].str);
            }
            staff_name_ptr++;
        } else {
            goto e3;
        }
        break;
    case STAFF_WAIT:
    case STAFF_LAST:
        if (end_w.timer >= 0) {
            end_w.timer = end_w.timer - roll_rate_t2;
        } else {
            staff_r_no++;
        }
        break;
    default:
        staffroll_end = 1;
        break;
    }
    return staffroll_end;
}
