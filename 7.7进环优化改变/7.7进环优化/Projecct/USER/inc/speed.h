#ifndef _speed_H
#define _speed_H

#include "headfile.h"
#define climate 80         //每cm对应的编码值，测量方法很多
//#define gyrozd (mpu6050.angle-mpu6050.offang)<0?(-1)*(mpu6050.angle-mpu6050.offang)/200:(mpu6050.angle-mpu6050.offang)/200
#define gyrozd 1
//#define gyrozd 0
typedef struct Turn{
    int p_d[6];                 //P值
  float d_d[6];                 //d值
  float p;                 //P值
  float d;                 //d值
  float value;             //陀螺仪控制变量
  float Lratio;            //左轮差速系数
  float Rratio;            //右轮差速系数
  float p2;                //P值备份
  int change;              //左右轮基础差速
}Turn;
typedef struct Speed{
    int want[7];                //目标基础速度
  int goal;                //目标基础速度
  int left;                //左轮速度
  int right;               //右轮速度
  int Lnum;                //左轮编码值
  int Rnum;                //右轮编码值
  int Lgoal;               //左轮目标编码值
  int Rgoal;               //右轮目标编码值
  int flag;                //加速标志位
  int pos;                 //大于0偏差计数
  int neg;                 //小于0偏差计数
}Speed;
extern Turn turn;
extern Speed speed;
extern float KD;
void DifferControl(void);
void SpeedControl(void);
void PWM_Above();
void Control();
#endif