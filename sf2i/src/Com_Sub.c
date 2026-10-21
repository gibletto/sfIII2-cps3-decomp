/*
 * COM_SUB.C  Computer player: pattern step library and decision helpers
 *
 * The building blocks used by every CPU pattern. Pattern steps: End_Pattern, Lever_On/Off,
 * Walk, Approach_Walk, Keep_Away, Wait, Look, Forced_Guard, Normal_Attack, Lever_Attack,
 * Jump_Attack, Hi_Jump_Attack, Command_Attack, Rapid_Command_Attack, SA_Term and the other
 * *_Term steps that attack when range and state conditions are met.
 * Checks and helpers: Ck_Distance, Ck_Area and the Check_* tests on the opponent, combo
 * speed and reaction time selection, Select_Active / Select_Passive / Decide_Follow_Menu
 * that pick the next pattern, and projectile handling (Check_Shell, Decide_Shell_Guard,
 * Guard_or_Jump_VS_Shell).
 * Exit_Term_* and ETC_Term_* are the term routines tested by patterns to end or branch.
 * Called from the pattern modules (ACTIVE*, Passive*, FOLLOW*) and Com_Pl.
 * The passive reaction checks are in CK_PASS.C.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "PLS03ATT.h"
#include "PLS02.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "HITCHECK.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Com_Sub.h"
#include "fighter.h"

extern const FOLLOW_MENU_1ST Follow_Menu_1st_Unit_Data_0[];
extern const FOLLOW_MENU_1ST Follow_Menu_1st_Unit_Data_2[];
extern const FOLLOW_MENU_2ND Follow_Menu_2nd_Unit_Data_0[];
extern const FOLLOW_MENU_2ND Follow_Menu_2nd_Unit_Data_2[];

/* 02000664 */
const FOLLOW_MENU_1ST* Follow_Menu_1st_Unit_Data[13] = {
    Follow_Menu_1st_Unit_Data_0,
    Follow_Menu_1st_Unit_Data_0,
    Follow_Menu_1st_Unit_Data_2,
    Follow_Menu_1st_Unit_Data_0,
    Follow_Menu_1st_Unit_Data_0,
    Follow_Menu_1st_Unit_Data_0,
    Follow_Menu_1st_Unit_Data_0,
    Follow_Menu_1st_Unit_Data_0,
    Follow_Menu_1st_Unit_Data_0,
    Follow_Menu_1st_Unit_Data_0,
    Follow_Menu_1st_Unit_Data_0,
    Follow_Menu_1st_Unit_Data_0,
    Follow_Menu_1st_Unit_Data_0,
};
/* 02000698 */
const FOLLOW_MENU_2ND* Follow_Menu_2nd_Unit_Data[13] = {
    Follow_Menu_2nd_Unit_Data_0,
    Follow_Menu_2nd_Unit_Data_0,
    Follow_Menu_2nd_Unit_Data_2,
    Follow_Menu_2nd_Unit_Data_0,
    Follow_Menu_2nd_Unit_Data_0,
    Follow_Menu_2nd_Unit_Data_0,
    Follow_Menu_2nd_Unit_Data_0,
    Follow_Menu_2nd_Unit_Data_0,
    Follow_Menu_2nd_Unit_Data_0,
    Follow_Menu_2nd_Unit_Data_0,
    Follow_Menu_2nd_Unit_Data_0,
    Follow_Menu_2nd_Unit_Data_0,
    Follow_Menu_2nd_Unit_Data_0,
};



s8 Lv;  /* 0200DCF4 */
s8 Rnd;  /* 0200DCF5 */



/* 2i 06019B04, 3s-exact: sf3 src/Com_Sub.c:76 End_Pattern */
void End_Pattern(void) { Next_Be_Free(); }



void Next_Be_Passive(void) { Next_Be_Free(); }



/* 2i 06019B10, 3s-exact: sf3 src/Com_Sub.c:84 Turn_Over_On */
void Turn_Over_On(PLW* wk) {
    Disposal_Again[wk->wu.id] = 1;
    Turn_Over[wk->wu.id] = 1;
    CP_Index[wk->wu.id][0]++;
}



/* 2i 06019B36, 3s-exact: sf3 src/Com_Sub.c:92 Only_Shot */
void Only_Shot(wk, Lever_Data)
PLW* wk;
s16 Lever_Data;
{
    Lever_Buff[wk->wu.id] = Lever_Data;
    CP_Index[wk->wu.id][0]++;
}



/* 2i 06019B54, 3s-exact: sf3 src/Com_Sub.c:102 Lever_On */
void Lever_On(wk, LR_Lever, UD_Lever)
PLW* wk;
u16 LR_Lever;
u16 UD_Lever;
{
    CP_Index[wk->wu.id][0]++;
    Disposal_Again[wk->wu.id] = 1;
    if ((LR_Lever == 0) || (LR_Lever == 1)) {
        Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, LR_Lever);
    } else {
        Lever_LR[wk->wu.id] = 0;
    }
    Lever_LR[wk->wu.id] |= UD_Lever;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}



/* 2i 06019BD8, 3s-exact: sf3 src/Com_Sub.c:120 Lever_Off */
void Lever_Off(PLW* wk) {
    CP_Index[wk->wu.id][0]++;
    Disposal_Again[wk->wu.id] = 1;
    Lever_LR[wk->wu.id] = 0;
}



/* 2i 06019C02, 3s-exact: sf3 src/Com_Sub.c:128 Pierce_On */
void Pierce_On(PLW* wk) {
    Disposal_Again[wk->wu.id] = 1;
    CP_Index[wk->wu.id][0]++;
    Pierce_Menu[wk->wu.id] = 1;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}



/* provisional name */
/* 2i 06019C36, 3s-exact: sf3 src/Com_Sub.c:138 Pierce_Off */
void Pierce_Off(PLW* wk) {
    CP_Index[wk->wu.id][0]++;
    Pierce_Menu[wk->wu.id] = 0;
    Disposal_Again[wk->wu.id] = 1;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}



/* provisional name: a second copy of Pierce_Off */
/* 2i 06019C6C, 3s-exact: sf3 src/Com_Sub.c:148 Pierce_Off_2 */
void Pierce_Off_2(PLW* wk) {
    CP_Index[wk->wu.id][0]++;
    Pierce_Menu[wk->wu.id] = 0;
    Disposal_Again[wk->wu.id] = 1;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}



/* 2i 06019CA2, 3s-exact: sf3 src/Com_Sub.c:157 Setup_DENJIN_LEVEL */
void Setup_DENJIN_LEVEL(PLW* wk) {
    u16 xx;
    Disposal_Again[wk->wu.id] = 1;
    if ((xx = DENJIN_No[wk->wu.id])) {
        Next_Another_Menu(wk, 2, xx);
    } else {
        Next_Another_Menu(wk, 2, Denjin_Data[Area_Number[wk->wu.id]][random_16_com()]);
    }
}



/* 2i 06019D02, 3s-near: sf3 src/Com_Sub.c:169 Push_Shot */
void Push_Shot(wk, Power_Level)
PLW* wk;
s16 Power_Level;
{
    s16 xx;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if ((wk->wu.cg_type == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        } else {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            if ((wk->wu.now_koc == 8) && (wk->wu.char_index == 0xD)) {
                xx = wk->wu.cg_ix / wk->wu.cgd_type;
                if (xx >= Power_Level) {
                    CP_Index[wk->wu.id][1] = 0x63;
                }
            }
            if (Check_Exit_DENJIN(wk) != 0) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
        }
        break;
    case 1:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Exit_DENJIN(wk) != 0) {
            CP_Index[wk->wu.id][1] = 0x63;
        }
    default:
        if ((wk->wu.cg_type == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        } else {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
            Reaction_Sub(wk, 8, Power_Level);
        }
        break;
    }
}



/* 2i 06019E3C, 3s-reloc: sf3 src/Com_Sub.c:209 Check_Exit_DENJIN */
s32 Check_Exit_DENJIN(PLW* wk) {
    s16 xx;
    WORK* em;
    if (!(DENJIN_Term[wk->wu.id] & 1)) {
        if (CP_Index[wk->wu.id][1] == 0) {
            return 0;
        }
    }
    if ((DENJIN_Term[wk->wu.id] & 8)) {
        if (Attack_Flag[wk->wu.id]) {
            return 1;
        }
    }
    em = (WORK*)wk->wu.target_adrs;
    xx = 0;
    if ((em->xyz[0].disp.pos) == (em->old_pos[0])) {
    } else if (Check_Attack_Direction(wk, em) != 0) {
        xx = -1;
    } else {
        xx = 1;
    }
    if ((DENJIN_Term[wk->wu.id] & 1) && (em->xyz[0].disp.pos != 0)) {
        if (CP_Index[wk->wu.id][2] == 0) {
            CP_Index[wk->wu.id][2]++;
            CP_Index[wk->wu.id][3] = Area_Number[wk->wu.id];
        }
        switch (CP_Index[wk->wu.id][3]) {
        case 0:
        case 1:
        case 2:
            if (em->mvxy.a[1].real.h > 0) {
                return 1;
            }
            if (em->mvxy.a[1].real.h < 0) {
                if (em->xyz[1].disp.pos <= 0x28) {
                    return 1;
                }
            }
            break;
        default:
            if ((em->mvxy.a[1].real.h > 0) && (xx == -1)) {
                return 1;
            }
            if (em->mvxy.a[1].real.h < 0) {
                if (em->xyz[1].disp.pos <= 0x28) {
                    return 1;
                }
            }
            break;
        }
    }
    if (xx == 0) {
        return 0;
    }
    if ((DENJIN_Term[wk->wu.id] & 2) && (xx == 1)) {
        return 1;
    }
    if ((DENJIN_Term[wk->wu.id] & 4) && (xx == -1)) {
        return 1;
    }
    if ((DENJIN_Term[wk->wu.id] & 0x20) && (Lie_Flag[wk->wu.id] == 0)) {
        return 1;
    }
    return 0;
}



/* 2i 06019FE0, 3s-reloc: sf3 src/Com_Sub.c:277 Keep_Away */
void Keep_Away(wk, Target_Pos, Option)
PLW* wk;
s16 Target_Pos;
s16 Option;
{
    switch (CP_Index[wk->wu.id][3]) {
    case 0:
        if (Option == 0) {
            if (random_16_com() < 4) {
                Setup_KA_Jump(wk);
            } else {
                Setup_KA_Walk(wk);
            }
        } else {
            if (Option == 1) {
                Setup_KA_Jump(wk);
            } else {
                CP_Index[wk->wu.id][3] = Option + 1;
            }
        }
    case 1:
    case 2:
        Jump(wk, CP_Index[wk->wu.id][3] - 1);
        break;
    case 3:
    case 4:
        Approach_Walk(wk, Target_Pos, CP_Index[wk->wu.id][3] - 1);
        break;
    }
}



/* 2i 0601A0A0, 3s-exact: sf3 src/Com_Sub.c:310 Setup_KA_Jump */
void Setup_KA_Jump(PLW* wk) {
    s16 xx;
    CP_Index[wk->wu.id][3] = 2;
    xx = KA_Jump_Data[wk->player_number];
    if (wk->wu.rl_waza) {
        xx = wk->wu.xyz[0].disp.pos - KA_Jump_Data[wk->player_number];
        if ((bg_w.bgw[1].l_limit2 - bg_w.pos_offset) > xx) {
            CP_Index[wk->wu.id][3] = 1;
        }
    } else {
        xx = wk->wu.xyz[0].disp.pos + KA_Jump_Data[wk->player_number];
        if ((bg_w.bgw[1].r_limit2 + bg_w.pos_offset) < xx) {
            CP_Index[wk->wu.id][3] = 1;
        }
    }
}



/* 2i 0601A112, 3s-exact: sf3 src/Com_Sub.c:329 Setup_KA_Walk */
void Setup_KA_Walk(PLW* wk) {
    CP_Index[wk->wu.id][3] = 4;
}



/* 2i 0601A122, 3s-reloc: sf3 src/Com_Sub.c:335 Search_Back_Term */
void Search_Back_Term(wk, Move_Value, Next_Action, Next_Menu)
PLW* wk;
s16 Move_Value;
s16 Next_Action;
s16 Next_Menu;
{
    if (wk->wu.rl_waza) {
        Move_Value = wk->wu.xyz[0].disp.pos - Move_Value;
        if ((bg_w.bgw[1].l_limit2 - bg_w.pos_offset) > Move_Value) {
            Next_Another_Menu(wk, Next_Action, Next_Menu);
        } else {
            CP_Index[wk->wu.id][0]++;
        }
    } else {
        Move_Value = wk->wu.xyz[0].disp.pos + Move_Value;
        if (((bg_w.bgw[1].r_limit2) + (bg_w.pos_offset)) < (Move_Value)) {
            Next_Another_Menu(wk, Next_Action, Next_Menu);
        } else {
            CP_Index[wk->wu.id][0]++;
        }
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}



/* 2i 0601A1CA, 3s-exact: sf3 src/Com_Sub.c:361 Approach_Walk */
void Approach_Walk(wk, Target_Pos, Option)
PLW* wk;
s16 Target_Pos;
s16 Option;
{
    s16 xx;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Timer_00[wk->wu.id] = 0x78;
    case 1:
        xx = Standing_Timer[wk->wu.id];
        if (Lie_Flag[wk->wu.id] == 0) {
            if (Check_Passive(wk) != 0) {
                break;
            }
        }
        Standing_Timer[wk->wu.id] = xx;
        if (--Timer_00[wk->wu.id] == 0) {
            Next_Be_Free(wk);
        }
        else if (Check_Arrival(wk, Target_Pos, Option) != 0) {
            Disposal_Again[wk->wu.id] = 1;
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            if (CP_No[wk->wu.id][0] != 6) {
                Passive_Flag[wk->wu.id] = 0;
            }
        } else {
            Ck_Distance_Lv(wk);
            if (Option == 3) {
                Lever_Buff[wk->wu.id] ^= 0xC;
            }
        }
    }
}



/* 2i 0601A30C, 3s-reloc: sf3 src/Com_Sub.c:405 Check_Arrival */
s32 Check_Arrival(wk, Target_Pos, Option)
PLW* wk;
s16 Target_Pos;
s16 Option;
{
    if (Option == 3) {
        if (Target_Pos <= PL_Distance[wk->wu.id]) {
            return 1;
        }
        return wk->micchaku_flag;
    }
    if (wk->hos_em_flag) {
        return 1;
    }
    if (Target_Pos >= PL_Distance[wk->wu.id]) {
        return 1;
    }
    return 0;
}



/* provisional name */
/* 2i 0601A39A, 3s-near: sf3 src/Com_Sub.c:428 Approach_Until_Landed */
void Approach_Until_Landed(wk, Target_Pos)
PLW* wk;
s16 Target_Pos;
{
    WORK* em;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Timer_00[wk->wu.id] = 1;
    case 1:
        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }
        if (Target_Pos < PL_Distance[wk->wu.id]) {
            Timer_00[wk->wu.id] = 1;
            Ck_Distance_Lv(wk);
            break;
        }
        em = (WORK*)wk->wu.target_adrs;
        if (em->xyz[1].disp.pos + em->cg_jphos > 0) {
            Timer_00[wk->wu.id] = 20;
            break;
        }
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Lever_Buff[wk->wu.id] = 0;
        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
        if (CP_No[wk->wu.id][0] != 6) {
            Passive_Flag[wk->wu.id] = 0;
        }
        break;
    }
}



/* 2i 0601A4C0, 3s-near: sf3 src/Com_Sub.c:468 Walk */
void Walk(wk, Lever, Time, unused)
PLW* wk;
u16 Lever;
s16 Time;
s16 unused;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Timer_00[wk->wu.id] = Time;
        Timer_01[wk->wu.id] = wk->wu.rl_flag;
        Free_Lever[wk->wu.id] = Setup_Guard_Lever(wk, Lever);
    case 1:
        if (Lie_Flag[wk->wu.id] == 0) {
            if (Check_Passive(wk) != 0) {
                break;
            }
        }
        if (--Timer_00[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            if (*CP_No[wk->wu.id] != 6) {
                Passive_Flag[wk->wu.id] = 0;
            }
        } else {
            if ((Timer_01[wk->wu.id] != (s16)wk->wu.rl_flag) || (wk->micchaku_flag != 0) || (wk->hos_em_flag != 0)) {
                Next_Be_Free(wk);
            }
            Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
        }
        break;
    }
}



