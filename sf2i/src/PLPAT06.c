/*
 * PLPAT06.C  Player 06 (Hugo) special attack routines
 *
 * Character-specific attack routines for player number 6. pl06_extra_attack dispatches attack
 * routine numbers 16 and up through pl06_exatt_table.
 * Att_PL06_TOKUSHUKOUDOU is the personal action: super gauge, then throw power (capped 8) on
 * cg_type 20 and strike power plus guts (tk_konjyou, capped 6/8) on cg_type 30. 2nd Impact has
 * neither the running command throw (3rd Strike's Att_PL06_HASHIRI_NAGE), the landing fix-up
 * (hoken_muriyari_chakuchi) nor the grade report.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLPAT.h"
#include "PLS01.h"
#include "PLPAT06.h"


/* 2i 06014DF8, 3s-reloc: sf3 src/PLPAT06.c:26 pl06_extra_attack */
void pl06_extra_attack(PLW* wk) {
    pl06_exatt_table[wk->wu.routine_no[2] - 16](wk);
}




/* 2i 06014E0E, 3s-near: sf3 src/PLPAT06.c:134 Att_PL06_TOKUSHUKOUDOU */
void Att_PL06_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 5, wk->as->char_ix);
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }
        switch (wk->wu.cg_type) {
        case 20:
            wk->wu.cg_type = 0;
            wk->tk_nage += 8;
            if (wk->tk_nage > 8) {
                wk->tk_nage = 8;
            }
            break;
        case 30:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 6;
            wk->tk_konjyou += 2;
            if (wk->tk_dageki > 6) {
                wk->tk_dageki = 6;
            }
            if (wk->tk_konjyou > 8) {
                wk->tk_konjyou = 8;
            }
            break;
        }
        break;
    }
}
