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
extern const u16 hddm_damage_tbl[];
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
extern const u8 alex_se_random_table[];
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
extern const u8 dudley_se_random_table[];
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
extern const u8 elena_se_random_table[];
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
extern const u8 gill_se_random_table[];
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
extern const u8 gouki1_se_random_table[];
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
extern const u8 gouki2_se_random_table[];
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
extern const u8 hugo_se_random_table[];
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
extern const u8 ibuki_se_random_table[];
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
extern const u8 ken_se_random_table[];
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
extern const u8 necro_se_random_table[];
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
extern const u8 oro_se_random_table[];
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
extern const u8 ryu_se_random_table[];
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
extern const u8 sean_se_random_table[];
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
extern const u8 urien_se_random_table[];
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
extern const u8 yang_se_random_table[];
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
extern const u8 yun_se_random_table[];
extern const s16 yun_stepxy_table[][2];
extern const u32 yun_yuca[];

const CHAR_INIT_ROM char_init_data[18] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { (void *)yun_nmca, (void *)yun_dmca, (void *)yun_btca, (void *)yun_caca, (void *)yun_cuca, (void *)yun_atca, (void *)yun_saca, (void *)yun_exca, (void *)yun_cbca, (void *)yun_yuca, (void *)yun_stepxy_table, (void *)yun_movexy_table, (void *)yun_se_random_table, (void *)yun_overlap_char_tbl, (void *)yun_olc_ix_table, (void *)yun_rival_catch_tbl, (void *)yun_hit_ix_table, (void *)yun_body_box, (void *)yun_hand_box, (void *)yun_cat_box, (void *)yun_cau_box, (void *)yun_att_box, (void *)yun_hos_box, (void *)yun_catt_table, 1, 16896, 8192, 38, 2, 0 },
    { (void *)dudley_nmca, (void *)dudley_dmca, (void *)dudley_btca, (void *)dudley_caca, (void *)dudley_cuca, (void *)dudley_atca, (void *)dudley_saca, (void *)dudley_exca, (void *)dudley_cbca, (void *)dudley_yuca, (void *)dudley_stepxy_table, (void *)dudley_movexy_table, (void *)dudley_se_random_table, (void *)dudley_overlap_char_tbl, (void *)dudley_olc_ix_table, (void *)dudley_rival_catch_tbl, (void *)dudley_hit_ix_table, (void *)dudley_body_box, (void *)dudley_hand_box, (void *)dudley_cat_box, (void *)dudley_cau_box, (void *)dudley_att_box, (void *)dudley_hos_box, (void *)dudley_catt_table, 1, 16896, 8192, 50, 2, 0 },
    { (void *)alex_nmca, (void *)alex_dmca, (void *)alex_btca, (void *)alex_caca, (void *)alex_cuca, (void *)alex_atca, (void *)alex_saca, (void *)alex_exca, (void *)alex_cbca, (void *)alex_yuca, (void *)alex_stepxy_table, (void *)alex_movexy_table, (void *)alex_se_random_table, (void *)alex_overlap_char_tbl, (void *)alex_olc_ix_table, (void *)alex_rival_catch_tbl, (void *)alex_hit_ix_table, (void *)alex_body_box, (void *)alex_hand_box, (void *)alex_cat_box, (void *)alex_cau_box, (void *)alex_att_box, (void *)alex_hos_box, (void *)alex_catt_table, 1, 16896, 8192, 52, 2, 0 },
    { (void *)ibuki_nmca, (void *)ibuki_dmca, (void *)ibuki_btca, (void *)ibuki_caca, (void *)ibuki_cuca, (void *)ibuki_atca, (void *)ibuki_saca, (void *)ibuki_exca, (void *)ibuki_cbca, (void *)ibuki_yuca, (void *)ibuki_stepxy_table, (void *)ibuki_movexy_table, (void *)ibuki_se_random_table, (void *)ibuki_overlap_char_tbl, (void *)ibuki_olc_ix_table, (void *)ibuki_rival_catch_tbl, (void *)ibuki_hit_ix_table, (void *)ibuki_body_box, (void *)ibuki_hand_box, (void *)ibuki_cat_box, (void *)ibuki_cau_box, (void *)ibuki_att_box, (void *)ibuki_hos_box, (void *)ibuki_catt_table, 1, 16896, 8192, 42, 2, 0 },
    { (void *)ryu_nmca, (void *)ryu_dmca, (void *)ryu_btca, (void *)ryu_caca, (void *)ryu_cuca, (void *)ryu_atca, (void *)ryu_saca, (void *)ryu_exca, (void *)ryu_cbca, (void *)ryu_yuca, (void *)ryu_stepxy_table, (void *)ryu_movexy_table, (void *)ryu_se_random_table, (void *)ryu_overlap_char_tbl, (void *)ryu_olc_ix_table, (void *)ryu_rival_catch_tbl, (void *)ryu_hit_ix_table, (void *)ryu_body_box, (void *)ryu_hand_box, (void *)ryu_cat_box, (void *)ryu_cau_box, (void *)ryu_att_box, (void *)ryu_hos_box, (void *)ryu_catt_table, 1, 16896, 8192, 48, 2, 0 },
    { (void *)gill_nmca, (void *)gill_dmca, (void *)gill_btca, (void *)gill_caca, (void *)gill_cuca, (void *)gill_atca, (void *)gill_saca, (void *)gill_exca, (void *)gill_cbca, (void *)gill_yuca, (void *)gill_stepxy_table, (void *)gill_movexy_table, (void *)gill_se_random_table, (void *)gill_overlap_char_tbl, (void *)gill_olc_ix_table, (void *)gill_rival_catch_tbl, (void *)gill_hit_ix_table, (void *)gill_body_box, (void *)gill_hand_box, (void *)gill_cat_box, (void *)gill_cau_box, (void *)gill_att_box, (void *)gill_hos_box, (void *)gill_catt_table, 1, 16896, 8192, 54, 2, 0 },
    { (void *)hugo_nmca, (void *)hugo_dmca, (void *)hugo_btca, (void *)hugo_caca, (void *)hugo_cuca, (void *)hugo_atca, (void *)hugo_saca, (void *)hugo_exca, (void *)hugo_cbca, (void *)hugo_yuca, (void *)hugo_stepxy_table, (void *)hugo_movexy_table, (void *)hugo_se_random_table, (void *)hugo_overlap_char_tbl, (void *)hugo_olc_ix_table, (void *)hugo_rival_catch_tbl, (void *)hugo_hit_ix_table, (void *)hugo_body_box, (void *)hugo_hand_box, (void *)hugo_cat_box, (void *)hugo_cau_box, (void *)hugo_att_box, (void *)hugo_hos_box, (void *)hugo_catt_table, 1, 16896, 8192, 56, 2, 0 },
    { (void *)oro_nmca, (void *)oro_dmca, (void *)oro_btca, (void *)oro_caca, (void *)oro_cuca, (void *)oro_atca, (void *)oro_saca, (void *)oro_exca, (void *)oro_cbca, (void *)oro_yuca, (void *)oro_stepxy_table, (void *)oro_movexy_table, (void *)oro_se_random_table, (void *)oro_overlap_char_tbl, (void *)oro_olc_ix_table, (void *)oro_rival_catch_tbl, (void *)oro_hit_ix_table, (void *)oro_body_box, (void *)oro_hand_box, (void *)oro_cat_box, (void *)oro_cau_box, (void *)oro_att_box, (void *)oro_hos_box, (void *)oro_catt_table, 1, 16896, 8192, 40, 2, 0 },
    { (void *)necro_nmca, (void *)necro_dmca, (void *)necro_btca, (void *)necro_caca, (void *)necro_cuca, (void *)necro_atca, (void *)necro_saca, (void *)necro_exca, (void *)necro_cbca, (void *)necro_yuca, (void *)necro_stepxy_table, (void *)necro_movexy_table, (void *)necro_se_random_table, (void *)necro_overlap_char_tbl, (void *)necro_olc_ix_table, (void *)necro_rival_catch_tbl, (void *)necro_hit_ix_table, (void *)necro_body_box, (void *)necro_hand_box, (void *)necro_cat_box, (void *)necro_cau_box, (void *)necro_att_box, (void *)necro_hos_box, (void *)necro_catt_table, 1, 16896, 8192, 46, 2, 0 },
    { (void *)elena_nmca, (void *)elena_dmca, (void *)elena_btca, (void *)elena_caca, (void *)elena_cuca, (void *)elena_atca, (void *)elena_saca, (void *)elena_exca, (void *)elena_cbca, (void *)elena_yuca, (void *)elena_stepxy_table, (void *)elena_movexy_table, (void *)elena_se_random_table, (void *)elena_overlap_char_tbl, (void *)elena_olc_ix_table, (void *)elena_rival_catch_tbl, (void *)elena_hit_ix_table, (void *)elena_body_box, (void *)elena_hand_box, (void *)elena_cat_box, (void *)elena_cau_box, (void *)elena_att_box, (void *)elena_hos_box, (void *)elena_catt_table, 1, 16896, 8192, 44, 2, 0 },
    { (void *)ef13_char_table, 0, 0, 0, 0, 0, 0, 0, 0, 0, (void *)ef13_stepxy_table, (void *)ef13_movexy_table, 0, 0, 0, 0, (void *)ef13_hit_ix_table, (void *)ef13_body_box, (void *)ef13_hand_box, (void *)ef13_cat_box, (void *)ef13_cau_box, (void *)ef13_att_box, (void *)ef13_hos_box, (void *)ef13_catt_table, 1, 16896, 8192, 28, 2, 0 },
    { (void *)yang_nmca, (void *)yang_dmca, (void *)yang_btca, (void *)yang_caca, (void *)yang_cuca, (void *)yang_atca, (void *)yang_saca, (void *)yang_exca, (void *)yang_cbca, (void *)yang_yuca, (void *)yang_stepxy_table, (void *)yang_movexy_table, (void *)yang_se_random_table, (void *)yang_overlap_char_tbl, (void *)yang_olc_ix_table, (void *)yang_rival_catch_tbl, (void *)yang_hit_ix_table, (void *)yang_body_box, (void *)yang_hand_box, (void *)yang_cat_box, (void *)yang_cau_box, (void *)yang_att_box, (void *)yang_hos_box, (void *)yang_catt_table, 1, 16896, 8192, 38, 2, 0 },
    { (void *)ken_nmca, (void *)ken_dmca, (void *)ken_btca, (void *)ken_caca, (void *)ken_cuca, (void *)ken_atca, (void *)ken_saca, (void *)ken_exca, (void *)ken_cbca, (void *)ken_yuca, (void *)ken_stepxy_table, (void *)ken_movexy_table, (void *)ken_se_random_table, (void *)ken_overlap_char_tbl, (void *)ken_olc_ix_table, (void *)ken_rival_catch_tbl, (void *)ken_hit_ix_table, (void *)ken_body_box, (void *)ken_hand_box, (void *)ken_cat_box, (void *)ken_cau_box, (void *)ken_att_box, (void *)ken_hos_box, (void *)ken_catt_table, 1, 16896, 8192, 48, 2, 0 },
    { (void *)sean_nmca, (void *)sean_dmca, (void *)sean_btca, (void *)sean_caca, (void *)sean_cuca, (void *)sean_atca, (void *)sean_saca, (void *)sean_exca, (void *)sean_cbca, (void *)sean_yuca, (void *)sean_stepxy_table, (void *)sean_movexy_table, (void *)sean_se_random_table, (void *)sean_overlap_char_tbl, (void *)sean_olc_ix_table, (void *)sean_rival_catch_tbl, (void *)sean_hit_ix_table, (void *)sean_body_box, (void *)sean_hand_box, (void *)sean_cat_box, (void *)sean_cau_box, (void *)sean_att_box, (void *)sean_hos_box, (void *)sean_catt_table, 1, 16896, 8192, 48, 2, 0 },
    { (void *)urien_nmca, (void *)urien_dmca, (void *)urien_btca, (void *)urien_caca, (void *)urien_cuca, (void *)urien_atca, (void *)urien_saca, (void *)urien_exca, (void *)urien_cbca, (void *)urien_yuca, (void *)urien_stepxy_table, (void *)urien_movexy_table, (void *)urien_se_random_table, (void *)urien_overlap_char_tbl, (void *)urien_olc_ix_table, (void *)urien_rival_catch_tbl, (void *)urien_hit_ix_table, (void *)urien_body_box, (void *)urien_hand_box, (void *)urien_cat_box, (void *)urien_cau_box, (void *)urien_att_box, (void *)urien_hos_box, (void *)urien_catt_table, 1, 16896, 8192, 54, 2, 0 },
    { (void *)gouki1_nmca, (void *)gouki1_dmca, (void *)gouki1_btca, (void *)gouki1_caca, (void *)gouki1_cuca, (void *)gouki1_atca, (void *)gouki1_saca, (void *)gouki1_exca, (void *)gouki1_cbca, (void *)gouki1_yuca, (void *)gouki1_stepxy_table, (void *)gouki1_movexy_table, (void *)gouki1_se_random_table, (void *)gouki1_overlap_char_tbl, (void *)gouki1_olc_ix_table, (void *)gouki1_rival_catch_tbl, (void *)gouki1_hit_ix_table, (void *)gouki1_body_box, (void *)gouki1_hand_box, (void *)gouki1_cat_box, (void *)gouki1_cau_box, (void *)gouki1_att_box, (void *)gouki1_hos_box, (void *)gouki1_catt_table, 1, 16896, 8192, 48, 2, 0 },
    { (void *)gouki2_nmca, (void *)gouki2_dmca, (void *)gouki2_btca, (void *)gouki2_caca, (void *)gouki2_cuca, (void *)gouki2_atca, (void *)gouki2_saca, (void *)gouki2_exca, (void *)gouki2_cbca, (void *)gouki2_yuca, (void *)gouki2_stepxy_table, (void *)gouki2_movexy_table, (void *)gouki2_se_random_table, (void *)gouki2_overlap_char_tbl, (void *)gouki2_olc_ix_table, (void *)gouki2_rival_catch_tbl, (void *)gouki2_hit_ix_table, (void *)gouki2_body_box, (void *)gouki2_hand_box, (void *)gouki2_cat_box, (void *)gouki2_cau_box, (void *)gouki2_att_box, (void *)gouki2_hos_box, (void *)gouki2_catt_table, 1, 16896, 8192, 48, 2, 0 },
};

