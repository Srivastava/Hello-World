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

	ll n,k;
	std::cin>>n>>k;

	if(n==1)
	{
		std::cout<<0<<std::endl;
		return 0;
	}
	
	if(n+1 > (k+1)*(k+2)/2)
	{
		std::cout<<-1<<std::endl;
		return 0;
	}

	ll l=0,r=k;	
	while(l<=r)
	{
		ll m=l+(r-l)/2;

		if()
	}

	std::cout<<ans+1<<std::endl;
	return 0;
}