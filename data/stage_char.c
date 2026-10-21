/*
 * STAGE_CHAR.C  Stage background character scripts
 *
 * Scripts for the characters in the stage backgrounds: the stgNN_char_table of each stage (provisional
 * names), brz_char_table, stage_char_06356D60, and the tables of the stage effects 07, 08, 09, 19, 21, 22,
 * 28, 29, 45, 54, 86 and 90.
 * Each *_char_table is an index of animation scripts ending in 0; set_char_move_init starts script
 * char_table[kind][index], whose HEAD sits just before the address the index holds. See charscr.h for
 * the line layouts.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

extern const u32 stg00_char_table[];
extern const u16 stg00_char_table_000_head[];
extern const u16 stg00_char_table_000[];
extern const u16 stg00_char_table_001_head[];
extern const u16 stg00_char_table_001[];
extern const u16 stg00_char_table_002_head[];
extern const u16 stg00_char_table_002[];
extern const u16 stg00_char_table_003_head[];
extern const u16 stg00_char_table_003[];
extern const u16 stg00_char_table_004_head[];
extern const u16 stg00_char_table_004[];
extern const u16 stg00_char_table_005_head[];
extern const u16 stg00_char_table_005[];
extern const u16 stg00_char_table_006_head[];
extern const u16 stg00_char_table_006[];
extern const u16 stg00_char_table_007_head[];
extern const u16 stg00_char_table_007[];
extern const u16 stg00_char_table_008_head[];
extern const u16 stg00_char_table_008[];
extern const u16 stg00_char_table_009_head[];
extern const u16 stg00_char_table_009[];
extern const u16 stg00_char_table_010_head[];
extern const u16 stg00_char_table_010[];
extern const u16 stg00_char_table_011_head[];
extern const u16 stg00_char_table_011[];
extern const u16 stg00_char_table_012_head[];
extern const u16 stg00_char_table_012[];
extern const u32 stg01_char_table[];
extern const u16 stg01_char_table_000_head[];
extern const u16 stg01_char_table_000[];
extern const u16 stg01_char_table_001_head[];
extern const u16 stg01_char_table_001[];
extern const u16 stg01_char_table_002_head[];
extern const u16 stg01_char_table_002[];
extern const u16 stg01_char_table_003_head[];
extern const u16 stg01_char_table_003[];
extern const u32 stg14_char_table[];
extern const u16 stg14_char_table_000_head[];
extern const u16 stg14_char_table_000[];
extern const u32 stg12_char_table[];
extern const u16 stg12_char_table_000_head[];
extern const u16 stg12_char_table_000[];
extern const u16 stg12_char_table_001_head[];
extern const u16 stg12_char_table_001[];
extern const u16 stg12_char_table_002_head[];
extern const u16 stg12_char_table_002[];
extern const u16 stg12_char_table_003_head[];
extern const u16 stg12_char_table_003[];
extern const u16 stg12_char_table_004_head[];
extern const u16 stg12_char_table_004[];
extern const u16 stg12_char_table_005_head[];
extern const u16 stg12_char_table_005[];
extern const u16 stg12_char_table_006_head[];
extern const u16 stg12_char_table_006[];
extern const u16 stg12_char_table_007_head[];
extern const u16 stg12_char_table_007[];
extern const u16 stg12_char_table_008_head[];
extern const u16 stg12_char_table_008[];
extern const u16 stg12_char_table_009_head[];
extern const u16 stg12_char_table_009[];
extern const u32 eff19_char_table[];
extern const u16 eff19_char_table_000_head[];
extern const u16 eff19_char_table_000[];
extern const u16 eff19_char_table_001_head[];
extern const u16 eff19_char_table_001[];
extern const u16 eff19_char_table_002_head[];
extern const u16 eff19_char_table_002[];
extern const u16 eff19_char_table_003_head[];
extern const u16 eff19_char_table_003[];
extern const u16 eff19_char_table_004_head[];
extern const u16 eff19_char_table_004[];
extern const u16 eff19_char_table_005_head[];
extern const u16 eff19_char_table_005[];
extern const u32 stg02_char_table[];
extern const u16 stg02_char_table_000_head[];
extern const u16 stg02_char_table_000[];
extern const u16 stg02_char_table_001_head[];
extern const u16 stg02_char_table_001[];
extern const u16 stg02_char_table_002_head[];
extern const u16 stg02_char_table_002[];
extern const u16 stg02_char_table_003_head[];
extern const u16 stg02_char_table_003[];
extern const u16 stg02_char_table_004_head[];
extern const u16 stg02_char_table_004[];
extern const u16 stg02_char_table_005_head[];
extern const u16 stg02_char_table_005[];
extern const u16 stg02_char_table_006_head[];
extern const u16 stg02_char_table_006[];
extern const u16 stg02_char_table_007_head[];
extern const u16 stg02_char_table_007[];
extern const u16 stg02_char_table_008_head[];
extern const u16 stg02_char_table_008[];
extern const u16 stg02_char_table_009_head[];
extern const u16 stg02_char_table_009[];
extern const u16 stg02_char_table_010_head[];
extern const u16 stg02_char_table_010[];
extern const u16 stg02_char_table_011_head[];
extern const u16 stg02_char_table_011[];
extern const u16 stg02_char_table_012_head[];
extern const u16 stg02_char_table_012[];
extern const u16 stg02_char_table_013_head[];
extern const u16 stg02_char_table_013[];
extern const u16 stg02_char_table_014_head[];
extern const u16 stg02_char_table_014[];
extern const u16 stg02_char_table_015_head[];
extern const u16 stg02_char_table_015[];
extern const u16 stg02_char_table_016_head[];
extern const u16 stg02_char_table_016[];
extern const u16 stg02_char_table_017_head[];
extern const u16 stg02_char_table_017[];
extern const u16 stg02_char_table_018_head[];
extern const u16 stg02_char_table_018[];
extern const u16 stg02_char_table_020_head[];
extern const u16 stg02_char_table_020[];
extern const u16 stg02_char_table_022_head[];
extern const u16 stg02_char_table_022[];
extern const u16 stg02_char_table_023_head[];
extern const u16 stg02_char_table_023[];
extern const u32 stg03_char_table[];
extern const u32 eff21_char_table[];
extern const u16 eff22_char_table[];
extern const u16 stg03_char_table_000_head[];
extern const u16 stg03_char_table_000[];
extern const u16 stg03_char_table_001_head[];
extern const u16 stg03_char_table_001[];
extern const u16 stg03_char_table_002_head[];
extern const u16 stg03_char_table_002[];
extern const u16 stg03_char_table_003_head[];
extern const u16 stg03_char_table_003[];
extern const u16 stg03_char_table_004_head[];
extern const u16 stg03_char_table_004[];
extern const u16 stg03_char_table_005_head[];
extern const u16 stg03_char_table_005[];
extern const u16 stg03_char_table_006_head[];
extern const u16 stg03_char_table_006[];
extern const u16 stg03_char_table_007_head[];
extern const u16 stg03_char_table_007[];
extern const u16 stg03_char_table_008_head[];
extern const u16 stg03_char_table_008[];
extern const u16 stg03_char_table_009_head[];
extern const u16 stg03_char_table_009[];
extern const u16 stg03_char_table_010_head[];
extern const u16 stg03_char_table_010[];
extern const u16 stg03_char_table_011_head[];
extern const u16 stg03_char_table_011[];
extern const u16 stg03_char_table_012_head[];
extern const u16 stg03_char_table_012[];
extern const u16 stg03_char_table_013_head[];
extern const u16 stg03_char_table_013[];
extern const u16 stg03_char_table_014_head[];
extern const u16 stg03_char_table_014[];
extern const u16 stg03_char_table_016_head[];
extern const u16 stg03_char_table_016[];
extern const u16 stg03_char_table_017_head[];
extern const u16 stg03_char_table_017[];
extern const u16 stg03_char_table_018_head[];
extern const u16 stg03_char_table_018[];
extern const u16 stg03_char_table_019_head[];
extern const u16 stg03_char_table_019[];
extern const u16 stg03_char_table_020_head[];
extern const u16 stg03_char_table_020[];
extern const u16 stg03_char_table_021_head[];
extern const u16 stg03_char_table_021[];
extern const u16 stg03_char_table_022_head[];
extern const u16 stg03_char_table_022[];
extern const u16 stg03_char_table_023_head[];
extern const u16 stg03_char_table_023[];
extern const u16 stg03_char_table_024_head[];
extern const u16 stg03_char_table_024[];
extern const u16 stg03_char_table_026_head[];
extern const u16 stg03_char_table_026[];
extern const u16 stg03_char_table_027_head[];
extern const u16 stg03_char_table_027[];
extern const u16 stg03_char_table_028_head[];
extern const u16 stg03_char_table_028[];
extern const u16 stg03_char_table_029_head[];
extern const u16 stg03_char_table_029[];
extern const u16 stg03_char_table_030_head[];
extern const u16 stg03_char_table_030[];
extern const u16 stg03_char_table_031_head[];
extern const u16 stg03_char_table_031[];
extern const u16 stg03_char_table_015_head[];
extern const u16 stg03_char_table_015[];
extern const u16 stg03_char_table_033_head[];
extern const u16 stg03_char_table_033[];
extern const u16 stg03_char_table_034_head[];
extern const u16 stg03_char_table_034[];
extern const u16 stg03_char_table_035_head[];
extern const u16 stg03_char_table_035[];
extern const u16 eff21_char_table_000_head[];
extern const u16 eff21_char_table_000[];
extern const u16 eff21_char_table_001_head[];
extern const u16 eff21_char_table_001[];
extern const u16 eff21_char_table_002_head[];
extern const u16 eff21_char_table_002[];
extern const u16 eff21_char_table_003_head[];
extern const u16 eff21_char_table_003[];
extern const u16 eff21_char_table_004_head[];
extern const u16 eff21_char_table_004[];
extern const u16 eff21_char_table_005_head[];
extern const u16 eff21_char_table_005[];
extern const u32 stg10_char_table[];
extern const u32 eff28_char_table[];
extern const u32 eff29_type0_char_table[];
extern const u16 eff29_type1_char_table[];
extern const u16 stg10_char_table_000_head[];
extern const u16 stg10_char_table_000[];
extern const u16 stg10_char_table_001_head[];
extern const u16 stg10_char_table_001[];
extern const u16 stg10_char_table_002_head[];
extern const u16 stg10_char_table_002[];
extern const u16 stg10_char_table_003_head[];
extern const u16 stg10_char_table_003[];
extern const u16 stg10_char_table_004_head[];
extern const u16 stg10_char_table_004[];
extern const u16 stg10_char_table_005_head[];
extern const u16 stg10_char_table_005[];
extern const u16 stg10_char_table_006_head[];
extern const u16 stg10_char_table_006[];
extern const u16 stg10_char_table_007_head[];
extern const u16 stg10_char_table_007[];
extern const u16 stg10_char_table_008_head[];
extern const u16 stg10_char_table_008[];
extern const u16 stg10_char_table_009_head[];
extern const u16 stg10_char_table_009[];
extern const u16 stg10_char_table_010_head[];
extern const u16 stg10_char_table_010[];
extern const u16 stg10_char_table_011_head[];
extern const u16 stg10_char_table_011[];
extern const u16 stg10_char_table_012_head[];
extern const u16 stg10_char_table_012[];
extern const u16 stg10_char_table_013_head[];
extern const u16 stg10_char_table_013[];
extern const u16 stg10_char_table_014_head[];
extern const u16 stg10_char_table_014[];
extern const u16 stg10_char_table_015_head[];
extern const u16 stg10_char_table_015[];
extern const u16 stg10_char_table_016_head[];
extern const u16 stg10_char_table_016[];
extern const u16 stg10_char_table_017_head[];
extern const u16 stg10_char_table_017[];
extern const u16 stg10_char_table_018_head[];
extern const u16 stg10_char_table_018[];
extern const u16 stg10_char_table_019_head[];
extern const u16 stg10_char_table_019[];
extern const u16 stg10_char_table_020_head[];
extern const u16 stg10_char_table_020[];
extern const u16 stg10_char_table_021_head[];
extern const u16 stg10_char_table_021[];
extern const u16 stg10_char_table_022_head[];
extern const u16 stg10_char_table_022[];
extern const u16 stg10_char_table_023_head[];
extern const u16 stg10_char_table_023[];
extern const u16 stg10_char_table_024_head[];
extern const u16 stg10_char_table_024[];
extern const u16 stg10_char_table_025_head[];
extern const u16 stg10_char_table_025[];
extern const u16 stg10_char_table_026_head[];
extern const u16 stg10_char_table_026[];
extern const u16 stg10_char_table_027_head[];
extern const u16 stg10_char_table_027[];
extern const u16 stg10_char_table_028_head[];
extern const u16 stg10_char_table_028[];
extern const u16 stg10_char_table_029_head[];
extern const u16 stg10_char_table_029[];
extern const u16 stg10_char_table_030_head[];
extern const u16 stg10_char_table_030[];
extern const u16 stg10_char_table_031_head[];
extern const u16 stg10_char_table_031[];
extern const u16 stg10_char_table_032_head[];
extern const u16 stg10_char_table_032[];
extern const u16 stg10_char_table_033_head[];
extern const u16 stg10_char_table_033[];
extern const u16 stg10_char_table_034_head[];
extern const u16 stg10_char_table_034[];
extern const u16 stg10_char_table_035_head[];
extern const u16 stg10_char_table_035[];
extern const u16 stg10_char_table_036_head[];
extern const u16 stg10_char_table_036[];
extern const u16 stg10_char_table_037_head[];
extern const u16 stg10_char_table_037[];
extern const u16 stg10_char_table_038_head[];
extern const u16 stg10_char_table_038[];
extern const u16 stg10_char_table_039_head[];
extern const u16 stg10_char_table_039[];
extern const u16 stg10_char_table_040_head[];
extern const u16 stg10_char_table_040[];
extern const u16 stg10_char_table_041_head[];
extern const u16 stg10_char_table_041[];
extern const u16 stg10_char_table_042_head[];
extern const u16 stg10_char_table_042[];
extern const u16 stg10_char_table_043_head[];
extern const u16 stg10_char_table_043[];
extern const u16 stg10_char_table_044_head[];
extern const u16 stg10_char_table_044[];
extern const u16 stg10_char_table_045_head[];
extern const u16 stg10_char_table_045[];
extern const u16 stg10_char_table_046_head[];
extern const u16 stg10_char_table_046[];
extern const u16 stg10_char_table_047_head[];
extern const u16 stg10_char_table_047[];
extern const u16 stg10_char_table_048_head[];
extern const u16 stg10_char_table_048[];
extern const u16 stg10_char_table_049_head[];
extern const u16 stg10_char_table_049[];
extern const u16 stg10_char_table_050_head[];
extern const u16 stg10_char_table_050[];
extern const u16 stg10_char_table_051_head[];
extern const u16 stg10_char_table_051[];
extern const u16 stg10_char_table_052_head[];
extern const u16 stg10_char_table_052[];
extern const u16 stg10_char_table_053_head[];
extern const u16 stg10_char_table_053[];
extern const u16 stg10_char_table_054_head[];
extern const u16 stg10_char_table_054[];
extern const u16 stg10_char_table_055_head[];
extern const u16 stg10_char_table_055[];
extern const u16 stg10_char_table_056_head[];
extern const u16 stg10_char_table_056[];
extern const u16 stg10_char_table_057_head[];
extern const u16 stg10_char_table_057[];
extern const u16 stg10_char_table_058_head[];
extern const u16 stg10_char_table_058[];
extern const u16 stg10_char_table_059_head[];
extern const u16 stg10_char_table_059[];
extern const u16 stg10_char_table_060_head[];
extern const u16 stg10_char_table_060[];
extern const u16 stg10_char_table_061_head[];
extern const u16 stg10_char_table_061[];
extern const u16 stg10_char_table_062_head[];
extern const u16 stg10_char_table_062[];
extern const u16 stg10_char_table_063_head[];
extern const u16 stg10_char_table_063[];
extern const u16 stg10_char_table_064_head[];
extern const u16 stg10_char_table_064[];
extern const u16 stg10_char_table_065_head[];
extern const u16 stg10_char_table_065[];
extern const u16 stg10_char_table_066_head[];
extern const u16 stg10_char_table_066[];
extern const u16 stg10_char_table_067_head[];
extern const u16 stg10_char_table_067[];
extern const u16 stg10_char_table_068_head[];
extern const u16 stg10_char_table_068[];
extern const u16 stg10_char_table_069_head[];
extern const u16 stg10_char_table_069[];
extern const u16 stg10_char_table_070_head[];
extern const u16 stg10_char_table_070[];
extern const u16 stg10_char_table_071_head[];
extern const u16 stg10_char_table_071[];
extern const u16 stg10_char_table_072_head[];
extern const u16 stg10_char_table_072[];
extern const u16 stg10_char_table_073_head[];
extern const u16 stg10_char_table_073[];
extern const u16 stg10_char_table_074_head[];
extern const u16 stg10_char_table_074[];
extern const u16 stg10_char_table_075_head[];
extern const u16 stg10_char_table_075[];
extern const u16 eff28_char_table_000_head[];
extern const u16 eff28_char_table_000[];
extern const u16 eff28_char_table_001_head[];
extern const u16 eff28_char_table_001[];
extern const u16 eff28_char_table_002_head[];
extern const u16 eff28_char_table_002[];
extern const u16 eff28_char_table_003_head[];
extern const u16 eff28_char_table_003[];
extern const u16 eff28_char_table_004_head[];
extern const u16 eff28_char_table_004[];
extern const u16 eff28_char_table_005_head[];
extern const u16 eff28_char_table_005[];
extern const u16 eff29_type0_char_table_000_head[];
extern const u16 eff29_type0_char_table_000[];
extern const u16 eff29_type0_char_table_001_head[];
extern const u16 eff29_type0_char_table_001[];
extern const u16 eff29_type0_char_table_002_head[];
extern const u16 eff29_type0_char_table_002[];
extern const u16 eff29_type0_char_table_003_head[];
extern const u16 eff29_type0_char_table_003[];
extern const u32 stg04_char_table[];
extern const u16 stg04_char_table_000_head[];
extern const u16 stg04_char_table_000[];
extern const u16 stg04_char_table_001_head[];
extern const u16 stg04_char_table_001[];
extern const u16 stg04_char_table_002_head[];
extern const u16 stg04_char_table_002[];
extern const u16 stg04_char_table_003_head[];
extern const u16 stg04_char_table_003[];
extern const u16 stg04_char_table_004_head[];
extern const u16 stg04_char_table_004[];
extern const u16 stg04_char_table_005_head[];
extern const u16 stg04_char_table_005[];
extern const u16 stg04_char_table_007_head[];
extern const u16 stg04_char_table_007[];
extern const u16 stg04_char_table_006_head[];
extern const u16 stg04_char_table_006[];
extern const u16 stg04_char_table_008_head[];
extern const u16 stg04_char_table_008[];
extern const u16 stg04_char_table_009_head[];
extern const u16 stg04_char_table_009[];
extern const u16 stg04_char_table_010_head[];
extern const u16 stg04_char_table_010[];
extern const u32 stg05_char_table[];
extern const u32 eff08_char_table[];
extern const u16 eff07_char_table[];
extern const u16 stg05_char_table_000_head[];
extern const u16 stg05_char_table_000[];
extern const u16 stg05_char_table_001_head[];
extern const u16 stg05_char_table_001[];
extern const u16 stg05_char_table_002_head[];
extern const u16 stg05_char_table_002[];
extern const u16 stg05_char_table_003_head[];
extern const u16 stg05_char_table_003[];
extern const u16 stg05_char_table_004_head[];
extern const u16 stg05_char_table_004[];
extern const u16 stg05_char_table_005_head[];
extern const u16 stg05_char_table_005[];
extern const u16 stg05_char_table_006_head[];
extern const u16 stg05_char_table_006[];
extern const u16 stg05_char_table_007_head[];
extern const u16 stg05_char_table_007[];
extern const u16 stg05_char_table_008_head[];
extern const u16 stg05_char_table_008[];
extern const u16 stg05_char_table_009_head[];
extern const u16 stg05_char_table_009[];
extern const u16 stg05_char_table_010_head[];
extern const u16 stg05_char_table_010[];
extern const u16 stg05_char_table_011_head[];
extern const u16 stg05_char_table_011[];
extern const u16 stg05_char_table_012_head[];
extern const u16 stg05_char_table_012[];
extern const u16 stg05_char_table_013_head[];
extern const u16 stg05_char_table_013[];
extern const u16 stg05_char_table_014_head[];
extern const u16 stg05_char_table_014[];
extern const u16 stg05_char_table_015_head[];
extern const u16 stg05_char_table_015[];
extern const u16 stg05_char_table_016_head[];
extern const u16 stg05_char_table_016[];
extern const u16 stg05_char_table_017_head[];
extern const u16 stg05_char_table_017[];
extern const u16 eff08_char_table_000_head[];
extern const u16 eff08_char_table_000[];
extern const u16 eff08_char_table_001_head[];
extern const u16 eff08_char_table_001[];
extern const u16 eff08_char_table_002_head[];
extern const u16 eff08_char_table_002[];
extern const u16 eff08_char_table_003_head[];
extern const u16 eff08_char_table_003[];
extern const u16 eff08_char_table_004_head[];
extern const u16 eff08_char_table_004[];
extern const u16 eff08_char_table_005_head[];
extern const u16 eff08_char_table_005[];
extern const u16 eff08_char_table_006_head[];
extern const u16 eff08_char_table_006[];
extern const u16 eff08_char_table_007_head[];
extern const u16 eff08_char_table_007[];
extern const u16 eff08_char_table_008_head[];
extern const u16 eff08_char_table_008[];
extern const u16 eff08_char_table_009_head[];
extern const u16 eff08_char_table_009[];
extern const u16 eff08_char_table_010_head[];
extern const u16 eff08_char_table_010[];
extern const u16 eff08_char_table_011_head[];
extern const u16 eff08_char_table_011[];
extern const u16 eff08_char_table_012_head[];
extern const u16 eff08_char_table_012[];
extern const u16 eff08_char_table_013_head[];
extern const u16 eff08_char_table_013[];
extern const u16 eff08_char_table_014_head[];
extern const u16 eff08_char_table_014[];
extern const u16 eff08_char_table_015_head[];
extern const u16 eff08_char_table_015[];
extern const u32 stg06_char_table[];
extern const u16 stg06_char_table_000_head[];
extern const u16 stg06_char_table_000[];
extern const u16 stg06_char_table_001_head[];
extern const u16 stg06_char_table_001[];
extern const u16 stg06_char_table_002_head[];
extern const u16 stg06_char_table_002[];
extern const u16 stg06_char_table_003_head[];
extern const u16 stg06_char_table_003[];
extern const u16 stg06_char_table_004_head[];
extern const u16 stg06_char_table_004[];
extern const u16 stg06_char_table_005_head[];
extern const u16 stg06_char_table_005[];
extern const u16 stg06_char_table_006_head[];
extern const u16 stg06_char_table_006[];
extern const u16 stg06_char_table_007_head[];
extern const u16 stg06_char_table_007[];
extern const u16 stg06_char_table_008_head[];
extern const u16 stg06_char_table_008[];
extern const u16 stg06_char_table_009_head[];
extern const u16 stg06_char_table_009[];
extern const u16 stg06_char_table_010_head[];
extern const u16 stg06_char_table_010[];
extern const u16 stg06_char_table_011_head[];
extern const u16 stg06_char_table_011[];
extern const u16 stg06_char_table_012_head[];
extern const u16 stg06_char_table_012[];
extern const u16 stg06_char_table_013_head[];
extern const u16 stg06_char_table_013[];
extern const u16 stg06_char_table_014_head[];
extern const u16 stg06_char_table_014[];
extern const u16 stg06_char_table_015_head[];
extern const u16 stg06_char_table_015[];
extern const u16 stg06_char_table_016_head[];
extern const u16 stg06_char_table_016[];
extern const u16 stg06_char_table_017_head[];
extern const u16 stg06_char_table_017[];
extern const u16 stg06_char_table_018_head[];
extern const u16 stg06_char_table_018[];
extern const u16 stg06_char_table_019_head[];
extern const u16 stg06_char_table_019[];
extern const u16 stg06_char_table_020_head[];
extern const u16 stg06_char_table_020[];
extern const u16 stg06_char_table_021_head[];
extern const u16 stg06_char_table_021[];
extern const u16 stg06_char_table_022_head[];
extern const u16 stg06_char_table_022[];
extern const u16 stg06_char_table_023_head[];
extern const u16 stg06_char_table_023[];
extern const u16 stg06_char_table_024_head[];
extern const u16 stg06_char_table_024[];
extern const u16 stg06_char_table_025_head[];
extern const u16 stg06_char_table_025[];
extern const u16 stg06_char_table_026_head[];
extern const u16 stg06_char_table_026[];
extern const u16 stg06_char_table_027_head[];
extern const u16 stg06_char_table_027[];
extern const u16 stg06_char_table_028_head[];
extern const u16 stg06_char_table_028[];
extern const u16 stg06_char_table_029_head[];
extern const u16 stg06_char_table_029[];
extern const u16 stg06_char_table_030_head[];
extern const u16 stg06_char_table_030[];
extern const u16 stg06_char_table_031_head[];
extern const u16 stg06_char_table_031[];
extern const u16 stg06_char_table_032_head[];
extern const u16 stg06_char_table_032[];
extern const u16 stg06_char_table_033_head[];
extern const u16 stg06_char_table_033[];
extern const u16 stg06_char_table_034_head[];
extern const u16 stg06_char_table_034[];
extern const u16 stg06_char_table_035_head[];
extern const u16 stg06_char_table_035[];
extern const u16 stg06_char_table_036_head[];
extern const u16 stg06_char_table_036[];
extern const u32 stg07_char_table[];
extern const u16 stg07_char_table_000_head[];
extern const u16 stg07_char_table_000[];
extern const u32 eff45_char_table[];
extern const u16 eff54_char_table[];
extern const u16 eff45_char_table_000_head[];
extern const u16 eff45_char_table_000[];
extern const u16 eff45_char_table_001_head[];
extern const u16 eff45_char_table_001[];
extern const u16 eff45_char_table_002_head[];
extern const u16 eff45_char_table_002[];
extern const u16 eff45_char_table_003_head[];
extern const u16 eff45_char_table_003[];
extern const u16 eff45_char_table_004_head[];
extern const u16 eff45_char_table_004[];
extern const u16 eff45_char_table_005_head[];
extern const u16 eff45_char_table_005[];
extern const u16 eff45_char_table_006_head[];
extern const u16 eff45_char_table_006[];
extern const u16 eff45_char_table_007_head[];
extern const u16 eff45_char_table_007[];
extern const u16 eff45_char_table_008_head[];
extern const u16 eff45_char_table_008[];
extern const u16 eff45_char_table_009_head[];
extern const u16 eff45_char_table_009[];
extern const u16 eff45_char_table_010_head[];
extern const u16 eff45_char_table_010[];
extern const u16 eff45_char_table_011_head[];
extern const u16 eff45_char_table_011[];
extern const u16 eff45_char_table_012_head[];
extern const u16 eff45_char_table_012[];
extern const u16 eff45_char_table_013_head[];
extern const u16 eff45_char_table_013[];
extern const u16 eff45_char_table_014_head[];
extern const u16 eff45_char_table_014[];
extern const u16 eff45_char_table_015_head[];
extern const u16 eff45_char_table_015[];
extern const u16 eff45_char_table_016_head[];
extern const u16 eff45_char_table_016[];
extern const u16 eff45_char_table_017_head[];
extern const u16 eff45_char_table_017[];
extern const u16 eff45_char_table_018_head[];
extern const u16 eff45_char_table_018[];
extern const u16 eff45_char_table_019_head[];
extern const u16 eff45_char_table_019[];
extern const u16 eff45_char_table_020_head[];
extern const u16 eff45_char_table_020[];
extern const u16 eff45_char_table_021_head[];
extern const u16 eff45_char_table_021[];
extern const u16 eff45_char_table_022_head[];
extern const u16 eff45_char_table_022[];
extern const u16 eff45_char_table_023_head[];
extern const u16 eff45_char_table_023[];
extern const u16 eff45_char_table_024_head[];
extern const u16 eff45_char_table_024[];
extern const u16 eff45_char_table_025_head[];
extern const u16 eff45_char_table_025[];
extern const u16 eff45_char_table_026_head[];
extern const u16 eff45_char_table_026[];
extern const u32 eff86_char_table[];
extern const u16 eff86_char_table_000_head[];
extern const u16 eff86_char_table_000[];
extern const u16 eff86_char_table_001_head[];
extern const u16 eff86_char_table_001[];
extern const u16 eff86_char_table_002_head[];
extern const u16 eff86_char_table_002[];
extern const u16 eff86_char_table_003_head[];
extern const u16 eff86_char_table_003[];
extern const u16 eff86_char_table_018_head[];
extern const u16 eff86_char_table_018[];
extern const u16 eff86_char_table_004_head[];
extern const u16 eff86_char_table_004[];
extern const u16 eff86_char_table_005_head[];
extern const u16 eff86_char_table_005[];
extern const u16 eff86_char_table_006_head[];
extern const u16 eff86_char_table_006[];
extern const u16 eff86_char_table_007_head[];
extern const u16 eff86_char_table_007[];
extern const u16 eff86_char_table_008_head[];
extern const u16 eff86_char_table_008[];
extern const u16 eff86_char_table_009_head[];
extern const u16 eff86_char_table_009[];
extern const u16 eff86_char_table_010_head[];
extern const u16 eff86_char_table_010[];
extern const u16 eff86_char_table_011_head[];
extern const u16 eff86_char_table_011[];
extern const u16 eff86_char_table_012_head[];
extern const u16 eff86_char_table_012[];
extern const u16 eff86_char_table_013_head[];
extern const u16 eff86_char_table_013[];
extern const u16 eff86_char_table_014_head[];
extern const u16 eff86_char_table_014[];
extern const u16 eff86_char_table_015_head[];
extern const u16 eff86_char_table_015[];
extern const u16 eff86_char_table_016_head[];
extern const u16 eff86_char_table_016[];
extern const u16 eff86_char_table_017_head[];
extern const u16 eff86_char_table_017[];
extern const u16 eff86_char_table_019_head[];
extern const u16 eff86_char_table_019[];
extern const u16 eff86_char_table_020_head[];
extern const u16 eff86_char_table_020[];
extern const u32 eff09_char_table[];
extern const u16 eff09_char_table_000_head[];
extern const u16 eff09_char_table_000[];
extern const u16 eff09_char_table_001_head[];
extern const u16 eff09_char_table_001[];
extern const u16 eff09_char_table_002_head[];
extern const u16 eff09_char_table_002[];
extern const u16 eff09_char_table_003_head[];
extern const u16 eff09_char_table_003[];
extern const u16 eff09_char_table_004_head[];
extern const u16 eff09_char_table_004[];
extern const u16 eff09_char_table_005_head[];
extern const u16 eff09_char_table_005[];
extern const u16 eff09_char_table_006_head[];
extern const u16 eff09_char_table_006[];
extern const u32 brz_char_table[];
extern const u32 eff90_char_table[];
extern const u16 brz_char_table_000_head[];
extern const u16 brz_char_table_000[];
extern const u16 brz_char_table_001_head[];
extern const u16 brz_char_table_001[];
extern const u16 brz_char_table_002_head[];
extern const u16 brz_char_table_002[];
extern const u16 brz_char_table_003_head[];
extern const u16 brz_char_table_003[];
extern const u16 brz_char_table_004_head[];
extern const u16 brz_char_table_004[];
extern const u16 brz_char_table_005_head[];
extern const u16 brz_char_table_005[];
extern const u16 brz_char_table_006_head[];
extern const u16 brz_char_table_006[];
extern const u16 brz_char_table_007_head[];
extern const u16 brz_char_table_007[];
extern const u16 brz_char_table_008_head[];
extern const u16 brz_char_table_008[];
extern const u16 brz_char_table_009_head[];
extern const u16 brz_char_table_009[];
extern const u16 brz_char_table_010_head[];
extern const u16 brz_char_table_010[];
extern const u16 brz_char_table_011_head[];
extern const u16 brz_char_table_011[];
extern const u16 brz_char_table_012_head[];
extern const u16 brz_char_table_012[];
extern const u16 brz_char_table_013_head[];
extern const u16 brz_char_table_013[];
extern const u16 brz_char_table_014_head[];
extern const u16 brz_char_table_014[];
extern const u16 brz_char_table_015_head[];
extern const u16 brz_char_table_015[];
extern const u16 brz_char_table_016_head[];
extern const u16 brz_char_table_016[];
extern const u16 brz_char_table_017_head[];
extern const u16 brz_char_table_017[];
extern const u16 brz_char_table_018_head[];
extern const u16 brz_char_table_018[];
extern const u16 brz_char_table_019_head[];
extern const u16 brz_char_table_019[];
extern const u16 brz_char_table_020_head[];
extern const u16 brz_char_table_020[];
extern const u16 brz_char_table_021_head[];
extern const u16 brz_char_table_021[];
extern const u16 brz_char_table_022_head[];
extern const u16 brz_char_table_022[];
extern const u16 brz_char_table_023_head[];
extern const u16 brz_char_table_023[];
extern const u16 brz_char_table_025_head[];
extern const u16 brz_char_table_025[];
extern const u16 brz_char_table_024_head[];
extern const u16 brz_char_table_024[];
extern const u16 brz_char_table_026_head[];
extern const u16 brz_char_table_026[];
extern const u16 brz_char_table_027_head[];
extern const u16 brz_char_table_027[];
extern const u16 brz_char_table_028_head[];
extern const u16 brz_char_table_028[];
extern const u16 brz_char_table_029_head[];
extern const u16 brz_char_table_029[];
extern const u16 brz_char_table_030_head[];
extern const u16 brz_char_table_030[];
extern const u16 brz_char_table_031_head[];
extern const u16 brz_char_table_031[];
extern const u16 brz_char_table_032_head[];
extern const u16 brz_char_table_032[];
extern const u16 brz_char_table_033_head[];
extern const u16 brz_char_table_033[];
extern const u16 brz_char_table_034_head[];
extern const u16 brz_char_table_034[];
extern const u16 brz_char_table_035_head[];
extern const u16 brz_char_table_035[];
extern const u16 brz_char_table_036_head[];
extern const u16 brz_char_table_036[];
extern const u16 brz_char_table_037_head[];
extern const u16 brz_char_table_037[];
extern const u16 brz_char_table_038_head[];
extern const u16 brz_char_table_038[];
extern const u16 brz_char_table_039_head[];
extern const u16 brz_char_table_039[];
extern const u16 brz_char_table_040_head[];
extern const u16 brz_char_table_040[];
extern const u16 brz_char_table_041_head[];
extern const u16 brz_char_table_041[];
extern const u16 brz_char_table_042_head[];
extern const u16 brz_char_table_042[];
extern const u16 brz_char_table_043_head[];
extern const u16 brz_char_table_043[];
extern const u16 brz_char_table_044_head[];
extern const u16 brz_char_table_044[];
extern const u16 brz_char_table_045_head[];
extern const u16 brz_char_table_045[];
extern const u16 brz_char_table_046_head[];
extern const u16 brz_char_table_046[];
extern const u16 brz_char_table_047_head[];
extern const u16 brz_char_table_047[];
extern const u16 brz_char_table_048_head[];
extern const u16 brz_char_table_048[];
extern const u16 brz_char_table_049_head[];
extern const u16 brz_char_table_049[];
extern const u16 brz_char_table_050_head[];
extern const u16 brz_char_table_050[];
extern const u16 brz_char_table_051_head[];
extern const u16 brz_char_table_051[];
extern const u16 eff90_char_table_000_head[];
extern const u16 eff90_char_table_000[];
extern const u32 stage_char_06356D60[];
extern const u16 stage_char_06356D60_000_head[];
extern const u16 stage_char_06356D60_000[];
extern const u16 stage_char_06356D60_001_head[];
extern const u16 stage_char_06356D60_001[];
extern const u16 stage_char_06356D60_002_head[];
extern const u16 stage_char_06356D60_002[];
extern const u16 stage_char_06356D60_003_head[];
extern const u16 stage_char_06356D60_003[];
extern const u16 stage_char_06356D60_004_head[];
extern const u16 stage_char_06356D60_004[];
extern const u16 stage_char_06356D60_005_head[];
extern const u16 stage_char_06356D60_005[];

/* stg00_char_table: 13 entries */
const u32 stg00_char_table[14] = {
    (u32)stg00_char_table_000, (u32)stg00_char_table_001, (u32)stg00_char_table_002, (u32)stg00_char_table_003, (u32)stg00_char_table_004, (u32)stg00_char_table_005,
    (u32)stg00_char_table_006, (u32)stg00_char_table_007, (u32)stg00_char_table_008, (u32)stg00_char_table_009, (u32)stg00_char_table_010, (u32)stg00_char_table_011,
    (u32)stg00_char_table_012, 0,
};

