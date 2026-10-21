/*
 * DBG_WORK.C  debug menu work
 *
 * The text of the debug menus and object displays (initialised, section D) and the debug tools'
 * work RAM (section B): menu state, the recorder's snapshots, the box editor's copy and edit
 * buffers. A <name>_tail table holds the bytes between <name> and the next named variable.
 */

#include "types.h"
#include "structs.h"

extern const char CMD_MAIN_tbl_c_0615BD28[];
extern const char str_KOC_IX_PT_Nix[];
extern const char str_KOC_IX_PT_Nix_n[];
extern const s16 eff19_char_table[];
extern const s16 eff86_char_table[];
extern const s16 stg00_char_table[];
extern const s16 stg01_char_table[];
extern const s16 stg02_char_table[];
extern const s16 stg04_char_table[];
extern const s16 stg06_char_table[];
extern const s16 stg07_char_table[];
extern const s16 stg12_char_table[];
extern const u16 effH3_char_table[];
extern const u32 ag_face_panel_table[];
extern const u32 alex_atca[];
extern const u32 alex_btca[];
extern const u32 alex_caca[];
extern const u32 alex_cuca[];
extern const u32 alex_dmca[];
extern const u32 alex_exca[];
extern const u32 alex_nmca[];
extern const u32 alex_saca[];
extern const u32 alex_yuca[];
extern const u32 brz_char_table[];
extern const u32 dudley_atca[];
extern const u32 dudley_btca[];
extern const u32 dudley_caca[];
extern const u32 dudley_cuca[];
extern const u32 dudley_dmca[];
extern const u32 dudley_exca[];
extern const u32 dudley_nmca[];
extern const u32 dudley_saca[];
extern const u32 dudley_yuca[];
extern const u32 ef01_char_table[];
extern const u32 ef13_char_table[];
extern const u32 eff45_char_table[];
extern const u32 effg0_char_table_0[], effg0_char_table_1[], effg0_char_table_2[], effg0_char_table_3[], effg0_char_table_4[], effg0_char_table_5[], effg0_char_table_6[], effg0_char_table_7[], effg0_char_table_8[];
extern const u32 elena_atca[];
extern const u32 elena_btca[];
extern const u32 elena_caca[];
extern const u32 elena_cuca[];
extern const u32 elena_dmca[];
extern const u32 elena_exca[];
extern const u32 elena_nmca[];
extern const u32 elena_saca[];
extern const u32 elena_yuca[];
extern const u32 etc2_char_table[];
extern const u32 etc3_char_table[];
extern const u32 etc_char_table[];
extern const u32 gill_atca[];
extern const u32 gill_btca[];
extern const u32 gill_caca[];
extern const u32 gill_cuca[];
extern const u32 gill_dmca[];
extern const u32 gill_exca[];
extern const u32 gill_nmca[];
extern const u32 gill_saca[];
extern const u32 gill_yuca[];
extern const u32 gouki1_atca[];
extern const u32 gouki1_btca[];
extern const u32 gouki1_caca[];
extern const u32 gouki1_cuca[];
extern const u32 gouki1_dmca[];
extern const u32 gouki1_exca[];
extern const u32 gouki1_nmca[];
extern const u32 gouki1_saca[];
extern const u32 gouki1_yuca[];
extern const u32 gouki2_atca[];
extern const u32 gouki2_btca[];
extern const u32 gouki2_caca[];
extern const u32 gouki2_cuca[];
extern const u32 gouki2_dmca[];
extern const u32 gouki2_exca[];
extern const u32 gouki2_nmca[];
extern const u32 gouki2_saca[];
extern const u32 gouki2_yuca[];
extern const u32 hugo_atca[];
extern const u32 hugo_btca[];
extern const u32 hugo_caca[];
extern const u32 hugo_cuca[];
extern const u32 hugo_dmca[];
extern const u32 hugo_exca[];
extern const u32 hugo_nmca[];
extern const u32 hugo_saca[];
extern const u32 hugo_yuca[];
extern const u32 ibuki_atca[];
extern const u32 ibuki_btca[];
extern const u32 ibuki_caca[];
extern const u32 ibuki_cuca[];
extern const u32 ibuki_dmca[];
extern const u32 ibuki_exca[];
extern const u32 ibuki_nmca[];
extern const u32 ibuki_saca[];
extern const u32 ibuki_yuca[];
extern const u32 ken_atca[];
extern const u32 ken_btca[];
extern const u32 ken_caca[];
extern const u32 ken_cuca[];
extern const u32 ken_dmca[];
extern const u32 ken_exca[];
extern const u32 ken_nmca[];
extern const u32 ken_saca[];
extern const u32 ken_yuca[];
extern const u32 necro_atca[];
extern const u32 necro_btca[];
extern const u32 necro_caca[];
extern const u32 necro_cuca[];
extern const u32 necro_dmca[];
extern const u32 necro_exca[];
extern const u32 necro_nmca[];
extern const u32 necro_saca[];
extern const u32 necro_yuca[];
extern const u32 oro_atca[];
extern const u32 oro_btca[];
extern const u32 oro_caca[];
extern const u32 oro_cuca[];
extern const u32 oro_dmca[];
extern const u32 oro_exca[];
extern const u32 oro_nmca[];
extern const u32 oro_saca[];
extern const u32 oro_yuca[];
extern const u32 plef_char_table[];
extern const u32 ryu_atca[];
extern const u32 ryu_btca[];
extern const u32 ryu_caca[];
extern const u32 ryu_cuca[];
extern const u32 ryu_dmca[];
extern const u32 ryu_exca[];
extern const u32 ryu_nmca[];
extern const u32 ryu_saca[];
extern const u32 ryu_yuca[];
extern const u32 sean_atca[];
extern const u32 sean_btca[];
extern const u32 sean_caca[];
extern const u32 sean_cuca[];
extern const u32 sean_dmca[];
extern const u32 sean_exca[];
extern const u32 sean_nmca[];
extern const u32 sean_saca[];
extern const u32 sean_yuca[];
extern const u32 stg03_char_table[];
extern const u32 stg05_char_table[];
extern const u32 stg10_char_table[];
extern const u32 urien_atca[];
extern const u32 urien_btca[];
extern const u32 urien_caca[];
extern const u32 urien_cuca[];
extern const u32 urien_dmca[];
extern const u32 urien_exca[];
extern const u32 urien_nmca[];
extern const u32 urien_saca[];
extern const u32 urien_yuca[];
extern const u32 yang_atca[];
extern const u32 yang_btca[];
extern const u32 yang_caca[];
extern const u32 yang_cuca[];
extern const u32 yang_dmca[];
extern const u32 yang_exca[];
extern const u32 yang_nmca[];
extern const u32 yang_saca[];
extern const u32 yang_yuca[];
extern const u32 yun_atca[];
extern const u32 yun_btca[];
extern const u32 yun_caca[];
extern const u32 yun_cuca[];
extern const u32 yun_dmca[];
extern const u32 yun_exca[];
extern const u32 yun_nmca[];
extern const u32 yun_saca[];
extern const u32 yun_yuca[];
extern const u8 dbg_bg_select_tbl[];

