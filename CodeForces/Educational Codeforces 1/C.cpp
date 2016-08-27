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
const long double PI = acos(-1.0) * 2;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

bool compare(std::pair<double,int>& p1, std::pair<double,int>& p2)
{
	return p1.first <p2.first; 
}

int main()
{
	ll n;
	std::cin>>n;

	// vpa p;
	std::vector<std::pair<long double,int> > p;
	p.reserve(n);

	for(ll i =0;i<n;++i)
	{
		double u,v;
		std::cin>>u>>v;

		// double m = v/u;

		// std::cout<<dist<<" dist"<<" "<<u<<" "<<v<<" "<<acos(u/dist)<<std::endl;
		long double ans = (atan2(v,u));
		if(ans<0){ans+=PI;}
		// if(u<0 && v>=0)
		// {
		// 	ans+=180.0;
		// }
		
		// if(u<0 && v<0)
		// {
		// 	ans+=180.0;
		// }
		std::cout<<ans<<" "<<u<<" "<<v<<std::endl;
/*
		if(u==0 && v<0)
		{
			ans=270.0;
		}
		if(u>0&& v<0)
		{
			ans+=360.0;
		}*/

		// if(ans<0){ans+=180.0;}
		// if(dist==0){ans=0;}
		p.push_back(std::make_pair(ans,i));
	}
	// p.push_back(std::make_pair(p[0].first+PI,p[0].second));
	// p.push_back(p[0]);
	std::sort(p.begin(),p.end());
	/*for(int i=0;i<n;++i)
	{
		std::cout<<p[i].first<<" "<<p[i].second<<std::endl;
	}*/

	ll a=0,b=0; double min=1e15;
	for(ll i=0;i<n;++i)
	{
		long double one = p[i].first;
		long double two = p[(i+1)%n].first;

		std::cout<<one<<" "<<two<<std::endl;
		long double ans=one-two;
		if(ans<0){ans+=PI;}
		if(min>ans)
		{
			min=ans;
			a=p[i].second+1;b=p[(i+1)%n].second+1;
		}

	}	

	std::cout<<a<<" "<<b<<std::endl;

	return 0;
}