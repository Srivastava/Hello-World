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


	vll a(n,0);
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}

	std::sort(a.begin(),a.end());

	if(n%2==0)
	{
		std::cout<<a[n/2-1]<<std::endl;
	}
	else
	{
		std::cout<<a[n/2]<<std::endl;
	}
	
	return 0;
}