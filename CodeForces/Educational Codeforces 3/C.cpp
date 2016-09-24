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
	int n;
	std::cin>>n;

	vi m(n,0);
	
	ll sum=0;
	for(int i=0;i<n;++i)
	{
		std::cin>>m[i];
		
		sum+=m[i];
	}

	ll avg=sum/n,rem=sum%n;

	std::sort(m.begin(),m.end());
	ll ans=0;
	for(int i=0;i<n-rem;++i)
	{
		ans+=std::abs(avg-m[i]);
	}

	for(int i=n-rem;i<n;++i)
	{
		ans+=std::abs(avg+1-m[i]);
	}
	std::cout<<ans/2<<std::endl;
	return 0;
}