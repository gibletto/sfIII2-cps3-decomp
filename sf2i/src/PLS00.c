/*
 * PLS00.C  Player lever and button check per state
 *
 * The input side of player control. check_lever_data is called from the player main routine
 * and, for each routine class (normal, damage, catch, caught, attack), runs the check that
 * decides whether the player's input starts a new action this frame.
 * process_normal dispatches nm_00000-nm_95000 by the current normal routine: each tries in turn
 * super arts, special moves, taunt, throws, leap attacks, normal attacks, jumps, dashes, walks,
 * guards and turns, depending on what that state allows. process_damage, process_catch and
 * process_attack do the same for the other classes; check_cg_cancel_data handles cancelling an
 * attack into another through the animation's cancel data.
 * The TO_nm_ routines switch a work into a given normal routine and run its first check.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLS01.h"
#include "PLS03ATT.h"
#include "PLS03.h"
#include "PLCNTSET.h"
#include "plcntset_2.h"
#include "PLPDM.h"
#include "PLS00.h"
#include "fighter.h"



/* 2i 0600949C, 3s-exact: sf3 src/PLS00.c:32 check_lever_data */
void check_lever_data(PLW* wk) {
    if (wk->wu.routine_no[0] == 4) {
        process_ndcca[wk->wu.routine_no[1]](wk);
    }
}



/* 2i 060094BE, 3s-exact: sf3 src/PLS00.c:40 process_normal */
void process_normal(PLW* wk) {
    plpnm_xxxxx[wk->wu.routine_no[2]](wk);
}



/* 2i 060094D2, 3s-exact: sf3 src/PLS00.c:46 TO_nm_01000 */
void TO_nm_01000(WORK* wk) {
    wk->routine_no[1] = 0;
    wk->routine_no[2] = 1;
    wk->routine_no[3] = 0;
    wk->cg_type = 0;
    nm_01000((PLW*)wk);
}



/* 2i 060094E8, 3s-exact: sf3 src/PLS00.c:56 TO_nm_36000 */
void TO_nm_36000(WORK* wk) {
    wk->routine_no[1] = 0;
    wk->routine_no[2] = 36;
    wk->routine_no[3] = 0;
    wk->cg_type = 0;
    nm_01000((PLW*)wk);
}



/* 2i 060094FE, 3s-reloc: sf3 src/PLS00.c:66 TO_nm_09000 */
void TO_nm_09000(WORK* wk) {
    wk->routine_no[1] = 0;
    wk->routine_no[2] = 9;
    wk->routine_no[3] = 0;
    wk->cg_type = 0;
    nm_09000((PLW*)wk);
}



/* 2i 06009514, 3s-reloc: sf3 src/PLS00.c:76 TO_nm_37000 */
void TO_nm_37000(WORK* wk) {
    wk->routine_no[1] = 0;
    wk->routine_no[2] = 37;
    wk->routine_no[3] = 0;
    wk->cg_type = 0;
    nm_09000((PLW*)wk);
}



/* 2i 0600952A, 3s-exact: sf3 src/PLS00.c:86 TO_nm_38000 */
void TO_nm_38000(WORK* wk) {
    wk->routine_no[1] = 0;
    wk->routine_no[2] = 38;
    wk->routine_no[3] = 1;
    wk->cg_type = 0;
}



/* 2i 06009542, 3s-reloc: sf3 src/PLS00.c:95 TO_nm_18000_01 */
void TO_nm_18000_01(WORK* wk) {
    wk->routine_no[1] = 0;
    wk->routine_no[2] = 18;
    wk->routine_no[3] = 1;
    wk->cg_type = 0;
    nm_18000((PLW*)wk);
}



/* 2i 0600955A, 3s-near: sf3 src/PLS00.c:105 nm_00000 */
void nm_00000(PLW* wk) {}



/* 2i 06009568, 3s-near: sf3 src/PLS00.c:109 nm_01000 */
void nm_01000(PLW* wk) {
    if (setup_kuzureochi(wk)) {
        return;
    }
    if (check_full_gauge_attack(wk, 0)) {
        return;
    }
    if (check_super_arts_attack(wk)) {
        return;
    }
    if (check_special_attack(wk)) {
        return;
    }
    if (check_chouhatsu(wk)) {
        return;
    }
    if (check_catch_attack(wk)) {
        return;
    }
    if (check_leap_attack(wk)) {
        return;
    }
    if (check_nm_attack(wk)) {
        return;
    }
    if (check_cg_cancel_data(wk)) {
        return;
    }
    if (check_turn_to_back(wk)) {
        return;
    }
    if (check_F_R_dash(wk)) {
        return;
    }
    if (check_360_jump(wk)) {
        return;
    }
    if (check_jump_ready(wk)) {
        return;
    }
    if (check_bend_myself(wk)) {
        return;
    }
    if (check_defense_lever(wk)) {
        return;
    }
    if (check_F_R_walk(wk)) {
        return;
    }
}



