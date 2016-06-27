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
/*						CANDY                                                 */
/********************                 *******************************************
/***************************************************************/

int main()
{



	int i=0;
	while(1)
	{
		int numofPackets;
		std::cin>>numofPackets;

		if(numofPackets==-1){break;}

		std::vector<int> candies;
		candies.reserve(numofPackets);


		int sum=0;
		
		for(int j=0;j<numofPackets;++j)
		{
			int val;
			std::cin>>val;
			sum+=val;
			candies.push_back(val);
		}

		double div= double(sum)/double(numofPackets);
		if(div!=floor(div)){std::cout<<"-1"<<std::endl;}
		else
		{
			int numofSteps=0;
			for(int k=0;k<numofPackets;++k)
			{
				int diff=div-candies[k];
				// std::cout<<diff<<" "<<candies[k]<<std::endl;
				if(diff>0){numofSteps+=diff;/*std::cout<<numofSteps<<" numofSteps "<<std::endl;*/}
				
			}
			std::cout<<numofSteps/*<<" here "<<div*/<<std::endl;
		}
		++i;
	}



	return 0;
}