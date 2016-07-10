#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

int main()
{
	  int n,m;
	  std::cin>>n>>m;

	  // std::vector<std::vector<int> > list;
	  // list.reserve(n);

	  std::vector<std::vector<long long> > graph(m+1,std::vector<long long> (1,0));
	  bool noOne=true;
	  int numZ=0;

	  for(int i=0;i<n;++i)
	  {
	  	int val;
	  	std::cin>>val;
	  	if(val>0){noOne=false;}
	  	else{++numZ;}
	  	// std::vector<int> temp;
	  	// temp.reserve(val);

	  	while(val--)
	  	{
	  		int lang;
	  		std::cin>>lang;
	  		graph[lang][0]=lang;
	  		graph[lang].push_back(i+1);
	  		// temp.push_back(lang);
	  	}
	  	// list.push_back(temp);
	  }


		// for(long long i=1;i<graph.size();++i)
		// {
		// 	for(long long j=0;j<graph[i].size();++j)
		// 	{
		// 		std::cout<<graph[i][j]<<",";
		// 	}
		// 	std::cout<<std::endl;
		// }

	  std::vector<std::vector<long long> > list(n+1,std::vector<long long> (1,0));


	 //  int sum=0;
	 //  for(long long i=0;i<graph.size();++i)
		// {
		// 	for(long long j=1;j<graph[i].size();++j)
		// 	{
		// 		int val=graph[i][j];
		// 		list[val].push_back(graph[i].size()-2);
		// 		// std::cout<<val<<" "<<i<<" "<<graph[i].size()-2<<std::endl;
		// 		if(j==1)
		// 		{

		// 			sum+=graph[i].size()-2;
		// 		}
		// 	}
		// }
		// std::cout<<sum<<std::endl;

	   // int sum=0;
	  for(long long i=0;i<graph.size();++i)
		{
			for(long long j=1;j<graph[i].size()-1;++j)
			{

				int val=graph[i][j];
				int val1=graph[i][j+1];
				list[val][0]=val;
				list[val1][0]=val1;
				list[val].push_back(val1);
				list[val1].push_back(val);
				// std::cout<<val<<" "<<i<<" "<<graph[i].size()-2<<std::endl;
				// if(j==1)
				// {

				// 	sum+=graph[i].size()-2;
				// }
			}
		}
		// std::cout<<sum<<std::endl;

		// std::cout<<"---------------------------------"<<std::endl;

		for(long long i=1;i<list.size();++i)
		{
			list[i][0]=i;
			// for(long long j=0;j<list[i].size();++j)
			// {
			// 	std::cout<<list[i][j]<<",";
			// }
			// std::cout<<std::endl;
		}

		// if(sum==0)
		// {
		// 	if(noOne){std::cout<<n<<std::endl;}
		// 	else
		// 	{
		// 		std::cout<<n-1-sum<<std::endl;
		// 	}
		// }

		// else
		// {
		// 	if(sum>n){if(numZ>0){std::cout<<numZ<<std::endl;}else{std::cout<<n-n<<std::endl;}}

		// 	else
		// 	std::cout<<n-1-sum<<std::endl;
		// }

		std::vector<int> visited(n+1,-1);
		int components=0;

		std::queue<int> q;
		// int summing=0;
		for(int i=1;i<list.size();++i)
		{
			int index=list[i][0];
			if(visited[index]!=1)
			{
				++components;
				q.push(index);
				visited[index]=1;


				while(!q.empty())
				{
					int top=q.front();
					q.pop();

					// std::cout<<top<<",*,";
					for(int j=1;j<list[top].size();++j)
					{
						
						if(visited[list[top][j]]!=1)
						{
							visited[list[top][j]]=1;
							q.push(list[top][j]);
							// ++summing;
						}
					}
				}
				// std::cout<<std::endl;
			}
			// else
			// {
			// 	++components;
			// }
			// std::cout<<components<<" nlah"<<std::endl;
			
		}

		// std::cout<<n-1-summing<<std::endl;
		if(noOne){std::cout<<n<<std::endl;}
		else{

		std::cout<<components-1<<std::endl;
		}

  return 0;
}