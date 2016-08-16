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

int dp[105][105][105]={};
vi d;

// std::vector<std::vector<std::vector<int> > > v;

ll solve(char c,int i,ll r)
{
	// ll a=1e10,b=1e10,e=1e10,f=1e10;
	int val=0;

	if(c=='r'){val=2;}
	else if(c=='g'){val=1;}
	else if(c=='c'){val=0;}

	ll temp=r;
	// std::cout<<dp[val][i][r]<<" "<<val<<" "<<i<<" "<<r<<std::endl;
	if(c!='u')
	{
		// std::cout<<dp[val][i][r]<<" * "<<i<<" "<<r<<std::endl;
		if(dp[val][i][r]!=-1){return dp[val][i][r];}
	}
	if(i<0){return 0;}
	if(d[i]==0)
	{

		r=solve('r',i-1,r+1)+1;
	}
	else if(d[i]==1)
	{
		if(c=='c')
		r=(solve('r',i-1,r+1)+1);

		else
		{
			r=std::min(solve('r',i-1,r+1)+1,solve('c',i-1,r));
		}
	}

	else if(d[i]==2)
	{

		if(c=='g')
		r=(solve('r',i-1,r+1)+1);

		else
		{
			r=std::min(solve('r',i-1,r+1)+1,solve('g',i-1,r));
		}
	}

	else if(d[i]==3)
	{

		if(c=='g')
			r=std::min(solve('c',i-1,r),solve('r',i-1,r+1)+1);
		else if(c=='c')
			r=std::min(solve('g',i-1,r),solve('r',--i,r+1)+1);
		else
		{
			ll r=std::min(solve('c',i-1,r),solve('g',i-1,r));
			r=std::min(r,solve('r',i-1,r+1)+1);
		}

	}

	if(c!='u')
		dp[val][i][temp]=r;

	return r;
}


int main()
{
	int n;
	std::cin>>n;

	d.resize(n,0);

	for(ll i=0;i<n;++i)
	{
		std::cin>>d[i];
	}

	for(int i=0;i<105;++i)
	{
		for(int j=0;j<105;++j)
		{
			for(int k=0;k<105;++k)
			{
				dp[i][j][k]=-1;
			}
		}
	}
	std::cout<<solve('u',n-1,0)<<std::endl;
	return 0;
}