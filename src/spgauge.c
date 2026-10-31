/*
 * spgauge.c  Super art gauge display
 *
 * Draws and animates the super art gauge for both players on the text layer.
 * spgauge_cont_init (and spgauge_cont_demo_init for attract mode) set each player's gauge work
 * from the chosen super art: stock count, gauge length and colour. spgauge_cont_main runs every
 * frame and calls spgauge_control per player, which follows the player's gauge value, plays the
 * gauge sounds, and reacts to the gauge flash requests: super art activation, EX move use and
 * reaching full stock start the "SA"/"EX"/"MAX" lettering (samoji_control, sast_control) and the
 * gauge colour changes (sagauge_color_chenge, sast_color_chenge).
 * wipe_check restores the gauge after a screen wipe, and the *_trans routines write the gauge
 * cells, frame, stock digits and lettering.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "sc_clear.h"
#include "PLMAIN.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "spgauge.h"
#include "fighter.h"

/* spg_dat[pl].max_rno: the gauge flash when a stock is gained (sast_control, samoji_control) */
#define SPG_MAX_START   0       /* a stock was gained: show it and start the flash */
#define SPG_MAX_FLASH   1       /* flash the gauge for timer */
#define SPG_MAX_IDLE    2       /* nothing to do */

/* spg_dat[pl].time_rno: the gauge of a timer-type art (samoji_control) */
#define SPG_TIME_START  0       /* the art is on (sa->ok -1): run, else just flash */
#define SPG_TIME_RUN    1       /* flash until the stock changes, then the drain */
#define SPG_TIME_DRAIN  2       /* while the art drains the gauge */
#define SPG_TIME_FLASH  3       /* flash for timer */
#define SPG_TIME_END    4       /* redraw the gauge */
#define SPG_TIME_IDLE   5       /* nothing to do */



extern const u16 spgauge_postbl_0[];
extern const u16 spgauge_postbl_1[];
extern const u16 spgauge_postbl_0_2[];
extern const u16 spgauge_postbl_1_2[];
extern const u16 spgauge_puttbl_0[];
extern const u16 spgauge_puttbl_1[];

s8 Old_Stop_SG;  /* 02023F08 */
s8 Exec_Wipe_F;  /* 02023F09 */
s8 time_clear[2];  /* 02023F0A */
s16 spg_number;  /* 02023F0C */
s16 spg_work;  /* 02023F0E */
s16 spg_offset;  /* 02023F10 */
s8 time_num;  /* 02023F12 */
s8 time_timer;  /* 02023F13 */
s8 time_flag[2];  /* 02023F14 */
s16 col;  /* 02023F16 */
SPG_DAT spg_dat[2];  /* 02023F18 */


/* 02007854 */
const u16* spgauge_puttbl[2] = {
    spgauge_puttbl_0,
    spgauge_puttbl_1,
};
/* 0200785C */
const u16* spgauge_postbl[4] = {
    spgauge_postbl_0,
    spgauge_postbl_1,
    spgauge_postbl_0_2,
    spgauge_postbl_1_2,
};


