/*********************************************************************************************************************
* COPYRIGHT NOTICE
* Copyright (c) 2017,逐飞科技
* All rights reserved.
* 技术讨论QQ群：179029047
*
* 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
* 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
*
* @file       		中断文件
* @company	   		成都逐飞科技有限公司
* @author     		逐飞科技(QQ3184284598)
* @version    		v2.0
* @Software 		IAR 7.7 or MDK 5.23
* @Target core		S9KEA128AMLK
* @Taobao   		https://seekfree.taobao.com/
* @date       		2017-11-6
********************************************************************************************************************/


#include "dispose.h"
#include "isr.h"
double U = 10;//10
uint8 flag_v=0,flag_stop=0,stop_s=5;
uint32 count_hqd = 0,stop_ms = 0;
double test=0;
int tiaoshi=0;
void PIT_CH0_IRQHandler(void)
{
  stop_ms++;
  test=ADC_U()/6.9;

  if((flag_v == 0 && (test>=U))||tiaoshi==1){
    flag_v=1;
  }
  if(flag_v==1)
  {
    if(count_hqd<101) count_hqd++;
    else{
        tof.toftime++;
    }
    
    if(Round.OutFlag){
      Round.OutCount++;
    }
    if(Round.timeflag){
      Round.timecount++;
    }
    if(Round.next==0){
      Round.nextcnt++;
      if(Round.nextcnt/200>=Round.nexttime){
        Round.nextcnt=0;
        Round.next=1;
      }
    }
    Control();
  }
  PIT_FLAG_CLR(pit0);
  
  
}
void PIT_CH1_IRQHandler(void)
{
  PIT_FLAG_CLR(pit1);
  
  
}

void IRQ_IRQHandler(void)
{
  if((stop_ms/200) >=stop_s && (!gpio_get(I2)))
  {
    flag_stop = 1;
  }
  CLEAR_IRQ_FLAG;
  
}


void KBI0_IRQHandler(void)
{
  CLEAN_KBI0_FLAG;
  
}





/*
中断函数名称，用于设置对应功能的中断函数
Sample usage:当前启用了周期定时器 通道0得中断
void PIT_CH0_IRQHandler(void)
{
;
}
记得进入中断后清除标志位

FTMRE_IRQHandler      
PMC_IRQHandler        
IRQ_IRQHandler        
I2C0_IRQHandler       
I2C1_IRQHandler       
SPI0_IRQHandler       
SPI1_IRQHandler       
UART0_IRQHandler 
UART1_IRQHandler 
UART2_IRQHandler 
ADC0_IRQHandler       
ACMP0_IRQHandler      
FTM0_IRQHandler       
FTM1_IRQHandler       
FTM2_IRQHandler       
RTC_IRQHandler        
ACMP1_IRQHandler      
PIT_CH0_IRQHandler    
PIT_CH1_IRQHandler    
KBI0_IRQHandler       
KBI1_IRQHandler       
Reserved26_IRQHandler 
ICS_IRQHandler        
WDG_IRQHandler        
PWT_IRQHandler        
MSCAN_Rx_IRQHandler   
MSCAN_Tx_IRQHandler   
*/



