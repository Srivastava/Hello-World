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
	ll b,d,s;
	std::cin>>b>>d>>s;

	ll max=std::max(b,std::max(d,s));

	max--;
	ll ans=std::max(max-b,0LL) + std::max(max-d,0LL)+std::max(max-s,0LL);
	std::cout<<ans<<std::endl;
	return 0;
}