void spgauge_cont_init(void) {
    s8 lpy;
    spg_dat[0].current_spg = 0;
    spg_dat[0].old_spg = 0;
    spg_dat[0].spgcol_number = 18;
    spg_dat[0].spgtbl_ptr = spgauge_puttbl[0];
    spg_dat[0].spg_level = 0;
    spg_dat[0].spg_maxlevel = super_arts[0].store_max;
    spg_dat[0].spg_len = super_arts[0].gauge_len / 8;
    spg_dat[0].spg_dotlen = super_arts[0].gauge_len;
    spg_dat[0].flag = 0;
    spg_dat[0].flag2 = 0;
    spg_dat[0].timer = 60;
    spg_dat[0].timer2 = 2;
    spg_dat[0].kind = 0;
    spg_dat[0].max = 0;
    spg_dat[0].max_old = 0;
    spg_dat[0].max_rno = SPG_MAX_START;
    spg_dat[0].time_rno = SPG_TIME_START;
    spg_dat[0].gauge_flash_time = 2;
    spg_dat[0].gauge_flash_col = 0;
    spg_dat[0].sa_flag = 0;
    spg_dat[0].ex_flag = 0;
    spg_dat[0].no_chgcol = 0;
    spg_dat[0].time_no_clear = 0;
    spg_dat[0].sa_mukou = 0;
    sa_gauge_flash[0] = 0;
    if (super_arts[0].gauge_type == SA_GAUGE_TIMER) {
        spg_dat[0].time = 1;
        time_flag[0] = 1;
    } else {
        spg_dat[0].time = 0;
        time_flag[0] = 0;
    }
    spg_dat[1].current_spg = 0;
    spg_dat[1].old_spg = 0;
    spg_dat[1].spgcol_number = 146;
    spg_dat[1].spgtbl_ptr = spgauge_puttbl[0];
    spg_dat[1].spg_level = 0;
    spg_dat[1].spg_maxlevel = super_arts[1].store_max;
    spg_dat[1].spg_len = super_arts[1].gauge_len / 8;
    spg_dat[1].spg_dotlen = super_arts[1].gauge_len;
    spg_dat[1].flag = 0;
    spg_dat[1].flag2 = 0;
    spg_dat[1].timer = 60;
    spg_dat[1].timer2 = 2;
    spg_dat[1].kind = 0;
    spg_dat[1].max = 0;
    spg_dat[1].max_old = 0;
    spg_dat[1].max_rno = SPG_MAX_START;
    spg_dat[1].time_rno = SPG_TIME_START;
    spg_dat[1].gauge_flash_time = 2;
    spg_dat[1].gauge_flash_col = 0;
    spg_dat[1].sa_flag = 0;
    spg_dat[1].ex_flag = 0;
    spg_dat[1].no_chgcol = 0;
    spg_dat[1].time_no_clear = 0;
    spg_dat[1].sa_mukou = 0;
    sa_gauge_flash[1] = 0;
    if (super_arts[1].gauge_type == SA_GAUGE_TIMER) {
        spg_dat[1].time = 1;
        time_flag[1] = 1;
    } else {
        spg_dat[1].time = 0;
        time_flag[1] = 0;
    }
    if (Game_setting.Screen_Mode == 0) {
        spg_dat[0].spgptbl_ptr = spgauge_postbl[0];
        spg_dat[1].spgptbl_ptr = spgauge_postbl[1];
    } else {
        spg_dat[0].spgptbl_ptr = spgauge_postbl[2];
        spg_dat[1].spgptbl_ptr = spgauge_postbl[3];
    }
    for (lpy = 0; lpy < 2; lpy++) {
        spg_dat[lpy].mass_len = spg_dat[lpy].spg_len - 5;
        if (spg_dat[lpy].spg_len & 1) {
            spg_dat[lpy].mchar = 5;
            spg_dat[lpy].mass_odd = 1;
        } else {
            spg_dat[lpy].mass_len = spg_dat[lpy].mass_len - 1;
            spg_dat[lpy].mchar = 6;
            spg_dat[lpy].mass_odd = 0;
        }
        spg_dat[lpy].mass_len /= 2;
    }
    sa_stock_trans(0, 0, 0);
    sa_stock_trans(0, 0, 1);
    sa_max_level_trans(0, spg_dat[0].spg_maxlevel);
    sa_max_level_trans(1, spg_dat[1].spg_maxlevel);
    sa_fullstock_trans(0, 0);
    sa_fullstock_trans(1, 0);
    sa_number_trans();
    sa_gauge_trans(0, 0);
    sa_gauge_trans(1, 0);
    sa_waku_trans(0, 0);
    sa_waku_trans(1, 1);
    Old_Stop_SG = 0;
    Exec_Wipe_F = 0;
    time_clear[0] = 0;
    time_clear[1] = 0;
    spg_offset = 0;
    time_num = 0;
    time_timer = 3;
    col = 0;
}



