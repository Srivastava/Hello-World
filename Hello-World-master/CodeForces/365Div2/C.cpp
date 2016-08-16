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
	ll n,w,v,u;
	std::cin>>n>>w>>v>>u;

	vpa p;
	p.reserve(n);

	for(int i=0;i<n;++i)
	{
		int u,v;
		std::cin>>u>>v;

		p.push_back({u,v});
	}
	return 0;
}