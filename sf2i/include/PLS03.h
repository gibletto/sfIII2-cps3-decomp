#ifndef PLS03_H
#define PLS03_H

#include "structs.h"

s32 check_full_gauge_attack(PLW* wk, s8 always);
s32 check_full_gauge_attack2(PLW* wk, s8 always);
s32 check_leap_attack(PLW* wk);
s32 check_special_attack(PLW* wk);
s32 check_super_arts_attack(PLW* wk);
s32 execute_super_arts(PLW* wk);
void hissatsu_setup_union(PLW* wk, s16 rno);

#endif