/* 2i 0601A626, 3s-exact: sf3 src/Com_Sub.c:509 Forced_Guard */
void Forced_Guard(wk, Guard_Type)
PLW* wk;
s16 Guard_Type;
{
    WORK* em;
    s16 xx;
    em = (WORK*)wk->wu.target_adrs;
    if (Attack_Flag[wk->wu.id] == 0) {
        Next_Be_Free(wk);
    }
    xx = Hit_Range_Data[em->hit_range];
    xx += Com_Width_Data[wk->wu.id];
    if (PL_Distance[wk->wu.id] > xx) {
        Next_Be_Free(wk);
    }
    Next_Be_Guard(wk, em, Guard_Type);
    Lever_Buff[wk->wu.id] |= Lever_Squat[wk->wu.id];
}



/* 2i 0601A692, 3s-near: sf3 src/Com_Sub.c:530 Provoke */
void Provoke(wk, Lever)
PLW* wk;
s16 Lever;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk)) {
            return;
        }
        CP_Index[wk->wu.id][1]++;
        if (Lever != -1) {
            Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, Lever & 1);
            Lever_LR[wk->wu.id] |= Lever & 2;
        }
    case 1:
        if (wk->permited_koa & 0x80) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = 0x240;
        }
        return;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (wk->wu.routine_no[1] == 4 && wk->wu.routine_no[2] == 0x1E) {
            return;
        }
        Reaction_Exit_Sub(wk);
        return;
    }
}



/* 2i 0601A7A6, 3s-near: sf3 src/Com_Sub.c:562 Normal_Attack */
void Normal_Attack(wk, Reaction, Lever_Data)
PLW* wk;
s16 Reaction;
u16 Lever_Data;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Lever_Data & 2) {
            Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, 1);
        } else {
            Lever_LR[wk->wu.id] = 0;
        }
        Lever_LR[wk->wu.id] |= Lever_Data & 2;
        (&Lever_Buff[0])[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = Lever_Data;
            Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
        } else {
            Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
        }
        break;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}



/* 2i 0601A912, 3s-reloc: sf3 src/Com_Sub.c:606 Small_Jump_Measure */
s32 Small_Jump_Measure(PLW* wk) {
    if (Lever_Squat[wk->wu.id] & 2) {
        return Setup_Guard_Lever(wk, 1);
    }
    return 0;
}



/* 2i 0601A944, 3s-near: sf3 src/Com_Sub.c:615 Normal_Attack_SP */
void Normal_Attack_SP(wk, Reaction, Lever_Data, Time)
PLW* wk;
s16 Reaction;
u16 Lever_Data;
s16 Time;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Timer_00[wk->wu.id] = Time;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            Lever_Buff[wk->wu.id] = Lever_Data;
            Lever_Squat[wk->wu.id] = Lever_Data & 2;
            CP_Index[wk->wu.id][1]++;
            Timer_00[wk->wu.id]--;
        } else {
            Lever_Buff[wk->wu.id] = Lever_Squat[wk->wu.id];
        }
        break;
    case 2:
        if (--Timer_00[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_Data;
            Lever_Squat[wk->wu.id] = Lever_Data & 2;
        } else {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}



#pragma inline(Check_Squat)

static s32 Check_Squat(wk)
PLW* wk;
{
    if (((WORK*)wk->wu.target_adrs)->pat_status == 0x20) {
        return 0;
    }
    return 2;
}



/* 2i 0601AAB4, 3s-near: sf3 src/Com_Sub.c:675 Adjust_Attack */
void Adjust_Attack(wk, Reaction, Lever_Data)
PLW* wk;
s16 Reaction;
u16 Lever_Data;
{
    u16 xx;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            xx = Check_Squat(wk);
            Lever_Buff[wk->wu.id] = Lever_Data | xx;
            Lever_LR[wk->wu.id] = xx;
            Lever_Buff[wk->wu.id] |= Small_Jump_Measure(wk);
            CP_Index[wk->wu.id][1]++;
        } else {
            (&Lever_Buff[0])[wk->wu.id] = Lever_LR[wk->wu.id];
            Lever_Buff[wk->wu.id] |= Small_Jump_Measure(wk);
        }
        break;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}


/* provisional name */
/* 2i 0601AC16, 3s-exact: sf3 src/Com_Sub.c:716 Check_Target_Pat_Status */
s32 Check_Target_Pat_Status(WORK* wk) {
    if (((WORK*)wk->target_adrs)->pat_status == 32) {
        return 0;
    }
    return 2;
}



/* 2i 0601AC2C, 3s-near: sf3 src/Com_Sub.c:725 Check_Start_Normal_Attack */
s32 Check_Start_Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data) {
    if (((wk->wu.routine_no[1]) != 4) || ((wk->wu.cg_type) == 0x40)) {
        return 0;
    }
    if (wk->wu.cg_cancel & 4) {
        return 0;
    }
    if (wk->permited_koa & 0x10) {
        return 0;
    }
    if ((wk->wu.cg_cancel & 8) && (Reaction == 0xE)) {
        return 0;
    }
    return 1;
}



/* 2i 0601AC78, 3s-near: sf3 src/Com_Sub.c:743 Lever_Attack */
void Lever_Attack(wk, Reaction, Lever, Lever_Data)
PLW* wk;
s16 Reaction;
u16 Lever;
u16 Lever_Data;
{
    s16 xx;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Lever_Attack(wk, Lever, Lever_Data) != 0) {
            break;
        }
        dash_flag_clear(wk->wu.id);
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id]) {
            break;
        }
        xx = Setup_Guard_Lever(wk, Lever);
        Lever_Buff[wk->wu.id] = (Lever_Data | xx);
        CP_Index[wk->wu.id][1]++;
        break;
    default:
        if (wk->wu.routine_no[1] == 2) {
            Be_Catch(wk);
        } else {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
            Reaction_Sub(wk, Reaction, 0);
        }
        break;
    }
}




/* 2i 0601AD76, 3s-near: sf3 src/Com_Sub.c:834 Setup_Guard_Lever */
s32 Setup_Guard_Lever(PLW* wk, u16 Lever) {
    if (Lever == 0) {
        if (wk->wu.rl_waza == 0) {
            return 4;
        }
        return 8;
    }
    if (wk->wu.rl_waza == 1) {
        return 4;
    }
    return 8;
}



/* 2i 0601AD9A, 3s-near: sf3 src/Com_Sub.c:852 Check_Start_Lever_Attack */
s32 Check_Start_Lever_Attack(wk, Lever, Lever_Data)
PLW* wk;
u16 Lever;
u16 Lever_Data;
{
    if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
        return 0;
    }
    if (wk->wu.cg_cancel & 4) {
        return 0;
    }
    if (wk->wu.cg_cancel & 8) {
        return 0;
    }
    return 1;
}



/* 2i 0601ADF8, 3s-near: sf3 src/Com_Sub.c:871 SA_Term */
void SA_Term(wk, SA0, SA1, SA2, Term_No)
PLW* wk;
u16 SA0;
u16 SA1;
u16 SA2;
u16 Term_No;
{
    s16 xx[3];
    if (((Passive_Flag[wk->wu.id]) == 0) && (Check_Passive(wk) != 0)) {
        return;
    }
    xx[0] = SA0;
    xx[1] = SA1;
    xx[2] = SA2;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    if (xx[plw[wk->wu.id].sa->kind_of_arts] == -1) {
        CP_Index[wk->wu.id][0]++;
    } else if ((plw[wk->wu.id].sa->ok) || (plw[wk->wu.id].sa->mp)) {
        Disposal_Again[wk->wu.id] = 1;
        if ((Term_No != -1) || (Term_No != 0)) {
            switch (My_char[wk->wu.id]) {
            case PL_RYU:
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                DENJIN_Check(wk, SA2, &xx[2], Term_No);
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;
            case PL_KEN:
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;
            case PL_ALEX:
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;
                break;
            case PL_NECRO:
                if (((WORK*)wk->wu.target_adrs)->xyz[1].disp.pos >= 0x10) {
                    CP_Index[wk->wu.id][0]++;
                    return;
                }
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;
            case PL_HUGO:
                if (SA_Range_Check(wk, 0, Term_No) != 0) {
                    return;
                }
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;
            case PL_ELENA:
                if ((plw[wk->wu.id].sa->kind_of_arts == 2) && (plw[wk->wu.id].wu.vital_new <= (Max_vitality / 2))) {
                    break;
                }
                CP_Index[wk->wu.id][0]++;
                return;
            case PL_ORO:
                YAGYOU_Check(wk, &xx[1], Term_No);
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;
            case PL_GOUKI1:
            case PL_GOUKI2:
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                if (SA_Range_Check(wk, 2, Term_No) != 0) {
                    return;
                }
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;
            }
        }
        Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
    } else {
        CP_Index[wk->wu.id][0]++;
    }
}



/* 2i 0601B102, 3s-near: sf3 src/Com_Sub.c:961 DENJIN_Check */
s32 DENJIN_Check(wk, SA2, xx, Term_No)
PLW* wk;
u16 SA2;
u16* xx;
u16 Term_No;
{
    if (plw[wk->wu.id].sa->kind_of_arts != 2) {
        return;
    }
    DENJIN_No[wk->wu.id] = Term_No;
    DENJIN_Term[wk->wu.id] = SA2;
    xx[0] = 0x37;
    return 1;
}



/* 2i 0601B134, 3s-near: sf3 src/Com_Sub.c:978 YAGYOU_Check */
s32 YAGYOU_Check(wk, xx, Term_No)
PLW* wk;
s16* xx;
u16 Term_No;
{
    if (plw[wk->wu.id].sa->kind_of_arts != 1) {
        return;
    }
    if (Term_No == 0) {
        Term_No = YAGYOU_Data[random_16_com()];
        Term_No += 0x36;
    }
    xx[0] = Term_No;
    return 1;
}



/* 2i 0601B174, 3s-near: sf3 src/Com_Sub.c:996 SA_Range_Check */
s32 SA_Range_Check(wk, SA_No, Range)
PLW* wk;
s16 SA_No;
u16 Range;
{
    if (plw[wk->wu.id].sa->kind_of_arts != SA_No) {
        return 0;
    }
    if (Range & 0x8000) {
        if ((PL_Distance[wk->wu.id]) < (Range & 0x7FFF)) {
            CP_Index[wk->wu.id][0]++;
            return 1;
        }
    }
    else if (PL_Distance[wk->wu.id] > Range) {
        CP_Index[wk->wu.id][0]++;
        return 1;
    }
    return 0;
}



/* 2i 0601B202, 3s-near: sf3 src/Com_Sub.c:1019 Check_SA */
void Check_SA(wk, Next_Action, Next_Menu)
PLW* wk;
s16 Next_Action;
s16 Next_Menu;
{
    if (plw[wk->wu.id].sa->ok) {
        CP_Index[wk->wu.id][0]++;
    } else {
        CP_No[wk->wu.id][0] = Next_Action;
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}



/* 2i 0601B276, 3s-near: sf3 src/Com_Sub.c:1036 Check_EX */
void Check_EX(wk, Next_Action, Next_Menu)
PLW* wk;
s16 Next_Action;
s16 Next_Menu;
{
    if (plw[wk->wu.id].sa->ex) {
        CP_Index[wk->wu.id][0]++;
    } else {
        CP_No[wk->wu.id][0] = Next_Action;
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}



/* 2i 0601B314, 3s-near: sf3 src/Com_Sub.c:1053 Check_SA_Full */
void Check_SA_Full(wk, Next_Action, Next_Menu)
PLW* wk;
s16 Next_Action;
s16 Next_Menu;
{
    Disposal_Again[wk->wu.id] = 1;
    if (!((wk->permited_koa & 0x40) == 0)) {
        CP_Index[wk->wu.id][0]++;
    } else {
        CP_No[wk->wu.id][0] = Next_Action;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}



/* provisional name */
/* 2i 0601B37A, 3s-exact: sf3 src/Com_Sub.c:1071 Check_SA_Range */
void Check_SA_Range(wk, SA_No, Range, Next_Action, Next_Menu)
PLW* wk;
s16 SA_No;
s16 Range;
s16 Next_Action;
s16 Next_Menu;
{
    Disposal_Again[wk->wu.id] = 1;
    if (plw[wk->wu.id].sa->kind_of_arts == SA_No) {
        if (PL_Distance[wk->wu.id] > Range) {
            CP_No[wk->wu.id][0] = Next_Action;
            Next_Another_Menu(wk, Next_Action, Next_Menu);
        }
    }
}



/* 2i 0601B3D0, 3s-reloc: sf3 src/Com_Sub.c:1089 Branch_Unit_Area */
void Branch_Unit_Area(wk, Next_Action, Menu_00, Menu_01, Menu_02, Menu_03)
PLW* wk;
s16 Next_Action;
s16 Menu_00;
s16 Menu_01;
s16 Menu_02;
s16 Menu_03;
{
    s16 xx[4];
    CP_No[wk->wu.id][0] = Next_Action;
    xx[0] = Menu_00;
    xx[1] = Menu_01;
    xx[2] = Menu_02;
    xx[3] = Menu_03;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    Disposal_Again[wk->wu.id] = 1;
    Next_Another_Menu(wk, Next_Action, xx[Area_Number[wk->wu.id]]);
}



/* 2i 0601B45C, 3s-exact: sf3 src/Com_Sub.c:1110 Com_Random_Select */
void Com_Random_Select(wk, Next_Action, Menu_00, Menu_01, Menu_02, Menu_03, Rnd_Type)
PLW* wk;
s16 Next_Action;
s16 Menu_00;
s16 Menu_01;
s16 Menu_02;
s16 Menu_03;
s16 Rnd_Type;
{
    s16 xx[4];
    s16 zz;
    zz = Com_Rnd_Select_Data[Rnd_Type][random_16_com()];
    xx[0] = Menu_00;
    xx[1] = Menu_01;
    xx[2] = Menu_02;
    xx[3] = Menu_03;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    if (xx[zz] == 0xFF) {
        Next_End(wk);
    } else {
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, xx[zz]);
    }
}



/* 2i 0601B4EE, 3s-reloc: sf3 src/Com_Sub.c:1137 Branch_Wait_Area */
void Branch_Wait_Area(wk, Time_00, Time_01, Time_02, Time_03)
PLW* wk;
s16 Time_00;
s16 Time_01;
s16 Time_02;
s16 Time_03;
{
    s16 xx[4];
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        xx[0] = Time_00;
        xx[1] = Time_01;
        xx[2] = Time_02;
        xx[3] = Time_03;
        Timer_00[wk->wu.id] = xx[Area_Number[wk->wu.id]];
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
        if (CP_No[wk->wu.id][0] != 6) {
            Passive_Flag[wk->wu.id] = 0;
        }
        break;
    }
}



/* 2i 0601B5DE, 3s-reloc: sf3 src/Com_Sub.c:1173 Wait */
void Wait(wk, Time)
PLW* wk;
s16 Time;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        if (Time == 0) {
            Timer_00[wk->wu.id] = Setup_WT_Data(wk);
        } else {
            Timer_00[wk->wu.id] = Time;
        }
        break;
    default:
        if (--Timer_00[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            if (CP_No[wk->wu.id][0] != 6) {
                Passive_Flag[wk->wu.id] = 0;
            }
        }
        break;
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}



/* 2i 0601B6B4, 3s-near: sf3 src/Com_Sub.c:1205 Look */
void Look(wk, Time)
PLW* wk;
s16 Time;
{
    s16* tm = Timer_00;
    Passive_Flag[wk->wu.id] = 0;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) == 0) {
            CP_Index[wk->wu.id][1]++;
            if (Time == 0) {
                tm[wk->wu.id] = Setup_LP_Data(wk);
            } else {
                tm[wk->wu.id] = Time;
            }
        }
        break;
    default:
        if (Check_Passive(wk) == 0 && --tm[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            Before_Look[wk->wu.id] = 1;
        }
        break;
    }
}



