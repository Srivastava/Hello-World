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

	ll n,k;
	std::cin>>n>>k;

	if(n==1)
	{
		std::cout<<0<<std::endl;
		return 0;
	}
	
	if(n<=k){std::cout<<1<<std::endl;return 0;}

	ll sum=1+(k*(k-1))/2;
	if(sum<n){std::cout<<-1<<std::endl;return 0;}

	ll l=1,r=k-1,m=0;

	while(r-l>1)
	{
		m=(l+r)>>1;
		ll sum=1+((k-m)*(k-1+m))/2;

		if(sum>=n){l=m;}
		else{r=m;}
	}
	m=r;
	sum=1+((k-m)*(k-1+m))/2;
	if(sum>=n){std::cout<<k-m<<std::endl;}
	else
	{
		m=l;
		sum=1+((k-m)*(k-1+m))/2;
		if(sum>=n){std::cout<<k-m<<std::endl;}

	}
	return 0;
}