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
typedef std::vector<vll> vvll;

bool solve(const vvll& graph,ll& t)
{
	std::vector<bool> visited(graph.size(),false);

	std::stack<ll> q;
	q.push(1);
	visited[1]=true;

	while(!q.empty())
	{
		ll temp=q.top();


		if(temp==t){return true;}

		q.pop();

		for(ll i=1;i<graph[temp].size();++i)
		{
			ll val=graph[temp][i];
			if(val==t){return true;}

			if(!visited[val])
			{
				visited[val]=true;
				q.push(val);
			}

		}
	}

	return false;
}

int main()
{

	ll n,t;
	std::cin>>n>>t;

	vll a(n,0);

	for(int i=1;i<n;++i)
	{
		std::cin>>a[i];
	}

	ll sum=1;
	while(sum<t)
	{

		sum=sum+a[sum];
	}

	if(sum==t){std::cout<<"YES"<<std::endl;}
	else{std::cout<<"NO"<<std::endl;}
	/*vvll graph(n+1,vll(1,0));

	for(int i=1;i<=n-1;++i )
	{
		ll val;
		std::cin>>val;

		graph[i][0]=i;
		graph[i+val][0]=i+val;
		graph[i].push_back(i+val);
	}

	// std::cout<<t<<std::endl;
	// for(int i=1;i<=n-1;++i)
	// {
	// 	for(int j=0;j<graph[i].size();++j)
	// 	{
	// 		std::cout<<graph[i][j]<<" ";
	// 	}
	// 	std::cout<<std::endl;
	// }


	if(solve(graph,t))
	{
		std::cout<<"YES"<<std::endl;
	}
	else
	{
		std::cout<<"NO"<<std::endl;
	}*/
	return 0;
}
