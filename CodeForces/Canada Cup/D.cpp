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
	int n;
	std::cin>>n;

	vpa a;
	a.reserve(n);

	ll lv,lw;
	for(int i=0;i<n;++i)
	{
		ll t,w;
		std::cin>>t>>w;
		// if(i>0)	
		a.push_back({t,w});
		if(i==0)
		{
			lv=t;
			lw=w;
		}
	}

	int globalMin=1e8;
	while(1)
	{
		int minI=-1;
		std::sort(a.rbegin(),a.rend());

		std::priority_queue<pa,vpa> pq;

		// std::cout<<"--------------"<<std::endl;

		for(int i=0;i<a.size();++i)
		{
			if(a[i].first==lv && a[i].second==lw)
			{
				minI=i;
				break;
			}
			// std::cout<<a[i].first<<" "<<a[i].second<<std::endl;
			pq.push(a[i]);
		}

		
		// std::cout<<a[minI].first<<" ** "<<a[minI].second<<std::endl;
		ll min=1e18;
		int cnt=0,index=-1;
		while(!pq.empty())
		{
			pa top=pq.top();

			pq.pop();

			if(min>top.second-top.first)
			{
				min=top.second-top.first;
				index=cnt;
			}
			++cnt;

		}
		// std::cout<<min<<std::endl;
		if(index==-1 || min+1>a[minI].first)
		{
			if(minI>globalMin)
			{
				std::cout<<globalMin+1<<std::endl;
				return 0;
			}
			std::cout<<minI+1<<std::endl;
			return 0;
		}
		else
		{
			a[minI].first=a[minI].first-(min+1);
			lv=lv-(min+1);
			a.erase(a.begin()+index);
			
			// std::cout<<a[minI].first<<" ** "<<a[minI].second<<std::endl;
		}
		globalMin=std::min(globalMin,minI);
		// break;
		
	}

	
	
	return 0;
}