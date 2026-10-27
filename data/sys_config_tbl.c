/*
 * SYS_CONFIG_TBL.C  test mode system configuration values
 *
 * coin_rate_tbl gives the coins and credits of each coin setting; read by SYS_CONFIG.C and
 * SYS_CONFIG_2.C. The coin_setting_, chute_mode_, on_off_, sound_mode_ and monitor_ string
 * tables place the value texts of the system configuration page (coin and chute settings,
 * on/off, sound output, language, monitor), which are the str_ strings that follow, and
 * cursor_mark_str and cursor_blank_str draw and erase the menu cursor; read by SYS_CONFIG_2.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u8 coin_rate_tbl[][2];
extern const TM_STRING coin_setting_str_tbl_0[];
extern const TM_STRING coin_setting_str_tbl_1[];
extern const TM_STRING coin_setting_str_tbl_2[];
extern const TM_STRING coin_setting_str_tbl_3[];
extern const TM_STRING coin_setting_str_tbl_4[];
extern const TM_STRING coin_setting_str_tbl_5[];
extern const TM_STRING coin_setting_str_tbl_6[];
extern const TM_STRING coin_setting_str_tbl_7[];
extern const TM_STRING coin_setting_str_tbl_8[];
extern const TM_STRING coin_setting_str_tbl_9[];
extern const TM_STRING coin_setting_str_tbl_10[];
extern const TM_STRING coin_setting_str_tbl_11[];
extern const TM_STRING coin_setting_str_tbl_12[];
extern const TM_STRING coin_setting_str_tbl_13[];
extern const TM_STRING coin_setting_str_tbl_14[];
extern const TM_STRING coin_setting_str_tbl_15[];
extern const TM_STRING coin_setting_str_tbl_16[];
extern const TM_STRING coin_setting_str_tbl_17[];
extern const TM_STRING coin_setting_str_tbl_18[];
extern const TM_STRING chute_mode_str_tbl_0[];
extern const TM_STRING chute_mode_str_tbl_1[];
extern const TM_STRING chute_mode_str_tbl_2[];
extern const TM_STRING chute_mode_str_tbl_3[];
extern const TM_STRING chute_mode_str_tbl_4[];
extern const TM_STRING chute_mode_str_tbl_5[];
extern const TM_STRING chute_mode_str_tbl_6[];
extern const TM_STRING chute_mode_str_tbl_7[];
extern const TM_STRING chute_mode_str_tbl_8[];
extern const TM_STRING chute_mode_str_tbl_9[];
extern const TM_STRING chute_mode_str_tbl_10[];
extern const TM_STRING chute_mode_str_tbl_11[];
extern const TM_STRING on_off_str_tbl_1[];
extern const TM_STRING on_off_str_tbl_0[];
extern const TM_STRING sound_mode_str_tbl_0[];
extern const TM_STRING sound_mode_str_tbl_1[];
extern const TM_STRING sound_mode_str_tbl_2[];
extern const TM_STRING sound_mode_str_tbl_3[];
extern const TM_STRING sound_mode_str_tbl_4[];
extern const TM_STRING sound_mode_str_tbl_5[];
extern const TM_STRING monitor_str_tbl_1[];
extern const s8 cursor_blank_str[];
extern const s8 cursor_mark_str[];
extern const char str_1coin_1credit[];
extern const char str_1coin_2credits[];
extern const char str_1coin_3credits[];
extern const char str_1coin_4credits[];
extern const char str_1coin_5credits[];
extern const char str_1coin_6credits[];
extern const char str_1coin_7credits[];
extern const char str_1coin_8credits[];
extern const char str_1coin_9credits[];
extern const char str_2coins_1credit[];
extern const char str_3coins_1credit[];
extern const char str_4coins_1credit[];
extern const char str_5coins_1credit[];
extern const char str_6coins_1credit[];
extern const char str_7coins_1credit[];
extern const char str_8coins_1credit[];
extern const char str_9coins_1credit[];
extern const char str_2coins_start_1coin_cont[];
extern const char str_coin_free_play[];
extern const char str_2pl_1chute_single[];
extern const char str_2pl_2chutes_single[];
extern const char str_2pl_2chutes_multi[];
extern const char str_3pl_1chute_single[];
extern const char str_3pl_2chutes_single[];
extern const char str_3pl_3chutes_single[];
extern const char str_3pl_3chutes_multi[];
extern const char str_4pl_1chute_single[];
extern const char str_4pl_2chutes_single[];
extern const char str_4pl_2chutes_multi[];
extern const char str_4pl_4chutes_single[];
extern const char str_4pl_4chutes_multi[];
extern const char str_cfg_on[];
extern const char str_cfg_off[];
extern const char str_cfg_stereo[];
extern const char str_cfg_monaural[];
extern const char str_cfg_english[];
extern const char str_cfg_spanish[];
extern const char str_cfg_portuguese[];
extern const char str_cfg_normal[];
extern const char str_cfg_flip[];
extern const s8 str_cfg_flip_tail[];

/* one row per coin setting (Coin_Mode): { coins, credits } */
const u8 coin_rate_tbl[20][2] = {
    { 1, 1 },
    { 1, 2 },
    { 1, 3 },
    { 1, 4 },
    { 1, 5 },
    { 1, 6 },
    { 1, 7 },
    { 1, 8 },
    { 1, 9 },
    { 2, 1 },
    { 3, 1 },
    { 4, 1 },
    { 5, 1 },
    { 6, 1 },
    { 7, 1 },
    { 8, 1 },
    { 9, 1 },
    { 1, 1 },
    { 0, 0 },
    { 0xFF, 0xFF },
};

