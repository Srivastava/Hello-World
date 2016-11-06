#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <map>

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


std::map<pa,vpa> s;
int n;

void add(int a,int b,int c,int d)
{
	pa temp({a,b});
	pa temp1({c,d});

	s[temp].push_back(temp1);
}

int main()
{
	std::cin>>n;

	int maxv=0,maxvi=-1;

	vi a(3,0);
	for(int i=1;i<=n;++i)
	{
		std::cin>>a[0]>>a[1]>>a[2];
		std::sort(a.begin(),a.end());

		add(a[0],a[1],a[2],i);
		add(a[0],a[2],a[1],i);
		add(a[1],a[2],a[0],i);

		if(maxv<a[0]){maxv=a[0];maxvi=i;}
	}

	bool two=false;

	int ans1=-1,ans2=-1;
	for(auto& maps:s)
	{
		std::sort(maps.second.rbegin(),maps.second.rend());

		if(maps.second.size()<2){continue;}

		int vol=maps.first.first;

		if(vol>maps.first.second)
		{
			vol=maps.first.second;
		}
		if(vol>maps.second[0].first+maps.second[1].first)
		{
			vol=maps.second[0].first+maps.second[1].first;
		}

		if(vol>maxv)
		{
			two=true;
			ans1=maps.second[0].second;
			ans2=maps.second[1].second;
		}
	}

	if(two)
	{
		std::cout<<2<<"\n"<<ans1<<" "<<ans2<<std::endl;
	}
	else
	{
		std::cout<<1<<"\n"<<maxvi<<std::endl;
	}
	return 0;
}