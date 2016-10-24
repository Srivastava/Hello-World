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
	ll n,d;
	std::cin>>n>>d;

	vll a(n,0);
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}
	ll ans=0;

	int j=0;
	for(int i=0;i<n;++i)
	{
		while(a[j]-a[i] <=d && j<n)
		{
			++j;
		}
		--j;
		ll val=j-i-1;

		ans+=(val*(val+1))/2;
	}

		
	std::cout<<ans<<std::endl;
	return 0;
}