void spgauge_cont_demo_init(void) {
    s8 lpy;
    demo_set_sa_full(&super_arts[0]);
    spg_dat[0].current_spg = super_arts[0].gauge_len;
    spg_dat[0].old_spg = super_arts[0].gauge_len;
    spg_dat[0].spgcol_number = 20;
    spg_dat[0].spgtbl_ptr = spgauge_puttbl[0];
    spg_dat[0].spg_level = super_arts[0].store;
    spg_dat[0].spg_maxlevel = super_arts[0].store_max;
    spg_dat[0].spg_len = super_arts[0].gauge_len / 8;
    spg_dat[0].spg_dotlen = super_arts[0].gauge_len;
    spg_dat[0].flag = 0;
    spg_dat[0].flag2 = 0;
    spg_dat[0].timer = 60;
    spg_dat[0].timer2 = 2;
    spg_dat[0].kind = 1;
    spg_dat[0].max = 1;
    spg_dat[0].max_old = 0;
    spg_dat[0].max_rno = SPG_MAX_IDLE;
    spg_dat[0].time_rno = SPG_TIME_START;
    spg_dat[0].gauge_flash_time = 2;
    spg_dat[0].gauge_flash_col = 0;
    spg_dat[0].sa_flag = 0;
    spg_dat[0].ex_flag = 0;
    spg_dat[0].no_chgcol = 0;
    spg_dat[0].time_no_clear = 0;
    spg_dat[0].sa_mukou = 0;
    sa_gauge_flash[0] = 0;
    if (super_arts[0].gauge_type == SA_GAUGE_TIMER) {
        spg_dat[0].time = 1;
        time_flag[0] = 1;
    } else {
        spg_dat[0].time = 0;
        time_flag[0] = 0;
    }
    demo_set_sa_full(&super_arts[1]);
    spg_dat[1].current_spg = super_arts[1].gauge_len;
    spg_dat[1].old_spg = super_arts[1].gauge_len;
    spg_dat[1].spgcol_number = 148;
    spg_dat[1].spgtbl_ptr = spgauge_puttbl[0];
    spg_dat[1].spg_level = super_arts[1].store;
    spg_dat[1].spg_maxlevel = super_arts[1].store_max;
    spg_dat[1].spg_len = super_arts[1].gauge_len / 8;
    spg_dat[1].spg_dotlen = super_arts[1].gauge_len;
    spg_dat[1].flag = 0;
    spg_dat[1].flag2 = 0;
    spg_dat[1].timer = 60;
    spg_dat[1].timer2 = 2;
    spg_dat[1].kind = 1;
    spg_dat[1].max = 1;
    spg_dat[1].max_old = 0;
    spg_dat[1].max_rno = SPG_MAX_IDLE;
    spg_dat[1].time_rno = SPG_TIME_START;
    spg_dat[1].gauge_flash_time = 2;
    spg_dat[1].gauge_flash_col = 0;
    spg_dat[1].sa_flag = 0;
    spg_dat[1].ex_flag = 0;
    spg_dat[1].no_chgcol = 0;
    spg_dat[1].time_no_clear = 0;
    spg_dat[1].sa_mukou = 0;
    sa_gauge_flash[1] = 0;
    if (super_arts[1].gauge_type == SA_GAUGE_TIMER) {
        spg_dat[1].time = 1;
        time_flag[1] = 1;
    } else {
        spg_dat[1].time = 0;
        time_flag[1] = 0;
    }
    if (Game_setting.Screen_Mode == 0) {
        spg_dat[0].spgptbl_ptr = spgauge_postbl[0];
        spg_dat[1].spgptbl_ptr = spgauge_postbl[1];
    } else {
        spg_dat[0].spgptbl_ptr = spgauge_postbl[2];
        spg_dat[1].spgptbl_ptr = spgauge_postbl[3];
    }
    for (lpy = 0; lpy < 2; lpy++) {
        spg_dat[lpy].mass_len = spg_dat[lpy].spg_len - 5;
        if (spg_dat[lpy].spg_len & 1) {
            spg_dat[lpy].mchar = 5;
            spg_dat[lpy].mass_odd = 1;
        } else {
            spg_dat[lpy].mass_len = spg_dat[lpy].mass_len - 1;
            spg_dat[lpy].mchar = 6;
            spg_dat[lpy].mass_odd = 0;
        }
        spg_dat[lpy].mass_len /= 2;
    }
    sa_stock_trans(spg_dat[0].spg_maxlevel, 1, 0);
    sa_stock_trans(spg_dat[1].spg_maxlevel, 1, 1);
    sa_max_level_trans(0, spg_dat[0].spg_maxlevel);
    sa_max_level_trans(1, spg_dat[1].spg_maxlevel);
    sa_fullstock_trans(0, 1);
    sa_fullstock_trans(1, 1);
    sa_number_trans();
    sa_gauge_trans(0, 1);
    sa_gauge_trans(1, 1);
    sa_waku_trans(0, 0);
    sa_waku_trans(1, 1);
    sa_moji_trans(0, 0, 1);
    sa_moji_trans(1, 0, 1);
    Old_Stop_SG = 0;
    Exec_Wipe_F = 0;
    time_clear[0] = 0;
    time_clear[1] = 0;
    spg_offset = 0;
    time_num = 0;
    time_timer = 3;
    col = 1;
}



void spgauge_cont_main(void) {
    if (Stop_SG) {
        wipe_check();
        Old_Stop_SG = Stop_SG;
        return;
    } else {
        if (Old_Stop_SG) {
            Old_Stop_SG = 0;
            Exec_Wipe_F = 0;
            time_clear[0] = 0;
            time_clear[1] = 0;
        }
        sa_time_moji_send();
        spgauge_control(0);
        spgauge_control(1);
    }
}



