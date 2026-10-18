#ifndef PLCNTSET_2_H
#define PLCNTSET_2_H

#include "structs.h"

void settle_type_50000(void);
void check_damage_hosei_nage(PLW* as, PLW* ds);
void setup_settle_rno();
s32 check_sa_resurrection(PLW* wk);
void reset_char_disp_work(WORK* wk);
void setup_gouki_wins(void);
void check_damage_hosei(void);
void add_next_position(PLW* wk);
void check_damage_hosei_dageki(PLW* as, PLW* ds);
s32 check_sa_type_rebirth(PLW* wk);
void settle_type_60000(void);
s32 footwork_check(char pl);
void move_P1_move_P2(void);
void move_P2_move_P1(void);
void move_player_work(void);
s32 nekorobi_check(char pl);
void plcnt_die(void);
void plcnt_move(void);
void set_quake(PLW* wk);
void settle_check(void);
void settle_type_00000(void);
void settle_type_10000(void);
void settle_type_20000(void);
void settle_type_30000(void);
void settle_type_40000(void);
s32 time_over_check(void);
s32 will_die(void);
void init_app_10000(void);
void pli_3000(void);
void init_app_20000(void);
void init_app_30000(void);
void pli_0000(void);
void pli_1000(void);

#endif
