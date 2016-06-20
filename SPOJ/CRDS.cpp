#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>

/***************************************************************
/********************                 *******************************************
/*						CRDS                                                 */
/********************                 *******************************************
/***************************************************************/

long long numCards(long long& n)
{
	return n*(n+1) + ((n-1)*n)/2;
}


int main()
{
	int numofInputs;
	std::cin>>numofInputs;
	long long i=0;

	while(i<numofInputs)
	{
		++i;

		long long n;
		std::cin>>n;

		long long ans=numCards(n);
		ans=ans%1000007;
		std::cout<<ans<<std::endl;
		
		
	}
	return 0;
}