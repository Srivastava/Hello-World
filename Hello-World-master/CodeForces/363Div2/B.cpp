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
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> pvll;


int main()
{
	ll n,m;
	std::cin>>n>>m;

	pvll wall;

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			char x;
			std::cin>>x;

			if(x=='*')
			{
				wall.push_back(std::make_pair(i+1,j+1));
			}

		}
	}

	ll x,y;

	// std::cout<<"HERE"<<std::endl;
	if(wall.size()>0)
	{

		x=wall[0].first;
		y=wall[0].second;
	}
	else if(wall.size()==0)
	{
		std::cout<<"YES"<<std::endl;
		std::cout<<1<<" "<<1<<std::endl;
		return 0;
	}
	// std::cout<<"HERE 1"<<std::endl;
	if(wall.size()==1)
	{
		std::cout<<"YES"<<std::endl;

		std::cout<<x<<" "<<y<<std::endl;
		return 0;
	}

	// std::cout<<"HERE 2"<<std::endl;
	/*ll count=0;

	for(int i=1;i<wall.size();++i)
	{
		if(wall[i].first != wall[i-1].first && wall[i].second!=wall[i-1].second)
		{
			
			if(count>0)
			{

				std::cout<<"NO"<<std::endl;
				return 0;
			}
			++count;
		}	
		else if(wall[i].first==wall[i-1].first)
		{
			x=wall[i].first;
		}
		else if(wall[i].second==wall[i-1].second)
		{
			y=wall[i].second;
		}
	}*/

	bool one=true;
	// std::cout<<"HERE 3"<<std::endl;
	x=1;y=1;
	for(int i=1;i<=n+1;++i)
	{
		for(int k=1;k<=m+1;++k)
		{

		// std::cout<<x<<" "<<y<<" "<<std::endl;
			one=true;
			for(int j=0;j<wall.size();++j)
			{
				// std::cout<<x<<" "<<y<<" "<<wall[j].first<<" "<<wall[j].second<<std::endl;
				if(x!=wall[j].first && y!=wall[j].second)
				{
					one=false;
					break;
				}
				else
				{

					// std::cout<<x<<" "<<y<<" "<<wall[j].first<<" "<<wall[j].second<<std::endl;

					one=true;
					// x=wall[i].first;
					// y=wall[i].second;
				}
			}


			if(one==true)
			{
				std::cout<<"YES"<<std::endl;
				std::cout<<x<<" "<<y<<std::endl;
				return 0;
			}
			x=i;
			y=k;
		}
	}

	std::cout<<"NO"<<std::endl;

	// std::cout<<x<<" "<<y<<std::endl;

	return 0;
}