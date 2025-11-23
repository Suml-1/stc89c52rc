#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"


void main()
{
	MatrixLED_Init();
	while(1)
	{	//LED矩阵屏输出爱心图案
		MatrixLED_ShowColumn(1,0x30);
		MatrixLED_ShowColumn(2,0x78);
		MatrixLED_ShowColumn(3,0x7C);
		MatrixLED_ShowColumn(4,0x3E);
		MatrixLED_ShowColumn(5,0x3E);
		MatrixLED_ShowColumn(6,0x7C);
		MatrixLED_ShowColumn(7,0x78);
		MatrixLED_ShowColumn(8,0x30);		
	}
}
