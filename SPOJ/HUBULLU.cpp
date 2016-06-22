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

	return "Wins";
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