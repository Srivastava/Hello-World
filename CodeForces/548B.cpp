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
typedef std::vector<vi> vvi;
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;


int main()
{
	int n,m,q;
	std::cin>>n>>m>>q;

	vvi matrix(n,vi(m,0));

	int gmax=0;
	vi sum(n,0);
	for(int i=0;i<n;++i)
	{
		int ans=0,max=0;
		for(int j=0;j<m;++j)
		{
			std::cin>>matrix[i][j];
			if(matrix[i][j])
			{
				++ans;
			}
			else
			{
				max=std::max(max,ans);
				ans=0;
			}
		}
		max=std::max(max,ans);
		sum[i]=max;
		// gmax=std::max(gmax,max);
	}

	// std::priority_queue<int,vi,std::greater<int> > pq;

	/*for(auto n:sum)
	{
		pq.push(n);
	}*/

	for(int i=0,qi,qj;i<q;++i)
	{
		std::cin>>qi>>qj;

		matrix[qi-1][qj-1]=1-matrix[qi-1][qj-1];
		
		int ans=0,max=0;
		for(int j=0;j<m;++j)
		{
			if(matrix[qi-1][j])
			{
				++ans;
			}
			else
			{
				max=std::max(max,ans);
				ans=0;
			}
		}

		max=std::max(max,ans);
		sum[qi-1]=max;
		ans=0;
		for(auto n:sum)
		{
			ans=std::max(ans,n);
		}
		// pq[qi-1]=max;
		// std::cout<<pq.top()<<std::endl;
		// gmax=std::max(gmax,max);
		std::cout<<ans<<std::endl;
	}

	return 0;
}