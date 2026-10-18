#ifndef PLCNTDAT_H
#define PLCNTDAT_H

#include "structs.h"

s32 debug_player_change(void);
void reset_piyori_and_fight(void);
void reset_fight_status(void);
void reset_round_and_screen(void);
void erase_extra_plef_work(void);
void setup_base_and_other_data(void);
void set_base_data_metamorphose(PLW* wk);
void clear_kizetsu_point(PLW* wk);
void set_base_data(PLW* wk, s16 ix);
void set_base_data_tiny(PLW* wk);
void set_player_shadow(PLW* wk);
void set_super_arts_status(s16 pl);
void setup_any_data(void);
void setup_other_data(PLW* wk);
void set_kizetsu_status();

#endif
