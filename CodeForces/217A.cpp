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

typedef std::vector<vll> vvll;

vpa sd;
pa target;
ll limit,limitX;
/*
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
*/

void dfs(int u,vpa& g,vb& visited)
{
	if(visited[u])
	{
		return;
	}
	int n=visited.size();
	visited[u]=true;
	for(int i=0;i<n;++i)
	{
		if(g[u].first==g[i].first || g[u].second==g[i].second)
		{
			dfs(i,g,visited);
		}
	}
}

vvll row,col;
int main()
{
	ll n;
	std::cin>>n;

	vpa sd;

	for(int i=0;i<n;++i)
	{
		ll x,y;
		std::cin>>x>>y;

		sd.push_back({x,y});
	}

	vb visited(n+1,false);

	int cnt=0;

	for(int i=0;i<n;++i)
	{
		if(!visited[i])
		{
			dfs(i,sd,visited);
			++cnt;
		}
	}

	std::cout<<cnt-1<<std::endl;
	return 0;
}