/*
 * EFFECT_CHAR.C  Effect character scripts
 *
 * Scripts for effects drawn with character data: player effects (plef), ef01, the ef13 effect, effect G0's
 * character sets, the rival face panels (ag_face_panel_table) and effD4; effect_unref_char_table is read
 * by nothing.
 * Each *_char_table is an index of animation scripts ending in 0; set_char_move_init starts script
 * char_table[kind][index], whose HEAD sits just before the address the index holds. See charscr.h for
 * the line layouts.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

extern const u32 plef_char_table[];
extern const u16 plef_char_table_000_head[];
extern const u16 plef_char_table_000[];
extern const u16 plef_char_table_001_head[];
extern const u16 plef_char_table_001[];
extern const u16 plef_char_table_002_head[];
extern const u16 plef_char_table_002[];
extern const u16 plef_char_table_003_head[];
extern const u16 plef_char_table_003[];
extern const u16 plef_char_table_004_head[];
extern const u16 plef_char_table_004[];
extern const u16 plef_char_table_005_head[];
extern const u16 plef_char_table_005[];
extern const u16 plef_char_table_006_head[];
extern const u16 plef_char_table_006[];
extern const u16 plef_char_table_007_head[];
extern const u16 plef_char_table_007[];
extern const u16 plef_char_table_008_head[];
extern const u16 plef_char_table_008[];
extern const u16 plef_char_table_009_head[];
extern const u16 plef_char_table_009[];
extern const u16 plef_char_table_010_head[];
extern const u16 plef_char_table_010[];
extern const u16 plef_char_table_011_head[];
extern const u16 plef_char_table_011[];
extern const u16 plef_char_table_012_head[];
extern const u16 plef_char_table_012[];
extern const u16 plef_char_table_013_head[];
extern const u16 plef_char_table_013[];
extern const u16 plef_char_table_014_head[];
extern const u16 plef_char_table_014[];
extern const u16 plef_char_table_015_head[];
extern const u16 plef_char_table_015[];
extern const u16 plef_char_table_016_head[];
extern const u16 plef_char_table_016[];
extern const u16 plef_char_table_017_head[];
extern const u16 plef_char_table_017[];
extern const u16 plef_char_table_018_head[];
extern const u16 plef_char_table_018[];
extern const u16 plef_char_table_019_head[];
extern const u16 plef_char_table_019[];
extern const u16 plef_char_table_020_head[];
extern const u16 plef_char_table_020[];
extern const u16 plef_char_table_021_head[];
extern const u16 plef_char_table_021[];
extern const u16 plef_char_table_022_head[];
extern const u16 plef_char_table_022[];
extern const u16 plef_char_table_023_head[];
extern const u16 plef_char_table_023[];
extern const u16 plef_char_table_024_head[];
extern const u16 plef_char_table_024[];
extern const u16 plef_char_table_025_head[];
extern const u16 plef_char_table_025[];
extern const u16 plef_char_table_026_head[];
extern const u16 plef_char_table_026[];
extern const u16 plef_char_table_027_head[];
extern const u16 plef_char_table_027[];
extern const u16 plef_char_table_028_head[];
extern const u16 plef_char_table_028[];
extern const u16 plef_char_table_029_head[];
extern const u16 plef_char_table_029[];
extern const u16 plef_char_table_030_head[];
extern const u16 plef_char_table_030[];
extern const u16 plef_char_table_031_head[];
extern const u16 plef_char_table_031[];
extern const u16 plef_char_table_032_head[];
extern const u16 plef_char_table_032[];
extern const u16 plef_char_table_033_head[];
extern const u16 plef_char_table_033[];
extern const u16 plef_char_table_034_head[];
extern const u16 plef_char_table_034[];
extern const u16 plef_char_table_035_head[];
extern const u16 plef_char_table_035[];
extern const u16 plef_char_table_036_head[];
extern const u16 plef_char_table_036[];
extern const u16 plef_char_table_037_head[];
extern const u16 plef_char_table_037[];
extern const u16 plef_char_table_038_head[];
extern const u16 plef_char_table_038[];
extern const u16 plef_char_table_039_head[];
extern const u16 plef_char_table_039[];
extern const u16 plef_char_table_040_head[];
extern const u16 plef_char_table_040[];
extern const u16 plef_char_table_041_head[];
extern const u16 plef_char_table_041[];
extern const u16 plef_char_table_042_head[];
extern const u16 plef_char_table_042[];
extern const u16 plef_char_table_043_head[];
extern const u16 plef_char_table_043[];
extern const u16 plef_char_table_044_head[];
extern const u16 plef_char_table_044[];
extern const u16 plef_char_table_045_head[];
extern const u16 plef_char_table_045[];
extern const u16 plef_char_table_046_head[];
extern const u16 plef_char_table_046[];
extern const u16 plef_char_table_047_head[];
extern const u16 plef_char_table_047[];
extern const u16 plef_char_table_048_head[];
extern const u16 plef_char_table_048[];
extern const u16 plef_char_table_049_head[];
extern const u16 plef_char_table_049[];
extern const u16 plef_char_table_050_head[];
extern const u16 plef_char_table_050[];
extern const u16 plef_char_table_051_head[];
extern const u16 plef_char_table_051[];
extern const u16 plef_char_table_052_head[];
extern const u16 plef_char_table_052[];
extern const u16 plef_char_table_053_head[];
extern const u16 plef_char_table_053[];
extern const u16 plef_char_table_054_head[];
extern const u16 plef_char_table_054[];
extern const u16 plef_char_table_055_head[];
extern const u16 plef_char_table_055[];
extern const u16 plef_char_table_056_head[];
extern const u16 plef_char_table_056[];
extern const u16 plef_char_table_057_head[];
extern const u16 plef_char_table_057[];
extern const u16 plef_char_table_058_head[];
extern const u16 plef_char_table_058[];
extern const u16 plef_char_table_059_head[];
extern const u16 plef_char_table_059[];
extern const u16 plef_char_table_060_head[];
extern const u16 plef_char_table_060[];
extern const u16 plef_char_table_061_head[];
extern const u16 plef_char_table_061[];
extern const u16 plef_char_table_062_head[];
extern const u16 plef_char_table_062[];
extern const u16 plef_char_table_063_head[];
extern const u16 plef_char_table_063[];
extern const u16 plef_char_table_064_head[];
extern const u16 plef_char_table_064[];
extern const u16 plef_char_table_065_head[];
extern const u16 plef_char_table_065[];
extern const u16 plef_char_table_066_head[];
extern const u16 plef_char_table_066[];
extern const u16 plef_char_table_067_head[];
extern const u16 plef_char_table_067[];
extern const u16 plef_char_table_068_head[];
extern const u16 plef_char_table_068[];
extern const u16 plef_char_table_069_head[];
extern const u16 plef_char_table_069[];
extern const u16 plef_char_table_070_head[];
extern const u16 plef_char_table_070[];
extern const u16 plef_char_table_071_head[];
extern const u16 plef_char_table_071[];
extern const u16 plef_char_table_072_head[];
extern const u16 plef_char_table_072[];
extern const u16 plef_char_table_073_head[];
extern const u16 plef_char_table_073[];
extern const u16 plef_char_table_074_head[];
extern const u16 plef_char_table_074[];
extern const u16 plef_char_table_075_head[];
extern const u16 plef_char_table_075[];
extern const u16 plef_char_table_076_head[];
extern const u16 plef_char_table_076[];
extern const u16 plef_char_table_077_head[];
extern const u16 plef_char_table_077[];
extern const u16 plef_char_table_078_head[];
extern const u16 plef_char_table_078[];
extern const u16 plef_char_table_079_head[];
extern const u16 plef_char_table_079[];
extern const u16 plef_char_table_080_head[];
extern const u16 plef_char_table_080[];
extern const u16 plef_char_table_081_head[];
extern const u16 plef_char_table_081[];
extern const u16 plef_char_table_082_head[];
extern const u16 plef_char_table_082[];
extern const u16 plef_char_table_083_head[];
extern const u16 plef_char_table_083[];
extern const u16 plef_char_table_084_head[];
extern const u16 plef_char_table_084[];
extern const u16 plef_char_table_085_head[];
extern const u16 plef_char_table_085[];
extern const u16 plef_char_table_086_head[];
extern const u16 plef_char_table_086[];
extern const u16 plef_char_table_087_head[];
extern const u16 plef_char_table_087[];
extern const u16 plef_char_table_090_head[];
extern const u16 plef_char_table_090[];
extern const u16 plef_char_table_091_head[];
extern const u16 plef_char_table_091[];
extern const u16 plef_char_table_092_head[];
extern const u16 plef_char_table_092[];
extern const u16 plef_char_table_093_head[];
extern const u16 plef_char_table_093[];
extern const u16 plef_char_table_094_head[];
extern const u16 plef_char_table_094[];
extern const u16 plef_char_table_095_head[];
extern const u16 plef_char_table_095[];
extern const u16 plef_char_table_096_head[];
extern const u16 plef_char_table_096[];
extern const u16 plef_char_table_097_head[];
extern const u16 plef_char_table_097[];
extern const u16 plef_char_table_098_head[];
extern const u16 plef_char_table_098[];
extern const u16 plef_char_table_099_head[];
extern const u16 plef_char_table_099[];
extern const u16 plef_char_table_100_head[];
extern const u16 plef_char_table_100[];
extern const u16 plef_char_table_101_head[];
extern const u16 plef_char_table_101[];
extern const u16 plef_char_table_102_head[];
extern const u16 plef_char_table_102[];
extern const u16 plef_char_table_103_head[];
extern const u16 plef_char_table_103[];
extern const u16 plef_char_table_104_head[];
extern const u16 plef_char_table_104[];
extern const u16 plef_char_table_105_head[];
extern const u16 plef_char_table_105[];
extern const u16 plef_char_table_106_head[];
extern const u16 plef_char_table_106[];
extern const u16 plef_char_table_107_head[];
extern const u16 plef_char_table_107[];
extern const u16 plef_char_table_108_head[];
extern const u16 plef_char_table_108[];
extern const u16 plef_char_table_109_head[];
extern const u16 plef_char_table_109[];
extern const u16 plef_char_table_110_head[];
extern const u16 plef_char_table_110[];
extern const u16 plef_char_table_111_head[];
extern const u16 plef_char_table_111[];
extern const u16 plef_char_table_112_head[];
extern const u16 plef_char_table_112[];
extern const u16 plef_char_table_113_head[];
extern const u16 plef_char_table_113[];
extern const u16 plef_char_table_114_head[];
extern const u16 plef_char_table_114[];
extern const u16 plef_char_table_115_head[];
extern const u16 plef_char_table_115[];
extern const u16 plef_char_table_116_head[];
extern const u16 plef_char_table_116[];
extern const u16 plef_char_table_117_head[];
extern const u16 plef_char_table_117[];
extern const u16 plef_char_table_118_head[];
extern const u16 plef_char_table_118[];
extern const u16 plef_char_table_119_head[];
extern const u16 plef_char_table_119[];
extern const u16 plef_char_table_120_head[];
extern const u16 plef_char_table_120[];
extern const u16 plef_char_table_121_head[];
extern const u16 plef_char_table_121[];
extern const u16 plef_char_table_122_head[];
extern const u16 plef_char_table_122[];
extern const u16 plef_char_table_123_head[];
extern const u16 plef_char_table_123[];
extern const u16 plef_char_table_124_head[];
extern const u16 plef_char_table_124[];
extern const u16 plef_char_table_125_head[];
extern const u16 plef_char_table_125[];
extern const u16 plef_char_table_126_head[];
extern const u16 plef_char_table_126[];
extern const u16 plef_char_table_127_head[];
extern const u16 plef_char_table_127[];
extern const u16 plef_char_table_128_head[];
extern const u16 plef_char_table_128[];
extern const u16 plef_char_table_129_head[];
extern const u16 plef_char_table_129[];
extern const u16 plef_char_table_130_head[];
extern const u16 plef_char_table_130[];
extern const u16 plef_char_table_131_head[];
extern const u16 plef_char_table_131[];
extern const u16 plef_char_table_132_head[];
extern const u16 plef_char_table_132[];
extern const u16 plef_char_table_133_head[];
extern const u16 plef_char_table_133[];
extern const u16 plef_char_table_134_head[];
extern const u16 plef_char_table_134[];
extern const u16 plef_char_table_135_head[];
extern const u16 plef_char_table_135[];
extern const u16 plef_char_table_136_head[];
extern const u16 plef_char_table_136[];
extern const u16 plef_char_table_137_head[];
extern const u16 plef_char_table_137[];
extern const u16 plef_char_table_138_head[];
extern const u16 plef_char_table_138[];
extern const u16 plef_char_table_139_head[];
extern const u16 plef_char_table_139[];
extern const u16 plef_char_table_140_head[];
extern const u16 plef_char_table_140[];
extern const u16 plef_char_table_155_head[];
extern const u16 plef_char_table_155[];
extern const u16 plef_char_table_156_head[];
extern const u16 plef_char_table_156[];
extern const u16 plef_char_table_159_head[];
extern const u16 plef_char_table_159[];
extern const u16 plef_char_table_160_head[];
extern const u16 plef_char_table_160[];
extern const u16 plef_char_table_161_head[];
extern const u16 plef_char_table_161[];
extern const u16 plef_char_table_162_head[];
extern const u16 plef_char_table_162[];
extern const u16 plef_char_table_163_head[];
extern const u16 plef_char_table_163[];
extern const u16 plef_char_table_164_head[];
extern const u16 plef_char_table_164[];
extern const u16 plef_char_table_165_head[];
extern const u16 plef_char_table_165[];
extern const u16 plef_char_table_166_head[];
extern const u16 plef_char_table_166[];
extern const u16 plef_char_table_167_head[];
extern const u16 plef_char_table_167[];
extern const u16 plef_char_table_168_head[];
extern const u16 plef_char_table_168[];
extern const u16 plef_char_table_169_head[];
extern const u16 plef_char_table_169[];
extern const u32 ef01_char_table[];
extern const u16 ef01_char_table_000_head[];
extern const u16 ef01_char_table_000[];
extern const u16 ef01_char_table_001_head[];
extern const u16 ef01_char_table_001[];
extern const u16 ef01_char_table_002_head[];
extern const u16 ef01_char_table_002[];
extern const u16 ef01_char_table_003_head[];
extern const u16 ef01_char_table_003[];
extern const u16 ef01_char_table_004_head[];
extern const u16 ef01_char_table_004[];
extern const u16 ef01_char_table_005_head[];
extern const u16 ef01_char_table_005[];
extern const u16 ef01_char_table_006_head[];
extern const u16 ef01_char_table_006[];
extern const u16 ef01_char_table_008_head[];
extern const u16 ef01_char_table_008[];
extern const u16 ef01_char_table_009_head[];
extern const u16 ef01_char_table_009[];
extern const u16 ef01_char_table_010_head[];
extern const u16 ef01_char_table_010[];
extern const u16 ef01_char_table_011_head[];
extern const u16 ef01_char_table_011[];
extern const u16 ef01_char_table_012_head[];
extern const u16 ef01_char_table_012[];
extern const u16 ef01_char_table_013_head[];
extern const u16 ef01_char_table_013[];
extern const u16 ef01_char_table_014_head[];
extern const u16 ef01_char_table_014[];
extern const u16 ef01_char_table_015_head[];
extern const u16 ef01_char_table_015[];
extern const u16 ef01_char_table_016_head[];
extern const u16 ef01_char_table_016[];
extern const u16 ef01_char_table_017_head[];
extern const u16 ef01_char_table_017[];
extern const u16 ef01_char_table_018_head[];
extern const u16 ef01_char_table_018[];
extern const u16 ef01_char_table_019_head[];
extern const u16 ef01_char_table_019[];
extern const u16 ef01_char_table_020_head[];
extern const u16 ef01_char_table_020[];
extern const u16 ef01_char_table_021_head[];
extern const u16 ef01_char_table_021[];
extern const u16 ef01_char_table_022_head[];
extern const u16 ef01_char_table_022[];
extern const u16 ef01_char_table_023_head[];
extern const u16 ef01_char_table_023[];
extern const u16 ef01_char_table_024_head[];
extern const u16 ef01_char_table_024[];
extern const u16 ef01_char_table_025_head[];
extern const u16 ef01_char_table_025[];
extern const u16 ef01_char_table_026_head[];
extern const u16 ef01_char_table_026[];
extern const u16 ef01_char_table_027_head[];
extern const u16 ef01_char_table_027[];
extern const u16 ef01_char_table_028_head[];
extern const u16 ef01_char_table_028[];
extern const u16 ef01_char_table_029_head[];
extern const u16 ef01_char_table_029[];
extern const u16 ef01_char_table_031_head[];
extern const u16 ef01_char_table_031[];
extern const u16 ef01_char_table_032_head[];
extern const u16 ef01_char_table_032[];
extern const u16 ef01_char_table_033_head[];
extern const u16 ef01_char_table_033[];
extern const u16 ef01_char_table_034_head[];
extern const u16 ef01_char_table_034[];
extern const u16 ef01_char_table_035_head[];
extern const u16 ef01_char_table_035[];
extern const u16 ef01_char_table_036_head[];
extern const u16 ef01_char_table_036[];
extern const u16 ef01_char_table_038_head[];
extern const u16 ef01_char_table_038[];
extern const u16 ef01_char_table_039_head[];
extern const u16 ef01_char_table_039[];
extern const u16 ef01_char_table_040_head[];
extern const u16 ef01_char_table_040[];
extern const u32 ef13_char_table[];
extern const u16 ef13_char_table_000_head[];
extern const u16 ef13_char_table_000[];
extern const u16 ef13_char_table_001_head[];
extern const u16 ef13_char_table_001[];
extern const u16 ef13_char_table_002_head[];
extern const u16 ef13_char_table_002[];
extern const u16 ef13_char_table_003_head[];
extern const u16 ef13_char_table_003[];
extern const u16 ef13_char_table_004_head[];
extern const u16 ef13_char_table_004[];
extern const u16 ef13_char_table_005_head[];
extern const u16 ef13_char_table_005[];
extern const u16 ef13_char_table_006_head[];
extern const u16 ef13_char_table_006[];
extern const u16 ef13_char_table_007_head[];
extern const u16 ef13_char_table_007[];
extern const u16 ef13_char_table_008_head[];
extern const u16 ef13_char_table_008[];
extern const u16 ef13_char_table_010_head[];
extern const u16 ef13_char_table_010[];
extern const u16 ef13_char_table_011_head[];
extern const u16 ef13_char_table_011[];
extern const u16 ef13_char_table_013_head[];
extern const u16 ef13_char_table_013[];
extern const u16 ef13_char_table_014_head[];
extern const u16 ef13_char_table_014[];
extern const u16 ef13_char_table_015_head[];
extern const u16 ef13_char_table_015[];
extern const u16 ef13_char_table_016_head[];
extern const u16 ef13_char_table_016[];
extern const u16 ef13_char_table_017_head[];
extern const u16 ef13_char_table_017[];
extern const u16 ef13_char_table_018_head[];
extern const u16 ef13_char_table_018[];
extern const u16 ef13_char_table_019_head[];
extern const u16 ef13_char_table_019[];
extern const u16 ef13_char_table_020_head[];
extern const u16 ef13_char_table_020[];
extern const u16 ef13_char_table_021_head[];
extern const u16 ef13_char_table_021[];
extern const u16 ef13_char_table_022_head[];
extern const u16 ef13_char_table_022[];
extern const u16 ef13_char_table_023_head[];
extern const u16 ef13_char_table_023[];
extern const u16 ef13_char_table_024_head[];
extern const u16 ef13_char_table_024[];
extern const u16 ef13_char_table_025_head[];
extern const u16 ef13_char_table_025[];
extern const u16 ef13_char_table_026_head[];
extern const u16 ef13_char_table_026[];
extern const u16 ef13_char_table_027_head[];
extern const u16 ef13_char_table_027[];
extern const u16 ef13_char_table_028_head[];
extern const u16 ef13_char_table_028[];
extern const u16 ef13_char_table_029_head[];
extern const u16 ef13_char_table_029[];
extern const u16 ef13_char_table_030_head[];
extern const u16 ef13_char_table_030[];
extern const u16 ef13_char_table_031_head[];
extern const u16 ef13_char_table_031[];
extern const u16 ef13_char_table_032_head[];
extern const u16 ef13_char_table_032[];
extern const u16 ef13_char_table_033_head[];
extern const u16 ef13_char_table_033[];
extern const u16 ef13_char_table_034_head[];
extern const u16 ef13_char_table_034[];
extern const u16 ef13_char_table_035_head[];
extern const u16 ef13_char_table_035[];
extern const u16 ef13_char_table_036_head[];
extern const u16 ef13_char_table_036[];
extern const u16 ef13_char_table_037_head[];
extern const u16 ef13_char_table_037[];
extern const u16 ef13_char_table_038_head[];
extern const u16 ef13_char_table_038[];
extern const u16 ef13_char_table_039_head[];
extern const u16 ef13_char_table_039[];
extern const u16 ef13_char_table_040_head[];
extern const u16 ef13_char_table_040[];
extern const u16 ef13_char_table_041_head[];
extern const u16 ef13_char_table_041[];
extern const u16 ef13_char_table_042_head[];
extern const u16 ef13_char_table_042[];
extern const u16 ef13_char_table_043_head[];
extern const u16 ef13_char_table_043[];
extern const u16 ef13_char_table_044_head[];
extern const u16 ef13_char_table_044[];
extern const u16 ef13_char_table_045_head[];
extern const u16 ef13_char_table_045[];
extern const u16 ef13_char_table_046_head[];
extern const u16 ef13_char_table_046[];
extern const u16 ef13_char_table_047_head[];
extern const u16 ef13_char_table_047[];
extern const u16 ef13_char_table_048_head[];
extern const u16 ef13_char_table_048[];
extern const u16 ef13_char_table_049_head[];
extern const u16 ef13_char_table_049[];
extern const u16 ef13_char_table_050_head[];
extern const u16 ef13_char_table_050[];
extern const u16 ef13_char_table_051_head[];
extern const u16 ef13_char_table_051[];
extern const u16 ef13_char_table_052_head[];
extern const u16 ef13_char_table_052[];
extern const u16 ef13_char_table_053_head[];
extern const u16 ef13_char_table_053[];
extern const u16 ef13_char_table_056_head[];
extern const u16 ef13_char_table_056[];
extern const u16 ef13_char_table_057_head[];
extern const u16 ef13_char_table_057[];
extern const u16 ef13_char_table_058_head[];
extern const u16 ef13_char_table_058[];
extern const u16 ef13_char_table_059_head[];
extern const u16 ef13_char_table_059[];
extern const u16 ef13_char_table_060_head[];
extern const u16 ef13_char_table_060[];
extern const u16 ef13_char_table_061_head[];
extern const u16 ef13_char_table_061[];
extern const u16 ef13_char_table_062_head[];
extern const u16 ef13_char_table_062[];
extern const u16 ef13_char_table_063_head[];
extern const u16 ef13_char_table_063[];
extern const u16 ef13_char_table_064_head[];
extern const u16 ef13_char_table_064[];
extern const u16 ef13_char_table_065_head[];
extern const u16 ef13_char_table_065[];
extern const u16 ef13_char_table_066_head[];
extern const u16 ef13_char_table_066[];
extern const u16 ef13_char_table_067_head[];
extern const u16 ef13_char_table_067[];
extern const u16 ef13_char_table_068_head[];
extern const u16 ef13_char_table_068[];
extern const u16 ef13_char_table_069_head[];
extern const u16 ef13_char_table_069[];
extern const u16 ef13_char_table_070_head[];
extern const u16 ef13_char_table_070[];
extern const u16 ef13_char_table_071_head[];
extern const u16 ef13_char_table_071[];
extern const u16 ef13_char_table_072_head[];
extern const u16 ef13_char_table_072[];
extern const u16 ef13_char_table_073_head[];
extern const u16 ef13_char_table_073[];
extern const u16 ef13_char_table_074_head[];
extern const u16 ef13_char_table_074[];
extern const u16 ef13_char_table_075_head[];
extern const u16 ef13_char_table_075[];
extern const u16 ef13_char_table_076_head[];
extern const u16 ef13_char_table_076[];
extern const u16 ef13_char_table_077_head[];
extern const u16 ef13_char_table_077[];
extern const u16 ef13_char_table_078_head[];
extern const u16 ef13_char_table_078[];
extern const u16 ef13_char_table_079_head[];
extern const u16 ef13_char_table_079[];
extern const u16 ef13_char_table_080_head[];
extern const u16 ef13_char_table_080[];
extern const u16 ef13_char_table_081_head[];
extern const u16 ef13_char_table_081[];
extern const u16 ef13_char_table_082_head[];
extern const u16 ef13_char_table_082[];
extern const u16 ef13_char_table_083_head[];
extern const u16 ef13_char_table_083[];
extern const u16 ef13_char_table_084_head[];
extern const u16 ef13_char_table_084[];
extern const u16 ef13_char_table_085_head[];
extern const u16 ef13_char_table_085[];
extern const u16 ef13_char_table_086_head[];
extern const u16 ef13_char_table_086[];
extern const u16 ef13_char_table_087_head[];
extern const u16 ef13_char_table_087[];
extern const u16 ef13_char_table_088_head[];
extern const u16 ef13_char_table_088[];
extern const u16 ef13_char_table_089_head[];
extern const u16 ef13_char_table_089[];
extern const u16 ef13_char_table_090_head[];
extern const u16 ef13_char_table_090[];
extern const u16 ef13_char_table_091_head[];
extern const u16 ef13_char_table_091[];
extern const u16 ef13_char_table_092_head[];
extern const u16 ef13_char_table_092[];
extern const u16 ef13_char_table_093_head[];
extern const u16 ef13_char_table_093[];
extern const u16 ef13_char_table_094_head[];
extern const u16 ef13_char_table_094[];
extern const u16 ef13_char_table_095_head[];
extern const u16 ef13_char_table_095[];
extern const u16 ef13_char_table_096_head[];
extern const u16 ef13_char_table_096[];
extern const u16 ef13_char_table_097_head[];
extern const u16 ef13_char_table_097[];
extern const u16 ef13_char_table_098_head[];
extern const u16 ef13_char_table_098[];
extern const u16 ef13_char_table_099_head[];
extern const u16 ef13_char_table_099[];
extern const u16 ef13_char_table_100_head[];
extern const u16 ef13_char_table_100[];
extern const u16 ef13_char_table_101_head[];
extern const u16 ef13_char_table_101[];
extern const u16 ef13_char_table_102_head[];
extern const u16 ef13_char_table_102[];
extern const u16 ef13_char_table_103_head[];
extern const u16 ef13_char_table_103[];
extern const u16 ef13_char_table_104_head[];
extern const u16 ef13_char_table_104[];
extern const u16 ef13_char_table_105_head[];
extern const u16 ef13_char_table_105[];
extern const u16 ef13_char_table_106_head[];
extern const u16 ef13_char_table_106[];
extern const u16 ef13_char_table_107_head[];
extern const u16 ef13_char_table_107[];
extern const u16 ef13_char_table_108_head[];
extern const u16 ef13_char_table_108[];
extern const u16 ef13_char_table_109_head[];
extern const u16 ef13_char_table_109[];
extern const u16 ef13_char_table_110_head[];
extern const u16 ef13_char_table_110[];
extern const u16 ef13_char_table_111_head[];
extern const u16 ef13_char_table_111[];
extern const u16 ef13_char_table_112_head[];
extern const u16 ef13_char_table_112[];
extern const u16 ef13_char_table_113_head[];
extern const u16 ef13_char_table_113[];
extern const u16 ef13_char_table_114_head[];
extern const u16 ef13_char_table_114[];
extern const u16 ef13_char_table_115_head[];
extern const u16 ef13_char_table_115[];
extern const u16 ef13_char_table_116_head[];
extern const u16 ef13_char_table_116[];
extern const u16 ef13_char_table_117_head[];
extern const u16 ef13_char_table_117[];
extern const u16 ef13_char_table_118_head[];
extern const u16 ef13_char_table_118[];
extern const u16 ef13_char_table_119_head[];
extern const u16 ef13_char_table_119[];
extern const u16 ef13_char_table_120_head[];
extern const u16 ef13_char_table_120[];
extern const u16 ef13_char_table_121_head[];
extern const u16 ef13_char_table_121[];
extern const u16 ef13_char_table_122_head[];
extern const u16 ef13_char_table_122[];
extern const u16 ef13_char_table_123_head[];
extern const u16 ef13_char_table_123[];
extern const u16 ef13_char_table_124_head[];
extern const u16 ef13_char_table_124[];
extern const u16 ef13_char_table_125_head[];
extern const u16 ef13_char_table_125[];
extern const u16 ef13_char_table_126_head[];
extern const u16 ef13_char_table_126[];
extern const u16 ef13_char_table_127_head[];
extern const u16 ef13_char_table_127[];
extern const u16 ef13_char_table_128_head[];
extern const u16 ef13_char_table_128[];
extern const u16 ef13_char_table_129_head[];
extern const u16 ef13_char_table_129[];
extern const u16 ef13_char_table_130_head[];
extern const u16 ef13_char_table_130[];
extern const u16 ef13_char_table_131_head[];
extern const u16 ef13_char_table_131[];
extern const u16 ef13_char_table_132_head[];
extern const u16 ef13_char_table_132[];
extern const u16 ef13_char_table_133_head[];
extern const u16 ef13_char_table_133[];
extern const u16 ef13_char_table_134_head[];
extern const u16 ef13_char_table_134[];
extern const u16 ef13_char_table_135_head[];
extern const u16 ef13_char_table_135[];
extern const u16 ef13_char_table_136_head[];
extern const u16 ef13_char_table_136[];
extern const u16 ef13_char_table_137_head[];
extern const u16 ef13_char_table_137[];
extern const u16 ef13_char_table_138_head[];
extern const u16 ef13_char_table_138[];
extern const u16 ef13_char_table_139_head[];
extern const u16 ef13_char_table_139[];
extern const u16 ef13_char_table_140_head[];
extern const u16 ef13_char_table_140[];
extern const u16 ef13_char_table_141_head[];
extern const u16 ef13_char_table_141[];
extern const u16 ef13_char_table_142_head[];
extern const u16 ef13_char_table_142[];
extern const u16 ef13_char_table_143_head[];
extern const u16 ef13_char_table_143[];
extern const u16 ef13_char_table_144_head[];
extern const u16 ef13_char_table_144[];
extern const u16 ef13_char_table_145_head[];
extern const u16 ef13_char_table_145[];
extern const u16 ef13_char_table_146_head[];
extern const u16 ef13_char_table_146[];
extern const u16 ef13_char_table_147_head[];
extern const u16 ef13_char_table_147[];
extern const u16 ef13_char_table_148_head[];
extern const u16 ef13_char_table_148[];
extern const u16 ef13_char_table_149_head[];
extern const u16 ef13_char_table_149[];
extern const u16 ef13_char_table_150_head[];
extern const u16 ef13_char_table_150[];
extern const u16 ef13_char_table_151_head[];
extern const u16 ef13_char_table_151[];
extern const u16 ef13_char_table_152_head[];
extern const u16 ef13_char_table_152[];
extern const u16 ef13_char_table_153_head[];
extern const u16 ef13_char_table_153[];
extern const u16 ef13_char_table_154_head[];
extern const u16 ef13_char_table_154[];
extern const u16 ef13_char_table_225_head[];
extern const u16 ef13_char_table_225[];
extern const u32 effg0_char_table_0[];
extern const u32 effg0_char_table_1[];
extern const u32 effg0_char_table_2[];
extern const u32 effg0_char_table_3[];
extern const u32 effg0_char_table_4[];
extern const u32 effg0_char_table_5[];
extern const u32 effg0_char_table_6[];
extern const u32 effg0_char_table_7[];
extern const u32 effg0_char_table_8[];
extern const u32 ag_face_panel_table[];
extern const u16 effg0_char_table_0_000_head[];
extern const u16 effg0_char_table_0_000[];
extern const u16 effg0_char_table_0_001_head[];
extern const u16 effg0_char_table_0_001[];
extern const u16 effg0_char_table_0_002_head[];
extern const u16 effg0_char_table_0_002[];
extern const u16 effg0_char_table_1_000_head[];
extern const u16 effg0_char_table_1_000[];
extern const u16 effg0_char_table_1_001_head[];
extern const u16 effg0_char_table_1_001[];
extern const u16 effg0_char_table_1_002_head[];
extern const u16 effg0_char_table_1_002[];
extern const u16 effg0_char_table_2_000_head[];
extern const u16 effg0_char_table_2_000[];
extern const u16 effg0_char_table_2_001_head[];
extern const u16 effg0_char_table_2_001[];
extern const u16 effg0_char_table_2_002_head[];
extern const u16 effg0_char_table_2_002[];
extern const u16 effg0_char_table_3_000_head[];
extern const u16 effg0_char_table_3_000[];
extern const u16 effg0_char_table_3_001_head[];
extern const u16 effg0_char_table_3_001[];
extern const u16 effg0_char_table_3_002_head[];
extern const u16 effg0_char_table_3_002[];
extern const u16 effg0_char_table_4_000_head[];
extern const u16 effg0_char_table_4_000[];
extern const u16 effg0_char_table_4_001_head[];
extern const u16 effg0_char_table_4_001[];
extern const u16 effg0_char_table_4_002_head[];
extern const u16 effg0_char_table_4_002[];
extern const u16 effg0_char_table_5_000_head[];
extern const u16 effg0_char_table_5_000[];
extern const u16 effg0_char_table_5_001_head[];
extern const u16 effg0_char_table_5_001[];
extern const u16 effg0_char_table_5_002_head[];
extern const u16 effg0_char_table_5_002[];
extern const u16 effg0_char_table_6_000_head[];
extern const u16 effg0_char_table_6_000[];
extern const u16 effg0_char_table_6_001_head[];
extern const u16 effg0_char_table_6_001[];
extern const u16 effg0_char_table_6_002_head[];
extern const u16 effg0_char_table_6_002[];
extern const u16 effg0_char_table_7_000_head[];
extern const u16 effg0_char_table_7_000[];
extern const u16 effg0_char_table_7_001_head[];
extern const u16 effg0_char_table_7_001[];
extern const u16 effg0_char_table_7_002_head[];
extern const u16 effg0_char_table_7_002[];
extern const u16 ag_face_panel_table_000_head[];
extern const u16 ag_face_panel_table_000[];
extern const u32 effD4_char_table[];
extern const u16 effD4_char_table_000_head[];
extern const u16 effD4_char_table_000[];
extern const u16 effD4_char_table_001_head[];
extern const u16 effD4_char_table_001[];
extern const u32 effect_unref_char_table[];
extern const u16 effect_unref_char_table_000_head[];
extern const u16 effect_unref_char_table_000[];

/* plef_char_table: 170 entries */
const u32 plef_char_table[171] = {
    (u32)plef_char_table_000, (u32)plef_char_table_001, (u32)plef_char_table_002, (u32)plef_char_table_003, (u32)plef_char_table_004, (u32)plef_char_table_005,
    (u32)plef_char_table_006, (u32)plef_char_table_007, (u32)plef_char_table_008, (u32)plef_char_table_009, (u32)plef_char_table_010, (u32)plef_char_table_011,
    (u32)plef_char_table_012, (u32)plef_char_table_013, (u32)plef_char_table_014, (u32)plef_char_table_015, (u32)plef_char_table_016, (u32)plef_char_table_017,
    (u32)plef_char_table_018, (u32)plef_char_table_019, (u32)plef_char_table_020, (u32)plef_char_table_021, (u32)plef_char_table_022, (u32)plef_char_table_023,
    (u32)plef_char_table_024, (u32)plef_char_table_025, (u32)plef_char_table_026, (u32)plef_char_table_027, (u32)plef_char_table_028, (u32)plef_char_table_029,
    (u32)plef_char_table_030, (u32)plef_char_table_031, (u32)plef_char_table_032, (u32)plef_char_table_033, (u32)plef_char_table_034, (u32)plef_char_table_035,
    (u32)plef_char_table_036, (u32)plef_char_table_037, (u32)plef_char_table_038, (u32)plef_char_table_039, (u32)plef_char_table_040, (u32)plef_char_table_041,
    (u32)plef_char_table_042, (u32)plef_char_table_043, (u32)plef_char_table_044, (u32)plef_char_table_045, (u32)plef_char_table_046, (u32)plef_char_table_047,
    (u32)plef_char_table_048, (u32)plef_char_table_049, (u32)plef_char_table_050, (u32)plef_char_table_051, (u32)plef_char_table_052, (u32)plef_char_table_053,
    (u32)plef_char_table_054, (u32)plef_char_table_055, (u32)plef_char_table_056, (u32)plef_char_table_057, (u32)plef_char_table_058, (u32)plef_char_table_059,
    (u32)plef_char_table_060, (u32)plef_char_table_061, (u32)plef_char_table_062, (u32)plef_char_table_063, (u32)plef_char_table_064, (u32)plef_char_table_065,
    (u32)plef_char_table_066, (u32)plef_char_table_067, (u32)plef_char_table_068, (u32)plef_char_table_069, (u32)plef_char_table_070, (u32)plef_char_table_071,
    (u32)plef_char_table_072, (u32)plef_char_table_073, (u32)plef_char_table_074, (u32)plef_char_table_075, (u32)plef_char_table_076, (u32)plef_char_table_077,
    (u32)plef_char_table_078, (u32)plef_char_table_079, (u32)plef_char_table_080, (u32)plef_char_table_081, (u32)plef_char_table_082, (u32)plef_char_table_083,
    (u32)plef_char_table_084, (u32)plef_char_table_085, (u32)plef_char_table_086, (u32)plef_char_table_087, (u32)plef_char_table_080, (u32)plef_char_table_080,
    (u32)plef_char_table_090, (u32)plef_char_table_091, (u32)plef_char_table_092, (u32)plef_char_table_093, (u32)plef_char_table_094, (u32)plef_char_table_095,
    (u32)plef_char_table_096, (u32)plef_char_table_097, (u32)plef_char_table_098, (u32)plef_char_table_099, (u32)plef_char_table_100, (u32)plef_char_table_101,
    (u32)plef_char_table_102, (u32)plef_char_table_103, (u32)plef_char_table_104, (u32)plef_char_table_105, (u32)plef_char_table_106, (u32)plef_char_table_107,
    (u32)plef_char_table_108, (u32)plef_char_table_109, (u32)plef_char_table_110, (u32)plef_char_table_111, (u32)plef_char_table_112, (u32)plef_char_table_113,
    (u32)plef_char_table_114, (u32)plef_char_table_115, (u32)plef_char_table_116, (u32)plef_char_table_117, (u32)plef_char_table_118, (u32)plef_char_table_119,
    (u32)plef_char_table_120, (u32)plef_char_table_121, (u32)plef_char_table_122, (u32)plef_char_table_123, (u32)plef_char_table_124, (u32)plef_char_table_125,
    (u32)plef_char_table_126, (u32)plef_char_table_127, (u32)plef_char_table_128, (u32)plef_char_table_129, (u32)plef_char_table_130, (u32)plef_char_table_131,
    (u32)plef_char_table_132, (u32)plef_char_table_133, (u32)plef_char_table_134, (u32)plef_char_table_135, (u32)plef_char_table_136, (u32)plef_char_table_137,
    (u32)plef_char_table_138, (u32)plef_char_table_139, (u32)plef_char_table_140, (u32)plef_char_table_140, (u32)plef_char_table_140, (u32)plef_char_table_140,
    (u32)plef_char_table_140, (u32)plef_char_table_140, (u32)plef_char_table_140, (u32)plef_char_table_140, (u32)plef_char_table_140, (u32)plef_char_table_140,
    (u32)plef_char_table_140, (u32)plef_char_table_140, (u32)plef_char_table_140, (u32)plef_char_table_140, (u32)plef_char_table_140, (u32)plef_char_table_155,
    (u32)plef_char_table_156, (u32)plef_char_table_156, (u32)plef_char_table_156, (u32)plef_char_table_159, (u32)plef_char_table_160, (u32)plef_char_table_161,
    (u32)plef_char_table_162, (u32)plef_char_table_163, (u32)plef_char_table_164, (u32)plef_char_table_165, (u32)plef_char_table_166, (u32)plef_char_table_167,
    (u32)plef_char_table_168, (u32)plef_char_table_169, 0,
};

