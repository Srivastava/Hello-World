#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::vector<vll> vvll;


//Just DFS

vll bfs(vvll& graph,const ll& a)
{
	std::vector<bool> visited(graph.size(),false);

	vll dp;

	std::queue<ll> s;
	s.push(a);

	dp.push_back(a);
	visited[a]=true;
	
	while(!s.empty())
	{
		ll temp= s.front();
		s.pop();

		// if(!visited[temp])
		// {
		// 	dp.push_back(temp);
		// }
		
		// if(!visited[temp])
		{

			for(ll i=1;i<graph[temp].size();++i)
			{
				if(!visited[graph[temp][i]])
				{
					// std::cout<<graph[temp][i]<<",";
					visited[graph[temp][i]]=true;
					dp.push_back(graph[temp][i]);
					s.push(graph[temp][i]);
				}	

			}
		}
		

		// std::cout<<std::endl;
	}

	return dp;
}

// Complete Graph Traversal
vll bfs(vvll& graph)
{
	std::vector<bool> visited(graph.size(),false);

	vll dp;

	std::queue<ll> s;

	for(int j=1;j<graph.size();++j)
	{

		s.push(graph[j][0]);

		// dp.push_back(a);

		while(!s.empty())
		{
			ll temp= s.front();
			s.pop();

			// if(!visited[temp])
			// {
			// 	dp.push_back(temp);
			// }
			
			if(!visited[temp])
			{
				dp.push_back(temp);
				for(ll i=1;i<graph[temp].size();++i)
				{
					if(!visited[graph[temp][i]])
					{
						// std::cout<<graph[temp][i]<<",";
						visited[graph[temp][i]]=true;
						dp.push_back(graph[temp][i]);
						s.push(graph[temp][i]);
					}	

				}
			}
	}
		

		// std::cout<<std::endl;
	}

	return dp;
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

	for(ll i =1 ;i<=m;++i)
	{
		// ll u,v;
		// std::cin>>u>>v;
		for(int j=0;j<graph[i].size();++j)
		{
			std::cout<<graph[i][j]<<",";
		}
		std::cout<<std::endl;
		// graph[u].push_back(v);
		// graph[v].push_back(u);
	}

	vll ans=bfs(graph,3);
	// vll ans=bfs(graph);
	std::copy(ans.begin(),ans.end(),std::ostream_iterator<ll>(std::cout," "));
	std::cout<<std::endl;

	return 0;
}