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
typedef std::pair<int,int> pai;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;
typedef std::vector<vi> vvi;
typedef std::vector<vpa> vvpa;

// vpa g[1e6+5]

/*int minIndex(vi& dist, vb& visited)
{
	int min=dist[0],index=0;

	for(int i=1;i<dist.size();++i)
	{
		if(min>dist[i] && visited[i])
		{
			min=dist[i];
			index=i;
		}
	}

	return index;
}

vi solve(vvi& g)
{
	vb visited(n,true);

	vi ans(g.size(),-1);
	vi dist(g.size(),MOD);

	dist[1]=0;

	while(1)
	{
		int u = minIndex(dist,visited);
		visited[u]=false;
		

		if(u==g.size()-1){break;}
		if(u==0)
		{
			vi sol(1,0);
			return sol;
		}
		for(int i =1;i<g[u].size();++i)
		{
			if(g[u][i]!=-1)
			{
				
				int alt=dist[u]+g[u][i];
				if(alt<dist[i])
				{
					dist[i]=alt;
					ans[i]=u;
				}
			}
		}
	}

	return ans;
}
int main()
{
	int n,m;
	std::cin>>n>>m;

	// std::cout<<"HERE"<<std::endl;

	vvi g(n+1,vi(n+1,-1));

	// std::cout<<"HERE 1 "<<std::endl;

	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		std::cin>>u>>v>>w;
		if(g[u][v]==-1)
		{
			g[u][v]=w;
			g[v][u]=w;
		}
		else
		{
			g[u][v]<w ? g[u][v]=g[u][v]:g[u][v]=w,g[v][u]=w;
		}
	}

	vi ans=solve(g);

	if(ans[0]==0){std::cout<<-1<<std::endl;return 0;}
	
	vi ansp;
	ansp.push_back(n);
	
	int index=n;
	while(index!=1)
	{
		int val=ans[index];
		ansp.push_back(val);
		index=val;
	}

	// ansp.push_back(1);

	
	// std::copy(ans.begin(),ans.end(),std::ostream_iterator<int>(std::cout," "));
	// std::cout<<std::endl;
	// std::cout<<solve(g)<<std::endl;
	std::reverse(ansp.begin(),ansp.end());
	std::copy(ansp.begin(),ansp.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;
	return 0;
}*/

vpa g[100000+5];
ll n,m;

ll minIndex(vll& dist, vb& visited)
{
	ll min=dist[0],index=0;
	bool allvis=true;

	// std::cout<<"HERE minIndec"<<std::endl;
	for(ll i=1;i<dist.size();++i)
	{
		if(visited[i])
		{
			allvis=false;
		}
		if(min>dist[i] && visited[i])
		{
			min=dist[i];
			index=i;
		}
	}

	if(allvis){return -1;}
	return index;
}

vi solve()
{
	vb visited(n,true);

	vi ans(n+1,-1);
	vll dist(n+1,1000000000000);

	dist[1]=0;

	while(1)
	{
		ll u = minIndex(dist,visited);
		if(u==-1){break;}
		visited[u]=false;
		
		// std::cout<<u<<std::endl;
		if(u==n){break;}
		if(u==0)
		{
			vi sol(1,0);
			return sol;
		}

		// std::cout<<g[u].size()<<" sixe "<<std::endl;
		for(ll i =0;i<g[u].size();++i)
		{
		
			pai temp=g[u][i];
			// std::cout<<temp.first<<" ** "<<temp.second<<std::endl;
			ll alt=dist[u]+temp.second;
			// std::cout<<alt<<" *** "<<dist[temp.first]<<std::endl;
			if(alt<dist[temp.first])
			{
				dist[temp.first]=alt;
				ans[temp.first]=u;
			}
		
		}
	}

	// std::cout<<" returned "<<std::endl;
	return ans;
}
int main()
{
	std::cin>>n>>m;

	// std::cout<<"HERE"<<std::endl;

	// vvi g(n+1,vi(n+1,-1));

	// std::cout<<"HERE 1 "<<std::endl;

	for(ll i=1;i<=m;++i)
	{
		ll u,v,w;
		std::cin>>u>>v>>w;

		g[u].push_back(std::make_pair(v,w));
		g[v].push_back(std::make_pair(u,w));
		/*if(g[u][v]==-1)
		{
			g[u][v]=w;
			g[v][u]=w;
		}
		else
		{
			g[u][v]<w ? g[u][v]=g[u][v]:g[u][v]=w,g[v][u]=w;
		}*/
	}


	vi ans=solve();
	// std::copy(ans.begin(),ans.end(),std::ostream_iterator<ll>(std::cout," "));
	// std::cout<<std::endl;

	if(ans.size()==1 && ans[0]==0){std::cout<<-1<<std::endl;return 0;}
	
	vi ansp;
	ansp.push_back(n);
	
	ll index=n;
	// std::cout<<"Outsided"<<std::endl;
	while(index!=1)
	{
		ll val=ans[index];
		ansp.push_back(val);
		index=val;
	}

	// ansp.push_back(1);

	
	// std::cout<<solve(g)<<std::endl;
	std::reverse(ansp.begin(),ansp.end());
	std::copy(ansp.begin(),ansp.end(),std::ostream_iterator<ll>(std::cout," "));
	std::cout<<std::endl;
	return 0;
}