/* 2i 06009612, 3s-near: sf3 src/PLS00.c:168 nm_02000 */
void nm_02000(PLW* wk) {
    if (wk->wu.cg_type == 0xFF) {
        TO_nm_01000((WORK*)wk);
        return;
    }
    if (wk->wu.cg_type == 64) {
        TO_nm_36000((WORK*)wk);
        return;
    }
    if (check_full_gauge_attack(wk, 0)) {
        return;
    }
    if (check_super_arts_attack(wk)) {
        return;
    }
    if (check_special_attack(wk)) {
        return;
    }
    if (check_chouhatsu(wk)) {
        return;
    }
    if (check_catch_attack(wk)) {
        return;
    }
    if (check_leap_attack(wk)) {
        return;
    }
    if (check_nm_attack(wk)) {
        return;
    }
    if (check_cg_cancel_data(wk)) {
        return;
    }
    if (check_F_R_dash(wk)) {
        return;
    }
    if (check_360_jump(wk)) {
        return;
    }
    if (check_jump_ready(wk)) {
        return;
    }
    if (check_bend_myself(wk)) {
        return;
    }
    if (check_defense_lever(wk)) {
        return;
    }
    if (check_F_R_walk(wk)) {
        return;
    }
}



/* 2i 06009750, 3s-near: sf3 src/PLS00.c:229 nm_03000 */
void nm_03000(PLW* wk) {
    if (check_full_gauge_attack(wk, 0)) {
        return;
    }
    if (check_super_arts_attack(wk)) {
        return;
    }
    if (check_special_attack(wk)) {
        return;
    }
    if (check_chouhatsu(wk)) {
        return;
    }
    if (check_catch_attack(wk)) {
        return;
    }
    if (check_leap_attack(wk)) {
        return;
    }
    if (check_nm_attack(wk)) {
        return;
    }
    if (check_cg_cancel_data(wk)) {
        return;
    }
    if (check_turn_to_back(wk)) {
        return;
    }
    if (check_F_R_dash(wk)) {
        return;
    }
    if (check_360_jump(wk)) {
        return;
    }
    if (check_jump_ready(wk)) {
        return;
    }
    if (check_bend_myself(wk)) {
        return;
    }
    if (check_walking_lv_dir(wk)) {
        wk->wu.routine_no[2] = 39;
        wk->wu.routine_no[3] = 0;
        wk->wu.cg_type = 0;
    }
    if (check_defense_lever(wk)) {
        return;
    }
}



/* 2i 06009800, 3s-near: sf3 src/PLS00.c:287 nm_05000 */
void nm_05000(PLW* wk) {
    jumping_cg_type_check(wk);
}



/* 2i 06009804, 3s-near: sf3 src/PLS00.c:295 nm_07000 */
void nm_07000(PLW* wk) {
    if (wk->wu.cg_type == 0xFF) {
        TO_nm_01000((WORK*)wk);
        return;
    }
    if (check_full_gauge_attack(wk, 0)) {
        return;
    }
    if (check_super_arts_attack(wk)) {
        return;
    }
    if (check_special_attack(wk)) {
        return;
    }
    if (check_chouhatsu(wk)) {
        return;
    }
    if (check_catch_attack(wk)) {
        return;
    }
    if (check_leap_attack(wk)) {
        return;
    }
    if (check_nm_attack(wk)) {
        return;
    }
    if (check_cg_cancel_data(wk)) {
        return;
    }
    if (check_turn_to_back(wk)) {
        return;
    }
    if (check_F_R_dash(wk)) {
        return;
    }
    if (check_360_jump(wk)) {
        return;
    }
    if (check_jump_ready(wk)) {
        return;
    }
    if (check_defense_lever(wk)) {
        return;
    }
    if (check_F_R_walk(wk)) {
        return;
    }
    if (check_bend_myself(wk)) {
        return;
    }
}



/* 2i 060098FC, 3s-near: sf3 src/PLS00.c:355 nm_08000 */
void nm_08000(PLW* wk) {
    if (wk->wu.cg_type == 0xFF) {
        TO_nm_09000((WORK*)wk);
        return;
    }
    if (wk->wu.cg_type == 64) {
        TO_nm_37000((WORK*)wk);
        return;
    }
    if (check_full_gauge_attack(wk, 0)) {
        return;
    }
    if (check_super_arts_attack(wk)) {
        return;
    }
    if (check_special_attack(wk)) {
        return;
    }
    if (check_chouhatsu(wk)) {
        return;
    }
    if (check_catch_attack(wk)) {
        return;
    }
    if (check_leap_attack(wk)) {
        return;
    }
    if (check_nm_attack(wk)) {
        return;
    }
    if (check_cg_cancel_data(wk)) {
        return;
    }
    if (check_turn_to_back(wk)) {
        return;
    }
    if (check_F_R_dash(wk)) {
        return;
    }
    if (check_360_jump(wk)) {
        return;
    }
    if (check_jump_ready(wk)) {
        return;
    }
    if (check_defense_lever(wk)) {
        return;
    }
    if (check_F_R_step(wk)) {
        return;
    }
    if (check_stand_up(wk)) {
        return;
    }
}



