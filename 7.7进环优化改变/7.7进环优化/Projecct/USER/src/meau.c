
/*
功能：flash菜单
返回值：无
形参：略
注意事项：下载前先记下flash值，以免调参被擦除
作者：中南民族大学2019节能组
*/
#include "meau.h"
#include "headfile.h"
#include "LCD.h"
/*控制菜单变量，不需要改动*/
int pagenum=1;//控制页数
int pagemax=10;//最大页数
int pagemin=1;//最小页数
int tabnum=1;//控制选项
int tabmax=7;//最大选择
int tabmin=1;//最小选择
int clear=0;//清除标题*
int erase=1;//是否擦除
void FlashReadPata(void){
  if(!flashread2_6){
    flashWrite1_6;
    
    flashWrite2_1;
    flashWrite2_2;
    flashWrite2_3;
    flashWrite2_4;
    flashWrite2_5;
    flashWrite2_6;
    
    flashWrite3_1;
    flashWrite3_2;
    flashWrite3_3;
    flashWrite3_4;
    flashWrite3_5;
    flashWrite3_6;
    flashWrite3_7;
    
    flashWrite4_1;
    flashWrite4_2;
    flashWrite4_3;
    flashWrite4_4;
    flashWrite4_5;
    flashWrite4_6;
    flashWrite4_7;
    
    flashWrite5_1;
    flashWrite5_2;
    flashWrite5_3;
    flashWrite5_4;
    flashWrite5_5;
    flashWrite5_6;
    flashWrite5_7;
  
    flashWrite6_2;
    flashWrite6_3;
    flashWrite6_4;
    flashWrite6_5;
    flashWrite6_6;
    flashWrite6_7;
    
    flashWrite7_1;
    flashWrite7_2;
    flashWrite7_4;
    flashWrite7_5;
    flashWrite7_6;
    flashWrite7_7;
        
    flashWrite8_1;
    flashWrite8_2;
    flashWrite8_3;
    flashWrite8_4;
    flashWrite8_5;
    flashWrite8_6;
    
    flashWrite9_1;
    flashWrite9_2;
    flashWrite9_3;
    flashWrite9_4;
    flashWrite9_5;
    flashWrite9_6; 
    
    flashWrite10_1;
    flashWrite10_2;
    flashWrite10_3;
    flashWrite10_4;
    flashWrite10_5;
    flashWrite10_6; 
  }
  else {
    value1_6=flashread1_6;
    
    value2_1=flashread2_1;
    value2_2=flashread2_2;
    value2_3=flashread2_3;
    value2_4=flashread2_4;
    value2_5=flashread2_5;
    value2_6=flashread2_6;
    
    value3_1=flashread3_1;
    value3_2=flashread3_2;
    value3_3=flashread3_3;
    value3_4=flashread3_4;
    value3_5=flashread3_5;
    value3_6=flashread3_6;
    value3_7=flashread3_7;
    
    value4_1=flashread4_1;
    value4_2=flashread4_2;
    value4_3=flashread4_3;
    value4_4=flashread4_4;
    value4_5=flashread4_5;
    value4_6=flashread4_6;
    value4_7=flashread4_7;
    
    value5_1=flashread5_1;
    value5_2=flashread5_2;
    value5_3=flashread5_3;
    value5_4=flashread5_4;
    value5_5=flashread5_5;
    value5_6=flashread5_6;
    value5_7=flashread5_7;
    
    value6_2=flashread6_2;
    value6_3=flashread6_3;
    value6_4=flashread6_4;
    value6_5=flashread6_5;
    value6_6=flashread6_6;
    value6_7=flashread6_7;
    
    value7_1=flashread7_1;
    value7_2=flashread7_2;
    value7_4=flashread7_4;
    value7_5=flashread7_5;
    value7_6=flashread7_6;
    value7_7=flashread7_7;
    
    value8_1=flashread8_1;
    value8_2=flashread8_2;
    value8_3=flashread8_3;
    value8_4=flashread8_4;
    value8_5=flashread8_5;
    value8_6=flashread8_6;
    
    value9_1=flashread9_1;
    value9_2=flashread9_2;
    value9_3=flashread9_3;
    value9_4=flashread9_4;
    value9_5=flashread9_5;
    value9_6=flashread9_6;
    
    value10_1=flashread10_1;
    value10_2=flashread10_2;
    value10_3=flashread10_3;
    value10_4=flashread10_4;
    value10_5=flashread10_5;
    value10_6=flashread10_6;
    
  }
  
}
void BootInit()
{
  LCD_Init();
  FlashReadPata();
  meanu();
}