const u16 stg00_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_000[12] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9B90),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9B91),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg00_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_001[12] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9B93),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9B94),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg00_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_002[12] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9B96),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9B97),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg00_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_003[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BA0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BA1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BA4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BA3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BA2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BA1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg00_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_004[36] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x9BB0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9BB1),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9BB2),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9BB3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BB4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BB5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BB6),
    CMD(CM_IXBW, 0, 0, 3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg00_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_005[84] = {
    L2(20, 0, 0, 0, 0, 0, 0, 0x9BC0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC1),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC6),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC6),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC7),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC8),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BC8),
    CMD(CM_IXBW, 0, 0, 4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg00_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_006[40] = {
    L2(16, 0, 0, 0, 0, 0, 0, 0x9BD0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BD1),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BD2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BD3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BD4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BD5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BD6),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BD7),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BD1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg00_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_007[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BF0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg00_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_008[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BF1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg00_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_009[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9BF2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg00_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_010[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0150),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg00_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_011[60] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BA0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BA5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BA6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BA7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BA8),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BA9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BAA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BAB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BAA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BA9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BA8),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BA7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BA6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BA5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg00_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg00_char_table_012[28] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BB7),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BB0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BB8),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BB9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9BBA),
    L2(6, 9, 0, 0, 0, 0, 0, 0x9BBB),
    CMD(CM_ROA, 0, 0, 0),
};

/* stg01_char_table: 4 entries */
const u32 stg01_char_table[5] = {
    (u32)stg01_char_table_000, (u32)stg01_char_table_001, (u32)stg01_char_table_002, (u32)stg01_char_table_003, 0,
};

const u16 stg01_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg01_char_table_000[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x8E20),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg01_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg01_char_table_001[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8E21),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg01_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg01_char_table_002[16] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8E22),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8E23),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8E24),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg01_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg01_char_table_003[20] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x8E22),
    L2(1, 0, 0, 0, 0, 0, 0, 0x8E23),
    L2(1, 0, 0, 0, 0, 0, 0, 0x8E24),
    L2(2, 255, 0, 0, 0, 0, 0, 0x8E24),
    CMD(CM_ROA, 0, 0, 0),
};

/* stg14_char_table: 1 entry */
const u32 stg14_char_table[2] = {
    (u32)stg14_char_table_000, 0,
};

const u16 stg14_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg14_char_table_000[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x9530),
    CMD(CM_ROA, 0, 0, 0),
};

/* stg12_char_table: 10 entries */
const u32 stg12_char_table[11] = {
    (u32)stg12_char_table_000, (u32)stg12_char_table_001, (u32)stg12_char_table_002, (u32)stg12_char_table_003, (u32)stg12_char_table_004, (u32)stg12_char_table_005,
    (u32)stg12_char_table_006, (u32)stg12_char_table_007, (u32)stg12_char_table_008, (u32)stg12_char_table_009, 0,
};

