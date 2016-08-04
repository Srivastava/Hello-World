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

int main()
{
	ll n,m;
	std::cin>>n>>m;

	vll g[105];

	vll edge(n+1,0);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		std::cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i=1;i<=n;++i)
	{
		edge[i]=g[i].size();
		// std::cout<<edge[i]<<" * "<<i<<std::endl;
	}

	bool run=true;
	ll ans=0;
	while(run)
	{
		run=false;
		vll ded;
		// std::cout<<"HERE"<<std::endl;
		for(int i=1;i<=n;++i)
		{
			if(edge[i]==1)
			{
				// std::cout<<i<<" "<<edge[i]<<" "<<edge[4]<<std::endl;
				edge[i]=edge[i]-1;
				run=true;
				for(int j=0;j<g[i].size();++j)
				{

					ll k= g[i][j];

					if(edge[k]!=0)
					ded.push_back(k);
					// std::cout<<k<<" "<<edge[k]<<" "<<edge[4]<<std::endl;
					// edge[k]=edge[k]-1;
				}
			}
		}

		for(int j=0;j<ded.size();++j)
		{
			edge[ded[j]]-=1;
		}
		++ans;
	}
	--ans;
	std::cout<<ans<<std::endl;
	return 0;
}