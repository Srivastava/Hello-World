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
	ll n,m;
	std::cin>>n>>m;

	vvll c(n,vll(m,0));

	ll max=-1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			std::cin>>c[i][j];
		}
		std::sort(c[i].begin(),c[i].end());
		max=std::max(max,c[i][0]);
	}

	std::cout<<max<<std::endl;
	/*for(ll i=0;i<n;++i)
	{
		std::copy(c[i].begin(),c[i].end(),std::ostream_iterator<int>(std::cout,","));
		std::cout<<std::endl;
	}*/
	return 0;
}