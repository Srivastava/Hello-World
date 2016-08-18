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
	ll n;
	std::cin>>n;

	vi a(n,0);

	for(int i=1;i<n;++i)
	{
		std::cin>>a[i];
	}

	ll dp[n][n];//,check[n][n]={-1};

	for(int i=0;i<=n;++i)
	{
		dp[i][i]=0;
		// check[i][i]=1;
	}

	ll ans=0;

	for(int j=n;j>=1;--j)
	{
		for(int i=j-1;i>=1;--i )
		{

			int val = a[i];
			val = val >j ? j : val;

			ll sol=1e15;
			for(int k=i+1;k<=val;++k)
			{
				sol=std::min(sol,1+dp[k][j]);
			}

			dp[i][j]=sol;
			ans+=sol;
			// check[i][j]=1;
		}
	}

	std::cout<<ans<<std::endl;
	return 0;
}