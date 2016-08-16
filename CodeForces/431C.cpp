#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <cstring>

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::vector<vll> vvll;

ll n,d,k;
ll dp[2002][200];


ll solve(ll sum,bool pick)
{
	ll ans=0;
	int val = pick==true ? 1:0;
	if(dp[sum][val]!=-1)
	{
		return dp[sum][val];
	}
	// std::cout<<sum<<" "<<pick<<std::endl;
	if(sum==0)
	{
		return pick==true ? 1:0;
	}

	for(ll i=1;i<=k;++i)
	{
		if(i>=d && sum-i>=0)
		{
			ans+=(solve(sum-i,true))%MOD;
		}
		else if(sum-i>=0)
		{
			ans+=(solve(sum-i,pick))%MOD;
		}
	}

	// std::cout<<sum<<" "<<val<<" "<<dp[sum][val]<<std::endl;

	dp[sum][val]=ans;
	// std::cout<<sum<<" "<<val<<" * "<<dp[sum][val]<<std::endl;

	return ans%MOD;
}

int main()
{
	// ll n,d,k;
	std::ios_base::sync_with_stdio(false);

	std::cin>>n>>k>>d;
	std::memset(dp,-1,sizeof(dp));
	
	(solve(n,false));
	// for(int i=0;i<=n;++i)
	// {
	// 	for(int j=0;j<=1;++j)
	// 	{
	// 		std::cout<<dp[i][j];
	// 	}
	// 	std::cout<<std::endl;
	// }
	std::cout<<dp[n][0]%MOD<<std::endl;
	return 0;
}