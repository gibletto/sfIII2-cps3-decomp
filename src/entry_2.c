/*
 * ENTRY_2.C  Task control, debug dumps and the player entry / credit task (part 2)
 *
 * Entry task: entry_task calls entry_main every frame, which dispatches on E_No to Entry_00
 * (flashing INSERT COIN / FREE PLAY), card entry, name entry, winner, loser, continue
 * (Entry_Continue_Sub countdown), in-game and ranking entry steps, letting a second player join or
 * break in (Break_Into_xx, Pay_Start_Credit, Credit_Sub / Credit_Continue). Title messages
 * (Disp_Start_Message, credit_display_render, Disp_More_Coins) and game-over handling (In_Game_Sub,
 * Setup_Next_Step) are also here. The unit ends with coin_in_sound_request and
 * Redisp_Continue_Count.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFA2_MAIN.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "n_input.h"
#include "SYS_sub.h"
#include "cmb_win.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "Eff93.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "eeprom.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "Grade.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "sc_trans.h"
#include "sc_clear.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "entry_2.h"



extern const s8 str_INSERT_COIN[];
extern const s8 str_INSERT_COINS[];
extern const s8 str_INSERT_COINS_2[];
extern const s8 str_INSERT_COINS_3[];
extern const s8 str_INSERT_COINS_4[];
extern const s8 str_INSERT_COINS_5[];
extern const s8 str_INSERT_COINS_6[];
extern const s8 str_INSERT_COINS_7[];
extern const s8 str_INSERT_COINS_8[];

/* 020000B0 */
TM_STRING insert_coin_mes[9] = {
    { 0, 0, 0x28, str_INSERT_COIN },
    { 0, 0, 0x28, str_INSERT_COINS },
    { 0, 0, 0x28, str_INSERT_COINS_2 },
    { 0, 0, 0x28, str_INSERT_COINS_3 },
    { 0, 0, 0x28, str_INSERT_COINS_4 },
    { 0, 0, 0x28, str_INSERT_COINS_5 },
    { 0, 0, 0x28, str_INSERT_COINS_6 },
    { 0, 0, 0x28, str_INSERT_COINS_7 },
    { 0, 0, 0x28, str_INSERT_COINS_8 },
};



void entry_task(void)
{
    do {
        entry_main();
        task_sleep(1);
    } while (1);
}



void entry_main(void) {
    void (*Main_Jmp_Tbl[11])() = { Entry_00, Entry_01, Entry_02, Entry_03, Entry_04, Entry_03, Entry_06, Entry_07, Entry_08, Entry_03, Entry_10 };
    if (Free_Play) {
        credit_1p = 9;
        credit_2p = 9;
    }
    Main_Jmp_Tbl[E_No0]();
    card_msg_disp();
}



void Entry_00(void) {
    switch (E_No1) {
    case 0:
        Text_Page_Y = 0;
        break;
    case 1:
        E_No1++;
        E_Timer = 50;
        if (Free_Play) {
            tilemap_print_string_attr(DE_X[3] + 14, Text_Page_Y + Insert_Y, 40, msg_free_play);
        } else if (Two_Coin_Start) {
            tilemap_print_string(DE_X[3] + 14, Text_Page_Y + Insert_Y, 0xFFFF, &insert_coin_mes[1]);
        } else {
            tilemap_print_string(DE_X[3] + 14, Text_Page_Y + Insert_Y, 0xFFFF, insert_coin_mes + coin_chute1_w.per_credit - 1);
        }
        if (G_No1 == G1_DEMO_PLAY || G_No1 == G1_DEMO_PLAY2) {
            if (Free_Play) {
                tilemap_print_string_attr(DE_X[16] + 2, Text_Page_Y, 40, msg_free_play);
                tilemap_print_string_attr(DE_X[3] + 27, Text_Page_Y, 40, msg_free_play);
            } else if (Two_Coin_Start) {
                tilemap_print_string(DE_X[16] + 2, Text_Page_Y, 0xFFFF, &insert_coin_mes[1]);
                tilemap_print_string(DE_X[3] + 27, Text_Page_Y, 0xFFFF, &insert_coin_mes[1]);
            } else {
                tilemap_print_string(DE_X[16] + 2, Text_Page_Y, 0xFFFF, insert_coin_mes + coin_chute1_w.per_credit - 1);
                tilemap_print_string(DE_X[3] + 27, Text_Page_Y, 0xFFFF, insert_coin_mes + coin_chute1_w.per_credit - 1);
            }
        }
        break;
    case 2:
        if (--E_Timer) {
            break;
        }
        E_No1++;
        E_Timer = 30;
        tilemap_print_string_attr(DE_X[3] + 14, Text_Page_Y + Insert_Y, 40, msg_blank);
        if (G_No1 == G1_DEMO_PLAY || G_No1 == G1_DEMO_PLAY2) {
            tilemap_print_string_attr(DE_X[16] + 2, Text_Page_Y, 40, msg_blank18);
            tilemap_print_string_attr(DE_X[3] + 27, Text_Page_Y, 40, msg_blank18);
        }
        break;
    case 3:
        if (--E_Timer) {
            break;
        }
        E_No1--;
        E_Timer = 50;
        if (Free_Play) {
            tilemap_print_string_attr(DE_X[3] + 14, Text_Page_Y + Insert_Y, 40, msg_free_play);
        } else if (Two_Coin_Start) {
            tilemap_print_string(DE_X[3] + 14, Text_Page_Y + Insert_Y, 0xFFFF, &insert_coin_mes[1]);
        } else {
            tilemap_print_string(DE_X[3] + 14, Text_Page_Y + Insert_Y, 0xFFFF,
                                 insert_coin_mes + coin_chute1_w.per_credit - 1);
        }
        if (G_No1 == G1_DEMO_PLAY || G_No1 == G1_DEMO_PLAY2) {
            if (Free_Play) {
                tilemap_print_string_attr(DE_X[16] + 2, Text_Page_Y, 40, msg_free_play);
                tilemap_print_string_attr(DE_X[3] + 27, Text_Page_Y, 40, msg_free_play);
            } else if (Two_Coin_Start) {
                tilemap_print_string(DE_X[16] + 2, Text_Page_Y, 0xFFFF, &insert_coin_mes[1]);
                tilemap_print_string(DE_X[3] + 27, Text_Page_Y, 0xFFFF, &insert_coin_mes[1]);
            } else {
                tilemap_print_string(DE_X[16] + 2, Text_Page_Y, 0xFFFF, insert_coin_mes + coin_chute1_w.per_credit - 1);
                tilemap_print_string(DE_X[3] + 27, Text_Page_Y, 0xFFFF, insert_coin_mes + coin_chute1_w.per_credit - 1);
            }
        }
        break;
    }
}



void Entry_01(void) {
    switch (E_No1) {
    case 0:
        E_No1++;
        Text_Page_Y = 0;
        credit_display_render(1);
        Disp_Start_Message();
        break;
    case 1:
        if (credit_display_render(0) != 0) {
            Disp_Start_Message();
        }
        if (~p1sw_1 & p1sw_0 & BUTTON_START) {
            if (Pay_Start_Credit(0) != 0) {
                Entry_01_Sub(0);
            }
        } else if (~p2sw_1 & p2sw_0 & BUTTON_START) {
            if (Pay_Start_Credit(1) != 0) {
                Entry_01_Sub(1);
            }
        }
        break;
    case 2:
        if (((u8)Request_E_No)) {
            E_No1++;
        }
        break;
    default:
        Exit_Title_Sub_Entry();
        break;
    }
}



