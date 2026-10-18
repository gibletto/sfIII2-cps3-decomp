#ifndef EXTERN_H
#define EXTERN_H

#include "structs.h"

void task_exit_to_system(void);
void effB1_trans(WORK* ewk);
void bios_vector_restart(s32 mode, s32 arg);
char * _builtin_strcpy(char* dst, const char* src);
void cpu_hang_forever(void);
void damage_atemi_setup(PLW* wk, PLW* ek);
void op_bg2_0000(void);
void op_bg2_0001(void);
void op_bg2_0002(void);
void op_bg2_0003(void);
void task_sleep(s32 frames);
void task_wait(void);
void task_dispatch(TCB* task);

#endif
