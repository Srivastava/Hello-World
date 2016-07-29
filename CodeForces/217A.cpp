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
typedef std::vector<bool> vb;
typedef std::vector<int> vi;

typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

vpa sd;
pa target;
ll limit,limitX;

ll solveUtil(pa curr,pa prev)
{
	ll l=0,r=0,t=0,b=0;
	
	std::cout<<target.first<<" "<<target.second<<" "<<curr.first<<" "<<curr.second<<" "<<prev.first<<" "<<prev.second<<std::endl;
	if(curr==target)
	{
		return 0;
	}

	if(curr.first>1)
	{
		pa left={curr.first-1,curr.second};
		
		if(left!=prev){

			if(left.first!=prev.first && left.second!=prev.second)
			{
				l=solveUtil(left,curr)+1;
			}
			else
			{
				l=solveUtil(left,curr);
			}
		}
	}
	
	if(curr.first<limit)
	{
		pa right={curr.first+1,curr.second};
		
		if(right!=prev)
		{

			if(right.first!=prev.first && right.second!=prev.second)
			{
				r=solveUtil(right,curr)+1;
			}
			else
			{
				r=solveUtil(right,curr);
			}
		}
	}
	
	if(curr.second<limit)
	{

		pa top={curr.first,curr.second+1};

		if(top!=prev)
		{

			if(top.first!=prev.first && top.second!=prev.second)
			{
				t=solveUtil(top,curr)+1;
			}
			else
			{
				t=solveUtil(top,curr);
			}
		}
	}
	
	if(curr.second>1)
	{

		pa bottom={curr.first,curr.second-1};
		
		if(bottom!=prev)
		{
			
			if(bottom.first!=prev.first && bottom.second!=prev.second)
			{
				b=solveUtil(bottom,curr)+1;
			}
			else
			{
				b=solveUtil(bottom,curr);
			}
		}
	}

	return std::min(l,std::min(r,std::min(t,b)));

}

ll solve()
{
	ll ans =solveUtil(sd[0],std::make_pair(-1,-1));
}

int main()
{
	ll n;
	std::cin>>n;

	// vpa sd;

	for(int i=0;i<n;++i)
	{
		ll x,y;
		std::cin>>x>>y;

		sd.push_back({x,y});
	}

	target=sd[n-1];
	limit=std::max(std::abs(target.first+sd[0].first),std::abs(target.second+sd[0].second));
	limit=std::min(limit,1000LL);
	limitX=std::max(std::abs(target.first-sd[0].first),std::abs(target.second-sd[0].second));
	std::cout<<solve()<<std::endl;

	return 0;
}