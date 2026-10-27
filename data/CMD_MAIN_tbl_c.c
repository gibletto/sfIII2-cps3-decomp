/*
 * CMD_MAIN_TBL_C.C  debug menu text and tables
 *
 * The dbg_*_str and str_* strings are the labels of the debug screens: menu titles, cg data
 * and judgement box field names, stage, stage part and character names, and the names of the
 * normal, damage, catch, caught and attack motions and of the throws; read by CMD_MAIN.C, the
 * debug menu, and gathered into the menu tables of DBG_WORK.C. The tables give the colours of
 * debug objects and players, the first cg code of each cg group, colour codes and numbers, and
 * the stage and area of each BG select entry; bcp_group_top_tbl and dbg_stage_area_tbl are not
 * referred to by name. chk22_tbl lists the eight lever directions marked in a move slot when
 * the command check starts; read by CMD_MAIN_2.C, the command input.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const char dbg_hex_mark_str[];
extern const char dbg_2p_str[];
extern const char dbg_1p_str[];
extern const char dbg_hold_str[];
extern const char dbg_free_str[];
extern const char dbg_copy_str[];
extern const char dbg_user_str[];
extern const char dbg_define_str[];
extern const char dbg_lp_str[];
extern const char dbg_nix_str[];
extern const char dbg_l2_str[];
extern const char dbg_sw_str[];
extern const char dbg_ja_str[];
extern const char dbg_j2_str[];
extern const char dbg_oa_str[];
extern const char dbg_over_write_str[];
extern const char dbg_insert_str[];
extern const char dbg_addition_str[];
extern const char dbg_parts1_str[];
extern const char dbg_blank8_str[];
extern const char dbg_nothing_str[];
extern const char dbg_parts2_str[];
extern const char dbg_parts3_str[];
extern const char dbg_parts4_str[];
extern const char dbg_no_extdat_str[];
extern const char dbg_eftype_str[];
extern const char debug_blank6_msg[];
extern const char dbg_waza_k_str[];
extern const char dbg_waza_p_str[];
extern const char dbg_digit0_str[];
extern const char dbg_digit1_str[];
extern const char dbg_digit2_str[];
extern const char dbg_wca_str[];
extern const u16 bcp_group_top_tbl[];
extern const u16 dbg_obj_color_tbl[];
extern const u32 dbg_char_color_tbl[];
extern const u8 dbg_stage_area_tbl[][2];
extern const u16 dbg_cg_group_top_tbl[];
extern const u16 dbg_col_code_tbl[];
extern const s16 dbg_col_no_tbl[];
extern const u8 dbg_bg_select_tbl[][2];
extern const char str_OBJECT_TEST[];
extern const char str_BG_SELECT[];
extern const char str_OBJECT_LOOK[];
extern const char str_OBJECT_EDIT[];
extern const char str_OBJECT_EDIT_2[];
extern const char str_HIT[];
extern const char str_ALL_CHARACTER[];
extern const char str_PARTS[];
extern const char str_SELECT_UP_DOWN[];
extern const char str_EXIT_1P_2P_START[];
extern const char str_PLAYER[];
extern const char str_ALL[];
extern const char str_MOTION[];
extern const char str_PATTERN[];
extern const char str_INTERRUT[];
extern const char str_CODE_H[];
extern const char str_FLIP[];
extern const char str_FLIP_ED[];
extern const char str_POS_X_H[];
extern const char str_POS_Y_H[];
extern const char str_REL_X_H[];
extern const char str_REL_Y_H[];
extern const char str_CURRENT[];
extern const char str_H_n[];
extern const char str_GROUP[];
extern const char str_R_n[];
extern const char str_G[];
extern const char str_B[];
extern const char str_EDIT_NUM[];
extern const char str_NUM_END[];
extern const char str_EDIT_INT[];
extern const char str_INT_END[];
extern const char str_CURRENT_n[];
extern const char str_PARTS_X_H[];
extern const char str_PARTS_Y_H[];
extern const char str_PARTS_FL[];
extern const char str_OLC_IX[];
extern const char str_IX_1[];
extern const char str_IX_2[];
extern const char str_IX_3[];
extern const char str_IX_4[];
extern const char str_DELETE_ALL_SH4[];
extern const char str_1DATA_SH5[];
extern const char str_CANCEL_SH6[];
extern const char str_blank_line[];
extern const char str_empty[];
extern const char str_NO_EDIT[];
extern const char str_DATA_NOTHING[];
extern const char str_REVISE_X_H[];
extern const char str_SIZE_X_H[];
extern const char str_REVISE_Y_H[];
extern const char str_SIZE_Y_H[];
extern const char str_IX[];
extern const char str_CUR[];
extern const char str_BOD[];
extern const char str_HAN[];
extern const char str_CAT[];
extern const char str_CAU[];
extern const char str_AT1[];
extern const char str_AT2[];
extern const char str_HOS[];
extern const char str_KOC_IX_PT_Nix_n[];
extern const char str_KOC_IX_PT_Nix[];
extern const char str_HEAD[];
extern const char str_BREAST[];
extern const char str_TRUNK_1[];
extern const char str_LEG[];
extern const char str_HAND_1[];
extern const char str_HAND_2[];
extern const char str_CATCH_n[];
extern const char str_CAUGHT_n[];
extern const char str_ATTACK_1[];
extern const char str_ATTACK_2[];
extern const char str_ATTACK_3[];
extern const char str_ATTACK_4[];
extern const char str_TRUNK_2[];
extern const char str_CG_CTR[];
extern const char str_CG_TYPE[];
extern const char str_CG_SE[];
extern const char str_CG_FLIP[];
extern const char str_CG_OLC_IX[];
extern const char str_CG_NUMBER[];
extern const char str_CG_ATT_IX[];
extern const char str_CG_HIT_IX[];
extern const char str_CG_EXTDAT[];
extern const char str_CG_CANCEL[];
extern const char str_CG_EFFECT[];
extern const char str_CG_EFTYPE[];
extern const char str_CG_RIVAL[];
extern const char str_CG_ADD_XY[];
extern const char str_CG_NIX[];
extern const char str_CG_STATUS[];
extern const char str_CGD_TYPE[];
extern const char str_PAT_ST[];
extern const char str_KIND_WAZA[];
extern const char str_HIT_RANGE[];
extern const char str_YOKE_TYPE[];
extern const char str_YOKE_PAT[];
extern const char str_SP_TECH[];
extern const char str_WCA_IX[];
extern const char str_ATT_IX[];
extern const char str_REACTION[];
extern const char str_MKH_IX[];
extern const char str_DIP[];
extern const char str_HISS[];
extern const char str_DIR[];
extern const char str_GUARD[];
extern const char str_POW[];
extern const char str_IMPACT[];
extern const char str_PIYO_n[];
extern const char str_NG_TYPE[];
extern const char str_HS_ME[];
extern const char str_HS_YOU[];
extern const char str_ZU_FLAG[];
extern const char str_ZOKUSEI[];
extern const char str_AT_LEVEL[];
extern const char str_ADD_ARTS[];
extern const char str_BUTT_TYPE[];
extern const char str_BUTT_PAT[];
extern const char str_DIR_ATT[];
extern const char str_VS_ID[];
extern const char str_blank_line_3[];
extern const char str_empty_3[];
extern const char str_blank_line_4[];
extern const char str_empty_4[];
extern const char str_CMOA[];
extern const char str_CMSW[];
extern const char str_CMLP[];
extern const char str_CML2[];
extern const char str_CMJA[];
extern const char str_CMJ2[];
extern const char str_CMJ3[];
extern const char str_CMJ4[];
extern const char str_CMMS[];
extern const char str_CMMD[];
extern const char str_CMYD[];
extern const char str_CMCF[];
extern const char str_CMCR[];
extern const char str_WCA[];
extern const char str_CGD1[];
extern const char str_CGD2[];
extern const char str_CGD3[];
extern const char str_empty_5[];
extern const char str_sl_00[];
extern const char str_sl_10[];
extern const char str_sl_12[];
extern const char str_sl_20[];
extern const char str_sl_22[];
extern const char str_sl_30[];
extern const char str_sl_32[];
extern const char str_sl_40[];
extern const char str_sl_42[];
extern const char str_sl_44[];
extern const char str_sl_50[];
extern const char str_sl_52[];
extern const char str_sl_54[];
extern const char str_sl_60[];
extern const char str_sl_62[];
extern const char str_sl_64[];
extern const char str_sl_70[];
extern const char str_sl_80[];
extern const char str_sl_82[];
extern const char str_sl_90[];
extern const char str_empty_6[];
extern const char str_BCP00[];
extern const char str_BCP01[];
extern const char str_BCP02[];
extern const char str_BCP03[];
extern const char str_BCP04[];
extern const char str_BCP05[];
extern const char str_BCP06[];
extern const char str_BCP07[];
extern const char str_BCP08[];
extern const char str_BCP09[];
extern const char str_BCP10[];
extern const char str_BCP11[];
extern const char str_BCP12[];
extern const char str_BCP13[];
extern const char str_BCP14[];
extern const char str_BCP15[];
extern const char str_BCP20[];
extern const char str_BCP21[];
extern const char str_BCP22[];
extern const char str_BCP23[];
extern const char str_BCP24[];
extern const char str_BCP25[];
extern const char str_BCP26[];
extern const char str_BCP27[];
extern const char str_BCP28[];
extern const char str_BCP29[];
extern const char str_BCP30[];
extern const char str_BCP31[];
extern const char str_BCP32[];
extern const char str_BCP33[];
extern const char str_BCP34[];
extern const char str_BCP35[];
extern const char str_BCP36[];
extern const char str_BCP37[];
extern const char str_BCP38[];
extern const char str_BCP39[];
extern const char str_BCP40[];
extern const char str_BCP41[];
extern const char str_BCP42[];
extern const char str_BCP43[];
extern const char str_BCP44[];
extern const char str_BCP45[];
extern const char str_BCP46[];
extern const char str_BCP47[];
extern const char str_BCP48[];
extern const char str_BCP49[];
extern const char str_BCP50[];
extern const char str_BCP51[];
extern const char str_BCP52[];
extern const char str_BCP53[];
extern const char str_BCP54[];
extern const char str_BCP55[];
extern const char str_BCP56[];
extern const char str_BCP57[];
extern const char str_BCP58[];
extern const char str_BCP59[];
extern const char str_BCP60[];
extern const char str_BCP61[];
extern const char str_BCP62[];
extern const char str_BCP63[];
extern const char str_BCP64[];
extern const char str_BCP65[];
extern const char str_BCP66[];
extern const char str_BCP67[];
extern const char str_BCP68[];
extern const char str_BCP69[];
extern const char str_BCP70[];
extern const char str_BCP71[];
extern const char str_BCP72[];
extern const char str_BCP73[];
extern const char str_BCP74[];
extern const char str_BCP75[];
extern const char str_BCP76[];
extern const char str_BCP77[];
extern const char str_BCP78[];
extern const char str_BCP79[];
extern const char str_BCP80[];
extern const char str_BCP81[];
extern const char str_BCP82[];
extern const char str_BCP83[];
extern const char str_BCP84[];
extern const char str_BCP85[];
extern const char str_empty_7[];
extern const char str_BCP86[];
extern const char str_BCP87[];
extern const char str_BCP88[];
extern const char str_BCP89[];
extern const char str_BCP90[];
extern const char str_BCP91[];
extern const char str_BCP92[];
extern const char str_BCP93[];
extern const char str_BCP94[];
extern const char str_BCP95[];
extern const char str_BCP96[];
extern const char str_BCP97[];
extern const char str_BCP98[];
extern const char str_BCP99[];
extern const char str_BCPA0[];
extern const char str_BCPA1[];
extern const char str_Pa[];
extern const char str_PA[];
extern const char str_PB[];
extern const char str_MLN[];
extern const char str_MLU[];
extern const char str_MLD[];
extern const char str_MLF[];
extern const char str_MLR[];
extern const char str_M[];
extern const char str_S1[];
extern const char str_S2[];
extern const char str_S3[];
extern const char str_S4[];
extern const char str_S5[];
extern const char str_S6[];
extern const char str_USEMJ[];
extern const char str_BASE[];
extern const char str_BEFORE[];
extern const char str_BACK[];
extern const char str_H[];
extern const char str_D[];
extern const char str_A[];
extern const char str_M_2[];
extern const char str_R[];
extern const char str_C[];
extern const char str_S[];
extern const char str_h[];
extern const char str_d[];
extern const char str_a[];
extern const char str_m[];
extern const char str_r[];
extern const char str_c[];
extern const char str_s[];
extern const char str_h_2[];
extern const char str_d_2[];
extern const char str_a_2[];
extern const char str_m_2[];
extern const char str_r_2[];
extern const char str_c_2[];
extern const char str_s_2[];
extern const char str_NM[];
extern const char str_DM[];
extern const char str_CA[];
extern const char str_CU[];
extern const char str_AT[];
extern const char str_BT[];
extern const char str_EX[];
extern const char str_SA[];
extern const char str_CB[];
extern const char str_empty_8[];
extern const char str_nmA[];
extern const char str_hsA[];
extern const char str_nmC[];
extern const char str_hsC[];
extern const char str_saA[];
extern const char str_saC[];
extern const char str_paA[];
extern const char str_huA[];
extern const char str_BLANK[];
extern const char str_FLASH[];
extern const char str_GILL[];
extern const char str_N_Y[];
extern const char str_JAPAN_2[];
extern const char str_CHAINA_1[];
extern const char str_ENGLAND[];
extern const char str_RUSSIA[];
extern const char str_GERMANY[];
extern const char str_FURUDERA[];
extern const char str_AFRICA_1[];
extern const char str_AFRICA_2[];
extern const char str_BRAZIL[];
extern const char str_CHAINA_2[];
extern const char str_SAN_FRANCISCO[];
extern const char str_SAO_PAULO[];
extern const char str_URIEN[];
extern const char str_KEIKOKU[];
extern const char str_GILL_2[];
extern const char str_ALEX[];
extern const char str_RYU[];
extern const char str_YUN[];
extern const char str_DUDLEY[];
extern const char str_NECRO[];
extern const char str_HUGO[];
extern const char str_IBUKI[];
extern const char str_ELENA[];
extern const char str_ORO[];
extern const char str_YANG[];
extern const char str_KEN[];
extern const char str_SEAN[];
extern const char str_URIEN_2[];
extern const char str_GOUKI1[];
extern const char str_GOUKI2[];
extern const char str_ETC_4[];
extern const char str_NORMAL[];
extern const char str_DAMAGE[];
extern const char str_CATCH[];
extern const char str_CAUGHT[];
extern const char str_ATTACK[];
extern const char str_SP_AT[];
extern const char str_BUTTOBI[];
extern const char str_UNION[];
extern const char str_ETC[];
extern const char str_EFFECT[];
extern const char str_empty_9[];
extern const char str_KAMAE[];
extern const char str_HURIMUKI[];
extern const char str_FRONT_WALK[];
extern const char str_BACK_WALK[];
extern const char str_DASH_HUMIKOMI[];
extern const char str_DASH_TOBINOKI[];
extern const char str_KAGAMU[];
extern const char str_KAGAMI_KAMAE[];
extern const char str_KAGAMI_TURN[];
extern const char str_KAGAMI_F_WALK[];
extern const char str_KAGAMI_B_WALK[];
extern const char str_STAND_UP[];
extern const char str_JUMP_JUNBI[];
extern const char str_SP_JUMP_JUNBI[];
extern const char str_JUMP_FRONT[];
extern const char str_JUMP_VERTICAL[];
extern const char str_JUMP_BACK[];
extern const char str_S_JUMP_FRONT[];
extern const char str_S_JUMP_V[];
extern const char str_S_JUMP_BACK[];
extern const char str_SP_JUMP_FRONT[];
extern const char str_SP_JUMP_V[];
extern const char str_SP_JUMP_BACK[];
extern const char str_WALK_END[];
extern const char str_PARING_HEAD[];
extern const char str_PARING_UP[];
extern const char str_PARING_DOWN[];
extern const char str_PARING_AIR_F[];
extern const char str_PARING_AIR_B[];
extern const char str_GUARD_HEAD[];
extern const char str_GUARD_UP[];
extern const char str_GUARD_DOWN[];
extern const char str_GUARD_AIR[];
extern const char str_empty_10[];
extern const char str_P_BREAK_ZUJOU[];
extern const char str_P_BREAK_UP[];
extern const char str_P_BREAK_DOWN[];
extern const char str_P_BREAK_AIR_F[];
extern const char str_P_BREAK_AIR_R[];
extern const char str_TUKAMIHAZUSI[];
extern const char str_TUKAMIHAZUSARE[];
extern const char str_GUARD_HEAD_2[];
extern const char str_GUARD_UP_2[];
extern const char str_GUARD_DOWN_2[];
extern const char str_GUARD_AIR_2[];
extern const char str_HUSHIN_HEAD[];
extern const char str_HUSHIN_UP[];
extern const char str_HUSHIN_DOWN[];
extern const char str_HUSHIN_AIR[];
extern const char str_FACE_S[];
extern const char str_FACE_M[];
extern const char str_FACE_L[];
extern const char str_FACE_SP[];
extern const char str_FOOK_OKU_S[];
extern const char str_FOOK_OKU_M[];
extern const char str_FOOK_OKU_L[];
extern const char str_FOOK_OKU_SP[];
extern const char str_FOOK_TEMAE_S[];
extern const char str_FOOK_TEMAE_M[];
extern const char str_FOOK_TEMAE_L[];
extern const char str_FOOK_TEMAE_SP[];
extern const char str_UPPER_S[];
extern const char str_UPPER_M[];
extern const char str_UPPER_L[];
extern const char str_UPPER_SP[];
extern const char str_NOUTEN_S[];
extern const char str_NOUTEN_M[];
extern const char str_NOUTEN_L[];
extern const char str_NOUTEN_SP[];
extern const char str_BODY_BROW_S[];
extern const char str_BODY_BROW_M[];
extern const char str_BODY_BROW_L[];
extern const char str_BODY_BROW_SP[];
extern const char str_BODY_UPPER_S[];
extern const char str_BODY_UPPER_M[];
extern const char str_BODY_UPPER_L[];
extern const char str_BODY_UPPER_SP[];
extern const char str_TATAKI_S[];
extern const char str_TATAKI_M[];
extern const char str_TATAKI_L[];
extern const char str_TATAKI_SP[];
extern const char str_TATAKI_V_S[];
extern const char str_TATAKI_V_M[];
extern const char str_TATAKI_V_L[];
extern const char str_TATAKI_V_SP[];
extern const char str_NOBASITA_TE_S[];
extern const char str_NOBASITA_TE_M[];
extern const char str_NOBASITA_TE_L[];
extern const char str_NOBASITA_TE_SP[];
extern const char str_KAGAMI_S[];
extern const char str_KAGAMI_M[];
extern const char str_KAGAMI_L[];
extern const char str_KAGAMI_SP[];
extern const char str_KGM_TATAKI_S[];
extern const char str_KGM_TATAKI_M[];
extern const char str_KGM_TATAKI_L[];
extern const char str_KGM_TATAKI_SP[];
extern const char str_KGM_TTKI_V_S[];
extern const char str_KGM_TTKI_V_M[];
extern const char str_KGM_TTKI_V_L[];
extern const char str_KGM_TTKI_V_SP[];
extern const char str_NEKOROBI_S[];
extern const char str_NEKOROBI_M[];
extern const char str_NEKOROBI_L[];
extern const char str_NEKOROBI_SP[];
extern const char str_OKIAGARI[];
extern const char str_OKIAGARI_F[];
extern const char str_OKIAGARI_B[];
extern const char str_LOSE_NO_STAND[];
extern const char str_LOSE_SONABA[];
extern const char str_LOSE_KAGAMI[];
extern const char str_PIYO[];
extern const char str_UKEMI_MOVE_F[];
extern const char str_UKEMI_MOVE_R[];
extern const char str_SHIMEOTASARE[];
extern const char str_TATI_TOUKETU_S[];
extern const char str_TATI_TOUKETU_M[];
extern const char str_TATI_TOUKETU_L[];
extern const char str_TATI_TOUKETU_P[];
extern const char str_KGM_TOUKETU_S[];
extern const char str_KGM_TOUKETU_M[];
extern const char str_KGM_TOUKETU_L[];
extern const char str_KGM_TOUKETU_P[];
extern const char str_TATI_DENGEKI_S[];
extern const char str_TATI_DENGEKI_M[];
extern const char str_TATI_DENGEKI_L[];
extern const char str_TATI_DENGEKI_P[];
extern const char str_KGM_DENGEKI_S[];
extern const char str_KGM_DENGEKI_M[];
extern const char str_KGM_DENGEKI_L[];
extern const char str_KGM_DENGEKI_P[];
extern const char str_OKIAGARI_FRONT[];
extern const char str_OKIAGARI_REAR[];
extern const char str_TATI_MOE_S[];
extern const char str_TATI_MOE_M[];
extern const char str_TATI_MOE_L[];
extern const char str_TATI_MOE_SP[];
extern const char str_AIR_S[];
extern const char str_AIR_M[];
extern const char str_AIR_L[];
extern const char str_AIR_SP[];
extern const char str_ASHIBARAI_A[];
extern const char str_ASHIBARAI_B[];
extern const char str_ASHIBARAI_C[];
extern const char str_ASHIBARAI_D[];
extern const char str_TUNNOMERI_A[];
extern const char str_TUNNOMERI_B[];
extern const char str_TUNNOMERI_C[];
extern const char str_TUNNOMERI_D[];
extern const char str_NOKEZORI_A[];
extern const char str_NOKEZORI_B[];
extern const char str_NOKEZORI_C[];
extern const char str_NOKEZORI_D[];
extern const char str_KUNOJI_A[];
extern const char str_KUNOJI_B[];
extern const char str_KUNOJI_C[];
extern const char str_KUNOJI_D[];
extern const char str_KIRIMOMI_A[];
extern const char str_KIRIMOMI_B[];
extern const char str_KIRIMOMI_C[];
extern const char str_KIRIMOMI_D[];
extern const char str_UPPER_A[];
extern const char str_UPPER_B[];
extern const char str_UPPER_C[];
extern const char str_UPPER_D[];
extern const char str_BODY_UPPER_A[];
extern const char str_BODY_UPPER_B[];
extern const char str_BODY_UPPER_C[];
extern const char str_BODY_UPPER_D[];
extern const char str_NM_BUTTOBI_A[];
extern const char str_NM_BUTTOBI_B[];
extern const char str_NM_BUTTOBI_C[];
extern const char str_NM_BUTTOBI_D[];
extern const char str_TATAKI_AIR_A[];
extern const char str_TATAKI_AIR_B[];
extern const char str_TATAKI_AIR_C[];
extern const char str_TATAKI_AIR_D[];
extern const char str_TTKI_V_AIR_A[];
extern const char str_TTKI_V_AIR_B[];
extern const char str_TTKI_V_AIR_C[];
extern const char str_TTKI_V_AIR_D[];
extern const char str_HUMI_ASIB_A[];
extern const char str_HUMI_ASIB_B[];
extern const char str_HUMI_ASIB_C[];
extern const char str_HUMI_ASIB_D[];
extern const char str_FACE_A[];
extern const char str_FACE_B[];
extern const char str_FACE_C[];
extern const char str_FACE_D[];
extern const char str_ASIBRI_MAKE_A[];
extern const char str_ASIBRI_MAKE_B[];
extern const char str_ASIBRI_MAKE_C[];
extern const char str_ASIBRI_MAKE_D[];
extern const char str_ASIB_TN_MAKE_A[];
extern const char str_ASIB_TN_MAKE_B[];
extern const char str_ASIB_TN_MAKE_C[];
extern const char str_ASIB_TN_MAKE_D[];
extern const char str_DENKI_A[];
extern const char str_DENKI_B[];
extern const char str_DENKI_C[];
extern const char str_DENKI_D[];
extern const char str_KUNOJI_NOKE_A[];
extern const char str_KUNOJI_NOKE_B[];
extern const char str_KUNOJI_NOKE_C[];
extern const char str_KUNOJI_NOKE_D[];
extern const char str_SINSYOURYU_A[];
extern const char str_SINSYOURYU_B[];
extern const char str_SINSYOURYU_C[];
extern const char str_SINSYOURYU_D[];
extern const char str_HANEAGARI_A[];
extern const char str_HANEAGARI_B[];
extern const char str_HANEAGARI_C[];
extern const char str_HANEAGARI_D[];
extern const char str_TOUKETSU_A[];
extern const char str_TOUKETSU_B[];
extern const char str_TOUKETSU_C[];
extern const char str_TOUKETSU_D[];
extern const char str_BODY_SLAM_A[];
extern const char str_BODY_SLAM_B[];
extern const char str_BODY_SLAM_C[];
extern const char str_BODY_SLAM_D[];
extern const char str_IPPONZEOI_A[];
extern const char str_IPPONZEOI_B[];
extern const char str_IPPONZEOI_C[];
extern const char str_IPPONZEOI_D[];
extern const char str_TOMOE_RYU_A[];
extern const char str_TOMOE_RYU_B[];
extern const char str_TOMOE_RYU_C[];
extern const char str_TOMOE_RYU_D[];
extern const char str_MONKEY_FLIP_A[];
extern const char str_MONKEY_FLIP_B[];
extern const char str_MONKEY_FLIP_C[];
extern const char str_MONKEY_FLIP_D[];
extern const char str_TOMOE_ORO_A[];
extern const char str_TOMOE_ORO_B[];
extern const char str_TOMOE_ORO_C[];
extern const char str_TOMOE_ORO_D[];
extern const char str_SNAKE_FANG_A[];
extern const char str_SNAKE_FANG_B[];
extern const char str_SNAKE_FANG_C[];
extern const char str_SNAKE_FANG_D[];
extern const char str_FLANKEN_S_A[];
extern const char str_FLANKEN_S_B[];
extern const char str_FLANKEN_S_C[];
extern const char str_FLANKEN_S_D[];
extern const char str_KISHINRIKI_A[];
extern const char str_KISHINRIKI_B[];
extern const char str_KISHINRIKI_C[];
extern const char str_KISHINRIKI_D[];
extern const char str_SPLASH_M_A[];
extern const char str_SPLASH_M_B[];
extern const char str_SPLASH_M_C[];
extern const char str_SPLASH_M_D[];
extern const char str_HARAIGOSHI_A[];
extern const char str_HARAIGOSHI_B[];
extern const char str_HARAIGOSHI_C[];
extern const char str_HARAIGOSHI_D[];
extern const char str_ALEX_B_D_A[];
extern const char str_ALEX_B_D_B[];
extern const char str_ALEX_B_D_C[];
extern const char str_ALEX_B_D_D[];
extern const char str_GILL_A[];
extern const char str_GILL_B[];
extern const char str_GILL_C[];
extern const char str_GILL_D[];
extern const char str_CATCH_1[];
extern const char str_CATCH_2[];
extern const char str_CATCH_3[];
extern const char str_CATCH_4[];
extern const char str_CATCH_5[];
extern const char str_CATCH_6[];
extern const char str_CATCH_7[];
extern const char str_CATCH_8[];
extern const char str_CATCH_9[];
extern const char str_CATCH_10[];
extern const char str_CATCH_11[];
extern const char str_CATCH_12[];
extern const char str_CATCH_13[];
extern const char str_CATCH_14[];
extern const char str_CATCH_15[];
extern const char str_CATCH_16[];
extern const char str_CATCH_17[];
extern const char str_CATCH_18[];
extern const char str_CATCH_19[];
extern const char str_CATCH_20[];
extern const char str_CATCH_21[];
extern const char str_CATCH_22[];
extern const char str_CATCH_23[];
extern const char str_CATCH_24[];
extern const char str_CATCH_25[];
extern const char str_CATCH_26[];
extern const char str_CATCH_27[];
extern const char str_CATCH_28[];
extern const char str_CATCH_29[];
extern const char str_CATCH_30[];
extern const char str_CATCH_31[];
extern const char str_CATCH_32[];
extern const char str_CATCH_33[];
extern const char str_CATCH_34[];
extern const char str_CATCH_35[];
extern const char str_CATCH_36[];
extern const char str_CATCH_37[];
extern const char str_CATCH_38[];
extern const char str_CATCH_39[];
extern const char str_CATCH_40[];
extern const char str_ALEX_ZUTUKI[];
extern const char str_ALEX_BODY_S[];
extern const char str_ALEX_BACK_D[];
extern const char str_ALEX_POWER_B[];
extern const char str_ALEX_SLEEPER[];
extern const char str_RYU_SEOINAGE[];
extern const char str_IBUKI_2[];
extern const char str_DADLEY_L_B[];
extern const char str_IBUKI_KUBIORI[];
extern const char str_NECRO_S_T[];
extern const char str_RYU_TOMOENAGE[];
extern const char str_YUN_HIZAGERI[];
extern const char str_ORO_KUBISIME[];
extern const char str_NECRO_G_S[];
extern const char str_DUDDLEY_D_S[];
extern const char str_YUN_MONKEY_F[];
extern const char str_ORO_TOMOENAGE[];
extern const char str_ORO_NIOURIKI[];
extern const char str_ORO_GIGOKU_G[];
extern const char str_YUN_2[];
extern const char str_NECRO_SNAKE_F[];
extern const char str_NECRO_F_S[];
extern const char str_IBUKI_HARAIG[];
extern const char str_GILL_SPLASH_M[];
extern const char str_KEN_HIZAGERI[];
extern const char str_ORO_KISINRIKI[];
extern const char str_SEAN_TACKLE[];
extern const char str_ALEX_HYPER_B[];
extern const char str_NECRO_SLAM_D[];
extern const char str_ELENA_ASINAGE[];
extern const char str_GILL_IMPACT_C[];
extern const char str_ALEX_S_H_B[];
extern const char str_ALEX_F_N_D[];
extern const char str_IBUKI_YOROI_D[];
extern const char str_MAWARIKOMI_M_F[];
extern const char str_HUGO_BODY_S[];
extern const char str_HUGO_N_G_T[];
extern const char str_HUGO_M_S_P[];
extern const char str_HUGO_S_D_B_B[];
extern const char str_S_PUNCH_A[];
extern const char str_S_PUNCH_B[];
extern const char str_S_PUNCH_C[];
extern const char str_M_PUNCH_A[];
extern const char str_M_PUNCH_B[];
extern const char str_M_PUNCH_C[];
extern const char str_L_PUNCH_A[];
extern const char str_L_PUNCH_B[];
extern const char str_L_PUNCH_C[];
extern const char str_S_KICK_A[];
extern const char str_S_KICK_B[];
extern const char str_S_KICK_C[];
extern const char str_M_KICK_A[];
extern const char str_M_KICK_B[];
extern const char str_M_KICK_C[];
extern const char str_L_KICK_A[];
extern const char str_L_KICK_B[];
extern const char str_L_KICK_C[];
extern const char str_KAGAMI_P_A[];
extern const char str_KAGAMI_P_B[];
extern const char str_KAGAMI_P_C[];
extern const char str_KAGAMI_K_A[];
extern const char str_KAGAMI_K_B[];
extern const char str_KAGAMI_K_C[];
extern const char str_V_JUMP_P_S_A[];
extern const char str_V_JUMP_P_S_B[];
extern const char str_V_JUMP_P_M_A[];
extern const char str_V_JUMP_P_M_B[];
extern const char str_V_JUMP_P_L_A[];
extern const char str_V_JUMP_P_L_B[];
extern const char str_V_JUMP_K_S_A[];
extern const char str_V_JUMP_K_S_B[];
extern const char str_V_JUMP_K_M_A[];
extern const char str_V_JUMP_K_M_B[];
extern const char str_V_JUMP_K_L_A[];
extern const char str_V_JUMP_K_L_B[];
extern const char str_F_JUMP_P_S_A[];
extern const char str_F_JUMP_P_S_B[];
extern const char str_F_JUMP_P_M_A[];
extern const char str_F_JUMP_P_M_B[];
extern const char str_F_JUMP_P_L_A[];
extern const char str_F_JUMP_P_L_B[];
extern const char str_F_JUMP_K_S_A[];
extern const char str_F_JUMP_K_S_B[];
extern const char str_F_JUMP_K_M_A[];
extern const char str_F_JUMP_K_M_B[];
extern const char str_F_JUMP_K_L_A[];
extern const char str_F_JUMP_K_L_B[];
extern const char str_B_JUMP_P_S_A[];
extern const char str_B_JUMP_P_S_B[];
extern const char str_B_JUMP_P_M_A[];
extern const char str_B_JUMP_P_M_B[];
extern const char str_B_JUMP_P_L_A[];
extern const char str_B_JUMP_P_L_B[];
extern const char str_B_JUMP_K_S_A[];
extern const char str_B_JUMP_K_S_B[];
extern const char str_B_JUMP_K_M_A[];
extern const char str_B_JUMP_K_M_B[];
extern const char str_B_JUMP_K_L_A[];
extern const char str_B_JUMP_K_L_B[];
extern const char str_SP_V_JP_S_P_A[];
extern const char str_SP_V_JP_S_P_B[];
extern const char str_SP_V_JP_M_P_A[];
extern const char str_SP_V_JP_M_P_B[];
extern const char str_SP_V_JP_L_P_A[];
extern const char str_SP_V_JP_L_P_B[];
extern const char str_SP_V_JP_S_K_A[];
extern const char str_SP_V_JP_S_K_B[];
extern const char str_SP_V_JP_M_K_A[];
extern const char str_SP_V_JP_M_K_B[];
extern const char str_SP_V_JP_L_K_A[];
extern const char str_SP_V_JP_L_K_B[];
extern const char str_SP_F_JP_S_P_A[];
extern const char str_SP_F_JP_S_P_B[];
extern const char str_SP_F_JP_M_P_A[];
extern const char str_SP_F_JP_M_P_B[];
extern const char str_SP_F_JP_L_P_A[];
extern const char str_SP_F_JP_L_P_B[];
extern const char str_SP_F_JP_S_K_A[];
extern const char str_SP_F_JP_S_K_B[];
extern const char str_SP_F_JP_M_K_A[];
extern const char str_SP_F_JP_M_K_B[];
extern const char str_SP_F_JP_L_K_A[];
extern const char str_SP_F_JP_L_K_B[];
extern const char str_SP_B_JP_S_P_A[];
extern const char str_SP_B_JP_S_P_B[];
extern const char str_SP_B_JP_M_P_A[];
extern const char str_SP_B_JP_M_P_B[];
extern const char str_SP_B_JP_L_P_A[];
extern const char str_SP_B_JP_L_P_B[];
extern const char str_SP_B_JP_S_K_A[];
extern const char str_SP_B_JP_S_K_B[];
extern const char str_SP_B_JP_M_K_A[];
extern const char str_SP_B_JP_M_K_B[];
extern const char str_SP_B_JP_L_K_A[];
extern const char str_SP_B_JP_L_K_B[];
extern const char str_S_V_JP_S_P_A[];
extern const char str_S_V_JP_S_P_B[];
extern const char str_S_V_JP_M_P_A[];
extern const char str_S_V_JP_M_P_B[];
extern const char str_S_V_JP_L_P_A[];
extern const char str_S_V_JP_L_P_B[];
extern const char str_S_V_JP_S_K_A[];
extern const char str_S_V_JP_S_K_B[];
extern const char str_S_V_JP_M_K_A[];
extern const char str_S_V_JP_M_K_B[];
extern const char str_S_V_JP_L_K_A[];
extern const char str_S_V_JP_L_K_B[];
extern const char str_S_F_JP_S_P_A[];
extern const char str_S_F_JP_S_P_B[];
extern const char str_S_F_JP_M_P_A[];
extern const char str_S_F_JP_M_P_B[];
extern const char str_S_F_JP_L_P_A[];
extern const char str_S_F_JP_L_P_B[];
extern const char str_S_F_JP_S_K_A[];
extern const char str_S_F_JP_S_K_B[];
extern const char str_S_F_JP_M_K_A[];
extern const char str_S_F_JP_M_K_B[];
extern const char str_S_F_JP_L_K_A[];
extern const char str_S_F_JP_L_K_B[];
extern const char str_S_B_JP_S_P_A[];
extern const char str_S_B_JP_S_P_B[];
extern const char str_S_B_JP_M_P_A[];
extern const char str_S_B_JP_M_P_B[];
extern const char str_S_B_JP_L_P_A[];
extern const char str_S_B_JP_L_P_B[];
extern const char str_S_B_JP_S_K_A[];
extern const char str_S_B_JP_S_K_B[];
extern const char str_S_B_JP_M_K_A[];
extern const char str_S_B_JP_M_K_B[];
extern const char str_S_B_JP_L_K_A[];
extern const char str_S_B_JP_L_K_B[];
extern const char str_TUKAMIKAKARI_A[];
extern const char str_TUKAMIKAKARI_B[];
extern const char str_TUKAMIKAKARI_C[];
extern const char str_TUKAMIKAKARI_D[];
extern const char str_TUKAMIKAKARI_E[];
extern const char str_TUKAMIKAKARI_F[];
extern const char str_TUKAMI_AIR_A[];
extern const char str_TUKAMI_AIR_B[];
extern const char str_TUKAMI_AIR_C[];
extern const char str_TUKAMI_AIR_D[];
extern const char str_TUKAMI_AIR_E[];
extern const char str_TUKAMI_AIR_F[];
extern const char str_UP_P_GUARD_P_S[];
extern const char str_UP_P_GUARD_P_M[];
extern const char str_UP_P_GUARD_P_L[];
extern const char str_UP_P_GUARD_K_S[];
extern const char str_UP_P_GUARD_K_M[];
extern const char str_UP_P_GUARD_K_L[];
extern const char str_D_P_GUARD_P_S[];
extern const char str_D_P_GUARD_P_M[];
extern const char str_D_P_GUARD_P_L[];
extern const char str_D_P_GUARD_K_S[];
extern const char str_D_P_GUARD_K_M[];
extern const char str_D_P_GUARD_K_L[];
extern const char str_FUSHIN_P_S[];
extern const char str_FUSHIN_P_M[];
extern const char str_FUSHIN_P_L[];
extern const char str_FUSHIN_K_S[];
extern const char str_FUSHIN_K_M[];
extern const char str_FUSHIN_K_L[];
extern const char str_OKIAGARI_P_S[];
extern const char str_OKIAGARI_P_M[];
extern const char str_OKIAGARI_P_L[];
extern const char str_OKIAGARI_K_S[];
extern const char str_OKIAGARI_K_M[];
extern const char str_OKIAGARI_K_L[];
extern const char str_ATTACK_1_S[];
extern const char str_ATTACK_1_M[];
extern const char str_ATTACK_1_L[];
extern const char str_ATTACK_1_SP[];
extern const char str_ATTACK_2_S[];
extern const char str_ATTACK_2_M[];
extern const char str_ATTACK_2_L[];
extern const char str_ATTACK_2_SP[];
extern const char str_ATTACK_3_S[];
extern const char str_ATTACK_3_M[];
extern const char str_ATTACK_3_L[];
extern const char str_ATTACK_3_SP[];
extern const char str_ATTACK_4_S[];
extern const char str_ATTACK_4_M[];
extern const char str_ATTACK_4_L[];
extern const char str_ATTACK_4_SP[];
extern const char str_ATTACK_5_S[];
extern const char str_ATTACK_5_M[];
extern const char str_ATTACK_5_L[];
extern const char str_ATTACK_5_SP[];
extern const char str_ATTACK_6_S[];
extern const char str_ATTACK_6_M[];
extern const char str_ATTACK_6_L[];
extern const char str_ATTACK_6_SP[];
extern const char str_ATTACK_7_S[];
extern const char str_ATTACK_7_M[];
extern const char str_ATTACK_7_L[];
extern const char str_ATTACK_7_SP[];
extern const char str_ATTACK_8_S[];
extern const char str_ATTACK_8_M[];
extern const char str_ATTACK_8_L[];
extern const char str_ATTACK_8_SP[];
extern const char str_ATTACK_9_S[];
extern const char str_ATTACK_9_M[];
extern const char str_ATTACK_9_L[];
extern const char str_ATTACK_9_SP[];
extern const char str_ATTACK_10_S[];
extern const char str_ATTACK_10_M[];
extern const char str_ATTACK_10_L[];
extern const char str_ATTACK_10_SP[];
extern const char str_ATTACK_11_S[];
extern const char str_ATTACK_11_M[];
extern const char str_ATTACK_11_L[];
extern const char str_ATTACK_11_SP[];
extern const char str_ATTACK_12_S[];
extern const char str_ATTACK_12_M[];
extern const char str_ATTACK_12_L[];
extern const char str_ATTACK_12_SP[];
extern const char str_ATTACK_13_S[];
extern const char str_ATTACK_13_M[];
extern const char str_ATTACK_13_L[];
extern const char str_ATTACK_13_SP[];
extern const char str_HANASARE[];
extern const char str_EFF01_CHAR[];
extern const char str_EFF13_CHAR[];
extern const char str_GILL_STAGE_OBJ[];
extern const char str_N_Y_1_OBJ[];
extern const char str_ONSEN_OBJ[];
extern const char str_CHAINA_1_OBJ[];
extern const char str_CHAINA_2_OBJ[];
extern const char str_ENGLAND_OBJ[];
extern const char str_ROCIA_OBJ[];
extern const char str_GERMANY_OBJ[];
extern const char str_FURUDERA_OBJ[];
extern const char str_AFRICA_1_OBJ[];
extern const char str_AFRICA_2_OBJ[];
extern const char str_BRAZIL_OBJ[];
extern const char str_SAN_FRANCISCO_2[];
extern const char str_SANPAURO[];
extern const char str_ETC_1[];
extern const char str_ETC_2[];
extern const char str_ETC_3[];
extern const char str_PLEF[];
extern const char str_ENDING_CHAR[];
extern const char str_APPEAR_JUNBI_1[];
extern const char str_APPEAR_JUNBI_2[];
extern const char str_APPEAR_JUNBI_3[];
extern const char str_APPEAR_JUNBI_4[];
extern const char str_APPEAR_JUNBI_5[];
extern const char str_APPEAR_JUNBI_6[];
extern const char str_APPEAR_JUNBI_7[];
extern const char str_APPEAR_JUNBI_8[];
extern const char str_APPEAR_1[];
extern const char str_APPEAR_2[];
extern const char str_APPEAR_3[];
extern const char str_APPEAR_4[];
extern const char str_APPEAR_5[];
extern const char str_APPEAR_6[];
extern const char str_APPEAR_7[];
extern const char str_APPEAR_8[];
extern const char str_SP_APPEAR_1[];
extern const char str_SP_APPEAR_2[];
extern const char str_SP_APPEAR_3[];
extern const char str_SP_APPEAR_4[];
extern const char str_SP_APPEAR_5[];
extern const char str_SP_APPEAR_6[];
extern const char str_SP_APPEAR_7[];
extern const char str_SP_APPEAR_8[];
extern const char str_ZANNEN_1[];
extern const char str_ZANNEN_2[];
extern const char str_ZANNEN_3[];
extern const char str_ZANNEN_4[];
extern const char str_ZANNEN_5[];
extern const char str_ZANNEN_6[];
extern const char str_ZANNEN_7[];
extern const char str_ZANNEN_8[];
extern const char str_WIN_1[];
extern const char str_WIN_2[];
extern const char str_WIN_3[];
extern const char str_WIN_4[];
extern const char str_WIN_5[];
extern const char str_WIN_6[];
extern const char str_WIN_7[];
extern const char str_WIN_8[];
extern const char str_SP_WIN_1[];
extern const char str_SP_WIN_2[];
extern const char str_SP_WIN_3[];
extern const char str_SP_WIN_4[];
extern const char str_SP_WIN_5[];
extern const char str_SP_WIN_6[];
extern const char str_SP_WIN_7[];
extern const char str_SP_WIN_8[];
extern const char str_JUDGMENT_WAIT[];
extern const char str_JUDGMENT_WIN[];
extern const char str_JUDGMENT_LOSE[];
extern const char str_WAIT[];
extern const char str_AFRICA_JUMP[];
extern const char str_AFRICA_LAND[];
extern const char str_SEAN_BALL_HIT[];
extern const char str_BONUS_WIN_1[];
extern const char str_BONUS_WIN_2[];
extern const char str_BONUS_WIN_3[];
extern const u16 chk22_tbl[];

const char dbg_hex_mark_str[4] = "H\0\xFF\xFF";

const char dbg_2p_str[4] = "2P\0\xFF";

const char dbg_1p_str[4] = "1P\0\xFF";

const char dbg_hold_str[8] = "HOLD\0\xFF\xFF\xFF";

const char dbg_free_str[8] = "FREE\0\xFF\xFF\xFF";

const char dbg_copy_str[8] = "COPY\0\xFF\xFF\xFF";

const char dbg_user_str[8] = "USER  \0\xFF";

const char dbg_define_str[8] = "DEFINE\0\xFF";

const char dbg_lp_str[4] = "LP\0\xFF";

const char dbg_nix_str[4] = "Nix";

const char dbg_l2_str[4] = "L2\0\xFF";

const char dbg_sw_str[4] = "SW\0\xFF";

const char dbg_ja_str[4] = "JA\0\xFF";

const char dbg_j2_str[4] = "J2\0\xFF";

const char dbg_oa_str[4] = "OA\0\xFF";

const char dbg_over_write_str[12] = "OVER WRITE\0\xFF";

const char dbg_insert_str[12] = "INSERT    \0\xFF";

const char dbg_addition_str[12] = "ADDITION  \0\xFF";

const char dbg_parts1_str[8] = "PARTS 1";

const char dbg_blank8_str[12] = "        \0\xFF\xFF\xFF";

const char dbg_nothing_str[12] = " NOTHING\0\xFF\xFF\xFF";

const char dbg_parts2_str[8] = "PARTS 2";

const char dbg_parts3_str[8] = "PARTS 3";

const char dbg_parts4_str[8] = "PARTS 4";

const char dbg_no_extdat_str[8] = "pbao\0\xFF\xFF\xFF";

const char dbg_eftype_str[4] = "Rpd";

const char debug_blank6_msg[8] = "      \0\xFF";

const char dbg_waza_k_str[4] = "K\0\xFF\xFF";

const char dbg_waza_p_str[4] = "P\0\xFF\xFF";

const char dbg_digit0_str[4] = "0\0\xFF\xFF";

const char dbg_digit1_str[4] = "1\0\xFF\xFF";

const char dbg_digit2_str[4] = "2\0\xFF\xFF";

const char dbg_wca_str[4] = "Wca";

const u16 bcp_group_top_tbl[16] = {
    0, 0x600, 0xC00, 0x1200, 0x1800, 0x1E00, 0x2400, 0x2A00,
    0x3000, 0x3600, 0x3C00, 0x4200, 0x4800, 0x4E00, 0x5400, 0x5A00,
};

/* provisional name */
const u16 dbg_obj_color_tbl[102] = {
    1, 1, 1, 0x68, 0x66, 0x67, 0x6A, 0x6B,
    0x64, 0x65, 0x61, 0x60, 0x6D, 0x6E, 0x6F, 0x62,
    0x63, 0x6C, 0x6C, 0x6C, 0x6C, 0x6C, 0x6C, 0x6C,
    0x6C, 0x6C, 0x6C, 0x6C, 0x6C, 0x6C, 0x6C, 0,
    0, 0x7890, 1, 0x7890, 1, 0x9800, 1, 0x8E20,
    1, 0x9530, 1, 0x9060, 2, 0x79C0, 1, 0x7BA0,
    1, 0x7D40, 1, 0x8160, 1, 0x8AD0, 1, 0x8400,
    1, 0x85E0, 1, 0x9D10, 1, 0x8760, 1, 0x88B0,
    1, 0x8BC0, 1, 0x9A40, 1, 0x1200, 1, 0x9C10,
    1, 0x9C10, 1, 0xA600, 1, 0xA600, 1, 0xA600,
    1, 0xA600, 1, 0xA600, 1, 0xA600, 1, 0xA600,
    1, 0xA600, 1, 0, 1, 0xAB98, 1, 0,
    1, 0, 1, 0, 1, 0xFFFF,
};

