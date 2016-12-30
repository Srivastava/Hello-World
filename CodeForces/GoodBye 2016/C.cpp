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

	ll minR=0,maxR=2e8;

	for(int i=0;i<n;++i)
	{
		int ci,di;
		std::cin>>ci>>di;
		if(di==1 && minR<1900){minR=1900;}
		if(di==2 && maxR>1899){maxR=1899;}
		maxR+=ci;
		minR+=ci;

		if(minR>maxR){std::cout<<"Impossible"<<std::endl;return 0;}
	}

	if(maxR>2e7){std::cout<<"Infinity"<<std::endl;return 0;}
	std::cout<<maxR<<std::endl;
	return 0;
}