void meanu()
{
  LCD_P6x8Str(120,tabnum,tab);
  if(pagenum==1){
    /*****标题1***/
    LCD_P6x8Str(10,0,title1);
    /****第1行***/
    LCD_P6x8Str(0,1,title1_1);
    /****第2行***/
    LCD_P6x8Str(0,2,title1_2);
    /****第3行***/
    LCD_P6x8Str(0,3,title1_3);
    /****第4行***/
    LCD_P6x8Str(0,4,title1_4);
    /****第5行***/
    LCD_P6x8Str(0,5,title1_5);
    /****第6行***/
    LCD_P6x8Str(0,6,title1_6);
    /****第7行***/
    LCD_P6x8Str(0,7,title1_7);
  }
  else if(pagenum==2){
    /*****标题1***/
    LCD_P6x8Str(10,0,title2);
    /****第1行***/
    LCD_P6x8Str(0,1,title2_1);
    /****第2行***/
    LCD_P6x8Str(0,2,title2_2);
    /****第3行***/
    LCD_P6x8Str(0,3,title2_3);
    /****第4行***/
    LCD_P6x8Str(0,4,title2_4);
    /****第5行***/
    LCD_P6x8Str(0,5,title2_5);
    /****第6行***/
    LCD_P6x8Str(0,6,title2_6);
    /****第7行***/
    LCD_P6x8Str(0,7,title2_7);      
    
  }
  else if(pagenum==3){
    /*****标题1***/
    LCD_P6x8Str(10,0,title3);
    /****第1行***/
    LCD_P6x8Str(0,1,title3_1);
    /****第2行***/
    LCD_P6x8Str(0,2,title3_2);
    /****第3行***/
    LCD_P6x8Str(0,3,title3_3);
    /****第4行***/
    LCD_P6x8Str(0,4,title3_4);
    /****第5行***/
    LCD_P6x8Str(0,5,title3_5);
    /****第6行***/
    LCD_P6x8Str(0,6,title3_6);
    /****第7行***/
    LCD_P6x8Str(0,7,title3_7);      
    
  }
  else if(pagenum==4){
    /*****标题1***/
    LCD_P6x8Str(10,0,title4);
    /****第1行***/
    LCD_P6x8Str(0,1,title4_1);
    /****第2行***/
    LCD_P6x8Str(0,2,title4_2);
    /****第3行***/
    LCD_P6x8Str(0,3,title4_3);
    /****第4行***/
    LCD_P6x8Str(0,4,title4_4);
    /****第5行***/
    LCD_P6x8Str(0,5,title4_5);
    /****第6行***/
    LCD_P6x8Str(0,6,title4_6);
    /****第7行***/
    LCD_P6x8Str(0,7,title4_7);      
    
  }    
  else if(pagenum==5){
    /*****标题1***/
    LCD_P6x8Str(10,0,title5);
    /****第1行***/
    LCD_P6x8Str(0,1,title5_1);
    /****第2行***/
    LCD_P6x8Str(0,2,title5_2);
    /****第3行***/
    LCD_P6x8Str(0,3,title5_3);
    /****第4行***/
    LCD_P6x8Str(0,4,title5_4);
    /****第5行***/
    LCD_P6x8Str(0,5,title5_5);
    /****第6行***/
    LCD_P6x8Str(0,6,title5_6);
    /****第7行***/
    LCD_P6x8Str(0,7,title5_7);      
    
  }      
  else if(pagenum==6){
    /*****标题1***/
    LCD_P6x8Str(10,0,title6);
    /****第1行***/
    LCD_P6x8Str(0,1,title6_1);
    /****第2行***/
    LCD_P6x8Str(0,2,title6_2);
    /****第3行***/
    LCD_P6x8Str(0,3,title6_3);
    /****第4行***/
    LCD_P6x8Str(0,4,title6_4);
    /****第5行***/
    LCD_P6x8Str(0,5,title6_5);
    /****第6行***/
    LCD_P6x8Str(0,6,title6_6);
    /****第7行***/
    LCD_P6x8Str(0,7,title6_7);      
    
  }    
  else if(pagenum==7){
    /*****标题1***/
    LCD_P6x8Str(10,0,title7);
    /****第1行***/
    LCD_P6x8Str(0,1,title7_1);
    /****第2行***/
    LCD_P6x8Str(0,2,title7_2);  
    /****第3行***/
    LCD_P6x8Str(0,3,title7_3);   
    /****第4行***/
    LCD_P6x8Str(0,4,title7_4);   
    /****第5行***/
    LCD_P6x8Str(0,5,title7_5);   
    /****第6行***/
    LCD_P6x8Str(0,6,title7_6);   
    /****第7行***/
    LCD_P6x8Str(0,7,title7_7); 
  }   
  else if(pagenum==8){
    /*****标题1***/
    LCD_P6x8Str(10,0,title8);
    /****第1行***/
    LCD_P6x8Str(0,1,title8_1);
    /****第2行***/
    LCD_P6x8Str(0,2,title8_2);
    /****第3行***/
    LCD_P6x8Str(0,3,title8_3);
    /****第4行***/
    LCD_P6x8Str(0,4,title8_4);
    /****第5行***/
    LCD_P6x8Str(0,5,title8_5);
    /****第6行***/
    LCD_P6x8Str(0,6,title8_6);   
    /****第6行***/
    LCD_P6x8Str(0,7,title8_7);   
  }      
  else if(pagenum==9){
    /*****标题1***/
    LCD_P6x8Str(10,0,title9);
    /****第1行***/
    LCD_P6x8Str(0,1,title9_1);
    /****第2行***/
    LCD_P6x8Str(0,2,title9_2);
    /****第3行***/
    LCD_P6x8Str(0,3,title9_3);
    /****第4行***/
    LCD_P6x8Str(0,4,title9_4);
    /****第5行***/
    LCD_P6x8Str(0,5,title9_5);
    /****第6行***/
    LCD_P6x8Str(0,6,title9_6);  
  }
  else if(pagenum==10){
    /*****标题1***/
    LCD_P6x8Str(10,0,title10);
    /****第1行***/
    LCD_P6x8Str(0,1,title10_1);
    /****第2行***/
    LCD_P6x8Str(0,2,title10_2);
    /****第3行***/
    LCD_P6x8Str(0,3,title10_3);
    /****第4行***/
    LCD_P6x8Str(0,4,title10_4);
    /****第5行***/
    LCD_P6x8Str(0,5,title10_5);
    /****第6行***/
    LCD_P6x8Str(0,6,title10_6);     
  }
}
void valuedisplay(){
  if(pagenum==1){
    /****第1行***/
    LCD_P6x8float(80,1,value1_1,2);
    /****第2行***/
    LCD_P6x8float(80,2,value1_2,2);
    /****第3行***/
    LCD_P6x8float(80,3,value1_3,2);
    /****第4行***/
    LCD_P6x8float(80,4,value1_4,2);
    /****第5行***/
    LCD_P6x8float(80,5,value1_5,2);
    /****第6行***/
    LCD_P6x8s(80,6,value1_6);
    /****第7行***/
    LCD_P6x8float(80,7,value1_7,2);
  }
  else if(pagenum==2){
    /****第1行***/
    LCD_P6x8s(80,1,value2_1);
    /****第2行***/
    LCD_P6x8float(80,2,value2_2,1);
    /****第3行***/
    LCD_P6x8s(80,3,value2_3);
    /****第4行***/
    LCD_P6x8s(80,4,value2_4);
    /****第5行***/
    LCD_P6x8s(80,5,value2_5);
    /****第6行***/
    LCD_P6x8s(80,6,value2_6);
    /****第7行***/
    LCD_P6x8s(80,7,value2_7);
  }
  else if(pagenum==3){
    /****第1行***/
    LCD_P6x8s(80,1,value3_1);
    /****第2行***/
    LCD_P6x8s(80,2,value3_2);
    /****第3行***/
    LCD_P6x8s(80,3,value3_3);
    /****第4行***/
    LCD_P6x8s(80,4,value3_4);
    /****第5行***/
    LCD_P6x8s(80,5,value3_5);
    /****第6行***/
    LCD_P6x8float(80,6,value3_6,1);
    /****第7行***/
    LCD_P6x8float(80,7,value3_7,1);
  }
  else if(pagenum==4){
    /****第1行***/
    LCD_P6x8s(80,1,value4_1);
    /****第2行***/
    LCD_P6x8s(80,2,value4_2);
    /****第3行***/
    LCD_P6x8s(80,3,value4_3);
    /****第4行***/
    LCD_P6x8s(80,4,value4_4);
    /****第5行***/
    LCD_P6x8s(80,5,value4_5);
    /****第6行***/
    LCD_P6x8s(80,6,value4_6);
    /****第7行***/
    LCD_P6x8s(80,7,value4_7);
  }
  
  else if(pagenum==5){
    /****第1行***/
    LCD_P6x8float(80,1,value5_1,2);
    /****第2行***/
    LCD_P6x8s(80,2,value5_2);
    /****第3行***/
    LCD_P6x8float(80,3,value5_3,2);
    /****第4行***/
    LCD_P6x8float(80,4,value5_4,2);
    /****第5行***/
    LCD_P6x8s(80,5,value5_5);
    /****第6行***/
    LCD_P6x8s(80,6,value5_6);
    /****第7行***/
    LCD_P6x8s(80,7,value5_7);
  }
  
  else if(pagenum==6){
    /****第1行***/
    LCD_P6x8s(80,1,value6_1);
    /****第2行***/
    LCD_P6x8s(80,2,value6_2);
    /****第3行***/
    LCD_P6x8s(80,3,value6_3);
    /****第4行***/
    LCD_P6x8s(80,4,value6_4);
    /****第5行***/
    LCD_P6x8s(80,5,value6_5);
    /****第6行***/
    LCD_P6x8s(80,6,value6_6);
    /****第7行***/
    LCD_P6x8s(80,7,value6_7);
  }
  else if(pagenum==7){
    /****第1行***/
    LCD_P6x8float(80,1,value7_1,2);
    /****第2行***/
    LCD_P6x8s(80,2,value7_2);
    /****第3行***/
    LCD_P6x8float(80,3,value7_3,2);
    /****第4行***/   
    LCD_P6x8s(80,4,value7_4);
    /****第5行***/    
    LCD_P6x8s(80,5,value7_5);
    /****第6行***/    
    LCD_P6x8s(80,6,value7_6);
    /****第6行***/    
    LCD_P6x8s(80,7,value7_7);
  }
  else if(pagenum==8){
    /****第1行***/
    LCD_P6x8s(80,1,value8_1);
    /****第2行***/
    LCD_P6x8s(80,2,value8_2);
    /****第3行***/
    LCD_P6x8s(80,3,value8_3);
    /****第4行***/
    LCD_P6x8s(80,4,value8_4);
    /****第5行***/
    LCD_P6x8s(80,5,value8_5);
    /****第6行***/
    LCD_P6x8s(80,6,value8_6);
    /****第6行***/
    LCD_P6x8s(80,7,value8_7);
  }
  else if(pagenum==9){
    /****第1行***/
    LCD_P6x8s(80,1,value9_1);
    /****第2行***/
    LCD_P6x8s(80,2,value9_2);
    /****第3行***/
    LCD_P6x8s(80,3,value9_3);
    /****第4行***/
    LCD_P6x8s(80,4,value9_4);
    /****第5行***/
    LCD_P6x8s(80,5,value9_5);
    /****第6行***/
    LCD_P6x8s(80,6,value9_6);
  }
  else if(pagenum==10){
    /****第1行***/
    LCD_P6x8float(80,1,value10_1,2);
    /****第2行***/
    LCD_P6x8float(80,2,value10_2,2);
    /****第3行***/
    LCD_P6x8float(80,3,value10_3,2);
    /****第4行***/
    LCD_P6x8float(80,4,value10_4,2);
    /****第5行***/
    LCD_P6x8float(80,5,value10_5,2);
    /****第6行***/
    LCD_P6x8float(80,6,value10_6,2);
  }
}
void anjian(){
  //延时控制变量
  uint16 ui16_DK = DELAY_KEY;
  while(Center){
    Signal_KEY;
    pagenum++;
    if(pagenum>pagemax) pagenum = pagemin;
    if(pagenum<pagemin) pagenum = pagemax;
    LCD_CLS();
    meanu();
    valuedisplay();
    //长时间按下时，延时减短
    if (ui16_DK > DELAY_KEY_FAST) {
      systick_delay_ms(ui16_DK -= DELAY_KEY_FAST);
    } else {
      systick_delay_ms(DELAY_KEY_FAST);
    }
  }
  while(DOWN){
    //while(DOWN);
    Signal_KEY;
    tabnum++;
    if(tabnum>tabmax) {tabnum = tabmin;clear=1;}
    if(tabnum<tabmin) {tabnum = tabmax;clear=2;}
    
    if(clear==0) LCD_CLS_part8(120,tabnum-1,8);
    else if(clear==1) LCD_CLS_part8(120,tabmax,8);
    else if(clear==2) LCD_CLS_part8(120,tabmin,8);
    LCD_P6x8Str(120,tabnum,tab);
    
    clear=0;
    //长时间按下时，延时减短
    if (ui16_DK > DELAY_KEY_FAST) {
      systick_delay_ms(ui16_DK -= DELAY_KEY_FAST);
    } else {
      systick_delay_ms(DELAY_KEY_FAST);
    }
  }
  while(UP){
    Signal_KEY;
    tabnum--;
    if(tabnum>tabmax) {tabnum = tabmin;clear=1;}
    if(tabnum<tabmin) {tabnum = tabmax;clear=2;}
    
    if(clear==0) LCD_CLS_part8(120,tabnum+1,8);
    else if(clear==1) LCD_CLS_part8(120,tabmax,8);
    else if(clear==2) LCD_CLS_part8(120,tabmin,8);
    LCD_P6x8Str(120,tabnum,tab);
    
    clear=0;
    //长时间按下时，延时减短
    if (ui16_DK > DELAY_KEY_FAST) {
      systick_delay_ms(ui16_DK -= DELAY_KEY_FAST);
    } else {
      systick_delay_ms(DELAY_KEY_FAST);
    }
  } 
  while(TURN_LEFT){
    // while(TURN_LEFT);
    Signal_KEY;
    LCD_CLS_part8(80,tabnum,39);
    switch(pagenum){
    case 1:onesub();break;
    case 2:twosub();break;
    case 3:threesub();break;
    case 4:foursub();break;
    case 5:fivesub();break;   
    case 6:sixsub();break;
    case 7:sevensub();break;
    case 8:eightsub();break;
    case 9:ninesub();break;
    case 10:tensub();break;
    default:break;
    }
    valuedisplay();
    //长时间按下时，延时减短
    if (ui16_DK > DELAY_KEY_FAST) {
      systick_delay_ms(ui16_DK -= DELAY_KEY_FAST);
    } else {
      systick_delay_ms(DELAY_KEY_FAST);
    }
  }
  while(TURN_RIGHT){
    //while(TURN_RIGHT);
    Signal_KEY;
    LCD_CLS_part8(80,tabnum,39);
    switch(pagenum){
    case 1:oneadd();break;
    case 2:twoadd();break;
    case 3:threeadd();break;
    case 4:fouradd();break;
    case 5:fiveadd();break;    
    case 6:sixadd();break;  
    case 7:sevenadd();break;
    case 8:eightadd();break;
    case 9:nineadd();break;
    case 10:tenadd();break;
    default:break;
    }
    valuedisplay();
    //长时间按下时，延时减短
    if (ui16_DK > DELAY_KEY_FAST) {
      systick_delay_ms(ui16_DK -= DELAY_KEY_FAST);
    } else {
      systick_delay_ms(DELAY_KEY_FAST);
    }
  }
  
}


