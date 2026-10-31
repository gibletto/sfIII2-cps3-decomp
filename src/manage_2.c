/*
 * MANAGE_2.C  Round and match management (part 2)
 *
 * Game_Management is called every fight frame (Game2_1, Bonus_Sub) and steps through the C_No
 * phases: stage setup, round call and fight start, the fight, KO / time over judgement
 * (Judge_Winner, Check_Perfect, win marks via effect_92_init), winner display and win poses, score
 * pooling and bonuses (Pool_Score, Additional_Bonus), match end, continue and break-in handling
 * (Loser_Sub, Be_Continue, Quick_Entry, Check_Break_Into_CPU), and the bonus stage result tallies
 * (Game_Manage_12_x). It also runs BGM_Fade_Sub.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "manage_2.h"
#include "SYS_sub.h"
#include "aboutspr.h"
#include "EM_Cand.h"
#include "demo00.h"
#include "demo01.h"
#include "demo02_code.h"
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
#include "VITAL.h"
#include "count.h"
#include "spgauge.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "Eff93.h"
#include "EffG0.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "Eff81.h"
#include "effb2.h"
#include "Grade.h"
#include "appear.h"
#include "ta_sub.h"
#include "eff35.h"
#include "eff56.h"
#include "eff57.h"
s32 effect_58_init();
#include "Eff76.h"
#include "EFF84.h"
#include "bg000.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "end_main_c.h"
#include "Entry.h"
#include "entry_2.h"
#include "fighter.h"

/* C_No3, Game_Manage_12_4 */
#define CM12_4_T_BONUS  0       /* count up the bonus */
#define CM12_4_T_BONUS2 1       /* count up the bonus */
#define CM12_4_T_BONUS3 2       /* count up the bonus */

/* C_No2, Game_Manage_8_4 */
#define CM8_4_WAIT      0       /* count down C_Timer */
#define CM8_4_WAIT2     1       /* count down C_Timer */

/* C_No2, Game_Manage_12_3 */
#define CM12_3_WAIT     0       /* wait C_Timer; a button cuts it short */
#define CM12_3_MESSAGE  1       /* until the message is gone */
#define CM12_3_WAIT2    2       /* count down C_Timer */
#define CM12_3_WAIT3    3       /* wait C_Timer; a button cuts it short */

/* C_No2, Game_Manage_12_4 */
#define CM12_4_BONUS    0       /* count up the bonus */
#define CM12_4_BONUS2   1       /* count up the bonus */
#define CM12_4_BONUS3   2       /* count up the bonus */
#define CM12_4_BONUS4   3       /* count up the bonus */

/* C_No2, Game_Manage_12_5 */
#define CM12_5_WAIT     0       /* count down C_Timer */
#define CM12_5_WAIT2    1       /* count down C_Timer */

/* C_No2, Game_Manage_14_0 */
#define CM14_0_EFFECT   0       /* start effect 58, again each frame until it has a work */
#define CM14_0_FADE     1       /* request the fade */

/* C_No2, Game_Manage_14_2 */
#define CM14_2_WAIT     0       /* count down C_Timer */

/* C_No1, Game_Manage_6th */
#define CM6_VICTORY     0       /* until the win is shown */
#define CM6_WAIT        1       /* count down C_Timer */

/* C_No1, Game_Manage_9th */
#define CM9_JUDGE       0       /* match won: on to the next scene; otherwise the next round */
#define CM9_WAIT        1       /* count down C_Timer */

/* C_No1, Game_Manage_10th */
#define CM10_WAIT       0       /* wait C_Timer; a button cuts it short */
#define CM10_WIPE_WAIT  1       /* until the wipe is done */

/* C_No1, Game_Manage_11th */
#define CM11_START      0       /* start the screen's effects */
#define CM11_WAIT       1       /* count down C_Timer */
#define CM11_WIPE_WAIT  2       /* until the wipe is done */
#define CM11_WIPE_WAIT2 3       /* until the wipe is done */

/* C_No1, Game_Manage_12th */
#define CM12_NEXT_STEP  0       /* until Next_Step */
#define CM12_WIPE_WAIT  1       /* until the wipe is done */

/* BGM_No: the music fade-in (BGM_Fade_Sub) */
#define BGMF_NONE       0       /* nothing to do */
#define BGMF_WAIT       1       /* wait BGM_Timer, then (default) raise the volume */

void Scrn_Move_Set(s32 n, s16 x, s16 y);

void sound_reg_level_set(s16 pitch, s8 volume);




void Game_Manage_13th(void);
void Game_Manage_14th(void);
s32 Check_Special_Settle(void);
void Stock_Loser_Char(void);
extern const u16 bg_color3_tbl[];  /* provisional name */
#pragma inline(request_center_message)
void Game_Manage_8_4(void);
void Game_Manage_8_5(void);
void Game_Manage_82_0(void);
void Game_Manage_82_1(void);
void Game_Manage_82_2(void);
void Game_Manage_82_3(void);
void Game_Manage_82_4(void);
void Game_Manage_82_5(void);
void Game_Manage_82_6(void);
void Game_Manage_82_7(void);
void Game_Manage_82_8(void);
void Game_Manage_82_9(void);
void Disp_Perfect_Mark(void);
s32 Bonus_Cut_All(void);
void Bonus_Count_Effect(s16 n);
extern u8 Straight_Win_Count;  /* provisional name */
extern u8 Straight_Lose_Count;  /* provisional name */
s32 Check_Break_Into(s16 PL_id);
s32 Check_Ending_Special(void);
void Game_Manage_14_0(void);
void Game_Manage_14_1(void);
void Game_Manage_14_2(void);
s16 Next_VS_Index(void);
extern u16 End_Course;  /* provisional name */
extern s8 End_Gouki_Flag;  /* provisional name */
extern u8 Stock_Battle_Country[2];  /* provisional name */
extern const s8 rival_char_tbl[];



s32 Game_Management(void) {
    void (*Management_Jmp_Tbl[14])() = { Game_Manage_1st, Game_Manage_2nd, Game_Manage_3rd, Game_Manage_4th, Game_Manage_5th, Game_Manage_6th, Game_Manage_7th, Game_Manage_8th, Game_Manage_9th, Game_Manage_10th, Game_Manage_11th, Game_Manage_12th, Game_Manage_13th, Game_Manage_14th };
    if (Break_Into) {
        return 0;
    }
    MANAGE_X = 0;
    Management_Jmp_Tbl[C_No0]();
    BGM_Fade_Sub();
    return MANAGE_X;
}



void Game_Manage_1st(void) {
    EXE_obroll = 0;
    if (bg_w.stage == 16) {
        C_No0 = C0_BONUS;
    } else {
        C_No0 = C0_ROUND_START;
    }
    win_pause_go = 0;
    if (bg_w.bgw[1].zuubun) {
        zuubun_base_x = 0x200;
    }
    appear_work_clear();
    win_sp_flag = 0;
    BGM_No = BGMF_NONE;
    Shin_Gouki_BGM = 0;
    Special_Settle = 0;
    Clear_1Stage_Work();
    if (Play_Type == PLAY_VS_CPU) {
        Control_Time = SC_Personal_Time[Player_id];
        paring_ctr_ori[Player_id] = paring_ctr_vs[0][Player_id] = 0;
        Stage_Stock_Score[Player_id] = Score[Player_id][SCORE_CPU];
        if (My_char[COM_id] == PL_GOUKI2) {
            Break_Into_CPU = 15;
            EXE_obroll = 1;
        }
        if (My_char[COM_id] == PL_GOUKI1) {
            Break_Into_CPU = 14;
        }
    }
    eff_hit_flag_clear();
    Stage_BGM(Get_Stage_Shin_Gouki());
    Fade_Flag = 0;
}



void Clear_1Stage_Work(void) {
    s16 xx;
    xx = 0;
    do {
        Vital_Bonus[xx] = 0;
        Time_Bonus[xx] = 0;
        Perfect_Counter[xx] = 0;
        Stage_SA_Finish[xx] = 0;
        Stage_Lost_Round[xx] = 0;
        Stage_Perfect_Finish[xx] = 0;
        Stage_Cheap_Finish[xx] = 0;
        Stage_Judge_Finish[xx] = 0;
        Stage_Time_Finish[xx] = 0;
    } while (++xx < 2);
}



void Game_Manage_2nd(void) {
    void (*SC2_Jmp_Tbl[5])() = { Game_Manage_2_0, Game_Manage_2_1, Game_Manage_2_2, Game_Manage_2_3, Game_Manage_2_4 };
    SC2_Jmp_Tbl[C_No1]();
}



void Game_Manage_2_0(void) {
    request_message = 0;
    if (Demo_Flag == 0) {
        C_No1 = 2;
    } else {
        if (--Cover_Timer != 0) {
            return;
        }
        C_No1++;
        Switch_Screen_Init(3, 3);
    }
}



void Game_Manage_2_1(void) {
    if (Switch_Screen_Revival()) {
        C_No1++;
    }
}



