/*
 * COUNT.C  Round timer
 *
 * count_cont_init / count_cont_reset / count_cont_main and counter_control run the 99-count round
 * timer, one count every hoji_counter_tbl[Timer_Speed] + 1 frames; counter_flash cycles the digit
 * colour from 30 down, at the second flash_timer_tbl rate from 10, and counter_color_clear puts the
 * colour back.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "PLS01.h"
#include "count.h"
#include "cps3.h"



ROUND_TIMER round_timer;  /* 02023EF4 */
s16 flash_timer;  /* 02023EFC */
s8 flash_r_num;  /* 02023EFE */
s8 flash_col;  /* 02023EFF */
COUNT_WORK count_work;  /* 02023F00 */



void count_cont_init(pl)
u8 pl;
{
    (*&count_work).hoji_counter = hoji_counter_tbl[Game_setting.Timer_Speed];
    Counter_hi = 99;
    Counter_low = hoji_counter_tbl[Game_setting.Timer_Speed];
    *(s16*)&round_timer = Counter_hi;
    bcount_digit_trans(pl, 9, 9);
    if (pl == 0) {
        sc_ram_to_vram(2, Game_setting.Screen_Mode * 7, 0);
        sc_ram_to_vram(3, Game_setting.Screen_Mode * 7, 0);
    }
    round_timer.size.full = 0x630000;
    Timer_Freeze = 0;
    flash_r_num = 0;
    flash_col = 0;
}



void count_cont_reset(void) {
    (*&count_work).hoji_counter = hoji_counter_tbl[Game_setting.Timer_Speed];
    Counter_hi = 99;
    Counter_low = hoji_counter_tbl[Game_setting.Timer_Speed];
    *(s16*)&round_timer = Counter_hi;
    flash_r_num = 0;
    flash_col = 0;
    bcount_digit_trans(0, 9, 9);
    sc_ram_to_vram(2, Game_setting.Screen_Mode * 7, 0);
    sc_ram_to_vram(3, Game_setting.Screen_Mode * 7, 0);
}



void count_cont_main(void) {
    if (!Break_Into && !sa_stop_check() && !EXE_flag && !Game_pause) {
        counter_control();
    }
}



void counter_control(void) {
    u16 hi;
    u16 lo;
    if (Counter_hi == 0) {
        return;
    }
    if (flash_r_num) {
        if (Counter_hi == 10 && Counter_low == (*&count_work).hoji_counter) {
            flash_timer = 0;
            counter_flash(1);
        } else if (Counter_hi <= 10) {
            counter_flash(1);
        } else {
            counter_flash(0);
        }
    } else if (Counter_hi == 30 && Counter_low == (*&count_work).hoji_counter) {
        flash_r_num = 1;
        flash_timer = 0;
        counter_flash(0);
    }
    if (Counter_low != 0) {
        Counter_low -= 1;
        return;
    }
    Counter_low = (*&count_work).hoji_counter;
    Counter_hi -= 1;
    if (Counter_hi == 0) {
        sq_paint_chenge(Game_setting.Screen_Mode * 7 + 22, 2, 4, 2, 34);
        sq_paint_chenge(Game_setting.Screen_Mode * 7 + 22, 1, 2, 1, 34);
        sq_paint_chenge(Game_setting.Screen_Mode * 7 + 24, 1, 2, 1, 0xA2);
        sq_paint_chenge(Game_setting.Screen_Mode * 7 + 22, 4, 2, 1, 34);
        sq_paint_chenge(Game_setting.Screen_Mode * 7 + 24, 4, 2, 1, 0xA2);
    }
    *(s16*)&round_timer = Counter_hi;
    hi = Counter_hi;
    hi = hi / 10;
    lo = Counter_hi - hi * 10;
    bcount_digit_trans(0, hi, lo);
}



void counter_flash(s8 ix) {
    flash_timer--;
    if (flash_timer >= 0) {
        return;
    }
    flash_timer = flash_timer_tbl[ix];
    sq_paint_chenge(Game_setting.Screen_Mode * 7 + 22, 2, 4, 2, flash_color_tbl[0][flash_col]);
    sq_paint_chenge(Game_setting.Screen_Mode * 7 + 22, 1, 2, 1, flash_color_tbl[0][flash_col]);
    sq_paint_chenge(Game_setting.Screen_Mode * 7 + 24, 1, 2, 1, flash_color_tbl[1][flash_col]);
    sq_paint_chenge(Game_setting.Screen_Mode * 7 + 22, 4, 2, 1, flash_color_tbl[2][flash_col]);
    sq_paint_chenge(Game_setting.Screen_Mode * 7 + 24, 4, 2, 1, flash_color_tbl[3][flash_col]);
    flash_col++;
    if (flash_col == 3) {
        flash_col = 0;
    }
}



void counter_color_clear(void) {
    sq_paint_chenge(Game_setting.Screen_Mode * 7 + 22, 2, 4, 2, 34);
    sq_paint_chenge(Game_setting.Screen_Mode * 7 + 22, 1, 2, 1, 34);
    sq_paint_chenge(Game_setting.Screen_Mode * 7 + 24, 1, 2, 1, 0xA2);
    sq_paint_chenge(Game_setting.Screen_Mode * 7 + 22, 4, 2, 1, 34);
    sq_paint_chenge(Game_setting.Screen_Mode * 7 + 24, 4, 2, 1, 0xA2);
}
