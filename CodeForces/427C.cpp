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
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;
const int maxn = 1e6+5;

vi g[maxn];
vi low(maxn,-1),num(maxn,-1),scc(maxn,-1);

vb instack(maxn,false);
int curnum=0,currScc=0;

std::stack<int> s;

void tarjan(int u)
{
	s.push(u);
	instack[u]=true;

	low[u]=num[u]=curnum++;

	for(int i=0;i<g[u].size();++i)
	{
		int v = g[u][i];

		if(num[v]==-1)
		{
			tarjan(v);
			low[u]=std::min(low[u],low[v]);
		}
		else if(instack[v])
		{
			low[u]=std::min(low[u],num[v]);
		}
	}

	if(num[u]==low[u])
	{
		int curr;
		do
		{
			curr=s.top();

			s.pop();
			instack[curr]=false;

			scc[curr]=currScc;
		}while(u!=curr);
		currScc++;
	}
}

int main()
{
	int n;
	std::cin>>n;

	vll cost(n+1,0);
	for(int i=1;i<=n;++i)
	{
		std::cin>>cost[i];
	}
	int m;
	std::cin>>m;

	for(int i=1;i<=m;++i)
	{
		int u,v;
		std::cin>>u>>v;
		g[u].push_back(v);
	}

	for(int i=1;i<=n;++i)
	{
		if(num[i]==-1)
		{
			tarjan(i);
		}
	}

	/*for(int i=1;i<=n;++i)
	{
		for(int j=0;j<g[i].size();++j)
		{
			std::cout<<g[i][j]<<" ";
		}
		std::cout<<std::endl;
	}*/

	vi sccC[currScc];
	for(int i=1;i<=n;++i)
	{
		sccC[scc[i]].push_back(i);
	}

	/*for(int i=0;i<currScc;++i)
	{
		for(int j=0;j<sccC[i].size();++j)
		{
			std::cout<<sccC[i][j]<<" ** ";
		}
		std::cout<<std::endl;
	}*/

	ll ans=0,ans1=1;
	for(int i=0;i<currScc;++i)
	{
		ll num=1;ll min=2000000000;
		for(int j=0;j<sccC[i].size();++j)
		{
			int u = sccC[i][j];
			if(min>cost[u])
			{
				min=cost[u];
				num=1;
			}
			else if(min==cost[u])
			{
				++num;
			}	
		}
		ans1=(ans1*(num%MOD))%MOD;
		ans+=min;
	}

	std::cout<<ans<<" "<<ans1<<std::endl;
	// std::copy(scc.begin()+1,scc.begin()+n+1,std::ostream_iterator<int>(std::cout,","));
	// std::cout<<std::endl;


	return 0;
}