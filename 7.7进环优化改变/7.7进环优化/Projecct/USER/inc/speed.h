#ifndef _speed_H
#define _speed_H

#include "headfile.h"
#define climate 80         //ÿcm��Ӧ�ı���ֵ�����������ܶ�
//#define gyrozd (mpu6050.angle-mpu6050.offang)<0?(-1)*(mpu6050.angle-mpu6050.offang)/200:(mpu6050.angle-mpu6050.offang)/200
#define gyrozd 1
//#define gyrozd 0
typedef struct Turn{
    int p_d[6];                 //Pֵ
  float d_d[6];                 //dֵ
  float p;                 //Pֵ
  float d;                 //dֵ
  float value;             //�����ǿ��Ʊ���
  float Lratio;            //���ֲ���ϵ��
  float Rratio;            //���ֲ���ϵ��
  float p2;                //Pֵ����
  int change;              //�����ֻ�������
}Turn;
typedef struct Speed{
    int want[7];                //Ŀ������ٶ�
  int goal;                //Ŀ������ٶ�
  int left;                //�����ٶ�
  int right;               //�����ٶ�
  int Lnum;                //���ֱ���ֵ
  int Rnum;                //���ֱ���ֵ
  int Lgoal;               //����Ŀ�����ֵ
  int Rgoal;               //����Ŀ�����ֵ
  int flag;                //���ٱ�־λ
  int pos;                 //����0ƫ�����
  int neg;                 //С��0ƫ�����
}Speed;
extern Turn turn;
extern Speed speed;
extern float KD;
void DifferControl(void);
void SpeedControl(void);
void PWM_Above();
void Control();
#endif