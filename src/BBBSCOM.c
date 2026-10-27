/*
 * BBBSCOM.C  Bonus stage: ball-thrower control and difficulty selection
 *
 * bbbs_com_execute is the control routine for the computer side in the ball bonus game
 * (Bonus_Game_Flag 22, called from PLMAIN2 instead of the normal CPU). On its first frame it picks
 * Bonus_Stage_Level: from the button combination the opponent holds (katteni_bonus_nando /
 * set_bonus_game_nando) or otherwise from the opponent's results (set_bonus_game_difficulty).
 * Then it steps through the bbbs_table entries for the level: waits, sets the throw action and
 * jump level, launches the balls through bbbs_ball_set, and ends when the table runs out.
 * It also creates the score display (effect 16) and the bonus-stage level objects.
 * bbbs_com_initialize clears Bonus_Stage_RNO.
 * There are five levels (0-4) and one table set.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFB1_INIT.h"
#include "EFFH0.h"
#include "EFFI8.h"
#include "EFF16.h"
#include "EFFH9.h"
#include "BBBSCOM.h"

/* Sean's attack routine 31 (pl12_exatt_table: Att_PL12_BONUS_STAGE), the ball thrower of the bonus stage */
#define SEAN_BONUS_STAGE 31
#include "cmd_data.h"



extern const BBBSTable bbbs_level_00[];
extern const BBBSTable bbbs_level_01[];
extern const BBBSTable bbbs_level_02[];
extern const BBBSTable bbbs_level_03[];
extern const BBBSTable bbbs_level_04[];



/* picks the level itself, one table set */
void bbbs_com_execute(PLW* wk) {
    switch (Bonus_Stage_RNO[0]) {
    case 0:
        if (Allow_a_battle_f == 0) {
            break;
        }
        if (katteni_bonus_nando(wk->wu.target_adrs)) {
            Bonus_Stage_Level = set_bonus_game_nando(((PLW*)wk->wu.target_adrs)->cp->sw_new & CMD_SW_KICK);
        } else {
            Bonus_Stage_Level = set_bonus_game_difficulty((wk->wu.id + 1) & 1);
        }
        Bonus_Stage_Tix = 0;
        Bonus_Stage_RNO[0] = 1;
        if ((wk->wu.dir_timer = bbbs_table[Bonus_Stage_Level][Bonus_Stage_Tix].timer)) {
            Bonus_Stage_RNO[1] = 1;
        } else {
            Bonus_Stage_RNO[1] = 2;
        }
        wk->zettai_muteki_flag = 1;
        effect_B1_init(wk);
        effect_16_init(wk);
        effect_H9_init(wk);
        effect_H0_init(&wk->wu);
        break;
    case 1:
        switch (Bonus_Stage_RNO[1]) {
        case 0:
            if (wk->wu.routine_no[1] != PLAYER_NORMAL) {
                break;
            }
            if (wk->wu.routine_no[2] != 1 && (wk->wu.routine_no[2] < 36 || wk->wu.routine_no[2] > 38)) {
                return;
            }
            Bonus_Stage_Tix++;
            if (bbbs_table[Bonus_Stage_Level][Bonus_Stage_Tix].timer == -1) {
                Bonus_Stage_RNO[0] = 2;
                Bonus_Stage_RNO[1] = 0;
                break;
            }
            if ((wk->wu.dir_timer = bbbs_table[Bonus_Stage_Level][Bonus_Stage_Tix].timer)) {
                if (bbbs_table[Bonus_Stage_Level][Bonus_Stage_Tix].kosuu) {
                    Bonus_Stage_RNO[1] = 1;
                } else {
                    Bonus_Stage_RNO[1] = 5;
                }
                break;
            }
            if (bbbs_table[Bonus_Stage_Level][Bonus_Stage_Tix].kosuu) {
                Bonus_Stage_RNO[1] = 2;
            } else {
                Bonus_Stage_RNO[1] = 6;
            }
            break;
        case 1:
            if (--wk->wu.dir_timer <= 0) {
                Bonus_Stage_RNO[1] = 2;
                break;
            }
            break;
        case 2:
            Bonus_Stage_RNO[1] = 3;
            wk->wu.routine_no[1] = PLAYER_ATTACK;
            wk->wu.routine_no[2] = SEAN_BONUS_STAGE;
            wk->wu.routine_no[3] = RN3_START;
            wk->wu.char_index = 71;
            wk->wu.cmwk[5] = bbbs_table[Bonus_Stage_Level][Bonus_Stage_Tix].kosuu;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[0].sp = 0;
            wk->wu.mvxy.a[1].sp = bbbs_jump_level[bbbs_table[Bonus_Stage_Level][Bonus_Stage_Tix].jmplv][0];
            wk->wu.mvxy.d[1].sp = bbbs_jump_level[bbbs_table[Bonus_Stage_Level][Bonus_Stage_Tix].jmplv][1];
            break;
        case 3:
            if (wk->wu.cg_type == 20) {
                wk->wu.cg_type = 0;
                bbbs_ball_set(wk, &bbbs_table[Bonus_Stage_Level][Bonus_Stage_Tix]);
                Bonus_Stage_RNO[1] = 4;
            }
            break;
        case 4:
            if (wk->wu.routine_no[1] == PLAYER_ATTACK && wk->wu.routine_no[2] == SEAN_BONUS_STAGE && wk->wu.routine_no[3] == 3) {
                Bonus_Stage_RNO[1] = 0;
            }
            break;
        case 5:
            if (--wk->wu.dir_timer <= 0) {
                Bonus_Stage_RNO[1] = 6;
            }
            break;
        case 6:
            Bonus_Stage_RNO[0] = 2;
            Bonus_Stage_RNO[1] = 0;
        }
    case 2:
        break;
    }
}



