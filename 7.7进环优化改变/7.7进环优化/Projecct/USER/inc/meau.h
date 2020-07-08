#ifndef _meau_H
#define _meau_H
#include "headfile.h"
/**变量外部调用***/
extern int moshi;
extern int pagenum;
extern int pagemax;
extern int pagemin;
extern int tabnum;
extern int tabmax;
extern int tabmin;
extern int lian;
extern int clear;
extern int erase;
extern int8 dw;
/**********/
/*****选中的标记****/
#define tab "*"
/**宏定义**/
/*五项按键*/
#define DOWN !gpio_get(C2)  //C2
#define UP !gpio_get(B5)    //B5
#define TURN_LEFT !gpio_get(C3) //C3
#define TURN_RIGHT !gpio_get(E6) //E5
#define Center !gpio_get(E5) //E6
/*delay*/
#define DELAY_KEY               300
#define DELAY_KEY_FAST          50
#define Signal_KEY {BEEP(1);systick_delay_ms(1);BEEP(0);}

/*************************************************/
/*标题宏定义*/
#define title1 "meau_one"
#define title2 "meau_two"
#define title3 "meau_three"
#define title4 "meau_four"
#define title5 "meau_five"
#define title6 "meau_six"
#define title7 "meau_seven"
#define title8 "meau_eight"
#define title9 "meau_nine"
#define title10 "meau_ten"
/*********************/
/*菜单一选项标题*/
#define title1_1 "left2"
#define title1_2 "left1"
#define title1_3 "middle"
#define title1_4 "right1"
#define title1_5 "right2"
#define title1_6 "DW"
#define title1_7 "offset"
/*菜单二选项标题*/
#define title2_1 "speed"
#define title2_2 "kp"
#define title2_3 "test"
#define title2_4 "leftnum"
#define title2_5 "righnum"
#define title2_6 "earse"
#define title2_7 "tof"
/*菜单三选项标题*/
#define title3_1 "Threshold_L2"
#define title3_2 "Threshold_L1"
#define title3_3 "Threshold_M"
#define title3_4 "Threshold_R1"
#define title3_5 "Threshold_R2"
#define title3_6 "DirLeftValue"
#define title3_7 "DirRightValue"
/*菜单四选项标题*/
#define title4_1 "roundone"
#define title4_2 "roundtwo"
#define title4_3 "roundthree"
#define title4_4 "roundfour"
#define title4_5 "nextime"
#define title4_6 "roundnum"
#define title4_7 "YesorNo"
/*菜单五选项标题*/
#define title5_1 "endset"
#define title5_2 "endis"
#define title5_3 "firofset"
#define title5_4 "secofset"
#define title5_5 "firdis"
#define title5_6 "dirdis"
#define title5_7 "secdis"
/*菜单六选项标题*/
#define title6_1 "getdis"
#define title6_2 "maxtf"
#define title6_3 "tofmode"
#define title6_4 "tofnum"
#define title6_5 "tofone"
#define title6_6 "toftwo"
#define title6_7 "tofdir"

/*菜单七选项标题*/
#define title7_1 "Uset"
#define title7_2 "Sset"
#define title7_3 "Unow"
#define title7_4 "Threshold_Po"
#define title7_5 "tofstartime"
#define title7_6 "toftaget"
#define title7_7 "tofspeed"
/*菜单八选项标题*/
#define title8_1 "speed0"
#define title8_2 "speed1"
#define title8_3 "speed2"
#define title8_4 "speed3"
#define title8_5 "speed4"
#define title8_6 "speed5"
#define title8_7 "speed6"
/*菜单九选项标题*/
#define title9_1 "duoji_P1"
#define title9_2 "duoji_P2"
#define title9_3 "duoji_P3"
#define title9_4 "duoji_P4"
#define title9_5 "duoji_P5"
#define title9_6 "duoji_P6"
/*菜单十选项标题*/
#define title10_1 "duoji_D1"
#define title10_2 "duoji_D2"
#define title10_3 "duoji_D3"
#define title10_4 "duoji_D4"
#define title10_5 "duoji_D5"
#define title10_6 "duoji_D6"
/**********************/
/*菜单标题值的宏定义*/
/*one*/
#define value1_1 inductance.Left2
#define value1_2 inductance.Left1
#define value1_3 inductance.middle
#define value1_4 inductance.Right1
#define value1_5 inductance.Right2
#define value1_6 dw
#define value1_7 Offset.offset
/*two*/
#define value2_1 speed.goal
#define value2_2 turn.p
#define value2_3 tiaoshi
#define value2_4 speed.Lnum
#define value2_5 speed.Rnum
#define value2_6 erase
#define value2_7 inductance.Tof
/*three*/
#define value3_1 Round.Threshold[0]
#define value3_2 Round.Threshold[1]
#define value3_3 Round.Threshold[2]
#define value3_4 Round.Threshold[3]
#define value3_5 Round.Threshold[4]
#define value3_6 Round.DirectLeftValue
#define value3_7 Round.DirectRightValue
/*four*/
#define value4_1 Round.Size[0] 
#define value4_2 Round.Size[1] 
#define value4_3 Round.Size[2] 
#define value4_4 Round.Size[3] 
#define value4_5 Round.nexttime 
#define value4_6 Round.Num
#define value4_7 Round.Mode
/*five*/
#define value5_1 tof.end
#define value5_2 tof.dis
#define value5_3 tof.first
#define value5_4 tof.second
#define value5_5 tof.dis1
#define value5_6 tof.dis2
#define value5_7 tof.dis3
/*six*/
#define value6_1 tof.flag
#define value6_2 tof.max
#define value6_3 tof.mode
#define value6_4 tof.num
#define value6_5 tof.correct[0]
#define value6_6 tof.correct[1]
#define value6_7 tof.dir
/*seven*/
#define value7_1 U
#define value7_2 stop_s 
#define value7_3 test
#define value7_4 tof.podao
#define value7_5 tof.start
#define value7_6 tof.target
#define value7_7 tof.speed
/*eight*/
#define value8_1 speed.want[0]
#define value8_2 speed.want[1]
#define value8_3 speed.want[2]
#define value8_4 speed.want[3]
#define value8_5 speed.want[4]
#define value8_6 speed.want[5]
#define value8_7 speed.want[6]
/*nine*/
#define value9_1 turn.p_d[0]
#define value9_2 turn.p_d[1]
#define value9_3 turn.p_d[2]
#define value9_4 turn.p_d[3]
#define value9_5 turn.p_d[4]
#define value9_6 turn.p_d[5]

