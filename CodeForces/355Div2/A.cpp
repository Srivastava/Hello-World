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
	ll n,h;
	std::cin>>n>>h;

	ll width=0;
	for(int i=0;i<n;++i)
	{
		ll val;
		std::cin>>val;

		if(val>h){width+=2;}
		else
		{
			width+=1;
		}
	}

	std::cout<<width<<std::endl;
	return 0;
}