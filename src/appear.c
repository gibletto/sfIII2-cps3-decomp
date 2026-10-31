/*
 * APPEAR.C  Fighter entrance (appearance) sequences
 *
 * Runs each fighter's entrance at the start of a match. appear_data_set loads an APPEAR_DATA entry chosen
 * from app_type_tbl (or app_type_tbl2 for a home/visitor rematch, home_visitor_check) by fighter,
 * stage and area, and appear_player dispatches on routine_no[4] through the 25-slot appear_jmp_tbl to
 * Appear_00000-Appear_24000: walk-ins, jumps and drops, poses, vehicles and props. The Yun/Yang and Sean
 * match-ups have their own checks. Appear_flag, Appear_free and Appear_end signal the stage and the game
 * flow; appear_work_clear resets them.
 *
 * The entrances stop the stage with bg_stop, the Yun/Yang stage uses the bg130 helpers, and sean_appear_check is
 * called (K&R) before its definition.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "win_pl.h"
#include "EFF86.h"
#include "EFFC8.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "PLS02.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "charmove_2.h"
#include "EFF09.h"
#include "EFF15.h"
#include "EFF46.h"
#include "eff97.h"
#include "EFFC5.h"
#include "EFFM1.h"
#include "effM5.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "EFFM7.h"
#include "EFF30.h"
#include "EFF31.h"
#include "EFF32.h"
#include "EFF82.h"
#include "EFF83.h"

s32 bg030_appear_check();
s32 bg110_appear_check();
extern const APPEAR_DATA appear_data[28];
#include "effL3.h"
#include "EFFL4.h"
#include "effl5.h"
#include "effl6.h"
#include "EFFM2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "lose_pl.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "aboutspr.h"
#include "SYS_sub.h"
#include "sc_trans.h"
#include "fifo.h"
#include "eff36.h"
#include "EFF48.h"
#include "EFFC1.h"
#include "efff6.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "Com_Pl.h"
#include "appear.h"
#include "fighter.h"

/* routine_no[3], Appear_01000 */
#define AP01_WAIT       1       /* until Appear_flag */
#define AP01_NEXT       2       /* start the next animation */
#define AP01_NEXT2      3       /* start the next animation */
#define AP01_END        4       /* run the animation to its end */

/* routine_no[3], Appear_03000 */
#define AP03_WAIT       1       /* until Appear_hv */
#define AP03_NEXT       2       /* start the next animation */
#define AP03_END        3       /* run the animation to its end */

/* routine_no[3], Appear_04000 */
#define AP04_MOVE       1       /* move and run the animation */
#define AP04_MOVE2      2       /* move and run the animation */
#define AP04_MOVE3      3       /* move and run the animation */
#define AP04_WAIT       4       /* count down appear_work */
#define AP04_NEXT       5       /* start the next animation */
#define AP04_NEXT2      6       /* start the next animation */
#define AP04_NEXT3      7       /* start the next animation */
#define AP04_CUE        8       /* run the animation to its next cue */

/* routine_no[3], Appear_05000 */
#define AP05_NEXT       1       /* start the next animation */
#define AP05_NEXT2      2       /* start the next animation */
#define AP05_NEXT3      3       /* start the next animation */
#define AP05_CUE        4       /* run the animation to its next cue */

/* routine_no[3], Appear_06000 */
#define AP06_WAIT       1       /* until demo_car_flag */
#define AP06_NEXT       2       /* start the next animation */
#define AP06_CUE        3       /* run the animation to its next cue */
#define AP06_HOLD       4       /* nothing more: the move holds here */

/* routine_no[3], Appear_07000 */
#define AP07_WAIT       1       /* until Appear_flag != 0 */
#define AP07_CUE        2       /* run the animation to cue 9 */
#define AP07_AIR        3       /* in the air until it lands (falls through) */
#define AP07_AIR2       4       /* in the air until it lands */
#define AP07_END        5       /* run the animation to its end */

/* routine_no[3], Appear_08000 */
#define AP08_END        1       /* run the animation to its end */

/* routine_no[3], Appear_09000 */
#define AP09_END        1       /* run the animation to its end */
#define AP09_NEXT       2       /* start the next animation */
#define AP09_NEXT2      3       /* start the next animation */
#define AP09_END2       4       /* run the animation to its end */

/* routine_no[3], Appear_10000 */
#define AP10_NEXT       1       /* start the next animation */
#define AP10_END        2       /* run the animation to its end */

/* routine_no[3], Appear_11000 */
#define AP11_WAIT       1       /* count down app_counter */

/* routine_no[3], Appear_12000 */
#define AP12_NEXT       1       /* start the next animation */
#define AP12_END        2       /* run the animation to its end */

