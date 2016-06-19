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
/*						NGM                                                 */
/********************                 *******************************************
/***************************************************************/

int main()
{
	long long start;
	std::cin>>start;
	
	int n = start%10;

	if(n==0)
	{
		std::cout<<2<<std::endl;
	}
	else
	{
		std::cout<<1<<"\n"<<n<<std::endl;
	}
	return 0;
}