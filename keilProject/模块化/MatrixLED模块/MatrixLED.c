#include <REGX52.H>
#include "Delay.h"

//定义管脚地址
sbit RCK =P3^5;		//RCLK
sbit SCK =P3^6;		//SRCLK
sbit SER =P3^4;		//SER

#define MATRIX_LED_PORT		P0


/**
  * @brief  74HC595写入一个字节
  * @param  要写入的字节
  * @retval 无
  */
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);		//从高为至低位，逐步写入字节数据
		SCK=1;     //数据上移
		SCK=0;     //置零
	}	
	RCK=1;		//数据整体发送
	RCK=0;		//置零
}


/**
  * @brief  点阵屏初始化
  * @param  
  * @retval 
  */
void MatrixLED_Init()
{
	SCK=0;
	RCK=0;
}


/**
  * @brief  LED点阵屏显示一列数据
  * @param  Column 要选中的列（1-8，0在最左边）
  * @param  Data 选择列要显示的数据（0x00-0xff,高位在上，1为亮，0为灭）
  * @retval 无
  */
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT=~(0x80>>(Column-1));
	Delay(1);	
	MATRIX_LED_PORT=0xFF;	
}