void spgauge_control(s8 Spg_Num) {
    if (sa_gauge_flash[Spg_Num]) {
        spgauge_sound_request(Spg_Num);
        if (plw[Spg_Num].sa->store == plw[Spg_Num].sa->store_max && spg_dat[Spg_Num].max_old == 0 && spg_dat[Spg_Num].max == 0) {
            spg_dat[Spg_Num].max = 1;
        } else {
            spg_dat[Spg_Num].max = 0;
        }
        spg_dat[Spg_Num].flag = 1;
        spg_dat[Spg_Num].max_rno = SPG_MAX_START;
        spg_dat[Spg_Num].time_rno = SPG_TIME_START;
        spg_dat[Spg_Num].timer2 = 2;
        spg_dat[Spg_Num].kind = 0;
        spg_dat[Spg_Num].no_chgcol = 0;
        if (plw[Spg_Num].sa->ok == -1 || plw[Spg_Num].sa->mp == -1) {
            spg_dat[Spg_Num].sa_flag = 1;
            spg_dat[Spg_Num].timer = 60;
            if (Conclusion_Flag != 0) {
                spg_dat[Spg_Num].time_no_clear = 1;
                if ((My_char[Spg_Num] & 0x7F) == PL_GILL && plw[Spg_Num].sa->ok == -1) {
                    spg_dat[Spg_Num].sa_mukou = 0;
                } else {
                    spg_dat[Spg_Num].sa_mukou = 1;
                }
            }
        } else if (plw[Spg_Num].sa->ex == -1) {
            spg_dat[Spg_Num].ex_flag = 1;
            spg_dat[Spg_Num].timer = 20;
        } else {
            spg_dat[Spg_Num].timer = 35;
        }
        sa_gauge_flash[Spg_Num] = 0;
    }
    if (spg_dat[Spg_Num].max) {
        sast_control(Spg_Num);
    } else if (spg_dat[Spg_Num].flag != 0) {
        samoji_control(Spg_Num);
    }
    if (plw[Spg_Num].sa->ex != 0 || spg_dat[Spg_Num].ex_flag == 1 || spg_dat[Spg_Num].sa_flag == 1) {
        sagauge_color_chenge(Spg_Num);
    }
    if (spg_dat[Spg_Num].current_spg != plw[Spg_Num].sa->gauge.s.h || spg_dat[Spg_Num].max != 0) {
        if (spg_dat[Spg_Num].max) {
            spg_dat[Spg_Num].current_spg = spg_dat[Spg_Num].spg_dotlen;
        } else {
            spg_dat[Spg_Num].current_spg = plw[Spg_Num].sa->gauge.s.h;
        }
        if (spg_dat[Spg_Num].max == 0 && spg_dat[Spg_Num].flag == 0) {
            if (spg_dat[Spg_Num].max_old == 0) {
                sa_waku_trans(Spg_Num, Spg_Num);
            }
        }
    }
}



void wipe_check(void) {
    if (Old_Stop_SG) {
        if (Exec_Wipe != 0 || Exec_Wipe_F != 0) {
            return;
        }
        Exec_Wipe_F = 1;
        if (spg_dat[0].time == 1 && time_clear[0] == 1) {
            if (spg_dat[0].time_no_clear == 0) {
                spgauge_work_clear(0);
                tilemap_clear_rect(1, 25, 4, 26);
                spgauge_wipe_write(0);
            } else {
                satime_ko_after_clear(0);
            }
        }
        if (spg_dat[1].time == 1 && time_clear[1] == 1) {
            if (spg_dat[1].time_no_clear == 0) {
                spgauge_work_clear(1);
                tilemap_clear_rect(Game_setting.Screen_Mode * 14 + 43, 25, Game_setting.Screen_Mode * 14 + 46, 26);
                spgauge_wipe_write(1);
            } else {
                satime_ko_after_clear(1);
            }
        }
    } else {
        if (plw[0].sa->ok == -1) {
            plw[0].sa->ok = 0;
            time_clear[0] = 1;
        }
        if (plw[1].sa->ok == -1) {
            plw[1].sa->ok = 0;
            time_clear[1] = 1;
        }
    }
}



void satime_ko_after_clear(s8 pl) {
    spg_dat[pl].max = 0;
    spg_dat[pl].max_old = 1;
    spg_dat[pl].kind = 1;
    spg_dat[pl].timer2 = 2;
    spg_dat[pl].max_rno = SPG_MAX_IDLE;
    spg_dat[pl].time_rno = SPG_TIME_IDLE;
}



void sa_time_moji_send(void) {
    if (time_flag[0] != 0 || time_flag[1] != 0) {
        time_timer--;
        if (time_timer == 0) {
            if (time_flag[0]) {
                sc_chr_block_trans(sa_time_data_tbl[time_num][0], 0x100, 4, 2);
            }
            if (time_flag[1]) {
                sc_chr_block_trans(sa_time_data_tbl[time_num][1], 0x120, 4, 2);
            }
            time_timer = 3;
            if (time_num == 5) {
                time_num = 0;
            } else {
                time_num++;
            }
        }
    }
}



void sast_control(Stpl_Num)
s8 Stpl_Num;
{
    switch (spg_dat[Stpl_Num].max_rno) {
    case SPG_MAX_START:
        sa_moji_trans(Stpl_Num, 0, 1);
        spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
        sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num);
        sa_gauge_trans(Stpl_Num, 1);
        sagauge_color_chenge(Stpl_Num);
        spg_dat[Stpl_Num].max_rno = SPG_MAX_FLASH;
        break;
    case SPG_MAX_FLASH:
        spg_dat[Stpl_Num].timer--;
        if (spg_dat[Stpl_Num].timer) {
            spg_dat[Stpl_Num].timer2--;
            if (spg_dat[Stpl_Num].timer2 != 0) {
                break;
            } else {
                spg_dat[Stpl_Num].kind++;
                if (spg_dat[Stpl_Num].kind == 3) {
                    spg_dat[Stpl_Num].kind = 0;
                }
                sa_gauge_trans(Stpl_Num, spg_dat[Stpl_Num].kind);
                sa_stock_trans(spg_dat[Stpl_Num].spg_level, spg_dat[Stpl_Num].kind, Stpl_Num);
                spg_dat[Stpl_Num].timer2 = 1;
            }
        } else {
            sa_gauge_trans(Stpl_Num, 1);
            sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num);
            spg_dat[Stpl_Num].max = 0;
            spg_dat[Stpl_Num].max_old = 1;
            spg_dat[Stpl_Num].kind = 1;
            spg_dat[Stpl_Num].timer2 = 2;
            spg_dat[Stpl_Num].max_rno = SPG_MAX_IDLE;
            spg_dat[Stpl_Num].time_rno = SPG_TIME_IDLE;
        }
        break;
    case SPG_MAX_IDLE:
        break;
    }
}