/*ten*/
#define value10_1 turn.d_d[0]
#define value10_2 turn.d_d[1]
#define value10_3 turn.d_d[2]
#define value10_4 turn.d_d[3]
#define value10_5 turn.d_d[4]
#define value10_6 turn.d_d[5]


/**************************/
/*Flash写入函数宏定义*/
#define flashWrite1_6 Flash_Write_Int(191,value1_6)

#define flashWrite2_1 Flash_Write_Int(255,value2_1)
#define flashWrite2_2 Flash_Write_Float(254,value2_2)
#define flashWrite2_3 Flash_Write_Int(253,value2_3)
#define flashWrite2_4 Flash_Write_Int(252,value2_4)
#define flashWrite2_5 Flash_Write_Int(251,value2_5)
#define flashWrite2_6 Flash_Write_Int(250,value2_6)

#define flashWrite3_1 Flash_Write_Int(249,value3_1)
#define flashWrite3_2 Flash_Write_Int(248,value3_2)
#define flashWrite3_3 Flash_Write_Int(247,value3_3)
#define flashWrite3_4 Flash_Write_Int(246,value3_4)
#define flashWrite3_5 Flash_Write_Int(245,value3_5)
#define flashWrite3_6 Flash_Write_Float(244,value3_6)
#define flashWrite3_7 Flash_Write_Float(243,value3_7)

#define flashWrite4_1 Flash_Write_Int(242,value4_1)
#define flashWrite4_2 Flash_Write_Int(241,value4_2)
#define flashWrite4_3 Flash_Write_Int(240,value4_3)
#define flashWrite4_4 Flash_Write_Int(239,value4_4)
#define flashWrite4_5 Flash_Write_Int(238,value4_5)
#define flashWrite4_6 Flash_Write_Int(237,value4_6)
#define flashWrite4_7 Flash_Write_Int(236,value4_7)

#define flashWrite5_1 Flash_Write_Float(229,value5_1)
#define flashWrite5_2 Flash_Write_Int(235,value5_2)
#define flashWrite5_3 Flash_Write_Float(234,value5_3)
#define flashWrite5_4 Flash_Write_Float(233,value5_4)
#define flashWrite5_5 Flash_Write_Int(232,value5_5)
#define flashWrite5_6 Flash_Write_Int(231,value5_6)
#define flashWrite5_7 Flash_Write_Int(230,value5_7)

#define flashWrite6_2 Flash_Write_Int(192,value6_2)
#define flashWrite6_3 Flash_Write_Int(228,value6_3)
#define flashWrite6_4 Flash_Write_Int(227,value6_4)
#define flashWrite6_5 Flash_Write_Int(226,value6_5)
#define flashWrite6_6 Flash_Write_Int(225,value6_6)
#define flashWrite6_7 Flash_Write_Int(224,value6_7)

