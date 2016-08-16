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


ll dijkstra(vvll& g)
{
	vll v(g.size(),0),d(g.size(),0),prev(g.size(),0);
	
	ll target = g.size()-1;

	for(int i=1;i<g.size();++i)
	{
		v[i]=i;
		d[i]=500;
	}

	d[1]=0;

	bool lol=true;
	while(1)
	{
		ll u=0,min=500;
		for(int i=1;i<=target;++i)
		{
			// std::cout<<i<<" "<<u<<std::endl;
			if(v[i]!=-1)
			{
				if(min>d[i])
				{
					min=d[i];
					u=i;
				}
			}
			if(i==target && u==0){lol=false;break;}
		}

		if(u==target){break;}
		if(!lol){break;}

		v[u]=-1;

		for(int i=1;i<g[u].size();++i)
		{
			ll j=g[u][i];
			ll a=d[u]+1;
			if(a<d[j])
			{
				d[j]=a;
				prev[j]=u;
			}
		} 
	}

	/*std::cout<<"----- distance----------"<<std::endl;
	std::copy(d.begin(),d.end(),std::ostream_iterator<ll>(std::cout,"*"));
	std::cout<<std::endl;*/

	return d[target];

}

int main()
{
	ll n,m;
	std::cin>>n>>m;


	vvll t(n+1,vll(1,0));
	for(int i=1;i<=n;++i)
	{
		t[i][0]=i;
	}


	for(int i=1;i<=m;++i)
	{
		ll u,v;
		std::cin>>u>>v;

		t[u][0]=u;
		t[v][0]=v;

		t[u].push_back(v);
		t[v].push_back(u);		

	}

	vvll r(n+1,vll(1,0));
	for(int i=1;i<=n;++i)
	{
		r[i][0]=i;
	}

	for(int i=1;i<=n;++i)
	{
		vb visited(n+1,false);
		for(int j=1;j<t[i].size();++j )
		{
			visited[t[i][j]]=true;
		}

		for(int j=1;j<=n;++j)
		{
			if(i!=j && !visited[j])
			{
				r[i].push_back(j);
			}

		}	

	}

/*
	std::cout<<"---------------"<<std::endl;
	for(int i=1;i<t.size();++i)
	{
		for(int j=0;j<t[i].size();++j)
		{
			std::cout<<t[i][j]<<",";
		}
		std::cout<<std::endl;
	}

	std::cout<<"---------------"<<std::endl;
	for(int i=1;i<r.size();++i)
	{
		for(int j=0;j<r[i].size();++j)
		{
			std::cout<<r[i][j]<<",";
		}
		std::cout<<std::endl;
	}
*/
	ll trains=dijkstra(t);
	ll roads=dijkstra(r);

	if(trains==500 || roads==500){std::cout<<-1<<std::endl;}
	else
	{
		
		std::cout<<std::max(trains,roads)<<std::endl;
	}
	// std::cout<<"---------------"<<std::endl;
	// std::copy(trains.begin(),trains.end(),std::ostream_iterator<ll>(std::cout,"*"));
	// std::cout<<std::endl;

	// std::cout<<"---------------"<<std::endl;
	// std::copy(roads.begin(),roads.end(),std::ostream_iterator<ll>(std::cout,"*"));
	// std::cout<<"---------------"<<std::endl;
	// std::cout<<std::endl;
	// ll distT=trains.size()-1;
	// ll distR=roads.size()-1;

	// if(distR==-1 || distT==-1){std::cout<<-1<<std::endl; return 0;}

	// ll size= std::min(distT,distR);
	// ll ans=std::max(distT,distR);
	// for(int i=1;i<=size;++i)
	// {
	// 	if(trains[i]==roads[i])
	// 	{
	// 		std::cout<<ans+1<<std::endl;
	// 		return 0;
	// 	}
	// }
	return 0;
	
	
}