#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <queue>

// #include <map>

/***************************************************************
/********************                 *******************************************
/*						C                                                 */
/********************                 *******************************************
/***************************************************************/


// bool biPartite(const std::vector<std::vector<unsigned long> >& graph,unsigned long src)
// {
// 	std::vector<int> color(graph.size(),-1);

// 	color[src]=1;

// 	std::queue<int> q;
// 	q.push(src);

// 	while(!q.empty())
// 	{
// 		int u=q.front();
// 		q.pop();

// 		for(int i=1;i<graph[u].size();++i)
// 		{
// 			if(color[graph[u][i]]==-1)
// 			{
// 				color[graph[u][i]]=1-color[u];
// 				q.push(graph[u][i]);
// 			}

// 			else if(color[u]==color[graph[u][i]])
// 			{
// 				return false;
// 			}
// 		}
// 	}

// 	// std::copy(color.begin(),color.end(),std::ostream_iterator<int>(std::cout,","));
// 	// std::cout<<std::endl;
// 	return true;
// }

bool biPartite(const std::vector<std::vector<unsigned long> >& graph,unsigned long src,std::vector<unsigned long>& A,std::vector<unsigned long>& B)
{
	std::vector<int> color(graph.size(),-1);

	color[src]=1;

	std::queue<int> q;
	q.push(src);

	while(!q.empty())
	{
		int u=q.front();
		q.pop();

		for(int i=1;i<graph[u].size();++i)
		{
			if(color[graph[u][i]]==-1)
			{
				color[graph[u][i]]=1-color[u];
				q.push(graph[u][i]);
			}

			else if(color[u]==color[graph[u][i]])
			{
				return false;
			}
		}
	}

	for(unsigned long i=0;i<color.size();++i)
	{
		if(color[i]==1){A.push_back(i);}
		else if(color[i]==0){B.push_back(i);}
	}
	// std::copy(color.begin(),color.end(),std::ostream_iterator<int>(std::cout,","));
	// std::cout<<std::endl;
	return true;
}
int main()
{
	unsigned long n,m;
	std::cin>>n>>m;

	unsigned long temp=m;

	std::vector<std::vector<unsigned long> > graph(n+1,std::vector<unsigned long> (1,0));
	
	// std::cout<<graph.size()<<std::endl;

	while(temp--)
	{
		unsigned long u,v;
		std::cin>>u>>v;

		graph[u][0]=u;
		graph[v][0]=v;

		graph[u].push_back(v);
		graph[v].push_back(u);

	}

	// biPartite(graph,graph[1][0]) ? std::cout<<"YES" : std::cout<<"NO";

	std::vector<unsigned long> A;
	std::vector<unsigned long> B;

	bool canSplit=	biPartite(graph,graph[1][0],A,B);

	if(canSplit)
	{
		std::cout<<A.size()<<std::endl;

		for(int i=0;i<A.size();++i)
		{
			std::cout<<A[i]<<" ";
		}
		std::cout<<std::endl;

		std::cout<<B.size()<<std::endl;

		for(int i=0;i<B.size();++i)
		{
			std::cout<<B[i]<<" ";
		}
		std::cout<<std::endl;
	}
	else
	{
		std::cout<<"-1"<<std::endl;
	}

	// for(int i=0;i<n+1;++i)
	// {
	// 	for(int j=0;j<graph[i].size();++j)
	// 	{
	// 		std::cout<<graph[i][j]<<",";
	// 	}
	// 	std::cout<<std::endl;
	// }

	return 0;
}

// int main()
// {
// 	unsigned long n,m;
// 	std::cin>>n>>m;

// 	unsigned long temp=m;

// 	std::vector<std::vector<unsigned long> > graph(n+1,std::vector<unsigned long> (1,0));
	
// 	// std::cout<<graph.size()<<std::endl;

// 	while(temp--)
// 	{
// 		unsigned long u,v;
// 		std::cin>>u>>v;

// 		graph[u][0]=u;
// 		graph[v][0]=v;

// 		graph[u].push_back(v);
// 		graph[v].push_back(u);

// 	}

// 	// std::vector<int> A(n+1,0);
// 	// std::vector<int> B(n+1,0);

// 	// for(int i=1;i<n+1;i+=2)
// 	// {
// 	// 	int j=i+1;


// 	// 	// std::cout<<i<<" "<<graph[i][0]<<std::endl;
// 	// 	A[graph[i][0]]=1;
// 	// 	for(int k=1;k<graph[i].size();++k)
// 	// 	{
// 	// 		int val=graph[i][k];
// 	// 		// std::cout<<i<<" "<<val<<" * "<<std::endl;
// 	// 		A[val]=-1;
// 	// 	}

// 	// 	if(j<n+1)
// 	// 	{
// 	// 		B[j]=1;
// 	// 		for(int k=1;k<graph[j].size();++k)
// 	// 		{
// 	// 			int val=graph[j][k];
// 	// 			// std::cout<<i<<" "<<
// 	// 			B[val]=-1;
// 	// 		}
// 	// 	}

// 	// }
// 	// for(int i=1;i<n+1;++i)
// 	// {
// 	// 	int first=graph[i][0];

// 	// 	if(A[first]==0){A[first]=1;}

// 	// 	std::cout<<first<<std::endl;

// 	// 	for(int j=1;j< graph[i].size();++j)
// 	// 	{
// 	// 		A[j]=-1;
// 	// 		int val=graph[i][1];
// 	// 		std::cout<<val<<" *"<<std::endl;
// 	// 		if(B[val]==0)
// 	// 		{
// 	// 			B[val]=1;
// 	// 			B[first]=-1;

// 	// 			for(int k=0;k<graph[val].size();++k)
// 	// 			{
// 	// 				B[val]=-1;
// 	// 			}
// 	// 		}

// 	// 	}
// 	// }

// 	// std::copy(A.begin(),A.end(),std::ostream_iterator<int>(std::cout,","));
// 	// std::cout<<std::endl;

// 	// std::copy(B.begin(),B.end(),std::ostream_iterator<int>(std::cout,","));
// 	// std::cout<<std::endl;

// 	bool correct=true;
// 	int countA=0,countB=0;

// 	for(int i=1;i<n+1;++i)
// 	{
// 		if(A[i]==1){if(B[i]!=0){++countA;}}
// 		if(B[i]==1){if(A[i]!=0){++countB;}}

// 		if(A[i]+B[i]!=0)
// 		{
// 			if(A[i]==0 || B[i]==0)
// 			{

// 			}
// 			else
// 			{
// 				correct=false;
// 			}
// 		}
// 	}

// 	if(correct==false)
// 	{
// 		std::cout<<"-1"<<std::endl;
// 	}

// 	else
// 	{
// 		std::cout<<countA<<std::endl;

// 		for(int i=1;i<n+1;++i)
// 		{
// 			if(A[i]==1){if(B[i]!=0){std::cout<<i<<" ";}}
// 		}
// 		std::cout<<std::endl;

// 		std::cout<<countB<<std::endl;
// 		for(int i=1;i<n+1;++i)
// 		{
// 			if(B[i]==1){if(A[i]!=0){std::cout<<i<<" ";}}
// 		}
// 	}

// 	// for(int i=0;i<n+1;++i)
// 	// {
// 	// 	for(int j=0;j<graph[i].size();++j)
// 	// 	{
// 	// 		std::cout<<graph[i][j]<<",";
// 	// 	}
// 	// 	std::cout<<std::endl;
// 	// }

// 	return 0;
// }