/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2017,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *                                                                                    turn.p_d[0] = 15;
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��                           turn.p_d[1] = 18;
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������                       turn.p_d[2] = 21;
 *                                                                                    turn.p_d[3] = 24;
 * @file       		main                                                          turn.p_d[4] = 27;
 * @company	   		�ɶ���ɿƼ����޹�˾                                   turn.p_d[5] = 30;
 * @author     		��ɿƼ�(QQ3184284598)
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
    get_clk();              //��ȡʱ��Ƶ�� ����ִ��
    Init_All();
    BootInit();
    if(dw ==1){//����
      speed.want[0] = 85; 
      speed.want[1] = 70;        turn.p_d[0] = 15;      turn.d_d[0] = -1.0;
      speed.want[2] = 68;        turn.p_d[1] = 20;      turn.d_d[1] = -1.4;
      speed.want[3] = 66;        turn.p_d[2] = 25;      turn.d_d[2] = -1.8;
      speed.want[4] = 64;        turn.p_d[3] = 30;      turn.d_d[3] = -2.2;
      speed.want[5] = 62;        turn.p_d[4] = 35;      turn.d_d[4] = -2.6;
      speed.want[6] = 60;        turn.p_d[5] = 40;      turn.d_d[5] = -3.0;
    }
    else if(dw ==2){//����
      speed.want[0] = 80;       
      speed.want[1] = 67;        turn.p_d[0] = 15;      turn.d_d[0] = -1.0;
      speed.want[2] = 65;        turn.p_d[1] = 18;      turn.d_d[1] = -1.4;
      speed.want[3] = 63;        turn.p_d[2] = 21;      turn.d_d[2] = -1.8;
      speed.want[4] = 61;        turn.p_d[3] = 24;      turn.d_d[3] = -2.2;
      speed.want[5] = 59;        turn.p_d[4] = 27;      turn.d_d[4] = -2.6;
      speed.want[6] = 57;        turn.p_d[5] = 30;      turn.d_d[5] = -3.0;
    }
    else if(dw ==3){//����
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
      anjian();//���̸ı�
      valuedisplay();//��ֵ����ʾ
      SDS_OutPut_Data(SDS_OutData); 
    }
        
	
}
