#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
// #include <map>

/***************************************************************
/********************                 *******************************************
/*						304Div2C                                                */
/********************                 *******************************************
/***************************************************************/

int main()
{
	unsigned long long k;
	std::cin>>k;
	unsigned long long n,m;
	std::cin>>n;

	std::queue<unsigned long long> a,b;

	// while
	while(n--)
	{
		unsigned long long val;
		std::cin>>val;
		a.push(val);
	}

	std::cin>>m;
	while(m--)
	{
		unsigned long long val;
		std::cin>>val;

		b.push(val);
	}

	unsigned long long count=0;
	bool valid=true;
	unsigned long long frontA=a.front(),frontB=b.front();
	int sizeA=a.size(),sizeB=b.size();

	while(1)
	{
		unsigned long long u=a.front(),v=b.front();
		a.pop();b.pop();

		if(u>v)
		{
			a.push(v);
			a.push(u);
		}
		else
		{
			b.push(u);
			b.push(v);
		}
		++count;

		// std::cout<<u<<" "<<v<<" "<<count<<std::endl;
		if(a.empty())
		{
			std::cout<<count<<" "<<2<<std::endl;
			break;
		}
		if(b.empty())
		{
			std::cout<<count<<" "<<1<<std::endl;
			break;
		}
		// if((frontA==a.front() && frontB==b.front())&&(sizeA==a.size() && sizeB==b.size()))
		// {
		// 	valid=false;
		// 	std::cout<<-1<<std::endl;
		// 	break;
		// }
		if(count>39916800)
		{
			std::cout<<-1<<std::endl;
			break;
		}

	}


	return 0;
}