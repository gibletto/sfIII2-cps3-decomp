#ifndef EFFECT_2_H
#define EFFECT_2_H

#include "structs.h"

void setup_free_program(WORK* wk, u8 arg);
void setup_bg_quake_x(WORK* wk, u8 ix);
void setup_bg_quake_y(WORK* wk, u8 ix);
void setup_exdm_ix(PLW* wk, u8 ix);
s32 exec_char_asxy(WORK* wk, u8 data);
void setup_dmv_use_flag(PLW* wk, u8 use);
void setup_disp_flag(WORK* wk, s8 flag);
void setup_command_number(PLW* wk, u8 cmd_no);

#endif
