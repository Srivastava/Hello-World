#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>

/***************************************************************
/********************                 *******************************************
/*						BEENUMS                                                 */
/********************                 *******************************************
/***************************************************************/

int main()
{
	while(1)
	{
		unsigned long long numofInputs;
		std::cin>>numofInputs;

		if(numofInputs==-1){break;}

		bool beehive=false;
		if((numofInputs-1)%6==0)
		{
			for(int i=0;i<=numofInputs/6;++i)
			{
				if(3*i*(i+1)+1==numofInputs)
				{
					
					beehive=true;
					break;
				}
			}
			if(beehive){std::cout<<"Y"<<std::endl;beehive=false;}
			else{std::cout<<"N"<<std::endl;}
		}
		else{std::cout<<"N"<<std::endl;}
	}



	return 0;
}