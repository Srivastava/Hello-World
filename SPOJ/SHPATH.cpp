#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_map>

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


struct edge
{
	ll u,v,w;

	edge(ll _u, ll _v, ll _w)
	{
		u=_u;
		v=_v;
		w=_w;
	}
};

std::vector<edge> g[10005];
vvll dist(10005,vll(10005,1e15));

void dijkstra(ll start)
{
	dist[start][start]=0;

	std::priority_queue<std::pair<ll,ll>,std::vector<std::pair<ll,ll> >,std::greater<std::pair<ll,ll> > >pq;

	pq.push(std::make_pair(dist[start][start],start));

	while(!pq.empty())
	{
		ll u=pq.top().second;
		pq.pop();

		for(int i=0;i<g[u].size();++i)
		{
			ll v=g[u][i].v;
			ll w=g[u][i].w;

			if(dist[start][u]+w<dist[start][v])
			{
				dist[start][v]=dist[start][u]+w;
				pq.push(std::make_pair(dist[start][v],v));
			}
		}
	}

}


int main()
{
	std::unordered_map<std::string,int> map;

	int t;
	std::cin>>t;

	while(t--)
	{
		int n;
		scanf("%d",&n);
		// std::cin>>n;

		for(int i=1;i<=n;++i)
		{
			std::string str;
			std::cin>>str;

			map[str]=i;

			int p;

			scanf("%d",&p);
			// std::cin>>p;

			for(int j=0;j<p;++j)
			{
				int v,w;
				// std::cin>>v>>w;
				scanf("%d%d",&v,&w);

				g[i].push_back(edge(i,v,w));

			}
		}

		int r;
		scanf("%d",&r);
		// std::cin>>r;

		/*for(int i=1;i<=n;++i)
		{

			dijkstra(i);
		}*/

		for(int i=0;i<r;++i)
		{
			std::string src,dest;
			std::cin>>src>>dest;
			// scanf("%100s%100s",&src,&dest);
			int u=map[src];
			int v=map[dest];

			if(dist[u][u]!=0)
			{
				dijkstra(u);
			}
			
			std::cout<<dist[u][v]<<std::endl;
		}
	}
	return 0;
}