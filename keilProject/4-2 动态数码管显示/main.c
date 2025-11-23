#include <REGX52.H>
#include <INTRINS.H>
void Delay(unsigned int xms)	
{
	unsigned char data i, j;
	while(xms--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}
unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00};
void Nixie(unsigned char Location,char Number)
{
	switch(Location)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=NixieTable[Number];
	Delay(1000);
	P0=0x00;
}

void main()
{
	
//	老师教导的
//	while(1)
//	{
//		Nixie(1,1);
//		Delay(1);
//		Nixie(2,2);
//		Delay(1);
//		Nixie(3,3);	
//		Delay(1);
//		Nixie(4,4);	
//		Delay(1);
//	}





	
//	从0到16流水灯
	int i;
	int j=-1;
	while(1)
	{
		for(i=1;i<=8;i++)
		{
			j++;
			Nixie(i,j);

			Delay(50);
			if(i>8)
				i=1;

			if(j>=16)
				j=-1;
		}
	}
	
	
	
}


