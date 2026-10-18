#ifndef EFF64_H
#define EFF64_H

#include "structs.h"

void eff64_00(WORK_Other* ewk);
void eff64_04(WORK_Other* ewk);
void eff64_08(WORK_Other* ewk);
void eff64_data_set(WORK_Other* ewk, s16 keep);
void eff64_wait(WORK_Other* ewk);
s32 eff64_goal_check(WORK_Other* ewk);
s32 effect_64_init(s16 type);
void eff64_02(WORK_Other* ewk);
void effect_64_move(WORK_Other* ewk);
s32 effect_67_init(s16 id, s16 X, s16 Y, s16 time0, s16 Char_Index, s16 Priority, s16 no, s16 col);
void effect_67_move(WORK_Other_CONN* ewk);

#endif
