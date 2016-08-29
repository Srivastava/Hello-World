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

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

int depth(vvi g, int i, int& dist,vb& visited)
{

	if(dist>=4){return;}
	for(int j=1;j<g[i].size();++j)
	{
		int k =g[i][j];
		if(!visited[k])
		{
			visited[k]=true;
			depth(g,k,dist,visited);
		}
	}
}
int solve(vvi& g)
{
	int size=g.size();
	for(int i=1;i<size++i)
	{
		
		vb visited(size,false);

		int dep=0;
		std::stack<int> q;
		q.push(i);
		while(dep<4)
		{
			int top = q.top();
			q.pop();

			for(int j=1;j<g[top].size();++j)
			{
				int k =g[top][j];
				if(!visited[k])
				{
					visited[k]=true;
					q.push(k);
					++dep;
				}
			}

		}
	}
}

int main()
{
	int n,m;
	std::cin>>n>>m;

	vvi g(n+1,vi(g,0));

	for(int i=0;i<m;++i)
	{
		int u,v;
		std::cin>>u>>v;

		g[u]=u;
		g[v]=v;
		g[u].push_back(v);
	}

	int start = solve(g);
	return 0;
}