/*偏差观看，不用改变*/
void oneadd(){
  switch(tabnum){
  case 1:value1_6=value1_6+1;oneLimit();flashWrite1_6;break;
  }
}
void onesub(){
  switch(tabnum){
  case 1:value1_6=value1_6-1;oneLimit();flashWrite1_6;break;
  }
}
/*控制加减的函数*/
void twoadd(){
  switch(tabnum){
  case 1:value2_1=value2_1+1;twoLimit();flashWrite2_1;break;
  case 2:value2_2=value2_2+1;twoLimit();flashWrite2_2;break;
  case 3:value2_3=value2_3+1;twoLimit();flashWrite2_3;break;
  case 4:value2_4=value2_4+1;twoLimit();flashWrite2_4;break;
  case 5:value2_5=value2_5+1;twoLimit();flashWrite2_5;break;
  case 6:value2_6=value2_6+1;twoLimit();flashWrite2_6;break;
  }
}
void threeadd(){
  switch(tabnum){
  case 1:value3_1=value3_1+1;threeLimit();flashWrite3_1;break;
  case 2:value3_2=value3_2+1;threeLimit();flashWrite3_2;break;
  case 3:value3_3=value3_3+1;threeLimit();flashWrite3_3;break;
  case 4:value3_4=value3_4+1;threeLimit();flashWrite3_4;break;
  case 5:value3_5=value3_5+1;threeLimit();flashWrite3_5;break;
  case 6:value3_6=value3_6+0.1;threeLimit();flashWrite3_6;break;
  case 7:value3_7=value3_7+0.1;threeLimit();flashWrite3_7;break;
  } 
}
void fouradd(){
  switch(tabnum){
  case 1:value4_1=value4_1+1;fourLimit();flashWrite4_1;break;
  case 2:value4_2=value4_2+1;fourLimit();flashWrite4_2;break;
  case 3:value4_3=value4_3+1;fourLimit();flashWrite4_3;break;
  case 4:value4_4=value4_4+1;fourLimit();flashWrite4_4;break;
  case 5:value4_5=value4_5+1;fourLimit();flashWrite4_5;break;
  case 6:value4_6=value4_6+1;fourLimit();flashWrite4_6;break;
  case 7:value4_7=value4_7+1;fourLimit();flashWrite4_7;break;
  }
}
void fiveadd(){
  switch(tabnum){
  case 1:value5_1=value5_1+0.01;fiveLimit();flashWrite5_1;break;
  case 2:value5_2=value5_2+1;fiveLimit();flashWrite5_2;break;
  case 3:value5_3=value5_3+0.01;fiveLimit();flashWrite5_3;break;
  case 4:value5_4=value5_4+0.01;fiveLimit();flashWrite5_4;break;
  case 5:value5_5=value5_5+1;fiveLimit();flashWrite5_5;break;
  case 6:value5_6=value5_6+1;fiveLimit();flashWrite5_6;break;
  case 7:value5_7=value5_7+1;fiveLimit();flashWrite5_7;break;
  default:break;
  }
}
void sixadd(){
  switch(tabnum){
  case 1:value6_1=value6_1+1;sixLimit();break;
  case 2:value6_2=value6_2+1;sixLimit();flashWrite6_2;break;
  case 3:value6_3=value6_3+1;sixLimit();flashWrite6_3;break;
  case 4:value6_4=value6_4+1;sixLimit();flashWrite6_4;break;
  case 5:value6_5=value6_5+1;sixLimit();flashWrite6_5;break;
  case 6:value6_6=value6_6+1;sixLimit();flashWrite6_6;break;
  case 7:value6_7=value6_7+1;sixLimit();flashWrite6_7;break;
  default:break;
  }
}
void sevenadd(){
  switch(tabnum){
  case 1:value7_1=value7_1+0.1;sevenLimit();flashWrite7_1;break;
  case 2:value7_2=value7_2+1;sevenLimit();flashWrite7_2;break;
  case 4:value7_4=value7_4+1;sevenLimit();flashWrite7_4;break;
  case 5:value7_5=value7_5+1;sevenLimit();flashWrite7_5;break;
  case 6:value7_6=value7_6+1;sevenLimit();flashWrite7_6;break;
  case 7:value7_7=value7_7+1;sevenLimit();flashWrite7_7;break;
  default:break;
  }
}
void eightadd(){
  switch(tabnum){
  case 1:value8_1=value8_1+1;eightLimit();flashWrite8_1;break;
  case 2:value8_2=value8_2+1;eightLimit();flashWrite8_2;break;
  case 3:value8_3=value8_3+1;eightLimit();flashWrite8_3;break;
  case 4:value8_4=value8_4+1;eightLimit();flashWrite8_4;break;
  case 5:value8_5=value8_5+1;eightLimit();flashWrite8_5;break;
  case 6:value8_6=value8_6+1;eightLimit();flashWrite8_6;break;
  case 7:value8_7=value8_7+1;eightLimit();flashWrite8_7;break;
  default:break;
  }
}
void nineadd(){
  switch(tabnum){
  case 1:value9_1=value9_1+1;nineLimit();flashWrite9_1;break;
  case 2:value9_2=value9_2+1;nineLimit();flashWrite9_2;break;
  case 3:value9_3=value9_3+1;nineLimit();flashWrite9_3;break;
  case 4:value9_4=value9_4+1;nineLimit();flashWrite9_4;break;
  case 5:value9_5=value9_5+1;nineLimit();flashWrite9_5;break;
  case 6:value9_6=value9_6+1;nineLimit();flashWrite9_6;break;
  default:break;
  }
}
void tenadd(){
  switch(tabnum){
  case 1:value10_1=value10_1+0.1;tenLimit();flashWrite10_1;break;
  case 2:value10_2=value10_2+0.1;tenLimit();flashWrite10_2;break;
  case 3:value10_3=value10_3+0.1;tenLimit();flashWrite10_3;break;
  case 4:value10_4=value10_4+0.1;tenLimit();flashWrite10_4;break;
  case 5:value10_5=value10_5+0.1;tenLimit();flashWrite10_5;break;
  case 6:value10_6=value10_6+0.1;tenLimit();flashWrite10_6;break;
  default:break;
  }
}
void twosub(){
  switch(tabnum){
  case 1:value2_1=value2_1-1;twoLimit();flashWrite2_1;break;
  case 2:value2_2=value2_2-1;twoLimit();flashWrite2_2;break;
  case 3:value2_3=value2_3-1;twoLimit();flashWrite2_3;break;
  case 4:value2_4=value2_4-1;twoLimit();flashWrite2_4;break;
  case 5:value2_5=value2_5-1;twoLimit();flashWrite2_5;break;
  case 6:value2_6=value2_6-1;twoLimit();flashWrite2_6;break;
  }
}
void threesub(){
  switch(tabnum){
  case 1:value3_1=value3_1-1;threeLimit();flashWrite3_1;break;
  case 2:value3_2=value3_2-1;threeLimit();flashWrite3_2;break;
  case 3:value3_3=value3_3-1;threeLimit();flashWrite3_3;break;
  case 4:value3_4=value3_4-1;threeLimit();flashWrite3_4;break;
  case 5:value3_5=value3_5-1;threeLimit();flashWrite3_5;break;
  case 6:value3_6=value3_6-0.1;threeLimit();flashWrite3_6;break;
  case 7:value3_7=value3_7-0.1;threeLimit();flashWrite3_7;break;
  }
}
void foursub(){
  switch(tabnum){
  case 1:value4_1=value4_1-1;fourLimit();flashWrite4_1;break;
  case 2:value4_2=value4_2-1;fourLimit();flashWrite4_2;break;
  case 3:value4_3=value4_3-1;fourLimit();flashWrite4_3;break;
  case 4:value4_4=value4_4-1;fourLimit();flashWrite4_4;break;
  case 5:value4_5=value4_5-1;fourLimit();flashWrite4_5;break;
  case 6:value4_6=value4_6-1;fourLimit();flashWrite4_6;break;
  case 7:value4_7=value4_7-1;fourLimit();flashWrite4_7;break;
  }
}
void fivesub(){
  switch(tabnum){
  case 1:value5_1=value5_1-0.01;fiveLimit();flashWrite5_1;break;
  case 2:value5_2=value5_2-1;fiveLimit();flashWrite5_2;break;
  case 3:value5_3=value5_3-0.01;fiveLimit();flashWrite5_3;break;
  case 4:value5_4=value5_4-0.01;fiveLimit();flashWrite5_4;break;
  case 5:value5_5=value5_5-1;fiveLimit();flashWrite5_5;break;
  case 6:value5_6=value5_6-1;fiveLimit();flashWrite5_6;break;
  case 7:value5_7=value5_7-1;fiveLimit();flashWrite5_7;break;
  default:break;
  }
}
void sixsub(){
  switch(tabnum){
  case 1:value6_1=value6_1-1;sixLimit();break;
  case 2:value6_2=value6_2-1;sixLimit();flashWrite6_2;break;
  case 3:value6_3=value6_3-1;sixLimit();flashWrite6_3;break;
  case 4:value6_4=value6_4-1;sixLimit();flashWrite6_4;break;
  case 5:value6_5=value6_5-1;sixLimit();flashWrite6_5;break;
  case 6:value6_6=value6_6-1;sixLimit();flashWrite6_6;break;
  case 7:value6_7=value6_7-1;sixLimit();flashWrite6_7;break;
  default:break;
  }
}
void sevensub(){
  switch(tabnum){
  case 1:value7_1=value7_1-0.1;sevenLimit();flashWrite7_1;break;
  case 2:value7_2=value7_2-1;sevenLimit();flashWrite7_2;break;
  case 4:value7_4=value7_4-1;sevenLimit();flashWrite7_4;break;
  case 5:value7_5=value7_5-1;sevenLimit();flashWrite7_5;break;
  case 6:value7_6=value7_6-1;sevenLimit();flashWrite7_6;break;
  case 7:value7_7=value7_7-1;sevenLimit();flashWrite7_7;break;
  default:break;
  }
}
void eightsub(){
  switch(tabnum){
  case 1:value8_1=value8_1-1;eightLimit();flashWrite8_1;break;
  case 2:value8_2=value8_2-1;eightLimit();flashWrite8_2;break;
  case 3:value8_3=value8_3-1;eightLimit();flashWrite8_3;break;
  case 4:value8_4=value8_4-1;eightLimit();flashWrite8_4;break;
  case 5:value8_5=value8_5-1;eightLimit();flashWrite8_5;break;
  case 6:value8_6=value8_6-1;eightLimit();flashWrite8_6;break;
  case 7:value8_7=value8_7-1;eightLimit();flashWrite8_7;break;
  default:break;
  }
}
void ninesub(){
  switch(tabnum){
  case 1:value9_1=value9_1-1;nineLimit();flashWrite9_1;break;
  case 2:value9_2=value9_2-1;nineLimit();flashWrite9_2;break;
  case 3:value9_3=value9_3-1;nineLimit();flashWrite9_3;break;
  case 4:value9_4=value9_4-1;nineLimit();flashWrite9_4;break;
  case 5:value9_5=value9_5-1;nineLimit();flashWrite9_5;break;
  case 6:value9_6=value9_6-1;nineLimit();flashWrite9_6;break;
  default:break;
  }
}
void tensub(){
  switch(tabnum){
  case 1:value10_1=value10_1-0.1;tenLimit();flashWrite10_1;break;
  case 2:value10_2=value10_2-0.1;tenLimit();flashWrite10_2;break;
  case 3:value10_3=value10_3-0.1;tenLimit();flashWrite10_3;break;
  case 4:value10_4=value10_4-0.1;tenLimit();flashWrite10_4;break;
  case 5:value10_5=value10_5-0.1;tenLimit();flashWrite10_5;break;
  case 6:value10_6=value10_6-0.1;tenLimit();flashWrite10_6;break;
  default:break;
  }
}
/*限幅的函数*/
void oneLimit(){
  if(value1_6>ms1_6max) value1_6=ms1_6min;
  if(value1_6<ms1_6min) value1_6=ms1_6max;
}

