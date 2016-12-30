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
	int n,k;
	std::cin>>n>>k;

	int mid=240-k;

	if(mid==0){std::cout<<0<<std::endl;return 0;}

	// int i=0;

	// std::cout<<mid<<std::endl;
	int ans=0;

	int i=0;
	/*for(i=0;i<=n;++i)
	{
		ans+=5*i;
		if(ans>mid || i>n){--i;break;}
		if(ans==mid){break;}
		++i;

	}*/
	while(ans<=mid && i<=n)
	{
		ans+=5*i;
		// std::cout<<ans<<" "<<i<<std::endl;
		if(ans>mid || i>n){--i;break;}
		if(ans==mid || i==n){break;}
		++i;
	}
	std::cout<<i<<std::endl;
	return 0;
}