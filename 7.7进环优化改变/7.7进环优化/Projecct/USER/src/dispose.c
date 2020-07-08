#include "dispose.h"
#include "headfile.h"
#include "math.h"
/********************�������˲��������**************/
float Get_Adc[5][4]={0};            //��вɼ�δ�˲�ֵ
float AD_temp[5]={0,0,0,0,0};     //���ֵ����˲���������
uint8 Adc_Data[5][10] = {0};         //����˲��������  ��10������
/*********************************************/
/**********************************************/
Inductance inductance={
  0,                  //ˮƽ����ֵ
  0,                  //��ֱ����ֵ
  0,                  //ˮƽ�е��ֵ
  0,                  //��ֱ�ҵ��ֵ
  0,                  //ˮƽ�ҵ��ֵ
  0,                  //�������ֵ
  0                   //�ɼ���ѹֵ
};
Ofset Offset={
  0,                  //���ڵ�ƫ��
  0,                  //ƫ��1 ˮƽ��Ⱥ�
  0,                  //ƫ��2 ��ֱ��Ⱥ�
  35,                 //ƫ��3 ������������
  0,                  //����ƫ��
  {0,0,0,0}           //���ƫ�������
};
Ring Round={
  {95,110,190,110,95}, //������ֵ = {90,130,100,130,90}
  {2,1,1,1,1},        //���ķ���= {1,1,2,1,1}
  0,                  //=0 ����ǿ�Ƴ���
  0,                  //������ʱ
  1,                  //�Ƿ����
  0,                  //��ʼʶ��Բ��
  0,                  //����״̬��־
  0,                  //������־λ
  0,                  //�ݼ���־λ
  0,                  //������־λ
  0,                  //1:��� 2���ҹ�
  2,                  //һȦ�Ļ�����
  0,                  //�ڼ�����
  0,                  //������־λ
  5.0,                //������ƫ��ϵ��
  1.0,                //������ƫ��ϵ��
  1,                  //��һ�ν���
  5,                  //��һ�ν�����ʱ    д���˵�
  0,                  //��һ�ν�����ʱ����

  
};
Tof tof={
  0,                  //�Ƿ��⵽·��
  0.5,                //��ȥ�ĵ�һ��ƫ��
  -0.5,               //�����ĵڶ���ƫ��
  85,                 //tof��ֵ
  0.2,                  //����ƫ��
  30,                 //��һ��ƫ���ƶ��ı���ֵ
  35,                 //��һ�κ͵ڶ���֮�����������
  45,                 //�ڶ���ƫ���ƶ��ı���ֵ
  60,                 //�ڶ���ƫ����ֱ�߱���ֵ
  0,                  //����������ֵ����¼�ƶ��ľ��룩
  0,                  //������ֵ�ĸ���  int target;              //������ֵ��Ŀ�����
  5,                 //������ֵ��Ŀ�����
  1,                  //�Ƿ���·�� 1������·�ϼ�� 0���ر�·�ϼ��
  1,                  //һȦ�ڵ�·������������·��
  0,                  //·�ϼ���
 {1,-1},              //�ڼ��������·��(����һȦһ��������д����)
  11,                 //��·�ϵķ���
  250,                //·���жϼ��    
  0,                  //·�����м�ʱ
  120,                //�µ���ֵ
  15,                 //tof����ʱ��
  0,                  //tof������ʱ
  50
};
Ding bee={
  0,                  //��������־λ
  0                   //��������ʱ
};

