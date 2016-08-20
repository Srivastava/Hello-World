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

vpa g[100005];

int main()
{
	int n,m,k;
	std::cin>>n>>m>>k;

	for(int i=0;i<m;++i)
	{
		ll u,v,l;
		std::cin>>u>>v>>l;

		g[u].push_back(std::make_pair(v,l));
		g[v].push_back(std::make_pair(u,l));
	}

	vll baker(k,0);
	vb bcity(n+1,false);
	for(int i =0;i<k;++i)
	{
		std::cin>>baker[i];
		bcity[baker[i]]=true;
	}

	/*for(int i=1;i<=n;++i)
	{
		for(int j=0;j<g[i].size();++j)
		{
			std::cout<<g[i][j].first<<" "<<g[i][j].second<<",";
		}
		std::cout<<std::endl;
	}
*/
	ll ans=1e15;

	for(int i=0;i<k;++i)
	{
		int b = baker[i];

		for(int j=0;j<g[b].size();++j)
		{
			pa u = g[b][j];
			if(!bcity[u.first])
			{
				ans=std::min(ans,u.second);
			}
				
		}
	}

	if(ans==1e15)
	{
		std::cout<<-1<<std::endl;
	}
	else
	{
		std::cout<<ans<<std::endl;
	}
	return 0;
}