#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

int main()
{
	ll n;
	std::cin>>n;

	std::string str;
	std::cin>>str;

	ll prev,curr;
	
	std::cin>>prev;
	
	ll min=1e12;

	for(int i=1;i<n;++i)
	{
		std::cin>>curr;

		if(str[i-1]=='R' && str[i]=='L')
		{
			// std::cout<<curr<<" "<<prev<<std::endl;
			if(min>curr-prev)
			{
				min=curr-prev;
			}
		}
		prev=curr;
	}

	if(min==1e12)
	{
		std::cout<<-1<<std::endl;
	}
	else
	{

		std::cout<<min/2<<std::endl;
	}
	return 0;
}