/* 2i 06009A04, 3s-near: sf3 src/PLS00.c:419 nm_09000 */
void nm_09000(PLW* wk) {
    if (setup_kuzureochi(wk)) {
        return;
    }
    if (check_full_gauge_attack(wk, 0)) {
        return;
    }
    if (check_super_arts_attack(wk)) {
        return;
    }
    if (check_special_attack(wk)) {
        return;
    }
    if (check_chouhatsu(wk)) {
        return;
    }
    if (check_catch_attack(wk)) {
        return;
    }
    if (check_leap_attack(wk)) {
        return;
    }
    if (check_nm_attack(wk)) {
        return;
    }
    if (check_cg_cancel_data(wk)) {
        return;
    }
    if (check_turn_to_back(wk)) {
        return;
    }
    if (check_F_R_dash(wk)) {
        return;
    }
    if (check_360_jump(wk)) {
        return;
    }
    if (check_jump_ready(wk)) {
        return;
    }
    if (check_stand_up(wk)) {
        return;
    }
    if (check_defense_lever(wk)) {
        return;
    }
    if (check_F_R_step(wk)) {
        return;
    }
}



/* 2i 06009AF0, 3s-near: sf3 src/PLS00.c:478 nm_10000 */
void nm_10000(PLW* wk) {
    if (wk->wu.cg_type == 0xFF) {
        TO_nm_09000((WORK*)wk);
        return;
    }
    if (check_full_gauge_attack(wk, 0)) {
        return;
    }
    if (check_super_arts_attack(wk)) {
        return;
    }
    if (check_special_attack(wk)) {
        return;
    }
    if (check_chouhatsu(wk)) {
        return;
    }
    if (check_catch_attack(wk)) {
        return;
    }
    if (check_leap_attack(wk)) {
        return;
    }
    if (check_nm_attack(wk)) {
        return;
    }
    if (check_cg_cancel_data(wk)) {
        return;
    }
    if (check_F_R_dash(wk)) {
        return;
    }
    if (check_360_jump(wk)) {
        return;
    }
    if (check_jump_ready(wk)) {
        return;
    }
    if (check_defense_lever(wk)) {
        return;
    }
    if (check_stand_up(wk)) {
        return;
    }
}



/* 2i 06009BCC, 3s-near: sf3 src/PLS00.c:532 nm_11000 */
void nm_11000(PLW* wk) {
    if (check_full_gauge_attack(wk, 0)) {
        return;
    }
    if (check_super_arts_attack(wk)) {
        return;
    }
    if (check_special_attack(wk)) {
        return;
    }
    if (check_chouhatsu(wk)) {
        return;
    }
    if (check_catch_attack(wk)) {
        return;
    }
    if (check_leap_attack(wk)) {
        return;
    }
    if (check_nm_attack(wk)) {
        return;
    }
    if (check_cg_cancel_data(wk)) {
        return;
    }
    if (check_turn_to_back(wk)) {
        return;
    }
    if (check_F_R_dash(wk)) {
        return;
    }
    if (check_360_jump(wk)) {
        return;
    }
    if (check_jump_ready(wk)) {
        return;
    }
    if (check_stand_up(wk)) {
        return;
    }
    if (check_defense_lever(wk)) {
        return;
    }
    if (check_walking_lv_dir2(wk)) {
        return;
    }
}




/* 2i 06009C6C, 3s-near: sf3 src/PLS00.c:536 nm_13000 */
void nm_13000(WORK* wk) {
    if (wk->cg_type == 0xFF) {
        TO_nm_01000(wk);
    }
}



/* 2i 06009C80, 3s-near: sf3 src/PLS00.c:544 nm_16000 */
void nm_16000(PLW* wk) {
    set_new_jpdir(wk);
    switch (wk->wu.cg_type) {
    case 0xFF:
        check_jump_rl_dir(wk);
        switch (wk->jpdir) {
        case 1:
            wk->wu.routine_no[2] = 21;
            break;
        case 2:
            wk->wu.routine_no[2] = 23;
            break;
        default:
            wk->wu.routine_no[2] = 22;
            break;
        }
        wk->wu.routine_no[3] = 0;
        break;
    case 1:
        break;
    }
    if (check_full_gauge_attack(wk, 0)) {
        return;
    }
    if (check_super_arts_attack(wk)) {
        return;
    }
    if (check_special_attack(wk)) {
        return;
    }
    if (check_chouhatsu(wk)) {
        return;
    }
    if (check_catch_attack(wk)) {
        return;
    }
    wk->wu.pat_status = jump_pat_status_data[wk->wu.rl_flag != wk->wu.rl_waza][wk->cp->lever_dir];
    if (check_leap_attack(wk)) {
        return;
    }
    if (check_nm_attack(wk)) {
        return;
    }
}



/* 2i 06009D80, 3s-near: sf3 src/PLS00.c:590 nm_17000 */
void nm_17000(PLW* wk) {
    set_new_jpdir(wk);
    if (wk->wu.cg_type == 0xFF) {
        check_jump_rl_dir(wk);
        switch (wk->jpdir) {
        case 1:
            wk->wu.routine_no[2] = 24;
            break;
        case 2:
            wk->wu.routine_no[2] = 26;
            break;
        default:
            wk->wu.routine_no[2] = 25;
            break;
        }
        wk->wu.routine_no[3] = 0;
        return;
    }
    if (check_full_gauge_attack(wk, 0)) {
        return;
    }
    if (check_super_arts_attack(wk)) {
        return;
    }
    if (check_special_attack(wk)) {
        return;
    }
    if (check_chouhatsu(wk)) {
        return;
    }
    check_catch_attack(wk);
}



