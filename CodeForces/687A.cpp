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

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

// ll solve(vvll& graph)
// {
// 	vb visited(graph.size(),false);

// 	vi color(graph.size(),-1);

// 	std::queue

// }

int main()
{
	ll n,m;
	std::cin>>n>>m;

	vvll graph(n+1,vll(1,0));

	for(int i=0;i<m;++i)
	{
		ll u,v;
		std::cin>>u>>v;

		graph[u][0]=u;
		graph[v][0]=v;

		graph[u].push_back(v);
		graph[v].push_back(u);

	}

	// std::cout<<solve(graph)<<std::endl;

	vb visited(graph.size(),false);

	vi color(graph.size(),1);

	std::queue<ll> q;
	q.push(graph[1][0]);
	visited[graph[1][0]]=true;

	// bool bipartite=true;
	while(!q.empty())
	{
		ll top=q.front();
		q.pop();

		visited[top]=true;

		for(ll i=1;i<graph[top].size();++i)
		{
			ll j=graph[top][i];
			if(!visited[j])
			{
				// if(color[top])
				// {
					color[j]=1-color[top];
				// }
				// else
				// {
				// 	color[j]=
				// }

				q.push(j);
				visited[j]=true;
			}
			else if(color[j]==color[top])
			{
				
				std::cout<<-1<<std::endl;
				return 0;
				break;
			}
		}
	}

	ll count=0;

	for(ll i=1;i<=n;++i)
	{
		if(color[i]) {++count;}
	}

	std::cout<<count<<std::endl;
	for(ll i=1;i<=n;++i)
	{
		if(color[i])
		{
			std::cout<<i<<" ";
		}

	}

	std::cout<<std::endl;
	std::cout<<n-count<<std::endl;
	


	for(ll i=1;i<=n;++i)
	{
		if(!color[i])
		{
			std::cout<<i<<" ";
		}
	}

	return 0;
}