const u16 plef_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_000[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2AC4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2AC5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2AC6),
    L2(3, 1, 0, 0, 0, 0, 0, 0x2AC6),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2AC6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_001[52] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B0B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B0C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B0D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B0E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B0F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B10),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B11),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B12),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B13),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B14),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B15),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B15),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_002[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xA752),
    L2(4, 0, 303, 0, 0, 0, 0, 0xA753),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA754),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA755),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA756),
    L2(4, 0, 303, 0, 0, 0, 0, 0xA757),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA758),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA759),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_003[28] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xA75A),
    L2(5, 0, 303, 0, 0, 0, 0, 0xA75B),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA75C),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA75D),
    L2(5, 0, 303, 0, 0, 0, 0, 0xA75E),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA75F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_004[24] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xA760),
    L2(5, 0, 316, 0, 0, 0, 0, 0xA761),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA762),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA763),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA764),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_005[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xA766),
    L2(4, 0, 315, 0, 0, 0, 0, 0xA767),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA768),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA769),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA76A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA76B),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA76C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA76D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_006[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xA793),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA794),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA795),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA796),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA797),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA798),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA799),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA799),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_007[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xA79A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA79B),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA79C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA79D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA79E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA79F),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7A0),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA7A0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_008[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xB007),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB008),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB009),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB00A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB00B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB00C),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB00C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_009[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xB00D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB00E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB00F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB010),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB011),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB012),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB012),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_010[36] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6D3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6D4),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6D5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6D6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6D7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6D8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6D9),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA6D9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_011[36] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6DA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6DB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6DC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6DD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6DE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6DF),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6E0),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA6E0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_012[36] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6E1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6E2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6E3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6E4),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6E5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6E6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA6E7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA6E7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_013[56] = {
    L2(250, 131, 0, 0, 0, 0, 0, 0xAF9F),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0xAFA0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA4),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA9),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFA9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_014[56] = {
    L2(250, 131, 0, 0, 0, 0, 0, 0xAFAA),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0xAFAB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFAC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFAD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFAE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFAF),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB4),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFB4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_015[56] = {
    L2(250, 131, 0, 0, 0, 0, 0, 0xAFB5),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0xAFB6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFBA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFBB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFBC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFBD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFBE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFBF),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFBF),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_016[56] = {
    L2(250, 131, 0, 0, 0, 0, 0, 0xAFC0),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0xAFC1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC4),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFCA),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFCA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_017[100] = {
    CMD(CM_FOR, 0, 0, 1),
    L2(2, 147, 0, 0, 0, 0, 0, 0xAFD0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD3),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD4),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD5),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD6),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD7),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD8),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD9),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFDA),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFDB),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFDC),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFDD),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFDE),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFDF),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xAFE0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFE1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFE2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFE3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFE4),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFE4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_018[92] = {
    CMD(CM_FOR, 0, 0, 1),
    L2(2, 144, 0, 0, 0, 0, 0, 0xB04C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB04D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB04E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB04F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB050),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB051),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB052),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB053),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB054),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB055),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB056),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB057),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB058),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xB059),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB05A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB05B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB05C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB05D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB05E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB05E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_019[28] = {
    L2(2, 1, 0, 0, 0, 0, 0, 0xAFE0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFE1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFE2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFE3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFE4),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFE4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_020[32] = {
    L2(3, 1, 0, 0, 0, 0, 0, 0xB059),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB05A),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB05B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB05C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB05D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB05E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB05E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_021[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFFE),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFFF),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB000),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB001),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB002),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB003),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB004),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB005),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB006),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB006),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_022[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFF5),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFF6),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFF7),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFF8),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFF9),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFFA),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFFB),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFFC),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFFD),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFFD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_023[60] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xAFE8),
    L2(4, 0, 283, 0, 0, 0, 0, 0xAFE9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFEA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFEB),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFEC),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFED),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFEE),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFEF),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFF0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFF1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFF2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFF3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAFF4),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFF4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_024[84] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA73E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA73F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA740),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA741),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA742),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA743),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA744),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA745),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA746),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA747),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA748),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA749),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA74A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA74B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA74C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA74D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA74E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA74F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA750),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA750),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_025[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D0B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D0C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D0D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D0E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D0F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D0F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_026[52] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2160),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2161),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2162),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2163),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2164),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2165),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2166),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2167),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2168),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2169),
    L2(3, 0, 0, 0, 0, 0, 0, 0x216A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x216B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_027[52] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x216C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x216D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x216E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x216F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2170),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2171),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2172),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2173),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2174),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2175),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2176),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2177),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_028[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xAF81),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAF82),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAF83),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAF84),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAF85),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAF86),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAF86),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_029[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xAF87),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAF88),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAF89),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAF8A),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAF8B),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAF8C),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAF8C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_030[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF96),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF97),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF98),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF99),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF9A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF9B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF9C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF9D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF9E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAF9E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_031[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF8D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF8E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF8F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF90),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF91),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF92),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF93),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF94),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF95),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAF95),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_032[60] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7A1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7A2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7A3),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7A4),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7A5),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7A6),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7A7),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7A8),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7A9),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7AA),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7AB),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7AC),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7AD),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA7AD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_033[88] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D7D),
    CMD(CM_PAXY, 0, 320, 256),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D7E),
    CMD(CM_PAXY, 0, 384, 288),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D7F),
    CMD(CM_PAXY, 0, 448, 320),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D80),
    CMD(CM_PAXY, 0, 512, 352),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D81),
    CMD(CM_PAXY, 0, 576, 384),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D82),
    CMD(CM_PAXY, 0, 640, 416),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D83),
    CMD(CM_PAXY, 0, 704, 448),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D84),
    CMD(CM_PAXY, 0, 768, 480),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D85),
    CMD(CM_PAXY, 0, 832, 512),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D86),
    CMD(CM_PAXY, 0, 896, 544),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D86),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_034[48] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D8D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D8E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D8F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D90),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D91),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D92),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D93),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D94),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D95),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D96),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D96),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_035[32] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D87),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D88),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D89),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D8A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D8B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2D8C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D8C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_036[68] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD68),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD69),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD6A),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD6B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD6C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD6D),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD6E),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD6F),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD70),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD71),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD72),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD73),
    L2(8, 1, 0, 0, 0, 0, 0, 0xAD74),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD75),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD76),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD77),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_037[36] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC8),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC9),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADCA),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADCB),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADCC),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADCD),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADCE),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADCF),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_038[68] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD78),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD79),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD7A),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD7B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD7C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD7D),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD7E),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD7F),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD80),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD81),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD82),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD83),
    L2(8, 1, 0, 0, 0, 0, 0, 0xAD84),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD85),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD86),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD87),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_039[48] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xADA8),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADA9),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADAA),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADAB),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADAC),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADAD),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADAE),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADAF),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB1),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_040[68] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD88),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD89),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD8A),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD8B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD8C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD8D),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD8E),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD8F),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD90),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD91),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD92),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD93),
    L2(8, 1, 0, 0, 0, 0, 0, 0xAD94),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD95),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD96),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD97),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_041[48] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB8),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB9),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADBA),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADBB),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADBC),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADBD),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADBE),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADBF),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC1),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_042[68] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD98),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD99),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD9A),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD9B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD9C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD9D),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD9E),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAD9F),
    L2(8, 0, 0, 0, 0, 0, 0, 0xADA0),
    L2(8, 0, 0, 0, 0, 0, 0, 0xADA1),
    L2(8, 0, 0, 0, 0, 0, 0, 0xADA2),
    L2(8, 0, 0, 0, 0, 0, 0, 0xADA3),
    L2(8, 1, 0, 0, 0, 0, 0, 0xADA4),
    L2(8, 0, 0, 0, 0, 0, 0, 0xADA5),
    L2(8, 0, 0, 0, 0, 0, 0, 0xADA6),
    L2(8, 0, 0, 0, 0, 0, 0, 0xADA7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_043[48] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xADD8),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADD9),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADDA),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADDB),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADDC),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADDD),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADDE),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADDF),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADE0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADE1),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADE2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_044[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2195),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2196),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2197),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2198),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2199),
    L2(3, 0, 0, 0, 0, 0, 0, 0x219A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x219A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_045[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x21AA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x21AB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x21AC),
    L2(250, 255, 0, 0, 0, 0, 0, 0x21AC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_046[8] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x21AA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_047[60] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xA7A1),
    L2(1, 0, 0, 0, 1, 0, 0, 0xA7A2),
    L2(1, 0, 0, 0, 1, 0, 0, 0xA7A3),
    L2(2, 0, 0, 0, 1, 0, 0, 0xA7A4),
    L2(2, 0, 0, 0, 1, 0, 0, 0xA7A5),
    L2(2, 0, 0, 0, 1, 0, 0, 0xA7A6),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA7A7),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA7A8),
    L2(4, 0, 0, 0, 1, 0, 0, 0xA7A9),
    L2(4, 0, 0, 0, 1, 0, 0, 0xA7AA),
    L2(4, 0, 0, 0, 1, 0, 0, 0xA7AB),
    L2(5, 0, 0, 0, 1, 0, 0, 0xA7AC),
    L2(5, 0, 0, 0, 1, 0, 0, 0xA7AD),
    L2(250, 255, 0, 0, 1, 0, 0, 0xA7AD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_048[48] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAA9E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAA9F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAAA0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAAA1),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAAA2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAAA3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAAA4),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAAA5),
    L2(5, 0, 0, 0, 0, 0, 0, 0xAAA6),
    L2(6, 0, 0, 0, 0, 0, 0, 0xAAA7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAAA7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_049[32] = {
    CMD(CM_FOR, 0, 0, 2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7CB),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA680),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7CC),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA680),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA680),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_050[32] = {
    CMD(CM_FOR, 0, 0, 2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7CD),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA680),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7CE),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA680),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA680),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_051[32] = {
    CMD(CM_FOR, 0, 0, 2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7CF),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA680),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7D0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA680),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA680),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_052[28] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xA811),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA812),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA813),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA814),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA815),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA815),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_053[64] = {
    L2(4, 133, 0, 0, 0, 0, 0, 0xAF9F),
    L2(1, 0, 323, 0, 0, 0, 0, 0xAF9F),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAF9F),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0xAFA0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA4),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFA9),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFA9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_054[64] = {
    L2(4, 133, 0, 0, 0, 0, 0, 0xAFAA),
    L2(1, 0, 323, 0, 0, 0, 0, 0xAFAA),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAFAA),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0xAFAB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFAC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFAD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFAE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFAF),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB4),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFB4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_055[64] = {
    L2(4, 133, 0, 0, 0, 0, 0, 0xAFB5),
    L2(1, 0, 323, 0, 0, 0, 0, 0xAFB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAFB5),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0xAFB6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFBA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFBB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFBC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFBD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFBE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFBF),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFBF),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_056[64] = {
    L2(4, 133, 0, 0, 0, 0, 0, 0xAFC0),
    L2(1, 0, 323, 0, 0, 0, 0, 0xAFC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAFC0),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0xAFC1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC4),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFC9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFCA),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFCA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_057[100] = {
    CMD(CM_FOR, 0, 0, 1),
    L2(2, 147, 0, 0, 0, 0, 0, 0xAFD0),
    L2(2, 0, 314, 0, 0, 0, 0, 0xAFD1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD3),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD4),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD5),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD6),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD7),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD8),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFD9),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFDA),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFDB),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFDC),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFDD),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFDE),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFDF),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xAFE0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAFE1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFE2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFE3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAFE4),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAFE4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_058[92] = {
    CMD(CM_FOR, 0, 0, 1),
    L2(2, 144, 0, 0, 0, 0, 0, 0xB04C),
    L2(2, 0, 314, 0, 0, 0, 0, 0xB04D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB04E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB04F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB050),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB051),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB052),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB053),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB054),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB055),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB056),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB057),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB058),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xB059),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB05A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB05B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB05C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB05D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB05E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB05E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_059[28] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2B71),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2B83),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2C01),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2C4C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2C4D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2C4E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_060[72] = {
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB1C),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB1D),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB1E),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB1F),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB20),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB21),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB22),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB23),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB24),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB25),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB26),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB27),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB28),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB29),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAB2A),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAB2B),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAB2B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_061[56] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA826),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA827),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA828),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA829),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA82A),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA82B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA82C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA82D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA82E),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA82F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA830),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA831),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA831),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_062[72] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA816),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA817),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA818),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA819),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA81A),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA81B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA81C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA81D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA81E),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA81F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA820),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA821),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA822),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA823),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA824),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA825),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA825),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_063[72] = {
    L2(3, 0, 0, 0, 1, 0, 0, 0xA816),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA817),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA818),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA819),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA81A),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA81B),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA81C),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA81D),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA81E),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA81F),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA820),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA821),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA822),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA823),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA824),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA825),
    L2(250, 255, 0, 0, 1, 0, 0, 0xA825),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_064[72] = {
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB1C),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB1D),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB1E),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB1F),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB20),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB21),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB22),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB23),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB24),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB25),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB26),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB27),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB28),
    L2(2, 0, 0, 0, 2, 0, 0, 0xAB29),
    L2(1, 0, 0, 0, 2, 0, 0, 0xAB2A),
    L2(1, 0, 0, 0, 2, 0, 0, 0xAB2B),
    L2(250, 255, 0, 0, 2, 0, 0, 0xAB2B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_065[12] = {
    L2(16, 0, 0, 0, 0, 0, 0, 0x2DDD),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2DDD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_066[40] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xA81E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA81F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA820),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA821),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA822),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA823),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA824),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA825),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA825),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_067[40] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xA81E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA81F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA820),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA821),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA822),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA823),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA824),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA825),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA825),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_068[40] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xA81E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA81F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA820),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA821),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA822),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA823),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA824),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA825),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA825),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_069_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_069[104] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xA816),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA817),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA818),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA819),
    CMD(CM_FOR, 0, 0, 4),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA81A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA81B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA81C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA81D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA81E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA81F),
    CMD(CM_NEX, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA826),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA827),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA828),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA829),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA82A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA82B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA82C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA82D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA82E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA82F),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA830),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA831),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA831),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_070_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_070[36] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xA7F6),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7F7),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7F8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7F9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7FA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7FB),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA7FC),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA7FC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_071_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_071[24] = {
    CMD(CM_FOR, 0, 0, 28),
    L2(1, 0, 0, 0, 0, 0, 0, 0x15F0),
    CMD(CM_PA_X, 0, 768, 0),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x15F0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_072_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_072[24] = {
    CMD(CM_FOR, 0, 0, 28),
    L2(1, 0, 0, 0, 0, 0, 0, 0x15F0),
    CMD(CM_PA_X, 0, -768, 0),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x15F0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_073_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_073[72] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB1C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB1D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB1E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB1F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB20),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB21),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB22),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB23),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB24),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB25),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB26),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB27),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB28),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB29),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB2A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB2B),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAB2B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_074_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_074[68] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD68),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD69),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD6A),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD6B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD6C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD6D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD6E),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD6F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD70),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD71),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD72),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD73),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD74),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD75),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD76),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD77),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_075_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_075[68] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD78),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD79),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD7A),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD7B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD7C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD7D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD7E),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD7F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD80),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD81),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD82),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD83),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD84),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD85),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD86),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD87),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_076_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_076[68] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD88),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD89),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD8A),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD8B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD8C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD8D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD8E),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD8F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD90),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD91),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD92),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD93),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD94),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD95),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD96),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD97),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_077_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_077[68] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD98),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD99),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD9A),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD9B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD9C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD9D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD9E),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAD9F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADA0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADA1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADA2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADA3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADA4),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADA5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADA6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADA7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_078_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_078[40] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x3434),
    L2(1, 0, 0, 0, 0, 0, 0, 0x3435),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3436),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3437),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3438),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3439),
    L2(4, 0, 0, 0, 0, 0, 0, 0x343A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x343B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x343B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_079_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_079[44] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x343C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x343D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x343E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x343F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3440),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3441),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3442),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3443),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3444),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3444),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_080_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_080[48] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x342A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x342B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x342C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x342D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x342E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x342F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3430),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3431),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3432),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3433),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3433),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_081_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_081[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D87),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D88),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D89),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D8A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2D8B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2D8C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D8C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_082_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_082[60] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xA7A1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA7A2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7A3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7A4),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7A5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7A6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7A7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7A8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7A9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7AA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7AB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7AC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7AD),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA7AD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_083_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_083[60] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xA7A1),
    L2(1, 0, 0, 0, 1, 0, 0, 0xA7A2),
    L2(2, 0, 0, 0, 1, 0, 0, 0xA7A3),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA7A4),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA7A5),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA7A6),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA7A7),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA7A8),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA7A9),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA7AA),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA7AB),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA7AC),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA7AD),
    L2(250, 255, 0, 0, 1, 0, 0, 0xA7AD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_084_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_084[20] = {
    L2(3, 0, 0, 2, 0, 0, 0, 0x1A94),
    L2(3, 0, 0, 2, 0, 0, 0, 0x1A95),
    L2(3, 0, 0, 2, 0, 0, 0, 0x1ABD),
    L2(250, 255, 0, 2, 0, 0, 0, 0x1ABD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_085_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_085[40] = {
    L2(3, 133, 0, 2, 0, 0, 0, 0xB02F),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB030),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB031),
    CMD(CM_IXBW, 0, 0, 3),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB032),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB033),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB034),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB035),
    L2(250, 255, 0, 2, 0, 0, 0, 0xB035),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_086_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_086[44] = {
    L2(3, 133, 0, 2, 0, 0, 0, 0xB036),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB037),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB038),
    CMD(CM_IXBW, 0, 0, 3),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB039),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB03A),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB03B),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB03C),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB03D),
    L2(250, 255, 0, 2, 0, 0, 0, 0xB03D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_087_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_087[60] = {
    L2(3, 133, 0, 2, 0, 0, 0, 0xB03E),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB03F),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB040),
    CMD(CM_IXBW, 0, 0, 3),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB041),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB042),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB043),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB044),
    L2(3, 0, 0, 2, 0, 0, 0, 0xB045),
    L2(250, 255, 0, 2, 0, 0, 0, 0xB045),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0001),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0001),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_090_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_090[24] = {
    CMD(CM_FOR, 0, 0, 28),
    L2(1, 0, 0, 0, 0, 0, 0, 0x3F46),
    CMD(CM_PA_X, 0, 768, 0),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3F46),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_091_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_091[24] = {
    CMD(CM_FOR, 0, 0, 28),
    L2(1, 0, 0, 0, 0, 0, 0, 0x3F46),
    CMD(CM_PA_X, 0, -768, 0),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3F46),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_092_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_092[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0366),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0367),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0368),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0369),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0369),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_093_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_093[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x036D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x036E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x036F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x036F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_094_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_094[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0377),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0378),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0379),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0379),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_095_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_095[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x037D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x037E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x037F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x037F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_096_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_096[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x038C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x038D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x038E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x038E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_097_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_097[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0385),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0386),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0387),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0388),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0388),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_098_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_098[28] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x039A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x039B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x039C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x039D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x039E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x039E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_099_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_099[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0394),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0395),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0396),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0397),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0397),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_100_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_100[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x03A5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03A6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03A7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03A8),
    L2(250, 255, 0, 0, 0, 0, 0, 0x03A8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_101_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_101[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x03AC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03AD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03AE),
    L2(250, 255, 0, 0, 0, 0, 0, 0x03AE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_102_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_102[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x03BB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03BC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03BD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03BE),
    L2(250, 255, 0, 0, 0, 0, 0, 0x03BE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_103_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_103[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x03B5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03B6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03B7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03B8),
    L2(250, 255, 0, 0, 0, 0, 0, 0x03B8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_104_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_104[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x038C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x038D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x038E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x038E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_105_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_105[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0385),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0386),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0387),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0388),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0388),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_106_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_106[44] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0460),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0461),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0462),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0463),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0464),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0465),
    L2(5, 0, 0, 0, 0, 0, 0, 0x0466),
    L2(6, 0, 0, 0, 0, 0, 0, 0x0467),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0468),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0468),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_107_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_107[36] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0437),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0438),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0439),
    L2(4, 0, 0, 0, 0, 0, 0, 0x043A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x043B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x043C),
    L2(7, 0, 0, 0, 0, 0, 0, 0x043D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x043D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_108_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_108[40] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0469),
    L2(2, 0, 0, 0, 0, 0, 0, 0x046A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x046B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x046C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x046D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x046E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x046F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0470),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0470),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_109_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_109[48] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x043E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x043F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0440),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0441),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0442),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0443),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0444),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0445),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0446),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0447),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0447),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_110_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_110[36] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0471),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0472),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0473),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0474),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0475),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0476),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0477),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0477),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_111_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_111[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0448),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0449),
    L2(2, 0, 0, 0, 0, 0, 0, 0x044A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x044B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x044C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x044D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x044E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x044F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0450),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0450),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_112_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_112[64] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E1),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E6),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E7),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E8),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02EA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02EB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02EC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02ED),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02ED),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_113_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_113[68] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x0451),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0452),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0453),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0454),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0455),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0456),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0457),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0458),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0459),
    L2(7, 0, 0, 0, 0, 0, 0, 0x045A),
    L2(7, 0, 0, 0, 0, 0, 0, 0x045B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x045C),
    L2(9, 0, 0, 0, 0, 0, 0, 0x045D),
    L2(10, 0, 0, 0, 0, 0, 0, 0x045E),
    L2(11, 0, 0, 0, 0, 0, 0, 0x045F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x045F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_114_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_114[52] = {
    CMD(CM_EXEC, 29, 1, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB069),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB06A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB06B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB06C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB06D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB06E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB06F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB070),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB071),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB072),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB072),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_115_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_115[52] = {
    CMD(CM_EXEC, 29, 2, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB073),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB074),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB075),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB076),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB077),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB078),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB079),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB07A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB07B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB07C),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB07C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_116_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_116[48] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7B),
    CMD(CM_QUAY, 10, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7E),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF80),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAF80),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_117_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_117[68] = {
    L4(5, 0, 0, 0, 1, 0, 0, 0x4ADB, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4ADC, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4ADD, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4ADE, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4ADF, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4AE0, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4AE1, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4AE2, 0, 42, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_118_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_118[84] = {
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE2, -55, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADB, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADC, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADD, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADE, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADF, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE0, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE1, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE2, 0, 41, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_119_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_119[36] = {
    L2(3, 0, 0, 0, 1, 0, 0, 0x4ADB),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4ADC),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4ADD),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4ADE),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4ADF),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4AE0),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4AE1),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4AE2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_120_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_120[56] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x226B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x226C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x226D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x226E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x226F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2270),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2271),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2272),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2273),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2274),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2275),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2276),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2276),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_121_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_121[36] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xA745),
    L2(1, 0, 349, 0, 0, 0, 0, 0xA748),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA749),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA74A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA74B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA74C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA74E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA74E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_122_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_122[88] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D7D),
    CMD(CM_PAXY, 0, 384, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D7E),
    CMD(CM_PAXY, 0, 464, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D7F),
    CMD(CM_PAXY, 0, 544, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D80),
    CMD(CM_PAXY, 0, 624, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D81),
    CMD(CM_PAXY, 0, 704, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D82),
    CMD(CM_PAXY, 0, 784, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D83),
    CMD(CM_PAXY, 0, 864, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D84),
    CMD(CM_PAXY, 0, 944, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D85),
    CMD(CM_PAXY, 0, 1024, 128),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D86),
    CMD(CM_PAXY, 0, 1120, 128),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D86),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_123_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_123[44] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AE6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1AE7),
    L2(6, 0, 0, 0, 0, 0, 0, 0x1AE8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1AE9),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1AEA),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1AEB),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1AEC),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1AED),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1AEE),
    L2(5, 1, 0, 0, 0, 0, 0, 0x1AEE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_124_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_124[180] = {
    CMD(CM_RJA, 0, 124, 9), 0, 0, 0, 0,
    L4(7, 0, 0, 0, 0, 0, 0, 0x1AEF, -54, 36, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1AF0, 0, 36, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1AF1, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1AF2, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1AF3, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1AF4, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1AF5, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1AF6, 0, 36, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1AF7, 0, 36, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1AF8, 0, 36, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1AF9, 0, 36, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1AFA, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1AFB, 0, 36, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1AFC, 0, 36, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1AFD, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1AFE, 0, 0, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1AFF, 0, 0, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1B00, 0, 0, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1B01, 0, 0, 0, 0, 0, 0, 0),
    L4(24, 0, 0, 0, 0, 0, 0, 0x1B02, 0, 0, 0, 0, 0, 47, 2),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1B02, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_125_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_125[32] = {
    CMD(CM_RJA, 0, 126, 1),
    CMD(CM_JSR, 0, 127, 3),
    CMD(CM_JSR, 0, 128, 3),
    CMD(CM_JSR, 0, 129, 3),
    CMD(CM_JSR, 0, 130, 3),
    CMD(CM_JSR, 0, 131, 3),
    CMD(CM_IXBW, 0, 0, 5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_126_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_126[28] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B09),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B0A),
    CMD(CM_DSPF, 2, 0, 0),
    L2(16, 0, 0, 0, 0, 0, 0, 0x1B0A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B0A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_127_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_127[108] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_PJMP, 12, 16389, 0),
    CMD(CM_PJMP, 18, 16393, 0),
    CMD(CM_PJMP, 16, 16397, 0),
    CMD(CM_PJMP, 14, 16401, 0),
    CMD(CM_JMP, 0, 132, 3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 0, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 256, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, -256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
};

const u16 plef_char_table_128_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_128[108] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_PJMP, 12, 16389, 0),
    CMD(CM_PJMP, 18, 16393, 0),
    CMD(CM_PJMP, 16, 16397, 0),
    CMD(CM_PJMP, 14, 16401, 0),
    CMD(CM_JMP, 0, 132, 3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 0, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 256, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, -256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
};

const u16 plef_char_table_129_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_129[108] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_PJMP, 12, 16389, 0),
    CMD(CM_PJMP, 18, 16393, 0),
    CMD(CM_PJMP, 16, 16397, 0),
    CMD(CM_PJMP, 14, 16401, 0),
    CMD(CM_JMP, 0, 132, 3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 0, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 256, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, -256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
};

