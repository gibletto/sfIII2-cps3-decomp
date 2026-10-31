/*
 * WIN_2.C  Winner and loser scenes
 *
 * Scene routines called from Game_Main between matches. Winner_Scene and Loser_Scene run the win and
 * lose screens step by step through one table each: Win_1st to Win_7th set up the background, the
 * player colours and the portraits, switch the screen in and start the BGM (Check_Win_BGM picks it),
 * count down and wait for a button (Check_Scene_Cut); the loser's own steps Lose_4th, Lose_6th and
 * Lose_7th clear the loser's character and fade out. Both return WIN_X, 1 when the scene is over.
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
#include "cmb_win.h"
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
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "win_2.h"
#include "fighter.h"
#include "Eff95.h"
#include "EFFB8.h"

/* M_No1 in Win_3rd and Lose_3rd */
#define M1_COVER        0       /* after Cover_Timer, clear the screen and wipe in */
#define M1_REVIVAL      1       /* finish the wipe */





s16 WIN_X;



s16 Winner_Scene(void) {
    void (*Scene_Tbl[7])() = { Win_1st, Win_2nd, Win_3rd, Win_4th, Win_5th, Win_6th, Win_7th };
    WIN_X = 0;
    Scene_Tbl[M_No0]();
    if (Break_Into) {
        return 0;
    } else {
        return WIN_X;
    }
}



void Win_1st(void) {
    M_No0++;
    Cover_Timer = 24;
}



void Win_2nd(void) {
    s16 ofs;
    M_No0++;
    M_No1 = M1_COVER;
    Suicide = 0;
    System_all_clear_Wait();
    base_y_pos = 40;
    bg_etc_write(0);
    bg_pos_hosei2();
    Bg_Family_Set();
    if (WINNER == 1) {
        ofs = 22;
    } else {
        ofs = -22;
    }
    if (Game_setting.Screen_Mode) {
        ofs = 0;
    }
    bg_w.bgw[0].position_x += ofs;
    bg_w.bgw[1].position_x = bg_w.bgw[0].position_x - ofs;
    bg_w.bgw[0].xy[0].disp.pos += ofs;
    bg_w.bgw[1].xy[0].disp.pos = bg_w.bgw[0].xy[0].disp.pos - ofs;
    Bg_Family_Set_Ex(1);
    load_side_color(0, My_char[WINNER]);
    load_side_color(1, My_char[LOSER]);
    load_any_color(4);
    load_any_color(0x86);
    win_slide_flag = 1;
    load_char_gfx(0x9C10, 1);
    load_char_gfx(0x9C90, 1);
    effect_95_init(16, WINNER);
    effect_95_init(0, LOSER);
    effect_B8_init(WINNER);
    if (Game_setting.Screen_Mode == 0) {
        effect_58_init(4, 1, -1);
    }
    effect_H3_init();
}



void Win_3rd(void) {
    switch (M_No1) {
    case M1_COVER:
        if (--Cover_Timer) {
            break;
        }
        M_No1++;
        tilemap_fill_all(0, 32);
        Clear_Flash_No();
        commit_name_entry_row_both_players(Text_Page_Y);
        if (G_No1 == G1_WINNER) {
            Scrn_Move_Set(4, 0, 0x100);
        }
        Switch_Screen_Init(0, 1);
        break;
    case M1_REVIVAL:
        if (Switch_Screen_Revival()) {
            M_No0++;
            M_Timer = 30;
            Forbid_Break = -1;
            Ignore_Entry[LOSER] = 0;
            if (Play_Type == PLAY_VS_CPU) {
                BGM_Request(4);
            } else if (Check_Win_BGM()) {
                BGM_Request(4);
            } else {
                BGM_Request(5);
            }
        }
        break;
    }
}



void Win_4th(void) {
    if (--M_Timer == 0) {
        M_No0++;
        M_Timer = 1;
    }
}



void Win_5th(void) {
    if (--M_Timer == 0) {
        M_No0++;
        M_Timer = 170;
        Forbid_Break = 0;
    }
}



void Win_6th(void) {
    if (Check_Scene_Cut(WINNER)) {
        M_Timer = 1;
    }
    if (--M_Timer == 0) {
        M_No0++;
        WIN_X = 1;
    }
}



void Win_7th(void) {
    WIN_X = 1;
}



s16 Loser_Scene(void) {
    void (*Scene_Tbl[8])() = { Win_1st, Win_2nd, Win_3rd, Lose_4th, Win_5th, Lose_6th, Lose_7th, Win_7th };
    WIN_X = 0;
    Scene_Tbl[M_No0]();
    if (Break_Into) {
        return 0;
    } else {
        return WIN_X;
    }
}



void Lose_4th(void) {
    if (--M_Timer == 0) {
        M_No0++;
        if (Request_Break[0] != 0 || Request_Break[1] != 0) {
            M_Timer = 30;
        } else {
            M_Timer = 120;
        }
        plw[LOSER].wu.operator = 0;
        My_char[LOSER] &= 0x7F;
    }
}



void Lose_6th(void) {
    if (Check_Scene_Cut(LOSER)) {
        M_Timer = 1;
    }
    if (--M_Timer == 0) {
        if (Request_Fade(38, 0)) {
            M_No0++;
            Forbid_Break = 0;
        } else {
            M_Timer = 1;
        }
    }
}



void Lose_7th(void) {
    if (Check_Fade_Complete_SP()) {
        M_No0++;
        Suicide = 1;
        if (Break_Into == 0) {
            WIN_X = 1;
        }
    }
}



s32 Check_Scene_Cut(id)
s16 id;
{
    if (id) {
        return p2sw_0 & 0x7F0;
    }
    return p1sw_0 & 0x7F0;
}



s32 Check_Win_BGM(void) {
    if (Win_Record[WINNER] == 0) {
        return 1;
    }
    return Win_Record[WINNER] % 10;
}



const u16 Entry_Msg_X_Data[12][2] = {
    { 6, 10 }, { 31, 40 },
    { 5, 10 }, { 30, 39 },
    { 2, 10 }, { 27, 36 },
    { 2, 9 }, { 27, 40 },
    { 7, 15 }, { 32, 41 },
    { 7, 15 }, { 32, 41 },
};



const u16 Score_X_Pos_Data[4][2] = {
    { 17, 23 }, { 37, 46 },
    { 6, 14 },
    { 31, 40 },
};



const s16 Loser_X_Pos_Data[6][2] = {
    { 5, 5 }, { 42, 55 },
    { 8, 15 },
    { 31, 40 },
    { 7, 15 },
    { 32, 41 },
};



/*
 * Indexed by area (kage_hx) and screen mode: the text rectangle effect A3 clears, as left,
 * top, right and bottom cells (rows counted from Text_Page_Y).
 */
const s16 EFFA3_Area_Data[2][2][4] = {
    { { 0, 9, 48, 10 }, { 8, 9, 62, 10 } },
    { { 0, 15, 48, 16 }, { 8, 15, 62, 16 } },
};
