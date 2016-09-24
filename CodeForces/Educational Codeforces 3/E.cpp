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

ll n,m;
const int mlog=19;
vpa graph[200005];

struct edge
{
	ll u,v,w;
	edge(ll _u,ll _v, ll _w)
	{
		u=_u;
		v=_v;
		w=_w;
	}
};

std::vector<edge> g;
vi s(200005,0);
vi h(200005,0);
int par[200005][mlog]={-1};
ll mw[200005][mlog]={0};

ll find(ll u)
{
	return u==s[u] ? u :s[u]=find(s[u]);
}

void join(ll u, ll v)
{
	s[find(u)]=find(v);
}



bool edgeCmp(const edge& a , const edge& b)
{
	return a.w<b.w;
}

ll mst(std::vector<edge>& edges)
{
	ll ans=0;

	/*join(e.u,e.v);
	ans+=e.w*/;

	for(int i=0;i<m;++i)
	{
		int u=g[i].u,v=g[i].v;

		// std::cout<<"HERE "<<u<<" "<<v<<std::endl;
		if(find(u)!=find(v))
		{
			join(u,v);
			edges.push_back(g[i]);
			ans+=g[i].w;
		}
	}

	return ans;
}

void dfs(int v,int p,ll val)
{
	par[v][0]=p;
	mw[v][0]=val;
	// std::cout<<v<<" "<<p<<std::endl;
	// std::cout<<"HERE 1"<<std::endl;
	if(p+1)
	{
		h[v]=h[p]+1;
	}

	// std::cout<<"HERE 2"<<std::endl;

	for(int i=1;i<mlog;++i)
	{
		if(par[v][i-1]+1)
		{
			par[v][i]=par[par[v][i-1]][i-1];
			mw[v][i]=std::max(mw[v][i-1],mw[par[v][i-1]][i-1]);
		}
	}

	// std::cout<<"HERE 3"<<std::endl;

	for(auto u:graph[v])
	{
		if(p-u.first)
		{
			// mw[u.first][0]=u.second;
			dfs(u.first,v,u.second);
		}
	}
}

ll LCA(int v,int u)
{
	ll ans=-1;

	if(h[v]<h[u])
	{
		std::swap(v,u);
	}

	// ans=std::max(ans,mw[v][0]);
	// ans=std::max(ans,mw[u][0]);

	for(int i=mlog-1;i>=0;i--)
	{
		if(par[v][i]+1 && h[par[v][i]]>=h[u])
		{
			ans=std::max(ans,mw[v][i]);
			// std::cout<<mw[v][i]<<" mw "<<std::endl;
			v=par[v][i];
		}
	}
	if(v==u){return ans;}

	// ans=std::max(ans,mw[v][0]);
	// ans=std::max(ans,mw[u][0]);

	for(int i=mlog-1;i>=0;i--)
	{
		if(par[v][i]-par[u][i])
		{
			ans=std::max(ans,mw[v][i]);
			ans=std::max(ans,mw[u][i]);
			v=par[v][i];
			u=par[u][i];
		}
	}
	ans=std::max(ans,mw[v][0]);
	ans=std::max(ans,mw[u][0]);

	/*ans=std::max(ans,mw[par[v][0]][0]);
	ans=std::max(ans,mw[par[u][0]][0]);*/
	return ans;
}

int main()
{
	std::cin>>n>>m;
	g.reserve(m);

	std::vector<edge> test;
	test.reserve(m);

	for(ll i=0;i<m;++i)
	{
		ll u,v,w;
		std::cin>>u>>v>>w;

		g.push_back(edge(u,v,w));
		// g.push_back(edge(v,u,w));

		/*graph[u].push_back(std::make_pair(v,w));
		graph[v].push_back(std::make_pair(u,w));*/
		
		test.push_back(edge(u,v,w));
	}

	
	std::sort(g.begin(),g.end(),edgeCmp);
	
	for(ll i=0;i<=n;++i)
	{
		s[i]=i;
	}
	// ll ans=mst(test[i]);
	
	std::vector<edge> ms;
	ll ans=mst(ms);

	for(auto i : ms)
	{
		graph[i.u].push_back({i.v,i.w});
		graph[i.v].push_back({i.u,i.w});
	}

	// std::cout<<ans<<" ans"<<std::endl;
	dfs(1,-1,0);
	for(int i=0;i<m;++i)
	{
		ll u=test[i].u;
		ll v=test[i].v;
		ll w=test[i].w;

		ll sol=LCA(u,v);
		// std::cout<<sol<<" sol "<<std::endl;
		std::cout<<ans-sol+w<<std::endl;
	}
	return 0;
}