/*
 * sel_pl.c  Player (character) select screen
 *
 * Select_Player is called each frame while the character select screen is up. Sel_PL_Control runs
 * the screen-wide sequence (Sel_PL_Cont_*: background, face panel and object setup, the face and
 * object controllers) and the exit sequence (Exit_1st..7th) that leads into the next scene; Sel_PL
 * then runs each player's own state machine (Sel_PL_1st..6th). Per player: the lever moves the
 * cursor over the face grid (Sel_PL_Sub and the CR/CL/CU/CD moves, with auto-repeat and diagonal
 * handling), a button confirms the character and colour, and Sel_Arts_Sub picks one of three super
 * arts; each choice plays its sound and the character's voice. Demo lever data drives the screen in
 * attract mode. Correct_Control_Time takes time off the select timer after continues, Check_Boss
 * flags the boss break-in after the ninth opponent, and Setup_Battle_Country picks the stage from
 * the characters in play.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "Eff93.h"
#include "SYS_sub.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Eff39.h"
#include "EFF44.h"
#include "EFF70.h"
#include "EFFA3.h"
#include "effa5.h"
#include "EFFA6.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "sc_trans.h"
#include "EFF69.h"
#include "next_cpu.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "EFF38.h"
#include "EFF42.h"
#include "Eff50.h"
#include "eff56.h"
#include "eff57.h"
#include "EFF58.h"
#include "EFF75_ORDER.h"
#include "Eff76.h"
#include "Eff79.h"
#include "EffK6.h"
#include "Grade.h"
#include "aboutspr.h"
#include "PLS02.h"
#include "Com_Pl.h"
#include "bg000.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "sel_pl.h"
#include "fighter.h"

/* S_Sub_No in Exit_4th: the VS screen */
#define VS4_WAIT        0       /* until Next_Step */
#define VS4_FADE_SEL    1       /* from select: fade, set up both plates */
#define VS4_FADE_NEXT   2       /* from the next-opponent screen: fade, set up the CPU plate */
#define VS4_FADE_WAIT   3       /* until the fade is done */
#define VS4_PAUSE       4       /* wait Exit_Wait */
#define VS4_SHOW        5       /* show the VS screen until cut or Exit_Wait, then the characters and arts */
#define VS4_END         6       /* until Next_Step, then the next exit step */

/* Deley_Shot_No[pl]: the button delay in Deley_Shot_Sub */
#define DELAY_NONE      0       /* until a button is pressed */
#define DELAY_HP        1       /* HP alone: wait a moment for LK */
#define DELAY_LK        2       /* (default) LK alone: wait a moment for HP */

/* Auto_No[pl]: the cursor auto-repeat */
#define AUTO_IDLE       0       /* until the lever is held */
#define AUTO_REPEAT     1       /* repeat the cursor move while it stays held */

/* Face_No[1]: the face panel move (Move_Face_BG) */
#define FACE_MOVE_IDLE  0       /* until a move is requested */
#define FACE_MOVING     1       /* (default) until the move is done */

/* Select_Status[0]: who is playing; Select_Status[1]: who has chosen a super art (bits) */
#define SEL_1P          1       /* player 1 */
#define SEL_2P          2       /* player 2 */
#define SEL_BOTH        3       /* both players */

/* SP_No[pl][0]: a player's select routine (Sel_PL_Jmp_Tbl) */
#define SP_INIT         0       /* Sel_PL_1st: set up the cursor */
#define SP_WAIT         1       /* Sel_PL_2nd: until the select starts */
#define SP_CHAR         2       /* Sel_PL_3rd: choose a character */
#define SP_ARTS_WAIT    3       /* Sel_PL_4th: until the super art select opens */
#define SP_ARTS         4       /* Sel_PL_5th: choose a super art */
#define SP_DONE         5       /* Sel_PL_6th: done */

/* Face_No[0]: the face panel routine (Face_Tbl) */
#define FACE_DONE       3       /* Face_4th: the face panel is done */

/* declarations the headers do not give */
extern s16 Sel_Arts_Pos[2];
extern s8 Sel_Char_Shot[2];
extern s16 sel_plate_state[2][3];
void Exit_8th(void);
void Exit_9th(void);
#pragma inline(Setup_BG)
#pragma inline(Check_Exit)
#pragma inline(PL_Sel_Mode_1, PL_Sel_Mode_2)
#pragma inline(Check_Exit_Boss, Check_Exit_Last)
void Next_CPU_1st(void);
void Next_CPU_2nd(void);
void Next_CPU_3rd(void);
void Next_CPU_4th(void);
void Next_CPU_5th(void);
void Next_CPU_6th(void);
void Check_Exit_Boss(void);
void Check_Exit_Last(void);
void Boss_Exit_1st(void);
void Boss_Exit_2nd(void);
void Boss_Exit_3rd(void);
void Boss_Exit_4th(void);
void Boss_Exit_5th(void);
void Boss_Exit_6th(void);
void Boss_Exit_7th(void);
void Boss_Exit_8th(void);
void Last_Exit_1st(void);
void Last_Exit_3rd(void);
void Last_Exit_4th(void);
void Last_Exit_5th(void);
void Setup_EFF75_Order(void);
void Setup_EFF76_Pair(void);
void Setup_VS_Plates();
void Setup_COM_Plate();
void Setup_Exit_Plates(void);
void Exit_Plate_Sub(s16 PL_id);
void Exit_Arts_Plate(s16 both);
void Setup_Next_EM(void);
void Sel_Command_Check(void);
s32 Sel_Lever_Get(s16 PL_id);
extern u16 Sel_Command_Sw;
extern const u8 Sel_Command_Face[];
extern const u16 Sel_Command_Data[][8];
s32 effect_52_init();
s32 effect_I1_init(s16 PL_id, s16 x, s16 y, s16 a3, s16 a4);
s32 effect_59_init();
s32 effect_E0_init();
s32 effect_D8_entry();
extern u8 Straight_Lose_Count;
extern u8 Stock_Battle_Country[2];
extern s16 Exit_Wait;
extern const s8 EM_Candidate_Data[][4][8];
extern const s8 rival_char_tbl[];
void Setup_EM_Course();
void Init_EM_Course();

s16 Select_Player(void) {
    SEL_PL_X = 0;
    if (Break_Into) {
        return 0;
    }
    Sel_PL_Control();
    ID = 0;
    Sel_PL();
    ID = 1;
    Sel_PL();
    Time_Over = 0;
    return SEL_PL_X;
}



void Sel_PL_Control(void) {
    void (*cont_tbl[4])() = { Sel_PL_Cont_1st, Sel_PL_Cont_2nd, Sel_PL_Cont_3rd, Sel_PL_Cont_4th };
    Setup_Select_Status();
    cont_tbl[S_No]();
    sel_pl_face_control();
    ID2 = 0;
    Player_Select_Control();
    ID2 = 1;
    Player_Select_Control();
    Check_Exit();
}



