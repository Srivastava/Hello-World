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


ll solve(vi& a, ll& t)
{
	
	ll size=a.size();

	ll i=0,j=1,max=0;
	
	ll sum=0;
	for(int k=0;k<size;++k)
	{
		sum+=a[k];
		if(sum>t)
		{
			while(sum>t)
			{

				sum-=a[i];++i;
			}
		}

		if(sum<=t)
		{
			// ++j;
			max=std::max(max,k-i+1);
		}

	}
	return max;
}

int main()
{
	ll n,t;
	std::cin>>n>>t;

	vi a(n,0);

	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}
	
	std::cout<<solve(a,t)<<std::endl;
	
	return 0;
}