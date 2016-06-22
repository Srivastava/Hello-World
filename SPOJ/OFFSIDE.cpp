#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>

/***************************************************************
/********************                 *******************************************
/*						OFFSIDE                                                   */
/********************                 *******************************************
/***************************************************************/

int main()
{

	while(1)
	{

		int nAttack, nDefend;
		std::cin>>nAttack>>nDefend;

		if(nAttack==0 && nDefend==0){break;}
		std::vector<int> attackers;
		attackers.reserve(nAttack);

		std::vector<int> defenders;
		defenders.reserve(nDefend);


		for(int i=0;i<nAttack;++i)
		{
			int num;
			std::cin>>num;

			attackers.push_back(num);
		}

		for(int i=0;i<nDefend;++i)
		{
			int num;
			std::cin>>num;

			defenders.push_back(num);
		}

		std::sort(attackers.begin(),attackers.end());
		std::sort(defenders.begin(),defenders.end());

		bool offside=false;
		for(int i=0;i<nAttack;++i)
		{
			if(attackers[i]<defenders[1])
			{
				offside=true;
				break;
			}
		}

		if(offside)
		{
			std::cout<<"Y"<<std::endl;
		}

		else
		{
			std::cout<<"N"<<std::endl;
		}
			

	}

	return 0;
}