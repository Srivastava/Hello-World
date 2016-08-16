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

vll g[105];
vb visited(105,false);

int n,m;
int answering=0,s=0;

bool dfs(int u,int v)
{
	++s;

	visited[u]=true;

	// std::cout<<"HERE dfs u "<<u<<std::endl;
	for(int i=0;i<g[u].size();++i)
	{
	
		int j=g[u][i];
		// std::cout<<"HERE dfs "<<j<<std::endl;
		if(!visited[j])
		{
			visited[j]=true;
			if(dfs(j,u))
			{
				return true;
			}
		}
		else if(j!=v)
		{
			++answering;
			// std::cout<<j<<" "<<u<<" great msystery"<<std::endl;
			// return true;
		}
	}
	
	return false;
}

bool solve()
{

	bool ans=false;

	// std::cout<<"HERE solve"<<std::endl;


	
	/*int comp=0;
	// for(int i=1;i<=n;++i)
	{
		std::cout<<"HERE solve "<<i<<std::endl;
		if(!visited[i])
		{
			// ++comp;

			visited[i]=true;
			bool result=dfs(i,0);
			
			if(result)
			{
				--comp;
				if(ans==true){ans=false;break;}
				ans=true;
			}
		}

	}*/

	dfs(1,0);

	// std::cout<<"HERE solve "<<comp<<" ans "<<ans<<std::endl;
	if(answering==2 && s==n){ans=true;}
	return ans;
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


	if(solve())
	{
		std::cout<<"FHTAGN!"<<std::endl;
	}
	else
	{
		std::cout<<"NO"<<std::endl;
	}
	return 0;
}