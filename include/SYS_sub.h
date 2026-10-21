#ifndef SYS_SUB_H
#define SYS_SUB_H

#include "structs.h"

s32 Button_Cut_EX(s16* Timer, s16 Limit_Time);
s32 Check_Fade_Complete_SP(void);
s32 Ck_Range_Out_S(WORK_Other* ewk, s16 BG_No, s16 R);
s32 Ck_Range_Out_Y(WORK_Other* ewk, s16 BG_No, s16 R);  /* provisional name; 2nd Impact only */
s32 Cut_Cut_C_Timer(void);
s32 Cut_Cut_Cut(void);
s8 Cut_Cut_Loser(void);
void Scr_all_clear_Wait(void);
void System_all_clear_Wait(void);
void System_all_clear_Ex_Wait(void);
void System_all_clear(void);
void System_all_clear_Ex(void);
s32 Check_Fade_Complete(void);
s32 Request_Fade();
void Switch_Screen_Init_Panel(s16 kind);
void Switch_Screen_Init();
s32 Switch_Screen(void);
s32 Switch_Screen_Revival(void);
void scfont_page0_fill(u32 attr, u16 code);
void scfont_page1_fill(u32 attr, u16 code);
s32 Button_Cut_Hold(s16* timer, s16 first, s16 repeat);
void Disp_Digit8x16(u32 value, s16 x, s16 y);
void Disp_Win_Type(void);
void Disp_Capcom_Rights(void);
s32 Cut_Cut_Sub(s16 xx);
void Setup_Play_Type(void);
void scrn_pos_clear(void);
void challenger_banner_clear(void);
void commit_name_entry_row_both_players();
void Clear_Flash_No(void);
s32 Check_Sort_Ranking();       /* provisional name; 2nd Impact only */
s32 cut_button_side(void);
u32 Check_Ranking();
void Check_Partners_Rank();
void Fade_Cont(void);
void Disp_Digit16x24(u32 value, s16 x, s16 y, u16 attr);

s32 cpu_algorithm(s16 id);

#endif
