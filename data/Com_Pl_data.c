/*
 * COM_PL_DATA.C  CPU opponent lists and computer player vitality
 *
 * EM_Candidate_Data gives the eight CPU opponents of each character on each of four courses;
 * EM_CAND.C copies them into the player's opponent list, SEL_PL.C reads the next opponent from
 * it and END_6.C (Hugo's ending) chooses its scene and message by the eighth opponent of Hugo's
 * course. Com_Vital_Unit_Data is the starting vitality by character, damage setting and level,
 * read by setup_vitality in PLS02.C.
 */

#include "types.h"
#include "structs.h"
#include "fighter.h"

#pragma section TBL

extern const u8 EM_Candidate_Data[][4][8];
extern const s16 Com_Vital_Unit_Data[][4][12];

const u8 EM_Candidate_Data[16][4][8] = {
    {  /* Gill */
        { PL_YANG, PL_NECRO, PL_ELENA, PL_ORO, PL_IBUKI, PL_HUGO, PL_GILL, PL_RYU },
        { PL_DUDLEY, PL_KEN, PL_HUGO, PL_ALEX, PL_URIEN, PL_YUN, PL_GILL, PL_RYU },
        { PL_ORO, PL_URIEN, PL_ALEX, PL_NECRO, PL_KEN, PL_DUDLEY, PL_GILL, PL_RYU },
        { PL_HUGO, PL_YUN, PL_URIEN, PL_KEN, PL_ELENA, PL_ORO, PL_GILL, PL_RYU },
    },
    {  /* Alex */
        { PL_RYU, PL_YANG, PL_DUDLEY, PL_NECRO, PL_IBUKI, PL_ELENA, PL_HUGO, PL_GILL },
        { PL_URIEN, PL_SEAN, PL_YUN, PL_ORO, PL_ELENA, PL_IBUKI, PL_HUGO, PL_GILL },
        { PL_DUDLEY, PL_RYU, PL_URIEN, PL_SEAN, PL_NECRO, PL_ORO, PL_HUGO, PL_GILL },
        { PL_NECRO, PL_URIEN, PL_IBUKI, PL_DUDLEY, PL_RYU, PL_ALEX, PL_HUGO, PL_GILL },
    },
    {  /* Ryu */
        { PL_YANG, PL_DUDLEY, PL_NECRO, PL_IBUKI, PL_ELENA, PL_ORO, PL_GILL, PL_KEN },
        { PL_ALEX, PL_URIEN, PL_ORO, PL_YUN, PL_HUGO, PL_ELENA, PL_GILL, PL_KEN },
        { PL_NECRO, PL_IBUKI, PL_URIEN, PL_HUGO, PL_DUDLEY, PL_ALEX, PL_GILL, PL_KEN },
        { PL_ORO, PL_HUGO, PL_ALEX, PL_ELENA, PL_YANG, PL_RYU, PL_GILL, PL_KEN },
    },
    {  /* Yun */
        { PL_DUDLEY, PL_HUGO, PL_IBUKI, PL_ELENA, PL_NECRO, PL_KEN, PL_GILL, PL_YANG },
        { PL_RYU, PL_ALEX, PL_HUGO, PL_SEAN, PL_KEN, PL_ORO, PL_GILL, PL_YANG },
        { PL_HUGO, PL_ELENA, PL_SEAN, PL_ORO, PL_ALEX, PL_RYU, PL_GILL, PL_YANG },
        { PL_KEN, PL_ORO, PL_NECRO, PL_HUGO, PL_IBUKI, PL_YUN, PL_GILL, PL_YANG },
    },
    {  /* Dudley */
        { PL_NECRO, PL_IBUKI, PL_YANG, PL_ORO, PL_SEAN, PL_RYU, PL_KEN, PL_GILL },
        { PL_URIEN, PL_YUN, PL_ALEX, PL_SEAN, PL_ELENA, PL_ORO, PL_KEN, PL_GILL },
        { PL_ELENA, PL_URIEN, PL_IBUKI, PL_NECRO, PL_RYU, PL_ALEX, PL_KEN, PL_GILL },
        { PL_YANG, PL_SEAN, PL_ELENA, PL_YUN, PL_IBUKI, PL_DUDLEY, PL_KEN, PL_GILL },
    },
    {  /* Necro */
        { PL_YANG, PL_SEAN, PL_ORO, PL_HUGO, PL_ELENA, PL_URIEN, PL_KEN, PL_GILL },
        { PL_DUDLEY, PL_URIEN, PL_RYU, PL_ALEX, PL_SEAN, PL_YUN, PL_KEN, PL_GILL },
        { PL_ORO, PL_RYU, PL_HUGO, PL_ELENA, PL_ALEX, PL_DUDLEY, PL_KEN, PL_GILL },
        { PL_URIEN, PL_ALEX, PL_DUDLEY, PL_RYU, PL_ORO, PL_NECRO, PL_KEN, PL_GILL },
    },
    {  /* Hugo */
        { PL_IBUKI, PL_ORO, PL_YANG, PL_SEAN, PL_URIEN, PL_ALEX, PL_GILL, PL_NECRO },
        { PL_ELENA, PL_URIEN, PL_DUDLEY, PL_IBUKI, PL_ALEX, PL_KEN, PL_GILL, PL_RYU },
        { PL_URIEN, PL_SEAN, PL_ORO, PL_NECRO, PL_DUDLEY, PL_IBUKI, PL_GILL, PL_ELENA },
        { PL_DUDLEY, PL_YANG, PL_ALEX, PL_SEAN, PL_IBUKI, PL_HUGO, PL_KEN, PL_GILL },
    },
    {  /* Ibuki */
        { PL_ORO, PL_YANG, PL_DUDLEY, PL_RYU, PL_ALEX, PL_URIEN, PL_KEN, PL_GILL },
        { PL_URIEN, PL_NECRO, PL_SEAN, PL_YUN, PL_RYU, PL_ALEX, PL_KEN, PL_GILL },
        { PL_SEAN, PL_ORO, PL_URIEN, PL_DUDLEY, PL_NECRO, PL_HUGO, PL_KEN, PL_GILL },
        { PL_YUN, PL_HUGO, PL_RYU, PL_NECRO, PL_ORO, PL_IBUKI, PL_KEN, PL_GILL },
    },
    {  /* Elena */
        { PL_ORO, PL_SEAN, PL_URIEN, PL_ALEX, PL_HUGO, PL_YUN, PL_KEN, PL_GILL },
        { PL_YANG, PL_IBUKI, PL_NECRO, PL_HUGO, PL_ALEX, PL_DUDLEY, PL_KEN, PL_GILL },
        { PL_NECRO, PL_HUGO, PL_DUDLEY, PL_SEAN, PL_IBUKI, PL_ORO, PL_KEN, PL_GILL },
        { PL_DUDLEY, PL_YANG, PL_SEAN, PL_IBUKI, PL_URIEN, PL_ELENA, PL_KEN, PL_GILL },
    },
    {  /* Oro */
        { PL_SEAN, PL_URIEN, PL_ALEX, PL_KEN, PL_YUN, PL_DUDLEY, PL_RYU, PL_GILL },
        { PL_YANG, PL_IBUKI, PL_KEN, PL_HUGO, PL_DUDLEY, PL_ELENA, PL_RYU, PL_GILL },
        { PL_ALEX, PL_DUDLEY, PL_HUGO, PL_SEAN, PL_ELENA, PL_URIEN, PL_RYU, PL_GILL },
        { PL_HUGO, PL_ELENA, PL_YUN, PL_ALEX, PL_SEAN, PL_ORO, PL_RYU, PL_GILL },
    },
    {  /* Yang */
        { PL_URIEN, PL_ALEX, PL_RYU, PL_DUDLEY, PL_NECRO, PL_IBUKI, PL_GILL, PL_YUN },
        { PL_SEAN, PL_KEN, PL_HUGO, PL_ELENA, PL_IBUKI, PL_NECRO, PL_GILL, PL_YUN },
        { PL_ELENA, PL_URIEN, PL_SEAN, PL_ALEX, PL_RYU, PL_DUDLEY, PL_GILL, PL_YUN },
        { PL_HUGO, PL_SEAN, PL_ELENA, PL_KEN, PL_URIEN, PL_YANG, PL_GILL, PL_YUN },
    },
    {  /* Ken */
        { PL_ALEX, PL_YUN, PL_HUGO, PL_NECRO, PL_IBUKI, PL_ELENA, PL_GILL, PL_RYU },
        { PL_URIEN, PL_SEAN, PL_YANG, PL_ORO, PL_ELENA, PL_IBUKI, PL_GILL, PL_RYU },
        { PL_HUGO, PL_ORO, PL_NECRO, PL_SEAN, PL_URIEN, PL_ALEX, PL_GILL, PL_RYU },
        { PL_SEAN, PL_NECRO, PL_URIEN, PL_ALEX, PL_IBUKI, PL_KEN, PL_GILL, PL_RYU },
    },
    {  /* Sean */
        { PL_YUN, PL_URIEN, PL_NECRO, PL_IBUKI, PL_ELENA, PL_ORO, PL_GILL, PL_KEN },
        { PL_RYU, PL_ALEX, PL_HUGO, PL_DUDLEY, PL_ORO, PL_ELENA, PL_GILL, PL_KEN },
        { PL_URIEN, PL_IBUKI, PL_DUDLEY, PL_NECRO, PL_RYU, PL_ALEX, PL_GILL, PL_KEN },
        { PL_ORO, PL_HUGO, PL_RYU, PL_ELENA, PL_DUDLEY, PL_SEAN, PL_GILL, PL_KEN },
    },
    {  /* Urien */
        { PL_DUDLEY, PL_NECRO, PL_HUGO, PL_ELENA, PL_ORO, PL_YUN, PL_KEN, PL_GILL },
        { PL_YANG, PL_RYU, PL_IBUKI, PL_SEAN, PL_NECRO, PL_ORO, PL_KEN, PL_GILL },
        { PL_IBUKI, PL_HUGO, PL_SEAN, PL_DUDLEY, PL_ELENA, PL_RYU, PL_KEN, PL_GILL },
        { PL_ORO, PL_YANG, PL_DUDLEY, PL_NECRO, PL_IBUKI, PL_URIEN, PL_KEN, PL_GILL },
    },
    {  /* Gouki */
        { PL_YANG, PL_NECRO, PL_ELENA, PL_ORO, PL_IBUKI, PL_HUGO, PL_GILL, PL_RYU },
        { PL_DUDLEY, PL_KEN, PL_HUGO, PL_ALEX, PL_URIEN, PL_YUN, PL_GILL, PL_RYU },
        { PL_ORO, PL_URIEN, PL_ALEX, PL_NECRO, PL_KEN, PL_DUDLEY, PL_GILL, PL_RYU },
        { PL_HUGO, PL_YUN, PL_URIEN, PL_KEN, PL_ELENA, PL_ORO, PL_GILL, PL_RYU },
    },
    {  /* Shin Gouki */
        { PL_YANG, PL_NECRO, PL_ELENA, PL_ORO, PL_IBUKI, PL_HUGO, PL_GILL, PL_RYU },
        { PL_DUDLEY, PL_KEN, PL_HUGO, PL_ALEX, PL_URIEN, PL_YUN, PL_GILL, PL_RYU },
        { PL_ORO, PL_URIEN, PL_ALEX, PL_NECRO, PL_KEN, PL_DUDLEY, PL_GILL, PL_RYU },
        { PL_HUGO, PL_YUN, PL_URIEN, PL_KEN, PL_ELENA, PL_ORO, PL_GILL, PL_RYU },
    },
};

