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
// typedef std::vector<<std::pair<ll,ll> > pvll;


int main()
{
	ll n,m,x,y,z,p;
	std::cin>>m>>n>>x>>y>>z>>p;

	std::vector<vll> c(p,vll(2,0));
	// pvll c;

	x=x%4;
	y=y%2;
	z=z%4;

	// std::cout<<x<< y<< z<<std::endl;
	for(ll i=0;i<p;++i )
	{
		std::cin>>c[i][0]>>c[i][1];
	}

	ll count=0;
	
	while(count<x)
	{
		++count;

		for(int i=0;i<p;++i)
		{
			ll temp=c[i][0];
			c[i][0]=c[i][1];
			c[i][1]=m+1-temp;
		}
		ll temp=m;
		m=n;
		n=temp;
	}

	count=0;

	while(count<y)
	{
		++count;

		for(int i=0;i<p;++i)
		{
			ll temp=c[i][0];
			// c[i][0]=m+1-c[i][1];
			c[i][1]=n+1-c[i][1];
		}
		// ll temp=m;
		// m=n;
		// n=temp;
	}

	count=0;

	while(count<z)
	{
		++count;

		for(int i=0;i<p;++i)
		{
			ll temp=c[i][0];
			c[i][0]=n+1-c[i][1];
			c[i][1]=temp;
		}
		ll temp=m;
		m=n;
		n=temp;
	}

	for(ll i=0;i<p;++i )
	{
		std::cout<<c[i][0]<<" "<<c[i][1]<<std::endl;
	}

	return 0;
}