/* 2i 06009E2E, 3s-near: sf3 src/PLS00.c:633 check_jump_rl_dir */
void check_jump_rl_dir(PLW* wk) {
    if (check_rl_flag(&wk->wu) == 0) {
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->cp->lever_dir = lvdir_conv[wk->cp->lever_dir];
        wk->jpdir = lvdir_conv[wk->jpdir];
    }
}




/* 2i 06009E62, 3s-near: sf3 src/PLS00.c:643 set_new_jpdir */
void set_new_jpdir(PLW* wk) {
    if (wk->cp->sw_lvbt & 1) {
        if (wk->cp->lever_dir) {
            wk->jpdir = wk->cp->lever_dir;
        }
    }
}



/* 2i 06009E8A, 3s-near: sf3 src/PLS00.c:653 nm_18000 */
void nm_18000(PLW* wk) {
    if (wk->wu.routine_no[3] < 2) {
        if (check_full_gauge_attack(wk, 0)) {
            return;
        }
        if (check_super_arts_attack(wk)) {
            return;
        }
        if (check_special_attack(wk)) {
            return;
        }
        if (check_chouhatsu(wk)) {
            return;
        }
        if (check_catch_attack(wk)) {
            return;
        }
        if (check_nm_attack(wk)) {
            return;
        }
        if (check_cg_cancel_data(wk)) {
            return;
        }
    }
    jumping_cg_type_check(wk);
}



/* 2i 06009F18, 3s-near: sf3 src/PLS00.c:693 jumping_cg_type_check */
void jumping_cg_type_check(PLW* wk) {
    if (wk->wu.pat_status < 32) {
        switch (wk->wu.cg_type) {
        case 0xFF:
            wk->guard_flag = 0;
            TO_nm_01000((WORK*)wk);
            break;
        case 2:
            wk->guard_flag = 0;
            if (check_full_gauge_attack(wk, 0)) {
                return;
            }
            if (check_super_arts_attack(wk)) {
                return;
            }
            if (check_special_attack(wk)) {
                return;
            }
            if (check_chouhatsu(wk)) {
                return;
            }
            if (check_catch_attack(wk)) {
                return;
            }
            if (check_leap_attack(wk)) {
                return;
            }
            if (check_nm_attack(wk)) {
                return;
            }
            if (check_cg_cancel_data(wk)) {
                return;
            }
            if (check_360_jump(wk)) {
                return;
            }
            if (check_jump_ready(wk)) {
                return;
            }
            break;
        case 7:
            wk->guard_flag = 0;
            if (check_full_gauge_attack(wk, 0)) {
                return;
            }
            if (check_super_arts_attack(wk)) {
                return;
            }
            if (check_special_attack(wk)) {
                return;
            }
            if (check_chouhatsu(wk)) {
                return;
            }
            if (check_catch_attack(wk)) {
                return;
            }
            if (check_leap_attack(wk)) {
                return;
            }
            if (check_nm_attack(wk)) {
                return;
            }
            if (check_cg_cancel_data(wk)) {
                return;
            }
            break;
        case 3:
            wk->guard_flag = 0;
            if (check_full_gauge_attack(wk, 0)) {
                return;
            }
            if (check_super_arts_attack(wk)) {
                return;
            }
            if (check_special_attack(wk)) {
                return;
            }
            if (check_chouhatsu(wk)) {
                return;
            }
            if (check_catch_attack(wk)) {
                return;
            }
            if (check_leap_attack(wk)) {
                return;
            }
            if (check_nm_attack(wk)) {
                return;
            }
            if (check_cg_cancel_data(wk)) {
                return;
            }
            if (check_turn_to_back(wk)) {
                return;
            }
            if (check_F_R_dash(wk)) {
                return;
            }
            if (check_360_jump(wk)) {
                return;
            }
            if (check_jump_ready(wk)) {
                return;
            }
            if (check_bend_myself(wk)) {
                return;
            }
            check_F_R_walk(wk);
            break;
        case 64:
            wk->guard_flag = 0;
            if (wk->wu.pat_status < 14) {
                TO_nm_36000((WORK*)wk);
                break;
            }
            TO_nm_38000((WORK*)wk);
            break;
        }
    } else {
        switch (wk->wu.cg_type) {
        case 0xFF:
            wk->guard_flag = 0;
            TO_nm_09000((WORK*)wk);
            break;
        case 2:
            wk->guard_flag = 0;
            if (check_full_gauge_attack(wk, 0)) {
                return;
            }
            if (check_super_arts_attack(wk)) {
                return;
            }
            if (check_special_attack(wk)) {
                return;
            }
            if (check_chouhatsu(wk)) {
                return;
            }
            if (check_catch_attack(wk)) {
                return;
            }
            if (check_leap_attack(wk)) {
                return;
            }
            if (check_nm_attack(wk)) {
                return;
            }
            if (check_cg_cancel_data(wk)) {
                return;
            }
            if (check_360_jump(wk)) {
                return;
            }
            if (check_jump_ready(wk)) {
                return;
            }
            break;
        case 7:
            wk->guard_flag = 0;
            if (check_full_gauge_attack(wk, 0)) {
                return;
            }
            if (check_super_arts_attack(wk)) {
                return;
            }
            if (check_special_attack(wk)) {
                return;
            }
            if (check_chouhatsu(wk)) {
                return;
            }
            if (check_catch_attack(wk)) {
                return;
            }
            if (check_leap_attack(wk)) {
                return;
            }
            if (check_nm_attack(wk)) {
                return;
            }
            if (check_cg_cancel_data(wk)) {
                return;
            }
            break;
        case 3:
            wk->guard_flag = 0;
            if (check_full_gauge_attack(wk, 0)) {
                return;
            }
            if (check_super_arts_attack(wk)) {
                return;
            }
            if (check_special_attack(wk)) {
                return;
            }
            if (check_chouhatsu(wk)) {
                return;
            }
            if (check_catch_attack(wk)) {
                return;
            }
            if (check_leap_attack(wk)) {
                return;
            }
            if (check_nm_attack(wk)) {
                return;
            }
            if (check_cg_cancel_data(wk)) {
                return;
            }
            if (check_turn_to_back(wk)) {
                return;
            }
            if (check_F_R_dash(wk)) {
                return;
            }
            if (check_360_jump(wk)) {
                return;
            }
            if (check_jump_ready(wk)) {
                return;
            }
            if (check_stand_up(wk)) {
                return;
            }
            if (check_F_R_step(wk)) {
                return;
            }
            break;
        case 64:
            wk->guard_flag = 0;
            TO_nm_37000((WORK*)wk);
            break;
        }
    }
}



