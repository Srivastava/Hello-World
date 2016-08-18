#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_map>

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
	ll n,a,b,c,d;
	std::cin>>n>>a>>b>>c>>d;

	std::unordered_map<ll,ll> map;

	ll x=0;
	for(ll i=1;i<=n;++i)
	{
		
		x = i+(c-b);

		if(x<=n && x !=0)
		{
			// std::cout<<x<<" for "<<i<<std::endl;
			map.insert({x,i});
		} 
	}
/*
	for(auto it=map.begin();it!=map.end();++it)
	{
		std::cout<<it->first<<" * "<<it->second<<std::endl;
	}*/
	x=0;
	ll ans=0;
	for (ll i = 1; i <=n; ++i)
	{
		
		x=i+(a-d);
		
		if(x<=0){continue;}
		
		auto it=map.find(x);
		if(it==map.end()){continue;}
		ll y = map[x];
		// std::cout<< x << " xyi "<<y<<" "<<i<<std::endl;
		ll v= 0;

		
		v=y-(a-d);
		
		it = map.find(i);
		if(it!=map.end())
		{
			// std::cout<<x<<" "<<y<<" "<<i << " u v  "<<v<<std::endl;
			if(it->second== v && v !=0)
			{
				++ans;
			}
		}
	}

	// std::cout<<n<<std::endl;
	std::cout<<ans*n<<std::endl;
	return 0;
}