void Entry_01_Sub(s16 PL_id) {
    E_No1++;
    Request_G_No = 1;
    if (Game_setting.Event) {
        plw[0].wu.operator = 1;
        plw[1].wu.operator = 1;
        Operator_Status[0] = 1;
        Operator_Status[1] = 1;
        Ignore_Entry[0] = 0;
        Ignore_Entry[1] = 0;
    } else {
        plw[PL_id].wu.operator = 1;
        Operator_Status[PL_id] = 1;
        Champion = PL_id;
        plw[PL_id ^ 1].wu.operator = 0;
        Operator_Status[PL_id ^ 1] = 0;
        Ignore_Entry[0] = 0;
        Ignore_Entry[1] = 0;
    }
}



void Exit_Title_Sub_Entry(void) {
    s16 i;
    s16 j;
    E_No0 = E0_SELECT;
    E_No1 = 0;
    E_No2 = 0;
    E_No3 = 0;
    F_No1[0] = F_No2[0] = F_No3[0] = 0;
    F_No1[1] = F_No2[1] = F_No3[1] = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            E_Number[i][j] = 0;
        }
    }
}



void Entry_02(void) {
    switch (E_No1) {
    case 0:
        E_No1 += 1;
        Text_Page_Y = 32;
        break;
    }
    Entry_Main_Sub(0, 2);
    Entry_Main_Sub(1, 2);
}



void Entry_03(void) {
    switch (E_No1) {
    case 0:
        Entry_03_1st();
        break;
    default:
        Entry_03_2nd();
        break;
    }
}



void Entry_03_1st(void) {
    switch (E_No2) {
    case 0:
        E_No2 += 1;
        Text_Page_Y = 32;
        break;
    }
    Entry_Main_Sub(0, 4);
    Entry_Main_Sub(1, 4);
}



void Entry_03_2nd(void) {
    switch (E_No2) {
    case 0:
        if (--E_Timer != 0) {
            break;
        }
        E_No2 += 1;
        Switch_Screen_Init(0, 2);
        break;
    case 1:
        if (Switch_Screen() != 0) {
            E_No2 += 1;
            tilemap_clear_rect(DE_X[3], Text_Page_Y + 11, DE_X[3] + 47, Text_Page_Y + 13);
            sc_vram_to_ram();
            Switch_Screen_Init(0, 0);
        }
        break;
    case 2:
        if (Switch_Screen() != 0) {
            Cover_Timer = 23;
            G_No1 = G1_SELECT;
            G_No2 = 0;
            G_No3 = 0;
            E_No0 = E0_SELECT;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            plw[New_Challenger].wu.operator = 1;
            Operator_Status[New_Challenger] = 1;
            Sel_Arts_Complete[Champion] = -1;
        }
        break;
    }
}



void Entry_04(void) {
    switch (E_No1) {
    case 0:
        Entry_04_1st();
        break;
    default:
        Entry_04_2nd();
        break;
    }
}



void Entry_04_1st(void) {
    switch (E_No2) {
    case 0:
        E_No2 += 1;
        Text_Page_Y = 0;
        break;
    }
    Entry_Main_Sub(0, 5);
    Entry_Main_Sub(1, 5);
}



void Entry_04_2nd(void) {
    switch (E_No2) {
    case 0:
        if (--E_Timer) {
            break;
        }
        E_No2 += 1;
        Switch_Screen_Init(0, 2);
        break;
    case 1:
        if (Switch_Screen() != 0) {
            E_No2 += 1;
            tilemap_clear_rect(DE_X[3], Text_Page_Y + 11, DE_X[3] + 47, Text_Page_Y + 13);
            sc_vram_to_ram();
            Switch_Screen_Init(3, 3);
        }
        break;
    default:
        if (Switch_Screen() != 0) {
            Cover_Timer = 23;
            G_No1 = G1_SELECT;
            G_No2 = 0;
            G_No3 = 0;
            if (E_No3 == -1 && Continue_Flag) {
                E_Number[LOSER][0] = ENTRY_CONTINUE;
                E_Number[LOSER][1] = 0;
                E_Number[LOSER][2] = 0;
                E_Number[LOSER][3] = 0;
            } else {
                Correct_BI_Data();
            }
            E_No0 = E0_SELECT;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            Game_pause = 0;
            plw[New_Challenger].wu.operator = 1;
            Operator_Status[New_Challenger] = 1;
        }
        break;
    }
}



void Entry_06(void) {
    switch (E_No1) {
    case 0:
        Entry_06_1st();
        break;
    default:
        Entry_06_2nd();
        break;
    }
}



void Entry_06_1st(void) {
    switch (E_No2) {
    case 0:
        E_No2 += 1;
        Text_Page_Y = 0;
        break;
    }
    Entry_Main_Sub(0, 7);
    Entry_Main_Sub(1, 7);
}



void Entry_06_2nd(void) {
    if (E_07_Flag[0] == 0) {
        Entry_Main_Sub(0, 7);
    }
    if (E_07_Flag[1] == 0) {
        Entry_Main_Sub(1, 7);
    }
    switch (E_No2) {
    case 0:
        E_No2 += 1;
        sc_vram_to_ram();
        Switch_Screen_Init(0, 1);
        break;
    case 1:
        if (Switch_Screen() != 0) {
            E_No2 = E_No2 + 1;
            Cover_Timer = 23;
            Switch_Screen_Init(0, 1);
        }
        break;
    default:
        if (Switch_Screen() != 0) {
            G_No1 = G1_SELECT;
            G_No2 = 0;
            G_No3 = 0;
            E_No0 = E0_SELECT;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            Fade_Flag = 0;
            if (E_07_Flag[0]) {
                plw[0].wu.operator = 1;
                Operator_Status[0] = 1;
            }
            if (E_07_Flag[1]) {
                plw[1].wu.operator = 1;
                Operator_Status[1] = 1;
            }
            E_07_Flag[0] = 0;
            E_07_Flag[1] = 0;
            if (E_Number[LOSER][0] == ENTRY_LOSER) {
                if (Continue_Flag != 0) {
                    E_Number[LOSER][0] = ENTRY_CONTINUE;
                }
            }
        }
        break;
    }
}



void Entry_07(void) {
    switch (E_No1) {
    case 0:
        Entry_07_1st();
        break;
    default:
        Entry_07_2nd();
        break;
    }
}



void Entry_07_1st(void) {
    switch (E_No2) {
    case 0:
        E_No2 += 1;
        Text_Page_Y = 0;
        break;
    }
    Entry_Main_Sub(0, 8);
    Entry_Main_Sub(1, 8);
}



void Entry_07_2nd(void) {
    if (E_07_Flag[0] == 0) {
        Entry_Main_Sub(0, 8);
    }
    if (E_07_Flag[1] == 0) {
        Entry_Main_Sub(1, 8);
    }
    switch (E_No2) {
    case 0:
        if (--E_Timer) {
            break;
        }
        E_No2 = E_No2 + 1;
        sc_vram_to_ram();
        Switch_Screen_Init(0, 1);
        break;
    default:
        if (Switch_Screen() != 0) {
            Cover_Timer = 23;
            G_No1 = G1_SELECT;
            G_No2 = 0;
            G_No3 = 0;
            E_No0 = E0_SELECT;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            if (E_07_Flag[0]) {
                plw[0].wu.operator = 1;
                Operator_Status[0] = 1;
            }
            if (E_07_Flag[1]) {
                plw[1].wu.operator = 1;
                Operator_Status[1] = 1;
            }
            E_07_Flag[0] = 0;
            E_07_Flag[1] = 0;
        }
        break;
    }
}



void Entry_08(void) {
    switch (E_No1) {
    case 0:
        Entry_08_1st();
        break;
    default:
        Entry_08_2nd();
        break;
    }
}



