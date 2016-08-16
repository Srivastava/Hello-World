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

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

vll g[100005];

int main()
{
	ll n,m;
	std::cin>>n>>m;

	// vvll g(n+1,vll(1,0));

	for(int i=1;i<=m;++i)
	{
		ll u,v;
		std::cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vll dp(n+1,0);

	dp[1]=1;

	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<g[i].size();++j)
		{
			int k= g[i][j];

			if(k<i)
			{
				dp[i]=std::max(dp[k]+1,dp[i]);
			}
		}

		if(dp[i]==0){dp[i]=1;}
	}

	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		ll size=g[i].size();
		ans=std::max(dp[i]*size,ans);
	}

	/*std::copy(dp.begin(),dp.end(),std::ostream_iterator<ll>(std::cout,","));
	std::cout<<std::endl;*/
	std::cout<<ans<<std::endl;
	return 0;
}