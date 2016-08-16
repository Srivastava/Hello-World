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

vll g[100010];
ll n,m;
int len=0;
bool bt=true;

void dfs(int u,int v,vb& visited)
{
	// std::cout<<u<<std::endl;
	visited[u]=true;
	++len;
	for(int i=0;i<g[u].size();++i)
	{
		
		if(g[u].size()>2){bt=false;}
		int j=g[u][i];

		if(!visited[j])
		{
			// visited[j]=true;
			dfs(j,u,visited);
		}
		else if(j!=v)
		{
			// std::cout<<j<<" "<<u<<std::endl;
			bt=false;
		}

	}
}

std::string solve()
{
	bool rt=true,st=true;

	// for(int i=1;i<=n;++i)
	for(int i=1;i<=n;++i)
	{
		if(g[i].size()!=2)
		{
			rt=false;
			break;
		}
	}

	if(rt)
	{
		return "ring topology";
	}

	for(int i=1;i<=n;++i)
	{
		if(g[i].size()!=1)
		{
			if(g[i].size()!=m)
			{
				st=false;
				break;
			}

		}
	}

	if(st){return "star topology";}

	{
		vb visited(n+1,false);

		len=0;
		dfs(1,0,visited);
		
		// std::cout<<len<<std::endl;
		if(len==n && bt)
		{
			return "bus topology";
		}
	}
	len=0;
	
	return "unknown topology";
}


int main()
{
	std::cin>>n>>m;

	for(int i=1;i<=m;++i)
	{
		int u,v;
		std::cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	std::cout<<solve()<<std::endl;

	return 0;
}