/* provisional name */
const u32 dbg_char_color_tbl[10] = {
    0x2320000, 0x2320200, 0x2320400, 0x2320600,
    0x2320800, 0x2320A00, 0x2320C00, 0x2320E00,
    0x2321000, 0x2312200,
};

/* provisional name */
const u8 dbg_stage_area_tbl[15][2] = {
    { 0, 0 },
    { 1, 0 },
    { 1, 1 },
    { 2, 0 },
    { 2, 1 },
    { 3, 0 },
    { 3, 1 },
    { 4, 0 },
    { 4, 1 },
    { 5, 0 },
    { 6, 0 },
    { 7, 0 },
    { 8, 0 },
    { 8, 1 },
    { 9, 0 },
};

/* provisional name */
const u16 dbg_cg_group_top_tbl[97] = {
    0, 0x600, 0xC00, 0x1200, 0x1800, 0x1E00, 0x2400, 0x2A00,
    0x3000, 0x3600, 0x3C00, 0x4200, 0x4800, 0x4E00, 0x5400, 0x5A00,
    0x7800, 0x7820, 0x7800, 0x7890, 0x79C0, 0x7BA0, 0x7D40, 0x7FC0,
    0x8400, 0x85E0, 0x8760, 0x88B0, 0x8AD0, 0x8BC0, 0x8E20, 0x9060,
    0x9130, 0x9330, 0x9530, 0x9800, 0x9A40, 0x9B90, 0x9C10, 0x9D10,
    0x9D80, 0x9E00, 0x9E80, 0x9F00, 0x9F80, 0xA000, 0xA080, 0xA100,
    0xA180, 0xA200, 0xA280, 0xA300, 0xA380, 0xA400, 0xA480, 0xA500,
    0xA600, 0xA680, 0xA880, 0xA88C, 0xA8EC, 0xA94C, 0xA958, 0xA964,
    0xA970, 0xA97C, 0xA984, 0xA98C, 0xA998, 0xA9A4, 0xA9B0, 0xA9BC,
    0xA9C8, 0xAAA8, 0xAB48, 0xAB98, 0xABE8, 0xAC48, 0xAC58, 0xAC98,
    0xACD8, 0xAD18, 0xAD68, 0xADE8, 0xAE28, 0xAE68, 0xAEA8, 0xAEC8,
    0xAF28, 0xAF58, 0xB158, 0xB188, 0xB1C8, 0xB208, 0xB248, 0xB288,
    0xB2B8,
};