void samoji_control(Stpl_Num)
s8 Stpl_Num;
{
    if (spg_dat[Stpl_Num].time) {
        switch (spg_dat[Stpl_Num].time_rno) {
        case SPG_TIME_START:
            if (plw[Stpl_Num].sa->ok == -1) {
                spg_dat[Stpl_Num].time_rno = SPG_TIME_RUN;
            } else {
                spg_dat[Stpl_Num].time_rno = SPG_TIME_FLASH;
                goto case_3;
            }
        case SPG_TIME_RUN:
            if (spg_dat[Stpl_Num].spg_level == plw[Stpl_Num].sa->store) {
                spg_dat[Stpl_Num].timer2--;
                if (spg_dat[Stpl_Num].kind == 0) {
                    if (spg_dat[Stpl_Num].timer2 == 0) {
                        sa_stock_trans(spg_dat[Stpl_Num].spg_level, 0, Stpl_Num);
                        sa_gauge_trans(Stpl_Num, 0);
                        spg_dat[Stpl_Num].kind = 1;
                        spg_dat[Stpl_Num].timer2 = 2;
                    }
                } else if (spg_dat[Stpl_Num].timer2 == 0) {
                    sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num);
                    sa_gauge_trans(Stpl_Num, 1);
                    spg_dat[Stpl_Num].kind = 0;
                    spg_dat[Stpl_Num].timer2 = 2;
                }
            } else if (spg_dat[Stpl_Num].sa_flag != 0 && Conclusion_Flag == 0) {
                sa_gauge_trans(Stpl_Num, 1);
                sa_moji_trans(Stpl_Num, 1, 1);
                sast_color_chenge(Stpl_Num);
                spg_dat[Stpl_Num].time_rno = SPG_TIME_DRAIN;
                spg_dat[Stpl_Num].no_chgcol = 1;
                goto case_2;
            } else {
                sast_color_chenge(Stpl_Num);
                spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
                sa_stock_trans(spg_dat[Stpl_Num].spg_level, col, Stpl_Num);
                sa_gauge_trans(Stpl_Num, col);
                sa_waku_trans(Stpl_Num, Stpl_Num);
                spg_dat[Stpl_Num].flag = 0;
                spg_dat[Stpl_Num].time_rno = SPG_TIME_IDLE;
                spg_dat[Stpl_Num].sa_flag = 0;
                spg_dat[Stpl_Num].ex_flag = 0;
                break;
            }
            return;
        case SPG_TIME_DRAIN:
        case_2:
            if (spg_dat[Stpl_Num].current_spg > 0 && plw[Stpl_Num].sa->ok == -1) {
                if (spg_dat[Stpl_Num].current_spg != spg_dat[Stpl_Num].old_spg) {
                    sa_waku_trans(Stpl_Num, Stpl_Num);
                }
                spg_dat[Stpl_Num].old_spg = spg_dat[Stpl_Num].current_spg;
                return;
            } else {
                spg_dat[Stpl_Num].time_rno = SPG_TIME_END;
                return;
            }
        case SPG_TIME_FLASH:
        case_3:
            spg_dat[Stpl_Num].timer--;
            if (spg_dat[Stpl_Num].timer != 0) {
                spg_dat[Stpl_Num].timer2--;
                if (spg_dat[Stpl_Num].kind == 0) {
                    if (spg_dat[Stpl_Num].timer2 == 0) {
                        sa_stock_trans(spg_dat[Stpl_Num].spg_level, 0, Stpl_Num);
                        sa_gauge_trans(Stpl_Num, 0);
                        spg_dat[Stpl_Num].kind = 1;
                        spg_dat[Stpl_Num].timer2 = 2;
                    }
                } else if (spg_dat[Stpl_Num].timer2 == 0) {
                    sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num);
                    sa_gauge_trans(Stpl_Num, 1);
                    spg_dat[Stpl_Num].kind = 0;
                    spg_dat[Stpl_Num].timer2 = 2;
                }
                return;
            } else {
                spg_dat[Stpl_Num].time_rno = SPG_TIME_END;
            }
        case SPG_TIME_END:
            sa_moji_trans(Stpl_Num, 1, 0);
            sast_color_chenge(Stpl_Num);
            spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
            sa_stock_trans(spg_dat[Stpl_Num].spg_level, col, Stpl_Num);
            sa_gauge_trans(Stpl_Num, col);
            sa_waku_trans(Stpl_Num, Stpl_Num);
            spg_dat[Stpl_Num].flag = 0;
            spg_dat[Stpl_Num].time_rno = SPG_TIME_IDLE;
            spg_dat[Stpl_Num].max_old = 0;
            spg_dat[Stpl_Num].max_rno = SPG_MAX_START;
            spg_dat[Stpl_Num].sa_flag = 0;
            spg_dat[Stpl_Num].ex_flag = 0;
            spg_dat[Stpl_Num].no_chgcol = 0;
            goto sw_end;
        case SPG_TIME_IDLE:
            return;
        default:
            return;
        }
    sw_end:;
    } else {
        switch (spg_dat[Stpl_Num].max_rno) {
        case SPG_MAX_START:
            if (plw[Stpl_Num].sa->store > spg_dat[Stpl_Num].spg_level) {
                spg_dat[Stpl_Num].current_spg = spg_dat[Stpl_Num].spg_dotlen;
                sa_waku_trans(Stpl_Num, Stpl_Num);
                spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
                sa_stock_trans(spg_dat[Stpl_Num].spg_level, col, Stpl_Num);
            }
            spg_dat[Stpl_Num].max_rno = SPG_MAX_FLASH;
        case SPG_MAX_FLASH:
            spg_dat[Stpl_Num].timer--;
            if (spg_dat[Stpl_Num].timer != 0) {
                spg_dat[Stpl_Num].timer2--;
                if (spg_dat[Stpl_Num].kind == 0) {
                    if (spg_dat[Stpl_Num].timer2 == 0) {
                        sa_stock_trans(spg_dat[Stpl_Num].spg_level, 0, Stpl_Num);
                        sa_gauge_trans(Stpl_Num, 0);
                        spg_dat[Stpl_Num].kind = 1;
                        spg_dat[Stpl_Num].timer2 = 2;
                    }
                } else if (spg_dat[Stpl_Num].timer2 == 0) {
                    sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num);
                    sa_gauge_trans(Stpl_Num, 1);
                    spg_dat[Stpl_Num].kind = 0;
                    spg_dat[Stpl_Num].timer2 = 2;
                }
                break;
            }
            if (spg_dat[Stpl_Num].max_old != 0 && spg_dat[Stpl_Num].sa_mukou == 0) {
                sa_moji_trans(Stpl_Num, 0, 0);
                spg_dat[Stpl_Num].max_old = 0;
            }
            sast_color_chenge(Stpl_Num);
            spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
            sa_stock_trans(spg_dat[Stpl_Num].spg_level, col, Stpl_Num);
            sa_gauge_trans(Stpl_Num, col);
            if (spg_dat[Stpl_Num].max_old == 0 && spg_dat[Stpl_Num].sa_mukou == 0) {
                sa_waku_trans(Stpl_Num, Stpl_Num);
            }
            spg_dat[Stpl_Num].flag = 0;
            spg_dat[Stpl_Num].max_rno = SPG_MAX_IDLE;
            spg_dat[Stpl_Num].sa_flag = 0;
            spg_dat[Stpl_Num].ex_flag = 0;
            spg_dat[Stpl_Num].sa_mukou = 0;
            break;
        case SPG_MAX_IDLE:
            break;
        }
    }
}




