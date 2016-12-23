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


/*ll minO(ll a,ll b,ll c)
{

	ll val1=b+c;
	ll val2=a+2*b;
	ll val3=c+2*a;

	return std::min(val1,std::min(val2,val3));
}

ll minT(ll a,ll b,ll c)
{

	// ll val1=std::min(2*a,b);
	// ll val1=std::min(3*b,1e18);
	ll val2=std::min(2*c,3*b);
	ll val3=std::min(a+b+c,val2);
	ll val4=std::min(3*a+c,val3);

	return val4;
}

ll minTh(ll a,ll b,ll c)
{

	ll three=std::min(3*a,std::min(c,b+c));
	ll four=std::min(4*a,std::min(2*b,std::min(2*b+2*a,c+a)));

	ll val1=minT(a,b,c)+a;
	ll val2=minO(a,b,c)+std::min(2*a,b);
	ll val3 = three+four;

	return std::min(val1,std::min(val2,val3));
}*/
int main()
{
	ll n,a,b,c;
	std::cin>>n>>a>>b>>c;


	int num=4-(n%4);

	if(num==4)
	{
		std::cout<<0<<std::endl;
		return 0;
	}

	if(num==1)
	{

		std::cout<<std::min(a,std::min(b+c,3*c))<<std::endl;
		return 0;
	}

	if(num==2)
	{
		ll val1=std::min(2*a,b);
		std::cout<<std::min(val1,2*c)<<std::endl;
		return 0;
	}
	if(num==3)
	{
		ll val1=std::min(3*a,c);
		std::cout<<std::min(val1,a+b)<<std::endl;
		return 0;
	}

	return 0;
}