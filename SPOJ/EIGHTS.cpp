#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <map>

/***************************************************************
/********************                 *******************************************
/*						EIGHTS                                                   */
/********************                 *******************************************
/***************************************************************/


int main()
{
	int testCases;
	std::cin>>testCases;

	int i=0;
	while(i<testCases)
	{
		unsigned long long int n;
		std::cin>>n;

		unsigned long long int ans=192+(n-1)*250;
		std::cout<<ans<<std::endl;
		++i;

	}
	
	return 0;
}