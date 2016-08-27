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

	vll c(n,0);

	for(ll i=0;i<n;++i)
	{
		std::cin>>c[i];
	}

	std::sort(c.begin(),c.end());
	
	while(k--)
	{
		if(c[n-1]==c[0]){continue;}
		c[n-1]--;
		c[0]++;

		std::vector<ll>::iterator it= std::lower_bound(c.begin(),c.end(),c[0]);

		std::sort(c.begin(),it);

		it = std::upper_bound(c.begin(),c.end(),c[n-1]);
		std::sort(it,c.end());
		/*int i=0;
		while(1)
		{
			if(c[i]>c[i+1])
			{
				std::swap(c[i],c[i+1]);
			}
			else
			{
				break;
			}
			++i;
		}
		i=n-1;
		while(1)
		{
			if(c[i]<c[i-1])
			{
				std::swap(c[i],c[i-1]);
			}
			else
			{
				break;
			}
			--i;
		}*/

	}

	std::cout<<c[n-1]-c[0]<<std::endl;

	return 0;
}