/* routine_no[3], Appear_13000 */
#define AP13_WAIT       1       /* until bg_land_flag */
#define AP13_NEXT       2       /* start the next animation */
#define AP13_END        3       /* run the animation to its end */

/* routine_no[3], Appear_14000 */
#define AP14_END        1       /* run the animation to its end */

/* routine_no[3], Appear_15000 */
#define AP15_END        1       /* run the animation to its end, with sounds at cues 2 and 3 */

/* routine_no[3], Appear_16000 */
#define AP16_NEXT       1       /* start the next animation */
#define AP16_END        2       /* run the animation to its end */

/* routine_no[3], Appear_17000 */
#define AP17_WAIT       1       /* until bg_app */
#define AP17_END        2       /* run the animation to its end */

/* routine_no[3], Appear_18000 */
#define AP18_CUE        1       /* run the animation to cue 9 */
#define AP18_WAIT       2       /* count down appear_work */
#define AP18_END        3       /* run the animation to its end */

/* routine_no[3], Appear_19000 */
#define AP19_NEXT       1       /* start the next animation */
#define AP19_NEXT2      2       /* start the next animation */
#define AP19_END        3       /* run the animation to its end */

/* routine_no[3], Appear_20000 */
#define AP20_END        1       /* run the animation to its end */

/* routine_no[3], Appear_22000 */
#define AP22_NEXT       1       /* start the next animation */
#define AP22_END        2       /* run the animation to its end */

/* routine_no[3], Appear_23000 */
#define AP23_NEXT       1       /* start the next animation */
#define AP23_END        2       /* run the animation to its end */




s16 Appear_end;  /* 02023A60 */
s16 appear_work[2];  /* 02023A62 */
s8 Appear_flag[2];  /* 02023A66 */
s8 Appear_free[2];  /* 02023A68 */
s8 Appear_hv[2];  /* 02023A6A */
s16 app_counter[2];  /* 02023A6C */


void appear_work_clear(void) {
    Appear_end = 0;
    Appear_flag[0] = 0;
    Appear_flag[1] = 0;
    Appear_free[0] = 0;
    Appear_free[1] = 0;
    bg_stop = 0;
}



s32 home_visitor_check(PLW* wk) {
    s32 hv_type;
    s32 pl_num;
    s16 num;
    hv_type = 0;
    if (wk->wu.id) {
        num = plw[0].player_number;
    } else {
        num = plw[1].player_number;
    }
    if (pl_num = num, Play_Type) {
        if (Champion == wk->wu.id && wk->player_number == pl_num && pl_num != PL_ELENA) {
            hv_type = 1;
        }
    } else {
        if (wk->wu.operator && wk->player_number == pl_num && pl_num != PL_ELENA) {
            hv_type = 1;
        }
    }
    return hv_type;
}

void appear_data_set(PLW* wk, const APPEAR_DATA* dtbl) {
    if (gouki_app) {
        dtbl = appear_data;
    }
    if (wk->wu.id) {
        if (Game_setting.Screen_Mode) {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - dtbl->whx;
        } else {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - dtbl->hx;
        }
        wk->wu.xyz[1].disp.pos = dtbl->hy;
        wk->wu.rl_flag = (dtbl->rl + 1) & 1;
        wk->wu.routine_no[4] = dtbl->rno;
        Appear_flag[0] = dtbl->ixod;
        wk->wu.char_index = dtbl->char_index;
    } else {
        if (Game_setting.Screen_Mode) {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + dtbl->whx;
        } else {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + dtbl->hx;
        }
        wk->wu.xyz[1].disp.pos = dtbl->hy;
        wk->wu.rl_flag = dtbl->rl;
        wk->wu.routine_no[4] = dtbl->rno;
        Appear_flag[1] = dtbl->ixod;
        wk->wu.char_index = dtbl->char_index;
    }
}



void appear_player(PLW* wk) {
    void (*appear_jmp_tbl[25])(PLW* wk) = { Appear_00000, Appear_01000, Appear_01000, Appear_03000, Appear_04000, Appear_05000, Appear_06000, Appear_07000, Appear_08000, Appear_09000, Appear_10000, Appear_11000, Appear_12000, Appear_13000, Appear_14000, Appear_15000, Appear_16000, Appear_17000, Appear_18000, Appear_19000, Appear_20000, Appear_21000, Appear_22000, Appear_23000, Appear_24000 };
    appear_jmp_tbl[wk->wu.routine_no[4]](wk);
}



void Appear_00000(PLW* wk) {
    Appear_end++;
    wk->wu.routine_no[2] = NORMAL_STAND;
    wk->wu.routine_no[3] = RN3_START;
}



