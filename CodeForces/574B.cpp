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

	vvll g(n+1,vll(1,0));

	for(int i=1;i<=n;++i)
	{
		g[i][0]=i;
		
	}


	for(int i=1;i<=m;++i)
	{
		ll u,v;
		std::cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);

	}

	
	return 0;
}