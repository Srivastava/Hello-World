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
	ll n,k;
	std::cin>>n>>k;

	vll a(n,0);

	for(int i =0;i<n;++i)
	{
		std::cin>>a[i];
	}

	std::sort(a.begin(),a.end());

	std::vector<ll>::iterator it = std::find(a.begin(),a.end(),k);

	// vll ans(a.begin(),it);

	ll ans=std::distance(a.begin(),it);
	// std::cout<<ans<<std::endl;

	std::vector<ll>::iterator left=it,right=it;

	ll last=(a[n-1])/k+1;

	// std::cout<<last<<std::endl;
	for(int i=2;i<=last;++i)
	{
		it=std::find(it,a.end(),k*i);

		if(it==a.end())
		{
			if(a[n-1]%k!=0)
			{
				ans+=std::distance(left,a.end());
			}
			break;
		}

		ans+=std::distance(left,it);
		left=it+1;
	}

	if(n==1){ans=1;}
	std::cout<<ans<<std::endl;
	return 0;
}