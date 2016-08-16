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


std::vector<int> cb(const ll&x)
{
	ll y=x;

	std::vector<int> ans;
	
	while(y)
	{
		ans.push_back(y%2);
		y/=2;
	}

	std::reverse(ans.begin(),ans.end());
	return ans;
}


ll numBits(std::vector<int>& ans)
{
	std::reverse(ans.begin(),ans.end());

	ll count=0;
	int change=1;
	for(int i=0;i<ans.size();++i)
	{
		if(ans[i]==0 && change==1){ans[i]=1;change=0;}
		else if(ans[i]==0 && change==0){ans[i]=0;change=0;}
		else if(ans[i]==1 && change==0){ans[i]=1;change=0;}
		else if(ans[i]==1 && change==1){ans[i]=0;change=1;}
		
		if(ans[i]==1){++count;}
	}

	if(change==1)
	{
		ans.push_back(1);
		++count;
	}

	std::reverse(ans.begin(),ans.end());
	return count;

}
int main()
{
	ll n;
	std::cin>>n;


	while(n--)
	{
		ll l,r;

		std::cin>>l>>r;

		for(ll i=0;i<=64;++i)
		{
			if((l & (1LL<<i))==0)
			{
				if((l|(1LL<<i)) > r) break;

				l|= (1LL<<i);
			}
		}
		std::cout<<l<<std::endl;
	}
/*
	while(n--)
	{
		ll l,r;
		std::cin>>l>>r;


		std::vector<int> ans = cb(l);

		ll num=0;
		for(ll i=0;i<ans.size();++i)
		{
			if(ans[i]==1){++num;}
		}

		ll count=0,number=l;
		
		while(count<r-l)
		{
			ll val=numBits(ans);
			// std::cout<<val<<" "<<num<<" "<<l+count<<" "<<number<<std::endl;

			// std::copy(ans.begin(),ans.end(),std::ostream_iterator<int>(std::cout,""));
			// std::cout<<std::endl;
			
			++count;
			if(num<val)
			{
				number=l+count;
				num=val;
			}
		}

		std::cout<<number<<std::endl;

	}
	*/

	// std::vector<int> ans = cb(2);

	// std::copy(ans.begin(),ans.end(),std::ostream_iterator<int>(std::cout,""));
	// std::cout<<std::endl;

	return 0;
}