/* 2i 0601B7A8, 3s-reloc: sf3 src/Com_Sub.c:1242 Keep_Status */
void Keep_Status(wk, Lever_Data, Option_Data)
PLW* wk;
u16 Lever_Data;
s16 Option_Data;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Timer_00[wk->wu.id] = 0xA;
        Free_Lever[wk->wu.id] = Lever_Data;
        if (Option_Data != -1) {
            Free_Lever[wk->wu.id] |= Setup_Guard_Lever(wk, Option_Data);
        }
        Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
        break;
    default:
        Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        Timer_00[wk->wu.id] = 1;
        if (Attack_Flag[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            if (CP_No[wk->wu.id][0] != 6) {
                Passive_Flag[wk->wu.id] = 0;
            }
        }
        break;
    }
}



/* No final return: the routine's result is only read when Check_Guard succeeded (return 1). */
/* 2i 0601B8FC, 3s-exact: sf3 src/Com_Sub.c:1282 VS_Jump_Guard */
s32 VS_Jump_Guard(PLW* wk) {
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Guard(wk)) {
            return 1;
        }
        dash_flag_clear(wk->wu.id);
        CP_Index[wk->wu.id][1]++;
        break;
    default:
        if (Check_Guard(wk)) {
            return 1;
        }
        if (((WORK*)wk->wu.target_adrs)->xyz[1].disp.pos <= 0x18) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
        }
        break;
    }
}



/* 2i 0601B9B0, 3s-reloc: sf3 src/Com_Sub.c:1310 Wait_Lie */
void Wait_Lie(wk, Lever_Data)
PLW* wk;
u16 Lever_Data;
{
    WORK* em;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Rolling_Flag[wk->wu.id] = 0;
        if (Lever_Data != 0) {
            Free_Lever[wk->wu.id] = Setup_Guard_Lever(wk, 1);
            Free_Lever[wk->wu.id] |= Lever_Data & 2;
        } else {
            Free_Lever[wk->wu.id] = 0;
        }
    default:
        Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
        em = (WORK*)wk->wu.target_adrs;
        if ((Check_Blow_Off(wk, em, 0) == 0) || (Lie_Flag[wk->wu.id] != 0)) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
        }
        break;
    }
}



/* 2i 0601BADC, 3s-reloc: sf3 src/Com_Sub.c:1343 Wait_Get_Up */
void Wait_Get_Up(wk, Lever_Data, Option)
PLW* wk;
u16 Lever_Data;
s16 Option;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Rolling_Flag[wk->wu.id] = 0;
        if (Lever_Data != 0) {
            Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, 1);
            Lever_LR[wk->wu.id] |= Lever_Data & 2;
        } else {
            Lever_LR[wk->wu.id] = 0;
        }
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Wait_Term(wk, Option) != 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Disposal_Again[wk->wu.id] = 1;
            Passive_Flag[wk->wu.id] = 1;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
        }
        break;
    }
}



/* 2i 0601BBDE, 3s-near: sf3 src/Com_Sub.c:1377 Check_Wait_Term */
s32 Check_Wait_Term(wk, Option)
PLW* wk;
s16 Option;
{
    WORK* em;
    em = (WORK*)wk->wu.target_adrs;
    if (em->routine_no[1] == 1 && em->pat_status == 0x18) {
        return 0;
    }
    if (Lie_Flag[wk->wu.id] == 0) {
        return 1;
    }
    if (Option != 0) {
        return 0;
    }
    if (em->cg_type == 0xB) {
        return 1;
    }
    return 0;
}



/* 2i 0601BC4C, 3s-reloc: sf3 src/Com_Sub.c:1400 Wait_Attack_Complete */
void Wait_Attack_Complete(wk, Lever_Data, Option)
PLW* wk;
u16 Lever_Data;
s16 Option;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        if (Lever_Data != 0) {
            Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, 1);
            Lever_LR[wk->wu.id] |= Lever_Data & 2;
            Guard_Flag[wk->wu.id] = 1;
        } else {
            Lever_LR[wk->wu.id] = 0;
        }
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    {
        s32 k = Option;
        if (!Check_Exit_Guard(wk, k)) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Guard_Flag[wk->wu.id] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            if (!k) {
                Passive_Flag[wk->wu.id] = 0;
            }
        }
    }
}



/* 2i 0601BD52, 3s-reloc: sf3 src/Com_Sub.c:1437 Check_Exit_Guard */
s32 Check_Exit_Guard(wk, Option)
PLW* wk;
s16 Option;
{
    WORK* em;
    if (wk->wu.routine_no[1] == 1) {
        return 1;
    }
    if (Option == 0) {
        em = (WORK*)wk->wu.target_adrs;
        if (em->routine_no[1] != 4) {
            return 0;
        }
        return 1;
    }
    return Attack_Flag[wk->wu.id];
}



/* 2i 0601BDA2, 3s-near: sf3 src/Com_Sub.c:1457 Short_Range_Attack */
void Short_Range_Attack(wk, Reaction, Lever_Data, Next_Action, Next_Menu)
PLW* wk;
s16 Reaction;
u16 Lever_Data;
s16 Next_Action;
s16 Next_Menu;
{
    u16 xx;
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) == 0) {
            CP_Index[wk->wu.id][1]++;
            Check_First_Menu(wk);
            Ck_Distance_LvJ(wk);
            xx = get_nearing_range(wk->player_number, xx = Lever_Data & 0x7F0);
            if (PL_Distance[wk->wu.id] > xx) {
                Next_Another_Menu(wk, Next_Action, Next_Menu);
            }
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id]) {
            break;
        }
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}



/* 2i 0601BED8, 3s-near: sf3 src/Com_Sub.c:1499 EM_Term */
void EM_Term(wk, Range_X, Range_Y, Exit_Number, Next_Action, Next_Menu)
PLW* wk;
s16 Range_X;
s16 Range_Y;
s16 Exit_Number;
s16 Next_Action;
s16 Next_Menu;
{
    WORK* em;
    em = (WORK*)wk->wu.target_adrs;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        Term_No[wk->wu.id] = 0;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        switch (Check_Exit_Term(wk, em, Exit_Number)) {
        case 0:
            if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], Range_X) == 0) {
                break;
            }
            if (Check_Term_Sub_Y(wk, em->xyz[1].disp.pos, Range_Y) == 0) {
                break;
            }
            Disposal_Again[wk->wu.id] = 1;
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            break;
        case 1:
            Disposal_Again[wk->wu.id] = 1;
            Next_Another_Menu(wk, Next_Action, Next_Menu);
            break;
        case 2:
            break;
        case 3:
            Select_Passive(wk);
            break;
        default:
            Counter_Attack[wk->wu.id] = 1;
            Select_Passive(wk);
            break;
        }
        break;
    }
}



/* 2i 0601C026, 3s-near: sf3 src/Com_Sub.c:1560 SHELL_Term */
void SHELL_Term(wk, Next_Command, Exit_Number, Next_Action, Next_Menu, unused)
PLW* wk;
s16 Next_Command;
s16 Exit_Number;
s16 Next_Action;
s16 Next_Menu;
s16 unused;
{
    WORK* em;
    WORK_Other* tmw;
    s16 xx;
    em = (WORK*)Shell_Address[wk->wu.id];
    tmw = (WORK_Other*)Shell_Address[wk->wu.id];
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        Term_No[wk->wu.id] = 0;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Exit_Term(wk, em, Exit_Number) == -1) {
            Next_Another_Menu(wk, Next_Action, Next_Menu);
        } else {
            xx = Compute_Hit_Time(wk, tmw);
            if (xx < Shell_Dodge_Data[Next_Command][wk->player_number]) {
                Disposal_Again[wk->wu.id] = 1;
                CP_Index[wk->wu.id][0]++;
                CP_Index[wk->wu.id][1] = 0;
                CP_Index[wk->wu.id][2] = 0;
                CP_Index[wk->wu.id][3] = 0;
                Flip_Flag[wk->wu.id] = 0;
                Limited_Flag[wk->wu.id] = 0;
            }
        }
        break;
    }
}



/* 2i 0601C178, 3s-near: sf3 src/Com_Sub.c:1602 Check_Term_Sub_Air */
s32 Check_Term_Sub_Air(PLW* wk, s16 Distance, s16 Range) {
    if (Range == -1) {
        return 1;
    }
    if (!(Range & 0x8000)) {
        if (Distance >= Range) {
            return 1;
        }
        return 0;
    } else {
        Range += Correct_Unit_PL(wk);
        if (Distance <= (Range & 0x7FFF)) {
            return 1;
        }
        return 0;
    }
}



/* 2i 0601C1BE, 3s-reloc: sf3 src/Com_Sub.c:1622 Check_Term_Sub */
s32 Check_Term_Sub(PLW* wk, s16 Distance, s16 Range) {
    if (Range == -1) {
        return 1;
    }
    if (!(Range & 0x8000)) {
        if (Distance >= Range) {
            return 1;
        }
        return 0;
    } else {
        if (Distance <= (Range & 0x7FFF)) {
            return 1;
        }
        return 0;
    }
}



/* provisional name */
/* 2i 0601C1F0, 3s-near: sf3 src/Com_Sub.c:1642 Correct_Unit_PL */
s32 Correct_Unit_PL(PLW* wk) {
    return Correct_VS_Air_Data[My_char[Player_id]];
}



/* 2i 0601C202, 3s-reloc: sf3 src/Com_Sub.c:1648 Check_Term_Sub_Y */
s32 Check_Term_Sub_Y(wk, Distance, Range)
PLW* wk;
s16 Distance;
s16 Range;
{
    WORK* em;
    if (Range == -1) {
        return 1;
    }
    em = (WORK*)wk->wu.target_adrs;
    if (!(Range & 0x8000)) {
        if (Distance >= Range) {
            return 1;
        }
        return 0;
    } else {
        if (em->mvxy.a[1].real.h > 0) {
            return 0;
        }
        if (Distance <= (Range & 0x7FFF)) {
            return 1;
        }
        return 0;
    }
}



/* 2i 0601C26C, 3s-near: sf3 src/Com_Sub.c:1676 Jump */
void Jump(wk, Jump_Dir)
PLW* wk;
s16 Jump_Dir;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }
        if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            CP_Index[wk->wu.id][1]++;
            hi_jump_flag_clear(wk->wu.id);
            Check_First_Menu(wk);
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Jump_Init(wk, Jump_Dir);
        Check_Air_Guard(wk);
        break;
    case 2:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        }
        break;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Lever_Buff[wk->wu.id] |= Air_Guard_Lever(wk);
        if (wk->wu.xyz[1].disp.pos) {
            break;
        }
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        break;
    }
}



/* 2i 0601C40E, 3s-near: sf3 src/Com_Sub.c:1728 Hi_Jump */
void Hi_Jump(wk, Pl_Number, Jump_Dir)
PLW* wk;
s16 Pl_Number;
s16 Jump_Dir;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Hi_Jump(wk) == 0) {
            CP_Index[wk->wu.id][1]++;
            Tech_Address[wk->wu.id] = player_cmd[Pl_Number][2];
            Check_First_Menu(wk);
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Tech_Index[wk->wu.id] = 0xC;
        Jump_Init(wk, Jump_Dir);
        Lever_Buff[wk->wu.id] = 0;
        Check_Air_Guard(wk);
        break;
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Command_Type_00(wk, 8, -1, -1) == -1) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
            break;
        }
        if (!(Lever_Buff[wk->wu.id] & 2)) {
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
        }
        break;
    case 3:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        }
        break;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Lever_Buff[wk->wu.id] |= Air_Guard_Lever(wk);
        if (wk->wu.xyz[1].disp.pos) {
            break;
        }
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        break;
    }
}


/* 2i 0601C650, 3s-exact: sf3 src/Com_Sub.c:1796 Check_Start_Hi_Jump */
s32 Check_Start_Hi_Jump(PLW* wk) {
    if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
        return 0;
    }
    if (wk->wu.cg_cancel & 4) {
        return 0;
    }
    if (wk->wu.cg_cancel & 1) {
        return 0;
    }
    return 1;
}



/* 2i 0601C688, 2i only: the air guard lever while the jump lasts (provisional name) */
s32 Air_Guard_Lever(PLW* wk) {
    switch (Air_Guard_Type[wk->wu.id]) {
    case 0:
        return 0;
    case 1:
        if (Attack_Flag[wk->wu.id] == 0) {
            return 0;
        }
        if (--Timer_01[wk->wu.id]) {
            return 0;
        }
        Timer_01[wk->wu.id] = 11;
        return Free_Lever[wk->wu.id];
    default:
        if (Attack_Flag[wk->wu.id] == 0) {
            return 0;
        }
        if (--Timer_01[wk->wu.id]) {
            return 0;
        }
        Timer_01[wk->wu.id] = 15;
        return Free_Lever[wk->wu.id];
    }
}



/* 2i 0601C724, 2i form of sf3 Check_Air_Guard: decides the air guard when the jump starts */
s32 Check_Air_Guard(PLW* wk) {
    Free_Lever[wk->wu.id] = 0;
    if (Lever_LR) {
        return;
    }
    Lv = Setup_Lv10(0);
    if (Break_Into_CPU == 2) {
        Lv = 9;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    Rnd = random_16_com();
    if (EM_Rank != 0) {
        Air_Guard_Type[wk->wu.id] = Air_Guard_Data[16][Lv][Rnd];
    } else {
        Air_Guard_Type[wk->wu.id] = Air_Guard_Data[wk->player_number][Lv][Rnd];
    }
    if (Air_Guard_Type[wk->wu.id] == 0) {
        return 0;
    }
    Timer_01[wk->wu.id] = 1;
    Free_Lever[wk->wu.id] = Setup_Guard_Lever(wk, Air_Guard_Type[wk->wu.id] - 1);
    return 1;
}




/* provisional name */
/* 2i 0601C800, 3s-near: sf3 src/Com_Sub.c:1853 Jump_Air_Guard */
void Jump_Air_Guard(wk, Lever)
PLW* wk;
s16 Lever;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (wk->wu.routine_no[1] == 4 && wk->wu.cg_type != 64) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Free_Lever[wk->wu.id] = Setup_Guard_Lever(wk, Lever);
    case 1:
        Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id] | 1;
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    default:
        if (wk->wu.xyz[1].disp.pos) {
            break;
        }
        Lever_Buff[wk->wu.id] = 0;
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        break;
    }
}



/* 2i 0601C92E, 3s-near: sf3 src/Com_Sub.c:1890 Jump_Attack */
void Jump_Attack(wk, Reaction, Time_Data, Lever_Data, Jump_Dir)
PLW* wk;
s16 Reaction;
s16 Time_Data;
u16 Lever_Data;
s16 Jump_Dir;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);
        if (Check_Passive(wk) != 0) {
            break;
        }
        if ((wk->wu.routine_no[1] == 4) && (wk->wu.cg_type != 0x40)) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Timer_00[wk->wu.id] = Time_Data;
        Continue_Menu[wk->wu.id] = 0;
        wk->wu.hf.hit.player = 0;
        hi_jump_flag_clear(wk->wu.id);
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        } else {
            Timer_00[wk->wu.id] = Time_Data;
            CP_Index[wk->wu.id][1]++;
            dash_flag_clear(wk->wu.id);
            Jump_Init(wk, Jump_Dir);
            Check_Air_Guard(wk);
            break;
        }
    case 2:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        }
        break;
    case 3:
        Lever_Buff[wk->wu.id] |= Air_Guard_Lever(wk);
        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }
        Lever_Data = Check_SP_Jump_Attack(wk, Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        break;
    default:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
}



/* 2i 0601CB2C, 3s-near: sf3 src/Com_Sub.c:1960 Jump_Attack_Term */
void Jump_Attack_Term(wk, Range_X, Range_Y, Reaction, Lever_Data, Jump_Dir, Range_JX, Range_JY, J_Lever_Data)
PLW* wk;
s16 Range_X;
s16 Range_Y;
s16 Reaction;
u16 Lever_Data;
s16 Jump_Dir;
s16 Range_JX;
s16 Range_JY;
s16 J_Lever_Data;
{
    s32 Reaction2;
    switch (Reaction2 = Reaction & 0x7F, CP_Index[wk->wu.id][1]) {
    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);
        if ((wk->wu.routine_no[1] == 4) && (wk->wu.cg_type != 0x40)) {
            break;
        }
        hi_jump_flag_clear(wk->wu.id);
        Continue_Menu[wk->wu.id] = 0;
        wk->wu.hf.hit.player = 0;
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
            dash_flag_clear(wk->wu.id);
            Jump_Init(wk, Jump_Dir);
            Check_Air_Guard(wk);
        }
        break;
    case 2:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        } else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        }
        break;
    case 3:
        Lever_Buff[wk->wu.id] |= Air_Guard_Lever(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, Range_JX, Range_JY, J_Lever_Data) != 0) {
            break;
        }
        if (Check_Term_ABS_Distance(wk)) {
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], Range_X) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }
        Lever_Data = Check_SP_Jump_Attack(wk, Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        Stock_Hit_Flag[wk->wu.id] = 0;
        break;
    case 4:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        if (Check_Landed(wk, Reaction2) != 0) {
            break;
        }
        break;
    case 5:
        if (Check_Landed(wk, Reaction2) == 0) {
            switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
            default:
            case 1:
            case 10:
                if (Command_Type_00(wk, 8, -1, -1) == -1) {
                    CP_Index[wk->wu.id][1] = 0x63;
                }
                break;
            }
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
}



