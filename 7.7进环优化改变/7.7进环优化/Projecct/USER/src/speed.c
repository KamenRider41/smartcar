#include "speed.h"
#include "math.h"

uint8 stop=0;
uint32 flag_zhixian = 0;
float L_error_1 = 0;
float L_error_2 = 0;
float R_error_1 = 0;
float R_error_2 = 0;
/*********基础速度变量************/
Speed speed={
  {85,70,68,66,64,62,60},               //目标基础速度
  50,               //目标基础速度
  0,                 //左轮速度
  0,                 //右轮速度
  0,                 //左轮编码值
  0,                 //右轮编码值
  50,               //左轮目标编码值
  50,                 //右轮目标编码值
  0,                 //加速标志位
  0,                 //大于0偏差计数
  0                  //小于0偏差计数
};
/*********转向环变量************/
Turn turn={
  {15,20,25,30,35,40},     //P值
  {-1.0,-1.4,-1.8,-2.2,-2.6,-3.0},     //d值
  30,                //P值
  0,                 //d值
  0,                 //陀螺仪控制变量
  1,                 //左轮差速系数
  1,                 //右轮差速系数
  200,                //P值备份
  0                  //左右轮基础差速
};

/**
* 函数：DifferControl
* 说明：转向环控制
* 参数：无    
* 输出：无
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
* 函数：TofControl
* 说明：路障状态
* 参数：无    
* 输出：无
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
* 函数：SpeedControl
* 说明：距离环控制
* 参数：无    
* 输出：无
*/
void SpeedControl(void){
  
  speed.Lnum = (gpio_get(E3)==1?ftm_count_get(ftm1):-ftm_count_get(ftm1));
  ftm_count_clean(ftm1);
  speed.Rnum = (gpio_get(E2)==0?ftm_count_get(ftm0):-ftm_count_get(ftm0));
  ftm_count_clean(ftm0);  
  L_error_1 = speed.Lgoal - speed.Lnum;
  R_error_1 = speed.Rgoal - speed.Rnum;
  
  speed.right += (int)(3.8*(L_error_1-L_error_2)+12.5*L_error_1); //左轮车速
  speed.left  += (int)(3.8*(R_error_1-R_error_2)+12.5*R_error_1); //右轮车速
  
  L_error_2 = L_error_1;
  R_error_2 = R_error_1;
  if(tof.flag!=0&&tof.mode==1&&tof.nownum==tof.correct[0]||tof.nownum==tof.correct[1]){
    if(tof.flag==1||tof.flag==2||tof.flag==3||tof.flag==4)//测距模式开始 第一次偏差flag=1，第二次直线flag=2，第三次回线偏差flag=3
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
    ftm_pwm_duty(ftm2,ftm_ch4,0);            //左轮正转
    ftm_pwm_duty(ftm2,ftm_ch5,0);           //左轮反转      
    ftm_pwm_duty(ftm2,ftm_ch2,0);           //右轮正转
    ftm_pwm_duty(ftm2,ftm_ch3,0);            //右轮反转
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
      
      ftm_pwm_duty(ftm2,ftm_ch4,speed.left);   //左轮正转
      ftm_pwm_duty(ftm2,ftm_ch5,0);            //左轮反转   
    }
    if(speed.left<0)
    {
      speed.left=(-1)*speed.left;   
      ftm_pwm_duty(ftm2,ftm_ch4,0);            //左轮正转
      ftm_pwm_duty(ftm2,ftm_ch5,speed.left);   //左轮反转
    }
    if(speed.right>=0)
    {
      
      ftm_pwm_duty(ftm2,ftm_ch2,speed.right);  //右轮正转
      ftm_pwm_duty(ftm2,ftm_ch3,0);            //右轮反转
    }
    if(speed.right<0)
    {
      speed.right=(-1)*speed.right;
      ftm_pwm_duty(ftm2,ftm_ch2,0);            //右轮正转
      ftm_pwm_duty(ftm2,ftm_ch3,speed.right);  //右轮反转
    }
  }
}
/**
* 函数：Control
* 说明：总控制（用于中断调用）
* 参数：无   
* 输出：无
*/
void Control(){ 
  offset_dispose();
  /*************解除路障模式**************/
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