void Appear_01000(PLW* wk) {
    s16 work;
    s16 id_w;
    id_w = wk->wu.id ^ 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        work = random_16_com();
        work &= 3;
        if (wk->wu.routine_no[4] != 1) {
            set_char_move_init(&wk->wu, 9, work + 4);
        } else {
            set_char_move_init(&wk->wu, 9, work);
        }
        bg_stop = 1;
        break;
    case AP01_WAIT:
        if (Appear_flag[wk->wu.id]) {
            wk->wu.routine_no[3]++;
            char_move(&wk->wu);
        } else {
            wk->wu.routine_no[3] = AP01_NEXT2;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 8);
        }
        break;
    case AP01_NEXT:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9 && Appear_flag[wk->wu.id] == 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 8);
        }
        break;
    case AP01_NEXT2:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            if (sean_appear_check(wk, id_w)) {
                wk->wu.routine_no[3]++;
                set_char_move_init(&wk->wu, 0, 0);
            } else {
                wk->wu.routine_no[2] = NORMAL_STAND;
                wk->wu.routine_no[3] = RN3_START;
                Appear_end++;
            }
        }
        break;
    case AP01_END:
        switch (Appear_free[id_w]) {
        case 0:
            char_move(&wk->wu);
            break;
        case 1:
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = AP01_WAIT;
            Appear_end++;
            break;
        case 2:
            char_move(&wk->wu);
            if (wk->wu.cg_type == 0xFF) {
                wk->wu.routine_no[2] = NORMAL_STAND;
                wk->wu.routine_no[3] = RN3_START;
                Appear_end++;
            }
            break;
        }
        break;
    }
}



void Appear_03000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, wk->wu.char_index);
        bg_stop = 1;
        break;
    case AP03_WAIT:
        if (Appear_hv[wk->wu.id]) {
            appear_data_set(wk, &appear_data[app_type_tbl2[wk->player_number][bg_w.stage][bg_w.area]]);
        } else {
            appear_data_set(wk, &appear_data[app_type_tbl[wk->player_number][bg_w.stage][bg_w.area]]);
        }
        if (Appear_flag[wk->wu.id]) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index - 8);
        } else {
            wk->wu.routine_no[3] = AP03_END;
        }
        break;
    case AP03_NEXT:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9) {
            wk->wu.routine_no[3]++;
            if (Appear_hv[wk->wu.id]) {
                appear_data_set(wk, &appear_data[app_type_tbl2[wk->player_number][bg_w.stage][bg_w.area]]);
            } else {
                appear_data_set(wk, &appear_data[app_type_tbl[wk->player_number][bg_w.stage][bg_w.area]]);
            }
            set_char_move_init(&wk->wu, 9, wk->wu.char_index);
        }
        break;
    case AP03_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



/* provisional name */
s32 yun_yang_appear_check(PLW* wk) {
    s16 kind;
    kind = bg030_appear_check();
    switch (kind) {
    case 1:
        if (wk->wu.id) {
            Appear_flag[0] = 0;
        } else {
            Appear_flag[1] = 0;
        }
        appear_data_set(wk, &appear_data[2]);
        wk->wu.routine_no[4] = 1;
        Appear_01000(wk);
        return 1;
    case 2:
        if (wk->wu.id) {
            Appear_flag[0] = 0;
        } else {
            Appear_flag[1] = 0;
        }
        appear_data_set(wk, &appear_data[24]);
        wk->wu.routine_no[4] = 20;
        Appear_20000(wk);
        return 1;
    }
    return 0;
}



/* provisional name: Appear_04000's mvxy rows */
static const s32 app04_mvxy_tbl[7][4] = {
    { 0, 0, 0, 0 },
    { 0, 0x1000, -0x380, 0x2000 },
    { -0x8000, 0x4000, -0x380, 0x4000 },
    { -0xD000, 0x88000, -0x100, -0x8000 },
    { 0, 0, 0, 0 },
    { -0x8000, 0, -0x100, -0x800 },
    { -0x8000, 0, -0x100, -0x800 },
};