/* 2i 0601CDFC, 3s-reloc: sf3 src/Com_Sub.c:2061 Check_SP_Jump_Attack */
s32 Check_SP_Jump_Attack(wk, Lever_Data)
PLW* wk;
s16 Lever_Data;
{
    u16 xx;
    if (!(Lever_Data & 0x8000)) {
        return Lever_Data;
    }
    xx = Setup_Guard_Lever(wk, 0);
    xx |= Lever_Data & 0x7FFF;
    return xx | 2;
}



/* 2i 0601CE2E, 3s-near: sf3 src/Com_Sub.c:2076 Check_VS_Air_Attack */
s32 Check_VS_Air_Attack(PLW* wk, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data) {
    WORK* em;
    if ((Range_JX == -1) && (Range_JY == -1)) {
        return 0;
    }
    em = (WORK*)wk->wu.target_adrs;
    if ((em->pat_status != 0xE) && (em->pat_status != 0x14) && (em->pat_status != 0x1A) && (em->xyz[1].disp.pos <= 0)) {
        return 0;
    }
    if (Check_Term_Sub_Air(wk, PL_Distance[wk->wu.id], Range_JX) == 0) {
        return 0;
    }
    if (Check_Term_Sub(wk, Ck_Distance_Height(wk), Range_JY) != 0) {
        switch (CP_Index[wk->wu.id][2]) {
        case 0:
            CP_Index[wk->wu.id][2]++;
            Timer_01[wk->wu.id] = Select_Reflection_Time(wk);
            Timer_01[wk->wu.id]++;
            break;
        default:
            if (--Timer_01[wk->wu.id] != 0) {
                break;
            }
            if (J_Lever_Data & 0x4000) {
                CP_Index[wk->wu.id][1] += 2;
                Tech_Address[wk->wu.id] = player_cmd[wk->player_number][J_Lever_Data & 0x3FFF];
                Continue_Menu[wk->wu.id] = 1;
                return -1;
            }
            Lever_Buff[wk->wu.id] = J_Lever_Data;
            CP_Index[wk->wu.id][1]++;
            Continue_Menu[wk->wu.id] = 1;
            return 1;
        }
    }
    return 0;
}



/* 2i 0601CF94, 3s-near: sf3 src/Com_Sub.c:2119 Hi_Jump_Attack */
void Hi_Jump_Attack(wk, Reaction, Time_Data, Lever_Data, Jump_Dir)
PLW* wk;
s16 Reaction;
s16 Time_Data;
u16 Lever_Data;
s16 Jump_Dir;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Hi_Jump(wk) == 0) {
            Continue_Menu[wk->wu.id] = 0;
            wk->wu.hf.hit.player = 0;
            CP_Index[wk->wu.id][1]++;
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][2];
            Timer_00[wk->wu.id] = Time_Data;
            Check_First_Menu(wk);
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        } else {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;
            dash_flag_clear(wk->wu.id);
            Jump_Init(wk, Jump_Dir);
            Lever_Pool[wk->wu.id] &= 0xC;
            Lever_Buff[wk->wu.id] = 0;
            Check_Air_Guard(wk);
            break;
        }
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Command_Type_00(wk, 8, -1, -1) == -1) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
            break;
        }
        if (Lever_Buff[wk->wu.id] & 2) {
            return;
        }
        Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
        break;
    case 3:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id] | 1;
        }
        break;
    case 4:
        Lever_Buff[wk->wu.id] |= Air_Guard_Lever(wk);
        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }
        Lever_Data = Check_SP_Jump_Attack(wk, (s16)Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1] += 2;
        if (Reaction & 0x80) {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    case 6:
        if (Attack_Flag[wk->wu.id]) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        if (wk->wu.hf.hit.player == 0) {
            break;
        }
        if (!(wk->wu.cg_cancel & 8)) {
            break;
        }
        Lever_Buff[wk->wu.id] = Get_Meoshi_Data(wk);
        break;
    default:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
}



/* 2i 0601D2B0, 3s-near: sf3 src/Com_Sub.c:2222 Hi_Jump_Attack_Term */
void Hi_Jump_Attack_Term(wk, Range_X, Range_Y, Reaction, Lever_Data, Jump_Dir, Range_JX, Range_JY, J_Lever_Data)
PLW* wk;
s16 Range_X;
s16 Range_Y;
s16 Reaction;
u16 Lever_Data;
s16 Jump_Dir;
s16 Range_JX;
s16 Range_JY;
u16 J_Lever_Data;
{
    s32 Reaction2;
    switch (Reaction2 = Reaction & 0xFFF, CP_Index[wk->wu.id][1]) {
    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Hi_Jump(wk) != 0) {
            break;
        }
        Continue_Menu[wk->wu.id] = 0;
        wk->wu.hf.hit.player = 0;
        CP_Index[wk->wu.id][1]++;
        Tech_Address[wk->wu.id] = player_cmd[wk->player_number][2];
        Check_First_Menu(wk);
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;
            dash_flag_clear(wk->wu.id);
            Jump_Init(wk, Jump_Dir);
            Lever_Pool[wk->wu.id] &= 0xC;
            Lever_Buff[wk->wu.id] = 0;
            Check_Air_Guard(wk);
        }
        break;
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Command_Type_00(wk, 8, -1) == -1) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
        } else {
            if (Lever_Buff[wk->wu.id] & 2) {
                return;
            }
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
        }
        break;
    case 3:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id] | 1;
        }
        break;
    case 4:
        Lever_Buff[wk->wu.id] |= Air_Guard_Lever(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, Range_JX, Range_JY, J_Lever_Data) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], Range_X) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }
        Lever_Data = Check_SP_Jump_Attack(wk, (s16)Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        if (Reaction & 0x80) {
            CP_Index[wk->wu.id][1] = 8;
        }
        break;
    case 5:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction2);
        break;
    case 6:
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            Command_Type_00(wk, -1);
            CP_Index[wk->wu.id][1] = 0x63;
        }
        break;
    case 7:
        if (--Combo_Speed[wk->wu.id]) {
            break;
        }
        Lever_Buff[wk->wu.id] = Tech_Address[wk->wu.id][8];
        CP_Index[wk->wu.id][1]++;
        break;
    case 8:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction2);
        break;
    default:
        if (Attack_Flag[wk->wu.id]) {
            break;
        }
        CP_Index[wk->wu.id][1] = 8;
        if (wk->wu.hf.hit.player == 0) {
            break;
        }
        if (wk->wu.cg_cancel & 8) {
            Lever_Buff[wk->wu.id] = Get_Meoshi_Data(wk);
        }
        break;
    }
    Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
}



/* 2i 0601D6A6, 3s-near: sf3 src/Com_Sub.c:2360 Check_Term_ABS_Distance */
s32 Check_Term_ABS_Distance(PLW* wk) {
    if (Turn_Over[wk->wu.id]) {
        return 1;
    }
    if (My_char[wk->wu.id] == PL_NECRO) {
        return 0;
    }
    if (PL_Distance[wk->wu.id] <= 0x30) {
        return 1;
    }
    if (wk->wu.mvxy.a[1].real.h >= 0) {
        return 0;
    }
    if (wk->wu.xyz[1].disp.pos <= 0x30) {
        return 1;
    }
    return 0;
}



/* 2i 0601D6F4, 3s-reloc: sf3 src/Com_Sub.c:2381 Check_Com_Add_Y */
s32 Check_Com_Add_Y(PLW* wk, s16 Pos_Y, s16 Range) {
    if (Range == -1) {
        return 1;
    }
    if (!(Range & 0x8000)) {
        if (Pos_Y >= Range) {
            return 1;
        }
        return 0;
    } else {
        if (wk->wu.mvxy.a[1].real.h >= 0) {
            return 0;
        }
        if (Pos_Y <= (Range & 0x7FFF)) {
            return 1;
        }
        return 0;
    }
}


/* provisional name */
/* 2i 0601D75E, 3s-near: sf3 src/Com_Sub.c:2403 Check_Com_Add_Y_Sub */
s32 Check_Com_Add_Y_Sub(PLW* wk) {
    if (wk->wu.routine_no[1] != 4 || (u8)wk->wu.cg_type == 64) {
        return 1;
    }
    return 0;
}




/* 2i 0601D77A, 3s-near: sf3 src/Com_Sub.c:2669 Command_Attack */
void Command_Attack(wk, Reaction, Tech_Number, Power_Level, Ex_Shot)
PLW* wk;
s16 Reaction;
u16 Tech_Number;
s16 Power_Level;
s16 Ex_Shot;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        dash_flag_clear(wk->wu.id);
        Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
        Tech_Index[wk->wu.id] = 0xC;
        (&Lever_Buff[0])[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Start_Command_Attack(wk, Reaction, Tech_Number & 0x80FF) != 0) {
            break;
        }
        if (Check_Dash_Hit(wk, Tech_Number & 0x80FF) != 0) {
            Next_Be_Free(wk);
        }
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
        if (Power_Level & 0x4000) {
            Free_Lever[wk->wu.id] = Free_Lever_Data[(Power_Level & 0xF) - 8];
        } else {
            Free_Lever[wk->wu.id] = 0;
        }
    case 1:
        if (--Combo_Speed[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            break;
        }
        if (Hadou_Check(wk, Tech_Number & 0x80FF) != 0) {
            if (Check_Passive(wk) == 0) {
                Combo_Speed[wk->wu.id] = 1;
            }
            break;
        } else {
            CP_Index[wk->wu.id][1]++;
            Check_Rapid(wk, Tech_Number);
        }
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        case 1:
        default:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                if ((Tech_Number & 0xF) == 0 || (Tech_Number & 0xF) == 1) {
                    if (Reaction == 0xC) {
                        CP_Index[wk->wu.id][1] = 0x63;
                        Timer_00[wk->wu.id] = Command_Wait_Data[wk->player_number][Tech_Number];
                    } else {
                        CP_Index[wk->wu.id][1] = 4;
                    }
                } else {
                    CP_Index[wk->wu.id][1] = 3;
                }
            }
            break;
        case 2:
            if (Command_Type_01(wk, Power_Level & 0xF, Ex_Shot) != 0) {
                CP_Index[wk->wu.id][1]++;
            }
            break;
        case 7:
            if (Command_Type_06(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) != 0) {
                CP_Index[wk->wu.id][1]++;
            }
            break;
        }
        break;
    case 3:
        (&Lever_Buff[0])[wk->wu.id] = Lever_LR[wk->wu.id];
        if (plw[wk->wu.id].tsukami_f) {
            break;
        }
        if (((wk->wu.cg_type) == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        } else {
            Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
            Rapid_Sub(wk);
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
            Reaction_Sub(wk, Reaction, Power_Level);
        }
        break;
    case 4:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (((wk->wu.cg_type) == 0x40) || (wk->running_f == 0)) {
            Reaction_Exit_Sub(wk);
        }
        break;
    case 5:
        if (PL_Distance[wk->wu.id] > 0x70) {
            Lever_Buff[wk->wu.id] = 0x40;
        }
        if (((wk->wu.cg_type) == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        }
        break;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (--Timer_00[wk->wu.id] == 0) {
            Reaction_Exit_Sub(wk);
        }
        break;
    }
}




/* 2i 0601DBD8, 3s-near: sf3 src/Com_Sub.c:2780 Hadou_Check (2i tests Ryu and Ken directly, no Hadou_Check_Data) */
s32 Hadou_Check(wk, Tech_Number)
PLW* wk;
u16 Tech_Number;
{
    if ((wk->player_number != PL_KEN) && (wk->player_number != PL_RYU)) {
        return 0;
    }
    if (Tech_Number != 0x1D) {
        return 0;
    }
    return Check_Resume_Lever(wk);
}



/* 2i 0601DBFE, 3s-reloc: sf3 src/Com_Sub.c:2795 Check_Resume_Lever */
s32 Check_Resume_Lever(PLW* wk) {
    u16 Target_Lever;
    s16 xx;
    if (wk->wu.rl_waza) {
        Target_Lever = 8;
    } else {
        Target_Lever = 4;
    }
    for (xx = 0; xx <= 8; xx++) {
        if (Target_Lever == Resume_Lever[wk->wu.id][xx]) {
            return 1;
        }
    }
    return 0;
}



/* 2i 0601DC46, 3s-near: sf3 src/Com_Sub.c:2813 J_Command_Attack */
void J_Command_Attack(wk, Reaction, Tech_Number, Power_Level, Ex_Shot)
PLW* wk;
s16 Reaction;
u16 Tech_Number;
s16 Power_Level;
s16 Ex_Shot;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        dash_flag_clear(wk->wu.id);
        Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
        Tech_Index[wk->wu.id] = 0xC;
        (&Lever_Buff[0])[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Start_Command_Attack(wk, Reaction, Tech_Number & 0x80FF) != 0) {
            break;
        }
        if (Check_Dash_Hit(wk, Tech_Number & 0x80FF) != 0) {
            Next_Be_Free(wk);
        }
        Continue_Menu[wk->wu.id] = 0;
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            break;
        }
        CP_Index[wk->wu.id][1]++;
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        case 2:
            if (Command_Type_01(wk, Power_Level & 0xF, Ex_Shot) != 0) {
                CP_Index[wk->wu.id][1]++;
            }
            break;
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;
    case 3:
        Check_Rapid(wk, Tech_Number);
        CP_Index[wk->wu.id][1]++;
        return;
    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        if ((wk->wu.cg_type == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        } else {
            Rapid_Sub(wk);
            if (Reaction == 0xC) {
                Reaction_Sub(wk, Reaction, Power_Level);
                break;
            }
            Check_Landed(wk, Reaction & 0xFFF);
        }
        break;
    }
}




/* 2i 0601DEB6, 3s-near: sf3 src/Com_Sub.c:2969 Check_Rapid */
void Check_Rapid(PLW* wk, u16 Tech_Number) {
    if (!(Tech_Number & 0xF00)) {
        Rapid_No[wk->wu.id][0] = 0;
    } else {
        Lv = Setup_Lv08(0);
        if (Break_Into_CPU == 2) {
            Lv = 7;
        }
        Rapid_No[wk->wu.id][0] = Rapid_SA_Data[Lv][random_32_com() & 7];
        Rapid_No[wk->wu.id][1] = 0;
        Setup_Rapid_End_Term(wk, Tech_Number);
        Rapid_Index[wk->wu.id] = 0x7F0;
    }
}



/* 2i 0601DF56, 3s-near: sf3 src/Com_Sub.c:2986 Setup_Rapid_End_Term */
void Setup_Rapid_End_Term(wk, Tech_Number)
PLW* wk;
s16 Tech_Number;
{
    Rapid_No[wk->wu.id][2] = (Tech_Number & 0xF00) >> 8;
    if ((Tech_Number & 0xF00) == 0x400) {
        Rapid_No[wk->wu.id][3] = Setup_Rapid_Time(wk, Tech_Number);
    }
}



/* provisional name */
s32 Setup_Rapid_Time(wk, Tech_Number)
PLW* wk;
u16 Tech_Number;
{
    return 60;
}



