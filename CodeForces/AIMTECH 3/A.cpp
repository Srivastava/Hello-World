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
	ll n,b,d;
	std::cin>>n>>b>>d;

	vll a(n,0);

	ll sum=0,ans=0;
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];

		if(a[i]<=b)
		{
			sum+=a[i];
		}

		if(sum>d)
		{
			sum=0;
			++ans;
		}
	}

	std::cout<<ans<<std::endl;
	return 0;
}