/*
���ܣ���������ֵ�˲�,����Ӳ��ƽ���˲��������Ȩ�����˲�
����ֵ��void 
�βΣ�void
ע�������
���ߣ�OverU
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
���ܣ�����Ԫ��ʶ�𣨻������µ���������
����ֵ��void 
�βΣ�void
ע�������
���ߣ�OverU
*/
void Element_identification(void){
  /******************·�ϵ�ʶ��**********************/
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
 /******************Բ����ʶ��**********************/

  //����
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
    //����ʶ�� 0.�ҵ���
    if(Round.Flag==0){
      Round.BeginFlag = 1;
      if(Round.BeginFlag==1){
        //�ҵ���
          if(Adc_Data[0][9]>Adc_Data[0][7]&&Adc_Data[2][9]>Adc_Data[2][7]&&Adc_Data[4][9]>Adc_Data[4][7]){
            Round.Flag = 1;
          }
          else {
            Round.Flag = 0;
          } 
      }
    }
    //1.������ֵ �ж�Ϊ�������ҵ����ʵ���ֵ����Ҫ��
    if(Round.Flag==1&&inductance.middle>Round.Threshold[2]&&inductance.Left2>Round.Threshold[0]&&inductance.Right2>Round.Threshold[4]&&Round.next==1){
      Round.Flag = 2; 
      Round.next = 0;
    }
    //2.������ֱ���������� �����жϣ�����ǰ���Ѿ��жϣ�
    else if(Round.Flag==2){

      for(uint8 i=9;i>5;i--){
        if(Adc_Data[2][i]>Adc_Data[2][i-1])//*****
        {
          Round.RunFlag = 0;
          break;
        }
        else Round.RunFlag = 1;
      }
      //����ʱ��
      if(Round.RunFlag==1){        
        Round.Flag = 3;
        Round.timecount = 0;
        Round.timeflag = 1;
        Round.SubFlag = 0;
        
        Round.Location = Round.Location%Round.Num;//�ڼ�����
        /*���ķ���*/
        if(Round.Size[Round.Location]==1) Round.Direct = 1;
        else if(Round.Size[Round.Location]==2) Round.Direct = 2;
        Round.Location++; 
      }
    }
    //3.���ڽ���ʱ��
    else if(Round.Flag==3){
      if(Round.SubFlag==0){
        /*�����*/
        if(Round.Direct==1){
          for(uint8 i=9;i>7;i--){
            if(Adc_Data[4][i]>Adc_Data[4][i-1]){
              Round.SubFlag = 0;
              break;
            }
            else Round.SubFlag = 1;
          }
        }
        /*�ҽ���*/
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
      //ǿ�ƽ������״̬
      if(Round.timecount>300){
        Round.Flag = 4;
        Round.SubFlag = 0;
        Round.RunFlag = 0;
      }
    } 
    //4.����
    else if(Round.Flag==4){
      //������ֱ�����ֵ�жϳ���
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
    //5.����
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
    //6.����
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
    //5*750/1000s��ǿ�Ƴ���
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
���ܣ�ѭ��������
����ֵ��void 
�βΣ�void
ע�������
���ߣ�OverU
*/
void offset_dispose(void)

{ 
  Average_filtering();
  Element_identification();
  /***************������������ʾ**********/
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
  /***************ˮƽ���ƫ��1***********/
  if(!inductance.Left2&&!inductance.Right2&&!inductance.middle)
    Offset.offset1 = 0;
  else 
    Offset.offset1 =((float)(inductance.Left2-inductance.Right2)/(inductance.Left2+inductance.Right2+inductance.middle));
  /*************************************/
  /***************��ֱ���ƫ��2***********/
  if(!inductance.Left1&&!inductance.Right1&&!inductance.middle)
    Offset.offset2 = 0;
  else
    Offset.offset2 =((float)(inductance.Left1-inductance.Right1)/(inductance.Left1+inductance.Right1+inductance.middle));
  /*************************************/
  /***************����Ѱ����һ��ƫ��**********/
  if(inductance.Left2<2&&inductance.Right2<2&&inductance.middle<2){
    Offset.offset1 = Offset.offsetlast;

  }
  /*************************************/
  /****************Բ��ƫ��**************/
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
  /***********����ƫ��******************/
  else{
    Offset.offset = 0.1*Offset.Data[3]+0.2*Offset.Data[2]+0.3*Offset.Data[1]+0.4*Offset.offset1;
  }
  /*************************************/
  /***********ƫ��洢****************/  
  Offset.Data[3] = Offset.Data[2];
  Offset.Data[2] = Offset.Data[1];
  Offset.Data[1] = Offset.Data[0];
  Offset.Data[0] = Offset.offset;

  /*************************************/
}
    

