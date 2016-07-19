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


typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<std::vector<ll> > vvll;

// vvll dp(5005,vll(5005,0));
vll sum(5005,0),val(5005,0);

int n,m,k;

// int main()
// {
// 	ll n,m,k;
// 	std::cin>>n>>m>>k;

// 	vll val(n,0);

// 	ll summing=0;

// 	for(ll i=0;i<n;++i)
// 	{
// 		std::cin>>val[i];
// 		summing+=val[i];
// 	}

// 	std::cout<<summing<<std::endl;

// 	std::sort(val.begin(),val.end());

// 	ll sum=0,count=0;

// 	vll::iterator index=val.end();
// 	--index;

// 	std::copy(val.begin(),val.end(),std::ostream_iterator<ll>(std::cout," "));
// 	std::cout<<std::endl;
// 	// for(int i=n-1;i>=0;--i)
// 	while(count<k)
// 	{
// 		ll r=*index;
// 		ll l=r-m+1;
// 		++count;

// 		std::cout<<r<<" "<<l<<std::endl;
// 		vll::iterator p=std::find(val.begin(),val.end(),l);

// 		if(p==val.end())
// 		{
// 			--index;
// 			--count;
// 		}

// 		else
// 		{
// 			if(l!=r)
// 				sum+=l+r;

// 			else
// 				sum+=l;
// 			index=p-1;
// 		}


// 	}

// 	std::cout<<sum<<std::endl;
// 	return 0;
// }


// ll dy(ll i,ll k)
// {
// 	if(i>n-m+1 && k> 0){return -1e16;}
// 	if(dp[i][k]!=-1)
// 	{
// 		return dp[i][k];
// 	}


// 	if(k==0){return 0;}
// 	ll selected= sum[i+m-1]-sum[i-1] + dy(i+m,k-1);

// 	// std::cout<<i<<" "<<sum[i+m-1]-sum[i-1]<<" "<<k<<" "<<selected<<std::endl;
// 	ll notselected=dy(i+1,k);

// 	return std::max(selected,notselected);

// }

int main()
{
	// ll n,m,k;
	std::cin>>n>>m>>k;

	// vll val(n+1,0),sum(n+1,0);

	sum[0]=0;
	for(int i=1;i<=n;++i)
	{
		std::cin>>val[i];
		sum[i]=val[i]+sum[i-1];
		// std::cout<<m<<",";
	}
	// std::cout<<std::endl;


	// std::cout<<dy(1,k)<<std::endl;
	vvll dp(n+1,vll(n+1,0));

	for(int i=1;i<=n;++i)
	{
		if(i<m){continue;}

		for(int j=1;j<=k;++j)
		{
			dp[i][j]=sum[i]-sum[i-m]+dp[i-m][j-1];
			dp[i][j]=std::max(dp[i][j],dp[i-1][j]);
		}
	}

	// for(int i=1;i<=n;++i)
	// {
	// 	for(int j=1;j<=k;++j)
	// 	{
	// 		std::cout<<dp[i][j]<<",";
	// 	}
	// 	std::cout<<std::endl;
	// }
	std::cout<<dp[n][k]<<std::endl;

}