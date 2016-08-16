#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <set>

/***************************************************************
/********************                 *******************************************
/*						TWOSQRS                                                   */
/********************                 *******************************************
/***************************************************************/

bool isSqNum(const unsigned long long& n)
{
	unsigned long long m=sqrt(n);

	if(m*m==n)
	{
		return true;
	}

	unsigned long long count=1;

	while(count<m+1)
	{
		unsigned long long check=sqrt(n-count*count);

		if(check*check + count*count == n)
		{
			return true;
		}
		++count;
	}
	return false;

}

int main()
{

	int nInputs;
	std::cin>>nInputs;

	while(nInputs--)
	{
		unsigned long long n;
		std::cin>>n;

		if(isSqNum(n))
		{
			std::cout<<"Yes"<<std::endl;
		}
		else
		{
			std::cout<<"No"<<std::endl;
		}

	}

	return 0;
}