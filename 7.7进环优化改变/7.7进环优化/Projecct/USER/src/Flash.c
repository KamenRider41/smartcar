#include "Flash.h"



/*
 * ��ʱһ��ʱ��
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
 * flash���浥������������д��
 *
 * ����:
 *    FlashPtr--flash��������,ȡֵ:0--255
 *    *data--16��32λ�޷�����������  
 *    num--�������
 */

void Flash_Write_DataBuff(uint32 FlashPtr,uint16 *data,uint8 num){
  uint8 result=NULL;
  //д��ǰ�Ȳ���ԭ������
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
 * flash���浥���������������
 *
 * ����:
 *    FlashPtr--flash��������,ȡֵ:0--255 
 *    num--�������
 *    len--���������λ��
 *
 * �����
 * ����lenλ�õ�����
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
 * flash���浥��������д��
 *
 * ����:
 *    FlashPtr--flash��������,ȡֵ:0--127
 *    data--32λ�з�������  
 *
 * ���:
 *    1--д��ɹ�
 *    0--д��ʧ��
 */
uint8 Flash_Write_Int(uint32 FlashPtr,int32 data){
 
  uint8 result=NULL;
  //д��ǰ�Ȳ���ԭ������
  result=FLASH_EraseSector(FlashPtr);
  if(result!=FLASH_OK){return 0;}

  uint8 write_buffer[DATA_SIZE]; //����д������
  
  if(data<0){
    data = -data;
    write_buffer[5]=0;
  }
  else{
    write_buffer[5]=1;
  }
  
  
  write_buffer[0]=4;//Ƕ���־λ���ڿռ�4��
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
 * flash���浥����float��д��
 *
 * ����:
 *    FlashPtr--flash��������
 *    data--float��С����֧�ָ��� 
 *
 * ���:
 *    1--д��ɹ�
 *    0--д��ʧ��
 */
uint8 Flash_Write_Float(uint32 FlashPtr,float data){
  uint8 write_buffer[DATA_SIZE]; //����д������
  uint8 result=NULL;
  //д��ǰ�Ȳ���ԭ������
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
  
  
  write_buffer[0]=7;//Ƕ���־λ���ڿռ�4��
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
 * flash���浥�����������ݶ�ȡ
 *
 * ����:
 *    FlashPtr--flash��������,ȡֵ:0--127
 *     
 *
 * ���:
 *    32λ�޷�������
 *    
 */
int32 Flash_Read_Int(uint32 FlashPtr){
  uint8 read_buffer[DATA_SIZE];  //�����������
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
 * flash���浥����float�����ݶ�ȡ
 *
 * ����:
 *    FlashPtr--flash��������,ȡֵ:0--127
 *     
 *
 * ���:
 *    �޷���float��
 *    
 */
float Flash_Read_Float(uint32 FlashPtr){
  uint8 read_buffer[DATA_SIZE];  //�����������
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


