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

int a,b,c;
int dp[51][51][60]={0};


int rec(int n,int m,int k)
{

	// std::cout<<dp[n]<<" "<<dp[m]<<" "<<dp[k]<<std::endl;
	// std::cout<<n<<" "<<m<<" "<<k<<std::endl;
	// if(k==0){return 0;}
	if(n*m==k){return 0;}
	if(dp[n][m][k])
	{
		return dp[n][m][k];
	}

	int a=1e6;

	for(int i=1;i<m;++i)
	{
		a=std::min(a,rec(n,i,k)+n*n);

		if(k-(n*(m-i))>=0)
		{
			a=std::min(a,rec(n,i,k-(m-i)*n)+n*n);	
		}
	}

	// a=std::min(a,b);
	for(int i=1;i<n;++i)
	{
		a=std::min(a,rec(i,m,k)+m*m);

		if(k-(m*(n-i))>=0)
		{
			a=std::min(a,rec(i,m,k-(n-i)*m)+m*m);	
		}

	}
	

	return dp[n][m][k]=a;

}

int main()
{
	int t;
	std::cin>>t;

	while(t--)
	{
		// int n,m,k;
		std::cin>>a>>b>>c;

		// dp[50][50][60]={-1};
		// std::cout<<"here"<<std::endl;
/*
		for(int i=0;i<51;++i)
		{
			for(int j=0;j<51;++j)
			{
				for(int k=0;k<60;++k )
				{
					dp[i][j][k]=-1;
				}
			}
		}*/

		std::cout<<rec(a,b,c)<<std::endl;
	}
	return 0;
}