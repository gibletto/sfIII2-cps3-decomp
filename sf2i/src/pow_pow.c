/*
 * POW_POW.C  Damage and score (2i)
 *
 * cal_damage_vitality and cal_damage_vitality_eff turn an attack's power into damage using the
 * round-level rate tables (2i: no attack/defence multipliers); Additinal_Score_DM, Disp_Player_Score
 * and Score_Sub add to and display the players' scores (2i: six digits, capped at 9999900).
 * Disp_Player_Score_Debug (2i only, unreferenced) shows Score[id][1] on row 18 while exsw_3 bit 6 is set.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "Eff93.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "SYS_sub.h"
#include "end_main.h"
#include "EM_Cand.h"
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
#include "sc_clear.h"
#include "cmb_win.h"
#include "Eff95.h"
#include "EFFB8.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "EFF49.h"
#include "eff56.h"
#include "eff57.h"
#include "EFF58.h"
#include "Eff76.h"
#include "EFFA7.h"
#include "effa8.h"
#include "effa9.h"
#include "EFFL1.h"
#include "aboutspr.h"
#include "bg000.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "win_2.h"
#include "pow_pow.h"
#include "fighter.h"



/* 2i 0608CF98, 3s-near: sf3 src/pow_pow.c:72 cal_damage_vitality (2i: no att_plus/def_plus) */
void cal_damage_vitality(PLW* as, PLW* ds) {
    u16 xx = as->wu.att.pow;
    s16 yy;
    s16 power = Damage_Power_Data[xx];
    if (as->player_number == PL_GOUKI2) {
        yy = Pow_Control_Data_1[1][Round_Level];
    } else {
        yy = Pow_Control_Data_1[0][Round_Level];
    }
    ds->wu.dm_vital = power * yy / 100;
}



/* 2i 0608CFE8, 3s-near: sf3 src/pow_pow.c:94 cal_damage_vitality_eff (2i: no att_plus/def_plus) */
void cal_damage_vitality_eff(WORK_Other* as, PLW* ds) {
    u16 xx = as->wu.att.pow;
    s16 yy;
    s16 power = Damage_Power_Data[xx];
    if (((PLW*)as)->player_number == PL_GOUKI2) {
        yy = Pow_Control_Data_1[1][Round_Level];
    } else {
        yy = Pow_Control_Data_1[0][Round_Level];
    }
    ds->wu.dm_vital = power * yy / 100;
}

/* 2i 0608D038, 3s-near: sf3 src/pow_pow.c:114 Additinal_Score_DM (2i: cap 9999900, stage 16 test) */
void Additinal_Score_DM(wk, ix)
WORK_Other* wk;
u16 ix;
{
    s16 id;
    if (wk->wu.work_id == 1) {
        id = wk->wu.id;
    } else {
        if (((WORK*)wk->my_master)->work_id != 1) {
            return;
        }
        id = wk->master_id;
    }
    Score[id][2] += Score_Data[ix];
    if (plw[id].wu.operator) {
        if (Play_Type == 0) {
            Score[id][0] += Score_Data[ix];
            if (Score[id][0] >= 9999900) {
                Score[id][0] = 9999900;
            }
        } else {
            Score[id][1] += Score_Data[ix];
        }
    }
    if (plw[id].wu.operator != 0 && bg_w.stage != 16) {
        Disp_Player_Score(id);
    }
}



/* provisional name */
/* 2i 0608D11E, 3s-near: sf3 src/pow_pow.c:146 Disp_Player_Score (2i: six digits) */
void Disp_Player_Score(id)
s16 id;
{
    s16 digit[6];
    u32 score;
    s32 div;
    s16 top;
    s16 x;
    s16 i;
    score = Score[id][Play_Type];
    i = 5;
    div = 1000000;
    top = -1;
    while (i >= 1) {
        digit[i] = score / div;
        score -= digit[i] * div;
        if (top < 0) {
            if (digit[i]) {
                top = i;
            }
        }
        i--;
        div = div / 10;
    }
    x = Score_X_Pos_Data[id][Game_setting.mode] - top - 1;
    for (i = top; i >= 1; i--, x++) {
        score8x16_put(x, 0, 16, digit[i]);
    }
}



/* provisional name */
/* 2i 0608D2DE */
void Disp_Player_Score_Debug(id)
s16 id;
{
    s16 digit[6];
    u32 score;
    s32 div;
    s16 top;
    s16 x;
    s16 i;
    if (!(exsw_3 & 0x40)) {
        return;
    }
    score = Score[id][1];
    i = 5;
    div = 1000000;
    top = -1;
    while (i >= 0) {
        digit[i] = score / div;
        score -= digit[i] * div;
        if (top < 0) {
            if (digit[i]) {
                top = i;
            }
        }
        i--;
        div = div / 10;
    }
    x = Score_X_Pos_Data[id][Game_setting.mode] - top - 1;
    for (i = top; i >= 0; i--, x++) {
        score8x16_put(x, 18, 16, digit[i]);
    }
}



/* provisional name */
/* 2i 0608D4A0, 3s-near: sf3 src/pow_pow.c:179 Score_Sub */
void Score_Sub(void) {
    u16 num;
    u16 tens;
    if (plw[0].wu.operator != 0 && Demo_Flag != 0) {
        tilemap_clear_rect(Score_X_Pos_Data[0][Game_setting.mode] - 7, 0, Score_X_Pos_Data[0][Game_setting.mode], 1);
        Disp_Player_Score(0);
        tens = Continue_Coin[0];
        num = Continue_Coin[0];
        tens = tens / 10;
        score8x16_put(Score_X_Pos_Data[0][Game_setting.mode] - 1, 0, 16, tens);
        num -= tens * 10;
        score8x16_put(Score_X_Pos_Data[0][Game_setting.mode], 0, 16, num);
    }
    if (plw[1].wu.operator != 0 && Demo_Flag != 0) {
        tilemap_clear_rect(Score_X_Pos_Data[1][Game_setting.mode] - 7, 0, Score_X_Pos_Data[1][Game_setting.mode], 1);
        Disp_Player_Score(1);
        tens = Continue_Coin[1];
        num = Continue_Coin[1];
        tens = tens / 10;
        score8x16_put(Score_X_Pos_Data[1][Game_setting.mode] - 1, 0, 16, tens);
        num -= tens * 10;
        score8x16_put(Score_X_Pos_Data[1][Game_setting.mode], 0, 16, num);
    }
}