const u16 dbg_col_code_tbl[16] = {
    0x5C, 0x58, 0x63, 0x5A, 0x55, 0x50, 0x59, 0x58,
    0x64, 0x5F, 0x51, 0x51, 0x51, 0x57, 0x60, 0x58,
};

const s16 dbg_col_no_tbl[64] = {
    104, 105, 102, 103, 106, 107, 100, 101,
    96, 97, 109, 110, 111, 98, 99, 108,
    108, 4, 3, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 3, 3,
    3, 3, 4, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 1, 2, 2, 2,
    2, 2, 1, 1, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
};

const u8 dbg_bg_select_tbl[18][2] = {
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 1, 0 },
    { 2, 0 },
    { 3, 0 },
    { 4, 0 },
    { 5, 0 },
    { 6, 0 },
    { 7, 0 },
    { 8, 0 },
    { 8, 1 },
    { 9, 0 },
    { 0xA, 0 },
    { 0xB, 0 },
    { 0xC, 0 },
    { 0xD, 0 },
    { 0xE, 0 },
};

const char str_OBJECT_TEST[16] = "OBJECT TEST\n\0\xFF\xFF\xFF";

const char str_BG_SELECT[16] = "BG SELECT  \n\0\xFF\xFF\xFF";

const char str_OBJECT_LOOK[16] = "OBJECT LOOK\n\0\xFF\xFF\xFF";

