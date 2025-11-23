#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"


void main()
{
	
	
	while(1)
	{
		Nixie(1,1);
		Delay(1);
		Nixie(2,2);
		Delay(1);
		Nixie(3,3);	
		Delay(1);
		Nixie(4,4);	
		Delay(1);
	}
	
	
}


