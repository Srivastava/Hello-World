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

	vi w(n,0);
	for(int i=0;i<n;++i)
	{
		std::cin>>w[i];
	}

	vi b(m,0);
	for(int i=0;i<m;++i)
	{
		std::cin>>b[i];
	}

	


	return 0;
}