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
	ll m;
	std::cin>>m;

	ll k=1;
	while(k*k*k<=m)
	{
		++k;
	}
	k-=1;
	std::cout<<k<<std::endl;

	vll val,fac;
	for(ll i=2;i<=k;++i)
	{
		val.push_back(i*i*i);
	}

	std::copy(val.begin(),val.end(),std::ostream_iterator<ll>(std::cout," "));
	std::cout<<" VAL---------- "<<std::endl;
	for(ll i=0;i<val.size();++i)
	{
		ll count=1;
		// fac.push_back(val[i]);
		while(count*val[i]<=m)
		{
			fac.push_back(val[i]*count);
			++count;
		}

	}

	std::sort(fac.begin(),fac.end());
	
	std::copy(fac.begin(),fac.end(),std::ostream_iterator<ll>(std::cout," "));
	std::cout<<" FAC---------- "<<std::endl;

	vll dp(m+1,0);

	ll ans=1;

	ll prev=1;

	for(ll i=1;i<=m;++i)
	{
		bool factor=false;



		for(ll j=0;j<fac.size();++j)
		{
			if(i<fac[j])
			{
				break;
			}
			else
			{
				if(i%fac[j]==0)
				{
					factor=true;
					dp[i]=i/fac[j];
					prev=fac[j];
					break;
				}
			}
		}

		if(!factor)
		{
			dp[i]=std::min(dp[i-prev]+1,dp[i-1]+1);
			if(dp[ans]<dp[i])
			{
				ans=i;
			}
		}
	}

std::copy(dp.begin(),dp.end(),std::ostream_iterator<ll>(std::cout," "));
std::cout<<" DP---------- "<<std::endl;

std::cout<<dp[ans]<<" "<<ans<<std::endl;

	return 0;
}