/*
 * PLNORMAL.C  Player normal-state routines
 *
 * The Normal_XXXXX routines are the entries of the player normal table (plpnm_lv_00, 51 slots in
 * 2i): crouching and turning (Normal_03000, 04000; Normal_02000 is in PLPNM in 2i), walking and
 * jump starts (Normal_05000, 06000 through normal_05/normal_06), dashes, jumps (Normal_16000 -
 * 18000), parry (Normal_31000, 35000, Normal_air_paring), guard and throw escapes (Normal_42000,
 * Normal_47000, Normal_48000) and the other special movement states.
 * Each sets up its animation and speed data and lands through the jumping process when airborne.
 * 2i has none of 3s Normal_51000 - 58000 (extra jumps, wall jump, character select moves).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "lose_pl.h"
#include "PLS02.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLS00.h"
#include "EFFG6.h"
#include "EFFI3.h"
#include "Grade.h"
#include "win_pl.h"
#include "PLNORMAL.h"

/* 2i 0600EC7C, 3s-reloc: sf3 src/PLNORMAL.c:46 Normal_03000 */
void Normal_03000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 2);
        setup_mvxy_data(&wk->wu, 0);
        wk->wu.mvxy.a[0].sp >>= 1;
        add_mvxy_speed(&wk->wu);
        wk->wu.mvxy.a[0].sp *= 2;
        break;
    case 1:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        char_move(&wk->wu);
        break;
    }
}



/* 2i 0600ECF2, 3s-near: sf3 src/PLNORMAL.c:69 Normal_04000 */
void Normal_04000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 3);
        setup_mvxy_data((WORK*)wk, 1);
        add_mvxy_speed((WORK*)wk);
        break;
    case 1:
        cal_mvxy_speed((WORK*)wk);
        add_mvxy_speed((WORK*)wk);
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600ED5A, 3s-near: sf3 src/PLNORMAL.c:90 Normal_05000 */
void Normal_05000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    wk->running_f = 1;
    wk->guard_flag = 3;
    normal_05[wk->player_number](wk);
    jumping_guard_type_check(wk);
}



/* 2i 0600EDB8, 3s-reloc: sf3 src/PLNORMAL.c:102 nm_05_0000 */
void nm_05_0000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 4);
        setup_mvxy_data((WORK*)wk, 2);
    case 1:
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed((WORK*)wk);
            wk->wu.routine_no[3]++;
        } else {
            char_move((WORK*)wk);
        }
        break;
    case 2:
        jumping_union_process((WORK*)wk, 3);
        break;
    case 3:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600EE34, 3s-near: sf3 src/PLNORMAL.c:128 nm_05_0100 */
void nm_05_0100(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 4);
        setup_mvxy_data((WORK*)wk, 2);
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed((WORK*)wk);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed((WORK*)wk);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }
        break;
    case 2:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }
        cal_mvxy_speed((WORK*)wk);
        add_mvxy_speed((WORK*)wk);
        break;
    case 3:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600EF0A, 3s-near: sf3 src/PLNORMAL.c:167 Normal_06000 */
void Normal_06000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    wk->running_f = 2;
    wk->guard_flag = 3;
    normal_06[wk->player_number](wk);
    jumping_guard_type_check(wk);
}



/* 2i 0600EF46, 3s-near: sf3 src/PLNORMAL.c:179 nm_06_0000 */
void nm_06_0000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 5);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600EF74, 3s-near: sf3 src/PLNORMAL.c:194 nm_06_0100 */
void nm_06_0100(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 5);
        setup_mvxy_data((WORK*)wk, 3);
    case 1:
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed((WORK*)wk);
            wk->wu.routine_no[3]++;
        } else {
            char_move((WORK*)wk);
        }
        break;
    case 2:
        jumping_union_process((WORK*)wk, 3);
        break;
    case 3:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600F018, 3s-near: sf3 src/PLNORMAL.c:220 nm_06_0200 */
void nm_06_0200(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 5);
        setup_mvxy_data((WORK*)wk, 3);
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed((WORK*)wk);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed((WORK*)wk);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }
        break;
    case 2:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }
        cal_mvxy_speed((WORK*)wk);
        add_mvxy_speed((WORK*)wk);
        break;
    case 3:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600F0D6, 3s-near: sf3 src/PLNORMAL.c:259 Normal_07000 */
void Normal_07000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 11);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600F12C, 3s-near: sf3 src/PLNORMAL.c:276 Normal_08000 */
void Normal_08000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 6);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600F168, 3s-near: sf3 src/PLNORMAL.c:293 Normal_09000 */
void Normal_09000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 7);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600F1A4, 3s-reloc: sf3 src/PLNORMAL.c:310 Normal_10000 */
void Normal_10000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 8);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600F1E4, 3s-near: sf3 src/PLNORMAL.c:328 Normal_11000 */
void Normal_11000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + -1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 0x9);
        setup_mvxy_data(&wk->wu, 0x4);
        add_mvxy_speed(&wk->wu);
        break;
    case 1:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        char_move(&wk->wu);
        break;
    }
}



