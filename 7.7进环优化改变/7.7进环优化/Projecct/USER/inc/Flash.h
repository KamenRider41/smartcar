#ifndef _Flash_h
#define _Flash_h

#include "headfile.h"

#define FLASH_OK 0x00
#define DATA_SIZE           (10)


//flash闪存单扇区整形写入
uint8 Flash_Write_Int(uint32 ,int32 );
//flash闪存单扇区float型写入
uint8 Flash_Write_Float(uint32 ,float );
//flash闪存单扇区整形数据读取
int32 Flash_Read_Int(uint32 );
//flash闪存单扇区float型数据读取
float Flash_Read_Float(uint32 );

//flash闪存单扇区int16（长度为50）的数组
void Flash_Write_DataBuff(uint32 ,uint16 *,uint8 );
uint16 Flash_Read_DataBuff(uint32 ,uint8 ,uint8 );
#endif