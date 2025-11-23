#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

void main()
{
	LCD_Init();
//	LCD_ShowChar(2,3,0xE0);	
//	LCD_ShowString(1,1,"Hello");
//	LCD_ShowNum(2,5,356,3);
//	
	//流动字幕
	
	
	LCD_ShowString(1,16,"Welcome to China!");
	while(1)
	{
		Delay(20);
		LCD_WriteCommand(0x18);
		Delay(500);
	}
}
