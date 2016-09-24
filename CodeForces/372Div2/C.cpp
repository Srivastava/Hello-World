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

	for(ll i=1;i<=n;++i)
	{
		if(i==1){std::cout<<2<<std::endl;}
		else std::cout<<i*i*i+2*i*i+1<<std::endl;
	}
	// m/=2;
	
	return 0;
}