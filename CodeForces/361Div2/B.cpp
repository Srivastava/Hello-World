#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>


unsigned long path(const std::vector<std::vector<unsigned long> >& graph,const int& index)
{
	std::queue<unsigned long> v;

	unsigned long ans=0;
	
	v.push(1);

	// std::cout<<"HERE ------------------------- "<<index<<std::endl;
	while(!v.empty())
	{
		unsigned long val=v.front();
		if(val>graph[index][0]){break;}
		if(val==graph[index][0]){break;}

		// std::cout<<"HERE 1 "<<val<<std::endl;

		v.pop();

		unsigned long max=0;
		for(int i=0;i<graph[val].size();++i)
		{

			// std::cout<<"HERE 2 "<<max<<" " <<graph[val][i]<<std::endl;
			if(graph[val][i]-graph[val][0] > max)
			{
				max=graph[val][i];
				if(max>graph[index][0])
				{
					v.push(val+1);
				}
				else
				{

					v.push(max);
				}
			}
		}
		ans+=1;
		if(max==0){v.push(val+1);}
	}

	// std::cout<<"HERE END "<<ans<<std::endl;
	return ans;
}

int main()
{
	unsigned long n;
	std::cin>>n;

	std::vector<std::vector<unsigned long> > graph(n+1,std::vector<unsigned long> (1,0));

	unsigned long temp=n;

	for(unsigned long i=1;i<n+1;++i)
	{
		unsigned long val;
		std::cin>>val;

		graph[i][0]=i;
		graph[i].push_back(val);
	}

	std::vector<unsigned long> ans(n+1,0);
	for(int i=1;i<=n;++i)
	{
		ans[i]=path(graph,i);
	}


	std::copy(ans.begin()+1,ans.end(),std::ostream_iterator<unsigned long>(std::cout," "));
	std::cout<<std::endl;
	// for(int i=0;i<graph.size();++i)
	// {
	// 	for(int j=0;j<graph[i].size();++j)
	// 	{
	// 		std::cout<<graph[i][j]<<",";
	// 	}
	// 	std::cout<<std::endl;
	// }

	return 0;
}