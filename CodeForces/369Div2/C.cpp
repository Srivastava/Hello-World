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

const ll inf=1e18;
ll dp[101][101][101]={inf};
ll p[101][101];
int n,m,k;
vi c(101,0);

ll solve(int i,int g,int col)
{
	if(i>n){return g==col?0:inf;}
	std::cout<<i<<" "<<g<<" "<<col<<std::endl;
	if(dp[i][g][col]!=inf && col!=-1)
	{
		// std::cout<<dp[i][g][col]<<std::endl;
		// std::cout<<"here not inf"<<std::endl;
		return dp[i][g][col];
	}


	ll ans = inf;
	int color=c[i];
	if(color)
	{
		if(i>0 && col==color)
		{
			dp[i][g][col]=std::min(dp[i][g][col],solve(i+1,g,color));
		}
		else
		{
			dp[i][g][col]=std::min(dp[i][g][col],solve(i+1,g+1,color));
		}
	}
	
	else
	{
		for(int j=1;j<=m;++j)
		{
			std::cout<<"here not zero"<<std::endl;
			if(j!=col)
				dp[i][g][col]=std::min(dp[i][g][col],solve(i+1,g+1,j)+p[i][j]);
			else
				dp[i][g][col]=std::min(dp[i][g][col],solve(i+1,g,j)+p[i][j]);
		}
	}

	return dp[i][g][col];
}

int main()
{
	// int n,m,k;
	std::cin>>n>>m>>k;


	for(int i=1;i<=n;++i)
	{
		std::cin>>c[i];
	}

	/*std::copy(c.begin(),c.end(),std::ostream_iterator<int>(std::cout," c "));
	std::cout<<std::endl;*/
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			std::cin>>p[i][j];
		}
	}

	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=k;++j)
		{
			for(int a=0;a<=m;++a)
			{
				dp[i][j][a]=inf;
			}
			
		}
		
	}

	/*for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			std::cout<<p[i][j]<<" * ";
		}
		std::cout<<std::endl;
	}*/
	solve(1,0,-1);

	/*if(c[1]!=0)
	{
		dp[1][1][c[1]]=0;
	}
	else
	{
		for(int i=1;i<=m;++i)
		{
			dp[1][1][i]=p[1][i];
		}
	}

	for(int i=2;i<=n;++i)
	{
		for(int j=1;j<=k;++j)
		{
			if(c[i]==0)
			{
				for(int a=1;a<=m;++a)
				{
					dp[i][j][a]=std::min(dp[i][j][a],dp[i-1][j][a]+p[i][a]);
					for(int b=1;b<=m;++b)
					{
						if(b!=a) dp[i][j][a]=std::min(dp[i][j][a],dp[i-1][j-1][b]+p[i][a]);
					}
				}
			}
			else
			{
				dp[i][j][c[i]]=std::min(dp[i][j][c[i]],dp[i-1][j][c[i]]);
				for(int b=1;b<=m;++b)
				{
					if(b!=c[i]) dp[i][j][c[i]]=std::min(dp[i][j][c[i]],dp[i-1][j-1][b]);
				}
			}
		}
	}*/

	ll ans=inf;
	for(int i=1;i<=m;++i)
	{
		// std::cout<<dp[n][k][i]<<" "<<i<<std::endl;
		ans=std::min(ans,dp[n][k][i]);
	}
	if(ans>=inf){ans=-1;}
	std::cout<<ans<<std::endl;

	return 0;
}