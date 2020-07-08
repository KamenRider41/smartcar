#include "dispose.h"
#include "headfile.h"
#include "math.h"
/********************传感器滤波计算变量**************/
float Get_Adc[5][4]={0};            //电感采集未滤波值
float AD_temp[5]={0,0,0,0,0};     //电感值求和滤波所用数组
uint8 Adc_Data[5][10] = {0};         //电感滤波后的数组  存10组数据
/*********************************************/
/**********************************************/
Inductance inductance={
  0,                  //水平左电感值
  0,                  //垂直左电感值
  0,                  //水平中电感值
  0,                  //垂直右电感值
  0,                  //水平右电感值
  0,                  //红外距离值
  0                   //采集电压值
};
Ofset Offset={
  0,                  //现在的偏差
  0,                  //偏差1 水平差比和
  0,                  //偏差2 垂直差比和
  35,                 //偏差3 陀螺仪零点采样
  0,                  //锁线偏差
  {0,0,0,0}           //存放偏差的数组
};
Ring Round={
  {95,110,190,110,95}, //进环阈值 = {90,130,100,130,90}
  {2,1,1,1,1},        //环的方向= {1,1,2,1,1}
  0,                  //=0 控制强制出环
  0,                  //出环计时
  1,                  //是否进环
  0,                  //开始识别圆环
  0,                  //环岛状态标志
  0,                  //进环标志位
  0,                  //递减标志位
  0,                  //出环标志位
  0,                  //1:左拐 2：右拐
  2,                  //一圈的环岛数
  0,                  //第几个环
  0,                  //计数标志位
  5.0,                //进环左偏差系数
  1.0,                //进环右偏差系数
  1,                  //下一次进环
  5,                  //下一次进环延时    写进菜单
  0,                  //下一次进环延时计数

  
};
Tof tof={
  0,                  //是否检测到路障
  0.5,                //出去的第一个偏差
  -0.5,               //回来的第二个偏差
  85,                 //tof阈值
  0.2,                  //回线偏差
  30,                 //第一次偏差移动的编码值
  35,                 //第一次和第二次之间编码器距离
  45,                 //第二次偏差移动的编码值
  60,                 //第二次偏差后的直线编码值
  0,                  //编码器编码值（记录移动的距离）
  0,                  //满足阈值的个数  int target;              //满足阈值的目标个数
  5,                 //满足阈值的目标个数
  1,                  //是否检测路障 1：开启路障检测 0：关闭路障检测
  1,                  //一圈内的路障数，含误判路障
  0,                  //路障计数
 {1,-1},              //第几个是真的路障(理论一圈一个，保险写两个)
  11,                 //过路障的方向
  250,                //路障判断间隔    
  0,                  //路障误判计时
  120,                //坡道阈值
  15,                 //tof启动时间
  0,                  //tof启动计时
  50
};
Ding bee={
  0,                  //蜂鸣器标志位
  0                   //蜂鸣器计时
};