#define flashWrite7_1 Flash_Write_Float(223,value7_1)
#define flashWrite7_2 Flash_Write_Int(222,value7_2)
#define flashWrite7_3 Flash_Write_Int(206,value7_3)
#define flashWrite7_4 Flash_Write_Int(205,value7_4)
#define flashWrite7_5 Flash_Write_Int(201,value7_5)
#define flashWrite7_6 Flash_Write_Int(200,value7_6)
#define flashWrite7_7 Flash_Write_Int(199,value7_7)

#define flashWrite8_1 Flash_Write_Int(219,value8_1)
#define flashWrite8_2 Flash_Write_Int(218,value8_2)
#define flashWrite8_3 Flash_Write_Int(217,value8_3)
#define flashWrite8_4 Flash_Write_Int(216,value8_4)
#define flashWrite8_5 Flash_Write_Int(215,value8_5)
#define flashWrite8_6 Flash_Write_Int(214,value8_6)
#define flashWrite8_7 Flash_Write_Int(213,value8_7)

#define flashWrite9_1 Flash_Write_Int(212,value9_1)
#define flashWrite9_2 Flash_Write_Int(211,value9_2)
#define flashWrite9_3 Flash_Write_Int(210,value9_3)
#define flashWrite9_4 Flash_Write_Int(209,value9_4)
#define flashWrite9_5 Flash_Write_Int(208,value9_5)
#define flashWrite9_6 Flash_Write_Int(207,value9_6)

#define flashWrite10_1 Flash_Write_Float(198,value10_1)
#define flashWrite10_2 Flash_Write_Float(197,value10_2)
#define flashWrite10_3 Flash_Write_Float(196,value10_3)
#define flashWrite10_4 Flash_Write_Float(195,value10_4)
#define flashWrite10_5 Flash_Write_Float(194,value10_5)
#define flashWrite10_6 Flash_Write_Float(193,value10_6)

/*Flash读出函数宏定义*/
#define flashread1_6 Flash_Read_Int(191)

#define flashread2_1 Flash_Read_Int(255)
#define flashread2_2 Flash_Read_Float(254)
#define flashread2_3 Flash_Read_Int(253)
#define flashread2_4 Flash_Read_Int(252)
#define flashread2_5 Flash_Read_Int(251)
#define flashread2_6 Flash_Read_Int(250)

#define flashread3_1 Flash_Read_Int(249)
#define flashread3_2 Flash_Read_Int(248)
#define flashread3_3 Flash_Read_Int(247)
#define flashread3_4 Flash_Read_Int(246)
#define flashread3_5 Flash_Read_Int(245)
#define flashread3_6 Flash_Read_Float(244)
#define flashread3_7 Flash_Read_Float(243)

#define flashread4_1 Flash_Read_Int(242)
#define flashread4_2 Flash_Read_Int(241)
#define flashread4_3 Flash_Read_Int(240)
#define flashread4_4 Flash_Read_Int(239)
#define flashread4_5 Flash_Read_Int(238)
#define flashread4_6 Flash_Read_Int(237)
#define flashread4_7 Flash_Read_Int(236)

#define flashread5_1 Flash_Read_Float(229)
#define flashread5_2 Flash_Read_Int(235)
#define flashread5_3 Flash_Read_Float(234)
#define flashread5_4 Flash_Read_Float(233)
#define flashread5_5 Flash_Read_Int(232)
#define flashread5_6 Flash_Read_Int(231)
#define flashread5_7 Flash_Read_Int(230)

#define flashread6_2 Flash_Read_Int(192)
#define flashread6_3 Flash_Read_Int(228)
#define flashread6_4 Flash_Read_Int(227)
#define flashread6_5 Flash_Read_Int(226)
#define flashread6_6 Flash_Read_Int(225)
#define flashread6_7 Flash_Read_Int(224)

#define flashread7_1 Flash_Read_Float(223)
#define flashread7_2 Flash_Read_Int(222)
#define flashread7_3 Flash_Read_Int(206)
#define flashread7_4 Flash_Read_Int(205)
#define flashread7_5 Flash_Read_Int(201)
#define flashread7_6 Flash_Read_Int(200)
#define flashread7_7 Flash_Read_Int(199)

#define flashread8_1 Flash_Read_Int(219)
#define flashread8_2 Flash_Read_Int(218)
#define flashread8_3 Flash_Read_Int(217)
#define flashread8_4 Flash_Read_Int(216)
#define flashread8_5 Flash_Read_Int(215)
#define flashread8_6 Flash_Read_Int(214)
#define flashread8_7 Flash_Read_Int(213)

#define flashread9_1 Flash_Read_Int(212)
#define flashread9_2 Flash_Read_Int(211)
#define flashread9_3 Flash_Read_Int(210)
#define flashread9_4 Flash_Read_Int(209)
#define flashread9_5 Flash_Read_Int(208)
#define flashread9_6 Flash_Read_Int(207)