/* 2i 0600A3D2, 3s-near: sf3 src/PLS00.c:951 jumping_guard_type_check */
void jumping_guard_type_check(PLW* wk) {
    switch (wk->wu.cg_type) {
    case 0xFF:
    case 64:
    case 2:
    case 3:
    case 7:
        wk->guard_flag = 0;
    }
}



/* 2i 0600A3FC, 3s-near: sf3 src/PLS00.c:964 nm_27000 */
void nm_27000(PLW* wk) {
    if (wk->wu.cg_type == 0xFF) {
        TO_nm_01000((WORK*)wk);
        return;
    }
    if (check_full_gauge_attack(wk, 0)) {
        return;
    }
    if (check_super_arts_attack(wk)) {
        return;
    }
    if (check_special_attack(wk)) {
        return;
    }
    if (check_chouhatsu(wk)) {
        return;
    }
    if (check_catch_attack(wk)) {
        return;
    }
    if (check_leap_attack(wk)) {
        return;
    }
    if (check_nm_attack(wk)) {
        return;
    }
    if (check_cg_cancel_data(wk)) {
        return;
    }
    if (check_turn_to_back(wk)) {
        return;
    }
    if (check_F_R_dash(wk)) {
        return;
    }
    if (check_360_jump(wk)) {
        return;
    }
    if (check_jump_ready(wk)) {
        return;
    }
    if (wk->cp->lever_dir != 2) {
        if (check_bend_myself(wk)) {
            return;
        }
        if (check_F_R_walk(wk)) {
            return;
        }
    }
    nm_27_cg_type_check(wk);
}




/* 2i 0600A4FC, 3s-near: sf3 src/PLS00.c:1024 nm_27_cg_type_check */
void nm_27_cg_type_check(PLW* wk) {
    s16 kind;
    if (wk->wu.routine_no[3] == 0) {
        return;
    }
    switch ((u8)wk->wu.cg_type) {
    case 1:
        if (check_em_catt(wk) == 0) {
            return;
        }
        if ((kind = check_defense_kind(wk)) != 0) {
            wk->wu.cg_ix = defense_cg_ix_table[wk->player_number][kind - 1] * wk->wu.cgd_type - wk->wu.cgd_type;
        } else {
            wk->wu.cg_ix -= wk->wu.cgd_type * 2;
        }
        char_move_z(&wk->wu);
        return;
    case 64:
        if (wk->wu.routine_no[2] == 29) {
            wk->wu.routine_no[2] = 37;
        } else {
            wk->wu.routine_no[2] = 36;
        }
        wk->wu.routine_no[3] = 0;
        wk->wu.cg_type = 0;
        return;
    case 32:
        break;
    case 0:
        check_defense_kind(wk);
        break;
    }
}



