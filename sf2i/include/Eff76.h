#ifndef EFF76_H
#define EFF76_H

#include "structs.h"

void EFF76_BEFORE(WORK_Other* ewk);
void EFF76_SLIDE_IN(WORK_Other* ewk);
void EFF76_SLIDE_OUT(WORK_Other* ewk);
void EFF76_SUDDENLY(WORK_Other* ewk);
void EFF76_WAIT(WORK_Other* ewk);
void EFF76_WAIT_BREAK_INTO(WORK_Other* ewk);
void EFF76_DIE(WORK_Other* ewk);
void EFF76_SHIFT(WORK_Other* ewk);
s32 Check_Range_Out(WORK_Other* ewk);
void Setup_Char_76(WORK_Other* ewk);
void Setup_Pos_76(WORK_Other* ewk);
s32 effect_76_init(s16 dir_old);
void effect_76_move(WORK_Other* ewk);
s32 chkNameAkuma();
void Setup_Color_76();
void Setup_Color_L1();

#endif
