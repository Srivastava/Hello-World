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
typedef std::pair<ll,ll> pvll;


ll answer(const std::vector<std::vector<std::pair<ll,ll> > >& tree,const vll& vertexV)
{
	std::vector<bool> visited(tree.size()+1,false);

	std::queue<std::pair<ll,ll> > q;
	q.push(std::make_pair(1LL,0LL));
	visited[1]=true;

	ll size=0;

	ll pathCost=0;

	while(!q.empty())
	{
		std::pair<ll,ll> top = q.front();
		q.pop();
		visited[top.first]=true;
		
		// std::cout<<top.first<<" "<<top.second<<" "<<vertexV[top.first]<<std::endl;
		// std::cout<<pathCost<<" "<<size<<std::endl;
		pathCost=std::max(pathCost+top.second,0LL);
		if(pathCost > vertexV[top.first])
		{
			pathCost==0 ? pathCost=0 : pathCost-=top.second;
			// pathCost-=top.second;
			continue;

		}	
		++size;
	
		for(ll i =0;i<tree[top.first].size();++i)
		{
			std::pair<ll,ll> value=tree[top.first][i];
			ll edge=value.first;
			ll cost=value.second;
			if(visited[value.first]==false){
				q.push(value);
			}
		}


	}

	return size;
}

int main()
{
	ll n;
	std::cin>>n;
	vll vertexV(n+1,0);

	for(ll i=1;i<n+1;++i)
	{
		std::cin>>vertexV[i];
	}

	std::vector<std::vector< std::pair<ll,ll> > > tree(n+1,std::vector<std::pair<ll,ll> >(1,std::make_pair(0LL,0ll)));

	// std::cout<<"Here "<<std::endl;
	// /tree.reserve(n-1);

	ll place=0;

	// tree.push_back(std::make_pair(0LL,std::make_pair(0LL,0LL)));
	for(ll i=1;i<=n-1;++i)
	{
		ll val,val1;
		std::cin>>val>>val1;
		tree[val].push_back(std::make_pair(i+1,val1));

		// /if(val==1 && place==0){place=i;}
		// edges.push_back()
	}
	// std::cout<<"Here 1"<<std::endl;

	ll ans=n+1-answer(tree,vertexV);
	if(ans<0){ans=0;}
	std::cout<<ans<<std::endl;
	return 0;
}