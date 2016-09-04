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
	int n,m;
	std::cin>>n>>m;

	vll a(n,0);
	vll b(m,0);

	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}
	for(int j=0;j<m;++j)
	{
		std::cin>>b[j];
	}

	std::sort(a.begin(),a.end());
	// std::sort(b.begin)

	for(int i=0;i<m;++i)
	{
		auto it = std::upper_bound(a.begin(),a.end(),b[i]);
		std::cout<<it-a.begin()<<" ";
	}

	return 0;
}