void Appear_04000(PLW* wk) {
    const s32* dat;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        if (yun_yang_appear_check(wk)) {
            break;
        }
        wk->wu.routine_no[3]++;
        bg_stop = 1;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x10);
        wk->wu.position_z = wk->wu.next_z = 100;
        wk->wu.my_mr_flag = 1;
        wk->wu.my_mr.size.x = 38;
        wk->wu.my_mr.size.y = 38;
        dat = app04_mvxy_tbl[wk->wu.routine_no[3]];
        wk->wu.mvxy.a[0].sp = *dat++;
        wk->wu.mvxy.a[1].sp = *dat++;
        wk->wu.mvxy.d[0].sp = *dat++;
        wk->wu.mvxy.d[1].sp = *dat;
        wk->wu.xyz[0].disp.pos = 0x250;
        break;
    case AP04_MOVE:
        wk->wu.position_z = wk->wu.next_z = 100;
        add_x_sub((WORK_Other*)wk);
        add_y_sub((WORK_Other*)wk);
        char_move(&wk->wu);
        wk->wu.my_mr.size.x++;
        wk->wu.my_mr.size.y++;
        wk->wu.my_mr_flag = 1;
        if (wk->wu.my_mr.size.x >= 51) {
            wk->wu.routine_no[3]++;
            dat = app04_mvxy_tbl[wk->wu.routine_no[3]];
            wk->wu.mvxy.a[0].sp = *dat++;
            wk->wu.mvxy.a[1].sp = *dat++;
            wk->wu.mvxy.d[0].sp = *dat++;
            wk->wu.mvxy.d[1].sp = *dat;
        }
        break;
    case AP04_MOVE2:
        wk->wu.position_z = wk->wu.next_z = 100;
        add_x_sub((WORK_Other*)wk);
        add_y_sub((WORK_Other*)wk);
        char_move(&wk->wu);
        if (wk->wu.xyz[1].disp.pos > 200) {
            wk->wu.routine_no[3]++;
            dat = app04_mvxy_tbl[wk->wu.routine_no[3]];
            wk->wu.mvxy.a[0].sp = *dat++;
            wk->wu.mvxy.a[1].sp = *dat++;
            wk->wu.mvxy.d[0].sp = *dat++;
            wk->wu.mvxy.d[1].sp = *dat;
        }
        break;
    case AP04_MOVE3:
        wk->wu.my_mr.size.x++;
        wk->wu.my_mr.size.y++;
        add_x_sub((WORK_Other*)wk);
        add_y_sub((WORK_Other*)wk);
        char_move(&wk->wu);
        if (wk->wu.mvxy.a[1].sp < 0) {
            wk->wu.routine_no[3]++;
            bg_land_flag = 1;
            appear_work[wk->wu.id] = 3;
        }
        break;
    case AP04_WAIT:
        char_move(&wk->wu);
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] < 0) {
            wk->wu.routine_no[3]++;
            appear_work[wk->wu.id] = 16;
            dat = app04_mvxy_tbl[wk->wu.routine_no[3]];
            wk->wu.mvxy.a[0].sp = *dat++;
            wk->wu.mvxy.a[1].sp = *dat++;
            wk->wu.mvxy.d[0].sp = *dat++;
            wk->wu.mvxy.d[1].sp = *dat;
        }
        break;
    case AP04_NEXT:
        char_move(&wk->wu);
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] < 0) {
            wk->wu.routine_no[3]++;
            wk->wu.my_mr_flag = 0;
            wk->wu.my_mr.size.x = 63;
            wk->wu.my_mr.size.y = 63;
            wk->wu.rl_flag++;
            wk->wu.rl_flag &= 1;
            set_char_move_init(&wk->wu, 9, 0x11);
            appear_work[wk->wu.id] = 24;
            if (wk->wu.id) {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], 0x258, 0, 1, 1);
            } else {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], 0x1A8, 0, 1, 1);
            }
            effect_C4_init(wk);
        } else {
            wk->wu.my_mr.size.x++;
            wk->wu.my_mr.size.y++;
        }
        break;
    case AP04_NEXT2:
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            wk->wu.xyz[1].cal = 0;
            set_char_move_init(&wk->wu, 9, 0x12);
            if (wk->wu.id) {
                Appear_flag[0] = 0;
            } else {
                Appear_flag[1] = 0;
            }
        } else {
            add_x_sub((WORK_Other*)wk);
            add_y_sub((WORK_Other*)wk);
            char_move(&wk->wu);
        }
        break;
    case AP04_NEXT3:
        char_move(&wk->wu);
        if (wk->wu.cg_type) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x13);
        }
        break;
    case AP04_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type) {
            bg_land_flag = 0;
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



/* provisional name */
s32 yang_yun_appear_check(PLW* wk) {
    s16 kind;
    if (bg_w.stage == 10) {
        kind = bg110_appear_check();
    } else if ((plw[0].player_number == PL_YUN && plw[1].player_number == PL_YANG) ||
               (plw[0].player_number == PL_YANG && plw[1].player_number == PL_YUN)) {
        kind = 2;
    } else {
        kind = 1;
    }
    switch (kind) {
    case 1:
        if (wk->wu.id) {
            Appear_flag[0] = 0;
        } else {
            Appear_flag[1] = 0;
        }
        appear_data_set(wk, &appear_data[2]);
        wk->wu.routine_no[4] = 1;
        Appear_01000(wk);
        return 1;
    case 2:
        if (wk->wu.id) {
            Appear_flag[0] = 0;
        } else {
            Appear_flag[1] = 0;
        }
        appear_data_set(wk, &appear_data[24]);
        wk->wu.routine_no[4] = 20;
        Appear_20000(wk);
        return 1;
    }
    return 0;
}



void Appear_05000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        if (yang_yun_appear_check(wk)) {
            break;
        }
        wk->wu.routine_no[3]++;
        bg_stop = 1;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x14);
        wk->wu.position_z = wk->wu.next_z = 110;
        wk->wu.my_mr_flag = 0;
        wk->wu.my_mr_flag = 0;
        wk->wu.xyz[0].disp.pos = 0x1D0;
        appear_work[wk->wu.id] = 92;
        if (wk->wu.id == 0) {
            wk->wu.rl_flag = 0;
        }
        break;
    case AP05_NEXT:
        wk->wu.position_z = wk->wu.next_z = 110;
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] < 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x11);
            appear_work[wk->wu.id] = 20;
            if (wk->wu.id) {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0, 1, 1);
            } else {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0, 1, 1);
            }
            if (wk->wu.id == 0) {
                wk->wu.rl_flag = 1;
            }
            if (wk->wu.id) {
                Appear_flag[0] = 0;
            } else {
                Appear_flag[1] = 0;
            }
        }
        break;
    case AP05_NEXT2:
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            wk->wu.xyz[1].cal = 0;
            set_char_move_init(&wk->wu, 9, 0x12);
        } else {
            add_x_sub((WORK_Other*)wk);
            add_y_sub((WORK_Other*)wk);
        }
        break;
    case AP05_NEXT3:
        char_move(&wk->wu);
        if (wk->wu.cg_type) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x13);
            Appear_end++;
        }
        break;
    case AP05_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
        }
        break;
    }
}



