/*
 * SC_SUB.C  HUD win marks, palette fade control and stun gauge
 *
 * Per-player HUD pieces drawn on the text layer during a fight. The win mark routines
 * (win_mark_control, win_mark_pos_set, win_mark_write, win_mark_all_write) place one mark per round
 * won and blink a newly won mark using win_mark_blink_tbl. fade_cont_init / fade_cont_main run a
 * multi-layer palette fade: the fade number selects a list of palette groups and step parameters,
 * and each frame the groups due for an update are re-sent through the colour request queue with the
 * next brightness until every layer has reached its target, after which the fade flags are cleared.
 * stngauge_cont_init / stngauge_cont_main / stngauge_control keep each player's stun gauge in step
 * with the stun value, with stun_put, stun_mark_write and stun_gauge_waku_write drawing the gauge,
 * its "stun" mark and its frame.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "sc_trans.h"
#include "sc_sub_2.h"
#include "sc_sub.h"
#include "cps3.h"



s16 win_mark_rno[2];  /* 02028704 */
s16 win_mark_timer[2];  /* 02028708 */
s16 win_mark_phase[2];  /* 0202870C */
s16 win_mark_num[2];  /* 02028710 */
s16 win_mark_pos[2];  /* 02028714 */


/* provisional name */
/* 2i 060BE46C, 3s-exact: sf3 src/sc_sub.c:43 win_mark_control */
void win_mark_control(s16 pl) {
    if (Exec_Wipe) {
        return;
    }
    switch (win_mark_rno[pl]) {
    case 0:
        win_mark_new[pl] = 0;
        if (PL_Wins[pl] == 0) {
            win_mark_rno[pl] = 99;
            return;
        } else {
            win_mark_rno[pl]++;
            win_mark_timer[pl] = 1;
            win_mark_phase[pl] = 0;
            win_mark_pos_set(pl);
        }
        return;
    case 1:
        if (win_mark_new[pl]) {
            win_mark_new_check(pl);
        }
        if (--win_mark_timer[pl] != 0) {
            return;
        }
        win_mark_write(pl);
        win_mark_timer[pl] = win_mark_blink_tbl[0][win_mark_phase[pl] + 1];
        if (win_mark_phase[pl] != 2) {
            win_mark_phase[pl] += 2;
        } else {
            win_mark_phase[pl] = 0;
        }
        break;
    default:
        if (win_mark_new[pl] != 0) {
            if (win_mark_phase[pl ^ 1] == 0) {
                win_mark_rno[pl] = 1;
                win_mark_new[pl] = 0;
                win_mark_timer[pl] = 1;
                win_mark_phase[pl] = 0;
                win_mark_pos_set(pl);
            }
        }
        return;
    }
}



/* provisional name */
/* 2i 060BE55C, 3s-exact: sf3 src/sc_sub.c:92 win_mark_pos_set */
void win_mark_pos_set(s16 pl) {
    win_mark_num[pl] = PL_Wins[pl] * 2;
    if (pl != 0) {
        win_mark_pos[1] = win_mark_pos_tbl[Game_setting.mode][4];
    } else {
        win_mark_pos[0] = win_mark_pos_tbl[Game_setting.mode][0];
    }
}



/* provisional name */
/* 2i 060BE58E, 3s-exact: sf3 src/sc_sub.c:104 win_mark_new_check */
void win_mark_new_check(pl)
s16 pl;
{
    if (win_mark_phase[pl] == 0) {
        win_mark_new[pl] = 0;
        win_mark_pos_set(pl);
    }
}



/* provisional name */
/* 2i 060BE5A6, 3s-reloc: sf3 src/sc_sub.c:116 win_mark_write */
void win_mark_write(pl)
s16 pl;
{
    u16* cell = (u16*)((SS_RAM + 0x400) + win_mark_pos[pl] * 4);
    s16 n;
    s16 i;
    if (pl == 0) {
        for (n = win_mark_num[pl], i = 0; n > 0; n -= 2, cell -= 4) {
            cell[1] = win_mark_blink_tbl[win_type[pl][i]][win_mark_phase[pl]] | (cell[1] & 1);
            cell[3] = win_mark_blink_tbl[win_type[pl][i]][win_mark_phase[pl]] | (cell[-1] & 1);
            i++;
        }
    } else {
        for (n = win_mark_num[pl], i = 0; n > 0; n -= 2, cell += 4) {
            cell[1] = win_mark_blink_tbl[win_type[pl][i]][win_mark_phase[pl]] | (cell[1] & 1);
            cell[3] = win_mark_blink_tbl[win_type[pl][i]][win_mark_phase[pl]] | (cell[3] & 1);
            i++;
        }
    }
}

/* one win mark on the text layer: four words */
typedef struct {
    u16 w[4];
} WIN_CELL;

/* provisional name */
/* 2i 060BE6B8, 3s-near: sf3 src/sc_sub.c:143 win_mark_all_write */
u32 win_mark_all_write(s16 pl)
{
    WIN_CELL* cell;
    s16 n;
    s32 i;

    win_mark_phase[pl] = 0;
    win_mark_pos_set(pl);
    cell = (WIN_CELL*)((SS_RAM + 0x400) + win_mark_pos[pl] * 4);
    if (pl == 0) {
        i = 0;
        for (n = (Game_setting.set4 + 1) * 2; n > 0; n -= 2) {
            cell->w[1] = win_mark_blink_tbl[win_type[pl][i]][win_mark_phase[pl]] | (cell->w[1] & 1);
            cell->w[3] = win_mark_blink_tbl[win_type[pl][i]][win_mark_phase[pl]] | (((u16*)cell)[-1] & 1);
            i++;
            cell--;
        }
    } else {
        i = 0;
        for (n = (Game_setting.set4 + 1) * 2; n > 0; n -= 2) {
            cell->w[1] = win_mark_blink_tbl[win_type[pl][i]][win_mark_phase[pl]] | (cell->w[1] & 1);
            cell->w[3] = win_mark_blink_tbl[win_type[pl][i]][win_mark_phase[pl]] | (cell->w[3] & 1);
            i++;
            cell++;
        }
    }
}



