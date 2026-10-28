/*
 * COM_PL_TBL.C  boot screen text, region warnings and default settings
 *
 * boot_title_str and boot_region_str lay out the boot screen title and region name, and the
 * str_* strings are the boot, version, region warning and parental advisory text, the warning
 * lines placed through the warning screen layouts of MODE_INIT.C. sys_cfg_default_* are the
 * default system settings, nine rows for each of three cabinet types, and
 * game_cfg_default_tbl_row* the nine default game settings rows, reached through the lists in
 * MODE_INIT.C. All read by MODE_INIT.C, except parental_advisory_msg (DEMO00.C, the
 * attract-mode logos) and test_cursor_x_tbl and test_cursor_y_tbl (TEST_MODE.C, the test-mode
 * cursor). boot_version_str is not referred to by name.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const TM_STRING boot_title_str[];
extern const TM_STRING boot_region_str[];
extern const TM_STRING boot_version_str[];
extern const TM_STRING parental_advisory_msg[];
extern const s8 str_STREET_FIGHTER_III[];
extern const s8 str_2ND_IMPACT[];
extern const s8 str_970930[];
extern const s8 str_blank[];
extern const s8 str_JAPAN[];
extern const s8 str_ASIA[];
extern const s8 str_EURO[];
extern const s8 str_USA[];
extern const s8 str_HISPANIC[];
extern const s8 str_BRAZIL_3[];
extern const s8 str_OCEANIA[];
extern const s8 str_ASIA_2[];
extern const s8 str_NO_CD[];
extern const s8 str_PRODUCT_VERSION[];
extern const s8 str_CHARACTER_CHECK_VERSION[];
extern const s8 str_PUBLICITY_VERSION[];
extern const s8 str_LOCATION_TEST_VERSION[];
extern const s8 str_SHOW_VERSION[];
extern const s8 str_BUG_CHECK_VERSION[];
extern const s8 str_BENT_STAFF_VERSION[];
extern const s8 str_DEVELOPMENT_VERSION[];
extern const s8 str_CHECK_VERSION[];
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
extern const s8 str_Parental_Advisory[];
extern const s8 str_Animated_violence_Mild[];
extern const s8 str_Contains_scenes_of_violence_invo[];
extern const s8 str_cartoon_like_characters_ina_fant[];
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
    { 8, 8, 2, str_STREET_FIGHTER_III },
    { 8, 9, 2, str_2ND_IMPACT },
    { 17, 11, 2, str_970930 },
};

const TM_STRING boot_region_str[10] = {
    { 15, 13, 0xE, str_blank },
    { 19, 13, 2, str_JAPAN },
    { 15, 13, 4, str_ASIA },
    { 19, 13, 6, str_EURO },
    { 19, 13, 8, str_USA },
    { 16, 13, 0xA, str_HISPANIC },
    { 18, 13, 0xC, str_BRAZIL_3 },
    { 17, 13, 0xE, str_OCEANIA },
    { 19, 13, 4, str_ASIA_2 },
    { 19, 13, 2, str_NO_CD },
};

const TM_STRING boot_version_str[9] = {
    { 16, 14, 0xE, str_PRODUCT_VERSION },
    { 13, 14, 0xE, str_CHARACTER_CHECK_VERSION },
    { 16, 14, 0xE, str_PUBLICITY_VERSION },
    { 15, 14, 0xE, str_LOCATION_TEST_VERSION },
    { 18, 14, 0xE, str_SHOW_VERSION },
    { 16, 14, 0xE, str_BUG_CHECK_VERSION },
    { 16, 14, 0xE, str_BENT_STAFF_VERSION },
    { 15, 14, 0xE, str_DEVELOPMENT_VERSION },
    { 17, 14, 0xE, str_CHECK_VERSION },
};

const TM_STRING parental_advisory_msg[4] = {
    { 6, 22, 0x28, str_Parental_Advisory },
    { 6, 23, 0x28, str_Animated_violence_Mild },
    { 1, 25, 0x28, str_Contains_scenes_of_violence_invo },
    { 1, 26, 0x28, str_cartoon_like_characters_ina_fant },
};

const s8 str_STREET_FIGHTER_III[36] = "S T R E E T   F I G H T E R   III\n\0\xFF";

const s8 str_2ND_IMPACT[28] = "       2 N D  I M P A C T\n\0\xFF";

const s8 str_970930[16] = " 9 7 0 9 3 0\0\xFF\xFF\xFF";

const s8 str_blank[16] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0, 0xFF, 0xFF,
};

const s8 str_JAPAN[12] = "J A P A N\0\xFF\xFF";

const s8 str_ASIA[20] = " A S I A ( NCD )\0\xFF\xFF\xFF";

const s8 str_EURO[12] = " E U R O \0\xFF\xFF";

const s8 str_USA[12] = "  U S A  \0\xFF\xFF";

const s8 str_HISPANIC[16] = "H I S P A N I C";

const s8 str_BRAZIL_3[12] = "B R A Z I L";

const s8 str_OCEANIA[16] = "O C E A N I A\0\xFF\xFF";

const s8 str_ASIA_2[12] = " A S I A\0\xFF\xFF\xFF";

const s8 str_NO_CD[8] = " NO CD\0\xFF";

const s8 str_PRODUCT_VERSION[16] = "PRODUCT VERSION";

const s8 str_CHARACTER_CHECK_VERSION[24] = "CHARACTER CHECK VERSION";

const s8 str_PUBLICITY_VERSION[20] = "PUBLICITY VERSION\0\xFF\xFF";

const s8 str_LOCATION_TEST_VERSION[24] = "LOCATION TEST VERSION\0\xFF\xFF";

const s8 str_SHOW_VERSION[16] = "SHOW VERSION\0\xFF\xFF\xFF";

const s8 str_BUG_CHECK_VERSION[20] = "BUG CHECK VERSION\0\xFF\xFF";

const s8 str_BENT_STAFF_VERSION[20] = "BENT STAFF VERSION\0\xFF";

const s8 str_DEVELOPMENT_VERSION[20] = "DEVELOPMENT VERSION";

const s8 str_CHECK_VERSION[16] = "CHECK VERSION\0\xFF\xFF";

const char str_WARNING[12] = "WARNING\n\0\xFF\xFF\xFF";

const char str_This_game_is_for_use_in_japan_on[40] = "This game is for use in japan only.\n\0\xFF\xFF\xFF";

const char str_Sales_export_or_operation_outsid[44] = "Sales, export or operation outside this\n\0\xFF\xFF\xFF";

const char str_country_may_be_construed_as_copy[40] = "country may be construed as copyright\n\0\xFF";

const char str_and_trademark_infringement_and_i[44] = "and trademark infringement and is strictly\n";

const char str_prohibited[16] = "prohibited.\n\0\xFF\xFF\xFF";

const char str_Violators_are_subject_to_severe_[44] = "Violators are subject to severe penalties\n\0\xFF";

const char str_and_will_be_prosecuted_to_the_fu[44] = "and will be prosecuted to the full extent\n\0\xFF";

const char str_of_the_law[12] = "of the law.";

const char str_blank_2[4] = {
    0, 0xFF, 0xFF, 0xFF,
};

const char str_This_game_is_for_use_in_the_sout[40] = "This game is for use in the south-east\n";

const char str_Asian_countries_only[24] = "Asian countries only.\n\0\xFF";

const char str_Sales_export_or_operation_outsid_2[44] = "Sales, export or operation outside these\n\0\xFF\xFF";

const char str_countries_may_be_construed_as_co[48] = "countries may be construed as copyright and\n\0\xFF\xFF\xFF";

const char str_trademark_infringement_and_is_st[40] = "trademark infringement and is strictly\n";

const char str_This_game_is_for_use_in_the_Euro[48] = "This game is for use in the European countries\n";

const char str_only[8] = "only.\n\0\xFF";

const char str_This_game_is_for_use_in_the_Unit[44] = "This game is for use in the United States\n\0\xFF";

const char str_of_America_and_Canada_only[32] = "of America and Canada only.\n\0\xFF\xFF\xFF";

const char str_This_game_is_for_use_in_the_West[48] = "This game is for use in the Western Hemisphere\n";

const char str_countries_except_the_United_Stat[48] = "countries except the United States of America,\n";

const char str_Canada_and_the_Federative_Republ[48] = "Canada, and the Federative Republic of Brazil.\n";

const char str_This_game_is_for_use_in_the_Fede[52] = "This game is for use in the Federative Republic\n\0\xFF\xFF\xFF";

const char str_of_Brazil_only[20] = "of Brazil only.\n\0\xFF\xFF\xFF";

const char str_country_may_be_construed_as_copy_2[44] = "country may be construed as copyright and\n\0\xFF";

const char str_This_game_is_for_use_in_the_Ocea[48] = "This game is for use in the Oceanian countries\n";

const s8 str_Parental_Advisory[20] = "Parental Advisory\n\0\xFF";

const s8 str_Animated_violence_Mild[28] = "Animated violence - Mild\n\0\xFF\xFF";

const s8 str_Contains_scenes_of_violence_invo[40] = "Contains scenes of violence involving\n\0\xFF";

const s8 str_cartoon_like_characters_ina_fant[48] = "cartoon-like characters in a fantasy setting.\0\xFF\xFF";

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