void Appear_06000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        effect_C5_init(wk);
        bg_stop = 1;
        wk->wu.disp_flag = 0;
    case AP06_WAIT:
        if (demo_car_flag[wk->wu.id]) {
            wk->wu.routine_no[3]++;
            wk->wu.disp_flag = 1;
            wk->wu.my_mr_flag = 0;
            set_char_move_init(&wk->wu, 9, 0x13);
            wk->wu.position_z = wk->wu.next_z = 110;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.d[1].sp = -0x8000;
            appear_work[wk->wu.id] = 42;
            if (wk->wu.id) {
                cal_initial_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0);
            } else {
                cal_initial_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0);
            }
        }
        break;
    case AP06_NEXT:
        char_move(&wk->wu);
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] < 0) {
            wk->wu.routine_no[3]++;
            wk->wu.xyz[1].cal = 0;
            set_char_move_init(&wk->wu, 9, 0x10);
            Appear_end++;
        } else {
            add_x_sub((WORK_Other*)wk);
            add_y_sub((WORK_Other*)wk);
        }
        break;
    case AP06_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type) {
            wk->wu.routine_no[3]++;
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
        }
        break;
    case AP06_HOLD:
        break;
    }
    wk->wu.position_x = wk->wu.xyz[0].disp.pos;
    wk->wu.position_y = wk->wu.xyz[1].disp.pos;
}



void Appear_07000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.disp_flag = 1;
        bg_stop = 1;
        if (plw[wk->wu.id ^ 1].player_number == PL_SEAN && bg_w.stage == 12 && bg_w.area == 0) {
            wk->wu.routine_no[4] = 1;
            set_char_move_init(&wk->wu, 9, 17);
            wk->wu.routine_no[3] = AP07_AIR;
        } else {
            set_char_move_init(&wk->wu, 9, 8);
            effect_C8_init(wk);
            if (Appear_flag[wk->wu.id]) {
                wk->wu.routine_no[3]++;
                break;
            }
            wk->wu.routine_no[3] = AP07_CUE;
        }
        break;
    case AP07_WAIT:
        if (Appear_flag[wk->wu.id] != 0) {
            break;
        }
        wk->wu.routine_no[3]++;
    case AP07_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }
        break;
    case AP07_AIR:
    case AP07_AIR2:
        switch (wk->wu.cg_type) {
        case 1:
            wk->wu.mvxy.a[1].sp = 0x30000;
            wk->wu.mvxy.d[1].sp = 0xFFFFA000;
            wk->wu.cg_type = 0;
            char_move_z(&wk->wu);
            break;
        case 2:
        case 3:
            char_move(&wk->wu);
            add_y_sub((WORK_Other*)wk);
            if (wk->wu.xyz[1].disp.pos < 0) {
                wk->wu.xyz[1].disp.pos = wk->wu.position_y = 0;
                wk->wu.xyz[1].disp.low = 0;
                char_move_z(&wk->wu);
            }
            break;
        case 4:
            wk->wu.cg_type = 0;
            char_move_z(&wk->wu);
            wk->wu.routine_no[3]++;
            break;
        default:
            char_move(&wk->wu);
            break;
        }
        break;
    case AP07_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
    }
    wk->wu.position_x = wk->wu.xyz[0].disp.pos;
    wk->wu.position_y = wk->wu.xyz[1].disp.pos;
}



