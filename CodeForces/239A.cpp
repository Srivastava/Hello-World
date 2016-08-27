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
	ll y,n,k;
	std::cin>>y>>k>>n;

	int m = n/k;
	int l = y/k+1;
	
	if(l>m){std::cout<<-1<<std::endl;return 0;}
	for(int i=l;i<=m;++i)
	{
		int x = i*k-y;
		if(x<1 || x+y>n)
		{
			std::cout<<-1<<std::endl;
			break;
		} 
		std::cout<<x<<" ";
	}

	return 0;
}