/* 2i 0600A5BC, 3s-near: sf3 src/PLS00.c:1059 nm_29000 */
void nm_29000(PLW* wk) {
    if (wk->wu.cg_type == 0xFF) {
        TO_nm_09000((WORK*)wk);
        return;
    }
    if (check_full_gauge_attack(wk, 0)) {
        return;
    }
    if (check_super_arts_attack(wk)) {
        return;
    }
    if (check_special_attack(wk)) {
        return;
    }
    if (check_chouhatsu(wk)) {
        return;
    }
    if (check_catch_attack(wk)) {
        return;
    }
    if (check_leap_attack(wk)) {
        return;
    }
    if (check_nm_attack(wk)) {
        return;
    }
    if (check_cg_cancel_data(wk)) {
        return;
    }
    if (check_turn_to_back(wk)) {
        return;
    }
    if (check_F_R_dash(wk)) {
        return;
    }
    if (check_360_jump(wk)) {
        return;
    }
    if (check_jump_ready(wk)) {
        return;
    }
    if (wk->cp->lever_dir != 2) {
        if (check_stand_up(wk)) {
            return;
        }
        if (check_F_R_step(wk)) {
            return;
        }
    }
    nm_27_cg_type_check(wk);
}



/* 2i 0600A6A0, 3s-near: sf3 src/PLS00.c:1119 nm_31000 */
void nm_31000(PLW* wk) {
    switch ((u8)wk->wu.cg_type) {
    case 1:
        if (check_full_gauge_attack(wk, 0)) {
            return;
        }
        if (check_super_arts_attack(wk)) {
            return;
        }
        if (check_special_attack(wk)) {
            return;
        }
        if (check_chouhatsu(wk)) {
            return;
        }
        if (check_catch_attack(wk)) {
            return;
        }
        if (check_leap_attack(wk)) {
            return;
        }
        if (check_nm_attack(wk)) {
            return;
        }
        break;
    case 64:
        if ((u8)wk->wu.pat_status < 32) {
            TO_nm_36000((WORK*)wk);
            break;
        }
        TO_nm_37000((WORK*)wk);
        break;
    case 0xFF:
        if ((u8)wk->wu.pat_status < 32) {
            TO_nm_01000((WORK*)wk);
            break;
        }
        TO_nm_09000((WORK*)wk);
        break;
    }
}



/* 2i 0600A78A, 3s-near: sf3 src/PLS00.c:1169 nm_34000 */
void nm_34000(PLW* wk) {
    switch ((u8)wk->wu.cg_type) {
    case 64:
    case 0xFF:
        TO_nm_18000_01((WORK*)wk);
        break;
    default:
        if (wk->wu.routine_no[3] >= 2) {
            if ((u8)wk->wu.pat_status < 32) {
                TO_nm_36000((WORK*)wk);
            } else {
                TO_nm_37000((WORK*)wk);
            }
        }
    }
}



/* 2i 0600A800, 3s-reloc: sf3 src/PLS00.c:1190 nm_36000 */
void nm_36000(PLW* wk) {
    if (wk->wu.cg_type == 0xFF) {
        if (wk->wu.now_koc == 0 && wk->wu.char_index == 0) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 1;
        } else {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
        }
    } else if (wk->player_number == PL_ELENA && wk->wu.now_koc == 0 && wk->wu.char_index == 36) {
        exset_char_move_init(&wk->wu, 0, 0);
        wk->wu.routine_no[2] = 1;
        wk->wu.routine_no[3] = 1;
    }
    nm_01000(wk);
}



/* 2i 0600A872, 3s-near: sf3 src/PLS00.c:1209 nm_37000 */
void nm_37000(PLW* wk) {
    if (wk->wu.cg_type == 0xFF) {
        wk->wu.routine_no[2] = 9;
        wk->wu.routine_no[3] = 0;
    }
    nm_09000(wk);
}



/* 2i 0600A88E, 3s-near: sf3 src/PLS00.c:1219 nm_38000 */
void nm_38000(PLW* wk) {
    if (wk->wu.routine_no[3] < 2) {
        if (check_full_gauge_attack(wk, 0)) {
            return;
        }
        if (check_super_arts_attack(wk)) {
            return;
        }
        if (check_special_attack(wk)) {
            return;
        }
        if (check_chouhatsu(wk)) {
            return;
        }
        if (check_catch_attack(wk)) {
            return;
        }
        if (check_nm_attack(wk)) {
            return;
        }
        if (check_cg_cancel_data(wk)) {
            return;
        }
    }
    jumping_cg_type_check(wk);
}



/* 2i 0600A91E, 3s-near: sf3 src/PLS00.c:1251 nm_39000 */
void nm_39000(PLW* wk) {
    if (wk->wu.cg_type == 0xFF) {
        if (wk->wu.now_koc == 0 && wk->wu.char_index == 0) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 1;
        } else {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
        }
    }
    nm_01000(wk);
}



/* 2i 0600A956, 3s-near: sf3 src/PLS00.c:1266 nm_40000 */
void nm_40000(PLW* wk) {
    if (wk->wu.routine_no[3] && wk->wu.cg_type == 0xFF) {
        wk->wu.routine_no[3] = 9;
    }
}



/* 2i 0600A974, 3s-reloc: sf3 src/PLS00.c:1274 nm_42000 */
void nm_42000(PLW* wk) {
    if (wk->wu.routine_no[3] > 1 && wk->wu.routine_no[3] < 4) {
        if (check_dm_shot_attack(wk)) {
            return;
        }
    }
    if (wk->wu.routine_no[3] > 3) {
        jumping_cg_type_check(wk);
    }
}



