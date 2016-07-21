#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;


typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::unordered_map<ll,ll> map;


std::pair<ll,ll> solve(ll q)
{
	map m;

	ll temp =q;

	while(q%2==0)
	{
		m[2]++;
		q/=2;
	}

	ll sq=std::sqrt(q);

	for(ll i=3;i<=sq;i+=2)
	{
		while(q%i==0)
		{
			m[i]++;
			q/=i;
		}
	}

	if(q>2)
	m[q]++;
	// for(auto it=m.begin();it!=m.end();++it)
	// {
	// 	std::cout<<it->first<<" "<<it->second<<std::endl;
	// }

	for(auto it=m.begin();it!=m.end();++it)
	{
		if(m.size()>1)
		{
			auto its=std::next(it);
			// std::cout<<"here"<<std::endl;

			if(its!=m.end())
			if(it->first * its->first!=temp)
				return std::make_pair(1,it->first * its->first);
		}

		else if(it->second>1 && m.size()==1)
		{
			// if(it->second%2!=0)
			// {
			if(it->first * it->first!=temp)
				return std::make_pair(1,it->first * it->first);
			
			return std::make_pair(2,-1);
			// }
			// else
			// {
			// 	return std::make_pair(2,-1);
			// }
		}
	}


	if(m.size()==1)
	{
		return std::make_pair(1,0);
	}

	return std::make_pair(2,-1);

}

int main()
{
	ll q;
	std::cin>>q;

	if(q==1)
	{
		std::cout<<1<<"\n"<<0<<std::endl;
		return 0;
	}

	

	std::pair<ll,ll> ans= solve(q);

	std::cout<<ans.first<<std::endl;

	if(ans.second!=-1)
	{
		std::cout<<ans.second<<std::endl;
	}
	// std::cout<<<<std::endl;

	return 0;
}