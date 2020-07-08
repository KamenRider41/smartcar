#include "AngleFilter.h"
#include "math.h"
/*********�����Ǳ���************/
Angle mpu6050={
  0,              //x��Ǽ��ٶ�
  0,              //y��Ǽ��ٶ�
  0,              //z��Ǽ��ٶ�
  0,              //x����ٶ�
  0,              //y����ٶ�
  0,              //z����ٶ�
  {0,0,-1.8,-16.3,0,0},  //3��Ǽ��ٶȺͼ��ٶȵ�������
  -16.9,              //�Ƕȵ����
  0               //�ںϵĽǶ�
};
/*
���ܣ������˲�
����ֵ��void 
�βΣ�Accel ������ٶȣ�Gyro ������ٶ�
ע�������
���ߣ�OverU
*/
void Complementary_Filter(float Accel,float Gyro)
{
  mpu6050.angle = (float)(K1 * Accel+ (1-K1) * (mpu6050.angle + Gyro * 0.005));//0.005��;Ϊ����ʱ�䣬��Ӧ5ms	
}


/**
 * ������GetMpu6050
 * ˵����mpu6050�����ں�
 * ��������    
 * �������
 */
void GetMpu6050(){
  
  Get_Gyro();
  Get_AccData();
  mpu6050.accx = (mpu_acc_x-mpu6050.zero[3])*AccValue;
  if(mpu6050.accx>1) mpu6050.accx = 1;
  if(mpu6050.accx<-1) mpu6050.accx = -1;
  mpu6050.accx = asin(mpu6050.accx)*180/PI;
  mpu6050.gyroz  = (mpu_gyro_z -mpu6050.zero[2])*GyroValue;
  mpu6050.gyroy = (-1)*(mpu_gyro_y-mpu6050.zero[1])*GyroValue;
  Complementary_Filter(mpu6050.accx,mpu6050.gyroz);
  
}