/* provisional name */
const s16 Com_Vital_Unit_Data[16][4][12] = {
    {  /* Gill */
        { 1402, 1485, 1567, 1650, 1732, 1815, 1897, 1980, 2062, 2145, 2227, 2310 },
        { 935, 990, 1045, 1100, 1155, 1210, 1265, 1320, 1375, 1430, 1485, 1540 },
        { 817, 865, 913, 962, 1010, 1058, 1106, 1154, 1202, 1250, 1298, 1346 },
        { 701, 742, 783, 825, 866, 907, 948, 990, 1031, 1072, 1113, 1155 },
    },
    {  /* Alex */
        { 1491, 1579, 1667, 1755, 1842, 1930, 2018, 2106, 2193, 2281, 2369, 2457 },
        { 994, 1053, 1111, 1170, 1228, 1287, 1345, 1404, 1462, 1521, 1579, 1638 },
        { 869, 920, 971, 1023, 1074, 1125, 1176, 1227, 1278, 1329, 1381, 1432 },
        { 745, 789, 833, 877, 920, 964, 1008, 1052, 1096, 1140, 1183, 1227 },
    },
    {  /* Ryu */
        { 1402, 1485, 1567, 1650, 1732, 1815, 1897, 1980, 2062, 2145, 2227, 2310 },
        { 935, 990, 1045, 1100, 1155, 1210, 1265, 1320, 1375, 1430, 1485, 1540 },
        { 817, 865, 913, 962, 1010, 1058, 1106, 1154, 1202, 1250, 1298, 1346 },
        { 701, 742, 783, 825, 866, 907, 948, 990, 1031, 1072, 1113, 1155 },
    },
    {  /* Yun */
        { 1338, 1417, 1496, 1575, 1653, 1732, 1811, 1890, 1968, 2047, 2126, 2205 },
        { 892, 945, 997, 1050, 1102, 1155, 1207, 1260, 1312, 1365, 1417, 1470 },
        { 780, 826, 872, 918, 963, 1009, 1055, 1101, 1147, 1193, 1239, 1285 },
        { 668, 708, 747, 787, 826, 865, 905, 944, 983, 1023, 1062, 1101 },
    },
    {  /* Dudley */
        { 1402, 1485, 1567, 1650, 1732, 1815, 1897, 1980, 2062, 2145, 2227, 2310 },
        { 935, 990, 1045, 1100, 1155, 1210, 1265, 1320, 1375, 1430, 1485, 1540 },
        { 817, 865, 913, 962, 1010, 1058, 1106, 1154, 1202, 1250, 1298, 1346 },
        { 701, 742, 783, 825, 866, 907, 948, 990, 1031, 1072, 1113, 1155 },
    },
    {  /* Necro */
        { 1402, 1485, 1567, 1650, 1732, 1815, 1897, 1980, 2062, 2145, 2227, 2310 },
        { 935, 990, 1045, 1100, 1155, 1210, 1265, 1320, 1375, 1430, 1485, 1540 },
        { 817, 865, 913, 962, 1010, 1058, 1106, 1154, 1202, 1250, 1298, 1346 },
        { 701, 742, 783, 825, 866, 907, 948, 990, 1031, 1072, 1113, 1155 },
    },
    {  /* Hugo */
        { 1593, 1687, 1781, 1875, 1968, 2062, 2156, 2250, 2343, 2437, 2531, 2625 },
        { 1062, 1125, 1187, 1250, 1312, 1375, 1437, 1500, 1562, 1625, 1687, 1750 },
        { 929, 983, 1038, 1093, 1147, 1202, 1256, 1311, 1366, 1420, 1475, 1530 },
        { 796, 843, 890, 937, 983, 1030, 1077, 1124, 1171, 1218, 1264, 1311 },
    },
    {  /* Ibuki */
        { 1338, 1417, 1496, 1575, 1653, 1732, 1811, 1890, 1968, 2047, 2126, 2205 },
        { 892, 945, 997, 1050, 1102, 1155, 1207, 1260, 1312, 1365, 1417, 1470 },
        { 780, 826, 872, 918, 963, 1009, 1055, 1101, 1147, 1193, 1239, 1285 },
        { 668, 708, 747, 787, 826, 865, 905, 944, 983, 1023, 1062, 1101 },
    },
    {  /* Elena */
        { 1338, 1417, 1496, 1575, 1653, 1732, 1811, 1890, 1968, 2047, 2126, 2205 },
        { 892, 945, 997, 1050, 1102, 1155, 1207, 1260, 1312, 1365, 1417, 1470 },
        { 780, 826, 872, 918, 963, 1009, 1055, 1101, 1147, 1193, 1239, 1285 },
        { 668, 708, 747, 787, 826, 865, 905, 944, 983, 1023, 1062, 1101 },
    },
    {  /* Oro */
        { 1338, 1417, 1496, 1575, 1653, 1732, 1811, 1890, 1968, 2047, 2126, 2205 },
        { 892, 945, 997, 1050, 1102, 1155, 1207, 1260, 1312, 1365, 1417, 1470 },
        { 780, 826, 872, 918, 963, 1009, 1055, 1101, 1147, 1193, 1239, 1285 },
        { 668, 708, 747, 787, 826, 865, 905, 944, 983, 1023, 1062, 1101 },
    },
    {  /* Yang */
        { 1338, 1417, 1496, 1575, 1653, 1732, 1811, 1890, 1968, 2047, 2126, 2205 },
        { 892, 945, 997, 1050, 1102, 1155, 1207, 1260, 1312, 1365, 1417, 1470 },
        { 780, 826, 872, 918, 963, 1009, 1055, 1101, 1147, 1193, 1239, 1285 },
        { 668, 708, 747, 787, 826, 865, 905, 944, 983, 1023, 1062, 1101 },
    },
    {  /* Ken */
        { 1402, 1485, 1567, 1650, 1732, 1815, 1897, 1980, 2062, 2145, 2227, 2310 },
        { 935, 990, 1045, 1100, 1155, 1210, 1265, 1320, 1375, 1430, 1485, 1540 },
        { 817, 865, 913, 962, 1010, 1058, 1106, 1154, 1202, 1250, 1298, 1346 },
        { 701, 742, 783, 825, 866, 907, 948, 990, 1031, 1072, 1113, 1155 },
    },
    {  /* Sean */
        { 1402, 1485, 1567, 1650, 1732, 1815, 1897, 1980, 2062, 2145, 2227, 2310 },
        { 935, 990, 1045, 1100, 1155, 1210, 1265, 1320, 1375, 1430, 1485, 1540 },
        { 817, 865, 913, 962, 1010, 1058, 1106, 1154, 1202, 1250, 1298, 1346 },
        { 701, 742, 783, 825, 866, 907, 948, 990, 1031, 1072, 1113, 1155 },
    },
    {  /* Urien */
        { 1402, 1485, 1567, 1650, 1732, 1815, 1897, 1980, 2062, 2145, 2227, 2310 },
        { 935, 990, 1045, 1100, 1155, 1210, 1265, 1320, 1375, 1430, 1485, 1540 },
        { 817, 865, 913, 962, 1010, 1058, 1106, 1154, 1202, 1250, 1298, 1346 },
        { 701, 742, 783, 825, 866, 907, 948, 990, 1031, 1072, 1113, 1155 },
    },
    {  /* Gouki */
        { 1275, 1350, 1425, 1500, 1575, 1650, 1725, 1800, 1875, 1950, 2025, 2100 },
        { 850, 900, 950, 1000, 1050, 1100, 1150, 1200, 1250, 1300, 1350, 1400 },
        { 743, 787, 831, 875, 918, 962, 1006, 1050, 1093, 1137, 1181, 1225 },
        { 637, 675, 712, 750, 787, 825, 862, 900, 937, 975, 1012, 1050 },
    },
    {  /* Shin Gouki */
        { 1402, 1485, 1567, 1650, 1732, 1815, 1897, 1980, 2062, 2145, 2227, 2310 },
        { 935, 990, 1045, 1100, 1155, 1210, 1265, 1320, 1375, 1430, 1485, 1540 },
        { 817, 865, 913, 962, 1010, 1058, 1106, 1154, 1202, 1250, 1298, 1346 },
        { 701, 742, 783, 825, 866, 907, 948, 990, 1031, 1072, 1113, 1155 },
    },
};
