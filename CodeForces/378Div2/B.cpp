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

	
	int cnt=0,cnt1=0;

	ll suml=0,sumr=0;

	vpa values;

	values.reserve(n);
	for(int i=0;i<n;++i)
	{
		ll l,r;
		std::cin>>l>>r;

		values.push_back({l,r});

		suml+=l;
		sumr+=r;
		
	}
	if(n==1){std::cout<<0<<std::endl;return 0;}
	// if(val1==-1||val==-1){std::cout<<0<<std::endl;return 0;}

	int ans=-1,ans1=-1;
	int val=-1;
	int val1=-1;
	ll diff=std::abs(suml-sumr);

	for(int i=0;i<n;++i)
	{
		ll l=values[i].first;
		ll r=values[i].second;

		ll templ=suml+r-l;
		ll tempr=sumr+l-r;

		ll res=std::abs(templ-tempr);
		if(res>diff)
		{
			diff=res;
			ans=i;
		}

	}
	std::cout<<ans+1<<std::endl;
	return 0;
}