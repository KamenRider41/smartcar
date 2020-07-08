#include "speed.h"
#include "math.h"

uint8 stop=0;
uint32 flag_zhixian = 0;
float L_error_1 = 0;
float L_error_2 = 0;
float R_error_1 = 0;
float R_error_2 = 0;
/*********�����ٶȱ���************/
Speed speed={
  {85,70,68,66,64,62,60},               //Ŀ������ٶ�
  50,               //Ŀ������ٶ�
  0,                 //�����ٶ�
  0,                 //�����ٶ�
  0,                 //���ֱ���ֵ
  0,                 //���ֱ���ֵ
  50,               //����Ŀ�����ֵ
  50,                 //����Ŀ�����ֵ
  0,                 //���ٱ�־λ
  0,                 //����0ƫ�����
  0                  //С��0ƫ�����
};
/*********ת�򻷱���************/
Turn turn={
  {15,20,25,30,35,40},     //Pֵ
  {-1.0,-1.4,-1.8,-2.2,-2.6,-3.0},     //dֵ
  30,                //Pֵ
  0,                 //dֵ
  0,                 //�����ǿ��Ʊ���
  1,                 //���ֲ���ϵ��
  1,                 //���ֲ���ϵ��
  200,                //Pֵ����
  0                  //�����ֻ�������
};