const char str_OBJECT_EDIT[16] = "OBJECT EDIT\n\0\xFF\xFF\xFF";

const char str_OBJECT_EDIT_2[16] = "OBJECT EDIT 2\n\0\xFF";

const char str_HIT[8] = "HIT\n\0\xFF\xFF\xFF";

const char str_ALL_CHARACTER[16] = "ALL CHARACTER\n\0\xFF";

const char str_PARTS[8] = "PARTS\0\xFF\xFF";

const char str_SELECT_UP_DOWN[20] = "SELECT  UP DOWN\n\0\xFF\xFF\xFF";

const char str_EXIT_1P_2P_START[24] = "EXIT    1P & 2P START\0\xFF\xFF";

const char str_PLAYER[12] = "PLAYER  :\n\0\xFF";

const char str_ALL[16] = "ALL     :   /\n\0\xFF";

const char str_MOTION[16] = "MOTION  :   /\n\0\xFF";

const char str_PATTERN[16] = "PATTERN :   /\n\0\xFF";

const char str_INTERRUT[16] = "INTERRUT:   /\n\0\xFF";

const char str_CODE_H[20] = "CODE    :     H\n\0\xFF\xFF\xFF";

const char str_FLIP[12] = "FLIP    :\n\0\xFF";

const char str_FLIP_ED[12] = "FLIP ED :\n\0\xFF";

const char str_POS_X_H[20] = "POS X   :     H\n\0\xFF\xFF\xFF";

const char str_POS_Y_H[16] = "POS Y   :     H";

const char str_REL_X_H[20] = "REL X   :     H\n\0\xFF\xFF\xFF";

const char str_REL_Y_H[20] = "REL Y   :     H\n\0\xFF\xFF\xFF";

const char str_CURRENT[12] = "CURRENT :\0\xFF\xFF";

const char str_H_n[16] = "             H\n";

const char str_GROUP[16] = "GROUP         \n";

const char str_R_n[16] = "R             \n";

const char str_G[16] = "G             \n";

const char str_B[20] = "B               \0\xFF\xFF\xFF";

const char str_EDIT_NUM[12] = "EDIT NUM:\n\0\xFF";

const char str_NUM_END[12] = " NUM END:\n\0\xFF";

const char str_EDIT_INT[12] = "EDIT INT:\n\0\xFF";

const char str_INT_END[12] = " INT END:\0\xFF\xFF";

const char str_CURRENT_n[12] = "CURRENT :\n\0\xFF";

const char str_PARTS_X_H[20] = "PARTS X :     H\n\0\xFF\xFF\xFF";

const char str_PARTS_Y_H[20] = "PARTS Y :     H\n\0\xFF\xFF\xFF";

const char str_PARTS_FL[12] = "PARTS FL:\n\0\xFF";

const char str_OLC_IX[12] = "OLC IX  :\n\0\xFF";

const char str_IX_1[12] = "    IX 1:\n\0\xFF";

const char str_IX_2[12] = "    IX 2:\n\0\xFF";

const char str_IX_3[12] = "    IX 3:\n\0\xFF";

const char str_IX_4[12] = "    IX 4:\0\xFF\xFF";

const char str_DELETE_ALL_SH4[20] = "DELETE ALL    SH4\n\0\xFF";

const char str_1DATA_SH5[20] = "       1DATA  SH5\n\0\xFF";

const char str_CANCEL_SH6[20] = "       CANCEL SH6\0\xFF\xFF";

const char str_blank_line[20] = "                  \n";

const char str_empty[20] = "                  \0\xFF";

const char str_NO_EDIT[24] = "NO EDIT             \n\0\xFF\xFF";

const char str_DATA_NOTHING[24] = "   DATA  NOTHING    \0\xFF\xFF\xFF";

const char str_REVISE_X_H[20] = "REVISE X:     H\n\0\xFF\xFF\xFF";

const char str_SIZE_X_H[20] = "SIZE   X:     H\n\0\xFF\xFF\xFF";

const char str_REVISE_Y_H[20] = "REVISE Y:     H\n\0\xFF\xFF\xFF";

const char str_SIZE_Y_H[20] = "SIZE   Y:     H\n\0\xFF\xFF\xFF";

const char str_IX[20] = "IX             \n\0\xFF\xFF\xFF";

const char str_CUR[20] = "CUR            \n\0\xFF\xFF\xFF";

const char str_BOD[12] = "BOD      \n\0\xFF";

const char str_HAN[12] = "HAN      \n\0\xFF";

const char str_CAT[12] = "CAT      \n\0\xFF";

const char str_CAU[12] = "CAU      \n\0\xFF";

const char str_AT1[12] = "AT1      \n\0\xFF";

const char str_AT2[12] = "AT2      \n\0\xFF";

const char str_HOS[12] = "HOS      \0\xFF\xFF";

const char str_KOC_IX_PT_Nix_n[32] = "        KOC     IX      PT Nix\n";

const char str_KOC_IX_PT_Nix[32] = "        KOC     IX      PT Nix\0\xFF";

const char str_HEAD[12] = "HEAD    \n\0\xFF\xFF";

const char str_BREAST[12] = "BREAST  \n\0\xFF\xFF";

const char str_TRUNK_1[12] = "TRUNK  1\n\0\xFF\xFF";

const char str_LEG[12] = "LEG     \n\0\xFF\xFF";

const char str_HAND_1[12] = "HAND   1\n\0\xFF\xFF";

const char str_HAND_2[12] = "HAND   2\n\0\xFF\xFF";

const char str_CATCH_n[12] = "CATCH   \n\0\xFF\xFF";

const char str_CAUGHT_n[12] = "CAUGHT  \n\0\xFF\xFF";

const char str_ATTACK_1[12] = "ATTACK 1\n\0\xFF\xFF";

const char str_ATTACK_2[12] = "ATTACK 2\n\0\xFF\xFF";

const char str_ATTACK_3[12] = "ATTACK 3\n\0\xFF\xFF";

const char str_ATTACK_4[12] = "ATTACK 4\n\0\xFF\xFF";

const char str_TRUNK_2[12] = "TRUNK  2\0\xFF\xFF\xFF";

const char str_CG_CTR[24] = "CG CTR        (    )\n\0\xFF\xFF";

const char str_CG_TYPE[12] = "CG TYPE  \n\0\xFF";

const char str_CG_SE[24] = "CG SE         (    )\n\0\xFF\xFF";

const char str_CG_FLIP[24] = "CG FLIP       (    )\n\0\xFF\xFF";

const char str_CG_OLC_IX[24] = "CG OLC IX     (    )\n\0\xFF\xFF";

const char str_CG_NUMBER[12] = "CG NUMBER\0\xFF\xFF";

const char str_CG_ATT_IX[24] = "CG ATT IX     (    )\n\0\xFF\xFF";

const char str_CG_HIT_IX[24] = "CG HIT IX     (    )\n\0\xFF\xFF";

const char str_CG_EXTDAT[12] = "CG EXTDAT\n\0\xFF";

const char str_CG_CANCEL[12] = "CG CANCEL\n\0\xFF";

const char str_CG_EFFECT[12] = "CG EFFECT\n\0\xFF";

const char str_CG_EFTYPE[12] = "CG EFTYPE  ";

const char str_CG_RIVAL[24] = "CG RIVAL      (    )\n\0\xFF\xFF";

const char str_CG_ADD_XY[24] = "CG ADD XY     (    )\n\0\xFF\xFF";

const char str_CG_NIX[8] = "CG NIX\n";

const char str_CG_STATUS[12] = "CG STATUS\0\xFF\xFF";

const char str_CGD_TYPE[12] = "CGD TYPE \n\0\xFF";

const char str_PAT_ST[12] = "PAT ST   \n\0\xFF";

const char str_KIND_WAZA[12] = "KIND WAZA\n\0\xFF";

const char str_HIT_RANGE[12] = "HIT RANGE\n\0\xFF";

const char str_YOKE_TYPE[12] = "YOKE TYPE\n\0\xFF";

const char str_YOKE_PAT[12] = "YOKE PAT \n\0\xFF";

const char str_SP_TECH[12] = "SP TECH\n\0\xFF\xFF\xFF";

const char str_WCA_IX[8] = "WCA IX\0\xFF";

const char str_ATT_IX[8] = "ATT IX\n";

const char str_REACTION[24] = "REACTION      (    )\n\0\xFF\xFF";

const char str_MKH_IX[24] = "MKH IX        (    )\n\0\xFF\xFF";

const char str_DIP[24] = "DIP           (    )\n\0\xFF\xFF";

const char str_HISS[24] = "HISS          (    )\n\0\xFF\xFF";

const char str_DIR[24] = "DIR           (    )\n\0\xFF\xFF";

const char str_GUARD[24] = "GUARD         (    )\n\0\xFF\xFF";

const char str_POW[24] = "POW           (    )\n\0\xFF\xFF";

const char str_IMPACT[24] = "IMPACT        (    )\n\0\xFF\xFF";

const char str_PIYO_n[24] = "PIYO          (    )\n\0\xFF\xFF";

const char str_NG_TYPE[24] = "NG TYPE       (    )\n\0\xFF\xFF";

const char str_HS_ME[24] = "HS ME         (    )\n\0\xFF\xFF";

const char str_HS_YOU[24] = "HS YOU        (    )\n\0\xFF\xFF";

const char str_ZU_FLAG[24] = "ZU FLAG       (    )\n\0\xFF\xFF";

const char str_ZOKUSEI[24] = "ZOKUSEI       (    )\n\0\xFF\xFF";

const char str_AT_LEVEL[24] = "AT LEVEL      (    )\n\0\xFF\xFF";

const char str_ADD_ARTS[24] = "ADD ARTS      (    )\n\0\xFF\xFF";

const char str_BUTT_TYPE[24] = "BUTT TYPE     (    )\n\0\xFF\xFF";

const char str_BUTT_PAT[24] = "BUTT PAT      (    )\n\0\xFF\xFF";

const char str_DIR_ATT[24] = "DIR ATT       (    )\n\0\xFF\xFF";

const char str_VS_ID[24] = "VS ID         (    )\0\xFF\xFF\xFF";

const char str_blank_line_3[32] = "                            \n\0\xFF\xFF";

const char str_empty_3[32] = "                            \0\xFF\xFF\xFF";

const char str_blank_line_4[40] = "                                     \n\0\xFF";

const char str_empty_4[40] = "                                     \0\xFF\xFF";

const char str_CMOA[8] = "CMOA\n\0\xFF\xFF";

const char str_CMSW[8] = "CMSW\n\0\xFF\xFF";

const char str_CMLP[8] = "CMLP\n\0\xFF\xFF";

const char str_CML2[8] = "CML2\n\0\xFF\xFF";

const char str_CMJA[8] = "CMJA\n\0\xFF\xFF";

const char str_CMJ2[8] = "CMJ2\n\0\xFF\xFF";

const char str_CMJ3[8] = "CMJ3\n\0\xFF\xFF";

const char str_CMJ4[8] = "CMJ4\n\0\xFF\xFF";

const char str_CMMS[8] = "CMMS\n\0\xFF\xFF";

const char str_CMMD[8] = "CMMD\n\0\xFF\xFF";

const char str_CMYD[8] = "CMYD\n\0\xFF\xFF";

const char str_CMCF[8] = "CMCF\n\0\xFF\xFF";

const char str_CMCR[8] = "CMCR\0\xFF\xFF\xFF";

const char str_WCA[8] = "WCA \0\xFF\xFF\xFF";

const char str_CGD1[8] = "CGD1\0\xFF\xFF\xFF";

const char str_CGD2[8] = "CGD2\0\xFF\xFF\xFF";

const char str_CGD3[8] = "CGD3\0\xFF\xFF\xFF";

const char str_empty_5[8] = "    \0\xFF\xFF\xFF";

const char str_sl_00[8] = "sl_00\0\xFF\xFF";

const char str_sl_10[8] = "sl_10\0\xFF\xFF";

const char str_sl_12[8] = "sl_12\0\xFF\xFF";

const char str_sl_20[8] = "sl_20\0\xFF\xFF";

const char str_sl_22[8] = "sl_22\0\xFF\xFF";

const char str_sl_30[8] = "sl_30\0\xFF\xFF";

const char str_sl_32[8] = "sl_32\0\xFF\xFF";

const char str_sl_40[8] = "sl_40\0\xFF\xFF";

const char str_sl_42[8] = "sl_42\0\xFF\xFF";

const char str_sl_44[8] = "sl_44\0\xFF\xFF";

const char str_sl_50[8] = "sl_50\0\xFF\xFF";

const char str_sl_52[8] = "sl_52\0\xFF\xFF";

const char str_sl_54[8] = "sl_54\0\xFF\xFF";

const char str_sl_60[8] = "sl_60\0\xFF\xFF";

const char str_sl_62[8] = "sl_62\0\xFF\xFF";

const char str_sl_64[8] = "sl_64\0\xFF\xFF";

const char str_sl_70[8] = "sl_70\0\xFF\xFF";

const char str_sl_80[8] = "sl_80\0\xFF\xFF";

const char str_sl_82[8] = "sl_82\0\xFF\xFF";

const char str_sl_90[8] = "sl_90\0\xFF\xFF";

const char str_empty_6[8] = "     \0\xFF\xFF";

const char str_BCP00[8] = "BCP00+\0\xFF";

const char str_BCP01[8] = "BCP01+\0\xFF";

const char str_BCP02[8] = "BCP02+\0\xFF";

const char str_BCP03[8] = "BCP03+\0\xFF";

const char str_BCP04[8] = "BCP04+\0\xFF";

const char str_BCP05[8] = "BCP05+\0\xFF";

const char str_BCP06[8] = "BCP06+\0\xFF";

const char str_BCP07[8] = "BCP07+\0\xFF";

const char str_BCP08[8] = "BCP08+\0\xFF";

const char str_BCP09[8] = "BCP09+\0\xFF";

const char str_BCP10[8] = "BCP10+\0\xFF";

const char str_BCP11[8] = "BCP11+\0\xFF";

const char str_BCP12[8] = "BCP12+\0\xFF";

const char str_BCP13[8] = "BCP13+\0\xFF";

const char str_BCP14[8] = "BCP14+\0\xFF";

const char str_BCP15[8] = "BCP15+\0\xFF";

const char str_BCP20[8] = "BCP20+\0\xFF";

const char str_BCP21[8] = "BCP21+\0\xFF";

const char str_BCP22[8] = "BCP22+\0\xFF";

const char str_BCP23[8] = "BCP23+\0\xFF";

const char str_BCP24[8] = "BCP24+\0\xFF";

const char str_BCP25[8] = "BCP25+\0\xFF";

const char str_BCP26[8] = "BCP26+\0\xFF";

const char str_BCP27[8] = "BCP27+\0\xFF";

const char str_BCP28[8] = "BCP28+\0\xFF";

const char str_BCP29[8] = "BCP29+\0\xFF";

const char str_BCP30[8] = "BCP30+\0\xFF";

const char str_BCP31[8] = "BCP31+\0\xFF";

const char str_BCP32[8] = "BCP32+\0\xFF";

const char str_BCP33[8] = "BCP33+\0\xFF";

const char str_BCP34[8] = "BCP34+\0\xFF";

const char str_BCP35[8] = "BCP35+\0\xFF";

const char str_BCP36[8] = "BCP36+\0\xFF";

