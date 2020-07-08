/*******************自建LCD.h文件********************/

/*****************************************************
*                                                    *
*      需外部调用LPLD_LPTMR_DelayMs(uint16);         *
*                                                    *
*****************************************************/

#include "common.h"

#ifndef __LCD_H
#define __LCD_H


//初始化
void LCD_Init(void); 
//清局屏x8
void LCD_CLS_part8(uint8 x,uint8 y,uint8 x_size);
//清局屏x16
void LCD_CLS_part16(uint8 x,uint8 y,uint8 x_size);
//清全屏
void LCD_CLS(void);
//蓝屏       
void LCD_Fill(void);
//
void LCD_FillY(uint8 y);
//LCD显示
void LCD_Display_oppen(void);
//LCD关闭
void LCD_Display_close(void);
//显示6x8字符串
void LCD_P6x8Str(uint8 x,uint8 y,uint8 ch[]);
//显示8x16字符串
void LCD_P8x16Str(uint8 x,uint8 y,uint8 ch[]);
//汉字字符串    
void LCD_P16x16Str(uint8 x,uint8 y,uint8 ch[]);
//显示6x8数字
void LCD_P6x8s(uint8 x,uint8 y,int32 data);
//显示6x8数字
void LCD_P6x8float(uint8 x,uint8 y,float data,uint8 row);
//显示6x8数字
void LCD_6x8int_row(uint8 x,uint8 y,int32 data,uint8 row);
//显示8x16数字
void LCD_P8x16s(uint8 x,uint8 y,int32 data);
//BMP图片
void LCD_BMP(uint8 x0,uint8 y0,uint8 x1,uint8 y1,uint16 bmp[]);
//画点       
void LCD_dot(uint8 x,uint8 y);
//画竖线       
void LCD_line_vertical(uint8 x,uint8 y0,uint8 y1);
//画水平线       
void LCD_line_level(uint8 x0,uint8 x1,uint8 y);
//画矩形       
void LCD_rectangle(uint8 x0,uint8 y0,uint8 x1,uint8 y1);
//画圆形      
void LCD_Round(uint8 x,uint8 y,uint8 r);
//x的y次方    
uint32 LCD_power(uint8 x,uint8 y);
//延时函数
void LCD_Delay_Ms(uint16 ms);
//汉字字符混合
void LCD_mixture(uint8 x, uint8 y, uint8 ch[]);

/*******************非外部调用函数*******************
*        void LCD_Pos(uint8 x, uint8 y);           *
*        void LCD_type(void);                      *
*        void LCD_write(uint8 data);               *
*        void LCD_Delay_Ms(uint16 ms);             *
******************非外部调用函数********************/

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