void Game_Manage_2_2(void) {
    Suicide = 0;
    if (effect_84_init()) {
        return;
    }
    C_No1++;
    Forbid_Break = 0;
    Extra_Break = 0;
    Complete_Victory = 0;
    Conclusion_Flag = 0;
    Perfect_Flag = 0;
    Round_Result = 0;
    Reserve_Cut = 0;
    Next_Step = 0;
    Judge_Round_Flag = 0;
    Stop_Combo = 0;
    if (Demo_Flag) {
        Stop_SG = 0;
    }
    Complete_Judgement = 0;
    judge_flag = 0;
    Music_Fade = 0;
    Pause_Hit_Marks = 0;
    Round_Operator[0] = plw[0].wu.operator;
    Round_Operator[1] = plw[1].wu.operator;
    CP_No[0][0] = COM_INIT;
    CP_No[1][0] = COM_INIT;
    Stock_Score[0] = Score[0][SCORE_CPU];
    Stock_Score[1] = Score[1][SCORE_CPU];
}



void Game_Manage_2_3(void) {
    if (Appear_end < 2) {
        return;
    }
    if (bg_app) {
        return;
    }
    appear_work_clear();
    win_sp_flag = 0;
    if (pcon_rno[0] != PCON_INIT) {
        return;
    }
    if (pcon_rno[1] != APP_WAIT_READY) {
        return;
    }
    C_No1++;
    effect_B2_init();
}



void Game_Manage_2_4(void) {
    if (Next_Step != 0) {
        if (Check_Break_Into_CPU(Player_id)) {
            C_No0 = C0_BREAK_IN_CPU;
            C_No1 = 0;
            Forbid_Break = -1;
            Next_Step = 0;
            BGM_Stop();
            effect_A0_init(Player_id);
        } else {
            C_No0++;
            C_No1 = 0;
            Allow_a_battle_f = 1;
            load_char_eff_color(My_char[0], 0);
            load_char_eff_color(My_char[1], 1);
            if (Demo_Flag == 0) {
                effect_58_init(10, 60, -1);
            }
        }
    }
}



void Game_Manage_3rd(void) {
    if (Demo_Flag != 0 && Conclusion_Flag != 0) {
        C_No0++;
        Forbid_Break = -1;
        Allow_a_battle_f = 0;
        counter_color_clear();
        setFinishType();
        Special_Settle = Check_Special_Settle();
    }
}



void setFinishType(void) {
    if (Play_Type == PLAY_VS_PLAYER) {
        return;
    }
    if (Round_Operator[Winner_id] == 0) {
        Lost_Round[Loser_id]++;
        Stage_Lost_Round[Loser_id]++;
        return;
    }
    switch (Conclusion_Type) {
    case CONCLUSION_KO:
        break;
    case CONCLUSION_DOUBLE_KO:
        Lost_Round[Player_id]++;
        Stage_Lost_Round[Player_id]++;
        break;
    case CONCLUSION_TIME_OVER:
        if (plw[0].wu.vital_new != plw[1].wu.vital_new) {
            Stage_Time_Finish[Winner_id]++;
        } else {
            Stage_Judge_Finish[Winner_id]++;
        }
        break;
    }
    Update_BI_Term();
}



void Game_Manage_4th(void) {
    switch (Conclusion_Type) {
    case CONCLUSION_KO:
        C_No0 = C0_ROUND_WIN;
        Setup_Win_Mark();
        Check_Perfect(Winner_id);
        PL_Wins[Winner_id]++;
        Update_VS_Data();
        Ck_Win_Record();
        Update_Level_Control();
        break;
    case CONCLUSION_DOUBLE_KO:
        sound_request(143);
        if (Judge_Next_Disposal()) {
            C_No0 = C0_JUDGE;
            break;
        }
        C_No0 = C0_DRAW;
        Round_Result |= RESULT_DRAW;
        win_type[0][PL_Wins[0]] = WIN_MARK_DRAW;
        win_type[1][PL_Wins[1]] = WIN_MARK_DRAW;
        PL_Wins[0]++;
        PL_Wins[1]++;
        if (PL_Wins[0] >= Game_setting.Battle_Number + 1) {
            Winner_id = 0;
            Loser_id = 1;
        } else if (PL_Wins[1] >= Game_setting.Battle_Number + 1) {
            Winner_id = 1;
            Loser_id = 0;
        }
        Update_VS_Data();
        Ck_Win_Record();
        break;
    default:
        sound_request(156);
        if (plw[0].wu.vital_new != plw[1].wu.vital_new) {
            C_No0 = C0_ROUND_WIN;
            Round_Result |= RESULT_TIME;
            ROW_ELEM(win_type[Winner_id], PL_Wins[Winner_id]) = WIN_MARK_NORMAL;
            Check_Perfect(Winner_id);
            PL_Wins[Winner_id]++;
            Update_VS_Data();
            Ck_Win_Record();
            Update_Level_Control();
            break;
        }
        C_No0 = C0_JUDGE;
        break;
    }
}



void Setup_Win_Mark(void) {
    if (Round_Result & RESULT_CHIP) {
        win_type[Winner_id][PL_Wins[Winner_id]] = WIN_MARK_CHIP;
        sound_request(121);
        sound_request(143);
        Finish_SE();
        return;
    }
    if (Round_Result & 0x180) {
        Setup_BGM_Fade_In(150);
        sound_reg_level_set(0, -128);
        ROW_ELEM(win_type[Winner_id], PL_Wins[Winner_id]) = WIN_MARK_SA;
        sound_request(142);
        Finish_SE();
        return;
    }
    if (Round_Result & 0x800) {
        if (Shin_Gouki_BGM == 0) {
            Setup_BGM_Fade_In(150);
            sound_reg_level_set(0, -128);
        } else {
            Shin_Gouki_BGM = 0;
        }
        ROW_ELEM(win_type[Winner_id], PL_Wins[Winner_id]) = WIN_MARK_SA;
        sound_request(142);
        Finish_SE();
        return;
    }
    win_type[Winner_id][PL_Wins[Winner_id]] = WIN_MARK_NORMAL;
    sound_request(121);
    sound_request(143);
    Finish_SE();
}



void Update_BI_Term(void)
{
    if (Play_Type == PLAY_VS_PLAYER) {
        return;
    }
    if (plw[Winner_id].sa_healing) {
        Super_Arts_Finish[Winner_id]++;
        Stage_SA_Finish[Winner_id]++;
        return;
    }
    if (plw[Winner_id].wu.vitality == plw[Winner_id].wu.vital_new) {
        Perfect_Finish[Winner_id]++;
        Stage_Perfect_Finish[Winner_id]++;
        if (Round_Result & 0x980) {
            Super_Arts_Finish[Winner_id]++;
            Stage_SA_Finish[Winner_id]++;
        }
        return;
    }
    if (Round_Result & RESULT_CHIP) {
        Cheap_Finish[Winner_id]++;
        Stage_Cheap_Finish[Winner_id]++;
        return;
    }
    if (Round_Result & 0x980) {
        Super_Arts_Finish[Winner_id]++;
        Stage_SA_Finish[Winner_id]++;
    }
}



void Control_Music_Fade(s16 time)
{
    if (PB_Music_Off) {
        goto set;
    }
    BGM_No = BGMF_WAIT;
    BGM_Timer = time;
set:
    sound_reg_level_set(0, -128);
}



void Game_Manage_5th(void) {
    void (*SC5_Jmp_Tbl[8])() = { Game_Manage_5_0, Game_Manage_5_1, Game_Manage_5_2, Game_Manage_5_3, Game_Manage_5_4, Game_Manage_5_5, Game_Manage_5_6, Game_Manage_5_7 };
    SC5_Jmp_Tbl[C_No1]();
}



void Game_Manage_5_0(void) {
    if (Complete_Victory == 0) {
        return;
    }
    C_No1++;
    C_Timer = 30;
    Judge_Round_Flag = 1;
    Event_Judge_Gals = 0;
}



void Game_Manage_5_1(void) {
    if (Button_Cut_EX(&C_Timer, 10)) {
        C_No1++;
        request_center_message(3);
        sound_request(141);
        bgm_fade_out(182);
    }
}



void Game_Manage_5_2(void) {
    if (request_message) {
        return;
    }
    C_No1++;
    C_Timer = 30;
}



void Game_Manage_5_3(void) {
    if (Button_Cut_EX(&C_Timer, 10)) {
        C_No1++;
        Judge_Winner();
        sc_vram_to_ram();
        Stop_Combo = 1;
        Switch_Screen_Init(3, 3);
    }
}