void Entry_08_1st(void) {
    switch (E_No2) {
    case 0:
        E_No2 += 1;
        tilemap_print_string_attr(ENTRY_MSG_X_PAIR(4)[0][Game_setting.Screen_Mode], Text_Page_Y, 40, msg_blank);
        tilemap_print_string_attr(ENTRY_MSG_X_PAIR(4)[1][Game_setting.Screen_Mode], Text_Page_Y, 40, msg_blank);
        if (Game_setting.Event) {
            E_No2 = 99;
        }
    case 1:
        Entry_Main_Sub(0, 9);
        Entry_Main_Sub(1, 9);
        break;
    }
}



void Entry_08_2nd(void) {
    if (E_07_Flag[0] == 0) {
        Entry_Main_Sub(0, 9);
    }
    if (E_07_Flag[1] == 0) {
        Entry_Main_Sub(1, 9);
    }
    switch (E_No2) {
    case 0:
        E_No2 += 1;
        if (E_Number[LOSER][0] == ENTRY_GAME_OVER && E_Number[LOSER][1] == 1) {
            Clear_Personal_Data(LOSER);
        }
        sc_vram_to_ram();
        Switch_Screen_Init(0, 1);
        break;
    default:
        if (Switch_Screen() != 0) {
            Cover_Timer = 23;
            G_No1 = G1_SELECT;
            G_No2 = 0;
            G_No3 = 0;
            E_No0 = E0_SELECT;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            if (E_07_Flag[0]) {
                plw[0].wu.operator = 1;
                Operator_Status[0] = 1;
            }
            if (E_07_Flag[1]) {
                plw[1].wu.operator = 1;
                Operator_Status[1] = 1;
            }
            E_07_Flag[0] = 0;
            E_07_Flag[1] = 0;
            Request_Disp_Rank[0][RANK_SCORE] = -1;
            Request_Disp_Rank[0][RANK_WINS] = -1;
            Request_Disp_Rank[1][RANK_SCORE] = -1;
            Request_Disp_Rank[1][RANK_WINS] = -1;
        }
        break;
    }
}



void Entry_10(void) {
    switch (E_No1) {
    case 0:
        Entry_10_1st();
        break;
    default:
        Entry_10_2nd();
        break;
    }
}



void Entry_10_1st(void) {
    switch (E_No2) {
    case 0:
        E_No2 += 1;
        Text_Page_Y = 0;
        Score[WINNER][SCORE_CPU] += Continue_Coin[WINNER];
        if (Check_Ranking(WINNER) != 0) {
            E_Number[WINNER][0] = ENTRY_NAME;
            E_Number[WINNER][1] = 0;
            E_Number[WINNER][2] = 0;
            E_Number[WINNER][3] = 0;
            Score[WINNER][SCORE_CPU] += Continue_Coin[WINNER];
            Request_Disp_Rank[WINNER][RANK_SCORE] = Rank_In[WINNER][RANK_SCORE];
            Request_Disp_Rank[WINNER][RANK_WINS] = Rank_In[WINNER][RANK_WINS];
        } else {
            E_Number[WINNER][0] = ENTRY_GAME_OVER;
            E_Number[WINNER][1] = 0;
        }
    default:
        Entry_Main_Sub(0, 10);
        Entry_Main_Sub(1, 10);
        break;
    }
}



void Entry_10_2nd(void) {
    if (E_07_Flag[0] == 0) {
        Entry_Main_Sub(0, 10);
    }
    if (E_07_Flag[1] == 0) {
        Entry_Main_Sub(1, 10);
    }
    switch (E_No2) {
    case 0:
        E_No2 += 1;
        if ((E_Number[LOSER][0] == ENTRY_GAME_OVER) && (E_Number[LOSER][1] == 1)) {
            Clear_Personal_Data(LOSER);
        }
        sc_vram_to_ram();
        Switch_Screen_Init(0, 1);
        break;
    default:
        if (Switch_Screen() != 0) {
            Cover_Timer = 23;
            G_No1 = G1_SELECT;
            G_No2 = 0;
            G_No3 = 0;
            E_No0 = E0_SELECT;
            E_No1 = 0;
            E_No2 = 0;
            E_No3 = 0;
            if (E_07_Flag[0]) {
                plw[0].wu.operator = 1;
                Operator_Status[0] = 1;
            }
            if (E_07_Flag[1]) {
                plw[1].wu.operator = 1;
                Operator_Status[1] = 1;
            }
            E_07_Flag[0] = 0;
            E_07_Flag[1] = 0;
            Request_Disp_Rank[0][RANK_SCORE] = -1;
            Request_Disp_Rank[0][RANK_WINS] = -1;
            Request_Disp_Rank[1][RANK_SCORE] = -1;
            Request_Disp_Rank[1][RANK_WINS] = -1;
        }
        break;
    }
}



void Entry_Main_Sub(PL_id, Jump_Index)
s16 PL_id;
s16 Jump_Index;
{
    ENTRY_X = 0;
    switch (E_Number[PL_id][0]) {
    case ENTRY_NONE:
        if (Game_setting.Event) {
            break;
        }
        if (Ignore_Entry[LOSER]) {
            break;
        }
        if (plw[PL_id].wu.operator == 0) {
            Entry_Common_Sub(PL_id, Jump_Index);
        }
        break;
    case ENTRY_CONTINUE:
        if (PL_id) {
            if (Credit_Continue_2P() != 0) {
                Break_Into_Sub(PL_id, Jump_Index);
            }
        } else if (Credit_Continue_1P() != 0) {
            Break_Into_Sub(PL_id, Jump_Index);
        }
        if (Request_Break[PL_id]) {
            E_Number[PL_id][0] = ENTRY_NONE;
            E_Number[PL_id][1] = 0;
            E_Number[PL_id][2] = 0;
            E_Number[PL_id][3] = 0;
        } else if ((E_Number[PL_id][0] == ENTRY_CONTINUE) && (E_07_Flag[PL_id ^ 1] == 0)) {
            Entry_Continue_Sub(PL_id);
        }
        break;
    case ENTRY_NAME:
        switch (E_Number[PL_id][1]) {
        case 0:
            E_Number[PL_id][1] += 1;
            Personal_Timer[PL_id] = 30;
            tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], 0, 40, msg_blank);
            tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], 32, 40, msg_blank);
            break;
        case 1:
            if (--Personal_Timer[PL_id] != 0) {
                break;
            }
            E_Number[PL_id][1] += 1;
            Naming_Init(PL_id);
            commit_name_entry_row_both_players(Text_Page_Y);
            break;
        case 2:
            if (Forbid_Break == 1) {
                break;
            }
            if (PL_id == 0) {
                Naming_Cut_Sub_1P();
            } else {
                Naming_Cut_Sub_2P();
            }
            if (Name_Input(PL_id) == 0) {
                break;
            }
            tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], 0, 40, msg_blank);
            tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], 32, 40, msg_blank);
            Name_In_Sub(PL_id);
            if (Naming_Cut[PL_id]) {
                Clear_Personal_Data(PL_id);
                break;
            }
            E_Number[PL_id][2] = 0;
            E_Number[PL_id][3] = 0;
            if (E_No0 == E0_GAME_OVER) {
                E_Number[PL_id][0] = ENTRY_GAME_OVER;
                E_Number[PL_id][1] = 1;
            } else {
                E_Number[PL_id][0] = ENTRY_GAME_OVER;
                E_Number[PL_id][1] = 0;
            }
            break;
        }
        break;
    case ENTRY_NAME_WAIT:
        switch (E_Number[PL_id][1]) {
        case 0:
            if ((E_No0 != E0_GAME_OVER) && (E_No0 != E0_SELECT)) {
                break;
            }
            E_Number[PL_id][0] = ENTRY_NAME;
            E_Number[PL_id][1] = 2;
            E_Number[PL_id][2] = 0;
            E_Number[PL_id][3] = 0;
            Naming_Init(PL_id);
            tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_blank);
            break;
        case 1:
            if ((E_No0 != E0_GAME_OVER) && (E_No0 != E0_SELECT)) {
                break;
            }
            E_Number[PL_id][0] = ENTRY_GAME_OVER;
            E_Number[PL_id][1] = 1;
            E_Number[PL_id][2] = 0;
            E_Number[PL_id][3] = 0;
            if (E_No0 == E0_SELECT) {
                E_Number[PL_id][1] = 0;
            }
            break;
        }
        break;
    case ENTRY_GAME_OVER:
        switch (E_Number[PL_id][1]) {
        case 0:
            In_Game_Sub(PL_id);
            break;
        case 1:
            In_Over_Sub(PL_id);
            break;
        }
        break;
    case ENTRY_LOSER:
        Loser_Scene_Sub(PL_id, Jump_Index);
        break;
    }
}