const u16 plef_char_table_130_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_130[108] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_PJMP, 12, 16389, 0),
    CMD(CM_PJMP, 18, 16393, 0),
    CMD(CM_PJMP, 16, 16397, 0),
    CMD(CM_PJMP, 14, 16401, 0),
    CMD(CM_JMP, 0, 132, 3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 0, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 256, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, -256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
};

const u16 plef_char_table_131_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_131[108] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_PJMP, 12, 16389, 0),
    CMD(CM_PJMP, 18, 16393, 0),
    CMD(CM_PJMP, 16, 16397, 0),
    CMD(CM_PJMP, 14, 16401, 0),
    CMD(CM_JMP, 0, 132, 3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 0, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 256, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, -256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
};

const u16 plef_char_table_132_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_132[52] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B08),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_PJMP, 16, 16390, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B09),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B0A),
    CMD(CM_PAXY, 0, 256, -512),
    CMD(CM_RET, 0, 0, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0x1B08),
    L2(4, 0, 0, 0, 1, 0, 0, 0x1B09),
    L2(4, 0, 0, 0, 1, 0, 0, 0x1B0A),
    CMD(CM_PAXY, 0, -256, -512),
    CMD(CM_RET, 0, 0, 0),
};

const u16 plef_char_table_133_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_133[284] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B7C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B7D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B7E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B7F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B80),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B81),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B82),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B83),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B84),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B85),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B86),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B87),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B88),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B89),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B8A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B8B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B8C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B8D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B8E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B8F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B90),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B91),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B92),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B93),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B94),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B95),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B96),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B97),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B98),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B99),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B9A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B9B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B9C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B9D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B9E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B9F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BAA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BAB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BAC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BAD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BAE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BAF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BBA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BBB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BBC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BBD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BBE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BBF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BC0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BC1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_134_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_134[208] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B83),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B84),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B85),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B86),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B87),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B88),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B89),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B8A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B8B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B8C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B8D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B8E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B8F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B90),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B91),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B92),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B93),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B94),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B95),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B96),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B97),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B98),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B99),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B9A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B9B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B9C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B9D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B9E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B9F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BAA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BAB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BAC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BAD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BAE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BAF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB4),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1BB4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_135_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_135[52] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BBA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BBB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BBC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BBD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BBE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BBF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BC0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BC1),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1BC1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_136_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_136[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AE9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AEA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AEB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AEC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AED),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AEE),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1AEE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_137_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_137[84] = {
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE2, -55, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADB, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADC, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADD, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADE, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADF, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE0, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE1, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE2, 0, 51, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_138_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_138[68] = {
    L4(3, 0, 0, 0, 1, 0, 0, 0x4ADB, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4ADC, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4ADD, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4ADE, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4ADF, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4AE0, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4AE1, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4AE2, 0, 52, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_139_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_139[68] = {
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADB, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADC, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADD, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADE, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADF, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE0, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE1, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE2, 0, 52, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_140_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_140[12] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0001),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0001),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_155_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_155[72] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xA816),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA817),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA818),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA819),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA81A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA81B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA81C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA81D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA81E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA81F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA820),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA821),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA822),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA823),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA824),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA825),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA825),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_156_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_156[108] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xA848),
    L2(1, 0, 317, 0, 0, 0, 0, 0xA849),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA84A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA84B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA84C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA84D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA84E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA84F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA850),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA851),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA852),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA853),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA854),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA855),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA856),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA857),
    L2(2, 1, 0, 0, 0, 0, 0, 0xA858),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA859),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA85A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA85B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA85C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA85D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA85E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA85F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA860),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA860),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_159_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_159[44] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xADCF),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADD0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADD1),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADD2),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADD3),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADD4),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADD5),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADD6),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADD7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xADD7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_160_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_160[52] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xADAD),
    L2(4, 0, 0, 0, 0, 0, 0, 0xADAE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xADAF),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB1),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB2),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB3),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB4),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB5),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB6),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADB7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xADB7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_161_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_161[72] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xADB8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADBA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADBB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xADBC),
    L2(4, 0, 0, 0, 0, 0, 0, 0xADBD),
    L2(4, 0, 0, 0, 0, 0, 0, 0xADBE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xADBF),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC1),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC2),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC3),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC4),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC5),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC6),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADC7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xADC7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_162_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_162[72] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xADD8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADD9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADDA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xADDB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xADDC),
    L2(4, 0, 0, 0, 0, 0, 0, 0xADDD),
    L2(4, 0, 0, 0, 0, 0, 0, 0xADDE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xADDF),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADE0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADE1),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADE2),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADE3),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADE4),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADE5),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADE6),
    L2(5, 0, 0, 0, 0, 0, 0, 0xADE7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xADE7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_163_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_163[128] = {
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C0),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C1),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C2),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C3),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C4),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C5),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C6),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C7),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C8),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C9),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03CA),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03CB),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03CC),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03CD),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03CE),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03CF),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03D0),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D1),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D2),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D3),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D4),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D5),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D6),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D7),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D8),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D9),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03DA),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03DB),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03DC),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03DD),
    L2(250, 255, 0, 0, 1, 0, 0, 0x03DD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_164_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_164[64] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02E7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02E8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02E9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02EA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02EB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02EC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02ED),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02ED),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_165_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_165[52] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02FA),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02FA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_166_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_166[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7F6),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7F7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7F8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7F9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7FA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7FB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7FC),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA7FC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_167_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_167[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x406F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4070),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4071),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4072),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4073),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4074),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4075),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4076),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4077),
    L2(250, 255, 0, 0, 0, 0, 0, 0x4077),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_168_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_168[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA680),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_169_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_169[20] = {
    L2(3, 0, 0, 2, 1, 0, 0, 0x1B61),
    L2(3, 0, 0, 2, 1, 0, 0, 0x1B62),
    L2(3, 0, 0, 2, 1, 0, 0, 0x1B63),
    L2(250, 255, 0, 2, 1, 0, 0, 0x1B63),
    CMD(CM_ROA, 0, 0, 0),
};