const char str_BCP37[8] = "BCP37+\0\xFF";

const char str_BCP38[8] = "BCP38+\0\xFF";

const char str_BCP39[8] = "BCP39+\0\xFF";

const char str_BCP40[8] = "BCP40+\0\xFF";

const char str_BCP41[8] = "BCP41+\0\xFF";

const char str_BCP42[8] = "BCP42+\0\xFF";

const char str_BCP43[8] = "BCP43+\0\xFF";

const char str_BCP44[8] = "BCP44+\0\xFF";

const char str_BCP45[8] = "BCP45+\0\xFF";

const char str_BCP46[8] = "BCP46+\0\xFF";

const char str_BCP47[8] = "BCP47+\0\xFF";

const char str_BCP48[8] = "BCP48+\0\xFF";

const char str_BCP49[8] = "BCP49+\0\xFF";

const char str_BCP50[8] = "BCP50+\0\xFF";

const char str_BCP51[8] = "BCP51+\0\xFF";

const char str_BCP52[8] = "BCP52+\0\xFF";

const char str_BCP53[8] = "BCP53+\0\xFF";

const char str_BCP54[8] = "BCP54+\0\xFF";

const char str_BCP55[8] = "BCP55+\0\xFF";

const char str_BCP56[8] = "BCP56+\0\xFF";

const char str_BCP57[8] = "BCP57+\0\xFF";

const char str_BCP58[8] = "BCP58+\0\xFF";

const char str_BCP59[8] = "BCP59+\0\xFF";

const char str_BCP60[8] = "BCP60+\0\xFF";

const char str_BCP61[8] = "BCP61+\0\xFF";

const char str_BCP62[8] = "BCP62+\0\xFF";

const char str_BCP63[8] = "BCP63+\0\xFF";

const char str_BCP64[8] = "BCP64+\0\xFF";

const char str_BCP65[8] = "BCP65+\0\xFF";

const char str_BCP66[8] = "BCP66+\0\xFF";

const char str_BCP67[8] = "BCP67+\0\xFF";

const char str_BCP68[8] = "BCP68+\0\xFF";

const char str_BCP69[8] = "BCP69+\0\xFF";

const char str_BCP70[8] = "BCP70+\0\xFF";

const char str_BCP71[8] = "BCP71+\0\xFF";

const char str_BCP72[8] = "BCP72+\0\xFF";

const char str_BCP73[8] = "BCP73+\0\xFF";

const char str_BCP74[8] = "BCP74+\0\xFF";

const char str_BCP75[8] = "BCP75+\0\xFF";

const char str_BCP76[8] = "BCP76+\0\xFF";

const char str_BCP77[8] = "BCP77+\0\xFF";

const char str_BCP78[8] = "BCP78+\0\xFF";

const char str_BCP79[8] = "BCP79+\0\xFF";

const char str_BCP80[8] = "BCP80+\0\xFF";

const char str_BCP81[8] = "BCP81+\0\xFF";

const char str_BCP82[8] = "BCP82+\0\xFF";

const char str_BCP83[8] = "BCP83+\0\xFF";

const char str_BCP84[8] = "BCP84+\0\xFF";

const char str_BCP85[8] = "BCP85+\0\xFF";

const char str_empty_7[8] = "      \0\xFF";

const char str_BCP86[8] = "BCP86+\0\xFF";

const char str_BCP87[8] = "BCP87+\0\xFF";

const char str_BCP88[8] = "BCP88+\0\xFF";

const char str_BCP89[8] = "BCP89+\0\xFF";

const char str_BCP90[8] = "BCP90+\0\xFF";

const char str_BCP91[8] = "BCP91+\0\xFF";

const char str_BCP92[8] = "BCP92+\0\xFF";

const char str_BCP93[8] = "BCP93+\0\xFF";

const char str_BCP94[8] = "BCP94+\0\xFF";

const char str_BCP95[8] = "BCP95+\0\xFF";

const char str_BCP96[8] = "BCP96+\0\xFF";

const char str_BCP97[8] = "BCP97+\0\xFF";

const char str_BCP98[8] = "BCP98+\0\xFF";

const char str_BCP99[8] = "BCP99+\0\xFF";

const char str_BCPA0[8] = "BCPA0+\0\xFF";

const char str_BCPA1[8] = "BCPA1+\0\xFF";

const char str_Pa[4] = "Pa\0\xFF";

const char str_PA[4] = "PA\0\xFF";

const char str_PB[4] = "PB\0\xFF";

const char str_MLN[4] = "MLN";

const char str_MLU[4] = "MLU";

const char str_MLD[4] = "MLD";

const char str_MLF[4] = "MLF";

const char str_MLR[4] = "MLR";

const char str_M[4] = "M__";

const char str_S1[4] = "S1\0\xFF";

const char str_S2[4] = "S2\0\xFF";

const char str_S3[4] = "S3\0\xFF";

const char str_S4[4] = "S4\0\xFF";

const char str_S5[4] = "S5\0\xFF";

const char str_S6[4] = "S6\0\xFF";

const char str_USEMJ[8] = "+USEMJ\0\xFF";

const char str_BASE[8] = "BASE  \0\xFF";

const char str_BEFORE[8] = "BEFORE\0\xFF";

const char str_BACK[8] = "BACK  \0\xFF";

const char str_H[4] = "H\0\xFF\xFF";

const char str_D[4] = "D\0\xFF\xFF";

const char str_A[4] = "A\0\xFF\xFF";

const char str_M_2[4] = "M\0\xFF\xFF";

const char str_R[4] = "R\0\xFF\xFF";

const char str_C[4] = "C\0\xFF\xFF";

const char str_S[4] = "S\0\xFF\xFF";

const char str_h[4] = "h\0\xFF\xFF";

const char str_d[4] = "d\0\xFF\xFF";

const char str_a[4] = "a\0\xFF\xFF";

const char str_m[4] = "m\0\xFF\xFF";

const char str_r[4] = "r\0\xFF\xFF";

const char str_c[4] = "c\0\xFF\xFF";

const char str_s[4] = "s\0\xFF\xFF";

const char str_h_2[4] = "h \0\xFF";

const char str_d_2[4] = "d \0\xFF";

const char str_a_2[4] = "a \0\xFF";

const char str_m_2[4] = "m \0\xFF";

const char str_r_2[4] = "r \0\xFF";

const char str_c_2[4] = "c \0\xFF";

const char str_s_2[4] = "s \0\xFF";

const char str_NM[4] = "NM\0\xFF";

const char str_DM[4] = "DM\0\xFF";

const char str_CA[4] = "CA\0\xFF";

const char str_CU[4] = "CU\0\xFF";

const char str_AT[4] = "AT\0\xFF";

const char str_BT[4] = "BT\0\xFF";

const char str_EX[4] = "EX\0\xFF";

const char str_SA[4] = "SA\0\xFF";

const char str_CB[4] = "CB\0\xFF";

const char str_empty_8[4] = "  \0\xFF";

const char str_nmA[4] = "nmA";

const char str_hsA[4] = "hsA";

const char str_nmC[4] = "nmC";

const char str_hsC[4] = "hsC";

const char str_saA[4] = "saA";

const char str_saC[4] = "saC";

const char str_paA[4] = "paA";

const char str_huA[4] = "huA";

const char str_BLANK[16] = "BLANK        \0\xFF\xFF";

const char str_FLASH[16] = "FLASH        \0\xFF\xFF";

const char str_GILL[16] = "GILL         \0\xFF\xFF";

const char str_N_Y[16] = "N.Y          \0\xFF\xFF";

const char str_JAPAN_2[16] = "JAPAN        \0\xFF\xFF";

const char str_CHAINA_1[16] = "CHAINA 1     \0\xFF\xFF";

const char str_ENGLAND[16] = "ENGLAND      \0\xFF\xFF";

const char str_RUSSIA[16] = "RUSSIA       \0\xFF\xFF";

const char str_GERMANY[16] = "GERMANY      \0\xFF\xFF";

const char str_FURUDERA[16] = "FURUDERA     \0\xFF\xFF";

const char str_AFRICA_1[16] = "AFRICA 1     \0\xFF\xFF";

const char str_AFRICA_2[16] = "AFRICA 2     \0\xFF\xFF";

const char str_BRAZIL[16] = "BRAZIL       \0\xFF\xFF";

const char str_CHAINA_2[16] = "CHAINA 2     \0\xFF\xFF";

const char str_SAN_FRANCISCO[16] = "SAN FRANCISCO\0\xFF\xFF";

const char str_SAO_PAULO[16] = "SAO PAULO    \0\xFF\xFF";

const char str_URIEN[16] = "URIEN        \0\xFF\xFF";

const char str_KEIKOKU[16] = "KEIKOKU      \0\xFF\xFF";

const char str_GILL_2[8] = "GILL  \0\xFF";

const char str_ALEX[8] = "ALEX  \0\xFF";

const char str_RYU[8] = "RYU   \0\xFF";

const char str_YUN[8] = "YUN   \0\xFF";

const char str_DUDLEY[8] = "DUDLEY\0\xFF";

const char str_NECRO[8] = "NECRO \0\xFF";

const char str_HUGO[8] = "HUGO  \0\xFF";

const char str_IBUKI[8] = "IBUKI \0\xFF";

const char str_ELENA[8] = "ELENA \0\xFF";

const char str_ORO[8] = "ORO   \0\xFF";

const char str_YANG[8] = "YANG  \0\xFF";

const char str_KEN[8] = "KEN   \0\xFF";

const char str_SEAN[8] = "SEAN  \0\xFF";

const char str_URIEN_2[8] = "URIEN \0\xFF";

const char str_GOUKI1[8] = "GOUKI1\0\xFF";

const char str_GOUKI2[8] = "GOUKI2\0\xFF";

const char str_ETC_4[8] = "ETC   \0\xFF";

const char str_NORMAL[8] = "NORMAL ";

const char str_DAMAGE[8] = "DAMAGE ";

const char str_CATCH[8] = "CATCH  ";

const char str_CAUGHT[8] = "CAUGHT ";

const char str_ATTACK[8] = "ATTACK ";

const char str_SP_AT[8] = "SP AT  ";

const char str_BUTTOBI[8] = "BUTTOBI";

const char str_UNION[8] = "UNION  ";

const char str_ETC[8] = "ETC    ";

const char str_EFFECT[8] = "EFFECT ";

const char str_empty_9[8] = "       ";

const char str_KAMAE[16] = "KAMAE         \0\xFF";

const char str_HURIMUKI[16] = "HURIMUKI      \0\xFF";

const char str_FRONT_WALK[16] = "FRONT WALK    \0\xFF";

const char str_BACK_WALK[16] = "BACK  WALK    \0\xFF";

const char str_DASH_HUMIKOMI[16] = "DASH  HUMIKOMI\0\xFF";

const char str_DASH_TOBINOKI[16] = "DASH  TOBINOKI\0\xFF";

const char str_KAGAMU[16] = "KAGAMU        \0\xFF";

const char str_KAGAMI_KAMAE[16] = "KAGAMI KAMAE  \0\xFF";

const char str_KAGAMI_TURN[16] = "KAGAMI TURN   \0\xFF";

const char str_KAGAMI_F_WALK[16] = "KAGAMI F WALK \0\xFF";

const char str_KAGAMI_B_WALK[16] = "KAGAMI B WALK \0\xFF";

const char str_STAND_UP[16] = "STAND UP      \0\xFF";

const char str_JUMP_JUNBI[16] = "JUMP     JUNBI\0\xFF";

const char str_SP_JUMP_JUNBI[16] = "SP JUMP  JUNBI\0\xFF";

const char str_JUMP_FRONT[16] = "JUMP FRONT    \0\xFF";

const char str_JUMP_VERTICAL[16] = "JUMP VERTICAL \0\xFF";

const char str_JUMP_BACK[16] = "JUMP BACK     \0\xFF";

const char str_S_JUMP_FRONT[16] = "S JUMP FRONT  \0\xFF";

const char str_S_JUMP_V[16] = "S JUMP V      \0\xFF";

const char str_S_JUMP_BACK[16] = "S JUMP BACK   \0\xFF";

const char str_SP_JUMP_FRONT[16] = "SP JUMP FRONT \0\xFF";

const char str_SP_JUMP_V[16] = "SP JUMP V     \0\xFF";

const char str_SP_JUMP_BACK[16] = "SP JUMP BACK  \0\xFF";

const char str_WALK_END[16] = "WALK END      \0\xFF";

const char str_PARING_HEAD[16] = "PARING  HEAD  \0\xFF";

const char str_PARING_UP[16] = "PARING  UP    \0\xFF";

const char str_PARING_DOWN[16] = "PARING  DOWN  \0\xFF";

const char str_PARING_AIR_F[16] = "PARING  AIR F \0\xFF";

const char str_PARING_AIR_B[16] = "PARING  AIR B \0\xFF";

const char str_GUARD_HEAD[16] = "GUARD  HEAD   \0\xFF";

const char str_GUARD_UP[16] = "GUARD  UP     \0\xFF";

const char str_GUARD_DOWN[16] = "GUARD  DOWN   \0\xFF";

const char str_GUARD_AIR[16] = "GUARD  AIR    \0\xFF";

const char str_empty_10[16] = "              \0\xFF";

const char str_P_BREAK_ZUJOU[16] = "P BREAK  ZUJOU\0\xFF";

const char str_P_BREAK_UP[16] = "P BREAK  UP   \0\xFF";

const char str_P_BREAK_DOWN[16] = "P BREAK  DOWN \0\xFF";

const char str_P_BREAK_AIR_F[16] = "P BREAK  AIR F\0\xFF";

const char str_P_BREAK_AIR_R[16] = "P BREAK  AIR R\0\xFF";

const char str_TUKAMIHAZUSI[16] = "TUKAMIHAZUSI  \0\xFF";

const char str_TUKAMIHAZUSARE[16] = "TUKAMIHAZUSARE\0\xFF";

const char str_GUARD_HEAD_2[16] = "GUARD HEAD    \0\xFF";

const char str_GUARD_UP_2[16] = "GUARD UP      \0\xFF";

const char str_GUARD_DOWN_2[16] = "GUARD DOWN    \0\xFF";

const char str_GUARD_AIR_2[16] = "GUARD AIR     \0\xFF";

const char str_HUSHIN_HEAD[16] = "HUSHIN  HEAD  \0\xFF";

const char str_HUSHIN_UP[16] = "HUSHIN  UP    \0\xFF";

const char str_HUSHIN_DOWN[16] = "HUSHIN  DOWN  \0\xFF";

const char str_HUSHIN_AIR[16] = "HUSHIN  AIR   \0\xFF";

const char str_FACE_S[16] = "FACE  S       \0\xFF";

const char str_FACE_M[16] = "FACE  M       \0\xFF";

const char str_FACE_L[16] = "FACE  L       \0\xFF";

const char str_FACE_SP[16] = "FACE  SP      \0\xFF";

const char str_FOOK_OKU_S[16] = "FOOK OKU  S   \0\xFF";

const char str_FOOK_OKU_M[16] = "FOOK OKU  M   \0\xFF";

const char str_FOOK_OKU_L[16] = "FOOK OKU  L   \0\xFF";

const char str_FOOK_OKU_SP[16] = "FOOK OKU  SP  \0\xFF";

const char str_FOOK_TEMAE_S[16] = "FOOK TEMAE  S \0\xFF";

const char str_FOOK_TEMAE_M[16] = "FOOK TEMAE  M \0\xFF";

const char str_FOOK_TEMAE_L[16] = "FOOK TEMAE  L \0\xFF";

const char str_FOOK_TEMAE_SP[16] = "FOOK TEMAE  SP\0\xFF";

const char str_UPPER_S[16] = "UPPER  S      \0\xFF";

const char str_UPPER_M[16] = "UPPER  M      \0\xFF";

const char str_UPPER_L[16] = "UPPER  L      \0\xFF";

const char str_UPPER_SP[16] = "UPPER  SP     \0\xFF";

const char str_NOUTEN_S[16] = "NOUTEN  S     \0\xFF";

const char str_NOUTEN_M[16] = "NOUTEN  M     \0\xFF";

const char str_NOUTEN_L[16] = "NOUTEN  L     \0\xFF";

const char str_NOUTEN_SP[16] = "NOUTEN  SP    \0\xFF";

const char str_BODY_BROW_S[16] = "BODY BROW   S \0\xFF";

const char str_BODY_BROW_M[16] = "BODY BROW   M \0\xFF";

const char str_BODY_BROW_L[16] = "BODY BROW   L \0\xFF";

const char str_BODY_BROW_SP[16] = "BODY BROW   SP\0\xFF";

const char str_BODY_UPPER_S[16] = "BODY UPPER  S \0\xFF";

const char str_BODY_UPPER_M[16] = "BODY UPPER  M \0\xFF";

const char str_BODY_UPPER_L[16] = "BODY UPPER  L \0\xFF";