/* 2i 0600A9BC, 3s-near: sf3 src/PLS00.c:1287 nm_45000 */
void nm_45000(PLW* wk) {
    if (wk->wu.routine_no[3] == 3) {
        if (check_full_gauge_attack(wk, 0)) {
            return;
        }
        if (check_super_arts_attack(wk)) {
            return;
        }
        if (check_special_attack(wk)) {
            return;
        }
        if (check_chouhatsu(wk)) {
            return;
        }
        if (check_catch_attack(wk)) {
            return;
        }
        if (check_nm_attack(wk)) {
            return;
        }
        if (check_cg_cancel_data(wk)) {
            return;
        }
    }
    switch (wk->wu.cg_type) {
    case 64:
        if (wk->wu.pat_status < 32) {
            TO_nm_36000((WORK*)wk);
            break;
        }
        TO_nm_37000((WORK*)wk);
        break;
    case 0xFF:
        if (wk->wu.pat_status < 32) {
            TO_nm_01000((WORK*)wk);
            break;
        }
        TO_nm_09000((WORK*)wk);
        break;
    default:
        jumping_cg_type_check(wk);
        break;
    }
}



/* 2i 0600AA70, 3s-reloc: sf3 src/PLS00.c:1337 nm_47000 */
void nm_47000(PLW* wk) {
    if (wk->wu.routine_no[3] > 3) {
        jumping_cg_type_check(wk);
    }
}



/* 2i 0600AA82, 3s-reloc: sf3 src/PLS00.c:1345 nm_48000 */
void nm_48000(PLW* wk) {
    jumping_cg_type_check(wk);
}



/* 2i 0600AA86, 3s-reloc: sf3 src/PLS00.c:1351 nm_49000 */
void nm_49000(PLW* wk) {
    jumping_cg_type_check(wk);
}




/* 2i 0600AA8A, 3s-reloc: sf3 src/PLS00.c:1394 process_damage */
void process_damage(PLW* wk) {
    if (wk->wu.routine_no[3] != 0) {
        plpdm_xxxxx[wk->wu.routine_no[2]](wk);
    }
}



/* 2i 0600AADC, 3s-near: sf3 src/PLS00.c:1402 dm_00000 */
void dm_00000(PLW* wk) {
    if (wk->wu.routine_no[2] != 0) {
        return;
    }
    if (wk->wu.routine_no[3] != 2) {
        return;
    }
    if (check_sa_type_rebirth(wk) != 0) {
        wk->py->flag = 0;
        execute_super_arts(wk);
    } else {
        wk->wu.routine_no[3]++;
    }
}



/* 2i 0600AB1C, 3s-near: sf3 src/PLS00.c:1419 dm_04000 */
void dm_04000(PLW* wk) {
    switch (wk->wu.cg_type) {
    case 9:
        if (wk->py->flag == 0) {
        }
        break;
    case 64:
        if (wk->py->flag == 0) {
            wk->tsukamarenai_flag = 5;
            if (wk->wu.pat_status < 32) {
                TO_nm_36000((WORK*)wk);
            } else {
                TO_nm_37000((WORK*)wk);
            }
        } else {
            wk->wu.routine_no[2] = 19;
            wk->wu.routine_no[3] = 0;
        }
        break;
    case 0xFF:
        if (wk->py->flag == 0) {
            wk->tsukamarenai_flag = 5;
            if (wk->wu.pat_status < 32) {
                TO_nm_01000((WORK*)wk);
            } else {
                TO_nm_09000((WORK*)wk);
            }
        } else {
            wk->wu.routine_no[2] = 19;
            wk->wu.routine_no[3] = 0;
        }
        break;
    }
}



/* 2i 0600ABA6, 3s-near: sf3 src/PLS00.c:1456 dm_08000 */
void dm_08000(PLW* wk) {
    switch (wk->wu.cg_type) {
    case 0xFF:
        wk->tsukamarenai_flag = 5;
        TO_nm_01000(&wk->wu);
        break;
    case 64:
        wk->tsukamarenai_flag = 5;
        TO_nm_36000(&wk->wu);
        break;
    default:
        if (wk->wu.routine_no[3] < 3 && check_dm_shot_attack(wk)) {
            wk->tsukamarenai_flag = 5;
        }
        break;
    }
}



/* 2i 0600AC28, 3s-near: sf3 src/PLS00.c:1476 dm_17000 */
void dm_17000(PLW* wk) {
    if (wk->wu.routine_no[3] == 3) {
        wk->wu.routine_no[1] = 0;
        wk->wu.routine_no[2] = 23;
        wk->wu.routine_no[3] = 2;
        jumping_cg_type_check(wk);
    }
}



