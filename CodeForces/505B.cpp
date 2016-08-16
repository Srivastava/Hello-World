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

const int maxn=105;

int f[maxn][maxn];

int find(ll c,ll x)
{
	return f[c][x]==x ? x : f[c][x]=find(c,f[c][x]);
}

int main()
{
	ll n,m;
	std::cin>>n>>m;

	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			f[i][j]=j;
		}
	}

	for(int i=1;i<=m;++i)
	{
		ll u,v,c;
		std::cin>>u>>v>>c;

		u=find(c,u);
		v=find(c,v);

		if(u!=v){f[c][u]=v;}
	}

	ll q;
	std::cin>>q;

	for(int i=1;i<=q;++i)
	{
		ll u,v;
		std::cin>>u>>v;

		ll ans=0;

		for(int i=1;i<=m;++i)
		{
			ans+=find(i,u)==find(i,v);
		}
		std::cout<<ans<<std::endl;
	}
	return 0;
}