void Sel_PL_Cont_1st(void) {
    s16 xx;
    if (Demo_Flag) {
        tilemap_fill_all(0, 32);
    } else {
        tilemap_print_string_attr(DE_X[0] + 14, Text_Page_Y + 23, 40, "                    ");
    }
    S_No++;
    Suicide = 0;
    Face_No[0] = 0;
    Face_No[1] = 0;
    Sel_Sub_No[0] = 0;
    Sel_Sub_No[1] = 0;
    Exit_No = 0;
    Fade_Flag = 0;
    for (xx = 0; xx < 4; xx++) {
        SP_No[0][xx] = 0;
        SP_No[1][xx] = 0;
    }
    for (xx = 0; xx < 3; xx++) {
        sel_plate_state[0][xx] = 52;
        sel_plate_state[1][xx] = 52;
    }
    System_all_clear_Wait();
    effect_work_quick_init();
    Setup_BG_General();
    Setup_BG_Layer2();
    Setup_BG_Layer3();
    Setup_EFF69();
    Setup_Cursor_Y();
    Time_Stop = 1;
    Select_Timer = 32;
    Unit_Of_Timer = 50;
    Setup_Face_ID();
    Setup_Face_Sub();
    effect_A5_entry();
    effect_42_init(0);
    effect_42_init(1);
    effect_52_init();
    effect_I2_init();
    Appear_Cursor = 0;
    Face_MV_Request = 0;
    Face_Status = 0;
    Face_Move = 0;
    Break_Into_CPU = 0;
    Explosion = 0;
    Time_Over = 0;
    Move_Super_Arts[0] = 0;
    Move_Super_Arts[1] = 0;
    Flash_Complete[0] = 0;
    Flash_Complete[1] = 0;
    Cursor_Move[0] = 0;
    Cursor_Move[1] = 0;
    Order[0] = 1;
    Order_Timer[0] = 30;
    Sel_Char_Shot[0] = 1;
    Sel_Char_Shot[1] = 1;
    Sel_Arts_Pos[0] = 32;
    Sel_Arts_Pos[1] = 95;
}



void Sel_PL_Cont_2nd(void) {
    if (--Cover_Timer == 0) {
        S_No++;
        if (G_No1 == G1_SELECT) {
            Request_E_No = 1;
        }
        Clear_Flash_No();
        Face_MV_Request = 1;
        Face_MV_Time = 10;
        commit_name_entry_row_both_players(Text_Page_Y);
        Scrn_Move_Set(4, 0, 0x100);
        Switch_Screen_Init(0, 1);
        if (Demo_Flag == 1 && G_No1 == G1_NEXT_CPU) {
            load_any_color_fade(86, 19, 19, 19);
            load_any_color_fade(87, 19, 19, 19);
            load_any_color_fade(87, 19, 19, 19);
        }
    }
}



void Sel_PL_Cont_3rd(void) {
    if (Switch_Screen_Revival()) {
        S_No++;
        Forbid_Break = 0;
        if (G_No1 == G1_SELECT || !Demo_Flag) {
            bgm_request(2);
            if (E_Number[0][0] != ENTRY_NAME && E_Number[1][0] != ENTRY_NAME) {
                Ranking_00_6th(0);
            }
        }
    }
}



void Sel_PL_Cont_4th(void) {}



void Initialize_BG(void)
{
    Setup_BG_General();
    Setup_BG_Layer2();
    Setup_BG_Layer3();
}



void Setup_EFF69(void) {
    s16 xx;
    for (xx = 0; xx < 6; xx++) {
        Order[xx] = 0;
        effect_69_init(xx);
    }
}



const s8 Face_Order_Data[7] = {
    1, 5, 6, 13, 9, 4, 14,
};


void Setup_Face_Sub(void) {
    s16 i;
    effect_70_init2();
    for (i = 0; i < 7; i++) {
        effect_70_init(Face_Order_Data[i]);
    }
}



void Sel_PL(void) {
    void (*Sel_PL_Jmp_Tbl[6])() = { Sel_PL_1st, Sel_PL_2nd, Sel_PL_3rd, Sel_PL_4th, Sel_PL_5th, Sel_PL_6th };
    if (plw[ID].wu.operator != 0) {
        Sel_PL_Jmp_Tbl[SP_No[ID][0]]();
    }
}



void Sel_PL_1st(void) {
    if (Exit_No) {
        return;
    }
    SP_No[ID][0]++;
    Stop_Cursor[ID] = 1;
    Auto_No[ID] = 0;
    Auto_Index[ID] = 0;
    Auto_Cursor[ID] = 0;
    Moving_Plate[ID] = 0;
    Moving_Plate_Counter[ID] = 0;
    Select_Start[ID] = 2;
    Select_Arts[ID] = -1;
    effect_D8_entry(ID == 1 ? 1 : 0);
    effect_38_init(ID, 30, 0, 0, -1, 2);
    effect_39_init(ID, 30, 0, 0, -1);
    if (Sel_PL_Complete[ID]) {
        SP_No[ID][0] = SP_ARTS_WAIT;
        Select_Start[ID] = 3;
        Select_Arts[ID] = 3;
        Stop_Cursor[ID] = 1;
        paring_ctr_vs[0][ID] = 0;
        paring_ctr_vs[1][ID] = 0;
        return;
    }
    Arts_Y[ID] = Super_Arts[ID] = Last_Super_Arts[ID];
}



void Sel_PL_2nd(void) {
    if (Select_Start[ID]) {
        return;
    }
    SP_No[ID][0]++;
    Stop_Cursor[ID] = 0;
    Deley_Shot_No[ID] = 0;
    if (Sel_Char_Shot[0]--) {
        Sound_SE(158);
    }
    if (Demo_Flag == 0) {
        Demo_Ptr[ID] = Demo_Lever_Data[Select_Demo_Index];
    }
}



void Sel_PL_3rd(void) {
    if (Stop_Cursor[ID] != 0 || ((u8)Face_Move) != 0) {
        return;
    }
    if (Demo_Flag == 0) {
        if (ID) {
            Sel_PL_Sub(1, *Demo_Ptr[1]);
        } else {
            Sel_PL_Sub(0, *Demo_Ptr[0]);
        }
        Demo_Ptr[ID]++;
    } else {
        Sel_Command_Check();
        if (ID) {
            Sel_PL_Sub(1, Deley_Shot_Sub(1));
        } else {
            Sel_PL_Sub(0, Deley_Shot_Sub(0));
        }
    }
    if (Sel_PL_Complete[ID] >= 0) {
        return;
    }
    SP_No[ID][0]++;
    Stop_Cursor[ID] = 1;
    Auto_No[ID] = 0;
    paring_ctr_vs[0][ID] = 0;
    paring_ctr_vs[1][ID] = 0;
}



/* provisional name */
const u8 Sel_Command_Face[6] = {
    2, 11, 2, 11, 12, 0xFF,
};