extern TM_STRING dbg_menu_str[];
extern TM_STRING dbg_select_exit_str[];
extern TM_STRING dbg_obj_info_str[];
extern TM_STRING dbg_obj_rel_str[];
extern TM_STRING dbg_all_char_str[];
extern TM_STRING dbg_edit_num_str[];
extern TM_STRING dbg_parts_info_str[];
extern TM_STRING dbg_rec_menu_str[];
extern TM_STRING dbg_rec_clear_str[];
extern TM_STRING dbg_rec_nodata_str[];
extern TM_STRING dbg_hit_size_str[];
extern TM_STRING dbg_hit_part_str[];
extern TM_STRING dbg_cg_head_str[];
extern TM_STRING dbg_cg_att_str[];
extern TM_STRING dbg_cg_rival_str[];
extern TM_STRING dbg_cgd_info_str[];
extern TM_STRING dbg_att_data_str[];
extern TM_STRING dbg_hud_clr_str[];
extern TM_STRING dbg_hud_clr_mid_str[];
extern TM_STRING dbg_hud_clr_low_str[];
extern TM_STRING dbg_hud_clr_bottom_str[];
extern TM_STRING dbg_cm_label_str[];
extern TM_STRING dbg_cgd_type_str[];
extern TM_STRING dbg_pat_status_str[];
extern TM_STRING dbg_cg_group_str[];
extern TM_STRING dbg_preview_group_str[];
extern TM_STRING dbg_edit_group_str[];
extern TM_STRING dbg_extdat_str[];
extern TM_STRING dbg_eftype_names[];
extern TM_STRING dbg_eftype_s_str[];
extern TM_STRING dbg_eftype_usemj_str[];
extern TM_STRING dbg_cancel_on_str[];
extern TM_STRING dbg_cancel_off_str[];
extern TM_STRING dbg_koc_cmlp_str[];
extern TM_STRING dbg_koc_cml2_str[];
extern TM_STRING dbg_koc_cmsw_str[];
extern TM_STRING dbg_koc_cmja_str[];
extern TM_STRING dbg_koc_cmoa_str[];
extern TM_STRING dbg_koc_str[];
extern TM_STRING dbg_waza_kind_str[];
extern TM_STRING dbg_bg_name_str[];
extern TM_STRING dbg_char_name_str[];
extern TM_STRING dbg_act_kind_str[];
extern const TM_STRING* dbg_act_name_tbl[];
extern u32* dbg_pl_char_tbl[][9];

