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
	int n;
	std::cin>>n;

	int m;
	std::cin>>m;

	vi a(n,0);
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}

	std::sort(a.begin(), a.end(), std::greater<int>());

	/*std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout,","));
	std::cout<<std::endl;*/
	int i=0;
	
	while(m>0)
	{
		m=m-a[i];
		++i;
	}

	std::cout<<i<<std::endl;
	return 0;
}