/* 2i 0600AC48, 3s-near: sf3 src/PLS00.c:1487 dm_18000 */
void dm_18000(PLW* wk) {
    switch (wk->wu.cg_type) {
    case 0xFF:
        if (wk->wu.vital_new < 0 && (check_sa_type_rebirth(wk) != 0)) {
            wk->py->flag = 0;
            execute_super_arts(wk);
            break;
        }
        if (wk->dead_flag) {
            wk->wu.routine_no[2] = 16;
        } else {
            wk->wu.routine_no[2] = 1;
        }
        wk->wu.routine_no[3] = 0;
        wk->wu.cg_type = 0;
        break;
    case 64:
        if (wk->py->flag == 0) {
            wk->tsukamarenai_flag = 5;
            TO_nm_36000(&wk->wu);
            break;
        }
        wk->wu.routine_no[2] = 19;
        wk->wu.routine_no[3] = 0;
        break;
    }
}




/* 2i 0600ACD8, 3s-near: sf3 src/PLS00.c:1517 dm_25000 */
void dm_25000(PLW* wk) {
    wk->py->time--;
    if (wk->py->time <= 0) {
        TO_nm_01000(&wk->wu);
    }
}



/* 2i 0600AD18, 3s-near: sf3 src/PLS00.c:1529 process_catch */
void process_catch(PLW* wk) {
    if (wk->wu.routine_no[3] == 0) {
        return;
    }
    switch (wk->wu.cg_type) {
    case 64:
        if (wk->wu.pat_status < 32) {
            TO_nm_36000((WORK*)wk);
            break;
        }
        TO_nm_37000((WORK*)wk);
        break;
    case 0xFF:
        if (wk->wu.pat_status < 32) {
            TO_nm_01000((WORK*)wk);
            break;
        }
        TO_nm_09000((WORK*)wk);
        break;
    }
}



/* 2i 0600AD66, 3s-near: sf3 src/PLS00.c:1553 nm_91000 */
void nm_91000(PLW* wk) {
    switch ((u8)wk->wu.cg_type) {
    case 64:
        if ((u8)wk->wu.pat_status < 32) {
            TO_nm_36000((WORK*)wk);
        } else {
            TO_nm_37000((WORK*)wk);
        }
        break;
    case 0xFF:
        if ((u8)wk->wu.pat_status < 32) {
            TO_nm_01000((WORK*)wk);
        } else {
            TO_nm_09000((WORK*)wk);
        }
        break;
    default:
        return;
    }
}



/* 2i 0600ADAC, 3s-exact: sf3 src/PLS00.c:1576 process_caught */
void process_caught(PLW* wk) {}



/* 2i 0600ADB0, 3s-near: sf3 src/PLS00.c:1580 nm_95000 */
void nm_95000(PLW* wk) {}



/* 2i 0600ADCC, 3s-near: sf3 src/PLS00.c:1584 process_attack */
void process_attack(PLW* wk) {
    if (wk->wu.routine_no[3]) {
        if (wk->cancel_timer && wk->wu.hit_stop == 0) {
            wk->cancel_timer--;
        }
        if (wk->cancel_timer) {
            if (check_full_gauge_attack(wk, 0)) {
                return;
            }
            if (check_super_arts_attack(wk)) {
                return;
            }
            if (check_special_attack(wk)) {
                return;
            }
            if (check_chouhatsu(wk)) {
                return;
            }
            if (check_catch_attack(wk)) {
                return;
            }
        }
        if (wk->wu.routine_no[2] < 16 && check_full_gauge_attack(wk, 1)) {
            wk->wu.cg_cancel &= 0;
            return;
        }
    }
    if (!check_cg_cancel_data(wk) && wk->wu.routine_no[3]) {
        jumping_cg_type_check(wk);
    }
}



/* 2i 0600AE6E, 3s-near: sf3 src/PLS00.c:1632 check_cg_cancel_data */
s32 check_cg_cancel_data(PLW* wk) {
    if (wk->wu.cg_cancel == 0) {
        return 0;
    }
    if (wk->wu.meoshi_hit_flag != 0) {
        if (wk->wu.cg_cancel & 0x40) {
            if (check_full_gauge_attack(wk, 0) != 0) {
                wk->wu.cg_cancel = 0;
                return 1;
            }
            if (check_super_arts_attack(wk)) {
                wk->wu.cg_cancel = 0;
                return 1;
            }
        }
        if (wk->wu.cg_cancel & 0x20) {
            if (check_special_attack(wk) != 0) {
                return 1;
            }
            if (check_chouhatsu(wk) != 0) {
                return 1;
            }
        }
    }
    if ((wk->wu.cg_cancel & 16) && (check_renda_cancel(wk) != 0)) {
        return 1;
    }
    if ((wk->wu.cg_cancel & 8) && (check_meoshi_cancel(wk) != 0)) {
        return 1;
    }
    if ((wk->wu.cg_cancel & 4) && ((wk->cp->sw_now & 0x770) != ((wk->current_attack))) && (check_nm_attack(wk) != 0)) {
        return 1;
    }
    if (wk->wu.meoshi_hit_flag == 0) {
        return 0;
    }
    if ((wk->wu.cg_cancel & 2) && (check_F_R_dash(wk))) {
        return 1;
    }
    if ((wk->wu.cg_cancel & 1) && (check_hijump_only(wk) != 0)) {
        return 1;
    }
    return 0;
}
