#ifndef EFF79_H
#define EFF79_H

#include "structs.h"

void effect_79_move(WORK_Other* ewk);
void Move_79(WORK_Other* ewk);
void Check_Priority(WORK_Other* ewk);
void eff79_char_move(WORK_Other* ewk);
void Setup_Move_79();
void EFF79_Move_X(WORK_Other* ewk);
s32 EFF79_Move_Y(WORK_Other* ewk);
void eff79_set_position(WORK_Other* ewk, s16 flag);
s32 Select_End_Sub_79(WORK_Other* ewk);
s32 effect_79_init(s16 pl_id, s16 plate_id, s16 pos_id, s16 time, s16 type);
void Setup_Pos_79(WORK_Other* ewk);

#endif
