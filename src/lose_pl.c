/*
 * LOSE_PL.C  Lose poses after a round
 *
 * Player routines for the end of a round: lose_player dispatches the loser through
 * Lose_00000..Lose_30000 by the character's lose type (normal loser, judged-loss loser and special
 * cases). The time-over outcomes (pcon_rno 2/5 and 2/6) run lose_time_over, a loss on
 * stage 8 area 0 runs lose_stage8_action, and Lose_20000 counts the rounds from Game_setting.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "aboutspr.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "SYS_sub.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "sc_trans.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "fifo.h"
#include "eff36.h"
#include "EFF48.h"
#include "EFFC1.h"
#include "efff6.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "PLS02.h"
#include "Com_Pl.h"
#include "lose_pl.h"

/* lose_rno[2] (and lose_rno[1]) in lose_stage8_action */
#define LS8_INIT        0       /* already down (pat_status 38) or standing: set up */
#define LS8_RUN         1       /* go down with the stage */
#define LS8_WAIT_BG     0       /* lose_rno[1]: until the stage starts to move */
#define LS8_FALL        1       /* lose_rno[1]: fall for lose_free frames */
#define LS8_HOLD        2       /* lose_rno[1]: stay there */

/* lose_rno[0] in lose_time_over */
#define LT_FIRST        0       /* the first animation, until cue 9 */
#define LT_REFILL       1       /* refill the vitality, then on */

/* routine_no[3], lose_time_over */
#define LOSE_TIME_OVER_NEXT 1   /* start the next animation */

/* wk->wu.routine_no[3] in a win or lose pose */
#define POSE_RUN        1       /* the pose runs until its script sets RN3_DONE */

s16 lose_rno[3];  /* 02023A7C */
s16 lose_free[2];  /* 02023A82 */


void lose_player(PLW* wk) {
    void (*lose_jp_tbl[4])(PLW*) = { Lose_00000, Lose_10000, Lose_20000, Lose_30000 };
    if (pcon_rno[0] == PCON_DIE && (pcon_rno[1] == SETTLE_SPECIAL || pcon_rno[1] == SETTLE_SPECIAL2)) {
        lose_time_over(wk);
    } else {
        lose_jp_tbl[loser_type_tbl[wk->player_number]](wk);
    }
}



void Lose_00000(PLW* wk) {
    if (pcon_rno[0] == PCON_DIE && pcon_rno[1] == SETTLE_JUDGE) {
        Judge_normal_loser(wk);
    } else {
        Normal_normal_Loser(wk);
    }
}



void Lose_10000(PLW* wk) {
    if (bg_w.stage == 8 && bg_w.area == 0) {
        lose_stage8_action(wk);
        return;
    }
    if ((pcon_rno[0] == PCON_DIE) && (pcon_rno[1] == SETTLE_JUDGE)) {
        switch (wk->wu.routine_no[3]) {
        case RN3_START:
            wk->wu.routine_no[3]++;
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            wk->wu.char_index = random_16_com();
            wk->wu.char_index &= 3;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 0x38);
            break;
        default:
        case POSE_RUN:
        case RN3_DONE:
            char_move(&wk->wu);
            break;
        }
    } else if ((pcon_rno[1] == SETTLE_KO) || (pcon_rno[1] == SETTLE_GOUKI)) {
        return;
    } else {
        switch (wk->wu.routine_no[3]) {
        case RN3_START:
            wk->wu.routine_no[3]++;
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            wk->wu.char_index = random_16_com();
            wk->wu.char_index &= 7;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 0x18);
            break;
        case POSE_RUN:
        case RN3_DONE:
            char_move(&wk->wu);
            break;
        }
    }
}



