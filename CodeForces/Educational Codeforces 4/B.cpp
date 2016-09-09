#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_map>


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
	int n;
	std::cin>>n;

	// vi a(n+1,0);
	std::unordered_map<int,int> map;

	for(int i=1;i<=n;++i)
	{
		int v;
		std::cin>>v;
		map[v]=i;
	}

	int ini=map[1];
	ll ans=0;
	for(int i=2;i<=n;++i)
	{
		ans+=std::abs(ini-map[i]);
		ini=map[i];
	}
	std::cout<<ans<<std::endl;
	return 0;
}