/* 2i 0601DF94, 3s-near: sf3 src/Com_Sub.c:3008 Rapid_Sub */
void Rapid_Sub(PLW* wk) {
    if (Check_Rapid_End(wk) != 0) {
        return;
    }
    switch (Rapid_No[wk->wu.id][0]) {
    case 0:
        break;
    case 2:
        switch (Rapid_No[wk->wu.id][1]) {
        case 0:
            Rapid_No[wk->wu.id][1]++;
            Timer_00[wk->wu.id] = 1;
            Timer_01[wk->wu.id] = 3;
            return;
        case 1:
            if (--Timer_00[wk->wu.id] == 0) {
                Lever_Buff[wk->wu.id] = Rapid_Index[wk->wu.id];
                Timer_00[wk->wu.id] = 2;
                if (--Timer_01[wk->wu.id] == 0) {
                    Rapid_No[wk->wu.id][1]++;
                    Timer_01[wk->wu.id] = 0x18;
                }
            }
            break;
        case 2:
            if (--Timer_01[wk->wu.id] == 0) {
                Rapid_No[wk->wu.id][1]++;
                Timer_00[wk->wu.id] = 1;
                Timer_01[wk->wu.id] = 2;
            }
            break;
        default:
            if (--Timer_00[wk->wu.id] == 0) {
                Lever_Buff[wk->wu.id] = Rapid_Index[wk->wu.id];
                Timer_00[wk->wu.id] = Timer_01[wk->wu.id];
            }
            break;
        }
        break;
    default:
        switch (Rapid_No[wk->wu.id][1]) {
        case 0:
            Rapid_No[wk->wu.id][1]++;
            Timer_00[wk->wu.id] = 1;
            Timer_01[wk->wu.id] = 2;
            break;
        default:
            if (--Timer_00[wk->wu.id] == 0) {
                Lever_Buff[wk->wu.id] = Rapid_Index[wk->wu.id];
                Timer_00[wk->wu.id] = Timer_01[wk->wu.id];
            }
            break;
        }
        break;
    }
}



/* 2i 0601E132, 3s-near: sf3 src/Com_Sub.c:3067 Check_Rapid_End */
s32 Check_Rapid_End(PLW* wk) {
    switch (Rapid_No[wk->wu.id][2]) {
    case 1:
        if (wk->wu.mvxy.a[1].real.h < 0) {
            Rapid_No[wk->wu.id][0] = 0;
            return 1;
        }
        break;
    case 2:
        switch (Rapid_No[wk->wu.id][3]) {
        case 0:
            if (plw[wk->wu.id].caution_flag) {
                Rapid_No[wk->wu.id][3]++;
            }
            break;
        case 1:
            if (plw[wk->wu.id].caution_flag == 0) {
                Rapid_No[wk->wu.id][0] = 0;
                return 1;
            }
            break;
        }
        break;
    case 4:
        if (--Rapid_No[wk->wu.id][3] == 0) {
            Rapid_No[wk->wu.id][0] = 0;
            return 1;
        }
        break;
    }
    return 0;
}



/* 2i 0601E1F0, 3s-near: sf3 src/Com_Sub.c:3111 Check_Start_Command_Attack */
s32 Check_Start_Command_Attack(wk, Reaction, Tech_Number)
PLW* wk;
s16 Reaction;
u16 Tech_Number;
{
    if (Before_Jump[wk->wu.id]) {
        return Before_Jump[wk->wu.id] = 0;
    }
    if (wk->wu.routine_no[1] == 2) {
        return 1;
    }
    if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
        return 0;
    }
    if ((Tech_Number == 0) || (Tech_Number == 1)) {
        if (wk->wu.cg_cancel & 2) {
            return 0;
        }
        return 1;
    }
    if (Tech_Number & 0x8000) {
        if (wk->wu.cg_cancel & 0x40) {
            return 0;
        }
    }
    if (wk->wu.cg_cancel & 0x20) {
        return 0;
    }
    if ((wk->wu.cg_cancel & 8) && (Reaction == 0xE)) {
        return 0;
    }
    return 1;
}




/* 2i 0601E296, 3s-near: sf3 src/Com_Sub.c:3397 Jump_Command_Attack_Term */
void Jump_Command_Attack_Term(wk, Reaction, Tech_Number, Power_Level, Ex_Shot, RX, RY, Jump_Dir, JRX, JRY, JLD)
PLW* wk;
s16 Reaction;
u16 Tech_Number;
s16 Power_Level;
s16 Ex_Shot;
s16 RX;
s16 RY;
s16 Jump_Dir;
s16 JRX;
s16 JRY;
u16 JLD;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Continue_Menu[wk->wu.id] = 0;
            CP_Index[wk->wu.id][1]++;
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
            Check_First_Menu(wk);
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;
            Jump_Init(wk, Jump_Dir);
            Check_Rapid(wk, Tech_Number);
        }
        break;
    case 2:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    case 3:
        Lever_Buff[wk->wu.id] |= Air_Guard_Lever(wk);
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, JRX, JRY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        CP_Index[wk->wu.id][1] += 2;
        break;
    case 4:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    case 5:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Rapid_Sub(wk);
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
}



/* 2i 0601E5AA, 3s-near: sf3 src/Com_Sub.c:3494 Hi_Jump_Command_Attack_Term */
void Hi_Jump_Command_Attack_Term(wk, Reaction, Tech_Number, Power_Level, Ex_Shot, RX, RY, Jump_Dir, JRX, JRY, JLD)
PLW* wk;
s16 Reaction;
u16 Tech_Number;
s16 Power_Level;
s16 Ex_Shot;
s16 RX;
s16 RY;
s16 Jump_Dir;
s16 JRX;
s16 JRY;
u16 JLD;
{
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Hi_Jump(wk) == 0) {
            Continue_Menu[wk->wu.id] = 0;
            CP_Index[wk->wu.id][1]++;
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0x7FFF];
            Check_First_Menu(wk);
        }
        break;
    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id == 0]) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;
            Jump_Init(wk, Jump_Dir);
            Lever_Pool[wk->wu.id] &= 0xC;
            Lever_Buff[wk->wu.id] = 0;
            Check_Air_Guard(wk);
        }
        break;
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Lever_Buff[wk->wu.id] = 2;
        Lever_Pool[wk->wu.id] |= 1;
        break;
    case 3:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id] | 1;
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        break;
    case 4:
        Lever_Buff[wk->wu.id] |= Air_Guard_Lever(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, JRX, JRY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        CP_Index[wk->wu.id][1] += 2;
        break;
    case 5:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    case 6:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
}



/* 2i 0601E900, 3s-near: sf3 src/Com_Sub.c:3599 Check_Landed */
s32 Check_Landed(wk, Reaction)
PLW* wk;
s16 Reaction;
{
    if ((wk->wu.old_pos[1] != 0) && (wk->wu.xyz[1].disp.pos == 0)) {
        Lever_Buff[wk->wu.id] = 0;
        if (Continue_Menu[wk->wu.id]) {
            Next_End(wk);
            Before_Jump[wk->wu.id] = 1;
            return 1;
        } else {
            Reaction_Sub(wk, Reaction, 0);
            if (Check_Guard(wk) != 0) {
                return 1;
            }
            Before_Jump[wk->wu.id] = 1;
            return 1;
        }
    }
    if ((wk->wu.old_pos[1] == 0) && (wk->wu.xyz[1].disp.pos == 0) && (wk->wu.routine_no[1] != 4)) {
        Lever_Buff[wk->wu.id] = 0;
        if (Continue_Menu[wk->wu.id]) {
            Next_End(wk);
            Before_Jump[wk->wu.id] = 1;
            return 1;
        } else {
            Reaction_Sub(wk, Reaction, 0);
            if (Check_Guard(wk) != 0) {
                return 1;
            }
            Before_Jump[wk->wu.id] = 1;
            return 1;
        }
    }
    return 0;
}



/* 2i 0601E9BE, 3s-reloc: sf3 src/Com_Sub.c:3637 Check_Dash_Hit */
s32 Check_Dash_Hit(wk, Tech_Number)
PLW* wk;
u16 Tech_Number;
{
    WORK_Other* tmw;
    WORK* em;
    s16 i;
    s16 xx;
    s16 zz;
    if ((Tech_Number != 0) && (Tech_Number != 1)) {
        return 0;
    }
    em = (WORK*)wk->wu.target_adrs;
    for (i = 0; i < 8; i++) {
        if ((get_vs_shell_adrs(em, em->id, i, &tmw) == 0) && (get_vs_shell_adrs((WORK*)wk, em->id, i, &tmw) == 0)) {
            return 0;
        }
        if (tmw->wu.routine_no[1] == 2) {
            continue;
        }
        xx = wk->wu.xyz[0].disp.pos - tmw->wu.xyz[0].disp.pos;
        zz = Setup_Front_or_Back(wk, xx);
        if (Tech_Number == 0) {
            if (zz != 1) {
                if (Check_Hit_Shell(wk, tmw, Tech_Number) != 0) {
                    return 1;
                }
            }
        } else {
            if (zz != 0) {
                if (Check_Hit_Shell(wk, tmw, Tech_Number) != 0) {
                    return 1;
                }
            }
        }
    }
}



/* 2i 0601EA7A, 3s-reloc: sf3 src/Com_Sub.c:3677 Setup_Front_or_Back */
s32 Setup_Front_or_Back(wk, xx)
PLW* wk;
s16 xx;
{
    if (wk->wu.rl_waza == 0) {
        if (xx >= 0) {
            return 0;
        }
        return 1;
    } else {
        if (xx >= 0) {
            return 1;
        }
        return 0;
    }
}



/* 2i 0601EAB0, 3s-exact: sf3 src/Com_Sub.c:3696 Check_Hit_Shell */
s32 Check_Hit_Shell(wk, tmw, Tech_Number)
PLW* wk;
WORK_Other* tmw;
u16 Tech_Number;
{
    s16 xx;
    if (wk->wu.rl_waza == 1) {
        Tech_Number ^= 1;
    }
    if (Tech_Number == 0) {
        xx = wk->wu.xyz[0].disp.pos - Dash_Distance_Data[wk->player_number][Tech_Number];
        if (xx <= tmw->wu.xyz[0].disp.pos) {
            return 1;
        }
        return 0;
    } else {
        xx = wk->wu.xyz[0].disp.pos + Dash_Distance_Data[wk->player_number][Tech_Number];
        if (xx >= tmw->wu.xyz[0].disp.pos) {
            return 1;
        }
        return 0;
    }
}



/* 2i 0601EB08, 3s-reloc: sf3 src/Com_Sub.c:3722 Jump_Init */
void Jump_Init(wk, Jump_Dir)
PLW* wk;
s16 Jump_Dir;
{
    u16* a;
    u16* b;
    s32 i;

    a = Lever_Buff;
    b = Lever_Pool;
    switch (Jump_Dir) {
    case 0:
        Ck_Distance_LvJ(wk);
        i = wk->wu.id * 2;
        *(u16*)((s32)a + i) = *(u16*)((s32)b + i);
        break;
    case 2:
        b[wk->wu.id] = 1;
        a[wk->wu.id] = 1;
        break;
    default:
        Ck_Distance_LvJ(wk);
        b[wk->wu.id] ^= 0xC;
        i = wk->wu.id * 2;
        *(u16*)((s32)a + i) = *(u16*)((s32)b + i);
        break;
    }
}



/* 2i 0601EB80, 3s-near: sf3 src/Com_Sub.c:3753 Command_Type_00 */
s32 Command_Type_00(wk, Power_Level, Tech_Number, Ex_Shot)
PLW* wk;
s16 Power_Level;
u16 Tech_Number;
s16 Ex_Shot;
{
    if (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 4] != 0x1C) {
        Lever_Buff[wk->wu.id] = Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 3] & 0x7FFF;
        Lever_Buff[wk->wu.id] = datacmd_conpanecmd(Lever_Buff[wk->wu.id]);
        if (wk->wu.rl_waza) {
            if (Lever_Buff[wk->wu.id] & 0xC) {
                Lever_Buff[wk->wu.id] ^= 0xC;
            }
        }
        Tech_Index[wk->wu.id] += 4;
        return 1;
    } else {
        Lever_Buff[wk->wu.id] = Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 3] & 0x7FFF;
        if (wk->wu.rl_waza) {
            if (Lever_Buff[wk->wu.id] & 0xC) {
                Lever_Buff[wk->wu.id] ^= 0xC;
            }
        }
        if (Tech_Address[wk->wu.id][7] == 0x80) {
            return -1;
        }
        Tech_Index[wk->wu.id] = 7;
        if ((plw[wk->wu.id].sa->ex) && ((Ex_Shot == 0x70) || (Ex_Shot == 0x380))) {
            Lever_Buff[wk->wu.id] |= Ex_Shot;
        } else {
            Lever_Buff[wk->wu.id] |= renbanshot_conpaneshot(Tech_Address[wk->wu.id], Power_Level);
        }
        if ((My_char[wk->wu.id] == PL_RYU) && ((Tech_Number) == 0x8015) && (Power_Level != 8)) {
            CP_Index[wk->wu.id][0]++;
            Lever_LR[wk->wu.id] = Lever_Buff[wk->wu.id] & 0x7F0;
            if (Power_Level == 0xA) {
                CP_Index[wk->wu.id][1] = 1;
            } else {
                CP_Index[wk->wu.id][1] = 0;
            }
        } else {
            if (CP_No[wk->wu.id][0] == 0xA) {
                Rapid_Index[wk->wu.id] = Lever_Buff[wk->wu.id] & 0x7F0;
                Lever_Pool[wk->wu.id] = Lever_Buff[wk->wu.id] & 0x7F0;
            }
            if ((My_char[wk->wu.id] == PL_HUGO) && ((Tech_Number) == 0x8016)) {
                CP_Index[wk->wu.id][1] = 5;
            } else {
                CP_Index[wk->wu.id][1]++;
            }
        }
        return 0;
    }
}



/* 2i 0601EDD4, 3s-exact: sf3 src/Com_Sub.c:3814 Command_Type_06 */
s32 Command_Type_06(wk, Power_Level, Tech_Number, Ex_Shot)
PLW* wk;
s16 Power_Level;
u16 Tech_Number;
s16 Ex_Shot;
{
    s16 xx;
    xx = 0;
    if (Tech_Number & 0x8000) {
        if ((My_char[wk->wu.id] == PL_HUGO) && (Super_Arts[wk->wu.id] == 0)) {
            xx = 1;
        }
    }
    Lever_Buff[wk->wu.id] = Rolling_Lv_Data[xx][CP_Index[wk->wu.id][2]];
    CP_Index[wk->wu.id][2]++;
    if ((Rolling_Lv_Data[xx][CP_Index[wk->wu.id][2]]) == 0xFFFF) {
        Lever_Buff[wk->wu.id] |= renbanshot_conpaneshot(Tech_Address[wk->wu.id], Power_Level);
        return 1;
    }
    return 0;
}



/* 2i 0601EE88, 3s-near: sf3 src/Com_Sub.c:3838 Command_Type_01 */
s32 Command_Type_01(wk, Power_Level, Ex_Shot)
PLW* wk;
s16 Power_Level;
s16 Ex_Shot;
{
    switch (CP_Index[wk->wu.id][2]) {
    case 0:
        CP_Index[wk->wu.id][2]++;
        Timer_01[wk->wu.id] = Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 1] + 2;
        (&Lever_Pool[0])[wk->wu.id] = Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 3];
        Setup_Command_01(wk);
        if (wk->wu.rl_waza) {
            if (Lever_Pool[wk->wu.id] & 0xC) {
                Lever_Pool[wk->wu.id] ^= 0xC;
            }
        }
    case 1:
        if (wk->permited_koa & 2) {
            CP_Index[wk->wu.id][2]++;
        } else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Timer_00[wk->wu.id]++;
            break;
        }
    default:
        if (++Timer_00[wk->wu.id] < Timer_01[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        } else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Tech_Index[wk->wu.id] += 4;
            if (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]] == 0x1C) {
                return 1;
            }
        }
        break;
    }
    return 0;
}



/* 2i 0601F002, 3s-reloc: sf3 src/Com_Sub.c:3879 Setup_Command_01 */
void Setup_Command_01(PLW* wk) {
    switch (Lever_Pool[wk->wu.id]) {
    case 2:
        (&Timer_00[0])[wk->wu.id] = Lever_Store[wk->wu.id][0];
        break;
    default:
        (&Timer_00[0])[wk->wu.id] = Lever_Store[wk->wu.id][2];
        break;
    }
}



