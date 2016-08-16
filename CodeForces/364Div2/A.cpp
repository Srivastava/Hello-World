#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <map>

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

int main()
{
	ll n;
	std::cin>>n;

	std::multimap<ll,ll> map;
	vll a(n+1,0);

	ll sum=0;
	for(ll i =1;i<=n;++i)
	{
		// ll val;
		// std::cin>>val;

		std::cin>>a[i];
		map.insert(std::make_pair(a[i],i));
		// std::cin>>a[i];
		sum+=a[i];
	}

	ll avg=(sum*2)/n;
	

	// std::cout<<avg<<std::endl;
	std::vector<bool> d(n+1,false);

	for(int i=1;i<=n;++i)
	{
		if(d[i]==true)
		{
			// std::cout<<i<<std::endl;
			continue;
		}

		// std::cout<<i<<std::endl;
		d[i]=true;
		for(int j=i+1;j<=n;++j)
		{
			if(d[j]==false)
			{
				if(a[j]==avg-a[i])
				{
					std::cout<<i<<" "<<j<<std::endl;
					d[j]=true;
					break;

				}
				
			}
		}
	}

	return 0;
}