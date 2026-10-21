#ifndef LOSE_PL_H
#define LOSE_PL_H

#include "structs.h"

void Lose_10000(PLW* wk);
void Lose_20000(PLW* wk);
void Lose_30000(PLW* wk);
void Normal_normal_Loser(PLW* wk);
void Judge_normal_loser(PLW* wk);
void lose_stage8_action(PLW* wk);   /* provisional name; 2nd Impact only */
void lose_time_over(PLW* wk);       /* provisional name; 2nd Impact only */
void lose_player(PLW* wk);
void Lose_00000(PLW* wk);
void opning_init_00000(void);
void opning_init_01000(void);
void op_102_move(void);
void op_104_move(void);
void op_105_move(void);
void op_106_move(void);
void opning_init_02000(void);
void op_100_move(void);
void op_101_move(void);
void op_103_move(void);
void op_work_clear(void);
s16 opening_demo_tick(void);
void opening_init2(void);
void opening_move(void);

#endif
