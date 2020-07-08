#ifndef _AngleFilter_H
#define _AngleFilter_H

#include "headfile.h"

#define AccValue 0.00006
#define GyroValue 0.06
#define PI 3.1415926
#define K1 0.02
/****************陀螺仪结构体*************************/
typedef struct Angle{
  float gyrox;          //x轴角加速度
  float gyroy;          //y轴角加速度
  float gyroz;          //z轴角加速度
  float accx;           //x轴加速度
  float accy;           //y轴加速度
  float accz;           //z轴加速度
  float zero[6];        //3轴角加速度和加速度的零点采样
  float offang;          //角度的零点
  float angle;          //融合的角度
}Angle;
/**********互补滤波*************/
void Complementary_Filter(float Accel,float Gyro);
/********获取6050数据***********/
void GetMpu6050();

extern struct Angle mpu6050;
#endif