#ifndef _dispose_H
#define _dispose_H
#include "headfile.h"

#define BEEP(x) gpio_set(D2,x)//������

#define ADC_Left2()  adc_once(ADC0_SE4,ADC_8bit) //B0
#define ADC_Left1()  adc_once(ADC0_SE9,ADC_8bit) //C1
#define ADC_Middle() adc_once(ADC0_SE6,ADC_8bit) //B2
#define ADC_Right1() adc_once(ADC0_SE5,ADC_8bit) //B1
#define ADC_Right2() adc_once(ADC0_SE7,ADC_8bit) //B3
#define ADC_Tof()    adc_once(ADC0_SE12,ADC_8bit)//F4
#define ADC_U()      adc_once(ADC0_SE2,ADC_8bit) //A6



/**************���������βɼ�*****************/
typedef struct Inductance{
  int16 Left2;                     //ˮƽ����ֵ
  uint8 Left1;                     //��ֱ����ֵ
  uint8 middle;                    //ˮƽ�е��ֵ
  uint8 Right1;                    //��ֱ�ҵ��ֵ
  int16 Right2;                    //ˮƽ�ҵ��ֵ
  uint32 Tof;                      //�������ֵ
  double v;                       //�ɼ���ѹֵ
}Inductance;
/*********************************************/
/****************ƫ��ṹ��*************************/
typedef struct Ofset{
  float offset;                   //���ڵ�ƫ��
  float offset1;                  //ƫ��1 ˮƽ��Ⱥ�
  float offset2;                  //ƫ��2 ��ֱ��Ⱥ�
  int offset3;                    //ƫ��3 ������ƫ��
  float offsetlast;               //��һ��ƫ��
  float Data[4];                  //���ƫ�������
}Ofset;
/**********************************************/
/****************Բ���ṹ��**************************/
typedef struct Ring{
  uint16 Threshold[5];     //������ֵ = {90,130,100,130,90}
  uint16 Size[5];          //���ķ���= {1,1,2,1,1}
  uint16 timecount;        //=0 ����ǿ�Ƴ���
  uint16 OutCount;         //������ʱ
  uint8  Mode;             //�Ƿ����
  uint8  BeginFlag;        //��ʼʶ��Բ��
  uint8  Flag;             //����״̬��־
  uint8  RunFlag;          //������־λ
  uint8  SubFlag;          //�ݼ���־λ
  uint8  OutFlag;          //������־λ
  uint8  Direct;           //1:��� 2���ҹ�
  uint8  Num;              //һȦ�Ļ�����
  uint8  Location;         //�ڼ�����
  uint8  timeflag;         //������־λ
  float DirectLeftValue;  //������ƫ��ϵ��
  float DirectRightValue; //������ƫ��ϵ��
  uint8  next;             //��һ�ν���
  uint8  nexttime;         //��һ�ν�����ʱ    д���˵�
  uint32  nextcnt;         //��һ�ν�����ʱ����
}Ring;
/****************·�Ͻṹ��**************************/
typedef struct Tof{
  int flag;                //�Ƿ��⵽·��(�������)
  float first;             //��ȥ�ĵ�һ��ƫ��
  float second;            //�����ĵڶ���ƫ��
  int max;                 //tof��ֵ
  float end;               //����ƫ��
  uint32 dis1;             //��һ��ƫ���ƶ��ı���ֵ
  uint32 dis2;             //��һ�κ͵ڶ���֮�����������
  uint32 dis3;             //�ڶ���ƫ���ƶ��ı���ֵ
  uint32 dis4;             //�ڶ���ƫ����ֱ�߱���ֵ
  uint32 dis;              //����������ֵ����¼�ƶ��ľ��룩
  int cnt;                 //������ֵ�ĸ���
  int target;              //������ֵ��Ŀ�����
  int mode;                //�Ƿ��ж�·��
  int num;                 //һȦ�ڵ�·������������·��
  int nownum;              //·�ϼ���
  int correct[2];          //�ڼ��������·��(����һȦһ��������д����)
  int dir;                 //1.��߹�  2.�ұ߹�
  uint32 maxcnt;           //·���жϼ��
  uint32 timecount;        //·�����м�ʱ
  uint8 podao;             //�µ���ֵ
  uint8 start;             //tof����ʱ��
  uint32 toftime;          //tof������ʱ
  uint8 speed;             //tof���ٶ�
}Tof;
/*************�������ṹ��***********************/
typedef struct Ding{
  uint8 BeginEnd;          //��������־λ
  uint16 Count;            //��������ʱ
}Ding;
/************************************************/
/**********�ⲿ���ýṹ��***********/
extern struct Inductance inductance;//����ֵ
extern struct Ofset Offset;         //ƫ��ֵ
extern struct Ring Round;           //Բ��ֵ
extern struct Ding bee;             //������
extern struct Tof tof;              //���⴫����
//�������ɼ�����
void Average_filtering(void);
//Ԫ��ʶ��
void Element_identification(void);
//ƫ�����
void offset_dispose(void);
#endif