void Naming_Init(PL_id)
s16 PL_id;
{
    Naming_Cut[PL_id] = 0;
    Name_00[PL_id] = 0;
    name_wk[PL_id].r_no_0 = 0;
    name_wk[PL_id].r_no_1 = 0;
    end_name_cut[PL_id] = 0;
    name_wk[PL_id].dmm = 0;
}



void Naming_Cut_Sub_1P(void) {
    s8 state;
    if (Naming_Cut[0]) {
        return;
    }
    if (Two_Coin_Start != 0 && Request_Break[0] == 0 && credit_1p < 2) {
        state = 99;
    } else {
        state = Request_Break[0] | credit_1p;
    }
    switch (state) {
    case 0:
        break;
    case 99:
        break;
    default:
        if (Ck_Break_Into_SP(p1sw_0, p1sw_1, 0) != 0) {
            Game_pause = 0;
            Naming_Cut[0] = 1;
            Request_Break[0] = 1;
        }
        break;
    }
}



void Naming_Cut_Sub_2P(void) {
    s8 credit;
    s8 state;
    if (Naming_Cut[1]) {
        return;
    }
    if (Two_Coin_Start != 0 && Request_Break[1] == 0 && credit < 2) {
        state = 99;
    } else {
        state = Request_Break[1] | credit;
    }
    switch (state) {
    case 0:
        break;
    case 99:
        break;
    default:
        if (Ck_Break_Into_SP(p2sw_0, p2sw_1, 1) != 0) {
            Game_pause = 0;
            Naming_Cut[1] = 1;
            Request_Break[1] = 1;
        }
        break;
    }
}



void Name_In_Sub(PL_id)
s16 PL_id;
{
    s16 xx;

    if (Rank_In[PL_id][RANK_SCORE] >= 0) {
        xx = Rank_In[PL_id][RANK_SCORE];
        Ranking_Data[xx].name[0] = rank_name_w[PL_id].code[0];
        Ranking_Data[xx].name[1] = rank_name_w[PL_id].code[1];
        Ranking_Data[xx].name[2] = rank_name_w[PL_id].code[2];
        Ranking_Data[xx].mark = 0;
        if (Special_Enemy[PL_id] == 14) {
            Ranking_Data[xx].mark = 'U';
            return;
        }
        if (Special_Enemy[PL_id] == 15) {
            Ranking_Data[xx].mark = 'V';
            return;
        }
        if (Last_VS_Index[PL_id] > 7) {
            if (Continue_Coin[PL_id]) {
                Ranking_Data[xx].mark = 'J';
            } else {
                Ranking_Data[xx].mark = 'I';
            }
        }
    }
    if (Rank_In[PL_id][RANK_WINS] >= 0) {
        xx = Rank_In[PL_id][RANK_WINS] + 6;
        Ranking_Data[xx].name[0] = rank_name_w[PL_id].code[0];
        Ranking_Data[xx].name[1] = rank_name_w[PL_id].code[1];
        Ranking_Data[xx].name[2] = rank_name_w[PL_id].code[2];
        if (G_No1 == G1_ENDING) {
            if (Continue_Coin[PL_id]) {
                Ranking_Data[xx].mark = 'I';
            } else {
                Ranking_Data[xx].mark = 'H';
            }
        } else {
            Ranking_Data[xx].mark = 0;
        }
    }
}



void Entry_Common_Sub(PL_id, Jump_Index)
s16 PL_id;
s16 Jump_Index;
{
    if (PL_id) {
        if (Credit_Sub_2P() != 0) {
            Break_Into_Sub(PL_id, Jump_Index);
        }
    } else if (Credit_Sub_1P() != 0) {
        Break_Into_Sub(PL_id, Jump_Index);
    }
}



void Loser_Scene_Sub(PL_id, Jump_Index)
s16 PL_id;
s16 Jump_Index;
{
    if (PL_id) {
        if (Loser_Sub_2P() != 0) {
            Break_Into_Sub(PL_id, Jump_Index);
        }
    } else if (Loser_Sub_1P() != 0) {
        Break_Into_Sub(PL_id, Jump_Index);
    }
}



s32 Loser_Sub_1P(void) {
    s8 status;
    if (Two_Coin_Start != 0 && Request_Break[0] == 0 && credit_1p < 2) {
        status = 99;
    } else {
        status = Request_Break[0] | credit_1p;
    }
    switch (status) {
    default:
        if (Ck_Break_Into(p1sw_0, p1sw_1, 0) == 0) {
            if (Request_Break[0]) {
                tilemap_print_string_attr(DE_X[Entry_Mes_Wide[0]] + Entry_Mes_X[0], Text_Page_Y, 40, msg_blank);
            } else if (LOSER == 0) {
                tilemap_print_string_attr(DE_X[Entry_Mes_Wide[0]] + Entry_Mes_X[0], Text_Page_Y, 40, msg_continue);
            } else {
                Flash_Start(0, Entry_Msg_X_Data[2][Game_setting.Screen_Mode]);
            }
        }
        break;
    }
    return ENTRY_X;
}



s32 Loser_Sub_2P(void) {
    s8 credits;
    s8 status;
    if (Chute_Mode < 2) {
        credits = credit_1p;
    } else {
        credits = credit_2p;
    }
    if (Two_Coin_Start != 0 && Request_Break[1] == 0 && credits < 2) {
        status = 99;
    } else {
        status = Request_Break[1] | credits;
    }
    switch (status) {
    default:
        if (Ck_Break_Into(p2sw_0, p2sw_1, 1) == 0) {
            if (Request_Break[1]) {
                tilemap_print_string_attr(DE_X[Entry_Mes_Wide[1]] + Entry_Mes_X[1], Text_Page_Y, 40, msg_blank);
            } else if (LOSER == 1) {
                tilemap_print_string_attr(DE_X[Entry_Mes_Wide[1]] + Entry_Mes_X[1], Text_Page_Y, 40, msg_continue);
            } else {
                Flash_Start(1, Entry_Msg_X_Data[3][Game_setting.Screen_Mode]);
            }
        }
        break;
    }
    return ENTRY_X;
}



