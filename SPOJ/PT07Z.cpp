#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>
// #include <unordered_map>
// #include <map>
#include <list>

/***************************************************************
/********************                 *******************************************
/*						PT07Z                                                 */
/********************                 *******************************************
/***************************************************************/
int total=0;
std::vector<bool> visited(100000,false);

int dfs(const std::vector<std::vector<int> >& graph,const int& index)
{
	// std::vector<bool> visited(graph.size(),false);
	
	int m1=-1,m2=-1;

	visited[index]=true;
	
	for(int i=1;i<graph[index].size();++i)
	{
		if(!visited[graph[index][i]])
		{
			int len=dfs(graph,graph[index][i]);

			if(len>=m1)
			{
				m2=m1;
				m1=len;
				
			}
			else if(len>m2)
			{
				m2=len;
			}
		}
	}


	total=std::max(total,m1+m2+2);
	// if(graph[index].size()==1){return 0;}
	return m1+1;
	
}

int main()
{
	int v,e;
	std::cin>>v;
	e=v-1;

	std::vector<std::vector<int> > graph(v+1,std::vector<int> (1,0));

	int i=0;
	while(i<e)
	{
		int u,v;
		std::cin>>u>>v;

		graph[u][0]=u;
		graph[v][0]=v;
		graph[u].push_back(v);
		// graph[v].push_back(u);
		// graph[v]
		++i;
	}	

	// for(int i=0;i<graph.size();++i)
	// {
	// 	for(int j=0;j<graph[i].size();++j)
	// 	{
	// 		std::cout<<graph[i][j]<<",";
	// 	}
	// 	std::cout<<std::endl;
	// }
	dfs(graph,1);
	// std::cout<<dfs(graph,1)<<std::endl;
	std::cout<<total<<std::endl;

	// if(dfs(graph,1) && e+1==v)
	// {
	// 	std::cout<<"YES"<<std::endl;
	// }

	// else
	// {
	// 	std::cout<<"NO"<<std::endl;
	// }

	return 0;
}