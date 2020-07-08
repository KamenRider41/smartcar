#ifndef _dispose_H
#define _dispose_H
#include "headfile.h"

#define BEEP(x) gpio_set(D2,x)//蜂鸣器

#define ADC_Left2()  adc_once(ADC0_SE4,ADC_8bit) //B0
#define ADC_Left1()  adc_once(ADC0_SE9,ADC_8bit) //C1
#define ADC_Middle() adc_once(ADC0_SE6,ADC_8bit) //B2
#define ADC_Right1() adc_once(ADC0_SE5,ADC_8bit) //B1
#define ADC_Right2() adc_once(ADC0_SE7,ADC_8bit) //B3
#define ADC_Tof()    adc_once(ADC0_SE12,ADC_8bit)//F4
#define ADC_U()      adc_once(ADC0_SE2,ADC_8bit) //A6



/**************传感器单次采集*****************/
typedef struct Inductance{
  int16 Left2;                     //水平左电感值
  uint8 Left1;                     //垂直左电感值
  uint8 middle;                    //水平中电感值
  uint8 Right1;                    //垂直右电感值
  int16 Right2;                    //水平右电感值
  uint32 Tof;                      //红外距离值
  double v;                       //采集电压值
}Inductance;
/*********************************************/
/****************偏差结构体*************************/
typedef struct Ofset{
  float offset;                   //现在的偏差
  float offset1;                  //偏差1 水平差比和
  float offset2;                  //偏差2 垂直差比和
  int offset3;                    //偏差3 陀螺仪偏差
  float offsetlast;               //上一个偏差
  float Data[4];                  //存放偏差的数组
}Ofset;
/**********************************************/
/****************圆环结构体**************************/
typedef struct Ring{
  uint16 Threshold[5];     //进环阈值 = {90,130,100,130,90}
  uint16 Size[5];          //环的方向= {1,1,2,1,1}
  uint16 timecount;        //=0 控制强制出环
  uint16 OutCount;         //出环计时
  uint8  Mode;             //是否进环
  uint8  BeginFlag;        //开始识别圆环
  uint8  Flag;             //环岛状态标志
  uint8  RunFlag;          //进环标志位
  uint8  SubFlag;          //递减标志位
  uint8  OutFlag;          //出环标志位
  uint8  Direct;           //1:左拐 2：右拐
  uint8  Num;              //一圈的环岛数
  uint8  Location;         //第几个环
  uint8  timeflag;         //计数标志位
  float DirectLeftValue;  //进环左偏差系数
  float DirectRightValue; //进环右偏差系数
  uint8  next;             //下一次进环
  uint8  nexttime;         //下一次进环延时    写进菜单
  uint32  nextcnt;         //下一次进环延时计数
}Ring;
/****************路障结构体**************************/
typedef struct Tof{
  int flag;                //是否检测到路障(开启测距)
  float first;             //出去的第一个偏差
  float second;            //回来的第二个偏差
  int max;                 //tof阈值
  float end;               //回线偏差
  uint32 dis1;             //第一次偏差移动的编码值
  uint32 dis2;             //第一次和第二次之间编码器距离
  uint32 dis3;             //第二次偏差移动的编码值
  uint32 dis4;             //第二次偏差后的直线编码值
  uint32 dis;              //编码器编码值（记录移动的距离）
  int cnt;                 //满足阈值的个数
  int target;              //满足阈值的目标个数
  int mode;                //是否判断路障
  int num;                 //一圈内的路障数，含误判路障
  int nownum;              //路障计数
  int correct[2];          //第几个是真的路障(理论一圈一个，保险写两个)
  int dir;                 //1.左边过  2.右边过
  uint32 maxcnt;           //路障判断间隔
  uint32 timecount;        //路障误判计时
  uint8 podao;             //坡道阈值
  uint8 start;             //tof启动时间
  uint32 toftime;          //tof启动计时
  uint8 speed;             //tof的速度
}Tof;
/*************蜂鸣器结构体***********************/
typedef struct Ding{
  uint8 BeginEnd;          //蜂鸣器标志位
  uint16 Count;            //蜂鸣器计时
}Ding;
/************************************************/
/**********外部调用结构体***********/
extern struct Inductance inductance;//采样值
extern struct Ofset Offset;         //偏差值
extern struct Ring Round;           //圆环值
extern struct Ding bee;             //蜂鸣器
extern struct Tof tof;              //红外传感器
//传感器采集函数
void Average_filtering(void);
//元素识别
void Element_identification(void);
//偏差处理函数
void offset_dispose(void);
#endif