const u16 stg12_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg12_char_table_000[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x9060),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg12_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg12_char_table_001[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x9061),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg12_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg12_char_table_002[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x9062),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg12_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg12_char_table_003[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x9063),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg12_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg12_char_table_004[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x9064),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg12_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg12_char_table_005[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x9065),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg12_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg12_char_table_006[124] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x9066),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9067),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9068),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9069),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9066),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9068),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9069),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9070),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9071),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9066),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9067),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9068),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9071),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9066),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9068),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x906D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg12_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg12_char_table_007[68] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x9072),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9073),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9074),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9075),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9072),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9073),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9074),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9075),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9072),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9073),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9074),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9075),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9072),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9073),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9074),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9075),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg12_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg12_char_table_008[684] = {
    CMD(CM_FOR, 0, 0, 2),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9079),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9078),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9079),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(9, 1, 0, 0, 0, 0, 0, 0x9077),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9089),
    L2(10, 0, 0, 0, 0, 0, 0, 0x908A),
    L2(10, 0, 0, 0, 0, 0, 0, 0x908B),
    L2(6, 1, 0, 0, 0, 0, 0, 0x9089),
    CMD(CM_FOR, 0, 0, 6),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9079),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 1, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9078),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9079),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x908C),
    L2(10, 0, 0, 0, 0, 0, 0, 0x908D),
    L2(10, 0, 0, 0, 0, 0, 0, 0x908E),
    L2(6, 1, 0, 0, 0, 0, 0, 0x908D),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9079),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 1, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9078),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9079),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 0, 0, 0, 0, 0, 0, 0x908F),
    L2(15, 0, 0, 0, 0, 0, 0, 0x9090),
    L2(8, 1, 0, 0, 0, 0, 0, 0x908F),
    CMD(CM_FOR, 0, 0, 4),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9079),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 1, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9078),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9079),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x908C),
    L2(10, 0, 0, 0, 0, 0, 0, 0x908D),
    L2(10, 0, 0, 0, 0, 0, 0, 0x908E),
    L2(6, 1, 0, 0, 0, 0, 0, 0x908D),
    CMD(CM_FOR, 0, 0, 4),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9079),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(8, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9078),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9079),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x908F),
    L2(15, 0, 0, 0, 0, 0, 0, 0x9090),
    L2(8, 1, 0, 0, 0, 0, 0, 0x908F),
    CMD(CM_FOR, 0, 0, 6),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9079),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(8, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9078),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9079),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9076),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9077),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9089),
    L2(10, 0, 0, 0, 0, 0, 0, 0x908A),
    L2(10, 0, 0, 0, 0, 0, 0, 0x908B),
    L2(6, 1, 0, 0, 0, 0, 0, 0x9089),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg12_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg12_char_table_009[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9077),
    L2(5, 0, 0, 0, 0, 0, 0, 0x907B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9081),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9082),
    L2(36, 0, 0, 0, 0, 0, 0, 0x9083),
    L2(9, 0, 0, 0, 0, 0, 0, 0x9082),
    L2(10, 0, 0, 0, 0, 0, 0, 0x907C),
    L2(10, 0, 0, 0, 0, 0, 0, 0x9086),
    L2(2, 1, 0, 0, 0, 0, 0, 0x9086),
    CMD(CM_ROA, 0, 0, 0),
};

/* eff19_char_table: 6 entries */
const u32 eff19_char_table[7] = {
    (u32)eff19_char_table_000, (u32)eff19_char_table_001, (u32)eff19_char_table_002, (u32)eff19_char_table_003, (u32)eff19_char_table_004, (u32)eff19_char_table_005,
    0,
};

const u16 eff19_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff19_char_table_000[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x79C0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff19_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff19_char_table_001[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x79C1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff19_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff19_char_table_002[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x79C2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff19_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff19_char_table_003[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x79C3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff19_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff19_char_table_004[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x79C4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff19_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff19_char_table_005[580] = {
    CMD(CM_FOR, 0, 0, 8),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(12, 0, 0, 0, 0, 0, 0, 0x4B2B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    CMD(CM_FOR, 0, 0, 16),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    CMD(CM_FOR, 0, 0, 10),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    CMD(CM_FOR, 0, 0, 4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(12, 0, 0, 0, 0, 0, 0, 0x4B2B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    CMD(CM_FOR, 0, 0, 14),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    CMD(CM_FOR, 0, 0, 6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(12, 0, 0, 0, 0, 0, 0, 0x4B2B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x4B23),
    CMD(CM_ROA, 0, 0, 0),
};

/* stg02_char_table: 24 entries */
const u32 stg02_char_table[25] = {
    (u32)stg02_char_table_000, (u32)stg02_char_table_001, (u32)stg02_char_table_002, (u32)stg02_char_table_003, (u32)stg02_char_table_004, (u32)stg02_char_table_005,
    (u32)stg02_char_table_006, (u32)stg02_char_table_007, (u32)stg02_char_table_008, (u32)stg02_char_table_009, (u32)stg02_char_table_010, (u32)stg02_char_table_011,
    (u32)stg02_char_table_012, (u32)stg02_char_table_013, (u32)stg02_char_table_014, (u32)stg02_char_table_015, (u32)stg02_char_table_016, (u32)stg02_char_table_017,
    (u32)stg02_char_table_018, (u32)stg02_char_table_018, (u32)stg02_char_table_020, (u32)stg02_char_table_020, (u32)stg02_char_table_022, (u32)stg02_char_table_023,
    0,
};

const u16 stg02_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_000[8] = {
    L2(44, 0, 0, 0, 0, 0, 0, 0x7BE9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_001[28] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0x7BA9),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7BAA),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7BAB),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7BAC),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7BAD),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7BAE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_002[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BC5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BC6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BC7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BC8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BC9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BCA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BCB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BCC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BCD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_003[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BCE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BCF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BD0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BD1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BD2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BD3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BD4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BD5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BD6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_004[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BE0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BE1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BE2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BE3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BE4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BE5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BE6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BE7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BE8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_005[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BD7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BD8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BD9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BDA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BDB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BDC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BDD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BDE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7BDF),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_006[8] = {
    L2(44, 0, 0, 0, 0, 0, 0, 0x7BEA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_007[8] = {
    L2(44, 0, 0, 0, 0, 0, 0, 0x7BEB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_008[64] = {
    L2(53, 0, 0, 0, 0, 0, 0, 0x7C55),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7C56),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7C57),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7C58),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7C57),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7C56),
    L2(49, 0, 0, 0, 0, 0, 0, 0x7C57),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7C56),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7C57),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7C58),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7C57),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7C56),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7C5B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C5A),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7C5A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_009[56] = {
    L2(49, 0, 0, 0, 0, 0, 0, 0x7C59),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C5A),
    L2(28, 0, 0, 0, 0, 0, 0, 0x7C5B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C5A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C58),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C57),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C56),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C57),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C58),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C57),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C56),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C5D),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7C5D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_010[204] = {
    L2(72, 0, 0, 0, 0, 0, 0, 0x7C31),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C32),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C33),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C34),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C35),
    L2(38, 0, 0, 0, 0, 0, 0, 0x7C36),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C35),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7C36),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C35),
    L2(15, 0, 0, 0, 0, 0, 0, 0x7C37),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C35),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C36),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7C37),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7C36),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C35),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C36),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C35),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7C37),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C36),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C37),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C35),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7C34),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C33),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C32),
    L2(71, 0, 0, 0, 0, 0, 0, 0x7C31),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C38),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C39),
    L2(20, 0, 0, 0, 0, 0, 0, 0x7C3A),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C39),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C38),
    L2(23, 0, 0, 0, 0, 0, 0, 0x7C31),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3B),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3C),
    CMD(CM_FOR, 0, 0, 2),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3D),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3E),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3F),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3E),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3D),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3E),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3F),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3E),
    CMD(CM_NEX, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3D),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3E),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3F),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3E),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3D),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3C),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C3B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_011[56] = {
    L2(7, 0, 0, 0, 0, 0, 0, 0x7CCC),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7CCD),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7CCE),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7CCF),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7CD0),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7CCF),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7CD0),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7CCF),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7CD0),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7CCF),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7CD0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7CCF),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7CD0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_012[52] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x7CD1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7CD2),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7CD3),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7CD4),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7CD5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7CD6),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7CD7),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7CD8),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7CD9),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7CDA),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7CDB),
    L2(5, 1, 0, 0, 0, 0, 0, 0x7CDB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_013[48] = {
    L2(200, 0, 0, 0, 0, 0, 0, 0x7C45),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C46),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C47),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C48),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C49),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C4A),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C4B),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C4C),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C4D),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C4E),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C4F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_014[48] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x7C50),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7C51),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7C52),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C53),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7C51),
    L2(16, 0, 0, 0, 0, 0, 0, 0x7C52),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7C53),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7C51),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7C52),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7C53),
    L2(13, 0, 0, 0, 0, 0, 0, 0x7C51),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_015[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C54),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_016[48] = {
    L2(36, 0, 0, 0, 0, 0, 0, 0x7C5E),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C5F),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C60),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C61),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7C62),
    L2(21, 0, 0, 0, 0, 0, 0, 0x7C63),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C64),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7C65),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C61),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C60),
    L2(200, 0, 0, 0, 0, 0, 0, 0x7C5F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_017[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C66),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_018[104] = {
    CMD(CM_FOR, 0, 0, 3),
    L2(35, 0, 0, 0, 0, 0, 0, 0x7C67),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C68),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7C69),
    L2(13, 0, 0, 0, 0, 0, 0, 0x7C6A),
    L2(25, 0, 0, 0, 0, 0, 0, 0x7C6B),
    L2(20, 0, 0, 0, 0, 0, 0, 0x7C6A),
    L2(18, 0, 0, 0, 0, 0, 0, 0x7C69),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7C68),
    CMD(CM_NEX, 0, 0, 0),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7C6C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C6D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C6E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C6F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C6E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C6D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7C6E),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7C6F),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7C6E),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7C6D),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7C6E),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7C6F),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7C6E),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7C6D),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7C6C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_020[92] = {
    CMD(CM_FOR, 0, 0, 2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C70),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C71),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C72),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C73),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C74),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C73),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C72),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C71),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C70),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C71),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C72),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C73),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C74),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C75),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C72),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C71),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C70),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C76),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7C77),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7C76),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_022[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C78),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg02_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg02_char_table_023[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0x7C7A),
    CMD(CM_ROA, 0, 0, 0),
};

/* stg03_char_table: 36 entries, and no 0: the index after it follows on */
const u32 stg03_char_table[36] = {
    (u32)stg03_char_table_000, (u32)stg03_char_table_001, (u32)stg03_char_table_002, (u32)stg03_char_table_003, (u32)stg03_char_table_004, (u32)stg03_char_table_005,
    (u32)stg03_char_table_006, (u32)stg03_char_table_007, (u32)stg03_char_table_008, (u32)stg03_char_table_009, (u32)stg03_char_table_010, (u32)stg03_char_table_011,
    (u32)stg03_char_table_012, (u32)stg03_char_table_013, (u32)stg03_char_table_014, (u32)stg03_char_table_015, (u32)stg03_char_table_016, (u32)stg03_char_table_017,
    (u32)stg03_char_table_018, (u32)stg03_char_table_019, (u32)stg03_char_table_020, (u32)stg03_char_table_021, (u32)stg03_char_table_022, (u32)stg03_char_table_023,
    (u32)stg03_char_table_024, (u32)stg03_char_table_024, (u32)stg03_char_table_026, (u32)stg03_char_table_027, (u32)stg03_char_table_028, (u32)stg03_char_table_029,
    (u32)stg03_char_table_030, (u32)stg03_char_table_031, (u32)stg03_char_table_015, (u32)stg03_char_table_033, (u32)stg03_char_table_034, (u32)stg03_char_table_035,
};

/* eff21_char_table: 6 entries, and no 0: the index after it follows on */
const u32 eff21_char_table[6] = {
    (u32)eff21_char_table_000, (u32)eff21_char_table_001, (u32)eff21_char_table_002, (u32)eff21_char_table_003, (u32)eff21_char_table_004, (u32)eff21_char_table_005,
};

const u16 eff22_char_table[8] = {
    0x634, 0xF9CC, 0x634, 0xF9FC, 0x634, 0xFC24, 0, 0,
};

const u16 stg03_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_000[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x7D40),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_001[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D42),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_002[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E1F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_003[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E1E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_004[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D46),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_005[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D47),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_006[20] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D48),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D49),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D4A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D4B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_007[8] = {
    L2(26, 0, 0, 0, 0, 0, 0, 0x7D75),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_008[48] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D4C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D4D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D4E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D4F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D50),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D51),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D52),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D53),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D54),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D55),
    L2(4, 1, 0, 0, 0, 0, 0, 0x7D55),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_009[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D57),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D58),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D59),
    L2(4, 1, 0, 0, 0, 0, 0, 0x7D5A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_010[60] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D5D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D5E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D5F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D60),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D61),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D62),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D63),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D64),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D65),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D66),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D67),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D68),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7D69),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7D69),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_011[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D6A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D6B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D6C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D6D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D6E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D6F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7D70),
    L2(4, 1, 0, 0, 0, 0, 0, 0x7D70),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_012[128] = {
    L2(8, 0, 113, 0, 0, 0, 0, 0x7E11),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E12),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E13),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E14),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E15),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E16),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E17),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E18),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E19),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E1A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E1B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E1C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E1D),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E1D),
    CMD(CM_ROA, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D76),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D77),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D78),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D79),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D7A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D7B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D7C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D7D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D7E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D7F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D80),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D81),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D82),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D83),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7D84),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7D84),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_013[56] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E11),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E12),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E13),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E14),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E15),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E16),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E17),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E18),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E19),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E1A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E1B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E1C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E1D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_014[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0x7E10),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_016[60] = {
    L2(84, 0, 0, 0, 0, 0, 0, 0x7E8C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E8D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E8E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E8F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E90),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E8F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E8E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E8D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E8E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E8F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E90),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E8F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E8E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E8D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_017[36] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E91),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E92),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E93),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E92),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E91),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E92),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E93),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E92),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_018[64] = {
    L2(200, 0, 0, 0, 0, 0, 0, 0x7E94),
    L2(129, 0, 0, 0, 0, 0, 0, 0x7E94),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E95),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E96),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E97),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E98),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E99),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E9A),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E9B),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E9A),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E99),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E98),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E97),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E96),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7E95),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_019[40] = {
    L2(155, 0, 0, 0, 0, 0, 0, 0x7E9E),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7E9D),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7E9C),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7E9D),
    L2(155, 1, 0, 0, 0, 0, 0, 0x7E9E),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7E9F),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7EA0),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7E9F),
    L2(11, 1, 0, 0, 0, 0, 0, 0x7E9F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_020[32] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x7E9E),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7EA1),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7EA2),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7EA3),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7EA4),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7EA5),
    L2(11, 1, 0, 0, 0, 0, 0, 0x7EA5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_021[8] = {
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EA6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_022[112] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EA7),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EA8),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EA9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAD),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAF),
    CMD(CM_FOR, 0, 0, 2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EB0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAF),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAD),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAF),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAF),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAD),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EAA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EA9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EA8),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EA7),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EA7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_023[28] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0x7EB1),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7EB2),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7EB3),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7EB4),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7EB5),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7EB6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_024[36] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x7EB7),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7EB8),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7EB9),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7EBA),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7EBB),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7EBC),
    L2(9, 0, 0, 0, 0, 0, 0, 0x7EBD),
    CMD(CM_END, 0, 0, 4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_026[28] = {
    L2(32, 0, 0, 0, 0, 0, 0, 0x7EBF),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7EC0),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7EC1),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7EC2),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7EC3),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7EC4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_027[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x7ED6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_028[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x7ED7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_029[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x7ED8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_030[136] = {
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EC5),
    L2(4, 1, 0, 0, 0, 0, 0, 0x7EC6),
    L2(4, 1, 0, 0, 0, 0, 0, 0x7EC7),
    L2(4, 1, 0, 0, 0, 0, 0, 0x7EC8),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EC9),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EC8),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EC7),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EC6),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EC5),
    L2(4, 1, 0, 0, 0, 0, 0, 0x7EC6),
    L2(4, 1, 0, 0, 0, 0, 0, 0x7EC7),
    L2(3, 1, 0, 0, 0, 0, 0, 0x7EC8),
    L2(1, 1, 0, 0, 0, 0, 0, 0x7EC8),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EC9),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EC8),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EC7),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EC6),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EC5),
    L2(4, 1, 0, 0, 0, 0, 0, 0x7EC6),
    L2(4, 1, 0, 0, 0, 0, 0, 0x7ECA),
    L2(4, 1, 0, 0, 0, 0, 0, 0x7ECB),
    CMD(CM_FOR, 0, 0, 2),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7ECC),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7ECF),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7ECD),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7ECE),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7ECD),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7ECF),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7ECC),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7ECB),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7ECA),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7EC6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_031[56] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7ECA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7ED0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7ED1),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7ED2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7ED3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7ED4),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7ED5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7ED4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7ED3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7ED2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7ED1),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7ECA),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7ECA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_015[148] = {
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E70),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E71),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E72),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E73),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E74),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E75),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E76),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E77),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E78),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E79),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E7A),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E7B),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E7C),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E7D),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E7E),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E7F),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E80),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E81),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E82),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E83),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E84),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E85),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E86),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E87),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E70),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E71),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E72),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E73),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E74),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E75),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E76),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E77),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E78),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E79),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E7A),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7E7B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_033[56] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E85),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E86),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E87),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E88),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E89),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E8A),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7E8B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x7E8A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E89),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E88),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E87),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7E70),
    L2(6, 1, 0, 0, 0, 0, 0, 0x7E70),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_034[8] = {
    L2(4, 1, 0, 0, 0, 0, 0, 0x7D69),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg03_char_table_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg03_char_table_035[8] = {
    L2(4, 1, 0, 0, 0, 0, 0, 0x7D8F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff21_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff21_char_table_000[56] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x7EDD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7EDE),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7EDF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7EE0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7EDE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7EE0),
    L2(11, 0, 0, 0, 0, 0, 0, 0x7EDE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7EE1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7EE2),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7EE3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7EE4),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7EE5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7EE4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff21_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff21_char_table_001[12] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x7EDA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7EDB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff21_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff21_char_table_002[52] = {
    L2(32, 0, 0, 0, 0, 0, 0, 0x7EEC),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EED),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EEE),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EED),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EEE),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EEC),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EEB),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EEA),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EEF),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EF0),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7EEF),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7EE9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff21_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff21_char_table_003[16] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x7EE6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7EE7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7EE8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff21_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff21_char_table_004[64] = {
    L2(32, 0, 0, 0, 0, 0, 0, 0x7EF1),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EF4),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EF3),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EF4),
    CMD(CM_FOR, 0, 0, 3),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EF2),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EF3),
    L2(14, 0, 0, 0, 0, 0, 0, 0x7EF4),
    CMD(CM_NEX, 0, 0, 0),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7EF2),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7EF2),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7EF4),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7EF2),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7EF1),
    L2(12, 0, 0, 0, 0, 0, 0, 0x7EF5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff21_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff21_char_table_005[356] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x7F0B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7F0C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7F0D),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(80, 0, 0, 0, 0, 0, 0, 0x7EF7),
    L2(48, 0, 0, 0, 0, 0, 0, 0x7EF6),
    L2(15, 0, 0, 0, 0, 0, 0, 0x7EF7),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7EF6),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(2, 8, 0, 0, 0, 0, 0, 0x7F07),
    L2(2, 8, 0, 0, 0, 0, 0, 0x7F08),
    L2(2, 7, 0, 0, 0, 0, 0, 0x7F07),
    L2(2, 7, 0, 0, 0, 0, 0, 0x7F08),
    L2(2, 6, 0, 0, 0, 0, 0, 0x7F07),
    L2(2, 6, 0, 0, 0, 0, 0, 0x7F08),
    L2(2, 5, 0, 0, 0, 0, 0, 0x7F07),
    L2(2, 5, 0, 0, 0, 0, 0, 0x7F08),
    L2(2, 4, 0, 0, 0, 0, 0, 0x7F09),
    L2(2, 4, 0, 0, 0, 0, 0, 0x7F0A),
    L2(2, 3, 0, 0, 0, 0, 0, 0x7F09),
    L2(2, 3, 0, 0, 0, 0, 0, 0x7F0A),
    L2(2, 2, 0, 0, 0, 0, 0, 0x7F09),
    L2(2, 2, 0, 0, 0, 0, 0, 0x7F0A),
    L2(2, 1, 0, 0, 0, 0, 0, 0x7F09),
    L2(2, 1, 0, 0, 0, 0, 0, 0x7F0A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7EDB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7EDC),
    L2(2, 31, 0, 0, 0, 0, 0, 0x7EDB),
    L2(2, 31, 0, 0, 0, 0, 0, 0x7EDC),
    L2(2, 30, 0, 0, 0, 0, 0, 0x7EDB),
    L2(2, 30, 0, 0, 0, 0, 0, 0x7EDC),
    L2(2, 29, 0, 0, 0, 0, 0, 0x7EDB),
    L2(2, 29, 0, 0, 0, 0, 0, 0x7EDC),
    L2(2, 28, 0, 0, 0, 0, 0, 0x7ED9),
    L2(2, 28, 0, 0, 0, 0, 0, 0x7EDA),
    L2(2, 27, 0, 0, 0, 0, 0, 0x7ED9),
    L2(2, 27, 0, 0, 0, 0, 0, 0x7EDA),
    L2(2, 26, 0, 0, 0, 0, 0, 0x7ED9),
    L2(2, 26, 0, 0, 0, 0, 0, 0x7EDA),
    L2(2, 25, 0, 0, 0, 0, 0, 0x7ED9),
    L2(2, 25, 0, 0, 0, 0, 0, 0x7EDA),
    L2(2, 24, 0, 0, 0, 0, 0, 0x7ED9),
    L2(2, 24, 0, 0, 0, 0, 0, 0x7EDA),
    L2(2, 23, 0, 0, 0, 0, 0, 0x7ED9),
    L2(2, 23, 0, 0, 0, 0, 0, 0x7EDA),
    L2(2, 22, 0, 0, 0, 0, 0, 0x7ED9),
    L2(2, 22, 0, 0, 0, 0, 0, 0x7EDA),
    L2(2, 21, 0, 0, 0, 0, 0, 0x7ED9),
    L2(2, 21, 0, 0, 0, 0, 0, 0x7EDA),
    L2(2, 20, 0, 0, 1, 0, 0, 0x7EDB),
    L2(2, 20, 0, 0, 1, 0, 0, 0x7EDC),
    L2(2, 19, 0, 0, 1, 0, 0, 0x7EDB),
    L2(2, 19, 0, 0, 1, 0, 0, 0x7EDC),
    L2(2, 18, 0, 0, 1, 0, 0, 0x7EDB),
    L2(2, 18, 0, 0, 1, 0, 0, 0x7EDC),
    L2(2, 17, 0, 0, 1, 0, 0, 0x7EDB),
    L2(2, 17, 0, 0, 1, 0, 0, 0x7EDC),
    L2(2, 16, 0, 0, 1, 0, 0, 0x7F09),
    L2(2, 16, 0, 0, 1, 0, 0, 0x7F0A),
    L2(2, 15, 0, 0, 1, 0, 0, 0x7F09),
    L2(2, 15, 0, 0, 1, 0, 0, 0x7F0A),
    L2(2, 14, 0, 0, 1, 0, 0, 0x7F09),
    L2(2, 14, 0, 0, 1, 0, 0, 0x7F0A),
    L2(2, 13, 0, 0, 1, 0, 0, 0x7F09),
    L2(2, 13, 0, 0, 1, 0, 0, 0x7F0A),
    L2(2, 12, 0, 0, 0, 0, 0, 0x7F07),
    L2(2, 12, 0, 0, 0, 0, 0, 0x7F08),
    L2(2, 11, 0, 0, 0, 0, 0, 0x7F07),
    L2(2, 11, 0, 0, 0, 0, 0, 0x7F08),
    L2(2, 10, 0, 0, 0, 0, 0, 0x7F07),
    L2(2, 10, 0, 0, 0, 0, 0, 0x7F08),
    L2(2, 9, 0, 0, 0, 0, 0, 0x7F07),
    L2(2, 9, 0, 0, 0, 0, 0, 0x7F08),
    L2(2, 8, 0, 0, 0, 0, 0, 0x7F07),
    L2(2, 8, 0, 0, 0, 0, 0, 0x7F08),
    L2(2, 99, 0, 0, 0, 0, 0, 0x7F08),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(80, 0, 0, 0, 0, 0, 0, 0x7EF9),
    L2(48, 0, 0, 0, 0, 0, 0, 0x7EF8),
    L2(15, 0, 0, 0, 0, 0, 0, 0x7EF9),
    L2(10, 0, 0, 0, 0, 0, 0, 0x7EF8),
    L2(40, 0, 0, 0, 0, 0, 0, 0x7EF9),
    L2(24, 0, 0, 0, 0, 0, 0, 0x7EF8),
    L2(7, 0, 0, 0, 0, 0, 0, 0x7EF9),
    L2(5, 0, 0, 0, 0, 0, 0, 0x7EF8),
    CMD(CM_ROA, 0, 0, 0),
};

