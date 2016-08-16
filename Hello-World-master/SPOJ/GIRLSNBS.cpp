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
/*						GIRLSNBS                                                 */
/********************                 *******************************************
/***************************************************************/

int main()
{

	double girls,boys;

	while(1)
	{
		std::cin>>girls>>boys;
		int ans;

		if(girls==-1 || boys==-1)
		{
			break;
		}
		if(girls==0 && boys ==0)
		{
			// std::cout<<0<<std::endl;
			ans=0;
		}

		else
		{
			if(girls==0){ans=boys;}
			else if(boys==0){ans=girls;}

			else
			{
				if(girls<=boys)
				{
					ans=ceil((boys/(girls+1)));
				}

				else
				{
					// std::cout<<((girls/(boys+1)))<<std::endl;
					ans=ceil((girls/(boys+1)));
				}
			}

		}
		std::cout<<ans<<std::endl;
	}
	return 0;
}