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

int main()
{
	ll n;
	std::cin>>n;

	std::vector<ll> val(n,0);

	for(ll i=0;i<n;++i)
	{
		std::cin>>val[i];
	}

	std::sort(val.begin(),val.end());

	ll mex=1;

	for(int i=0;i<val.size();++i)
	{
		if(val[i]>=mex){++mex;}
	}
	std::cout<<mex<<std::endl;
	// ll mex=val[n-1]+1;
	// for(ll i=n-1;i>=1;--i)
	// {
	// 	if(val[i-1]!=val[i]-1)
	// 	{
	// 		if(val[i]-1!=0)
	// 		{
	// 			mex=val[i]-1;
	// 		}
	// 		break;
	// 	}
	// }
	// if(n==1){mex=2;}
	// std::cout<<mex<<std::endl;

	return 0;
}