/* the code declares dbg_menu_str[15]; dbg_select_exit_str starts after its first 8 entries */
/* 02000F50 */
TM_STRING dbg_menu_str[8] = {
    { 0xD, 2, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 36) },
    { 0xA, 4, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 52) },
    { 0xA, 5, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 68) },
    { 0xA, 6, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 84) },
    { 0xA, 7, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 100) },
    { 0xA, 8, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 116) },
    { 0xA, 9, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 124) },
    { 0xA, 0xA, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 140) },
};
/* 02000FB0 */
TM_STRING dbg_select_exit_str[2] = {
    { 0x11, 3, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 148) },
    { 0x11, 4, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 168) },
};
/* 02000FC8 */
TM_STRING dbg_obj_info_str[10] = {
    { 1, 3, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 192) },
    { 1, 4, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 204) },
    { 1, 6, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 220) },
    { 1, 8, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 236) },
    { 1, 9, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 252) },
    { 1, 0xA, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 268) },
    { 1, 0xB, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 288) },
    { 1, 0xC, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 300) },
    { 1, 0xD, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 312) },
    { 1, 0xE, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 332) },
};
/* 02001040 */
TM_STRING dbg_obj_rel_str[3] = {
    { 1, 0xF, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 348) },
    { 1, 0x10, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 368) },
    { 1, 0x11, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 388) },
};
/* 02001064 */
TM_STRING dbg_all_char_str[7] = {
    { 0xF, 1, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 124) },
    { 1, 5, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 400) },
    { 1, 7, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 400) },
    { 4, 0xB, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 416) },
    { 4, 0xC, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 432) },
    { 4, 0xD, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 448) },
    { 4, 0xE, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 464) },
};
/* 020010B8 */
TM_STRING dbg_edit_num_str[4] = {
    { 1, 0x12, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 484) },
    { 1, 0x13, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 496) },
    { 1, 0x14, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 508) },
    { 1, 0x15, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 520) },
};
/* 020010E8 */
TM_STRING dbg_parts_info_str[17] = {
    { 1, 3, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 192) },
    { 1, 4, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 204) },
    { 1, 6, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 220) },
    { 1, 8, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 236) },
    { 1, 9, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 252) },
    { 1, 0xA, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 268) },
    { 1, 0xB, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 288) },
    { 1, 0xC, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 300) },
    { 1, 0xD, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 532) },
    { 1, 0xE, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 544) },
    { 1, 0xF, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 564) },
    { 1, 0x10, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 584) },
    { 1, 0x11, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 596) },
    { 1, 0x12, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 608) },
    { 1, 0x13, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 620) },
    { 1, 0x14, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 632) },
    { 1, 0x15, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 644) },
};
/* 020011B4 */
TM_STRING dbg_rec_menu_str[3] = {
    { 0x1B, 3, 6, (const s8 *)((const u8*)dbg_bg_select_tbl + 656) },
    { 0x1B, 4, 6, (const s8 *)((const u8*)dbg_bg_select_tbl + 676) },
    { 0x1B, 5, 6, (const s8 *)((const u8*)dbg_bg_select_tbl + 696) },
};
/* 020011D8 */
TM_STRING dbg_rec_clear_str[3] = {
    { 0x1B, 3, 6, (const s8 *)((const u8*)dbg_bg_select_tbl + 716) },
    { 0x1B, 4, 6, (const s8 *)((const u8*)dbg_bg_select_tbl + 716) },
    { 0x1B, 5, 6, (const s8 *)((const u8*)dbg_bg_select_tbl + 736) },
};
/* 020011FC */
TM_STRING dbg_rec_nodata_str[2] = {
    { 0x1B, 3, 6, (const s8 *)((const u8*)dbg_bg_select_tbl + 756) },
    { 0x1B, 4, 6, (const s8 *)((const u8*)dbg_bg_select_tbl + 780) },
};
/* 02001214 */
TM_STRING dbg_hit_size_str[16] = {
    { 1, 0xF, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 804) },
    { 1, 0x10, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 824) },
    { 1, 0x11, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 844) },
    { 1, 0x12, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 864) },
    { 1, 0x14, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 884) },
    { 1, 0x15, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 904) },
    { 0xA, 0x14, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 924) },
    { 0xA, 0x15, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 936) },
    { 0xA, 0x16, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 948) },
    { 0xA, 0x17, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 960) },
    { 0xA, 0x18, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 972) },
    { 0xA, 0x19, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 984) },
    { 0xA, 0x1A, 2, (const s8 *)((const u8*)dbg_bg_select_tbl + 996) },
    { 0xF, 0x19, 2, (const s8 *)str_KOC_IX_PT_Nix_n },
    { 0xF, 0x1A, 2, (const s8 *)str_KOC_IX_PT_Nix_n },
    { 0xF, 0x1B, 2, (const s8 *)str_KOC_IX_PT_Nix },
};
/* 020012D4 */
TM_STRING dbg_hit_part_str[13] = {
    { 0x24, 0xD, 2, (const s8 *)CMD_MAIN_tbl_c_0615BD28 },
    { 0x24, 0xE, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12) },
    { 0x24, 0xF, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 24) },
    { 0x24, 0x10, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 36) },
    { 0x24, 0x11, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 48) },
    { 0x24, 0x12, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 60) },
    { 0x24, 0x13, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 72) },
    { 0x24, 0x14, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 84) },
    { 0x24, 0x15, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 96) },
    { 0x24, 0x16, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 108) },
    { 0x24, 0x17, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 120) },
    { 0x24, 0x18, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 132) },
    { 0x24, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 144) },
};
/* 02001370 */
TM_STRING dbg_cg_head_str[6] = {
    { 0x1B, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 156) },
    { 0x1B, 4, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 180) },
    { 0x1B, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 192) },
    { 0x1B, 6, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 216) },
    { 0x1B, 7, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 240) },
    { 0x1B, 8, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 264) },
};
/* 020013B8 */
TM_STRING dbg_cg_att_str[6] = {
    { 0x1B, 0xA, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 276) },
    { 0x1B, 0xB, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 300) },
    { 0x1B, 0xC, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 324) },
    { 0x1B, 0xD, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 336) },
    { 0x1B, 0xE, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 348) },
    { 0x1B, 0xF, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 360) },
};
/* 02001400 */
TM_STRING dbg_cg_rival_str[4] = {
    { 0x1B, 0x10, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 372) },
    { 0x1B, 0x11, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 396) },
    { 0x1B, 0x12, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 420) },
    { 0x1B, 0x13, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 428) },
};
/* 02001430 */
TM_STRING dbg_cgd_info_str[8] = {
    { 0x1B, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 440) },
    { 0x1B, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 452) },
    { 0x1B, 4, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 464) },
    { 0x1B, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 476) },
    { 0x1B, 6, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 488) },
    { 0x1B, 7, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 500) },
    { 0x1B, 8, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 512) },
    { 0x1B, 9, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 524) },
};
/* 02001490 */
TM_STRING dbg_att_data_str[21] = {
    { 0x1B, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 532) },
    { 0x1B, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 540) },
    { 0x1B, 4, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 564) },
    { 0x1B, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 588) },
    { 0x1B, 6, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 612) },
    { 0x1B, 7, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 636) },
    { 0x1B, 8, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 660) },
    { 0x1B, 9, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 684) },
    { 0x1B, 0xA, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 708) },
    { 0x1B, 0xB, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 732) },
    { 0x1B, 0xC, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 756) },
    { 0x1B, 0xD, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 780) },
    { 0x1B, 0xE, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 804) },
    { 0x1B, 0xF, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 828) },
    { 0x1B, 0x10, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 852) },
    { 0x1B, 0x11, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 876) },
    { 0x1B, 0x12, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 900) },
    { 0x1B, 0x13, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 924) },
    { 0x1B, 0x14, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 948) },
    { 0x1B, 0x15, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 972) },
    { 0x1B, 0x16, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 996) },
};
/* 0200158C */
TM_STRING dbg_hud_clr_str[26] = {
    { 0x1B, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 4, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 6, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 7, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 8, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 9, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0xA, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0xB, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0xC, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0xD, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0xE, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0xF, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x10, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x11, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x12, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x13, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x14, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x15, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x16, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x17, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x18, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x1A, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x1B, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1052) },
};
/* 020016C4 */
TM_STRING dbg_hud_clr_mid_str[6] = {
    { 0x1B, 0xE, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0xF, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x10, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x11, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x12, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x13, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
};
/* 0200170C */
TM_STRING dbg_hud_clr_low_str[9] = {
    { 0x1B, 0x14, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x15, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x16, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x17, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x18, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x1A, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1020) },
    { 0x1B, 0x1B, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1052) },
    { 0x1B, 0x1C, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1052) },
};
/* 02001778 */
TM_STRING dbg_hud_clr_bottom_str[3] = {
    { 5, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1084) },
    { 5, 0x1A, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1084) },
    { 5, 0x1B, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1124) },
};
/* 0200179C */
TM_STRING dbg_cm_label_str[13] = {
    { 0x1B, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1164) },
    { 0x1B, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1172) },
    { 0x1B, 4, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1180) },
    { 0x1B, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1188) },
    { 0x1B, 6, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1196) },
    { 0x1B, 7, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1204) },
    { 0x1B, 8, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1212) },
    { 0x1B, 9, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1220) },
    { 0x1B, 0xA, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1228) },
    { 0x1B, 0xB, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1236) },
    { 0x1B, 0xC, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1244) },
    { 0x1B, 0xD, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1252) },
    { 0x1B, 0xE, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1260) },
};
/* 02001838 */
TM_STRING dbg_cgd_type_str[5] = {
    { 0x25, 1, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1268) },
    { 0x25, 2, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1276) },
    { 0x25, 2, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1284) },
    { 0x25, 2, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1292) },
    { 0x25, 2, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1300) },
};
/* 02001874 */
TM_STRING dbg_pat_status_str[23] = {
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1308) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1316) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1324) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1332) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1340) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1348) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1356) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1364) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1372) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1380) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1388) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1396) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1404) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1412) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1420) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1428) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1436) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1444) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1452) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1460) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1468) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1468) },
    { 0x25, 3, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1468) },
};
/* 02001988 */
TM_STRING dbg_cg_group_str[90] = {
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1476) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1484) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1492) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1500) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1508) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1516) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1524) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1532) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1540) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1548) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1556) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1564) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1572) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1580) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1588) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1596) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1604) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1612) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1620) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1628) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1636) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1644) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1652) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1660) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1668) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1676) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1684) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1692) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1700) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1708) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1716) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1724) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1732) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1740) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1748) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1756) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1764) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1772) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1780) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1788) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1796) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1804) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1812) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1820) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1828) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1836) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1844) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1852) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1860) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1868) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1876) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1884) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1892) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1900) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1908) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1916) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1924) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1932) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1940) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1948) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1956) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1964) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1972) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1980) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1988) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1996) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2004) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2012) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2020) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2028) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2036) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2044) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2052) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2060) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2068) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2076) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2084) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2092) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2100) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2108) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2116) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2124) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 0x25, 8, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
};
/* provisional name */
/* 02001DC0 */
TM_STRING dbg_preview_group_str[104] = {
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1476) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1484) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1492) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1500) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1508) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1516) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1524) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1532) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1540) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1548) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1556) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1564) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1572) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1580) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1588) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1596) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1604) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1612) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1620) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1628) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1636) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1644) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1652) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1660) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1668) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1676) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1684) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1692) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1700) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1708) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1716) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1724) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1732) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1740) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1748) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1756) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1764) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1772) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1780) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1788) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1796) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1804) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1812) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1820) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1828) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1836) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1844) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1852) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1860) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1868) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1876) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1884) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1892) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1900) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1908) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1916) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1924) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1932) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1940) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1948) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1956) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1964) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1972) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1980) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1988) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1996) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2004) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2012) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2020) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2028) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2036) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2044) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2052) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2060) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2068) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2076) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2084) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2092) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2100) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2108) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2116) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2124) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2140) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2148) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2156) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2164) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2172) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2180) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2188) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2196) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2204) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2212) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2220) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2228) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2236) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2244) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2252) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2260) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 4, 5, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
};
/* provisional name */
/* 020022A0 */
TM_STRING dbg_edit_group_str[107] = {
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1476) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1484) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1492) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1500) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1508) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1516) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1524) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1532) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1540) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1548) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1556) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1564) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1572) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1580) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1588) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1596) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1604) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1612) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1620) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1628) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1636) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1644) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1652) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1660) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1668) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1676) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1684) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1692) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1700) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1708) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1716) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1724) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1732) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1740) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1748) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1756) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1764) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1772) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1780) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1788) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1796) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1804) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1812) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1820) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1828) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1836) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1844) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1852) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1860) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1868) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1876) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1884) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1892) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1900) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1908) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1916) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1924) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1932) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1940) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1948) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1956) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1964) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1972) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1980) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1988) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 1996) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2004) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2012) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2020) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2028) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2036) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2044) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2052) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2060) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2068) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2076) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2084) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2092) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2100) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2108) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2116) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2124) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2140) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2148) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2156) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2164) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2172) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2180) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2188) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2196) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2204) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2212) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2220) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2228) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2236) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2244) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2252) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2260) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 1, 0x19, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
};
/* 020027A4 */
TM_STRING dbg_extdat_str[3] = {
    { 0x25, 0xC, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2268) },
    { 0x25, 0xC, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2272) },
    { 0x25, 0xC, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2276) },
};
/* 020027C8 */
TM_STRING dbg_eftype_names[9] = {
    { 0x25, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2280) },
    { 0x25, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2284) },
    { 0x25, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2288) },
    { 0x25, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2292) },
    { 0x25, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2292) },
    { 0x25, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2296) },
    { 0x25, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2296) },
    { 0x25, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2296) },
    { 0x25, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2300) },
};
/* 02002834 */
TM_STRING dbg_eftype_s_str[6] = {
    { 0x28, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2304) },
    { 0x28, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2308) },
    { 0x28, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2312) },
    { 0x28, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2316) },
    { 0x28, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2320) },
    { 0x28, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2324) },
};
/* 0200287C */
TM_STRING dbg_eftype_usemj_str[8] = {
    { 0x2A, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 0x2A, 0xF, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2328) },
    { 0x25, 0x18, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2336) },
    { 0x25, 0x18, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2344) },
    { 0x25, 0x18, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2352) },
    { 0x25, 0x18, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 0x25, 0x18, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
    { 0x25, 0x18, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2132) },
};
/* 020028DC */
TM_STRING dbg_cancel_on_str[8] = {
    { 0x2C, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2360) },
    { 0x2B, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2364) },
    { 0x2A, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2368) },
    { 0x29, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2372) },
    { 0x28, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2376) },
    { 0x27, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2380) },
    { 0x26, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2384) },
    { 0x25, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2384) },
};
/* 0200293C */
TM_STRING dbg_cancel_off_str[24] = {
    { 0x2C, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2388) },
    { 0x2B, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2392) },
    { 0x2A, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2396) },
    { 0x29, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2400) },
    { 0x28, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2404) },
    { 0x27, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2408) },
    { 0x26, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2412) },
    { 0x25, 0xD, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2412) },
    { 0x25, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2360) },
    { 0x26, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2364) },
    { 0x27, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2368) },
    { 0x28, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2372) },
    { 0x29, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2376) },
    { 0x2A, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2380) },
    { 0x2B, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2384) },
    { 0x2C, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2384) },
    { 0x25, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2416) },
    { 0x26, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2420) },
    { 0x27, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2424) },
    { 0x28, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2428) },
    { 0x29, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2432) },
    { 0x2A, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2436) },
    { 0x2B, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2440) },
    { 0x2C, 0x11, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2440) },
};
/* 02002A5C */
TM_STRING dbg_koc_cmlp_str[11] = {
    { 0xC, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2444) },
    { 0xC, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2448) },
    { 0xC, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2452) },
    { 0xC, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2456) },
    { 0xC, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2460) },
    { 0xC, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2464) },
    { 0xC, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2468) },
    { 0xC, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2472) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2476) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2480) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2480) },
};
/* 02002AE0 */
TM_STRING dbg_koc_cml2_str[11] = {
    { 0xC, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2444) },
    { 0xC, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2448) },
    { 0xC, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2452) },
    { 0xC, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2456) },
    { 0xC, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2460) },
    { 0xC, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2464) },
    { 0xC, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2468) },
    { 0xC, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2472) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2476) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2480) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2480) },
};
/* 02002B64 */
TM_STRING dbg_koc_cmsw_str[11] = {
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2444) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2448) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2452) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2456) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2460) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2472) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2464) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2468) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2476) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2480) },
    { 0x20, 0x19, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2480) },
};
/* 02002BE8 */
TM_STRING dbg_koc_cmja_str[11] = {
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2444) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2448) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2452) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2456) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2460) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2472) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2464) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2468) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2476) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2480) },
    { 0x20, 0x1A, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2480) },
};
/* 02002C6C */
TM_STRING dbg_koc_cmoa_str[9] = {
    { 0x20, 0x1B, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2444) },
    { 0x20, 0x1B, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2448) },
    { 0x20, 0x1B, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2452) },
    { 0x20, 0x1B, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2456) },
    { 0x20, 0x1B, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2460) },
    { 0x20, 0x1B, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2472) },
    { 0x20, 0x1B, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2464) },
    { 0x20, 0x1B, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2468) },
    { 0x20, 0x1B, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2476) },
};
/* 02002CD8 */
TM_STRING dbg_koc_str[9] = {
    { 0x20, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2444) },
    { 0x20, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2448) },
    { 0x20, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2452) },
    { 0x20, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2456) },
    { 0x20, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2460) },
    { 0x20, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2472) },
    { 0x20, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2464) },
    { 0x20, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2468) },
    { 0x20, 2, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2476) },
};
/* 02002D44 */
TM_STRING dbg_waza_kind_str[8] = {
    { 0x25, 4, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2484) },
    { 0x25, 4, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2488) },
    { 0x25, 4, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2492) },
    { 0x25, 4, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2496) },
    { 0x25, 4, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2500) },
    { 0x25, 4, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2504) },
    { 0x25, 4, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2508) },
    { 0x25, 4, 0xA, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2512) },
};
/* 02002DA4 */
TM_STRING dbg_bg_name_str[18] = {
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2516) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2532) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2548) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2564) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2580) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2596) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2612) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2628) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2644) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2660) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2676) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2692) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2708) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2724) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2740) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2756) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2772) },
    { 2, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2788) },
};
/* 02002E7C */
TM_STRING dbg_char_name_str[17] = {
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2804) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2812) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2820) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2828) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2836) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2844) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2852) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2860) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2868) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2876) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2884) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2892) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2900) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2908) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2916) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2924) },
    { 0xB, 3, 2, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2932) },
};
/* 02002F48 */
TM_STRING dbg_act_kind_str[1061] = {
    { 3, 5, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2940) },
    { 3, 5, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2948) },
    { 3, 5, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2956) },
    { 3, 5, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2964) },
    { 3, 5, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2972) },
    { 3, 5, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2980) },
    { 3, 5, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2988) },
    { 3, 5, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 2996) },
    { 3, 5, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3004) },
    { 3, 5, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3004) },
    { 3, 5, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3012) },
    { 3, 5, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3020) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3028) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3044) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3060) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3076) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3092) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3108) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3124) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3140) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3156) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3172) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3188) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3204) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3220) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3236) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3252) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3268) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3284) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3300) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3316) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3332) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3348) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3364) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3380) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3396) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3412) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3428) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3444) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3460) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3476) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3492) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3508) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3524) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3540) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3572) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3588) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3604) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3620) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3636) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3652) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3668) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3652) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3668) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3684) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3700) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3716) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3732) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3748) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3764) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3780) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3796) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3812) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3828) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3844) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3860) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3876) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3892) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3908) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3924) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3940) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3956) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3972) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3988) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4004) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4020) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4036) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4068) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4084) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4100) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4116) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4132) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4148) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4164) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4180) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4196) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4212) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4228) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4244) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4260) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4276) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4292) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4308) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4324) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4340) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4356) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4372) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4388) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4404) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4420) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4436) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4452) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4468) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4484) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4500) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4516) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4532) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4548) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4564) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4580) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4596) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4612) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4628) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4644) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4660) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4676) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4692) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4708) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4724) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4740) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4756) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4772) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4788) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4804) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4820) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4836) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4852) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4868) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4884) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4900) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4916) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4932) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4948) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4964) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4980) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 4996) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5012) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5028) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5044) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5060) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5076) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5092) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5108) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5124) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5140) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5156) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5172) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5188) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5204) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5220) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5236) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5252) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5268) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5284) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5300) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5316) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5332) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5348) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5364) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5380) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5396) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5412) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5428) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5444) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5460) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5476) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5492) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5508) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5524) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5540) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5572) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5588) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5604) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5620) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5636) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5652) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5668) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5684) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5700) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5716) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5732) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5748) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5764) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5780) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5796) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5812) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5828) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5844) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5860) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5876) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5892) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5908) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5924) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5940) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5956) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5972) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 5988) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6004) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6020) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6036) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6068) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6084) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6100) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6116) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6132) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6148) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6164) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6180) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6196) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6212) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6228) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6244) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6260) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6276) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6292) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6308) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6324) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6340) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6356) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6372) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6388) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6404) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6420) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6436) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6452) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6468) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6484) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6500) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6516) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6532) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6548) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6564) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6580) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6596) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6612) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6628) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6644) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6660) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6676) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6692) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6708) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6724) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6740) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6756) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6772) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6788) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6804) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6820) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6836) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6852) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6868) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6884) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6900) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6916) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6932) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6948) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6964) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6980) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 6996) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7012) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7028) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7044) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7060) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7076) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7092) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7108) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7124) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7140) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7156) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7172) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7188) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7204) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7220) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7236) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7252) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7268) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7284) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7300) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7316) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7332) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7348) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7364) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7380) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7396) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7412) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7428) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7444) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7460) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7476) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7492) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7508) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7524) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7540) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7572) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7588) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7604) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7620) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7636) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7652) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7668) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7684) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7700) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7716) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7732) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7748) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7764) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7780) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7796) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7812) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7828) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7844) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7860) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7876) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7892) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7908) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7924) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7940) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7956) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7972) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 7988) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8004) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8020) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8036) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8068) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8084) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8100) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8116) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8132) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8148) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8164) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8180) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8196) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8212) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8228) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8244) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8260) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8276) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8292) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8308) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8324) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8340) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8356) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8372) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8388) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8404) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8420) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8004) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8436) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8452) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8468) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8484) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8500) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8516) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8532) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8548) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8564) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8580) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8596) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8612) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8628) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8644) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8660) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8676) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8692) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8708) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8724) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8740) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8756) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8772) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8788) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8804) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8820) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8836) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8852) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8820) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8836) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8852) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8820) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8836) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8852) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8868) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8884) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8900) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8868) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8884) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8900) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8868) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8884) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8900) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8916) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8932) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8948) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8964) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8980) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 8996) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9012) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9028) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9044) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9060) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9076) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9092) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9108) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9124) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9140) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9156) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9172) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9188) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9204) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9220) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9236) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9252) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9268) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9284) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9300) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9316) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9332) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9348) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9364) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9380) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9396) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9412) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9428) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9444) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9460) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9476) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9492) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9508) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9524) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9540) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9572) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9588) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9604) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9620) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9636) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9652) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9668) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9684) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9700) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9716) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9732) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9748) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9764) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9780) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9796) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9812) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9828) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9844) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9860) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9876) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9892) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9908) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9924) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9940) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9956) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9972) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 9988) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10004) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10020) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10036) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10068) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10084) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10100) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10116) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10132) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10148) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10164) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10180) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10196) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10212) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10228) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10244) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10260) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10276) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10292) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10308) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10324) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10340) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10356) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10372) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10388) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10404) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10420) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10436) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10452) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10468) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10484) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10500) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10516) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10532) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10548) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10564) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10580) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10596) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10612) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10628) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10644) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10660) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10676) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10692) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10708) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10724) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10740) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10756) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10772) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10788) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10804) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10820) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10836) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10852) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10868) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10884) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10900) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10916) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10932) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10948) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10964) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10980) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 10996) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11012) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11028) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11044) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11060) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11076) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11092) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11108) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11124) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11140) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11156) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11172) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11188) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11204) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11220) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11236) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11252) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11268) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11284) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11300) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11316) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11332) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11348) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11364) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11380) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11396) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11412) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11428) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11444) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11460) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11476) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11492) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11508) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11524) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11540) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11572) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11588) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11604) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11620) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11636) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11652) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11668) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11684) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11700) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11716) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11732) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11748) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11764) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11780) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11796) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11812) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11828) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11844) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11860) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11876) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11892) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11908) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11924) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11940) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11956) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11972) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 11988) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12004) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12020) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12036) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12052) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12068) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12084) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12100) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12116) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12132) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12148) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12164) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12180) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12196) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12212) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12228) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12244) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12260) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12276) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12292) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12308) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12324) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12340) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12356) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12372) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12388) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12404) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12420) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12436) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12452) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12468) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12484) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12500) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12516) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12532) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12548) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12564) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12580) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12596) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12612) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12628) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12644) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12660) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12676) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12692) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12708) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12724) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12740) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12756) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12772) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12788) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12804) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12820) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12836) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12852) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12868) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12884) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12900) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12916) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12932) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12948) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12964) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12980) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 12996) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13012) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13028) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13044) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13060) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13076) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13092) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13108) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13124) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13140) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13156) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13172) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13172) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13172) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13172) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13188) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13188) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13188) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13188) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13204) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13204) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13204) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13204) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13220) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13236) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13252) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13268) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13284) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13300) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 13316) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
    { 3, 7, 4, (const s8 *)((const u8*)CMD_MAIN_tbl_c_0615BD28 + 3556) },
};
/* 02006104 */
const TM_STRING* dbg_act_name_tbl[11] = {
    (const TM_STRING *)((u8*)dbg_act_kind_str + 144),
    (const TM_STRING *)((u8*)dbg_act_kind_str + 924),
    (const TM_STRING *)((u8*)dbg_act_kind_str + 3924),
    (const TM_STRING *)((u8*)dbg_act_kind_str + 4500),
    (const TM_STRING *)((u8*)dbg_act_kind_str + 5100),
    (const TM_STRING *)((u8*)dbg_act_kind_str + 8472),
    (const TM_STRING *)((u8*)dbg_act_kind_str + 2172),
    (const TM_STRING *)((u8*)dbg_act_kind_str + 9816),
    (const TM_STRING *)((u8*)dbg_act_kind_str + 11844),
    (const TM_STRING *)((u8*)dbg_act_kind_str + 11844),
    (const TM_STRING *)((u8*)dbg_act_kind_str + 11388),
};
/* 02006130 */
u32* dbg_pl_char_tbl[20][9] = {
    { (u32 *)gill_nmca, (u32 *)gill_dmca, (u32 *)gill_caca, (u32 *)gill_cuca, (u32 *)gill_atca, (u32 *)gill_saca, (u32 *)gill_btca, (u32 *)gill_exca, (u32 *)gill_yuca },
    { (u32 *)alex_nmca, (u32 *)alex_dmca, (u32 *)alex_caca, (u32 *)alex_cuca, (u32 *)alex_atca, (u32 *)alex_saca, (u32 *)alex_btca, (u32 *)alex_exca, (u32 *)alex_yuca },
    { (u32 *)ryu_nmca, (u32 *)ryu_dmca, (u32 *)ryu_caca, (u32 *)ryu_cuca, (u32 *)ryu_atca, (u32 *)ryu_saca, (u32 *)ryu_btca, (u32 *)ryu_exca, (u32 *)ryu_yuca },
    { (u32 *)yun_nmca, (u32 *)yun_dmca, (u32 *)yun_caca, (u32 *)yun_cuca, (u32 *)yun_atca, (u32 *)yun_saca, (u32 *)yun_btca, (u32 *)yun_exca, (u32 *)yun_yuca },
    { (u32 *)dudley_nmca, (u32 *)dudley_dmca, (u32 *)dudley_caca, (u32 *)dudley_cuca, (u32 *)dudley_atca, (u32 *)dudley_saca, (u32 *)dudley_btca, (u32 *)dudley_exca, (u32 *)dudley_yuca },
    { (u32 *)necro_nmca, (u32 *)necro_dmca, (u32 *)necro_caca, (u32 *)necro_cuca, (u32 *)necro_atca, (u32 *)necro_saca, (u32 *)necro_btca, (u32 *)necro_exca, (u32 *)necro_yuca },
    { (u32 *)hugo_nmca, (u32 *)hugo_dmca, (u32 *)hugo_caca, (u32 *)hugo_cuca, (u32 *)hugo_atca, (u32 *)hugo_saca, (u32 *)hugo_btca, (u32 *)hugo_exca, (u32 *)hugo_yuca },
    { (u32 *)ibuki_nmca, (u32 *)ibuki_dmca, (u32 *)ibuki_caca, (u32 *)ibuki_cuca, (u32 *)ibuki_atca, (u32 *)ibuki_saca, (u32 *)ibuki_btca, (u32 *)ibuki_exca, (u32 *)ibuki_yuca },
    { (u32 *)elena_nmca, (u32 *)elena_dmca, (u32 *)elena_caca, (u32 *)elena_cuca, (u32 *)elena_atca, (u32 *)elena_saca, (u32 *)elena_btca, (u32 *)elena_exca, (u32 *)elena_yuca },
    { (u32 *)oro_nmca, (u32 *)oro_dmca, (u32 *)oro_caca, (u32 *)oro_cuca, (u32 *)oro_atca, (u32 *)oro_saca, (u32 *)oro_btca, (u32 *)oro_exca, (u32 *)oro_yuca },
    { (u32 *)yang_nmca, (u32 *)yang_dmca, (u32 *)yang_caca, (u32 *)yang_cuca, (u32 *)yang_atca, (u32 *)yang_saca, (u32 *)yang_btca, (u32 *)yang_exca, (u32 *)yang_yuca },
    { (u32 *)ken_nmca, (u32 *)ken_dmca, (u32 *)ken_caca, (u32 *)ken_cuca, (u32 *)ken_atca, (u32 *)ken_saca, (u32 *)ken_btca, (u32 *)ken_exca, (u32 *)ken_yuca },
    { (u32 *)sean_nmca, (u32 *)sean_dmca, (u32 *)sean_caca, (u32 *)sean_cuca, (u32 *)sean_atca, (u32 *)sean_saca, (u32 *)sean_btca, (u32 *)sean_exca, (u32 *)sean_yuca },
    { (u32 *)urien_nmca, (u32 *)urien_dmca, (u32 *)urien_caca, (u32 *)urien_cuca, (u32 *)urien_atca, (u32 *)urien_saca, (u32 *)urien_btca, (u32 *)urien_exca, (u32 *)urien_yuca },
    { (u32 *)gouki1_nmca, (u32 *)gouki1_dmca, (u32 *)gouki1_caca, (u32 *)gouki1_cuca, (u32 *)gouki1_atca, (u32 *)gouki1_saca, (u32 *)gouki1_btca, (u32 *)gouki1_exca, (u32 *)gouki1_yuca },
    { (u32 *)gouki2_nmca, (u32 *)gouki2_dmca, (u32 *)gouki2_caca, (u32 *)gouki2_cuca, (u32 *)gouki2_atca, (u32 *)gouki2_saca, (u32 *)gouki2_btca, (u32 *)gouki2_exca, (u32 *)gouki2_yuca },
    { (u32 *)ef01_char_table, (u32 *)ef13_char_table, (u32 *)stg00_char_table, (u32 *)stg01_char_table, (u32 *)stg02_char_table, (u32 *)stg03_char_table, (u32 *)stg10_char_table, (u32 *)stg04_char_table, (u32 *)stg05_char_table },
    { (u32 *)stg06_char_table, (u32 *)stg07_char_table, (u32 *)eff45_char_table, (u32 *)eff86_char_table, (u32 *)brz_char_table, (u32 *)eff19_char_table, (u32 *)stg12_char_table, (u32 *)etc_char_table, (u32 *)etc2_char_table },
    { (u32 *)etc3_char_table, (u32 *)effg0_char_table_0, (u32 *)effg0_char_table_1, (u32 *)effg0_char_table_2, (u32 *)effg0_char_table_3, (u32 *)effg0_char_table_4, (u32 *)effg0_char_table_5, (u32 *)effg0_char_table_6, (u32 *)effg0_char_table_7 },
    { (u32 *)ag_face_panel_table, (u32 *)plef_char_table, (u32 *)effH3_char_table, 0, 0, 0, 0, 0, 0 },
};