s32 Credit_Sub_1P(void) {
    s8 status;
    if (Two_Coin_Start != 0 && Request_Break[0] == 0 && credit_1p < 2) {
        status = 99;
    } else {
        status = Request_Break[0] | credit_1p;
    }
    switch (status) {
    case 0:
        if (coin_chute1_w.count) {
            Flash_More_Coins(0, Entry_Msg_X_Data[4][Game_setting.Screen_Mode], (s8)(coin_chute1_w.per_credit - coin_chute1_w.count));
        } else {
            Flash_Insert_Coin(0, Entry_Msg_X_Data[0][Game_setting.Screen_Mode]);
        }
        break;
    case 99:
        if (credit_1p) {
            Flash_More_Coins(0, Entry_Msg_X_Data[4][Game_setting.Screen_Mode], 1);
        } else {
            Flash_Insert_Coin(0, Entry_Msg_X_Data[0][Game_setting.Screen_Mode]);
        }
        break;
    default:
        if (Ck_Break_Into(p1sw_0, p1sw_1, 0) == 0) {
            if (Request_Break[0]) {
                Flash_Please(0);
            } else {
                Flash_Start(0, Entry_Msg_X_Data[2][Game_setting.Screen_Mode]);
            }
        }
        break;
    }
    return ENTRY_X;
}



s32 Credit_Sub_2P(void) {
    s8 credits;
    s8 status;
    if (Chute_Mode < 2) {
        credits = credit_1p;
    } else {
        credits = credit_2p;
    }
    if (Two_Coin_Start != 0 && Request_Break[1] == 0 && credits < 2) {
        status = 99;
    } else {
        status = Request_Break[1] | credits;
    }
    switch (status) {
    case 0:
        if (Get_2P_Coin_Count()) {
            if (Chute_Mode < 2) {
                Flash_More_Coins(1, Entry_Msg_X_Data[5][Game_setting.Screen_Mode], (s8)(coin_chute1_w.per_credit - coin_chute1_w.count));
            } else {
                Flash_More_Coins(1, Entry_Msg_X_Data[5][Game_setting.Screen_Mode], (s8)(coin_chute2_w.per_credit - coin_chute2_w.count));
            }
        } else {
            Flash_Insert_Coin(1, Entry_Msg_X_Data[1][Game_setting.Screen_Mode]);
        }
        break;
    case 99:
        if (credits != 0) {
            Flash_More_Coins(1, Entry_Msg_X_Data[5][Game_setting.Screen_Mode], 1);
        } else {
            Flash_Insert_Coin(1, Entry_Msg_X_Data[1][Game_setting.Screen_Mode]);
        }
        break;
    default:
        if (Ck_Break_Into(p2sw_0, p2sw_1, 1) == 0) {
            if (Request_Break[1]) {
                Flash_Please(1);
            } else {
                Flash_Start(1, Entry_Msg_X_Data[3][Game_setting.Screen_Mode]);
            }
        }
        break;
    }
    return ENTRY_X;
}



s32 Credit_Continue_1P(void) {
    s8 state;
    state = Request_Break[0] | credit_1p;
    switch (state) {
    case 0:
        return 0;
        break;
    default:
        Ck_Break_Into(p1sw_0, p1sw_1, 0);
        break;
    }
    return ENTRY_X;
}



s32 Credit_Continue_2P(void) {
    s8 state;
    if (Chute_Mode < 2) {
        state = Request_Break[1] | credit_1p;
    } else {
        state = Request_Break[1] | credit_2p;
    }
    switch (state) {
    case 0:
        return 0;
        break;
    default:
        Ck_Break_Into(p2sw_0, p2sw_1, 1);
        break;
    }
    return ENTRY_X;
}



void Entry_Continue_Sub(PL_id)
s16 PL_id;
{
    switch (E_Number[PL_id][1]) {
    case 0:
        E_Number[PL_id][1]++;
        Personal_Disp_Flag = 1;
        Personal_Timer[PL_id] = 70;
        tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_continue_cnt);
        Disp_Personal_Count(PL_id, Continue_Count[PL_id]);
        break;
    case 1:
        if (Personal_Disp_Flag == 0) {
            Personal_Disp_Flag = 1;
            Personal_Timer[PL_id] = 70;
            tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_continue_cnt);
            Disp_Personal_Count(PL_id, Continue_Count[PL_id]);
        }
        if (Check_Coin_In(PL_id) != 0) {
            Continue_Count[PL_id] = 10;
            Personal_Timer[PL_id] = 1;
        }
        if (Check_Count_Cut(PL_id, 8) == 0) {
            if (--Personal_Timer[PL_id] != 0) {
                break;
            }
        }
        if (--Continue_Count[PL_id] >= 0) {
            Personal_Timer[PL_id] = 70;
            Disp_Personal_Count(PL_id, Continue_Count[PL_id]);
            break;
        }
        Setup_Next_Step(PL_id);
        break;
    }
}



void Setup_Next_Step(PL_id)
s16 PL_id;
{
    s16 xx;
    E_Number[PL_id][1] = 0;
    E_Number[PL_id][2] = 0;
    E_Number[PL_id][3] = 0;
    Score[PL_id][SCORE_CPU] += Continue_Coin[PL_id];
    for (xx = 0; xx < 16; xx++) {
        Break_Com[PL_id][xx] = 0;
    }
    if (E_No0 != E0_CONTINUE) {
        tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_blank);
        if (Check_Ranking(PL_id) != 0) {
            E_Number[PL_id][0] = ENTRY_NAME;
            if (E_No0 == E0_LOSER) {
                Request_Disp_Rank[PL_id][RANK_SCORE] = Rank_In[PL_id][RANK_SCORE];
                Request_Disp_Rank[PL_id][RANK_WINS] = Rank_In[PL_id][RANK_WINS];
            }
            return;
        }
        E_Number[PL_id][0] = ENTRY_GAME_OVER;
        E_Number[PL_id][1] = 0;
        return;
    } else {
        if (Check_Ranking(PL_id) != 0) {
            Request_Disp_Rank[PL_id][RANK_SCORE] = Rank_In[PL_id][RANK_SCORE];
            Request_Disp_Rank[PL_id][RANK_WINS] = Rank_In[PL_id][RANK_WINS];
            if (E_Number[PL_id ^ 1][0] != ENTRY_NONE) {
                E_Number[PL_id][0] = ENTRY_NAME;
                return;
            }
            E_Number[PL_id][0] = ENTRY_NAME_WAIT;
            E_Number[PL_id][1] = 0;
            return;
        } else {
            if (E_Number[PL_id ^ 1][0] != ENTRY_NONE) {
                E_Number[PL_id][0] = ENTRY_GAME_OVER;
                E_Number[PL_id][1] = 0;
            } else {
                E_Number[PL_id][0] = ENTRY_NAME_WAIT;
                E_Number[PL_id][1] = 1;
            }
        }
    }
}



void In_Game_Sub(PL_id)
s16 PL_id;
{
    switch (E_Number[PL_id][2]) {
    case 0:
        E_Number[PL_id][2]++;
        Personal_Timer[PL_id] = 30;
        if (Game_setting.Event == 0) {
            tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40, msg_blank);
        }
        break;
    case 1:
        if (--Personal_Timer[PL_id] == 0) {
            E_Number[PL_id][2]++;
            Personal_Timer[PL_id] = 60;
            if (Game_setting.Event == 0) {
                tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40, msg_blank);
            }
        }
        break;
    case 2:
        if (Personal_Disp_Flag == 0) {
            Personal_Disp_Flag = 1;
            if (Personal_Timer[PL_id] < 20) {
                Personal_Timer[PL_id] = 20;
            }
            if (Game_setting.Event == 0) {
                tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40, (s8*)msg_game_over);
            }
        }
        if (--Personal_Timer[PL_id]) {
            break;
        }
        E_Number[PL_id][2]++;
        Personal_Timer[PL_id] = 30;
        if (Game_setting.Event == 0) {
            tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40, (s8*)msg_game_over);
        }
        break;
    default:
        if (--Personal_Timer[PL_id] == 0) {
            Clear_Personal_Data(PL_id);
            Clear_Flash_No();
        }
        break;
    }
}



