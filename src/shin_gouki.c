/*
 * shin_gouki.c  Shin Gouki: the challenger checks (provisional name)
 *
 * Character 15 (Shin Gouki, a copy of Gouki's attack routines: plpat15) can be the
 * next opponent. Check_Shin_Gouki_Next says whether the player's next candidate is him (never in
 * a versus game), Get_Stage_Shin_Gouki gives the stage to load (his own, 15, when the computer
 * plays him) and Init_Sel_Command clears the select-screen command input that calls him, which
 * the bonus setting can switch off.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EM_Cand.h"
#include "fighter.h"



/* provisional name */
s32 Check_Shin_Gouki_Next(void) {
    if (Play_Type == PLAY_VS_PLAYER) {
        return 0;
    }
    if (EM_Candidate[Player_id][VS_Index[Player_id]] == 15) {
        return 1;
    }
    return 0;
}



/* provisional name */
s32 Get_Stage_Shin_Gouki(void) {
    if (Play_Type == PLAY_VS_PLAYER) {
        return (u16)bg_w.stage;
    }
    if (My_char[COM_id] == PL_GOUKI2) {
        return 15;
    }
    return (u16)bg_w.stage;
}



/* provisional name */
void Init_Sel_Command(void) {
    if (Game_setting.Bonus_Game & 2) {
        Gouki_Select_Open = 1;
    } else {
        Gouki_Select_Open = 0;
    }
    Sel_Command_Step[0] = 0;
    Sel_Command_Step[1] = 0;
    Sel_Command_Key[0] = 0;
    Sel_Command_Key[1] = 0;
}
