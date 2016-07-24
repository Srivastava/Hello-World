#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
// #include <map>

/***************************************************************
/********************                 *******************************************
/*						PIGBANK                                                   */
/********************                 *******************************************
/***************************************************************/

int minAmt(const std::vector<int>& cost,const std::vector<int>& weight,const int& actualW, std::vector<int>& min)
{
	// std::vector<std::vector<int> > num(actualW+1,std::vector<int> (cost.size(),0));


	// std::copy(cost.begin(),cost.end(),std::ostream_iterator<int>(std::cout,","));
	// std::cout<<std::endl;

	// std::copy(weight.begin(),weight.end(),std::ostream_iterator<int>(std::cout,","));
	// std::cout<<std::endl;

	// std::vector<int> min(actualW+1,0);
	for(int i=1;i<=actualW;++i)
	{
		for(int j=0;j<cost.size();++j)
		{
			if(weight[j]<=i)
			{
				if(min[i]==0)
				{
					min[i]=min[i-weight[j]]+cost[j];
				}
				else if(min[i-weight[j]]+cost[j]<min[i])
				{
					min[i]=min[i-weight[j]]+cost[j];

				}
				// std::cout<<weight[j]<<" "<<i-weight[j]<<" "<<cost[j]<<" "<<min[i-weight[j]] + cost[j]<<" "<<min[i]<<std::endl;
				// min[i]=min[i-weight[j]]+cost[j];
			} 
		}
	}
	// std::copy(min.begin(),min.end(),std::ostream_iterator<int>(std::cout,","));
	// std::cout<<std::endl;
	return min[actualW];
}

int main()
{
	int nInputs;
	std::cin>>nInputs;

	while(nInputs--)
	{
		int empty,full;
		std::cin>>empty>>full;
		int actualW=full-empty;

		int nDiff;
		std::cin>>nDiff;

		std::vector<int> cost;
		std::vector<int> weight;

		cost.reserve(nDiff);
		weight.reserve(nDiff);

		while(nDiff--)
		{
			int c,w;
			std::cin>>c>>w;

			cost.push_back(c);
			weight.push_back(w);
		}

		std::vector<int> min(actualW+1,0);
		
		int minVal=minAmt(cost,weight,actualW,min);

		if(min[actualW]==min[actualW-1]){std::cout<<"This is impossible."<<std::endl;}
		else
		{
			std::cout<<"The minimum amount of money in the piggy-bank is "<<minVal<<"."<<std::endl;
		}
		// std::cout<<minAmt(cost,weight,actualW,min)<<std::endl;
		// std::copy(cost.begin(),cost.end(),std::ostream_iterator<int>(std::cout,","));
		// std::cout<<std::endl;
		
		// std::copy(weight.begin(),weight.end(),std::ostream_iterator<int>(std::cout,","));
		// std::cout<<std::endl;

	}

	return 0;
}