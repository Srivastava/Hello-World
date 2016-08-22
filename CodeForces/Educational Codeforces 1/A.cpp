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
	int t;
	std::cin>>t;

	while(t--)
	{
		ll n;
		std::cin>>n;

		ll sum=(n*(n+1))/2;

		ll ans=0,mul=1;
		while(1)
		{
			ans+=mul;
			mul*=2;
			if(mul>n){break;}
		}
		ans=sum-2*ans;
		std::cout<<ans<<std::endl;
	}
	return 0;
}