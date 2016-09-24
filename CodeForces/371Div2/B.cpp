#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <set>

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

	vll a(n,0);
	ll sum=0;

	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
		// sum+=a[i];
	}

	std::set<int> s(a.begin(),a.end());

	if(s.size()>=4){std::cout<<"NO"<<std::endl;return 0;}
	if(s.size()<=2){std::cout<<"YES"<<std::endl;return 0;}
	else
	{
		vll so(3,0);
		auto it=s.begin();
		so[0]=*it;
		++it;
		so[1]=*it;
		++it;
		so[2]=*it;
		std::sort(so.begin(),so.end());
		if(2*so[1]==so[2]+so[0])
		{
			std::cout<<"YES"<<std::endl;
		}
		else
		{
			std::cout<<"NO"<<std::endl;
		}


	}

	/*std::sort(a.begin(),a.end());
	ll mid=n/2;



	ll diff=-1;
	// if(a[mid]-a[0]!=0){diff=a[mid]-a[0];}
	// if(a[n-1]-a[mid]!=0)
	// {
	// 	if(diff!=a[n-1]-a[mid])
	// 	{
	// 		std::cout<<"NO"<<std::endl;
	// 	}
	// }
	for(ll i=mid;i>=0;--i)
	{
		ll val=a[mid]-a[i];
		if(val!=0)
		{
			if(diff==-1){diff=val;}
			else if(val!=diff){std::cout<<"NO"<<std::endl;return 0;}
		}
	}

	for(ll i=mid;i<n;++i)
	{
		ll val=a[i]-a[mid];
		if(val!=0)
		{
			if(diff==-1){diff=val;}
			else if(val!=diff){std::cout<<"NO"<<std::endl;return 0;}
		}
	}
	std::cout<<"YES"<<std::endl;*/

	return 0;
}