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
/*						HUBULLU                                                 */
/********************                 *******************************************
/***************************************************************/

std::string whoWins(const long long& a, int b)
{
	if(b==0)
	{
		return "Airborne wins.";
	}

	else
	{
		return "Pagfloyd wins.";
	}
	
}
int main()
{
	long long int n;
	std::cin>>n;

	while(n--)
	{
		long long a;
		int b;

		std::cin>>a>>b;

		std::cout<<whoWins(a,b)<<std::endl;
	}

	return 0;
}