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

vi d;

void dfs(int v,int len)
{
	if(len==2)
	{
		d[v]++;
		return;
	}

	for(int i=0;i<g[v].size();++i)
	{
		dfs(g[v][i],len+1);
	}

}

int main()
{
	std::cin>>n>>m;

	g.resize(n+1);
	visited.resize(n+1,false);

	d.resize(n+1,0);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		std::cin>>a>>b;

		g[a].push_back(b);
	}

	ll ans=0;

	for(int i=1;i<=n;++i)
	{
		for(int k=1;k<=n;++k)
		{
			d[k]=0;
		}

		dfs(i,0);

		for(int j=1;j<=n;++j)
		{
			if(j!=i)
			{
				ans+=(d[j]*(d[j]-1)/2);
			}
		}
	}

	std::cout<<ans<<std::endl;
	return 0;
}