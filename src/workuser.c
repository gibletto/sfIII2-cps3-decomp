/*
 * WORKUSER.C  work RAM shared by the whole game
 *
 * Cleared work RAM (section B). A <name>_tail table holds the bytes between <name> and the next
 * named variable.
 */

#include "types.h"
#include "structs.h"

u16 Game_timer;  /* 0201015C */
s16 Game_pause;  /* 0201015E */
s16 Game_difficulty;  /* 02010160 */
s16 Control_Time;  /* 02010162 */
s16 Time_in_Time;  /* 02010164 */
s16 Counter_hi;  /* 02010166 */
s16 Counter_low;  /* 02010168 */
s16 Round_Level;  /* 0201016A */
u16 Round_Result;  /* 0201016C */
s8 request_message;  /* 0201016E */
s8 Winner_id;  /* 0201016F */
s8 Loser_id;  /* 02010170 */
s16 PL_Wins[2];  /* 02010172 */
s8 Break_Into;  /* 02010176 */
u8 My_char[2];  /* 02010177 */
u8 Allow_a_battle_f;  /* 02010179 */
u8 Round_num;  /* 0201017A */
s8 Super_Arts[2];  /* 0201017B */
s8 Fade_Flag;  /* 0201017D */
s8 Forbid_Break;  /* 0201017E */
s8 Request_Break[2];  /* 0201017F */
s16 Fade_R_No0;  /* 02010182 */
s16 Fade_R_No1;  /* 02010184 */
u16 Fade_Number;  /* 02010186 */
u8 Fade_Mode;  /* 02010188 */
u32 Score[2][3];  /* 0201018C */
s16 Play_Type;  /* 020101A4 */
s8 Win_Record[2];  /* 020101A6 */
s8 Continue_Count[2];  /* 020101A8 */
s8 Personal_Continue_Flag[2];  /* 020101AA */
s8 Personal_Disp_Flag;  /* 020101AC */
u8 Personal_Disp_Flag_tail[1];  /* after Personal_Disp_Flag; nothing refers to it by name or address */
s8 WINNER;  /* 020101AE */
s8 LOSER;  /* 020101AF */
u8 LOSER_tail[2];  /* after LOSER; nothing refers to it by name or address */
s16 Conclusion_Type;  /* 020101B2 */
s8 Judge_Round_Flag;  /* 020101B4 */
s16 win_type[2][4];  /* 020101B6 */
s8 win_pause_go;  /* 020101C6 */
s16 message_index;  /* 020101C8 */
s16 Conclusion_Flag;  /* 020101CA */
s8 New_Challenger;  /* 020101CC */
s8 Champion;  /* 020101CD */
s8 Complete_Judgement;  /* 020101CE */
s8 Reserve_Cut;  /* 020101CF */
s8 Perfect_Flag;  /* 020101D0 */
s16 DE_X[19];  /* 020101D2 */
u8 DE_X_tail[2];  /* after DE_X; nothing refers to it by name or address */
s16 Fade_Gap_Timer;  /* 020101FA */
s8 Fade_Half_Flag;  /* 020101FC */
u32 Vital_Bonus[2];  /* 02010200 */
u32 Time_Bonus[2];  /* 02010208 */
u8 Time_Bonus_tail[8];  /* after Time_Bonus; nothing refers to it by name or address */
s16 win_mark_new[2];  /* 02010218 */
s8 Next_Step;  /* 0201021C */
s8 judge_flag;  /* 0201021D */
s8 Wipe_Count;  /* 0201021E */
u8 Wipe_Limit;  /* 0201021F */
u8 Wipe_Mode;  /* 02010220 */
u8 Wipe_Kind;  /* 02010221 */
u8 sc_chr_ram[16384];  /* 02010222 */
s8 Cover_Timer;  /* 02014222 */
s16 Text_Page_Y;  /* 02014224 */
s8 E_07_Flag[2];  /* 02014226 */
s8 Suicide;  /* 02014228 */
s8 Personal_Timer[2];  /* 02014229 */
s8 Request_E_No;  /* 0201422B */
s8 Request_G_No;  /* 0201422C */
s16 G_Timer;  /* 0201422E */
s16 G_No0;  /* 02014230 */
s16 G_No1;  /* 02014232 */
s16 G_No2;  /* 02014234 */
s16 G_No3;  /* 02014236 */
s16 D_Timer;  /* 02014238 */
s16 D_No0;  /* 0201423A */
s16 D_No1;  /* 0201423C */
s16 D_No2;  /* 0201423E */
s16 D_No3;  /* 02014240 */
u8 Present_Rank[2];  /* 02014242 */
s8 Rank_In[2][2];  /* 02014244 */
s8 Request_Disp_Rank[2][2];  /* 02014248 */
s8 Demo_Type;  /* 0201424C */
s8 Rank_Type;  /* 0201424D */
s8 Flash_Sign[2];  /* 0201424E */
s8 Flash_Rank_Time;  /* 02014250 */
s8 Flash_Rank_Interval;  /* 02014251 */
s8 Ranking_X;  /* 02014252 */
s8 Rank;  /* 02014253 */
s8 Rank_X;  /* 02014254 */
s16 Rank_Pos_X;  /* 02014256 */
s16 Rank_Pos_Y;  /* 02014258 */
s16 E_Timer;  /* 0201425A */
s16 E_No0;  /* 0201425C */
s16 E_No1;  /* 0201425E */
s16 E_No2;  /* 02014260 */
s16 E_No3;  /* 02014262 */
s16 F_No0[2];  /* 02014264 */
s16 F_No1[2];  /* 02014268 */
s16 F_No2[2];  /* 0201426C */
s16 F_No3[2];  /* 02014270 */
s16 F_Timer[2];  /* 02014274 */
u8 F_Timer_tail[12];  /* after F_Timer; nothing refers to it by name or address */
s16 E_Number[2][4];  /* 02014284 */
s16 ENTRY_X;  /* 02014294 */
s16 C_Timer;  /* 02014296 */
s16 C_No0;  /* 02014298 */
s16 C_No1;  /* 0201429A */
s16 C_No2;  /* 0201429C */
s16 C_No3;  /* 0201429E */
s8 Complete_Victory;  /* 020142A0 */
s8 Demo_Flag;  /* 020142A1 */
s8 Next_Demo;  /* 020142A2 */
s8 Demo_PL_Index;  /* 020142A3 */
s8 Demo_Stage_Index;  /* 020142A4 */
s16 Exit_Timer;  /* 020142A6 */
s16 S_No;  /* 020142A8 */
s16 S_Sub_No;  /* 020142AA */
s16 S_Sub2_No;  /* 020142AC */
s16 S_Sub3_No;  /* 020142AE */
s16 Flash_Complete[2];  /* 020142B0 */
s16 Sel_PL_Complete[2];  /* 020142B4 */
s16 Sel_Arts_Complete[2];  /* 020142B8 */
s16 Select_Start[2];  /* 020142BC */
s16 Cursor_X[2];  /* 020142C0 */
s16 Arts_Y[2];  /* 020142C4 */
u8 Arts_Y_tail[4];  /* after Arts_Y; nothing refers to it by name or address */
s16 Cursor_Y_Pos[2][3];  /* 020142CC */
s16 Stop_Cursor[2];  /* 020142D8 */
s16 Move_Super_Arts[2];  /* 020142DC */
u8 Move_Super_Arts_tail[6];  /* after Move_Super_Arts; nothing refers to it by name or address */
s16 Battle_Country;  /* 020142E6 */
s16 Face_Status;  /* 020142E8 */
s8 Face_MV_Request;  /* 020142EA */
s8 Face_Move;  /* 020142EB */
s8 Appear_Cursor;  /* 020142EC */
s8 Select_Timer;  /* 020142ED */
s8 Time_Stop;  /* 020142EE */
s8 Time_Over;  /* 020142EF */
s16 Unit_Of_Timer;  /* 020142F0 */
s8 Player_id;  /* 020142F2 */
s8 Last_Player_id;  /* 020142F3 */
s8 Player_Number;  /* 020142F4 */
s8 COM_id;  /* 020142F5 */
s8 EM_id;  /* 020142F6 */
s16 VS_Index[2];  /* 020142F8 */
u8 VS_Index_tail[2];  /* after VS_Index; nothing refers to it by name or address */
s16 Plate_X[2][3];  /* 020142FE */
s16 Plate_Y[2][3];  /* 0201430A */
u8 Plate_Y_tail[24];  /* after Plate_Y; nothing refers to it by name or address */
s16 SP_No[2][4];  /* 0201432E */
s16 ID;  /* 0201433E */
s16 Face_No[2];  /* 02014340 */
s16 Sel_Sub_No[2];  /* 02014344 */
s16 Arts_Cursor_No[2];  /* 02014348 */
s16 Arts_Cursor_Timer[2];  /* 0201434C */
s16 Exit_No;  /* 02014350 */
u8 Exit_No_tail[4];  /* after Exit_No; nothing refers to it by name or address */
s16 Select_Arts[2];  /* 02014356 */
u8 Select_Arts_tail[4];  /* after Select_Arts; nothing refers to it by name or address */
/* the code declares Order[100]; sel_plate_state starts after its first 6 entries */
s16 Order[6];  /* 0201435E */
s16 sel_plate_state[2][3];  /* 0201436A, provisional name */
s8 Select_Status[2];  /* 02014376 */
s8 Select_Demo_Index;  /* 02014378 */
u8 Country;  /* 02014379 */
s16 mes_already;  /* 0201437A */
s16 CP_No[2][4];  /* 0201437C */
s16 CP_Index[2][8];  /* 0201438C */
s16 Pattern_Index[2];  /* 020143AC */
s16 Timer_00[2];  /* 020143B0 */
s16 Timer_01[2];  /* 020143B4 */
s8 Combo_Speed[2];  /* 020143B8 */
u8 Combo_Speed_tail[2];  /* after Combo_Speed; nothing refers to it by name or address */
s16 PL_Distance[2];  /* 020143BC */
s16 Area_Number[2];  /* 020143C0 */
u16 Lever_Buff[2];  /* 020143C4 */
u16 Lever_Pool[2];  /* 020143C8 */
const_s16_arr Tech_Address[2];  /* 020143CC */
s16 Tech_Index[2];  /* 020143D4 */
u8 Tech_Index_tail[24];  /* after Tech_Index; nothing refers to it by name or address */
s16 Random_ix16_com;  /* 020143F0 */
s16 Random_ix32_com;  /* 020143F2 */
s16 M_Timer;  /* 020143F4 */
s16 M_No0;  /* 020143F6 */
s16 M_No1;  /* 020143F8 */
s16 M_No2;  /* 020143FA */
s16 M_No3;  /* 020143FC */
s8 Demo_Time_Stop;  /* 020143FE */
u8 Demo_Time_Stop_tail[1];  /* after Demo_Time_Stop; nothing refers to it by name or address */
s8 win_slide_flag;  /* 02014400, provisional name */
s16 VS_Tech[2];  /* 02014402 */
s8 Exec_Wipe;  /* 02014406 */
s16 Guard_Type[2];  /* 02014408 */
s16 Separate_Area[2][3];  /* 0201440C */
u32* Shell_Address[2];  /* 02014418 */
u16 Free_Lever[2];  /* 02014420 */
s8 Passive_Flag[2];  /* 02014424 */
s8 Flip_Flag[2];  /* 02014426 */
s16 Air_Guard_Type[2];  /* 02014428 */
s8 Lie_Flag[2];  /* 0201442C */
s16 Term_No[2];  /* 0201442E */
s8 Attack_Flag[2];  /* 02014432 */
s8 Passive_Mode;  /* 02014434 */
s8 Limited_Flag[2];  /* 02014435 */
s8 Shell_Ignore_Timer[2];  /* 02014437 */
s16 Com_Width_Data[2];  /* 0201443A */
s8 Event_Judge_Gals;  /* 0201443E */
u8 EJG_index[4];  /* 0201443F */
s8 Guard_Flag[2];  /* 02014443 */
u16 Lever_Squat[2];  /* 02014446 */
u16 M_Lv[2];  /* 0201444A */
s8 Pierce_Menu[2];  /* 0201444E */
s8 Counter_Attack[2];  /* 02014450 */
s16 zuubun_base_x;  /* 02014452 */
s8 Face_MV_Time;  /* 02014454 */
s8 Before_Jump[2];  /* 02014455 */
u8 Before_Jump_tail[17];  /* after Before_Jump; nothing refers to it by name or address */
s8 Stop_Combo;  /* 02014468 */
u8 Stock_Hit_Flag[2];  /* 02014469 */
s8 Rolling_Flag[2];  /* 0201446B */
u8 Continue_Coin[2];  /* 0201446D */
s8 Ignore_Entry[2];  /* 0201446F */
s16 Cursor_Y[2];  /* 02014472 */
s16 eff98_plate_z[2][3];  /* 02014476, provisional name */
s8 Slide_Type;  /* 02014482 */
/* the code declares Order_Dir[100]; Order_Timer starts after its first 6 entries */
s8 Order_Dir[6];  /* 02014483 */
/* the code declares Order_Timer[100]; Moving_Plate starts after its first 6 entries */
s8 Order_Timer[6];  /* 02014489 */
s8 Moving_Plate[2];  /* 0201448F */
s8 Naming_Cut[2];  /* 02014491 */
s8 Moving_Plate_Counter[2];  /* 02014493 */
s8 OK_Priority[2];  /* 02014495 */
s8 Player_Color[2];  /* 02014497 */
s8 PP_Priority[2][3];  /* 02014499 */
s8 eff98_arts_req[2][3];  /* 0201449F, provisional name */
u8 eff98_arts_req_tail[25];  /* after eff98_arts_req; nothing refers to it by name or address */
u8 Stock_My_char[2];  /* 020144BE */
s8 Stock_Player_Color[2];  /* 020144C0 */
s16 Insert_Y;  /* 020144C2 */
u8 Insert_Y_tail[2];  /* after Insert_Y; nothing refers to it by name or address */
u8 Version_Type;  /* 020144C6 */
u8 Version_Type_tail[1];  /* after Version_Type; nothing refers to it by name or address */
s8 Music_Fade;  /* 020144C8 */
s16 zoom_request_flag;  /* 020144CA */
s16 zoom_req_flag_old;  /* 020144CC */
s16 zoom_request_level;  /* 020144CE */
s16 Stock_Com_Color[2];  /* 020144D0 */
s8 Stock_Com_Arts[2];  /* 020144D4 */
u8 Stock_Com_Arts_tail[16];  /* after Stock_Com_Arts; nothing refers to it by name or address */
s8 Stop_SG;  /* 020144E6 */
s16 Last_Selected_ID;  /* 020144E8 */
s16 Last_Called_SE;  /* 020144EA */
s16 scr_req_x;  /* 020144EC */
s16 scr_req_y;  /* 020144EE */
u8 scr_req_y_tail[6];  /* after scr_req_y; nothing refers to it by name or address */
s8 Operator_Status[2];  /* 020144F6 */
s8 Round_Operator[2];  /* 020144F8 */
u32 Stock_Score[2];  /* 020144FC */
s8 another_bg[2];  /* 02014504 */
s8 another_bg_old[2];  /* 02014506 */
s8 judge_disp_all;  /* 02014508 */
u8 judge_disp_all_tail[49];  /* after judge_disp_all; nothing refers to it by name or address */
s8 unused_flag_b;  /* 0201453A */
s8 bg_test_flag;  /* 0201453B */
s8 Last_Super_Arts[2];  /* 0201453C */
s8 Last_My_char[2];  /* 0201453E */
u8 Last_My_char_tail[4];  /* after Last_My_char; nothing refers to it by name or address */
s8 Continue_Menu[2];  /* 02014544 */
s8 Timer_Freeze;  /* 02014546 */
s8 Rapid_No[2][4];  /* 02014547 */
s16 Rapid_Index[2];  /* 02014550 */
s8 Standing_Timer[2];  /* 02014554 */
s8 Before_Look[2];  /* 02014556 */
s16 Shell_Separate_Area[2][3];  /* 02014558 */
s16 Attack_Counter[2];  /* 02014564 */
s16 Last_Attack_Counter[2];  /* 02014568 */
s8 Attack_Count_No0[2];  /* 0201456C */
s16 Com_Color_Shot;  /* 0201456E */
s8 Standing_Master_Timer[2];  /* 02014570 */
s8 unused_flag_c;  /* 02014572 */
s8 test_sw_lock;  /* 02014573 */
s8 PB_Music_Off;  /* 02014574 */
s8 No_Death;  /* 02014575 */
s8 Flash_MT[2];  /* 02014576 */
s8 Squat_Timer[2];  /* 02014578 */
s8 Squat_Master_Timer[2];  /* 0201457A */
s8 Turn_Over[2];  /* 0201457C */
s16 Distance_XX_Index[2];  /* 0201457E */
u16 Resume_Lever[2][20];  /* 02014582 */
s8 Turn_Over_Timer[2];  /* 020145D2 */
s8 Jump_Pass_Timer[2][4];  /* 020145D4 */
s16 BGM_No;  /* 020145DC */
u16 BGM_Timer;  /* 020145DE */
s8 sa_gauge_flash[2];  /* 020145E0 */
s8 Receive_Flag[2];  /* 020145E2 */
s8 Disposal_Again[2];  /* 020145E4 */
u16 players_timer;  /* 020145E6 */
s8 unused_flag_a;  /* 020145E8 */
volatile s8 BGM_Vol;  /* 020145E9 */
u8 Used_char[2];  /* 020145EA */
s8 Break_Com[2][16];  /* 020145EC */
s8 Sel_Exit_Flag;  /* 0201460C */
u16 EM_Course[2];  /* 0201460E: the CPU course each player picks on the select screen (0-3, FFFF none yet); provisional name */
u16 Lever_Store[2][3];  /* 02014612 */
s16 Return_CP_No[2];  /* 0201461E */
s16 Return_CP_Index[2];  /* 02014622 */
s16 Return_Pattern_Index[2];  /* 02014626 */
s8 aiuchi_flag;  /* 0201462A */
u8 Straight_Lose_Count;  /* 0201462B, provisional name */
u8 paring_counter[2];  /* 0201462C */
u8 paring_bonus_r[2];  /* 0201462E */
u8 paring_ctr_vs[2][2];  /* 02014630 */
u8 paring_ctr_ori[2];  /* 02014634 */
u8 Type_of_Attack[2];  /* 02014636 */
u16 Lever_LR[2];  /* 02014638 */
s16 Last_Eftype[2];  /* 0201463C */
u16 DENJIN_No[2];  /* 02014640 */
u8 DENJIN_Term[2];  /* 02014644 */
u16 SC_Personal_Time[2];  /* 02014646 */
u8 Attack_Count_Buff[2][4];  /* 0201464A */
u8 Attack_Count_Index[2];  /* 02014652 */
s16 Guard_Counter[2];  /* 02014654 */
u8 CC_Type;  /* 02014658 */
u8 CC_Value[2];  /* 02014659 */
u8 CC_Value_tail[2];  /* after CC_Value; nothing refers to it by name or address */
u8 Continue_Coin2[2];  /* 0201465D */
s16 kage_gfx_ofs[64];  /* 02014660 */
s16 kage_gfx_cells[64];  /* 020146E0 */
u16 seraph_gfx_ofs[48];  /* 02014760 */
s16 seraph_gfx_cells[48];  /* 020147C0 */
s16 hitmark_gfx_ofs[2][512];  /* 02014820 */
s16 hitmark_gfx_cells[512];  /* 02015020 */
s16 car_gfx_ofs[64];  /* 02015420 */
s16 car_gfx_cells[64];  /* 020154A0 */
s16 Limit_Time;  /* 02015520 */
u8 Weak_PL;  /* 02015522 */
s16 Last_Pattern_Index[2];  /* 02015524 */
u8 Bullet_No[2];  /* 02015528 */
u8 Bullet_Counter[2];  /* 0201552A */
u8 Straight_Win_Count;  /* 0201552C, provisional name */
s16 Random_ix16_ex_com;  /* 0201552E */
s16 Random_ix32_ex_com;  /* 02015530 */
s16 Entry_Mes_X[2];  /* 02015532 */
s16 Entry_Mes_Wide[2];  /* 02015536 */
s8 Disp_Win_Name;  /* 0201553A */
u8 Perfect_Counter[2];  /* 0201553B */
u8 Straight_Counter[2];  /* 0201553D */
u32 Complete_Bonus;  /* 02015540 */
s8 Introduce_Boss[2];  /* 02015544 */
u8 Introduce_Boss_tail[8];  /* after Introduce_Boss; nothing refers to it by name or address */
s8 Break_Into_CPU;  /* 0201554E */
/* the code declares ID_of_Face[3][13]; Cursor_Move starts after its first 2 entries */
s8 ID_of_Face[2][13];  /* 0201554F */
s8 Cursor_Move[2];  /* 02015569 */
s8 Auto_Cursor[2];  /* 0201556B */
s8 Auto_No[2];  /* 0201556D */
s8 Auto_Index[2];  /* 0201556F */
s8 Auto_Timer[2];  /* 02015571 */
s8 ID2;  /* 02015573 */
s8 Explosion;  /* 02015574 */
s16 Exit_Wait;  /* 02015576 */
s8 Introduce_Break_Into[2];  /* 02015578 */
u32 Stage_Stock_Score[2];  /* 0201557C */
s16 Max_vitality;  /* 02015584 */
s8 gouki_wins;  /* 02015586 */
s8 EM_Rank;  /* 02015587 */
s8 Gouki_Select_Open;  /* 02015588, provisional name */
s8 Disp_PERFECT;  /* 02015589 */
s8 Escape_SS;  /* 0201558A */
s8 Deley_Shot_No[2];  /* 0201558B */
s8 Deley_Shot_Timer[2];  /* 0201558D */
s16 Bonus_Game_Flag;  /* 02015590 */
s16 Bonus_Game_Work;  /* 02015592 */
s16 Bonus_Game_result;  /* 02015594 */
s16 Bonus_Game_ex_result;  /* 02015596 */
s8 Lost_Round[2];  /* 02015598 */
s8 Super_Arts_Finish[2];  /* 0201559A */
s8 Stage_SA_Finish[2];  /* 0201559C */
s8 Perfect_Finish[2];  /* 0201559E */
s8 Cheap_Finish[2];  /* 020155A0 */
s8 Last_My_char2[2];  /* 020155A2 */
s8 gouki_app;  /* 020155A4 */
s8 Completion_Bonus[2];  /* 020155A5 */
s8 Bonus_Game_Complete;  /* 020155A7 */
s16 Stock_Bonus_Game_Result;  /* 020155A8 */
s16 Gill_Pos_X;  /* 020155AA */
s16 bs_scrrrl[2][2];  /* 020155AC */
u32 Bonus_Score;  /* 020155B4 */
u32 Final_Bonus_Score;  /* 020155B8 */
s16 Bonus_Stage_RNO[4];  /* 020155BC */
u8 Demo_Lever_Play;  /* 020155C4 */
s16 Bonus_Stage_Level;  /* 020155C6 */
s16 Bonus_Stage_Tix;  /* 020155C8 */
u8 Get_Demo_Index;  /* 020155CA */
u8 Combo_Demo_Flag;  /* 020155CB */
u8 Stage_Continue[2];  /* 020155CC */
u8 Pause_Hit_Marks;  /* 020155CE */
u8 Special_Settle;  /* 020155CF */
u8 Extra_Break;  /* 020155D0 */
u8 EM_Candidate[2][8];  /* 020155D1 */
u8 Shin_Gouki_BGM;  /* 020155E1 */
s8 Stage_Lost_Round[2];  /* 020155E2 */
s8 Stage_Perfect_Finish[2];  /* 020155E4 */
s8 Stage_Cheap_Finish[2];  /* 020155E6 */
s8 EXE_obroll;  /* 020155E8 */
u8 End_PL;  /* 020155E9 */
s8 Stage_Judge_Finish[2];  /* 020155EA */
u8 Special_Enemy[2];  /* 020155EC */
s8 End_Gouki_Flag;  /* 020155EE, provisional name */
u16 End_Course;  /* 020155F0: the winner's CPU course, which picks the ending's messages; provisional name */
u8 PB_Status;  /* 020155F2 */
u8 Sel_Command_Step[2];  /* 020155F3, provisional name */
u8 Sel_Command_Key[2];  /* 020155F5, provisional name */
u8 Flip_Counter[2];  /* 020155F7 */
u8 Stage_Time_Finish[2];  /* 020155F9 */
u8 Stock_Battle_Country[2];  /* 020155FB, provisional name */
u8 Stock_Battle_Country_tail[807];  /* after Stock_Battle_Country; nothing refers to it by name or address */
