#include "AngleFilter.h"
#include "math.h"
/*********陀螺仪变量************/
Angle mpu6050={
  0,              //x轴角加速度
  0,              //y轴角加速度
  0,              //z轴角加速度
  0,              //x轴加速度
  0,              //y轴加速度
  0,              //z轴加速度
  {0,0,-1.8,-16.3,0,0},  //3轴角加速度和加速度的零点采样
  -16.9,              //角度的零点
  0               //融合的角度
};
/*
功能：互补滤波
返回值：void 
形参：Accel 输入加速度；Gyro 输入角速度
注意事项：无
作者：OverU
*/
void Complementary_Filter(float Accel,float Gyro)
{
  mpu6050.angle = (float)(K1 * Accel+ (1-K1) * (mpu6050.angle + Gyro * 0.005));//0.005秒;为周期时间，对应5ms	
}


/**
 * 函数：GetMpu6050
 * 说明：mpu6050数据融合
 * 参数：无    
 * 输出：无
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
