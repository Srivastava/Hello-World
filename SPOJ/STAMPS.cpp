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
/*						STAMPS                                                 */
/********************                 *******************************************
/***************************************************************/

int main()
{
	int numofInputs;
	std::cin>>numofInputs;

	int i=0;
	while(i<numofInputs)
	{
		++i;

		int stamps,friends;

		std::cin>>stamps>>friends;

		int j=0;
		std::vector<int> vec;
		while(j<friends)
		{
			++j;

			int val;
			std::cin>>val;

			vec.push_back(val);
		}

		std::sort(vec.begin(),vec.end());

		int sum=0;
		int index=0;
		for(int k=friends-1;k>=0;--k)
		{
			sum+=vec[k];
			++index;
			if(sum>=stamps){break;}
		}

		if(index==friends && sum<stamps)
		{
			std::cout<<"Scenario #"<<i<<":\n";
			std::cout<<"impossible"<<std::endl;
		}
		else
		{
			std::cout<<"Scenario #"<<i<<":\n";
			std::cout<<index<<std::endl;
		}

	}
	return 0;
}