/* 2i 0600F258, 3s-near: sf3 src/PLNORMAL.c:349 Normal_12000 */
void Normal_12000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 10);
        setup_mvxy_data(&wk->wu, 5);
        add_mvxy_speed(&wk->wu);
        break;
    case 1:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        char_move(&wk->wu);
        break;
    }
}



/* 2i 0600F2C0, 3s-near: sf3 src/PLNORMAL.c:370 Normal_13000 */
void Normal_13000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 50);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600F2FC, 3s-near: sf3 src/PLNORMAL.c:387 Normal_16000 */
void Normal_16000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 12);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600F352, 3s-near: sf3 src/PLNORMAL.c:406 Normal_17000 */
void Normal_17000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 13);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600F38E, 3s-near: sf3 src/PLNORMAL.c:425 Normal_18000 */
void Normal_18000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, jpdat_tbl[wk->wu.routine_no[2] - 18][0]);
        setup_mvxy_data(&wk->wu, jpdat_tbl[wk->wu.routine_no[2] - 18][1]);
        add_mvxy_speed(&wk->wu);
        break;
    case 1:
        jumping_union_process(&wk->wu, 2);
        break;
    case 2:
        char_move(&wk->wu);
        break;
    }
    jumping_guard_type_check(wk);
}



/* 2i 0600F438, 3s-near: sf3 src/PLNORMAL.c:450 Normal_18000_init_unit */
void Normal_18000_init_unit(wk, ps)
PLW* wk;
u8 ps;
{
    u8 i = (ps - 14) / 2;
    if (i > 8) {
        i = 4;
    }
    set_char_move_init(&wk->wu, 0, jpdat_tbl[i][0]);
    setup_mvxy_data(&wk->wu, jpdat_tbl[i][1]);
    add_mvxy_speed(&wk->wu);
}



/* 2i 0600F48A, 3s-near: sf3 src/PLNORMAL.c:465 Normal_27000 */
void Normal_27000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, wk->wu.routine_no[2] + 2);
        break;
    case 1:
        char_move(&wk->wu);
        break;
    }
}



/* 2i 0600F4D4, 3s-near: sf3 src/PLNORMAL.c:482 Normal_31000 */
void Normal_31000(PLW* wk) {
    if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
        wk->wu.next_z = 32;
    }
    wk->guard_chuu = guard_kind[wk->wu.routine_no[2] - 27];
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        set_char_move_init((WORK*)wk, 0, wk->wu.routine_no[2] - 7);
        set_hit_stop_hit_quake((WORK*)wk);
        Flash_MT[(wk->wu.id)] = 2;
        add_sp_arts_gauge_paring(wk);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600F588, 3s-near: sf3 src/PLNORMAL.c:544 Normal_35000 */
void Normal_35000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    wk->guard_chuu = guard_kind[wk->wu.routine_no[2] - 27];
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_hit_stop_hit_quake((WORK*)wk);
        if (wk->wu.rl_flag != ((wk->wu.dm_rl + 1) & 1)) {
            wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }
        remake_mvxy_PoSB((WORK*)wk);
        set_char_move_init((WORK*)wk, 0, 27);
        Flash_MT[(wk->wu.id)] = 2;
        break;
    case 1:
        if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
            wk->wu.next_z = 32;
        }
        jumping_union_process((WORK*)wk, 2);
        break;
    case 2:
        char_move((WORK*)wk);
        break;
    }
}



/* provisional name */
/* 2i 0600F648, 3s-near: sf3 src/PLNORMAL.c:509 Normal_air_paring */
void Normal_air_paring(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    wk->guard_chuu = guard_kind[wk->wu.routine_no[2] - 27];
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_hit_stop_hit_quake((WORK*)wk);
        if (wk->wu.rl_flag != ((wk->wu.dm_rl + 1) & 1)) {
            wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }
        setup_air_paring_mvxy((WORK*)wk);
        set_char_move_init((WORK*)wk, 0, 27);
        Flash_MT[(wk->wu.id)] = 2;
        break;
    case 1:
        if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
            wk->wu.next_z = 32;
        }
        jumping_union_process((WORK*)wk, 2);
        break;
    case 2:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600F732, 3s-near: sf3 src/PLNORMAL.c:579 Normal_36000 */
void Normal_36000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    char_move((WORK*)wk);
}



/* 2i 0600F74A, 3s-near: sf3 src/PLNORMAL.c:588 Normal_37000 */
void Normal_37000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    char_move((WORK*)wk);
}



/* 2i 0600F762, 3s-near: sf3 src/PLNORMAL.c:597 Normal_38000 */
void Normal_38000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
    case 1:
        jumping_union_process(&wk->wu, 2);
        break;
    case 2:
        char_move(&wk->wu);
        break;
    }
    jumping_guard_type_check(wk);
}



