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
typedef std::vector<int> vi;
typedef std::vector<ull> vull;

int main()
{
	int a,n;
	std::cin>>n>>a;

	std::unordered_map<int,int> map;

	vi t(n+1,0);

	for(int i=1;i<=n;++i)
	{
		std::cin>>t[i];

		map[std::abs(a-i)]++;
	}

	ll ans=0;
	for(auto it=map.begin();it!=map.end();++it)
	{
		ll l=a-it->first,r=a+it->first;

		bool left=false,right=false;
		if(l>0)
		{
			t[l]==1? left=true:left=false;
		}
		else
		{
			left=true;
		}
		if(r<n+1)
		{
			t[r]==1? right=true:right=false;
		}
		else
		{
			right=true;
		}

		if(left&&right)
		{
			ans+=it->second;
		}
	}	

	std::cout<<ans<<std::endl;
	return 0;
}