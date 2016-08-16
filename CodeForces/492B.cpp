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
	ll n,l;
	std::cin>>n>>l;

	vll a(n,0);
	for(ll i=0;i<n;++i)
	{
		std::cin>>a[i];
	}

	std::sort(a.begin(),a.end());

	double min=0;
	for(int i=0;i<n-1;++i)
	{
		min=std::max(min,double(a[i+1]-a[i])/2.0);
	}

	// std::cout<<min<<std::endl;
	if(a[0]!=0){min=std::max(min,(double)a[0]);}
	// std::cout<<min<<std::endl;
	if(a[n-1]!=l){min=std::max(min,(double)l-a[n-1]);}
	
	printf("%0.9f\n",min);
	// std::cout<<min<<std::endl;
	return 0;
}