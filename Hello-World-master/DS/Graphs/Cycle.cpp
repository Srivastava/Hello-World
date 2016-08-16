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
typedef std::vector<vll> vvll;
typedef std::vector<bool> vb;

bool isCyclicUtil(vvll& graph,ll i,vb& visited,ll parent)
{
	visited[i]=true;
	std::cout<<i<<std::endl;
	// std::vector<ll> ::iterator it;
	for(int j=1;j<graph[i].size();++j)
	{
		if(!visited[graph[i][j]])
		{
			if(isCyclicUtil(graph,graph[i][j],visited,graph[i][0]))
				return true;
		}

		else if(graph[i][j]!=parent)
		{
			return true;
		}
	}

	return false;
}

bool isCyclic(vvll& graph)
{
	vb visited(graph.size(),false);

	for(int i=1;i<graph.size();++i)
	{
		if(!visited[graph[i][0]])
		{
			if(isCyclicUtil(graph,graph[i][0],visited,-1))
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{

	ll n,m;
	std::cin>>n>>m;

	vvll graph(n+1,vll(1,0));

	for(ll i =1 ;i<=m;++i)
	{
		ll u,v;
		std::cin>>u>>v;

		graph[u][0]=u;
		graph[v][0]=v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(ll i =1 ;i<graph.size();++i)
	{
		for(int j=0;j<graph[i].size();++j)
		{
			std::cout<<graph[i][j]<<",";
		}
		std::cout<<std::endl;
	}

	// vll ans=bfs(graph,3);
	// vll ans=bfs(graph);

	if(isCyclic(graph))
	{
		std::cout<<"Cycle is Present"<<std::endl;
	}
	else
	{
		std::cout<<"NO Cycle :)"<<std::endl;
	}

	// std::copy(ans.begin(),ans.end(),std::ostream_iterator<ll>(std::cout," "));
	// std::cout<<std::endl;

	return 0;
}