void bbbs_com_initialize(void) {
    Bonus_Stage_RNO[0] = Bonus_Stage_RNO[1] = 0;
    Bonus_Stage_RNO[2] = Bonus_Stage_RNO[3] = 0;
}



/* from the straight wins and the perfect and super-art finishes (weighted by the round setting), not the VS-CPU grade */
s32 set_bonus_game_difficulty(emid)
s16 emid;
{
    s16 s;
    s16 rate;
    s16 perfect;
    s16 super;

    if (bonus_level_max_check(emid)) {
        return 4;
    }
    if (Continue_Coin[emid]) {
        return 0;
    }
    rate = bonus_level_rate_tbl[Game_setting.set4 & 3];
    s = (Straight_Counter[emid] > 2) * 20;
    perfect = Perfect_Finish[emid] * rate * 4;
    super = Super_Arts_Finish[emid] * rate * 2;
    s = s + perfect + super;
    if (s < 60) {
        return 0;
    }
    if (s < 80) {
        return 1;
    }
    if (s < 100) {
        return 2;
    }
    if (s < 120) {
        return 3;
    }
    return 4;
}



/* buttons 0x100/0x200/0x400 pick levels 0-2, all three level 3 */
s32 set_bonus_game_nando(swdat)
u16 swdat;
{
    if (swdat == 0x700) {
        return 3;
    }
    if (swdat & 0x100) {
        return 0;
    }
    if (swdat & 0x200) {
        return 1;
    }
    if (swdat & 0x400) {
        return 2;
    }
    return 0;
}



/* one of 0x100-0x400 held and nothing of 0x7F, read from the player's work */
s32 katteni_bonus_nando(pl)
PLW* pl;
{
    if (pl->cp->sw_new & 0x7F) {
        return 0;
    }
    if (!(pl->cp->sw_new & CMD_SW_KICK)) {
        return 0;
    }
    return 1;
}



/* provisional name: 1 when player emid has just pressed exactly the combination 0x252 */
s32 bonus_level_max_check(s16 emid) {
    WORK_CP* cp = plw[emid].cp;
    if (cp->sw_new != 0x252) {
        return 0;
    }
    return 1;
}

/* 02000C0C */
const BBBSTable* bbbs_table[5] = { bbbs_level_00, bbbs_level_01, bbbs_level_02, bbbs_level_03, bbbs_level_04 };