/* stg10_char_table: 76 entries, and no 0: the index after it follows on */
const u32 stg10_char_table[76] = {
    (u32)stg10_char_table_000, (u32)stg10_char_table_001, (u32)stg10_char_table_002, (u32)stg10_char_table_003, (u32)stg10_char_table_004, (u32)stg10_char_table_005,
    (u32)stg10_char_table_006, (u32)stg10_char_table_007, (u32)stg10_char_table_008, (u32)stg10_char_table_009, (u32)stg10_char_table_010, (u32)stg10_char_table_011,
    (u32)stg10_char_table_012, (u32)stg10_char_table_013, (u32)stg10_char_table_014, (u32)stg10_char_table_015, (u32)stg10_char_table_016, (u32)stg10_char_table_017,
    (u32)stg10_char_table_018, (u32)stg10_char_table_019, (u32)stg10_char_table_020, (u32)stg10_char_table_021, (u32)stg10_char_table_022, (u32)stg10_char_table_023,
    (u32)stg10_char_table_024, (u32)stg10_char_table_025, (u32)stg10_char_table_026, (u32)stg10_char_table_027, (u32)stg10_char_table_028, (u32)stg10_char_table_029,
    (u32)stg10_char_table_030, (u32)stg10_char_table_031, (u32)stg10_char_table_032, (u32)stg10_char_table_033, (u32)stg10_char_table_034, (u32)stg10_char_table_035,
    (u32)stg10_char_table_036, (u32)stg10_char_table_037, (u32)stg10_char_table_038, (u32)stg10_char_table_039, (u32)stg10_char_table_040, (u32)stg10_char_table_041,
    (u32)stg10_char_table_042, (u32)stg10_char_table_043, (u32)stg10_char_table_044, (u32)stg10_char_table_045, (u32)stg10_char_table_046, (u32)stg10_char_table_047,
    (u32)stg10_char_table_048, (u32)stg10_char_table_049, (u32)stg10_char_table_050, (u32)stg10_char_table_051, (u32)stg10_char_table_052, (u32)stg10_char_table_053,
    (u32)stg10_char_table_054, (u32)stg10_char_table_055, (u32)stg10_char_table_056, (u32)stg10_char_table_057, (u32)stg10_char_table_058, (u32)stg10_char_table_059,
    (u32)stg10_char_table_060, (u32)stg10_char_table_061, (u32)stg10_char_table_062, (u32)stg10_char_table_063, (u32)stg10_char_table_064, (u32)stg10_char_table_065,
    (u32)stg10_char_table_066, (u32)stg10_char_table_067, (u32)stg10_char_table_068, (u32)stg10_char_table_069, (u32)stg10_char_table_070, (u32)stg10_char_table_071,
    (u32)stg10_char_table_072, (u32)stg10_char_table_073, (u32)stg10_char_table_074, (u32)stg10_char_table_075,
};

/* eff28_char_table: 6 entries, and no 0: the index after it follows on */
const u32 eff28_char_table[6] = {
    (u32)eff28_char_table_000, (u32)eff28_char_table_001, (u32)eff28_char_table_002, (u32)eff28_char_table_003, (u32)eff28_char_table_004, (u32)eff28_char_table_005,
};

/* eff29_type0_char_table: 4 entries, and no 0: the index after it follows on */
const u32 eff29_type0_char_table[4] = {
    (u32)eff29_type0_char_table_000, (u32)eff29_type0_char_table_001, (u32)eff29_type0_char_table_002, (u32)eff29_type0_char_table_003,
};

/* provisional name */
const u16 eff29_type1_char_table[16] = {
    0x635, 0x1734, 0x635, 0x1814, 0x635, 0x1874, 0x635, 0x18C4,
    0x635, 0x18EC, 0x635, 0x1954, 0x635, 0x197C, 0, 0,
};

const u16 stg10_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_000[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x7FC0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_001[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7FC2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_002[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7FC5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_003[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7FC6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_004[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7FC8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_005[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7FC9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_006[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7FCA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_007[8] = {
    L2(26, 0, 0, 0, 0, 0, 0, 0x7FCB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_008[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x7FCC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_009[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x7FCD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_010[12] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x7FD0),
    L2(8, 1, 0, 0, 0, 0, 0, 0x7FD0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_011[68] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FE1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FE2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FE3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FE4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FE5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FE6),
    L2(3, 2, 0, 0, 0, 0, 0, 0x7FE7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FE8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FE9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FEA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FEB),
    L2(3, 2, 0, 0, 0, 0, 0, 0x7FEC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FED),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FEE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7FEF),
    L2(3, 1, 0, 0, 0, 0, 0, 0x7FEF),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_012[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x7FF1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7FF2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7FF3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7FF4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7FF5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7FF6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7FF7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x7FF8),
    L2(4, 1, 0, 0, 0, 0, 0, 0x7FF8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_013[16] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x809C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x809D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x809E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_014[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8001),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8002),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8003),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8004),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8005),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8006),
    L2(2, 1, 0, 0, 0, 0, 0, 0x8006),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_015[52] = {
    CMD(CM_FOR, 0, 0, 2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8010),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8011),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8012),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8013),
    CMD(CM_NEX, 0, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8014),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8015),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8016),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8017),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8018),
    CMD(CM_END, 0, 0, 9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_016[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8020),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8021),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8022),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8023),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_017[60] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8031),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8032),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8033),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8034),
    L2(3, 2, 0, 0, 0, 0, 0, 0x8035),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8036),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8037),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8038),
    L2(3, 2, 0, 0, 0, 0, 0, 0x8039),
    L2(3, 0, 0, 0, 0, 0, 0, 0x803A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x803C),
    L2(5, 0, 0, 0, 0, 0, 0, 0x803B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x803A),
    L2(5, 1, 0, 0, 0, 0, 0, 0x803A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_018[20] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8107),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8108),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8109),
    L2(6, 0, 0, 0, 0, 0, 0, 0x810A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_019[20] = {
    L2(7, 0, 0, 0, 0, 0, 0, 0x8045),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8046),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8047),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8048),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_020[28] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8051),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8052),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8053),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8054),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8055),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8056),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_021[60] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8061),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8062),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8063),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8064),
    L2(4, 2, 0, 0, 0, 0, 0, 0x8065),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8066),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8067),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8068),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8069),
    L2(4, 2, 0, 0, 0, 0, 0, 0x806A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x806B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x806C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x806D),
    L2(4, 1, 0, 0, 0, 0, 0, 0x806D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_022[56] = {
    L2(4, 0, 112, 0, 0, 0, 0, 0x8071),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8072),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8073),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8074),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8075),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8076),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8077),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8078),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8079),
    L2(3, 0, 0, 0, 0, 0, 0, 0x807A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x807B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x807C),
    L2(4, 1, 0, 0, 0, 0, 0, 0x807C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_023[48] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8091),
    L2(2, 2, 0, 0, 0, 0, 0, 0x8091),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8092),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8093),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8094),
    L2(2, 2, 0, 0, 0, 0, 0, 0x8091),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8091),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8092),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8093),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8094),
    L2(2, 1, 0, 0, 0, 0, 0, 0x8094),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_024[16] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8099),
    L2(4, 0, 0, 0, 0, 0, 0, 0x809A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x809B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_025[20] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x80B0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80B1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80B2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80B3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_026[20] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x80B4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80B5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80B6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80B7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_027[20] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x80B8),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80B9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80BA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80BB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_028[16] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x80BC),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80BD),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80BE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_029[28] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x80CB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80CC),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80CD),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80CE),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80CF),
    L2(8, 1, 0, 0, 0, 0, 0, 0x80CF),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_030[24] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x80D0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x80D1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x80D2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x80D3),
    L2(8, 1, 0, 0, 0, 0, 0, 0x80D3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_031[20] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x80D4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80D5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80D6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80D7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_032[64] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x7FD0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80DE),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80DF),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E8),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80EA),
    L2(8, 1, 0, 0, 0, 0, 0, 0x80EA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_033[24] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x80ED),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80EE),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80EF),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80F0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80F1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_034[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8095),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8096),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8097),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8098),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_035[20] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_036[40] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x80E9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80EA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80EB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80EC),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80ED),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80EE),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80EF),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80F0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80F1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_037[40] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x80F2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80F3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80F4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80F5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80F6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80F7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80F8),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80F9),
    L2(8, 1, 0, 0, 0, 0, 0, 0x80F9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_038[16] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x80FA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80FB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x80FC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_039[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8160),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8161),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8162),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8163),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8164),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8165),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8166),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8167),
    L2(4, 1, 0, 0, 0, 0, 0, 0x8167),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_040[52] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8170),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8171),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8172),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8173),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8174),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8175),
    L2(2, 2, 0, 0, 0, 0, 0, 0x8176),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8177),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8178),
    L2(2, 2, 0, 0, 0, 0, 0, 0x8179),
    L2(2, 0, 0, 0, 0, 0, 0, 0x817A),
    L2(4, 1, 0, 0, 0, 0, 0, 0x817A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_041[56] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8180),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8181),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8182),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8183),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8184),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8185),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8186),
    L2(2, 2, 0, 0, 0, 0, 0, 0x8187),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8188),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8189),
    L2(2, 0, 0, 0, 0, 0, 0, 0x818A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x818B),
    L2(4, 1, 0, 0, 0, 0, 0, 0x818B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_042[56] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8190),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8191),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8192),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8193),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8194),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8195),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8196),
    L2(2, 2, 0, 0, 0, 0, 0, 0x8197),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8198),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8199),
    L2(2, 2, 0, 0, 0, 0, 0, 0x819A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x819B),
    L2(2, 1, 0, 0, 0, 0, 0, 0x819B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_043[56] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x81A0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81A1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81A2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81A3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81A4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81A5),
    L2(2, 2, 0, 0, 0, 0, 0, 0x81A6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81A7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81A8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81A9),
    L2(2, 2, 0, 0, 0, 0, 0, 0x81AA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81AB),
    L2(2, 1, 0, 0, 0, 0, 0, 0x81AB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_044[52] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x81B0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81B1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81B2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81B3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81B4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81B5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81B6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81B7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81B8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81B9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81BA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81BB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_045[52] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x81C0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81C1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81C2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81C3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81C4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81C5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81C6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81C7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81C8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81C9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81CA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x81CB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_046[60] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x81E0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x81E1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81E2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81E3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81E4),
    L2(1, 0, 0, 0, 0, 0, 0, 0x81E5),
    L2(1, 0, 0, 0, 0, 0, 0, 0x81E6),
    L2(2, 2, 0, 0, 0, 0, 0, 0x81E7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81E4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81E5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81E6),
    L2(2, 2, 0, 0, 0, 0, 0, 0x81E7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81E8),
    L2(2, 1, 0, 0, 0, 0, 0, 0x81E8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_047[60] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x81F0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81F1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81F2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81F3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81F4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81F5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81F6),
    L2(2, 2, 0, 0, 0, 0, 0, 0x81F7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81F6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81F5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81F4),
    L2(2, 2, 0, 0, 0, 0, 0, 0x81F3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x81F2),
    L2(2, 1, 0, 0, 0, 0, 0, 0x81F2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_048[56] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8200),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8201),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8202),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8203),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8204),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8205),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8206),
    L2(4, 2, 0, 0, 0, 0, 0, 0x8207),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8208),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8209),
    L2(4, 0, 0, 0, 0, 0, 0, 0x820A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x820B),
    L2(4, 1, 0, 0, 0, 0, 0, 0x820B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_049[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8210),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8211),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8212),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8213),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8214),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8215),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8216),
    L2(200, 0, 0, 0, 0, 0, 0, 0x8217),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_050[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8220),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8221),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8222),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8223),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8224),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8225),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8226),
    L2(200, 0, 0, 0, 0, 0, 0, 0x8227),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_051[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8230),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8231),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8232),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8233),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8234),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8235),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8236),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8237),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_052[40] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8240),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8242),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8243),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8245),
    L2(2, 2, 0, 0, 0, 0, 0, 0x8247),
    L2(2, 0, 0, 0, 0, 0, 0, 0x824A),
    L2(2, 2, 0, 0, 0, 0, 0, 0x824B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x824A),
    L2(2, 1, 0, 0, 0, 0, 0, 0x824A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_053[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8250),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8251),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8252),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8253),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8254),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8255),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8256),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8257),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_054[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8260),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8261),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8262),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8263),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8264),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8265),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8266),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8267),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_055[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8270),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8271),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8272),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8273),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8274),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8275),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8276),
    L2(200, 0, 0, 0, 0, 0, 0, 0x8277),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_056[64] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8280),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8281),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8282),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8283),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8284),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8285),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8286),
    L2(2, 2, 0, 0, 0, 0, 0, 0x8287),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8288),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8289),
    L2(2, 0, 0, 0, 0, 0, 0, 0x828A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x828B),
    L2(2, 2, 0, 0, 0, 0, 0, 0x828C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x828D),
    L2(2, 1, 0, 0, 0, 0, 0, 0x828D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_057[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8297),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8295),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8296),
    L2(2, 2, 0, 0, 0, 0, 0, 0x8297),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8298),
    L2(2, 1, 0, 0, 0, 0, 0, 0x8298),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_058[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x82A0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x82A1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x82A2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x82A3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x82A4),
    L2(2, 1, 0, 0, 0, 0, 0, 0x82A4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_059[40] = {
    L2(4, 0, 111, 0, 0, 0, 0, 0x82B0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82B1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82B2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82B3),
    L2(4, 2, 0, 0, 0, 0, 0, 0x82B4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82B5),
    L2(4, 2, 0, 0, 0, 0, 0, 0x82B6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82B7),
    L2(4, 1, 0, 0, 0, 0, 0, 0x82B7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_060[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x82BC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_061[20] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x82BE),
    L2(10, 0, 0, 0, 0, 0, 0, 0x82BF),
    L2(10, 0, 0, 0, 0, 0, 0, 0x82C0),
    L2(10, 0, 0, 0, 0, 0, 0, 0x82C1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_062[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8100),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_063[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8101),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_064[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8104),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_065[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8103),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_066[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8102),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_067[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x7FC7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_068[36] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x8300),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8301),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8302),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8303),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8304),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8305),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8306),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8307),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_069_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_069[16] = {
    L2(70, 0, 111, 0, 0, 0, 0, 0x8106),
    L2(4, 1, 0, 0, 0, 0, 0, 0x8106),
    CMD(CM_END, 0, 0, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_070_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_070[12] = {
    L2(50, 0, 0, 0, 0, 0, 0, 0x8105),
    L2(4, 1, 0, 0, 0, 0, 0, 0x8105),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_071_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_071[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x80A0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x80A1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x80A2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x80A3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_072_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_072[16] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8102),
    L2(200, 0, 0, 0, 0, 0, 0, 0x8102),
    CMD(CM_END, 0, 0, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_073_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_073[8] = {
    L2(200, 0, 0, 0, 0, 0, 0, 0x8104),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_074_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_074[8] = {
    L2(200, 0, 0, 0, 0, 0, 0, 0x807C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg10_char_table_075_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg10_char_table_075[8] = {
    L2(200, 0, 0, 0, 0, 0, 0, 0x80EA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff28_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff28_char_table_000[84] = {
    L2(128, 0, 0, 0, 0, 0, 0, 0x82D0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D6),
    L2(8, 1, 0, 0, 0, 0, 0, 0x82D6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff28_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff28_char_table_001[36] = {
    L2(32, 0, 0, 0, 0, 0, 0, 0x82D7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D8),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DA),
    L2(32, 0, 0, 0, 0, 0, 0, 0x82DB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff28_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff28_char_table_002[96] = {
    L2(32, 0, 0, 0, 0, 0, 0, 0x82D7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D8),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DA),
    CMD(CM_FOR, 0, 0, 2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DC),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DD),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DE),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DD),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DC),
    CMD(CM_NEX, 0, 0, 0),
    L2(32, 0, 0, 0, 0, 0, 0, 0x82DB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DC),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DD),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DE),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DD),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DC),
    L2(32, 0, 0, 0, 0, 0, 0, 0x82DB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82DA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D8),
    L2(8, 1, 0, 0, 0, 0, 0, 0x82D8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff28_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff28_char_table_003[44] = {
    CMD(CM_FOR, 0, 0, 3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D4),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D3),
    L2(8, 1, 0, 0, 0, 0, 0, 0x82D3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff28_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff28_char_table_004[180] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0x82D7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82D6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82D5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82DF),
    L2(68, 0, 0, 0, 0, 0, 0, 0x82E0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82E1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82E2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82E3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82E4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82E5),
    CMD(CM_FOR, 0, 0, 2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x82E6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x82E7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82E8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82E9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82E8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82E7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x82E6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x82E5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x82E4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x82E5),
    CMD(CM_NEX, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82E6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82E7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x82E8),
    L2(33, 0, 0, 0, 0, 0, 0, 0x82E9),
    L2(12, 0, 0, 0, 0, 0, 0, 0x82EA),
    L2(32, 0, 0, 0, 0, 0, 0, 0x82EB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x82EC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x82ED),
    L2(6, 0, 0, 0, 0, 0, 0, 0x82EE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x82EF),
    L2(6, 0, 0, 0, 0, 0, 0, 0x82F0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82F1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82F2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82F3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82F4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82F5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82F6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82F5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82F4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82F5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x82F6),
    L2(8, 1, 0, 0, 0, 0, 0, 0x82F5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff28_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff28_char_table_005[100] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F4),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F5),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F6),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F7),
    L2(32, 0, 0, 0, 0, 0, 0, 0x82F8),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F7),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F6),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F5),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F4),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F5),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F6),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F5),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F4),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F5),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F6),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F5),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F4),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F5),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F6),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F7),
    L2(42, 0, 0, 0, 0, 0, 0, 0x82F8),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F7),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F6),
    L2(9, 0, 0, 0, 0, 0, 0, 0x82F5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff29_type0_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff29_type0_char_table_000[52] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x835E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x835F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8360),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8361),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8362),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8363),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8364),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8365),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8366),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8367),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8368),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8368),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff29_type0_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff29_type0_char_table_001[44] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x831C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x831D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x831E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x831F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8320),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8321),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8322),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8323),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8324),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8324),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff29_type0_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff29_type0_char_table_002[56] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8311),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8312),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8313),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8314),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8315),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8316),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8311),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8317),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8318),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8319),
    L2(8, 0, 0, 0, 0, 0, 0, 0x831A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x831B),
    L2(8, 1, 0, 0, 0, 0, 0, 0x831B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff29_type0_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff29_type0_char_table_003[376] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x8355),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8356),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8357),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8358),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8359),
    L2(10, 0, 0, 0, 0, 0, 0, 0x835A),
    L2(10, 0, 0, 0, 0, 0, 0, 0x835B),
    L2(10, 0, 0, 0, 0, 0, 0, 0x835C),
    L2(10, 0, 0, 0, 0, 0, 0, 0x835D),
    L2(10, 1, 0, 0, 0, 0, 0, 0x835D),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x833A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x833B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x833C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x833D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x833E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x833F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8340),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8369),
    L2(8, 0, 0, 0, 0, 0, 0, 0x836A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x836B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x836C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x836D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x836E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x836F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x833A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x833B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x833C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x833D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x833E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x833F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8340),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8369),
    L2(8, 0, 0, 0, 0, 0, 0, 0x836A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x836B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x836C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x836D),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8341),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8342),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8343),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8344),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8345),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8346),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8347),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8348),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8349),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8349),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0x834A),
    L2(10, 0, 0, 0, 0, 0, 0, 0x834B),
    L2(10, 0, 0, 0, 0, 0, 0, 0x834C),
    L2(10, 0, 0, 0, 0, 0, 0, 0x834D),
    L2(10, 0, 0, 0, 0, 0, 0, 0x834E),
    L2(10, 0, 0, 0, 0, 0, 0, 0x834F),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8350),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8351),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8352),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8353),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8353),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8325),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8326),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8327),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8328),
    L2(10, 0, 0, 0, 0, 0, 0, 0x832A),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8325),
    L2(10, 0, 0, 0, 0, 0, 0, 0x832B),
    L2(10, 0, 0, 0, 0, 0, 0, 0x832C),
    L2(10, 0, 0, 0, 0, 0, 0, 0x832D),
    L2(10, 0, 0, 0, 0, 0, 0, 0x832E),
    L2(10, 1, 0, 0, 0, 0, 0, 0x832F),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8330),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8331),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8331),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8332),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8333),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8334),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8335),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8336),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8337),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8338),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8339),
    CMD(CM_ROA, 0, 0, 0),
};