const s16 Dsas_dir_table[16] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 0,
};

const s8 sel_sp_ch_tbl[10] = {
    0, 1, 0, 1, 1, 1, 1, 1, 1, 0,
};

const s16 rsix_r_table[17][2] = {
    { 0x3D, 1 }, { 0x79, 2 }, { 0xB5, 3 }, { 0xF1, 4 },
    { 0x12D, 5 }, { 0x169, 6 }, { 0x1A5, 7 }, { 0x1E1, 8 },
    { 0x21D, 9 }, { 0x259, 0xA }, { 0x295, 0xB }, { 0x2D1, 0xC },
    { 0x30D, 0xD }, { 0x349, 0xE }, { 0x385, 0xF }, { 0x3C1, 0x10 },
    { 0x3E7, 0x11 },
};

const s16 attr_flame_tbl[82] = {
    0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A,
    0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67,
    0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67,
    0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67,
    0x67, 0x67,
};

const s16 attr_thunder_tbl[82] = {
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x68, 0x68, 0x68, 0x68, 0x68, 0x68, 0x68, 0x68,
    0x68, 0x68, 0x68, 0x68, 0x68, 0x68, 0x68, 0x68,
    0x68, 0x68, 0x68, 0x68, 0x68, 0x68, 0x68, 0x68,
    0x68, 0x68,
};

