#ifndef WIN_PL_H
#define WIN_PL_H

#include "structs.h"

void win_player(PLW* wk);
void Win_00000(PLW* wk);
void Win_01000(PLW* wk);
void jijii_fly_up(PLW* wk);
void jijii_jump(PLW* wk);
void Win_02000(PLW* wk);
void Win_03000(PLW* wk);
void Win_04000(PLW* wk);
void Normal_normal_Winner(PLW* wk);
void Judge_normal_winner(PLW* wk);
s32 win_special_check(PLW* wk);     /* provisional name; 2nd Impact only */
void Win_05000(PLW* wk);
void Win_06000(PLW* wk);
void Win_07000(PLW* wk);
void Win_08000(PLW* wk);
void Win_09000(PLW* wk);
void win_stage8_action(PLW* wk);    /* provisional name; 2nd Impact only */
s32 win_select(PLW* wk, s16 num);
void bonus_game_win_pause(PLW* wk);

#endif