void Appear_08000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        if (sean_appear_check(wk, wk->wu.id)) {
            set_char_move_init(&wk->wu, 9, 0x11);
            Appear_free[wk->wu.id] = 0;
            bg_stop = 1;
            break;
        }
        appear_data_set(wk, appear_data);
        wk->wu.routine_no[4] = 2;
        break;
    case AP08_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
    }
}



s32 sean_appear_check(PLW* wk, s16 id) {
    if (plw[id].player_number == PL_SEAN && bg_w.stage == 12) {
        return 1;
    }
    return 0;
}



void Appear_09000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x10);
        bg_stop = 1;
        break;
    case AP09_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
            Appear_free[wk->wu.id] = 1;
            app_counter[wk->wu.id] = 0x20;
            return;
        }
        break;
    case AP09_NEXT:
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] < 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x11);
            wk->wu.mvxy.a[1].sp = -0xB0000;
            wk->wu.mvxy.d[1].sp = -0x6000;
            return;
        }
        break;
    case AP09_NEXT2:
        char_move(&wk->wu);
        add_y_sub((WORK_Other*)&wk->wu);
        if (wk->wu.xyz[1].disp.pos <= 0) {
            wk->wu.routine_no[3]++;
            wk->wu.xyz[1].cal = 0;
            set_char_move_init(&wk->wu, 9, 0x12);
            Appear_end++;
            return;
        }
        break;
    case AP09_END2:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
        }
        break;
    }
}



void Appear_10000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x13);
        bg_stop = 1;
        wk->wu.mvxy.d[0].sp = 0;
        if (wk->wu.id) {
            wk->wu.mvxy.a[0].sp = -0x18000;
        } else {
            wk->wu.mvxy.a[0].sp = 0x18000;
        }
        break;
    case AP10_NEXT:
        char_move(&wk->wu);
        add_x_sub((WORK_Other*)&wk->wu);
        if (wk->wu.id) {
            if (wk->wu.xyz[0].disp.pos > bg_w.bgw[1].pos_x_work + 0x58) {
                break;
            }
        } else {
            if (wk->wu.xyz[0].disp.pos < bg_w.bgw[1].pos_x_work - 0x58) {
                break;
            }
        }
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 9, 0x14);
        Appear_end++;
        break;
    case AP10_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
        }
        break;
    }
}



void Appear_11000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        app_counter[wk->wu.id] = 0x50;
        set_char_move_init(&wk->wu, 0, 0);
        break;
    case AP11_WAIT:
        char_move(&wk->wu);
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] < 0) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = AP11_WAIT;
            Appear_end++;
            if (Demo_Sound != 0 || Demo_Flag != 0) {
                sound_request_pan(0x209, 0x40, 0x40, 0, 2);
            }
        }
    }
}



void Appear_12000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        bg_stop = 1;
        set_char_move_init(&wk->wu, 9, 12);
        work = 88;
        wk->wu.mvxy.d[0].sp = 0;
        wk->wu.mvxy.d[1].sp = -0x8000;
        app_counter[wk->wu.id] = 0x30;
        if (wk->wu.id) {
            cal_initial_speed(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work + work, 0);
        } else {
            cal_initial_speed(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work - work, 0);
        }
        break;
    case AP12_NEXT:
        char_move(&wk->wu);
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            wk->wu.xyz[1].cal = 0;
            set_char_move_init2(&wk->wu, 9, 12, 18, 0);
            Appear_end++;
            break;
        }
        add_x_sub((WORK_Other*)&wk->wu);
        add_y_sub((WORK_Other*)&wk->wu);
        break;
    case AP12_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
        }
    }
}



void Appear_13000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        bg_stop = 1;
        set_char_move_init2(&wk->wu, 9, 0x3D, 4, 0);
        wk->wu.mvxy.a[1].sp = 0x78000;
        wk->wu.mvxy.d[1].sp = -0x3000;
        wk->wu.kage_flag = 0;
        break;
    case AP13_WAIT:
        if (bg_land_flag) {
            wk->wu.kage_flag = 1;
            wk->wu.routine_no[3]++;
        }
    case AP13_NEXT:
        char_move(&wk->wu);
        add_y_sub((WORK_Other*)&wk->wu);
        if (wk->wu.xyz[1].disp.pos < 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x3E);
            wk->wu.xyz[1].cal = 0;
            Appear_end++;
            return;
        }
        break;
    case AP13_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
        }
        break;
    }
}