void In_Over_Sub(PL_id)
s16 PL_id;
{
    switch (E_Number[PL_id][2]) {
    case 0:
        E_Number[PL_id][2]++;
        tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40,
                                  (s8*)msg_game_over);
        break;
    default:
        break;
    }
}


s32 Flash_Insert_Coin(PL_id)
s16 PL_id;
{
    if (E_No0 == E0_LOSER || E_No0 == E0_GAME_OVER || E_No0 == E0_CONTINUE) {
        tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40,
                                  msg_blank);
        return 0;
    }
    switch (F_No0[PL_id]) {
    case 0:
        F_No0[PL_id] += 1;
        F_No1[PL_id] = F_No2[PL_id] = 0;
        F_Timer[PL_id] = 1;
        tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40,
                                  msg_blank);
        break;
    case 1:
        if (--F_Timer[PL_id] != 0) {
            break;
        }
        F_No0[PL_id] += 1;
        F_Timer[PL_id] = 50;
        if (Two_Coin_Start) {
            tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40,
                                      (s8*)msg_insert_2coins);
            break;
        }
        if (coin_chute1_w.per_credit == 1) {
            tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40,
                                      (s8*)msg_insert_coin);
        } else {
            tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40,
                                      (s8*)msg_insert_coins);
            tilemap_print_hex_block(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]] + 10, Text_Page_Y, 40,
                                         coin_chute1_w.per_credit, 1, 1);
        }
        break;
    case 2:
        if (--F_Timer[PL_id] != 0) {
            break;
        }
        F_No0[PL_id] -= 1;
        F_Timer[PL_id] = 50;
        tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40,
                                  (s8*)msg_join_in);
    }
    return 0;
}


s32 Flash_Start(PL_id, x)
s16 PL_id;
u16 x;
{
    switch (F_No1[PL_id]) {
    case 0:
        F_No1[PL_id] += 1;
        F_No0[PL_id] = 0;
        F_No2[PL_id] = 0;
        F_No3[PL_id] = 0;
        F_Timer[PL_id] = 1;
        tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40, msg_blank);
        if (E_No0 == E0_LOSER && PL_id == LOSER) {
            if (Continue_Flag) {
                F_No1[PL_id] = 3;
            }
        }
        break;
    case 1:
        if (--F_Timer[PL_id]) {
            break;
        }
        F_No1[PL_id] += 1;
        F_Timer[PL_id] = 50;
        if (Free_Play) {
            tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_free_play);
            break;
        } else {
            tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, PL_id ? msg_press_2p_start : msg_press_1p_start);
        }
        break;
    case 2:
        if (--F_Timer[PL_id]) {
            break;
        }
        F_No1[PL_id] -= 1;
        F_Timer[PL_id] = 30;
        tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_blank);
        break;
    case 3:
        F_No1[PL_id] = 99;
        tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_continue);
        break;
    }
    return 0;
}



s32 Flash_Please(PL_id)
s16 PL_id;
{
    if (E_No0 == E0_LOSER || E_No0 == E0_GAME_OVER) {
        return 0;
    }
    switch (F_No3[PL_id]) {
    case 0:
        F_No3[PL_id] += 1;
        F_No1[PL_id] = 0;
        F_Timer[PL_id] = 1;
        tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40, msg_blank);
        break;
    case 1:
        if (--F_Timer[PL_id] == 0) {
            F_No3[PL_id] += 1;
            F_Timer[PL_id] = 50;
            tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40, msg_please_wait);
        }
        break;
    default:
        if (--F_Timer[PL_id] == 0) {
            F_No3[PL_id] -= 1;
            F_Timer[PL_id] = 30;
            tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40, msg_blank);
        }
        break;
    }
    return 0;
}



#pragma inline(flash_pos_disp)
static void flash_pos_disp(s16 x, s16 y) {}

s32 Flash_More_Coins(PL_id, unused, coins)
s16 PL_id;
s16 unused;
s8 coins;
{
    s32 count = coins;
    switch (F_No2[PL_id]) {
    case 0:
        F_No2[PL_id] += 1;
        F_No0[PL_id] = F_No1[PL_id] = 0;
        F_Timer[PL_id] = 1;
        (void)tilemap_print_string_attr;
        flash_pos_disp(Entry_Mes_X[PL_id], Text_Page_Y);
        tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40,
                                  msg_blank);
        if (E_No0 == E0_LOSER && PL_id == LOSER) {
            F_No2[PL_id] = 3;
        }
        break;
    case 1:
        if (Disp_More_Coins(PL_id, unused, count) == 0) {
            if (--F_Timer[PL_id] == 0) {
                F_No2[PL_id] += 1;
                F_Timer[PL_id] = 50;
                if (count == 1) {
                    tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40,
                                              msg_insert_more_coin);
                } else {
                    tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40,
                                              msg_insert_more_coins);
                }
                tilemap_print_hex_block(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]] + 7, Text_Page_Y, 40,
                                        count, 1, 1);
            }
        } else {
            F_No2[PL_id] += 1;
        }
        break;
    case 2:
        Disp_More_Coins(PL_id, unused, count);
        if (--F_Timer[PL_id] == 0) {
            F_No2[PL_id] -= 1;
            F_Timer[PL_id] = 30;
            tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40,
                                      msg_blank);
        }
        break;
    }
    return 0;
}



s32 Disp_More_Coins(PL_id, unused, coins)
s16 PL_id;
s16 unused;
s16 coins;
{
    if (Check_Coin_In(PL_id) != 0) {
        if (coins == 1) {
            tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40,
                                      msg_insert_more_coin);
        } else {
            tilemap_print_string_attr(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]], Text_Page_Y, 40,
                                      msg_insert_more_coins);
        }
        tilemap_print_hex_block(Entry_Mes_X[PL_id] + DE_X[Entry_Mes_Wide[PL_id]] + 7, Text_Page_Y, 40, (s8)coins,
                                     1, 1);
        F_Timer[PL_id] = 50;
        return 1;
    }
    return 0;
}



s32 Get_2P_Coin_Count(void) {
    switch (Chute_Mode) {
    case 0:
    case 1:
        return coin_chute1_w.count;
    default:
        return coin_chute2_w.count;
    }
}



