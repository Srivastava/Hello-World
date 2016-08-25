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
	int n,x;
	std::cin>>n>>x;

	if(n==1){std::cout<<0<<std::endl;return 0;}
	vll a(n,0);

	for(int i=0;i<n;++i )
	{
		std::cin>>a[i];
	}
	std::sort(a.begin(),a.end());

	ll ans=1e18;
	if(x<=a[0])
	{
		ans=std::min(ans,std::abs(a[n-2]-x));
		// std::cout<<ans<<std::endl;
		
	}

	if(x>=a[n-1])
	{
		ans=std::min(ans,std::abs(x-a[1]));
		// ans=x-a[1];
		// std::cout<<ans<<std::endl;
	}
	if(x>=a[n-2])
	{
		ans=std::min(ans,std::abs(x-a[0]));
	}
	if(x<=a[1])
	{
		ans=std::min(ans,std::abs(x-a[n-1]));
	}
		

		// ans=1e18;
	// std::cout<<ans<<std::endl;
	ans=std::min(ans,std::abs(2*(a[n-1]-x))+std::abs(x-a[1]));
	// std::cout<<ans<<std::endl;
	ans=std::min(ans,std::abs(2*(a[n-2]-x))+std::abs(x-a[0]));
	// std::cout<<ans<<std::endl;
	ans=std::min(ans,std::abs((a[n-1]-x))+std::abs(2*(x-a[1])));
	// std::cout<<ans<<std::endl;
	ans=std::min(ans,std::abs((a[n-2]-x))+std::abs(2*(x-a[0])));
	// std::cout<<ans<<std::endl;
		

	std::cout<<ans<<std::endl;
	return 0;
}