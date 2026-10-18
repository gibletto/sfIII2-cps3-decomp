#ifndef EFF79_H
#define EFF79_H

#include "structs.h"

s32 Check_Depth_to_Before();
s32 Check_Play_Status_79(WORK_Other* ewk);
void Check_Speed_79(WORK_Other* ewk);
s32 EFF79_Move_X(WORK_Other* ewk);
s32 EFF79_Move_Y(WORK_Other* ewk);
void Check_Priority(WORK_Other* ewk);
void Move_79(WORK_Other* ewk);
void Move_Move_79(WORK_Other* ewk);
s32 Move_X_Sub(WORK_Other* ewk, s16 Target_X, s16 cut);
s32 Move_Y_Sub(WORK_Other* ewk, s16 Target_Y, u16 cut);
void Setup_Command_Name(WORK_Other* ewk);
void Setup_Move_79();
void Setup_Pos_79(WORK_Other* ewk);
s32 effect_79_init(s16 pl_id, s16 plate_id, s16 pos_id, s16 time, s16 Target_BG);
void effect_79_move(WORK_Other* ewk);
s32 Select_End_Sub_79(WORK_Other* ewk);

#endif
