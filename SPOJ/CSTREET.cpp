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

vi s(1005,0);

struct edge
{
	int u,v,w;

	edge(int _u,int _v,int _w)
	{
		u=_u;
		v=_v;
		w=_w;
	}
};


int find(int x)
{
	return x==s[x] ? x :s[x]=find(s[x]);
}

void join(int x,int y)
{
	s[find(x)]=find(y);
}


bool edge_comp(const edge& a,const edge& b)
{
	return a.w<b.w;
}

ll kruskal(std::vector<edge>& edges)
{
	std::sort(edges.begin(),edges.end(),edge_comp);

	ll ans=0;
	int num=edges.size();
	for(int i=0;i<num;++i)
	{
		int u=edges[i].u;
		int v=edges[i].v;

		if(find(u)!=find(v))
		{
			join(u,v);
			ans+=edges[i].w;
		}
	}
	return ans;
}


// std::vector<edge> g[1005];
int main()
{
	int t;
	std::cin>>t;

	while(t--)
	{
		int p;
		std::cin>>p;

		int n,m;
		std::cin>>n>>m;

		// std::cout<<p<<" "<<n<<" "<<m<<std::endl;
		// std::vector<edge> g[1005];

		std::vector<edge> edges;
		edges.reserve(m);

		for(int i=0;i<m;++i)
		{
			int u,v,w;
			std::cin>>u>>v>>w;

			edges.push_back(edge(u,v,w));
		}

		for(int i=0;i<=n;++i)
		{
			s[i]=i;
		}

		ll ans=kruskal(edges);
		std::cout<<ans*p<<std::endl;
	}
	return 0;
}