#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>

/***************************************************************
/********************                 *******************************************
/*						AMR10G                                                   */
/********************                 *******************************************
/***************************************************************/

unsigned long long difference(std::vector<unsigned long long> input,const int& k)
{
	std::sort(input.begin(),input.end());

	unsigned long long diff=input[k-1]-input[0];

	for(auto it=input.begin();it<input.end()-k+1;++it)
	{
		auto its=it+k-1;
		// std::cout<<*it<<" "<<*its<<std::endl;

		if(diff>*its-*it)
		{
			diff=*its-*it;
		}
	}
	return diff;
}

int main()
{

	int nInputs;
	std::cin>>nInputs;

	while(nInputs--)
	{
		int n,k;
		std::cin>>n>>k;

		std::vector<unsigned long long> input;
		for(int i=0;i<n;++i)
		{
			unsigned long long val;
			std::cin>>val;

			input.push_back(val);
		}

		std::cout<<difference(input,k)<<std::endl;

	}
	return 0;
}