/* 2i 0601F06A, 3s-near: sf3 src/Com_Sub.c:3892 Check_Store_Lever */
void Check_Store_Lever(wk, Tech_Number, Next_Action, Next_Menu)
PLW* wk;
u16 Tech_Number;
s16 Next_Action;
s16 Next_Menu;
{
    s16 time;
    u16 lever;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
    time = Tech_Address[wk->wu.id][13] + 2;
    lever = Tech_Address[wk->wu.id][15];
    if (Check_Store_Direction(wk, lever, time) != 0) {
        CP_Index[wk->wu.id][0]++;
    } else {
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
}



/* 2i 0601F0F6, 3s-reloc: sf3 src/Com_Sub.c:3913 Check_Store_Direction */
s32 Check_Store_Direction(wk, lever, time)
PLW* wk;
u16 lever;
s16 time;
{
    if (wk->wu.rl_waza) {
        if (lever & 0xC) {
            lever ^= 0xC;
        }
    }
    switch (lever) {
    case 2:
        if (time <= Lever_Store[wk->wu.id][0]) {
            return 1;
        }
        break;
    case 8:
        if (time <= Lever_Store[wk->wu.id][1]) {
            return 1;
        }
        break;
    case 4:
        if (time <= Lever_Store[wk->wu.id][2]) {
            return 1;
        }
        break;
    }
    return 0;
}



/* 2i 0601F192, 3s-near: sf3 src/Com_Sub.c:3945 Select_Combo_Speed */
s32 Select_Combo_Speed(PLW* wk) {
    s8 xx;
    s8 zz;
    xx = (u8)random_32_com();
    Lv = Setup_Lv18(8);
    Lv += CC_Value[0];
    if (Break_Into_CPU == 2) {
        Lv = 0x13;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    if ((Break_Into_CPU == 1) || (Break_Into_CPU == 2)) {
        return zz = Combo_Speed_Unit_Data[16][Lv][xx];
    }
    return zz = Combo_Speed_Unit_Data[wk->player_number][Lv][xx];
}



/* 2i 0601F250, 3s-near: sf3 src/Com_Sub.c:3965 Select_Reflection_Time */
s32 Select_Reflection_Time(PLW* wk) {
    s8 Lv;
    s8 xx;
    s8 zz;
    xx = random_32_com();
    Lv = Setup_Lv18(Game_setting.level);
    Lv += CC_Value[0];
    if (Break_Into_CPU == 2) {
        Lv = 0x13;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    if ((Break_Into_CPU == 1) || (Break_Into_CPU == 2)) {
        return zz = Reflection_Time_Data[16][Lv][xx];
    }
    return zz = Reflection_Time_Data[wk->player_number][Lv][xx];
}



/* 2i 0601F2E2, 3s-reloc: sf3 src/Com_Sub.c:3986 Setup_Lv04 */
s32 Setup_Lv04(xx)
s16 xx;
{
    s16 i;
    s16* zz;
    zz = (s16*)(Lv04_Time_Data[CC_Type] + xx);
    for (i = 0; i < 3; i++) {
        if (Control_Time <= zz[i]) {
            return i;
        }
    }
    return 3;
}



/* 2i 0601F324, 3s-reloc: sf3 src/Com_Sub.c:4002 Setup_Lv08 */
s32 Setup_Lv08(xx)
s16 xx;
{
    s16 i;
    s16* zz;
    zz = (s16*)(Lv08_Time_Data[CC_Type] + xx);
    for (i = 0; i < 7; i++) {
        if (Control_Time <= zz[i]) {
            break;
        }
    }
    return i;
}



/* 2i 0601F390, 3s-reloc: sf3 src/Com_Sub.c:4018 Setup_Lv10 */
s32 Setup_Lv10(xx)
s16 xx;
{
    s16 i;
    s16* zz;
    zz = (s16*)(Lv10_Time_Data[CC_Type] + xx);
    for (i = 0; i < 9; i++) {
        if (Control_Time <= zz[i]) {
            break;
        }
    }
    return i;
}



/* 2i 0601F3D0, 3s-reloc: sf3 src/Com_Sub.c:4034 Setup_Lv18 */
s32 Setup_Lv18(xx)
s16 xx;
{
    s16 i;
    s16* zz;
    zz = (s16*)(Lv18_Time_Data[CC_Type] + xx);
    for (i = 0; i < 17; i++) {
        if (Control_Time <= zz[i]) {
            break;
        }
    }
    return i;
}




/* 2i 0601F412, 3s-near: sf3 src/Com_Sub.c:4063 Setup_LP_Data */
s32 Setup_LP_Data(PLW* wk) {
    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    return LOOK_POSITION_Data[Lv][random_32_com()];
}



/* 2i 0601F494, 3s-near: sf3 src/Com_Sub.c:4076 Setup_WT_Data */
s32 Setup_WT_Data(PLW* wk) {
    Lv = Setup_Lv04(0);
    if (Break_Into_CPU == 2) {
        Lv = 3;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    return Wait_Time_Data[Lv][random_16_com() & 7];
}



/* 2i 0601F4EA, 3s-near: sf3 src/Com_Sub.c:4089 Ck_Distance */
void Ck_Distance(PLW* wk) {
    PL_Distance[wk->wu.id] = ((WORK*)wk->wu.target_adrs)->xyz[0].disp.pos - wk->wu.xyz[0].disp.pos;
    if (PL_Distance[wk->wu.id] < 0) {
        PL_Distance[wk->wu.id] = PL_Distance[wk->wu.id] * -1;
    }
}



/* 2i 0601F51E, 3s-near: sf3 src/Com_Sub.c:4098 Ck_Distance_Height */
s32 Ck_Distance_Height(PLW* wk) {
    s16 xx;
    xx = ((WORK*)wk->wu.target_adrs)->xyz[1].disp.pos - wk->wu.xyz[1].disp.pos;
    if (xx < 0) {
        xx = -xx;
    }
    return xx;
}



s32 Ck_Area(PLW* wk) {
    s16 i;
    for (i = 0; i < 3; i++) {
        if (PL_Distance[wk->wu.id] <= Separate_Area[wk->wu.id][i]) {
            return i;
        }
    }
    return 3;
}



/* 2i 0601F534, 3s-reloc: sf3 src/Com_Sub.c:4121 Ck_Area_Shell */
s32 Ck_Area_Shell(PLW* wk) {
    s16 i;
    for (i = 0; i < 3; i++) {
        if (PL_Distance[wk->wu.id] <= Shell_Separate_Area[wk->wu.id][i]) {
            return i;
        }
    }
    return 3;
}



/* 2i 0601F5B8, 3s-near: sf3 src/Com_Sub.c:4133 Ck_Distance_Lv */
void Ck_Distance_Lv(PLW* wk) {
    PL_Distance[wk->wu.id] = ((WORK*)wk->wu.target_adrs)->xyz[0].disp.pos - wk->wu.xyz[0].disp.pos;
    if (PL_Distance[wk->wu.id] > 0) {
        Lever_Buff[wk->wu.id] = 8;
    } else {
        Lever_Buff[wk->wu.id] = 4;
        PL_Distance[wk->wu.id] = PL_Distance[wk->wu.id] * -1;
    }
}



/* 2i 0601F600, 3s-near: sf3 src/Com_Sub.c:4145 Ck_Distance_LvJ */
void Ck_Distance_LvJ(PLW* wk) {
    PL_Distance[wk->wu.id] = ((WORK*)wk->wu.target_adrs)->xyz[0].disp.pos - wk->wu.xyz[0].disp.pos;
    if (PL_Distance[wk->wu.id] > 0) {
        Lever_Pool[wk->wu.id] = 9;
    } else {
        Lever_Pool[wk->wu.id] = 5;
        PL_Distance[wk->wu.id] = PL_Distance[wk->wu.id] * -1;
    }
}



/* 2i 0601F648, 3s-near: sf3 src/Com_Sub.c:4157 Next_End */
s32 Next_End(PLW* wk) {
    if (Check_Guard(wk) != 0) {
        return 1;
    }
    CP_Index[wk->wu.id][0] = -1;
    CP_Index[wk->wu.id][1] = 0;
    CP_Index[wk->wu.id][2] = 0;
    CP_Index[wk->wu.id][3] = 0;
}



/* 2i 0601F69C, 3s-reloc: sf3 src/Com_Sub.c:4169 Next_Another_Menu */
void Next_Another_Menu(PLW* wk, s16 Next_Action, s16 Next_Menu) {
    if (Next_Action != 1) {
        CP_No[wk->wu.id][0] = Next_Action;
        Pattern_Index[wk->wu.id] = Next_Menu;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
    } else {
        Next_Be_Free(wk);
    }
}



/* 2i 0601F73C, 3s-near: sf3 src/Com_Sub.c:4184 Reaction_Sub */
void Reaction_Sub(wk, Reaction, Power_Level)
PLW* wk;
s16 Reaction;
s16 Power_Level;
{
    switch (Reaction & 0x7F) {
    case 9:
        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        } else if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Next_End(wk);
        }
        break;
    case 10:
        if ((Stock_Hit_Flag[wk->wu.id] >> 2) != 0) {
            Next_End(wk);
            break;
        }
        if (Stock_Hit_Flag[wk->wu.id] || wk->wu.routine_no[1] != 4 || wk->wu.cg_type == 0x40) {
            Reaction_Exit_Sub(wk);
        }
        break;
    case 11:
        if (plw[wk->wu.id].caution_flag) {
            break;
        }
        if (plw[wk->wu.id].tsukami_f) {
            break;
        }
        if ((Stock_Hit_Flag[wk->wu.id] >> 2) != 0) {
            Next_End(wk);
            break;
        }
        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        } else if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Next_End(wk);
        }
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        if ((Stock_Hit_Flag[wk->wu.id] >> 2) != 0) {
            Setup_Follow(wk, Reaction & 0xFFF);
            break;
        }
        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        } else if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Setup_Follow(wk, Reaction & 0xFFF);
        }
        break;
    case 12:
        Reaction_Exit_Sub(wk);
        Counter_Attack[wk->wu.id] = 1;
        break;
    case 14:
        Reaction_Exit_Sub(wk);
        Counter_Attack[wk->wu.id] = 1;
        break;
    case 13:
        if ((Stock_Hit_Flag[wk->wu.id] >> 2) != 0) {
            Next_End(wk);
            break;
        }
        if (wk->permited_koa & 0x10) {
            if (Check_Meoshi_Attack(wk, Reaction, Power_Level) != 0) {
                break;
            }
        }
        Last_Eftype[wk->wu.id] = -1;
        if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            if (Stock_Hit_Flag[wk->wu.id]) {
                if ((CP_No[wk->wu.id][0] == 6) && (Pattern_Index[wk->wu.id] == 0)) {
                    CP_No[wk->wu.id][0] = Return_CP_No[wk->wu.id];
                    CP_Index[wk->wu.id][0] = Return_CP_Index[wk->wu.id];
                    CP_Index[wk->wu.id][1] = 0;
                    CP_Index[wk->wu.id][2] = 0;
                    CP_Index[wk->wu.id][3] = 0;
                    Pattern_Index[wk->wu.id] = Return_Pattern_Index[wk->wu.id];
                } else {
                    Reaction_Exit_Sub(wk);
                }
            } else {
                Next_End(wk);
            }
        }
        break;
    default:
        if (plw[wk->wu.id].caution_flag) {
            break;
        }
        if (plw[wk->wu.id].tsukami_f) {
            break;
        }
        if (Stock_Hit_Flag[wk->wu.id] || (wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Reaction_Exit_Sub(wk);
        }
        break;
    }
}



/* 2i 0601FA8E, 3s-near: sf3 src/Com_Sub.c:4293 Check_Meoshi_Attack */
s32 Check_Meoshi_Attack(wk, Reaction, Power_Level)
PLW* wk;
s16 Reaction;
s16 Power_Level;
{
    if (Last_Eftype[wk->wu.id] == wk->wu.cg_meoshi) {
        return 0;
    }
    if (wk->permited_koa & 0x10) {
        Last_Eftype[wk->wu.id] = wk->wu.cg_meoshi;
        M_Lv[wk->wu.id] = Get_Meoshi_Data(wk);
        if ((s16)Pattern_Index[wk->wu.id] != 0) {
            Return_CP_No[wk->wu.id] = CP_No[wk->wu.id][0];
            Return_CP_Index[wk->wu.id] = CP_Index[wk->wu.id][0] + 1;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Return_Pattern_Index[wk->wu.id] = Pattern_Index[wk->wu.id];
        }
        CP_No[wk->wu.id][0] = 6;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Pattern_Index[wk->wu.id] = 0;
        return 1;
    }
    return 0;
}



/* 2i 0601FBAC, 3s-near: sf3 src/Com_Sub.c:4325 Get_Meoshi_Data */
s32 Get_Meoshi_Data(PLW* wk) {
    u16 lever;
    u16 shot;
    lever = get_meoshi_lever(wk->wu.cg_meoshi);
    shot = get_meoshi_shot(wk->wu.cg_meoshi);
    if (wk->wu.rl_flag) {
        lever ^= 0xC;
    }
    return shot | lever;
}



/* 2i 0601FC0C, 3s-exact: sf3 src/Com_Sub.c:4338 Reaction_Exit_Sub */
void Reaction_Exit_Sub(PLW* wk) {
    CP_Index[wk->wu.id][0]++;
    CP_Index[wk->wu.id][1] = 0;
    CP_Index[wk->wu.id][2] = 0;
    CP_Index[wk->wu.id][3] = 0;
    Flip_Flag[wk->wu.id] = 0;
    Counter_Attack[wk->wu.id] = 0;
    Limited_Flag[wk->wu.id] = 0;
    Before_Jump[wk->wu.id] = 0;
    if (CP_No[wk->wu.id][0] != 6) {
        Passive_Flag[wk->wu.id] = 0;
    }
}



/* provisional name */
/* 2i 0601FC80, 3s-reloc: sf3 src/Com_Sub.c:4355 Check_Stock_Hit_Menu */
s32 Check_Stock_Hit_Menu(wk, Menu)
PLW* wk;
s16 Menu;
{
    s32 hit;
    switch (Menu) {
    case 8:
        break;
    case 9:
        if (Stock_Hit_Flag[wk->wu.id] == 0) {
            return 1;
        }
        break;
    case 10:
        if (Stock_Hit_Flag[wk->wu.id] >> 2) {
            return 1;
        }
        break;
    case 11:
        if (Stock_Hit_Flag[wk->wu.id] >> 2) {
            return 1;
        }
        if (Stock_Hit_Flag[wk->wu.id] == 0) {
            return 1;
        }
        break;
    default:
        hit = Stock_Hit_Flag[wk->wu.id];
        if (hit == 0 || hit >> 2) {
            Setup_Follow(wk, Menu & 0xFFF);
            return -1;
        }
        break;
    }
    return 0;
}



/* 2i 0601FD38, 3s-reloc: sf3 src/Com_Sub.c:4394 Check_First_Menu */
void Check_First_Menu(PLW* wk) {
    if (CP_Index[wk->wu.id][0] == 0) {
        Combo_Speed[wk->wu.id] = 1;
    } else {
        Combo_Speed[wk->wu.id] = Select_Combo_Speed(wk);
    }
}



/* 2i 0601FD70, 3s-near: sf3 src/Com_Sub.c:4404 Select_Active */
void Select_Active(PLW* wk) {
    s16 pl_id;
    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    Rnd = (u8)random_32_ex_com();
    if (Check_SA_Active(wk, &pl_id) != 0) {
        Lv = Setup_Lv04(0);
        if (Break_Into_CPU == 2) {
            Lv = 3;
        }
        if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
            Lv = 2;
        }
        switch (Area_Number[wk->wu.id]) {
        case 0:
            Pattern_Index[wk->wu.id] = SA_Active_A_Unit_Data[pl_id - 1][Lv][Rnd];
            break;
        case 1:
            Pattern_Index[wk->wu.id] = SA_Active_B_Unit_Data[pl_id - 1][Lv][Rnd];
            break;
        case 2:
            Pattern_Index[wk->wu.id] = SA_Active_C_Unit_Data[pl_id - 1][Lv][Rnd];
            break;
        default:
            Pattern_Index[wk->wu.id] = SA_Active_D_Unit_Data[pl_id - 1][Lv][Rnd];
            break;
        }
    } else {
        switch (Area_Number[wk->wu.id]) {
        case 0:
            Pattern_Index[wk->wu.id] = Active_Area0_Data[wk->player_number][Lv][Rnd];
            Check_Bullet_Counter(wk);
            break;
        case 1:
            Pattern_Index[wk->wu.id] = Active_Area1_Data[wk->player_number][Lv][Rnd];
            Check_Bullet_Counter(wk);
            break;
        case 2:
            Pattern_Index[wk->wu.id] = Active_Area2_Data[wk->player_number][Lv][Rnd];
            Check_Bullet_Counter(wk);
            break;
        default:
            Pattern_Index[wk->wu.id] = Active_Area3_Data[wk->player_number][Lv][Rnd];
            Check_Bullet_Counter(wk);
            break;
        }
    }
}