/* 2i 0600F7D0, 3s-reloc: sf3 src/PLNORMAL.c:615 Normal_39000 */
void Normal_39000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    if (wk->wu.routine_no[3]) {
        char_move((WORK*)wk);
    } else {
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 23);
    }
}



/* 2i 0600F800, 3s-reloc: sf3 src/PLNORMAL.c:629 Normal_40000 */
void Normal_40000(PLW* wk) {
    wk->wu.next_z = 38;
    win_player(wk);
}



/* 2i 0600F80C, 3s-reloc: sf3 src/PLNORMAL.c:636 Normal_41000 */
void Normal_41000(PLW* wk) {
    wk->wu.next_z = 34;
    lose_player(wk);
}



/* 2i 0600F818, 3s-near: sf3 src/PLNORMAL.c:643 Normal_42000 */
void Normal_42000(PLW* wk) {
    const s16* dadr = nmPB_data[wk->wu.routine_no[2] - 42];
    if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
        wk->wu.next_z = 32;
    }
    if (wk->wu.dm_work_id & 11) {
        wk->dm_hos_flag = 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        if (dadr[2]) {
            wk->wu.xyz[1].disp.pos = 0;
        }
        set_char_move_init((WORK*)wk, 0, dadr[0]);
        setup_mvxy_data((WORK*)wk, dadr[1]);
        Flash_MT[(wk->wu.id)] = 2;
        add_sp_arts_gauge_paring(wk);
        set_hit_stop_hit_quake((WORK*)wk);
        if (wk->wu.hit_stop > 0) {
            wk->wu.hit_stop = -wk->wu.hit_stop;
        }
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca((WORK*)wk);
        goto move_done;
        break;
    case 2:
        char_move((WORK*)wk);
    move_done:
        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3]++;
            add_mvxy_speed((WORK*)wk);
            if (dadr[2]) {
                effect_G6_init((WORK*)wk, wk->wu.weight_level);
            }
        }
        break;
    case 3:
        jumping_union_process((WORK*)wk, 4);
        break;
    case 4:
        char_move((WORK*)wk);
        break;
    }
}



/* 2i 0600F976, 3s-near: sf3 src/PLNORMAL.c:694 Normal_47000 */
void Normal_47000(PLW* wk) {
    const s16* datix = nmCE_data[wk->wu.routine_no[2] - 47];
    if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
        wk->wu.next_z = 32;
    }
    if (wk->wu.dm_work_id & 11) {
        wk->dm_hos_flag = 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        if (datix[2]) {
            wk->wu.xyz[1].disp.pos = 0;
        }
        set_char_move_init(&wk->wu, 0, datix[0]);
        setup_mvxy_data(&wk->wu, datix[1]);
        wk->wu.hit_stop = -18;
        wk->wu.hit_quake = 0;
        wk->wu.dm_stop = wk->wu.dm_quake = 0;
        add_sp_arts_gauge_nagenuke(wk);
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca(&wk->wu);
        goto move_done;
        break;
    case 2:
        char_move(&wk->wu);
    move_done:
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            add_mvxy_speed(&wk->wu);
            if (datix[2]) {
                effect_G6_init(&wk->wu, wk->wu.weight_level);
            }
        }
        break;
    case 3:
        jumping_union_process(&wk->wu, 4);
        break;
    case 4:
        char_move(&wk->wu);
        break;
    }
}



/* 2i 0600FAD2, 3s-near: sf3 src/PLNORMAL.c:745 Normal_48000 */
void Normal_48000(PLW* wk) {
    wk->guard_flag = 3;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->wu.xyz[1].disp.pos = 0;
        set_char_move_init(&wk->wu, 0, 44);
        setup_mvxy_data(&wk->wu, 27);
        wk->wu.hit_stop = -17;
        wk->wu.hit_quake = 8;
        wk->wu.dm_stop = wk->wu.dm_quake = 0;
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca(&wk->wu);
        goto move_done;
        break;
    case 2:
        char_move(&wk->wu);
    move_done:
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
            add_mvxy_speed(&wk->wu);
            effect_G6_init(&wk->wu, wk->wu.weight_level);
        }
        break;
    case 3:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        break;
    }
}



/* 2i 0600FBC0, 3s-near: sf3 src/PLNORMAL.c:784 Normal_50000 */
void Normal_50000(PLW* wk) {
    wk->guard_flag = 3;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 0, 46);
        setup_mvxy_data(&wk->wu, 29);
        wk->wu.hit_stop = -17;
        wk->wu.hit_quake = 8;
        wk->wu.dm_stop = wk->wu.dm_quake = 0;
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca(&wk->wu);
        goto move_done;
        break;
    case 2:
        char_move(&wk->wu);
    move_done:
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            add_mvxy_speed(&wk->wu);
        }
        break;
    case 3:
        jumping_union_process(&wk->wu, 4);
        break;
    case 4:
        char_move(&wk->wu);
        break;
    }
}

