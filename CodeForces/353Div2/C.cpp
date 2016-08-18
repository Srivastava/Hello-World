#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_map>

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

	ll sum=0;
	ll ans= n-1;
	std::unordered_map<ll,ll> map;
	for(int i=1,t;i<=n;++i)
	{
		std::cin>>t;
		sum+=t;
		map[sum]++;

		ans=std::min(ans,n-map[sum]);

	}

	std::cout<<ans<<std::endl;
	return 0;
}