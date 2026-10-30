/*
 * CMD_MAIN_TBL_B.C  English game configuration text and debug character sets
 *
 * gcfg_line_*_en and gcfg_help_*_en are the item and help lines of the English GAME
 * CONFIGURATION page (the *2_en lines are the layout without SCREEN MODE), reached through the
 * tables in CMD_MAIN_TBL.C. str_NORMAL_2 .. str_ON are the setting values printed beside the
 * items, read by GAME_CONFIG_EN.C. debug_charset_tbl gives the charset_id loaded for each
 * character number in the debug menu, read by CMD_MAIN.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 gcfg_line_title_en[];
extern const s8 gcfg_line_screen_en[];
extern const s8 gcfg_line_level_en[];
extern const s8 gcfg_line_damage_en[];
extern const s8 gcfg_line_timer_en[];
extern const s8 gcfg_line_round_en[];
extern const s8 gcfg_line_event_en[];
extern const s8 gcfg_line_bonus_en[];
extern const s8 gcfg_line_exit_en[];
extern const s8 gcfg_help_select_en[];
extern const s8 gcfg_line_level2_en[];
extern const s8 gcfg_line_damage2_en[];
extern const s8 gcfg_line_timer2_en[];
extern const s8 gcfg_line_round2_en[];
extern const s8 gcfg_line_event2_en[];
extern const s8 gcfg_line_exit2_en[];
extern const s8 gcfg_help_modify_en[];
extern const s8 gcfg_help_shots_en[];
extern const s8 gcfg_help_select2_en[];
extern const s8 gcfg_help_return_en[];
extern const s8 gcfg_help_shot1_en[];
extern const char str_NORMAL_2[];
extern const s8 str_WIDE[];
extern const s8 str_1_ROUND[];
extern const s8 str_3_ROUNDS[];
extern const s8 str_5_ROUNDS[];
extern const s8 str_7_ROUNDS[];
extern const s8 str_OFF[];
extern const s8 str_1_MATCH[];
extern const s8 str_OFF_2[];
extern const char str_ON[];
extern const u8 debug_charset_tbl[];

const s8 gcfg_line_title_en[44] = "7-2. G A M E   C O N F I G U R A T I O N\n\0\xFF\xFF";

const s8 gcfg_line_screen_en[44] = "1. SCREEN MODE       NORMAL            \n\0\xFF\xFF\xFF";

const s8 gcfg_line_level_en[44] = "2. GAME DIFFICULTY   EASY[********]HARD\n\0\xFF\xFF\xFF";

const s8 gcfg_line_damage_en[40] = "3. DAMAGE LEVEL      LOW [****] HIGH\n\0\xFF\xFF";

const s8 gcfg_line_timer_en[40] = "4. TIME COUNT SPEED  SLOW[****]FAST\n\0\xFF\xFF\xFF";

const s8 gcfg_line_round_en[32] = "5. MAX ROUND         3 ROUND\n\0\xFF\xFF";

const s8 gcfg_line_event_en[28] = "6. EVENT             OFF\n\0\xFF\xFF";

const s8 gcfg_line_bonus_en[28] = "7. BONUS GAME        ON \n\0\xFF\xFF";

const s8 gcfg_line_exit_en[12] = "8. EXIT\n\0\xFF\xFF\xFF";

const s8 gcfg_help_select_en[32] = "SELECT OPTION  = 1P UP or DOWN\0\xFF";

/* provisional name */
const s8 gcfg_line_level2_en[44] = "1. GAME DIFFICULTY   EASY[********]HARD\n\0\xFF\xFF\xFF";

/* provisional name */
const s8 gcfg_line_damage2_en[40] = "2. DAMAGE LEVEL      LOW [****] HIGH\n\0\xFF\xFF";

/* provisional name */
const s8 gcfg_line_timer2_en[40] = "3. TIME COUNT SPEED  SLOW[****]FAST\n\0\xFF\xFF\xFF";

/* provisional name */
const s8 gcfg_line_round2_en[32] = "4. MAX ROUND         3 ROUND\n\0\xFF\xFF";

/* provisional name */
const s8 gcfg_line_event2_en[28] = "5. EVENT             OFF\n\0\xFF\xFF";

/* provisional name */
const s8 gcfg_line_exit2_en[12] = "6. EXIT\n\0\xFF\xFF\xFF";

const s8 gcfg_help_modify_en[36] = "MODIFY SETTING = 1P LEFT or RIGHT \n";

const s8 gcfg_help_shots_en[36] = "               = 1P SHOT1 or SHOT2\0\xFF";

const s8 gcfg_help_select2_en[36] = "SELECT OPTION  = 1P UP or DOWN    \n";

const s8 gcfg_help_return_en[36] = "RETURN TO CONFIGURATION MENU      \n";

const s8 gcfg_help_shot1_en[36] = "               = 1P SHOT1         \0\xFF";

const char str_NORMAL_2[12] = "NORMAL  \0\xFF\xFF\xFF";

const s8 str_WIDE[12] = "WIDE    \0\xFF\xFF\xFF";

const s8 str_1_ROUND[12] = "1 ROUND \0\xFF\xFF\xFF";

const s8 str_3_ROUNDS[12] = "3 ROUNDS\0\xFF\xFF\xFF";

const s8 str_5_ROUNDS[12] = "5 ROUNDS\0\xFF\xFF\xFF";

const s8 str_7_ROUNDS[12] = "7 ROUNDS\0\xFF\xFF\xFF";

const s8 str_OFF[8] = "OFF    ";

const s8 str_1_MATCH[8] = "1 MATCH";

const s8 str_OFF_2[4] = "OFF";

const char str_ON[4] = "ON ";

/* provisional name */
const u8 debug_charset_tbl[16] = {
    6, 3, 5, 1, 2, 9, 7, 4, 10, 8, 12, 13, 14, 15, 16, 17,
};
