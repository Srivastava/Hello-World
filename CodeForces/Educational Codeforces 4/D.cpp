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
typedef std::pair<int,int> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;


int main()
{
	std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

	int n,k;
	// std::cin>>n>>k;

	scanf("%d%d",&n,&k);

	vpa p;
	p.reserve(n);
	for(int i=0;i<n;++i)
	{
		int u,v;
		// std::cin>>u>>v;
		scanf("%d%d",&u,&v);
		p.push_back(std::make_pair(u,-1));
		p.push_back(std::make_pair(v,1));
	}

	std::sort(p.begin(),p.end());

	int count=0;

	int st=-1,end=-1;

	vpa ans;
	ans.reserve(n);
	for(int i=0;i<p.size();++i)
	{
		count-=p[i].second;

		if(count==k && p[i].second==-1)
		{
			st=p[i].first;
		}
		if(count == k-1 && p[i].second==1)
		{
			ans.push_back(std::make_pair(st,p[i].first));
		}
	}

	printf("%d\n",ans.size());
	// std::cout<<ans.size()<<std::endl;
	for(int i=0;i<ans.size();++i)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
		// std::cout<<ans[i].first<<" "<<ans[i].second<<std::endl;
	}
	return 0;
}