void sast_color_chenge(pl)
s8 pl;
{
    if (plw[pl].sa->gauge_type == SA_GAUGE_TIMER && plw[pl].sa->ok == -1) {
        col = 1;
        if (pl == 0) {
            spg_dat[0].spgcol_number = 52;
        } else {
            spg_dat[1].spgcol_number = 180;
        }
        return;
    }
    if (plw[pl].sa->store) {
        col = 1;
        if (pl == 0) {
            spg_dat[0].spgcol_number = 20;
        } else {
            spg_dat[1].spgcol_number = 148;
        }
    } else {
        col = 0;
        if (pl == 0) {
            spg_dat[0].spgcol_number = 18;
        } else {
            spg_dat[1].spgcol_number = 146;
        }
    }
}



void sa_color_chenge(pl, step)
s8 pl;
s8 step;
{
    if (spg_dat[pl].kind) {
        if (pl == 0) {
            spg_dat[0].spgcol_number = step * 2 + 18;
        } else {
            spg_dat[1].spgcol_number = step * 2 + 146;
        }
    } else {
        if (pl == 0) {
            spg_dat[0].spgcol_number = 20 - step * 2;
        } else {
            spg_dat[1].spgcol_number = 148 - step * 2;
        }
    }
}



void sagauge_color_chenge(Stpl_Num)
s8 Stpl_Num;
{
    if (spg_dat[Stpl_Num].no_chgcol) {
        return;
    }
    spg_dat[Stpl_Num].gauge_flash_time--;
    if (spg_dat[Stpl_Num].gauge_flash_time == 0) {
        spg_dat[Stpl_Num].gauge_flash_time = 2;
        if (Stpl_Num == 0) {
            sq_paint_chenge(5, 26, spg_dat[0].spg_len, 1, sagauge_colchg_tbl[spg_dat[0].gauge_flash_col][0]);
        } else if (spg_dat[1].max == 1 || spg_dat[1].max_old == 1 || spg_dat[1].spg_level == spg_dat[1].spg_maxlevel) {
            sq_paint_chenge(43 - spg_dat[1].spg_len + DE_X[18], 26, spg_dat[1].mass_len, 1, sagauge_colchg_tbl[spg_dat[1].gauge_flash_col][1]);
            sq_paint_chenge(43 - spg_dat[1].spg_len + spg_dat[1].mass_len + DE_X[18], 26, spg_dat[1].mchar, 1, sagauge_colchg_tbl[spg_dat[1].gauge_flash_col][0]);
            sq_paint_chenge(43 - spg_dat[1].spg_len + spg_dat[1].mass_len + spg_dat[1].mchar + DE_X[18],
                         26,
                         spg_dat[1].mass_len,
                         1,
                         sagauge_colchg_tbl[spg_dat[1].gauge_flash_col][1]);
        } else {
            SPG_DAT* spg = &spg_dat[1];
            sq_paint_chenge(43 - spg_dat[1].spg_len + DE_X[18], 26, spg->spg_len, 1, sagauge_colchg_tbl[spg->gauge_flash_col][1]);
        }
        if (spg_dat[Stpl_Num].gauge_flash_col == 5) {
            spg_dat[Stpl_Num].gauge_flash_col = 0;
        } else {
            spg_dat[Stpl_Num].gauge_flash_col++;
        }
    }
}



