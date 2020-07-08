/*******************�Խ�LCD.h�ļ�********************/

/*****************************************************
*                                                    *
*      ���ⲿ����LPLD_LPTMR_DelayMs(uint16);         *
*                                                    *
*****************************************************/

#include "common.h"

#ifndef __LCD_H
#define __LCD_H


//��ʼ��
void LCD_Init(void); 
//�����x8
void LCD_CLS_part8(uint8 x,uint8 y,uint8 x_size);
//�����x16
void LCD_CLS_part16(uint8 x,uint8 y,uint8 x_size);
//��ȫ��
void LCD_CLS(void);
//����       
void LCD_Fill(void);
//
void LCD_FillY(uint8 y);
//LCD��ʾ
void LCD_Display_oppen(void);
//LCD�ر�
void LCD_Display_close(void);
//��ʾ6x8�ַ���
void LCD_P6x8Str(uint8 x,uint8 y,uint8 ch[]);
//��ʾ8x16�ַ���
void LCD_P8x16Str(uint8 x,uint8 y,uint8 ch[]);
//�����ַ���    
void LCD_P16x16Str(uint8 x,uint8 y,uint8 ch[]);
//��ʾ6x8����
void LCD_P6x8s(uint8 x,uint8 y,int32 data);
//��ʾ6x8����
void LCD_P6x8float(uint8 x,uint8 y,float data,uint8 row);
//��ʾ6x8����
void LCD_6x8int_row(uint8 x,uint8 y,int32 data,uint8 row);
//��ʾ8x16����
void LCD_P8x16s(uint8 x,uint8 y,int32 data);
//BMPͼƬ
void LCD_BMP(uint8 x0,uint8 y0,uint8 x1,uint8 y1,uint16 bmp[]);
//����       
void LCD_dot(uint8 x,uint8 y);
//������       
void LCD_line_vertical(uint8 x,uint8 y0,uint8 y1);
//��ˮƽ��       
void LCD_line_level(uint8 x0,uint8 x1,uint8 y);
//������       
void LCD_rectangle(uint8 x0,uint8 y0,uint8 x1,uint8 y1);
//��Բ��      
void LCD_Round(uint8 x,uint8 y,uint8 r);
//x��y�η�    
uint32 LCD_power(uint8 x,uint8 y);
//��ʱ����
void LCD_Delay_Ms(uint16 ms);
//�����ַ����
void LCD_mixture(uint8 x, uint8 y, uint8 ch[]);

/*******************���ⲿ���ú���*******************
*        void LCD_Pos(uint8 x, uint8 y);           *
*        void LCD_type(void);                      *
*        void LCD_write(uint8 data);               *
*        void LCD_Delay_Ms(uint16 ms);             *
******************���ⲿ���ú���********************/

extern uint16 OverU32X320[320];
extern uint16 OverU32X321[320];
extern uint16 setup0[80];
extern uint16 setup1[80];
extern uint16 BW0[32];
extern uint16 BW1[32];
extern uint16 Run0[48];
extern uint16 Run1[48];
extern uint16 qiang32X24[96];
extern uint16 Bullets6X8[6];

#endif 