void Lose_20000(PLW* wk) {
    s32 work;
    s16 id_w;
    if (bg_w.stage == 8 && bg_w.area == 0) {
        lose_stage8_action(wk);
        return;
    }
    if ((pcon_rno[0] == PCON_DIE) && (pcon_rno[1] == SETTLE_JUDGE)) {
        Judge_normal_loser(wk);
        return;
    }
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        id_w = wk->wu.id ^ 1;
        if ((Round_num >= (work = Game_setting.Battle_Number) * 2) || (PL_Wins[id_w] >= work + 1)) {
            effect_C1_init(&wk->wu);
        }
        break;
    }
    Lose_00000(wk);
}



void Lose_30000(PLW* wk) {
    if (bg_w.stage == 8 && bg_w.area == 0) {
        lose_stage8_action(wk);
        return;
    }
    if ((pcon_rno[0] == PCON_DIE) && (pcon_rno[1] == SETTLE_JUDGE)) {
        switch (wk->wu.routine_no[3]) {
        case RN3_START:
            wk->wu.routine_no[3]++;
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            if (Country != 1) {
                set_char_move_init(&wk->wu, 9, 0x3A);
            } else {
                set_char_move_init(&wk->wu, 9, 0x38);
            }
            break;
        default:
        case POSE_RUN:
        case RN3_DONE:
            char_move(&wk->wu);
            break;
        }
    } else if ((pcon_rno[1] == SETTLE_KO) || (pcon_rno[1] == SETTLE_GOUKI)) {
        return;
    } else {
        switch (wk->wu.routine_no[3]) {
        case RN3_START:
            wk->wu.routine_no[3]++;
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            if (Country != 1) {
                set_char_move_init(&wk->wu, 9, 0x1C);
            } else {
                set_char_move_init(&wk->wu, 9, 0x18);
            }
            break;
        case POSE_RUN:
        case RN3_DONE:
            char_move(&wk->wu);
            break;
        }
    }
}



void Normal_normal_Loser(PLW* wk) {
    s16 work;
    if (bg_w.stage == 8 && bg_w.area == 0) {
        lose_stage8_action(wk);
        return;
    }
    if ((pcon_rno[1] == SETTLE_KO) || (pcon_rno[1] == SETTLE_GOUKI)) {
        return;
    }
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
        work = random_16_com();
        work &= 7;
        set_char_move_init(&wk->wu, 9, work + 0x18);
        break;
    case POSE_RUN:
    case RN3_DONE:
        char_move(&wk->wu);
        break;
    }
}



void Judge_normal_loser(PLW* wk) {
    s16 work;
    if (bg_w.stage == 8 && bg_w.area == 0) {
        lose_stage8_action(wk);
        return;
    }
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3] += 1;
        work = random_16_com();
        work &= 3;
        set_char_move_init(&wk->wu, 9, work + 0x38);
        break;
    case POSE_RUN:
    case RN3_DONE:
    default:
        char_move(&wk->wu);
        break;
    }
}



/* provisional name: the loser on stage 8 area 0 */
void lose_stage8_action(PLW* wk) {
    if (wk->wu.routine_no[3] == RN3_START) {
        wk->wu.routine_no[3]++;
        lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
    }
    switch (lose_rno[2]) {
    case LS8_INIT:
        lose_rno[2]++;
        lose_rno[1] = LS8_WAIT_BG;
        if (wk->wu.pat_status != 38) {
            lose_rno[0] = 0;
            set_char_move_init(&wk->wu, 9, 60);
        } else {
            lose_rno[0] = 1;
        }
        break;
    case LS8_RUN:
        if (lose_rno[0]) {
            switch (lose_rno[1]) {
            case LS8_WAIT_BG:
                if (bg_w.bgw[1].r_no_1 >= 1) {
                    lose_rno[1]++;
                    lose_free[wk->wu.id] = 110;
                }
                wk->wu.position_y = wk->wu.xyz[1].disp.pos = stage8_base_y + wk->wu.xyz[1].disp.pos - 40;
                break;
            case LS8_FALL:
                lose_free[wk->wu.id]--;
                if (lose_free[wk->wu.id] < 0) {
                    wk->wu.routine_no[3]++;
                }
                wk->wu.position_y = wk->wu.xyz[1].disp.pos = stage8_base_y - 40;
                /* fall through */
            case LS8_HOLD:
                wk->wu.kage_flag = 0;
                break;
            }
        } else {
            switch (lose_rno[1]) {
            case LS8_WAIT_BG:
                if (bg_w.bgw[1].r_no_1 >= 1) {
                    lose_rno[1]++;
                    set_char_move_init(&wk->wu, 9, 61);
                    wk->wu.mvxy.a[1].sp = 0x60000;
                    wk->wu.mvxy.d[1].sp = -0x4000;
                    lose_free[wk->wu.id] = 110;
                } else {
                    char_move(&wk->wu);
                }
                break;
            case LS8_FALL:
                lose_free[wk->wu.id]--;
                if (lose_free[wk->wu.id] < 0) {
                    wk->wu.routine_no[3]++;
                } else {
                    add_y_sub((WORK_Other*)wk);
                }
                /* fall through */
            case LS8_HOLD:
                char_move(&wk->wu);
                wk->wu.kage_flag = 0;
                break;
            }
        }
        break;
    }
}