/*
功能：传感器采值滤波,采用硬件平均滤波、软件加权递推滤波
返回值：void 
形参：void
注意事项：无
作者：OverU
*/
void Average_filtering(void){
  for(uint8 m = 0;m<5;m++){
    for(uint8 n = 0;n<5;n++){
      Get_Adc[m][n] = Get_Adc[m][n+1];
    }
  }
  for(uint8 m = 0;m < 4;m++){
    Get_Adc[0][m] =  ADC_Left2();
    Get_Adc[1][m] =  ADC_Left1();
    Get_Adc[2][m] =  ADC_Middle();
    Get_Adc[3][m] =  ADC_Right1();
    Get_Adc[4][m] =  ADC_Right2();
    
    AD_temp[0]+=Get_Adc[0][m];
    AD_temp[1]+=Get_Adc[1][m];
    AD_temp[2]+=Get_Adc[2][m];
    AD_temp[3]+=Get_Adc[3][m];
    AD_temp[4]+=Get_Adc[4][m];
  }
  Get_Adc[0][3] = (float)AD_temp[0]/4;
  Get_Adc[1][3] = (float)AD_temp[1]/4;
  Get_Adc[2][3] = (float)AD_temp[2]/4;
  Get_Adc[3][3] = (float)AD_temp[3]/4;
  Get_Adc[4][3] = (float)AD_temp[4]/4;
  inductance.Tof= ADC_Tof();
  AD_temp[0] = 0;
  AD_temp[1] = 0;
  AD_temp[2] = 0;
  AD_temp[3] = 0;
  AD_temp[4] = 0;
  
  inductance.Left2 =  (int16)(Get_Adc[0][0]*0.1+Get_Adc[0][1]*0.2+Get_Adc[0][2]*0.3+Get_Adc[0][3]*0.4);
  inductance.Left1 =  (int16)(Get_Adc[1][0]*0.1+Get_Adc[1][1]*0.2+Get_Adc[1][2]*0.3+Get_Adc[1][3]*0.4);
  inductance.middle = (int16)(Get_Adc[2][0]*0.1+Get_Adc[2][1]*0.2+Get_Adc[2][2]*0.3+Get_Adc[2][3]*0.4);
  inductance.Right1 = (int16)(Get_Adc[3][0]*0.1+Get_Adc[3][1]*0.2+Get_Adc[3][2]*0.3+Get_Adc[3][3]*0.4);
  inductance.Right2 = (int16)(Get_Adc[4][0]*0.1+Get_Adc[4][1]*0.2+Get_Adc[4][2]*0.3+Get_Adc[4][3]*0.4);

}