const char str_BODY_UPPER_SP[16] = "BODY UPPER  SP\0\xFF";

const char str_TATAKI_S[16] = "TATAKI  S     \0\xFF";

const char str_TATAKI_M[16] = "TATAKI  M     \0\xFF";

const char str_TATAKI_L[16] = "TATAKI  L     \0\xFF";

const char str_TATAKI_SP[16] = "TATAKI  SP    \0\xFF";

const char str_TATAKI_V_S[16] = "TATAKI V. S   \0\xFF";

const char str_TATAKI_V_M[16] = "TATAKI V. M   \0\xFF";

const char str_TATAKI_V_L[16] = "TATAKI V. L   \0\xFF";

const char str_TATAKI_V_SP[16] = "TATAKI V. SP  \0\xFF";

const char str_NOBASITA_TE_S[16] = "NOBASITA TE  S\0\xFF";

const char str_NOBASITA_TE_M[16] = "NOBASITA TE  M\0\xFF";

const char str_NOBASITA_TE_L[16] = "NOBASITA TE  L\0\xFF";

const char str_NOBASITA_TE_SP[16] = "NOBASITA TE SP\0\xFF";

const char str_KAGAMI_S[16] = "KAGAMI  S     \0\xFF";

const char str_KAGAMI_M[16] = "KAGAMI  M     \0\xFF";

const char str_KAGAMI_L[16] = "KAGAMI  L     \0\xFF";

const char str_KAGAMI_SP[16] = "KAGAMI  SP    \0\xFF";

const char str_KGM_TATAKI_S[16] = "KGM TATAKI S  \0\xFF";

const char str_KGM_TATAKI_M[16] = "KGM TATAKI M  \0\xFF";

const char str_KGM_TATAKI_L[16] = "KGM TATAKI L  \0\xFF";

const char str_KGM_TATAKI_SP[16] = "KGM TATAKI SP \0\xFF";

const char str_KGM_TTKI_V_S[16] = "KGM TTKI V.S  \0\xFF";

const char str_KGM_TTKI_V_M[16] = "KGM TTKI V.M  \0\xFF";

const char str_KGM_TTKI_V_L[16] = "KGM TTKI V.L  \0\xFF";

const char str_KGM_TTKI_V_SP[16] = "KGM TTKI V.SP \0\xFF";

const char str_NEKOROBI_S[16] = "NEKOROBI  S   \0\xFF";

const char str_NEKOROBI_M[16] = "NEKOROBI  M   \0\xFF";

const char str_NEKOROBI_L[16] = "NEKOROBI  L   \0\xFF";

const char str_NEKOROBI_SP[16] = "NEKOROBI  SP  \0\xFF";

const char str_OKIAGARI[16] = "OKIAGARI      \0\xFF";

const char str_OKIAGARI_F[16] = "OKIAGARI  F   \0\xFF";

const char str_OKIAGARI_B[16] = "OKIAGARI  B   \0\xFF";

const char str_LOSE_NO_STAND[16] = "LOSE  NO STAND\0\xFF";

const char str_LOSE_SONABA[16] = "LOSE  SONABA  \0\xFF";

const char str_LOSE_KAGAMI[16] = "LOSE  KAGAMI  \0\xFF";

const char str_PIYO[16] = "PIYO          \0\xFF";

const char str_UKEMI_MOVE_F[16] = "UKEMI MOVE F  \0\xFF";

const char str_UKEMI_MOVE_R[16] = "UKEMI MOVE R  \0\xFF";

const char str_SHIMEOTASARE[16] = "SHIMEOTASARE  \0\xFF";

const char str_TATI_TOUKETU_S[16] = "TATI TOUKETU S\0\xFF";

const char str_TATI_TOUKETU_M[16] = "TATI TOUKETU M\0\xFF";

const char str_TATI_TOUKETU_L[16] = "TATI TOUKETU L\0\xFF";

const char str_TATI_TOUKETU_P[16] = "TATI TOUKETU P\0\xFF";

const char str_KGM_TOUKETU_S[16] = "KGM  TOUKETU S\0\xFF";

const char str_KGM_TOUKETU_M[16] = "KGM  TOUKETU M\0\xFF";

const char str_KGM_TOUKETU_L[16] = "KGM  TOUKETU L\0\xFF";

const char str_KGM_TOUKETU_P[16] = "KGM  TOUKETU P\0\xFF";

const char str_TATI_DENGEKI_S[16] = "TATI DENGEKI S\0\xFF";

const char str_TATI_DENGEKI_M[16] = "TATI DENGEKI M\0\xFF";

const char str_TATI_DENGEKI_L[16] = "TATI DENGEKI L\0\xFF";

const char str_TATI_DENGEKI_P[16] = "TATI DENGEKI P\0\xFF";

const char str_KGM_DENGEKI_S[16] = "KGM  DENGEKI S\0\xFF";

const char str_KGM_DENGEKI_M[16] = "KGM  DENGEKI M\0\xFF";

const char str_KGM_DENGEKI_L[16] = "KGM  DENGEKI L\0\xFF";

const char str_KGM_DENGEKI_P[16] = "KGM  DENGEKI P\0\xFF";

const char str_OKIAGARI_FRONT[16] = "OKIAGARI FRONT\0\xFF";

const char str_OKIAGARI_REAR[16] = "OKIAGARI REAR \0\xFF";

const char str_TATI_MOE_S[16] = "TATI MOE  S   \0\xFF";

const char str_TATI_MOE_M[16] = "TATI MOE  M   \0\xFF";

const char str_TATI_MOE_L[16] = "TATI MOE  L   \0\xFF";

const char str_TATI_MOE_SP[16] = "TATI MOE  SP  \0\xFF";

const char str_AIR_S[16] = "AIR  S        \0\xFF";

const char str_AIR_M[16] = "AIR  M        \0\xFF";

const char str_AIR_L[16] = "AIR  L        \0\xFF";

const char str_AIR_SP[16] = "AIR  SP       \0\xFF";

const char str_ASHIBARAI_A[16] = "ASHIBARAI  A  \0\xFF";

const char str_ASHIBARAI_B[16] = "ASHIBARAI  B  \0\xFF";

const char str_ASHIBARAI_C[16] = "ASHIBARAI  C  \0\xFF";

const char str_ASHIBARAI_D[16] = "ASHIBARAI  D  \0\xFF";

const char str_TUNNOMERI_A[16] = "TUNNOMERI  A  \0\xFF";

const char str_TUNNOMERI_B[16] = "TUNNOMERI  B  \0\xFF";

const char str_TUNNOMERI_C[16] = "TUNNOMERI  C  \0\xFF";

const char str_TUNNOMERI_D[16] = "TUNNOMERI  D  \0\xFF";

const char str_NOKEZORI_A[16] = "NOKEZORI  A   \0\xFF";

const char str_NOKEZORI_B[16] = "NOKEZORI  B   \0\xFF";

const char str_NOKEZORI_C[16] = "NOKEZORI  C   \0\xFF";

const char str_NOKEZORI_D[16] = "NOKEZORI  D   \0\xFF";

const char str_KUNOJI_A[16] = "KUNOJI  A     \0\xFF";

const char str_KUNOJI_B[16] = "KUNOJI  B     \0\xFF";

const char str_KUNOJI_C[16] = "KUNOJI  C     \0\xFF";

const char str_KUNOJI_D[16] = "KUNOJI  D     \0\xFF";

const char str_KIRIMOMI_A[16] = "KIRIMOMI  A   \0\xFF";

const char str_KIRIMOMI_B[16] = "KIRIMOMI  B   \0\xFF";

const char str_KIRIMOMI_C[16] = "KIRIMOMI  C   \0\xFF";

const char str_KIRIMOMI_D[16] = "KIRIMOMI  D   \0\xFF";

const char str_UPPER_A[16] = "UPPER  A      \0\xFF";

const char str_UPPER_B[16] = "UPPER  B      \0\xFF";

const char str_UPPER_C[16] = "UPPER  C      \0\xFF";

const char str_UPPER_D[16] = "UPPER  D      \0\xFF";

const char str_BODY_UPPER_A[16] = "BODY UPPER  A \0\xFF";

const char str_BODY_UPPER_B[16] = "BODY UPPER  B \0\xFF";

const char str_BODY_UPPER_C[16] = "BODY UPPER  C \0\xFF";

const char str_BODY_UPPER_D[16] = "BODY UPPER  D \0\xFF";

const char str_NM_BUTTOBI_A[16] = "NM BUTTOBI  A \0\xFF";

const char str_NM_BUTTOBI_B[16] = "NM BUTTOBI  B \0\xFF";

const char str_NM_BUTTOBI_C[16] = "NM BUTTOBI  C \0\xFF";

const char str_NM_BUTTOBI_D[16] = "NM BUTTOBI  D \0\xFF";

const char str_TATAKI_AIR_A[16] = "TATAKI  AIR A \0\xFF";

const char str_TATAKI_AIR_B[16] = "TATAKI  AIR B \0\xFF";

const char str_TATAKI_AIR_C[16] = "TATAKI  AIR C \0\xFF";

const char str_TATAKI_AIR_D[16] = "TATAKI  AIR D \0\xFF";

const char str_TTKI_V_AIR_A[16] = "TTKI V. AIR A \0\xFF";

const char str_TTKI_V_AIR_B[16] = "TTKI V. AIR B \0\xFF";

const char str_TTKI_V_AIR_C[16] = "TTKI V. AIR C \0\xFF";

const char str_TTKI_V_AIR_D[16] = "TTKI V. AIR D \0\xFF";

const char str_HUMI_ASIB_A[16] = "HUMI ASIB   A \0\xFF";

const char str_HUMI_ASIB_B[16] = "HUMI ASIB   B \0\xFF";

const char str_HUMI_ASIB_C[16] = "HUMI ASIB   C \0\xFF";

const char str_HUMI_ASIB_D[16] = "HUMI ASIB   D \0\xFF";

const char str_FACE_A[16] = "FACE   A      \0\xFF";

const char str_FACE_B[16] = "FACE   B      \0\xFF";

const char str_FACE_C[16] = "FACE   C      \0\xFF";

const char str_FACE_D[16] = "FACE   D      \0\xFF";

const char str_ASIBRI_MAKE_A[16] = "ASIBRI MAKE A \0\xFF";

const char str_ASIBRI_MAKE_B[16] = "ASIBRI MAKE B \0\xFF";

const char str_ASIBRI_MAKE_C[16] = "ASIBRI MAKE C \0\xFF";

const char str_ASIBRI_MAKE_D[16] = "ASIBRI MAKE D \0\xFF";

const char str_ASIB_TN_MAKE_A[16] = "ASIB TN MAKE A\0\xFF";

const char str_ASIB_TN_MAKE_B[16] = "ASIB TN MAKE B\0\xFF";

const char str_ASIB_TN_MAKE_C[16] = "ASIB TN MAKE C\0\xFF";

const char str_ASIB_TN_MAKE_D[16] = "ASIB TN MAKE D\0\xFF";

const char str_DENKI_A[16] = "DENKI A       \0\xFF";

const char str_DENKI_B[16] = "DENKI B       \0\xFF";

const char str_DENKI_C[16] = "DENKI C       \0\xFF";

const char str_DENKI_D[16] = "DENKI D       \0\xFF";

const char str_KUNOJI_NOKE_A[16] = "KUNOJI NOKE  A\0\xFF";

const char str_KUNOJI_NOKE_B[16] = "KUNOJI NOKE  B\0\xFF";

const char str_KUNOJI_NOKE_C[16] = "KUNOJI NOKE  C\0\xFF";

const char str_KUNOJI_NOKE_D[16] = "KUNOJI NOKE  D\0\xFF";

const char str_SINSYOURYU_A[16] = "SINSYOURYU  A \0\xFF";

const char str_SINSYOURYU_B[16] = "SINSYOURYU  B \0\xFF";

const char str_SINSYOURYU_C[16] = "SINSYOURYU  C \0\xFF";

const char str_SINSYOURYU_D[16] = "SINSYOURYU  D \0\xFF";

const char str_HANEAGARI_A[16] = "HANEAGARI  A  \0\xFF";

const char str_HANEAGARI_B[16] = "HANEAGARI  B  \0\xFF";

const char str_HANEAGARI_C[16] = "HANEAGARI  C  \0\xFF";

const char str_HANEAGARI_D[16] = "HANEAGARI  D  \0\xFF";

const char str_TOUKETSU_A[16] = "TOUKETSU  A   \0\xFF";

const char str_TOUKETSU_B[16] = "TOUKETSU  B   \0\xFF";

const char str_TOUKETSU_C[16] = "TOUKETSU  C   \0\xFF";

const char str_TOUKETSU_D[16] = "TOUKETSU  D   \0\xFF";

const char str_BODY_SLAM_A[16] = "BODY SLAM  A  \0\xFF";

const char str_BODY_SLAM_B[16] = "BODY SLAM  B  \0\xFF";

const char str_BODY_SLAM_C[16] = "BODY SLAM  C  \0\xFF";

const char str_BODY_SLAM_D[16] = "BODY SLAM  D  \0\xFF";

const char str_IPPONZEOI_A[16] = "IPPONZEOI  A  \0\xFF";

const char str_IPPONZEOI_B[16] = "IPPONZEOI  B  \0\xFF";

const char str_IPPONZEOI_C[16] = "IPPONZEOI  C  \0\xFF";

const char str_IPPONZEOI_D[16] = "IPPONZEOI  D  \0\xFF";

const char str_TOMOE_RYU_A[16] = "TOMOE  RYU  A \0\xFF";

const char str_TOMOE_RYU_B[16] = "TOMOE  RYU  B \0\xFF";

const char str_TOMOE_RYU_C[16] = "TOMOE  RYU  C \0\xFF";

const char str_TOMOE_RYU_D[16] = "TOMOE  RYU  D \0\xFF";

const char str_MONKEY_FLIP_A[16] = "MONKEY FLIP A \0\xFF";

const char str_MONKEY_FLIP_B[16] = "MONKEY FLIP B \0\xFF";

const char str_MONKEY_FLIP_C[16] = "MONKEY FLIP C \0\xFF";

const char str_MONKEY_FLIP_D[16] = "MONKEY FLIP D \0\xFF";

const char str_TOMOE_ORO_A[16] = "TOMOE ORO  A  \0\xFF";

const char str_TOMOE_ORO_B[16] = "TOMOE ORO  B  \0\xFF";

const char str_TOMOE_ORO_C[16] = "TOMOE ORO  C  \0\xFF";

const char str_TOMOE_ORO_D[16] = "TOMOE ORO  D  \0\xFF";

const char str_SNAKE_FANG_A[16] = "SNAKE FANG  A \0\xFF";

const char str_SNAKE_FANG_B[16] = "SNAKE FANG  B \0\xFF";

const char str_SNAKE_FANG_C[16] = "SNAKE FANG  C \0\xFF";

const char str_SNAKE_FANG_D[16] = "SNAKE FANG  D \0\xFF";

const char str_FLANKEN_S_A[16] = "FLANKEN.S  A  \0\xFF";

const char str_FLANKEN_S_B[16] = "FLANKEN.S  B  \0\xFF";

const char str_FLANKEN_S_C[16] = "FLANKEN.S  C  \0\xFF";

const char str_FLANKEN_S_D[16] = "FLANKEN.S  D  \0\xFF";

const char str_KISHINRIKI_A[16] = "KISHINRIKI  A \0\xFF";

const char str_KISHINRIKI_B[16] = "KISHINRIKI  B \0\xFF";

const char str_KISHINRIKI_C[16] = "KISHINRIKI  C \0\xFF";

const char str_KISHINRIKI_D[16] = "KISHINRIKI  D \0\xFF";

const char str_SPLASH_M_A[16] = "SPLASH.M  A   \0\xFF";

const char str_SPLASH_M_B[16] = "SPLASH.M  B   \0\xFF";

const char str_SPLASH_M_C[16] = "SPLASH.M  C   \0\xFF";

const char str_SPLASH_M_D[16] = "SPLASH.M  D   \0\xFF";

const char str_HARAIGOSHI_A[16] = "HARAIGOSHI A  \0\xFF";

const char str_HARAIGOSHI_B[16] = "HARAIGOSHI B  \0\xFF";

const char str_HARAIGOSHI_C[16] = "HARAIGOSHI C  \0\xFF";

const char str_HARAIGOSHI_D[16] = "HARAIGOSHI D  \0\xFF";

const char str_ALEX_B_D_A[16] = "ALEX B.D  A   \0\xFF";

const char str_ALEX_B_D_B[16] = "ALEX B.D  B   \0\xFF";

const char str_ALEX_B_D_C[16] = "ALEX B.D  C   \0\xFF";

const char str_ALEX_B_D_D[16] = "ALEX B.D  D   \0\xFF";

const char str_GILL_A[16] = "GILL   A      \0\xFF";

const char str_GILL_B[16] = "GILL   B      \0\xFF";

