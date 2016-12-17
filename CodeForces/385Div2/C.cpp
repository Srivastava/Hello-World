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

int find(int u,vi& s)
{
	return s[u]==u?u:s[u]=find(s[u]); 
}

void join(int u,int v)
{
	s[find(u)]=find(v);
}

int main()
{
	int n,m,k;
	std::cin>>n>>m>>k;

	vi gov(k,0);
	for(int i=0;i<k;++i)
	{
		std::cin>>gov[i];
	}


	vi s(n+1,0);

	int ans=0;
	for(int i=0;i<m;++i)
	{
		int u,v;
		std::cin>>u>>v;
		if(find(u)!=find(v))
		{
			join(u,v);
		}
		else
		{
			--ans;
		}
	}

	std::unordered_map<int,int> map;

	for(auto& i:s)
	{
		map[i]++;
	}

	
	return 0;
}