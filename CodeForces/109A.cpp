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


// ll solve(const ll& n)
// {
// 	if(n==0){return 0;}
// 	ll f=1e15,s=1e15;

// 	if(n-4>=0)
// 		f=4+10*solve(n-4);
	
// 	if(n-7>=0)
// 		s=7+10*solve(n-7);

// 	return std::min(f,s);
// }


int main()
{

	ll n;
	std::cin>>n;

	if((n<7 && n!=4) || (n<10 && (n!=4 && n!=7 && n!=8)) || n==10 || n==13 || n==17)
	{
		std::cout<<-1;
		return 0;
	}

	else
	{
		while(n%7!=0)
		{
			std::cout<<4;
			n-=4;
		}

		while(n > 0)
		{
			std::cout<<7;
			n-=7;
		}
	}
	// ll ans=solve(n);

	// if(ans>=1e15){ans=-1;}
	// std::cout<<ans<<std::endl;
	return 0;
}