/* provisional name */
/* 2i 0601FF7A, 3s-near: sf3 src/Com_Sub.c:4457 Check_Bullet_Counter */
void Check_Bullet_Counter(PLW* wk) {
    if (Bullet_No[wk->wu.id] != 0) {
        if (plw[wk->wu.id].bullet_hcnt == 0) {
            Bullet_No[wk->wu.id] = 0;
            Setup_Bullet_Counter(wk);
        } else {
            Pattern_Index[wk->wu.id] = 0;
            if (--Bullet_Counter[wk->wu.id] == 0) {
                Bullet_No[wk->wu.id] = 0;
                Setup_Bullet_Counter(wk);
            }
        }
        return;
    }
    if (plw[wk->wu.id].bullet_hcnt >= Bullet_Counter[wk->wu.id]) {
        Bullet_No[wk->wu.id] = 1;
        Bullet_Counter[wk->wu.id] = 5;
        Bullet_Counter[wk->wu.id] += random_32_com() & 3;
        Pattern_Index[wk->wu.id] = 0;
    }
}



/* 2i 06020072, 3s-near: sf3 src/Com_Sub.c:4481 Check_SA_Active */
s32 Check_SA_Active(wk, pl_id)
PLW* wk;
s16* pl_id;
{
    if (wk->sa->ok != -1) {
        return 0;
    }
    if (My_char[wk->wu.id] == PL_ORO) {
        if (plw[wk->wu.id].sa->kind_of_arts == 0) {
            return *pl_id = 3;
        }
        return *pl_id = 2;
    }
    if (My_char[wk->wu.id] == PL_YUN && plw[wk->wu.id].sa->kind_of_arts == 2) {
        return *pl_id = 1;
    }
    if (My_char[wk->wu.id] == 0xA && plw[wk->wu.id].sa->kind_of_arts == 2) {
        return *pl_id = 1;
    }
    return 0;
}



/* 2i 06020120, 3s-near: sf3 src/Com_Sub.c:4508 Setup_Follow */
void Setup_Follow(wk, Follow_Type)
PLW* wk;
s16 Follow_Type;
{
    CP_No[wk->wu.id][0] = 3;
    CP_No[wk->wu.id][1] = Follow_Type;
    if (wk->wu.hf.hit.player == 0) {
        CP_No[wk->wu.id][2] = 0;
    } else {
        CP_No[wk->wu.id][2] = 1;
    }
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = Select_Reflection_Time(wk);
    Timer_00[wk->wu.id]++;
}



/* 2i 060201BE, 3s-near: sf3 src/Com_Sub.c:4526 Decide_Follow_Menu */
void Decide_Follow_Menu(PLW* wk) {
    s8 xx;
    const FOLLOW_MENU_1ST* Menu_Add_Ptr0;
    const FOLLOW_MENU_2ND* Menu_Add_Ptr1;
    Menu_Add_Ptr0 = Follow_Menu_1st_Unit_Data[wk->player_number];
    Rnd = (u8)random_32_com();
    xx = Menu_Add_Ptr0->xxxx[CP_No[wk->wu.id][1]][CP_No[wk->wu.id][2]][Rnd];
    Menu_Add_Ptr1 = Follow_Menu_2nd_Unit_Data[wk->player_number];
    Pattern_Index[wk->wu.id] = Menu_Add_Ptr1->zzzz[xx][Area_Number[wk->wu.id]];
}



/* 2i 06020250, 3s-near: sf3 src/Com_Sub.c:4539 Select_Passive */
s32 Select_Passive(PLW* wk) {
    u16 xx;
    if (VS_Tech[wk->wu.id] == 0xB) {
        Area_Number[wk->wu.id] = Ck_Area_Shell(wk);
    }
    if (VS_Tech[wk->wu.id] == 0x1E) {
        Area_Number[wk->wu.id] = Ck_Area_Shell(wk);
    }
    Last_Attack_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
    Standing_Timer[wk->wu.id] = 0;
    Devide_Level(VS_Tech[wk->wu.id] >> 0xC);
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 1;
    }
    VS_Tech[wk->wu.id] &= 0xFFF;
    Setup_Random(wk);
    switch (Area_Number[wk->wu.id]) {
    case 0:
        xx = Passive_A_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];
        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][0] = 0x78;
            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][0] = 0;
        break;
    case 1:
        xx = Passive_B_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];
        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][1] = 0x78;
            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][1] = 0;
        break;
    case 2:
        xx = Passive_C_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];
        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][2] = 0x78;
            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][2] = 0;
        break;
    default:
        xx = Passive_D_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];
        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][3] = 0x78;
            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][3] = 0;
        break;
    }
    Passive_Flag[wk->wu.id] = 1;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = Select_Reflection_Time(wk);
    if ((VS_Tech[wk->wu.id] == 0x19) || (VS_Tech[wk->wu.id] == 0x13) || (Timer_00[wk->wu.id] == 0)) {
        CP_No[wk->wu.id][0] = 6;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
    } else {
        CP_No[wk->wu.id][0] = 5;
    }
    return 1;
}



/* 2i 0602057C, 3s-exact: sf3 src/Com_Sub.c:4620 Devide_Level */
void Devide_Level(xx)
s16 xx;
{
    switch (xx) {
    case 0:
        Lv = Setup_Lv04(0);
        if (Break_Into_CPU == 2) {
            Lv = 3;
        }
        break;
    default:
        Lv = Setup_Lv08(2);
        if (Break_Into_CPU == 2) {
            Lv = 7;
        }
        break;
    }
}



/* 2i 060205BC, 3s-reloc: sf3 src/Com_Sub.c:4641 Setup_Random */
void Setup_Random(PLW* wk) {
    if (VS_Tech[wk->wu.id] == 0x20) {
        Rnd = (u8)random_16_com() & 7;
        VS_Tech[wk->wu.id] = 0x1C;
    } else {
        Rnd = (u8)random_16_com();
        Rnd = Check_Dramatic(wk, wk->wu.id);
    }
}



/* 2i 06020630, 3s-near: sf3 src/Com_Sub.c:4653 Check_Dramatic */
s32 Check_Dramatic(wk, PL_id)
PLW* wk;
s16 PL_id;
{
    s32 rnd;
    s32 rnd8;
    if (rnd = Rnd, rnd8 = rnd | 8, plw[wk->wu.id].sa->ok) {
        return rnd8;
    }
    if ((plw[PL_id].wu.vital_new <= 0x30) || (plw[PL_id ^ 1].wu.vital_new <= 0x30)) {
        return rnd8;
    }
    return rnd;
}



/* 2i 0602068E, 3s-near: sf3 src/Com_Sub.c:4670 Check_Passive */
s32 Check_Passive(PLW* wk) {
    WORK* em;
    if ((Counter_Attack[wk->wu.id] != 0) || (Pierce_Menu[wk->wu.id])) {
        return 0;
    }
    em = (WORK*)wk->wu.target_adrs;
    if (Check_Blow_Off(wk, em, 0) != 0) {
        *CP_No[wk->wu.id] = 0xE;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        return -1;
    }
    if (Check_Shell(wk) != 0) {
        return 1;
    }
    if ((Passive_Flag[wk->wu.id]) || (Flip_Flag[wk->wu.id])) {
        return Check_Guard(wk);
    }
    if (Check_Lie(wk) == 1) {
        return 1;
    }
    if (PL_Status[em->routine_no[1]] == 0) {
        return Check_Shell(wk);
    }
    Passive_Mode = 4;
    if (Ck_Guard_Passive_Term(wk) != 0) {
        if (Select_Passive(wk) != -1) {
            return 1;
        }
    }
    if (Check_Guard(wk) != 0) {
        return 1;
    }
    if ((Passive_Flag[wk->wu.id]) || (Flip_Flag[wk->wu.id])) {
        return 0;
    }
    Passive_Mode = 0;
    if (Ck_Guard_Passive_Term(wk) != 0) {
        return Select_Passive(wk);
    }
    return 0;
}



/* 2i 060207D8, 2i only (provisional name): the passive term check by screen area */
s32 Ck_Guard_Passive_Term(PLW* wk) {
    switch (Area_Number[wk->wu.id]) {
    case 0:
        if (Ck_Passive_Term(wk)) {
            return 1;
        }
        return 0;
    case 1:
        if (Ck_Passive_Term(wk)) {
            return 1;
        }
        return 0;
    case 2:
        if (Ck_Passive_Term(wk)) {
            return 1;
        }
        return 0;
    default:
        if (Ck_Passive_Term(wk)) {
            return 1;
        }
        return 0;
    }
}



/* 2i 06020856, 3s-near: sf3 src/Com_Sub.c:4721 Check_Guard */
s32 Check_Guard(PLW* wk) {
    WORK* em;
    s16 xx;
    s16 zz;
    em = (WORK*)wk->wu.target_adrs;
    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }
    if (Guard_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
        return 0;
    }
    xx = Hit_Range_Data[em->hit_range];
    xx += Com_Width_Data[wk->wu.id];
    if (PL_Distance[wk->wu.id] > xx) {
        return 0;
    }
    Lv = Setup_Lv10(0);
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    Rnd = random_16_com();
    Lv += CC_Value[0];
    if (Break_Into_CPU == 2) {
        Lv = 0xA;
    }
    zz = Setup_EM_Rank_Index(wk);
    if (Guard_Data[zz][Lv][Rnd] == 3) {
        Guard_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
        return 0;
    }
    if (Check_Flip_Term(wk) != 0) {
        Next_Be_Flip(wk, 0);
    } else {
        Next_Be_Guard(wk, em, Guard_Data[zz][Lv][random_16_ex_com()]);
    }
    return 1;
}




/* 2i 060209EC, 3s-near: sf3 src/Com_Sub.c:4775 Check_Flip_Term */
s32 Check_Flip_Term(PLW* wk) {
    s16 xx;
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Flip_Tech(em) == 0) {
        return 0;
    }
    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    Rnd = random_32_com();
    Rnd -= Flip_Term_Correct(wk);
    xx = Setup_EM_Rank_Index(wk);
    if (Rnd >= (Flip_Data[xx][Lv])) {
        return 0;
    }
    return 1;
}



/* 2i 06020A7E, 3s-near: sf3 src/Com_Sub.c:4799 Setup_EM_Rank_Index */
s32 Setup_EM_Rank_Index(PLW* wk) {
    if (EM_Rank != 0) {
        return 0x10;
    } else {
        return wk->player_number;
    }
}



/* 2i 06020A92, 3s-near: sf3 src/Com_Sub.c:4809 Flip_Term_Correct */
s32 Flip_Term_Correct(PLW* wk) {
    s16 xx = 0;
    if (plw[wk->wu.id].wu.vital_new <= 0x30) {
        xx++;
    }
    if ((PL_Wins[wk->wu.id]) < (PL_Wins[wk->wu.id ^ 1])) {
        xx += 2;
    }
    if (Counter_hi < 0xF) {
        xx += 1;
    }
    return xx;
}



/* 2i 06020B0C, 3s-reloc: sf3 src/Com_Sub.c:4828 Next_Be_Guard */
void Next_Be_Guard(wk, em, Type_Of_Guard)
PLW* wk;
WORK* em;
s16 Type_Of_Guard;
{
    CP_No[wk->wu.id][0] = 7;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = 10;
    dash_flag_clear(wk->wu.id);
    Guard_Type[wk->wu.id] = Type_Of_Guard;
    Check_Guard_Type(wk, em);
}



/* 2i 06020B80, 3s-near: sf3 src/Com_Sub.c:4845 Check_Flip_Tech */
s32 Check_Flip_Tech(WORK* em) {
    if ((My_char[COM_id] != PL_GOUKI2) && (em->kind_of_waza & 0xF8)) {
        return 0;
    }
    if (em->kind_of_waza == 0) {
        return 0;
    }
    if (em->kind_of_waza == 1) {
        return 0;
    }
    return 1;
}



/* 2i 06020BBC, 3s-near: sf3 src/Com_Sub.c:4860 Next_Be_Flip */
void Next_Be_Flip(wk, xx)
PLW* wk;
s16 xx;
{
    WORK* em;
    em = (WORK*)wk->wu.target_adrs;
    CP_No[wk->wu.id][0] = 0xC;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = 9;
    Flip_Counter[wk->wu.id] = 0;
    if (xx) {
        if ((em->pat_status == 0x21) || (em->pat_status == 0x20)) {
            Lever_Buff[wk->wu.id] = 2;
        } else {
            Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 0);
        }
        CP_No[wk->wu.id][2] = 1;
        Timer_01[wk->wu.id] = xx;
    } else {
        Check_Flip_GO(wk, 0);
    }
}




/* 2i 06020CB6, 3s-reloc: sf3 src/Com_Sub.c:4950 Check_Shell */
s32 Check_Shell(PLW* wk) {
    WORK* em;
    WORK_Other* tmw;
    s16 i;
    s32 ix;
    s16 xx;
    if (Shell_Ignore_Timer[wk->wu.id]) {
        Shell_Ignore_Timer[wk->wu.id]--;
        return 0;
    }
    if (CP_No[wk->wu.id][0] == 8) {
        return 0;
    }
    em = (WORK*)wk->wu.target_adrs;
    for (i = 0; i < 8; i++) {
        if ((get_vs_shell_adrs(em, em->id, ix = i, &tmw) == 0) && (get_vs_shell_adrs(&wk->wu, em->id, ix, &tmw) == 0)) {
            return 0;
        }
        if (tmw->wu.routine_no[1] == 2) {
            continue;
        }
        if (wk->wu.rl_waza == tmw->wu.rl_flag) {
            continue;
        }
        if (tmw->wu.routine_no[0] != 1) {
            continue;
        }
        if (Check_Behind(wk, tmw)) {
            continue;
        }
        if (tmw->wu.charset_id == 2) {
            continue;
        }
        if (Check_Ignore_Shell(tmw)) {
            continue;
        }
        xx = Compute_Hit_Time(wk, tmw);
        if (Decide_Shell_Guard(wk, tmw)) {
            return 0;
        }
        CP_No[wk->wu.id][0] = 8;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Shell_Address[wk->wu.id] = (u32*)tmw;
        Guard_or_Jump_VS_Shell(wk, tmw, xx);
        return 1;
    }
}



/* 2i 06020E1C, 3s-near: sf3 src/Com_Sub.c:5006 Check_Ignore_Shell */
s32 Check_Ignore_Shell(WORK_Other* tmw) {
    if ((tmw->wu.type >= 0x24) && (tmw->wu.type <= 0x27)) {
        return 1;
    }
    if ((tmw->wu.type >= 0xD) && (tmw->wu.type <= 0xF)) {
        return 1;
    }
    if ((tmw->wu.type == 0x54) || (tmw->wu.type == 0x55)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x7A) && (tmw->wu.type <= 0x7E)) {
        return 1;
    }
    return 0;
}



/* 2i 06020E72, 3s-near: sf3 src/Com_Sub.c:5027 Compute_Hit_Time */
s32 Compute_Hit_Time(PLW* wk, WORK_Other* tmw) {
    s32 lx1;
    s16 x2;
    lx1 = wk->wu.xyz[0].cal - tmw->wu.xyz[0].cal;
    x2 = lx1 / tmw->wu.mvxy.a[0].sp;
    if (x2 < 0) {
        return (s16)(x2 * -1);
    }
    return x2;
}