#define flashread10_1 Flash_Read_Float(198)
#define flashread10_2 Flash_Read_Float(197)
#define flashread10_3 Flash_Read_Float(196)
#define flashread10_4 Flash_Read_Float(195)
#define flashread10_5 Flash_Read_Float(194)
#define flashread10_6 Flash_Read_Float(193)

//#define flashread10_2 Flash_Read_Float(204)
//#define flashread10_4 Flash_Read_Float(203)
//#define flashread10_6 Flash_Read_Float(202)
/**************************************/
/**参数限幅宏定义**/
/*one*/
#define ms1_6max 3
#define ms1_6min 0
/*two*/
#define ms2_1max 800
#define ms2_1min 0
#define ms2_2max 100
#define ms2_2min 10
#define ms2_3max 1
#define ms2_3min 0
#define ms2_4max 1000
#define ms2_4min 0
#define ms2_5max 1000
#define ms2_5min 0
#define ms2_6max 1
#define ms2_6min 0
/***********************/
/*three*/
#define ms3_1max 250
#define ms3_1min 1
#define ms3_2max 250
#define ms3_2min 1
#define ms3_3max 250
#define ms3_3min 1
#define ms3_4max 250
#define ms3_4min 1
#define ms3_5max 250
#define ms3_5min 1
#define ms3_6max 5
#define ms3_6min 1
#define ms3_7max 5
#define ms3_7min 1
/**********************/
/*four*/
#define ms4_1max 2
#define ms4_1min 1
#define ms4_2max 2
#define ms4_2min 1
#define ms4_3max 2
#define ms4_3min 1
#define ms4_4max 2
#define ms4_4min 1
#define ms4_5max 20
#define ms4_5min 1
#define ms4_6max 5
#define ms4_6min 1
#define ms4_7max 1
#define ms4_7min 0
/**********************/
/*five*/
#define ms5_1max 1
#define ms5_1min -1
#define ms5_2max 100
#define ms5_2min 1
#define ms5_3max 1
#define ms5_3min -1
#define ms5_4max 1
#define ms5_4min -1
#define ms5_5max 100
#define ms5_5min 10
#define ms5_6max 100
#define ms5_6min 10
#define ms5_7max 200
#define ms5_7min 20
/**********************/
/*six*/
#define ms6_1max 5
#define ms6_1min 0
#define ms6_2max 100
#define ms6_2min 30
#define ms6_3max 1
#define ms6_3min 0
#define ms6_4max 10
#define ms6_4min 1
#define ms6_5max 10
#define ms6_5min 0
#define ms6_6max 10
#define ms6_6min 0
#define ms6_7max 22
#define ms6_7min 11
/**********************/
/*seven*/
#define ms7_1max 12
#define ms7_1min 1
#define ms7_2max 50
#define ms7_2min 1
#define ms7_4max 200
#define ms7_4min 100
#define ms7_5max 50
#define ms7_5min 1
#define ms7_6max 30
#define ms7_6min 1
#define ms7_7max 100
#define ms7_7min 1
/**********************/
/*eight*/
#define ms8_1max 990
#define ms8_1min 10
#define ms8_2max 990
#define ms8_2min 10
#define ms8_3max 990
#define ms8_3min 10
#define ms8_4max 990
#define ms8_4min 10
#define ms8_5max 990
#define ms8_5min 10
#define ms8_6max 990
#define ms8_6min 10
#define ms8_7max 990
#define ms8_7min 10
/**********************/
/*nine*/
#define ms9_1max 990
#define ms9_1min 1
#define ms9_2max 990
#define ms9_2min 1
#define ms9_3max 990
#define ms9_3min 1
#define ms9_4max 990
#define ms9_4min 1
#define ms9_5max 990
#define ms9_5min 1
#define ms9_6max 990
#define ms9_6min 1
/********************/
/*nine*/
#define ms10_1max 25
#define ms10_1min -25
#define ms10_2max 25
#define ms10_2min -25
#define ms10_3max 25
#define ms10_3min -25
#define ms10_4max 25
#define ms10_4min -25
#define ms10_5max 25
#define ms10_5min -25
#define ms10_6max 25
#define ms10_6min -25
/********************/
/**函数**/
void FlashReadData(void);//flash 存储
void BootInit();//初始化

void meanu();//标题
void valuedisplay();//数值的显示
void anjian();//键盘改变
/*控制加减的函数*/
void oneadd();
void twoadd();
void threeadd();
void fouradd();
void fiveadd();
void sixadd();
void sevenadd();
void eightadd();
void nineadd();
void tenadd();

void onesub();
void twosub();
void threesub();
void foursub();
void fivesub();
void sixsub();
void sevensub();
void eightsub();
void ninesub();
void tensub();
/*限幅的函数*/
void oneLimit();
void twoLimit();
void threeLimit();
void fourLimit();
void fiveLimit();
void sixLimit();
void sevenLimit();
void eightLimit();
void nineLimit();
void tenLimit();
#endif