/*
 * DBG_WORK.C  debug menu work
 *
 * The text of the debug menus and object displays (initialised, section D) and the debug tools'
 * work RAM (section B): menu state, the recorder's snapshots, the box editor's copy and edit
 * buffers. A <name>_tail table holds the bytes between <name> and the next named variable.
 */

#include "types.h"
#include "structs.h"

extern const s8 str_OBJECT_TEST[];
extern const s8 str_BG_SELECT[];
extern const s8 str_OBJECT_LOOK[];
extern const s8 str_OBJECT_EDIT[];
extern const s8 str_OBJECT_EDIT_2[];
extern const s8 str_HIT[];
extern const s8 str_ALL_CHARACTER[];
extern const s8 str_PARTS[];
extern const s8 str_SELECT_UP_DOWN[];
extern const s8 str_EXIT_1P_2P_START[];
extern const s8 str_PLAYER[];
extern const s8 str_ALL[];
extern const s8 str_MOTION[];
extern const s8 str_PATTERN[];
extern const s8 str_INTERRUT[];
extern const s8 str_CODE_H[];
extern const s8 str_FLIP[];
extern const s8 str_FLIP_ED[];
extern const s8 str_POS_X_H[];
extern const s8 str_POS_Y_H[];
extern const s8 str_REL_X_H[];
extern const s8 str_REL_Y_H[];
extern const s8 str_CURRENT[];
extern const s8 str_H_n[];
extern const s8 str_GROUP[];
extern const s8 str_R_n[];
extern const s8 str_G[];
extern const s8 str_B[];
extern const s8 str_EDIT_NUM[];
extern const s8 str_NUM_END[];
extern const s8 str_EDIT_INT[];
extern const s8 str_INT_END[];
extern const s8 str_CURRENT_n[];
extern const s8 str_PARTS_X_H[];
extern const s8 str_PARTS_Y_H[];
extern const s8 str_PARTS_FL[];
extern const s8 str_OLC_IX[];
extern const s8 str_IX_1[];
extern const s8 str_IX_2[];
extern const s8 str_IX_3[];
extern const s8 str_IX_4[];
extern const s8 str_DELETE_ALL_SH4[];
extern const s8 str_1DATA_SH5[];
extern const s8 str_CANCEL_SH6[];
extern const s8 str_blank_line[];
extern const s8 str_empty[];
extern const s8 str_NO_EDIT[];
extern const s8 str_DATA_NOTHING[];
extern const s8 str_REVISE_X_H[];
extern const s8 str_SIZE_X_H[];
extern const s8 str_REVISE_Y_H[];
extern const s8 str_SIZE_Y_H[];
extern const s8 str_IX[];
extern const s8 str_CUR[];
extern const s8 str_BOD[];
extern const s8 str_HAN[];
extern const s8 str_CAT[];
extern const s8 str_CAU[];
extern const s8 str_AT1[];
extern const s8 str_AT2[];
extern const s8 str_HOS[];
extern const s8 str_HEAD[];
extern const s8 str_BREAST[];
extern const s8 str_TRUNK_1[];
extern const s8 str_LEG[];
extern const s8 str_HAND_1[];
extern const s8 str_HAND_2[];
extern const s8 str_CATCH_n[];
extern const s8 str_CAUGHT_n[];
extern const s8 str_ATTACK_1[];
extern const s8 str_ATTACK_2[];
extern const s8 str_ATTACK_3[];
extern const s8 str_ATTACK_4[];
extern const s8 str_TRUNK_2[];
extern const s8 str_CG_CTR[];
extern const s8 str_CG_TYPE[];
extern const s8 str_CG_SE[];
extern const s8 str_CG_FLIP[];
extern const s8 str_CG_OLC_IX[];
extern const s8 str_CG_NUMBER[];
extern const s8 str_CG_ATT_IX[];
extern const s8 str_CG_HIT_IX[];
extern const s8 str_CG_EXTDAT[];
extern const s8 str_CG_CANCEL[];
extern const s8 str_CG_EFFECT[];
extern const s8 str_CG_EFTYPE[];
extern const s8 str_CG_RIVAL[];
extern const s8 str_CG_ADD_XY[];
extern const s8 str_CG_NIX[];
extern const s8 str_CG_STATUS[];
extern const s8 str_CGD_TYPE[];
extern const s8 str_PAT_ST[];
extern const s8 str_KIND_WAZA[];
extern const s8 str_HIT_RANGE[];
extern const s8 str_YOKE_TYPE[];
extern const s8 str_YOKE_PAT[];
extern const s8 str_SP_TECH[];
extern const s8 str_WCA_IX[];
extern const s8 str_ATT_IX[];
extern const s8 str_REACTION[];
extern const s8 str_MKH_IX[];
extern const s8 str_DIP[];
extern const s8 str_HISS[];
extern const s8 str_DIR[];
extern const s8 str_GUARD[];
extern const s8 str_POW[];
extern const s8 str_IMPACT[];
extern const s8 str_PIYO_n[];
extern const s8 str_NG_TYPE[];
extern const s8 str_HS_ME[];
extern const s8 str_HS_YOU[];
extern const s8 str_ZU_FLAG[];
extern const s8 str_ZOKUSEI[];
extern const s8 str_AT_LEVEL[];
extern const s8 str_ADD_ARTS[];
extern const s8 str_BUTT_TYPE[];
extern const s8 str_BUTT_PAT[];
extern const s8 str_DIR_ATT[];
extern const s8 str_VS_ID[];
extern const s8 str_blank_line_3[];
extern const s8 str_empty_3[];
extern const s8 str_blank_line_4[];
extern const s8 str_empty_4[];
extern const s8 str_CMOA[];
extern const s8 str_CMSW[];
extern const s8 str_CMLP[];
extern const s8 str_CML2[];
extern const s8 str_CMJA[];
extern const s8 str_CMJ2[];
extern const s8 str_CMJ3[];
extern const s8 str_CMJ4[];
extern const s8 str_CMMS[];
extern const s8 str_CMMD[];
extern const s8 str_CMYD[];
extern const s8 str_CMCF[];
extern const s8 str_CMCR[];
extern const s8 str_WCA[];
extern const s8 str_CGD1[];
extern const s8 str_CGD2[];
extern const s8 str_CGD3[];
extern const s8 str_empty_5[];
extern const s8 str_sl_00[];
extern const s8 str_sl_10[];
extern const s8 str_sl_12[];
extern const s8 str_sl_20[];
extern const s8 str_sl_22[];
extern const s8 str_sl_30[];
extern const s8 str_sl_32[];
extern const s8 str_sl_40[];
extern const s8 str_sl_42[];
extern const s8 str_sl_44[];
extern const s8 str_sl_50[];
extern const s8 str_sl_52[];
extern const s8 str_sl_54[];
extern const s8 str_sl_60[];
extern const s8 str_sl_62[];
extern const s8 str_sl_64[];
extern const s8 str_sl_70[];
extern const s8 str_sl_80[];
extern const s8 str_sl_82[];
extern const s8 str_sl_90[];
extern const s8 str_empty_6[];
extern const s8 str_BCP00[];
extern const s8 str_BCP01[];
extern const s8 str_BCP02[];
extern const s8 str_BCP03[];
extern const s8 str_BCP04[];
extern const s8 str_BCP05[];
extern const s8 str_BCP06[];
extern const s8 str_BCP07[];
extern const s8 str_BCP08[];
extern const s8 str_BCP09[];
extern const s8 str_BCP10[];
extern const s8 str_BCP11[];
extern const s8 str_BCP12[];
extern const s8 str_BCP13[];
extern const s8 str_BCP14[];
extern const s8 str_BCP15[];
extern const s8 str_BCP20[];
extern const s8 str_BCP21[];
extern const s8 str_BCP22[];
extern const s8 str_BCP23[];
extern const s8 str_BCP24[];
extern const s8 str_BCP25[];
extern const s8 str_BCP26[];
extern const s8 str_BCP27[];
extern const s8 str_BCP28[];
extern const s8 str_BCP29[];
extern const s8 str_BCP30[];
extern const s8 str_BCP31[];
extern const s8 str_BCP32[];
extern const s8 str_BCP33[];
extern const s8 str_BCP34[];
extern const s8 str_BCP35[];
extern const s8 str_BCP36[];
extern const s8 str_BCP37[];
extern const s8 str_BCP38[];
extern const s8 str_BCP39[];
extern const s8 str_BCP40[];
extern const s8 str_BCP41[];
extern const s8 str_BCP42[];
extern const s8 str_BCP43[];
extern const s8 str_BCP44[];
extern const s8 str_BCP45[];
extern const s8 str_BCP46[];
extern const s8 str_BCP47[];
extern const s8 str_BCP48[];
extern const s8 str_BCP49[];
extern const s8 str_BCP50[];
extern const s8 str_BCP51[];
extern const s8 str_BCP52[];
extern const s8 str_BCP53[];
extern const s8 str_BCP54[];
extern const s8 str_BCP55[];
extern const s8 str_BCP56[];
extern const s8 str_BCP57[];
extern const s8 str_BCP58[];
extern const s8 str_BCP59[];
extern const s8 str_BCP60[];
extern const s8 str_BCP61[];
extern const s8 str_BCP62[];
extern const s8 str_BCP63[];
extern const s8 str_BCP64[];
extern const s8 str_BCP65[];
extern const s8 str_BCP66[];
extern const s8 str_BCP67[];
extern const s8 str_BCP68[];
extern const s8 str_BCP69[];
extern const s8 str_BCP70[];
extern const s8 str_BCP71[];
extern const s8 str_BCP72[];
extern const s8 str_BCP73[];
extern const s8 str_BCP74[];
extern const s8 str_BCP75[];
extern const s8 str_BCP76[];
extern const s8 str_BCP77[];
extern const s8 str_BCP78[];
extern const s8 str_BCP79[];
extern const s8 str_BCP80[];
extern const s8 str_BCP81[];
extern const s8 str_BCP82[];
extern const s8 str_BCP83[];
extern const s8 str_BCP84[];
extern const s8 str_BCP85[];
extern const s8 str_empty_7[];
extern const s8 str_BCP86[];
extern const s8 str_BCP87[];
extern const s8 str_BCP88[];
extern const s8 str_BCP89[];
extern const s8 str_BCP90[];
extern const s8 str_BCP91[];
extern const s8 str_BCP92[];
extern const s8 str_BCP93[];
extern const s8 str_BCP94[];
extern const s8 str_BCP95[];
extern const s8 str_BCP96[];
extern const s8 str_BCP97[];
extern const s8 str_BCP98[];
extern const s8 str_BCP99[];
extern const s8 str_BCPA0[];
extern const s8 str_BCPA1[];
extern const s8 str_Pa[];
extern const s8 str_PA[];
extern const s8 str_PB[];
extern const s8 str_MLN[];
extern const s8 str_MLU[];
extern const s8 str_MLD[];
extern const s8 str_MLF[];
extern const s8 str_MLR[];
extern const s8 str_M[];
extern const s8 str_S1[];
extern const s8 str_S2[];
extern const s8 str_S3[];
extern const s8 str_S4[];
extern const s8 str_S5[];
extern const s8 str_S6[];
extern const s8 str_USEMJ[];
extern const s8 str_BASE[];
extern const s8 str_BEFORE[];
extern const s8 str_BACK[];
extern const s8 str_H[];
extern const s8 str_D[];
extern const s8 str_A[];
extern const s8 str_M_2[];
extern const s8 str_R[];
extern const s8 str_C[];
extern const s8 str_S[];
extern const s8 str_h[];
extern const s8 str_d[];
extern const s8 str_a[];
extern const s8 str_m[];
extern const s8 str_r[];
extern const s8 str_c[];
extern const s8 str_s[];
extern const s8 str_h_2[];
extern const s8 str_d_2[];
extern const s8 str_a_2[];
extern const s8 str_m_2[];
extern const s8 str_r_2[];
extern const s8 str_c_2[];
extern const s8 str_s_2[];
extern const s8 str_NM[];
extern const s8 str_DM[];
extern const s8 str_CA[];
extern const s8 str_CU[];
extern const s8 str_AT[];
extern const s8 str_BT[];
extern const s8 str_EX[];
extern const s8 str_SA[];
extern const s8 str_CB[];
extern const s8 str_empty_8[];
extern const s8 str_nmA[];
extern const s8 str_hsA[];
extern const s8 str_nmC[];
extern const s8 str_hsC[];
extern const s8 str_saA[];
extern const s8 str_saC[];
extern const s8 str_paA[];
extern const s8 str_huA[];
extern const s8 str_BLANK[];
extern const s8 str_FLASH[];
extern const s8 str_GILL[];
extern const s8 str_N_Y[];
extern const s8 str_JAPAN_2[];
extern const s8 str_CHAINA_1[];
extern const s8 str_ENGLAND[];
extern const s8 str_RUSSIA[];
extern const s8 str_GERMANY[];
extern const s8 str_FURUDERA[];
extern const s8 str_AFRICA_1[];
extern const s8 str_AFRICA_2[];
extern const s8 str_BRAZIL[];
extern const s8 str_CHAINA_2[];
extern const s8 str_SAN_FRANCISCO[];
extern const s8 str_SAO_PAULO[];
extern const s8 str_URIEN[];
extern const s8 str_KEIKOKU[];
extern const s8 str_GILL_2[];
extern const s8 str_ALEX[];
extern const s8 str_RYU[];
extern const s8 str_YUN[];
extern const s8 str_DUDLEY[];
extern const s8 str_NECRO[];
extern const s8 str_HUGO[];
extern const s8 str_IBUKI[];
extern const s8 str_ELENA[];
extern const s8 str_ORO[];
extern const s8 str_YANG[];
extern const s8 str_KEN[];
extern const s8 str_SEAN[];
extern const s8 str_URIEN_2[];
extern const s8 str_GOUKI1[];
extern const s8 str_GOUKI2[];
extern const s8 str_ETC_4[];
extern const s8 str_NORMAL[];
extern const s8 str_DAMAGE[];
extern const s8 str_CATCH[];
extern const s8 str_CAUGHT[];
extern const s8 str_ATTACK[];
extern const s8 str_SP_AT[];
extern const s8 str_BUTTOBI[];
extern const s8 str_UNION[];
extern const s8 str_ETC[];
extern const s8 str_EFFECT[];
extern const s8 str_empty_9[];
extern const s8 str_KAMAE[];
extern const s8 str_HURIMUKI[];
extern const s8 str_FRONT_WALK[];
extern const s8 str_BACK_WALK[];
extern const s8 str_DASH_HUMIKOMI[];
extern const s8 str_DASH_TOBINOKI[];
extern const s8 str_KAGAMU[];
extern const s8 str_KAGAMI_KAMAE[];
extern const s8 str_KAGAMI_TURN[];
extern const s8 str_KAGAMI_F_WALK[];
extern const s8 str_KAGAMI_B_WALK[];
extern const s8 str_STAND_UP[];
extern const s8 str_JUMP_JUNBI[];
extern const s8 str_SP_JUMP_JUNBI[];
extern const s8 str_JUMP_FRONT[];
extern const s8 str_JUMP_VERTICAL[];
extern const s8 str_JUMP_BACK[];
extern const s8 str_S_JUMP_FRONT[];
extern const s8 str_S_JUMP_V[];
extern const s8 str_S_JUMP_BACK[];
extern const s8 str_SP_JUMP_FRONT[];
extern const s8 str_SP_JUMP_V[];
extern const s8 str_SP_JUMP_BACK[];
extern const s8 str_WALK_END[];
extern const s8 str_PARING_HEAD[];
extern const s8 str_PARING_UP[];
extern const s8 str_PARING_DOWN[];
extern const s8 str_PARING_AIR_F[];
extern const s8 str_PARING_AIR_B[];
extern const s8 str_GUARD_HEAD[];
extern const s8 str_GUARD_UP[];
extern const s8 str_GUARD_DOWN[];
extern const s8 str_GUARD_AIR[];
extern const s8 str_empty_10[];
extern const s8 str_P_BREAK_ZUJOU[];
extern const s8 str_P_BREAK_UP[];
extern const s8 str_P_BREAK_DOWN[];
extern const s8 str_P_BREAK_AIR_F[];
extern const s8 str_P_BREAK_AIR_R[];
extern const s8 str_TUKAMIHAZUSI[];
extern const s8 str_TUKAMIHAZUSARE[];
extern const s8 str_GUARD_HEAD_2[];
extern const s8 str_GUARD_UP_2[];
extern const s8 str_GUARD_DOWN_2[];
extern const s8 str_GUARD_AIR_2[];
extern const s8 str_HUSHIN_HEAD[];
extern const s8 str_HUSHIN_UP[];
extern const s8 str_HUSHIN_DOWN[];
extern const s8 str_HUSHIN_AIR[];
extern const s8 str_FACE_S[];
extern const s8 str_FACE_M[];
extern const s8 str_FACE_L[];
extern const s8 str_FACE_SP[];
extern const s8 str_FOOK_OKU_S[];
extern const s8 str_FOOK_OKU_M[];
extern const s8 str_FOOK_OKU_L[];
extern const s8 str_FOOK_OKU_SP[];
extern const s8 str_FOOK_TEMAE_S[];
extern const s8 str_FOOK_TEMAE_M[];
extern const s8 str_FOOK_TEMAE_L[];
extern const s8 str_FOOK_TEMAE_SP[];
extern const s8 str_UPPER_S[];
extern const s8 str_UPPER_M[];
extern const s8 str_UPPER_L[];
extern const s8 str_UPPER_SP[];
extern const s8 str_NOUTEN_S[];
extern const s8 str_NOUTEN_M[];
extern const s8 str_NOUTEN_L[];
extern const s8 str_NOUTEN_SP[];
extern const s8 str_BODY_BROW_S[];
extern const s8 str_BODY_BROW_M[];
extern const s8 str_BODY_BROW_L[];
extern const s8 str_BODY_BROW_SP[];
extern const s8 str_BODY_UPPER_S[];
extern const s8 str_BODY_UPPER_M[];
extern const s8 str_BODY_UPPER_L[];
extern const s8 str_BODY_UPPER_SP[];
extern const s8 str_TATAKI_S[];
extern const s8 str_TATAKI_M[];
extern const s8 str_TATAKI_L[];
extern const s8 str_TATAKI_SP[];
extern const s8 str_TATAKI_V_S[];
extern const s8 str_TATAKI_V_M[];
extern const s8 str_TATAKI_V_L[];
extern const s8 str_TATAKI_V_SP[];
extern const s8 str_NOBASITA_TE_S[];
extern const s8 str_NOBASITA_TE_M[];
extern const s8 str_NOBASITA_TE_L[];
extern const s8 str_NOBASITA_TE_SP[];
extern const s8 str_KAGAMI_S[];
extern const s8 str_KAGAMI_M[];
extern const s8 str_KAGAMI_L[];
extern const s8 str_KAGAMI_SP[];
extern const s8 str_KGM_TATAKI_S[];
extern const s8 str_KGM_TATAKI_M[];
extern const s8 str_KGM_TATAKI_L[];
extern const s8 str_KGM_TATAKI_SP[];
extern const s8 str_KGM_TTKI_V_S[];
extern const s8 str_KGM_TTKI_V_M[];
extern const s8 str_KGM_TTKI_V_L[];
extern const s8 str_KGM_TTKI_V_SP[];
extern const s8 str_NEKOROBI_S[];
extern const s8 str_NEKOROBI_M[];
extern const s8 str_NEKOROBI_L[];
extern const s8 str_NEKOROBI_SP[];
extern const s8 str_OKIAGARI[];
extern const s8 str_OKIAGARI_F[];
extern const s8 str_OKIAGARI_B[];
extern const s8 str_LOSE_NO_STAND[];
extern const s8 str_LOSE_SONABA[];
extern const s8 str_LOSE_KAGAMI[];
extern const s8 str_PIYO[];
extern const s8 str_UKEMI_MOVE_F[];
extern const s8 str_UKEMI_MOVE_R[];
extern const s8 str_SHIMEOTASARE[];
extern const s8 str_TATI_TOUKETU_S[];
extern const s8 str_TATI_TOUKETU_M[];
extern const s8 str_TATI_TOUKETU_L[];
extern const s8 str_TATI_TOUKETU_P[];
extern const s8 str_KGM_TOUKETU_S[];
extern const s8 str_KGM_TOUKETU_M[];
extern const s8 str_KGM_TOUKETU_L[];
extern const s8 str_KGM_TOUKETU_P[];
extern const s8 str_TATI_DENGEKI_S[];
extern const s8 str_TATI_DENGEKI_M[];
extern const s8 str_TATI_DENGEKI_L[];
extern const s8 str_TATI_DENGEKI_P[];
extern const s8 str_KGM_DENGEKI_S[];
extern const s8 str_KGM_DENGEKI_M[];
extern const s8 str_KGM_DENGEKI_L[];
extern const s8 str_KGM_DENGEKI_P[];
extern const s8 str_OKIAGARI_FRONT[];
extern const s8 str_OKIAGARI_REAR[];
extern const s8 str_TATI_MOE_S[];
extern const s8 str_TATI_MOE_M[];
extern const s8 str_TATI_MOE_L[];
extern const s8 str_TATI_MOE_SP[];
extern const s8 str_AIR_S[];
extern const s8 str_AIR_M[];
extern const s8 str_AIR_L[];
extern const s8 str_AIR_SP[];
extern const s8 str_ASHIBARAI_A[];
extern const s8 str_ASHIBARAI_B[];
extern const s8 str_ASHIBARAI_C[];
extern const s8 str_ASHIBARAI_D[];
extern const s8 str_TUNNOMERI_A[];
extern const s8 str_TUNNOMERI_B[];
extern const s8 str_TUNNOMERI_C[];
extern const s8 str_TUNNOMERI_D[];
extern const s8 str_NOKEZORI_A[];
extern const s8 str_NOKEZORI_B[];
extern const s8 str_NOKEZORI_C[];
extern const s8 str_NOKEZORI_D[];
extern const s8 str_KUNOJI_A[];
extern const s8 str_KUNOJI_B[];
extern const s8 str_KUNOJI_C[];
extern const s8 str_KUNOJI_D[];
extern const s8 str_KIRIMOMI_A[];
extern const s8 str_KIRIMOMI_B[];
extern const s8 str_KIRIMOMI_C[];
extern const s8 str_KIRIMOMI_D[];
extern const s8 str_UPPER_A[];
extern const s8 str_UPPER_B[];
extern const s8 str_UPPER_C[];
extern const s8 str_UPPER_D[];
extern const s8 str_BODY_UPPER_A[];
extern const s8 str_BODY_UPPER_B[];
extern const s8 str_BODY_UPPER_C[];
extern const s8 str_BODY_UPPER_D[];
extern const s8 str_NM_BUTTOBI_A[];
extern const s8 str_NM_BUTTOBI_B[];
extern const s8 str_NM_BUTTOBI_C[];
extern const s8 str_NM_BUTTOBI_D[];
extern const s8 str_TATAKI_AIR_A[];
extern const s8 str_TATAKI_AIR_B[];
extern const s8 str_TATAKI_AIR_C[];
extern const s8 str_TATAKI_AIR_D[];
extern const s8 str_TTKI_V_AIR_A[];
extern const s8 str_TTKI_V_AIR_B[];
extern const s8 str_TTKI_V_AIR_C[];
extern const s8 str_TTKI_V_AIR_D[];
extern const s8 str_HUMI_ASIB_A[];
extern const s8 str_HUMI_ASIB_B[];
extern const s8 str_HUMI_ASIB_C[];
extern const s8 str_HUMI_ASIB_D[];
extern const s8 str_FACE_A[];
extern const s8 str_FACE_B[];
extern const s8 str_FACE_C[];
extern const s8 str_FACE_D[];
extern const s8 str_ASIBRI_MAKE_A[];
extern const s8 str_ASIBRI_MAKE_B[];
extern const s8 str_ASIBRI_MAKE_C[];
extern const s8 str_ASIBRI_MAKE_D[];
extern const s8 str_ASIB_TN_MAKE_A[];
extern const s8 str_ASIB_TN_MAKE_B[];
extern const s8 str_ASIB_TN_MAKE_C[];
extern const s8 str_ASIB_TN_MAKE_D[];
extern const s8 str_DENKI_A[];
extern const s8 str_DENKI_B[];
extern const s8 str_DENKI_C[];
extern const s8 str_DENKI_D[];
extern const s8 str_KUNOJI_NOKE_A[];
extern const s8 str_KUNOJI_NOKE_B[];
extern const s8 str_KUNOJI_NOKE_C[];
extern const s8 str_KUNOJI_NOKE_D[];
extern const s8 str_SINSYOURYU_A[];
extern const s8 str_SINSYOURYU_B[];
extern const s8 str_SINSYOURYU_C[];
extern const s8 str_SINSYOURYU_D[];
extern const s8 str_HANEAGARI_A[];
extern const s8 str_HANEAGARI_B[];
extern const s8 str_HANEAGARI_C[];
extern const s8 str_HANEAGARI_D[];
extern const s8 str_TOUKETSU_A[];
extern const s8 str_TOUKETSU_B[];
extern const s8 str_TOUKETSU_C[];
extern const s8 str_TOUKETSU_D[];
extern const s8 str_BODY_SLAM_A[];
extern const s8 str_BODY_SLAM_B[];
extern const s8 str_BODY_SLAM_C[];
extern const s8 str_BODY_SLAM_D[];
extern const s8 str_IPPONZEOI_A[];
extern const s8 str_IPPONZEOI_B[];
extern const s8 str_IPPONZEOI_C[];
extern const s8 str_IPPONZEOI_D[];
extern const s8 str_TOMOE_RYU_A[];
extern const s8 str_TOMOE_RYU_B[];
extern const s8 str_TOMOE_RYU_C[];
extern const s8 str_TOMOE_RYU_D[];
extern const s8 str_MONKEY_FLIP_A[];
extern const s8 str_MONKEY_FLIP_B[];
extern const s8 str_MONKEY_FLIP_C[];
extern const s8 str_MONKEY_FLIP_D[];
extern const s8 str_TOMOE_ORO_A[];
extern const s8 str_TOMOE_ORO_B[];
extern const s8 str_TOMOE_ORO_C[];
extern const s8 str_TOMOE_ORO_D[];
extern const s8 str_SNAKE_FANG_A[];
extern const s8 str_SNAKE_FANG_B[];
extern const s8 str_SNAKE_FANG_C[];
extern const s8 str_SNAKE_FANG_D[];
extern const s8 str_FLANKEN_S_A[];
extern const s8 str_FLANKEN_S_B[];
extern const s8 str_FLANKEN_S_C[];
extern const s8 str_FLANKEN_S_D[];
extern const s8 str_KISHINRIKI_A[];
extern const s8 str_KISHINRIKI_B[];
extern const s8 str_KISHINRIKI_C[];
extern const s8 str_KISHINRIKI_D[];
extern const s8 str_SPLASH_M_A[];
extern const s8 str_SPLASH_M_B[];
extern const s8 str_SPLASH_M_C[];
extern const s8 str_SPLASH_M_D[];
extern const s8 str_HARAIGOSHI_A[];
extern const s8 str_HARAIGOSHI_B[];
extern const s8 str_HARAIGOSHI_C[];
extern const s8 str_HARAIGOSHI_D[];
extern const s8 str_ALEX_B_D_A[];
extern const s8 str_ALEX_B_D_B[];
extern const s8 str_ALEX_B_D_C[];
extern const s8 str_ALEX_B_D_D[];
extern const s8 str_GILL_A[];
extern const s8 str_GILL_B[];
extern const s8 str_GILL_C[];
extern const s8 str_GILL_D[];
extern const s8 str_CATCH_1[];
extern const s8 str_CATCH_2[];
extern const s8 str_CATCH_3[];
extern const s8 str_CATCH_4[];
extern const s8 str_CATCH_5[];
extern const s8 str_CATCH_6[];
extern const s8 str_CATCH_7[];
extern const s8 str_CATCH_8[];
extern const s8 str_CATCH_9[];
extern const s8 str_CATCH_10[];
extern const s8 str_CATCH_11[];
extern const s8 str_CATCH_12[];
extern const s8 str_CATCH_13[];
extern const s8 str_CATCH_14[];
extern const s8 str_CATCH_15[];
extern const s8 str_CATCH_16[];
extern const s8 str_CATCH_17[];
extern const s8 str_CATCH_18[];
extern const s8 str_CATCH_19[];
extern const s8 str_CATCH_20[];
extern const s8 str_CATCH_21[];
extern const s8 str_CATCH_22[];
extern const s8 str_CATCH_23[];
extern const s8 str_CATCH_24[];
extern const s8 str_CATCH_25[];
extern const s8 str_CATCH_26[];
extern const s8 str_CATCH_27[];
extern const s8 str_CATCH_28[];
extern const s8 str_CATCH_29[];
extern const s8 str_CATCH_30[];
extern const s8 str_CATCH_31[];
extern const s8 str_CATCH_32[];
extern const s8 str_CATCH_33[];
extern const s8 str_CATCH_34[];
extern const s8 str_CATCH_35[];
extern const s8 str_CATCH_36[];
extern const s8 str_CATCH_37[];
extern const s8 str_CATCH_38[];
extern const s8 str_CATCH_39[];
extern const s8 str_CATCH_40[];
extern const s8 str_ALEX_ZUTUKI[];
extern const s8 str_ALEX_BODY_S[];
extern const s8 str_ALEX_BACK_D[];
extern const s8 str_ALEX_POWER_B[];
extern const s8 str_ALEX_SLEEPER[];
extern const s8 str_RYU_SEOINAGE[];
extern const s8 str_IBUKI_2[];
extern const s8 str_DADLEY_L_B[];
extern const s8 str_IBUKI_KUBIORI[];
extern const s8 str_NECRO_S_T[];
extern const s8 str_RYU_TOMOENAGE[];
extern const s8 str_YUN_HIZAGERI[];
extern const s8 str_ORO_KUBISIME[];
extern const s8 str_NECRO_G_S[];
extern const s8 str_DUDDLEY_D_S[];
extern const s8 str_YUN_MONKEY_F[];
extern const s8 str_ORO_TOMOENAGE[];
extern const s8 str_ORO_NIOURIKI[];
extern const s8 str_ORO_GIGOKU_G[];
extern const s8 str_YUN_2[];
extern const s8 str_NECRO_SNAKE_F[];
extern const s8 str_NECRO_F_S[];
extern const s8 str_IBUKI_HARAIG[];
extern const s8 str_GILL_SPLASH_M[];
extern const s8 str_KEN_HIZAGERI[];
extern const s8 str_ORO_KISINRIKI[];
extern const s8 str_SEAN_TACKLE[];
extern const s8 str_ALEX_HYPER_B[];
extern const s8 str_NECRO_SLAM_D[];
extern const s8 str_ELENA_ASINAGE[];
extern const s8 str_GILL_IMPACT_C[];
extern const s8 str_ALEX_S_H_B[];
extern const s8 str_ALEX_F_N_D[];
extern const s8 str_IBUKI_YOROI_D[];
extern const s8 str_MAWARIKOMI_M_F[];
extern const s8 str_HUGO_BODY_S[];
extern const s8 str_HUGO_N_G_T[];
extern const s8 str_HUGO_M_S_P[];
extern const s8 str_HUGO_S_D_B_B[];
extern const s8 str_S_PUNCH_A[];
extern const s8 str_S_PUNCH_B[];
extern const s8 str_S_PUNCH_C[];
extern const s8 str_M_PUNCH_A[];
extern const s8 str_M_PUNCH_B[];
extern const s8 str_M_PUNCH_C[];
extern const s8 str_L_PUNCH_A[];
extern const s8 str_L_PUNCH_B[];
extern const s8 str_L_PUNCH_C[];
extern const s8 str_S_KICK_A[];
extern const s8 str_S_KICK_B[];
extern const s8 str_S_KICK_C[];
extern const s8 str_M_KICK_A[];
extern const s8 str_M_KICK_B[];
extern const s8 str_M_KICK_C[];
extern const s8 str_L_KICK_A[];
extern const s8 str_L_KICK_B[];
extern const s8 str_L_KICK_C[];
extern const s8 str_KAGAMI_P_A[];
extern const s8 str_KAGAMI_P_B[];
extern const s8 str_KAGAMI_P_C[];
extern const s8 str_KAGAMI_K_A[];
extern const s8 str_KAGAMI_K_B[];
extern const s8 str_KAGAMI_K_C[];
extern const s8 str_V_JUMP_P_S_A[];
extern const s8 str_V_JUMP_P_S_B[];
extern const s8 str_V_JUMP_P_M_A[];
extern const s8 str_V_JUMP_P_M_B[];
extern const s8 str_V_JUMP_P_L_A[];
extern const s8 str_V_JUMP_P_L_B[];
extern const s8 str_V_JUMP_K_S_A[];
extern const s8 str_V_JUMP_K_S_B[];
extern const s8 str_V_JUMP_K_M_A[];
extern const s8 str_V_JUMP_K_M_B[];
extern const s8 str_V_JUMP_K_L_A[];
extern const s8 str_V_JUMP_K_L_B[];
extern const s8 str_F_JUMP_P_S_A[];
extern const s8 str_F_JUMP_P_S_B[];
extern const s8 str_F_JUMP_P_M_A[];
extern const s8 str_F_JUMP_P_M_B[];
extern const s8 str_F_JUMP_P_L_A[];
extern const s8 str_F_JUMP_P_L_B[];
extern const s8 str_F_JUMP_K_S_A[];
extern const s8 str_F_JUMP_K_S_B[];
extern const s8 str_F_JUMP_K_M_A[];
extern const s8 str_F_JUMP_K_M_B[];
extern const s8 str_F_JUMP_K_L_A[];
extern const s8 str_F_JUMP_K_L_B[];
extern const s8 str_B_JUMP_P_S_A[];
extern const s8 str_B_JUMP_P_S_B[];
extern const s8 str_B_JUMP_P_M_A[];
extern const s8 str_B_JUMP_P_M_B[];
extern const s8 str_B_JUMP_P_L_A[];
extern const s8 str_B_JUMP_P_L_B[];
extern const s8 str_B_JUMP_K_S_A[];
extern const s8 str_B_JUMP_K_S_B[];
extern const s8 str_B_JUMP_K_M_A[];
extern const s8 str_B_JUMP_K_M_B[];
extern const s8 str_B_JUMP_K_L_A[];
extern const s8 str_B_JUMP_K_L_B[];
extern const s8 str_SP_V_JP_S_P_A[];
extern const s8 str_SP_V_JP_S_P_B[];
extern const s8 str_SP_V_JP_M_P_A[];
extern const s8 str_SP_V_JP_M_P_B[];
extern const s8 str_SP_V_JP_L_P_A[];
extern const s8 str_SP_V_JP_L_P_B[];
extern const s8 str_SP_V_JP_S_K_A[];
extern const s8 str_SP_V_JP_S_K_B[];
extern const s8 str_SP_V_JP_M_K_A[];
extern const s8 str_SP_V_JP_M_K_B[];
extern const s8 str_SP_V_JP_L_K_A[];
extern const s8 str_SP_V_JP_L_K_B[];
extern const s8 str_SP_F_JP_S_P_A[];
extern const s8 str_SP_F_JP_S_P_B[];
extern const s8 str_SP_F_JP_M_P_A[];
extern const s8 str_SP_F_JP_M_P_B[];
extern const s8 str_SP_F_JP_L_P_A[];
extern const s8 str_SP_F_JP_L_P_B[];
extern const s8 str_SP_F_JP_S_K_A[];
extern const s8 str_SP_F_JP_S_K_B[];
extern const s8 str_SP_F_JP_M_K_A[];
extern const s8 str_SP_F_JP_M_K_B[];
extern const s8 str_SP_F_JP_L_K_A[];
extern const s8 str_SP_F_JP_L_K_B[];
extern const s8 str_SP_B_JP_S_P_A[];
extern const s8 str_SP_B_JP_S_P_B[];
extern const s8 str_SP_B_JP_M_P_A[];
extern const s8 str_SP_B_JP_M_P_B[];
extern const s8 str_SP_B_JP_L_P_A[];
extern const s8 str_SP_B_JP_L_P_B[];
extern const s8 str_SP_B_JP_S_K_A[];
extern const s8 str_SP_B_JP_S_K_B[];
extern const s8 str_SP_B_JP_M_K_A[];
extern const s8 str_SP_B_JP_M_K_B[];
extern const s8 str_SP_B_JP_L_K_A[];
extern const s8 str_SP_B_JP_L_K_B[];
extern const s8 str_S_V_JP_S_P_A[];
extern const s8 str_S_V_JP_S_P_B[];
extern const s8 str_S_V_JP_M_P_A[];
extern const s8 str_S_V_JP_M_P_B[];
extern const s8 str_S_V_JP_L_P_A[];
extern const s8 str_S_V_JP_L_P_B[];
extern const s8 str_S_V_JP_S_K_A[];
extern const s8 str_S_V_JP_S_K_B[];
extern const s8 str_S_V_JP_M_K_A[];
extern const s8 str_S_V_JP_M_K_B[];
extern const s8 str_S_V_JP_L_K_A[];
extern const s8 str_S_V_JP_L_K_B[];
extern const s8 str_S_F_JP_S_P_A[];
extern const s8 str_S_F_JP_S_P_B[];
extern const s8 str_S_F_JP_M_P_A[];
extern const s8 str_S_F_JP_M_P_B[];
extern const s8 str_S_F_JP_L_P_A[];
extern const s8 str_S_F_JP_L_P_B[];
extern const s8 str_S_F_JP_S_K_A[];
extern const s8 str_S_F_JP_S_K_B[];
extern const s8 str_S_F_JP_M_K_A[];
extern const s8 str_S_F_JP_M_K_B[];
extern const s8 str_S_F_JP_L_K_A[];
extern const s8 str_S_F_JP_L_K_B[];
extern const s8 str_S_B_JP_S_P_A[];
extern const s8 str_S_B_JP_S_P_B[];
extern const s8 str_S_B_JP_M_P_A[];
extern const s8 str_S_B_JP_M_P_B[];
extern const s8 str_S_B_JP_L_P_A[];
extern const s8 str_S_B_JP_L_P_B[];
extern const s8 str_S_B_JP_S_K_A[];
extern const s8 str_S_B_JP_S_K_B[];
extern const s8 str_S_B_JP_M_K_A[];
extern const s8 str_S_B_JP_M_K_B[];
extern const s8 str_S_B_JP_L_K_A[];
extern const s8 str_S_B_JP_L_K_B[];
extern const s8 str_TUKAMIKAKARI_A[];
extern const s8 str_TUKAMIKAKARI_B[];
extern const s8 str_TUKAMIKAKARI_C[];
extern const s8 str_TUKAMIKAKARI_D[];
extern const s8 str_TUKAMIKAKARI_E[];
extern const s8 str_TUKAMIKAKARI_F[];
extern const s8 str_TUKAMI_AIR_A[];
extern const s8 str_TUKAMI_AIR_B[];
extern const s8 str_TUKAMI_AIR_C[];
extern const s8 str_TUKAMI_AIR_D[];
extern const s8 str_TUKAMI_AIR_E[];
extern const s8 str_TUKAMI_AIR_F[];
extern const s8 str_UP_P_GUARD_P_S[];
extern const s8 str_UP_P_GUARD_P_M[];
extern const s8 str_UP_P_GUARD_P_L[];
extern const s8 str_UP_P_GUARD_K_S[];
extern const s8 str_UP_P_GUARD_K_M[];
extern const s8 str_UP_P_GUARD_K_L[];
extern const s8 str_D_P_GUARD_P_S[];
extern const s8 str_D_P_GUARD_P_M[];
extern const s8 str_D_P_GUARD_P_L[];
extern const s8 str_D_P_GUARD_K_S[];
extern const s8 str_D_P_GUARD_K_M[];
extern const s8 str_D_P_GUARD_K_L[];
extern const s8 str_FUSHIN_P_S[];
extern const s8 str_FUSHIN_P_M[];
extern const s8 str_FUSHIN_P_L[];
extern const s8 str_FUSHIN_K_S[];
extern const s8 str_FUSHIN_K_M[];
extern const s8 str_FUSHIN_K_L[];
extern const s8 str_OKIAGARI_P_S[];
extern const s8 str_OKIAGARI_P_M[];
extern const s8 str_OKIAGARI_P_L[];
extern const s8 str_OKIAGARI_K_S[];
extern const s8 str_OKIAGARI_K_M[];
extern const s8 str_OKIAGARI_K_L[];
extern const s8 str_ATTACK_1_S[];
extern const s8 str_ATTACK_1_M[];
extern const s8 str_ATTACK_1_L[];
extern const s8 str_ATTACK_1_SP[];
extern const s8 str_ATTACK_2_S[];
extern const s8 str_ATTACK_2_M[];
extern const s8 str_ATTACK_2_L[];
extern const s8 str_ATTACK_2_SP[];
extern const s8 str_ATTACK_3_S[];
extern const s8 str_ATTACK_3_M[];
extern const s8 str_ATTACK_3_L[];
extern const s8 str_ATTACK_3_SP[];
extern const s8 str_ATTACK_4_S[];
extern const s8 str_ATTACK_4_M[];
extern const s8 str_ATTACK_4_L[];
extern const s8 str_ATTACK_4_SP[];
extern const s8 str_ATTACK_5_S[];
extern const s8 str_ATTACK_5_M[];
extern const s8 str_ATTACK_5_L[];
extern const s8 str_ATTACK_5_SP[];
extern const s8 str_ATTACK_6_S[];
extern const s8 str_ATTACK_6_M[];
extern const s8 str_ATTACK_6_L[];
extern const s8 str_ATTACK_6_SP[];
extern const s8 str_ATTACK_7_S[];
extern const s8 str_ATTACK_7_M[];
extern const s8 str_ATTACK_7_L[];
extern const s8 str_ATTACK_7_SP[];
extern const s8 str_ATTACK_8_S[];
extern const s8 str_ATTACK_8_M[];
extern const s8 str_ATTACK_8_L[];
extern const s8 str_ATTACK_8_SP[];
extern const s8 str_ATTACK_9_S[];
extern const s8 str_ATTACK_9_M[];
extern const s8 str_ATTACK_9_L[];
extern const s8 str_ATTACK_9_SP[];
extern const s8 str_ATTACK_10_S[];
extern const s8 str_ATTACK_10_M[];
extern const s8 str_ATTACK_10_L[];
extern const s8 str_ATTACK_10_SP[];
extern const s8 str_ATTACK_11_S[];
extern const s8 str_ATTACK_11_M[];
extern const s8 str_ATTACK_11_L[];
extern const s8 str_ATTACK_11_SP[];
extern const s8 str_ATTACK_12_S[];
extern const s8 str_ATTACK_12_M[];
extern const s8 str_ATTACK_12_L[];
extern const s8 str_ATTACK_12_SP[];
extern const s8 str_ATTACK_13_S[];
extern const s8 str_ATTACK_13_M[];
extern const s8 str_ATTACK_13_L[];
extern const s8 str_ATTACK_13_SP[];
extern const s8 str_HANASARE[];
extern const s8 str_EFF01_CHAR[];
extern const s8 str_EFF13_CHAR[];
extern const s8 str_GILL_STAGE_OBJ[];
extern const s8 str_N_Y_1_OBJ[];
extern const s8 str_ONSEN_OBJ[];
extern const s8 str_CHAINA_1_OBJ[];
extern const s8 str_CHAINA_2_OBJ[];
extern const s8 str_ENGLAND_OBJ[];
extern const s8 str_ROCIA_OBJ[];
extern const s8 str_GERMANY_OBJ[];
extern const s8 str_FURUDERA_OBJ[];
extern const s8 str_AFRICA_1_OBJ[];
extern const s8 str_AFRICA_2_OBJ[];
extern const s8 str_BRAZIL_OBJ[];
extern const s8 str_SAN_FRANCISCO_2[];
extern const s8 str_SANPAURO[];
extern const s8 str_ETC_1[];
extern const s8 str_ETC_2[];
extern const s8 str_ETC_3[];
extern const s8 str_PLEF[];
extern const s8 str_ENDING_CHAR[];
extern const s8 str_APPEAR_JUNBI_1[];
extern const s8 str_APPEAR_JUNBI_2[];
extern const s8 str_APPEAR_JUNBI_3[];
extern const s8 str_APPEAR_JUNBI_4[];
extern const s8 str_APPEAR_JUNBI_5[];
extern const s8 str_APPEAR_JUNBI_6[];
extern const s8 str_APPEAR_JUNBI_7[];
extern const s8 str_APPEAR_JUNBI_8[];
extern const s8 str_APPEAR_1[];
extern const s8 str_APPEAR_2[];
extern const s8 str_APPEAR_3[];
extern const s8 str_APPEAR_4[];
extern const s8 str_APPEAR_5[];
extern const s8 str_APPEAR_6[];
extern const s8 str_APPEAR_7[];
extern const s8 str_APPEAR_8[];
extern const s8 str_SP_APPEAR_1[];
extern const s8 str_SP_APPEAR_2[];
extern const s8 str_SP_APPEAR_3[];
extern const s8 str_SP_APPEAR_4[];
extern const s8 str_SP_APPEAR_5[];
extern const s8 str_SP_APPEAR_6[];
extern const s8 str_SP_APPEAR_7[];
extern const s8 str_SP_APPEAR_8[];
extern const s8 str_ZANNEN_1[];
extern const s8 str_ZANNEN_2[];
extern const s8 str_ZANNEN_3[];
extern const s8 str_ZANNEN_4[];
extern const s8 str_ZANNEN_5[];
extern const s8 str_ZANNEN_6[];
extern const s8 str_ZANNEN_7[];
extern const s8 str_ZANNEN_8[];
extern const s8 str_WIN_1[];
extern const s8 str_WIN_2[];
extern const s8 str_WIN_3[];
extern const s8 str_WIN_4[];
extern const s8 str_WIN_5[];
extern const s8 str_WIN_6[];
extern const s8 str_WIN_7[];
extern const s8 str_WIN_8[];
extern const s8 str_SP_WIN_1[];
extern const s8 str_SP_WIN_2[];
extern const s8 str_SP_WIN_3[];
extern const s8 str_SP_WIN_4[];
extern const s8 str_SP_WIN_5[];
extern const s8 str_SP_WIN_6[];
extern const s8 str_SP_WIN_7[];
extern const s8 str_SP_WIN_8[];
extern const s8 str_JUDGMENT_WAIT[];
extern const s8 str_JUDGMENT_WIN[];
extern const s8 str_JUDGMENT_LOSE[];
extern const s8 str_WAIT[];
extern const s8 str_AFRICA_JUMP[];
extern const s8 str_AFRICA_LAND[];
extern const s8 str_SEAN_BALL_HIT[];
extern const s8 str_BONUS_WIN_1[];
extern const s8 str_BONUS_WIN_2[];
extern const s8 str_BONUS_WIN_3[];
extern const s8 str_KOC_IX_PT_Nix[];
extern const s8 str_KOC_IX_PT_Nix_n[];
extern const u32 eff19_char_table[];
extern const u32 eff86_char_table[];
extern const u32 stg00_char_table[];
extern const u32 stg01_char_table[];
extern const u32 stg02_char_table[];
extern const u32 stg04_char_table[];
extern const u32 stg06_char_table[];
extern const u32 stg07_char_table[];
extern const u32 stg12_char_table[];
extern const u32 effH3_char_table[];
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
extern const u32* dbg_pl_char_tbl[][9];