void twoLimit(){
  if(value2_1>ms2_1max) value2_1=ms2_1min;
  if(value2_1<ms2_1min) value2_1=ms2_1max;
  if(value2_2>ms2_2max) value2_2=ms2_2min;
  if(value2_2<ms2_2min) value2_2=ms2_2max;
  if(value2_3>ms2_3max) value2_3=ms2_3min;
  if(value2_3<ms2_3min) value2_3=ms2_3max;
  if(value2_4>ms2_4max) value2_4=ms2_4min;
  if(value2_4<ms2_4min) value2_4=ms2_4max;
  if(value2_4>ms2_4max) value2_4=ms2_4min;
  if(value2_4<ms2_4min) value2_4=ms2_4max;
  if(value2_5>ms2_5max) value2_5=ms2_5min;
  if(value2_5<ms2_5min) value2_5=ms2_5max;
  if(value2_6>ms2_6max) value2_6=ms2_6min;
  if(value2_6<ms2_6min) value2_6=ms2_6max;
}
void threeLimit(){
  if(value3_1>ms3_1max) value3_1=ms3_1min;
  if(value3_1<ms3_1min) value3_1=ms3_1max;
  if(value3_2>ms3_2max) value3_2=ms3_2min;
  if(value3_2<ms3_2min) value3_2=ms3_2max;
  if(value3_3>ms3_3max) value3_3=ms3_3min;
  if(value3_3<ms3_3min) value3_3=ms3_3max;
  if(value3_4>ms3_4max) value3_4=ms3_4min;
  if(value3_4<ms3_4min) value3_4=ms3_4max;
  if(value3_5>ms3_5max) value3_5=ms3_5min;
  if(value3_5<ms3_5min) value3_5=ms3_5max;
  if(value3_6>ms3_6max) value3_6=ms3_6min;
  if(value3_6<ms3_6min) value3_6=ms3_6max;
  if(value3_7>ms3_7max) value3_7=ms3_7min;
  if(value3_7<ms3_7min) value3_7=ms3_7max;
  
}
void fourLimit(){
  if(value4_1>ms4_1max) value4_1=ms4_1min;
  if(value4_1<ms4_1min) value4_1=ms4_1max;
  if(value4_2>ms4_2max) value4_2=ms4_2min;
  if(value4_2<ms4_2min) value4_2=ms4_2max;
  if(value4_3>ms4_3max) value4_3=ms4_3min;
  if(value4_3<ms4_3min) value4_3=ms4_3max;
  if(value4_4>ms4_4max) value4_4=ms4_4min;
  if(value4_4<ms4_4min) value4_4=ms4_4max;
  if(value4_5>ms4_5max) value4_5=ms4_5min;
  if(value4_5<ms4_5min) value4_5=ms4_5max;
  
}
void fiveLimit(){
  if(value5_1>ms5_1max) value5_1=ms5_1min;
  if(value5_1<ms5_1min) value5_1=ms5_1max;  
  if(value5_2>ms5_2max) value5_2=ms5_2min;
  if(value5_2<ms5_2min) value5_2=ms5_2max; 
  if(value5_3>ms5_3max) value5_3=ms5_3min;
  if(value5_3<ms5_3min) value5_3=ms5_3max;  
  if(value5_4>ms5_4max) value5_4=ms5_4min;
  if(value5_4<ms5_4min) value5_4=ms5_4max;  
  if(value5_5>ms5_5max) value5_5=ms5_5min;
  if(value5_5<ms5_5min) value5_5=ms5_5max;  
  if(value5_6>ms5_6max) value5_6=ms5_6min;
  if(value5_6<ms5_6min) value5_6=ms5_6max;  
  if(value5_7>ms5_7max) value5_7=ms5_7min;
  if(value5_7<ms5_7min) value5_7=ms5_7max;  
}
void sixLimit(){
  if(value6_2>ms6_2max) value6_2=ms6_2min;
  if(value6_2<ms6_2min) value6_2=ms6_2max;
  if(value6_3>ms6_3max) value6_3=ms6_3min;
  if(value6_3<ms6_3min) value6_3=ms6_3max;  
  if(value6_4>ms6_4max) value6_4=ms6_4min;
  if(value6_4<ms6_4min) value6_4=ms6_4max;  
  if(value6_5>ms6_5max) value6_5=ms6_5min;
  if(value6_5<ms6_5min) value6_5=ms6_5max;  
  if(value6_6>ms6_6max) value6_6=ms6_6min;
  if(value6_6<ms6_6min) value6_6=ms6_6max;  
  if(value6_7>ms6_7max) value6_7=ms6_7min;
  if(value6_7<ms6_7min) value6_7=ms6_7max;  
}

