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
	int n,m;
	std::cin>>n>>m;

	// std::unordered_map<int,int> map;

	vi a(n,0),b(m,0);

	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}

	for(int i=0;i<m;++i)
	{
		// std::cin>>j;
		// map[j]++;
		std::cin>>b[i];
	}

	int i=0,j=0;

	for(i=0,j=0;i<n && j <m;++j)
	{
		if(b[j]>=a[i])
		{
			++i;
		}
	}
	std::cout<<n-i<<std::endl;
	return 0;
		
}