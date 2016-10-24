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
	int k,r;
	std::cin>>k>>r;

	for(int i=1;i<=10;++i)
	{
		
		int val=(k*i-r);
		if(val%10==0 || (k*i)%10==0)
		{
			std::cout<<i<<std::endl;
			return 0;
		}
		
	}
	return 0;
}