/*
 * EFFECT_TBL.C  tables read by CHARMOVE.c, EFF00.c and 2 other modules
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const effmovejptbl[])();
extern void (*const effinitjptbl[])();
extern void (*const effinitjp_quake_y[])();
extern const u16 jdb[];
extern const u16 jdb2[];
extern const u16 parts_colmd_table[];
extern const u16 parts_colcd_table[];
extern void clear_caution_flag();
extern void effect_00_move();
extern void effect_01_move();
extern void effect_02_move();
extern void effect_03_init();
extern void effect_03_move();
extern void effect_04_move();
extern void effect_05_move();
extern void effect_06_move();
extern void effect_07_move();
extern void effect_08_move();
extern void effect_09_init();
extern void effect_09_init2();
extern void effect_09_move();
extern void effect_10_move();
extern void effect_11_move();
extern void effect_12_move();
extern void effect_13_init();
extern void effect_13_move();
extern void effect_14_move();
extern void effect_15_move();
extern void effect_16_move();
extern void effect_17_move();
extern void effect_18_move();
extern void effect_19_move();
extern void effect_20_move();
extern void effect_21_move();
extern void effect_22_move();
extern void effect_23_move();
extern void effect_24_move();
extern void effect_25_move();
extern void effect_26_move();
extern void effect_27_move();
extern void effect_28_move();
extern void effect_29_move();
extern void effect_30_move();
extern void effect_31_move();
extern void effect_32_move();
extern void effect_33_move();
extern void effect_34_init();
extern void effect_34_move();
extern void effect_35_move();
extern void effect_36_move();
extern void effect_37_init();
extern void effect_37_move();
extern void effect_38_move();
extern void effect_39_move();
extern void effect_40_move();
extern void effect_41_init();
extern void effect_41_move();
extern void effect_42_move();
extern void effect_43_move();
extern void effect_44_move();
extern void effect_45_move();
extern void effect_46_move();
extern void effect_47_init();
extern void effect_47_move();
extern void effect_48_move();
extern void effect_49_move();
extern void effect_50_move();
extern void effect_51_move();
extern void effect_52_move();
extern void effect_53_move();
extern void effect_54_init();
extern void effect_54_move();
extern void effect_55_move();
extern void effect_56_move();
extern void effect_57_move();
extern void effect_58_move();
extern void effect_59_move();
extern void effect_60_move();
extern void effect_61_move();
extern void effect_62_move();
extern void effect_63_move();
extern void effect_64_move();
extern void effect_65_move();
extern void effect_66_move();
extern void effect_67_move();
extern void effect_68_move();
extern void effect_69_move();
extern void effect_70_move();
extern void effect_71_move();
extern void effect_72_move();
extern void effect_73_move();
extern void effect_74_move();
extern void effect_75_move();
extern void effect_76_move();
extern void effect_77_init();
extern void effect_77_move();
extern void effect_78_move();
extern void effect_79_move();
extern void effect_80_move();
extern void effect_81_move();
extern void effect_82_move();
extern void effect_83_move();
extern void effect_84_move();
extern void effect_85_move();
extern void effect_86_move();
extern void effect_87_move();
extern void effect_88_move();
extern void effect_89_move();
extern void effect_90_move();
extern void effect_91_move();
extern void effect_92_move();
extern void effect_93_move();
extern void effect_94_move();
extern void effect_95_move();
extern void effect_96_move();
extern void effect_97_move();
extern void effect_98_move();
extern void effect_99_move();
extern void effect_A0_move();
extern void effect_A1_move();
extern void effect_A2_move();
extern void effect_A3_move();
extern void effect_A4_move();
extern void effect_A5_move();
extern void effect_A6_move();
extern void effect_A7_move();
extern void effect_A8_move();
extern void effect_A9_move();
extern void effect_B0_move();
extern void effect_B1_move();
extern void effect_B2_move();
extern void effect_B3_move();
extern void effect_B4_move();
extern void effect_B5_move();
extern void effect_B6_move();
extern void effect_B7_move();
extern void effect_B8_move();
extern void effect_B9_move();
extern void effect_C0_init();
extern void effect_C0_move();
extern void effect_C1_move();
extern void effect_C2_move();
extern void effect_C3_move();
extern void effect_C4_move();
extern void effect_C5_move();
extern void effect_C6_move();
extern void effect_C7_init();
extern void effect_C7_move();
extern void effect_C8_move();
extern void effect_C9_move();
extern void effect_D0_init();
extern void effect_D0_move();
extern void effect_D1_init();
extern void effect_D1_move();
extern void effect_D2_move();
extern void effect_D3_move();
extern void effect_D4_init();
extern void effect_D4_move();
extern void effect_D5_init();
extern void effect_D5_move();
extern void effect_D6_init();
extern void effect_D6_move();
extern void effect_D7_move();
extern void effect_D8_move();
extern void effect_D9_init();
extern void effect_D9_move();
extern void effect_E0_move();
extern void effect_E1_move();
extern void effect_E2_move();
extern void effect_E3_move();
extern void effect_E4_move();
extern void effect_E5_move();
extern void effect_E6_move();
extern void effect_E7_move();
extern void effect_E8_move();
extern void effect_E9_move();
extern void effect_F0_move();
extern void effect_F1_init();
extern void effect_F1_move();
extern void effect_F2_move();
extern void effect_F3_move();
extern void effect_F4_init();
extern void effect_F4_move();
extern void effect_F5_move();
extern void effect_F6_move();
extern void effect_F7_move();
extern void effect_F8_init();
extern void effect_F8_move();
extern void effect_F9_move();
extern void effect_G0_init();
extern void effect_G0_move();
extern void effect_G1_move();
extern void effect_G2_move();
extern void effect_G3_init();
extern void effect_G3_move();
extern void effect_G4_init();
extern void effect_G4_move();
extern void effect_G5_move();
extern void effect_G6_init();
extern void effect_G6_move();
extern void effect_G7_move();
extern void effect_G8_move();
extern void effect_G9_move();
extern void effect_H0_move();
extern void effect_H1_move();
extern void effect_H2_move();
extern void effect_H3_move();
extern void effect_H4_move();
extern void effect_H5_move();
extern void effect_H6_move();
extern void effect_H7_init();
extern void effect_H7_move();
extern void effect_H8_init();
extern void effect_H8_move();
extern void effect_H9_init();
extern void effect_H9_move();
extern void effect_I0_init();
extern void effect_I0_move();
extern void effect_I1_move();
extern void effect_I2_move();
extern void effect_I3_move();
extern void effect_I4_move();
extern void effect_I5_move();
extern void effect_I6_move();
extern void effect_I7_init();
extern void effect_I7_move();
extern void effect_I8_move();
extern void effect_I9_move();
extern void effect_J0_move();
extern void effect_J1_move();
extern void effect_J2_move();
extern void effect_J3_init();
extern void effect_J3_move();
extern void erase_after_images();
extern void exec_char_asxy();
extern void flip_my_rl_flag();
extern void reset_extra_bg_flag();
extern void set_caution_flag();
extern void set_tenguiwa();
extern void setup_accessories();
extern void setup_after_images();
extern void setup_ase_extra();
extern void setup_bg_quake_x();
extern void setup_bg_quake_y();
extern void setup_command_number();
extern void setup_disp_flag();
extern void setup_dmv_use_flag();
extern void setup_exdm_ix();
extern void setup_free_program();
extern void setup_meoshi_hit_flag();
extern void setup_status_flag();

void (*const effmovejptbl[194])() = {
    (void (*)())effect_00_move,
    (void (*)())effect_01_move,
    (void (*)())effect_02_move,
    (void (*)())effect_03_move,
    (void (*)())effect_04_move,
    (void (*)())effect_05_move,
    (void (*)())effect_06_move,
    (void (*)())effect_07_move,
    (void (*)())effect_08_move,
    (void (*)())effect_09_move,
    (void (*)())effect_10_move,
    (void (*)())effect_11_move,
    (void (*)())effect_12_move,
    (void (*)())effect_13_move,
    (void (*)())effect_14_move,
    (void (*)())effect_15_move,
    (void (*)())effect_16_move,
    (void (*)())effect_17_move,
    (void (*)())effect_18_move,
    (void (*)())effect_19_move,
    (void (*)())effect_20_move,
    (void (*)())effect_21_move,
    (void (*)())effect_22_move,
    (void (*)())effect_23_move,
    (void (*)())effect_24_move,
    (void (*)())effect_25_move,
    (void (*)())effect_26_move,
    (void (*)())effect_27_move,
    (void (*)())effect_28_move,
    (void (*)())effect_29_move,
    (void (*)())effect_30_move,
    (void (*)())effect_31_move,
    (void (*)())effect_32_move,
    (void (*)())effect_33_move,
    (void (*)())effect_34_move,
    (void (*)())effect_35_move,
    (void (*)())effect_36_move,
    (void (*)())effect_37_move,
    (void (*)())effect_38_move,
    (void (*)())effect_39_move,
    (void (*)())effect_40_move,
    (void (*)())effect_41_move,
    (void (*)())effect_42_move,
    (void (*)())effect_43_move,
    (void (*)())effect_44_move,
    (void (*)())effect_45_move,
    (void (*)())effect_46_move,
    (void (*)())effect_47_move,
    (void (*)())effect_48_move,
    (void (*)())effect_49_move,
    (void (*)())effect_50_move,
    (void (*)())effect_51_move,
    (void (*)())effect_52_move,
    (void (*)())effect_53_move,
    (void (*)())effect_54_move,
    (void (*)())effect_55_move,
    (void (*)())effect_56_move,
    (void (*)())effect_57_move,
    (void (*)())effect_58_move,
    (void (*)())effect_59_move,
    (void (*)())effect_60_move,
    (void (*)())effect_61_move,
    (void (*)())effect_62_move,
    (void (*)())effect_63_move,
    (void (*)())effect_64_move,
    (void (*)())effect_65_move,
    (void (*)())effect_66_move,
    (void (*)())effect_67_move,
    (void (*)())effect_68_move,
    (void (*)())effect_69_move,
    (void (*)())effect_70_move,
    (void (*)())effect_71_move,
    (void (*)())effect_72_move,
    (void (*)())effect_73_move,
    (void (*)())effect_74_move,
    (void (*)())effect_75_move,
    (void (*)())effect_76_move,
    (void (*)())effect_77_move,
    (void (*)())effect_78_move,
    (void (*)())effect_79_move,
    (void (*)())effect_80_move,
    (void (*)())effect_81_move,
    (void (*)())effect_82_move,
    (void (*)())effect_83_move,
    (void (*)())effect_84_move,
    (void (*)())effect_85_move,
    (void (*)())effect_86_move,
    (void (*)())effect_87_move,
    (void (*)())effect_88_move,
    (void (*)())effect_89_move,
    (void (*)())effect_90_move,
    (void (*)())effect_91_move,
    (void (*)())effect_92_move,
    (void (*)())effect_93_move,
    (void (*)())effect_94_move,
    (void (*)())effect_95_move,
    (void (*)())effect_96_move,
    (void (*)())effect_97_move,
    (void (*)())effect_98_move,
    (void (*)())effect_99_move,
    (void (*)())effect_A0_move,
    (void (*)())effect_A1_move,
    (void (*)())effect_A2_move,
    (void (*)())effect_A3_move,
    (void (*)())effect_A4_move,
    (void (*)())effect_A5_move,
    (void (*)())effect_A6_move,
    (void (*)())effect_A7_move,
    (void (*)())effect_A8_move,
    (void (*)())effect_A9_move,
    (void (*)())effect_B0_move,
    (void (*)())effect_B1_move,
    (void (*)())effect_B2_move,
    (void (*)())effect_B3_move,
    (void (*)())effect_B4_move,
    (void (*)())effect_B5_move,
    (void (*)())effect_B6_move,
    (void (*)())effect_B7_move,
    (void (*)())effect_B8_move,
    (void (*)())effect_B9_move,
    (void (*)())effect_C0_move,
    (void (*)())effect_C1_move,
    (void (*)())effect_C2_move,
    (void (*)())effect_C3_move,
    (void (*)())effect_C4_move,
    (void (*)())effect_C5_move,
    (void (*)())effect_C6_move,
    (void (*)())effect_C7_move,
    (void (*)())effect_C8_move,
    (void (*)())effect_C9_move,
    (void (*)())effect_D0_move,
    (void (*)())effect_D1_move,
    (void (*)())effect_D2_move,
    (void (*)())effect_D3_move,
    (void (*)())effect_D4_move,
    (void (*)())effect_D5_move,
    (void (*)())effect_D6_move,
    (void (*)())effect_D7_move,
    (void (*)())effect_D8_move,
    (void (*)())effect_D9_move,
    (void (*)())effect_E0_move,
    (void (*)())effect_E1_move,
    (void (*)())effect_E2_move,
    (void (*)())effect_E3_move,
    (void (*)())effect_E4_move,
    (void (*)())effect_E5_move,
    (void (*)())effect_E6_move,
    (void (*)())effect_E7_move,
    (void (*)())effect_E8_move,
    (void (*)())effect_E9_move,
    (void (*)())effect_F0_move,
    (void (*)())effect_F1_move,
    (void (*)())effect_F2_move,
    (void (*)())effect_F3_move,
    (void (*)())effect_F4_move,
    (void (*)())effect_F5_move,
    (void (*)())effect_F6_move,
    (void (*)())effect_F7_move,
    (void (*)())effect_F8_move,
    (void (*)())effect_F9_move,
    (void (*)())effect_G0_move,
    (void (*)())effect_G1_move,
    (void (*)())effect_G2_move,
    (void (*)())effect_G3_move,
    (void (*)())effect_G4_move,
    (void (*)())effect_G5_move,
    (void (*)())effect_G6_move,
    (void (*)())effect_G7_move,
    (void (*)())effect_G8_move,
    (void (*)())effect_G9_move,
    (void (*)())effect_H0_move,
    (void (*)())effect_H1_move,
    (void (*)())effect_H2_move,
    (void (*)())effect_H3_move,
    (void (*)())effect_H4_move,
    (void (*)())effect_H5_move,
    (void (*)())effect_H6_move,
    (void (*)())effect_H7_move,
    (void (*)())effect_H8_move,
    (void (*)())effect_H9_move,
    (void (*)())effect_I0_move,
    (void (*)())effect_I1_move,
    (void (*)())effect_I2_move,
    (void (*)())effect_I3_move,
    (void (*)())effect_I4_move,
    (void (*)())effect_I5_move,
    (void (*)())effect_I6_move,
    (void (*)())effect_I7_move,
    (void (*)())effect_I8_move,
    (void (*)())effect_I9_move,
    (void (*)())effect_J0_move,
    (void (*)())effect_J1_move,
    (void (*)())effect_J2_move,
    (void (*)())effect_J3_move,
};

void (*const effinitjptbl[39])() = {
    0,
    (void (*)())effect_03_init,
    (void (*)())effect_13_init,
    (void (*)())effect_09_init,
    (void (*)())effect_54_init,
    (void (*)())effect_C0_init,
    (void (*)())effect_C7_init,
    (void (*)())effect_D0_init,
    (void (*)())effect_D1_init,
    (void (*)())effect_F4_init,
    (void (*)())effect_34_init,
    (void (*)())effect_37_init,
    (void (*)())effect_09_init2,
    (void (*)())effect_41_init,
    (void (*)())effect_D4_init,
    (void (*)())set_tenguiwa,
    (void (*)())effect_D9_init,
    (void (*)())setup_accessories,
    (void (*)())setup_after_images,
    (void (*)())erase_after_images,
    (void (*)())effect_F1_init,
    (void (*)())clear_caution_flag,
    (void (*)())setup_status_flag,
    (void (*)())reset_extra_bg_flag,
    (void (*)())flip_my_rl_flag,
    (void (*)())effect_F8_init,
    (void (*)())effect_G0_init,
    (void (*)())effect_G3_init,
    (void (*)())effect_G4_init,
    (void (*)())setup_ase_extra,
    (void (*)())effect_G6_init,
    (void (*)())setup_meoshi_hit_flag,
    (void (*)())exec_char_asxy,
    (void (*)())set_caution_flag,
    (void (*)())effect_H7_init,
    (void (*)())effect_H8_init,
    (void (*)())effect_H9_init,
    (void (*)())setup_free_program,
    (void (*)())setup_bg_quake_x,
};

void (*const effinitjp_quake_y[12])() = {
    (void (*)())setup_bg_quake_y,
    (void (*)())effect_47_init,
    (void (*)())effect_I0_init,
    (void (*)())effect_77_init,
    (void (*)())setup_exdm_ix,
    (void (*)())setup_dmv_use_flag,
    (void (*)())effect_D5_init,
    (void (*)())effect_D6_init,
    (void (*)())setup_disp_flag,
    (void (*)())setup_command_number,
    (void (*)())effect_I7_init,
    (void (*)())effect_J3_init,
};

const u16 jdb[16] = {
    0x6000, 0x603F, 0x6F00, 0x6F3F, 0x60C0, 0x60FF, 0x6FC0, 0x6FFF,
    0x7000, 0x703F, 0x7F00, 0x7F3F, 0x70C0, 0x70FF, 0x7FC0, 0x7FFF,
};

const u16 jdb2[16] = {
    2, 0x1A, 0x12, 0x2A, 0xA, 0x22, 0x1A, 0x32,
    6, 0x1E, 0x16, 0x2E, 0xE, 0x26, 0x1E, 0x36,
};

const u16 parts_colmd_table[2] = {
    0x4000, 0,
};

const u16 parts_colcd_table[10] = {
    0x2000, 0, 6, 0x2000, 4, 0x2020, 4, 4,
    0, 0xFFFF,
};