s8 Debug_R_No;  /* 02015A38 */
s8 Debug_Select_No;  /* 02015A39 */
s8 Debug_Menu_No;  /* 02015A3A */
s8 Debug_Tool_No;  /* 02015A3B */
s16 Debug_Rep_Timer[21];  /* 02015A3C */
s8 Debug_Rep_Count[21];  /* 02015A66 */
s16 Debug_RGB[4];  /* 02015A7C */
s8 Debug_RL_Flag[2];  /* 02015A84 */
s8 Debug_CG_Flip[2];  /* 02015A86 */
s8 Debug_Flip_Work[2];  /* 02015A88 */
s8 Debug_Flip_Mask[2];  /* 02015A8A */
s8 Debug_Play_Flag;  /* 02015A8C */
s8 Debug_Snap_Disp;  /* 02015A8D */
s8 Debug_Dec_Disp;  /* 02015A8E */
s16 Debug_Rec_Frame;  /* 02015A90 */
s16 Debug_Rec_Count;  /* 02015A92 */
s8 Debug_PL_id;  /* 02015A94 */
s8 Debug_Command;  /* 02015A95 */
s8 Debug_Edit_Sub;  /* 02015A96 */
s8 Debug_Hit_Sub;  /* 02015A97 */
s8 Debug_Box_Edit;  /* 02015A98 */
s8 dbg_copy_done;  /* 02015A99 */
s8 dbg_snap_req;  /* 02015A9A */
s8 dbg_hud_mode;  /* 02015A9B */
s8 dbg_rec_menu;  /* 02015A9C */
s8 dbg_save_mode;  /* 02015A9D */
s8 dbg_look_mode;  /* 02015A9E */
s8 dbg_kakusyuku_mode;  /* 02015A9F */
s8 dbg_rec_exist;  /* 02015AA0 */
s8 dbg_cmd_panel;  /* 02015AA1 */
s8 dbg_col_ix[2];  /* 02015AA2 */
s8 dbg_stage_sel;  /* 02015AA4 */
s8 dbg_stage_sub;  /* 02015AA5 */
s16 dbg_judge_eff_ix;  /* 02015AA6 */
s16 dbg_zoom_x;  /* 02015AA8 */
s16 dbg_zoom_y;  /* 02015AAA */
s16 dbg_old_cgd_type;  /* 02015AAC */
s16 dbg_hud_x;  /* 02015AAE */
s16 dbg_copy_pat;  /* 02015AB0 */
s16 dbg_copy_char;  /* 02015AB2 */
u8 dbg_copy_char_tail[2];  /* after dbg_copy_char; nothing refers to it by name or address */
u16 dbg_p1sw_0;  /* 02015AB6 */
u16 dbg_p1sw_1;  /* 02015AB8 */
u16 dbg_p2sw_0;  /* 02015ABA */
u16 dbg_p2sw_1;  /* 02015ABC */
s16 dbg_dipsw_0;  /* 02015ABE */
s16 dbg_dipsw_1;  /* 02015AC0 */
s16* dbg_edit_box;  /* 02015AC4 */
s16 dbg_col_char;  /* 02015AC8 */
PLW* dbg_pl;  /* 02015ACC */
DBG_SLOT* dbg_slot;  /* 02015AD0 */
s16 dbg_slot_w[2][9];  /* 02015AD4 */
SNAPSHOT* dbg_snap_ptr;  /* 02015AF8 */
SNAPSHOT dbg_snap_w[2][128];  /* 02015AFC */
WORK_Other* dbg_ghost_ewk[2][3];  /* 020174FC */
PATTERN_BUF dbg_look_buf;  /* 02017514 */
u8 dbg_look_buf_tail[20];  /* after dbg_look_buf; nothing refers to it by name or address */
PATTERN_BUF dbg_copy_buf;  /* 02017EB4 */
u8 dbg_copy_buf_tail[20];  /* after dbg_copy_buf; nothing refers to it by name or address */
PATTERN_BUF dbg_edit_buf;  /* 02018854 */
u8 dbg_edit_buf_tail[20];  /* after dbg_edit_buf; nothing refers to it by name or address */
WORK_Other_JUDGE* dbg_judge_ewk;  /* 020191F4 */
u8 dbg_look_judge[1584];  /* 020191F8 */
HITA_BOX dbg_look_body[99];  /* 02019828 */
HITA_BOX dbg_look_hand[99];  /* 0201A488 */
u8 dbg_look_catch[792];  /* 0201B0E8 */
u8 dbg_look_caught[792];  /* 0201B400 */
HITA_BOX dbg_look_attack[49];  /* 0201B718 */
u8 dbg_look_attack_tail[16];  /* after dbg_look_attack; nothing refers to it by name or address */
u8 dbg_look_eat[1584];  /* 0201BD48, provisional name */
u8 dbg_look_hosei[792];  /* 0201C378 */
u8 dbg_edit_judge[1584];  /* 0201C690 */
u8 dbg_edit_body[3168];  /* 0201CCC0 */
u8 dbg_edit_hand[3168];  /* 0201D920 */
u8 dbg_edit_catch[792];  /* 0201E580 */
u8 dbg_edit_caught[792];  /* 0201E898 */
u8 dbg_edit_attack[1584];  /* 0201EBB0 */
u8 dbg_edit_eat[1584];  /* 0201F1E0, provisional name */
u8 dbg_edit_hosei[792];  /* 0201F810 */
u8 dbg_copy_judge[16];  /* 0201FB28 */
u8 dbg_copy_body[32];  /* 0201FB38 */
u8 dbg_copy_hand[32];  /* 0201FB58 */
u8 dbg_copy_catch[8];  /* 0201FB78 */
u8 dbg_copy_caught[8];  /* 0201FB80 */
u8 dbg_copy_attack[16];  /* 0201FB88 */
u8 dbg_copy_eat[16];  /* 0201FB98, provisional name */
u8 dbg_copy_hosei[8];  /* 0201FBA8 */
s16 dbg_parts_olc_ix[4];  /* 0201FBB0 */
s8 dbg_parts_sel;  /* 0201FBB8 */
PLW dbg_parts_plw[4];  /* 0201FBBC */
u8 dbg_parts_plw_tail[4];  /* after dbg_parts_plw; nothing refers to it by name or address */
