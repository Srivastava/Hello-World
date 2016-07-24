#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
// #include <unordered_map>
/***************************************************************
/********************                 *******************************************
/*						PARTY                                                   */
/********************                 *******************************************
/***************************************************************/

// std::vector<int> cost;
// std::vector<int> fun;


int maxFun(const std::vector<int>& cost,const std::vector<int>& fun,std::vector< std::vector<int> >& num)
{
	int sizeI=num.size();
	int sizeJ=num[0].size();

	for(int i=1;i<sizeI;++i)
	{
		for(int j=0;j<sizeJ;++j)
		{
			// std::cout<<cost[i-1]<<" "<<j+1<<",";
			if(cost[i-1]>j+1)
			{
				num[i][j]=num[i-1][j];
			}
			else
			{
				num[i][j]=std::max(num[i-1][j],num[i-1][j-cost[i-1]]+fun[i-1]);
			}
		}
		// std::cout<<std::endl;
	}

	// for(int i=0;i<sizeI;++i)
	// {
	// 	for(int j=0;j<sizeJ;++j)
	// 	{
	// 		std::cout<<num[i][j]<<",";
	// 	}
	// 	std::cout<<std::endl;
	// }

	return num[sizeI-1][sizeJ-1];
}

int main()
{
	
	while(1)
	{
		int budget, nParties;
		// std::cin>>budget>>nParties;
		scanf("%d %d",&budget,&nParties);

		if(budget==0 && nParties==0){break;}

		std::vector<std::vector<int> > num(nParties+1,std::vector<int> (budget,0));

		std::vector<int> cost;
		std::vector<int> fun;

		// cost.clear();
		// fun.clear();
		
		cost.reserve(nParties);
		fun.reserve(nParties);

		// std::unordered_map<int,int> map;
		while(nParties--)
		{
			int c,f;
			// std::cin>>c>>f;
		
			scanf("%d %d",&c,&f);

			cost.push_back(c);
			fun.push_back(f);
		}

		int sizeI=num.size();
		int sizeJ=num[0].size();

		int maxVal=maxFun(cost,fun,num);
		int weight=0;
		// std::cout<<"Here"<<std::endl;

		for(int i=sizeJ-1;i>=0;i--)
		{
			// std::cout<<i<<std::endl;
			// std::cout<<num[sizeI-1][i]<<std::endl;
			if(num[sizeI-1][i]!=maxVal)
			{
				weight=i+2;
				break;
			}
		}
		// std::cout<< weight<<" "<<maxVal<<std::endl;
		printf("%d %d\n",weight,maxVal );

	}
	return 0;
}