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
typedef std::vector<vi> vvi;
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

vvi g;
int n,m;
vb visited;

int t;

void dfs(int u,int par)
{
	visited[u]=true;

	for(const auto& i :g[u])
	{
		if(i==par){continue;}

		if(!visited[i]){dfs(i,u);}
		else if(visited[i]){t=0;}
	}
}

int main()
{
	std::cin>>n>>m;

	g.resize(n+1);
	visited.resize(n+1,false);
	

	for(int i=1;i<=m;++i)
	{
		int u,v;
		std::cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
		
	}

	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(!visited[i])
		{
			t=1;
			dfs(i,0);
			ans+=t;
		}
	}

	std::cout<<ans<<std::endl;
	// std::cout<<solve()<<std::endl;
	return 0;
}