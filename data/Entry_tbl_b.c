/*
 * ENTRY_TBL_B.C  tables read by entry_2.c and mode_init.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 msg_free_play[];
extern const s8 msg_blank[];
extern const s8 msg_blank18[];
extern const s8 msg_continue[];
extern const s8 msg_continue_cnt[];
extern const u8 msg_game_over[];
extern const u8 msg_insert_2coins[];
extern const u8 msg_insert_coin[];
extern const u8 msg_insert_coins[];
extern const u8 msg_join_in[];
extern const s8 msg_press_2p_start[];
extern const s8 msg_press_1p_start[];
extern const s8 msg_please_wait[];
extern const s8 msg_insert_more_coin[];
extern const s8 msg_insert_more_coins[];
extern const s8 msg_coins[];
extern const s8 msg_credit[];
extern const s8 msg_plural_s[];
extern const s8 msg_credits[];
extern const s8 msg_space[];
extern const s8 msg_blank6[];
extern const s8 msg_coin_frac[];
extern const s8 msg_blank25[];
extern const s8 msg_insert_1_more[];
extern const s8 msg_press_1or2_start[];
extern const s8 msg_insert_2_more[];
extern const s8 msg_press_1p_button[];
extern const s8 msg_press_2p_button[];
extern const s8 str_INSERT_COIN[];
extern const s8 str_INSERT_COINS[];
extern const s8 str_INSERT_COINS_2[];
extern const s8 str_INSERT_COINS_3[];
extern const s8 str_INSERT_COINS_4[];
extern const s8 str_INSERT_COINS_5[];
extern const s8 str_INSERT_COINS_6[];
extern const s8 str_INSERT_COINS_7[];
extern const s8 str_INSERT_COINS_8[];
extern const s8 region_type_tbl[];
extern const s8 region_cc_type_tbl[];
extern const s8 region_param_tbl[];

const s8 msg_free_play[20] = "     FREE PLAY     ";

const s8 msg_blank[20] = {
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 0,
};

const s8 msg_blank18[20] = {
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 0, -1,
};

const s8 msg_continue[20] = "     CONTINUE_     ";

const s8 msg_continue_cnt[20] = {
    32, 32, 32, 32, 32, 67, 79, 78, 84, 73, 78, 85, 69, 95, 9, 32,
    32, 32, 32, 0,
};

const u8 msg_game_over[20] = "     GAME OVER     ";

const u8 msg_insert_2coins[24] = {
    0x20, 0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 2, 0x20, 0x43, 0x4F, 0x49, 0x4E,
    0x53, 0x20, 0x20, 0x20, 0, 0xFF, 0xFF, 0xFF,
};

const u8 msg_insert_coin[20] = "    INSERT COIN    ";

const u8 msg_insert_coins[20] = "   INSERT   COINS  ";

const u8 msg_join_in[20] = "      JOIN IN      ";

const s8 msg_press_2p_start[20] = {
    32, 32, 32, 80, 82, 69, 83, 83, 32, 2, 80, 32, 83, 84, 65, 82,
    84, 32, 32, 0,
};

const s8 msg_press_1p_start[20] = {
    32, 32, 32, 80, 82, 69, 83, 83, 32, 1, 80, 32, 83, 84, 65, 82,
    84, 32, 32, 0,
};

const s8 msg_please_wait[20] = "    PLEASE WAIT    ";

const s8 msg_insert_more_coin[20] = "INSERT   MORE COIN ";

const s8 msg_insert_more_coins[20] = "INSERT   MORE COINS";

const s8 msg_coins[8] = "COINS:\0\xFF";

const s8 msg_credit[12] = "CREDIT :\0\xFF\xFF\xFF";

const s8 msg_plural_s[4] = "S\0\xFF\xFF";

const s8 msg_credits[12] = "CREDITS:\0\xFF\xFF\xFF";

const s8 msg_space[4] = {
    32, 0, -1, -1,
};

const s8 msg_blank6[8] = {
    32, 32, 32, 32, 32, 32, 0, -1,
};

const s8 msg_coin_frac[8] = "( / )\0\xFF\xFF";

const s8 msg_blank25[28] = {
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 0, -1, -1,
};

const s8 msg_insert_1_more[20] = "INSERT 1 MORE COIN\0\xFF";

const s8 msg_press_1or2_start[28] = {
    80, 82, 69, 83, 83, 32, 1, 32, 79, 82, 32, 2, 32, 83, 84, 65,
    82, 84, 32, 66, 85, 84, 84, 79, 78, 0, -1, -1,
};

const s8 msg_insert_2_more[20] = "INSERT 2 MORE COINS";

const s8 msg_press_1p_button[24] = {
    80, 82, 69, 83, 83, 32, 1, 80, 32, 83, 84, 65, 82, 84, 32, 66,
    85, 84, 84, 79, 78, 0, -1, -1,
};

const s8 msg_press_2p_button[24] = {
    80, 82, 69, 83, 83, 32, 2, 80, 32, 83, 84, 65, 82, 84, 32, 66,
    85, 84, 84, 79, 78, 0, -1, -1,
};

const s8 str_INSERT_COIN[20] = "     INSERT COIN   ";

const s8 str_INSERT_COINS[20] = {
    32, 32, 32, 73, 78, 83, 69, 82, 84, 32, 2, 32, 67, 79, 73, 78,
    83, 32, 32, 0,
};

const s8 str_INSERT_COINS_2[20] = {
    32, 32, 32, 73, 78, 83, 69, 82, 84, 32, 3, 32, 67, 79, 73, 78,
    83, 32, 32, 0,
};

const s8 str_INSERT_COINS_3[20] = {
    32, 32, 32, 73, 78, 83, 69, 82, 84, 32, 4, 32, 67, 79, 73, 78,
    83, 32, 32, 0,
};

const s8 str_INSERT_COINS_4[20] = {
    32, 32, 32, 73, 78, 83, 69, 82, 84, 32, 5, 32, 67, 79, 73, 78,
    83, 32, 32, 0,
};

const s8 str_INSERT_COINS_5[20] = {
    32, 32, 32, 73, 78, 83, 69, 82, 84, 32, 6, 32, 67, 79, 73, 78,
    83, 32, 32, 0,
};

const s8 str_INSERT_COINS_6[20] = {
    32, 32, 32, 73, 78, 83, 69, 82, 84, 32, 7, 32, 67, 79, 73, 78,
    83, 32, 32, 0,
};

const s8 str_INSERT_COINS_7[20] = {
    32, 32, 32, 73, 78, 83, 69, 82, 84, 32, 8, 32, 67, 79, 73, 78,
    83, 32, 32, 0,
};

const s8 str_INSERT_COINS_8[20] = {
    32, 32, 32, 73, 78, 83, 69, 82, 84, 32, 9, 32, 67, 79, 73, 78,
    83, 32, 32, 0,
};

const s8 region_type_tbl[9] = {
    0, 0, 2, 5, 1, 3, 4, 7, 2,
};

const s8 region_cc_type_tbl[8] = {
    0, 2, 1, 1, 1, 1, 1, 2,
};

const s8 region_param_tbl[7] = {
    0, 0, 1, 2, 2, 4, -1,
};