/* ef01_char_table: 41 entries */
const u32 ef01_char_table[42] = {
    (u32)ef01_char_table_000, (u32)ef01_char_table_001, (u32)ef01_char_table_002, (u32)ef01_char_table_003, (u32)ef01_char_table_004, (u32)ef01_char_table_005,
    (u32)ef01_char_table_006, (u32)ef01_char_table_006, (u32)ef01_char_table_008, (u32)ef01_char_table_009, (u32)ef01_char_table_010, (u32)ef01_char_table_011,
    (u32)ef01_char_table_012, (u32)ef01_char_table_013, (u32)ef01_char_table_014, (u32)ef01_char_table_015, (u32)ef01_char_table_016, (u32)ef01_char_table_017,
    (u32)ef01_char_table_018, (u32)ef01_char_table_019, (u32)ef01_char_table_020, (u32)ef01_char_table_021, (u32)ef01_char_table_022, (u32)ef01_char_table_023,
    (u32)ef01_char_table_024, (u32)ef01_char_table_025, (u32)ef01_char_table_026, (u32)ef01_char_table_027, (u32)ef01_char_table_028, (u32)ef01_char_table_029,
    (u32)ef01_char_table_029, (u32)ef01_char_table_031, (u32)ef01_char_table_032, (u32)ef01_char_table_033, (u32)ef01_char_table_034, (u32)ef01_char_table_035,
    (u32)ef01_char_table_036, (u32)ef01_char_table_036, (u32)ef01_char_table_038, (u32)ef01_char_table_039, (u32)ef01_char_table_040, 0,
};

