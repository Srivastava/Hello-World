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


int main()
{
	int n,m;
	std::cin>>n>>m;

	vi a(n+1,0),sum(n+1,0);

	for(int i=1;i<=n;++i)
	{
		std::cin>>a[i];
		sum[i]=a[i]+sum[i-1];
	}

	vi hap(m,0);
	for(int i=0;i<m;++i)
	{
		int u,v;
		std::cin>>u>>v;
		--u;
		hap[i]=sum[v]-sum[u];
	}

	std::sort(hap.begin(),hap.end(),std::greater<int>());

	int ans=0;

	for(auto& i:hap)
	{
		if(i<0){break;}
		ans+=i;
	}

	std::cout<<ans<<std::endl;
	return 0;
}