/**
* ������DifferControl
* ˵����ת�򻷿���
* ��������    
* �������
*/
void DifferControl(void){
  
  if(Offset.offset<=0.08 && Offset.offset>=-0.08){
    speed.Lgoal = (int) speed.want[1];
    speed.Rgoal = (int) speed.want[1];
    flag_zhixian++;
    if(flag_zhixian>=50){
      speed.Lgoal =  speed.want[0];
      speed.Lgoal =  speed.want[0];
    }
  }
//  mpu_gyro_z-Offset.offset3
  else if(Offset.offset<=0.15 && Offset.offset>=-0.15){
    flag_zhixian=0;
    speed.Lgoal = (int) (speed.want[1]-(Offset.offset*turn.p_d[0]+(Offset.offset-Offset.Data[0])*turn.d_d[0]));
    speed.Rgoal = (int) (speed.want[1]+(Offset.offset*turn.p_d[0]+(Offset.offset-Offset.Data[0])*turn.d_d[0]));
  }
  else if(Offset.offset <= 0.25 && Offset.offset >= -0.25)
  {
    flag_zhixian=0;
    speed.Lgoal = (int) (speed.want[2]-(Offset.offset*turn.p_d[1]+(Offset.offset-Offset.Data[0])*turn.d_d[1]));
    speed.Rgoal = (int) (speed.want[2]+(Offset.offset*turn.p_d[1]+(Offset.offset-Offset.Data[0])*turn.d_d[1]));
  }
  else if(Offset.offset <= 0.4 && Offset.offset >= -0.40)
  {
    flag_zhixian=0;
    speed.Lgoal = (int)  (speed.want[3]-(Offset.offset*turn.p_d[2]+(Offset.offset-Offset.Data[0])*turn.d_d[2]));
    speed.Rgoal = (int)  (speed.want[3]+(Offset.offset*turn.p_d[2]+(Offset.offset-Offset.Data[0])*turn.d_d[2]));
  }
  else if(Offset.offset <= 0.55 && Offset.offset >= -0.55)
  {
    flag_zhixian=0;
    speed.Lgoal = (int)  (speed.want[4]-(Offset.offset*turn.p_d[3]+(Offset.offset-Offset.Data[0])*turn.d_d[3]));
    speed.Rgoal = (int)  (speed.want[4]+(Offset.offset*turn.p_d[3]+(Offset.offset-Offset.Data[0])*turn.d_d[3]));
  }
  else if(Offset.offset <= 0.70 && Offset.offset >= -0.70)
  {
    flag_zhixian=0;
    speed.Lgoal = (int)  (speed.want[5]-(Offset.offset*turn.p_d[4]+(Offset.offset-Offset.Data[0])*turn.d_d[4]));
    speed.Rgoal = (int)  (speed.want[5]+(Offset.offset*turn.p_d[4]+(Offset.offset-Offset.Data[0])*turn.d_d[4]));
  }
  else
  {
    flag_zhixian=0;
    speed.Lgoal = (int)  (speed.want[6]-(Offset.offset*turn.p_d[5]+(Offset.offset-Offset.Data[0])*turn.d_d[5]));
    speed.Rgoal = (int)  (speed.want[6]+(Offset.offset*turn.p_d[5]+(Offset.offset-Offset.Data[0])*turn.d_d[5]));
  }
  if(Round.Flag==2||Round.Flag==3){
    flag_zhixian=0;
    speed.Lgoal = (int)  (speed.goal-(Offset.offset*turn.p+(Offset.offset-Offset.Data[0])*0));
    speed.Rgoal = (int)  (speed.goal+(Offset.offset*turn.p+(Offset.offset-Offset.Data[0])*0));
  }
  if(tof.flag!=0&&tof.nownum==tof.correct[0]&&tof.nownum==tof.correct[1]){
    flag_zhixian=0;
    speed.Lgoal = (int)  (tof.speed-(Offset.offset*turn.p+(Offset.offset-Offset.Data[0])*0));
    speed.Rgoal = (int)  (tof.speed+(Offset.offset*turn.p+(Offset.offset-Offset.Data[0])*0));
  }

}
/**
* ������TofControl
* ˵����·��״̬
* ��������    
* �������
*/
void TofControl(void){
  if(tof.flag==1){
    if(tof.nownum==tof.correct[0]){
      if(tof.dir/10==1)
        Offset.offset=tof.first;
      else
        Offset.offset=(-1)*tof.first;
    }
    else if(tof.nownum==tof.correct[1]){
      if(tof.dir%10==1)
        Offset.offset=tof.first;
      else
        Offset.offset=(-1)*tof.first;
    }
    
  }
  else if(tof.flag==2){
    Offset.offset=0;
  }
  else if(tof.flag==3){
    if(tof.nownum==tof.correct[0]){
      if(tof.dir/10==1)
        Offset.offset=tof.second;
      else
        Offset.offset=(-1)*tof.second;
    }
    else if(tof.nownum==tof.correct[1]){
      if(tof.dir%10==1)
        Offset.offset=tof.second;
      else
        Offset.offset=(-1)*tof.second;
    }
  }
  else if(tof.flag==4){
        Offset.offset=0;
  
    
  }
  else if(tof.flag==5){
    if(tof.nownum==tof.correct[0]){
      if(tof.dir/10==1)
        Offset.offset=tof.end;
      else
        Offset.offset=(-1)*tof.end;
    }
    else if(tof.nownum==tof.correct[1]){
      if(tof.dir%10==1)
        Offset.offset=tof.end;
      else
        Offset.offset=(-1)*tof.end;
    }
  }
//  turn.change=(int)(turn.p*Offset.offset);
  
} 
/**
* ������SpeedControl
* ˵�������뻷����
* ��������    
* �������
*/
void SpeedControl(void){
  
  speed.Lnum = (gpio_get(E3)==1?ftm_count_get(ftm1):-ftm_count_get(ftm1));
  ftm_count_clean(ftm1);
  speed.Rnum = (gpio_get(E2)==0?ftm_count_get(ftm0):-ftm_count_get(ftm0));
  ftm_count_clean(ftm0);  
  L_error_1 = speed.Lgoal - speed.Lnum;
  R_error_1 = speed.Rgoal - speed.Rnum;
  
  speed.right += (int)(3.8*(L_error_1-L_error_2)+12.5*L_error_1); //���ֳ���
  speed.left  += (int)(3.8*(R_error_1-R_error_2)+12.5*R_error_1); //���ֳ���
  
  L_error_2 = L_error_1;
  R_error_2 = R_error_1;
  if(tof.flag!=0&&tof.mode==1&&tof.nownum==tof.correct[0]||tof.nownum==tof.correct[1]){
    if(tof.flag==1||tof.flag==2||tof.flag==3||tof.flag==4)//���ģʽ��ʼ ��һ��ƫ��flag=1���ڶ���ֱ��flag=2�������λ���ƫ��flag=3
    {
      tof.dis+=(speed.Lnum+speed.Rnum)/2;
    }
    if(tof.flag==1&&tof.dis>=tof.dis1*climate)
    {
      tof.flag=2;
      tof.dis=0;
    }
    if(tof.flag==2&&tof.dis>=tof.dis2*climate){
      tof.flag=3;
      tof.dis=0;
      
    }
    if(tof.flag==3&&tof.dis>=tof.dis3*climate){
      tof.flag=4;
      tof.dis=0; 
    }
    if(tof.flag==4&&tof.dis>=tof.dis4*climate){
           tof.flag=5;
           tof.dis=0; 
         } 
  }
  else if(tof.flag!=0&&tof.mode==1){
    tof.timecount+=(speed.Lnum+speed.Rnum)/2;
    if(tof.timecount/climate>tof.maxcnt){
      tof.timecount=0;
      tof.flag=0;
    }
  }
  
} 

