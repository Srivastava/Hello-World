#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

int main()
{
	unsigned long long n;
	std::cin>>n;

	std::vector<unsigned long long> value;
	
	unsigned long long sum=0,score=0;
	while(n--)
	{
		unsigned long long val;
		std::cin>>val;
		
		sum+=val;

		value.push_back(val);
	}

	std::sort(value.begin(),value.end());
	std::reverse(value.begin(),value.end());
	// std::cout<<sum<<std::endl;
	score=sum;
	// sum+sum;
	// int count=0;
	// for(const auto& it:value)
	// {
	// 	count+=it;
	// 	sum+=sum-count;
	// 	std::cout<<sum<<std::endl;

	// }


	// score=
	unsigned long long  val=value[0];
	for(int i=1;i<value.size();++i)
	{
		val+=value[i];
		score+=val;
		// std::cout<<score<<std::endl;

	}
	std::cout<<score<<std::endl;

	return 0;
}