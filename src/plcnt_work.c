/*
 * PLCNT_WORK.C  player work
 *
 * The two players' work areas and their control state: cleared work RAM (section B). A
 * <name>_tail table holds the bytes between <name> and the next named variable.
 */

#include "types.h"
#include "structs.h"

s16 pcon_rno[4];  /* 0200E4F4 */
s16 appear_type;  /* 0200E4FC */
u8 round_slow_flag;  /* 0200E4FE */
u8 pcon_dp_flag;  /* 0200E4FF */
u8 pl_eff_disp_stop;  /* 0200E500 */
u8 pl_eff_disp_stop_tail[1];  /* after pl_eff_disp_stop; nothing refers to it by name or address */
u8 win_sp_flag;  /* 0200E502 */
char dead_voice_flag;  /* 0200E503 */
PLW plw[2];  /* 0200E504 */
SA_WORK super_arts[2];  /* 0200ED1C */
PiyoriType piyori_type[2];  /* 0200ED74 */
ComboType combo_type[2];  /* 0200ED9C */
ComboType remake_power[2];  /* 0200EEEC */
ZanzouTableEntry zanzou_table[2][48];  /* 0200F03C */
u8 zanzou_table_tail[12];  /* after zanzou_table; nothing refers to it by name or address */
