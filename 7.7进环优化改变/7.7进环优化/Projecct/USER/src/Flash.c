#include "Flash.h"



/*
 * 延时一段时间
 */
void delay()
{
  uint16 i;
  for(i=0;i<1000;i++)
  {
    asm("nop");
  }
}
/*
 * Flash_Write_DataBuff
 * flash闪存单扇区整形数组写入
 *
 * 参数:
 *    FlashPtr--flash闪存扇区,取值:0--255
 *    *data--16灬32位无符号整形数组  
 *    num--数组个数
 */

void Flash_Write_DataBuff(uint32 FlashPtr,uint16 *data,uint8 num){
  uint8 result=NULL;
  //写入前先擦除原来数据
  result=FLASH_EraseSector(FlashPtr);
  if(result!=FLASH_OK){return ;}
  uint8 write_buffer[4];
  for(uint8 i=0;i<num;i++){
    write_buffer[0]=data[i]/65536/256;//data/65536/256
    write_buffer[1]=data[i]/65536%256;//data/65536%256
    write_buffer[2]=data[i]%65536/256;//data%65536/256
    write_buffer[3]=data[i]%65536%256;//data%65536%256
    DisableInterrupts;  
    result = FLASH_WriteSector((uint32)FlashPtr,(uint8*)write_buffer, 4,4*i);
    EnableInterrupts;
    delay();
//    if(result==FLASH_OK)
//      return 1;
//     else
//    return 0;
  }
}
/*
 * Flash_Read_DataBuff
 * flash闪存单扇区整形数组输出
 *
 * 参数:
 *    FlashPtr--flash闪存扇区,取值:0--255 
 *    num--数组个数
 *    len--输出的数组位置
 *
 * 输出：
 * 数组len位置的数据
 */
uint16 Flash_Read_DataBuff(uint32 FlashPtr,uint8 num,uint8 len){
  uint8 read_buffer[4];
  uint8 *ptr;
  ptr = (uint8*)(FlashPtr*512);
  
  uint16 data;
  for(uint8 i=0;i<4;i++){
    read_buffer[i] = *(ptr + i+len*4);
  }
  uint16 temp=0;
  temp=read_buffer[2];
  temp<<=8;
  temp|=read_buffer[3];
  data = temp;
  
  //temp = 0;
  return data;
}
/*
 * Flash_Write_Int
 * flash闪存单扇区整形写入
 *
 * 参数:
 *    FlashPtr--flash闪存扇区,取值:0--127
 *    data--32位有符号整形  
 *
 * 输出:
 *    1--写入成功
 *    0--写入失败
 */
uint8 Flash_Write_Int(uint32 FlashPtr,int32 data){
 
  uint8 result=NULL;
  //写入前先擦除原来数据
  result=FLASH_EraseSector(FlashPtr);
  if(result!=FLASH_OK){return 0;}

  uint8 write_buffer[DATA_SIZE]; //定义写缓冲区
  
  if(data<0){
    data = -data;
    write_buffer[5]=0;
  }
  else{
    write_buffer[5]=1;
  }
  
  
  write_buffer[0]=4;//嵌入标志位，在空间4个
  write_buffer[1]=data/65536/256;//data/65536/256
  write_buffer[2]=data/65536%256;//data/65536%256
  write_buffer[3]=data%65536/256;//data%65536/256
  write_buffer[4]=data%65536%256;//data%65536%256
      
  DisableInterrupts;  
  result=FLASH_WriteSector((uint32)FlashPtr,(uint8*)write_buffer, 8,0);
  EnableInterrupts;
  delay();
        
  if(result==FLASH_OK)
    return 1;
  else
    return 0;
}
/*
 * Flash_Write_Float
 * flash闪存单扇区float型写入
 *
 * 参数:
 *    FlashPtr--flash闪存扇区
 *    data--float型小数，支持负数 
 *
 * 输出:
 *    1--写入成功
 *    0--写入失败
 */
uint8 Flash_Write_Float(uint32 FlashPtr,float data){
  uint8 write_buffer[DATA_SIZE]; //定义写缓冲区
  uint8 result=NULL;
  //写入前先擦除原来数据
  result=FLASH_EraseSector(FlashPtr);
  if(result!=FLASH_OK){return 0;}
  
  if(data<0){
    write_buffer[8] = 0;
    data = -data;
  }
  else{
    write_buffer[8] = 1;
  }
  uint32 tempz=(uint32)data;
  
  
  write_buffer[0]=7;//嵌入标志位，在空间4个
  write_buffer[1]=tempz/65536/256;//tempz/65536/256
  write_buffer[2]=tempz/65536%256;//tempz/65536%256
  write_buffer[3]=tempz%65536/256;//tempz%65536/256
  write_buffer[4]=tempz%65536%256;//tempz%65536%256

  float tempx=data-tempz;
  tempx=tempx*10000000;
  uint32 tempc=(uint32)tempx;
  write_buffer[5]=tempc/65536%256;//tempc/65536%256
  write_buffer[6]=tempc%65536/256;//tempc%65536/256
  write_buffer[7]=tempc%65536%256;//tempc%65536%256
  DisableInterrupts;  
  result=FLASH_WriteSector((uint32)FlashPtr,(uint8*)write_buffer,12,0);
  EnableInterrupts;
  delay();
        
  if(result==FLASH_OK)
    return 1;
  else
    return 0;
}
/*
 * Flash_Read_Int
 * flash闪存单扇区整形数据读取
 *
 * 参数:
 *    FlashPtr--flash闪存扇区,取值:0--127
 *     
 *
 * 输出:
 *    32位无符号整形
 *    
 */
int32 Flash_Read_Int(uint32 FlashPtr){
  uint8 read_buffer[DATA_SIZE];  //定义读缓冲区
  uint8 *ptr;
  int len;
  ptr = (uint8*)(FlashPtr*512);
  
  read_buffer[0] = *ptr;
  if(read_buffer[0]!=4)
    return 0;
  for( len = 1 ; len < 6 ; len++)
  {
    read_buffer[len] = *(ptr + len);
  }   
  
  uint32 temp=0;
  temp=read_buffer[1];
  temp<<=8;
  temp|=read_buffer[2];
  temp<<=8;
  temp|=read_buffer[3];
  temp<<=8;
  temp|=read_buffer[4];
  
  if(read_buffer[5])
    return temp;
  else
    return -temp;
}


/*
 * Flash_Read_Float
 * flash闪存单扇区float型数据读取
 *
 * 参数:
 *    FlashPtr--flash闪存扇区,取值:0--127
 *     
 *
 * 输出:
 *    无符号float型
 *    
 */
float Flash_Read_Float(uint32 FlashPtr){
  uint8 read_buffer[DATA_SIZE];  //定义读缓冲区
  uint8 *ptr;
  int len;
  ptr = (uint8*)(FlashPtr*512);
  
  read_buffer[0] = *ptr;
  if(read_buffer[0]!=7)
    return 0;
  for( len = 1 ; len < 9 ; len++)
  {
    read_buffer[len] = *(ptr + len);
  }   
  
  uint32 temp=0,temp1=0;
  temp=read_buffer[1];
  temp<<=8;
  temp|=read_buffer[2];
  temp<<=8;
  temp|=read_buffer[3];
  temp<<=8;
  temp|=read_buffer[4];
  
  temp1|=read_buffer[5];
  temp1<<=8;
  temp1|=read_buffer[6];
  temp1<<=8;
  temp1|=read_buffer[7];
  
  if(read_buffer[8])
    return temp+temp1/10000000.0;
  else
    return -(temp+temp1/10000000.0);
}


