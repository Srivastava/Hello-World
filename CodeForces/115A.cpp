#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::vector<vll> vvll;
typedef std::vector<bool> vb;
typedef std::vector<int> vi;


void colorUtil(vi& color, vb& visited, const vvll& graph,const ll& i)
{
	std::stack<ll> s;
	s.push(i);

	while(!s.empty())
	{
		ll t=s.top();
		s.pop();

		for(ll j=1;j<graph[t].size();++j)
		{
			ll temp=graph[t][j];
			if(!visited[temp])
			{
				visited[temp]=true;
				s.push(temp);
				color[temp]=color[t]+1;
			}

			else
			{
				if(color[temp]==color[t])
				{
					color[temp]=color[t]+1;
					s.push(temp);
				}
			}
		}

	}
}


ll solve(const vvll& graph)
{
	
	vb visited(graph.size(),false);
	// visited[1]=true;

	vi color(graph.size(),-1);
	// color.reserve(graph.size());

	ll count=0;
	for(ll i=1;i<graph.size();++i)
	{
		ll temp = graph[i][0];
		if(!visited[temp])
		{
			color[temp]=1+count;
			// ++count;
			visited[temp]=true;
			colorUtil(color,visited,graph,temp);
		}
	}	

	std::unordered_set<int> set(color.begin()+1,color.end());

	std::unordered_set<int>::iterator it;
	for (it =set.begin(); it !=set.end(); ++it)
	{
	   std::cout<<*it<<",";; // Note the "*" here
	}

	std::cout<<std::endl;
	std::copy(color.begin(),color.end(),std::ostream_iterator<int>(std::cout,","));
	std::cout<<std::endl;
	return set.size();

}

int main()
{
	ll n;
	std::cin>>n;

	vvll graph(n+1,vll(1,0));
	vll bfs;

	for(ll i=1;i<=n;++i)
	{
		ll val;
		std::cin>>val;

		graph[i][0]=i;

		if(val!=-1)
		{
			graph[val].push_back(i);
		}
		else
		{
			bfs.push_back(i);
		}

	}


	// std::cout<<"--------------"<<std::endl;
	// for(int i=1;i<=n;++i)
	// {
	// 	for(int j=0;j<graph[i].size();++j)
	// 	{
	// 		std::cout<<graph[i][j]<<" ";
	// 	}
	// 	std::cout<<std::endl;
	// }
	// std::cout<<"--------------"<<std::endl;
	
	// std::cout<<solve(graph)<<std::endl;
		
	ll level=0;

	vb visited(n+1,false);

	for(ll s:bfs)
	{
		std::queue<std::pair<ll,ll> > q;
		q.push({s,1});
		visited[s]=true;

		while(!q.empty())
		{
			std::pair<ll,ll> t= q.front();
			q.pop();

			level=std::max(level,t.second);

			for(int i=1;i<graph[t.first].size();++i)
			{
				ll temp=graph[t.first][i];

				if(!visited[temp])
				{
					visited[temp]=true;
					q.push({temp,t.second+1});
				}
			}
		}
	}

	std::cout<<level<<std::endl;

	return 0;
}