const s16 attr_freeze_tbl[82] = {
    0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C,
    0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69,
    0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69,
    0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69,
    0x69, 0x69,
};

const s16 sky_nm_damage_tbl[82] = {
    0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x61,
    0x62, 0x58, 0x67, 0x68, 0x69, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x58, 0x61, 0x62, 0x67, 0x68, 0x69, 0x62, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
    0x68, 0x69, 0x6A, 0x6B, 0x5B, 0x6D, 0x6E, 0x6F,
    0x70, 0x71,
};

const s16 sky_nm2_damage_tbl[82] = {
    0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58,
    0x58, 0x58, 0x58, 0x58, 0x58, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58,
    0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58,
    0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58,
    0x58, 0x58,
};

const s16 sky_sp_damage_tbl[82] = {
    0x5B, 0x5B, 0x5B, 0x5F, 0x5B, 0x5B, 0x60, 0x61,
    0x62, 0x5B, 0x67, 0x68, 0x69, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x5B, 0x61, 0x62, 0x67, 0x68, 0x69, 0x62, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
    0x60, 0x61, 0x62, 0x5A, 0x64, 0x65, 0x66, 0x67,
    0x68, 0x69, 0x6A, 0x6B, 0x5B, 0x6D, 0x6E, 0x6F,
    0x61, 0x71,
};

const s16 kagami_damage_tbl[82] = {
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x41,
    0x42, 0x40, 0x43, 0x44, 0x45, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
    0x60, 0x41, 0x42, 0x5A, 0x64, 0x65, 0x66, 0x67,
    0x68, 0x69, 0x6A, 0x6B, 0x41, 0x6D, 0x6E, 0x6F,
    0x70, 0x71,
};

const s16 kagami2_damage_tbl[82] = {
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x40, 0x40, 0x43, 0x44, 0x45, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x40, 0x40, 0x40, 0x43, 0x44, 0x45, 0x40, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x40, 0x59, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x43,
    0x44, 0x45, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x40, 0x40,
};

const s16 grd_hand_damage_tbl[82] = {
    0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29,
    0x29, 0x29, 0x2A, 0x2B, 0x2C, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x29, 0x29, 0x29, 0x2A, 0x2B, 0x2C, 0x29, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x29, 0x59, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29,
    0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x2A,
    0x2B, 0x2C, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29,
    0x29, 0x29,
};

const u16 hddm_damage_tbl[41] = {
    0x100, 1, 0x101, 0x100, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x100, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0,
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
