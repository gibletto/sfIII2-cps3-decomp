/*
 * CHARID_TBL.C  character base data and damage conversion tables
 *
 * char_init_data has one entry per charset_id: the cg script tables (normal, damage, catch,
 * caught, attack, super art and the rest), step and move tables, sound table, overlap tables,
 * catch, hit and judgement box tables, attack attributes and the colour, priority and family
 * settings of each character and of the effect 13 projectile set. Entry 0 is empty. Read by
 * CHARID.C, which loads them into a work in set_char_base_data. The rest are read by
 * HITCHECK.C, the hit detection: indexed by damage reaction number from 32, attr_flame_tbl,
 * attr_thunder_tbl and attr_freeze_tbl give the fire, electric and ice version of a damage;
 * sky_*, kagami* and grd_hand_damage_tbl the airborne, kagami and guard-hand versions;
 * hddm_damage_tbl and trdm_damage_tbl flag head and trunk damage, and ttk_damage_req_tbl the
 * ttk damage request. Also Dsas_dir_table (attack directions that change a running defender's
 * reaction), sel_sp_ch_tbl (by move kind), rsix_r_table (damage to score index), parisucc_pts
 * (parry counter values by play type and parry count) and dm_oiuchi_catch (damage states that
 * a pursuit can catch).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const CHAR_INIT_ROM char_init_data[];
extern const s16 Dsas_dir_table[];
extern const s8 sel_sp_ch_tbl[];
extern const s16 rsix_r_table[][2];
extern const s16 attr_flame_tbl[];
extern const s16 attr_thunder_tbl[];
extern const s16 attr_freeze_tbl[];
extern const s16 sky_nm_damage_tbl[];
extern const s16 sky_nm2_damage_tbl[];
extern const s16 sky_sp_damage_tbl[];
extern const s16 kagami_damage_tbl[];
extern const s16 kagami2_damage_tbl[];
extern const s16 grd_hand_damage_tbl[];
extern const u8 hddm_damage_tbl[];
extern const u8 trdm_damage_tbl[];
extern const u8 ttk_damage_req_tbl[];
extern const u8 parisucc_pts[][40];
extern const u8 dm_oiuchi_catch[];
extern const u32 alex_atca[];
extern const ATTACK_BOX alex_att_box[];
extern const u32 alex_btca[];
extern const u32 alex_caca[];
extern const CATCH_BOX alex_cat_box[];
extern const ATTACK_ATTR alex_catt_table[];
extern const CAUGHT_BOX alex_cau_box[];
extern const u32 alex_cbca[];
extern const u32 alex_cuca[];
extern const u32 alex_dmca[];
extern const u32 alex_exca[];
extern const HAND_BOX alex_hand_box[];
extern const HIT_IX alex_hit_ix_table[];
extern const BODY_BOX alex_body_box[];
extern const HOSEI_BOX alex_hos_box[];
extern const s16 alex_movexy_table[][6];
extern const u32 alex_nmca[];
extern const OLC_IX alex_olc_ix_table[];
extern const OVERLAP_PARTS alex_overlap_char_tbl[];
extern const CatchTable alex_rival_catch_tbl[];
extern const u32 alex_saca[];
extern const u16* const alex_se_random_table[];
extern const s16 alex_stepxy_table[][2];
extern const u32 alex_yuca[];
extern const CatchTable hugo_rival_catch_tbl[];
extern const u32 hugo_cbca[];
extern const OVERLAP_PARTS ibuki_overlap_char_tbl[];
extern const ATTACK_ATTR yang_catt_table[];
extern const ATTACK_ATTR sean_catt_table[];
extern const u32 dudley_atca[];
extern const ATTACK_BOX dudley_att_box[];
extern const BODY_BOX dudley_body_box[];
extern const u32 dudley_btca[];
extern const u32 dudley_caca[];
extern const CATCH_BOX dudley_cat_box[];
extern const ATTACK_ATTR dudley_catt_table[];
extern const CAUGHT_BOX dudley_cau_box[];
extern const u32 dudley_cbca[];
extern const u32 dudley_cuca[];
extern const u32 dudley_dmca[];
extern const u32 dudley_exca[];
extern const HAND_BOX dudley_hand_box[];
extern const HIT_IX dudley_hit_ix_table[];
extern const HOSEI_BOX dudley_hos_box[];
extern const s16 dudley_movexy_table[][6];
extern const u32 dudley_nmca[];
extern const OLC_IX dudley_olc_ix_table[];
extern const OVERLAP_PARTS dudley_overlap_char_tbl[];
extern const CatchTable dudley_rival_catch_tbl[];
extern const u32 dudley_saca[];
extern const u16* const dudley_se_random_table[];
extern const s16 dudley_stepxy_table[][2];
extern const u32 dudley_yuca[];
extern const ATTACK_BOX ef13_att_box[];
extern const BODY_BOX ef13_body_box[];
extern const CATCH_BOX ef13_cat_box[];
extern const ATTACK_ATTR ef13_catt_table[];
extern const CAUGHT_BOX ef13_cau_box[];
extern const u32 ef13_char_table[];
extern const HAND_BOX ef13_hand_box[];
extern const HIT_IX ef13_hit_ix_table[];
extern const HOSEI_BOX ef13_hos_box[];
extern const s16 ef13_movexy_table[][6];
extern const s16 ef13_stepxy_table[][2];
extern const u32 elena_atca[];
extern const ATTACK_BOX elena_att_box[];
extern const BODY_BOX elena_body_box[];
extern const u32 elena_btca[];
extern const u32 elena_caca[];
extern const CATCH_BOX elena_cat_box[];
extern const ATTACK_ATTR elena_catt_table[];
extern const CAUGHT_BOX elena_cau_box[];
extern const u32 elena_cbca[];
extern const u32 elena_cuca[];
extern const u32 elena_dmca[];
extern const u32 elena_exca[];
extern const HAND_BOX elena_hand_box[];
extern const HIT_IX elena_hit_ix_table[];
extern const HOSEI_BOX elena_hos_box[];
extern const s16 elena_movexy_table[][6];
extern const u32 elena_nmca[];
extern const OLC_IX elena_olc_ix_table[];
extern const OVERLAP_PARTS elena_overlap_char_tbl[];
extern const CatchTable elena_rival_catch_tbl[];
extern const u32 elena_saca[];
extern const u16* const elena_se_random_table[];
extern const s16 elena_stepxy_table[][2];
extern const u32 elena_yuca[];
extern const u32 gill_atca[];
extern const ATTACK_BOX gill_att_box[];
extern const BODY_BOX gill_body_box[];
extern const u32 gill_btca[];
extern const u32 gill_caca[];
extern const CATCH_BOX gill_cat_box[];
extern const ATTACK_ATTR gill_catt_table[];
extern const CAUGHT_BOX gill_cau_box[];
extern const u32 gill_cbca[];
extern const OLC_IX gill_olc_ix_table[];
extern const u32 gill_cuca[];
extern const u32 gill_dmca[];
extern const u32 gill_exca[];
extern const HAND_BOX gill_hand_box[];
extern const HIT_IX gill_hit_ix_table[];
extern const HOSEI_BOX gill_hos_box[];
extern const s16 gill_movexy_table[][6];
extern const u32 gill_nmca[];
extern const OVERLAP_PARTS gill_overlap_char_tbl[];
extern const CatchTable gill_rival_catch_tbl[];
extern const u32 gill_saca[];
extern const u16* const gill_se_random_table[];
extern const s16 gill_stepxy_table[][2];
extern const u32 gill_yuca[];
extern const u32 gouki1_atca[];
extern const ATTACK_BOX gouki1_att_box[];
extern const u32 gouki1_btca[];
extern const u32 gouki1_caca[];
extern const CATCH_BOX gouki1_cat_box[];
extern const ATTACK_ATTR gouki1_catt_table[];
extern const CAUGHT_BOX gouki1_cau_box[];
extern const u32 gouki1_cbca[];
extern const u32 gouki1_cuca[];
extern const u32 gouki1_dmca[];
extern const u32 gouki1_exca[];
extern const HAND_BOX gouki1_hand_box[];
extern const HIT_IX gouki1_hit_ix_table[];
extern const BODY_BOX gouki1_body_box[];
extern const HOSEI_BOX gouki1_hos_box[];
extern const s16 gouki1_movexy_table[][6];
extern const u32 gouki1_nmca[];
extern const OLC_IX gouki1_olc_ix_table[];
extern const OVERLAP_PARTS gouki1_overlap_char_tbl[];
extern const CatchTable gouki1_rival_catch_tbl[];
extern const u32 gouki1_saca[];
extern const u16* const gouki1_se_random_table[];
extern const s16 gouki1_stepxy_table[][2];
extern const u32 gouki1_yuca[];
extern const u32 gouki2_atca[];
extern const ATTACK_BOX gouki2_att_box[];
extern const BODY_BOX gouki2_body_box[];
extern const u32 gouki2_btca[];
extern const u32 gouki2_caca[];
extern const CATCH_BOX gouki2_cat_box[];
extern const ATTACK_ATTR gouki2_catt_table[];
extern const CAUGHT_BOX gouki2_cau_box[];
extern const u32 gouki2_cbca[];
extern const u32 gouki2_cuca[];
extern const u32 gouki2_dmca[];
extern const u32 gouki2_exca[];
extern const HAND_BOX gouki2_hand_box[];
extern const HIT_IX gouki2_hit_ix_table[];
extern const HOSEI_BOX gouki2_hos_box[];
extern const s16 gouki2_movexy_table[][6];
extern const u32 gouki2_nmca[];
extern const OLC_IX gouki2_olc_ix_table[];
extern const OVERLAP_PARTS gouki2_overlap_char_tbl[];
extern const CatchTable gouki2_rival_catch_tbl[];
extern const u32 gouki2_saca[];
extern const u16* const gouki2_se_random_table[];
extern const s16 gouki2_stepxy_table[][2];
extern const u32 gouki2_yuca[];
extern const u32 hugo_atca[];
extern const ATTACK_BOX hugo_att_box[];
extern const BODY_BOX hugo_body_box[];
extern const u32 hugo_btca[];
extern const u32 hugo_caca[];
extern const CATCH_BOX hugo_cat_box[];
extern const ATTACK_ATTR hugo_catt_table[];
extern const CAUGHT_BOX hugo_cau_box[];
extern const u32 hugo_cuca[];
extern const u32 hugo_dmca[];
extern const u32 hugo_exca[];
extern const HAND_BOX hugo_hand_box[];
extern const HIT_IX hugo_hit_ix_table[];
extern const HOSEI_BOX hugo_hos_box[];
extern const s16 hugo_movexy_table[][6];
extern const u32 hugo_nmca[];
extern const OLC_IX hugo_olc_ix_table[];
extern const OVERLAP_PARTS hugo_overlap_char_tbl[];
extern const u32 hugo_saca[];
extern const u16* const hugo_se_random_table[];
extern const s16 hugo_stepxy_table[][2];
extern const u32 hugo_yuca[];
extern const u32 ibuki_atca[];
extern const ATTACK_BOX ibuki_att_box[];
extern const BODY_BOX ibuki_body_box[];
extern const u32 ibuki_btca[];
extern const u32 ibuki_caca[];
extern const CATCH_BOX ibuki_cat_box[];
extern const ATTACK_ATTR ibuki_catt_table[];
extern const CAUGHT_BOX ibuki_cau_box[];
extern const u32 ibuki_cbca[];
extern const u32 ibuki_cuca[];
extern const u32 ibuki_dmca[];
extern const u32 ibuki_exca[];
extern const HAND_BOX ibuki_hand_box[];
extern const HIT_IX ibuki_hit_ix_table[];
extern const HOSEI_BOX ibuki_hos_box[];
extern const s16 ibuki_movexy_table[][6];
extern const u32 ibuki_nmca[];
extern const OLC_IX ibuki_olc_ix_table[];
extern const CatchTable ibuki_rival_catch_tbl[];
extern const u32 ibuki_saca[];
extern const u16* const ibuki_se_random_table[];
extern const s16 ibuki_stepxy_table[][2];
extern const u32 ibuki_yuca[];
extern const u32 ken_atca[];
extern const ATTACK_BOX ken_att_box[];
extern const ATTACK_BOX sean_att_box[];
extern const BODY_BOX ken_body_box[];
extern const u32 ken_btca[];
extern const u32 ken_caca[];
extern const CATCH_BOX ken_cat_box[];
extern const ATTACK_ATTR ken_catt_table[];
extern const CAUGHT_BOX ken_cau_box[];
extern const u32 ken_cbca[];
extern const u32 ken_cuca[];
extern const u32 ken_dmca[];
extern const u32 ken_exca[];
extern const HAND_BOX ken_hand_box[];
extern const HIT_IX ken_hit_ix_table[];
extern const HOSEI_BOX ken_hos_box[];
extern const s16 ken_movexy_table[][6];
extern const u32 ken_nmca[];
extern const OLC_IX ken_olc_ix_table[];
extern const OVERLAP_PARTS ken_overlap_char_tbl[];
extern const CatchTable ken_rival_catch_tbl[];
extern const u32 ken_saca[];
extern const u16* const ken_se_random_table[];
extern const s16 ken_stepxy_table[][2];
extern const u32 ken_yuca[];
extern const u32 necro_atca[];
extern const ATTACK_BOX necro_att_box[];
extern const BODY_BOX necro_body_box[];
extern const u32 necro_btca[];
extern const u32 necro_caca[];
extern const CATCH_BOX necro_cat_box[];
extern const ATTACK_ATTR necro_catt_table[];
extern const CAUGHT_BOX necro_cau_box[];
extern const u32 necro_cbca[];
extern const u32 necro_cuca[];
extern const u32 necro_dmca[];
extern const u32 necro_exca[];
extern const HAND_BOX necro_hand_box[];
extern const HIT_IX necro_hit_ix_table[];
extern const HOSEI_BOX necro_hos_box[];
extern const s16 necro_movexy_table[][6];
extern const u32 necro_nmca[];
extern const OLC_IX necro_olc_ix_table[];
extern const OVERLAP_PARTS necro_overlap_char_tbl[];
extern const CatchTable necro_rival_catch_tbl[];
extern const u32 necro_saca[];
extern const u16* const necro_se_random_table[];
extern const s16 necro_stepxy_table[][2];
extern const u32 necro_yuca[];
extern const u32 oro_atca[];
extern const ATTACK_BOX oro_att_box[];
extern const BODY_BOX oro_body_box[];
extern const u32 oro_btca[];
extern const u32 oro_caca[];
extern const CATCH_BOX oro_cat_box[];
extern const ATTACK_ATTR oro_catt_table[];
extern const CAUGHT_BOX oro_cau_box[];
extern const u32 oro_cbca[];
extern const OLC_IX oro_olc_ix_table[];
extern const u32 oro_cuca[];
extern const u32 oro_dmca[];
extern const u32 oro_exca[];
extern const HAND_BOX oro_hand_box[];
extern const HIT_IX oro_hit_ix_table[];
extern const HOSEI_BOX oro_hos_box[];
extern const s16 oro_movexy_table[][6];
extern const u32 oro_nmca[];
extern const OVERLAP_PARTS oro_overlap_char_tbl[];
extern const CatchTable oro_rival_catch_tbl[];
extern const u32 oro_saca[];
extern const u16* const oro_se_random_table[];
extern const s16 oro_stepxy_table[][2];
extern const u32 oro_yuca[];
extern const u32 ryu_atca[];
extern const ATTACK_BOX ryu_att_box[];
extern const BODY_BOX ryu_body_box[];
extern const u32 ryu_btca[];
extern const u32 ryu_caca[];
extern const CATCH_BOX ryu_cat_box[];
extern const ATTACK_ATTR ryu_catt_table[];
extern const CAUGHT_BOX ryu_cau_box[];
extern const u32 ryu_cbca[];
extern const u32 ryu_cuca[];
extern const u32 ryu_dmca[];
extern const u32 ryu_exca[];
extern const HAND_BOX ryu_hand_box[];
extern const HIT_IX ryu_hit_ix_table[];
extern const HOSEI_BOX ryu_hos_box[];
extern const s16 ryu_movexy_table[][6];
extern const u32 ryu_nmca[];
extern const OLC_IX ryu_olc_ix_table[];
extern const OVERLAP_PARTS ryu_overlap_char_tbl[];
extern const CatchTable ryu_rival_catch_tbl[];
extern const u32 ryu_saca[];
extern const u16* const ryu_se_random_table[];
extern const s16 ryu_stepxy_table[][2];
extern const u32 ryu_yuca[];
extern const u32 sean_atca[];
extern const BODY_BOX sean_body_box[];
extern const u32 sean_btca[];
extern const u32 sean_caca[];
extern const CATCH_BOX sean_cat_box[];
extern const CAUGHT_BOX sean_cau_box[];
extern const u32 sean_cbca[];
extern const u32 sean_cuca[];
extern const u32 sean_dmca[];
extern const u32 sean_exca[];
extern const HAND_BOX sean_hand_box[];
extern const HIT_IX sean_hit_ix_table[];
extern const HOSEI_BOX sean_hos_box[];
extern const s16 sean_movexy_table[][6];
extern const u32 sean_nmca[];
extern const OLC_IX sean_olc_ix_table[];
extern const OVERLAP_PARTS sean_overlap_char_tbl[];
extern const CatchTable sean_rival_catch_tbl[];
extern const u32 sean_saca[];
extern const u16* const sean_se_random_table[];
extern const s16 sean_stepxy_table[][2];
extern const u32 sean_yuca[];
extern const u32 urien_atca[];
extern const ATTACK_BOX urien_att_box[];
extern const BODY_BOX urien_body_box[];
extern const u32 urien_btca[];
extern const u32 urien_caca[];
extern const CATCH_BOX urien_cat_box[];
extern const ATTACK_ATTR urien_catt_table[];
extern const CAUGHT_BOX urien_cau_box[];
extern const u32 urien_cbca[];
extern const u32 urien_cuca[];
extern const u32 urien_dmca[];
extern const u32 urien_exca[];
extern const HAND_BOX urien_hand_box[];
extern const HIT_IX urien_hit_ix_table[];
extern const HOSEI_BOX urien_hos_box[];
extern const s16 urien_movexy_table[][6];
extern const u32 urien_nmca[];
extern const OLC_IX urien_olc_ix_table[];
extern const OVERLAP_PARTS urien_overlap_char_tbl[];
extern const CatchTable urien_rival_catch_tbl[];
extern const u32 urien_saca[];
extern const u16* const urien_se_random_table[];
extern const s16 urien_stepxy_table[][2];
extern const u32 urien_yuca[];
extern const u32 yang_atca[];
extern const ATTACK_BOX yang_att_box[];
extern const BODY_BOX yang_body_box[];
extern const u32 yang_btca[];
extern const u32 yang_caca[];
extern const CATCH_BOX yang_cat_box[];
extern const CAUGHT_BOX yang_cau_box[];
extern const u32 yang_cbca[];
extern const u32 yang_cuca[];
extern const u32 yang_dmca[];
extern const u32 yang_exca[];
extern const HAND_BOX yang_hand_box[];
extern const HIT_IX yang_hit_ix_table[];
extern const HOSEI_BOX yang_hos_box[];
extern const s16 yang_movexy_table[][6];
extern const u32 yang_nmca[];
extern const OLC_IX yang_olc_ix_table[];
extern const OVERLAP_PARTS yang_overlap_char_tbl[];
extern const CatchTable yang_rival_catch_tbl[];
extern const u32 yang_saca[];
extern const u16* const yang_se_random_table[];
extern const s16 yang_stepxy_table[][2];
extern const u32 yang_yuca[];
extern const u32 yun_atca[];
extern const ATTACK_BOX yun_att_box[];
extern const BODY_BOX yun_body_box[];
extern const u32 yun_btca[];
extern const u32 yun_caca[];
extern const CATCH_BOX yun_cat_box[];
extern const ATTACK_ATTR yun_catt_table[];
extern const CAUGHT_BOX yun_cau_box[];
extern const u32 yun_cbca[];
extern const CatchTable yun_rival_catch_tbl[];
extern const u32 yun_cuca[];
extern const u32 yun_dmca[];
extern const u32 yun_exca[];
extern const HAND_BOX yun_hand_box[];
extern const HIT_IX yun_hit_ix_table[];
extern const HOSEI_BOX yun_hos_box[];
extern const s16 yun_movexy_table[][6];
extern const u32 yun_nmca[];
extern const OLC_IX yun_olc_ix_table[];
extern const OVERLAP_PARTS yun_overlap_char_tbl[];
extern const u32 yun_saca[];
extern const u16* const yun_se_random_table[];
extern const s16 yun_stepxy_table[][2];
extern const u32 yun_yuca[];

const CHAR_INIT_ROM char_init_data[18] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { yun_nmca, yun_dmca, yun_btca, yun_caca, yun_cuca, yun_atca, yun_saca, yun_exca, yun_cbca, yun_yuca, &yun_stepxy_table[0][0], &yun_movexy_table[0][0], (void *)yun_se_random_table, yun_overlap_char_tbl, yun_olc_ix_table, yun_rival_catch_tbl, yun_hit_ix_table, yun_body_box, yun_hand_box, yun_cat_box, yun_cau_box, yun_att_box, yun_hos_box, yun_catt_table, 1, 16896, 8192, 38, 2, 0 },
    { dudley_nmca, dudley_dmca, dudley_btca, dudley_caca, dudley_cuca, dudley_atca, dudley_saca, dudley_exca, dudley_cbca, dudley_yuca, &dudley_stepxy_table[0][0], &dudley_movexy_table[0][0], (void *)dudley_se_random_table, dudley_overlap_char_tbl, dudley_olc_ix_table, dudley_rival_catch_tbl, dudley_hit_ix_table, dudley_body_box, dudley_hand_box, dudley_cat_box, dudley_cau_box, dudley_att_box, dudley_hos_box, dudley_catt_table, 1, 16896, 8192, 50, 2, 0 },
    { alex_nmca, alex_dmca, alex_btca, alex_caca, alex_cuca, alex_atca, alex_saca, alex_exca, alex_cbca, alex_yuca, &alex_stepxy_table[0][0], &alex_movexy_table[0][0], (void *)alex_se_random_table, alex_overlap_char_tbl, alex_olc_ix_table, alex_rival_catch_tbl, alex_hit_ix_table, alex_body_box, alex_hand_box, alex_cat_box, alex_cau_box, alex_att_box, alex_hos_box, alex_catt_table, 1, 16896, 8192, 52, 2, 0 },
    { ibuki_nmca, ibuki_dmca, ibuki_btca, ibuki_caca, ibuki_cuca, ibuki_atca, ibuki_saca, ibuki_exca, ibuki_cbca, ibuki_yuca, &ibuki_stepxy_table[0][0], &ibuki_movexy_table[0][0], (void *)ibuki_se_random_table, ibuki_overlap_char_tbl, ibuki_olc_ix_table, ibuki_rival_catch_tbl, ibuki_hit_ix_table, ibuki_body_box, ibuki_hand_box, ibuki_cat_box, ibuki_cau_box, ibuki_att_box, ibuki_hos_box, ibuki_catt_table, 1, 16896, 8192, 42, 2, 0 },
    { ryu_nmca, ryu_dmca, ryu_btca, ryu_caca, ryu_cuca, ryu_atca, ryu_saca, ryu_exca, ryu_cbca, ryu_yuca, &ryu_stepxy_table[0][0], &ryu_movexy_table[0][0], (void *)ryu_se_random_table, ryu_overlap_char_tbl, ryu_olc_ix_table, ryu_rival_catch_tbl, ryu_hit_ix_table, ryu_body_box, ryu_hand_box, ryu_cat_box, ryu_cau_box, ryu_att_box, ryu_hos_box, ryu_catt_table, 1, 16896, 8192, 48, 2, 0 },
    { gill_nmca, gill_dmca, gill_btca, gill_caca, gill_cuca, gill_atca, gill_saca, gill_exca, gill_cbca, gill_yuca, &gill_stepxy_table[0][0], &gill_movexy_table[0][0], (void *)gill_se_random_table, gill_overlap_char_tbl, gill_olc_ix_table, gill_rival_catch_tbl, gill_hit_ix_table, gill_body_box, gill_hand_box, gill_cat_box, gill_cau_box, gill_att_box, gill_hos_box, gill_catt_table, 1, 16896, 8192, 54, 2, 0 },
    { hugo_nmca, hugo_dmca, hugo_btca, hugo_caca, hugo_cuca, hugo_atca, hugo_saca, hugo_exca, hugo_cbca, hugo_yuca, &hugo_stepxy_table[0][0], &hugo_movexy_table[0][0], (void *)hugo_se_random_table, hugo_overlap_char_tbl, hugo_olc_ix_table, hugo_rival_catch_tbl, hugo_hit_ix_table, hugo_body_box, hugo_hand_box, hugo_cat_box, hugo_cau_box, hugo_att_box, hugo_hos_box, hugo_catt_table, 1, 16896, 8192, 56, 2, 0 },
    { oro_nmca, oro_dmca, oro_btca, oro_caca, oro_cuca, oro_atca, oro_saca, oro_exca, oro_cbca, oro_yuca, &oro_stepxy_table[0][0], &oro_movexy_table[0][0], (void *)oro_se_random_table, oro_overlap_char_tbl, oro_olc_ix_table, oro_rival_catch_tbl, oro_hit_ix_table, oro_body_box, oro_hand_box, oro_cat_box, oro_cau_box, oro_att_box, oro_hos_box, oro_catt_table, 1, 16896, 8192, 40, 2, 0 },
    { necro_nmca, necro_dmca, necro_btca, necro_caca, necro_cuca, necro_atca, necro_saca, necro_exca, necro_cbca, necro_yuca, &necro_stepxy_table[0][0], &necro_movexy_table[0][0], (void *)necro_se_random_table, necro_overlap_char_tbl, necro_olc_ix_table, necro_rival_catch_tbl, necro_hit_ix_table, necro_body_box, necro_hand_box, necro_cat_box, necro_cau_box, necro_att_box, necro_hos_box, necro_catt_table, 1, 16896, 8192, 46, 2, 0 },
    { elena_nmca, elena_dmca, elena_btca, elena_caca, elena_cuca, elena_atca, elena_saca, elena_exca, elena_cbca, elena_yuca, &elena_stepxy_table[0][0], &elena_movexy_table[0][0], (void *)elena_se_random_table, elena_overlap_char_tbl, elena_olc_ix_table, elena_rival_catch_tbl, elena_hit_ix_table, elena_body_box, elena_hand_box, elena_cat_box, elena_cau_box, elena_att_box, elena_hos_box, elena_catt_table, 1, 16896, 8192, 44, 2, 0 },
    { ef13_char_table, 0, 0, 0, 0, 0, 0, 0, 0, 0, &ef13_stepxy_table[0][0], &ef13_movexy_table[0][0], 0, 0, 0, 0, ef13_hit_ix_table, ef13_body_box, ef13_hand_box, ef13_cat_box, ef13_cau_box, ef13_att_box, ef13_hos_box, ef13_catt_table, 1, 16896, 8192, 28, 2, 0 },
    { yang_nmca, yang_dmca, yang_btca, yang_caca, yang_cuca, yang_atca, yang_saca, yang_exca, yang_cbca, yang_yuca, &yang_stepxy_table[0][0], &yang_movexy_table[0][0], (void *)yang_se_random_table, yang_overlap_char_tbl, yang_olc_ix_table, yang_rival_catch_tbl, yang_hit_ix_table, yang_body_box, yang_hand_box, yang_cat_box, yang_cau_box, yang_att_box, yang_hos_box, yang_catt_table, 1, 16896, 8192, 38, 2, 0 },
    { ken_nmca, ken_dmca, ken_btca, ken_caca, ken_cuca, ken_atca, ken_saca, ken_exca, ken_cbca, ken_yuca, &ken_stepxy_table[0][0], &ken_movexy_table[0][0], (void *)ken_se_random_table, ken_overlap_char_tbl, ken_olc_ix_table, ken_rival_catch_tbl, ken_hit_ix_table, ken_body_box, ken_hand_box, ken_cat_box, ken_cau_box, ken_att_box, ken_hos_box, ken_catt_table, 1, 16896, 8192, 48, 2, 0 },
    { sean_nmca, sean_dmca, sean_btca, sean_caca, sean_cuca, sean_atca, sean_saca, sean_exca, sean_cbca, sean_yuca, &sean_stepxy_table[0][0], &sean_movexy_table[0][0], (void *)sean_se_random_table, sean_overlap_char_tbl, sean_olc_ix_table, sean_rival_catch_tbl, sean_hit_ix_table, sean_body_box, sean_hand_box, sean_cat_box, sean_cau_box, sean_att_box, sean_hos_box, sean_catt_table, 1, 16896, 8192, 48, 2, 0 },
    { urien_nmca, urien_dmca, urien_btca, urien_caca, urien_cuca, urien_atca, urien_saca, urien_exca, urien_cbca, urien_yuca, &urien_stepxy_table[0][0], &urien_movexy_table[0][0], (void *)urien_se_random_table, urien_overlap_char_tbl, urien_olc_ix_table, urien_rival_catch_tbl, urien_hit_ix_table, urien_body_box, urien_hand_box, urien_cat_box, urien_cau_box, urien_att_box, urien_hos_box, urien_catt_table, 1, 16896, 8192, 54, 2, 0 },
    { gouki1_nmca, gouki1_dmca, gouki1_btca, gouki1_caca, gouki1_cuca, gouki1_atca, gouki1_saca, gouki1_exca, gouki1_cbca, gouki1_yuca, &gouki1_stepxy_table[0][0], &gouki1_movexy_table[0][0], (void *)gouki1_se_random_table, gouki1_overlap_char_tbl, gouki1_olc_ix_table, gouki1_rival_catch_tbl, gouki1_hit_ix_table, gouki1_body_box, gouki1_hand_box, gouki1_cat_box, gouki1_cau_box, gouki1_att_box, gouki1_hos_box, gouki1_catt_table, 1, 16896, 8192, 48, 2, 0 },
    { gouki2_nmca, gouki2_dmca, gouki2_btca, gouki2_caca, gouki2_cuca, gouki2_atca, gouki2_saca, gouki2_exca, gouki2_cbca, gouki2_yuca, &gouki2_stepxy_table[0][0], &gouki2_movexy_table[0][0], (void *)gouki2_se_random_table, gouki2_overlap_char_tbl, gouki2_olc_ix_table, gouki2_rival_catch_tbl, gouki2_hit_ix_table, gouki2_body_box, gouki2_hand_box, gouki2_cat_box, gouki2_cau_box, gouki2_att_box, gouki2_hos_box, gouki2_catt_table, 1, 16896, 8192, 48, 2, 0 },
};

const s16 Dsas_dir_table[16] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 0,
};

const s8 sel_sp_ch_tbl[10] = {
    0, 1, 0, 1, 1, 1, 1, 1, 1, 0,
};

const s16 rsix_r_table[17][2] = {
    { 61, 1 }, { 121, 2 }, { 181, 3 }, { 241, 4 },
    { 301, 5 }, { 361, 6 }, { 421, 7 }, { 481, 8 },
    { 541, 9 }, { 601, 10 }, { 661, 11 }, { 721, 12 },
    { 781, 13 }, { 841, 14 }, { 901, 15 }, { 961, 16 },
    { 999, 17 },
};

const s16 attr_flame_tbl[82] = {
    42, 42, 42, 42, 42, 42, 42, 42,
    42, 42, 42, 42, 42, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    67, 67, 67, 67, 67, 67, 67, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    103, 103, 103, 103, 103, 103, 103, 103,
    103, 103, 103, 103, 103, 103, 103, 103,
    103, 103, 103, 103, 103, 103, 103, 103,
    103, 103,
};

const s16 attr_thunder_tbl[82] = {
    43, 43, 43, 43, 43, 43, 43, 43,
    43, 43, 43, 43, 43, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    68, 68, 68, 68, 68, 68, 68, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    104, 104, 104, 104, 104, 104, 104, 104,
    104, 104, 104, 104, 104, 104, 104, 104,
    104, 104, 104, 104, 104, 104, 104, 104,
    104, 104,
};

const s16 attr_freeze_tbl[82] = {
    44, 44, 44, 44, 44, 44, 44, 44,
    44, 44, 44, 44, 44, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    69, 69, 69, 69, 69, 69, 69, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    105, 105, 105, 105, 105, 105, 105, 105,
    105, 105, 105, 105, 105, 105, 105, 105,
    105, 105, 105, 105, 105, 105, 105, 105,
    105, 105,
};

const s16 sky_nm_damage_tbl[82] = {
    88, 88, 88, 88, 88, 88, 88, 97,
    98, 88, 103, 104, 105, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    88, 97, 98, 103, 104, 105, 98, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 99, 100, 101, 102, 103,
    104, 105, 106, 107, 91, 109, 110, 111,
    112, 113,
};

const s16 sky_nm2_damage_tbl[82] = {
    88, 88, 88, 88, 88, 88, 88, 88,
    88, 88, 88, 88, 88, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    88, 88, 88, 88, 88, 88, 88, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    88, 88, 88, 88, 88, 88, 88, 88,
    88, 88, 88, 88, 88, 88, 88, 88,
    88, 88, 88, 88, 88, 88, 88, 88,
    88, 88,
};

const s16 sky_sp_damage_tbl[82] = {
    91, 91, 91, 95, 91, 91, 96, 97,
    98, 91, 103, 104, 105, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    91, 97, 98, 103, 104, 105, 98, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 90, 100, 101, 102, 103,
    104, 105, 106, 107, 91, 109, 110, 111,
    97, 113,
};

const s16 kagami_damage_tbl[82] = {
    64, 64, 64, 64, 64, 64, 64, 65,
    66, 64, 67, 68, 69, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    64, 65, 66, 67, 68, 69, 70, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    88, 89, 90, 91, 92, 93, 94, 95,
    96, 65, 66, 90, 100, 101, 102, 103,
    104, 105, 106, 107, 65, 109, 110, 111,
    112, 113,
};

const s16 kagami2_damage_tbl[82] = {
    64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 67, 68, 69, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    64, 64, 64, 67, 68, 69, 64, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    64, 89, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 67,
    68, 69, 64, 64, 64, 64, 64, 64,
    64, 64,
};

const s16 grd_hand_damage_tbl[82] = {
    41, 41, 41, 41, 41, 41, 41, 41,
    41, 41, 42, 43, 44, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    41, 41, 41, 42, 43, 44, 41, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    41, 89, 41, 41, 41, 41, 41, 41,
    41, 41, 41, 41, 41, 41, 41, 42,
    43, 44, 41, 41, 41, 41, 41, 41,
    41, 41,
};

const u8 hddm_damage_tbl[82] = {
    1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0,
};

const u8 trdm_damage_tbl[82] = {
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0,
};

const u8 ttk_damage_req_tbl[82] = {
    0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
    0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1,
    0, 0,
};

const u8 parisucc_pts[2][40] = {
    { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 100, 100, 100, 100 },
    { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20 },
};

const u8 dm_oiuchi_catch[32] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 255,
};
