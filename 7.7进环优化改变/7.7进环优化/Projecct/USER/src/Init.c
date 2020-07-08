#include "Init.h"


#define Dianji 250000

/***************************
* 功能 * 定时器初始化
* 参数 * 无
* 时间 * 2018/3/28 
****************************/
void PIT_Init()
{
  pit_init_ms(pit0,5);
  set_irq_priority(PIT_CH0_IRQn,2);
  enable_irq(PIT_CH0_IRQn);
}
/***************************
* 功能 * 红外，蜂鸣器初始化
* 参数 * 无
* 时间 * 2018/3/28 
****************************/
void GPIO_Init(){
  /******蜂鸣器******/
  gpio_init(D2,GPO,0);
  //prot_pull(A2);
  /******红外*******/
  gpio_init(A7,GPI,1); 
  port_pull(A7);
  //irq_init();
  //set_irq_priority(IRQ_IRQn,0);
}
/***************************
* 功能 * 串口初始化
* 参数 * 无
* 时间 * 2018/3/28 
****************************/
void UART_Init()
{
  uart_init(uart1,115200);
}
/***************************
* 功能 * 电机初始化
* 参数 * 无
* 时间 * 2018/3/28 
****************************/
void PWM_Init()
{
  ftm_pwm_init(ftm2,ftm_ch2,Dianji,0);
  ftm_pwm_init(ftm2,ftm_ch3,Dianji,0);
  ftm_pwm_init(ftm2,ftm_ch4,Dianji,0);
  ftm_pwm_init(ftm2,ftm_ch5,Dianji,0);
  gpio_init(I5,GPO,1);
  gpio_init(I6,GPO,1);
}
/****************************
* 功能 * 编码器脉冲捕获
* 参数 * 无
* 时间 * 2018/3/28 
****************************/
void PWMIC_Init()
{
  gpio_init(E2,GPI,1);//对应ftm0 
  gpio_init(E3,GPI,1);//对应ftm1
  port_pull(E2);
  port_pull(E3);
  ftm_count_init(ftm0);//E0
  ftm_count_init(ftm1);//E7
}

/****************************
* 功能 * AD电感采样初始化
* 参数 * 无
* 时间 * 2018/3/28 
****************************/
void AD_Init()
{
  adc_init(ADC0_SE4);//B0
  adc_init(ADC0_SE9);//C1
  adc_init(ADC0_SE6);//B2
  adc_init(ADC0_SE5);//B1
  adc_init(ADC0_SE7);//B3
  adc_init(ADC0_SE2);//A6
  
}
/***************************
* 功能 * 按键初始化
* 参数 * 无
* 时间 * 2018/3/28 
****************************/
void KeyInit()
{
  gpio_init(E6, GPI, 0);//初始化C2输入
  port_pull(E6);        //上拉
  gpio_init(C2, GPI, 0);//初始化C3输入
  port_pull(C2);        //上拉
  gpio_init(C3, GPI, 0);//上
  port_pull(C3);        //上拉
  gpio_init(E5, GPI, 0);//右
  port_pull(E5);        //上拉
  gpio_init(B5, GPI, 0);//中
  port_pull(B5);        //上拉
  
  //霍尔开关
  gpio_init(I2, GPI, 0);//红外
  port_pull(I2);        //上拉
  set_irq_priority(IRQ_IRQn,0);
  enable_irq(IRQ_IRQn);
}
/***************************
* 功能 * 初始化所有模块
* 参数 * 无
* 时间 * 2018/3/28 
****************************/
void Init_All()
{
  irq_init();  //中断
  //MH_Init();  模糊表
  KeyInit();
  FLASH_Init();
  IIC_init();
  InitMPU6050();
  AD_Init();
  PWM_Init();
  PWMIC_Init();
  PIT_Init();
  UART_Init();
  GPIO_Init();
}