void sevenLimit(){
  if(value7_1>ms7_1max) value7_1=ms7_1min;
  if(value7_1<ms7_1min) value7_1=ms7_1max;  
  if(value7_2>ms7_2max) value7_2=ms7_2min;
  if(value7_2<ms7_2min) value7_2=ms7_2max;  
  if(value7_4>ms7_4max) value7_4=ms7_4min;
  if(value7_4<ms7_4min) value7_4=ms7_4max;  
  if(value7_5>ms7_5max) value7_5=ms7_5min;
  if(value7_5<ms7_5min) value7_5=ms7_5max; 
  if(value7_6>ms7_6max) value7_6=ms7_6min;
  if(value7_6<ms7_6min) value7_6=ms7_6max;  
  if(value7_7>ms7_7max) value7_7=ms7_7min;
  if(value7_7<ms7_7min) value7_7=ms7_7max;   
}

void eightLimit(){
  if(value8_1>ms8_1max) value8_1=ms8_1min;
  if(value8_1<ms8_1min) value8_1=ms8_1max;
  if(value8_2>ms8_2max) value8_2=ms8_2min;
  if(value8_2<ms8_2min) value8_2=ms8_2max;
  if(value8_3>ms8_3max) value8_3=ms8_3min;
  if(value8_3<ms8_3min) value8_3=ms8_3max;
  if(value8_4>ms8_4max) value8_4=ms8_4min;
  if(value8_4<ms8_4min) value8_4=ms8_4max;
  if(value8_5>ms8_5max) value8_5=ms8_5min;
  if(value8_5<ms8_5min) value8_5=ms8_5max;
  if(value8_6>ms8_6max) value8_6=ms8_6min;
  if(value8_6<ms8_6min) value8_6=ms8_6max;
  if(value8_7>ms8_7max) value8_7=ms8_7min;
  if(value8_7<ms8_7min) value8_7=ms8_7max;
}
void nineLimit(){
  if(value9_1>ms9_1max) value9_1=ms9_1min;
  if(value9_1<ms9_1min) value9_1=ms9_1max;
  if(value9_2>ms9_2max) value9_2=ms9_2min;
  if(value9_2<ms9_2min) value9_2=ms9_2max;
  if(value9_3>ms9_3max) value9_3=ms9_3min;
  if(value9_3<ms9_3min) value9_3=ms9_3max;
  if(value9_4>ms9_4max) value9_4=ms9_4min;
  if(value9_4<ms9_4min) value9_4=ms9_4max;
  if(value9_5>ms9_5max) value9_5=ms9_5min;
  if(value9_5<ms9_5min) value9_5=ms9_5max;
  if(value9_6>ms9_6max) value9_6=ms9_6min;
  if(value9_6<ms9_6min) value9_6=ms9_6max;
}
void tenLimit(){
  if(value10_1>ms10_1max) value10_1=ms10_1min;
  if(value10_1<ms10_1min) value10_1=ms10_1max;
  if(value10_2>ms10_2max) value10_2=ms10_2min;
  if(value10_2<ms10_2min) value10_2=ms10_2max;
  if(value10_3>ms10_3max) value10_3=ms10_3min;
  if(value10_3<ms10_3min) value10_3=ms10_3max;
  if(value10_4>ms10_4max) value10_4=ms10_4min;
  if(value10_4<ms10_4min) value10_4=ms10_4max;
  if(value10_5>ms10_5max) value10_5=ms10_5min;
  if(value10_5<ms10_5min) value10_5=ms10_5max;
  if(value10_6>ms10_6max) value10_6=ms10_6min;
  if(value10_6<ms10_6min) value10_6=ms10_6max;
}
