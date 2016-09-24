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
	ll n,c;
	std::cin>>n>>c;

	vll t(n,0);

	ll ans=0;
	for(int i=0;i<n;++i)
	{
		std::cin>>t[i];
		++ans;

		// if(i==0){++ans;}
		if(i>0)
		{	
			if(t[i]>t[i-1]+c){ans=0;++ans;}
		}
		// std::cout<<ans<<",";
	}	
	// std::cout<<std::endl;
	std::cout<<ans<<std::endl;
	return 0;
}