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



vll factorial(2003,0);
vll invfactorial(2003,0);

ll expo(ll x, ll n)
{
	ll res=1;

	while(n>0)
	{
		if(n%2==1)
		{
			res=(res*x)%MOD;
		}

		x=(x*x)%MOD;
		n/=2;
	}

	return res%MOD;
}

ll combi(ll n, ll r)
{
	return (((factorial[n]*invfactorial[n-r])%MOD)*invfactorial[r])%MOD;
}

int main()
{

	factorial[0]=1;
	invfactorial[0]=1;

	for(int i=1;i<2002;++i)
	{
		factorial[i]=(factorial[i-1]*i)%MOD;
		invfactorial[i]=expo(factorial[i],MOD-2);
	}

	int k;
	std::cin>>k;

	ll total;

	vll num(1001,0);

	for(int i=0;i<k;++i)
	{
		std::cin>>num[i+1];
	}

	// std::copy(num.begin(),num.end(),std::ostream_iterator<ll>(std::cout,","));
	// std::cout<<std::endl;

	vll dp(1001,0);
	dp[0]=0;
	dp[1]=1;
	total=num[1];

	for(int i=2;i<=k;++i)
	{
		total+=num[i];
		dp[i]=(dp[i-1]*combi(total-1,num[i]-1))%MOD;
	}

	std::cout<<dp[k]<<std::endl;
	return 0;
}