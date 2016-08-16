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
/*						HYPNOS                                                 */
/********************                 *******************************************
/***************************************************************/

long long happyNum(const long long& num)
{
	long long n=num;

	int count=0;
	int first=0;

	int sum=11;
	while(1)
	{
		sum=0;
		++count;

		while(n)
		{

			// std::cout<<n<<" N "<<std::endl;
			int p =n%10;
			sum+=p*p;
			n/=10;
		}
		
		if(count==1){first=sum;}

		if(sum==4){return -1;break;}
		// std::cout<<sum<<" SUM "<<std::endl;
		n=sum;
		if(sum==1){return count;}
	}

	// if(n!=1){return -1;}
	// return count;
}

int main()
{
	long long num;

	std::cin>>num;

	std::cout<<happyNum(num)<<std::endl;

	return 0;
}