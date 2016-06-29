#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <unordered_map>
/***************************************************************
/********************                 *******************************************
/*						PARTY                                                   */
/********************                 *******************************************
/***************************************************************/


std::pair<int,int> party(const int& budget,const std::unordered_map<int,int>& map,const std::vector<int>& cost)
{
	int size=cost.size();
	std::vector<int> tempCost=cost;
	std::sort(tempCost.begin(),tempCost.end());

	std::vector<std::vector<int> > num(size,std::vector<int> (budget+1,0));

	for(int i = 0;i<size+1;++i)
	{
		for(int j = 1;j<budget+1;++j)
		{
			// if(j<tempCost[i])
		}
	}
}

int main()
{
	int budget, nParties;
	std::cin>>budget>>nParties;

	while(1)
	{

		if(budget==0 && nParties==0){break;}

		std::vector<int> cost;
		std::vector<int> fun;
		
		cost.reserve(nParties);
		fun.reserve(nParties);

		std::unordered_map<int,int> map;
		while(nParties--)
		{
			int c,f;
			std::cin>>c>>f;
		
			auto it=map.find(c);
			if(it==map.end())
			{
				map.insert({c,f});
			}
			else
			{
				if(it->second < f)
				{
					it->second=f;
				}
			}

			
			// cost.push_back(c);
			// fun.push_back(f);
		
		}
	}
	return 0;
}