/* stg04_char_table: 11 entries */
const u32 stg04_char_table[12] = {
    (u32)stg04_char_table_000, (u32)stg04_char_table_001, (u32)stg04_char_table_002, (u32)stg04_char_table_003, (u32)stg04_char_table_004, (u32)stg04_char_table_005,
    (u32)stg04_char_table_006, (u32)stg04_char_table_007, (u32)stg04_char_table_008, (u32)stg04_char_table_009, (u32)stg04_char_table_010, 0,
};

const u16 stg04_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg04_char_table_000[32] = {
    L2(200, 0, 0, 0, 0, 0, 0, 0x8AD2),
    L2(200, 0, 0, 0, 0, 0, 0, 0x8AD2),
    L2(80, 0, 0, 0, 0, 0, 0, 0x8AD2),
    L2(120, 0, 0, 0, 0, 0, 0, 0x8AD3),
    L2(200, 0, 0, 0, 0, 0, 0, 0x8AD4),
    L2(200, 0, 0, 0, 0, 0, 0, 0x8AD4),
    L2(80, 0, 0, 0, 0, 0, 0, 0x8AD4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg04_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg04_char_table_001[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B10),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg04_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg04_char_table_002[12] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8B52),
    L2(4, 1, 0, 0, 0, 0, 0, 0x8B52),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg04_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg04_char_table_003[44] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B52),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B53),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B54),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B55),
    L2(24, 0, 0, 0, 0, 0, 0, 0x8B56),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8B57),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B54),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B53),
    L2(20, 0, 0, 0, 0, 0, 0, 0x8B52),
    L2(20, 1, 0, 0, 0, 0, 0, 0x8B52),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg04_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg04_char_table_004[56] = {
    L2(200, 0, 0, 0, 0, 0, 0, 0x8B20),
    L2(15, 0, 0, 0, 0, 0, 0, 0x8B21),
    L2(13, 0, 0, 0, 0, 0, 0, 0x8B22),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8B23),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8B24),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8B25),
    L2(80, 0, 0, 0, 0, 0, 0, 0x8B26),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8B25),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8B24),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8B23),
    L2(13, 0, 0, 0, 0, 0, 0, 0x8B22),
    L2(15, 0, 0, 0, 0, 0, 0, 0x8B21),
    L2(200, 0, 0, 0, 0, 0, 0, 0x8B20),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg04_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg04_char_table_005[48] = {
    L2(80, 0, 0, 0, 0, 0, 0, 0x8B20),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8B27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8B28),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8B29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8B2A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8B2B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8B2A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8B29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8B28),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8B27),
    L2(4, 1, 0, 0, 0, 0, 0, 0x8B27),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg04_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg04_char_table_007[116] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8B93),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8B93),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B94),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8B95),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B96),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B97),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8B98),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B9D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B9E),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8B9F),
    CMD(CM_PA_X, 0, -3072, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8B4C),
    CMD(CM_PA_X, 0, -3072, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8B4C),
    CMD(CM_PA_X, 0, -3072, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B4D),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(12, 2, 0, 0, 0, 0, 0, 0x8B9E),
    L2(24, 2, 0, 0, 0, 0, 0, 0x8B9F),
    L2(8, 2, 0, 0, 0, 0, 0, 0x8B9E),
    L2(24, 2, 0, 0, 0, 0, 0, 0x8B9D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg04_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg04_char_table_006[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8B99),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B9A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B9B),
    L2(14, 0, 0, 0, 0, 0, 0, 0x8B9C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B9B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8B9A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B99),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8B9D),
    L2(10, 1, 0, 0, 0, 0, 0, 0x8B9D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg04_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg04_char_table_008[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B58),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg04_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg04_char_table_009[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B59),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg04_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg04_char_table_010[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8B90),
    CMD(CM_ROA, 0, 0, 0),
};

/* stg05_char_table: 18 entries, and no 0: the index after it follows on */
const u32 stg05_char_table[18] = {
    (u32)stg05_char_table_000, (u32)stg05_char_table_001, (u32)stg05_char_table_002, (u32)stg05_char_table_003, (u32)stg05_char_table_004, (u32)stg05_char_table_005,
    (u32)stg05_char_table_006, (u32)stg05_char_table_007, (u32)stg05_char_table_008, (u32)stg05_char_table_009, (u32)stg05_char_table_010, (u32)stg05_char_table_011,
    (u32)stg05_char_table_012, (u32)stg05_char_table_013, (u32)stg05_char_table_014, (u32)stg05_char_table_015, (u32)stg05_char_table_016, (u32)stg05_char_table_017,
};

/* eff08_char_table: 16 entries, and no 0: the index after it follows on */
const u32 eff08_char_table[16] = {
    (u32)eff08_char_table_000, (u32)eff08_char_table_001, (u32)eff08_char_table_002, (u32)eff08_char_table_003, (u32)eff08_char_table_004, (u32)eff08_char_table_005,
    (u32)eff08_char_table_006, (u32)eff08_char_table_007, (u32)eff08_char_table_008, (u32)eff08_char_table_009, (u32)eff08_char_table_010, (u32)eff08_char_table_011,
    (u32)eff08_char_table_012, (u32)eff08_char_table_013, (u32)eff08_char_table_014, (u32)eff08_char_table_015,
};

const u16 eff07_char_table[12] = {
    0x635, 0x2DAC, 0x635, 0x2E2C, 0x635, 0x2F44, 0x635, 0x2FB4,
    0x635, 0x2FFC, 0, 0,
};

const u16 stg05_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_000[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x84F0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_001[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8408),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_002[188] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8487),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8488),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8489),
    L2(6, 0, 0, 0, 0, 0, 0, 0x848A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x848B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x848C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x848D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x848E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x848F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8490),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8491),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8492),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8493),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8494),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8495),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8496),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8497),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8498),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8499),
    L2(6, 0, 0, 0, 0, 0, 0, 0x849A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x849B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x849C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x849D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84CA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84CB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84CC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84CD),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84CE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84CF),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84D0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84D1),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84D2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84D3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84D4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84D5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84D6),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84D7),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84D8),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84D9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84DA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84DB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84DC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84DD),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84DE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84DF),
    L2(6, 0, 0, 0, 0, 0, 0, 0x84E0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_003[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x840A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_004[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x840B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_005[8] = {
    L2(200, 0, 0, 0, 0, 0, 0, 0x8408),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_006[44] = {
    L2(84, 0, 0, 0, 0, 0, 0, 0x840E),
    L2(12, 0, 0, 0, 0, 0, 0, 0x840F),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8410),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8411),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8412),
    L2(60, 0, 0, 0, 0, 0, 0, 0x8413),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8412),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8411),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8410),
    L2(10, 0, 0, 0, 0, 0, 0, 0x840F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_007[52] = {
    L2(20, 0, 0, 0, 0, 0, 0, 0x8414),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8415),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8416),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8417),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8418),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8419),
    L2(10, 0, 0, 0, 0, 0, 0, 0x841A),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8419),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8418),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8417),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8416),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8415),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_008[64] = {
    L2(32, 0, 0, 0, 0, 0, 0, 0x841B),
    L2(22, 0, 0, 0, 0, 0, 0, 0x841C),
    L2(22, 0, 0, 0, 0, 0, 0, 0x841D),
    L2(22, 0, 0, 0, 0, 0, 0, 0x841E),
    L2(22, 0, 0, 0, 0, 0, 0, 0x841F),
    L2(22, 0, 0, 0, 0, 0, 0, 0x8420),
    L2(22, 0, 0, 0, 0, 0, 0, 0x8421),
    L2(32, 0, 0, 0, 0, 0, 0, 0x8422),
    L2(22, 0, 0, 0, 0, 0, 0, 0x8423),
    L2(22, 0, 0, 0, 0, 0, 0, 0x8424),
    L2(22, 0, 0, 0, 0, 0, 0, 0x8425),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8426),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8427),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8428),
    L2(160, 0, 0, 0, 0, 0, 0, 0x8429),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_009[60] = {
    L2(42, 0, 0, 0, 0, 0, 0, 0x842A),
    L2(16, 0, 0, 0, 0, 0, 0, 0x842B),
    L2(16, 0, 0, 0, 0, 0, 0, 0x842C),
    L2(16, 0, 0, 0, 0, 0, 0, 0x842D),
    L2(16, 0, 0, 0, 0, 0, 0, 0x842E),
    L2(16, 0, 0, 0, 0, 0, 0, 0x842F),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8430),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8431),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8432),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8433),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8434),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8435),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8436),
    L2(160, 0, 0, 0, 0, 0, 0, 0x8437),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_010[64] = {
    L2(26, 0, 0, 0, 0, 0, 0, 0x8438),
    L2(26, 0, 0, 0, 0, 0, 0, 0x8439),
    L2(26, 0, 0, 0, 0, 0, 0, 0x843A),
    L2(22, 0, 0, 0, 0, 0, 0, 0x843B),
    L2(20, 0, 0, 0, 0, 0, 0, 0x843C),
    L2(20, 0, 0, 0, 0, 0, 0, 0x843D),
    L2(20, 0, 0, 0, 0, 0, 0, 0x843E),
    L2(20, 0, 0, 0, 0, 0, 0, 0x843F),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8440),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8441),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8442),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8443),
    L2(22, 0, 0, 0, 0, 0, 0, 0x8444),
    L2(22, 0, 0, 0, 0, 0, 0, 0x8445),
    L2(160, 0, 0, 0, 0, 0, 0, 0x8446),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_011[52] = {
    L2(48, 0, 0, 0, 0, 0, 0, 0x8447),
    L2(22, 0, 0, 0, 0, 0, 0, 0x8448),
    L2(22, 0, 0, 0, 0, 0, 0, 0x8449),
    L2(20, 0, 0, 0, 0, 0, 0, 0x844A),
    L2(20, 0, 0, 0, 0, 0, 0, 0x844B),
    L2(20, 0, 0, 0, 0, 0, 0, 0x844C),
    L2(20, 0, 0, 0, 0, 0, 0, 0x844D),
    L2(18, 0, 0, 0, 0, 0, 0, 0x844E),
    L2(10, 0, 0, 0, 0, 0, 0, 0x844F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8450),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8451),
    L2(160, 0, 0, 0, 0, 0, 0, 0x8452),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_012[84] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x845E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x845F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8460),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8461),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8462),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8463),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8462),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8461),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8460),
    L2(6, 0, 0, 0, 0, 0, 0, 0x845F),
    L2(12, 0, 0, 0, 0, 0, 0, 0x845E),
    L2(12, 0, 0, 0, 0, 0, 0, 0x845F),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8460),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8461),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8462),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8463),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8462),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8461),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8460),
    L2(12, 0, 0, 0, 0, 0, 0, 0x845F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_013[124] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8464),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8465),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8466),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8467),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8466),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8465),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8464),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8465),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8466),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8467),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8468),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8469),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8468),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8467),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8468),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8469),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8468),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8467),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8466),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8465),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8464),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8465),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8466),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8467),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8468),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8469),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8468),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8467),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8466),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8465),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_014[44] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x846A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x846B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x846C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x846D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x846E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x846F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x846E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x846D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x846C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x846B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_015[72] = {
    L2(16, 0, 0, 0, 0, 0, 0, 0x8470),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8471),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8472),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8473),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8474),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8475),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8476),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8477),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8478),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8479),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8480),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8481),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8482),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8483),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8484),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8485),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8486),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_016[96] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8487),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8488),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8489),
    L2(6, 0, 0, 0, 0, 0, 0, 0x848A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x848B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x848C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x848D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x848E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x848F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8490),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8491),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8492),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8493),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8494),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8495),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8496),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8497),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8498),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8499),
    L2(6, 0, 0, 0, 0, 0, 0, 0x849A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x849B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x849C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x849D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg05_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg05_char_table_017[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x849E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_000[60] = {
    L2(54, 0, 0, 0, 0, 0, 0, 0x8453),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8455),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8456),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8457),
    L2(8, 0, 0, 0, 0, 0, 0, 0x845B),
    CMD(CM_EXEC, 3, 0, 0),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8457),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8456),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8455),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8454),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8453),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8458),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8453),
    L2(6, 1, 0, 0, 0, 0, 0, 0x8453),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_001[32] = {
    L2(12, 0, 0, 0, 0, 0, 0, 0x8457),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8456),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8455),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8454),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8453),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8458),
    L2(200, 0, 0, 0, 0, 0, 0, 0x8458),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_002[44] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x8464),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8465),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8466),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8467),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8468),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8469),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8468),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8467),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8466),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8465),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_003[44] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8464),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8465),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8466),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8467),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8468),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8469),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8468),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8467),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8466),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8465),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_004[112] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F9),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84FA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84FB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84FC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84FD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84FF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8500),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8501),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8502),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8503),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8504),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8505),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8506),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8507),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8508),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8509),
    L2(2, 0, 0, 0, 0, 0, 0, 0x850A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x850B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x850C),
    L2(2, 1, 0, 0, 0, 0, 0, 0x850C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_005[188] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x8487),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8488),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8489),
    L2(8, 0, 0, 0, 0, 0, 0, 0x848A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x848B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x848C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x848D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x848E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x848F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8490),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8491),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8492),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8493),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8494),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8495),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8496),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8497),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8498),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8499),
    L2(8, 0, 0, 0, 0, 0, 0, 0x849A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x849B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x849C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x849D),
    L2(10, 0, 0, 0, 0, 0, 0, 0x84CA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84CB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84CC),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84CD),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84CE),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84CF),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84D0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84D1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84D2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84D3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84D4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84D5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84D6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84D7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84D8),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84D9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84DA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84DB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84DC),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84DD),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84DE),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84DF),
    L2(8, 0, 0, 0, 0, 0, 0, 0x84E0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_006[56] = {
    CMD(CM_EXEC, 3, 1, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8532),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8533),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8534),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8535),
    CMD(CM_EXEC, 3, 2, 0),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8536),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8535),
    CMD(CM_EXEC, 3, 3, 0),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8534),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8535),
    L2(60, 0, 0, 0, 0, 0, 0, 0x8536),
    L2(4, 255, 0, 0, 0, 0, 0, 0x8536),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_007[24] = {
    CMD(CM_EXEC, 3, 1, 0),
    L2(14, 0, 0, 0, 0, 0, 0, 0x8532),
    CMD(CM_EXEC, 3, 1, 0),
    L2(18, 0, 0, 0, 0, 0, 0, 0x8532),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8532),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_008[52] = {
    L2(7, 0, 0, 0, 0, 0, 0, 0x853A),
    L2(10, 0, 0, 0, 0, 0, 0, 0x853B),
    L2(9, 0, 0, 0, 0, 0, 0, 0x853C),
    L2(12, 0, 0, 0, 0, 0, 0, 0x853D),
    L2(5, 0, 0, 0, 0, 0, 0, 0x853E),
    L2(13, 0, 0, 0, 0, 0, 0, 0x853F),
    L2(13, 0, 0, 0, 0, 0, 0, 0x8540),
    L2(13, 0, 0, 0, 0, 0, 0, 0x8541),
    L2(13, 0, 0, 0, 0, 0, 0, 0x8542),
    L2(13, 0, 0, 0, 0, 0, 0, 0x8543),
    L2(13, 0, 0, 0, 0, 0, 0, 0x8544),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8545),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_009[56] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x854E),
    L2(11, 0, 0, 0, 0, 0, 0, 0x854F),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8550),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8551),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8552),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8553),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8554),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8555),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8556),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8557),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8558),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8559),
    L2(11, 0, 0, 0, 0, 0, 0, 0x855A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_010[20] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x855B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x855C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x855D),
    L2(2, 1, 0, 0, 0, 0, 0, 0x855D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_011[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8583),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8584),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8585),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8586),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8587),
    L2(2, 1, 0, 0, 0, 0, 0, 0x8587),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_012[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8588),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8589),
    L2(2, 0, 0, 0, 0, 0, 0, 0x858A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x858B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x858C),
    L2(2, 1, 0, 0, 0, 0, 0, 0x858C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_013[24] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x858E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x858F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8590),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8591),
    L2(2, 1, 0, 0, 0, 0, 0, 0x8591),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_014[36] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8592),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8593),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8594),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8595),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8596),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8597),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8598),
    L2(2, 1, 0, 0, 0, 0, 0, 0x8598),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff08_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff08_char_table_015[412] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x85B6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85B7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85B8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85B9),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85BA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85BB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85BC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85BD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85BE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85BF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85B6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85B7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85B8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85B9),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85BA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85BB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85BC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85BD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85BE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x85BF),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3),
    L2(7, 0, 0, 0, 0, 0, 0, 0x856E),
    L2(17, 0, 0, 0, 0, 0, 0, 0x856F),
    L2(7, 0, 0, 0, 0, 0, 0, 0x856E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8570),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8571),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8570),
    CMD(CM_NEX, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8570),
    L2(7, 0, 0, 0, 0, 0, 0, 0x856E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8573),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8574),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8575),
    L2(6, 1, 0, 0, 0, 0, 0, 0x8575),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(21, 0, 0, 0, 0, 0, 0, 0x856E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8572),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8573),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8574),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8575),
    CMD(CM_FOR, 0, 0, 3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8577),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8578),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8577),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8576),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8575),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8576),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8577),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8576),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8575),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8576),
    CMD(CM_NEX, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8577),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8578),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8577),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8576),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8575),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8576),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8577),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8576),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8575),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8576),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8577),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8576),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8575),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8574),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8573),
    L2(7, 1, 0, 0, 0, 0, 0, 0x8573),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8579),
    L2(6, 0, 0, 0, 0, 0, 0, 0x857A),
    L2(32, 0, 0, 0, 0, 0, 0, 0x857B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x857C),
    L2(12, 0, 0, 0, 0, 0, 0, 0x857D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8570),
    L2(12, 0, 0, 0, 0, 0, 0, 0x857F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8580),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8581),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8580),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8581),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8581),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x857F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8581),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8580),
    CMD(CM_NEX, 0, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8571),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8571),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8578),
    L2(6, 0, 0, 0, 0, 0, 0, 0x857C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x857D),
    L2(16, 0, 0, 0, 0, 0, 0, 0x857B),
    L2(12, 0, 0, 0, 0, 0, 0, 0x857A),
    L2(12, 1, 0, 0, 0, 0, 0, 0x857A),
    CMD(CM_ROA, 0, 0, 0),
};

