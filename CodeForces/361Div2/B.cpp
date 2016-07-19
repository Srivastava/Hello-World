#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

// typedef std::pair<int,int> edge;
std::vector<int> g[200005];
int dist[200005], a[200005];
bool visited[200005]={0};
// unsigned long path(const std::vector<std::vector<unsigned long> >& graph,const int& index)
// {
// 	std::queue<unsigned long> v;

// 	unsigned long ans=0;
	
// 	v.push(1);

// 	// std::cout<<"HERE ------------------------- "<<index<<std::endl;
// 	while(!v.empty())
// 	{
// 		unsigned long val=v.front();
// 		if(val>graph[index][0]){break;}
// 		if(val==graph[index][0]){break;}

// 		// std::cout<<"HERE 1 "<<val<<std::endl;

// 		v.pop();

// 		unsigned long max=0;
// 		for(int i=0;i<graph[val].size();++i)
// 		{

// 			// std::cout<<"HERE 2 "<<max<<" " <<graph[val][i]<<std::endl;
// 			if(graph[val][i]-graph[val][0] > max)
// 			{
// 				max=graph[val][i];
// 				if(max>graph[index][0])
// 				{
// 					v.push(val+1);
// 				}
// 				else
// 				{

// 					v.push(max);
// 				}
// 			}
// 		}
// 		ans+=1;
// 		if(max==0){v.push(val+1);}
// 	}

// 	// std::cout<<"HERE END "<<ans<<std::endl;
// 	return ans;
// }

// int main()
// {
// 	unsigned long n;
// 	std::cin>>n;

// 	std::vector<std::vector<unsigned long> > graph(n+1,std::vector<unsigned long> (1,0));

// 	unsigned long temp=n;

// 	for(unsigned long i=1;i<n+1;++i)
// 	{
// 		unsigned long val;
// 		std::cin>>val;

// 		graph[i][0]=i;
// 		graph[i].push_back(val);
// 	}

// 	std::vector<unsigned long> ans(n+1,0);
// 	for(int i=1;i<=n;++i)
// 	{
// 		ans[i]=path(graph,i);
// 	}


// 	std::copy(ans.begin()+1,ans.end(),std::ostream_iterator<unsigned long>(std::cout," "));
// 	std::cout<<std::endl;
// 	// for(int i=0;i<graph.size();++i)
// 	// {
// 	// 	for(int j=0;j<graph[i].size();++j)
// 	// 	{
// 	// 		std::cout<<graph[i][j]<<",";
// 	// 	}
// 	// 	std::cout<<std::endl;
// 	// }

// 	return 0;
// }

void bfs(const int& start)
{
	dist[start]=0;
	visited[start]=true;
	std::queue<int> q;

	q.push(start);

	while(!q.empty())
	{
		int temp=q.front();
		q.pop();

		for(std::vector<int>::iterator it=g[temp].begin();it!=g[temp].end();++it)
		{
			if(visited[*it]!=1)
			{
				dist[*it]=dist[temp]+1;
				visited[*it]=true;
				q.push(*it);
			}
		}
		// visited[temp]=true;
	}
}

int main()
{
	int n;
	std::cin>>n;

	for(int i=1;i<n;++i)
	{
		g[i].push_back(i+1);
		g[i+1].push_back(i);
	}

	for(int i=1;i<=n;++i)
	{
		std::cin>>a[i];
		g[i].push_back(a[i]);
	}

	bfs(1);

	for(int i=1;i<=n;++i)
	{
		std::cout<<dist[i]<<" ";
	}
	return 0;
}

