/*
 * COM_PL_TBL.C  tables read by demo00.c, mode_init.c and test_mode.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const TM_STRING boot_title_str[];
extern const TM_STRING boot_region_str[];
extern const TM_STRING boot_version_str[];
extern const TM_STRING parental_advisory_msg[];
extern const char str_STREET_FIGHTER_III[];
extern const char str_3rd_STRIKE[];
extern const char str_990512[];
extern const char str_blank[];
extern const char str_JAPAN[];
extern const char str_ASIA[];
extern const char str_EURO[];
extern const char str_USA[];
extern const char str_HISPANIC[];
extern const char str_BRAZIL_3[];
extern const char str_OCEANIA[];
extern const char str_ASIA_2[];
extern const char str_NO_CD[];
extern const char str_PRODUCT_VERSION[];
extern const char str_CHARACTER_CHECK_VERSION[];
extern const char str_PUBLICITY_VERSION[];
extern const char str_LOCATION_TEST_VERSION[];
extern const char str_SHOW_VERSION[];
extern const char str_BUG_CHECK_VERSION[];
extern const char str_BENT_STAFF_VERSION[];
extern const char str_DEVELOPMENT_VERSION[];
extern const char str_CHECK_VERSION[];
extern const char str_WARNING[];
extern const char str_This_game_is_for_use_in_japan_on[];
extern const char str_Sales_export_or_operation_outsid[];
extern const char str_country_may_be_construed_as_copy[];
extern const char str_and_trademark_infringement_and_i[];
extern const char str_prohibited[];
extern const char str_Violators_are_subject_to_severe_[];
extern const char str_and_will_be_prosecuted_to_the_fu[];
extern const char str_of_the_law[];
extern const char str_blank_2[];
extern const char str_This_game_is_for_use_in_the_sout[];
extern const char str_Asian_countries_only[];
extern const char str_Sales_export_or_operation_outsid_2[];
extern const char str_countries_may_be_construed_as_co[];
extern const char str_trademark_infringement_and_is_st[];
extern const char str_This_game_is_for_use_in_the_Euro[];
extern const char str_only[];
extern const char str_This_game_is_for_use_in_the_Unit[];
extern const char str_of_America_and_Canada_only[];
extern const char str_This_game_is_for_use_in_the_West[];
extern const char str_countries_except_the_United_Stat[];
extern const char str_Canada_and_the_Federative_Republ[];
extern const char str_This_game_is_for_use_in_the_Fede[];
extern const char str_of_Brazil_only[];
extern const char str_country_may_be_construed_as_copy_2[];
extern const char str_This_game_is_for_use_in_the_Ocea[];
extern const char str_Parental_Advisory[];
extern const char str_Animated_violence_Mild[];
extern const char str_Contains_scenes_of_violence_invo[];
extern const char str_cartoon_like_characters_ina_fant[];
extern const u8 sys_cfg_default_0_0[];
extern const u8 sys_cfg_default_0_1[];
extern const u8 sys_cfg_default_0_2[];
extern const u8 sys_cfg_default_0_4[];
extern const u8 sys_cfg_default_0_3[];
extern const u8 sys_cfg_default_0_5[];
extern const u8 sys_cfg_default_0_6[];
extern const u8 sys_cfg_default_0_7[];
extern const u8 sys_cfg_default_0_8[];
extern const u8 sys_cfg_default_1_0[];
extern const u8 sys_cfg_default_1_1[];
extern const u8 sys_cfg_default_1_2[];
extern const u8 sys_cfg_default_1_4[];
extern const u8 sys_cfg_default_1_3[];
extern const u8 sys_cfg_default_1_5[];
extern const u8 sys_cfg_default_1_6[];
extern const u8 sys_cfg_default_1_7[];
extern const u8 sys_cfg_default_1_8[];
extern const u8 sys_cfg_default_2_0[];
extern const u8 sys_cfg_default_2_1[];
extern const u8 sys_cfg_default_2_2[];
extern const u8 sys_cfg_default_2_4[];
extern const u8 sys_cfg_default_2_3[];
extern const u8 sys_cfg_default_2_5[];
extern const u8 sys_cfg_default_2_6[];
extern const u8 sys_cfg_default_2_7[];
extern const u8 sys_cfg_default_2_8[];
extern const u8 game_cfg_default_tbl_row0[];
extern const u8 game_cfg_default_tbl_row1[];
extern const u8 game_cfg_default_tbl_row2[];
extern const u8 game_cfg_default_tbl_row3[];
extern const u8 game_cfg_default_tbl_row4[];
extern const u8 game_cfg_default_tbl_row5[];
extern const u8 game_cfg_default_tbl_row6[];
extern const u8 game_cfg_default_tbl_row7[];
extern const u8 game_cfg_default_tbl_row8[];
extern const u32 test_cursor_y_tbl[][10];
extern const u32 test_cursor_x_tbl[];

const TM_STRING boot_title_str[3] = {
    { 8, 8, 2, (void *)str_STREET_FIGHTER_III },
    { 8, 9, 2, (void *)str_3rd_STRIKE },
    { 0x11, 0xB, 2, (void *)str_990512 },
};

const TM_STRING boot_region_str[10] = {
    { 0xF, 0xD, 0xE, (void *)str_blank },
    { 0x13, 0xD, 2, (void *)str_JAPAN },
    { 0xF, 0xD, 4, (void *)str_ASIA },
    { 0x13, 0xD, 6, (void *)str_EURO },
    { 0x13, 0xD, 8, (void *)str_USA },
    { 0x10, 0xD, 0xA, (void *)str_HISPANIC },
    { 0x12, 0xD, 0xC, (void *)str_BRAZIL_3 },
    { 0x11, 0xD, 0xE, (void *)str_OCEANIA },
    { 0x13, 0xD, 4, (void *)str_ASIA_2 },
    { 0x13, 0xD, 2, (void *)str_NO_CD },
};

const TM_STRING boot_version_str[9] = {
    { 0x10, 0xE, 0xE, (void *)str_PRODUCT_VERSION },
    { 0xD, 0xE, 0xE, (void *)str_CHARACTER_CHECK_VERSION },
    { 0x10, 0xE, 0xE, (void *)str_PUBLICITY_VERSION },
    { 0xF, 0xE, 0xE, (void *)str_LOCATION_TEST_VERSION },
    { 0x12, 0xE, 0xE, (void *)str_SHOW_VERSION },
    { 0x10, 0xE, 0xE, (void *)str_BUG_CHECK_VERSION },
    { 0x10, 0xE, 0xE, (void *)str_BENT_STAFF_VERSION },
    { 0xF, 0xE, 0xE, (void *)str_DEVELOPMENT_VERSION },
    { 0x11, 0xE, 0xE, (void *)str_CHECK_VERSION },
};

const TM_STRING parental_advisory_msg[4] = {
    { 6, 0x16, 0x28, (void *)str_Parental_Advisory },
    { 6, 0x17, 0x28, (void *)str_Animated_violence_Mild },
    { 1, 0x19, 0x28, (void *)str_Contains_scenes_of_violence_invo },
    { 1, 0x1A, 0x28, (void *)str_cartoon_like_characters_ina_fant },
};

const char str_STREET_FIGHTER_III[36] = {
    0x53, 0x20, 0x54, 0x20, 0x52, 0x20, 0x45, 0x20, 0x45, 0x20, 0x54, 0x20, 0x20, 0x20, 0x46, 0x20,
    0x49, 0x20, 0x47, 0x20, 0x48, 0x20, 0x54, 0x20, 0x45, 0x20, 0x52, 0x20, 0x20, 0x20, 0x49, 0x49,
    0x49, 0xA, 0, 0xFF,
};

const char str_3rd_STRIKE[28] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x32, 0x20, 0x4E, 0x20, 0x44, 0x20, 0x20, 0x49, 0x20,
    0x4D, 0x20, 0x50, 0x20, 0x41, 0x20, 0x43, 0x20, 0x54, 0xA, 0, 0xFF,
};

const char str_990512[16] = {
    0x20, 0x39, 0x20, 0x37, 0x20, 0x30, 0x20, 0x39, 0x20, 0x33, 0x20, 0x30, 0, 0xFF, 0xFF, 0xFF,
};

const char str_blank[16] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0, 0xFF, 0xFF,
};

const char str_JAPAN[12] = {
    0x4A, 0x20, 0x41, 0x20, 0x50, 0x20, 0x41, 0x20, 0x4E, 0, 0xFF, 0xFF,
};

const char str_ASIA[20] = {
    0x20, 0x41, 0x20, 0x53, 0x20, 0x49, 0x20, 0x41, 0x20, 0x28, 0x20, 0x4E, 0x43, 0x44, 0x20, 0x29,
    0, 0xFF, 0xFF, 0xFF,
};

const char str_EURO[12] = {
    0x20, 0x45, 0x20, 0x55, 0x20, 0x52, 0x20, 0x4F, 0x20, 0, 0xFF, 0xFF,
};

const char str_USA[12] = {
    0x20, 0x20, 0x55, 0x20, 0x53, 0x20, 0x41, 0x20, 0x20, 0, 0xFF, 0xFF,
};

const char str_HISPANIC[16] = "H I S P A N I C";

const char str_BRAZIL_3[12] = "B R A Z I L";

const char str_OCEANIA[16] = "O C E A N I A\0\xFF\xFF";

const char str_ASIA_2[12] = " A S I A\0\xFF\xFF\xFF";

const char str_NO_CD[8] = {
    0x20, 0x4E, 0x4F, 0x20, 0x43, 0x44, 0, 0xFF,
};

const char str_PRODUCT_VERSION[16] = "PRODUCT VERSION";

const char str_CHARACTER_CHECK_VERSION[24] = "CHARACTER CHECK VERSION";

const char str_PUBLICITY_VERSION[20] = {
    0x50, 0x55, 0x42, 0x4C, 0x49, 0x43, 0x49, 0x54, 0x59, 0x20, 0x56, 0x45, 0x52, 0x53, 0x49, 0x4F,
    0x4E, 0, 0xFF, 0xFF,
};

const char str_LOCATION_TEST_VERSION[24] = {
    0x4C, 0x4F, 0x43, 0x41, 0x54, 0x49, 0x4F, 0x4E, 0x20, 0x54, 0x45, 0x53, 0x54, 0x20, 0x56, 0x45,
    0x52, 0x53, 0x49, 0x4F, 0x4E, 0, 0xFF, 0xFF,
};

const char str_SHOW_VERSION[16] = {
    0x53, 0x48, 0x4F, 0x57, 0x20, 0x56, 0x45, 0x52, 0x53, 0x49, 0x4F, 0x4E, 0, 0xFF, 0xFF, 0xFF,
};

const char str_BUG_CHECK_VERSION[20] = {
    0x42, 0x55, 0x47, 0x20, 0x43, 0x48, 0x45, 0x43, 0x4B, 0x20, 0x56, 0x45, 0x52, 0x53, 0x49, 0x4F,
    0x4E, 0, 0xFF, 0xFF,
};

const char str_BENT_STAFF_VERSION[20] = {
    0x42, 0x45, 0x4E, 0x54, 0x20, 0x53, 0x54, 0x41, 0x46, 0x46, 0x20, 0x56, 0x45, 0x52, 0x53, 0x49,
    0x4F, 0x4E, 0, 0xFF,
};

const char str_DEVELOPMENT_VERSION[20] = "DEVELOPMENT VERSION";

const char str_CHECK_VERSION[16] = {
    0x43, 0x48, 0x45, 0x43, 0x4B, 0x20, 0x56, 0x45, 0x52, 0x53, 0x49, 0x4F, 0x4E, 0, 0xFF, 0xFF,
};

const char str_WARNING[12] = {
    0x57, 0x41, 0x52, 0x4E, 0x49, 0x4E, 0x47, 0xA, 0, 0xFF, 0xFF, 0xFF,
};

const char str_This_game_is_for_use_in_japan_on[40] = {
    0x54, 0x68, 0x69, 0x73, 0x20, 0x67, 0x61, 0x6D, 0x65, 0x20, 0x69, 0x73, 0x20, 0x66, 0x6F, 0x72,
    0x20, 0x75, 0x73, 0x65, 0x20, 0x69, 0x6E, 0x20, 0x6A, 0x61, 0x70, 0x61, 0x6E, 0x20, 0x6F, 0x6E,
    0x6C, 0x79, 0x2E, 0xA, 0, 0xFF, 0xFF, 0xFF,
};

const char str_Sales_export_or_operation_outsid[44] = {
    0x53, 0x61, 0x6C, 0x65, 0x73, 0x2C, 0x20, 0x65, 0x78, 0x70, 0x6F, 0x72, 0x74, 0x20, 0x6F, 0x72,
    0x20, 0x6F, 0x70, 0x65, 0x72, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x6F, 0x75, 0x74, 0x73, 0x69,
    0x64, 0x65, 0x20, 0x74, 0x68, 0x69, 0x73, 0xA, 0, 0xFF, 0xFF, 0xFF,
};

const char str_country_may_be_construed_as_copy[40] = {
    0x63, 0x6F, 0x75, 0x6E, 0x74, 0x72, 0x79, 0x20, 0x6D, 0x61, 0x79, 0x20, 0x62, 0x65, 0x20, 0x63,
    0x6F, 0x6E, 0x73, 0x74, 0x72, 0x75, 0x65, 0x64, 0x20, 0x61, 0x73, 0x20, 0x63, 0x6F, 0x70, 0x79,
    0x72, 0x69, 0x67, 0x68, 0x74, 0xA, 0, 0xFF,
};

const char str_and_trademark_infringement_and_i[44] = "and trademark infringement and is strictly\n";

const char str_prohibited[16] = {
    0x70, 0x72, 0x6F, 0x68, 0x69, 0x62, 0x69, 0x74, 0x65, 0x64, 0x2E, 0xA, 0, 0xFF, 0xFF, 0xFF,
};

const char str_Violators_are_subject_to_severe_[44] = {
    0x56, 0x69, 0x6F, 0x6C, 0x61, 0x74, 0x6F, 0x72, 0x73, 0x20, 0x61, 0x72, 0x65, 0x20, 0x73, 0x75,
    0x62, 0x6A, 0x65, 0x63, 0x74, 0x20, 0x74, 0x6F, 0x20, 0x73, 0x65, 0x76, 0x65, 0x72, 0x65, 0x20,
    0x70, 0x65, 0x6E, 0x61, 0x6C, 0x74, 0x69, 0x65, 0x73, 0xA, 0, 0xFF,
};

const char str_and_will_be_prosecuted_to_the_fu[44] = {
    0x61, 0x6E, 0x64, 0x20, 0x77, 0x69, 0x6C, 0x6C, 0x20, 0x62, 0x65, 0x20, 0x70, 0x72, 0x6F, 0x73,
    0x65, 0x63, 0x75, 0x74, 0x65, 0x64, 0x20, 0x74, 0x6F, 0x20, 0x74, 0x68, 0x65, 0x20, 0x66, 0x75,
    0x6C, 0x6C, 0x20, 0x65, 0x78, 0x74, 0x65, 0x6E, 0x74, 0xA, 0, 0xFF,
};

const char str_of_the_law[12] = "of the law.";

const char str_blank_2[4] = {
    0, 0xFF, 0xFF, 0xFF,
};

const char str_This_game_is_for_use_in_the_sout[40] = "This game is for use in the south-east\n";

const char str_Asian_countries_only[24] = {
    0x41, 0x73, 0x69, 0x61, 0x6E, 0x20, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x72, 0x69, 0x65, 0x73, 0x20,
    0x6F, 0x6E, 0x6C, 0x79, 0x2E, 0xA, 0, 0xFF,
};

const char str_Sales_export_or_operation_outsid_2[44] = {
    0x53, 0x61, 0x6C, 0x65, 0x73, 0x2C, 0x20, 0x65, 0x78, 0x70, 0x6F, 0x72, 0x74, 0x20, 0x6F, 0x72,
    0x20, 0x6F, 0x70, 0x65, 0x72, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x6F, 0x75, 0x74, 0x73, 0x69,
    0x64, 0x65, 0x20, 0x74, 0x68, 0x65, 0x73, 0x65, 0xA, 0, 0xFF, 0xFF,
};

const char str_countries_may_be_construed_as_co[48] = {
    0x63, 0x6F, 0x75, 0x6E, 0x74, 0x72, 0x69, 0x65, 0x73, 0x20, 0x6D, 0x61, 0x79, 0x20, 0x62, 0x65,
    0x20, 0x63, 0x6F, 0x6E, 0x73, 0x74, 0x72, 0x75, 0x65, 0x64, 0x20, 0x61, 0x73, 0x20, 0x63, 0x6F,
    0x70, 0x79, 0x72, 0x69, 0x67, 0x68, 0x74, 0x20, 0x61, 0x6E, 0x64, 0xA, 0, 0xFF, 0xFF, 0xFF,
};

const char str_trademark_infringement_and_is_st[40] = "trademark infringement and is strictly\n";

const char str_This_game_is_for_use_in_the_Euro[48] = "This game is for use in the European countries\n";

const char str_only[8] = {
    0x6F, 0x6E, 0x6C, 0x79, 0x2E, 0xA, 0, 0xFF,
};

const char str_This_game_is_for_use_in_the_Unit[44] = {
    0x54, 0x68, 0x69, 0x73, 0x20, 0x67, 0x61, 0x6D, 0x65, 0x20, 0x69, 0x73, 0x20, 0x66, 0x6F, 0x72,
    0x20, 0x75, 0x73, 0x65, 0x20, 0x69, 0x6E, 0x20, 0x74, 0x68, 0x65, 0x20, 0x55, 0x6E, 0x69, 0x74,
    0x65, 0x64, 0x20, 0x53, 0x74, 0x61, 0x74, 0x65, 0x73, 0xA, 0, 0xFF,
};

const char str_of_America_and_Canada_only[32] = {
    0x6F, 0x66, 0x20, 0x41, 0x6D, 0x65, 0x72, 0x69, 0x63, 0x61, 0x20, 0x61, 0x6E, 0x64, 0x20, 0x43,
    0x61, 0x6E, 0x61, 0x64, 0x61, 0x20, 0x6F, 0x6E, 0x6C, 0x79, 0x2E, 0xA, 0, 0xFF, 0xFF, 0xFF,
};

const char str_This_game_is_for_use_in_the_West[48] = "This game is for use in the Western Hemisphere\n";

const char str_countries_except_the_United_Stat[48] = "countries except the United States of America,\n";

const char str_Canada_and_the_Federative_Republ[48] = "Canada, and the Federative Republic of Brazil.\n";

const char str_This_game_is_for_use_in_the_Fede[52] = {
    0x54, 0x68, 0x69, 0x73, 0x20, 0x67, 0x61, 0x6D, 0x65, 0x20, 0x69, 0x73, 0x20, 0x66, 0x6F, 0x72,
    0x20, 0x75, 0x73, 0x65, 0x20, 0x69, 0x6E, 0x20, 0x74, 0x68, 0x65, 0x20, 0x46, 0x65, 0x64, 0x65,
    0x72, 0x61, 0x74, 0x69, 0x76, 0x65, 0x20, 0x52, 0x65, 0x70, 0x75, 0x62, 0x6C, 0x69, 0x63, 0xA,
    0, 0xFF, 0xFF, 0xFF,
};

const char str_of_Brazil_only[20] = {
    0x6F, 0x66, 0x20, 0x42, 0x72, 0x61, 0x7A, 0x69, 0x6C, 0x20, 0x6F, 0x6E, 0x6C, 0x79, 0x2E, 0xA,
    0, 0xFF, 0xFF, 0xFF,
};

const char str_country_may_be_construed_as_copy_2[44] = {
    0x63, 0x6F, 0x75, 0x6E, 0x74, 0x72, 0x79, 0x20, 0x6D, 0x61, 0x79, 0x20, 0x62, 0x65, 0x20, 0x63,
    0x6F, 0x6E, 0x73, 0x74, 0x72, 0x75, 0x65, 0x64, 0x20, 0x61, 0x73, 0x20, 0x63, 0x6F, 0x70, 0x79,
    0x72, 0x69, 0x67, 0x68, 0x74, 0x20, 0x61, 0x6E, 0x64, 0xA, 0, 0xFF,
};

const char str_This_game_is_for_use_in_the_Ocea[48] = "This game is for use in the Oceanian countries\n";

const char str_Parental_Advisory[20] = {
    0x50, 0x61, 0x72, 0x65, 0x6E, 0x74, 0x61, 0x6C, 0x20, 0x41, 0x64, 0x76, 0x69, 0x73, 0x6F, 0x72,
    0x79, 0xA, 0, 0xFF,
};

const char str_Animated_violence_Mild[28] = "Animated violence - Mild\n\0\xFF\xFF";

const char str_Contains_scenes_of_violence_invo[40] = "Contains scenes of violence involving\n\0\xFF";

const char str_cartoon_like_characters_ina_fant[48] = "cartoon-like characters in a fantasy setting.\0\xFF\xFF";

const u8 sys_cfg_default_0_0[32] = {
    0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_0_1[32] = {
    0, 9, 1, 1, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_0_2[32] = {
    0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 2, 2, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_0_4[32] = {
    0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_0_3[32] = {
    0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_0_5[32] = {
    0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_0_6[32] = {
    0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_0_7[32] = {
    0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_0_8[32] = {
    0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 2, 2, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_1_0[32] = {
    1, 0, 1, 5, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_1_1[32] = {
    1, 9, 1, 5, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_1_2[32] = {
    1, 0, 1, 5, 0, 1, 0, 0, 1, 0, 0, 2, 2, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_1_4[32] = {
    1, 0, 1, 5, 0, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_1_3[32] = {
    1, 0, 1, 5, 0, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_1_5[32] = {
    1, 0, 1, 5, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_1_6[32] = {
    1, 0, 1, 5, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_1_7[32] = {
    1, 0, 1, 5, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_1_8[32] = {
    1, 0, 1, 5, 0, 1, 0, 0, 1, 0, 0, 2, 2, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_2_0[32] = {
    2, 0, 1, 0xA, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_2_1[32] = {
    2, 9, 1, 0xA, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_2_2[32] = {
    2, 0, 1, 0xA, 0, 1, 0, 0, 1, 0, 0, 2, 2, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_2_4[32] = {
    2, 0, 1, 0xA, 0, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_2_3[33] = {
    2, 0, 1, 0xA, 0, 1, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,
};

const u8 sys_cfg_default_2_5[32] = {
    2, 0, 1, 0xA, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_2_6[33] = {
    2, 0, 1, 0xA, 0, 1, 0, 0, 0, 1, 0, 0, 2, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,
};

const u8 sys_cfg_default_2_7[32] = {
    2, 0, 1, 0xA, 0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 sys_cfg_default_2_8[32] = {
    2, 0, 1, 0xA, 0, 1, 0, 0, 1, 0, 0, 2, 2, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 game_cfg_default_tbl_row0[16] = {
    0, 2, 1, 1, 1, 0, 0, 1, 0x97, 9, 0x25, 0, 0x33, 0x47, 0x41, 0x20,
};

const u8 game_cfg_default_tbl_row1[16] = {
    0, 2, 1, 1, 1, 0, 0, 1, 0x97, 9, 0x25, 3, 0x33, 0x47, 0x41, 0x20,
};

const u8 game_cfg_default_tbl_row2[16] = {
    0, 2, 1, 1, 1, 0, 0, 1, 0x97, 9, 0x25, 1, 0x33, 0x47, 0x41, 0x20,
};

const u8 game_cfg_default_tbl_row3[16] = {
    0, 2, 1, 1, 1, 0, 0, 1, 0x97, 9, 0x25, 4, 0x33, 0x47, 0x41, 0x20,
};

const u8 game_cfg_default_tbl_row4[16] = {
    0, 2, 1, 1, 1, 0, 0, 1, 0x97, 9, 0x25, 5, 0x33, 0x47, 0x41, 0x20,
};

const u8 game_cfg_default_tbl_row5[16] = {
    0, 2, 1, 1, 1, 0, 0, 1, 0x97, 9, 0x25, 2, 0x33, 0x47, 0x41, 0x20,
};

const u8 game_cfg_default_tbl_row6[16] = {
    0, 2, 1, 1, 1, 0, 0, 1, 0x97, 9, 0x25, 6, 0x33, 0x47, 0x41, 0x20,
};

const u8 game_cfg_default_tbl_row7[16] = {
    0, 2, 1, 1, 1, 0, 0, 1, 0x97, 9, 0x25, 7, 0x33, 0x47, 0x41, 0x20,
};

const u8 game_cfg_default_tbl_row8[18] = {
    0, 2, 1, 1, 1, 0, 1, 1, 0x97, 9, 0x25, 8, 0x33, 0x47, 0x41, 0x20,
    0xFF, 0xFF,
};

const u32 test_cursor_y_tbl[2][10] = {
    { 3, 5, 7, 9, 0xB, 0xD, 0xF, 0x11, 0x13, 0x15 },
    { 4, 6, 8, 0xA, 0xC, 0xE, 0x10, 0x12, 0x14, 0x16 },
};

const u32 test_cursor_x_tbl[2] = {
    0xE, 0xD,
};
