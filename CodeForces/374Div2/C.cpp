#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <stack>

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

// const int maxn=5005;
const ll inf =1e11;


int main()
{
	// std::cout<<"here"<<std::endl;
	
	// std::cout<<"here 1"<<std::endl;
	
	// std::cout<<"here 2"<<std::endl;

	

	ll n,m,t;
	std::cin>>n>>m>>t;

	pa dp[n+5][n+5];
	vpa edge[n+5];
	std::stack<int> ans;
	for(ll i=0;i<=n;++i)
	{
		for(ll j=0;j<=n;++j)
		{
			dp[i][j]=std::make_pair(inf,inf);
		}
	}

	dp[1][0]=std::make_pair(0,0);

	for(ll i=0;i<m;++i)
	{
		ll u,v,w;
		std::cin>>u>>v>>w;
		u--;v--;

		edge[u].push_back(std::make_pair(w,v));
	}

	for(ll i=1;i<n;++i)
	{
		for(ll j=0;j<n;++j)
		{
			for(ll k=0;k<edge[j].size();++k)
			{
				ll v=edge[j][k].second;
				ll w=edge[j][k].first;
				if(dp[i][j].first!=inf && dp[i][j].first +w<=t )
				{
					dp[i+1][v]=std::min(dp[i+1][v],std::make_pair(dp[i][j].first+w,j));
				}
			}
		}
	}

	for(ll i=n;i>0;--i)
	{
		ll j=n-1;
		if(dp[i][j].first>t)
		{
			continue;
		}
		ll u=j;
		// std::cout<<u<<" "<<j<<" "<<n<<std::endl;
		ans.push(u);
		std::cout<<i<<std::endl;
		for(ll k=i;k>=2;--k)
		{
			u=dp[k][u].second;
			// std::cout<<u<<" u "<<std::endl;
			ans.push(u);
		}
		while(!ans.empty())
		{
			std::cout<<ans.top()+1<<" ";
			ans.pop();
		}
		return 0;
	}
	std::cout<<-1<<std::endl;
	return 0;
}