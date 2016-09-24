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

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

int g[1000];
vb visited(1000,false);
vi component(1000,-1);

void dfs(int u)
{
	if(visited[u])
	{
		return;
	}

	visited[u]=true;

	for(int i=0;i<g[u].size();++i)
	{
		int v=g[u][i];
		dfs(v);
	}
}


void find_component(int currC,int u)
{
	if(component[u]!=-1)
	{
		return;
	}

	component[u]=currC;

	for(int i=0;i<g[u].size();++i)
	{
		int v=g[u][i];
		find_component(currC,v);
	}
}

int numComponent()
{
	int components=0
	for(int i=0;i<n;++i)
	{
		if(component[u]==-1)
		{
			find_component(components,u);
			++components;
		}
	}
	return components;
}

void solveDfs()
{

}

int main()
{

	for(int i=0;i<10;++i)
	{
		g[i].push_back(i+1);
		g[i+1].push_back(i);
	}

	return 0;
}