const u16 ef01_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_000[44] = {
    L2(2, 0, 265, 0, 0, 0, 0, 0xAF5F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF60),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF61),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF62),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF63),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF64),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF65),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF66),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF67),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAF67),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_001[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xAF58),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF59),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF5A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF5B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF5C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF5D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF5E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAF5E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_002[36] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xB013),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB014),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB015),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB016),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB017),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB018),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB019),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB019),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_003[40] = {
    L2(3, 0, 265, 0, 0, 0, 0, 0xA691),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA692),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA693),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA694),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA695),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA696),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA697),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA698),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA698),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_004[52] = {
    CMD(CM_EXEC, 29, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB05F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB060),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB061),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB062),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB063),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB064),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB065),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB066),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB067),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB068),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB068),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_005[52] = {
    CMD(CM_EXEC, 29, 1, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB069),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB06A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB06B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB06C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB06D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB06E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB06F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB070),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB071),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB072),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB072),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_006[52] = {
    CMD(CM_EXEC, 29, 2, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB073),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB074),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB075),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB076),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB077),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB078),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB079),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB07A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB07B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB07C),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB07C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_008[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7B),
    CMD(CM_EXEC, 1, 2, 0),
    CMD(CM_EXEC, 1, 3, 0),
    CMD(CM_EXEC, 41, 0, 0),
    CMD(CM_JMP, 0, 10, 7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_009[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7B),
    CMD(CM_EXEC, 1, 4, 0),
    CMD(CM_EXEC, 1, 5, 0),
    CMD(CM_EXEC, 41, 1, 0),
    CMD(CM_JMP, 0, 10, 7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_010[52] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7B),
    CMD(CM_EXEC, 1, 6, 0),
    CMD(CM_EXEC, 1, 7, 0),
    CMD(CM_EXEC, 41, 2, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7E),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF80),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAF80),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_011[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7B),
    CMD(CM_EXEC, 1, 8, 0),
    CMD(CM_EXEC, 1, 9, 0),
    CMD(CM_EXEC, 41, 3, 0),
    CMD(CM_JMP, 0, 10, 7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_012[40] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xA7AE),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7AF),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA7B0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7B1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA7B2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7B3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7B4),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA7B5),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA7B5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_013[92] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xB01A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB01B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB01C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB01D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB01E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB01F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB020),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB021),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB022),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB023),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB024),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB025),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB026),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB027),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB028),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB029),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB02A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB02B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB02C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB02D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB02E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB02E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_014[24] = {
    CMD(CM_EXEC, 1, 2, 0),
    CMD(CM_EXEC, 1, 3, 0),
    CMD(CM_EXEC, 41, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_015[24] = {
    CMD(CM_EXEC, 1, 4, 0),
    CMD(CM_EXEC, 41, 1, 0),
    CMD(CM_EXEC, 1, 5, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_016[24] = {
    CMD(CM_EXEC, 1, 6, 0),
    CMD(CM_EXEC, 1, 7, 0),
    CMD(CM_EXEC, 41, 2, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_017[24] = {
    CMD(CM_EXEC, 1, 8, 0),
    CMD(CM_EXEC, 1, 9, 0),
    CMD(CM_EXEC, 41, 3, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_018[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7B),
    CMD(CM_EXEC, 41, 2, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7E),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7F),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAF80),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAF80),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_019[28] = {
    L2(2, 0, 0, 0, 1, 0, 0, 0xA836),
    L2(1, 0, 0, 0, 1, 0, 0, 0xA832),
    L2(2, 0, 0, 0, 1, 0, 0, 0xA833),
    L2(3, 0, 0, 0, 1, 0, 0, 0xA834),
    L2(4, 0, 0, 0, 1, 0, 0, 0xA835),
    L2(250, 255, 0, 0, 1, 0, 0, 0xA835),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_020[76] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x03E5),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03DE),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03DF),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E1),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E2),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E3),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E4),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E5),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E6),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E7),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E8),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E9),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03EA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03EB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03EC),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03ED),
    L2(250, 255, 0, 0, 0, 0, 0, 0x03ED),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_021[76] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xB01A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB01C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB01E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB020),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB022),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB023),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB024),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB025),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB026),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB027),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB028),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB029),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB02A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB02B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB02C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB02D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB02E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB02E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_022[64] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xB023),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB022),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB023),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB024),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB025),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB026),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB027),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB028),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB029),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB02A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB02B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB02C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB02D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB02E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB02E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_023[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7B),
    CMD(CM_EXEC, 1, 2, 0),
    CMD(CM_EXEC, 1, 3, 0),
    CMD(CM_EXEC, 41, 4, 0),
    CMD(CM_JMP, 0, 10, 7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_024[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7B),
    CMD(CM_EXEC, 1, 4, 0),
    CMD(CM_EXEC, 1, 5, 0),
    CMD(CM_EXEC, 41, 5, 0),
    CMD(CM_JMP, 0, 10, 7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_025[52] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7B),
    CMD(CM_EXEC, 1, 6, 0),
    CMD(CM_EXEC, 1, 7, 0),
    CMD(CM_EXEC, 41, 6, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7E),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF80),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAF80),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_026[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7B),
    CMD(CM_EXEC, 1, 8, 0),
    CMD(CM_EXEC, 1, 9, 0),
    CMD(CM_EXEC, 41, 7, 0),
    CMD(CM_JMP, 0, 10, 7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_027[16] = {
    CMD(CM_EXEC, 29, 1, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_028[12] = {
    CMD(CM_EXEC, 29, 2, 0),
    CMD(CM_JMP, 0, 27, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_029[12] = {
    CMD(CM_EXEC, 29, 3, 0),
    CMD(CM_JMP, 0, 27, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_031[52] = {
    CMD(CM_EXEC, 29, 2, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB07D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB07E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB07F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB080),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB081),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB082),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB083),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB084),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB085),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB086),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB086),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_032[52] = {
    CMD(CM_EXEC, 29, 2, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB07D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB07E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB07F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB080),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB081),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB082),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB083),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB084),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB085),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB086),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB086),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_033[40] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAF7B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAF7D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7E),
    L2(3, 0, 0, 0, 0, 0, 0, 0xAF7F),
    L2(4, 0, 0, 0, 0, 0, 0, 0xAF80),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAF80),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_034[8] = {
    CMD(CM_JMP, 0, 4, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_035[8] = {
    CMD(CM_JMP, 0, 5, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_036[8] = {
    CMD(CM_JMP, 0, 6, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_038[184] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x7820),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7821),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7822),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7823),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7824),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7825),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7826),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7827),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7828),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7829),
    L2(4, 0, 0, 0, 0, 0, 0, 0x782A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x782B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x782C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x782D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x782E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x782F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7830),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7831),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7832),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7833),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7834),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7835),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7836),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7837),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7838),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7839),
    L2(4, 0, 0, 0, 0, 0, 0, 0x783A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x783B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x783C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x783D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x783E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x783F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7840),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7841),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7842),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7843),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7844),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7845),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7846),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7847),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7848),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7849),
    L2(4, 0, 0, 0, 0, 0, 0, 0x784A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x784B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x784C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_039[108] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x784D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x784E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x784F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7850),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7851),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7852),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7853),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7854),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7855),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7856),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7857),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7858),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7859),
    L2(4, 0, 0, 0, 0, 0, 0, 0x785A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x785B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x785C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x785D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x785E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x785F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7860),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7861),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7862),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7863),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7864),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7865),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7866),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_040[12] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7E5),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA7E5),
    CMD(CM_ROA, 0, 0, 0),
};

