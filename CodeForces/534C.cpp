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

int main()
{
	ll n, a;
	std::cin>>n>>a;

	vll d(n,0);
	// std::copy(d.begin(),d.end(),std::ostream_iterator<ll>(std::cout,","));

	ll sum=0;
	for(ll i=0;i<n;++i)
	{
		std::cin>>d[i];
		sum+=d[i];
	}

	// std::copy(d.begin(),d.end(),std::ostream_iterator<ll>(std::cout,","));
	// std::cout<<std::endl;
	for(ll i=0;i<n;++i)
	{
		ll l=std::max(1LL,a-(sum-d[i]));
		ll r = std::min(0LL+d[i],a-(n-1));

		ll ans=d[i]-(r-l+1);
		std::cout<<ans<<" ";
	}




	return 0;
}