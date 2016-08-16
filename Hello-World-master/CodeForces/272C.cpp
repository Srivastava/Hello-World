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
typedef std::pair<ll,ll> pll;
typedef std::vector<pll> pvll;

int main()
{
	ll n;
	std::cin>>n;

	vll a(n+1,0);

	for(ll i=1;i<=n;++i)
	{
		std::cin>>a[i];
		
	}

	ll m;

	std::cin>>m;
	// std::cout<<m<<std::endl;
	pvll wh;

	// vll ans(m+1,0);

	vll b(m+1,0);
	ll max=0;

	for(ll i=1;i<=m;++i)
	{
		ll p,q;
		std::cin>>p>>q;
		// std::cout<<std::max(max,a[p])<<std::endl;
		b[i]=std::max(max,a[p]);
		a[p]=std::max(max,a[p])+q;
		max=std::max(max,a[p]);
		
	}

	std::copy(b.begin()+1,b.end(),std::ostream_iterator<ll>(std::cout,"\n"));

	return 0;
}