/* provisional name */
const u16 Sel_Command_Data[6][8] = {
    { 2, 2, 1, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
    { 1, 1, 2, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
    { 1, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
    { 2, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
    { 2, 2, 1, 2, 1, 1, 1, 0xFFFF },
    { 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
};


/* provisional name */
/* the Gouki code on the select screen: each step wants the cursor on one face (Ryu, Ken, Ryu, Ken,
   Sean) and a fixed run of lever moves; the last opens Gouki's face */
void Sel_Command_Check(void) {
    u16 sw;
    if (Gouki_Select_Open) {
        return;
    }
    Sel_Command_Sw = Sel_Lever_Get(ID);
    sw = ID_of_Face[Cursor_Y[ID]][Cursor_X[ID]];
    if (Sel_Command_Face[Sel_Command_Step[ID]] != sw) {
        return;
    }
    if (Sel_Command_Sw == 0) {
        return;
    }
    if (Sel_Command_Data[Sel_Command_Step[ID]][Sel_Command_Key[ID]] == Sel_Command_Sw) {
        if (Sel_Command_Data[Sel_Command_Step[ID]][Sel_Command_Key[ID] + 1] == 0xFFFF) {
            if (Sel_Command_Face[Sel_Command_Step[ID] + 1] == 0xFF) {
                Gouki_Select_Open = -1;
                return;
            }
            Sel_Command_Step[ID]++;
            Sel_Command_Key[ID] = 0;
        } else {
            Sel_Command_Key[ID]++;
        }
    } else {
        Sel_Command_Step[ID] = 0;
        Sel_Command_Key[ID] = 0;
    }
}



/* provisional name */
s32 Sel_Lever_Get(s16 PL_id) {
    if (PL_id == 0) {
        return ~p1sw_1 & p1sw_0 & LEVER_ALL;
    }
    return ~p2sw_1 & p2sw_0 & LEVER_ALL;
}



s32 Deley_Shot_Sub(s16 PL_id) {
    u16 sw;
    u16 lever;
    if (PL_id == 0) {
        sw = ~p1sw_1 & p1sw_0;
    } else {
        sw = ~p2sw_1 & p2sw_0;
    }
    lever = sw & 0xF;
    sw = sw & 0x7F0;
    switch (Deley_Shot_No[PL_id]) {
    case DELAY_NONE:
        if (sw & 0x7F0) {
            if (sw == 0xC0) {
                return lever | 0xC0;
            }
            if (sw & 0x330) {
                return sw | lever;
            }
            Deley_Shot_Timer[PL_id] = 3;
            if (sw == 0x40) {
                Deley_Shot_No[PL_id] = DELAY_HP;
            }
            if (sw == 0x80) {
                Deley_Shot_No[PL_id] = DELAY_LK;
            }
        }
        break;
    case DELAY_HP:
        if (--Deley_Shot_Timer[PL_id] == 0) {
            return lever | 0x40;
        }
        if (sw & 0x7F0) {
            if (sw == 0x80) {
                return lever | 0xC0;
            }
            return sw | lever;
        }
        break;
    default:
        if (--Deley_Shot_Timer[PL_id] == 0) {
            return lever | 0x80;
        }
        if (sw & 0x7F0) {
            if (sw == 0x40) {
                return lever | 0xC0;
            }
            return sw | lever;
        }
        break;
    }
    return lever;
}



void Sel_PL_4th(void) {
    if (!Select_Arts[ID]) {
        SP_No[ID][0]++;
        Stop_Cursor[ID] = 0;
        Arts_Cursor_No[ID] = 0;
        Arts_Cursor_Timer[ID] = 0;
        if (Sel_Char_Shot[1]--) {
            Sound_SE(159);
        }
    }
}



void Sel_PL_5th(void) {
    if (Stop_Cursor[ID] != 0 || ((u8)Face_Move) != 0) {
        return;
    }
    if (Demo_Flag == 0) {
        if (ID) {
            Sel_Arts_Sub(1, *Demo_Ptr[1], 0);
        } else {
            Sel_Arts_Sub(0, *Demo_Ptr[0], 0);
        }
        Demo_Ptr[ID]++;
    } else if (ID) {
        Sel_Arts_Sub(1, ~p2sw_1 & p2sw_0, p2sw_0);
    } else {
        Sel_Arts_Sub(0, ~p1sw_1 & p1sw_0, p1sw_0);
    }
    if (!Sel_Arts_Complete[ID]) {
        return;
    }
    SP_No[ID][0]++;
    if (plw[0].wu.operator == 0 || plw[1].wu.operator == 0) {
        Check_Boss(ID);
    }
}



void Sel_PL_6th(void) {}



/* the face grid is two rows of 13 (row 1 has only the middle column, the Shin Gouki face, open once
   his command is in); left/right step along the row, up/down only in the middle column */
void Sel_PL_Sub(PL_id, sw)
s16 PL_id;
u16 sw;
{
    Cursor_Move[PL_id] = 0;
    if (Sel_PL_Complete[PL_id] != 0) {
        return;
    }
    if (Time_Over != 0) {
        sw = 16;
    }
    if (sw == 0) {
        Auto_Repeat_Sub(PL_id);
    }
    if (sw & 8) {
        if (Cursor_X[PL_id] != 6 || Cursor_Y[PL_id] != 1) {
            Cursor_Move[PL_id] = 1;
            if (++Cursor_X[PL_id] >= 13) {
                Cursor_X[PL_id] = 0;
            }
        }
    }
    if (sw & 4) {
        if (Cursor_X[PL_id] != 6 || Cursor_Y[PL_id] != 1) {
            Cursor_Move[PL_id] = 1;
            if (--Cursor_X[PL_id] < 0) {
                Cursor_X[PL_id] = 12;
            }
        }
    }
    if (sw & 1) {
        if (Cursor_X[PL_id] == 6 && Gouki_Select_Open != 0) {
            Cursor_Move[PL_id] = 1;
            if (++Cursor_Y[PL_id] > 1) {
                Cursor_Y[PL_id] = 0;
            }
        }
    }
    if (sw & 2) {
        if (Cursor_X[PL_id] == 6 && Gouki_Select_Open != 0) {
            Cursor_Move[PL_id] = 1;
            if (--Cursor_Y[PL_id] < 0) {
                Cursor_Y[PL_id] = 1;
            }
        }
    }
    if (Cursor_Move[PL_id]) {
        Sound_SE(ID + 96);
    }
    if (!(sw & 0x7F0)) {
        return;
    }
    Sel_PL_Complete[PL_id] = 1;
    My_char[PL_id] = ID_of_Face[Cursor_Y[PL_id]][Cursor_X[PL_id]];
    if (Last_My_char2[PL_id] != My_char[PL_id]) {
        Arts_Y[ID] = Super_Arts[ID] = Last_Super_Arts[ID] = 0;
    }
    Last_My_char2[PL_id] = My_char[PL_id];
    Last_Selected_ID = PL_id;
    effect_58_init(6, 20, My_char[PL_id] + PL_id * 16 + 192);
    Sound_SE(ID + 98);
    Setup_PL_Color(PL_id, sw);
    Correct_Control_Time(PL_id);
}



const s8 Repeat_Time_Data[3] = {
    26, 9, 7,
};


const s8 Auto_Repeat_Wife_Data[3] = {
    1, 1, 1,
};


void Auto_Repeat_Sub(PL_id)
s16 PL_id;
{
    u16 sw;
    if (Demo_Flag == 0) {
        return;
    }
    if (Cursor_Move[PL_id] != 0) {
        return;
    }
    if (Cursor_X[PL_id] == 6 && Cursor_Y[PL_id] == 1) {
        return;
    }
    if (PL_id == 0) {
        sw = p1sw_0;
    } else {
        sw = p2sw_0;
    }
    switch (Auto_No[PL_id]) {
    case AUTO_IDLE:
        if (sw & 8) {
            Auto_No[PL_id] = AUTO_REPEAT;
            Auto_Cursor[PL_id] = 8;
            Auto_Timer[PL_id] = Repeat_Time_Data[0];
            Auto_Index[PL_id] = 1;
            break;
        } else if (sw & 4) {
            Auto_No[PL_id] = AUTO_REPEAT;
            Auto_Cursor[PL_id] = 4;
            Auto_Timer[PL_id] = Repeat_Time_Data[0];
            Auto_Index[PL_id] = 1;
            break;
        }
        break;
    case AUTO_REPEAT:
        if ((sw &= 0xC) != Auto_Cursor[PL_id]) {
            Auto_No[PL_id] = AUTO_IDLE;
        } else {
            if (--Auto_Timer[PL_id] != 0) {
                break;
            }
            Auto_Timer[PL_id] = Repeat_Time_Data[Auto_Index[PL_id]++];
            if (Auto_Index[PL_id] > 2) {
                Auto_Index[PL_id] = 2;
            }
            if (sw & 8) {
                Cursor_Move[PL_id] = 1;
                if (++Cursor_X[PL_id] >= 13) {
                    Cursor_X[PL_id] = 0;
                }
            }
            if (sw & 4) {
                Cursor_Move[PL_id] = 1;
                if (--Cursor_X[PL_id] < 0) {
                    Cursor_X[PL_id] = 12;
                }
            }
        }
        break;
    }
}



s32 Auto_Repeat_Sub_Wife(s16 pl) {
    u16 sw;
    if (Cursor_Move[pl] || !Demo_Flag) {
        return 0;
    }
    if (pl == 0) {
        sw = p1sw_0;
    } else {
        sw = p2sw_0;
    }
    switch (Auto_No[pl]) {
    case AUTO_IDLE:
        if (sw & 1) {
            Auto_No[pl] = AUTO_REPEAT;
            Auto_Cursor[pl] = 1;
            Auto_Timer[pl] = Auto_Repeat_Wife_Data[0];
            Auto_Index[pl] = 1;
            break;
        }
        if (sw & 2) {
            Auto_No[pl] = AUTO_REPEAT;
            Auto_Cursor[pl] = 2;
            Auto_Timer[pl] = Auto_Repeat_Wife_Data[0];
            Auto_Index[pl] = 1;
            break;
        }
        break;
    case AUTO_REPEAT:
        if (sw &= Auto_Cursor[pl]) {
            if (--Auto_Timer[pl] == 0) {
                Auto_Timer[pl] = Auto_Repeat_Wife_Data[Auto_Index[pl]++];
                if (Auto_Index[pl] > 2) {
                    Auto_Index[pl] = 2;
                }
                if (sw & 1) {
                    return 1;
                }
                if (sw & 2) {
                    return 2;
                }
            }
        } else {
            Auto_No[pl] = AUTO_IDLE;
        }
        break;
    }
    return 0;
}



void Setup_PL_Color(PL_id, sw)
s16 PL_id;
u16 sw;
{
    s8 id_0;
    s8 id_1;
    if (plw[PL_id ^ 1].wu.operator == 0) {
        id_0 = -1;
        id_1 = 1;
    } else {
        id_0 = My_char[PL_id];
        id_1 = My_char[PL_id * 1 ^ 1U];
    }
    if (Sel_PL_Complete[PL_id ^ 1] == 0) {
        id_0 = 127;
    }
    switch (sw) {
    case 192:
        if (Player_Color[PL_id ^ 1] == 6 && id_0 == id_1) {
            Player_Color[PL_id] = 0;
        } else {
            Player_Color[PL_id] = 6;
        }
        break;
    case 16:
        if (Player_Color[PL_id ^ 1] == 0 && id_0 == id_1) {
            Player_Color[PL_id] = 3;
        } else {
            Player_Color[PL_id] = 0;
        }
        break;
    case 32:
        if (Player_Color[PL_id ^ 1] == 1 && id_0 == id_1) {
            Player_Color[PL_id] = 4;
        } else {
            Player_Color[PL_id] = 1;
        }
        break;
    case 64:
        if (Player_Color[PL_id ^ 1] == 2 && id_0 == id_1) {
            Player_Color[PL_id] = 5;
        } else {
            Player_Color[PL_id] = 2;
        }
        break;
    case 128:
        if (Player_Color[PL_id ^ 1] == 3 && id_0 == id_1) {
            Player_Color[PL_id] = 0;
        } else {
            Player_Color[PL_id] = 3;
        }
        break;
    case 256:
        if (Player_Color[PL_id ^ 1] == 4 && id_0 == id_1) {
            Player_Color[PL_id] = 1;
        } else {
            Player_Color[PL_id] = 4;
        }
        break;
    default:
        if (Player_Color[PL_id ^ 1] == 5 && id_0 == id_1) {
            Player_Color[PL_id] = 2;
        } else {
            Player_Color[PL_id] = 5;
        }
        break;
    }
}



void Sel_Arts_Sub(PL_id, sw)
s16 PL_id;
u16 sw;
{
    u16 lever_sw;
    if (Sel_Arts_Complete[PL_id]) {
        return;
    }
    if (Moving_Plate_Counter[PL_id]) {
        return;
    }
    if (Moving_Plate[PL_id]) {
        return;
    }
    if (Time_Over) {
        sw = 16;
    }
    lever_sw = sw & 0xF;
    if (lever_sw == 0) {
        sw |= Auto_Repeat_Sub_Wife(PL_id);
    }
    if (sw & 2) {
        Sound_SE(ID + 96);
        Moving_Plate[PL_id] = 2;
        Moving_Plate_Counter[PL_id] = 3;
        OK_Priority[PL_id] = 0;
        if ((Arts_Y[PL_id] -= 1) < 0) {
            Arts_Y[PL_id] = 2;
        }
    }
    if (sw & 1) {
        Sound_SE(ID + 96);
        Moving_Plate[PL_id] = 1;
        Moving_Plate_Counter[PL_id] = 3;
        OK_Priority[PL_id] = 0;
        if ((Arts_Y[PL_id] += 1) > 2) {
            Arts_Y[PL_id] = 0;
        }
    }
    if (sw & 0x7F0) {
        Stop_Cursor[ID] = 1;
        Last_Arts_PL = PL_id;
        Sel_Arts_Complete[PL_id] = 1;
        *(s8*)&Last_Super_Arts[PL_id] = *(s8*)&Super_Arts[PL_id] = Arts_Y[PL_id];
        Sound_SE(ID + 98);
        if (ID == 0) {
            sw |= p1sw_0 & LEVER_ALL;
        } else {
            sw |= p2sw_0 & LEVER_ALL;
        }
        Setup_EM_Course(PL_id, sw);
        Decided_My_char[PL_id] = My_char[PL_id];
    }
}



/* provisional name */
/* the lever held with the super art button picks the CPU course (0-3); none held, a random one */
void Setup_EM_Course(PL_id, sw)
s16 PL_id;
u16 sw;
{
    if (EM_Course[PL_id] == 0xFFFF) {
        goto set_id;
    }
set_id:
    Setup_ID();
    if (Decided_My_char[PL_id] == My_char[PL_id]) {
        return;
    }
    if (Continue_Coin[PL_id] && EM_Candidate[PL_id][VS_Index[PL_id]] == 15) {
        return;
    }
    switch (sw) {
    case 24:
    case 40:
    case 72:
        EM_Course[PL_id] = 0;
        break;
    case 136:
    case 264:
    case 520:
        EM_Course[PL_id] = 1;
        break;
    case 20:
    case 36:
    case 68:
        EM_Course[PL_id] = 2;
        break;
    case 132:
    case 260:
    case 516:
        EM_Course[PL_id] = 3;
        break;
    default:
        EM_Course[PL_id] = random_32_com() & 3;
        break;
    }
    Init_EM_Course(PL_id);
}



/* provisional name */
void Init_EM_Course(PL_id)
s16 PL_id;
{
    s16 em;
    Stock_Com_Color[PL_id] = -1;
    Stock_Com_Arts[PL_id] = -1;
    Straight_Lose_Count = 0;
    Introduce_Boss[PL_id] = 0;
    Initialize_EM_Candidate(PL_id, EM_Course[PL_id]);
    em = EM_Candidate[PL_id][7];
    Break_Com[PL_id][em] = 0;
    Introduce_Boss[PL_id] = 0;
    Special_Enemy[PL_id] = 0;
    Break_Com[PL_id][14] = 0;
    Last_Player_id = PL_id;
    VS_Index[PL_id] = 0;
}



void sel_pl_face_control(void) {
    void (*Face_Tbl[4])() = { Face_1st, Face_2nd, Face_3rd, Face_4th };
    Face_Tbl[Face_No[0]]();
    Move_Face_BG();
}



void Face_1st(void) {
    switch (Select_Status[1]) {
    case SEL_1P:
    case SEL_2P:
        if (Sel_Arts_Complete[Select_Status[1] - 1] < 0) {
            Face_MV_Request = 2;
            Face_MV_Time = 5;
            Face_No[0]++;
        }
        break;
    default:
        if (Sel_Arts_Complete[0] < 0 && Sel_Arts_Complete[1] < 0) {
            Face_MV_Request = 2;
            Face_MV_Time = 5;
            Face_No[0] = FACE_DONE;
        }
        break;
    }
}



void Face_2nd(void) {
    if (Move_Super_Arts[0] == 0 && Move_Super_Arts[1] == 0 && Select_Status[1] == SEL_BOTH && Face_Move == 0) {
        Face_MV_Request = 1;
        Face_MV_Time = 20;
        Face_No[0]++;
    }
}



void Face_3rd(void) {
    if (Sel_PL_Complete[0] < 0 && Sel_PL_Complete[1] < 0) {
        Face_MV_Request = 2;
        Face_MV_Time = 5;
        Face_No[0] = FACE_DONE;
    }
}



void Face_4th(void) {}



void Move_Face_BG(void) {
    switch (Face_No[1]) {
    case FACE_MOVE_IDLE:
        if (Face_MV_Request == 0) {
            break;
        }
        Face_Move = Face_MV_Request;
        effect_93_init(Face_Move, Face_MV_Time);
        Face_No[1]++;
        break;
    default:
        if (Face_MV_Request = Face_Move) {
            break;
        }
        Face_No[1] = FACE_MOVE_IDLE;
        break;
    }
}



/* provisional name */
void Player_Select_Control(void) {
    void (*Obj_Tbl[5])() = { PL_Sel_Begin, PL_Sel_2nd, PL_Sel_3rd, PL_Sel_4th, PL_Sel_5th };

    if (plw[ID2].wu.operator != 0) {
        Obj_Tbl[SP_No[ID2][1]]();
    }
}



/* provisional name */
void PL_Sel_Begin(void) {
    if (Sel_PL_Complete[ID2] == -0x8000) {
        SP_No[ID2][1] = 2;
        Order[ID2 + 1] = 5;
        Sel_Arts_Complete[ID2] = 0;
        Order[ID2 + 3] = 3;
        Order_Timer[ID2 + 3] = 1;
        Order_Dir[ID2 + 3] = PL_Sel_Mode_1();
        sel_pl_disp_char_effect_trio(ID2, 32);
        effect_50_init(ID2, 1);
        effect_50_init(ID2, 2);
    } else {
        SP_No[ID2][1]++;
        Order[ID2 + 1] = 3;
        Order_Timer[ID2 + 1] = 1;
        Order_Dir[ID2 + 1] = PL_Sel_Mode_1();
    }
}


/* provisional name */
s32 PL_Sel_Mode_1(void) {
    if (ID2 == 0) {
        return 8;
    } else {
        return 4;
    }
}


/* provisional name */
s32 PL_Sel_Mode_2(void) {
    if (ID2 == 0) {
        return 4;
    } else {
        return 8;
    }
}



void PL_Sel_2nd(void) {
    if (Sel_PL_Complete[ID2] < 0) {
        SP_No[ID2][1]++;
        Order[ID2 + 1] = 4;
        Order_Timer[ID2 + 1] = 1;
        Order_Dir[ID2 + 1] = PL_Sel_Mode_2();
        Order[ID2 + 3] = 3;
        Order_Timer[ID2 + 3] = 25;
        Order_Dir[ID2 + 3] = PL_Sel_Mode_1();
        sel_pl_disp_char_effect_trio(ID2, 0);
        effect_50_init(ID2, 1);
        effect_50_init(ID2, 2);
    }
}



void PL_Sel_3rd(void) {
    if (Sel_Arts_Complete[ID2] < 0) {
        SP_No[ID2][1]++;
        Order[ID2 + 3] = 4;
        Order_Timer[ID2 + 3] = 1;
        Order_Dir[ID2 + 3] = PL_Sel_Mode_2();
    }
}



void PL_Sel_4th(void) {}



const s16 Setup_Aborigine_table[3][3] = {
    { 1, 0, 2 }, { 2, 1, 0 }, { 0, 2, 1 },
};


/* provisional name */
const s16 Setup_Aborigine_time[3][3] = {
    { 30, 25, 20 }, { 20, 30, 25 }, { 25, 20, 30 },
};


void sel_pl_disp_char_effect_trio(s8 PL_id, s16 Time) {
    Move_Super_Arts[PL_id] = 3;
    Select_Arts[PL_id] = 3;
    effect_79_init(PL_id, 0, Setup_Aborigine_table[Super_Arts[PL_id]][0], Setup_Aborigine_time[Super_Arts[PL_id]][0] + Time, 0);
    effect_79_init(PL_id, 1, Setup_Aborigine_table[Super_Arts[PL_id]][1], Setup_Aborigine_time[Super_Arts[PL_id]][1] + Time, 0);
    effect_79_init(PL_id, 2, Setup_Aborigine_table[Super_Arts[PL_id]][2], Setup_Aborigine_time[Super_Arts[PL_id]][2] + Time, 0);
}



void PL_Sel_5th(void) {}



void Setup_Select_Status(void) {
    if (plw[0].wu.operator) {
        Select_Status[0] = SEL_1P;
    } else {
        Select_Status[0] = 0;
    }
    if (plw[1].wu.operator) {
        Select_Status[0] |= SEL_2P;
    }
    if (Sel_Arts_Complete[0] != -1 && plw[0].wu.operator) {
        Select_Status[1] = SEL_1P;
    } else {
        Select_Status[1] = 0;
    }
    if (Sel_Arts_Complete[1] != -1 && plw[1].wu.operator) {
        Select_Status[1] |= SEL_2P;
    }
}



void Basic_Sub(void) {
    bg_w.bgw[0].old_pos_x = bg_w.bgw[0].xy[0].disp.pos;
    move_effect_work(0);
    move_effect_work(1);
    move_effect_work(2);
    move_effect_work(3);
    move_effect_work(4);
    move_effect_work(6);
    move_effect_work(5);
    bg_pos_hosei2();
    Bg_Family_Set();
}



void Basic_Sub_Ex(void) {
    move_effect_work(0);
    move_effect_work(1);
    move_effect_work(2);
    move_effect_work(3);
    move_effect_work(4);
    move_effect_work(6);
    move_effect_work(5);
}



/* provisional name */
/* Basic_Sub with layer 0's work and correction positions kept on its scroll and its line scroll redone */
void Basic_Sub_Suzi(void) {
    bg_w.bgw[0].old_pos_x = bg_w.bgw[0].xy[0].disp.pos;
    move_effect_work(0);
    move_effect_work(1);
    move_effect_work(2);
    move_effect_work(3);
    move_effect_work(4);
    move_effect_work(6);
    move_effect_work(5);
    bg_w.bgw[0].hos_xy[0].disp.pos = bg_w.bgw[0].wxy[0].disp.pos = bg_w.bgw[0].xy[0].disp.pos;
    suzi_line_calc(0);
    bg_pos_hosei2();
    Bg_Family_Set();
}



static void Setup_BG(BG_INDEX, X, Y)
s16 BG_INDEX;
s32 X;
s32 Y;
{
    bg_w.bgw[BG_INDEX].xy[0].disp.pos = X;
    bg_w.bgw[BG_INDEX].xy[1].disp.pos = Y;
    bg_w.bgw[BG_INDEX].xy[0].disp.low = 0;
    bg_w.bgw[BG_INDEX].xy[1].disp.low = 0;
    bg_w.bgw[BG_INDEX].position_x = X;
    bg_w.bgw[BG_INDEX].position_y = Y;
}



/* provisional name */
void Setup_BG_General(void) {
    s16 i;
    Zoomf_Init();
    bg_w.stage = 17;
    bg_w.area = 0;
    bg_initialize();
    for (i = 0; i < bg_w.scno; i++) {
        bg_w.bgw[i].xy[0].disp.pos = 512;
        bg_w.bgw[i].xy[1].disp.pos = 0;
        bg_w.bgw[i].xy[0].disp.low = 0;
        bg_w.bgw[i].xy[1].disp.low = 0;
        bg_w.bgw[i].position_x = 512;
        bg_w.bgw[i].position_y = 0;
        bg_w.bgw[i].hos_xy[0].disp.pos = bg_w.bgw[i].wxy[0].disp.pos = bg_w.bgw[i].xy[0].disp.pos;
    }
    bg_w.bgw[0].old_pos_x = bg_w.bgw[0].xy[0].disp.pos;
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
void Setup_BG_Layer2(void) {
    Setup_BG(2, 512, 0);
    Bg_Family_Set_Ex(2);
}



/* provisional name */
void Setup_BG_Layer3(void) {
    bg_w.bgw[1].xy[0].disp.pos = 259;
    bg_w.bgw[1].xy[1].disp.pos = 144;
    bg_w.bgw[1].xy[0].disp.low = 0;
    bg_w.bgw[1].xy[1].disp.low = 0;
    bg_w.bgw[1].position_x = 257;
    bg_w.bgw[1].position_y = 144;
    bg_w.bgw[1].hos_xy[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos;
}



const s16 Cursor_Y_Data[6] = {
    80, 104, 128, 80, 104, 128,
};


void Setup_Cursor_Y(void) {
    s16 i;
    s16 j;
    s32 p;

    p = (s32)Cursor_Y_Pos;
    for (i = 2, j = 0; i >= 0; i--, j++) {
        *(s16*)(p + i * 2) = Cursor_Y_Data[j];
    }
    p = (s32)Cursor_Y_Pos;
    for (i = 2, j = 3; i >= 0; i--, j++) {
        *(s16*)(p + i * 2 + 6) = Cursor_Y_Data[j];
    }
}



/* provisional name */
/* the next opponent from the player's list, skipping those already beaten */
void Setup_Next_EM(void) {
    Setup_ID();
    paring_counter[COM_id] = 0;
    paring_bonus_r[COM_id] = 0;
    EM_id = EM_Candidate[Player_id][VS_Index[Player_id]];
    if (Break_Com[Player_id][EM_id] != 0) {
        for (; VS_Index[Player_id] <= 7; VS_Index[Player_id]++) {
            EM_id = EM_Candidate[Player_id][VS_Index[Player_id]];
            if (Break_Com[Player_id][EM_id] == 0) {
                break;
            }
        }
    }
}



const u8 Arts_Rnd_Data[8] = {
    0, 0, 0, 1, 1, 1, 2, 2,
};


s32 Setup_Com_Arts(void) {
    if (EM_id == PL_GILL) {
        return 1;
    }
    if (Stock_Com_Arts[Player_id] == -1) {
        return Arts_Rnd_Data[random_16_com() & 7];
    }
    return Stock_Com_Arts[Player_id];
}



void Setup_ID(void) {
    if (Operator_Status[0] == 0) {
        COM_id = 0;
        Player_id = 1;
    } else {
        COM_id = 1;
        Player_id = 0;
    }
}



/* provisional name */
/* the select screen's second entry, for the next fight: the player's choice stands, the opponent is
   set up and the exit runs on to the VS screen (or the break-in boss's) */
s32 Next_CPU(void) {
    void (*Next_CPU_Tbl[6])() = { Next_CPU_1st, Next_CPU_2nd, Next_CPU_3rd, Next_CPU_4th, Next_CPU_5th, Next_CPU_6th };
    SEL_PL_X = 0;
    Next_CPU_Tbl[S_No]();
    return SEL_PL_X;
}



/* provisional name */
const s16 Sel_Shot_Data[6] = {
    16, 32, 64, 128, 256, 512,
};


/* provisional name */
void Next_CPU_1st(void) {
    s16 pl;
    S_No++;
    Exit_Timer = 20;
    SEL_PL_X = 0;
    Suicide = 0;
    Explosion = 0;
    Exit_No = 1;
    System_all_clear_Wait();
    effect_work_quick_init();
    Setup_BG_General();
    Setup_BG_Layer2();
    Setup_BG_Layer3();
    Setup_Cursor_Y();
    Setup_Face_ID();
    Setup_Face_Sub();
    effect_I2_init();
    if (plw[0].wu.operator) {
        pl = 0;
    } else {
        pl = 1;
    }
    effect_38_init(pl, -1, 1, 1, My_char[pl], 0);
    if (Check_Boss(pl)) {
        effect_79_init(pl, Super_Arts[pl], 1, 1, 3);
        effect_39_init(pl, -1, 2, 1, My_char[pl]);
    } else {
        effect_79_init(pl, Super_Arts[pl], 1, 1, 2);
        effect_39_init(pl, -1, 1, 1, My_char[pl]);
    }
}



/* provisional name */
void Next_CPU_2nd(void) {
    Sel_PL_Cont_2nd();
}



/* provisional name */
void Next_CPU_3rd(void) {
    Sel_PL_Cont_3rd();
}



/* provisional name */
void Next_CPU_4th(void) {
    if (Break_Into) {
        return;
    }
    Check_Exit();
}



/* provisional name */
void Next_CPU_5th(void) {
    if (Break_Into) {
        return;
    }
    Check_Exit_Boss();
}



/* provisional name */
void Next_CPU_6th(void) {
    if (Break_Into) {
        return;
    }
    Check_Exit_Last();
}



void Check_Exit(void) {
    void (*Exit_Tbl[9])(void) = { Exit_1st, Exit_2nd, Exit_3rd, Exit_4th, Exit_5th, Exit_6th, Exit_7th, Exit_8th, Exit_9th };

    Exit_Tbl[Exit_No]();
}



void Exit_1st(void) {
    if (plw[0].wu.operator && Sel_Arts_Complete[0] >= 0) {
        return;
    }
    if (plw[1].wu.operator != 0 && Sel_Arts_Complete[1] >= 0) {
        return;
    }
    Exit_No++;
    Order[0] = 2;
    Order_Timer[0] = 1;
    Order_Dir[0] = 1;
    if (Demo_Flag == 0) {
        return;
    }
    E_No0 = E0_SELECTED;
    E_No1 = 0;
    E_No2 = 0;
    E_No3 = 0;
}



void Exit_2nd(void) {
    s16 em;
    Sel_Exit_Flag = 0;
    S_Sub_No = 0;
    if (plw[0].wu.operator && plw[1].wu.operator != 0) {
        Exit_No = 4;
        Battle_Country = My_char[New_Challenger];
        Next_Step = 0;
        Setup_EFF75_Order();
        Setup_EFF76_Pair();
        effect_59_init(60);
    } else {
        if (Cut_Cut_Cut()) {
            Exit_Timer = 1;
        } else {
            Exit_Timer = 60;
        }
        Exit_No++;
        if (Last_My_char[Player_id] != My_char[Player_id]) {
            Last_My_char[Player_id] = My_char[Player_id];
            VS_Index[Player_id] = 0;
            em = EM_Candidate[Player_id][7];
            Break_Com[Player_id][em] = 0;
        }
        Setup_Next_EM();
        My_char[COM_id] = EM_id;
        Battle_Country = Setup_Battle_Country();
        Super_Arts[COM_id] = Stock_Com_Arts[Player_id] = Setup_Com_Arts();
        Setup_Com_Color();
        Setup_PL_Color(COM_id, Com_Color_Shot);
        Request_Disp_Rank[COM_id][RANK_SCORE] = -1;
        Request_Disp_Rank[COM_id][RANK_WINS] = -1;
        Next_Step = 0;
        Setup_EFF75_Order();
        Setup_EFF76_Pair();
        effect_E0_init(COM_id ^ 1);
        effect_59_init(60);
    }
}



void Exit_3rd(void) {
    if (Cut_Cut_Cut()) {
        goto exit;
    }
    if (--Exit_Timer == 0) {
exit:
        Exit_No = 4;
        if (VS_Index[Player_id] >= 7) {
            EM_Rank = 1;
        } else {
            EM_Rank = 0;
        }
        if (Break_Into_CPU == 1) {
            Exit_No = 3;
        }
    }
}



void Exit_4th(void) {
    switch (S_Sub_No) {
    case VS4_WAIT:
        if (Next_Step) {
            if (G_No1 == G1_NEXT_CPU) {
                S_Sub_No = VS4_FADE_NEXT;
            } else {
                S_Sub_No++;
            }
        }
        break;
    case VS4_FADE_SEL:
        if (Request_Fade(65, 0)) {
            S_Sub_No = VS4_FADE_WAIT;
            Suicide = 1;
            Forbid_Break = 0;
            Next_Step = 2;
            bgm_request(3);
            effect_38_init(0, 1, 1, 1, My_char[0], 0);
            effect_38_init(1, 1, 1, 1, My_char[1], 0);
            Stop_Cursor[0] = 1;
            Stop_Cursor[1] = 1;
            Setup_VS_Plates(0, 1, 6);
            Exit_Wait = 60;
        }
        break;
    case VS4_FADE_NEXT:
        if (Request_Fade(65, 0)) {
            S_Sub_No++;
            Suicide = 1;
            Forbid_Break = 0;
            Next_Step = 2;
            bgm_request(3);
            Setup_COM_Plate(1);
            Stop_Cursor[0] = 1;
            Stop_Cursor[1] = 1;
            Setup_VS_Plates(0, 1, 6);
            Exit_Wait = 60;
        }
        break;
    case VS4_FADE_WAIT:
        if (Check_Fade_Complete_SP()) {
            S_Sub_No++;
        }
        break;
    case VS4_PAUSE:
        if (--Exit_Wait == 0) {
            S_Sub_No++;
            Exit_Wait = 240;
        }
        break;
    case VS4_SHOW:
        if (Cut_Cut_Cut() || --Exit_Wait == 0) {
            S_Sub_No++;
            Next_Step = 16;
            effect_39_init(0, 10, 3, 1, My_char[0]);
            effect_39_init(1, 10, 3, 1, My_char[1]);
            effect_79_init(0, Super_Arts[0], 1, 1, 1);
            effect_79_init(1, Super_Arts[1], 1, 1, 1);
        }
        break;
    case VS4_END:
        if (Next_Step == 0) {
            break;
        }
        Exit_No = 7;
        Exit_Wait = 90;
        Next_Step = 0;
        Introduce_Boss[Player_id] = 1;
        effect_43_init(0, 1);
        effect_43_init(1, 1);
        break;
    }
}



void Exit_5th(void) {
    if (Next_Step != 0 && Request_Fade(65, 0)) {
        Exit_No++;
        Suicide = 1;
        Next_Step = 0;
        Forbid_Break = 0;
        bgm_request(3);
        Setup_Exit_Plates();
        Stop_Cursor[0] = 1;
        Stop_Cursor[1] = 1;
        if (Demo_Flag == 0) {
            Exit_Arts_Plate(1);
        } else {
            Exit_Arts_Plate(0);
        }
        effect_43_init(0, 10);
        effect_43_init(1, 10);
    }
}



/* provisional name */
void Setup_Exit_Plates(void) {
    if (Demo_Flag == 1 && G_No1 == G1_NEXT_CPU) {
        Setup_COM_Plate(0);
    } else {
        if (plw[0].wu.operator) {
            Exit_Plate_Sub(0);
        } else {
            Setup_COM_Plate(0);
        }
        if (plw[1].wu.operator) {
            Exit_Plate_Sub(1);
        } else {
            Setup_COM_Plate(0);
        }
    }
}



/* provisional name */
void Exit_Plate_Sub(s16 PL_id) {
    effect_38_init(PL_id, 10, 1, 0, -1, 0);
    effect_39_init(PL_id, 5, 1, 0, -1);
}



/* provisional name */
void Exit_Arts_Plate(s16 both) {
    if (both == 0 && G_No1 == G1_NEXT_CPU) {
        effect_79_init(COM_id, Super_Arts[COM_id], 1, 1, 2);
    } else {
        effect_79_init(0, Super_Arts[0], 1, 1, 2);
        effect_79_init(1, Super_Arts[1], 1, 1, 2);
    }
}



void Exit_6th(void) {
    if (Check_Fade_Complete_SP()) {
        Exit_No++;
    }
}



void Exit_7th(void) {
    if (Next_Step) {
        Exit_No++;
        Exit_Wait = 50;
    }
}



void Exit_8th(void) {
    if (Cut_Cut_Cut()) {
        Exit_No++;
    } else if (--Exit_Wait == 0) {
        Exit_No = 8;
    }
}



void Exit_9th(void) {
    bg_w.stage = Battle_Country;
    bg_w.area = 0;
    SEL_PL_X = 1;
}



/* provisional name */
/* the exit when the break-in boss comes on */
void Check_Exit_Boss(void) {
    void (*Exit_Tbl[8])(void) = { Boss_Exit_1st, Boss_Exit_2nd, Boss_Exit_3rd, Boss_Exit_4th, Boss_Exit_5th, Boss_Exit_6th, Boss_Exit_7th, Boss_Exit_8th };

    Exit_Tbl[Exit_No]();
}



/* provisional name */
void Boss_Exit_1st(void) {
    Scr_all_clear_Wait();
    Exit_No++;
    SEL_PL_X = 0;
    Suicide = 0;
    Explosion = 0;
    Setup_BG_General();
    Setup_BG_Layer2();
    Setup_BG_Layer3();
    My_char[COM_id] = Break_Into_CPU;
    if (Break_Into_CPU == 2) {
        (&My_char[COM_id])[0] = rival_char_tbl[My_char[Player_id]];
    }
    EM_id = My_char[COM_id];
    Stock_Com_Arts[Player_id] = -1;
    Super_Arts[COM_id] = Stock_Com_Arts[Player_id] = Setup_Com_Arts();
    Setup_Com_Color();
    if (My_char[COM_id] != PL_GOUKI1) {
        Setup_PL_Color(COM_id, Com_Color_Shot);
    }
    pcon_rno[0] = 0;
    pcon_rno[1] = 0;
    pcon_rno[2] = 0;
    pcon_rno[3] = 0;
    appear_type = APPEAR_ENTRY;
    erase_extra_plef_work();
    effect_38_init(Player_id, -1, 1, 1, My_char[Player_id], 0);
    effect_38_init(COM_id, -1, 1, 1, My_char[COM_id], 0);
}



/* provisional name */
void Boss_Exit_2nd(void) {
    if (--Cover_Timer == 0) {
        Exit_No++;
        Clear_Flash_No();
        commit_name_entry_row_both_players(Text_Page_Y);
        Scrn_Move_Set(4, 0, 0x100);
        Switch_Screen_Init(0, 1);
    }
}



/* provisional name */
void Boss_Exit_3rd(void) {
    if (Switch_Screen_Revival()) {
        Exit_No++;
        Forbid_Break = 0;
        Next_Step = 2;
        Exit_Wait = 60;
        if (My_char[COM_id] == PL_GOUKI1) {
            Setup_VS_Plates(0, 10, 15);
        } else {
            Setup_VS_Plates(1, 10, 15);
        }
    }
}



/* provisional name */
void Boss_Exit_4th(void) {
    if (--Exit_Wait == 0) {
        Exit_No++;
        Exit_Wait = 240;
    }
}



/* provisional name */
void Boss_Exit_5th(void) {
    if (Cut_Cut_Cut() || --Exit_Wait == 0) {
        Exit_No++;
        Next_Step = 16;
        effect_39_init(0, 10, 3, 1, My_char[0]);
        effect_39_init(1, 10, 3, 1, My_char[1]);
        effect_79_init(0, Super_Arts[0], 1, 1, 1);
        effect_79_init(1, Super_Arts[1], 1, 1, 1);
    }
}



/* provisional name */
void Boss_Exit_6th(void) {
    if (Next_Step) {
        Exit_No++;
        Exit_Wait = 120;
        Next_Step = 0;
        Introduce_Break_Into[Player_id] = 1;
        bgm_request(3);
        effect_43_init(0, 10);
        effect_43_init(1, 10);
    }
}



/* provisional name */
void Boss_Exit_7th(void) {
    if (Cut_Cut_Cut()) {
        Exit_Wait = 1;
    }
    if (--Exit_Wait == 0) {
        Exit_No++;
        if (Break_Into_CPU == 14 || Break_Into_CPU == 15) {
            Battle_Country = EM_Candidate_Data[My_char[Player_id]][EM_Course[Player_id]][VS_Index[Player_id]];
        } else {
            Battle_Country = EM_Candidate_Data[My_char[Player_id]][EM_Course[Player_id]][VS_Index[Player_id] - 1];
        }
        bg_w.stage = Battle_Country;
    }
}



s32 Setup_Battle_Country(void) {
    if (My_char[COM_id] == PL_GOUKI2) {
        return Stock_Battle_Country[Player_id];
    }
    return EM_Candidate_Data[My_char[Player_id]][EM_Course[Player_id]][VS_Index[Player_id]];
}



/* provisional name */
void Boss_Exit_8th(void) {
    SEL_PL_X = 1;
}



/* provisional name */
/* the exit to the last boss */
void Check_Exit_Last(void) {
    void (*Exit_Tbl[6])(void) = { Last_Exit_1st, Boss_Exit_2nd, Last_Exit_3rd, Last_Exit_4th, Last_Exit_5th, Boss_Exit_8th };

    Exit_Tbl[Exit_No]();
}



/* provisional name */
void Last_Exit_1st(void) {
    Scr_all_clear_Wait();
    Exit_No++;
    SEL_PL_X = 0;
    Suicide = 0;
    Explosion = 0;
    Setup_BG_General();
    Setup_BG_Layer2();
    Setup_BG_Layer3();
    My_char[COM_id] = PL_GOUKI1;
    pcon_rno[0] = 0;
    pcon_rno[1] = 0;
    pcon_rno[2] = 0;
    pcon_rno[3] = 0;
    appear_type = APPEAR_STAND;
    erase_extra_plef_work();
    effect_38_init(Player_id, -1, 1, 1, My_char[Player_id], 0);
    effect_39_init(Player_id, -1, 1, 1, My_char[Player_id]);
    effect_79_init(Player_id, Super_Arts[Player_id], 1, 1, 2);
    Stock_Com_Arts[Player_id] = -1;
    Super_Arts[COM_id] = Stock_Com_Arts[Player_id] = Setup_Com_Arts();
    effect_38_init(COM_id, -1, 1, 1, My_char[COM_id], 0);
    effect_39_init(COM_id, -1, 1, 1, My_char[COM_id]);
    effect_79_init(COM_id, Super_Arts[COM_id], 1, 1, 2);
}



/* provisional name */
void Last_Exit_3rd(void) {
    if (Switch_Screen_Revival()) {
        Exit_No++;
        Forbid_Break = 0;
        Exit_Wait = 30;
    }
}



/* provisional name */
void Last_Exit_4th(void) {
    if (Cut_Cut_Cut()) {
        Exit_Wait = 1;
    }
    if (--Exit_Wait == 0) {
        Exit_No++;
        Exit_Wait = 90;
        effect_43_init(0, 10);
        effect_43_init(1, 10);
    }
}



/* provisional name */
void Last_Exit_5th(void) {
    if (--Exit_Wait == 0) {
        Exit_No++;
        bg_w.stage = EM_Candidate[Player_id][VS_Index[Player_id]];
        bg_w.area = 0;
    }
}



/* provisional name */
const s16 Stage_Order_Skip[15] = {
    16, 19, 17, 17, 15, 17, 15, 17, 16, 20, 17, 19, 20, 16, 17,
};


/* provisional name */
void Setup_EFF75_Order(void) {
    s16 i;
    s16 skip;
    skip = Stage_Order_Skip[Battle_Country];
    for (i = 15; i <= 20; i++) {
        if (i != skip) {
            effect_75_init(1, i, 6);
        }
    }
    effect_75_init(1, Battle_Country, 6);
}



/* provisional name */
const u8 EFF76_Side_Data[16] = {
    1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
};


/* provisional name */
void Setup_EFF76_Pair(void) {
    effect_76_init(0, 1, 0, My_char[0]);
    effect_76_init(1, 1, EFF76_Side_Data[My_char[1]], My_char[1]);
}



/* provisional name */
const u8 VS_Plate_Data[16][2] = {
    { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 },
    { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 },
};


/* provisional name */
void Setup_VS_Plates(type, x, y)
s16 type;
s16 x;
s16 y;
{
    if (VS_Plate_Data[My_char[Player_id]][type]) {
        effect_I1_init(Player_id, y, 48, 8, 1);
        effect_I1_init(Player_id ^ 1, x, 104, 6, 0);
    } else {
        effect_I1_init(Player_id ^ 1, y, 48, 8, 1);
        effect_I1_init(Player_id, x, 104, 6, 0);
    }
}



/* provisional name */
void Setup_COM_Plate(face_only)
s16 face_only;
{
    effect_38_init(COM_id, 10, 1, 1, EM_id, 0);
    if (!face_only) {
        effect_39_init(COM_id, 5, 1, 1, EM_id);
    }
}



void Setup_Face_ID(void) {
    s16 i, j;

    for (i = 0; i <= 1; i++) {
        for (j = 0; j < 13; j++) {
            (&ID_of_Face[i][0])[j] = Face_Cursor_Data[i][j];
        }
    }
}



/* provisional name */
const s16 Com_Color_Data[17] = {
    16, 16, 16, 16, 16, 16, 32, 32, 64, 64, 128, 128, 256, 256, 512, 512, -1,
};


void Setup_Com_Color(void) {
    if (EM_id == PL_GILL || EM_id == PL_GOUKI2) {
        if (My_char[COM_id] == PL_GILL) {
            Com_Color_Shot = 16;
        } else if (COM_id == 0) {
            Com_Color_Shot = 16;
        } else {
            Com_Color_Shot = 32;
        }
    } else if (Stock_Com_Color[Player_id] == -1) {
        Com_Color_Shot = Stock_Com_Color[Player_id] = Com_Color_Data[random_16_com()];
    } else {
        Com_Color_Shot = Stock_Com_Color[Player_id];
    }
}



void Correct_Control_Time(PL_id)
s16 PL_id;
{
    u8 xx;
    u8 zz;
    if (Play_Type == PLAY_VS_PLAYER) {
        return;
    }
    if (Stage_Continue[PL_id] == 0) {
        return;
    }
    xx = Stage_Continue[PL_id];
    if (VS_Index[PL_id] >= 7) {
        zz = 1;
    } else {
        zz = 0;
    }
    if (Stage_Continue[PL_id] >= 16) {
        xx = 16;
    } else {
        xx = Stage_Continue[PL_id];
    }
    Control_Time = SC_Personal_Time[PL_id] - Correct_Cont_Time_Data[zz][xx];
    if (Control_Time < 0) {
        Control_Time = 0;
    }
    SC_Personal_Time[PL_id] = Control_Time;
}



s32 Check_Boss(PL_id)
s16 PL_id;
{
    Setup_Next_EM();
    if (VS_Index[Player_id] >= 7 && Introduce_Boss[Player_id] == 0) {
        Control_Time = Limit_Time;
        SC_Personal_Time[PL_id] = Control_Time;
        return Break_Into_CPU = 1;
    }
    return Break_Into_CPU = 0;
}
