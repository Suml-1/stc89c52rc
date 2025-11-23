#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

int result;


void main()
{
	LCD_Init();
//	LCD_ShowChar(1,2,'A');
//	LCD_ShowNum(2,3,123,3);
//	LCD_ShowSignedNum(1,4,-12,2);
//	LCD_ShowHexNum(1,13,0xA8,2);
//	LCD_ShowBinNum(2,8,0xAA,8);
	
	
	
	result=1+1;
	LCD_ShowNum(2,3,result,3);
	
	
	
	
	while(1)
	{
		result++;
		Delay(1000);
		LCD_ShowNum(2,3,result,3);
	}
}