/* provisional name: the loser at time over (pcon_rno 2/5 and 2/6) */
void lose_time_over(PLW* wk) {
    s16 id_w;

    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
        id_w = wk->wu.id ^ 1;
        if (wk->wu.cg_number == 0x54F8) {
            wk->wu.char_index = 16;
            if (wk->wu.rl_flag) {
                if (wk->wu.xyz[0].disp.pos > plw[id_w].wu.xyz[0].disp.pos) {
                    lose_rno[1] = 1;
                } else {
                    lose_rno[1] = 0;
                }
            } else if (wk->wu.xyz[0].disp.pos < plw[id_w].wu.xyz[0].disp.pos) {
                lose_rno[1] = 1;
            } else {
                lose_rno[1] = 0;
            }
        } else {
            wk->wu.char_index = 21;
            if (wk->wu.rl_flag) {
                if (wk->wu.xyz[0].disp.pos > plw[id_w].wu.xyz[0].disp.pos) {
                    lose_rno[1] = 2;
                } else {
                    lose_rno[1] = 3;
                }
            } else if (wk->wu.xyz[0].disp.pos < plw[id_w].wu.xyz[0].disp.pos) {
                lose_rno[1] = 2;
            } else {
                lose_rno[1] = 3;
            }
        }
        set_char_move_init(&wk->wu, 9, wk->wu.char_index);
        wk->wu.kind_of_waza = 0;
        break;
    case LOSE_TIME_OVER_NEXT:
        switch (lose_rno[0]) {
        case LT_FIRST:
            char_move(&wk->wu);
            if (wk->wu.cg_type == 9) {
                lose_rno[0]++;
                wk->wu.cg_type = 0;
                switch (lose_rno[1]) {
                case 0:
                    wk->wu.char_index = 17;
                    break;
                case 1:
                    wk->wu.char_index = 19;
                    break;
                case 2:
                    wk->wu.char_index = 22;
                    break;
                case 3:
                    wk->wu.char_index = 23;
                    break;
                }
                set_char_move_init(&wk->wu, 9, wk->wu.char_index);
            }
            break;
        case LT_REFILL:
            char_move(&wk->wu);
            if (wk->wu.vital_new < wk->wu.vitality) {
                wk->wu.vital_new += 2;
            } else {
                wk->wu.vital_new = wk->wu.vitality;
            }
            if (wk->wu.cg_type == 9 && wk->wu.vital_new == wk->wu.vitality) {
                wk->wu.routine_no[3]++;
                switch (lose_rno[1]) {
                case 0:
                case 3:
                    wk->wu.char_index = 18;
                    break;
                case 1:
                case 2:
                    wk->wu.char_index = 20;
                    break;
                }
                set_char_move_init(&wk->wu, 9, wk->wu.char_index);
                load_player_color(15, wk->wu.id, Player_Color[wk->wu.id]);
            }
            break;
        }
        break;
    default:
        char_move(&wk->wu);
        break;
    }
}