void Appear_14000(PLW* wk) {
    s16 work;
    s16 id_w = wk->wu.id ^ 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3] ++;
        wk->wu.disp_flag = 1;
        if (sean_appear_check(wk, id_w)) {
            set_char_move_init(&wk->wu, 9, 0x3C);
            return;
        }
        wk->wu.routine_no[2] = NORMAL_STAND;
        wk->wu.routine_no[3] = RN3_START;
        Appear_end ++;
        break;
    case AP14_END:
        switch (Appear_free[id_w]) {
        case 0:
            char_move(&wk->wu);
            break;
        case 1:
            work = wk->wu.cg_ix / wk->wu.cgd_type;
            set_char_move_init2(&wk->wu, 0, 0, work + 1, 0);
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = AP14_END;
            Appear_end ++;
            break;
        case 2:
            char_move(&wk->wu);
            if (wk->wu.cg_type == 0xFF) {
                wk->wu.routine_no[2] = NORMAL_STAND;
                wk->wu.routine_no[3] = RN3_START;
                Appear_end ++;
            }
        }
    }
}



void Appear_15000(PLW* wk) {
    bg_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        if (plw[wk->wu.id ^ 1].player_number != PL_IBUKI) {
            appear_data_set(wk, &appear_data[2]);
            wk->wu.routine_no[4] = 2;
            Appear_01000(wk);
            break;
        }
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 8);
        effect_97_init(wk);
        break;
    case AP15_END:
        char_move(&wk->wu);
        switch (wk->wu.cg_type) {
        case 0x2:
            wk->wu.cg_type = 0;
            Sound_SE(0x10A);
            break;
        case 0x3:
            wk->wu.cg_type = 0;
            Sound_SE(0x10B);
            break;
        case 0xFF:
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
            bg_stop = 0;
            break;
        }
    }
}



void Appear_16000(PLW* wk) {
    s16 id_w;
    bg_stop = 1;
    id_w = wk->wu.id ^ 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        if (smoke_check[bg_w.bg_index]) {
            set_char_move_init(&wk->wu, 9, 0xE);
        } else {
            set_char_move_init(&wk->wu, 9, 0xC);
        }
        break;
    case AP16_NEXT:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            if (sean_appear_check(wk, id_w)) {
                wk->wu.routine_no[3]++;
                set_char_move_init(&wk->wu, 0, 0);
            } else {
                wk->wu.routine_no[2] = NORMAL_STAND;
                wk->wu.routine_no[3] = RN3_START;
                Appear_end++;
            }
        }
        break;
    case AP16_END:
        switch (Appear_free[id_w]) {
        case 0:
            char_move(&wk->wu);
            break;
        case 1:
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = AP16_NEXT;
            Appear_end++;
            break;
        case 2:
            char_move(&wk->wu);
            if (wk->wu.cg_type == 0xFF) {
                wk->wu.routine_no[2] = NORMAL_STAND;
                wk->wu.routine_no[3] = RN3_START;
                Appear_end++;
            }
            break;
        }
        break;
    }
}



