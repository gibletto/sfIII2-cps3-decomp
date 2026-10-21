/*
 * CMD_MAIN_TBL.C  tables read by game_config_en.c: test-mode game configuration, English page
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const TM_STRING config_title_str_tbl[];
extern const TM_STRING config_help_modify_str_tbl[];
extern const TM_STRING config_help_return_str_tbl[];
extern const s16 gcfg_gauge_clr_chr_en[];
extern const s16 gcfg_gauge_chr_en[];
extern const u8 CMD_MAIN_tbl_b_0615B198[];
extern const u8 gcfg_help_modify_en[];
extern const u8 gcfg_help_return_en[];
extern const u8 gcfg_help_select2_en[];
extern const u8 gcfg_help_shot1_en[];
extern const u8 gcfg_help_shots_en[];
extern const u8 gcfg_line_1p_round_en[];
extern const u8 gcfg_line_2p_round_en[];
extern const u8 gcfg_line_bonus_en[];
extern const u8 gcfg_line_damage_en[];
extern const u8 gcfg_line_event_en[];
extern const u8 gcfg_line_exit_en[];
extern const u8 gcfg_line_level_en[];
extern const u8 gcfg_line_timer_en[];
extern const u8 gcfg_line_title_en[];

const TM_STRING config_title_str_tbl[18] = {
    { 3, 1, 2, (void *)gcfg_line_title_en },
    { 5, 4, 2, (void *)gcfg_line_level_en },
    { 5, 6, 2, (void *)gcfg_line_damage_en },
    { 5, 8, 2, (void *)gcfg_line_timer_en },
    { 5, 0xA, 2, (void *)gcfg_line_1p_round_en },
    { 5, 0xC, 2, (void *)gcfg_line_2p_round_en },
    { 5, 0xE, 2, (void *)gcfg_line_event_en },
    { 5, 0x10, 2, (void *)gcfg_line_bonus_en },
    { 5, 0x12, 2, (void *)gcfg_line_exit_en },
    { 9, 0x19, 2, (void *)CMD_MAIN_tbl_b_0615B198 },
    { 3, 1, 2, (void *)gcfg_line_title_en },
    { 5, 4, 2, (void *)((const u8 *)CMD_MAIN_tbl_b_0615B198 + 32) },
    { 5, 6, 2, (void *)((const u8 *)CMD_MAIN_tbl_b_0615B198 + 76) },
    { 5, 8, 2, (void *)((const u8 *)CMD_MAIN_tbl_b_0615B198 + 116) },
    { 5, 0xA, 2, (void *)((const u8 *)CMD_MAIN_tbl_b_0615B198 + 156) },
    { 5, 0xC, 2, (void *)((const u8 *)CMD_MAIN_tbl_b_0615B198 + 188) },
    { 5, 0xE, 2, (void *)((const u8 *)CMD_MAIN_tbl_b_0615B198 + 216) },
    { 9, 0x19, 2, (void *)CMD_MAIN_tbl_b_0615B198 },
};

const TM_STRING config_help_modify_str_tbl[2] = {
    { 9, 0x1A, 2, (void *)gcfg_help_modify_en },
    { 9, 0x1B, 2, (void *)gcfg_help_shots_en },
};

const TM_STRING config_help_return_str_tbl[3] = {
    { 9, 0x19, 2, (void *)gcfg_help_select2_en },
    { 9, 0x1A, 2, (void *)gcfg_help_return_en },
    { 9, 0x1B, 2, (void *)gcfg_help_shot1_en },
};

const s16 gcfg_gauge_clr_chr_en[1] = {
    42,
};

const s16 gcfg_gauge_chr_en[9] = {
    49, 50, 51, 52, 53, 54, 55, 56,
    -1,
};