const TM_STRING coin_setting_str_tbl_0[1] = {
    { 0x12, 5, 0xE, (void *)str_1coin_1credit },
};

const TM_STRING coin_setting_str_tbl_1[1] = {
    { 0x12, 5, 0xE, (void *)str_1coin_2credits },
};

const TM_STRING coin_setting_str_tbl_2[1] = {
    { 0x12, 5, 0xE, (void *)str_1coin_3credits },
};

const TM_STRING coin_setting_str_tbl_3[1] = {
    { 0x12, 5, 0xE, (void *)str_1coin_4credits },
};

const TM_STRING coin_setting_str_tbl_4[1] = {
    { 0x12, 5, 0xE, (void *)str_1coin_5credits },
};

const TM_STRING coin_setting_str_tbl_5[1] = {
    { 0x12, 5, 0xE, (void *)str_1coin_6credits },
};

const TM_STRING coin_setting_str_tbl_6[1] = {
    { 0x12, 5, 0xE, (void *)str_1coin_7credits },
};

const TM_STRING coin_setting_str_tbl_7[1] = {
    { 0x12, 5, 0xE, (void *)str_1coin_8credits },
};

const TM_STRING coin_setting_str_tbl_8[1] = {
    { 0x12, 5, 0xE, (void *)str_1coin_9credits },
};

const TM_STRING coin_setting_str_tbl_9[1] = {
    { 0x12, 5, 0xE, (void *)str_2coins_1credit },
};

const TM_STRING coin_setting_str_tbl_10[1] = {
    { 0x12, 5, 0xE, (void *)str_3coins_1credit },
};

const TM_STRING coin_setting_str_tbl_11[1] = {
    { 0x12, 5, 0xE, (void *)str_4coins_1credit },
};

const TM_STRING coin_setting_str_tbl_12[1] = {
    { 0x12, 5, 0xE, (void *)str_5coins_1credit },
};

const TM_STRING coin_setting_str_tbl_13[1] = {
    { 0x12, 5, 0xE, (void *)str_6coins_1credit },
};

const TM_STRING coin_setting_str_tbl_14[1] = {
    { 0x12, 5, 0xE, (void *)str_7coins_1credit },
};

const TM_STRING coin_setting_str_tbl_15[1] = {
    { 0x12, 5, 0xE, (void *)str_8coins_1credit },
};

const TM_STRING coin_setting_str_tbl_16[1] = {
    { 0x12, 5, 0xE, (void *)str_9coins_1credit },
};

const TM_STRING coin_setting_str_tbl_17[1] = {
    { 0x12, 5, 0xE, (void *)str_2coins_start_1coin_cont },
};

