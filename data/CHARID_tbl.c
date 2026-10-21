/*
 * CHARID_TBL.C  tables read by CHARID.c and HITCHECK.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const CHAR_INIT_ROM char_init_data[];
extern const s16 Dsas_dir_table[];
extern const u16 sel_sp_ch_tbl[];
extern const u16 rsix_r_table[];
extern const u16 attr_flame_tbl[];
extern const u16 attr_thunder_tbl[];
extern const u16 attr_freeze_tbl[];
extern const u16 sky_nm_damage_tbl[];
extern const u16 sky_nm2_damage_tbl[];
extern const u16 sky_sp_damage_tbl[];
extern const u16 kagami_damage_tbl[];
extern const u16 kagami2_damage_tbl[];
extern const u16 grd_hand_damage_tbl[];
extern const u16 hddm_damage_tbl[];
extern const u16 trdm_damage_tbl[];
extern const u16 ttk_damage_req_tbl[];
extern const u16 parisucc_pts[];
extern const u16 dm_oiuchi_catch[];
extern const u8 alex_atca[];
extern const u8 alex_att_box[];
extern const u8 alex_btca[];
extern const u8 alex_caca[];
extern const u8 alex_cat_box[];
extern const u8 alex_catt_table[];
extern const u8 alex_cau_box[];
extern const u8 alex_cbca[];
extern const u8 alex_cuca[];
extern const u8 alex_dmca[];
extern const u8 alex_exca[];
extern const u8 alex_hand_box[];
extern const u8 alex_hit_ix_table[];
extern const u8 alex_body_box[];
extern const u8 alex_hos_box[];
extern const u8 alex_movexy_table[];
extern const u8 alex_nmca[];
extern const u8 alex_olc_ix_table[];
extern const u8 alex_overlap_char_tbl[];
extern const u8 alex_rival_catch_tbl[];
extern const u8 alex_saca[];
extern const u8 alex_se_random_table[];
extern const u8 alex_stepxy_table[];
extern const u8 alex_yuca[];
extern const u8 hugo_rival_catch_tbl[];
extern const u8 hugo_cbca[];
extern const u8 ibuki_overlap_char_tbl[];
extern const u8 yang_catt_table[];
extern const u8 sean_catt_table[];
extern const u8 dudley_atca[];
extern const u8 dudley_att_box[];
extern const u8 dudley_body_box[];
extern const u8 dudley_btca[];
extern const u8 dudley_caca[];
extern const u8 dudley_cat_box[];
extern const u8 dudley_catt_table[];
extern const u8 dudley_cau_box[];
extern const u8 dudley_cbca[];
extern const u8 dudley_cuca[];
extern const u8 dudley_dmca[];
extern const u8 dudley_exca[];
extern const u8 dudley_hand_box[];
extern const u8 dudley_hit_ix_table[];
extern const u8 dudley_hos_box[];
extern const u8 dudley_movexy_table[];
extern const u8 dudley_nmca[];
extern const u8 dudley_olc_ix_table[];
extern const u8 dudley_overlap_char_tbl[];
extern const u8 dudley_rival_catch_tbl[];
extern const u8 dudley_saca[];
extern const u8 dudley_se_random_table[];
extern const u8 dudley_stepxy_table[];
extern const u8 dudley_yuca[];
extern const u8 ef13_att_box[];
extern const u8 ef13_body_box[];
extern const u8 ef13_cat_box[];
extern const u8 ef13_catt_table[];
extern const u8 ef13_cau_box[];
extern const u8 ef13_char_table[];
extern const u8 ef13_hand_box[];
extern const u8 ef13_hit_ix_table[];
extern const u8 ef13_hos_box[];
extern const u8 ef13_movexy_table[];
extern const u8 ef13_stepxy_table[];
extern const u8 elena_atca[];
extern const u8 elena_att_box[];
extern const u8 elena_body_box[];
extern const u8 elena_btca[];
extern const u8 elena_caca[];
extern const u8 elena_cat_box[];
extern const u8 elena_catt_table[];
extern const u8 elena_cau_box[];
extern const u8 elena_cbca[];
extern const u8 elena_cuca[];
extern const u8 elena_dmca[];
extern const u8 elena_exca[];
extern const u8 elena_hand_box[];
extern const u8 elena_hit_ix_table[];
extern const u8 elena_hos_box[];
extern const u8 elena_movexy_table[];
extern const u8 elena_nmca[];
extern const u8 elena_olc_ix_table[];
extern const u8 elena_overlap_char_tbl[];
extern const u8 elena_rival_catch_tbl[];
extern const u8 elena_saca[];
extern const u8 elena_se_random_table[];
extern const u8 elena_stepxy_table[];
extern const u8 elena_yuca[];
extern const u8 gill_atca[];
extern const u8 gill_att_box[];
extern const u8 gill_body_box[];
extern const u8 gill_btca[];
extern const u8 gill_caca[];
extern const u8 gill_cat_box[];
extern const u8 gill_catt_table[];
extern const u8 gill_cau_box[];
extern const u8 gill_cbca[];
extern const u8 gill_olc_ix_table[];
extern const u8 gill_cuca[];
extern const u8 gill_dmca[];
extern const u8 gill_exca[];
extern const u8 gill_hand_box[];
extern const u8 gill_hit_ix_table[];
extern const u8 gill_hos_box[];
extern const u8 gill_movexy_table[];
extern const u8 gill_nmca[];
extern const u8 gill_overlap_char_tbl[];
extern const u8 gill_rival_catch_tbl[];
extern const u8 gill_saca[];
extern const u8 gill_se_random_table[];
extern const u8 gill_stepxy_table[];
extern const u8 gill_yuca[];
extern const u8 gouki1_atca[];
extern const u8 gouki1_att_box[];
extern const u8 gouki1_btca[];
extern const u8 gouki1_caca[];
extern const u8 gouki1_cat_box[];
extern const u8 gouki1_catt_table[];
extern const u8 gouki1_cau_box[];
extern const u8 gouki1_cbca[];
extern const u8 gouki1_cuca[];
extern const u8 gouki1_dmca[];
extern const u8 gouki1_exca[];
extern const u8 gouki1_hand_box[];
extern const u8 gouki1_hit_ix_table[];
extern const u8 gouki1_body_box[];
extern const u8 gouki1_hos_box[];
extern const u8 gouki1_movexy_table[];
extern const u8 gouki1_nmca[];
extern const u8 gouki1_olc_ix_table[];
extern const u8 gouki1_overlap_char_tbl[];
extern const u8 gouki1_rival_catch_tbl[];
extern const u8 gouki1_saca[];
extern const u8 gouki1_se_random_table[];
extern const u8 gouki1_stepxy_table[];
extern const u8 gouki1_yuca[];
extern const u8 gouki2_atca[];
extern const u8 gouki2_att_box[];
extern const u8 gouki2_body_box[];
extern const u8 gouki2_btca[];
extern const u8 gouki2_caca[];
extern const u8 gouki2_cat_box[];
extern const u8 gouki2_catt_table[];
extern const u8 gouki2_cau_box[];
extern const u8 gouki2_cbca[];
extern const u8 gouki2_cuca[];
extern const u8 gouki2_dmca[];
extern const u8 gouki2_exca[];
extern const u8 gouki2_hand_box[];
extern const u8 gouki2_hit_ix_table[];
extern const u8 gouki2_hos_box[];
extern const u8 gouki2_movexy_table[];
extern const u8 gouki2_nmca[];
extern const u8 gouki2_olc_ix_table[];
extern const u8 gouki2_overlap_char_tbl[];
extern const u8 gouki2_rival_catch_tbl[];
extern const u8 gouki2_saca[];
extern const u8 gouki2_se_random_table[];
extern const u8 gouki2_stepxy_table[];
extern const u8 gouki2_yuca[];
extern const u8 hugo_atca[];
extern const u8 hugo_att_box[];
extern const u8 hugo_body_box[];
extern const u8 hugo_btca[];
extern const u8 hugo_caca[];
extern const u8 hugo_cat_box[];
extern const u8 hugo_catt_table[];
extern const u8 hugo_cau_box[];
extern const u8 hugo_cuca[];
extern const u8 hugo_dmca[];
extern const u8 hugo_exca[];
extern const u8 hugo_hand_box[];
extern const u8 hugo_hit_ix_table[];
extern const u8 hugo_hos_box[];
extern const u8 hugo_movexy_table[];
extern const u8 hugo_nmca[];
extern const u8 hugo_olc_ix_table[];
extern const u8 hugo_overlap_char_tbl[];
extern const u8 hugo_saca[];
extern const u8 hugo_se_random_table[];
extern const u8 hugo_stepxy_table[];
extern const u8 hugo_yuca[];
extern const u8 ibuki_atca[];
extern const u8 ibuki_att_box[];
extern const u8 ibuki_body_box[];
extern const u8 ibuki_btca[];
extern const u8 ibuki_caca[];
extern const u8 ibuki_cat_box[];
extern const u8 ibuki_catt_table[];
extern const u8 ibuki_cau_box[];
extern const u8 ibuki_cbca[];
extern const u8 ibuki_cuca[];
extern const u8 ibuki_dmca[];
extern const u8 ibuki_exca[];
extern const u8 ibuki_hand_box[];
extern const u8 ibuki_hit_ix_table[];
extern const u8 ibuki_hos_box[];
extern const u8 ibuki_movexy_table[];
extern const u8 ibuki_nmca[];
extern const u8 ibuki_olc_ix_table[];
extern const u8 ibuki_rival_catch_tbl[];
extern const u8 ibuki_saca[];
extern const u8 ibuki_se_random_table[];
extern const u8 ibuki_stepxy_table[];
extern const u8 ibuki_yuca[];
extern const u8 ken_atca[];
extern const u8 ken_att_box[];
extern const u8 sean_att_box[];
extern const u8 ken_body_box[];
extern const u8 ken_btca[];
extern const u8 ken_caca[];
extern const u8 ken_cat_box[];
extern const u8 ken_catt_table[];
extern const u8 ken_cau_box[];
extern const u8 ken_cbca[];
extern const u8 ken_cuca[];
extern const u8 ken_dmca[];
extern const u8 ken_exca[];
extern const u8 ken_hand_box[];
extern const u8 ken_hit_ix_table[];
extern const u8 ken_hos_box[];
extern const u8 ken_movexy_table[];
extern const u8 ken_nmca[];
extern const u8 ken_olc_ix_table[];
extern const u8 ken_overlap_char_tbl[];
extern const u8 ken_rival_catch_tbl[];
extern const u8 ken_saca[];
extern const u8 ken_se_random_table[];
extern const u8 ken_stepxy_table[];
extern const u8 ken_yuca[];
extern const u8 necro_atca[];
extern const u8 necro_att_box[];
extern const u8 necro_body_box[];
extern const u8 necro_btca[];
extern const u8 necro_caca[];
extern const u8 necro_cat_box[];
extern const u8 necro_catt_table[];
extern const u8 necro_cau_box[];
extern const u8 necro_cbca[];
extern const u8 necro_cuca[];
extern const u8 necro_dmca[];
extern const u8 necro_exca[];
extern const u8 necro_hand_box[];
extern const u8 necro_hit_ix_table[];
extern const u8 necro_hos_box[];
extern const u8 necro_movexy_table[];
extern const u8 necro_nmca[];
extern const u8 necro_olc_ix_table[];
extern const u8 necro_overlap_char_tbl[];
extern const u8 necro_rival_catch_tbl[];
extern const u8 necro_saca[];
extern const u8 necro_se_random_table[];
extern const u8 necro_stepxy_table[];
extern const u8 necro_yuca[];
extern const u8 oro_atca[];
extern const u8 oro_att_box[];
extern const u8 oro_body_box[];
extern const u8 oro_btca[];
extern const u8 oro_caca[];
extern const u8 oro_cat_box[];
extern const u8 oro_catt_table[];
extern const u8 oro_cau_box[];
extern const u8 oro_cbca[];
extern const u8 oro_olc_ix_table[];
extern const u8 oro_cuca[];
extern const u8 oro_dmca[];
extern const u8 oro_exca[];
extern const u8 oro_hand_box[];
extern const u8 oro_hit_ix_table[];
extern const u8 oro_hos_box[];
extern const u8 oro_movexy_table[];
extern const u8 oro_nmca[];
extern const u8 oro_overlap_char_tbl[];
extern const u8 oro_rival_catch_tbl[];
extern const u8 oro_saca[];
extern const u8 oro_se_random_table[];
extern const u8 oro_stepxy_table[];
extern const u8 oro_yuca[];
extern const u8 ryu_atca[];
extern const u8 ryu_att_box[];
extern const u8 ryu_body_box[];
extern const u8 ryu_btca[];
extern const u8 ryu_caca[];
extern const u8 ryu_cat_box[];
extern const u8 ryu_catt_table[];
extern const u8 ryu_cau_box[];
extern const u8 ryu_cbca[];
extern const u8 ryu_cuca[];
extern const u8 ryu_dmca[];
extern const u8 ryu_exca[];
extern const u8 ryu_hand_box[];
extern const u8 ryu_hit_ix_table[];
extern const u8 ryu_hos_box[];
extern const u8 ryu_movexy_table[];
extern const u8 ryu_nmca[];
extern const u8 ryu_olc_ix_table[];
extern const u8 ryu_overlap_char_tbl[];
extern const u8 ryu_rival_catch_tbl[];
extern const u8 ryu_saca[];
extern const u8 ryu_se_random_table[];
extern const u8 ryu_stepxy_table[];
extern const u8 ryu_yuca[];
extern const u8 sean_atca[];
extern const u8 sean_body_box[];
extern const u8 sean_btca[];
extern const u8 sean_caca[];
extern const u8 sean_cat_box[];
extern const u8 sean_cau_box[];
extern const u8 sean_cbca[];
extern const u8 sean_cuca[];
extern const u8 sean_dmca[];
extern const u8 sean_exca[];
extern const u8 sean_hand_box[];
extern const u8 sean_hit_ix_table[];
extern const u8 sean_hos_box[];
extern const u8 sean_movexy_table[];
extern const u8 sean_nmca[];
extern const u8 sean_olc_ix_table[];
extern const u8 sean_overlap_char_tbl[];
extern const u8 sean_rival_catch_tbl[];
extern const u8 sean_saca[];
extern const u8 sean_se_random_table[];
extern const u8 sean_stepxy_table[];
extern const u8 sean_yuca[];
extern const u8 urien_atca[];
extern const u8 urien_att_box[];
extern const u8 urien_body_box[];
extern const u8 urien_btca[];
extern const u8 urien_caca[];
extern const u8 urien_cat_box[];
extern const u8 urien_catt_table[];
extern const u8 urien_cau_box[];
extern const u8 urien_cbca[];
extern const u8 urien_cuca[];
extern const u8 urien_dmca[];
extern const u8 urien_exca[];
extern const u8 urien_hand_box[];
extern const u8 urien_hit_ix_table[];
extern const u8 urien_hos_box[];
extern const u8 urien_movexy_table[];
extern const u8 urien_nmca[];
extern const u8 urien_olc_ix_table[];
extern const u8 urien_overlap_char_tbl[];
extern const u8 urien_rival_catch_tbl[];
extern const u8 urien_saca[];
extern const u8 urien_se_random_table[];
extern const u8 urien_stepxy_table[];
extern const u8 urien_yuca[];
extern const u8 yang_atca[];
extern const u8 yang_att_box[];
extern const u8 yang_body_box[];
extern const u8 yang_btca[];
extern const u8 yang_caca[];
extern const u8 yang_cat_box[];
extern const u8 yang_cau_box[];
extern const u8 yang_cbca[];
extern const u8 yang_cuca[];
extern const u8 yang_dmca[];
extern const u8 yang_exca[];
extern const u8 yang_hand_box[];
extern const u8 yang_hit_ix_table[];
extern const u8 yang_hos_box[];
extern const u8 yang_movexy_table[];
extern const u8 yang_nmca[];
extern const u8 yang_olc_ix_table[];
extern const u8 yang_overlap_char_tbl[];
extern const u8 yang_rival_catch_tbl[];
extern const u8 yang_saca[];
extern const u8 yang_se_random_table[];
extern const u8 yang_stepxy_table[];
extern const u8 yang_yuca[];
extern const u8 yun_atca[];
extern const u8 yun_att_box[];
extern const u8 yun_body_box[];
extern const u8 yun_btca[];
extern const u8 yun_caca[];
extern const u8 yun_cat_box[];
extern const u8 yun_catt_table[];
extern const u8 yun_cau_box[];
extern const u8 yun_cbca[];
extern const u8 yun_rival_catch_tbl[];
extern const u8 yun_cuca[];
extern const u8 yun_dmca[];
extern const u8 yun_exca[];
extern const u8 yun_hand_box[];
extern const u8 yun_hit_ix_table[];
extern const u8 yun_hos_box[];
extern const u8 yun_movexy_table[];
extern const u8 yun_nmca[];
extern const u8 yun_olc_ix_table[];
extern const u8 yun_overlap_char_tbl[];
extern const u8 yun_saca[];
extern const u8 yun_se_random_table[];
extern const u8 yun_stepxy_table[];
extern const u8 yun_yuca[];

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

const u16 sel_sp_ch_tbl[5] = {
    1, 1, 0x101, 0x101, 0x100,
};

const u16 rsix_r_table[34] = {
    0x3D, 1, 0x79, 2, 0xB5, 3, 0xF1, 4,
    0x12D, 5, 0x169, 6, 0x1A5, 7, 0x1E1, 8,
    0x21D, 9, 0x259, 0xA, 0x295, 0xB, 0x2D1, 0xC,
    0x30D, 0xD, 0x349, 0xE, 0x385, 0xF, 0x3C1, 0x10,
    0x3E7, 0x11,
};

const u16 attr_flame_tbl[82] = {
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

const u16 attr_thunder_tbl[82] = {
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

const u16 attr_freeze_tbl[82] = {
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

const u16 sky_nm_damage_tbl[82] = {
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

const u16 sky_nm2_damage_tbl[82] = {
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

const u16 sky_sp_damage_tbl[82] = {
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

const u16 kagami_damage_tbl[82] = {
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

const u16 kagami2_damage_tbl[82] = {
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

const u16 grd_hand_damage_tbl[82] = {
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

const u16 trdm_damage_tbl[41] = {
    0x101, 0x101, 0x101, 0x100, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0,
};

const u16 ttk_damage_req_tbl[41] = {
    0, 0, 0, 1, 0x100, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 0x100, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0x100,
    1, 0x100, 0, 0, 0, 0x100, 0, 0x101,
    0,
};

const u16 parisucc_pts[40] = {
    0xA0B, 0xC0D, 0xE0F, 0x1011, 0x1213, 0x1416, 0x181A, 0x1C1E,
    0x2022, 0x2426, 0x282C, 0x3034, 0x383C, 0x4044, 0x484C, 0x5054,
    0x585C, 0x6064, 0x6464, 0x6464, 0x1414, 0x1414, 0x1414, 0x1414,
    0x1414, 0x1414, 0x1414, 0x1414, 0x1414, 0x1414, 0x1414, 0x1414,
    0x1414, 0x1414, 0x1414, 0x1414, 0x1414, 0x1414, 0x1414, 0x1414,
};

const u16 dm_oiuchi_catch[16] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0x100, 0x101, 0x100, 1, 1, 0x100, 1, 0x1FF,
};
