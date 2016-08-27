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

const int maxn=1e7+10;
ll dp[maxn];

ll rec(ll n,ll x,ll y)
{
	if(dp[n])
	{
		return dp[n];
	}
	if(n==0){return 0;}
	if(n==1){return x;}
	// ll a = 1e18;

	// if(n>1e7){return 0;}
	// a=std::min(a,std::min(x+rec(n-1,x,y),y+rec(n/2,x,y)+x*(n%2)));
	/*if(n%2==0)
	{
		if(n/2!=0)
		{
			a=std::min(a,y+rec(n/2,x,y));
		}
		
		// if(n-1!=0)
		a=std::min(a,x+rec(n-1,x,y));
		// a=std::min(a,x+y+rec((n+1)/2,x,y));
	}
	else
	{
		// if(n-1!=0)
		a=std::min(a,x+rec(n-1,x,y));
		a=std::min(a,x+y+rec((n+1)/2,x,y));
		// a=std::min(a,x+rec(n+1,x,y));
	}*/
	return dp[n]=std::min(x+rec(n-1,x,y),y+rec(n/2,x,y)+x*(n%2));
}


int main()
{
	ll n,x,y;
	std::cin>>n>>x>>y;
/*
	ll ans=0;

	if(n*x < y)
	{
		std::cout<<n*x<<std::endl;
		return 0;
	}

	if(x>n*y || n > x*y)
	{
		while(n > 50000)
		{
			// std::cout<<n<<" "<<ans<<std::endl;
			if(n%2==0)
			{
				ans+=y;

				 n/=2;	
			}
			else
			{
				n=n-1;
				ans+=x;
			}
		}

		std::cout<<ans+rec(n,x,y)<<std::endl;
		return 0;
	}
	std::cout<<rec(n,x,y)<<std::endl;*/

	for(int i=1;i<=n;++i)
	{
		dp[i]=std::min(dp[i-1]+x,dp[(i+1)/2]+y+(ll)x*(i%2));
	}
	std::cout<<dp[n]<<std::endl;
	/*for(int i=0;i<=n;++i)
	{
		std::cout<<dp[i]<<" "<<i<<std::endl;
	}*/
	return 0;
}