void Game_Manage_5_4(void) {
    if (Switch_Screen()) {
        C_No1++;
        Switch_Screen_Init(3, 3);
        Cover_Timer = 5;
        reset_all_char_display_with_backup();
        judge_flag = 1;
        load_any_color_fade(bg_palette_no_tbl[bg_w.bg_index], 15, 15, 15);
        load_any_color_fade(bg_color2_tbl[bg_w.bg_index], 15, 15, 15);
        if (bg_w.bg_index) {
            load_any_color_fade(bg_color3_tbl[bg_w.bg_index - 1], 15, 15, 15);
        }
        pcon_rno[0] = PCON_INIT;
        pcon_rno[1] = APP_SETUP;
        pcon_rno[2] = 0;
        pcon_rno[3] = 0;
        appear_type = APPEAR_JUDGE;
    }
}



void Game_Manage_5_5(void) {
    if (--Cover_Timer == 0) {
        C_No1++;
        pcon_rno[1] = SETTLE_JUDGE;
        pcon_rno[2] = JG_WAIT;
        Clear_Flash_No();
        Switch_Screen_Init(3, 3);
    }
}



void Game_Manage_5_6(void) {
    if (Switch_Screen_Revival()) {
        C_No1++;
        C_Timer = 60;
        Stop_SG = 0;
        sound_request(7);
    }
}



void Game_Manage_5_7(void) {
    if (--C_Timer != 0) {
        return;
    }
    C_No0 = C0_ROUND_WIN;
    C_No1 = 7;
    C_Timer = 30;
    Fade_Half_Flag = 1;
    Complete_Judgement = 1;
    Round_Result |= RESULT_JUDGE;
    win_type[Winner_id][PL_Wins[Winner_id]] = WIN_MARK_JUDGE;
    Stage_Judge_Finish[Winner_id]++;
    Check_Perfect(Winner_id);
    PL_Wins[Winner_id]++;
    Update_VS_Data();
    Update_Level_Control();
}



void Game_Manage_6th(void) {
    switch (C_No1) {
    case CM6_VICTORY:
        if (Complete_Victory) {
            C_No1++;
            C_Timer = 60;
            pcon_rno[1] = SETTLE_JUDGE;
            pcon_rno[2] = JG_IDLE;
            effect_58_init(6, 1, Winner_id + 100);
            effect_92_init(0, win_type[0][PL_Wins[0] - 1]);
            effect_92_init(1, win_type[1][PL_Wins[1] - 1]);
        }
        break;
    case CM6_WAIT:
        if (--C_Timer != 0) {
            break;
        }
        C_No0 = C0_NEXT;
        C_No1 = CM6_VICTORY;
        Round_num++;
        Quick_Entry();
        break;
    }
}



void Game_Manage_7th(void) {
    void (*SC7_Jmp_Tbl[10])() = { Game_Manage_7_0, Game_Manage_7_1, Game_Manage_7_2, Game_Manage_7_3, Game_Manage_7_4, Game_Manage_7_5, Game_Manage_7_6, Game_Manage_7_7, Game_Manage_7_8, Game_Manage_7_9 };
    SC7_Jmp_Tbl[C_No1]();
}



void Game_Manage_7_0(void) {
    if (Complete_Victory) {
        C_No1++;
        C_Timer = 1;
        Stock_Loser_Char();
        effect_92_init(Winner_id, win_type[Winner_id][PL_Wins[Winner_id] - 1]);
        effect_58_init(6, 1, Winner_id + 100);
    }
}



void Game_Manage_7_1(void) {
    if (--C_Timer == 0) {
        C_No1++;
        C_Timer = 10;
    }
}



void Game_Manage_7_2(void) {
    if (!Button_Cut_EX(&C_Timer, 0x7FFF)) {
        return;
    }
    if (Check_Disp_Combo()) {
        C_Timer = 1;
        return;
    }
    C_No1++;
    if (Check_Disp_Winner() == 0) {
        C_Timer = 50;
    } else {
        Disp_Winner();
        C_Timer = 90;
    }
    if (Round_Operator[Winner_id] == 0 && Perfect_Flag == 0) {
        Check_Fade_Out_BGM(182);
    }
}



s32 Check_Disp_Combo(void) {
    if (PL_Wins[Winner_id] < Game_setting.Battle_Number + 1) {
        return 0;
    }
    if (cmb_all_stock != 0 || cmb_calc_now[0] != 0 || cmb_calc_now[1] != 0) {
        return 1;
    }
    return 0;
}



void Game_Manage_7_3(void) {
    if (Play_Type == PLAY_VS_CPU && Perfect_Flag == 0) {
        if (--C_Timer) {
            return;
        }
    } else {
        if (--C_Timer) {
            return;
        }
    }
    tilemap_clear_rect(DE_X[3] + 8, 9, DE_X[1] + 47, 16);
    if (Perfect_Flag) {
        C_No1++;
        C_Timer = 10;
    } else {
        C_No0++;
        C_No1 = 0;
        Event_Judge_Gals = -1;
    }
}



void Game_Manage_7_4(void) {
    if (--C_Timer == 0) {
        C_No1++;
        request_center_message(4);
        sound_request(138);
    }
}



void Game_Manage_7_5(void) {
    if (request_message) {
        return;
    }
    C_No1++;
    C_Timer = 6;
    Event_Judge_Gals = -1;
}



void Game_Manage_7_6(void) {
    if (Cut_Cut_Cut()) {
        C_Timer = 1;
    }
    if (--C_Timer == 0) {
        C_No0++;
        C_No1 = 0;
    }
}



void Game_Manage_7_7(void) {
    if (--C_Timer == 0) {
        C_No1++;
        Event_Judge_Gals = 3;
    }
}



void Game_Manage_7_8(void) {
    if (Event_Judge_Gals == 0) {
        C_No1++;
        C_Timer = 30;
        Ck_Win_Record();
    }
}



void Game_Manage_7_9(void) {
    if (--C_Timer == 0) {
        C_No1 = 0;
    }
}



void Stock_Loser_Char(void) {
    if (PL_Wins[WINNER] >= Game_setting.Battle_Number + 1) {
        if (Round_Operator[LOSER] != 0) {
            Win_Record[LOSER] = 0;
            Stock_My_char[LOSER] = My_char[LOSER];
            Stock_Player_Color[LOSER] = Player_Color[LOSER];
        }
    }
}



void Check_Fade_Out_BGM(s16 Time) {
    if (!Music_Fade) {
        if (PL_Wins[Winner_id] >= Game_setting.Battle_Number + 1) {
            Music_Fade = 1;
            bgm_fade_out(Time);
        }
    }
}



void Game_Manage_8th(void) {
    void (*SC8_Jmp_Tbl[6])() = { Game_Manage_8_0, Game_Manage_8_1, Game_Manage_8_2, Game_Manage_8_3, Game_Manage_8_4, Game_Manage_8_5 };
    SC8_Jmp_Tbl[C_No1]();
}



void Game_Manage_8_0(void) {
    Round_num++;
    Quick_Entry();
    if (Round_Operator[Winner_id]) {
        Pool_Score(Winner_id);
        if (Judge_Round_Flag) {
            bgm_fade_in_stage(180);
        }
        if (PL_Wins[Winner_id] >= Game_setting.Battle_Number + 1) {
            C_No1++;
            C_Timer = 7;
            Additional_Bonus(Winner_id);
            effect_58_init(11, 1, -1);
        } else {
            C_No1 = 5;
            C_Timer = 1;
        }
    } else {
        C_No1 = 5;
        C_Timer = 40;
        if (Judge_Round_Flag) {
            bgm_fade_in_stage(180);
        }
    }
}



void Game_Manage_8_1(void) {
    if (--C_Timer == 0) {
        C_No1++;
        C_No2 = 0;
        C_Timer = 1;
    }
}



void Game_Manage_8_2(void) {
    void (*SC82_Jmp_Tbl[10])() = { Game_Manage_82_0, Game_Manage_82_1, Game_Manage_82_2, Game_Manage_82_3, Game_Manage_82_4, Game_Manage_82_5, Game_Manage_82_6, Game_Manage_82_7, Game_Manage_82_8, Game_Manage_82_9 };
    SC82_Jmp_Tbl[C_No2]();
}



void Game_Manage_82_0(void) {
    if (Cut_Cut_Cut()) {
        if (Bonus_Cut_All()) {
            if (Judge_Round_Flag) {
                bgm_fade_in_stage(180);
            } else if (Perfect_Flag) {
                Check_Fade_Out_BGM(0x111);
            } else {
                Check_Fade_Out_BGM(0x222);
            }
        }
    } else {
        C_No2++;
        C_Timer = 20;
        sc_ram_to_vram_opc(20, Game_setting.Screen_Mode * 7, 0, 26);
        sc_ram_to_vram_opc(21, Game_setting.Screen_Mode * 7, 0, 26);
        sc_ram_to_vram_opc(22, Game_setting.Screen_Mode * 7, 0, 26);
        if (Judge_Round_Flag) {
            bgm_fade_out(0x222);
            bgm_fade_in_stage(180);
        }
    }
}



void Game_Manage_82_1(void) {
    if (Cut_Cut_Cut()) {
        if (Bonus_Cut_All()) {
            Check_Fade_Out_BGM(0x111);
        }
        return;
    }
    if (--C_Timer == 0) {
        C_No2++;
        C_Timer = 20;
        Disp_Digit16x24(Vital_Bonus[Winner_id], DE_X[3] + 35, 10, 26);
        sound_request(Winner_id + 102);
    }
}



