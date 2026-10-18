#ifndef WIN_PL_H
#define WIN_PL_H

#include "structs.h"

void Win_02000(PLW* wk);
void Win_10000(PLW* wk);
void q_walk_past_action(PLW* wk);
void Win_12000(PLW* wk);
void Win_13000(PLW* wk);
void Win_15000(PLW* wk);
s32 win_select(PLW* wk, s16 num);
void Normal_normal_Winner(PLW* wk);
void Win_00000(PLW* wk);
void Win_01000(PLW* wk);
void jijii_fly_up(PLW* wk);
void jijii_jump(PLW* wk);
void jijii_full(PLW* wk);
void Win_03000(PLW* wk);
void Win_04000(PLW* wk);
void Win_05000(PLW* wk);
void Win_06000(PLW* wk);
void Win_07000(PLW* wk);
void Win_08000(PLW* wk);
void Win_09000(PLW* wk);
void Win_11000(PLW* wk);
void twelve_win_away(PLW* wk);
void twelve_win_backjump(PLW* wk);
void Win_14000(PLW* wk);
s32 q_em_dir(PLW* wk);
s16 q_em_distance_chk(PLW* wk);
void q_keeping_action(PLW* wk);
void q_leave_after_action(PLW* wk);
void urien_dash(PLW* wk);
s32 urien_dash_chk(PLW* wk);
void Judge_normal_winner(PLW* wk);
void win_player(PLW* wk);
void bonus_game_win_pause(PLW* wk);
void meta_win_pause(PLW* wk);

#endif