/* the code declares dbg_menu_str[15]; dbg_select_exit_str starts after its first 8 entries */
/* 02000F50 */
TM_STRING dbg_menu_str[8] = {
    { 13, 2, 2, str_OBJECT_TEST },
    { 10, 4, 2, str_BG_SELECT },
    { 10, 5, 2, str_OBJECT_LOOK },
    { 10, 6, 2, str_OBJECT_EDIT },
    { 10, 7, 2, str_OBJECT_EDIT_2 },
    { 10, 8, 2, str_HIT },
    { 10, 9, 2, str_ALL_CHARACTER },
    { 10, 10, 2, str_PARTS },
};
/* 02000FB0 */
TM_STRING dbg_select_exit_str[2] = {
    { 17, 3, 2, str_SELECT_UP_DOWN },
    { 17, 4, 2, str_EXIT_1P_2P_START },
};
/* 02000FC8 */
TM_STRING dbg_obj_info_str[10] = {
    { 1, 3, 2, str_PLAYER },
    { 1, 4, 2, str_ALL },
    { 1, 6, 2, str_MOTION },
    { 1, 8, 2, str_PATTERN },
    { 1, 9, 2, str_INTERRUT },
    { 1, 10, 2, str_CODE_H },
    { 1, 11, 2, str_FLIP },
    { 1, 12, 2, str_FLIP_ED },
    { 1, 13, 2, str_POS_X_H },
    { 1, 14, 2, str_POS_Y_H },
};
/* 02001040 */
TM_STRING dbg_obj_rel_str[3] = {
    { 1, 15, 2, str_REL_X_H },
    { 1, 16, 2, str_REL_Y_H },
    { 1, 17, 2, str_CURRENT },
};
/* 02001064 */
TM_STRING dbg_all_char_str[7] = {
    { 15, 1, 2, str_ALL_CHARACTER },
    { 1, 5, 2, str_H_n },
    { 1, 7, 2, str_H_n },
    { 4, 11, 2, str_GROUP },
    { 4, 12, 2, str_R_n },
    { 4, 13, 2, str_G },
    { 4, 14, 2, str_B },
};
/* 020010B8 */
TM_STRING dbg_edit_num_str[4] = {
    { 1, 18, 2, str_EDIT_NUM },
    { 1, 19, 2, str_NUM_END },
    { 1, 20, 2, str_EDIT_INT },
    { 1, 21, 2, str_INT_END },
};
/* 020010E8 */
TM_STRING dbg_parts_info_str[17] = {
    { 1, 3, 2, str_PLAYER },
    { 1, 4, 2, str_ALL },
    { 1, 6, 2, str_MOTION },
    { 1, 8, 2, str_PATTERN },
    { 1, 9, 2, str_INTERRUT },
    { 1, 10, 2, str_CODE_H },
    { 1, 11, 2, str_FLIP },
    { 1, 12, 2, str_FLIP_ED },
    { 1, 13, 2, str_CURRENT_n },
    { 1, 14, 2, str_PARTS_X_H },
    { 1, 15, 2, str_PARTS_Y_H },
    { 1, 16, 2, str_PARTS_FL },
    { 1, 17, 2, str_OLC_IX },
    { 1, 18, 2, str_IX_1 },
    { 1, 19, 2, str_IX_2 },
    { 1, 20, 2, str_IX_3 },
    { 1, 21, 2, str_IX_4 },
};
/* 020011B4 */
TM_STRING dbg_rec_menu_str[3] = {
    { 27, 3, 6, str_DELETE_ALL_SH4 },
    { 27, 4, 6, str_1DATA_SH5 },
    { 27, 5, 6, str_CANCEL_SH6 },
};
/* 020011D8 */
TM_STRING dbg_rec_clear_str[3] = {
    { 27, 3, 6, str_blank_line },
    { 27, 4, 6, str_blank_line },
    { 27, 5, 6, str_empty },
};
/* 020011FC */
TM_STRING dbg_rec_nodata_str[2] = {
    { 27, 3, 6, str_NO_EDIT },
    { 27, 4, 6, str_DATA_NOTHING },
};
/* 02001214 */
TM_STRING dbg_hit_size_str[16] = {
    { 1, 15, 2, str_REVISE_X_H },
    { 1, 16, 2, str_SIZE_X_H },
    { 1, 17, 2, str_REVISE_Y_H },
    { 1, 18, 2, str_SIZE_Y_H },
    { 1, 20, 2, str_IX },
    { 1, 21, 2, str_CUR },
    { 10, 20, 2, str_BOD },
    { 10, 21, 2, str_HAN },
    { 10, 22, 2, str_CAT },
    { 10, 23, 2, str_CAU },
    { 10, 24, 2, str_AT1 },
    { 10, 25, 2, str_AT2 },
    { 10, 26, 2, str_HOS },
    { 15, 25, 2, str_KOC_IX_PT_Nix_n },
    { 15, 26, 2, str_KOC_IX_PT_Nix_n },
    { 15, 27, 2, str_KOC_IX_PT_Nix },
};
/* 020012D4 */
TM_STRING dbg_hit_part_str[13] = {
    { 36, 13, 2, str_HEAD },
    { 36, 14, 2, str_BREAST },
    { 36, 15, 2, str_TRUNK_1 },
    { 36, 16, 2, str_LEG },
    { 36, 17, 2, str_HAND_1 },
    { 36, 18, 2, str_HAND_2 },
    { 36, 19, 2, str_CATCH_n },
    { 36, 20, 2, str_CAUGHT_n },
    { 36, 21, 2, str_ATTACK_1 },
    { 36, 22, 2, str_ATTACK_2 },
    { 36, 23, 2, str_ATTACK_3 },
    { 36, 24, 2, str_ATTACK_4 },
    { 36, 25, 2, str_TRUNK_2 },
};
/* 02001370 */
TM_STRING dbg_cg_head_str[6] = {
    { 27, 3, 2, str_CG_CTR },
    { 27, 4, 2, str_CG_TYPE },
    { 27, 5, 2, str_CG_SE },
    { 27, 6, 2, str_CG_FLIP },
    { 27, 7, 2, str_CG_OLC_IX },
    { 27, 8, 2, str_CG_NUMBER },
};
/* 020013B8 */
TM_STRING dbg_cg_att_str[6] = {
    { 27, 10, 2, str_CG_ATT_IX },
    { 27, 11, 2, str_CG_HIT_IX },
    { 27, 12, 2, str_CG_EXTDAT },
    { 27, 13, 2, str_CG_CANCEL },
    { 27, 14, 2, str_CG_EFFECT },
    { 27, 15, 2, str_CG_EFTYPE },
};
/* 02001400 */
TM_STRING dbg_cg_rival_str[4] = {
    { 27, 16, 2, str_CG_RIVAL },
    { 27, 17, 2, str_CG_ADD_XY },
    { 27, 18, 2, str_CG_NIX },
    { 27, 19, 2, str_CG_STATUS },
};
/* 02001430 */
TM_STRING dbg_cgd_info_str[8] = {
    { 27, 2, 2, str_CGD_TYPE },
    { 27, 3, 2, str_PAT_ST },
    { 27, 4, 2, str_KIND_WAZA },
    { 27, 5, 2, str_HIT_RANGE },
    { 27, 6, 2, str_YOKE_TYPE },
    { 27, 7, 2, str_YOKE_PAT },
    { 27, 8, 2, str_SP_TECH },
    { 27, 9, 2, str_WCA_IX },
};
/* 02001490 */
TM_STRING dbg_att_data_str[21] = {
    { 27, 2, 2, str_ATT_IX },
    { 27, 3, 2, str_REACTION },
    { 27, 4, 2, str_MKH_IX },
    { 27, 5, 2, str_DIP },
    { 27, 6, 2, str_HISS },
    { 27, 7, 2, str_DIR },
    { 27, 8, 2, str_GUARD },
    { 27, 9, 2, str_POW },
    { 27, 10, 2, str_IMPACT },
    { 27, 11, 2, str_PIYO_n },
    { 27, 12, 2, str_NG_TYPE },
    { 27, 13, 2, str_HS_ME },
    { 27, 14, 2, str_HS_YOU },
    { 27, 15, 2, str_ZU_FLAG },
    { 27, 16, 2, str_ZOKUSEI },
    { 27, 17, 2, str_AT_LEVEL },
    { 27, 18, 2, str_ADD_ARTS },
    { 27, 19, 2, str_BUTT_TYPE },
    { 27, 20, 2, str_BUTT_PAT },
    { 27, 21, 2, str_DIR_ATT },
    { 27, 22, 2, str_VS_ID },
};
/* 0200158C */
TM_STRING dbg_hud_clr_str[26] = {
    { 27, 2, 2, str_blank_line_3 },
    { 27, 3, 2, str_blank_line_3 },
    { 27, 4, 2, str_blank_line_3 },
    { 27, 5, 2, str_blank_line_3 },
    { 27, 6, 2, str_blank_line_3 },
    { 27, 7, 2, str_blank_line_3 },
    { 27, 8, 2, str_blank_line_3 },
    { 27, 9, 2, str_blank_line_3 },
    { 27, 10, 2, str_blank_line_3 },
    { 27, 11, 2, str_blank_line_3 },
    { 27, 12, 2, str_blank_line_3 },
    { 27, 13, 2, str_blank_line_3 },
    { 27, 14, 2, str_blank_line_3 },
    { 27, 15, 2, str_blank_line_3 },
    { 27, 16, 2, str_blank_line_3 },
    { 27, 17, 2, str_blank_line_3 },
    { 27, 18, 2, str_blank_line_3 },
    { 27, 19, 2, str_blank_line_3 },
    { 27, 20, 2, str_blank_line_3 },
    { 27, 21, 2, str_blank_line_3 },
    { 27, 22, 2, str_blank_line_3 },
    { 27, 23, 2, str_blank_line_3 },
    { 27, 24, 2, str_blank_line_3 },
    { 27, 25, 2, str_blank_line_3 },
    { 27, 26, 2, str_blank_line_3 },
    { 27, 27, 2, str_empty_3 },
};
/* 020016C4 */
TM_STRING dbg_hud_clr_mid_str[6] = {
    { 27, 14, 2, str_blank_line_3 },
    { 27, 15, 2, str_blank_line_3 },
    { 27, 16, 2, str_blank_line_3 },
    { 27, 17, 2, str_blank_line_3 },
    { 27, 18, 2, str_blank_line_3 },
    { 27, 19, 2, str_blank_line_3 },
};
/* 0200170C */
TM_STRING dbg_hud_clr_low_str[9] = {
    { 27, 20, 2, str_blank_line_3 },
    { 27, 21, 2, str_blank_line_3 },
    { 27, 22, 2, str_blank_line_3 },
    { 27, 23, 2, str_blank_line_3 },
    { 27, 24, 2, str_blank_line_3 },
    { 27, 25, 2, str_blank_line_3 },
    { 27, 26, 2, str_blank_line_3 },
    { 27, 27, 2, str_empty_3 },
    { 27, 28, 2, str_empty_3 },
};
/* 02001778 */
TM_STRING dbg_hud_clr_bottom_str[3] = {
    { 5, 25, 2, str_blank_line_4 },
    { 5, 26, 2, str_blank_line_4 },
    { 5, 27, 2, str_empty_4 },
};
/* 0200179C */
TM_STRING dbg_cm_label_str[13] = {
    { 27, 2, 2, str_CMOA },
    { 27, 3, 2, str_CMSW },
    { 27, 4, 2, str_CMLP },
    { 27, 5, 2, str_CML2 },
    { 27, 6, 2, str_CMJA },
    { 27, 7, 2, str_CMJ2 },
    { 27, 8, 2, str_CMJ3 },
    { 27, 9, 2, str_CMJ4 },
    { 27, 10, 2, str_CMMS },
    { 27, 11, 2, str_CMMD },
    { 27, 12, 2, str_CMYD },
    { 27, 13, 2, str_CMCF },
    { 27, 14, 2, str_CMCR },
};
/* 02001838 */
TM_STRING dbg_cgd_type_str[5] = {
    { 37, 1, 0xA, str_WCA },
    { 37, 2, 0xA, str_CGD1 },
    { 37, 2, 0xA, str_CGD2 },
    { 37, 2, 0xA, str_CGD3 },
    { 37, 2, 0xA, str_empty_5 },
};
/* 02001874 */
TM_STRING dbg_pat_status_str[23] = {
    { 37, 3, 0xA, str_sl_00 },
    { 37, 3, 0xA, str_sl_10 },
    { 37, 3, 0xA, str_sl_12 },
    { 37, 3, 0xA, str_sl_20 },
    { 37, 3, 0xA, str_sl_22 },
    { 37, 3, 0xA, str_sl_30 },
    { 37, 3, 0xA, str_sl_32 },
    { 37, 3, 0xA, str_sl_40 },
    { 37, 3, 0xA, str_sl_42 },
    { 37, 3, 0xA, str_sl_44 },
    { 37, 3, 0xA, str_sl_50 },
    { 37, 3, 0xA, str_sl_52 },
    { 37, 3, 0xA, str_sl_54 },
    { 37, 3, 0xA, str_sl_60 },
    { 37, 3, 0xA, str_sl_62 },
    { 37, 3, 0xA, str_sl_64 },
    { 37, 3, 0xA, str_sl_70 },
    { 37, 3, 0xA, str_sl_80 },
    { 37, 3, 0xA, str_sl_82 },
    { 37, 3, 0xA, str_sl_90 },
    { 37, 3, 0xA, str_empty_6 },
    { 37, 3, 0xA, str_empty_6 },
    { 37, 3, 0xA, str_empty_6 },
};
/* 02001988 */
TM_STRING dbg_cg_group_str[90] = {
    { 37, 8, 0xA, str_BCP00 },
    { 37, 8, 0xA, str_BCP01 },
    { 37, 8, 0xA, str_BCP02 },
    { 37, 8, 0xA, str_BCP03 },
    { 37, 8, 0xA, str_BCP04 },
    { 37, 8, 0xA, str_BCP05 },
    { 37, 8, 0xA, str_BCP06 },
    { 37, 8, 0xA, str_BCP07 },
    { 37, 8, 0xA, str_BCP08 },
    { 37, 8, 0xA, str_BCP09 },
    { 37, 8, 0xA, str_BCP10 },
    { 37, 8, 0xA, str_BCP11 },
    { 37, 8, 0xA, str_BCP12 },
    { 37, 8, 0xA, str_BCP13 },
    { 37, 8, 0xA, str_BCP14 },
    { 37, 8, 0xA, str_BCP15 },
    { 37, 8, 0xA, str_BCP20 },
    { 37, 8, 0xA, str_BCP21 },
    { 37, 8, 0xA, str_BCP22 },
    { 37, 8, 0xA, str_BCP23 },
    { 37, 8, 0xA, str_BCP24 },
    { 37, 8, 0xA, str_BCP25 },
    { 37, 8, 0xA, str_BCP26 },
    { 37, 8, 0xA, str_BCP27 },
    { 37, 8, 0xA, str_BCP28 },
    { 37, 8, 0xA, str_BCP29 },
    { 37, 8, 0xA, str_BCP30 },
    { 37, 8, 0xA, str_BCP31 },
    { 37, 8, 0xA, str_BCP32 },
    { 37, 8, 0xA, str_BCP33 },
    { 37, 8, 0xA, str_BCP34 },
    { 37, 8, 0xA, str_BCP35 },
    { 37, 8, 0xA, str_BCP36 },
    { 37, 8, 0xA, str_BCP37 },
    { 37, 8, 0xA, str_BCP38 },
    { 37, 8, 0xA, str_BCP39 },
    { 37, 8, 0xA, str_BCP40 },
    { 37, 8, 0xA, str_BCP41 },
    { 37, 8, 0xA, str_BCP42 },
    { 37, 8, 0xA, str_BCP43 },
    { 37, 8, 0xA, str_BCP44 },
    { 37, 8, 0xA, str_BCP45 },
    { 37, 8, 0xA, str_BCP46 },
    { 37, 8, 0xA, str_BCP47 },
    { 37, 8, 0xA, str_BCP48 },
    { 37, 8, 0xA, str_BCP49 },
    { 37, 8, 0xA, str_BCP50 },
    { 37, 8, 0xA, str_BCP51 },
    { 37, 8, 0xA, str_BCP52 },
    { 37, 8, 0xA, str_BCP53 },
    { 37, 8, 0xA, str_BCP54 },
    { 37, 8, 0xA, str_BCP55 },
    { 37, 8, 0xA, str_BCP56 },
    { 37, 8, 0xA, str_BCP57 },
    { 37, 8, 0xA, str_BCP58 },
    { 37, 8, 0xA, str_BCP59 },
    { 37, 8, 0xA, str_BCP60 },
    { 37, 8, 0xA, str_BCP61 },
    { 37, 8, 0xA, str_BCP62 },
    { 37, 8, 0xA, str_BCP63 },
    { 37, 8, 0xA, str_BCP64 },
    { 37, 8, 0xA, str_BCP65 },
    { 37, 8, 0xA, str_BCP66 },
    { 37, 8, 0xA, str_BCP67 },
    { 37, 8, 0xA, str_BCP68 },
    { 37, 8, 0xA, str_BCP69 },
    { 37, 8, 0xA, str_BCP70 },
    { 37, 8, 0xA, str_BCP71 },
    { 37, 8, 0xA, str_BCP72 },
    { 37, 8, 0xA, str_BCP73 },
    { 37, 8, 0xA, str_BCP74 },
    { 37, 8, 0xA, str_BCP75 },
    { 37, 8, 0xA, str_BCP76 },
    { 37, 8, 0xA, str_BCP77 },
    { 37, 8, 0xA, str_BCP78 },
    { 37, 8, 0xA, str_BCP79 },
    { 37, 8, 0xA, str_BCP80 },
    { 37, 8, 0xA, str_BCP81 },
    { 37, 8, 0xA, str_BCP82 },
    { 37, 8, 0xA, str_BCP83 },
    { 37, 8, 0xA, str_BCP84 },
    { 37, 8, 0xA, str_BCP85 },
    { 37, 8, 0xA, str_empty_7 },
    { 37, 8, 0xA, str_empty_7 },
    { 37, 8, 0xA, str_empty_7 },
    { 37, 8, 0xA, str_empty_7 },
    { 37, 8, 0xA, str_empty_7 },
    { 37, 8, 0xA, str_empty_7 },
    { 37, 8, 0xA, str_empty_7 },
    { 37, 8, 0xA, str_empty_7 },
};
/* provisional name */
/* 02001DC0 */
TM_STRING dbg_preview_group_str[104] = {
    { 4, 5, 2, str_BCP00 },
    { 4, 5, 2, str_BCP01 },
    { 4, 5, 2, str_BCP02 },
    { 4, 5, 2, str_BCP03 },
    { 4, 5, 2, str_BCP04 },
    { 4, 5, 2, str_BCP05 },
    { 4, 5, 2, str_BCP06 },
    { 4, 5, 2, str_BCP07 },
    { 4, 5, 2, str_BCP08 },
    { 4, 5, 2, str_BCP09 },
    { 4, 5, 2, str_BCP10 },
    { 4, 5, 2, str_BCP11 },
    { 4, 5, 2, str_BCP12 },
    { 4, 5, 2, str_BCP13 },
    { 4, 5, 2, str_BCP14 },
    { 4, 5, 2, str_BCP15 },
    { 4, 5, 2, str_BCP20 },
    { 4, 5, 2, str_BCP21 },
    { 4, 5, 2, str_BCP22 },
    { 4, 5, 2, str_BCP23 },
    { 4, 5, 2, str_BCP24 },
    { 4, 5, 2, str_BCP25 },
    { 4, 5, 2, str_BCP26 },
    { 4, 5, 2, str_BCP27 },
    { 4, 5, 2, str_BCP28 },
    { 4, 5, 2, str_BCP29 },
    { 4, 5, 2, str_BCP30 },
    { 4, 5, 2, str_BCP31 },
    { 4, 5, 2, str_BCP32 },
    { 4, 5, 2, str_BCP33 },
    { 4, 5, 2, str_BCP34 },
    { 4, 5, 2, str_BCP35 },
    { 4, 5, 2, str_BCP36 },
    { 4, 5, 2, str_BCP37 },
    { 4, 5, 2, str_BCP38 },
    { 4, 5, 2, str_BCP39 },
    { 4, 5, 2, str_BCP40 },
    { 4, 5, 2, str_BCP41 },
    { 4, 5, 2, str_BCP42 },
    { 4, 5, 2, str_BCP43 },
    { 4, 5, 2, str_BCP44 },
    { 4, 5, 2, str_BCP45 },
    { 4, 5, 2, str_BCP46 },
    { 4, 5, 2, str_BCP47 },
    { 4, 5, 2, str_BCP48 },
    { 4, 5, 2, str_BCP49 },
    { 4, 5, 2, str_BCP50 },
    { 4, 5, 2, str_BCP51 },
    { 4, 5, 2, str_BCP52 },
    { 4, 5, 2, str_BCP53 },
    { 4, 5, 2, str_BCP54 },
    { 4, 5, 2, str_BCP55 },
    { 4, 5, 2, str_BCP56 },
    { 4, 5, 2, str_BCP57 },
    { 4, 5, 2, str_BCP58 },
    { 4, 5, 2, str_BCP59 },
    { 4, 5, 2, str_BCP60 },
    { 4, 5, 2, str_BCP61 },
    { 4, 5, 2, str_BCP62 },
    { 4, 5, 2, str_BCP63 },
    { 4, 5, 2, str_BCP64 },
    { 4, 5, 2, str_BCP65 },
    { 4, 5, 2, str_BCP66 },
    { 4, 5, 2, str_BCP67 },
    { 4, 5, 2, str_BCP68 },
    { 4, 5, 2, str_BCP69 },
    { 4, 5, 2, str_BCP70 },
    { 4, 5, 2, str_BCP71 },
    { 4, 5, 2, str_BCP72 },
    { 4, 5, 2, str_BCP73 },
    { 4, 5, 2, str_BCP74 },
    { 4, 5, 2, str_BCP75 },
    { 4, 5, 2, str_BCP76 },
    { 4, 5, 2, str_BCP77 },
    { 4, 5, 2, str_BCP78 },
    { 4, 5, 2, str_BCP79 },
    { 4, 5, 2, str_BCP80 },
    { 4, 5, 2, str_BCP81 },
    { 4, 5, 2, str_BCP82 },
    { 4, 5, 2, str_BCP83 },
    { 4, 5, 2, str_BCP84 },
    { 4, 5, 2, str_BCP85 },
    { 4, 5, 2, str_BCP86 },
    { 4, 5, 2, str_BCP87 },
    { 4, 5, 2, str_BCP88 },
    { 4, 5, 2, str_BCP89 },
    { 4, 5, 2, str_BCP90 },
    { 4, 5, 2, str_BCP91 },
    { 4, 5, 2, str_BCP92 },
    { 4, 5, 2, str_BCP93 },
    { 4, 5, 2, str_BCP94 },
    { 4, 5, 2, str_BCP95 },
    { 4, 5, 2, str_BCP96 },
    { 4, 5, 2, str_BCP97 },
    { 4, 5, 2, str_BCP98 },
    { 4, 5, 2, str_BCP99 },
    { 4, 5, 2, str_BCPA0 },
    { 4, 5, 2, str_BCPA1 },
    { 4, 5, 2, str_empty_7 },
    { 4, 5, 2, str_empty_7 },
    { 4, 5, 2, str_empty_7 },
    { 4, 5, 2, str_empty_7 },
    { 4, 5, 2, str_empty_7 },
    { 4, 5, 2, str_empty_7 },
};
/* provisional name */
/* 020022A0 */
TM_STRING dbg_edit_group_str[107] = {
    { 1, 25, 2, str_BCP00 },
    { 1, 25, 2, str_BCP01 },
    { 1, 25, 2, str_BCP02 },
    { 1, 25, 2, str_BCP03 },
    { 1, 25, 2, str_BCP04 },
    { 1, 25, 2, str_BCP05 },
    { 1, 25, 2, str_BCP06 },
    { 1, 25, 2, str_BCP07 },
    { 1, 25, 2, str_BCP08 },
    { 1, 25, 2, str_BCP09 },
    { 1, 25, 2, str_BCP10 },
    { 1, 25, 2, str_BCP11 },
    { 1, 25, 2, str_BCP12 },
    { 1, 25, 2, str_BCP13 },
    { 1, 25, 2, str_BCP14 },
    { 1, 25, 2, str_BCP15 },
    { 1, 25, 2, str_BCP20 },
    { 1, 25, 2, str_BCP21 },
    { 1, 25, 2, str_BCP22 },
    { 1, 25, 2, str_BCP23 },
    { 1, 25, 2, str_BCP24 },
    { 1, 25, 2, str_BCP25 },
    { 1, 25, 2, str_BCP26 },
    { 1, 25, 2, str_BCP27 },
    { 1, 25, 2, str_BCP28 },
    { 1, 25, 2, str_BCP29 },
    { 1, 25, 2, str_BCP30 },
    { 1, 25, 2, str_BCP31 },
    { 1, 25, 2, str_BCP32 },
    { 1, 25, 2, str_BCP33 },
    { 1, 25, 2, str_BCP34 },
    { 1, 25, 2, str_BCP35 },
    { 1, 25, 2, str_BCP36 },
    { 1, 25, 2, str_BCP37 },
    { 1, 25, 2, str_BCP38 },
    { 1, 25, 2, str_BCP39 },
    { 1, 25, 2, str_BCP40 },
    { 1, 25, 2, str_BCP41 },
    { 1, 25, 2, str_BCP42 },
    { 1, 25, 2, str_BCP43 },
    { 1, 25, 2, str_BCP44 },
    { 1, 25, 2, str_BCP45 },
    { 1, 25, 2, str_BCP46 },
    { 1, 25, 2, str_BCP47 },
    { 1, 25, 2, str_BCP48 },
    { 1, 25, 2, str_BCP49 },
    { 1, 25, 2, str_BCP50 },
    { 1, 25, 2, str_BCP51 },
    { 1, 25, 2, str_BCP52 },
    { 1, 25, 2, str_BCP53 },
    { 1, 25, 2, str_BCP54 },
    { 1, 25, 2, str_BCP55 },
    { 1, 25, 2, str_BCP56 },
    { 1, 25, 2, str_BCP57 },
    { 1, 25, 2, str_BCP58 },
    { 1, 25, 2, str_BCP59 },
    { 1, 25, 2, str_BCP60 },
    { 1, 25, 2, str_BCP61 },
    { 1, 25, 2, str_BCP62 },
    { 1, 25, 2, str_BCP63 },
    { 1, 25, 2, str_BCP64 },
    { 1, 25, 2, str_BCP65 },
    { 1, 25, 2, str_BCP66 },
    { 1, 25, 2, str_BCP67 },
    { 1, 25, 2, str_BCP68 },
    { 1, 25, 2, str_BCP69 },
    { 1, 25, 2, str_BCP70 },
    { 1, 25, 2, str_BCP71 },
    { 1, 25, 2, str_BCP72 },
    { 1, 25, 2, str_BCP73 },
    { 1, 25, 2, str_BCP74 },
    { 1, 25, 2, str_BCP75 },
    { 1, 25, 2, str_BCP76 },
    { 1, 25, 2, str_BCP77 },
    { 1, 25, 2, str_BCP78 },
    { 1, 25, 2, str_BCP79 },
    { 1, 25, 2, str_BCP80 },
    { 1, 25, 2, str_BCP81 },
    { 1, 25, 2, str_BCP82 },
    { 1, 25, 2, str_BCP83 },
    { 1, 25, 2, str_BCP84 },
    { 1, 25, 2, str_BCP85 },
    { 1, 25, 2, str_BCP86 },
    { 1, 25, 2, str_BCP87 },
    { 1, 25, 2, str_BCP88 },
    { 1, 25, 2, str_BCP89 },
    { 1, 25, 2, str_BCP90 },
    { 1, 25, 2, str_BCP91 },
    { 1, 25, 2, str_BCP92 },
    { 1, 25, 2, str_BCP93 },
    { 1, 25, 2, str_BCP94 },
    { 1, 25, 2, str_BCP95 },
    { 1, 25, 2, str_BCP96 },
    { 1, 25, 2, str_BCP97 },
    { 1, 25, 2, str_BCP98 },
    { 1, 25, 2, str_BCP99 },
    { 1, 25, 2, str_BCPA0 },
    { 1, 25, 2, str_BCPA1 },
    { 1, 25, 2, str_empty_7 },
    { 1, 25, 2, str_empty_7 },
    { 1, 25, 2, str_empty_7 },
    { 1, 25, 2, str_empty_7 },
    { 1, 25, 2, str_empty_7 },
    { 1, 25, 2, str_empty_7 },
    { 1, 25, 2, str_empty_7 },
    { 1, 25, 2, str_empty_7 },
    { 1, 25, 2, str_empty_7 },
};
/* 020027A4 */
TM_STRING dbg_extdat_str[3] = {
    { 37, 12, 0xA, str_Pa },
    { 37, 12, 0xA, str_PA },
    { 37, 12, 0xA, str_PB },
};
/* 020027C8 */
TM_STRING dbg_eftype_names[9] = {
    { 37, 15, 0xA, str_MLN },
    { 37, 15, 0xA, str_MLU },
    { 37, 15, 0xA, str_MLD },
    { 37, 15, 0xA, str_MLF },
    { 37, 15, 0xA, str_MLF },
    { 37, 15, 0xA, str_MLR },
    { 37, 15, 0xA, str_MLR },
    { 37, 15, 0xA, str_MLR },
    { 37, 15, 0xA, str_M },
};
/* 02002834 */
TM_STRING dbg_eftype_s_str[6] = {
    { 40, 15, 0xA, str_S1 },
    { 40, 15, 0xA, str_S2 },
    { 40, 15, 0xA, str_S3 },
    { 40, 15, 0xA, str_S4 },
    { 40, 15, 0xA, str_S5 },
    { 40, 15, 0xA, str_S6 },
};
/* 0200287C */
TM_STRING dbg_eftype_usemj_str[8] = {
    { 42, 15, 0xA, str_empty_7 },
    { 42, 15, 0xA, str_USEMJ },
    { 37, 24, 0xA, str_BASE },
    { 37, 24, 0xA, str_BEFORE },
    { 37, 24, 0xA, str_BACK },
    { 37, 24, 0xA, str_empty_7 },
    { 37, 24, 0xA, str_empty_7 },
    { 37, 24, 0xA, str_empty_7 },
};
/* 020028DC */
TM_STRING dbg_cancel_on_str[8] = {
    { 44, 13, 0xA, str_H },
    { 43, 13, 0xA, str_D },
    { 42, 13, 0xA, str_A },
    { 41, 13, 0xA, str_M_2 },
    { 40, 13, 0xA, str_R },
    { 39, 13, 0xA, str_C },
    { 38, 13, 0xA, str_S },
    { 37, 13, 0xA, str_S },
};
/* 0200293C */
TM_STRING dbg_cancel_off_str[24] = {
    { 44, 13, 0xA, str_h },
    { 43, 13, 0xA, str_d },
    { 42, 13, 0xA, str_a },
    { 41, 13, 0xA, str_m },
    { 40, 13, 0xA, str_r },
    { 39, 13, 0xA, str_c },
    { 38, 13, 0xA, str_s },
    { 37, 13, 0xA, str_s },
    { 37, 17, 0xA, str_H },
    { 38, 17, 0xA, str_D },
    { 39, 17, 0xA, str_A },
    { 40, 17, 0xA, str_M_2 },
    { 41, 17, 0xA, str_R },
    { 42, 17, 0xA, str_C },
    { 43, 17, 0xA, str_S },
    { 44, 17, 0xA, str_S },
    { 37, 17, 0xA, str_h_2 },
    { 38, 17, 0xA, str_d_2 },
    { 39, 17, 0xA, str_a_2 },
    { 40, 17, 0xA, str_m_2 },
    { 41, 17, 0xA, str_r_2 },
    { 42, 17, 0xA, str_c_2 },
    { 43, 17, 0xA, str_s_2 },
    { 44, 17, 0xA, str_s_2 },
};
/* 02002A5C */
TM_STRING dbg_koc_cmlp_str[11] = {
    { 12, 25, 0xA, str_NM },
    { 12, 25, 0xA, str_DM },
    { 12, 25, 0xA, str_CA },
    { 12, 25, 0xA, str_CU },
    { 12, 25, 0xA, str_AT },
    { 12, 25, 0xA, str_BT },
    { 12, 25, 0xA, str_EX },
    { 12, 25, 0xA, str_SA },
    { 32, 25, 0xA, str_CB },
    { 32, 25, 0xA, str_empty_8 },
    { 32, 25, 0xA, str_empty_8 },
};
/* 02002AE0 */
TM_STRING dbg_koc_cml2_str[11] = {
    { 12, 26, 0xA, str_NM },
    { 12, 26, 0xA, str_DM },
    { 12, 26, 0xA, str_CA },
    { 12, 26, 0xA, str_CU },
    { 12, 26, 0xA, str_AT },
    { 12, 26, 0xA, str_BT },
    { 12, 26, 0xA, str_EX },
    { 12, 26, 0xA, str_SA },
    { 32, 26, 0xA, str_CB },
    { 32, 26, 0xA, str_empty_8 },
    { 32, 26, 0xA, str_empty_8 },
};
/* 02002B64 */
TM_STRING dbg_koc_cmsw_str[11] = {
    { 32, 25, 0xA, str_NM },
    { 32, 25, 0xA, str_DM },
    { 32, 25, 0xA, str_CA },
    { 32, 25, 0xA, str_CU },
    { 32, 25, 0xA, str_AT },
    { 32, 25, 0xA, str_SA },
    { 32, 25, 0xA, str_BT },
    { 32, 25, 0xA, str_EX },
    { 32, 25, 0xA, str_CB },
    { 32, 25, 0xA, str_empty_8 },
    { 32, 25, 0xA, str_empty_8 },
};
/* 02002BE8 */
TM_STRING dbg_koc_cmja_str[11] = {
    { 32, 26, 0xA, str_NM },
    { 32, 26, 0xA, str_DM },
    { 32, 26, 0xA, str_CA },
    { 32, 26, 0xA, str_CU },
    { 32, 26, 0xA, str_AT },
    { 32, 26, 0xA, str_SA },
    { 32, 26, 0xA, str_BT },
    { 32, 26, 0xA, str_EX },
    { 32, 26, 0xA, str_CB },
    { 32, 26, 0xA, str_empty_8 },
    { 32, 26, 0xA, str_empty_8 },
};
/* 02002C6C */
TM_STRING dbg_koc_cmoa_str[9] = {
    { 32, 27, 0xA, str_NM },
    { 32, 27, 0xA, str_DM },
    { 32, 27, 0xA, str_CA },
    { 32, 27, 0xA, str_CU },
    { 32, 27, 0xA, str_AT },
    { 32, 27, 0xA, str_SA },
    { 32, 27, 0xA, str_BT },
    { 32, 27, 0xA, str_EX },
    { 32, 27, 0xA, str_CB },
};
/* 02002CD8 */
TM_STRING dbg_koc_str[9] = {
    { 32, 2, 2, str_NM },
    { 32, 2, 2, str_DM },
    { 32, 2, 2, str_CA },
    { 32, 2, 2, str_CU },
    { 32, 2, 2, str_AT },
    { 32, 2, 2, str_SA },
    { 32, 2, 2, str_BT },
    { 32, 2, 2, str_EX },
    { 32, 2, 2, str_CB },
};
/* 02002D44 */
TM_STRING dbg_waza_kind_str[8] = {
    { 37, 4, 0xA, str_nmA },
    { 37, 4, 0xA, str_hsA },
    { 37, 4, 0xA, str_nmC },
    { 37, 4, 0xA, str_hsC },
    { 37, 4, 0xA, str_saA },
    { 37, 4, 0xA, str_saC },
    { 37, 4, 0xA, str_paA },
    { 37, 4, 0xA, str_huA },
};
/* 02002DA4 */
TM_STRING dbg_bg_name_str[18] = {
    { 2, 3, 2, str_BLANK },
    { 2, 3, 2, str_FLASH },
    { 2, 3, 2, str_GILL },
    { 2, 3, 2, str_N_Y },
    { 2, 3, 2, str_JAPAN_2 },
    { 2, 3, 2, str_CHAINA_1 },
    { 2, 3, 2, str_ENGLAND },
    { 2, 3, 2, str_RUSSIA },
    { 2, 3, 2, str_GERMANY },
    { 2, 3, 2, str_FURUDERA },
    { 2, 3, 2, str_AFRICA_1 },
    { 2, 3, 2, str_AFRICA_2 },
    { 2, 3, 2, str_BRAZIL },
    { 2, 3, 2, str_CHAINA_2 },
    { 2, 3, 2, str_SAN_FRANCISCO },
    { 2, 3, 2, str_SAO_PAULO },
    { 2, 3, 2, str_URIEN },
    { 2, 3, 2, str_KEIKOKU },
};
/* 02002E7C */
TM_STRING dbg_char_name_str[17] = {
    { 11, 3, 2, str_GILL_2 },
    { 11, 3, 2, str_ALEX },
    { 11, 3, 2, str_RYU },
    { 11, 3, 2, str_YUN },
    { 11, 3, 2, str_DUDLEY },
    { 11, 3, 2, str_NECRO },
    { 11, 3, 2, str_HUGO },
    { 11, 3, 2, str_IBUKI },
    { 11, 3, 2, str_ELENA },
    { 11, 3, 2, str_ORO },
    { 11, 3, 2, str_YANG },
    { 11, 3, 2, str_KEN },
    { 11, 3, 2, str_SEAN },
    { 11, 3, 2, str_URIEN_2 },
    { 11, 3, 2, str_GOUKI1 },
    { 11, 3, 2, str_GOUKI2 },
    { 11, 3, 2, str_ETC_4 },
};
/* 02002F48 */
TM_STRING dbg_act_kind_str[1061] = {
    { 3, 5, 4, str_NORMAL },
    { 3, 5, 4, str_DAMAGE },
    { 3, 5, 4, str_CATCH },
    { 3, 5, 4, str_CAUGHT },
    { 3, 5, 4, str_ATTACK },
    { 3, 5, 4, str_SP_AT },
    { 3, 5, 4, str_BUTTOBI },
    { 3, 5, 4, str_UNION },
    { 3, 5, 4, str_ETC },
    { 3, 5, 4, str_ETC },
    { 3, 5, 4, str_EFFECT },
    { 3, 5, 4, str_empty_9 },
    { 3, 7, 4, str_KAMAE },
    { 3, 7, 4, str_HURIMUKI },
    { 3, 7, 4, str_FRONT_WALK },
    { 3, 7, 4, str_BACK_WALK },
    { 3, 7, 4, str_DASH_HUMIKOMI },
    { 3, 7, 4, str_DASH_TOBINOKI },
    { 3, 7, 4, str_KAGAMU },
    { 3, 7, 4, str_KAGAMI_KAMAE },
    { 3, 7, 4, str_KAGAMI_TURN },
    { 3, 7, 4, str_KAGAMI_F_WALK },
    { 3, 7, 4, str_KAGAMI_B_WALK },
    { 3, 7, 4, str_STAND_UP },
    { 3, 7, 4, str_JUMP_JUNBI },
    { 3, 7, 4, str_SP_JUMP_JUNBI },
    { 3, 7, 4, str_JUMP_FRONT },
    { 3, 7, 4, str_JUMP_VERTICAL },
    { 3, 7, 4, str_JUMP_BACK },
    { 3, 7, 4, str_S_JUMP_FRONT },
    { 3, 7, 4, str_S_JUMP_V },
    { 3, 7, 4, str_S_JUMP_BACK },
    { 3, 7, 4, str_SP_JUMP_FRONT },
    { 3, 7, 4, str_SP_JUMP_V },
    { 3, 7, 4, str_SP_JUMP_BACK },
    { 3, 7, 4, str_WALK_END },
    { 3, 7, 4, str_PARING_HEAD },
    { 3, 7, 4, str_PARING_UP },
    { 3, 7, 4, str_PARING_DOWN },
    { 3, 7, 4, str_PARING_AIR_F },
    { 3, 7, 4, str_PARING_AIR_B },
    { 3, 7, 4, str_GUARD_HEAD },
    { 3, 7, 4, str_GUARD_UP },
    { 3, 7, 4, str_GUARD_DOWN },
    { 3, 7, 4, str_GUARD_AIR },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_P_BREAK_ZUJOU },
    { 3, 7, 4, str_P_BREAK_UP },
    { 3, 7, 4, str_P_BREAK_DOWN },
    { 3, 7, 4, str_P_BREAK_AIR_F },
    { 3, 7, 4, str_P_BREAK_AIR_R },
    { 3, 7, 4, str_TUKAMIHAZUSI },
    { 3, 7, 4, str_TUKAMIHAZUSARE },
    { 3, 7, 4, str_TUKAMIHAZUSI },
    { 3, 7, 4, str_TUKAMIHAZUSARE },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_GUARD_HEAD_2 },
    { 3, 7, 4, str_GUARD_UP_2 },
    { 3, 7, 4, str_GUARD_DOWN_2 },
    { 3, 7, 4, str_GUARD_AIR_2 },
    { 3, 7, 4, str_HUSHIN_HEAD },
    { 3, 7, 4, str_HUSHIN_UP },
    { 3, 7, 4, str_HUSHIN_DOWN },
    { 3, 7, 4, str_HUSHIN_AIR },
    { 3, 7, 4, str_FACE_S },
    { 3, 7, 4, str_FACE_M },
    { 3, 7, 4, str_FACE_L },
    { 3, 7, 4, str_FACE_SP },
    { 3, 7, 4, str_FOOK_OKU_S },
    { 3, 7, 4, str_FOOK_OKU_M },
    { 3, 7, 4, str_FOOK_OKU_L },
    { 3, 7, 4, str_FOOK_OKU_SP },
    { 3, 7, 4, str_FOOK_TEMAE_S },
    { 3, 7, 4, str_FOOK_TEMAE_M },
    { 3, 7, 4, str_FOOK_TEMAE_L },
    { 3, 7, 4, str_FOOK_TEMAE_SP },
    { 3, 7, 4, str_UPPER_S },
    { 3, 7, 4, str_UPPER_M },
    { 3, 7, 4, str_UPPER_L },
    { 3, 7, 4, str_UPPER_SP },
    { 3, 7, 4, str_NOUTEN_S },
    { 3, 7, 4, str_NOUTEN_M },
    { 3, 7, 4, str_NOUTEN_L },
    { 3, 7, 4, str_NOUTEN_SP },
    { 3, 7, 4, str_BODY_BROW_S },
    { 3, 7, 4, str_BODY_BROW_M },
    { 3, 7, 4, str_BODY_BROW_L },
    { 3, 7, 4, str_BODY_BROW_SP },
    { 3, 7, 4, str_BODY_UPPER_S },
    { 3, 7, 4, str_BODY_UPPER_M },
    { 3, 7, 4, str_BODY_UPPER_L },
    { 3, 7, 4, str_BODY_UPPER_SP },
    { 3, 7, 4, str_TATAKI_S },
    { 3, 7, 4, str_TATAKI_M },
    { 3, 7, 4, str_TATAKI_L },
    { 3, 7, 4, str_TATAKI_SP },
    { 3, 7, 4, str_TATAKI_V_S },
    { 3, 7, 4, str_TATAKI_V_M },
    { 3, 7, 4, str_TATAKI_V_L },
    { 3, 7, 4, str_TATAKI_V_SP },
    { 3, 7, 4, str_NOBASITA_TE_S },
    { 3, 7, 4, str_NOBASITA_TE_M },
    { 3, 7, 4, str_NOBASITA_TE_L },
    { 3, 7, 4, str_NOBASITA_TE_SP },
    { 3, 7, 4, str_KAGAMI_S },
    { 3, 7, 4, str_KAGAMI_M },
    { 3, 7, 4, str_KAGAMI_L },
    { 3, 7, 4, str_KAGAMI_SP },
    { 3, 7, 4, str_KGM_TATAKI_S },
    { 3, 7, 4, str_KGM_TATAKI_M },
    { 3, 7, 4, str_KGM_TATAKI_L },
    { 3, 7, 4, str_KGM_TATAKI_SP },
    { 3, 7, 4, str_KGM_TTKI_V_S },
    { 3, 7, 4, str_KGM_TTKI_V_M },
    { 3, 7, 4, str_KGM_TTKI_V_L },
    { 3, 7, 4, str_KGM_TTKI_V_SP },
    { 3, 7, 4, str_NEKOROBI_S },
    { 3, 7, 4, str_NEKOROBI_M },
    { 3, 7, 4, str_NEKOROBI_L },
    { 3, 7, 4, str_NEKOROBI_SP },
    { 3, 7, 4, str_OKIAGARI },
    { 3, 7, 4, str_OKIAGARI_F },
    { 3, 7, 4, str_OKIAGARI_B },
    { 3, 7, 4, str_LOSE_NO_STAND },
    { 3, 7, 4, str_LOSE_SONABA },
    { 3, 7, 4, str_LOSE_KAGAMI },
    { 3, 7, 4, str_PIYO },
    { 3, 7, 4, str_UKEMI_MOVE_F },
    { 3, 7, 4, str_UKEMI_MOVE_R },
    { 3, 7, 4, str_SHIMEOTASARE },
    { 3, 7, 4, str_TATI_TOUKETU_S },
    { 3, 7, 4, str_TATI_TOUKETU_M },
    { 3, 7, 4, str_TATI_TOUKETU_L },
    { 3, 7, 4, str_TATI_TOUKETU_P },
    { 3, 7, 4, str_KGM_TOUKETU_S },
    { 3, 7, 4, str_KGM_TOUKETU_M },
    { 3, 7, 4, str_KGM_TOUKETU_L },
    { 3, 7, 4, str_KGM_TOUKETU_P },
    { 3, 7, 4, str_TATI_DENGEKI_S },
    { 3, 7, 4, str_TATI_DENGEKI_M },
    { 3, 7, 4, str_TATI_DENGEKI_L },
    { 3, 7, 4, str_TATI_DENGEKI_P },
    { 3, 7, 4, str_KGM_DENGEKI_S },
    { 3, 7, 4, str_KGM_DENGEKI_M },
    { 3, 7, 4, str_KGM_DENGEKI_L },
    { 3, 7, 4, str_KGM_DENGEKI_P },
    { 3, 7, 4, str_OKIAGARI_FRONT },
    { 3, 7, 4, str_OKIAGARI_REAR },
    { 3, 7, 4, str_TATI_MOE_S },
    { 3, 7, 4, str_TATI_MOE_M },
    { 3, 7, 4, str_TATI_MOE_L },
    { 3, 7, 4, str_TATI_MOE_SP },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_AIR_S },
    { 3, 7, 4, str_AIR_M },
    { 3, 7, 4, str_AIR_L },
    { 3, 7, 4, str_AIR_SP },
    { 3, 7, 4, str_ASHIBARAI_A },
    { 3, 7, 4, str_ASHIBARAI_B },
    { 3, 7, 4, str_ASHIBARAI_C },
    { 3, 7, 4, str_ASHIBARAI_D },
    { 3, 7, 4, str_TUNNOMERI_A },
    { 3, 7, 4, str_TUNNOMERI_B },
    { 3, 7, 4, str_TUNNOMERI_C },
    { 3, 7, 4, str_TUNNOMERI_D },
    { 3, 7, 4, str_NOKEZORI_A },
    { 3, 7, 4, str_NOKEZORI_B },
    { 3, 7, 4, str_NOKEZORI_C },
    { 3, 7, 4, str_NOKEZORI_D },
    { 3, 7, 4, str_KUNOJI_A },
    { 3, 7, 4, str_KUNOJI_B },
    { 3, 7, 4, str_KUNOJI_C },
    { 3, 7, 4, str_KUNOJI_D },
    { 3, 7, 4, str_KIRIMOMI_A },
    { 3, 7, 4, str_KIRIMOMI_B },
    { 3, 7, 4, str_KIRIMOMI_C },
    { 3, 7, 4, str_KIRIMOMI_D },
    { 3, 7, 4, str_UPPER_A },
    { 3, 7, 4, str_UPPER_B },
    { 3, 7, 4, str_UPPER_C },
    { 3, 7, 4, str_UPPER_D },
    { 3, 7, 4, str_BODY_UPPER_A },
    { 3, 7, 4, str_BODY_UPPER_B },
    { 3, 7, 4, str_BODY_UPPER_C },
    { 3, 7, 4, str_BODY_UPPER_D },
    { 3, 7, 4, str_NM_BUTTOBI_A },
    { 3, 7, 4, str_NM_BUTTOBI_B },
    { 3, 7, 4, str_NM_BUTTOBI_C },
    { 3, 7, 4, str_NM_BUTTOBI_D },
    { 3, 7, 4, str_TATAKI_AIR_A },
    { 3, 7, 4, str_TATAKI_AIR_B },
    { 3, 7, 4, str_TATAKI_AIR_C },
    { 3, 7, 4, str_TATAKI_AIR_D },
    { 3, 7, 4, str_TTKI_V_AIR_A },
    { 3, 7, 4, str_TTKI_V_AIR_B },
    { 3, 7, 4, str_TTKI_V_AIR_C },
    { 3, 7, 4, str_TTKI_V_AIR_D },
    { 3, 7, 4, str_HUMI_ASIB_A },
    { 3, 7, 4, str_HUMI_ASIB_B },
    { 3, 7, 4, str_HUMI_ASIB_C },
    { 3, 7, 4, str_HUMI_ASIB_D },
    { 3, 7, 4, str_FACE_A },
    { 3, 7, 4, str_FACE_B },
    { 3, 7, 4, str_FACE_C },
    { 3, 7, 4, str_FACE_D },
    { 3, 7, 4, str_ASIBRI_MAKE_A },
    { 3, 7, 4, str_ASIBRI_MAKE_B },
    { 3, 7, 4, str_ASIBRI_MAKE_C },
    { 3, 7, 4, str_ASIBRI_MAKE_D },
    { 3, 7, 4, str_ASIB_TN_MAKE_A },
    { 3, 7, 4, str_ASIB_TN_MAKE_B },
    { 3, 7, 4, str_ASIB_TN_MAKE_C },
    { 3, 7, 4, str_ASIB_TN_MAKE_D },
    { 3, 7, 4, str_DENKI_A },
    { 3, 7, 4, str_DENKI_B },
    { 3, 7, 4, str_DENKI_C },
    { 3, 7, 4, str_DENKI_D },
    { 3, 7, 4, str_KUNOJI_NOKE_A },
    { 3, 7, 4, str_KUNOJI_NOKE_B },
    { 3, 7, 4, str_KUNOJI_NOKE_C },
    { 3, 7, 4, str_KUNOJI_NOKE_D },
    { 3, 7, 4, str_SINSYOURYU_A },
    { 3, 7, 4, str_SINSYOURYU_B },
    { 3, 7, 4, str_SINSYOURYU_C },
    { 3, 7, 4, str_SINSYOURYU_D },
    { 3, 7, 4, str_HANEAGARI_A },
    { 3, 7, 4, str_HANEAGARI_B },
    { 3, 7, 4, str_HANEAGARI_C },
    { 3, 7, 4, str_HANEAGARI_D },
    { 3, 7, 4, str_TOUKETSU_A },
    { 3, 7, 4, str_TOUKETSU_B },
    { 3, 7, 4, str_TOUKETSU_C },
    { 3, 7, 4, str_TOUKETSU_D },
    { 3, 7, 4, str_BODY_SLAM_A },
    { 3, 7, 4, str_BODY_SLAM_B },
    { 3, 7, 4, str_BODY_SLAM_C },
    { 3, 7, 4, str_BODY_SLAM_D },
    { 3, 7, 4, str_IPPONZEOI_A },
    { 3, 7, 4, str_IPPONZEOI_B },
    { 3, 7, 4, str_IPPONZEOI_C },
    { 3, 7, 4, str_IPPONZEOI_D },
    { 3, 7, 4, str_TOMOE_RYU_A },
    { 3, 7, 4, str_TOMOE_RYU_B },
    { 3, 7, 4, str_TOMOE_RYU_C },
    { 3, 7, 4, str_TOMOE_RYU_D },
    { 3, 7, 4, str_MONKEY_FLIP_A },
    { 3, 7, 4, str_MONKEY_FLIP_B },
    { 3, 7, 4, str_MONKEY_FLIP_C },
    { 3, 7, 4, str_MONKEY_FLIP_D },
    { 3, 7, 4, str_TOMOE_ORO_A },
    { 3, 7, 4, str_TOMOE_ORO_B },
    { 3, 7, 4, str_TOMOE_ORO_C },
    { 3, 7, 4, str_TOMOE_ORO_D },
    { 3, 7, 4, str_SNAKE_FANG_A },
    { 3, 7, 4, str_SNAKE_FANG_B },
    { 3, 7, 4, str_SNAKE_FANG_C },
    { 3, 7, 4, str_SNAKE_FANG_D },
    { 3, 7, 4, str_FLANKEN_S_A },
    { 3, 7, 4, str_FLANKEN_S_B },
    { 3, 7, 4, str_FLANKEN_S_C },
    { 3, 7, 4, str_FLANKEN_S_D },
    { 3, 7, 4, str_KISHINRIKI_A },
    { 3, 7, 4, str_KISHINRIKI_B },
    { 3, 7, 4, str_KISHINRIKI_C },
    { 3, 7, 4, str_KISHINRIKI_D },
    { 3, 7, 4, str_SPLASH_M_A },
    { 3, 7, 4, str_SPLASH_M_B },
    { 3, 7, 4, str_SPLASH_M_C },
    { 3, 7, 4, str_SPLASH_M_D },
    { 3, 7, 4, str_HARAIGOSHI_A },
    { 3, 7, 4, str_HARAIGOSHI_B },
    { 3, 7, 4, str_HARAIGOSHI_C },
    { 3, 7, 4, str_HARAIGOSHI_D },
    { 3, 7, 4, str_ALEX_B_D_A },
    { 3, 7, 4, str_ALEX_B_D_B },
    { 3, 7, 4, str_ALEX_B_D_C },
    { 3, 7, 4, str_ALEX_B_D_D },
    { 3, 7, 4, str_GILL_A },
    { 3, 7, 4, str_GILL_B },
    { 3, 7, 4, str_GILL_C },
    { 3, 7, 4, str_GILL_D },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_CATCH_1 },
    { 3, 7, 4, str_CATCH_2 },
    { 3, 7, 4, str_CATCH_3 },
    { 3, 7, 4, str_CATCH_4 },
    { 3, 7, 4, str_CATCH_5 },
    { 3, 7, 4, str_CATCH_6 },
    { 3, 7, 4, str_CATCH_7 },
    { 3, 7, 4, str_CATCH_8 },
    { 3, 7, 4, str_CATCH_9 },
    { 3, 7, 4, str_CATCH_10 },
    { 3, 7, 4, str_CATCH_11 },
    { 3, 7, 4, str_CATCH_12 },
    { 3, 7, 4, str_CATCH_13 },
    { 3, 7, 4, str_CATCH_14 },
    { 3, 7, 4, str_CATCH_15 },
    { 3, 7, 4, str_CATCH_16 },
    { 3, 7, 4, str_CATCH_17 },
    { 3, 7, 4, str_CATCH_18 },
    { 3, 7, 4, str_CATCH_19 },
    { 3, 7, 4, str_CATCH_20 },
    { 3, 7, 4, str_CATCH_21 },
    { 3, 7, 4, str_CATCH_22 },
    { 3, 7, 4, str_CATCH_23 },
    { 3, 7, 4, str_CATCH_24 },
    { 3, 7, 4, str_CATCH_25 },
    { 3, 7, 4, str_CATCH_26 },
    { 3, 7, 4, str_CATCH_27 },
    { 3, 7, 4, str_CATCH_28 },
    { 3, 7, 4, str_CATCH_29 },
    { 3, 7, 4, str_CATCH_30 },
    { 3, 7, 4, str_CATCH_31 },
    { 3, 7, 4, str_CATCH_32 },
    { 3, 7, 4, str_CATCH_33 },
    { 3, 7, 4, str_CATCH_34 },
    { 3, 7, 4, str_CATCH_35 },
    { 3, 7, 4, str_CATCH_36 },
    { 3, 7, 4, str_CATCH_37 },
    { 3, 7, 4, str_CATCH_38 },
    { 3, 7, 4, str_CATCH_39 },
    { 3, 7, 4, str_CATCH_40 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_ALEX_ZUTUKI },
    { 3, 7, 4, str_ALEX_BODY_S },
    { 3, 7, 4, str_ALEX_BACK_D },
    { 3, 7, 4, str_ALEX_POWER_B },
    { 3, 7, 4, str_ALEX_SLEEPER },
    { 3, 7, 4, str_RYU_SEOINAGE },
    { 3, 7, 4, str_IBUKI_2 },
    { 3, 7, 4, str_DADLEY_L_B },
    { 3, 7, 4, str_IBUKI_KUBIORI },
    { 3, 7, 4, str_NECRO_S_T },
    { 3, 7, 4, str_RYU_TOMOENAGE },
    { 3, 7, 4, str_YUN_HIZAGERI },
    { 3, 7, 4, str_ORO_KUBISIME },
    { 3, 7, 4, str_NECRO_G_S },
    { 3, 7, 4, str_DUDDLEY_D_S },
    { 3, 7, 4, str_YUN_MONKEY_F },
    { 3, 7, 4, str_ORO_TOMOENAGE },
    { 3, 7, 4, str_ORO_NIOURIKI },
    { 3, 7, 4, str_ORO_GIGOKU_G },
    { 3, 7, 4, str_YUN_2 },
    { 3, 7, 4, str_NECRO_SNAKE_F },
    { 3, 7, 4, str_NECRO_F_S },
    { 3, 7, 4, str_IBUKI_HARAIG },
    { 3, 7, 4, str_GILL_SPLASH_M },
    { 3, 7, 4, str_KEN_HIZAGERI },
    { 3, 7, 4, str_ORO_KISINRIKI },
    { 3, 7, 4, str_SEAN_TACKLE },
    { 3, 7, 4, str_ALEX_HYPER_B },
    { 3, 7, 4, str_NECRO_SLAM_D },
    { 3, 7, 4, str_ELENA_ASINAGE },
    { 3, 7, 4, str_GILL_IMPACT_C },
    { 3, 7, 4, str_ALEX_S_H_B },
    { 3, 7, 4, str_ALEX_F_N_D },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_IBUKI_2 },
    { 3, 7, 4, str_IBUKI_YOROI_D },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_MAWARIKOMI_M_F },
    { 3, 7, 4, str_HUGO_BODY_S },
    { 3, 7, 4, str_HUGO_N_G_T },
    { 3, 7, 4, str_HUGO_M_S_P },
    { 3, 7, 4, str_HUGO_S_D_B_B },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_S_PUNCH_A },
    { 3, 7, 4, str_S_PUNCH_B },
    { 3, 7, 4, str_S_PUNCH_C },
    { 3, 7, 4, str_M_PUNCH_A },
    { 3, 7, 4, str_M_PUNCH_B },
    { 3, 7, 4, str_M_PUNCH_C },
    { 3, 7, 4, str_L_PUNCH_A },
    { 3, 7, 4, str_L_PUNCH_B },
    { 3, 7, 4, str_L_PUNCH_C },
    { 3, 7, 4, str_S_KICK_A },
    { 3, 7, 4, str_S_KICK_B },
    { 3, 7, 4, str_S_KICK_C },
    { 3, 7, 4, str_M_KICK_A },
    { 3, 7, 4, str_M_KICK_B },
    { 3, 7, 4, str_M_KICK_C },
    { 3, 7, 4, str_L_KICK_A },
    { 3, 7, 4, str_L_KICK_B },
    { 3, 7, 4, str_L_KICK_C },
    { 3, 7, 4, str_KAGAMI_P_A },
    { 3, 7, 4, str_KAGAMI_P_B },
    { 3, 7, 4, str_KAGAMI_P_C },
    { 3, 7, 4, str_KAGAMI_P_A },
    { 3, 7, 4, str_KAGAMI_P_B },
    { 3, 7, 4, str_KAGAMI_P_C },
    { 3, 7, 4, str_KAGAMI_P_A },
    { 3, 7, 4, str_KAGAMI_P_B },
    { 3, 7, 4, str_KAGAMI_P_C },
    { 3, 7, 4, str_KAGAMI_K_A },
    { 3, 7, 4, str_KAGAMI_K_B },
    { 3, 7, 4, str_KAGAMI_K_C },
    { 3, 7, 4, str_KAGAMI_K_A },
    { 3, 7, 4, str_KAGAMI_K_B },
    { 3, 7, 4, str_KAGAMI_K_C },
    { 3, 7, 4, str_KAGAMI_K_A },
    { 3, 7, 4, str_KAGAMI_K_B },
    { 3, 7, 4, str_KAGAMI_K_C },
    { 3, 7, 4, str_V_JUMP_P_S_A },
    { 3, 7, 4, str_V_JUMP_P_S_B },
    { 3, 7, 4, str_V_JUMP_P_M_A },
    { 3, 7, 4, str_V_JUMP_P_M_B },
    { 3, 7, 4, str_V_JUMP_P_L_A },
    { 3, 7, 4, str_V_JUMP_P_L_B },
    { 3, 7, 4, str_V_JUMP_K_S_A },
    { 3, 7, 4, str_V_JUMP_K_S_B },
    { 3, 7, 4, str_V_JUMP_K_M_A },
    { 3, 7, 4, str_V_JUMP_K_M_B },
    { 3, 7, 4, str_V_JUMP_K_L_A },
    { 3, 7, 4, str_V_JUMP_K_L_B },
    { 3, 7, 4, str_F_JUMP_P_S_A },
    { 3, 7, 4, str_F_JUMP_P_S_B },
    { 3, 7, 4, str_F_JUMP_P_M_A },
    { 3, 7, 4, str_F_JUMP_P_M_B },
    { 3, 7, 4, str_F_JUMP_P_L_A },
    { 3, 7, 4, str_F_JUMP_P_L_B },
    { 3, 7, 4, str_F_JUMP_K_S_A },
    { 3, 7, 4, str_F_JUMP_K_S_B },
    { 3, 7, 4, str_F_JUMP_K_M_A },
    { 3, 7, 4, str_F_JUMP_K_M_B },
    { 3, 7, 4, str_F_JUMP_K_L_A },
    { 3, 7, 4, str_F_JUMP_K_L_B },
    { 3, 7, 4, str_B_JUMP_P_S_A },
    { 3, 7, 4, str_B_JUMP_P_S_B },
    { 3, 7, 4, str_B_JUMP_P_M_A },
    { 3, 7, 4, str_B_JUMP_P_M_B },
    { 3, 7, 4, str_B_JUMP_P_L_A },
    { 3, 7, 4, str_B_JUMP_P_L_B },
    { 3, 7, 4, str_B_JUMP_K_S_A },
    { 3, 7, 4, str_B_JUMP_K_S_B },
    { 3, 7, 4, str_B_JUMP_K_M_A },
    { 3, 7, 4, str_B_JUMP_K_M_B },
    { 3, 7, 4, str_B_JUMP_K_L_A },
    { 3, 7, 4, str_B_JUMP_K_L_B },
    { 3, 7, 4, str_SP_V_JP_S_P_A },
    { 3, 7, 4, str_SP_V_JP_S_P_B },
    { 3, 7, 4, str_SP_V_JP_M_P_A },
    { 3, 7, 4, str_SP_V_JP_M_P_B },
    { 3, 7, 4, str_SP_V_JP_L_P_A },
    { 3, 7, 4, str_SP_V_JP_L_P_B },
    { 3, 7, 4, str_SP_V_JP_S_K_A },
    { 3, 7, 4, str_SP_V_JP_S_K_B },
    { 3, 7, 4, str_SP_V_JP_M_K_A },
    { 3, 7, 4, str_SP_V_JP_M_K_B },
    { 3, 7, 4, str_SP_V_JP_L_K_A },
    { 3, 7, 4, str_SP_V_JP_L_K_B },
    { 3, 7, 4, str_SP_F_JP_S_P_A },
    { 3, 7, 4, str_SP_F_JP_S_P_B },
    { 3, 7, 4, str_SP_F_JP_M_P_A },
    { 3, 7, 4, str_SP_F_JP_M_P_B },
    { 3, 7, 4, str_SP_F_JP_L_P_A },
    { 3, 7, 4, str_SP_F_JP_L_P_B },
    { 3, 7, 4, str_SP_F_JP_S_K_A },
    { 3, 7, 4, str_SP_F_JP_S_K_B },
    { 3, 7, 4, str_SP_F_JP_M_K_A },
    { 3, 7, 4, str_SP_F_JP_M_K_B },
    { 3, 7, 4, str_SP_F_JP_L_K_A },
    { 3, 7, 4, str_SP_F_JP_L_K_B },
    { 3, 7, 4, str_SP_B_JP_S_P_A },
    { 3, 7, 4, str_SP_B_JP_S_P_B },
    { 3, 7, 4, str_SP_B_JP_M_P_A },
    { 3, 7, 4, str_SP_B_JP_M_P_B },
    { 3, 7, 4, str_SP_B_JP_L_P_A },
    { 3, 7, 4, str_SP_B_JP_L_P_B },
    { 3, 7, 4, str_SP_B_JP_S_K_A },
    { 3, 7, 4, str_SP_B_JP_S_K_B },
    { 3, 7, 4, str_SP_B_JP_M_K_A },
    { 3, 7, 4, str_SP_B_JP_M_K_B },
    { 3, 7, 4, str_SP_B_JP_L_K_A },
    { 3, 7, 4, str_SP_B_JP_L_K_B },
    { 3, 7, 4, str_S_V_JP_S_P_A },
    { 3, 7, 4, str_S_V_JP_S_P_B },
    { 3, 7, 4, str_S_V_JP_M_P_A },
    { 3, 7, 4, str_S_V_JP_M_P_B },
    { 3, 7, 4, str_S_V_JP_L_P_A },
    { 3, 7, 4, str_S_V_JP_L_P_B },
    { 3, 7, 4, str_S_V_JP_S_K_A },
    { 3, 7, 4, str_S_V_JP_S_K_B },
    { 3, 7, 4, str_S_V_JP_M_K_A },
    { 3, 7, 4, str_S_V_JP_M_K_B },
    { 3, 7, 4, str_S_V_JP_L_K_A },
    { 3, 7, 4, str_S_V_JP_L_K_B },
    { 3, 7, 4, str_S_F_JP_S_P_A },
    { 3, 7, 4, str_S_F_JP_S_P_B },
    { 3, 7, 4, str_S_F_JP_M_P_A },
    { 3, 7, 4, str_S_F_JP_M_P_B },
    { 3, 7, 4, str_S_F_JP_L_P_A },
    { 3, 7, 4, str_S_F_JP_L_P_B },
    { 3, 7, 4, str_S_F_JP_S_K_A },
    { 3, 7, 4, str_S_F_JP_S_K_B },
    { 3, 7, 4, str_S_F_JP_M_K_A },
    { 3, 7, 4, str_S_F_JP_M_K_B },
    { 3, 7, 4, str_S_F_JP_L_K_A },
    { 3, 7, 4, str_S_F_JP_L_K_B },
    { 3, 7, 4, str_S_B_JP_S_P_A },
    { 3, 7, 4, str_S_B_JP_S_P_B },
    { 3, 7, 4, str_S_B_JP_M_P_A },
    { 3, 7, 4, str_S_B_JP_M_P_B },
    { 3, 7, 4, str_S_B_JP_L_P_A },
    { 3, 7, 4, str_S_B_JP_L_P_B },
    { 3, 7, 4, str_S_B_JP_S_K_A },
    { 3, 7, 4, str_S_B_JP_S_K_B },
    { 3, 7, 4, str_S_B_JP_M_K_A },
    { 3, 7, 4, str_S_B_JP_M_K_B },
    { 3, 7, 4, str_S_B_JP_L_K_A },
    { 3, 7, 4, str_S_B_JP_L_K_B },
    { 3, 7, 4, str_TUKAMIKAKARI_A },
    { 3, 7, 4, str_TUKAMIKAKARI_B },
    { 3, 7, 4, str_TUKAMIKAKARI_C },
    { 3, 7, 4, str_TUKAMIKAKARI_D },
    { 3, 7, 4, str_TUKAMIKAKARI_E },
    { 3, 7, 4, str_TUKAMIKAKARI_F },
    { 3, 7, 4, str_TUKAMI_AIR_A },
    { 3, 7, 4, str_TUKAMI_AIR_B },
    { 3, 7, 4, str_TUKAMI_AIR_C },
    { 3, 7, 4, str_TUKAMI_AIR_D },
    { 3, 7, 4, str_TUKAMI_AIR_E },
    { 3, 7, 4, str_TUKAMI_AIR_F },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_UP_P_GUARD_P_S },
    { 3, 7, 4, str_UP_P_GUARD_P_M },
    { 3, 7, 4, str_UP_P_GUARD_P_L },
    { 3, 7, 4, str_UP_P_GUARD_K_S },
    { 3, 7, 4, str_UP_P_GUARD_K_M },
    { 3, 7, 4, str_UP_P_GUARD_K_L },
    { 3, 7, 4, str_D_P_GUARD_P_S },
    { 3, 7, 4, str_D_P_GUARD_P_M },
    { 3, 7, 4, str_D_P_GUARD_P_L },
    { 3, 7, 4, str_D_P_GUARD_K_S },
    { 3, 7, 4, str_D_P_GUARD_K_M },
    { 3, 7, 4, str_D_P_GUARD_K_L },
    { 3, 7, 4, str_FUSHIN_P_S },
    { 3, 7, 4, str_FUSHIN_P_M },
    { 3, 7, 4, str_FUSHIN_P_L },
    { 3, 7, 4, str_FUSHIN_K_S },
    { 3, 7, 4, str_FUSHIN_K_M },
    { 3, 7, 4, str_FUSHIN_K_L },
    { 3, 7, 4, str_OKIAGARI_P_S },
    { 3, 7, 4, str_OKIAGARI_P_M },
    { 3, 7, 4, str_OKIAGARI_P_L },
    { 3, 7, 4, str_OKIAGARI_K_S },
    { 3, 7, 4, str_OKIAGARI_K_M },
    { 3, 7, 4, str_OKIAGARI_K_L },
    { 3, 7, 4, str_ATTACK_1_S },
    { 3, 7, 4, str_ATTACK_1_M },
    { 3, 7, 4, str_ATTACK_1_L },
    { 3, 7, 4, str_ATTACK_1_SP },
    { 3, 7, 4, str_ATTACK_2_S },
    { 3, 7, 4, str_ATTACK_2_M },
    { 3, 7, 4, str_ATTACK_2_L },
    { 3, 7, 4, str_ATTACK_2_SP },
    { 3, 7, 4, str_ATTACK_3_S },
    { 3, 7, 4, str_ATTACK_3_M },
    { 3, 7, 4, str_ATTACK_3_L },
    { 3, 7, 4, str_ATTACK_3_SP },
    { 3, 7, 4, str_ATTACK_4_S },
    { 3, 7, 4, str_ATTACK_4_M },
    { 3, 7, 4, str_ATTACK_4_L },
    { 3, 7, 4, str_ATTACK_4_SP },
    { 3, 7, 4, str_ATTACK_5_S },
    { 3, 7, 4, str_ATTACK_5_M },
    { 3, 7, 4, str_ATTACK_5_L },
    { 3, 7, 4, str_ATTACK_5_SP },
    { 3, 7, 4, str_ATTACK_6_S },
    { 3, 7, 4, str_ATTACK_6_M },
    { 3, 7, 4, str_ATTACK_6_L },
    { 3, 7, 4, str_ATTACK_6_SP },
    { 3, 7, 4, str_ATTACK_7_S },
    { 3, 7, 4, str_ATTACK_7_M },
    { 3, 7, 4, str_ATTACK_7_L },
    { 3, 7, 4, str_ATTACK_7_SP },
    { 3, 7, 4, str_ATTACK_8_S },
    { 3, 7, 4, str_ATTACK_8_M },
    { 3, 7, 4, str_ATTACK_8_L },
    { 3, 7, 4, str_ATTACK_8_SP },
    { 3, 7, 4, str_ATTACK_9_S },
    { 3, 7, 4, str_ATTACK_9_M },
    { 3, 7, 4, str_ATTACK_9_L },
    { 3, 7, 4, str_ATTACK_9_SP },
    { 3, 7, 4, str_ATTACK_10_S },
    { 3, 7, 4, str_ATTACK_10_M },
    { 3, 7, 4, str_ATTACK_10_L },
    { 3, 7, 4, str_ATTACK_10_SP },
    { 3, 7, 4, str_ATTACK_11_S },
    { 3, 7, 4, str_ATTACK_11_M },
    { 3, 7, 4, str_ATTACK_11_L },
    { 3, 7, 4, str_ATTACK_11_SP },
    { 3, 7, 4, str_ATTACK_12_S },
    { 3, 7, 4, str_ATTACK_12_M },
    { 3, 7, 4, str_ATTACK_12_L },
    { 3, 7, 4, str_ATTACK_12_SP },
    { 3, 7, 4, str_ATTACK_13_S },
    { 3, 7, 4, str_ATTACK_13_M },
    { 3, 7, 4, str_ATTACK_13_L },
    { 3, 7, 4, str_ATTACK_13_SP },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_EFF01_CHAR },
    { 3, 7, 4, str_EFF13_CHAR },
    { 3, 7, 4, str_GILL_STAGE_OBJ },
    { 3, 7, 4, str_N_Y_1_OBJ },
    { 3, 7, 4, str_ONSEN_OBJ },
    { 3, 7, 4, str_CHAINA_1_OBJ },
    { 3, 7, 4, str_CHAINA_2_OBJ },
    { 3, 7, 4, str_ENGLAND_OBJ },
    { 3, 7, 4, str_ROCIA_OBJ },
    { 3, 7, 4, str_GERMANY_OBJ },
    { 3, 7, 4, str_FURUDERA_OBJ },
    { 3, 7, 4, str_AFRICA_1_OBJ },
    { 3, 7, 4, str_AFRICA_2_OBJ },
    { 3, 7, 4, str_BRAZIL_OBJ },
    { 3, 7, 4, str_SAN_FRANCISCO_2 },
    { 3, 7, 4, str_SANPAURO },
    { 3, 7, 4, str_ETC_1 },
    { 3, 7, 4, str_ETC_2 },
    { 3, 7, 4, str_ETC_3 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_PLEF },
    { 3, 7, 4, str_ENDING_CHAR },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_APPEAR_JUNBI_1 },
    { 3, 7, 4, str_APPEAR_JUNBI_2 },
    { 3, 7, 4, str_APPEAR_JUNBI_3 },
    { 3, 7, 4, str_APPEAR_JUNBI_4 },
    { 3, 7, 4, str_APPEAR_JUNBI_5 },
    { 3, 7, 4, str_APPEAR_JUNBI_6 },
    { 3, 7, 4, str_APPEAR_JUNBI_7 },
    { 3, 7, 4, str_APPEAR_JUNBI_8 },
    { 3, 7, 4, str_APPEAR_1 },
    { 3, 7, 4, str_APPEAR_2 },
    { 3, 7, 4, str_APPEAR_3 },
    { 3, 7, 4, str_APPEAR_4 },
    { 3, 7, 4, str_APPEAR_5 },
    { 3, 7, 4, str_APPEAR_6 },
    { 3, 7, 4, str_APPEAR_7 },
    { 3, 7, 4, str_APPEAR_8 },
    { 3, 7, 4, str_SP_APPEAR_1 },
    { 3, 7, 4, str_SP_APPEAR_2 },
    { 3, 7, 4, str_SP_APPEAR_3 },
    { 3, 7, 4, str_SP_APPEAR_4 },
    { 3, 7, 4, str_SP_APPEAR_5 },
    { 3, 7, 4, str_SP_APPEAR_6 },
    { 3, 7, 4, str_SP_APPEAR_7 },
    { 3, 7, 4, str_SP_APPEAR_8 },
    { 3, 7, 4, str_ZANNEN_1 },
    { 3, 7, 4, str_ZANNEN_2 },
    { 3, 7, 4, str_ZANNEN_3 },
    { 3, 7, 4, str_ZANNEN_4 },
    { 3, 7, 4, str_ZANNEN_5 },
    { 3, 7, 4, str_ZANNEN_6 },
    { 3, 7, 4, str_ZANNEN_7 },
    { 3, 7, 4, str_ZANNEN_8 },
    { 3, 7, 4, str_WIN_1 },
    { 3, 7, 4, str_WIN_2 },
    { 3, 7, 4, str_WIN_3 },
    { 3, 7, 4, str_WIN_4 },
    { 3, 7, 4, str_WIN_5 },
    { 3, 7, 4, str_WIN_6 },
    { 3, 7, 4, str_WIN_7 },
    { 3, 7, 4, str_WIN_8 },
    { 3, 7, 4, str_SP_WIN_1 },
    { 3, 7, 4, str_SP_WIN_2 },
    { 3, 7, 4, str_SP_WIN_3 },
    { 3, 7, 4, str_SP_WIN_4 },
    { 3, 7, 4, str_SP_WIN_5 },
    { 3, 7, 4, str_SP_WIN_6 },
    { 3, 7, 4, str_SP_WIN_7 },
    { 3, 7, 4, str_SP_WIN_8 },
    { 3, 7, 4, str_JUDGMENT_WAIT },
    { 3, 7, 4, str_JUDGMENT_WAIT },
    { 3, 7, 4, str_JUDGMENT_WAIT },
    { 3, 7, 4, str_JUDGMENT_WAIT },
    { 3, 7, 4, str_JUDGMENT_WIN },
    { 3, 7, 4, str_JUDGMENT_WIN },
    { 3, 7, 4, str_JUDGMENT_WIN },
    { 3, 7, 4, str_JUDGMENT_WIN },
    { 3, 7, 4, str_JUDGMENT_LOSE },
    { 3, 7, 4, str_JUDGMENT_LOSE },
    { 3, 7, 4, str_JUDGMENT_LOSE },
    { 3, 7, 4, str_JUDGMENT_LOSE },
    { 3, 7, 4, str_WAIT },
    { 3, 7, 4, str_AFRICA_JUMP },
    { 3, 7, 4, str_AFRICA_LAND },
    { 3, 7, 4, str_SEAN_BALL_HIT },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_BONUS_WIN_1 },
    { 3, 7, 4, str_BONUS_WIN_2 },
    { 3, 7, 4, str_BONUS_WIN_3 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
};
/* Where each kind's script names start in dbg_act_kind_str, by kind. The editor shows script number n
   of a kind as entry n - 1 from there; some characters have more scripts of a kind than the list has
   names, and their higher numbers show the names of the kind after it. */