void sa_moji_trans(Stpl_Num, Kind, OnOff)
s32 Stpl_Num;
s8 Kind;
s8 OnOff;
{
    SPG_DAT* spg;
    s16 x;
    switch (Kind) {
    case 0:
        if (OnOff) {
            spg = &spg_dat[Stpl_Num];
            spg->current_spg = spg->spg_dotlen;
            sa_waku_trans(Stpl_Num, Stpl_Num);
            max_mark_write(Stpl_Num, spg->spg_len, (s16)spg->mchar, (s16)spg->mass_len, spg->mass_odd);
        } else {
            sa_waku_trans(Stpl_Num, Stpl_Num);
        }
        break;
    case 1:
    default:
        if ((s8)Stpl_Num == 0) {
            if (Game_setting.Screen_Mode == 0) {
                x = 1;
            } else {
                x = 1;
            }
            if (OnOff) {
                scfont_sqput(x, 25, 4, 2, 8, 0x100);
            } else {
                tilemap_clear_rect(x, 25, x + 3, 26);
            }
        } else {
            if (Game_setting.Screen_Mode == 0) {
                x = 43;
            } else {
                x = 57;
            }
            if (OnOff) {
                scfont_sqput(x, 25, 4, 2, 8, 0x120);
            } else {
                tilemap_clear_rect(x, 25, x + 3, 26);
            }
        }
        break;
    }
}



void sa_waku_trans(s8 pl_kind, s8 pl) {
    s8 i;
    s16 len;
    const u16* sa_char_ptr;
    SPG_DAT* spg;
    spg_work = 0;
    spg_number = 0;
    sa_char_ptr = spgauge_puttbl[0];
    if (Game_setting.Screen_Mode == 0) {
    }
    len = super_arts[pl_kind].gauge_len / 8;
    i = 0;
    spg = &spg_dat[pl_kind];
    for (; i < len; i++) {
        spg_work += 8;
        if (spg_work >= spg->current_spg) {
            if (spg->current_spg >= (spg_work - 8)) {
                spg_offset = spg->current_spg - (i * 8);
                tilemap_put_cell((&spg->spgptbl_ptr[spg_number])[16 - len],
                                 26,
                                 spg->spgcol_number,
                                 sa_char_ptr[spg_offset]);
            } else {
                tilemap_put_cell(
                    (&spg->spgptbl_ptr[spg_number])[16 - len], 26, spg->spgcol_number, sa_char_ptr[0]);
            }
        } else {
            tilemap_put_cell((&spg_dat[pl_kind].spgptbl_ptr[spg_number])[16 - len], 26, spg->spgcol_number, sa_char_ptr[8]);
        }
        spg_number++;
    }
}



void spgauge_sound_request(Stpl_Num)
s8 Stpl_Num;
{
    if (plw[Stpl_Num].sa->store > spg_dat[Stpl_Num].spg_level) {
        Sound_SE(Stpl_Num + 107);
    }
}