void Game_Manage_82_2(void) {
    if (Cut_Cut_Cut()) {
        if (Bonus_Cut_All()) {
            Check_Fade_Out_BGM(0x111);
        }
        return;
    }
    if (--C_Timer == 0) {
        C_No2++;
        C_Timer = 20;
        Disp_Digit16x24(Time_Bonus[Winner_id], DE_X[3] + 35, 14, 26);
        sound_request(Winner_id + 102);
    }
}



void Game_Manage_82_3(void) {
    if (Cut_Cut_Cut()) {
        if (Bonus_Cut_All()) {
            Check_Fade_Out_BGM(0x111);
        }
        return;
    }
    if (--C_Timer == 0) {
        C_No2++;
        C_Timer = 20;
        Disp_Digit16x24(Complete_Bonus, DE_X[3] + 35, 18, 26);
        Disp_Perfect_Mark();
        sound_request(Winner_id + 102);
    }
}



void Game_Manage_82_4(void) {
    if (Cut_Cut_Cut()) {
        if (Bonus_Cut_All()) {
            Check_Fade_Out_BGM(0x111);
        }
        return;
    }
    if (--C_Timer == 0) {
        C_No2++;
        C_Timer = 9;
    }
}



void Game_Manage_82_5(void) {
    if (Button_Cut_EX(&C_Timer, 0x7FFF)) {
        if (Perfect_Flag) {
            C_No2++;
            C_Timer = 10;
        } else {
            C_No2 = 8;
            C_Timer = 10;
        }
    }
}



void Game_Manage_82_6(void) {
    if (Cut_Cut_Cut()) {
        if (Bonus_Cut_All()) {
            Check_Fade_Out_BGM(0x111);
        }
        return;
    }
    if (--C_Timer == 0) {
        C_No2++;
        C_Timer = 10;
        sc_ram_to_vram_opc(23, Game_setting.Screen_Mode * 7, 0, 26);
        Disp_Digit16x24(Vital_Bonus[Winner_id] + 40000, DE_X[3] + 35, 10, 26);
        sound_request(Winner_id + 102);
    }
}



void Disp_Perfect_Mark(void) {
    if (Perfect_Counter[Winner_id] == 0) {
        return;
    }
    Disp_PERFECT = 1;
    effect_99_init(77, 1, -1);
    effect_99_init(78, 1, Perfect_Counter[Winner_id]);
}



void Game_Manage_82_7(void) {
    if (Cut_Cut_Cut()) {
        if (Bonus_Cut_All()) {
            Check_Fade_Out_BGM(0x222);
        }
        return;
    }
    if (--C_Timer == 0) {
        C_No2++;
        C_Timer = 10;
        Disp_Digit16x24(Complete_Bonus, DE_X[3] + 35, 18, 26);
        sound_request(Winner_id + 102);
    }
}



void Game_Manage_82_8(void) {
    if (Button_Cut_EX(&C_Timer, 0x7FFF) && Cut_Cut_Cut()) {
        Bonus_Cut_All();
    }
    if (--C_Timer == 0) {
        C_No2++;
        C_Timer = 20;
        if (Perfect_Flag != 0) {
            C_Timer = 40;
            effect_89_init(4, 1, 10, DE_X[1] + 36, 3);
            effect_89_init(4, 1, 18, DE_X[1] + 36, 3);
        }
    }
}



void Game_Manage_82_9(void) {
    if (Perfect_Flag) {
        goto timer;
    }
    if (Button_Cut_EX(&C_Timer, 0x7FFF) && Cut_Cut_Cut()) {
        C_Timer = 1;
    }
timer:
    if (--C_Timer == 0) {
        Disp_Player_Score(Winner_id);
        Check_Fade_Out_BGM(0x222);
        C_No1++;
        C_Timer = 10;
    }
}



void Game_Manage_8_3(void) {
    if (Button_Cut_EX(&C_Timer, 110)) {
        Disp_PERFECT = 0;
        tilemap_clear_rect(1, 8, DE_X[1] + 47, 21);
        C_No0++;
        C_No1 = 0;
    }
}



void Game_Manage_8_4(void) {
    switch (C_No2) {
    case CM8_4_WAIT:
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 20;
            if (Perfect_Flag != 0) {
                effect_89_init(4, 1, 10, DE_X[1] + 36, 3);
                effect_89_init(4, 1, 18, DE_X[1] + 36, 3);
            }
        }
        break;
    case CM8_4_WAIT2:
        if (Perfect_Flag) {
        } else if (Cut_Cut_Cut()) {
            C_Timer = 1;
        }
        if (--C_Timer != 0) {
            break;
        }
        C_No1 = 3;
        C_Timer = 120;
        Disp_Player_Score(Winner_id);
        Check_Fade_Out_BGM(0x222);
        break;
    }
}



void Game_Manage_8_5(void) {
    if (Button_Cut_EX(&C_Timer, 50)) {
        C_No0++;
        C_No1 = 0;
    }
}



void Restore_Loser_Score(void) {
    if (Play_Type == PLAY_VS_PLAYER) {
        return;
    }
    if (PL_Wins[Winner_id] >= Game_setting.Battle_Number + 1) {
        return;
    }
    if (Round_Operator[Loser_id]) {
        Score[Loser_id][SCORE_CPU] = Stock_Score[Loser_id];
    }
}



s32 Check_Bonus_Skip(void) {
    if (Play_Type == PLAY_VS_CPU) {
        return 0;
    }
    if (Winner_id) {
        if (!(p2sw_0 & 0x7F0)) {
            return 0;
        }
    } else {
        if (!(p1sw_0 & 0x7F0)) {
            return 0;
        }
    }
    C_No0++;
    C_No1 = 0;
    C_No2 = 0;
    C_No3 = 0;
    Additional_Bonus(Winner_id);
    if (Judge_Round_Flag) {
        bgm_fade_in_stage(180);
    } else {
        Check_Fade_Out_BGM(0x222);
    }
    return 1;
}



s32 Bonus_Cut_All(void) {
    C_No1 = 4;
    C_No2 = 0;
    C_Timer = 20;
    if (Perfect_Flag) {
        sc_ram_to_vram_opc(23, Game_setting.Screen_Mode * 7, 0, 26);
        sc_ram_to_vram_opc(21, Game_setting.Screen_Mode * 7, 0, 26);
        sc_ram_to_vram_opc(22, Game_setting.Screen_Mode * 7, 0, 26);
        Disp_Perfect_Mark();
        Disp_Digit16x24(Vital_Bonus[Winner_id] + 40000, DE_X[3] + 35, 10, 26);
        Disp_Digit16x24(Time_Bonus[Winner_id], DE_X[3] + 35, 14, 26);
        Disp_Digit16x24(Complete_Bonus, DE_X[3] + 35, 18, 26);
        Bonus_Count_Effect(2);
    } else {
        sc_ram_to_vram_opc(20, Game_setting.Screen_Mode * 7, 0, 26);
        sc_ram_to_vram_opc(21, Game_setting.Screen_Mode * 7, 0, 26);
        sc_ram_to_vram_opc(22, Game_setting.Screen_Mode * 7, 0, 26);
        Disp_Perfect_Mark();
        Disp_Digit16x24(Vital_Bonus[Winner_id], DE_X[3] + 35, 10, 26);
        Disp_Digit16x24(Time_Bonus[Winner_id], DE_X[3] + 35, 14, 26);
        Disp_Digit16x24(Complete_Bonus, DE_X[3] + 35, 18, 26);
        Bonus_Count_Effect(1);
    }
    return 1;
}



void Bonus_Count_Effect(s16 n) {
    s16 i;
    s16 t;
    for (i = 0, t = 1; i < n; i++, t += 10) {
        effect_58_init(6, t, Winner_id + 102);
    }
}



void Pool_Score(s16 PL_id) {
    u32 Score_Buff;
    Score_Buff = plw[PL_id].wu.vital_new * 100 / Max_vitality;
    Score_Buff *= 600;
    if (Perfect_Flag) {
        Score_Buff += 40000;
    }
    Vital_Bonus[Winner_id] += Score_Buff;
    Time_Bonus[Winner_id] += *(s16*)&round_timer * 300;
}



const u32 Comp_Bonus_Data[11] = {
    30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000,
    110000, 120000, 130000,
};



void Additional_Bonus(s16 PL_id) {
    Complete_Bonus = Setup_Comp_Bonus();
    if (Time_Bonus[Winner_id] >= 48000) {
        Time_Bonus[Winner_id] += 30000;
    }
    Score[PL_id][Play_Type] += Vital_Bonus[Winner_id] + Time_Bonus[Winner_id];
    Score[PL_id][Play_Type] += Complete_Bonus;
    if (Score[PL_id][Play_Type] >= 9999900) {
        Score[PL_id][Play_Type] = 9999900;
    }
}