/* ef13_char_table: 156 entries */
const u32 ef13_char_table[157] = {
    (u32)ef13_char_table_000, (u32)ef13_char_table_001, (u32)ef13_char_table_002, (u32)ef13_char_table_003, (u32)ef13_char_table_004, (u32)ef13_char_table_005,
    (u32)ef13_char_table_006, (u32)ef13_char_table_007, (u32)ef13_char_table_008, (u32)ef13_char_table_008, (u32)ef13_char_table_010, (u32)ef13_char_table_011,
    (u32)ef13_char_table_011, (u32)ef13_char_table_013, (u32)ef13_char_table_014, (u32)ef13_char_table_015, (u32)ef13_char_table_016, (u32)ef13_char_table_017,
    (u32)ef13_char_table_018, (u32)ef13_char_table_019, (u32)ef13_char_table_020, (u32)ef13_char_table_021, (u32)ef13_char_table_022, (u32)ef13_char_table_023,
    (u32)ef13_char_table_024, (u32)ef13_char_table_025, (u32)ef13_char_table_026, (u32)ef13_char_table_027, (u32)ef13_char_table_028, (u32)ef13_char_table_029,
    (u32)ef13_char_table_030, (u32)ef13_char_table_031, (u32)ef13_char_table_032, (u32)ef13_char_table_033, (u32)ef13_char_table_034, (u32)ef13_char_table_035,
    (u32)ef13_char_table_036, (u32)ef13_char_table_037, (u32)ef13_char_table_038, (u32)ef13_char_table_039, (u32)ef13_char_table_040, (u32)ef13_char_table_041,
    (u32)ef13_char_table_042, (u32)ef13_char_table_043, (u32)ef13_char_table_044, (u32)ef13_char_table_045, (u32)ef13_char_table_046, (u32)ef13_char_table_047,
    (u32)ef13_char_table_048, (u32)ef13_char_table_049, (u32)ef13_char_table_050, (u32)ef13_char_table_051, (u32)ef13_char_table_052, (u32)ef13_char_table_053,
    (u32)ef13_char_table_053, (u32)ef13_char_table_053, (u32)ef13_char_table_056, (u32)ef13_char_table_057, (u32)ef13_char_table_058, (u32)ef13_char_table_059,
    (u32)ef13_char_table_060, (u32)ef13_char_table_061, (u32)ef13_char_table_062, (u32)ef13_char_table_063, (u32)ef13_char_table_064, (u32)ef13_char_table_065,
    (u32)ef13_char_table_066, (u32)ef13_char_table_067, (u32)ef13_char_table_068, (u32)ef13_char_table_069, (u32)ef13_char_table_070, (u32)ef13_char_table_071,
    (u32)ef13_char_table_072, (u32)ef13_char_table_073, (u32)ef13_char_table_074, (u32)ef13_char_table_075, (u32)ef13_char_table_076, (u32)ef13_char_table_077,
    (u32)ef13_char_table_078, (u32)ef13_char_table_079, (u32)ef13_char_table_080, (u32)ef13_char_table_081, (u32)ef13_char_table_082, (u32)ef13_char_table_083,
    (u32)ef13_char_table_084, (u32)ef13_char_table_085, (u32)ef13_char_table_086, (u32)ef13_char_table_087, (u32)ef13_char_table_088, (u32)ef13_char_table_089,
    (u32)ef13_char_table_090, (u32)ef13_char_table_091, (u32)ef13_char_table_092, (u32)ef13_char_table_093, (u32)ef13_char_table_094, (u32)ef13_char_table_095,
    (u32)ef13_char_table_096, (u32)ef13_char_table_097, (u32)ef13_char_table_098, (u32)ef13_char_table_099, (u32)ef13_char_table_100, (u32)ef13_char_table_101,
    (u32)ef13_char_table_102, (u32)ef13_char_table_103, (u32)ef13_char_table_104, (u32)ef13_char_table_105, (u32)ef13_char_table_106, (u32)ef13_char_table_107,
    (u32)ef13_char_table_108, (u32)ef13_char_table_109, (u32)ef13_char_table_110, (u32)ef13_char_table_111, (u32)ef13_char_table_112, (u32)ef13_char_table_113,
    (u32)ef13_char_table_114, (u32)ef13_char_table_115, (u32)ef13_char_table_116, (u32)ef13_char_table_117, (u32)ef13_char_table_118, (u32)ef13_char_table_119,
    (u32)ef13_char_table_120, (u32)ef13_char_table_121, (u32)ef13_char_table_122, (u32)ef13_char_table_123, (u32)ef13_char_table_124, (u32)ef13_char_table_125,
    (u32)ef13_char_table_126, (u32)ef13_char_table_127, (u32)ef13_char_table_128, (u32)ef13_char_table_129, (u32)ef13_char_table_130, (u32)ef13_char_table_131,
    (u32)ef13_char_table_132, (u32)ef13_char_table_133, (u32)ef13_char_table_134, (u32)ef13_char_table_135, (u32)ef13_char_table_136, (u32)ef13_char_table_137,
    (u32)ef13_char_table_138, (u32)ef13_char_table_139, (u32)ef13_char_table_140, (u32)ef13_char_table_141, (u32)ef13_char_table_142, (u32)ef13_char_table_143,
    (u32)ef13_char_table_144, (u32)ef13_char_table_145, (u32)ef13_char_table_146, (u32)ef13_char_table_147, (u32)ef13_char_table_148, (u32)ef13_char_table_149,
    (u32)ef13_char_table_150, (u32)ef13_char_table_151, (u32)ef13_char_table_152, (u32)ef13_char_table_153, (u32)ef13_char_table_154, (u32)ef13_char_table_225,
    0,
};

const u16 ef13_char_table_000_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_000[204] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0xA8F4, -1, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F5, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F6, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F7, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F8, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F9, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FA, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FB, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FC, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FD, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FE, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FF, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA900, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA901, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA902, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA903, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA904, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA905, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA906, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA907, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA908, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FE, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FF, -1, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_001[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA681),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA682),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA683),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA684),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA685),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA686),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA686),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_002[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA842),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA843),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA844),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA845),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA846),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA847),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA847),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_003[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0xA842),
    CMD(CM_JMP, 0, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_004[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0xA842),
    CMD(CM_JMP, 0, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_005_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_005[388] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA8F4, -2, 1, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F5, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA924, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F6, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA925, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F7, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA926, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F8, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA927, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F9, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA928, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FA, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA929, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FB, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA92A, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FC, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA92B, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FD, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA924, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FE, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA925, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FF, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA926, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA900, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA927, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA901, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA928, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA902, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA929, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA903, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA92A, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA904, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA92B, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA905, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA924, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA906, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA925, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA907, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA926, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA908, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA927, 0, 47, 0, 171, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA92A, 2, 47, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 3, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA904, -2, 47, 0, 171, 0, 0, 0),
    CMD(CM_END, 0, 0, 33), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA904, -3, 47, 0, 171, 0, 0, 0),
    CMD(CM_END, 0, 0, 33), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_006_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 5) };
const u16 ef13_char_table_006[148] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0xA92C, -4, 1, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA92D, 0, 2, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA92E, 0, 2, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA92F, 0, 2, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA930, 0, 2, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA931, 0, 2, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA932, 0, 2, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA933, 0, 2, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA92C, 0, 2, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA92F, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 1), 0, 0, 0, 0,
    CMD(CM_WSWK, 16384, 1, 16392), 0, 0, 0, 0,
    CMD(CM_WCEQ, 16384, 1, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA930, -4, 2, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA930, -5, 2, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_007_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_007[204] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA8F4, -25, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F5, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F6, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F7, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F8, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F9, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FA, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FB, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FC, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FD, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FE, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FF, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA900, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA901, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA902, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA903, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA904, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA905, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA906, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA907, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA908, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FE, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FF, -25, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_008_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_008[140] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0xA93B, -26, 2, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA93C, 0, 2, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA93D, 0, 2, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA93E, 0, 2, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA93F, 0, 2, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA940, 0, 2, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA941, 0, 2, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA942, 0, 2, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA943, 0, 2, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA944, 0, 2, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA945, 0, 2, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA946, 0, 2, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA93B, 0, 2, 0, 143, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA93C, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA93D, -26, 2, 0, 143, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_010_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 5) };
const u16 ef13_char_table_010[148] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x2193, -6, 22, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2194, 0, 22, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2194, 0, 22, 0, 0, 0, 1, 33),
    CMD(CM_PA_X, 0, 28672, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x219B, 0, 23, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x219C, 0, 24, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x219D, 0, 25, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x219E, 0, 22, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x219F, 0, 22, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x219F, 0, 22, 0, 0, 0, 1, 33),
    CMD(CM_PA_X, 0, 28672, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2190, 0, 23, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2191, 0, 24, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2192, 0, 25, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2193, 0, 22, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 11, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_011_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 5) };
const u16 ef13_char_table_011[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2195),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2196),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2197),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2198),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2199),
    L2(3, 0, 0, 0, 0, 0, 0, 0x219A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x219A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_013_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 5) };
const u16 ef13_char_table_013[12] = {
    L2(3, 0, 267, 0, 0, 0, 0, 0x2195),
    CMD(CM_JMP, 0, 11, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_014_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 5) };
const u16 ef13_char_table_014[12] = {
    L2(3, 0, 266, 0, 0, 0, 0, 0x2195),
    CMD(CM_JMP, 0, 11, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_015_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_015[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xA880, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA881, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA882, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA883, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA884, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA885, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA886, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA887, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA888, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA889, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA88A, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA88B, 7, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_016_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_016[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xA94C, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA94D, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA94E, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA94F, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA950, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA951, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA952, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA953, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA954, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA955, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA956, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA957, 8, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_017_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_017[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xA958, 9, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA959, 9, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA95A, 9, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA95B, 9, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA95C, 9, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA95D, 9, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA95E, 9, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA95F, 9, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA960, 9, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA961, 9, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA962, 9, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA963, 9, 5, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_018_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_018[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xA964, 10, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA965, 10, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA966, 10, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA967, 10, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA968, 10, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA969, 10, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA96A, 10, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA96B, 10, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA96C, 10, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA96D, 10, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA96E, 10, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA96F, 10, 6, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_019_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_019[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xA970, 11, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA971, 11, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA972, 11, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA973, 11, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA974, 11, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA975, 11, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA976, 11, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA977, 11, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA978, 11, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA979, 11, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA97A, 11, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA97B, 11, 7, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_020_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_020[68] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xA97C, 12, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA97D, 12, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA97E, 12, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA97F, 12, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA980, 12, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA981, 12, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA982, 12, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA983, 12, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_021_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_021[68] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xA984, 13, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA985, 13, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA986, 13, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA987, 13, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA988, 13, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA989, 13, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA98A, 13, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA98B, 13, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_022_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_022[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xA98C, 14, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA98D, 14, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA98E, 14, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA98F, 14, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA990, 14, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA991, 14, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA992, 14, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA993, 14, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA994, 14, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA995, 14, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA996, 14, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA997, 14, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_023_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_023[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xA998, 15, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA999, 15, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA99A, 15, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA99B, 15, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA99C, 15, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA99D, 15, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA99E, 15, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA99F, 15, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9A0, 15, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9A1, 15, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9A2, 15, 12, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9A3, 15, 12, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_024_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_024[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9A4, 16, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9A5, 16, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9A6, 16, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9A7, 16, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9A8, 16, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9A9, 16, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9AA, 16, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9AB, 16, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9AC, 16, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9AD, 16, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9AE, 16, 13, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9AF, 16, 13, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_025_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_025[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9B0, 17, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9B1, 17, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9B2, 17, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9B3, 17, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9B4, 17, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9B5, 17, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9B6, 17, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9B7, 17, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9B8, 17, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9B9, 17, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9BA, 17, 14, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9BB, 17, 14, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_026_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_026[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9BC, 18, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9BD, 18, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9BE, 18, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9BF, 18, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9C0, 18, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9C1, 18, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9C2, 18, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9C3, 18, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9C4, 18, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9C5, 18, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9C6, 18, 15, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0xA9C7, 18, 15, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_027_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_027[172] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88C, -20, 27, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88C, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88D, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88E, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88F, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA890, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA891, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA892, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA893, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA894, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA895, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA896, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA897, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA898, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA899, 0, 20, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88E, 0, 20, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88F, -20, 20, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_028_head[4] = { HEAD(2, 0, 8, 0, 0, 0, 0) };
const u16 ef13_char_table_028[64] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A3),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A4),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A5),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A6),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA8A7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_029_head[4] = { HEAD(2, 0, 8, 0, 0, 0, 0) };
const u16 ef13_char_table_029[64] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A3),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A4),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A5),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A6),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA8A7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_030_head[4] = { HEAD(2, 0, 8, 0, 0, 0, 0) };
const u16 ef13_char_table_030[64] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0xA89A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A3),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A4),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A5),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A6),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA8A7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_031_head[4] = { HEAD(2, 0, 8, 0, 0, 0, 0) };
const u16 ef13_char_table_031[64] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0xA89A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA89F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A3),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A4),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A5),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A6),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8A7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA8A7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_032_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_032[140] = {
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8CF, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8C4, -19, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 335, 0, 0, 0, 1, 0xA8C5, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8C6, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8C7, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8C8, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8C9, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8CA, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8CB, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8CC, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8CD, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8CE, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8CF, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8C4, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0xA8C5, 0, 17, 0, 66, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_033_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_033[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8D0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D4),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA8D4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_034_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_034[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA8D0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D4),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA8D4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_035_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_035[28] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0xA8D0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D4),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA8D4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_036_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_036[28] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0xA8D0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA8D4),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA8D4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_037_head[4] = { HEAD(4, 0, 10, 10, 0, 6, 0) };
const u16 ef13_char_table_037[172] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88C, -21, 28, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88C, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88D, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88E, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88F, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA890, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA891, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA892, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA893, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA894, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA895, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA896, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA897, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA898, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA899, 0, 30, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88E, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88F, -21, 30, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_038_head[4] = { HEAD(4, 0, 12, 10, 0, 6, 0) };
const u16 ef13_char_table_038[172] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88C, -22, 29, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88C, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88D, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88E, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88F, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA890, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA891, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA892, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA893, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA894, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA895, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA896, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA897, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA898, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA899, 0, 30, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88E, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88F, -22, 30, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_039_head[4] = { HEAD(4, 0, 14, 10, 0, 6, 0) };
const u16 ef13_char_table_039[172] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88C, -23, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88C, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88D, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88E, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88F, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA890, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA891, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA892, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA893, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA894, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA895, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA896, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA897, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA898, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA899, 0, 50, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88E, 0, 50, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88F, -23, 50, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_040_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_040[20] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA88C, -24, 16, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 37, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_041_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_041[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA33, -28, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA33, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA34, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA35, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA36, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA37, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA38, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA39, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA3A, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_042_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_042[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2B, -28, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2B, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2C, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2D, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2E, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2F, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA30, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA31, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA32, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_043_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_043[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA23, -28, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA23, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA24, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA25, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA26, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA27, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA28, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA29, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2A, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_044_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_044[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA1B, -28, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA1B, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA1C, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA1D, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA1E, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA1F, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA20, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA21, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA22, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_045_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_045[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA13, -28, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA13, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA14, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA15, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA16, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA17, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA18, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA19, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA1A, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_046[12] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xAA36),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAA36),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_047[12] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xAA2E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAA2E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_048[12] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xAA26),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAA26),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_049[12] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xAA1E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAA1E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_050[12] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xAA16),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAA16),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_051[104] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0xAA3C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA3D),
    L2(1, 0, 340, 0, 0, 0, 0, 0xAA3E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA3F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA40),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA41),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA42),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA43),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA3C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA3D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA3E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA3F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA40),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA41),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA42),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA43),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA3C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA3D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA3E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA3F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA40),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA41),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA42),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA43),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAA43),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_052[40] = {
    L2(1, 0, 340, 0, 0, 0, 0, 0xAA3C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAA3D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAA3E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAA3F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAA40),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAA41),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAA42),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAA43),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAA43),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_053[52] = {
    L2(1, 0, 341, 0, 0, 0, 0, 0x2C99),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2C9B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2C9C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2C9D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2C9E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2C9F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2CA0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2CA1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2CA2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D10),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D11),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D11),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_056[52] = {
    L2(1, 0, 341, 0, 0, 0, 0, 0x2D12),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D13),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D14),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D15),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D16),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D17),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D18),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D1A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D1B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D1C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D1C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_057[52] = {
    L2(1, 0, 331, 0, 0, 0, 0, 0x2DD1),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2DD2),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2DD3),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2DD4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2DD5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2DD6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2DD7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2DD8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2DD9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2DDA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2DDB),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2DDB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_058_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 4) };
