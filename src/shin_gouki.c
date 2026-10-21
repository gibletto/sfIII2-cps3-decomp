/*
 * shin_gouki.c  Shin Gouki: the challenger checks (2nd Impact only; provisional name)
 *
 * 2nd Impact's character 15 (Shin Gouki, a copy of Gouki's attack routines: plpat15) can be the
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



/* provisional name */
s32 Check_Shin_Gouki_Next(void) {
    if (Play_Type == 1) {
        return 0;
    }
    if (EM_Candidate[Player_id][VS_Index[Player_id]] == 15) {
        return 1;
    }
    return 0;
}



/* provisional name */
s32 Get_Stage_Shin_Gouki(void) {
    if (Play_Type == 1) {
        return (u16)bg_w.stage;
    }
    if (My_char[COM_id] == 15) {
        return 15;
    }
    return (u16)bg_w.stage;
}



/* provisional name */
void Init_Sel_Command(void) {
    if (Game_setting.bonus & 2) {
        Sel_Command_Off = 1;
    } else {
        Sel_Command_Off = 0;
    }
    Sel_Command_Step[0] = 0;
    Sel_Command_Step[1] = 0;
    Sel_Command_Key[0] = 0;
    Sel_Command_Key[1] = 0;
}