const char str_GILL_C[16] = "GILL   C      \0\xFF";

const char str_GILL_D[16] = "GILL   D      \0\xFF";

const char str_CATCH_1[16] = "CATCH  1      \0\xFF";

const char str_CATCH_2[16] = "CATCH  2      \0\xFF";

const char str_CATCH_3[16] = "CATCH  3      \0\xFF";

const char str_CATCH_4[16] = "CATCH  4      \0\xFF";

const char str_CATCH_5[16] = "CATCH  5      \0\xFF";

const char str_CATCH_6[16] = "CATCH  6      \0\xFF";

const char str_CATCH_7[16] = "CATCH  7      \0\xFF";

const char str_CATCH_8[16] = "CATCH  8      \0\xFF";

const char str_CATCH_9[16] = "CATCH  9      \0\xFF";

const char str_CATCH_10[16] = "CATCH  10     \0\xFF";

const char str_CATCH_11[16] = "CATCH  11     \0\xFF";

const char str_CATCH_12[16] = "CATCH  12     \0\xFF";

const char str_CATCH_13[16] = "CATCH  13     \0\xFF";

const char str_CATCH_14[16] = "CATCH  14     \0\xFF";

const char str_CATCH_15[16] = "CATCH  15     \0\xFF";

const char str_CATCH_16[16] = "CATCH  16     \0\xFF";

const char str_CATCH_17[16] = "CATCH  17     \0\xFF";

const char str_CATCH_18[16] = "CATCH  18     \0\xFF";

const char str_CATCH_19[16] = "CATCH  19     \0\xFF";

const char str_CATCH_20[16] = "CATCH  20     \0\xFF";

const char str_CATCH_21[16] = "CATCH  21     \0\xFF";

const char str_CATCH_22[16] = "CATCH  22     \0\xFF";

const char str_CATCH_23[16] = "CATCH  23     \0\xFF";

const char str_CATCH_24[16] = "CATCH  24     \0\xFF";

const char str_CATCH_25[16] = "CATCH  25     \0\xFF";

const char str_CATCH_26[16] = "CATCH  26     \0\xFF";

const char str_CATCH_27[16] = "CATCH  27     \0\xFF";

const char str_CATCH_28[16] = "CATCH  28     \0\xFF";

const char str_CATCH_29[16] = "CATCH  29     \0\xFF";

const char str_CATCH_30[16] = "CATCH  30     \0\xFF";

const char str_CATCH_31[16] = "CATCH  31     \0\xFF";

const char str_CATCH_32[16] = "CATCH  32     \0\xFF";

const char str_CATCH_33[16] = "CATCH  33     \0\xFF";

const char str_CATCH_34[16] = "CATCH  34     \0\xFF";

const char str_CATCH_35[16] = "CATCH  35     \0\xFF";

const char str_CATCH_36[16] = "CATCH  36     \0\xFF";

const char str_CATCH_37[16] = "CATCH  37     \0\xFF";

const char str_CATCH_38[16] = "CATCH  38     \0\xFF";

const char str_CATCH_39[16] = "CATCH  39     \0\xFF";

const char str_CATCH_40[16] = "CATCH  40     \0\xFF";

const char str_ALEX_ZUTUKI[16] = "ALEX ZUTUKI   \0\xFF";

const char str_ALEX_BODY_S[16] = "ALEX BODY S   \0\xFF";

const char str_ALEX_BACK_D[16] = "ALEX BACK D   \0\xFF";

const char str_ALEX_POWER_B[16] = "ALEX POWER B  \0\xFF";

const char str_ALEX_SLEEPER[16] = "ALEX SLEEPER  \0\xFF";

const char str_RYU_SEOINAGE[16] = "RYU SEOINAGE  \0\xFF";

const char str_IBUKI_2[16] = "IBUKI         \0\xFF";

const char str_DADLEY_L_B[16] = "DADLEY  L B   \0\xFF";

const char str_IBUKI_KUBIORI[16] = "IBUKI KUBIORI \0\xFF";

const char str_NECRO_S_T[16] = "NECRO S T     \0\xFF";

const char str_RYU_TOMOENAGE[16] = "RYU TOMOENAGE \0\xFF";

const char str_YUN_HIZAGERI[16] = "YUN HIZAGERI  \0\xFF";

const char str_ORO_KUBISIME[16] = "ORO KUBISIME  \0\xFF";

const char str_NECRO_G_S[16] = "NECRO G S     \0\xFF";

const char str_DUDDLEY_D_S[16] = "DUDDLEY D S   \0\xFF";

const char str_YUN_MONKEY_F[16] = "YUN MONKEY F  \0\xFF";

const char str_ORO_TOMOENAGE[16] = "ORO TOMOENAGE \0\xFF";

const char str_ORO_NIOURIKI[16] = "ORO NIOURIKI  \0\xFF";

const char str_ORO_GIGOKU_G[16] = "ORO GIGOKU G  \0\xFF";

const char str_YUN_2[16] = "YUN           \0\xFF";

const char str_NECRO_SNAKE_F[16] = "NECRO SNAKE F \0\xFF";

const char str_NECRO_F_S[16] = "NECRO F S     \0\xFF";

const char str_IBUKI_HARAIG[16] = "IBUKI HARAIG  \0\xFF";

const char str_GILL_SPLASH_M[16] = "GILL SPLASH M \0\xFF";

const char str_KEN_HIZAGERI[16] = "KEN HIZAGERI  \0\xFF";

const char str_ORO_KISINRIKI[16] = "ORO KISINRIKI \0\xFF";

const char str_SEAN_TACKLE[16] = "SEAN TACKLE   \0\xFF";

const char str_ALEX_HYPER_B[16] = "ALEX HYPER B  \0\xFF";

const char str_NECRO_SLAM_D[16] = "NECRO SLAM D  \0\xFF";

const char str_ELENA_ASINAGE[16] = "ELENA ASINAGE \0\xFF";

const char str_GILL_IMPACT_C[16] = "GILL IMPACT C \0\xFF";

const char str_ALEX_S_H_B[16] = "ALEX  S H B   \0\xFF";

const char str_ALEX_F_N_D[16] = "ALEX  F N D   \0\xFF";

const char str_IBUKI_YOROI_D[16] = "IBUKI YOROI D \0\xFF";

const char str_MAWARIKOMI_M_F[16] = "MAWARIKOMI M F\0\xFF";

const char str_HUGO_BODY_S[16] = "HUGO BODY S   \0\xFF";

const char str_HUGO_N_G_T[16] = "HUGO N G T    \0\xFF";

const char str_HUGO_M_S_P[16] = "HUGO M S P    \0\xFF";

const char str_HUGO_S_D_B_B[16] = "HUGO S D B B  \0\xFF";

const char str_S_PUNCH_A[16] = "S PUNCH  A    \0\xFF";

const char str_S_PUNCH_B[16] = "S PUNCH  B    \0\xFF";

const char str_S_PUNCH_C[16] = "S PUNCH  C    \0\xFF";

const char str_M_PUNCH_A[16] = "M PUNCH  A    \0\xFF";

const char str_M_PUNCH_B[16] = "M PUNCH  B    \0\xFF";

const char str_M_PUNCH_C[16] = "M PUNCH  C    \0\xFF";

const char str_L_PUNCH_A[16] = "L PUNCH  A    \0\xFF";

const char str_L_PUNCH_B[16] = "L PUNCH  B    \0\xFF";

const char str_L_PUNCH_C[16] = "L PUNCH  C    \0\xFF";

const char str_S_KICK_A[16] = "S KICK   A    \0\xFF";

const char str_S_KICK_B[16] = "S KICK   B    \0\xFF";

const char str_S_KICK_C[16] = "S KICK   C    \0\xFF";

const char str_M_KICK_A[16] = "M KICK   A    \0\xFF";

const char str_M_KICK_B[16] = "M KICK   B    \0\xFF";

const char str_M_KICK_C[16] = "M KICK   C    \0\xFF";

const char str_L_KICK_A[16] = "L KICK   A    \0\xFF";

const char str_L_KICK_B[16] = "L KICK   B    \0\xFF";

const char str_L_KICK_C[16] = "L KICK   C    \0\xFF";

const char str_KAGAMI_P_A[16] = "KAGAMI P  A   \0\xFF";

const char str_KAGAMI_P_B[16] = "KAGAMI P  B   \0\xFF";

const char str_KAGAMI_P_C[16] = "KAGAMI P  C   \0\xFF";

const char str_KAGAMI_K_A[16] = "KAGAMI K  A   \0\xFF";

const char str_KAGAMI_K_B[16] = "KAGAMI K  B   \0\xFF";

const char str_KAGAMI_K_C[16] = "KAGAMI K  C   \0\xFF";

const char str_V_JUMP_P_S_A[16] = "V JUMP P S  A \0\xFF";

const char str_V_JUMP_P_S_B[16] = "V JUMP P S  B \0\xFF";

const char str_V_JUMP_P_M_A[16] = "V JUMP P M  A \0\xFF";

const char str_V_JUMP_P_M_B[16] = "V JUMP P M  B \0\xFF";

const char str_V_JUMP_P_L_A[16] = "V JUMP P L  A \0\xFF";

const char str_V_JUMP_P_L_B[16] = "V JUMP P L  B \0\xFF";

const char str_V_JUMP_K_S_A[16] = "V JUMP K S  A \0\xFF";

const char str_V_JUMP_K_S_B[16] = "V JUMP K S  B \0\xFF";

const char str_V_JUMP_K_M_A[16] = "V JUMP K M  A \0\xFF";

const char str_V_JUMP_K_M_B[16] = "V JUMP K M  B \0\xFF";

const char str_V_JUMP_K_L_A[16] = "V JUMP K L  A \0\xFF";

const char str_V_JUMP_K_L_B[16] = "V JUMP K L  B \0\xFF";

const char str_F_JUMP_P_S_A[16] = "F JUMP P S  A \0\xFF";

const char str_F_JUMP_P_S_B[16] = "F JUMP P S  B \0\xFF";

const char str_F_JUMP_P_M_A[16] = "F JUMP P M  A \0\xFF";

const char str_F_JUMP_P_M_B[16] = "F JUMP P M  B \0\xFF";

const char str_F_JUMP_P_L_A[16] = "F JUMP P L  A \0\xFF";

const char str_F_JUMP_P_L_B[16] = "F JUMP P L  B \0\xFF";

const char str_F_JUMP_K_S_A[16] = "F JUMP K S  A \0\xFF";

const char str_F_JUMP_K_S_B[16] = "F JUMP K S  B \0\xFF";

const char str_F_JUMP_K_M_A[16] = "F JUMP K M  A \0\xFF";

const char str_F_JUMP_K_M_B[16] = "F JUMP K M  B \0\xFF";

const char str_F_JUMP_K_L_A[16] = "F JUMP K L  A \0\xFF";

const char str_F_JUMP_K_L_B[16] = "F JUMP K L  B \0\xFF";

const char str_B_JUMP_P_S_A[16] = "B JUMP P S  A \0\xFF";

const char str_B_JUMP_P_S_B[16] = "B JUMP P S  B \0\xFF";

const char str_B_JUMP_P_M_A[16] = "B JUMP P M  A \0\xFF";

const char str_B_JUMP_P_M_B[16] = "B JUMP P M  B \0\xFF";

const char str_B_JUMP_P_L_A[16] = "B JUMP P L  A \0\xFF";

const char str_B_JUMP_P_L_B[16] = "B JUMP P L  B \0\xFF";

const char str_B_JUMP_K_S_A[16] = "B JUMP K S  A \0\xFF";

const char str_B_JUMP_K_S_B[16] = "B JUMP K S  B \0\xFF";

const char str_B_JUMP_K_M_A[16] = "B JUMP K M  A \0\xFF";

const char str_B_JUMP_K_M_B[16] = "B JUMP K M  B \0\xFF";

const char str_B_JUMP_K_L_A[16] = "B JUMP K L  A \0\xFF";

const char str_B_JUMP_K_L_B[16] = "B JUMP K L  B \0\xFF";

const char str_SP_V_JP_S_P_A[16] = "SP V JP S P  A\0\xFF";

const char str_SP_V_JP_S_P_B[16] = "SP V JP S P  B\0\xFF";

const char str_SP_V_JP_M_P_A[16] = "SP V JP M P  A\0\xFF";

const char str_SP_V_JP_M_P_B[16] = "SP V JP M P  B\0\xFF";

const char str_SP_V_JP_L_P_A[16] = "SP V JP L P  A\0\xFF";

const char str_SP_V_JP_L_P_B[16] = "SP V JP L P  B\0\xFF";

const char str_SP_V_JP_S_K_A[16] = "SP V JP S K  A\0\xFF";

const char str_SP_V_JP_S_K_B[16] = "SP V JP S K  B\0\xFF";

const char str_SP_V_JP_M_K_A[16] = "SP V JP M K  A\0\xFF";

const char str_SP_V_JP_M_K_B[16] = "SP V JP M K  B\0\xFF";

const char str_SP_V_JP_L_K_A[16] = "SP V JP L K  A\0\xFF";

const char str_SP_V_JP_L_K_B[16] = "SP V JP L K  B\0\xFF";

const char str_SP_F_JP_S_P_A[16] = "SP F JP S P  A\0\xFF";

const char str_SP_F_JP_S_P_B[16] = "SP F JP S P  B\0\xFF";

const char str_SP_F_JP_M_P_A[16] = "SP F JP M P  A\0\xFF";

const char str_SP_F_JP_M_P_B[16] = "SP F JP M P  B\0\xFF";

const char str_SP_F_JP_L_P_A[16] = "SP F JP L P  A\0\xFF";

const char str_SP_F_JP_L_P_B[16] = "SP F JP L P  B\0\xFF";

const char str_SP_F_JP_S_K_A[16] = "SP F JP S K  A\0\xFF";

const char str_SP_F_JP_S_K_B[16] = "SP F JP S K  B\0\xFF";

const char str_SP_F_JP_M_K_A[16] = "SP F JP M K  A\0\xFF";

const char str_SP_F_JP_M_K_B[16] = "SP F JP M K  B\0\xFF";

const char str_SP_F_JP_L_K_A[16] = "SP F JP L K  A\0\xFF";

const char str_SP_F_JP_L_K_B[16] = "SP F JP L K  B\0\xFF";

const char str_SP_B_JP_S_P_A[16] = "SP B JP S P  A\0\xFF";

const char str_SP_B_JP_S_P_B[16] = "SP B JP S P  B\0\xFF";

const char str_SP_B_JP_M_P_A[16] = "SP B JP M P  A\0\xFF";

const char str_SP_B_JP_M_P_B[16] = "SP B JP M P  B\0\xFF";

const char str_SP_B_JP_L_P_A[16] = "SP B JP L P  A\0\xFF";

const char str_SP_B_JP_L_P_B[16] = "SP B JP L P  B\0\xFF";

const char str_SP_B_JP_S_K_A[16] = "SP B JP S K  A\0\xFF";

const char str_SP_B_JP_S_K_B[16] = "SP B JP S K  B\0\xFF";

const char str_SP_B_JP_M_K_A[16] = "SP B JP M K  A\0\xFF";

const char str_SP_B_JP_M_K_B[16] = "SP B JP M K  B\0\xFF";

const char str_SP_B_JP_L_K_A[16] = "SP B JP L K  A\0\xFF";

const char str_SP_B_JP_L_K_B[16] = "SP B JP L K  B\0\xFF";

const char str_S_V_JP_S_P_A[16] = "S  V JP S P  A\0\xFF";

const char str_S_V_JP_S_P_B[16] = "S  V JP S P  B\0\xFF";

const char str_S_V_JP_M_P_A[16] = "S  V JP M P  A\0\xFF";

const char str_S_V_JP_M_P_B[16] = "S  V JP M P  B\0\xFF";

const char str_S_V_JP_L_P_A[16] = "S  V JP L P  A\0\xFF";

const char str_S_V_JP_L_P_B[16] = "S  V JP L P  B\0\xFF";

const char str_S_V_JP_S_K_A[16] = "S  V JP S K  A\0\xFF";

const char str_S_V_JP_S_K_B[16] = "S  V JP S K  B\0\xFF";

const char str_S_V_JP_M_K_A[16] = "S  V JP M K  A\0\xFF";

const char str_S_V_JP_M_K_B[16] = "S  V JP M K  B\0\xFF";

const char str_S_V_JP_L_K_A[16] = "S  V JP L K  A\0\xFF";

const char str_S_V_JP_L_K_B[16] = "S  V JP L K  B\0\xFF";

const char str_S_F_JP_S_P_A[16] = "S  F JP S P  A\0\xFF";

const char str_S_F_JP_S_P_B[16] = "S  F JP S P  B\0\xFF";

const char str_S_F_JP_M_P_A[16] = "S  F JP M P  A\0\xFF";

const char str_S_F_JP_M_P_B[16] = "S  F JP M P  B\0\xFF";

