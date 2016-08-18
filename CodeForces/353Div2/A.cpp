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
	ll a,b,c;
	std::cin>>a>>b>>c;

	ll n = b-a;

	if(c==0)
	{
		if(b==a){std::cout<<"YES"<<std::endl;}
		else
		{
			std::cout<<"NO"<<std::endl;
		}
	}

	else if(n%c==0 && c!=0)
	{
		ll d =n/c+1; 
		if(d>0)
		{
			std::cout<<"YES"<<std::endl;
		}
		else
		{
			std::cout<<"NO"<<std::endl;
		}
	}

	else
	{
		std::cout<<"NO"<<std::endl;
	}
	return 0;
}