const TM_STRING coin_setting_str_tbl_18[1] = {
    { 0x12, 5, 0xE, (void *)str_coin_free_play },
};

const TM_STRING chute_mode_str_tbl_0[1] = {
    { 0x12, 7, 0xE, (void *)str_2pl_1chute_single },
};

const TM_STRING chute_mode_str_tbl_1[1] = {
    { 0x12, 7, 0xE, (void *)str_2pl_2chutes_single },
};

const TM_STRING chute_mode_str_tbl_2[1] = {
    { 0x12, 7, 0xE, (void *)str_2pl_2chutes_multi },
};

const TM_STRING chute_mode_str_tbl_3[1] = {
    { 0x12, 7, 0xE, (void *)str_3pl_1chute_single },
};

const TM_STRING chute_mode_str_tbl_4[1] = {
    { 0x12, 7, 0xE, (void *)str_3pl_2chutes_single },
};

const TM_STRING chute_mode_str_tbl_5[1] = {
    { 0x12, 7, 0xE, (void *)str_3pl_3chutes_single },
};

const TM_STRING chute_mode_str_tbl_6[1] = {
    { 0x12, 7, 0xE, (void *)str_3pl_3chutes_multi },
};

const TM_STRING chute_mode_str_tbl_7[1] = {
    { 0x12, 7, 0xE, (void *)str_4pl_1chute_single },
};

const TM_STRING chute_mode_str_tbl_8[1] = {
    { 0x12, 7, 0xE, (void *)str_4pl_2chutes_single },
};

const TM_STRING chute_mode_str_tbl_9[1] = {
    { 0x12, 7, 0xE, (void *)str_4pl_2chutes_multi },
};

const TM_STRING chute_mode_str_tbl_10[1] = {
    { 0x12, 7, 0xE, (void *)str_4pl_4chutes_single },
};

const TM_STRING chute_mode_str_tbl_11[1] = {
    { 0x12, 7, 0xE, (void *)str_4pl_4chutes_multi },
};

const TM_STRING on_off_str_tbl_1[1] = {
    { 0x12, 0xB, 0xE, (void *)str_cfg_on },
};

const TM_STRING on_off_str_tbl_0[1] = {
    { 0x12, 0xB, 0xE, (void *)str_cfg_off },
};

const TM_STRING sound_mode_str_tbl_0[1] = {
    { 0x12, 0x10, 0xE, (void *)str_cfg_stereo },
};

const TM_STRING sound_mode_str_tbl_1[1] = {
    { 0x12, 0x10, 0xE, (void *)str_cfg_monaural },
};

const TM_STRING sound_mode_str_tbl_2[1] = {
    { 0x12, 0x13, 0xE, (void *)str_cfg_english },
};

const TM_STRING sound_mode_str_tbl_3[1] = {
    { 0x12, 0x13, 0xE, (void *)str_cfg_spanish },
};

const TM_STRING sound_mode_str_tbl_4[1] = {
    { 0x12, 0x13, 0xE, (void *)str_cfg_portuguese },
};

const TM_STRING sound_mode_str_tbl_5[1] = {
    { 0x12, 0xB, 0xE, (void *)str_cfg_normal },
};

const TM_STRING monitor_str_tbl_1[1] = {
    { 0x12, 0xB, 0xE, (void *)str_cfg_flip },
};

const s8 cursor_blank_str[4] = {
    32, 0, -1, -1,
};

const s8 cursor_mark_str[4] = {
    62, 0, -1, -1,
};

const char str_1coin_1credit[32] = "1 COIN  1 CREDIT             \0\xFF\xFF";

const char str_1coin_2credits[32] = "1 COIN  2 CREDITS            \0\xFF\xFF";

const char str_1coin_3credits[32] = "1 COIN  3 CREDITS            \0\xFF\xFF";

const char str_1coin_4credits[32] = "1 COIN  4 CREDITS            \0\xFF\xFF";

const char str_1coin_5credits[32] = "1 COIN  5 CREDITS            \0\xFF\xFF";

const char str_1coin_6credits[32] = "1 COIN  6 CREDITS            \0\xFF\xFF";

