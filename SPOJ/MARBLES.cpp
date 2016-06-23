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
#include <string>

/***************************************************************
/********************                 *******************************************
/*						MARBLES                                                 */
/********************                 *******************************************
/***************************************************************/
unsigned long long mul(const unsigned long long& start,const unsigned long long& end,const unsigned long long& k)
{
	unsigned long long result;

	unsigned long long count=start+1;

	if(start==0){count=1;}
	double multiply=1;
	unsigned long long knum=1;
	while(count<=end)
	{
		// std::cout<<multiply<<"* ";
		 multiply=(multiply*count)/knum;
		// std::cout<<count<<" **** "<<knum<<std::endl;
		++count;
		++knum;
	}
	// std::cout<<"\n"<<"Knum "<<knum<<std::endl;
	return multiply;
}


unsigned long long combi(const unsigned long long& n, const unsigned long long& k)
{
	
	unsigned long long result1=	mul(n-k,n,k);
	// unsigned long long result2 = mul(1,k);

	return result1;

}

int main()
{
	unsigned long nInputs;
	std::cin>>nInputs;

	while(nInputs--)
	{
		unsigned long long n,k;
		// if(n==k){std::cout<<1<<std::endl;continue;}
		std::cin>>n>>k;

		std::cout<<combi(n-1,k-1)<<std::endl;
	}
	
	return 0;
}