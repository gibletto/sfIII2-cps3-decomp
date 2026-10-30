#ifndef EFFK6_H
#define EFFK6_H

#include "structs.h"

void EFFK6_MOVE(WORK_Other* ewk);
void EFFK6_SLIDE_IN(WORK_Other* ewk);
void EFFK6_SLIDE_OUT(WORK_Other* ewk);
void EFFK6_SUDDENLY(WORK_Other* ewk);
void EFFK6_KILL(WORK_Other* ewk);
s16 Get_PosK6();
void Setup_1st_PosK6();
void Setup_CharK6(WORK_Other* ewk, s16 dm_vital);
s16 Setup_K6_Index(WORK_Other* ewk);
s32 effect_K6_init(s16 PL_id, s16 dir_old, s16 dm_vital, s16 Target_BG);
void effect_K6_move(WORK_Other* ewk);
void EFFK6_WAIT(WORK_Other* ewk);

s32 chkNameSuv(s16 name_no);

#endif
