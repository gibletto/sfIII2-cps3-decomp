#ifndef EFFK2_H
#define EFFK2_H

#include "structs.h"

s32 effect_K1_init(s16 side);
void effK2_parts_move_type_1(WORK_Other* ewk, DADD* hahen);
void effK2_parts_move_type_4(WORK_Other* ewk, DADD* arg1);
void effK2_parts_move_type_7(WORK_Other* ewk, DADD* arg1);
void effK2_parts_move_type_8(WORK_Other* ewk, DADD* hahen);
void disp_effK2(WORK* wk, WORK* mk, DADD* hk);
void effK2_parts_move_type_0(WORK_Other* ewk, DADD* _p1);
void effK2_parts_move_type_2(WORK_Other* ewk, DADD* _p1);
void effK2_parts_move_type_3(WORK_Other* ewk, DADD* hahen);
void effK2_parts_move_type_5(WORK_Other* ewk, DADD* arg1);
void effK2_parts_move_type_6(WORK_Other* ewk, DADD* arg1);
void effect_K1_move(WORK_Other* ewk);
s32 effect_K2_init(WORK_Other* wk, u32* dad);
void effect_K2_move(WORK_Other* ewk);
void illegal_setup_effK2(WORK* wk, s16 ix);
void set_next_next_y();
void setup_effK2(WORK* wk);
void setup_effK2_sync_bomb(WORK* wk);

#endif