const char str_S_F_JP_L_P_A[16] = "S  F JP L P  A\0\xFF";

const char str_S_F_JP_L_P_B[16] = "S  F JP L P  B\0\xFF";

const char str_S_F_JP_S_K_A[16] = "S  F JP S K  A\0\xFF";

const char str_S_F_JP_S_K_B[16] = "S  F JP S K  B\0\xFF";

const char str_S_F_JP_M_K_A[16] = "S  F JP M K  A\0\xFF";

const char str_S_F_JP_M_K_B[16] = "S  F JP M K  B\0\xFF";

const char str_S_F_JP_L_K_A[16] = "S  F JP L K  A\0\xFF";

const char str_S_F_JP_L_K_B[16] = "S  F JP L K  B\0\xFF";

const char str_S_B_JP_S_P_A[16] = "S  B JP S P  A\0\xFF";

const char str_S_B_JP_S_P_B[16] = "S  B JP S P  B\0\xFF";

const char str_S_B_JP_M_P_A[16] = "S  B JP M P  A\0\xFF";

const char str_S_B_JP_M_P_B[16] = "S  B JP M P  B\0\xFF";

const char str_S_B_JP_L_P_A[16] = "S  B JP L P  A\0\xFF";

const char str_S_B_JP_L_P_B[16] = "S  B JP L P  B\0\xFF";

const char str_S_B_JP_S_K_A[16] = "S  B JP S K  A\0\xFF";

const char str_S_B_JP_S_K_B[16] = "S  B JP S K  B\0\xFF";

const char str_S_B_JP_M_K_A[16] = "S  B JP M K  A\0\xFF";

const char str_S_B_JP_M_K_B[16] = "S  B JP M K  B\0\xFF";

const char str_S_B_JP_L_K_A[16] = "S  B JP L K  A\0\xFF";

const char str_S_B_JP_L_K_B[16] = "S  B JP L K  B\0\xFF";

const char str_TUKAMIKAKARI_A[16] = "TUKAMIKAKARI A\0\xFF";

const char str_TUKAMIKAKARI_B[16] = "TUKAMIKAKARI B\0\xFF";

const char str_TUKAMIKAKARI_C[16] = "TUKAMIKAKARI C\0\xFF";

const char str_TUKAMIKAKARI_D[16] = "TUKAMIKAKARI D\0\xFF";

const char str_TUKAMIKAKARI_E[16] = "TUKAMIKAKARI E\0\xFF";

const char str_TUKAMIKAKARI_F[16] = "TUKAMIKAKARI F\0\xFF";

const char str_TUKAMI_AIR_A[16] = "TUKAMI  AIR  A\0\xFF";

const char str_TUKAMI_AIR_B[16] = "TUKAMI  AIR  B\0\xFF";

const char str_TUKAMI_AIR_C[16] = "TUKAMI  AIR  C\0\xFF";

const char str_TUKAMI_AIR_D[16] = "TUKAMI  AIR  D\0\xFF";

const char str_TUKAMI_AIR_E[16] = "TUKAMI  AIR  E\0\xFF";

const char str_TUKAMI_AIR_F[16] = "TUKAMI  AIR  F\0\xFF";

const char str_UP_P_GUARD_P_S[16] = "UP P GUARD P S\0\xFF";

const char str_UP_P_GUARD_P_M[16] = "UP P GUARD P M\0\xFF";

const char str_UP_P_GUARD_P_L[16] = "UP P GUARD P L\0\xFF";

const char str_UP_P_GUARD_K_S[16] = "UP P GUARD K S\0\xFF";

const char str_UP_P_GUARD_K_M[16] = "UP P GUARD K M\0\xFF";

const char str_UP_P_GUARD_K_L[16] = "UP P GUARD K L\0\xFF";

const char str_D_P_GUARD_P_S[16] = "D  P GUARD P S\0\xFF";

const char str_D_P_GUARD_P_M[16] = "D  P GUARD P M\0\xFF";

const char str_D_P_GUARD_P_L[16] = "D  P GUARD P L\0\xFF";

const char str_D_P_GUARD_K_S[16] = "D  P GUARD K S\0\xFF";

const char str_D_P_GUARD_K_M[16] = "D  P GUARD K M\0\xFF";

const char str_D_P_GUARD_K_L[16] = "D  P GUARD K L\0\xFF";

const char str_FUSHIN_P_S[16] = "FUSHIN     P S\0\xFF";

const char str_FUSHIN_P_M[16] = "FUSHIN     P M\0\xFF";

const char str_FUSHIN_P_L[16] = "FUSHIN     P L\0\xFF";

const char str_FUSHIN_K_S[16] = "FUSHIN     K S\0\xFF";

const char str_FUSHIN_K_M[16] = "FUSHIN     K M\0\xFF";

const char str_FUSHIN_K_L[16] = "FUSHIN     K L\0\xFF";

const char str_OKIAGARI_P_S[16] = "OKIAGARI   P S\0\xFF";

const char str_OKIAGARI_P_M[16] = "OKIAGARI   P M\0\xFF";

const char str_OKIAGARI_P_L[16] = "OKIAGARI   P L\0\xFF";

const char str_OKIAGARI_K_S[16] = "OKIAGARI   K S\0\xFF";

const char str_OKIAGARI_K_M[16] = "OKIAGARI   K M\0\xFF";

const char str_OKIAGARI_K_L[16] = "OKIAGARI   K L\0\xFF";

const char str_ATTACK_1_S[16] = "ATTACK 1   S  \0\xFF";

const char str_ATTACK_1_M[16] = "ATTACK 1   M  \0\xFF";

const char str_ATTACK_1_L[16] = "ATTACK 1   L  \0\xFF";

const char str_ATTACK_1_SP[16] = "ATTACK 1   SP \0\xFF";

const char str_ATTACK_2_S[16] = "ATTACK 2   S  \0\xFF";

const char str_ATTACK_2_M[16] = "ATTACK 2   M  \0\xFF";

const char str_ATTACK_2_L[16] = "ATTACK 2   L  \0\xFF";

const char str_ATTACK_2_SP[16] = "ATTACK 2   SP \0\xFF";

const char str_ATTACK_3_S[16] = "ATTACK 3   S  \0\xFF";

const char str_ATTACK_3_M[16] = "ATTACK 3   M  \0\xFF";

const char str_ATTACK_3_L[16] = "ATTACK 3   L  \0\xFF";

const char str_ATTACK_3_SP[16] = "ATTACK 3   SP \0\xFF";

const char str_ATTACK_4_S[16] = "ATTACK 4   S  \0\xFF";

const char str_ATTACK_4_M[16] = "ATTACK 4   M  \0\xFF";

const char str_ATTACK_4_L[16] = "ATTACK 4   L  \0\xFF";

const char str_ATTACK_4_SP[16] = "ATTACK 4   SP \0\xFF";

const char str_ATTACK_5_S[16] = "ATTACK 5   S  \0\xFF";

const char str_ATTACK_5_M[16] = "ATTACK 5   M  \0\xFF";

const char str_ATTACK_5_L[16] = "ATTACK 5   L  \0\xFF";

const char str_ATTACK_5_SP[16] = "ATTACK 5   SP \0\xFF";

const char str_ATTACK_6_S[16] = "ATTACK 6   S  \0\xFF";

const char str_ATTACK_6_M[16] = "ATTACK 6   M  \0\xFF";

const char str_ATTACK_6_L[16] = "ATTACK 6   L  \0\xFF";

const char str_ATTACK_6_SP[16] = "ATTACK 6   SP \0\xFF";

const char str_ATTACK_7_S[16] = "ATTACK 7   S  \0\xFF";

const char str_ATTACK_7_M[16] = "ATTACK 7   M  \0\xFF";

const char str_ATTACK_7_L[16] = "ATTACK 7   L  \0\xFF";

const char str_ATTACK_7_SP[16] = "ATTACK 7   SP \0\xFF";

const char str_ATTACK_8_S[16] = "ATTACK 8   S  \0\xFF";

const char str_ATTACK_8_M[16] = "ATTACK 8   M  \0\xFF";

const char str_ATTACK_8_L[16] = "ATTACK 8   L  \0\xFF";

const char str_ATTACK_8_SP[16] = "ATTACK 8   SP \0\xFF";

const char str_ATTACK_9_S[16] = "ATTACK 9   S  \0\xFF";

const char str_ATTACK_9_M[16] = "ATTACK 9   M  \0\xFF";

const char str_ATTACK_9_L[16] = "ATTACK 9   L  \0\xFF";

const char str_ATTACK_9_SP[16] = "ATTACK 9   SP \0\xFF";

const char str_ATTACK_10_S[16] = "ATTACK 10  S  \0\xFF";

const char str_ATTACK_10_M[16] = "ATTACK 10  M  \0\xFF";

const char str_ATTACK_10_L[16] = "ATTACK 10  L  \0\xFF";

const char str_ATTACK_10_SP[16] = "ATTACK 10  SP \0\xFF";

const char str_ATTACK_11_S[16] = "ATTACK 11  S  \0\xFF";

const char str_ATTACK_11_M[16] = "ATTACK 11  M  \0\xFF";

const char str_ATTACK_11_L[16] = "ATTACK 11  L  \0\xFF";

const char str_ATTACK_11_SP[16] = "ATTACK 11  SP \0\xFF";

const char str_ATTACK_12_S[16] = "ATTACK 12  S  \0\xFF";

const char str_ATTACK_12_M[16] = "ATTACK 12  M  \0\xFF";

const char str_ATTACK_12_L[16] = "ATTACK 12  L  \0\xFF";

const char str_ATTACK_12_SP[16] = "ATTACK 12  SP \0\xFF";

const char str_ATTACK_13_S[16] = "ATTACK 13  S  \0\xFF";

const char str_ATTACK_13_M[16] = "ATTACK 13  M  \0\xFF";

const char str_ATTACK_13_L[16] = "ATTACK 13  L  \0\xFF";

const char str_ATTACK_13_SP[16] = "ATTACK 13  SP \0\xFF";

const char str_HANASARE[16] = "HANASARE      \0\xFF";

const char str_EFF01_CHAR[16] = "EFF01 CHAR    \0\xFF";

const char str_EFF13_CHAR[16] = "EFF13 CHAR    \0\xFF";

const char str_GILL_STAGE_OBJ[16] = "GILL STAGE OBJ\0\xFF";

const char str_N_Y_1_OBJ[16] = "N.Y 1      OBJ\0\xFF";

const char str_ONSEN_OBJ[16] = "ONSEN      OBJ\0\xFF";

const char str_CHAINA_1_OBJ[16] = "CHAINA 1   OBJ\0\xFF";

const char str_CHAINA_2_OBJ[16] = "CHAINA 2   OBJ\0\xFF";

const char str_ENGLAND_OBJ[16] = "ENGLAND    OBJ\0\xFF";

const char str_ROCIA_OBJ[16] = "ROCIA      OBJ\0\xFF";

const char str_GERMANY_OBJ[16] = "GERMANY    OBJ\0\xFF";

const char str_FURUDERA_OBJ[16] = "FURUDERA   OBJ\0\xFF";

const char str_AFRICA_1_OBJ[16] = "AFRICA 1   OBJ\0\xFF";

const char str_AFRICA_2_OBJ[16] = "AFRICA 2   OBJ\0\xFF";

const char str_BRAZIL_OBJ[16] = "BRAZIL     OBJ\0\xFF";

const char str_SAN_FRANCISCO_2[16] = "SAN FRANCISCO \0\xFF";

const char str_SANPAURO[16] = "SANPAURO      \0\xFF";

const char str_ETC_1[16] = "ETC 1         \0\xFF";

const char str_ETC_2[16] = "ETC 2         \0\xFF";

const char str_ETC_3[16] = "ETC 3         \0\xFF";

const char str_PLEF[16] = "PLEF          \0\xFF";

const char str_ENDING_CHAR[16] = "ENDING CHAR   \0\xFF";

const char str_APPEAR_JUNBI_1[16] = "APPEAR JUNBI 1\0\xFF";

const char str_APPEAR_JUNBI_2[16] = "APPEAR JUNBI 2\0\xFF";

const char str_APPEAR_JUNBI_3[16] = "APPEAR JUNBI 3\0\xFF";

const char str_APPEAR_JUNBI_4[16] = "APPEAR JUNBI 4\0\xFF";

const char str_APPEAR_JUNBI_5[16] = "APPEAR JUNBI 5\0\xFF";

const char str_APPEAR_JUNBI_6[16] = "APPEAR JUNBI 6\0\xFF";

const char str_APPEAR_JUNBI_7[16] = "APPEAR JUNBI 7\0\xFF";

const char str_APPEAR_JUNBI_8[16] = "APPEAR JUNBI 8\0\xFF";

const char str_APPEAR_1[16] = "APPEAR   1    \0\xFF";

const char str_APPEAR_2[16] = "APPEAR   2    \0\xFF";

const char str_APPEAR_3[16] = "APPEAR   3    \0\xFF";

const char str_APPEAR_4[16] = "APPEAR   4    \0\xFF";

const char str_APPEAR_5[16] = "APPEAR   5    \0\xFF";

const char str_APPEAR_6[16] = "APPEAR   6    \0\xFF";

const char str_APPEAR_7[16] = "APPEAR   7    \0\xFF";

const char str_APPEAR_8[16] = "APPEAR   8    \0\xFF";

const char str_SP_APPEAR_1[16] = "SP  APPEAR  1 \0\xFF";

const char str_SP_APPEAR_2[16] = "SP  APPEAR  2 \0\xFF";

const char str_SP_APPEAR_3[16] = "SP  APPEAR  3 \0\xFF";

const char str_SP_APPEAR_4[16] = "SP  APPEAR  4 \0\xFF";

const char str_SP_APPEAR_5[16] = "SP  APPEAR  5 \0\xFF";

const char str_SP_APPEAR_6[16] = "SP  APPEAR  6 \0\xFF";

const char str_SP_APPEAR_7[16] = "SP  APPEAR  7 \0\xFF";

const char str_SP_APPEAR_8[16] = "SP  APPEAR  8 \0\xFF";

const char str_ZANNEN_1[16] = "ZANNEN  1     \0\xFF";

const char str_ZANNEN_2[16] = "ZANNEN  2     \0\xFF";

const char str_ZANNEN_3[16] = "ZANNEN  3     \0\xFF";

const char str_ZANNEN_4[16] = "ZANNEN  4     \0\xFF";

const char str_ZANNEN_5[16] = "ZANNEN  5     \0\xFF";

const char str_ZANNEN_6[16] = "ZANNEN  6     \0\xFF";

const char str_ZANNEN_7[16] = "ZANNEN  7     \0\xFF";

const char str_ZANNEN_8[16] = "ZANNEN  8     \0\xFF";

const char str_WIN_1[16] = "WIN  1        \0\xFF";

const char str_WIN_2[16] = "WIN  2        \0\xFF";

const char str_WIN_3[16] = "WIN  3        \0\xFF";

const char str_WIN_4[16] = "WIN  4        \0\xFF";

const char str_WIN_5[16] = "WIN  5        \0\xFF";

const char str_WIN_6[16] = "WIN  6        \0\xFF";

const char str_WIN_7[16] = "WIN  7        \0\xFF";

const char str_WIN_8[16] = "WIN  8        \0\xFF";

const char str_SP_WIN_1[16] = "SP WIN  1     \0\xFF";

const char str_SP_WIN_2[16] = "SP WIN  2     \0\xFF";

const char str_SP_WIN_3[16] = "SP WIN  3     \0\xFF";

const char str_SP_WIN_4[16] = "SP WIN  4     \0\xFF";

const char str_SP_WIN_5[16] = "SP WIN  5     \0\xFF";

const char str_SP_WIN_6[16] = "SP WIN  6     \0\xFF";

const char str_SP_WIN_7[16] = "SP WIN  7     \0\xFF";

const char str_SP_WIN_8[16] = "SP WIN  8     \0\xFF";

const char str_JUDGMENT_WAIT[16] = "JUDGMENT WAIT \0\xFF";

const char str_JUDGMENT_WIN[16] = "JUDGMENT WIN  \0\xFF";

const char str_JUDGMENT_LOSE[16] = "JUDGMENT LOSE \0\xFF";

const char str_WAIT[16] = "WAIT          \0\xFF";

const char str_AFRICA_JUMP[16] = "AFRICA  JUMP  \0\xFF";

const char str_AFRICA_LAND[16] = "AFRICA  LAND  \0\xFF";

const char str_SEAN_BALL_HIT[16] = "SEAN BALL HIT \0\xFF";

const char str_BONUS_WIN_1[16] = "BONUS WIN 1   \0\xFF";

const char str_BONUS_WIN_2[16] = "BONUS WIN 2   \0\xFF";

const char str_BONUS_WIN_3[16] = "BONUS WIN 3   \0\xFF";

const u16 chk22_tbl[8] = {
    1, 9, 8, 0xA, 2, 6, 4, 5,
};