/* The bonus for a match won without losing a round: 30000 in versus play; against the CPU it grows
   by 10000 with each such win in a row (Straight_Counter), from 30000 to 130000, and a lost round
   starts it again. */
u32 Setup_Comp_Bonus(void) {
    u32 xx;
    u16 zz;
    if (Play_Type == PLAY_VS_PLAYER) {
        if (PL_Wins[Loser_id]) {
            return 0;
        }
        return 30000;
    }
    if (PL_Wins[Loser_id]) {
        return Straight_Counter[Winner_id] = 0;
    }
    Straight_Counter[Winner_id]++;
    if (Straight_Counter[Winner_id] >= 12) {
        Straight_Counter[Winner_id] = 11;
    }
    zz = Straight_Counter[Winner_id];
    xx = Comp_Bonus_Data[zz - 1];
    return xx;
}



void Game_Manage_9th(void) {
    switch (C_No1) {
    case CM9_JUDGE:
        if (PL_Wins[WINNER] >= Game_setting.Battle_Number + 1) {
            C_No0++;
            C_No1 = CM9_JUDGE;
            C_Timer = 75;
            sc_vram_to_ram();
            if (Play_Type == PLAY_VS_PLAYER) {
                card_win_check(0);
                Stock_My_char[LOSER] = My_char[LOSER];
                Stock_Player_Color[LOSER] = Player_Color[LOSER];
            } else if (Round_Operator[WINNER]) {
                card_win_check(0);
                SC_Personal_Time[WINNER] = Control_Time;
                Stage_Continue[WINNER] = 0;
                if (Special_Settle) {
                    C_No0 = C0_SPECIAL;
                    C_No2 = 0;
                    C_No3 = 0;
                    return;
                }
                if (Check_Break_Into(WINNER)) {
                    C_No0 = C0_BREAK_IN;
                }
            } else {
                Win_Record[LOSER] = 0;
                Straight_Counter[LOSER] = 0;
                Stock_My_char[LOSER] = My_char[LOSER];
                Stock_Player_Color[LOSER] = Player_Color[LOSER];
            }
        } else {
            C_No1++;
            if (bg_w.stage == 8 && bg_w.area == 0) {
                C_Timer = 150;
            } else {
                C_Timer = 60;
            }
            satime_stock_clear();
            sc_vram_to_ram();
            Stop_Combo = 1;
            BGM_Timer = 1;
        }
        break;
    case CM9_WAIT:
        if (!(bg_w.stage == 8 && bg_w.area == 0) && Cut_Cut_Cut()) {
            C_Timer = 1;
        }
        if (--C_Timer > 0) {
            return;
        }
        C_No1++;
        Game_pause = 1;
        Switch_Screen_Init(3, 3);
    default:
        if (Switch_Screen()) {
            if (bg_w.stage == 8 && bg_w.area == 0) {
                G_No2 = G2_ROUND_RESET;
                Cover_Timer = 10;
            } else {
                G_No2 = G2_ROUND_RESET2;
                Cover_Timer = 5;
            }
            G_No3 = 0;
            G_Timer = 4;
            C_No0 = C0_ROUND_START;
            C_No1 = C_No2 = C_No3 = 0;
            Suicide = 1;
        }
        break;
    }
}



void Game_Manage_10th(void) {
    switch (C_No1) {
    case CM10_WAIT:
        if (Button_Cut_EX(&C_Timer, 0x7FFF)) {
            C_No1++;
            Cover_Timer = 25;
            sc_vram_to_ram();
            Stop_Combo = 1;
            Game_pause = 1;
            Switch_Screen_Init(3, 3);
        }
        break;
    case CM10_WIPE_WAIT:
        if (Switch_Screen()) {
            effect_work_quick_init();
            SE_All_Off();
            Check_Naming(0);
            Check_Naming(1);
            pcon_rno[0] = PCON_INIT;
            pcon_rno[1] = APP_SETUP;
            pcon_rno[2] = 0;
            pcon_rno[3] = 0;
            appear_type = APPEAR_ENTRY;
            Continue_Coin2[WINNER] = 0;
            if (Round_Operator[WINNER]) {
                G_No1 = G1_WINNER;
                G_No2 = 0;
                G_No3 = 0;
                M_No0 = 0;
                M_No1 = 0;
                M_No2 = 0;
                M_No3 = 0;
                E_No0 = E0_WINNER;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
                Straight_Lose_Count = 0;
                if (++Straight_Win_Count == 0) {
                    Straight_Win_Count = 0xFF;
                }
                if (Check_Ending_Special() == 0) {
                    Check_Ending();
                }
                Continue_Coin2[WINNER] = 0;
                Clear_Flash_No();
            } else {
                G_No1 = G1_LOSER;
                G_No2 = 0;
                G_No3 = 0;
                M_No0 = 0;
                M_No1 = 0;
                M_No2 = 0;
                M_No3 = 0;
                E_No0 = E0_LOSER;
                E_No1 = 0;
                E_No2 = 0;
                E_No3 = 0;
                E_07_Flag[0] = 0;
                E_07_Flag[1] = 0;
                Straight_Win_Count = 0;
                if (++Straight_Lose_Count == 0) {
                    Straight_Lose_Count = 0xFF;
                }
                Clear_Flash_No();
            }
        }
        break;
    }
}



void Game_Manage_11th(void) {
    switch (C_No1) {
    case CM11_START:
        Forbid_Break = -1;
        C_No1++;
        C_Timer = 150;
        EM_Rank = 2;
        effect_56_init(1);
        effect_A2_init(1);
        BGM_Request(6);
        break;
    case CM11_WAIT:
        if (--C_Timer == 0) {
            C_No1++;
            Switch_Screen_Init(0, 2);
        }
        break;
    case CM11_WIPE_WAIT:
        if (Switch_Screen()) {
            C_No1++;
            tilemap_clear_rect(DE_X[3], Text_Page_Y + 11, DE_X[3] + 47, Text_Page_Y + 13);
            sc_vram_to_ram();
            Switch_Screen_Init(3, 1);
        }
        break;
    case CM11_WIPE_WAIT2:
        if (Switch_Screen()) {
            G_No1 = G1_NEXT_CPU;
            G_No2 = G2_NEXT_INIT;
            G_No3 = 0;
            E_No0 = E0_NEXT_CPU;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            effect_work_quick_init();
            Cover_Timer = 21;
        }
        break;
    }
}



void Check_Naming(id)
s16 id;
{
    if (Game_setting.Event) {
        return;
    }
    if (E_Number[id][0] != ENTRY_NAME) {
        Rank_In[id][RANK_SCORE] = -1;
        Rank_In[id][RANK_WINS] = -1;
    }
}



void Game_Manage_12th(void) {
    switch (C_No1) {
    case CM12_NEXT_STEP:
        if (Next_Step) {
            C_No1++;
            sc_vram_to_ram();
            Switch_Screen_Init(3, 1);
        }
        break;
    case CM12_WIPE_WAIT:
        if (Switch_Screen()) {
            G_No1 = G1_NEXT_CPU;
            G_No2 = G2_NEXT_INIT;
            G_No3 = 0;
            E_No0 = E0_NEXT_CPU;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            Break_Into_CPU = 14;
            gouki_app = 0;
            effect_work_quick_init();
            Cover_Timer = 21;
        }
        break;
    }
}



void Game_Manage_13th(void) {
    void (*SC13_Jmp_Tbl[6])() = { Game_Manage_12_0, Game_Manage_12_1, Game_Manage_12_7, Game_Manage_12_3, Game_Manage_12_4, Game_Manage_12_5 };
    SC13_Jmp_Tbl[C_No1]();
}



void Game_Manage_12_0(void) {
    Suicide = 0;
    if (effect_84_init()) {
        return;
    }
    C_No1++;
    Forbid_Break = 0;
    Extra_Break = 0;
    request_message = 0;
    Complete_Victory = 0;
    Conclusion_Flag = 0;
    Perfect_Flag = 0;
    Round_Result = 0;
    Reserve_Cut = 0;
    Next_Step = 0;
    Judge_Round_Flag = 0;
    Stop_Combo = 0;
    if (Demo_Flag) {
        Stop_SG = 0;
    }
    Complete_Judgement = 0;
    judge_flag = 0;
    Music_Fade = 0;
    win_sp_flag = 0;
    Round_Operator[0] = plw[0].wu.operator;
    Round_Operator[1] = plw[1].wu.operator;
    CP_No[0][0] = COM_INIT;
    CP_No[1][0] = COM_INIT;
    Stock_Score[0] = Score[0][SCORE_CPU];
    Stock_Score[1] = Score[1][SCORE_CPU];
    load_any_color(179);
}



void Game_Manage_12_1(void) {
    if (Next_Step == 0) {
        return;
    }
    C_No1++;
    Allow_a_battle_f = 1;
    load_char_eff_color(My_char[0], 0);
    load_char_eff_color(My_char[1], 1);
}