/* stg06_char_table: 37 entries */
const u32 stg06_char_table[38] = {
    (u32)stg06_char_table_000, (u32)stg06_char_table_001, (u32)stg06_char_table_002, (u32)stg06_char_table_003, (u32)stg06_char_table_004, (u32)stg06_char_table_005,
    (u32)stg06_char_table_006, (u32)stg06_char_table_007, (u32)stg06_char_table_008, (u32)stg06_char_table_009, (u32)stg06_char_table_010, (u32)stg06_char_table_011,
    (u32)stg06_char_table_012, (u32)stg06_char_table_013, (u32)stg06_char_table_014, (u32)stg06_char_table_015, (u32)stg06_char_table_016, (u32)stg06_char_table_017,
    (u32)stg06_char_table_018, (u32)stg06_char_table_019, (u32)stg06_char_table_020, (u32)stg06_char_table_021, (u32)stg06_char_table_022, (u32)stg06_char_table_023,
    (u32)stg06_char_table_024, (u32)stg06_char_table_025, (u32)stg06_char_table_026, (u32)stg06_char_table_027, (u32)stg06_char_table_028, (u32)stg06_char_table_029,
    (u32)stg06_char_table_030, (u32)stg06_char_table_031, (u32)stg06_char_table_032, (u32)stg06_char_table_033, (u32)stg06_char_table_034, (u32)stg06_char_table_035,
    (u32)stg06_char_table_036, 0,
};

const u16 stg06_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_000[52] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x85E0),
    L2(12, 0, 0, 0, 0, 0, 0, 0x85E1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85E2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85E3),
    L2(9, 0, 0, 0, 0, 0, 0, 0x85E4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85E5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85E6),
    L2(12, 0, 0, 0, 0, 0, 0, 0x85E7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85E8),
    L2(9, 0, 0, 0, 0, 0, 0, 0x85E5),
    L2(9, 0, 0, 0, 0, 0, 0, 0x85E4),
    L2(9, 0, 0, 0, 0, 0, 0, 0x85E3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_001[116] = {
    L2(32, 0, 0, 0, 0, 0, 0, 0x863A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x863B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x863C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x863D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x863E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x863F),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8640),
    L2(14, 0, 0, 0, 0, 0, 0, 0x8641),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8642),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8643),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8644),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8645),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8646),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8647),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8648),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8647),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8646),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8645),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8644),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8643),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8642),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8641),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8640),
    L2(6, 0, 0, 0, 0, 0, 0, 0x863F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x863E),
    L2(12, 0, 0, 0, 0, 0, 0, 0x863D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x863C),
    L2(14, 0, 0, 0, 0, 0, 0, 0x863B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_002[80] = {
    L2(120, 0, 0, 0, 0, 0, 0, 0x8658),
    CMD(CM_FOR, 0, 0, 3),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8658),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8655),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8658),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8656),
    CMD(CM_NEX, 0, 0, 0),
    L2(120, 0, 0, 0, 0, 0, 0, 0x8658),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8659),
    L2(9, 0, 0, 0, 0, 0, 0, 0x865A),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8657),
    CMD(CM_FOR, 0, 0, 2),
    L2(9, 0, 0, 0, 0, 0, 0, 0x865A),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8659),
    L2(9, 0, 0, 0, 0, 0, 0, 0x865A),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8657),
    CMD(CM_NEX, 0, 0, 0),
    L2(9, 0, 0, 0, 0, 0, 0, 0x865A),
    L2(120, 0, 0, 0, 0, 0, 0, 0x8658),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_003[176] = {
    CMD(CM_FOR, 0, 0, 3),
    L2(9, 0, 0, 0, 0, 0, 0, 0x865E),
    L2(9, 0, 0, 0, 0, 0, 0, 0x865F),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8660),
    L2(9, 0, 0, 0, 0, 0, 0, 0x865F),
    CMD(CM_NEX, 0, 0, 0),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8661),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8662),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8663),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8664),
    L2(72, 0, 0, 0, 0, 0, 0, 0x8665),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8666),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8667),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8668),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8669),
    L2(4, 0, 0, 0, 0, 0, 0, 0x866A),
    CMD(CM_FOR, 0, 0, 2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8664),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8665),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8666),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8667),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8668),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8669),
    L2(4, 0, 0, 0, 0, 0, 0, 0x866A),
    CMD(CM_NEX, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x866B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x866A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x865B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x865C),
    L2(10, 0, 0, 0, 0, 0, 0, 0x865D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8662),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8661),
    L2(190, 0, 0, 0, 0, 0, 0, 0x865E),
    CMD(CM_FOR, 0, 0, 3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x866C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x866D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x866E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x866F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8670),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8671),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8672),
    CMD(CM_NEX, 0, 0, 0),
    L2(190, 0, 0, 0, 0, 0, 0, 0x865E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_004[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8673),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_005[92] = {
    CMD(CM_FOR, 0, 0, 3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85F4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85F5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85F6),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85F5),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85F7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x85F8),
    L2(4, 1, 0, 0, 0, 0, 0, 0x85F8),
    L2(180, 0, 0, 0, 0, 0, 0, 0x85F9),
    CMD(CM_FOR, 0, 0, 3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85F9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85FA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85FB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85FC),
    CMD(CM_NEX, 0, 0, 0),
    L2(4, 1, 0, 0, 0, 0, 0, 0x85FC),
    L2(5, 0, 0, 0, 0, 0, 0, 0x85FD),
    L2(5, 0, 0, 0, 0, 0, 0, 0x85F8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x85F7),
    L2(5, 1, 0, 0, 0, 0, 0, 0x85F3),
    L2(186, 1, 0, 0, 0, 0, 0, 0x85F3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_006[76] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x85FE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x85FF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8600),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8601),
    CMD(CM_FOR, 0, 0, 3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8602),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8603),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8604),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8605),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8606),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8607),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8601),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8600),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85FF),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85FE),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85FE),
    L2(8, 1, 0, 0, 0, 0, 0, 0x85FE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_007[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x85E9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85EA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85EB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85EC),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85ED),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85EE),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85EF),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85F0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85F1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85F2),
    L2(8, 1, 0, 0, 0, 0, 0, 0x85E9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x85E9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_008[84] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x85E9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85EA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85EB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85EC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85ED),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85EE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85EF),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85F0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x85F1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85F2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85EA),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85EB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85EC),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85ED),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85EE),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85EF),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85F0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x85F1),
    L2(10, 0, 0, 0, 0, 0, 0, 0x85F2),
    L2(8, 1, 0, 0, 0, 0, 0, 0x85F2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_009[56] = {
    L2(90, 0, 0, 0, 0, 0, 0, 0x8610),
    L2(6, 0, 0, 0, 0, 0, 0, 0x860F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x860E),
    L2(9, 0, 0, 0, 0, 0, 0, 0x860D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x860E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x860F),
    L2(20, 0, 0, 0, 0, 0, 0, 0x8610),
    L2(6, 0, 0, 0, 0, 0, 0, 0x860F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x860E),
    L2(9, 0, 0, 0, 0, 0, 0, 0x860D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x860E),
    L2(5, 0, 0, 0, 0, 0, 0, 0x860F),
    L2(1, 1, 0, 0, 0, 0, 0, 0x860F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_010[84] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0x8610),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8611),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8612),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8613),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8614),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8615),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8616),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8617),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8618),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8619),
    L2(6, 0, 0, 0, 0, 0, 0, 0x861A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x861B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x861C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x861D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x861E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x861F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8620),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8612),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8611),
    L2(7, 1, 0, 0, 0, 0, 0, 0x8611),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_011[104] = {
    L2(20, 0, 0, 0, 0, 0, 0, 0x8621),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8622),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8623),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8624),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8625),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8626),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8627),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8628),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8629),
    L2(6, 0, 0, 0, 0, 0, 0, 0x862A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x862B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x862C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x862D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x862C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x862B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x862A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8629),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8628),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8627),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8626),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8625),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8624),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8623),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8622),
    L2(6, 1, 0, 0, 0, 0, 0, 0x8622),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_012[100] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8621),
    L2(4, 0, 0, 0, 0, 0, 0, 0x862E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x862F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8630),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8631),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8632),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8633),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8634),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8635),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8636),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8637),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8638),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8639),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8638),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8637),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8636),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8635),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8634),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8633),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8632),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8631),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8630),
    L2(5, 0, 0, 0, 0, 0, 0, 0x862F),
    L2(5, 1, 0, 0, 0, 0, 0, 0x862E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_013[100] = {
    L2(20, 0, 0, 0, 0, 0, 0, 0x8649),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x864A),
    L2(6, 1, 0, 0, 0, 0, 0, 0x864A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_014[52] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8649),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8650),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8651),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8652),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8653),
    L2(20, 0, 0, 0, 0, 0, 0, 0x8654),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8653),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8652),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8651),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8650),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8649),
    L2(4, 1, 0, 0, 0, 0, 0, 0x8649),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_015[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8608),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_016[28] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0x8609),
    L2(9, 0, 0, 0, 0, 0, 0, 0x860A),
    L2(9, 0, 0, 0, 0, 0, 0, 0x860B),
    L2(48, 0, 0, 0, 0, 0, 0, 0x860C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x860A),
    L2(6, 1, 0, 0, 0, 0, 0, 0x860A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_017[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x86A5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_018[32] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x86F0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86F1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86F2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86F3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86F4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86F5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86F6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_019[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x86A7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_020[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x86A8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_021[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x86AA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_022[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x86AB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_023[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8720),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8724),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8725),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8726),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8727),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8728),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8729),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_024[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x86B3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_025[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8721),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_026[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8722),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_027[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8723),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_028[36] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x86BD),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86BE),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86BF),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86C0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86C1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86C2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86C3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86C4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_029[92] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x86C5),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86C6),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86C7),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86C8),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86C9),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86CA),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86CB),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86CC),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86CD),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86CE),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86CF),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86D0),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86CF),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86CE),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86CD),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86CC),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86CB),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86CA),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86C9),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86C8),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86C7),
    L2(10, 0, 0, 0, 0, 0, 0, 0x86C6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_030[8] = {
    L2(200, 0, 0, 0, 0, 0, 0, 0x86D9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_031[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x86A9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_032[20] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x86A9),
    L2(8, 0, 113, 0, 0, 0, 0, 0x86D1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x86D2),
    L2(8, 1, 0, 0, 0, 0, 0, 0x86D2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_033[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x86D2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_034[96] = {
    L2(4, 0, 113, 0, 0, 0, 0, 0x86D3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86D4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86D5),
    L2(4, 2, 0, 0, 0, 0, 0, 0x86D6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86D7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86D8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86D9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86DA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86DB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86DC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86DB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86DA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86D9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86DD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86DE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86DF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86DD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86D9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86DA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86DB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86DA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86D9),
    L2(4, 1, 0, 0, 0, 0, 0, 0x86D9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_035[68] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x86E0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86E1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86E2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86E3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86E4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86E5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86E6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86E7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86E8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86E9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86EA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86EB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86EC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x86ED),
    L2(5, 0, 0, 0, 0, 0, 0, 0x86EE),
    L2(5, 1, 0, 0, 0, 0, 0, 0x86EE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stg06_char_table_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg06_char_table_036[8] = {
    L2(5, 1, 0, 0, 0, 0, 0, 0x86EF),
    CMD(CM_ROA, 0, 0, 0),
};

/* stg07_char_table: 1 entry */
const u32 stg07_char_table[2] = {
    (u32)stg07_char_table_000, 0,
};

const u16 stg07_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stg07_char_table_000[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9D10),
    CMD(CM_ROA, 0, 0, 0),
};

/* eff45_char_table: 27 entries, and no 0: the index after it follows on */
const u32 eff45_char_table[27] = {
    (u32)eff45_char_table_000, (u32)eff45_char_table_001, (u32)eff45_char_table_002, (u32)eff45_char_table_003, (u32)eff45_char_table_004, (u32)eff45_char_table_005,
    (u32)eff45_char_table_006, (u32)eff45_char_table_007, (u32)eff45_char_table_008, (u32)eff45_char_table_009, (u32)eff45_char_table_010, (u32)eff45_char_table_011,
    (u32)eff45_char_table_012, (u32)eff45_char_table_013, (u32)eff45_char_table_014, (u32)eff45_char_table_015, (u32)eff45_char_table_016, (u32)eff45_char_table_017,
    (u32)eff45_char_table_018, (u32)eff45_char_table_019, (u32)eff45_char_table_020, (u32)eff45_char_table_021, (u32)eff45_char_table_022, (u32)eff45_char_table_023,
    (u32)eff45_char_table_024, (u32)eff45_char_table_025, (u32)eff45_char_table_026,
};

const u16 eff54_char_table[12] = {
    0x635, 0x4590, 0x635, 0x46C8, 0x635, 0x4710, 0x635, 0x4738,
    0x635, 0x4778, 0, 0,
};

const u16 eff45_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_000[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8760),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_001[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8761),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_002[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8762),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_003[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8763),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_004[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8764),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_005[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x876F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_006[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8770),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_007[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8771),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_008[56] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8772),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8773),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8774),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8775),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8776),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8777),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8778),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8779),
    L2(4, 0, 0, 0, 0, 0, 0, 0x877A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x877B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x877C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x877D),
    L2(4, 1, 0, 0, 0, 0, 0, 0x877D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_009[56] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x87D0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87D1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87D2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87D3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87D4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87D5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87D6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87D7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87D8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87D9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87DA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87DB),
    L2(4, 1, 0, 0, 0, 0, 0, 0x87DB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_010[56] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x878A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x878B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x878C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x878D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x878E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x878F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8790),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8791),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8792),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8793),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8794),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8795),
    L2(4, 1, 0, 0, 0, 0, 0, 0x8795),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_011[56] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x87DC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87DD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87DE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87DF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87E0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87E1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87E2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87E3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87E4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87E5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87E6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x87E7),
    L2(4, 1, 0, 0, 0, 0, 0, 0x87E7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_012[8] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x8761),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_013[8] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x87E8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_014[8] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x87E9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_015[24] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x876B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x876C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x876D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x876E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x876D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_016[24] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x876B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x876C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x876D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x876E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x876D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_017[24] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x876B),
    L2(10, 0, 0, 0, 0, 0, 0, 0x876C),
    L2(10, 0, 0, 0, 0, 0, 0, 0x876D),
    L2(10, 0, 0, 0, 0, 0, 0, 0x876E),
    L2(10, 0, 0, 0, 0, 0, 0, 0x876D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_018[24] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x876B),
    L2(10, 0, 0, 0, 0, 0, 0, 0x876C),
    L2(10, 0, 0, 0, 0, 0, 0, 0x876D),
    L2(10, 0, 0, 0, 0, 0, 0, 0x876E),
    L2(10, 0, 0, 0, 0, 0, 0, 0x876D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_019[20] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8768),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8769),
    L2(6, 0, 0, 0, 0, 0, 0, 0x876A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8769),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_020[20] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8768),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8769),
    L2(8, 0, 0, 0, 0, 0, 0, 0x876A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8769),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_021[20] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x8768),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8769),
    L2(10, 0, 0, 0, 0, 0, 0, 0x876A),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8769),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_022[20] = {
    L2(12, 0, 0, 0, 0, 0, 0, 0x8768),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8769),
    L2(12, 0, 0, 0, 0, 0, 0, 0x876A),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8769),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_023[20] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x8765),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8766),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8767),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8766),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_024[20] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8765),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8766),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8767),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8766),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_025[20] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0x8765),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8766),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8767),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8766),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff45_char_table_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff45_char_table_026[348] = {
    L2(12, 0, 0, 0, 0, 0, 0, 0x8765),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8766),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8767),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8766),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8818),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8819),
    L2(6, 0, 0, 0, 0, 0, 0, 0x881A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x881B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x881C),
    L2(6, 0, 0, 0, 0, 0, 0, 0x881D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x881E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x881F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8820),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8821),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8822),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8823),
    L2(6, 1, 0, 0, 0, 0, 0, 0x8823),
    CMD(CM_EXEC, 4, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8824),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8825),
    L2(1, 2, 0, 0, 0, 0, 0, 0x8825),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8826),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8827),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8828),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8829),
    L2(9, 0, 0, 0, 0, 0, 0, 0x882A),
    L2(9, 0, 0, 0, 0, 0, 0, 0x882B),
    L2(9, 0, 0, 0, 0, 0, 0, 0x882C),
    L2(9, 0, 0, 0, 0, 0, 0, 0x882D),
    L2(9, 0, 0, 0, 0, 0, 0, 0x882E),
    L2(9, 0, 0, 0, 0, 0, 0, 0x882F),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8830),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8831),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8832),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8833),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8834),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8835),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8836),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8837),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8838),
    L2(2, 1, 0, 0, 0, 0, 0, 0x8838),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8839),
    L2(10, 0, 0, 0, 0, 0, 0, 0x883A),
    L2(9, 0, 0, 0, 0, 0, 0, 0x883B),
    L2(10, 0, 0, 0, 0, 0, 0, 0x883C),
    L2(10, 0, 0, 0, 0, 0, 0, 0x883D),
    L2(11, 0, 0, 0, 0, 0, 0, 0x883E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x883F),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8848),
    L2(16, 0, 0, 0, 0, 0, 0, 0x8849),
    L2(16, 0, 0, 0, 0, 0, 0, 0x884A),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8841),
    L2(24, 0, 0, 0, 0, 0, 0, 0x8843),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8844),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8845),
    L2(2, 2, 0, 0, 0, 0, 0, 0x8845),
    L2(250, 1, 0, 0, 0, 0, 0, 0x8845),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8839),
    L2(6, 0, 0, 0, 0, 0, 0, 0x883A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x883B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x883C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x883D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x883E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x883F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8840),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8839),
    L2(4, 0, 0, 0, 0, 0, 0, 0x883A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x883B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x883C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x883D),
    L2(5, 0, 0, 0, 0, 0, 0, 0x883E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x883F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8840),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8839),
    L2(5, 0, 0, 0, 0, 0, 0, 0x883A),
    L2(200, 0, 0, 0, 0, 0, 0, 0x883B),
    CMD(CM_ROA, 0, 0, 0),
};

