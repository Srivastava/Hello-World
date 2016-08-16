#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
// #include <unordered_map>

/***************************************************************
/********************                 *******************************************
/*						HOTELS                                                   */
/********************                 *******************************************
/***************************************************************/

int main()
{
	unsigned long long N,M;
	std::cin>>N>>M;

	std::vector<int> values;
	values.reserve(N);

	unsigned long long sum=0;

	unsigned long long max=0;
	int left=0,right=0;
	while(N--)
	{
		int val;
		std::cin>>val;

		sum+=val;
		++right;

		if(sum==M){max=M;break;}

		while(sum>M && left!=right)
		{
			sum-=values[left];
			++left;
			// values.erase(values.begin());t
		}

		if(sum>max && sum<=M){max=sum;}
		values.push_back(val);
	}

	std::cout<<max<<std::endl;

	return 0;
}