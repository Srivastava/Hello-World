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
	ll n;
	std::cin>>n;

	vll a(n+1,0);

	vll b(n+1,0);

	for(int i=1;i<=n;++i)
	{
		std::cin>>a[i];
	}
	b[n]=a[n];

	for(int i=n-1;i>=1;--i)
	{
		b[i]=a[i]+a[i+1];
		// std::cout<<b[i]<<" ";
	}

	std::copy(b.begin()+1,b.end(),std::ostream_iterator<ll>(std::cout," "));
	std::cout<<std::endl;
	return 0;
}