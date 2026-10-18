#ifndef PLPCA_H
#define PLPCA_H

#include "structs.h"

void Catch_01000(PLW* wk);
void Catch_02000(PLW* wk);
void Catch_04000(PLW* wk);
void Catch_05000(PLW* wk);
void Catch_06000(PLW* wk);
void Catch_07000(PLW* wk);
void check_nagenuke(PLW* wk, PLW* tk);
void Catch_00000(PLW* wk);
void Catch_03000(PLW* wk);
s32 cat07_running_check(WORK* wk);
void Catch_08000(PLW* wk);
void Player_catch(PLW* wk);
void catch_cg_type_check(PLW* wk);
void set_char_move_init_ca();
void subtract_cu_vital(PLW* wk);

#endif