const u16 ef13_char_table_058[52] = {
    L4(1, 0, 0, 0, 1, 0, 0, 0xA9F3, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0xA9EE, -29, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA9EF, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA9F0, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA9F1, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_059_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 4) };
const u16 ef13_char_table_059[52] = {
    L4(1, 0, 0, 0, 1, 0, 0, 0xA9F3, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0xA9EE, -30, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA9EF, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA9F0, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA9F1, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_060[12] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x2DDD),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2DDD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_061_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_061[276] = {
    L4(2, 0, 322, 0, 0, 0, 0, 0x0320, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 487, 0, 0, 0, 0, 0x0321, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0322, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0323, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0324, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0325, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0326, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0327, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0328, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0329, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032A, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032B, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032C, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032D, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032E, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032F, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0330, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0331, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0332, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0333, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0334, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0335, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0336, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0337, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0338, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0339, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033A, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033B, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033C, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033D, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033E, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033F, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0320, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0321, -32, 21, 0, 64, 0, 3, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_062_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_062[276] = {
    L4(2, 0, 322, 0, 0, 0, 0, 0x0340, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 486, 0, 0, 0, 0, 0x0341, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0342, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0343, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0344, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0345, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0346, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0347, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0348, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0349, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034A, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034B, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034C, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034D, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034E, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034F, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0350, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0351, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0352, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0353, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0354, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0355, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0356, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0357, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0358, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0359, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035A, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035B, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035C, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035D, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035E, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035F, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0340, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0341, -33, 21, 0, 64, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_063[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02EA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02EB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02EC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02ED),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02ED),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_064[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F9),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02F9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_065[8] = {
    CMD(CM_JMP, 0, 63, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_066[8] = {
    CMD(CM_JMP, 0, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_067[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x02E8),
    CMD(CM_JMP, 0, 63, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_068[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x02F1),
    CMD(CM_JMP, 0, 64, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_069_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_069[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x02E8),
    CMD(CM_JMP, 0, 63, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_070_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_070[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x02F1),
    CMD(CM_JMP, 0, 64, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_071_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 5) };
const u16 ef13_char_table_071[20] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x2193, -34, 22, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_072_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_072[284] = {
    L4(2, 0, 322, 0, 0, 0, 0, 0x0320, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 487, 0, 0, 0, 0, 0x0321, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0322, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0323, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0324, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0325, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0326, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0327, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0328, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0329, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032A, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032B, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032C, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032D, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032E, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032F, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0330, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0331, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0332, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0333, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0334, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0335, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0336, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0337, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0338, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0339, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033A, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033B, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033C, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033D, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033E, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033F, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0320, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0321, -32, 21, 0, 64, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_073_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_073[284] = {
    L4(2, 0, 322, 0, 0, 0, 0, 0x0340, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 486, 0, 0, 0, 0, 0x0341, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0342, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0343, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0344, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0345, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0346, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0347, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0348, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0349, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034A, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034B, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034C, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034D, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034E, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034F, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0350, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0351, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0352, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0353, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0354, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0355, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0356, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0357, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0358, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0359, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035A, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035B, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035C, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035D, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035E, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035F, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0340, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0341, -33, 21, 0, 64, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_074_head[4] = { HEAD(4, 0, 14, 10, 0, 6, 0) };
const u16 ef13_char_table_074[204] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA909, -35, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90A, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90B, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90C, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90D, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90E, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90F, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA910, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA911, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA912, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA915, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA916, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA917, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA918, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA919, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91A, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91B, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91C, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91D, 0, 46, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 0, 46, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, -36, 46, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_075_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_075[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA681),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA682),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA683),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA684),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA685),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA686),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA686),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_076_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_076[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA91E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA91F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA920),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA923),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA923),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_077_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_077[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0xA91E),
    CMD(CM_JMP, 0, 76, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_078_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_078[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0xA91E),
    CMD(CM_JMP, 0, 76, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_079_head[4] = { HEAD(4, 0, 14, 10, 0, 6, 0) };
const u16 ef13_char_table_079[204] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA8F4, -53, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F5, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F6, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F7, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F8, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F9, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FA, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FB, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FC, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FD, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FE, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FF, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA900, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA901, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA902, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA903, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA904, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA905, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA906, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA907, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA908, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FE, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FF, -58, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_080_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_080[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA681),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA682),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA683),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA684),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA685),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA686),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA686),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_081_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_081[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA91E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA91F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA920),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA921),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA922),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA923),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA923),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_082_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_082[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0xA91E),
    CMD(CM_JMP, 0, 81, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_083_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_083[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0xA91E),
    CMD(CM_JMP, 0, 81, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_084_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_084[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2B, -37, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2B, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2C, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2D, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2E, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2F, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA30, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA31, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA32, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_085_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_085[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA23, -37, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA23, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA24, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA25, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA26, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA27, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA28, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA29, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xAA2A, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_086_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_086[292] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5340, -38, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5341, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5342, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5343, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5344, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5345, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5346, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5347, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5348, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5349, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534A, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534B, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534C, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534D, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534E, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534F, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5350, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5351, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5352, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5353, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5354, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5355, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5356, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5357, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5358, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5359, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535A, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535B, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535C, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535D, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5340, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5341, 0, 31, 0, 162, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5349, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534A, -38, 31, 0, 162, 0, 0, 0),
    CMD(CM_END, 0, 0, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_087_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_087[28] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x539A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5398),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5399),
    L2(3, 0, 0, 0, 0, 0, 0, 0x539A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x539B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x539C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_088_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_088[8] = {
    CMD(CM_JMP, 0, 87, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_089_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_089[12] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0x539A),
    CMD(CM_JMP, 0, 87, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_090_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_090[12] = {
    L2(1, 0, 266, 0, 0, 0, 0, 0x539A),
    CMD(CM_JMP, 0, 87, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_091_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_091[292] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5340, -38, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5341, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5342, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5343, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5344, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5345, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5346, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5347, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5348, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5349, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534A, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534B, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534C, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534D, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534E, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534F, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5350, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5351, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5352, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5353, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5354, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5355, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5356, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5357, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5358, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5359, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535A, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535B, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535C, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535D, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5340, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5341, 0, 32, 0, 162, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5349, 0, 32, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534A, -38, 32, 0, 162, 0, 0, 0),
    CMD(CM_END, 0, 0, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_092_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_092[300] = {
    L4(2, 0, 322, 0, 0, 0, 0, 0x0320, -39, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0321, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0322, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0323, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0324, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0325, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0326, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0327, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0328, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0329, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032A, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032B, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032C, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032D, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032E, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032F, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0330, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0331, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0332, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0333, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0334, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0335, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0336, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0337, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0338, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0339, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033A, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033B, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033C, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033D, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033E, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033F, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0320, 0, 26, 0, 163, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0327, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0328, -39, 26, 0, 163, 0, 0, 0),
    CMD(CM_END, 0, 0, 10), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_093_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_093[300] = {
    L4(2, 0, 322, 0, 0, 0, 0, 0x0340, -40, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0341, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0342, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0343, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0344, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0345, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0346, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0347, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0348, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0349, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034A, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034B, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034C, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034D, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034E, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034F, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0350, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0351, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0352, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0353, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0354, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0355, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0356, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0357, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0358, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0359, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035A, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035B, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035C, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035D, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035E, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035F, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0340, 0, 21, 0, 163, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0344, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0345, -40, 26, 0, 163, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_094_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_094[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02EA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02EB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02EC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02ED),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02ED),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_095_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_095[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F9),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02F9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_096_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_096[8] = {
    CMD(CM_JMP, 0, 94, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_097_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_097[8] = {
    CMD(CM_JMP, 0, 95, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_098_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_098[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x02E8),
    CMD(CM_JMP, 0, 94, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_099_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_099[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x02F1),
    CMD(CM_JMP, 0, 95, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_100_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_100[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x02E8),
    CMD(CM_JMP, 0, 94, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_101_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_101[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x02F1),
    CMD(CM_JMP, 0, 95, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_102_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_102[572] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x535E, -56, 37, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x535F, 0, 37, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5360, 0, 37, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5361, 0, 37, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5362, 0, 37, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5363, 0, 37, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5364, 0, 38, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5365, 0, 38, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5366, 0, 38, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5367, 0, 38, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5368, 0, 39, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5369, 0, 39, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x536A, 0, 39, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x536B, 0, 39, 0, 144, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x536C, 0, 39, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x536D, -56, 39, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x536E, 0, 39, 0, 128, 0, 0, 0),
    CMD(CM_WCGT, 16399, 3, 16386), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_SSTX, 0, 3, 256), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_SSTX, 0, 0, 1248), 0, 0, 0, 0,
    CMD(CM_ABBAK, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x536E, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x536F, 41, 39, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5370, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5371, 41, 39, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5372, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5373, 41, 39, 0, 0, 0, 0, 0),
    CMD(CM_SSTX, 0, 3, 512), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5374, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5375, 41, 39, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5376, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5377, 41, 39, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5378, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5379, 41, 39, 0, 0, 0, 0, 0),
    CMD(CM_SSTX, 0, 3, 768), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x537A, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x537B, 41, 38, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x537C, -41, 38, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x537D, 41, 38, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x537E, -41, 38, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x537F, 41, 38, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5380, -41, 38, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5381, 41, 38, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5382, -41, 38, 0, 87, 0, 0, 0),
    CMD(CM_SSTX, 0, 3, 768), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5383, 41, 37, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5384, -41, 37, 0, 87, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5385, 41, 37, 0, 87, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5386, -41, 37, 0, 87, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5387, 41, 37, 0, 87, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5388, -41, 37, 0, 87, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5389, 41, 37, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x538A, -41, 37, 0, 87, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x538B, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x538C, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x538D, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x538E, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x538F, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5390, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5391, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5392, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5393, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5394, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5395, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5396, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5397, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_103_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_103[12] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_104_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_104[8] = {
    CMD(CM_JMP, 0, 103, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_105_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_105[12] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0x0000),
    CMD(CM_JMP, 0, 103, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_106_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_106[12] = {
    L2(1, 0, 266, 0, 0, 0, 0, 0x0000),
    CMD(CM_JMP, 0, 103, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_107_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 0) };
const u16 ef13_char_table_107[196] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x575E, -42, 45, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x575E, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x575F, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5760, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5761, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5762, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5763, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5764, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5765, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5766, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5767, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5768, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5769, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576A, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576B, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576C, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576D, 0, 49, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x575F, 42, 49, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 4, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xAC4C, -42, 49, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xAC4C, -43, 49, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_108_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_108[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA681),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA682),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA683),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA684),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA685),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA686),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA686),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_109_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_109[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x576E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x576F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5770),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5771),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5772),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5773),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5773),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_110_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_110[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x576A),
    CMD(CM_JMP, 0, 109, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_111_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_111[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x576A),
    CMD(CM_JMP, 0, 109, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_112_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_112[196] = {
    CMD(CM_PS_Y, 0, 0, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5241, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5242, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5243, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5244, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 111, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x5245, -44, 33, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5246, 0, 33, 0, 150, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5247, 0, 33, 0, 150, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5248, -45, 33, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5249, -45, 33, 0, 150, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524A, 0, 33, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524B, 0, 33, 0, 150, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524C, 0, 33, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524D, 0, 33, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524E, 0, 33, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5245, 0, 33, 0, 147, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 10), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x524F, 0, 33, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5250, 0, 33, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 11), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5250, 0, 33, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524F, 0, 33, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 10), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_113_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_113[32] = {
    L2(4, 0, 323, 0, 0, 0, 0, 0x524F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5250),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5251),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5252),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5253),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5254),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5254),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_114_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_114[24] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x5246),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5247),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5246),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5245),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5245),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_115_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_115[12] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x5246),
    CMD(CM_JMP, 0, 114, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_116_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_116[12] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x524F),
    CMD(CM_JMP, 0, 113, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_117_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_117[204] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA909, -51, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA910, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA911, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA912, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA915, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA916, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA917, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA918, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA919, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91D, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, -46, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_118_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_118[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA681),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA682),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA683),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA684),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA685),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA686),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA686),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_119_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_119[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA91E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA91F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA920),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xA923),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA923),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_120_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_120[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0xA91E),
    CMD(CM_JMP, 0, 119, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_121_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_121[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0xA91E),
    CMD(CM_JMP, 0, 119, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_122_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_122[100] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5750, -47, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5751, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5752, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5753, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5754, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5755, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5756, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5757, 0, 44, 0, 138, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5753, 0, 44, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5754, -47, 44, 0, 138, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_123_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_123[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x5758),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5759),
    L2(2, 0, 0, 0, 0, 0, 0, 0x575A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x575B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x575C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x575D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x575D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_124_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_124[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x5758),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5759),
    L2(2, 0, 0, 0, 0, 0, 0, 0x575A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x575B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x575C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x575D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x575D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_125_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_125[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x5755),
    CMD(CM_JMP, 0, 124, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_126_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_126[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x5755),
    CMD(CM_JMP, 0, 124, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_127_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_127[92] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5777, -48, 43, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5778, 0, 43, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5779, 0, 43, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x577A, 0, 43, 0, 134, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x577A, 48, 43, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 4, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5777, -48, 43, 0, 134, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5777, -52, 43, 0, 134, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_128_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_128[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x577B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x577C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x577D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x577E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x577F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5780),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5780),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_129_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_129[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x577B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x577C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x577D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x577E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x577F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5780),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5780),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_130_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_130[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x577A),
    CMD(CM_JMP, 0, 129, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_131_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_131[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x577A),
    CMD(CM_JMP, 0, 129, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_132_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_132[20] = {
    L4(10, 0, 0, 0, 0, 0, 0, 0x0000, 49, 8, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_133_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_133[12] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_134_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_134[20] = {
    L4(10, 0, 0, 0, 0, 0, 0, 0x0000, 49, 8, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_135_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_135[12] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_136_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_136[220] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA8F4, -57, 1, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F5, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F6, 50, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F7, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F8, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F9, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FA, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FB, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FC, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FD, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FE, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FF, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA900, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA901, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA902, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA903, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA904, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA905, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA906, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA907, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA908, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F5, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F6, 0, 2, 0, 153, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FE, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FF, -50, 2, 0, 153, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_137_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_137[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA681),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA682),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA683),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA684),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA685),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA686),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA686),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_138_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_138[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA861),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA862),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA863),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA864),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA865),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA866),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA866),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_139_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_139[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0xA861),
    CMD(CM_JMP, 0, 138, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_140_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_140[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0xA861),
    CMD(CM_JMP, 0, 138, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_141_head[4] = { HEAD(4, 0, 34, 10, 0, 6, 0) };
const u16 ef13_char_table_141[52] = {
    CMD(CM_PS_Y, 0, 0, 1), 0, 0, 0, 0,
    L4(7, 0, 0, 0, 0, 0, 0, 0x5241, 0, 0, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x5242, 0, 0, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x5243, 0, 0, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x5244, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 112, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_142_head[4] = { HEAD(4, 0, 36, 10, 0, 6, 0) };
const u16 ef13_char_table_142[52] = {
    CMD(CM_PS_Y, 0, 0, 1), 0, 0, 0, 0,
    L4(9, 0, 0, 0, 0, 0, 0, 0x5241, 0, 0, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x5242, 0, 0, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x5243, 0, 0, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x5244, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 112, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_143_head[4] = { HEAD(4, 0, 38, 10, 0, 6, 0) };
const u16 ef13_char_table_143[172] = {
    CMD(CM_PS_Y, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5244, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5245, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5245, -44, 33, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5246, 0, 33, 0, 148, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5247, 0, 33, 0, 148, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5248, -45, 33, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5249, -45, 33, 0, 148, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524A, 0, 33, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524B, 0, 33, 0, 148, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524C, 0, 33, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524D, 0, 33, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524E, 0, 33, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5245, 0, 33, 0, 145, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 10), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x524F, 0, 33, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5250, 0, 33, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 9), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5250, 0, 33, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524F, 0, 33, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_144_head[4] = { HEAD(4, 0, 14, 10, 0, 6, 0) };
const u16 ef13_char_table_144[308] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5340, -38, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5341, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5342, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5343, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5344, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5345, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5346, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5347, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5348, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5349, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534A, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534B, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534C, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534D, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534E, 0, 48, 0, 164, 0, 0, 0),
    CMD(CM_SCHY, 1, -1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x534F, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5350, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5351, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5352, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5353, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5354, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5355, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5356, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5357, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5358, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5359, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535A, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535B, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535C, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535D, 0, 48, 0, 164, 0, 0, 0),
    CMD(CM_SCHY, 1, -1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5340, 0, 48, 0, 164, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5341, 0, 48, 0, 164, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5349, 0, 48, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534A, -38, 48, 0, 164, 0, 0, 0),
    CMD(CM_END, 0, 0, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_145_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_145[228] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA909, -46, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA910, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA911, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA912, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA915, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA916, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA917, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA918, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA919, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91D, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 46, 2, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 0, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, -46, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, -51, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_146_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_146[228] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA909, -46, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA910, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA911, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA912, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA915, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA916, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA917, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA918, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA919, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91D, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 46, 2, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 1, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, -46, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, -51, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_147_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 0) };
const u16 ef13_char_table_147[196] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x575E, -59, 45, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x575E, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x575F, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5760, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5761, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5762, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5763, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5764, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5765, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5766, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5767, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5768, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5769, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576A, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576B, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576C, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576D, 0, 49, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x575F, 59, 49, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 5, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xAC4C, -59, 49, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xAC4C, -60, 49, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_148_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_148[100] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5750, -62, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5751, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5752, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5753, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5754, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5755, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5756, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5757, 0, 44, 0, 138, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5753, 0, 44, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5754, -62, 44, 0, 138, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_149_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_149[92] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5777, -63, 43, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5778, 0, 43, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5779, 0, 43, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x577A, 0, 43, 0, 134, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x577A, 63, 43, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 5, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5777, -63, 43, 0, 134, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5777, -66, 43, 0, 134, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_150_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_150[220] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA8F4, -67, 1, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F5, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F6, 64, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F7, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F8, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F9, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FA, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FB, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FC, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FD, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FE, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FF, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA900, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA901, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA902, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA903, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA904, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA905, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA906, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA907, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA908, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F5, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8F6, 0, 2, 0, 153, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FE, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA8FF, -64, 2, 0, 153, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_151_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_151[204] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA909, -65, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA910, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA911, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA912, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA915, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA916, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA917, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA918, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA919, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91D, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, -61, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_152_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_152[228] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA909, -61, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA910, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA911, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA912, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA915, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA916, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA917, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA918, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA919, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91D, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 61, 2, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 0, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, -61, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, -65, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_153_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_153[228] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0xA909, -61, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA90F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA910, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA911, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA912, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA915, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA916, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA917, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA918, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA919, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0xA91D, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA913, 61, 2, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 1, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, -61, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0xA914, -65, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_154_head[4] = { HEAD(4, 0, 4, 10, 0, 6, 0) };
const u16 ef13_char_table_154[236] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4ADB, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4ADC, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4ADD, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4ADE, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4ADF, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AE0, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AE1, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AE2, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AE3, 0, 26, 0, 64, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x0020, 0x0A00, 0x0A05,
    L4(2, 0, 0, 0, 0, 0, 0, 0xA904, -4, 1, 0, 69, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA900, 0, 1, 0, 69, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA905, 0, 1, 0, 69, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA901, 0, 1, 0, 69, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0xA8EC, -5, 2, 0, 65, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA8F0, 0, 2, 0, 65, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA8EC, 0, 2, 0, 65, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x0020, 0x0A00, 0x0A05,
    L4(2, 0, 0, 0, 0, 0, 0, 0xA904, -4, 1, 0, 69, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA900, 0, 1, 0, 69, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA905, 0, 1, 0, 69, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA901, 0, 1, 0, 69, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0xA8EC, -5, 2, 0, 65, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA8F0, 0, 2, 0, 65, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xA8EC, 0, 2, 0, 65, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_225_head[4] = { HEAD(2, 0, 8, 0, 0, 0, 0) };
const u16 ef13_char_table_225[108] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x20F2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x20F3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x20F4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x20F5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x20F6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2195),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2196),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2197),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2198),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2199),
    L2(2, 0, 0, 0, 0, 0, 0, 0x219A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2190),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2191),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2192),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2193),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2194),
    L2(2, 0, 0, 0, 0, 0, 0, 0x219B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x219C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x219D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x219E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x219F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x21A0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x21A1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x21A2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x21A3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x21A4),
    CMD(CM_ROA, 0, 0, 0),
};

