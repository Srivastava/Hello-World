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


ll solve(vll& h, const vll& index,const ll& n)
{
	ll count=0;

	int left=0,right=0;

	for(int i=0;i<index.size()+1;++i )
	{
		if(i==index.size() && index[i-1]!=n-1)
		{
			right=n-1;
		}
		else
		{
			right=index[i];
		}

		if(left==n-1){continue;}
		ll max=0;
		// std::cout<<left<<" "<<right<<" "<<count<<std::endl;
		for(int i=left;i<=right;++i)
		{
			if(max<h[i])
			{
				max=h[i];
			}
		}
		if(right-left==2){max=std::min(max,1LL);}
		count+=max;
		left=right;
	}
	// std::cout<<count<<std::endl;
	return count;
}

int main()
{
	ll n;
	std::cin>>n;

	vll h(n,0);

	ll min=10e9+7;
	for(ll i=0;i<n;++i)
	{
		std::cin>>h[i];
		if(min>h[i])
		{
			min=h[i];
		}
	}

	vll index;
	
	for(int i=0;i<n;++i)
	{
		h[i]-=min;

		if(h[i]==0)
		{
			index.push_back(i);
		}
	}

	// else
	{

		std::cout<<std::min(solve(h,index,n)+min,n)<<std::endl;
	}
	return 0;
}