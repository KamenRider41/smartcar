/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2017,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：179029047
 *                                                                                    turn.p_d[0] = 15;
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，                           turn.p_d[1] = 18;
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。                       turn.p_d[2] = 21;
 *                                                                                    turn.p_d[3] = 24;
 * @file       		main                                                          turn.p_d[4] = 27;
 * @company	   		成都逐飞科技有限公司                                   turn.p_d[5] = 30;
 * @author     		逐飞科技(QQ3184284598)
 * @version    		v2.0
 * @Software 		IAR 7.7 or MDK 5.23
 * @Target core		S9KEA128AMLK
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2017-11-6
 ********************************************************************************************************************/

#include "headfile.h"
int8 dw = 0;
int main(void)
{
    get_clk();              //获取时钟频率 必须执行
    Init_All();
    BootInit();
    if(dw ==1){//快速
      speed.want[0] = 85; 
      speed.want[1] = 70;        turn.p_d[0] = 15;      turn.d_d[0] = -1.0;
      speed.want[2] = 68;        turn.p_d[1] = 20;      turn.d_d[1] = -1.4;
      speed.want[3] = 66;        turn.p_d[2] = 25;      turn.d_d[2] = -1.8;
      speed.want[4] = 64;        turn.p_d[3] = 30;      turn.d_d[3] = -2.2;
      speed.want[5] = 62;        turn.p_d[4] = 35;      turn.d_d[4] = -2.6;
      speed.want[6] = 60;        turn.p_d[5] = 40;      turn.d_d[5] = -3.0;
    }
    else if(dw ==2){//中速
      speed.want[0] = 80;       
      speed.want[1] = 67;        turn.p_d[0] = 15;      turn.d_d[0] = -1.0;
      speed.want[2] = 65;        turn.p_d[1] = 18;      turn.d_d[1] = -1.4;
      speed.want[3] = 63;        turn.p_d[2] = 21;      turn.d_d[2] = -1.8;
      speed.want[4] = 61;        turn.p_d[3] = 24;      turn.d_d[3] = -2.2;
      speed.want[5] = 59;        turn.p_d[4] = 27;      turn.d_d[4] = -2.6;
      speed.want[6] = 57;        turn.p_d[5] = 30;      turn.d_d[5] = -3.0;
    }
    else if(dw ==3){//稳速
      speed.want[0] = 75; 
      speed.want[1] = 65;        turn.p_d[0] = 15;      turn.d_d[0] = -1.0;
      speed.want[2] = 63;        turn.p_d[1] = 20;      turn.d_d[1] = -1.4;
      speed.want[3] = 61;        turn.p_d[2] = 25;      turn.d_d[2] = -1.8;
      speed.want[4] = 59;        turn.p_d[3] = 30;      turn.d_d[3] = -2.2;
      speed.want[5] = 57;        turn.p_d[4] = 35;      turn.d_d[4] = -2.6;
      speed.want[6] = 55;        turn.p_d[5] = 40;      turn.d_d[5] = -3.0; 
    }
    for(;;)
    {
      anjian();//键盘改变
      valuedisplay();//数值的显示
      SDS_OutPut_Data(SDS_OutData); 
    }
        
	
}
