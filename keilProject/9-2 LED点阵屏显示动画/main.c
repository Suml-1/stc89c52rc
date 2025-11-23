#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"
#include "Timer0.h"

unsigned char Animation[]={
	0x3C,0x42,0xA9,0x85,0x85,0xA9,0x42,0x3C,
	0x3C,0x42,0xA5,0x85,0x85,0xA5,0x42,0x3C,
	0x3C,0x42,0xA5,0x89,0x89,0xA5,0x42,0x3C,
};

unsigned char Offest=0;

void main()
{
	unsigned char i;
	Timer0_Init();
	MatrixLED_Init();
	while(1)
	{	
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,Animation[i+Offest]);	
		}

	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TH0 = 0xFC;				
	TL0 = 0x66;	
	T0Count++;
	if(T0Count>=300)
	{
		T0Count=0;
		Offest+=8;
		if(Offest>16)
			Offest=0;
	}
}