void Game_Manage_12_7(void) {
    if (Bonus_Game_Complete) {
        C_No1++;
        C_No2 = 0;
        C_Timer = 30;
        Forbid_Break = -1;
        Completion_Bonus[Player_id] = -128;
        Stock_Bonus_Game_Result = Bonus_Game_result;
        Bonus_Score = 0;
        Final_Bonus_Score = Setup_Final_Score();
        ToneDown(8);
        ToneDown(9);
        effect_58_init(6, 10, 169);
        if (Check_Bonus_Perfect()) {
            C_Timer = 20;
        } else {
            C_No1 = 4;
        }
    }
}



void Game_Manage_12_3(void) {
    switch (C_No2) {
    case CM12_3_WAIT:
        if (Cut_Cut_C_Timer() == 0) {
            C_No2++;
            C_Timer = 10;
            request_center_message(4);
            sound_request(138);
            return;
        }
        break;
    case CM12_3_MESSAGE:
        if (request_message == 0) {
            C_No2++;
            C_Timer = 6;
        }
        break;
    case CM12_3_WAIT2:
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 20;
            ToneDown(8);
            ToneDown(9);
            return;
        }
        break;
    case CM12_3_WAIT3:
        if (Cut_Cut_C_Timer() == 0) {
            C_No1++;
            C_No2 = CM12_3_WAIT;
            C_No3 = 0;
            C_Timer = 30;
        }
        break;
    }
}



const u32 Ball_Perfect_PTS[2][5] = {
    { 20000, 30000, 50000, 80000, 120000 },
    { 10000, 20000, 40000, 80000, 160000 },
};



void Game_Manage_12_4(void) {
    switch (C_No2) {
    case CM12_4_BONUS:
        if (Bonus_Cut_Sub() != 0) {
            break;
        }
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 20;
            sc_ram_to_vram_opc(27, Game_setting.Screen_Mode * 7, 0, 26);
            Disp_Digit16x24(Bonus_Score, DE_X[3] + 35, 11, 26);
        }
        break;
    case CM12_4_BONUS2:
        if (Bonus_Cut_Sub() != 0) {
            break;
        }
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 1;
            Bonus_Score = 0;
        }
        break;
    case CM12_4_BONUS3:
        if (Bonus_Cut_Sub() != 0) {
            break;
        }
        if (--C_Timer == 0) {
            if (Bonus_Game_result == 0 && !(PB_Status & 2)) {
                C_No2 = 4;
                C_Timer = 30;
                break;
            }
            if (Bonus_Game_result == 0) {
                Bonus_Game_result = 1;
            } else {
                Bonus_Score += 1000;
                Score[Player_id][SCORE_CPU] += 1000;
                Disp_Digit16x24(Bonus_Score, DE_X[3] + 35, 11, 26);
                Sound_SE(100);
            }
            if (--Bonus_Game_result == 0) {
                C_No2++;
                if (PB_Status) {
                    C_No3 = CM12_4_T_BONUS2;
                    C_Timer = 10;
                } else {
                    C_No3 = CM12_4_T_BONUS;
                    C_Timer = 20;
                }
                break;
            }
            C_Timer = 3;
        }
        break;
    case CM12_4_BONUS4:
        switch (C_No3) {
        case CM12_4_T_BONUS:
            if (Bonus_Cut_Sub() != 0) {
                break;
            }
            if (--C_Timer == 0) {
                C_No2++;
                C_Timer = 30;
                Bonus_Game_result = Stock_Bonus_Game_Result;
            }
            break;
        case CM12_4_T_BONUS2:
            if (Bonus_Cut_Sub() != 0) {
                break;
            }
            if (--C_Timer == 0) {
                C_No3++;
                C_Timer = 10;
                Disp_Bonus_Perfect();
            }
            break;
        case CM12_4_T_BONUS3:
            if (Bonus_Cut_Sub() != 0) {
                break;
            }
            if (--C_Timer == 0) {
                C_No3++;
                C_Timer = 40;
                if (PB_Status & 1) {
                    Score[Player_id][SCORE_CPU] += Ball_Perfect_PTS[0][Bonus_Stage_Level];
                }
                if (PB_Status & 2) {
                    Score[Player_id][SCORE_CPU] += Ball_Perfect_PTS[1][Bonus_Stage_Level];
                }
                if (Score[Player_id][SCORE_CPU] >= 9999900) {
                    Score[Player_id][SCORE_CPU] = 9999900;
                }
                Flash_Bonus_Perfect();
            }
            break;
        default:
            if (--C_Timer == 0) {
                C_No2++;
                C_Timer = 30;
            }
            break;
        }
        break;
    default:
        if (Cut_Cut_C_Timer() == 0) {
            C_No1++;
            C_No2 = CM12_4_BONUS;
            C_No3 = 0;
            C_Timer = 10;
            tilemap_clear_rect(1, 8, DE_X[1] + 47, 21);
            Check_Fade_Out_BGM(0x222);
        }
        break;
    }
}



void Game_Manage_12_5(void) {
    switch (C_No2) {
    case CM12_5_WAIT:
        if (--C_Timer == 0) {
            C_No2++;
            C_Timer = 20;
        }
        break;
    case CM12_5_WAIT2:
        if (Cut_Cut_Cut()) {
            C_Timer = 1;
        }
        if (--C_Timer == 0) {
            C_No2++;
        }
        break;
    default:
        MANAGE_X = 1;
        break;
    }
}



s32 Check_Bonus_Perfect(void) {
    PB_Status = 0;
    if (Stock_Bonus_Game_Result >= 20) {
        PB_Status |= 1;
    }
    if (Bonus_Game_ex_result >= 20) {
        PB_Status |= 2;
    }
    return PB_Status;
}



void Disp_Bonus_Perfect(void) {
    switch (PB_Status) {
    case 1:
        sc_ram_to_vram_opc(23, Game_setting.Screen_Mode * 7, 5, 26);
        Disp_Digit16x24(Ball_Perfect_PTS[0][Bonus_Stage_Level], DE_X[3] + 35, 15, 26);
        break;
    case 2:
        sc_ram_to_vram_opc(23, Game_setting.Screen_Mode * 7, 5, 0);
        Disp_Digit16x24(Ball_Perfect_PTS[1][Bonus_Stage_Level], DE_X[3] + 35, 15, 0);
        break;
    case 3:
        sc_ram_to_vram_opc(23, Game_setting.Screen_Mode * 7, 5, 26);
        Disp_Digit16x24(Ball_Perfect_PTS[0][Bonus_Stage_Level], DE_X[3] + 35, 15, 26);
        sc_ram_to_vram_opc(23, Game_setting.Screen_Mode * 7, 9, 0);
        Disp_Digit16x24(Ball_Perfect_PTS[1][Bonus_Stage_Level], DE_X[3] + 35, 19, 0);
        break;
    }
    sound_request(Winner_id + 102);
}



void Flash_Bonus_Perfect(void) {
    switch (PB_Status) {
    case 1:
        effect_89_init(4, 1, 15, DE_X[1] + 36, 3);
        break;
    case 2:
        effect_89_init(9, 1, 15, DE_X[1] + 36, 3);
        break;
    case 3:
        effect_89_init(4, 1, 15, DE_X[1] + 36, 3);
        effect_89_init(9, 1, 19, DE_X[1] + 36, 3);
        break;
    }
}



u32 Setup_Final_Score(void) {
    u32 xx;

    xx = Bonus_Game_result * 1000;
    if (Stock_Bonus_Game_Result >= 20) {
        xx += Ball_Perfect_PTS[0][Bonus_Stage_Level];
    }
    if (Bonus_Game_ex_result >= 20) {
        xx += Ball_Perfect_PTS[1][Bonus_Stage_Level];
    }
    xx += Score[Player_id][COM_id];
    if (xx >= 9999900) {
        xx = 9999900;
    }
    return xx;
}



s32 Bonus_Cut_Sub(void) {
    if (Cut_Cut_Cut()) {
        Sound_SE(100);
        Bonus_Game_result = 0;
        Score[Player_id][SCORE_CPU] += Final_Bonus_Score;
        if (Score[Player_id][SCORE_CPU] >= 9999900) {
            Score[Player_id][SCORE_CPU] = 9999900;
        }
        sc_ram_to_vram_opc(27, Game_setting.Screen_Mode * 7, 0, 26);
        Disp_Digit16x24(Stock_Bonus_Game_Result * 1000, DE_X[3] + 35, 11, 26);
        Disp_Bonus_Perfect();
        Flash_Bonus_Perfect();
        C_No2 = 3;
        C_No3 = 99;
        return C_Timer = 90;
    }
    return 0;
}



void Game_Manage_14th(void) {
    void (*SC14_Jmp_Tbl[3])() = { Game_Manage_14_0, Game_Manage_14_1, Game_Manage_14_2 };
    SC14_Jmp_Tbl[C_No1]();
}



