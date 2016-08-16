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
	ll n,m;
	std::cin>>n>>m;

	ll k=(n+m)/5;
	// if(5*k> m){k=k-1;}

	// std::cout<<k<<std::endl;
	std::vector<ll> val(6,0);
	ll count=0,ans=0;
	if(m!=1)
	{

		ll where = std::min(5LL,n);
		for(ll i=1;i<=where;++i)
		{
			count=0;
			for(ll j=1;j<=k;++j)
			{
				// std::cout<<i<<" "<<j<<std::endl;
				ll y= 5*j-i;
				// std::cout<<y<<" y "<<std::endl;
				if(y<=m && y>=1){++count;}

			}
			ans+=count;
			val[i]=count;
		}

		// for(int i =0 ;i<=5;++i)
		// {
		// 	std::cout<<val[i]<<",";
		// }
		// std::cout<<std::endl;
		for(ll i = 6;i<=n;++i)
		{
			ll num=i%5;
			if(num==0){num=5;}
			ans+=val[num];
		}
	}

	else
	{
		ans=k;
	}
	std::cout<<ans<<std::endl;
	return 0;
}