/*
功能：特殊元素识别（环岛，坡道，颠簸）
返回值：void 
形参：void
注意事项：无
作者：OverU
*/
void Element_identification(void){
  /******************路障的识别**********************/
     // if(inductance.Tof>100) inductance.Tof=0;
      if(inductance.Tof>tof.max&&Offset.offset>-0.1&&Offset.offset<0.1&&tof.flag==0&&inductance.middle<tof.podao&&tof.toftime/200>tof.start){
        tof.cnt++;
      }
      else{
        tof.cnt=0;
      }
      if(tof.cnt>=tof.target){
        tof.flag=1;
        tof.cnt=0;
        tof.nownum++;
        if(tof.nownum>tof.num)
          tof.nownum=1;
      }
 /*************************************/
 /******************圆环的识别**********************/

  //递推
  for(uint8 m = 0;m<5;m++){
    for(uint8 n = 0;n<9;n++){
      Adc_Data[m][n] = Adc_Data[m][n+1];
    }
  }
  Adc_Data[0][9] = inductance.Left2;
  Adc_Data[1][9] = inductance.Left1;
  Adc_Data[2][9] = inductance.middle;
  Adc_Data[3][9] = inductance.Right1;
  Adc_Data[4][9] = inductance.Right2;
    if(Round.Mode){
    //环岛识别 0.找递增
    if(Round.Flag==0){
      Round.BeginFlag = 1;
      if(Round.BeginFlag==1){
        //找递增
          if(Adc_Data[0][9]>Adc_Data[0][7]&&Adc_Data[2][9]>Adc_Data[2][7]&&Adc_Data[4][9]>Adc_Data[4][7]){
            Round.Flag = 1;
          }
          else {
            Round.Flag = 0;
          } 
      }
    }
    //1.找特征值 判断为环岛（找到合适的阈值很重要）
    if(Round.Flag==1&&inductance.middle>Round.Threshold[2]&&inductance.Left2>Round.Threshold[0]&&inductance.Right2>Round.Threshold[4]&&Round.next==1){
      Round.Flag = 2; 
      Round.next = 0;
    }
    //2.根据竖直电感先增后减 进环判断（先增前面已经判断）
    else if(Round.Flag==2){

      for(uint8 i=9;i>5;i--){
        if(Adc_Data[2][i]>Adc_Data[2][i-1])//*****
        {
          Round.RunFlag = 0;
          break;
        }
        else Round.RunFlag = 1;
      }
      //进环时刻
      if(Round.RunFlag==1){        
        Round.Flag = 3;
        Round.timecount = 0;
        Round.timeflag = 1;
        Round.SubFlag = 0;
        
        Round.Location = Round.Location%Round.Num;//第几个环
        /*环的方向*/
        if(Round.Size[Round.Location]==1) Round.Direct = 1;
        else if(Round.Size[Round.Location]==2) Round.Direct = 2;
        Round.Location++; 
      }
    }
    //3.处于进环时期
    else if(Round.Flag==3){
      if(Round.SubFlag==0){
        /*左进环*/
        if(Round.Direct==1){
          for(uint8 i=9;i>7;i--){
            if(Adc_Data[4][i]>Adc_Data[4][i-1]){
              Round.SubFlag = 0;
              break;
            }
            else Round.SubFlag = 1;
          }
        }
        /*右进环*/
        if(Round.Direct==2){
          for(uint8 i=9;i>7;i--){
            if(Adc_Data[0][i]>Adc_Data[0][i-1]){
              Round.SubFlag = 0;
              break;
            }
            else Round.SubFlag = 1;
          }
        }
      }
      if(Round.SubFlag==1){
        if(Round.Direct==1){
          if(inductance.Right2<(Round.Threshold[4]-8)){
            Round.Flag = 4;
            
            Round.SubFlag = 0;
            Round.RunFlag = 0;
          }
        }
        if(Round.Direct==2){
          if(inductance.Left2<(Round.Threshold[0]-8)){
            Round.Flag = 4;
            Round.SubFlag = 0;
            Round.RunFlag = 0;
          }
        }
      }
      //强制解除进环状态
      if(Round.timecount>300){
        Round.Flag = 4;
        Round.SubFlag = 0;
        Round.RunFlag = 0;
      }
    } 
    //4.环中
    else if(Round.Flag==4){
      //根据竖直电感阈值判断出环
      if(Round.Direct==1){
        if(inductance.Left1>Round.Threshold[1]&&inductance.Right1>Round.Threshold[3]&&Round.timecount>150)
        {
          Round.Flag = 5;
          Round.OutFlag = 1;
          Round.SubFlag = 0;
        }
      }
      if(Round.Direct==2){  
        if(inductance.Right1>Round.Threshold[3]&&inductance.Left1>Round.Threshold[1]&&Round.timecount>150)
        {
          Round.Flag = 5;
          Round.OutFlag = 1;
          Round.SubFlag = 0;
        }
      }

    }
    //5.出环
    else if(Round.Flag==5){ 
      if(Round.SubFlag==0){
        for(uint8 i=9;i>2;i--){
          if(Adc_Data[2][i]<Adc_Data[2][i-1]){
            Round.SubFlag = 0;
            break;
          }
          else Round.SubFlag = 1;
        }
      }
      if(Round.SubFlag==1){
        for(uint8 i=9;i>5;i--){
          if(Adc_Data[2][i]>Adc_Data[2][i-1]){
            Round.Flag = 5;
            Round.SubFlag = 1;
            break;
          }
          else {
            Round.Flag = 6;
            Round.SubFlag = 0;
          }
        }
      }
      if(Round.Flag==6){
        if(Round.OutCount<50){
          Round.Flag = 5;
          Round.SubFlag = 1;
        }
      }
      if(Round.OutCount>70){
        Round.Flag = 6;
        Round.OutCount = 0;
      }
    }
    //6.出环
    else if(Round.Flag==6){
      if(Round.Direct==1){
        for(uint8 i=9;i>2;i--){
          if((Adc_Data[0][i]>Adc_Data[0][i-1])||(Adc_Data[2][i]>Adc_Data[2][i-1])){
            Round.SubFlag=0;
            break;
          }
          else {
            Round.SubFlag=1;
          }
        }
      }
      if(Round.Direct==2){
        for(uint8 i=9;i>2;i--){
          if((Adc_Data[4][i]>Adc_Data[4][i-1])||(Adc_Data[2][i]>Adc_Data[2][i-1])){
            Round.SubFlag=0;
            break;
          }
          else {
            Round.SubFlag=1;
          }
        }
      }
      if(Round.OutCount>90){
        if(Round.SubFlag==1&&Round.timecount>200){
          Round.SubFlag = 0;
          Round.timeflag = 0;
          Round.timecount = 0;
          Round.Flag =0;
          Round.RunFlag = 0;
          Round.Direct = 0;
          Round.OutFlag = 0;
          Round.OutCount = 0;
        } 
      }
      if(Round.OutCount>120){
        Round.SubFlag = 0;
        Round.timeflag = 0;
        Round.timecount = 0;
        Round.Flag =0;
        Round.RunFlag = 0;
        Round.Direct = 0;
        Round.OutFlag = 0;
        Round.OutCount = 0;
      }
    }
    //5*750/1000s后强制出环
    if(Round.timecount>1500){
      Round.timeflag = 0;
      Round.timecount = 0;
      Round.Flag =0;
      Round.RunFlag = 0;
      Round.Direct = 0;
      Round.SubFlag = 0;
      Round.OutFlag = 0;
      Round.OutCount = 0;
    }
    }
}
/*
功能：循迹处理函数
返回值：void 
形参：void
注意事项：无
作者：OverU
*/
void offset_dispose(void)

