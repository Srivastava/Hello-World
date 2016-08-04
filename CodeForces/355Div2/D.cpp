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
	ll n,m,p;
	std::cin>>n>>m>>p;

	ll start=0;

	vpa g(p+1,pa(0,0));

	for(ll i=1;i<=n;++i)
	{
		for(ll j=1;j<=m;++j)
		{
			ll val;
			std::cin>>val;

			if(i==1 && j==1){start=val;}

			g[val]=std::make_pair(i,j);
		}
	}

	ll sum=0;pa prev;
	prev={1LL,1LL};

	while(start!=p)
	{
		pa curr= g[start+1];
		
		sum+=std::abs(prev.first-curr.first)+std::abs(prev.second-curr.second);
		start+=1;
		prev=curr;

	}

	std::cout<<sum<<std::endl;
	return 0;
}