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

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

int main()
{
	vll t(5,0);

	std::unordered_map<int,int> map;


	ll sum=0,max=0;
	for(int i=0;i<5;++i)
	{
		ll val;
		std::cin>>val;

		sum+=val;
		map[val]++;

		if(map[val]>1 && map[val]<=3)
		{
			// std::cout<<val*map[val]<<" "<<val<<" "<<map[val]<<std::endl;
			if(max<val*map[val])
			{
				max=val*map[val];
			}
		}
	}

	std::cout<<sum-max<<std::endl;

	// for(auto it=map.begin();it!=map.end();++it)
	// {
	// 	std::cout<<it->first<<" "<<it->second<<std::endl;
	// }
	return 0;
}