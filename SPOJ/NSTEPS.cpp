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
/*						NSTEPS                                                  */
/********************                 *******************************************
/***************************************************************/

// struct Point
// {
// 	int x,y;
// };

int main()
{
	int numofInputs;
	std::cin>>numofInputs;

	int i=0;
	while(i<numofInputs)
	{
		int x,y;
		std::cin>>x>>y;

		if(x<y){std::cout<<"No Number"<<std::endl;}
		else if(abs(x-y)!=2 && abs(x-y)!=0){std::cout<<"No Number"<<std::endl;}

		else if(x%2==0){std::cout<<x+y<<std::endl;}
		else{std::cout<<x+y-1<<std::endl;}

		++i;
	}


	return 0;
}