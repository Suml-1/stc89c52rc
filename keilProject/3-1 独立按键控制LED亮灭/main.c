#include <REGX52.H>
#include <intrins.h>
void main()
{
//	P2=0xFE;
//	P2_0=0;
//	P2_4=0;
//	P2_3=0;
	while(1)
	{
		if(P3_1==0)
		{
			P2_0=0;
		}
		else
			P2_0=1;
		
	}

}