/* 02006104 */
const TM_STRING* dbg_act_name_tbl[11] = {
    &dbg_act_kind_str[12],
    &dbg_act_kind_str[77],
    &dbg_act_kind_str[327],
    &dbg_act_kind_str[375],
    &dbg_act_kind_str[425],
    &dbg_act_kind_str[706],
    &dbg_act_kind_str[181],
    &dbg_act_kind_str[818],
    &dbg_act_kind_str[987],
    &dbg_act_kind_str[987],
    &dbg_act_kind_str[949],
};
/* 02006130 */
const u32* dbg_pl_char_tbl[20][9] = {
    { gill_nmca, gill_dmca, gill_caca, gill_cuca, gill_atca, gill_saca, gill_btca, gill_exca, gill_yuca },
    { alex_nmca, alex_dmca, alex_caca, alex_cuca, alex_atca, alex_saca, alex_btca, alex_exca, alex_yuca },
    { ryu_nmca, ryu_dmca, ryu_caca, ryu_cuca, ryu_atca, ryu_saca, ryu_btca, ryu_exca, ryu_yuca },
    { yun_nmca, yun_dmca, yun_caca, yun_cuca, yun_atca, yun_saca, yun_btca, yun_exca, yun_yuca },
    { dudley_nmca, dudley_dmca, dudley_caca, dudley_cuca, dudley_atca, dudley_saca, dudley_btca, dudley_exca, dudley_yuca },
    { necro_nmca, necro_dmca, necro_caca, necro_cuca, necro_atca, necro_saca, necro_btca, necro_exca, necro_yuca },
    { hugo_nmca, hugo_dmca, hugo_caca, hugo_cuca, hugo_atca, hugo_saca, hugo_btca, hugo_exca, hugo_yuca },
    { ibuki_nmca, ibuki_dmca, ibuki_caca, ibuki_cuca, ibuki_atca, ibuki_saca, ibuki_btca, ibuki_exca, ibuki_yuca },
    { elena_nmca, elena_dmca, elena_caca, elena_cuca, elena_atca, elena_saca, elena_btca, elena_exca, elena_yuca },
    { oro_nmca, oro_dmca, oro_caca, oro_cuca, oro_atca, oro_saca, oro_btca, oro_exca, oro_yuca },
    { yang_nmca, yang_dmca, yang_caca, yang_cuca, yang_atca, yang_saca, yang_btca, yang_exca, yang_yuca },
    { ken_nmca, ken_dmca, ken_caca, ken_cuca, ken_atca, ken_saca, ken_btca, ken_exca, ken_yuca },
    { sean_nmca, sean_dmca, sean_caca, sean_cuca, sean_atca, sean_saca, sean_btca, sean_exca, sean_yuca },
    { urien_nmca, urien_dmca, urien_caca, urien_cuca, urien_atca, urien_saca, urien_btca, urien_exca, urien_yuca },
    { gouki1_nmca, gouki1_dmca, gouki1_caca, gouki1_cuca, gouki1_atca, gouki1_saca, gouki1_btca, gouki1_exca, gouki1_yuca },
    { gouki2_nmca, gouki2_dmca, gouki2_caca, gouki2_cuca, gouki2_atca, gouki2_saca, gouki2_btca, gouki2_exca, gouki2_yuca },
    { ef01_char_table, ef13_char_table, stg00_char_table, stg01_char_table, stg02_char_table, stg03_char_table, stg10_char_table, stg04_char_table, stg05_char_table },
    { stg06_char_table, stg07_char_table, eff45_char_table, eff86_char_table, brz_char_table, eff19_char_table, stg12_char_table, etc_char_table, etc2_char_table },
    { etc3_char_table, effg0_char_table_0, effg0_char_table_1, effg0_char_table_2, effg0_char_table_3, effg0_char_table_4, effg0_char_table_5, effg0_char_table_6, effg0_char_table_7 },
    { ag_face_panel_table, plef_char_table, effH3_char_table, 0, 0, 0, 0, 0, 0 },
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
CATCH_BOX dbg_look_catch[99];  /* 0201B0E8 */
CAUGHT_BOX dbg_look_caught[99];  /* 0201B400 */
HITA_BOX dbg_look_attack[49];  /* 0201B718 */
u8 dbg_look_attack_tail[16];  /* after dbg_look_attack; nothing refers to it by name or address */
ATTACK_BOX dbg_look_eat[99];  /* 0201BD48, provisional name */
HOSEI_BOX dbg_look_hosei[99];  /* 0201C378 */
u8 dbg_edit_judge[1584];  /* 0201C690 */
BODY_BOX dbg_edit_body[99];  /* 0201CCC0 */
HAND_BOX dbg_edit_hand[198];  /* 0201D920 */
CATCH_BOX dbg_edit_catch[99];  /* 0201E580 */
CAUGHT_BOX dbg_edit_caught[99];  /* 0201E898 */
ATTACK_BOX dbg_edit_attack[99];  /* 0201EBB0 */
ATTACK_BOX dbg_edit_eat[99];  /* 0201F1E0, provisional name */
HOSEI_BOX dbg_edit_hosei[99];  /* 0201F810 */
u8 dbg_copy_judge[16];  /* 0201FB28 */
BODY_BOX dbg_copy_body[1];  /* 0201FB38 */
HAND_BOX dbg_copy_hand[2];  /* 0201FB58 */
CATCH_BOX dbg_copy_catch[1];  /* 0201FB78 */
CAUGHT_BOX dbg_copy_caught[1];  /* 0201FB80 */
ATTACK_BOX dbg_copy_attack[1];  /* 0201FB88 */
ATTACK_BOX dbg_copy_eat[1];  /* 0201FB98, provisional name */
HOSEI_BOX dbg_copy_hosei[1];  /* 0201FBA8 */
s16 dbg_parts_olc_ix[4];  /* 0201FBB0 */
s8 dbg_parts_sel;  /* 0201FBB8 */
PLW dbg_parts_plw[4];  /* 0201FBBC */
u8 dbg_parts_plw_tail[4];  /* after dbg_parts_plw; nothing refers to it by name or address */
