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

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

ll gcd(ll a,ll b)
{

	if(a==0){return b;}
	
	return gcd(b%a,a);

}

int main()
{
	// ll g=gcd(0,5);
	// std::cout<<g<<std::endl;
	// std::cout<<gcd(g,6)<<std::endl;
	ll n;
	std::cin>>n;

	vll a(n,0);

	ll max=0,g=0;
	bool even=true;
	for(ll i=0;i<n;++i)
	{
		std::cin>>a[i];
		if(a[i]>max)
		{
			max=a[i];
		}
		// if(a[i]%2!=0)
		// {
		// 	even=false;
		// }
		
		g=gcd(g,a[i]);	
		// std::cout<<g<<std::endl;	
	}
	// std::sort(a.begin())

	ll num=max/g-n;
	// std::cout<<g<<std::endl;
	// if(even)
	// {
	// 	num=max/2 - n;
	// }
	// else
	// {
	// 	num=max-n;
	// }

	if(num%2==0){std::cout<<"Bob"<<std::endl;}
	else
	{
		std::cout<<"Alice"<<std::endl;
	}

	return 0;
}