void PWM_Above(){  
  if(flag_stop == 1){
    stop++;
    if(stop>=100) flag_stop=2;
  }
  if(flag_stop == 2){
    ftm_pwm_duty(ftm2,ftm_ch4,0);            //������ת
    ftm_pwm_duty(ftm2,ftm_ch5,0);           //���ַ�ת      
    ftm_pwm_duty(ftm2,ftm_ch2,0);           //������ת
    ftm_pwm_duty(ftm2,ftm_ch3,0);            //���ַ�ת
  }
  else{
    if(speed.right<-200) speed.right=-200;
    if(speed.right>990) speed.right=990;
    if(speed.left<-200) speed.left=-200;
    if(speed.left>990)speed.left=990;
    if(count_hqd <=100){
      speed.right = (int)((speed.right/100.0)* count_hqd);
      speed.left  = (int)((speed.left/100.0) * count_hqd);
    }  
    if(speed.left>=0)
    {
      
      ftm_pwm_duty(ftm2,ftm_ch4,speed.left);   //������ת
      ftm_pwm_duty(ftm2,ftm_ch5,0);            //���ַ�ת   
    }
    if(speed.left<0)
    {
      speed.left=(-1)*speed.left;   
      ftm_pwm_duty(ftm2,ftm_ch4,0);            //������ת
      ftm_pwm_duty(ftm2,ftm_ch5,speed.left);   //���ַ�ת
    }
    if(speed.right>=0)
    {
      
      ftm_pwm_duty(ftm2,ftm_ch2,speed.right);  //������ת
      ftm_pwm_duty(ftm2,ftm_ch3,0);            //���ַ�ת
    }
    if(speed.right<0)
    {
      speed.right=(-1)*speed.right;
      ftm_pwm_duty(ftm2,ftm_ch2,0);            //������ת
      ftm_pwm_duty(ftm2,ftm_ch3,speed.right);  //���ַ�ת
    }
  }
}
/**
* ������Control
* ˵�����ܿ��ƣ������жϵ��ã�
* ��������   
* �������
*/
void Control(){ 
  offset_dispose();
  /*************���·��ģʽ**************/
  if(tof.flag==5){
    if(inductance.middle>20&&Offset.offset>-0.5&&Offset.offset<0.5){
      tof.flag=0;
      tof.dis=0;
    }
  }
  /***************************************/
  if(tof.flag!=0&&tof.mode==1)//&&(tof.num==tof.correct[1]||tof.num==tof.correct[0])
  {
    if(tof.nownum==tof.correct[0]||tof.nownum==tof.correct[1])
      TofControl();
  }
  
  
  DifferControl();
  
  
  SpeedControl();
  PWM_Above();
}