#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>

/***************************************************************
/********************                 *******************************************
/*						FASHION                                                 */
/********************                 *******************************************
/***************************************************************/

int main()
{
	int numofInputs;

	std::cin>>numofInputs;

	int i=0;
	while(i<numofInputs)
	{
		int numofPairs;
		std::cin>>numofPairs;
		
		std::vector<int> men,women;
		men.reserve(numofPairs);
		women.reserve(numofPairs);

		for(int j=0;j<numofPairs;++j)
		{
			int val;
			std::cin>>val;
			men.push_back(val);
		}
		std::sort(men.begin(),men.end());
		
		for(int j=0;j<numofPairs;++j)
		{
			int val;
			std::cin>>val;
			women.push_back(val);int
		}
		std::sort(women.begin(),women.end());

		int sum=0;
		for(int j=0;j<numofPairs;++j)
		{
			sum+=men[j]*women[j];
		}

		std::cout<<sum<<std::endl;

		++i;
	}

	return 0;
}