#ifndef _Init_H
#define _Init_H

#include "headfile.h"


/*******定时器初始化**********/
void PIT_Init();
/********串口初始化************/
void UART_Init();
/*****电机PWM初始化**********/
void PWM_Init();
/*陀螺仪与加速度计  ADC初始化*/
void Balance_Init();
/******编码器脉冲捕获********/
void PWMIC_Init();
/********AD电感采样初始化**************/
void AD_Init();
/********按键初始化**********/
void KeyInit();
/********红外,蜂鸣器初始化***********/
void GPIO_Init();
/**初始化所有*/
void Init_All();

#endif