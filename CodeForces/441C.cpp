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

// const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::vector<std::pair<ll,ll> > pvll;

int main()
{
	ll n,m,k;
	std::cin>>n>>m>>k;


	pvll val;

	// ll count=1;
	for(int i=1;i<=n;++i)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=m;++j)
			{
				val.push_back(std::make_pair(i,j));
			}
		}

		else
		{
			for(int j=m;j>=1;--j)
			{
				val.push_back(std::make_pair(i,j));
			}
		}
			
	}

	ll div=((val.size())/k);

	// std::cout<<val.size()<<std::endl;
	ll count=0,left=0,right=0;
	while(count<k)
	{
		right=left+div;

		if(count==k-1 && right!=val.size())
		{
			right=val.size();
		}

		std::cout<<right-left<<" ";
		for(ll i = left;i<right;++i)
		{
			std::cout<<val[i].first<<" "<<val[i].second<<" ";
		}
		++count;
		left=right;
		std::cout<<std::endl;
	}

	return 0;
		
}