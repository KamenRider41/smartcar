#ifndef _Init_H
#define _Init_H

#include "headfile.h"


/*******��ʱ����ʼ��**********/
void PIT_Init();
/********���ڳ�ʼ��************/
void UART_Init();
/*****���PWM��ʼ��**********/
void PWM_Init();
/*����������ٶȼ�  ADC��ʼ��*/
void Balance_Init();
/******���������岶��********/
void PWMIC_Init();
/********AD��в�����ʼ��**************/
void AD_Init();
/********������ʼ��**********/
void KeyInit();
/********����,��������ʼ��***********/
void GPIO_Init();
/**��ʼ������*/
void Init_All();

#endif