void Appear_17000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0);
        bg_stop = 1;
        break;
    case AP17_WAIT:
        if (bg_app) {
            break;
        }
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 9, 8);
        break;
    case AP17_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void Appear_18000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        if (plw[0].player_number == PL_ELENA && plw[1].player_number == PL_ELENA) {
            Appear_free[wk->wu.id] = 0;
            if (wk->wu.id) {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - 0x3B;
            } else {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 0x3B;
            }
            set_char_move_init(&wk->wu, 9, 0x10);
        } else {
            Appear_free[wk->wu.id] = 1;
            work = random_16_com();
            work &= 3;
            set_char_move_init(&wk->wu, 9, work + 8);
            wk->wu.mvxy.a[0].sp = 0;
            wk->wu.mvxy.a[1].sp = 0x80000;
            appear_work[wk->wu.id] = 0x1F;
            if (wk->wu.id) {
                cal_delta_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0, 0, 1);
            } else {
                cal_delta_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0, 0, 1);
            }
        }
        bg_stop = 1;
        break;
    case AP18_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9) {
            if (!Appear_free[wk->wu.id]) {
                wk->wu.mvxy.a[0].sp = 0;
                wk->wu.mvxy.a[1].sp = 0x80000;
                appear_work[wk->wu.id] = 0x1F;
                if (wk->wu.id) {
                    cal_delta_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0, 0, 1);
                } else {
                    cal_delta_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0, 0, 1);
                }
            }
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
        }
        break;
    case AP18_WAIT:
        char_move(&wk->wu);
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            wk->wu.xyz[1].cal = 0;
            break;
        }
        add_x_sub((WORK_Other*)&wk->wu);
        add_y_sub((WORK_Other*)&wk->wu);
        break;
    case AP18_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void Appear_19000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        bg_stop = 1;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0);
        wk->wu.rl_flag = 0;
        wk->wu.xyz[0].disp.pos = 0x275;
        wk->wu.xyz[1].disp.pos = 0x154;
        wk->wu.next_z = 0x56;
        wk->wu.my_mr_flag = 1;
        wk->wu.my_mr.size.x = 0x35;
        wk->wu.my_mr.size.y = 0x35;
        appear_work[wk->wu.id] = 0x82;
        break;
    case AP19_NEXT:
        appear_work[wk->wu.id]--;
        wk->wu.next_z = 0x56;
        if (appear_work[wk->wu.id] < 0) {
            wk->wu.routine_no[3]++;
            wk->wu.my_mr_flag = 0;
            wk->wu.my_mr.size.x = 0x3F;
            wk->wu.my_mr.size.y = 0x3F;
            set_char_move_init2(&wk->wu, 9, 0x3D, 4, 0);
            appear_work[wk->wu.id] = 0x20;
            if (wk->wu.id) {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0, 1, 1);
            } else {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0, 1, 1);
            }
            if (wk->wu.id == 0) {
                wk->wu.rl_flag = 1;
            }
            wk->wu.next_z = wk->wu.my_priority;
            effect_15_init(&wk->wu, 0);
            effect_15_init(&wk->wu, 1);
            effect_15_init(&wk->wu, 2);
        }
        break;
    case AP19_NEXT2:
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x3E);
            wk->wu.xyz[1].cal = 0;
            if (wk->wu.id) {
                Appear_flag[0] = 0;
            } else {
                Appear_flag[1] = 0;
            }
        } else {
            add_x_sub((WORK_Other*)&wk->wu);
            add_y_sub((WORK_Other*)&wk->wu);
        }
        break;
    case AP19_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void Appear_20000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x17);
        bg_stop = 1;
        break;
    case AP20_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
    }
}



void Appear_21000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        if (wk->wu.id) {
            Appear_flag[0] = 0;
        } else {
            Appear_flag[1] = 0;
        }
        if ((plw[0].player_number == PL_YUN && plw[1].player_number == PL_YANG) ||
            (plw[0].player_number == PL_YANG && plw[1].player_number == PL_YUN)) {
            appear_data_set(wk, &appear_data[24]);
            wk->wu.routine_no[4] = 20;
            Appear_20000(wk);
        } else {
            appear_data_set(wk, &appear_data[1]);
            wk->wu.routine_no[4] = 1;
            Appear_01000(wk);
        }
        break;
    }
}



void Appear_22000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        wk->wu.cmwk[1] = 0;
        set_char_move_init(&wk->wu, 9, 0);
        bg_stop = 1;
        break;
    case AP22_NEXT:
        char_move(&wk->wu);
        if (bg_app) {
            break;
        }
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 9, 8);
        break;
    case AP22_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void Appear_23000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3] += 1;
        wk->wu.disp_flag = 1;
        work = random_16_com();
        work &= 3;
        wk->wu.cmwk[1] = 0;
        set_char_move_init(&wk->wu, 9, work + 4);
        bg_stop = 1;
        break;
    case AP23_NEXT:
        char_move(&wk->wu);
        if ((wk->wu.cmwk[1]) && wk->wu.cg_type == 9) {
            wk->wu.routine_no[3] += 1;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 8);
            return;
        } else {
            return;
        }
    case AP23_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end += 1;
        }
        break;
    }
}



void Appear_24000(PLW* wk) {
    if (wk->wu.operator == 0) {
        if (wk->wu.id) {
            if (Game_setting.Screen_Mode) {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 168;
            } else {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 120;
            }
        } else if (Game_setting.Screen_Mode) {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - 168;
        } else {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - 128;
        }
    }
    wk->wu.routine_no[2] = NORMAL_STAND;
    wk->wu.routine_no[3] = RN3_START;
}



void jijii_nebukuro(wk)
PLW* wk;
{
    if (!wk->wu.cmwk[0]) {
        char_move(&wk->wu);
        return;
    }
    switch (wk->wu.routine_no[6]) {
    case 0:
        wk->wu.routine_no[6]++;
        set_char_move_init(&wk->wu, 1, 60);
        char_move_z(&wk->wu);
        wk->wu.xyz[1].disp.pos = -6;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[6]++;
        }
    case 2:
        if (wk->player_number == PL_GILL) {
            Gill_Pos_X = wk->wu.xyz[0].disp.pos;
        }
        break;
    }
}