{ 
  Average_filtering();
  Element_identification();
  /***************蜂鸣器调试提示**********/
  if(Round.RunFlag==1||Round.Flag==6){
    if(Round.Mode==1)
    BEEP(1);
  }
  else {
      BEEP(0);
  }
  
  if(tof.flag==1&&tof.mode==1){
    BEEP(1);
  }
  else if(Round.RunFlag!=1&&Round.Flag!=6){
      BEEP(0);
  }
  
  /*************************************/
  /***************水平电感偏差1***********/
  if(!inductance.Left2&&!inductance.Right2&&!inductance.middle)
    Offset.offset1 = 0;
  else 
    Offset.offset1 =((float)(inductance.Left2-inductance.Right2)/(inductance.Left2+inductance.Right2+inductance.middle));
  /*************************************/
  /***************竖直电感偏差2***********/
  if(!inductance.Left1&&!inductance.Right1&&!inductance.middle)
    Offset.offset2 = 0;
  else
    Offset.offset2 =((float)(inductance.Left1-inductance.Right1)/(inductance.Left1+inductance.Right1+inductance.middle));
  /*************************************/
  /***************丢线寻找上一个偏差**********/
  if(inductance.Left2<2&&inductance.Right2<2&&inductance.middle<2){
    Offset.offset1 = Offset.offsetlast;

  }
  /*************************************/
  /****************圆环偏差**************/
 if(Round.Flag>2&&Round.Flag<4){
    if(Round.RunFlag==1){
      if(Round.Mode==1){
        if(Offset.offset2>0) Offset.offset = Offset.offset2*Round.DirectLeftValue;
        else Offset.offset = Offset.offset2*Round.DirectRightValue;
      }
    }
    else{
      Offset.offset = 0.1*Offset.Data[3]+0.2*Offset.Data[2]+0.3*Offset.Data[1]+0.4*Offset.offset1;
    }
  }
  else if(Round.Flag==5){
    Offset.offset = 0.1*Offset.Data[3]+0.2*Offset.Data[2]+0.3*Offset.Data[1]+0.4*Offset.offset1;
    
    if(Round.Direct==1){
      //0.2
      if(Offset.offset>0) Offset.offset += 0.1;
    }
    if(Round.Direct==2){
      if(Offset.offset<0) Offset.offset -=0.1;
    }
  }
  else if(Round.Flag==6){

    Offset.offset = 0.1*Offset.Data[3]+0.2*Offset.Data[2]+0.3*Offset.Data[1]+0.4*Offset.offset1;
    if(Round.Direct==1){
      //0.1
      if(Offset.offset>0.1){
        Offset.offset = 0.1;
      }
      
    }
    if(Round.Direct==2){
      if(Offset.offset<-0.1){
        Offset.offset = -0.1;
      }
    }
  }
  /***********正常偏差******************/
  else{
    Offset.offset = 0.1*Offset.Data[3]+0.2*Offset.Data[2]+0.3*Offset.Data[1]+0.4*Offset.offset1;
  }
  /*************************************/
  /***********偏差存储****************/  
  Offset.Data[3] = Offset.Data[2];
  Offset.Data[2] = Offset.Data[1];
  Offset.Data[1] = Offset.Data[0];
  Offset.Data[0] = Offset.offset;

  /*************************************/
}
    