void spgauge_work_clear(s8 Stpl_Num) {
    SPG_DAT* spg;
    plw[Stpl_Num].sa->gauge.i = 0;
    spg = &spg_dat[Stpl_Num];
    spg->current_spg = 0;
    spg->old_spg = 0;
    spg->spgcol_number = 18;
    spg->spg_level = 0;
    spg->flag = 0;
    spg->flag2 = 0;
    spg->timer = 60;
    spg->timer2 = 2;
    spg->kind = 0;
    spg->max = 0;
    spg->max_old = 0;
    spg->max_rno = SPG_MAX_START;
    spg->time_rno = SPG_TIME_START;
    spg->gauge_flash_time = 2;
    spg->gauge_flash_col = 0;
    spg->sa_flag = 0;
    spg->ex_flag = 0;
    spg->no_chgcol = 0;
    spg->time_no_clear = 0;
    spg->sa_mukou = 0;
    sa_gauge_flash[Stpl_Num] = 0;
    sa_color_chenge(Stpl_Num, 1);
}



/* provisional name */
void satime_stock_clear(void) {
    if (spg_dat[0].time == 1 && plw[0].sa->ok == -1 && spg_dat[0].time_no_clear == 0) {
        sa_stock_chr_trans(0, 0);
    }
    if (spg_dat[1].time == 1 && plw[1].sa->ok == -1 && spg_dat[1].time_no_clear == 0) {
        sa_stock_chr_trans(1, 0);
    }
}



void spgauge_wipe_write(s32 Stpl_Num) {
    s16 x;
    if ((s8)Stpl_Num == 0) {
        if (Game_setting.Screen_Mode == 0) {
            x = 1;
        } else {
            x = 1;
        }
        tilemap_put_cell(x, 25, 10, 0xD4);
        tilemap_put_cell(x + 1, 25, 10, 0xD5);
        tilemap_put_cell(x, 26, 10, 0xD6);
        tilemap_put_cell(x + 1, 26, 10, 0xD7);
    } else {
        if (Game_setting.Screen_Mode == 0) {
            x = 43;
        } else {
            x = 57;
        }
        tilemap_put_cell(x, 25, 10, 0xE4);
        tilemap_put_cell(x + 1, 25, 10, 0xE5);
        tilemap_put_cell(x, 26, 10, 0xE6);
        tilemap_put_cell(x + 1, 26, 10, 0xE7);
    }
    sa_waku_trans(Stpl_Num, Stpl_Num);
    sa_gauge_trans((s8)Stpl_Num, 0);
}



void sa_gauge_trans(Stpl_Num, Spg_Col)
s8 Stpl_Num;
s16 Spg_Col;
{
    s8 lpy;
    if (Game_setting.Screen_Mode) {
        sc_ram_to_vram(Stpl_Num + (Spg_Col * 2) + 6, Stpl_Num * 14, 0);
    } else {
        sc_ram_to_vram(Stpl_Num + (Spg_Col * 2) + 6, 0, 0);
    }
    if (Stpl_Num == 0) {
        for (lpy = 0; lpy < spg_dat[0].spg_len - 7; lpy++) {
            tilemap_put_cell(lpy + 13, 25, sa_color_data2_tbl[Spg_Col][0], 187);
            tilemap_put_cell(lpy + 13, 27, sa_color_data2_tbl[Spg_Col][0], 205);
        }
        tilemap_put_cell(lpy + 13, 25, sa_color_data2_tbl[Spg_Col][0], 186);
        tilemap_put_cell(lpy + 13, 27, sa_color_data2_tbl[Spg_Col][0], 204);
        tilemap_put_cell(lpy + 14, 26, sa_color_data2_tbl[Spg_Col][0], 185);
        tilemap_put_cell(lpy + 12, 26, sa_color_data2_tbl[Spg_Col][0], 303);
        tilemap_put_cell(lpy + 13, 26, sa_color_data2_tbl[Spg_Col][0], 302);
        sa_fullstock_trans(0, Spg_Col);
    } else {
        for (lpy = 0; lpy < spg_dat[1].spg_len - 7; lpy++) {
            tilemap_put_cell(DE_X[18] - lpy + 34, 25, sa_color_data2_tbl[Spg_Col][1], 187);
            tilemap_put_cell(DE_X[18] - lpy + 34, 27, sa_color_data2_tbl[Spg_Col][1], 205);
        }
        tilemap_put_cell(DE_X[18] - lpy + 34, 25, sa_color_data2_tbl[Spg_Col][1], 186);
        tilemap_put_cell(DE_X[18] - lpy + 34, 27, sa_color_data2_tbl[Spg_Col][1], 204);
        tilemap_put_cell(DE_X[18] - lpy + 33, 26, sa_color_data2_tbl[Spg_Col][1], 185);
        tilemap_put_cell(DE_X[18] - lpy + 34, 26, sa_color_data2_tbl[Spg_Col][1], 318);
        tilemap_put_cell(DE_X[18] - lpy + 35, 26, sa_color_data2_tbl[Spg_Col][1], 319);
        sa_fullstock_trans(1, Spg_Col);
    }
}