void Game_Manage_14_0(void) {
    switch (C_No2) {
    case CM14_0_EFFECT:
        if (effect_58_init(12, 10, -1) == -1) {
            break;
        }
        C_No2++;
        Next_Step = 0;
        break;
    case CM14_0_FADE:
        if (Request_Fade(stage_index_get(), 0)) {
            C_No2++;
            Game_pause = 1;
            Forbid_Break = -1;
            EXE_obroll = 1;
        }
        break;
    default:
        if (Check_Fade_Complete_SP()) {
            C_No1++;
            Game_pause = 0;
        }
        break;
    }
}



void Game_Manage_14_1(void) {
    if (Next_Step) {
        C_No1++;
        C_No2 = 0;
        C_Timer = 90;
        Stage_BGM(15);
    }
}



void Game_Manage_14_2(void) {
    switch (C_No2) {
    case CM14_2_WAIT:
        if (--C_Timer == 0) {
            C_No2++;
            Game_pause = 1;
            satime_stock_clear();
            sc_vram_to_ram();
            Stop_Combo = 1;
            BGM_Timer = 1;
            Switch_Screen_Init(3, 3);
        }
        break;
    default:
        if (Switch_Screen()) {
            G_No2 = G2_ROUND_RESET2;
            G_No3 = 0;
            G_Timer = 4;
            C_No0 = C0_ROUND_START;
            C_No1 = 0;
            C_No2 = CM14_2_WAIT;
            C_No3 = 0;
            bg_stop = 0;
            Round_num = 0;
            Shin_Gouki_BGM = 1;
            PL_Wins[0] = 0;
            PL_Wins[1] = 0;
            Clear_Win_Type();
            win_mark_ram_clear();
            My_char[COM_id] = PL_GOUKI2;
            Break_Into_CPU = 15;
            Player_Color[COM_id] = COM_id;
            EM_Candidate[Player_id][7] = 15;
            Clear_1Stage_Work();
            Stock_Battle_Country[Player_id] = Battle_Country;
            Cover_Timer = 5;
            Suicide = 1;
            bg_w.area--;
            win_mark_all_write(0);
            win_mark_all_write(1);
            player_face_default_set(COM_id);
        }
        break;
    }
}



void Ck_Win_Record(void) {
    s16 w;
    s16 l;
    if (Play_Type == PLAY_VS_PLAYER) {
        if (PL_Wins[0] >= Game_setting.Battle_Number + 1 || PL_Wins[1] >= Game_setting.Battle_Number + 1) {
            if (PL_Wins[0] >= Game_setting.Battle_Number + 1) {
                w = 0;
                l = 1;
            } else {
                w = 1;
                l = 0;
            }
            if (++Win_Record[w] <= 99) {
                Disp_Win_Record_Sub(w);
                Erase_Win_Record(l);
            } else {
                Win_Record[w] = 99;
            }
        }
    }
}



void Disp_Win_Record_Sub(PL_id)
s16 PL_id;
{
    s16 zz;
    s16 xx;
    s16 Wins_Buff;
    if (PL_id) {
        zz = DE_X[12] + 42;
    } else {
        zz = 5;
    }
    switch (Win_Record[PL_id]) {
    case 1:
        tilemap_print_string_attr(zz, Text_Page_Y, 40, "WIN");
        break;
    default:
        tilemap_print_string_attr(zz, Text_Page_Y, 40, "WINS");
        break;
    }
    xx = Win_Record[PL_id] / 10;
    if (xx > 0) {
        tilemap_print_hex_block(zz - 3, Text_Page_Y, 40, (s8)xx, 1, 1);
    }
    Wins_Buff = Win_Record[PL_id] % 10;
    tilemap_print_hex_block(zz - 2, Text_Page_Y, 40, (s8)Wins_Buff, 1, 1);
}



void Disp_Win_Record(void) {
    s16 x;
    s16 pl;
    s16 digit;
    s16 num;
    if (Play_Type != PLAY_VS_PLAYER) {
        return;
    }
    if (Win_Record[0] == 0 && Win_Record[1] == 0) {
        return;
    }
    if (Win_Record[0]) {
        pl = 0;
    } else {
        pl = 1;
    }
    if (pl) {
        x = DE_X[12] + 42;
    } else {
        x = 5;
    }
    if (Win_Record[Winner_id] > 1) {
        tilemap_print_string_attr(x, 0, 40, "WINS");
    } else {
        tilemap_print_string_attr(x, 0, 40, "WIN");
    }
    digit = Win_Record[pl] / 10;
    if (digit > 0) {
        tilemap_print_hex_block(x - 3, 0, 40, (s8)digit, 1, 1);
    }
    num = Win_Record[pl] % 10;
    tilemap_print_hex_block(x - 2, 0, 40, (s8)num, 1, 1);
}



void Erase_Win_Record(PL_id)
s16 PL_id;
{
    s16 x;
    if (Win_Record[PL_id] != 0) {
        if (PL_id) {
            x = DE_X[12] + 39;
        } else {
            x = 2;
        }
        tilemap_print_string_attr(x, Text_Page_Y, 40, "       ");
        Win_Record[PL_id] = 0;
    }
}



s32 Check_Disp_Winner(void) {
    if (PL_Wins[Winner_id] >= Game_setting.Battle_Number + 1) {
        return Disp_Win_Name = 1;
    }
    if (Conclusion_Type == CONCLUSION_KO) {
        return Disp_Win_Name = 0;
    }
    return Disp_Win_Name = 1;
}



void Disp_Winner(void) {
    if (Play_Type == PLAY_VS_PLAYER) {
        winner_name_put(My_char[Winner_id]);
        effect_89_init(1, DE_X[3] + 10, 9, 29, 4);
        sound_request(155);
    } else {
        if (Round_Operator[Winner_id] != 0) {
            sc_picture_put(5, 0, 0);
            effect_89_init(1, DE_X[3] + 11, 9, 25, 4);
            sound_request(155);
        } else {
            sc_picture_put(6, 0, 0);
            effect_89_init(2, DE_X[3] + 11, 9, 24, 4);
            sound_request(154);
        }
    }
}



void Update_Level_Control(void) {
    if (Round_Operator[Winner_id]) {
        if (!Round_Operator[Loser_id]) {
            Control_Time += 40;
            if (Control_Time > Limit_Time) {
                Control_Time = Limit_Time;
                return;
            }
        }
    } else {
        if ((Control_Time -= 30) < 0) {
            Control_Time = 0;
        }
    }
}



void complete_victory_pause(void)
{
    Complete_Victory = 1;
}



void request_center_message(s16 Kind_of_Message) {
    request_message = 1;
    message_index = Kind_of_Message;
}



s32 Judge_Next_Disposal(void) {
    if (PL_Wins[0] != PL_Wins[1]) {
        return 0;
    }
    if (PL_Wins[0] >= Game_setting.Battle_Number) {
        return 1;
    }
    return 0;
}



void Check_Perfect(s16 PL_id) {

    if (plw[PL_id].wu.vitality == plw[PL_id].wu.vital_new) {
        Perfect_Flag = 1;
        Perfect_Counter[Winner_id]++;
        Round_Result |= RESULT_PERFECT;
        win_type[PL_id][PL_Wins[PL_id]] = WIN_MARK_PERFECT;
    }
}



void Judge_Winner(void) {
    if (Score[0][SCORE_ROUND] == Score[1][SCORE_ROUND]) {
        if (Play_Type == PLAY_VS_CPU) {
            Winner_id = Player_id;
            Loser_id = COM_id;
        } else {
            Winner_id = Champion;
            Loser_id = Champion ^ 1;
        }
    } else if (Score[0][SCORE_ROUND] > Score[1][SCORE_ROUND]) {
        Winner_id = 0;
        Loser_id = 1;
    } else {
        Winner_id = 1;
        Loser_id = 0;
    }
}



s32 Check_Ending(void) {
    s16 i;
    if (Play_Type == PLAY_VS_PLAYER) {
        return 0;
    }
    Last_VS_Index[WINNER] = Next_VS_Index();
    if (Last_VS_Index[WINNER] > 7) {
        G_No1 = G1_ENDING;
        G_No2 = G2_END_INIT;
        E_No0 = E0_ENDING;
        End_PL = plw[WINNER].player_number;
        plw[WINNER].wu.operator = 0;
        Operator_Status[WINNER] = 0;
        sound_reg_level_set(0, 0);
        End_Course = EM_Course[WINNER];
        End_Gouki_Flag = Break_Com[WINNER][14];
        Control_Time = 481;
        Ending_init();
        Stock_My_char[WINNER] = My_char[WINNER];
        Stock_Player_Color[WINNER] = Player_Color[WINNER];
        for (i = 0; i < 16; i++) {
            ROW_ELEM(Break_Com[WINNER], i) = 0;
        }
        return 1;
    }
    return 0;
}



