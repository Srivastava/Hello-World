#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <map>

/***************************************************************
/********************                 *******************************************
/*						CANDY3                                                   */
/********************                 *******************************************
/***************************************************************/

int main()
{
	int numofInputs;
	std::cin>>numofInputs;

	int i=0;
	int numCandies=0;
	
	// std::cout<<"HERRRRR "<<numofInputs<<std::endl;
	while(i<numofInputs)
	{
		
		int numChildren;
		
		std::cin>>numChildren;
		long long sum=0;
		long long  candies;

		for(int j=0;j<numChildren;++j)
		{
			std::cin>>candies;
			sum+=candies;

			if(sum>=numChildren)
			{
				sum=sum%numChildren;
			}
		}
		if(sum==0)
		{
			std::cout<<"YES"<<std::endl;
		}
		else
		{
			std::cout<<"NO"<<std::endl;
		}

		++i;
	}
}