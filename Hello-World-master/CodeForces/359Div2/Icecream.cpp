#include <iostream>
#include <vector>o
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
/*						ICECREAM                                                 */
/********************                 *******************************************
/***************************************************************/

int main()
{
	int n;
	unsigned long long x;
	std::cin>>n>>x;

	unsigned long long sum=x;
	unsigned long long distressed=0;
	while(n--)
	{
		char c;
		int val;

		std::cin>>c>>val;

		if(c=='+')
		{
			sum+=val;
		}
		else if(c=='-')
		{
			if(sum<val)
			{
				++distressed;
			}
			else
			{
				sum-=val;
			}

		}


	}
	std::cout<<sum<<" "<<distressed<<std::endl;

	return 0;

}