/* eff86_char_table: 21 entries */
const u32 eff86_char_table[22] = {
    (u32)eff86_char_table_000, (u32)eff86_char_table_001, (u32)eff86_char_table_002, (u32)eff86_char_table_003, (u32)eff86_char_table_004, (u32)eff86_char_table_005,
    (u32)eff86_char_table_006, (u32)eff86_char_table_007, (u32)eff86_char_table_008, (u32)eff86_char_table_009, (u32)eff86_char_table_010, (u32)eff86_char_table_011,
    (u32)eff86_char_table_012, (u32)eff86_char_table_013, (u32)eff86_char_table_014, (u32)eff86_char_table_015, (u32)eff86_char_table_016, (u32)eff86_char_table_017,
    (u32)eff86_char_table_018, (u32)eff86_char_table_019, (u32)eff86_char_table_020, 0,
};

const u16 eff86_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_000[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x88B0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_001[44] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x88F1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x88F2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x88F3),
    L2(8, 0, 0, 0, 0, 0, 0, 0x88F4),
    L2(8, 0, 0, 0, 0, 0, 0, 0x88F5),
    L2(8, 0, 0, 0, 0, 0, 0, 0x88F6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x88F7),
    L2(8, 0, 0, 0, 0, 0, 0, 0x88F8),
    L2(8, 0, 0, 0, 0, 0, 0, 0x88F9),
    L2(8, 0, 0, 0, 0, 0, 0, 0x88FA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_002[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8910),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_003[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8911),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_018[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8929),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_004[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x88C0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_005[8] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x8912),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_006[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8950),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_007[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8951),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_008[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8952),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_009[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8953),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_010[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8A98),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_011[140] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8956),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8957),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8958),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8959),
    L2(5, 0, 0, 0, 0, 0, 0, 0x895A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x895B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x895C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x895D),
    CMD(CM_FOR, 0, 0, 3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x895E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x895F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8960),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8961),
    CMD(CM_NEX, 0, 0, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x895E),
    L2(5, 0, 0, 0, 0, 0, 0, 0x895D),
    CMD(CM_FOR, 0, 0, 2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8956),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8957),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8958),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8959),
    L2(5, 0, 0, 0, 0, 0, 0, 0x895A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x895B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x895C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x895D),
    CMD(CM_NEX, 0, 0, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x895E),
    L2(5, 0, 0, 0, 0, 0, 0, 0x895F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8960),
    L2(5, 0, 0, 0, 0, 0, 0, 0x895F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x895E),
    L2(5, 0, 0, 0, 0, 0, 0, 0x895F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8960),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8961),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_012[180] = {
    CMD(CM_FOR2, 0, 0, 2),
    CMD(CM_FOR, 0, 0, 4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8967),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8966),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8965),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8966),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8966),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8968),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8969),
    L2(5, 0, 0, 0, 0, 0, 0, 0x896A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8969),
    L2(6, 0, 0, 0, 0, 0, 0, 0x896B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x896C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8968),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8969),
    L2(6, 0, 0, 0, 0, 0, 0, 0x896A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8969),
    L2(4, 0, 0, 0, 0, 0, 0, 0x896B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x896C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x896D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x896E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x896F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8970),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8971),
    L2(5, 0, 0, 0, 0, 0, 0, 0x896E),
    L2(5, 0, 0, 0, 0, 0, 0, 0x896D),
    L2(5, 0, 0, 0, 0, 0, 0, 0x896B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8966),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8967),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8966),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8965),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8966),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8967),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8966),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8965),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8966),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8967),
    CMD(CM_NEX2, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8972),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8973),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8974),
    L2(30, 0, 0, 0, 0, 0, 0, 0x8975),
    L2(9, 1, 0, 0, 0, 0, 0, 0x8975),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_013[220] = {
    CMD(CM_FOR2, 0, 0, 2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8978),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8978),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(6, 0, 0, 0, 0, 0, 0, 0x897A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8978),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(6, 0, 0, 0, 0, 0, 0, 0x897A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8980),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8982),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8983),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8984),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8982),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8983),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8984),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8983),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8982),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8981),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8980),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8981),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8982),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8983),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8984),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8983),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8982),
    L2(5, 0, 0, 0, 0, 0, 0, 0x897B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(5, 0, 0, 0, 0, 0, 0, 0x897A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8979),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8981),
    L2(5, 0, 0, 0, 0, 0, 0, 0x897B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x897D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x897E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8981),
    L2(2, 0, 0, 0, 0, 0, 0, 0x897D),
    L2(6, 0, 0, 0, 0, 0, 0, 0x897E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x897F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8981),
    CMD(CM_NEX2, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8987),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8986),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8988),
    L2(30, 0, 0, 0, 0, 0, 0, 0x8989),
    L2(9, 1, 0, 0, 0, 0, 0, 0x8989),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_014[220] = {
    L2(48, 0, 0, 0, 0, 0, 0, 0x898B),
    L2(10, 0, 0, 0, 0, 0, 0, 0x898C),
    L2(10, 0, 0, 0, 0, 0, 0, 0x898D),
    L2(10, 0, 0, 0, 0, 0, 0, 0x898E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x898F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8990),
    L2(22, 0, 0, 0, 0, 0, 0, 0x8991),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8990),
    CMD(CM_FOR, 0, 0, 2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x898F),
    L2(7, 0, 0, 0, 0, 0, 0, 0x898E),
    CMD(CM_NEX, 0, 0, 0),
    L2(22, 0, 0, 0, 0, 0, 0, 0x898D),
    L2(7, 0, 0, 0, 0, 0, 0, 0x898C),
    CMD(CM_FOR, 0, 0, 3),
    L2(7, 0, 0, 0, 0, 0, 0, 0x898B),
    L2(7, 0, 0, 0, 0, 0, 0, 0x898C),
    CMD(CM_NEX, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8990),
    L2(21, 0, 0, 0, 0, 0, 0, 0x898E),
    L2(7, 0, 0, 0, 0, 0, 0, 0x898F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8992),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8993),
    L2(67, 0, 0, 0, 0, 0, 0, 0x8994),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8995),
    L2(96, 0, 0, 0, 0, 0, 0, 0x8996),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8993),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8992),
    L2(7, 0, 0, 0, 0, 0, 0, 0x898F),
    L2(21, 0, 0, 0, 0, 0, 0, 0x898E),
    L2(7, 0, 0, 0, 0, 0, 0, 0x898D),
    L2(7, 0, 0, 0, 0, 0, 0, 0x898C),
    L2(31, 0, 0, 0, 0, 0, 0, 0x898B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8997),
    CMD(CM_FOR, 0, 0, 2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8998),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8999),
    CMD(CM_NEX, 0, 0, 0),
    L2(46, 0, 0, 0, 0, 0, 0, 0x899A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x899B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x899A),
    L2(12, 0, 0, 0, 0, 0, 0, 0x899B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8999),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8998),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8999),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8998),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8999),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8998),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8997),
    L2(3, 1, 0, 0, 0, 0, 0, 0x8997),
    CMD(CM_FOR, 0, 0, 2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x898F),
    L2(7, 0, 0, 0, 0, 0, 0, 0x898E),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_015[160] = {
    L2(41, 0, 0, 0, 0, 0, 0, 0x8A80),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8A81),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8A82),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8A83),
    L2(32, 0, 0, 0, 0, 0, 0, 0x8A85),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A86),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A87),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A88),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A87),
    CMD(CM_FOR, 0, 0, 2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A86),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A85),
    L2(31, 0, 0, 0, 0, 0, 0, 0x8A84),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A85),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A86),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A87),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A88),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A87),
    CMD(CM_NEX, 0, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A86),
    L2(31, 0, 0, 0, 0, 0, 0, 0x8A85),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8A84),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8A83),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8A82),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8A81),
    L2(31, 0, 0, 0, 0, 0, 0, 0x8A80),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8A89),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A8A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A8B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A8C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A8D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A8E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A8F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A90),
    L2(53, 0, 0, 0, 0, 0, 0, 0x8A91),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8A92),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8A93),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8A94),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8A95),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_016[236] = {
    L2(30, 0, 0, 0, 0, 0, 0, 0x89D4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D1),
    L2(30, 0, 0, 0, 0, 0, 0, 0x89D0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D5),
    L2(30, 0, 0, 0, 0, 0, 0, 0x89D4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D9),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x89DB),
    L2(8, 0, 0, 0, 0, 0, 0, 0x89E0),
    L2(12, 0, 0, 0, 0, 0, 0, 0x89E1),
    CMD(CM_FOR, 0, 0, 2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x89E0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x89DB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DF),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x89DE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x89DD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89E0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DF),
    CMD(CM_FOR, 0, 0, 2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89E0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x89DF),
    L2(6, 0, 0, 0, 0, 0, 0, 0x89DE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x89DD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89E0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DF),
    CMD(CM_NEX, 0, 0, 0),
    L2(14, 0, 0, 0, 0, 0, 0, 0x89DE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x89DF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89E0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89DA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D9),
    L2(2, 0, 0, 0, 0, 0, 0, 0x89D8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x89D7),
    L2(7, 0, 0, 0, 0, 0, 0, 0x89D6),
    L2(8, 0, 0, 0, 0, 0, 0, 0x89D1),
    L2(43, 0, 0, 0, 0, 0, 0, 0x89D0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_017[452] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A10),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A11),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A12),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A13),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A14),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A15),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A16),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A17),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A18),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A1A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A1B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A1C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A1D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A1E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A1F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A20),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A21),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A22),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A23),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A24),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A25),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A26),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A27),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A28),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A29),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A2A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A2B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A2C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A2D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A2E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A2F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A30),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A31),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A32),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A33),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A34),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A35),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A36),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A37),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A38),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A39),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A3A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A3B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A3C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A3D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A3E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A3F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A40),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A41),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A42),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A43),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A44),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A45),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A46),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A47),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A48),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A49),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A4A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A4B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A4C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A4D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A4E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A4F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A50),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A51),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A52),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A53),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A54),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A55),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A56),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A57),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A58),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A59),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A5A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A5B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A5C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A5D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A5E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A5F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A60),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A61),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A62),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A63),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A64),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A65),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A66),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A67),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A68),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A69),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A6A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A6B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A6C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A6D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A6E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A6F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A70),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A71),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A72),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A73),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A74),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A75),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A76),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A77),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A78),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A79),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A7A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A7B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A7C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A7D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A7E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8A7F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_019[24] = {
    L2(30, 0, 0, 0, 0, 0, 0, 0x8975),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8974),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8973),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8972),
    L2(2, 1, 0, 0, 0, 0, 0, 0x8972),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff86_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff86_char_table_020[24] = {
    L2(30, 0, 0, 0, 0, 0, 0, 0x8989),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8988),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8986),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8987),
    L2(2, 1, 0, 0, 0, 0, 0, 0x8987),
    CMD(CM_ROA, 0, 0, 0),
};

/* eff09_char_table: 7 entries */
const u32 eff09_char_table[8] = {
    (u32)eff09_char_table_000, (u32)eff09_char_table_001, (u32)eff09_char_table_002, (u32)eff09_char_table_003, (u32)eff09_char_table_004, (u32)eff09_char_table_005,
    (u32)eff09_char_table_006, 0,
};

const u16 eff09_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff09_char_table_000[112] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84F9),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84FA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84FB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84FC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84FD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x84FF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8500),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8501),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8502),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8503),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8504),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8505),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8506),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8507),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8508),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8509),
    L2(2, 0, 0, 0, 0, 0, 0, 0x850A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x850B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x850C),
    L2(2, 1, 0, 0, 0, 0, 0, 0x850C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff09_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff09_char_table_001[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8583),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8584),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8585),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8586),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8587),
    L2(2, 1, 0, 0, 0, 0, 0, 0x8587),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff09_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff09_char_table_002[36] = {
    CMD(CM_FOR, 0, 0, 2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8588),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8589),
    L2(2, 0, 0, 0, 0, 0, 0, 0x858A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x858B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x858C),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 1, 0, 0, 0, 0, 0, 0x858C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff09_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff09_char_table_003[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x855B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x855C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x855D),
    L2(2, 1, 0, 0, 0, 0, 0, 0x855D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff09_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff09_char_table_004[36] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x7990),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7991),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7992),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7993),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7994),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7995),
    L2(6, 0, 0, 0, 0, 0, 0, 0x7996),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_EXEC, 3, 0, 0),
};

const u16 eff09_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff09_char_table_005[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA534),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA535),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA536),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA537),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA538),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA539),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA539),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff09_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff09_char_table_006[40] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xA53A),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA53B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA53C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA53D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA53E),
    L2(3, 2, 0, 0, 0, 0, 0, 0xA53F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA540),
    L2(3, 0, 0, 0, 0, 0, 0, 0xA541),
    L2(250, 255, 0, 0, 0, 0, 0, 0xA541),
    CMD(CM_ROA, 0, 0, 0),
};

/* brz_char_table: 52 entries, and no 0: the index after it follows on */
const u32 brz_char_table[52] = {
    (u32)brz_char_table_000, (u32)brz_char_table_001, (u32)brz_char_table_002, (u32)brz_char_table_003, (u32)brz_char_table_004, (u32)brz_char_table_005,
    (u32)brz_char_table_006, (u32)brz_char_table_007, (u32)brz_char_table_008, (u32)brz_char_table_009, (u32)brz_char_table_010, (u32)brz_char_table_011,
    (u32)brz_char_table_012, (u32)brz_char_table_013, (u32)brz_char_table_014, (u32)brz_char_table_015, (u32)brz_char_table_016, (u32)brz_char_table_017,
    (u32)brz_char_table_018, (u32)brz_char_table_019, (u32)brz_char_table_020, (u32)brz_char_table_021, (u32)brz_char_table_022, (u32)brz_char_table_023,
    (u32)brz_char_table_024, (u32)brz_char_table_025, (u32)brz_char_table_026, (u32)brz_char_table_027, (u32)brz_char_table_028, (u32)brz_char_table_029,
    (u32)brz_char_table_030, (u32)brz_char_table_031, (u32)brz_char_table_032, (u32)brz_char_table_033, (u32)brz_char_table_034, (u32)brz_char_table_035,
    (u32)brz_char_table_036, (u32)brz_char_table_037, (u32)brz_char_table_038, (u32)brz_char_table_039, (u32)brz_char_table_040, (u32)brz_char_table_041,
    (u32)brz_char_table_042, (u32)brz_char_table_043, (u32)brz_char_table_044, (u32)brz_char_table_045, (u32)brz_char_table_046, (u32)brz_char_table_047,
    (u32)brz_char_table_048, (u32)brz_char_table_049, (u32)brz_char_table_050, (u32)brz_char_table_051,
};

/* eff90_char_table: 1 entry */
const u32 eff90_char_table[2] = {
    (u32)eff90_char_table_000, 0,
};

