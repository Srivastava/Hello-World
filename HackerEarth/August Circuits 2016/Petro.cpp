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
	int n,m;
	std::cin>>n>>m;

	for(int i=1;i<=m;++i)
	{
		ll u,v;
		std::cin>>u>>v;

		g[u].push_back(std::make_pair(v,i));
		g[v].push_back(std::make_pair(u,m+i));
	}

	ll ans=0;
	vvll v;

	for(int i=1;i<=n;++i)
	{
		int len =0;

		ll u =i;
		while(len<=2)
		{
			std::queue<ll> q;
			q.push(i);

			int top 
			for(int j=0;i<g[u].size();++j)
			{
				
			}
		}
	}
	return 0;
}