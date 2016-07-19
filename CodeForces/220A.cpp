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

	vll a(n,0);

	for(ll i=0;i<n;++i)
	{
		std::cin>>a[i];
	}
	vll b=a;

	std::sort(b.begin(),b.end());
	ll count=0;
	bool ans=true;
	for(int i=0;i<n;++i)
	{
		// std::cout<<a[i]<<" "<<b[i]<<" "<<std::endl;
		if(a[i] !=b[i])
		{
			++count;
		}

		if(count>2)
		{
			ans=false;
		}
	}

	if(ans)
	{
		std::cout<<"YES"<<std::endl;
	}
	else
	{
		std::cout<<"NO"<<std::endl;
	}

	return 0;

}