/* 2i 06020EC4, 3s-near: sf3 src/Com_Sub.c:5042 Decide_Shell_Guard */
s32 Decide_Shell_Guard(PLW* wk, WORK_Other* tmw) {
    s16 xx;
    Lv = Setup_Lv10(0);
    if (Break_Into_CPU == 2) {
        Lv = 9;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    Rnd = random_32_com();
    xx = Setup_EM_Rank_Index(wk);
    if (Shell_Guard_Data[xx][Lv] > Rnd) {
        return 0;
    }
    Shell_Ignore_Timer[wk->wu.id] = 0x3C;
    return 1;
}



/* 2i 06020F4C, 3s-near: sf3 src/Com_Sub.c:5062 Guard_or_Jump_VS_Shell */
void Guard_or_Jump_VS_Shell(wk, tmw, xx)
PLW* wk;
WORK_Other* tmw;
s16 xx;
{
    if (xx <= Shell_Dodge_Data[0][wk->player_number]) {
        if (Check_Flip_Term(wk) != 0) {
            Pattern_Index[wk->wu.id] = 9;
        } else {
            Pattern_Index[wk->wu.id] = 0;
        }
    } else {
        Pattern_Index[wk->wu.id] = Decide_Shell_Reaction(wk, tmw, Shell_Reaction_Type_Data[tmw->wu.type]);
    }
    Setup_Shell_Disposal(wk, tmw);
}



/* 2i 06020FE8, 3s-exact: sf3 src/Com_Sub.c:5081 Setup_Shell_Disposal */
void Setup_Shell_Disposal(PLW* wk, WORK_Other* tmw) {
    switch (Pattern_Index[wk->wu.id]) {
    case 0:
        Next_Be_Shell_Guard(wk, &tmw->wu);
        break;
    case 9:
        Passive_Flag[wk->wu.id] = 1;
        break;
    case 10:
        Pattern_Index[wk->wu.id] = Decide_Shell_Reaction(wk, tmw, 0);
        if (Pattern_Index[wk->wu.id] != 0) {
            break;
        }
        Next_Be_Shell_Guard(wk, &tmw->wu);
        break;
    }
}




/* 2i 06021054, 3s-reloc: sf3 src/Com_Sub.c:5101 Next_Be_Shell_Guard */
void Next_Be_Shell_Guard(PLW* wk, WORK* tmw) {
    CP_No[wk->wu.id][0] = 9;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = 0xA;
    dash_flag_clear(wk->wu.id);
    Guard_Type[wk->wu.id] = 0;
    Check_Guard_Type(wk, tmw);
}



/* 2i 060210C6, 3s-near: sf3 src/Com_Sub.c:5114 Decide_Shell_Reaction */
s32 Decide_Shell_Reaction(wk, tmw, dir_step)
PLW* wk;
WORK_Other* tmw;
u16 dir_step;
{
    if (dir_step == 0xFF) {
        return 0;
    }
    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 4;
    }
    Rnd = random_16_com();
    return VS_Shell_Active_Data[wk->player_number][dir_step][Lv][Rnd];
}


/* provisional name */
/* 2i 06021170, 3s-exact: sf3 src/Com_Sub.c:5135 calc_abs_diff */
s32 calc_abs_diff(s16 a, s16 b) {
    a -= b;
    if (a < 0) {
        a = -a;
    }
    return a;
}



/* 2i 0602117E, 3s-reloc: sf3 src/Com_Sub.c:5145 Check_Behind */
s32 Check_Behind(PLW* wk, WORK_Other* tmw) {
    if (!wk->wu.rl_waza) {
        if (wk->wu.xyz[0].disp.pos < tmw->wu.xyz[0].disp.pos) {
            return 1;
        }
        return 0;
    }
    if (wk->wu.xyz[0].disp.pos > tmw->wu.xyz[0].disp.pos) {
        return 1;
    }
    return 0;
}



/* 2i 060211AA, 3s-near: sf3 src/Com_Sub.c:5160 Ck_Distance_XX */
s32 Ck_Distance_XX(PLW* wk) {
    if (Ck_Distance_Wall(wk) == 0) {
        return 0;
    }
    if (PL_Distance[wk->wu.id] >= Distance_XX_Data[wk->player_number][0] &&
        PL_Distance[wk->wu.id] <= Distance_XX_Data[wk->player_number][1]) {
        Distance_XX_Index[wk->wu.id] = Distance_XX_Data[wk->player_number][2];
        return 1;
    }
    return 0;
}



/* provisional name */
/* 2i 06021248, 3s-near: sf3 src/Com_Sub.c:5175 Ck_Distance_Wall */
s32 Ck_Distance_Wall(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    s16 xx;
    if (wk->wu.rl_waza) {
        xx = bg_w.bgw[1].r_limit2 + bg_w.pos_offset - em->xyz[0].disp.pos;
        if (xx <= 96) {
            return 0;
        }
    } else {
        xx = em->xyz[0].disp.pos - bg_w.bgw[1].l_limit2 + bg_w.pos_offset;
        if (xx <= 96) {
            return 0;
        }
    }
    return 1;
}



/* 2i 0602128C, 3s-near: sf3 src/Com_Sub.c:5194 Setup_Lever_LR */
void Setup_Lever_LR(wk, PL_id, Lever)
PLW* wk;
s16 PL_id;
s16 Lever;
{
    if (Lever == 0) {
        Lever_LR[PL_id] = 0;
    } else {
        if (Lever & 0x1000) {
            Lever_LR[PL_id] = 1;
        }
        else if (Lever & 0x2000) {
            Lever_LR[PL_id] |= 2;
        }
        if (Lever & 0x4000) {
            Lever_LR[PL_id] |= Setup_Guard_Lever(wk, 0);
        } else {
            if (Lever & 0x8000) {
                Lever_LR[PL_id] |= Setup_Guard_Lever(wk, 1);
            }
        }
    }
}



/* 2i 06021302, 3s-near: sf3 src/Com_Sub.c:5220 Check_Exit_Term */
s32 Check_Exit_Term(wk, em, Exit_No)
PLW* wk;
WORK* em;
s16 Exit_No;
{
    s16 xx;
    if (VS_Jump_Term(wk, em, &xx) != 0) {
        return xx;
    }
    return Exit_Term_Tbl[Exit_No](wk, em);
}



/* 2i 0602135C, 3s-reloc: sf3 src/Com_Sub.c:5234 VS_Jump_Term */
s32 VS_Jump_Term(wk, em, xx)
PLW* wk;
WORK* em;
s16* xx;
{
    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }
    switch (My_char[em->id]) {
    case PL_ALEX:
        if (Check_F_Cross_Chop(wk, em, 0xF) != 0) {
            return *xx = 3;
        }
        break;
    case PL_YUN:
    case PL_YANG:
        if (Check_Special_Technique(wk, em, 0, 0, 0x2b, -1, -1) != 0) {
            return *xx = 2;
        }
        break;
    case PL_NECRO:
        if (Check_Special_Technique(wk, em, 0, 0, 0x2A, -1, -1) != 0) {
            return *xx = 2;
        }
        if (Check_Limited_Jump_Attack(wk, em, 0x14, 4) != 0) {
            VS_Tech[wk->wu.id] = 0xF;
            return *xx = 3;
        }
        break;
    case PL_ELENA:
        if (Check_Limited_Jump_Attack(wk, em, 0x14, 5) != 0) {
            VS_Tech[wk->wu.id] = 0xF;
            return *xx = 3;
        }
        break;
    case PL_ORO:
        if (Check_Special_Technique(wk, em, 0xF, 8, 0x2C, 1, -1) != 0) {
            return *xx = 3;
        }
        break;
    }
    return 0;
}



/* 2i 0602146E, 3s-reloc: sf3 src/Com_Sub.c:5280 Exit_Term_0000 */
s32 Exit_Term_0000(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0x1E;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }
    return 0;
}


/* 2i 060214B6, 3s-exact: sf3 src/Com_Sub.c:5297 Exit_Term_0001 */
s32 Exit_Term_0001(PLW* wk, WORK* em) {
    return 1;
}



/* 2i 060214BA, 3s-exact: sf3 src/Com_Sub.c:5303 Exit_Term_0002 */
s32 Exit_Term_0002(PLW* wk, WORK* em) {
    if (em->routine_no[1] == 2) {
        return 1;
    }
    if (em->id != 0xD) {
        return 1;
    }
    return 0;
}



/* 2i 060214D6, 3s-reloc: sf3 src/Com_Sub.c:5315 Exit_Term_0003 */
s32 Exit_Term_0003(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0xA;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Check_SHINRYU(wk)) {
            return 0;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }
    return 0;
}



/* 2i 06021536, 3s-reloc: sf3 src/Com_Sub.c:5336 Exit_Term_0004 */
s32 Exit_Term_0004(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 1;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Check_SHINRYU(wk)) {
            return 0;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }
    return 0;
}



/* 2i 060215B6, 3s-reloc: sf3 src/Com_Sub.c:5357 Exit_Term_0005 */
s32 Exit_Term_0005(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 5;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Check_SHINRYU(wk)) {
            return 0;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }
    return 0;
}



/* 2i 06021616, 3s-reloc: sf3 src/Com_Sub.c:5378 Exit_Term_0006 */
s32 Exit_Term_0006(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0x3C;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Check_SHINRYU(wk)) {
            return 0;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }
    return 0;
}



/* 2i 06021676, 3s-reloc: sf3 src/Com_Sub.c:5399 Exit_Term_0007 */
s32 Exit_Term_0007(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0x1E;
    default:
        if (Check_Drop_Term(em, 0x28) != 0) {
            if (Area_Number[wk->wu.id] >= 3) {
                return 1;
            }
            VS_Tech[wk->wu.id] = 0x1A;
            return -1;
        }
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }
    return 0;
}




/* 2i 0602170C, 3s-reloc: sf3 src/Com_Sub.c:5441 Check_Drop_Term */
s32 Check_Drop_Term(em, Y)
WORK* em;
s16 Y;
{
    if (em->mvxy.a[1].real.h >= 0) {
        return 0;
    }
    if (em->xyz[1].disp.pos >= Y) {
        return 0;
    }
    return 1;
}



/* 2i 0602172C, 3s-near: sf3 src/Com_Sub.c:5456 Check_SHINRYU */
s32 Check_SHINRYU(PLW* wk) {
    PLW* em;
    em = (PLW*)wk->wu.target_adrs;
    if (em->sa->ok != -1) {
        return 0;
    }
    if (My_char[em->wu.id] != 0xB) {
        return 0;
    }
    if (plw[em->wu.id].sa->kind_of_arts != 1) {
        return 0;
    }
    return 1;
}



/* 2i 06021772, 3s-reloc: sf3 src/Com_Sub.c:5473 Check_BOSS */
void Check_BOSS(wk, Next_Action, Next_Menu)
PLW* wk;
u32 Next_Action;
s16 Next_Menu;
{
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Break_Into_CPU == 1) {
        Disposal_Again[wk->wu.id] = 1;
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
    } else {
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
}



/* 2i 060217E2, 3s-near: sf3 src/Com_Sub.c:5495 Check_BOSS_EX */
void Check_BOSS_EX(wk, Next_Action, Next_Menu)
PLW* wk;
u32 Next_Action;
s16 Next_Menu;
{
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Break_Into_CPU != 1) {
        Disposal_Again[wk->wu.id] = 1;
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
    } else {
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
}



/* 2i 06021878, 3s-reloc: sf3 src/Com_Sub.c:5517 ETC_Term */
void ETC_Term(wk, Exit_No, Next_Action, Next_Menu)
PLW* wk;
s16 Exit_No;
u32 Next_Action;
s16 Next_Menu;
{
    s16 xx;
    WORK* em = (WORK*)wk->wu.target_adrs;
    xx = ETC_Term_Tbl[Exit_No](wk, em);
    if (xx == -1) {
        return;
    }
    if (xx) {
        Disposal_Again[wk->wu.id] = 1;
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
    } else {
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
}



/* 2i 06021914, 3s-reloc: sf3 src/Com_Sub.c:5545 ETC_Term_0000 */
s32 ETC_Term_0000(PLW* wk, WORK* em) {
    if (Check_VS_Squat(wk, em, 0x1D, 0x21, 0x20) != 0) {
        return 1;
    }
    return 0;
}



/* 2i 06021936, 3s-near: sf3 src/Com_Sub.c:5554 ETC_Term_0001 */
s32 ETC_Term_0001(PLW* wk, WORK* em) {
    if (wk->sa->ok != -1) {
        return 1;
    }
    if (My_char[wk->wu.id] != PL_ORO) {
        return 1;
    }
    if (!plw[wk->wu.id].sa->kind_of_arts) {
        return 0;
    }
}



/* 2i 06021974, 3s-near: sf3 src/Com_Sub.c:5568 ETC_Term_0002 */
s32 ETC_Term_0002(PLW* wk, WORK* em) {
    if (plw[wk->wu.id].wu.vital_new <= 0x30) {
        return 1;
    }
    return 0;
}



/* 2i 060219C4, 3s-near: sf3 src/Com_Sub.c:5577 ETC_Term_0003 */
s32 ETC_Term_0003(PLW* wk, WORK* em) {
    if ((em->pat_status != 0x20) && (em->pat_status != 0x21) && (em->pat_status != 2)) {
        return 1;
    }
    return 0;
}



/* 2i 060219E6, 3s-near: sf3 src/Com_Sub.c:5586 ETC_Term_0004 */
s32 ETC_Term_0004(PLW* wk, WORK* em) {
    if (em->vital_new >= 0x50) {
        return 0;
    }
    if (plw[wk->wu.id].wu.vital_new < 0x78) {
        return 0;
    }
    return 1;
}



/* 2i 06021A18, 3s-near: sf3 src/Com_Sub.c:5598 ETC_Term_0005 */
s32 ETC_Term_0005(PLW* wk, WORK* em) {
    if (em->vital_new < plw[wk->wu.id].wu.vital_new) {
        return 1;
    }
    return 0;
}



/* 2i 06021A3C, 3s-near: sf3 src/Com_Sub.c:5607 ETC_Term_0006 */
s32 ETC_Term_0006(PLW* wk, WORK* em) {
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        Timer_00[wk->wu.id] = 0x78;
        /* fall through */
    case 1:
        if (--Timer_00[wk->wu.id] == 0) {
            return 1;
        }
        if (PL_Distance[wk->wu.id] < 0x70) {
            return 1;
        }
        Lever_Buff[wk->wu.id] = 0x40;
        return -1;
    default:
        break;
    }
}



s32 ETC_Term_0007(PLW* wk, WORK* em) {
    if (plw[wk->wu.id].sa->kind_of_arts != 2) {
        return 0;
    }
}

s32 ETC_Term_0008(PLW* wk) {
    if (plw[wk->wu.id].sa->kind_of_arts != 1) {
        return 0;
    }
}

/* 2i 06021AFC, 3s-near: sf3 src/Com_Sub.c:5641 ETC_Term_0009 */
s32 ETC_Term_0009(PLW* wk)
{
    if (plw[wk->wu.id].sa->kind_of_arts != 0) {
        return 0;
    }
}



/* provisional name */
/* 2i 06021B18, 3s-reloc: sf3 src/Com_Sub.c:5651 Setup_Com_Max_Range */
void Setup_Com_Max_Range(void) {
    s16 limit;
    s16 xx;
    const s16* row;
    u8 type = CC_Type;
    if (type == 2) {
        limit = Lv18_Time_Data[type][Game_setting.level][14] + 20;
    } else {
        limit = ((const s16*)&Lv18_Time_Data[type][Game_setting.level][0])[16] + 20;
    }
    if (type == 2) {
        xx = Lv18_Time_Data[type][8][14] + 20;
    } else {
        xx = Lv18_Time_Data[type][8][16] + 20;
    }
    if (limit < xx) {
        limit = xx;
    }
    if (type == 2) {
        xx = Lv10_Time_Data[type][0][7] + 20;
    } else {
        xx = Lv10_Time_Data[type][0][8] + 20;
    }
    if (limit < xx) {
        limit = xx;
    }
    xx = Lv08_Time_Data[type][0][6] + 20;
    if (limit < xx) {
        limit = xx;
    }
    xx = Lv08_Time_Data[type][1][6] + 20;
    if (limit < xx) {
        limit = xx;
    }
    row = Lv08_Time_Data[type][2];
    xx = row[6] + 20;
    if (limit < xx) {
        limit = xx;
    }
    xx = Lv04_Time_Data[type][0][2] + 20;
    if (limit < xx) {
        limit = xx;
    }
    Limit_Time = limit;
}



/* 2i 06021C28, 2i only: an empty routine nothing calls (provisional name) */
void Com_Sub_Dummy(void) {
}