s32 Check_Ending_Special(void) {
    s16 i;
    if (Play_Type == PLAY_VS_PLAYER) {
        return 0;
    }
    if (My_char[COM_id] == PL_GOUKI1 || My_char[COM_id] == PL_GOUKI2) {
        G_No1 = G1_ENDING;
        G_No2 = G2_END_INIT;
        E_No0 = E0_ENDING;
        End_Course = EM_Course[WINNER];
        End_Gouki_Flag = Break_Com[WINNER][14];
        if (My_char[COM_id] == PL_GOUKI2) {
            End_PL = PL_GOUKI2;
        } else {
            End_PL = plw[WINNER].player_number;
        }
        plw[WINNER].wu.operator = 0;
        Operator_Status[WINNER] = 0;
        sound_reg_level_set(0, 0);
        Control_Time = 481;
        Ending_init();
        Stock_My_char[WINNER] = My_char[WINNER];
        Stock_Player_Color[WINNER] = Player_Color[WINNER];
        for (i = 0; i < 16; i++) {
            ROW_ELEM(Break_Com[WINNER], i) = 0;
        }
        return 1;
    }
    return 0;
}



s16 Next_VS_Index(void) {
    s16 em;
    if (VS_Index[WINNER] >= 8) {
        return 8;
    }
    ROW_ELEM(Last_VS_Index, WINNER) = VS_Index[WINNER];
    for (; Last_VS_Index[WINNER] <= 7; Last_VS_Index[WINNER]++) {
        em = EM_Candidate[WINNER][Last_VS_Index[WINNER]];
        if (Break_Com[WINNER][em] == 0) {
            return Last_VS_Index[WINNER];
        }
    }
    return 7;
}



void Quick_Entry(void) {
    if (Check_Entry_Again()) {
        Forbid_Break = 0;
        Extra_Break = 0;
    }
    if (PL_Wins[Winner_id] >= Game_setting.Battle_Number + 1) {
        if (plw[LOSER].wu.operator) {
            Loser_Sub();
            Be_Continue();
        }
        sc_vram_to_ram();
    }
}



s32 Check_Entry_Again(void) {
    if (Play_Type == PLAY_VS_PLAYER) {
        return 1;
    }
    if (Version_Type == 3 && VS_Index[WINNER] >= 6) {
        return 0;
    }
    if (Version_Type == 4 && VS_Index[WINNER] >= 6) {
        return 0;
    }
    if (VS_Index[WINNER] < 7) {
        return 1;
    }
    return 0;
}



void Loser_Sub(void) {
    plw[LOSER].wu.operator = 0;
    Operator_Status[LOSER] = 0;
    Sel_PL_Complete[LOSER] = 0;
    Sel_Arts_Complete[LOSER] = 0;
    if (Play_Type == PLAY_VS_CPU) {
        if (--Round_Level < 0) {
            Round_Level = 0;
        }
        Stage_Continue[LOSER]++;
    }
    if (Game_setting.Event == 0) {
        tilemap_clear_rect(Score_X_Pos_Data[LOSER][Game_setting.Screen_Mode] - 7, Text_Page_Y, Score_X_Pos_Data[LOSER][Game_setting.Screen_Mode], Text_Page_Y + 1);
    }
    tilemap_print_string_attr(Loser_X_Pos_Data[LOSER][Game_setting.Screen_Mode] - 2, 0, 40, "      ");
}



void Be_Continue(void) {
    if (Continue_Flag != 0 && Game_setting.Event == 0) {
        Continue_Count[LOSER] = 9;
        E_Number[LOSER][0] = ENTRY_LOSER;
        E_Number[LOSER][1] = 0;
        E_Number[LOSER][2] = 0;
        E_Number[LOSER][3] = 0;
    } else {
        E_Number[LOSER][0] = ENTRY_GAME_OVER;
        E_Number[LOSER][1] = 0;
        E_Number[LOSER][2] = 0;
        E_Number[LOSER][3] = 0;
        Stock_My_char[LOSER] = My_char[LOSER];
        Stock_Player_Color[LOSER] = Player_Color[LOSER];
    }
}



void Update_VS_Data(void) {
    if (PL_Wins[Winner_id] < Game_setting.Battle_Number + 1) {
        return;
    }
    WINNER = Winner_id;
    LOSER = Loser_id;
    if (Play_Type != PLAY_VS_CPU || Round_Operator[Winner_id] == 0) {
        return;
    }
    Stock_Com_Color[Player_id] = -1;
    Stock_Com_Arts[Player_id] = -1;
    if (My_char[COM_id] == PL_GOUKI1) {
        Special_Enemy[Player_id] = 14;
        ROW_ELEM(Break_Com[Winner_id], EM_id) = 1;
        return;
    }
    if (My_char[COM_id] == PL_GOUKI2) {
        Special_Enemy[Player_id] = 15;
        ROW_ELEM(Break_Com[Winner_id], EM_id) = 1;
        return;
    }
    if (My_char[COM_id] != rival_char_tbl[My_char[Player_id]] && My_char[COM_id] != PL_GOUKI1 && My_char[COM_id] != PL_GOUKI2) {
        VS_Index[Player_id]++;
        ROW_ELEM(Break_Com[Winner_id], EM_id) = 1;
    }
    if (++Round_Level > 7) {
        Round_Level = 7;
    }
}



void BGM_Fade_Sub(void) {
    s8* v = &BGM_Vol;
    switch (BGM_No) {
    case BGMF_WAIT:
        if (--BGM_Timer == 0) {
            BGM_No++;
            BGM_Timer = 1;
            *v = -128;
        }
        break;
    default:
        if (--BGM_Timer == 0) {
            BGM_Timer = 2;
            if (++*v == 0) {
                BGM_No = BGMF_NONE;
            }
        }
        sound_reg_level_set(0, *v);
        break;
    case BGMF_NONE:
        break;
    }
}



void Setup_BGM_Fade_In(s16 time) {
    if (PB_Music_Off) {
        return;
    }
    BGM_No = BGMF_WAIT;
    BGM_Timer = time;
}



void Update_Personal_Time(s16 id) {
    if (Continue_Coin2[id] == 0) {
        SC_Personal_Time[id] = Control_Time;
    }
}



const u8 Break_Into_Perfect_Data[4] = { 1, 2, 3, 4 };  /* provisional name */



const u8 Shin_Gouki_Perfect_Data[4] = { 2, 3, 4, 5 };  /* provisional name */



const u8 Shin_Gouki_Cheap_Data[4] = { 3, 4, 5, 6 };  /* provisional name */



const u8 Break_Into_SA_Data[4] = { 3, 5, 7, 9 };  /* provisional name */



s32 Check_Special_Settle(void) {
    if (Play_Type == PLAY_VS_PLAYER) {
        return 0;
    }
    if (My_char[COM_id] != PL_GOUKI1) {
        return 0;
    }
    if (PL_Wins[Winner_id] + 1 < Game_setting.Battle_Number + 1) {
        return 0;
    }
    if (Continue_Coin[Player_id]) {
        return 0;
    }
    if (Stage_Judge_Finish[Player_id] || Stage_Time_Finish[Player_id]) {
        return 0;
    }
    if (Stage_SA_Finish[Player_id] == 0 && Stage_Perfect_Finish[Player_id] == 0) {
        return 0;
    }
    if (Cheap_Finish[Player_id] >= Shin_Gouki_Cheap_Data[Game_setting.Battle_Number]) {
        return 0;
    }
    if (Lost_Round[Player_id]) {
        return 0;
    }
    if (Perfect_Finish[Player_id] < Shin_Gouki_Perfect_Data[Game_setting.Battle_Number]) {
        return 0;
    }
    return 1;
}



s32 Check_Break_Into_CPU(s16 PL_id) {
    if (Round_num) {
        return 0;
    }
    if (My_char[COM_id] == PL_GOUKI1 || My_char[COM_id] == PL_GOUKI2) {
        return 0;
    }
    if (plw[0].wu.operator != 0 && plw[1].wu.operator != 0) {
        return 0;
    }
    if (Continue_Coin[Player_id]) {
        return 0;
    }
    if (Lost_Round[Player_id]) {
        return 0;
    }
    if (VS_Index[Player_id] < 7) {
        return 0;
    }
    if (Perfect_Finish[Player_id] < Break_Into_Perfect_Data[Game_setting.Battle_Number]) {
        return 0;
    }
    return EM_Candidate[Player_id][7] = 14;
}



s32 Check_Break_Into(s16 PL_id) {
    s32 ix;
    if (plw[0].wu.operator != 0 && plw[1].wu.operator != 0) {
        return Break_Into_CPU = 0;
    }
    if (Continue_Coin[PL_id]) {
        return Break_Into_CPU = 0;
    }
    if ((ix = VS_Index[PL_id]) < 4 || ix >= 7) {
        return Break_Into_CPU = 0;
    }
    if (Introduce_Break_Into[PL_id]) {
        return Break_Into_CPU = 0;
    }
    if (Super_Arts_Finish[PL_id] < Break_Into_SA_Data[Game_setting.Battle_Number]) {
        return Break_Into_CPU = 0;
    }
    return Break_Into_CPU = 2;
}
