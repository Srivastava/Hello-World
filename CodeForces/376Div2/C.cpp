#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <map>

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

vll g[200005];
vb visit(200005,false);
vll c(200005,0);
void dfs(int u,int last,ll& cnt,std::map<int,int>& freq)
{
	if(visit[u]){return;}
	visit[u]=true;
	freq[c[u]]++;
	++cnt;
	for(auto v:g[u])
	{
		if(v!=last)
		{
			// ++cnt;
			dfs(v,u,cnt,freq);
		}
	}
}

int main()
{
	ll n,m,k;
	std::cin>>n>>m>>k;

	
	for(int i=1;i<=n;++i)
	{
		std::cin>>c[i];
	}

	vi nodes;
	nodes.reserve(n+1);
	for(int i=0;i<m;++i)
	{
		int u,v;
		std::cin>>u>>v;

		if(!visit[u])
		{
			visit[u]=true;
			nodes.push_back(u);
		}
		if(!visit[v])
		{
			visit[v]=true;
			nodes.push_back(v);
		}
		// int c1=c[u];
		// int c2=c[v];
		// if(c1!=c2)
		// {
		// 	g[c1].push_back(c2);
		// 	g[c2].push_back(c1);
		// }

		g[u].push_back(v);
		g[v].push_back(u);
		
	}

	visit.assign(200005,false);

	ll ans=0;
	for(auto i:nodes)
	{
		// std::cout<<i<<" "<<visit[i]<<std::endl;
		std::map<int,int> freq;
		if(!visit[i])
		{
			ll cnt=0;
			dfs(i,-1,cnt,freq);
			int max=0;

			for(auto it=freq.begin();it!=freq.end();++it)
			{
				max=std::max(max,it->second);
			}
			// std::cout<<cnt<<" "<<max<<std::endl;
			ans+=(cnt-max);
		}
	}

	std::cout<<ans<<std::endl;

	return 0;
}