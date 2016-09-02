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
int ticks=0,currScc=0;

std::stack<int> s;


void tarjan(int u)
{

	s.push(u);
	instack[u]=true;

	low[u]=num[u]=ticks++;

	for(int v:g[u])
	{
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

	// std::cout<<u<<" "<<low[u]<<" "<<num[u]<<" **** "<<std::endl;
	if(num[u]==low[u])
	{
		int curr;
		do
		{
			curr=s.top();
			// std::cout<<curr<<" curr "<<u<<std::endl;

			s.pop();
			instack[curr]=false;

			scc[curr]=currScc;
		}while(u!=curr);
		currScc++;
	}

}

int main()
{
	int n,m;
	std::cin>>n>>m;

	vi inDeg(n+1,0);

	for(int i=1;i<=m;++i)
	{
		int u,v;
		std::cin>>u>>v;

		g[u].push_back(v);
		inDeg[u]++;
	}

	/*for(int i=1;i<=n;++i)
	{
		for(int j=0;j<g[i].size();++j)
		{
			std::cout<<g[i][j]<<",";
		}
		std::cout<<std::endl;
	}*/
	// std::cout<<"HERE"<<std::endl;
	for(int i=1;i<=n;++i)
	{
		if(num[i]==-1)
		{
			
			tarjan(i);
		}
	}

	vi sccC[currScc];
	for(int i=1;i<=n;++i)
	{
		sccC[scc[i]].push_back(i);
	}

	for(int i=0;i<currScc;++i)
	{
		if(sccC[i].size()>1)
		{
			for(int v:sccC[i])
			{
				inDeg[v]=0;
			}
		}
	}

	// std::cout<<"HERE 1"<<std::endl;
	int index=-1;
	for(int i=1;i<=n;++i)
	{
		if(inDeg[i]==0 && index==-1)
		{
			index=i;
		}
		else if(inDeg[i]==0 && index!=-1)
		{
			if(scc[i]!=scc[index])
			{

				index=-1;
				break;
			}
		}
	}

	/*std::copy(scc.begin(),scc.begin()+n+1,std::ostream_iterator<int>(std::cout,","));
	std::cout<<std::endl;*/
	
	// std::cout<<"HERE 2"<<std::endl;
	if(index==-1){std::cout<<"NO ANSWER"<<std::endl;return 0;}

	// std::cout<<"HERE 3"<<std::endl;

	// std::cout<<"HERE 4"<<std::endl;
	// std::cout<<index<<std::endl;
	
	index=scc[index];


	std::sort(sccC[index].begin(),sccC[index].end());

	// std::cout<<"HERE 5"<<std::endl;
	std::cout<<sccC[index].size()<<std::endl;

	// std::cout<<"HERE 6"<<std::endl;
	std::copy(sccC[index].begin(),sccC[index].end(),std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;

	// std::cout<<"HERE 7"<<std::endl;

	return 0;
}