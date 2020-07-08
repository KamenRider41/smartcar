#ifndef _AngleFilter_H
#define _AngleFilter_H

#include "headfile.h"

#define AccValue 0.00006
#define GyroValue 0.06
#define PI 3.1415926
#define K1 0.02
/****************�����ǽṹ��*************************/
typedef struct Angle{
  float gyrox;          //x��Ǽ��ٶ�
  float gyroy;          //y��Ǽ��ٶ�
  float gyroz;          //z��Ǽ��ٶ�
  float accx;           //x����ٶ�
  float accy;           //y����ٶ�
  float accz;           //z����ٶ�
  float zero[6];        //3��Ǽ��ٶȺͼ��ٶȵ�������
  float offang;          //�Ƕȵ����
  float angle;          //�ںϵĽǶ�
}Angle;
/**********�����˲�*************/
void Complementary_Filter(float Accel,float Gyro);
/********��ȡ6050����***********/
void GetMpu6050();

extern struct Angle mpu6050;
#endif