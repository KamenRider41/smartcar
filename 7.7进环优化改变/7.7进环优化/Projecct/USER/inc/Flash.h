#ifndef _Flash_h
#define _Flash_h

#include "headfile.h"

#define FLASH_OK 0x00
#define DATA_SIZE           (10)


//flash���浥��������д��
uint8 Flash_Write_Int(uint32 ,int32 );
//flash���浥����float��д��
uint8 Flash_Write_Float(uint32 ,float );
//flash���浥�����������ݶ�ȡ
int32 Flash_Read_Int(uint32 );
//flash���浥����float�����ݶ�ȡ
float Flash_Read_Float(uint32 );

//flash���浥����int16������Ϊ50��������
void Flash_Write_DataBuff(uint32 ,uint16 *,uint8 );
uint16 Flash_Read_DataBuff(uint32 ,uint8 ,uint8 );
#endif