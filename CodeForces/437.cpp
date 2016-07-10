#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>


long long leastEn(std::vector<std::vector<long long> >& graph, const std::vector<long long>& cost)
{
	std::vector<long long> color(cost.size()+1,0);
	std::vector<std::pair<long long,long long> > costPair;

	for(long long i=0;i<cost.size();++i)
	{
		costPair.push_back(std::make_pair(i+1,cost[i]));
	}

	std::sort(costPair.begin(), costPair.end(), [](const std::pair<long long,long long> &left, const std::pair<long long,long long> &right) {
    return left.second < right.second;
	});

	for(long long i=0;i<costPair.size();++i)
	{
		// std::cout<<costPair[i].first<<" "<<costPair[i].second<<",";
	}
	// std::cout<<std::endl;
	long long sum=0;
	for(long long i=0;i<costPair.size();++i)
	{
		if(color[costPair[i].first]==0)
		{
			color[costPair[i].first]=1;
			for(long long j=0;j<graph[costPair[i].first].size();++j)
			{
				long long index=graph[costPair[i].first][j];
				// color[index]=1;
				// std::cout<<index<<" ------------ "<<costPair[i].first<<std::endl;
				if(color[index]==0)
				{
					for(long long k=1;k<graph[index].size();++k)
					{
						// std::cout<<graph[index][k]<<" in loo[ loop"<<std::endl;
						if(graph[index][k]==costPair[i].first)
						{
							graph[index].erase(graph[index].begin()+k);
							break;
						}
					}
					// std::cout<<index << " "<<cost[costPair[i].first-1]<<" in loop "<<std::endl;
					sum+=cost[costPair[i].first-1];

				}
			}

		}
	}
	return sum;
}

int main()
{
	long long n,m;
	std::cin>>n>>m;

	long long tempN=n,tempM=m;
	std::vector<long long> cost;
	cost.reserve(n);

	std::vector<std::vector<long long> > graph(n+1,std::vector<long long> (1,0));

	while(n--)
	{
		long long val;
		std::cin>>val;

		cost.push_back(val);
	}

	while(m--)
	{
		long long u,v;
		std::cin>>u>>v;

		graph[u][0]=u;
		graph[v][0]=v;

		graph[u].push_back(v);
		graph[v].push_back(u);

	}

	// for(long long i=1;i<graph.size();++i)
	// {
	// 	for(long long j=0;j<graph[i].size();++j)
	// 	{
	// 		std::cout<<graph[i][j]<<",";
	// 	}
	// 	std::cout<<std::endl;
	// }
	if(tempM==0){std::cout<<0<<std::endl;}
	else
	{

		std::cout<<leastEn(graph,cost)<<std::endl;
	}

	// for(long long i=1;i<graph.size();++i)
	// {
	// 	for(long long j=0;j<graph[i].size();++j)
	// 	{
	// 		std::cout<<graph[i][j]<<",";
	// 	}
	// 	std::cout<<std::endl;
	// }
	return 0;
}