const char str_1coin_7credits[32] = "1 COIN  7 CREDITS            \0\xFF\xFF";

const char str_1coin_8credits[32] = "1 COIN  8 CREDITS            \0\xFF\xFF";

const char str_1coin_9credits[32] = "1 COIN  9 CREDITS            \0\xFF\xFF";

const char str_2coins_1credit[32] = "2 COINS 1 CREDIT             \0\xFF\xFF";

const char str_3coins_1credit[32] = "3 COINS 1 CREDIT             \0\xFF\xFF";

const char str_4coins_1credit[32] = "4 COINS 1 CREDIT             \0\xFF\xFF";

const char str_5coins_1credit[32] = "5 COINS 1 CREDIT             \0\xFF\xFF";

const char str_6coins_1credit[32] = "6 COINS 1 CREDIT             \0\xFF\xFF";

const char str_7coins_1credit[32] = "7 COINS 1 CREDIT             \0\xFF\xFF";

const char str_8coins_1credit[32] = "8 COINS 1 CREDIT             \0\xFF\xFF";

const char str_9coins_1credit[32] = "9 COINS 1 CREDIT             \0\xFF\xFF";

const char str_2coins_start_1coin_cont[32] = "2 COINS START 1 COIN CONTINUE\0\xFF\xFF";

const char str_coin_free_play[32] = "FREE PLAY                    \0\xFF\xFF";

const char str_2pl_1chute_single[28] = "2 PLAYERS 1 CHUTER  SINGLE ";

const char str_2pl_2chutes_single[28] = "2 PLAYERS 2 CHUTERS SINGLE ";

const char str_2pl_2chutes_multi[28] = "2 PLAYERS 2 CHUTERS MULTI  ";

const char str_3pl_1chute_single[28] = "3 PLAYERS 1 CHUTER  SINGLE ";

const char str_3pl_2chutes_single[28] = "3 PLAYERS 2 CHUTERS SINGLE ";

const char str_3pl_3chutes_single[28] = "3 PLAYERS 3 CHUTERS SINGLE ";

const char str_3pl_3chutes_multi[28] = "3 PLAYERS 3 CHUTERS MULTI  ";

const char str_4pl_1chute_single[28] = "4 PLAYERS 1 CHUTER  SINGLE ";

const char str_4pl_2chutes_single[28] = "4 PLAYERS 2 CHUTERS SINGLE ";

const char str_4pl_2chutes_multi[28] = "4 PLAYERS 2 CHUTERS MULTI  ";

const char str_4pl_4chutes_single[28] = "4 PLAYERS 4 CHUTERS SINGLE ";

const char str_4pl_4chutes_multi[28] = "4 PLAYERS 4 CHUTERS MULTI  ";

const char str_cfg_on[8] = "ON    \0\xFF";

const char str_cfg_off[8] = "OFF   \0\xFF";

const char str_cfg_stereo[12] = "STEREO  \0\xFF\xFF\xFF";

const char str_cfg_monaural[12] = "MONAURAL\0\xFF\xFF\xFF";

const char str_cfg_english[16] = "ENGLISH     \0\xFF\xFF\xFF";

const char str_cfg_spanish[16] = "SPANISH     \0\xFF\xFF\xFF";

const char str_cfg_portuguese[16] = "PORTUGUESE  \0\xFF\xFF\xFF";

const char str_cfg_normal[8] = "NORMAL\0\xFF";

const char str_cfg_flip[8] = "FLIP  \0\xFF";

/* Stored after str_cfg_flip. Nothing in the program refers to it by name or address. */
const s8 str_cfg_flip_tail[64] = {
    0, 0, 1, -1, 2, 0, 3, -1, 63, 15, 0, 13, 0, 0, 0, 0,
    0, 0, 1, -1, 2, 0, 3, -65, 63, 15, 0, 13, 0, 0, 0, 0,
    0, 0, 1, -1, 2, 0, 3, 127, 63, 15, 0, 13, 0, 0, 0, 0,
    0, 0, 1, -1, 2, 0, 3, 63, 63, 15, 0, 13, 0, 0, 0, 0,
};
