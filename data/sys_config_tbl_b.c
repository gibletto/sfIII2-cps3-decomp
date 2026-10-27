/*
 * SYS_CONFIG_TBL_B.C  test mode configuration menu screens
 *
 * The config_ and sysconfig_ tables place the lines of the configuration menu: the top menu
 * and its guides, the system configuration page with its alternative last lines (language,
 * card dispenser, voice type, win points, exit), the modify and return guides and the saving
 * message; the str_ strings that follow are their text. Read by SYS_CONFIG_2.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const TM_STRING config_top_menu_scr[];
extern const TM_STRING config_top_guide_scr[];
extern const TM_STRING config_reset_guide_scr[];
extern const TM_STRING sysconfig_scr[];
extern const TM_STRING sysconfig_exit_scr[];
extern const TM_STRING sysconfig_dispenser_scr[];
extern const TM_STRING sysconfig_winpoint_scr[];
extern const TM_STRING sysconfig_modify_guide[];
extern const TM_STRING sysconfig_return_guide[];
extern const TM_STRING config_saving_scr[];
extern const s8 str_config_menu_title[];
extern const s8 str_config_1_system[];
extern const s8 str_config_2_game[];
extern const s8 str_config_3_default[];
extern const s8 str_config_4_save_exit[];
extern const s8 str_guide_select_up_down[];
extern const s8 str_guide_start_shot1[];
extern const s8 str_guide_reset_shot1_shot2[];
extern const s8 str_sysconfig_title[];
extern const s8 str_sys_1_coin[];
extern const s8 str_sys_2_chute_mode[];
extern const s8 str_sys_3_continue[];
extern const s8 str_sys_4_monitor[];
extern const s8 str_sys_5_demo_sound[];
extern const s8 str_sys_6_sound_mode[];
extern const s8 str_sys_7_exit[];
extern const s8 str_sys_7_language[];
extern const s8 str_sys_8_exit[];
extern const s8 str_sys_7_c_dispenser[];
extern const s8 str_sys_8_win_point[];
extern const s8 str_sys_9_exit[];
extern const s8 str_sys_7_voice_type[];
extern const s8 str_sys_8_win_point_com[];
extern const s8 str_sys_9_win_point_human[];
extern const s8 str_sys_10_exit[];
extern const s8 str_guide_select_option[];
extern const s8 str_guide_modify_setting[];
extern const s8 str_guide_modify_shot1_shot2[];
extern const s8 str_guide_return_config_menu[];
extern const s8 str_guide_return_shot1[];
extern const s8 str_saving_configuration[];
extern const s8 str_saving_in_eeprom[];

const TM_STRING config_top_menu_scr[5] = {
    { 4, 2, 2, str_config_menu_title },
    { 0x12, 6, 2, str_config_1_system },
    { 0x12, 8, 2, str_config_2_game },
    { 0x12, 0xA, 2, str_config_3_default },
    { 0x12, 0xC, 2, str_config_4_save_exit },
};

const TM_STRING config_top_guide_scr[2] = {
    { 0xD, 0x1A, 2, str_guide_select_up_down },
    { 0xD, 0x1B, 2, str_guide_start_shot1 },
};

const TM_STRING config_reset_guide_scr[2] = {
    { 0xD, 0x1A, 2, str_guide_select_up_down },
    { 0xD, 0x1B, 2, str_guide_reset_shot1_shot2 },
};

const TM_STRING sysconfig_scr[7] = {
    { 1, 2, 2, str_sysconfig_title },
    { 3, 5, 2, str_sys_1_coin },
    { 3, 7, 2, str_sys_2_chute_mode },
    { 3, 9, 2, str_sys_3_continue },
    { 3, 0xB, 2, str_sys_4_monitor },
    { 3, 0xD, 2, str_sys_5_demo_sound },
    { 3, 0xF, 2, str_sys_6_sound_mode },
};

const TM_STRING sysconfig_exit_scr[3] = {
    { 3, 0x11, 2, str_sys_7_exit },
    { 3, 0x11, 2, str_sys_7_language },
    { 3, 0x13, 2, str_sys_8_exit },
};

const TM_STRING sysconfig_dispenser_scr[5] = {
    { 3, 0x11, 2, str_sys_7_c_dispenser },
    { 3, 0x13, 2, str_sys_8_win_point },
    { 3, 0x15, 2, str_sys_9_exit },
    { 3, 0x11, 2, str_sys_7_voice_type },
    { 3, 0x13, 2, str_sys_8_exit },
};

const TM_STRING sysconfig_winpoint_scr[4] = {
    { 3, 0x11, 2, str_sys_7_c_dispenser },
    { 3, 0x13, 2, str_sys_8_win_point_com },
    { 3, 0x15, 2, str_sys_9_win_point_human },
    { 2, 0x17, 2, str_sys_10_exit },
};

const TM_STRING sysconfig_modify_guide[3] = {
    { 7, 0x19, 2, str_guide_select_option },
    { 7, 0x1A, 2, str_guide_modify_setting },
    { 7, 0x1B, 2, str_guide_modify_shot1_shot2 },
};

const TM_STRING sysconfig_return_guide[3] = {
    { 7, 0x19, 2, str_guide_select_option },
    { 7, 0x1A, 2, str_guide_return_config_menu },
    { 7, 0x1B, 2, str_guide_return_shot1 },
};

const TM_STRING config_saving_scr[2] = {
    { 5, 0xC, 0xE, str_saving_configuration },
    { 5, 0xE, 0xE, str_saving_in_eeprom },
};

const s8 str_config_menu_title[40] = "7. C O N F I G U R A T I O N   M E N U\n";

const s8 str_config_1_system[12] = "1. SYSTEM\n\0\xFF";

const s8 str_config_2_game[12] = "2. GAME\n\0\xFF\xFF\xFF";

const s8 str_config_3_default[12] = "3. DEFAULT\n";

const s8 str_config_4_save_exit[16] = "4. SAVE & EXIT\0\xFF";

const s8 str_guide_select_up_down[28] = "SELECT = 1P UP or DOWN   \n\0\xFF";

const s8 str_guide_start_shot1[28] = "START  = 1P SHOT1        \0\xFF\xFF";

const s8 str_guide_reset_shot1_shot2[28] = "RESET  = 1P SHOT1 & SHOT2\0\xFF\xFF";

const s8 str_sysconfig_title[48] = "7-1. S Y S T E M   C O N F I G U R A T I O N\n\0\xFF\xFF";

const s8 str_sys_1_coin[12] = "1. COIN\n\0\xFF\xFF\xFF";

const s8 str_sys_2_chute_mode[16] = "2. CHUTE MODE\n\0\xFF";

const s8 str_sys_3_continue[16] = "3. CONTINUE\n\0\xFF\xFF\xFF";

const s8 str_sys_4_monitor[12] = "4. MONITOR\n";

const s8 str_sys_5_demo_sound[16] = "5. DEMO SOUND\n\0\xFF";

const s8 str_sys_6_sound_mode[16] = "6. SOUND MODE\0\xFF\xFF";

const s8 str_sys_7_exit[8] = "7. EXIT";

const s8 str_sys_7_language[16] = "7. LANGUAGE\n\0\xFF\xFF\xFF";

const s8 str_sys_8_exit[8] = "8. EXIT";

const s8 str_sys_7_c_dispenser[16] = "7. C.DISPENSER\n";

const s8 str_sys_8_win_point[16] = "8. WIN POINT\n\0\xFF\xFF";

const s8 str_sys_9_exit[8] = "9. EXIT";

const s8 str_sys_7_voice_type[16] = "7. VOICE TYPE\n\0\xFF";

const s8 str_sys_8_win_point_com[20] = "8. WIN POINT COM\n\0\xFF\xFF";

const s8 str_sys_9_win_point_human[20] = "9. WIN POINT HUMAN\n";

const s8 str_sys_10_exit[12] = "10. EXIT\0\xFF\xFF\xFF";

const s8 str_guide_select_option[36] = "SELECT OPTION  = 1P UP or DOWN    \n";

const s8 str_guide_modify_setting[36] = "MODIFY SETTING = 1P LEFT or RIGHT \n";

const s8 str_guide_modify_shot1_shot2[36] = "               = 1P SHOT1 or SHOT2\0\xFF";

const s8 str_guide_return_config_menu[36] = "RETURN TO CONFIGURATION MENU      \n";

const s8 str_guide_return_shot1[36] = "               = 1P SHOT1         \0\xFF";

const s8 str_saving_configuration[36] = "NOW  SAVING  NEW  CONFIGURATION\n\0\xFF\xFF\xFF";

const s8 str_saving_in_eeprom[40] = "                         IN  EEPROM...\0\xFF";
