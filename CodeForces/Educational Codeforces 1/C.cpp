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
#define PI 3.14159265

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

bool complare(std::pair<double,int>& p1, std::pair<double,int>& p2)
{
	return p1.first <p2.first; 
}

int main()
{
	ll n;
	std::cin>>n;

	// vpa p;
	std::vector<std::pair<double,int> > p;
	p.reserve(n);

	for(ll i =0;i<n;++i)
	{
		double u,v;
		std::cin>>u>>v;

		double m = v/u;

		// std::cout<<dist<<" dist"<<" "<<u<<" "<<v<<" "<<acos(u/dist)<<std::endl;
		double ans = atan(m)*180.0/PI;
		
		if(u<0 && v==0)
		{
			ans=180.0;
		}
/*
		if(u==0 && v<0)
		{
			ans=270.0;
		}
		if(u<0 && v<0)
		{
			ans+=180.0;
		}
		if(u>0&& v<0)
		{
			ans+=360.0;
		}*/

		// if(ans<0){ans+=180.0;}
		// if(dist==0){ans=0;}
		p.push_back(std::make_pair(ans,i));
	}

	std::sort(p.begin(),p.end(),complare);
	/*for(int i=0;i<n;++i)
	{
		std::cout<<p[i].first<<" "<<p[i].second<<std::endl;
	}*/

	ll a=0,b=0; double min=1e15;
	for(ll i=0;i<n-1;++i)
	{
		double one = p[i].first;
		double two = p[i+1].first;

		if(min>std::abs(one-two))
		{
			min=std::abs(one-two);
			a=p[i].second+1;b=p[i+1].second+1;
		}

	}	

	std::cout<<a<<" "<<b<<std::endl;

	return 0;
}