/* effg0_char_table_0: 3 entries */
const u32 effg0_char_table_0[4] = {
    (u32)effg0_char_table_0_000, (u32)effg0_char_table_0_001, (u32)effg0_char_table_0_002, 0,
};

/* effg0_char_table_1: 3 entries */
const u32 effg0_char_table_1[4] = {
    (u32)effg0_char_table_1_000, (u32)effg0_char_table_1_001, (u32)effg0_char_table_1_002, 0,
};

/* effg0_char_table_2: 3 entries */
const u32 effg0_char_table_2[4] = {
    (u32)effg0_char_table_2_000, (u32)effg0_char_table_2_001, (u32)effg0_char_table_2_002, 0,
};

/* effg0_char_table_3: 3 entries */
const u32 effg0_char_table_3[4] = {
    (u32)effg0_char_table_3_000, (u32)effg0_char_table_3_001, (u32)effg0_char_table_3_002, 0,
};

/* effg0_char_table_4: 3 entries */
const u32 effg0_char_table_4[4] = {
    (u32)effg0_char_table_4_000, (u32)effg0_char_table_4_001, (u32)effg0_char_table_4_002, 0,
};

/* effg0_char_table_5: 3 entries */
const u32 effg0_char_table_5[4] = {
    (u32)effg0_char_table_5_000, (u32)effg0_char_table_5_001, (u32)effg0_char_table_5_002, 0,
};

/* effg0_char_table_6: 3 entries */
const u32 effg0_char_table_6[4] = {
    (u32)effg0_char_table_6_000, (u32)effg0_char_table_6_001, (u32)effg0_char_table_6_002, 0,
};

/* effg0_char_table_7: 3 entries */
const u32 effg0_char_table_7[4] = {
    (u32)effg0_char_table_7_000, (u32)effg0_char_table_7_001, (u32)effg0_char_table_7_002, 0,
};

/* effg0_char_table_8: 3 entries */
const u32 effg0_char_table_8[4] = {
    (u32)effg0_char_table_7_000, (u32)effg0_char_table_7_001, (u32)effg0_char_table_7_002, 0,
};

/* ag_face_panel_table: 1 entry */
const u32 ag_face_panel_table[2] = {
    (u32)ag_face_panel_table_000, 0,
};

const u16 effg0_char_table_0_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_0_000[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0xA600),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_0_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_0_001[20] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xA601),
    L2(6, 0, 0, 0, 0, 0, 0, 0xA602),
    L2(90, 0, 0, 0, 0, 0, 0, 0xA603),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA603),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_0_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_0_002[36] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xA604),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA605),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA606),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA607),
    L2(3, 1, 0, 0, 0, 0, 0, 0xA608),
    L2(30, 2, 0, 0, 0, 0, 0, 0xA609),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA609),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_1_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_1_000[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0xA60A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_1_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_1_001[48] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xA60B),
    L2(7, 0, 0, 0, 0, 0, 0, 0xA60C),
    L2(32, 0, 0, 0, 0, 0, 0, 0xA60D),
    CMD(CM_FOR, 0, 0, 3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA60E),
    L2(16, 0, 0, 0, 0, 0, 0, 0xA60F),
    L2(10, 0, 0, 0, 0, 0, 0, 0xA610),
    L2(8, 0, 0, 0, 0, 0, 0, 0xA60E),
    L2(6, 0, 0, 0, 0, 0, 0, 0xA60D),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA60D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_1_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_1_002[72] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xA611),
    L2(8, 0, 0, 0, 0, 0, 0, 0xA612),
    L2(32, 0, 0, 0, 0, 0, 0, 0xA613),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA614),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA615),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA616),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA617),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA618),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA619),
    L2(6, 0, 0, 0, 0, 0, 0, 0xA61A),
    L2(7, 0, 0, 0, 0, 0, 0, 0xA61B),
    L2(4, 1, 0, 0, 0, 0, 0, 0xA61C),
    L2(6, 2, 0, 0, 0, 0, 0, 0xA61D),
    L2(6, 2, 0, 0, 0, 0, 0, 0xA61E),
    L2(20, 2, 0, 0, 0, 0, 0, 0xA61F),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA61F),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_2_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_2_000[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0xA624),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_2_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_2_001[32] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xA622),
    L2(58, 0, 0, 0, 0, 0, 0, 0xA623),
    L2(7, 0, 0, 0, 0, 0, 0, 0xA622),
    L2(8, 0, 0, 0, 0, 0, 0, 0xA621),
    L2(58, 0, 0, 0, 0, 0, 0, 0xA620),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA621),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA621),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_2_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_2_002[36] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xA625),
    L2(8, 0, 0, 0, 0, 0, 0, 0xA626),
    L2(8, 0, 0, 0, 0, 0, 0, 0xA627),
    L2(7, 0, 0, 0, 0, 0, 0, 0xA628),
    L2(6, 0, 0, 0, 0, 0, 0, 0xA629),
    L2(20, 1, 0, 0, 0, 0, 0, 0xA62A),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA62A),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_3_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_3_000[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0xA62F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_3_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_3_001[32] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xA62D),
    L2(58, 0, 0, 0, 0, 0, 0, 0xA62E),
    L2(7, 0, 0, 0, 0, 0, 0, 0xA62D),
    L2(8, 0, 0, 0, 0, 0, 0, 0xA62C),
    L2(58, 0, 0, 0, 0, 0, 0, 0xA62B),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA62C),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA62C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_3_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_3_002[36] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xA630),
    L2(8, 0, 0, 0, 0, 0, 0, 0xA631),
    L2(8, 0, 0, 0, 0, 0, 0, 0xA632),
    L2(7, 0, 0, 0, 0, 0, 0, 0xA633),
    L2(6, 0, 0, 0, 0, 0, 0, 0xA634),
    L2(20, 1, 0, 0, 0, 0, 0, 0xA635),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA635),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_4_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_4_000[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0xA63A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_4_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_4_001[32] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xA638),
    L2(58, 0, 0, 0, 0, 0, 0, 0xA639),
    L2(7, 0, 0, 0, 0, 0, 0, 0xA638),
    L2(8, 0, 0, 0, 0, 0, 0, 0xA637),
    L2(58, 0, 0, 0, 0, 0, 0, 0xA636),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA637),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA637),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_4_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_4_002[36] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xA63B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xA63C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xA63D),
    L2(7, 0, 0, 0, 0, 0, 0, 0xA63E),
    L2(6, 0, 0, 0, 0, 0, 0, 0xA63F),
    L2(20, 1, 0, 0, 0, 0, 0, 0xA640),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA640),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_5_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_5_000[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0xA641),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_5_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_5_001[68] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xA642),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA643),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA644),
    L2(6, 0, 0, 0, 0, 0, 0, 0xA645),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA646),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA647),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA648),
    L2(6, 0, 0, 0, 0, 0, 0, 0xA649),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA642),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA643),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA644),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA645),
    L2(6, 0, 0, 0, 0, 0, 0, 0xA643),
    L2(7, 0, 0, 0, 0, 0, 0, 0xA64A),
    L2(32, 0, 0, 0, 0, 0, 0, 0xA64B),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA64B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_5_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_5_002[36] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xA64C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA64D),
    L2(4, 1, 0, 0, 0, 0, 0, 0xA64E),
    L2(4, 2, 0, 0, 0, 0, 0, 0xA64F),
    L2(4, 2, 0, 0, 0, 0, 0, 0xA650),
    L2(20, 2, 0, 0, 0, 0, 0, 0xA651),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA651),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_6_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_6_000[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0xA652),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_6_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_6_001[48] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xA653),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA654),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA655),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA656),
    L2(32, 0, 0, 0, 0, 0, 0, 0xA657),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA658),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA659),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA65A),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA65B),
    L2(32, 0, 0, 0, 0, 0, 0, 0xA65C),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA65C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_6_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_6_002[68] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xA65D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA65E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xA65F),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA660),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA661),
    L2(5, 0, 0, 0, 0, 0, 0, 0xA662),
    L2(5, 1, 0, 0, 0, 0, 0, 0xA663),
    L2(5, 1, 0, 0, 0, 0, 0, 0xA664),
    L2(5, 1, 0, 0, 0, 0, 0, 0xA665),
    L2(5, 1, 0, 0, 0, 0, 0, 0xA666),
    L2(5, 1, 0, 0, 0, 0, 0, 0xA667),
    L2(5, 1, 0, 0, 0, 0, 0, 0xA668),
    L2(5, 1, 0, 0, 0, 0, 0, 0xA669),
    L2(5, 1, 0, 0, 0, 0, 0, 0xA66A),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA66A),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_7_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_7_000[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2245),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2246),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2247),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2248),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2249),
    L2(4, 0, 0, 0, 0, 0, 0, 0x224A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x224B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x224C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x224D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x224E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x224F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x224F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_7_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_7_001[28] = {
    L2(56, 0, 0, 0, 0, 0, 0, 0x2250),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2251),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2252),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2251),
    L2(16, 0, 0, 0, 0, 0, 0, 0x2252),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2252),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effg0_char_table_7_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effg0_char_table_7_002[48] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x2253),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2254),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2255),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2256),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2257),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2258),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2259),
    L2(5, 1, 0, 0, 0, 0, 0, 0x225A),
    L2(5, 1, 0, 0, 0, 0, 0, 0x225B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x225B),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ag_face_panel_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ag_face_panel_table_000[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEA8),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEA9),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEAA),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEAB),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEAC),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEAD),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEAE),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEAF),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB0),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB2),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0xAEB8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x91BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x91BE),
    CMD(CM_ROA, 0, 0, 0),
};

/* effD4_char_table: 2 entries */
const u32 effD4_char_table[3] = {
    (u32)effD4_char_table_000, (u32)effD4_char_table_001, 0,
};

const u16 effD4_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effD4_char_table_000[12] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA826),
    L2(3, 255, 0, 0, 0, 0, 0, 0xA827),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effD4_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effD4_char_table_001[48] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xA828),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA829),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA82A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA82B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA82C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA82D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA82E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA82F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA830),
    L2(2, 0, 0, 0, 0, 0, 0, 0xA831),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA831),
    CMD(CM_ROA, 0, 0, 0),
};

/* provisional name */
/* 1 entry; nothing in the program refers to it */
const u32 effect_unref_char_table[2] = {
    (u32)effect_unref_char_table_000, 0,
};

const u16 effect_unref_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effect_unref_char_table_000[20] = {
    CMD(CM_EXEC, 1, 65, 0),
    CMD(CM_PAXY, 0, 8192, 0),
    CMD(CM_EXEC, 1, 66, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};
