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


int main()
{
	ll q;
	std::cin>>q;

	std::cout<<q<<std::endl;
	std::vector<std::pair<ll,ll> >graph[q+1];


	for(ll i=1;i<=q/2;++i)
	{
		// graph[i][0]=i;
		graph[i].push_back(std::make_pair(2*i,0));
		graph[i].push_back(std::make_pair(2*i+1,0));

		graph[2*i].push_back(std::make_pair(i,0));
		graph[2*i+1].push_back(std::make_pair(i,0));

		std::cout<<graph[i][1].first<<graph[i][1].second<<std::endl;
		std::cout<<graph[i][1].first<<graph[i][1].second<<std::endl;
	}

	// std::vector<vll> graph(q+1,vll(1,0));

	for(int i=1;i<=q;++i)
	{
		for(int j=0;j<graph[i].size();++j)
		{
			std::pair<ll,ll> val=graph[i][j];
			std::cout<<i<<" "<<val.first<<" "<<val.second<<",";
		}
		std::cout<<std::endl;
	}


	return 0;
}