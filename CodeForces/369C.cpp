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
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

vll g[100005];
// int t[100005];
int w[100005],d[100005];

int n;

void calc(int v,int prev)
{
	d[v]=w[v];

	for(int i=0;i<g[v].size();++i)
	{
		int j=g[v][i];

		if(j==prev)
			continue;

		calc(j,v);
		d[v]+=d[j];
	}
}

void solve()
{
	d[0]=0;
	calc(1,0);

	vi ans;
	for(int i=1;i<=n;++i)
	{
		if(w[i] && d[i]==1)
		{
			ans.push_back(i);
		}
	}

	std::cout<<ans.size()<<std::endl;

	for(int i=0;i<ans.size();++i)
	{
		std::cout<<ans[i]<<" ";
	}
}

int main()
{
	std::cin>>n;

	for(int i=1;i<n;++i)
	{
		int u,v,t;
		std::cin>>u>>v>>t;

		g[u].push_back(v);
		g[v].push_back(u);	
		
		if(t==2)
		{
			w[u]=1;
			w[v]=1;
		}
	}

	solve();


	return 0;
}