s32 credit_display_render(s8 force) {
    COINCHUTE* chute = &coin_chute1_w;
    s32 per;
    s8 two_coin;
    const s8* msg;
    s16* dx;
    if ((force | chute->dropped | coin_chute2_w.dropped) == 0) {
        return 0;
    }
    switch (per = chute->per_credit, two_coin = Two_Coin_Start, dx = DE_X, Chute_Mode) {
    case 0:
    case 1:
        switch (per) {
        case 0:
        case 1:
            if (two_coin != 0) {
                tilemap_print_string_attr(dx[0] + 21, 23, 40, &msg_coins);
                tilemap_print_hex_block(dx[0] + 27, 23, 40, credit_1p, 1, 1);
            } else {
                tilemap_print_string_attr(dx[0] + 20, 23, 40, &msg_credit);
                if (credit_1p >= 2) {
                    tilemap_print_string_attr(DE_X[0] + 26, 23, 40, msg_plural_s);
                }
                tilemap_print_hex_block(DE_X[0] + 28, 23, 40, credit_1p, 1, 1);
            }
            break;
        default:
            tilemap_print_string_attr(dx[0] + 18, 23, 40, &msg_credits);
            if (credit_1p < 2) {
                tilemap_print_string_attr(DE_X[0] + 24, 23, 40, msg_space);
            }
            tilemap_print_hex_block(DE_X[0] + 26, 23, 40, credit_1p, 1, 1);
            if (credit_1p >= 9) {
                tilemap_print_string_attr(DE_X[0] + 27, 23, 40, msg_blank6);
            } else {
                tilemap_print_string_attr(DE_X[0] + 27, 23, 40, msg_coin_frac);
                tilemap_print_hex_block(DE_X[0] + 28, 23, 40, chute->count, 1, 1);
                tilemap_print_hex_block(DE_X[0] + 30, 23, 40, chute->per_credit, 1, 1);
            }
            break;
        }
        break;
    default:
        switch (per) {
        case 0:
        case 1:
            if (two_coin != 0) {
                tilemap_print_string_attr(dx[0] + 5, 23, 40, &msg_coins);
                tilemap_print_hex_block(dx[0] + 11, 23, 40, credit_1p, 1, 1);
                tilemap_print_string_attr(dx[0] + 31, 23, 40, &msg_coins);
                tilemap_print_hex_block(dx[0] + 37, 23, 40, credit_2p, 1, 1);
            } else {
                msg = (credit_1p < 2) ? &msg_credit : &msg_credits;
                tilemap_print_string_attr(dx[0] + 6, 23, 40, msg);
                tilemap_print_hex_block(DE_X[0] + 14, 23, 40, credit_1p, 1, 1);
                if (credit_2p < 2) {
                    tilemap_print_string_attr(DE_X[0] + 32, 23, 40, &msg_credit);
                } else {
                    tilemap_print_string_attr(DE_X[0] + 32, 23, 40, &msg_credits);
                }
                tilemap_print_hex_block(DE_X[0] + 40, 23, 40, credit_2p, 1, 1);
            }
            break;
        default:
            if (credit_1p < 2) {
                tilemap_print_string_attr(dx[0] + 5, 23, 40, &msg_credit);
            } else {
                tilemap_print_string_attr(dx[0] + 5, 23, 40, &msg_credits);
            }
            tilemap_print_hex_block(DE_X[0] + 13, 23, 40, credit_1p, 1, 1);
            if (credit_1p >= 9) {
                tilemap_print_string_attr(DE_X[0] + 14, 23, 40, msg_blank6);
            } else {
                tilemap_print_string_attr(DE_X[0] + 14, 23, 40, msg_coin_frac);
                tilemap_print_hex_block(DE_X[0] + 15, 23, 40, chute->count, 1, 1);
                tilemap_print_hex_block(DE_X[0] + 17, 23, 40, chute->per_credit, 1, 1);
            }
            if (credit_2p < 2) {
                tilemap_print_string_attr(DE_X[0] + 30, 23, 40, &msg_credit);
            } else {
                tilemap_print_string_attr(DE_X[0] + 30, 23, 40, &msg_credits);
            }
            tilemap_print_hex_block(DE_X[0] + 38, 23, 40, credit_2p, 1, 1);
            if (credit_2p >= 9) {
                tilemap_print_string_attr(DE_X[0] + 39, 23, 40, msg_blank6);
            } else {
                tilemap_print_string_attr(DE_X[0] + 39, 23, 40, msg_coin_frac);
                tilemap_print_hex_block(DE_X[0] + 40, 23, 40, coin_chute2_w.count, 1, 1);
                tilemap_print_hex_block(DE_X[0] + 42, 23, 40, coin_chute2_w.per_credit, 1, 1);
            }
            break;
        }
        break;
    }
    return 1;
}



void Disp_Start_Message(void) {
    s8 credits;
    s8 coins;
    s8 needed;
    const s8* blank;
    const s8* one_more;
    if (Two_Coin_Start != 0 && credit_1p < 2) {
        credits = 99;
    } else {
        credits = credit_1p;
    }
    one_more = msg_insert_1_more;
    blank = msg_blank25;
    switch (Chute_Mode) {
    case 0:
    case 1:
        switch (credits) {
        case 0:
            needed = coin_chute1_w.per_credit - coin_chute1_w.count;
            tilemap_print_string_attr(DE_X[0] + 12, 18, 40, blank);
            if (needed == 1) {
                tilemap_print_string_attr(DE_X[0] + 15, 18, 40, msg_insert_more_coin);
            } else {
                tilemap_print_string_attr(DE_X[0] + 15, 18, 40, msg_insert_more_coins);
            }
            tilemap_print_hex_block(DE_X[0] + 22, 18, 40, needed, 1, 1);
            break;
        case 99:
            tilemap_print_string_attr(DE_X[0] + 15, 18, 40, one_more);
            break;
        default:
            tilemap_print_string_attr(DE_X[0] + 12, 18, 40, msg_press_1or2_start);
            break;
        }
        return;
    default:
        switch (credits) {
        case 0:
            tilemap_print_string_attr(DE_X[0] + 2, 18, 40, blank);
            coins = coin_chute1_w.count;
            needed = coin_chute1_w.per_credit - coins;
            if (coins) {
                if (needed == 1) {
                    tilemap_print_string_attr(DE_X[0] + 2, 18, 40, msg_insert_more_coin);
                } else {
                    tilemap_print_string_attr(DE_X[0] + 2, 18, 40, msg_insert_more_coins);
                }
                tilemap_print_hex_block(DE_X[0] + 9, 18, 40, needed, 1, 1);
            } else {
                tilemap_print_string(6, 18, 0xFFFF, insert_coin_mes + coin_chute1_w.per_credit - 1);
            }
            break;
        case 99:
            if (credit_1p) {
                tilemap_print_string_attr(DE_X[0] + 2, 18, 40, one_more);
            } else {
                tilemap_print_string_attr(DE_X[0] + 2, 18, 40, msg_insert_2_more);
            }
            break;
        default:
            tilemap_print_string_attr(DE_X[0] + 2, 18, 40, msg_press_1p_button);
            break;
        }
    }
    if (Two_Coin_Start != 0 && credit_2p < 2) {
        credits = 99;
    } else {
        credits = credit_2p;
    }
    switch (credits) {
    case 0:
        tilemap_print_string_attr(DE_X[0] + 25, 18, 40, blank);
        coins = coin_chute2_w.count;
        needed = coin_chute2_w.per_credit - coins;
        if (coins) {
            if (needed == 1) {
                tilemap_print_string_attr(DE_X[0] + 25, 18, 40, msg_insert_more_coin);
            } else {
                tilemap_print_string_attr(DE_X[0] + 25, 18, 40, msg_insert_more_coins);
            }
            tilemap_print_hex_block(DE_X[0] + 32, 18, 40, needed, 1, 1);
        } else {
            tilemap_print_string(DE_X[4] + 29, 18, 0xFFFF, insert_coin_mes + coin_chute1_w.per_credit - 1);
        }
        break;
    case 99:
        if (credit_2p) {
            tilemap_print_string_attr(DE_X[0] + 25, 18, 40, one_more);
        } else {
            tilemap_print_string_attr(DE_X[0] + 25, 18, 40, msg_insert_2_more);
        }
        break;
    default:
        tilemap_print_string_attr(DE_X[0] + 25, 18, 40, msg_press_2p_button);
        break;
    }
}



void Break_Into_Sub(PL_id, Jump_Index)
s16 PL_id;
s16 Jump_Index;
{
    switch (Jump_Index) {
    case 0:
    case 1:
    case 2:
    case 3:
        Break_Into_02(PL_id);
        break;
    case 4:
    case 6:
        Break_Into_04(PL_id);
        break;
    case 5:
        Break_Into_05(PL_id);
        break;
    case 7:
        Break_Into_07(PL_id);
        break;
    case 8:
        Break_Into_08(PL_id);
        break;
    case 9:
        Break_Into_09(PL_id);
        break;
    case 10:
        Break_Into_10(PL_id);
        break;
    default:
        break;
    }
}