const u16 brz_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_000[68] = {
    CMD(CM_FOR, 0, 0, 3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC6),
    CMD(CM_NEX, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BCA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BCB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BCC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BCD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_001[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BC9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BCA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BCB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BCC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BCD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_002[68] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BCE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BCF),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BD8),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BD9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BDA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BDB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BCE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BCF),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BD0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BD1),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BD2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BD3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BD4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BD5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BD6),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BD7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_003[52] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x8BDC),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8BDD),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8BDE),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8BDF),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8BE0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8BE1),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8BE2),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8BE3),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8BE4),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8BE5),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8BE6),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8BE7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_004[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BE8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BE9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BEA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BEB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BEC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BED),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BEE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BEF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BF0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_005[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BF1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BF2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BF3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BF4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BF5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BF6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BF7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BF8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8BF9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_006[40] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BFA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BFB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BFC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BFD),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BFE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8BFF),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8C00),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8C01),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8C02),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_007[8] = {
    L2(26, 0, 0, 0, 0, 0, 0, 0x8C03),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_008[48] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8C04),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8C05),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8C06),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8C07),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8C08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8C09),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8C0A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8C0B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8C0C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8C0D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8C0E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_009[12] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x8C0F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8C10),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_010[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C11),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_011[32] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C12),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C13),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C14),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C15),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C16),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C17),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C18),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_012[188] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C19),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C1A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C1B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C1C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C1D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C1E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C1F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C20),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C21),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C22),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C23),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C24),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C25),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C26),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C27),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C28),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C29),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C2A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C2B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C2C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C2D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C2E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C2F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C30),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C31),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C32),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C33),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C34),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C35),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C36),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C37),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C38),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C39),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C3A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C3B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C3C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C3D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C3E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C3F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C40),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C41),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C42),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C43),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C44),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C45),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8C46),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_013[108] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x8CE8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8CE9),
    L2(29, 0, 0, 0, 0, 0, 0, 0x8CEA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8CE9),
    L2(9, 0, 0, 0, 0, 0, 0, 0x8CE8),
    CMD(CM_FOR, 0, 0, 3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8CEB),
    L2(26, 0, 0, 0, 0, 0, 0, 0x8CEC),
    CMD(CM_NEX, 0, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8CED),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8CEE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8CEF),
    CMD(CM_FOR, 0, 0, 3),
    L2(60, 0, 0, 0, 0, 0, 0, 0x8CF0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8CF1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8CF2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8CF1),
    L2(60, 0, 0, 0, 0, 0, 0, 0x8CF0),
    CMD(CM_NEX, 0, 0, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8CF2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8CF3),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8CF4),
    L2(56, 0, 0, 0, 0, 0, 0, 0x8CEC),
    L2(136, 0, 0, 0, 0, 0, 0, 0x8CEB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8CE8),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8CE9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_014[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8CF9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_015[68] = {
    L2(145, 1, 0, 0, 0, 0, 0, 0x8CFA),
    L2(10, 1, 0, 0, 0, 0, 0, 0x8CFB),
    L2(11, 1, 0, 0, 0, 0, 0, 0x8CFC),
    L2(176, 1, 0, 0, 0, 0, 0, 0x8CFD),
    L2(11, 1, 0, 0, 0, 0, 0, 0x8CFC),
    L2(10, 1, 0, 0, 0, 0, 0, 0x8CFB),
    CMD(CM_FOR, 0, 0, 3),
    L2(12, 1, 0, 0, 0, 0, 0, 0x8CFB),
    L2(12, 1, 0, 0, 0, 0, 0, 0x8CFC),
    L2(12, 1, 0, 0, 0, 0, 0, 0x8CFD),
    CMD(CM_NEX, 0, 0, 0),
    L2(10, 1, 0, 0, 0, 0, 0, 0x8CFB),
    L2(11, 1, 0, 0, 0, 0, 0, 0x8CFC),
    L2(106, 1, 0, 0, 0, 0, 0, 0x8CFD),
    L2(11, 1, 0, 0, 0, 0, 0, 0x8CFC),
    L2(10, 1, 0, 0, 0, 0, 0, 0x8CFB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_016[16] = {
    L2(24, 0, 0, 0, 0, 0, 0, 0x8CFF),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8CFE),
    L2(6, 1, 0, 0, 0, 0, 0, 0x8CFE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_017[108] = {
    L2(103, 2, 0, 0, 0, 0, 0, 0x8D00),
    L2(10, 2, 0, 0, 0, 0, 0, 0x8D01),
    L2(7, 2, 0, 0, 0, 0, 0, 0x8D02),
    L2(5, 2, 0, 0, 0, 0, 0, 0x8D01),
    L2(7, 2, 0, 0, 0, 0, 0, 0x8D02),
    L2(7, 2, 0, 0, 0, 0, 0, 0x8D01),
    L2(6, 2, 0, 0, 0, 0, 0, 0x8D02),
    L2(7, 2, 0, 0, 0, 0, 0, 0x8D01),
    L2(36, 2, 0, 0, 0, 0, 0, 0x8D02),
    L2(4, 2, 0, 0, 0, 0, 0, 0x8D03),
    L2(5, 2, 0, 0, 0, 0, 0, 0x8D04),
    L2(5, 2, 0, 0, 0, 0, 0, 0x8D05),
    L2(19, 2, 0, 0, 0, 0, 0, 0x8D06),
    L2(23, 0, 0, 0, 0, 0, 0, 0x8D07),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8D08),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8D09),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D07),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D08),
    L2(15, 0, 0, 0, 0, 0, 0, 0x8D09),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D07),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D08),
    L2(14, 0, 0, 0, 0, 0, 0, 0x8D09),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8D0A),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8D0B),
    L2(46, 0, 0, 0, 0, 0, 0, 0x8D07),
    CMD(CM_END, 0, 0, 14),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_018[68] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D0C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D0D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D0E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D0F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8D10),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D11),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D12),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8D13),
    L2(39, 0, 0, 0, 0, 0, 0, 0x8D14),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D15),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D16),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D15),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D16),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D15),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D16),
    L2(200, 0, 0, 0, 0, 0, 0, 0x8D14),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_019[76] = {
    L2(39, 0, 0, 0, 0, 0, 0, 0x8D17),
    CMD(CM_FOR, 0, 0, 2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D18),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D19),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D18),
    L2(18, 0, 0, 0, 0, 0, 0, 0x8D1A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D17),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D19),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D1A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D1B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D1E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D1D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D1E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D1D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D1C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D1B),
    L2(33, 0, 0, 0, 0, 0, 0, 0x8D17),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_020[200] = {
    CMD(CM_FOR, 0, 0, 3),
    L2(80, 0, 0, 0, 0, 0, 0, 0x8D25),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8D26),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8D27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D28),
    L2(88, 0, 0, 0, 0, 0, 0, 0x8D29),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8D2A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8D2B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D2A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D2B),
    L2(18, 0, 0, 0, 0, 0, 0, 0x8D2A),
    L2(230, 0, 0, 0, 0, 0, 0, 0x8D29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D28),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8D27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D26),
    L2(140, 0, 0, 0, 0, 0, 0, 0x8D25),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D2E),
    L2(20, 0, 0, 0, 0, 0, 0, 0x8D2F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D2E),
    L2(92, 0, 0, 0, 0, 0, 0, 0x8D2F),
    L2(140, 0, 0, 0, 0, 0, 0, 0x8D25),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8D26),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8D27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D28),
    L2(60, 0, 0, 0, 0, 0, 0, 0x8D29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D28),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8D27),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8D26),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8D27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D28),
    L2(168, 0, 0, 0, 0, 0, 0, 0x8D29),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8D2A),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8D2B),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8D2A),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8D2B),
    L2(7, 0, 0, 0, 0, 0, 0, 0x8D2A),
    L2(50, 0, 0, 0, 0, 0, 0, 0x8D29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D28),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8D27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D26),
    L2(178, 0, 0, 0, 0, 0, 0, 0x8D25),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D2E),
    L2(30, 0, 0, 0, 0, 0, 0, 0x8D2F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D2E),
    L2(32, 0, 0, 0, 0, 0, 0, 0x8D2F),
    CMD(CM_NEX, 0, 0, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8D2C),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8D2D),
    L2(5, 1, 0, 0, 0, 0, 0, 0x8D2D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_021[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D1F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D20),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D21),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D22),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D23),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D24),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_022[24] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8D26),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8D27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D28),
    L2(29, 0, 0, 0, 0, 0, 0, 0x8D29),
    L2(29, 1, 0, 0, 0, 0, 0, 0x8D29),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_023[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D2A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D2B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D2A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D2B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D2A),
    L2(4, 1, 0, 0, 0, 0, 0, 0x8D2B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_025[16] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x8D2C),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8D2D),
    L2(5, 1, 0, 0, 0, 0, 0, 0x8D2D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_024[24] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x8D2E),
    L2(20, 0, 0, 0, 0, 0, 0, 0x8D2F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x8D2E),
    L2(32, 0, 0, 0, 0, 0, 0, 0x8D2F),
    L2(32, 1, 0, 0, 0, 0, 0, 0x8D2F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_026[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D30),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D31),
    L2(40, 0, 0, 0, 0, 0, 0, 0x8D25),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D2E),
    L2(20, 0, 0, 0, 0, 0, 0, 0x8D2F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D2E),
    L2(32, 0, 0, 0, 0, 0, 0, 0x8D2F),
    L2(3, 1, 0, 0, 0, 0, 0, 0x8D25),
    L2(40, 0, 0, 0, 0, 0, 0, 0x8D25),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_027[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x8D40),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_028[28] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x8D43),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8D43),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8D44),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8D44),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8D46),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8D46),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_029[36] = {
    CMD(CM_FOR, 0, 0, 4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D47),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D48),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D49),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D4A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D4B),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 1, 0, 0, 0, 0, 0, 0x8D4B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_030[72] = {
    CMD(CM_FOR, 0, 0, 2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D4C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D4D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D4E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D4F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D50),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D51),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D52),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D4C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D4D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D4E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D4F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D50),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D51),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D52),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8D52),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_031[36] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D4C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D4D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D4E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D4F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D50),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D51),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D52),
    L2(8, 1, 0, 0, 0, 0, 0, 0x8D52),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_032[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D58),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D59),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D5A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D5B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_033[44] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D5C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D5D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D5F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D60),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D61),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D62),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D63),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D64),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D65),
    L2(3, 1, 0, 0, 0, 0, 0, 0x8D65),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_034[20] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D68),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D69),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D6A),
    L2(6, 1, 0, 0, 0, 0, 0, 0x8D6A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_035[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D6B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_036[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D6C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D6D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D6E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D6F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_037[44] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D70),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D71),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D72),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D73),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D74),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D75),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D76),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D77),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8D78),
    L2(3, 1, 0, 0, 0, 0, 0, 0x8D78),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_038[20] = {
    L2(6, 0, 0, 0, 1, 0, 0, 0x8D68),
    L2(6, 0, 0, 0, 1, 0, 0, 0x8D69),
    L2(6, 0, 0, 0, 1, 0, 0, 0x8D6A),
    L2(6, 1, 0, 0, 1, 0, 0, 0x8D6A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_039[8] = {
    L2(6, 0, 0, 0, 1, 0, 0, 0x8D6B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_040[40] = {
    L2(200, 0, 0, 0, 0, 0, 0, 0x8D39),
    CMD(CM_FOR, 0, 0, 2),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8D3A),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8D3B),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8D3C),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8D3D),
    L2(11, 0, 0, 0, 0, 0, 0, 0x8D3E),
    CMD(CM_NEX, 0, 0, 0),
    L2(200, 0, 0, 0, 0, 0, 0, 0x8D39),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_041[56] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D39),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D38),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D37),
    L2(10, 0, 0, 0, 0, 0, 0, 0x8D33),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8D34),
    L2(24, 0, 0, 0, 0, 0, 0, 0x8D35),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D34),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8D36),
    L2(18, 0, 0, 0, 0, 0, 0, 0x8D33),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8D37),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8D38),
    L2(12, 0, 0, 0, 0, 0, 0, 0x8D39),
    L2(10, 1, 0, 0, 0, 0, 0, 0x8D39),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_042[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C1A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C1B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C1C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C1D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C1E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C1F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_043[16] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C20),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C21),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C22),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_044[28] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C23),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C24),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C25),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C26),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C27),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C28),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_045[28] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C29),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C2A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C2B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C2C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C2D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C2E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_046[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C2F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C30),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C31),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C32),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C33),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_047[28] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C34),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C35),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C36),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C37),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C38),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C39),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_048[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C3A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C3B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C3C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C3D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_049[28] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C3E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C3F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C40),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C41),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C42),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C43),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_050[16] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C44),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C45),
    L2(3, 0, 0, 0, 0, 0, 0, 0x8C46),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_051[52] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x8CF5),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8CF6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8CF7),
    CMD(CM_FOR, 0, 0, 10),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8CF8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x8CF7),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x8CF8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x8CF6),
    L2(5, 0, 0, 0, 0, 0, 0, 0x8CF5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x8CE9),
    L2(6, 1, 0, 0, 0, 0, 0, 0x8CE9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eff90_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eff90_char_table_000[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x409A),
    CMD(CM_ROA, 0, 0, 0),
};

/* provisional name */
/* 6 entries; nothing in the program refers to it */
const u32 stage_char_06356D60[7] = {
    (u32)stage_char_06356D60_000, (u32)stage_char_06356D60_001, (u32)stage_char_06356D60_002, (u32)stage_char_06356D60_003, (u32)stage_char_06356D60_004, (u32)stage_char_06356D60_005,
    0,
};

const u16 stage_char_06356D60_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stage_char_06356D60_000[224] = {
    L2(4, 13, 0, 0, 0, 0, 0, 0x9A90),
    L2(4, 13, 0, 0, 0, 0, 0, 0x9A91),
    L2(4, 13, 0, 0, 0, 0, 0, 0x9A92),
    L2(4, 13, 0, 0, 0, 0, 0, 0x9A93),
    L2(4, 13, 0, 0, 0, 0, 0, 0x9A94),
    L2(4, 13, 0, 0, 0, 0, 0, 0x9A95),
    L2(5, 14, 0, 0, 0, 0, 0, 0x9A90),
    L2(5, 14, 0, 0, 0, 0, 0, 0x9A91),
    L2(5, 14, 0, 0, 0, 0, 0, 0x9A92),
    L2(5, 14, 0, 0, 0, 0, 0, 0x9A93),
    L2(5, 14, 0, 0, 0, 0, 0, 0x9A94),
    L2(5, 14, 0, 0, 0, 0, 0, 0x9A95),
    L2(6, 14, 0, 0, 0, 0, 0, 0x9A90),
    L2(6, 14, 0, 0, 0, 0, 0, 0x9A91),
    L2(6, 15, 0, 0, 0, 0, 0, 0x9A92),
    L2(6, 15, 0, 0, 0, 0, 0, 0x9A93),
    L2(6, 15, 0, 0, 0, 0, 0, 0x9A94),
    L2(6, 16, 0, 0, 0, 0, 0, 0x9A95),
    L2(7, 16, 0, 0, 0, 0, 0, 0x9A90),
    L2(7, 16, 0, 0, 0, 0, 0, 0x9A91),
    L2(7, 17, 0, 0, 0, 0, 0, 0x9A92),
    L2(7, 17, 0, 0, 0, 0, 0, 0x9A93),
    L2(7, 18, 0, 0, 0, 0, 0, 0x9A94),
    L2(8, 18, 0, 0, 0, 0, 0, 0x9A95),
    L2(8, 19, 0, 0, 0, 0, 0, 0x9A90),
    L2(8, 19, 0, 0, 0, 0, 0, 0x9A91),
    L2(8, 19, 0, 0, 0, 0, 0, 0x9A92),
    L2(8, 20, 0, 0, 0, 0, 0, 0x9A93),
    L2(8, 21, 0, 0, 0, 0, 0, 0x9A94),
    L2(9, 22, 0, 0, 0, 0, 0, 0x9A95),
    L2(9, 23, 0, 0, 0, 0, 0, 0x9A90),
    L2(9, 24, 0, 0, 0, 0, 0, 0x9A91),
    L2(9, 25, 0, 0, 0, 0, 0, 0x9A92),
    L2(9, 26, 0, 0, 0, 0, 0, 0x9A93),
    L2(9, 27, 0, 0, 0, 0, 0, 0x9A94),
    L2(10, 28, 0, 0, 0, 0, 0, 0x9A95),
    L2(10, 29, 0, 0, 0, 0, 0, 0x9A90),
    L2(10, 30, 0, 0, 0, 0, 0, 0x9A91),
    L2(10, 31, 0, 0, 0, 0, 0, 0x9A92),
    L2(10, 32, 0, 0, 0, 0, 0, 0x9A93),
    L2(10, 33, 0, 0, 0, 0, 0, 0x9A94),
    L2(11, 34, 0, 0, 0, 0, 0, 0x9A95),
    L2(11, 34, 0, 0, 0, 0, 0, 0x9A90),
    L2(11, 34, 0, 0, 0, 0, 0, 0x9A91),
    L2(11, 34, 0, 0, 0, 0, 0, 0x9A92),
    L2(11, 34, 0, 0, 0, 0, 0, 0x9A93),
    L2(11, 34, 0, 0, 0, 0, 0, 0x9A94),
    L2(11, 34, 0, 0, 0, 0, 0, 0x9A95),
    L2(12, 34, 0, 0, 0, 0, 0, 0x9A90),
    L2(12, 34, 0, 0, 0, 0, 0, 0x9A91),
    L2(12, 34, 0, 0, 0, 0, 0, 0x9A92),
    L2(12, 34, 0, 0, 0, 0, 0, 0x9A93),
    L2(12, 34, 0, 0, 0, 0, 0, 0x9A94),
    L2(12, 34, 0, 0, 0, 0, 0, 0x9A95),
    L2(12, 99, 0, 0, 0, 0, 0, 0x9A95),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stage_char_06356D60_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stage_char_06356D60_001[176] = {
    L2(1, 13, 0, 0, 0, 0, 0, 0x9A96),
    L2(1, 13, 0, 0, 0, 0, 0, 0x9A97),
    L2(1, 13, 0, 0, 0, 0, 0, 0x9A98),
    L2(1, 13, 0, 0, 0, 0, 0, 0x9A99),
    L2(2, 13, 0, 0, 0, 0, 0, 0x9A9A),
    L2(2, 13, 0, 0, 0, 0, 0, 0x9A9B),
    L2(2, 14, 0, 0, 0, 0, 0, 0x9A96),
    L2(2, 14, 0, 0, 0, 0, 0, 0x9A97),
    L2(2, 14, 0, 0, 0, 0, 0, 0x9A98),
    L2(2, 14, 0, 0, 0, 0, 0, 0x9A99),
    L2(2, 14, 0, 0, 0, 0, 0, 0x9A9A),
    L2(3, 14, 0, 0, 0, 0, 0, 0x9A9B),
    L2(3, 15, 0, 0, 0, 0, 0, 0x9A96),
    L2(4, 15, 0, 0, 0, 0, 0, 0x9A97),
    L2(4, 15, 0, 0, 0, 0, 0, 0x9A98),
    L2(4, 15, 0, 0, 0, 0, 0, 0x9A99),
    L2(4, 16, 0, 0, 0, 0, 0, 0x9A9A),
    L2(5, 16, 0, 0, 0, 0, 0, 0x9A9B),
    L2(5, 17, 0, 0, 0, 0, 0, 0x9A96),
    L2(5, 17, 0, 0, 0, 0, 0, 0x9A97),
    L2(5, 18, 0, 0, 0, 0, 0, 0x9A98),
    L2(6, 18, 0, 0, 0, 0, 0, 0x9A99),
    L2(6, 19, 0, 0, 0, 0, 0, 0x9A9A),
    L2(6, 19, 0, 0, 0, 0, 0, 0x9A9B),
    L2(6, 20, 0, 0, 0, 0, 0, 0x9A96),
    L2(7, 20, 0, 0, 0, 0, 0, 0x9A97),
    L2(7, 21, 0, 0, 0, 0, 0, 0x9A98),
    L2(7, 21, 0, 0, 0, 0, 0, 0x9A99),
    L2(7, 22, 0, 0, 0, 0, 0, 0x9A9A),
    L2(8, 22, 0, 0, 0, 0, 0, 0x9A9B),
    L2(8, 23, 0, 0, 0, 0, 0, 0x9A96),
    L2(8, 24, 0, 0, 0, 0, 0, 0x9A97),
    L2(8, 25, 0, 0, 0, 0, 0, 0x9A98),
    L2(9, 26, 0, 0, 0, 0, 0, 0x9A99),
    L2(9, 27, 0, 0, 0, 0, 0, 0x9A9A),
    L2(9, 28, 0, 0, 0, 0, 0, 0x9A9B),
    L2(10, 29, 0, 0, 0, 0, 0, 0x9A96),
    L2(10, 30, 0, 0, 0, 0, 0, 0x9A97),
    L2(10, 31, 0, 0, 0, 0, 0, 0x9A98),
    L2(10, 32, 0, 0, 0, 0, 0, 0x9A99),
    L2(10, 33, 0, 0, 0, 0, 0, 0x9A9A),
    L2(10, 34, 0, 0, 0, 0, 0, 0x9A9B),
    L2(10, 99, 0, 0, 0, 0, 0, 0x9A9B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stage_char_06356D60_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stage_char_06356D60_002[40] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF38),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF39),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF3A),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF38),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF39),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF3A),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF38),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF39),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF3A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stage_char_06356D60_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stage_char_06356D60_003[40] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF3B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF3C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF3D),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF3B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF3C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF3D),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF3B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF3C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xAF3D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stage_char_06356D60_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stage_char_06356D60_004[16] = {
    L2(18, 0, 0, 0, 0, 0, 0, 0xAF40),
    L2(18, 0, 0, 0, 0, 0, 0, 0xAF41),
    L2(18, 0, 0, 0, 0, 0, 0, 0xAF42),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 stage_char_06356D60_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 stage_char_06356D60_005[16] = {
    L2(18, 0, 0, 0, 0, 0, 0, 0xAF43),
    L2(18, 0, 0, 0, 0, 0, 0, 0xAF44),
    L2(18, 0, 0, 0, 0, 0, 0, 0xAF45),
    CMD(CM_ROA, 0, 0, 0),
};
