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


ll summing(ll n)
{
	// std::cout<<" Here Sum"<<std::endl;
	ll s=0;
	while(n)
	{	
		s+=n%10;
		n/=10;
		// std::cout<<" Here Sum 1"<<std::endl;
		// ++count;
	}
	return s;
}

int main()
{
	ll n;
	std::cin>>n;

	ll temp=n;

	ll sum=0,count=0;

	// std::cout<<" Here "<<std::endl;
	while(temp)
	{	
		sum=temp%10;
		temp/=10;
		++count;
	}

	// std::cout<<" Here 1"<<std::endl;
	ll min=n-9*count-19;
	
	// std::cout<<" Here 2"<<std::endl;
	ll ans=0;

	while(min!=n)
	{
		ll s=summing(min);
		if(min+s+summing(s)==n)
		{
			std::cout<<min<<std::endl;
			++ans;
		}
		++min;

	}

	std::cout<<ans<<std::endl;


	return 0;
}