s32 Ck_Break_Into(Sw_0, Sw_1, PL_id)
u16 Sw_0;
u16 Sw_1;
s16 PL_id;
{
    if (Request_Break[PL_id]) {
        if (Forbid_Break || Extra_Break) {
            return 0;
        }
        Game_pause = 1;
        New_Challenger = PL_id;
        Champion = New_Challenger ^ 1;
        Request_Break[PL_id] = 0;
        return ENTRY_X = 1;
    } else {
        if (!(~Sw_1 & Sw_0 & 0x1000)) {
            return 0;
        }
        if (!Pay_Start_Credit(PL_id)) {
            return 0;
        }
        if (E_No0 == E0_LOSER) {
            effect_58_init(6, 1, 116);
        }
        if (Forbid_Break || Extra_Break) {
            Request_Break[PL_id] = 1;
            tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_blank);
        } else {
            Game_pause = 1;
            New_Challenger = PL_id;
            Champion = New_Challenger ^ 1;
            return ENTRY_X = 1;
        }
        return 0;
    }
}



s32 Ck_Break_Into_SP(Sw_0, Sw_1, PL_id)
u16 Sw_0;
u16 Sw_1;
s16 PL_id;
{
    if (!(~Sw_1 & Sw_0 & 0x1000)) {
        return 0;
    }
    if (!Pay_Start_Credit(PL_id)) {
        return 0;
    }
    New_Challenger = PL_id;
    Champion = New_Challenger ^ 1;
    return ENTRY_X = 1;
}



s32 Pay_Start_Credit(PL_id)
s16 PL_id;
{
    s8* credit;
    if (Free_Play) {
        bookkeep_freeplay_count();
        return 1;
    }
    if (E_Number[PL_id][0] == ENTRY_CONTINUE || E_Number[PL_id][0] == ENTRY_LOSER) {
        return (s8)credit_use(PL_id);
    }
    if (Two_Coin_Start) {
        switch (Chute_Mode) {
        case 0:
        case 1:
            if (credit_1p < 2) {
                return 0;
            } else {
                credit_1p -= 2;
                return 1;
            }
            break;
        default:
            if (PL_id) {
                credit = &credit_2p;
            } else {
                credit = &credit_1p;
            }
            if (*credit < 2) {
                return 0;
            } else {
                *credit -= 2;
                return 1;
            }
            break;
        }
    } else {
        return (s8)credit_use(PL_id);
    }
}



void Break_Into_02(PL_id)
s16 PL_id;
{
    Continue_Score_Sub(PL_id);
    plw[New_Challenger].wu.operator = 1;
    Operator_Status[New_Challenger] = 1;
    E_Number[New_Challenger][0] = ENTRY_NONE;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;
    tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_blank);
    Select_Timer = 32;
    Unit_Of_Timer = 50;
}



void Break_Into_04(PL_id)
s16 PL_id;
{
    Continue_Score_Sub(PL_id);
    Break_Into = 1;
    E_No1++;
    E_No2 = 0;
    E_Timer = 150;
    E_Number[New_Challenger][0] = ENTRY_NONE;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;
    effect_56_init(0);
    effect_A2_init(0);
    bgm_request(6);
    effect_58_init(6, 30, 160);
    tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_blank);
}



void Break_Into_05(PL_id)
s16 PL_id;
{
    Continue_Score_Sub(PL_id);
    Break_Into = 1;
    Stop_Combo = 1;
    E_No1 = E_No1 + 1;
    E_No2 = 0;
    E_Number[New_Challenger][0] = ENTRY_NONE;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;
    if ((Play_Type == PLAY_VS_CPU) && (Conclusion_Flag != 0) && (plw[Champion].wu.operator == 0)) {
        E_Timer = 1;
        if (LOSER != New_Challenger) {
            E_No3 = -1;
        } else {
            E_No3 = 0;
        }
    } else {
        E_Timer = 150;
        if (Conclusion_Flag == 0) {
            Score[Champion][SCORE_CPU] = Stage_Stock_Score[Champion];
        }
        effect_56_init(0);
        effect_A2_init(0);
        bgm_request(6);
        effect_58_init(6, 30, 160);
    }
    tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_blank);
}



void Break_Into_07(PL_id)
s16 PL_id;
{
    Continue_Score_Sub(PL_id);
    E_Number[New_Challenger][0] = ENTRY_NONE;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;
    E_07_Flag[PL_id] = 1;
    if (E_07_Flag[0] != 0 && E_07_Flag[1] != 0) {
        return;
    }
    E_No1 = E_No1 + 1;
    E_No2 = 0;
    Break_Into = 1;
}



void Break_Into_08(PL_id)
s16 PL_id;
{
    tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_blank);
    Continue_Score_Sub(PL_id);
    E_Number[New_Challenger][0] = ENTRY_NONE;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;
    E_07_Flag[PL_id] = 1;
    if (E_07_Flag[0] == 0 || E_07_Flag[1] == 0) {
        Break_Into = -1;
        E_No1++;
        E_No2 = 0;
        if (Continue_Count[PL_id ^ 1] >= 0) {
            E_Timer = 60;
            effect_58_init(6, 1, 116);
        } else {
            E_Timer = 10;
        }
        kill_tasks_by_func(continue_task);
    }
}



void Break_Into_09(PL_id)
s16 PL_id;
{
    tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_blank);
    E_Number[New_Challenger][0] = ENTRY_NONE;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;
    E_07_Flag[PL_id] = 1;
    if (E_07_Flag[0] != 0 && E_07_Flag[1] != 0) {
        return;
    }
    Break_Into = -1;
    E_No1 += 1;
    E_No2 = 0;
    Champion = New_Challenger;
}



void Break_Into_10(PL_id)
s16 PL_id;
{
    tilemap_print_string_attr(DE_X[Entry_Mes_Wide[PL_id]] + Entry_Mes_X[PL_id], Text_Page_Y, 40, msg_blank);
    E_Number[New_Challenger][0] = ENTRY_NONE;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;
    E_07_Flag[PL_id] = 1;
    if (E_07_Flag[0] != 0 && E_07_Flag[1] != 0) {
        return;
    }
    Break_Into = -1;
    E_No1 += 1;
    E_No2 = 0;
    Champion = New_Challenger;
}



void Continue_Score_Sub(PL_id)
s16 PL_id;
{
    if ((E_Number[PL_id][0] == ENTRY_CONTINUE) || (E_Number[PL_id][0] == ENTRY_LOSER)) {
        Continue_Coin[PL_id] += 1;
        Score[PL_id][SCORE_CPU] = Stage_Stock_Score[PL_id];
        if (Continue_Coin[PL_id] >= 99) {
            Continue_Coin[PL_id] = 99;
        }
    }
}



void Correct_BI_Data(void) {
    Super_Arts_Finish[Player_id] -= Stage_SA_Finish[Player_id];
    Lost_Round[Player_id] -= Stage_Lost_Round[Player_id];
    Perfect_Finish[Player_id] -= Stage_Perfect_Finish[Player_id];
    Cheap_Finish[Player_id] -= Stage_Cheap_Finish[Player_id];
}



void coin_in_sound_request(void) {
    if (coin_chute1_w.dropped | coin_chute2_w.dropped) {
        if (Demo_Flag == 1) {
            sound_request(E_No0 == E0_TITLE ? 115 : 106);
        }
    }
}



void Redisp_Continue_Count(s16 pl_id) {
    if (E_Number[pl_id][0] == ENTRY_CONTINUE) {
        tilemap_print_string_attr(DE_X[Entry_Mes_Wide[pl_id]] + Entry_Mes_X[pl_id], Text_Page_Y, 40, msg_continue);
        Disp_Personal_Count(pl_id, Continue_Count[pl_id]);
    }
}
