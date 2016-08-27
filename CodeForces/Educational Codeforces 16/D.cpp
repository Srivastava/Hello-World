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

void ex_gcd(ll a, ll b, ll &x, ll &y )
{
	if(!b){
		x=1;y=0;
	}
	else{
		ex_gcd(b, a%b, y, x);
		y-=x*(a/b);
	}
}

int gcd(ll a,ll b)
{
	return a%b==0 ? b : gcd(b,a%b);
}
int main()
{
	ll a1,b1,a2,b2,l,r;
	std::cin>>a1>>b1>>a2>>b2>>l>>r;

	ll temp=std::ceil((double)(l-b1)/(double)a1);
	ll kl1=std::max(0LL,temp);
	temp=std::ceil((double)(l-b2)/(double)a2);
	ll kl2=std::max(0LL,temp);


	ll ku1=((r-b1)/a1);
	ll ku2=((r-b2)/a1);

	ll ans=0;
	// std::cout<<kl1<<" "<<ku1<<" ** "<<kl2<<" "<<ku2<<std::endl;
	ll g=std::abs(gcd(a1,-a2));
	std::cout<<g<<std::endl;
	std::cout<<b2-b1<<std::endl;
	if((b2-b1)%g!=0){std::cout<<0<<std::endl;return 0;}

	std::cout<<(r-l)/g<<std::endl;

	/*for(int k1=kl1;k1<=ku1;++k1)
	{
		for(int k2=kl2;k2<=ku2;++k2)
		{
			if(a1*k1-a2*k2==b2-b1){++ans;}
			// if(a1*k1-a2*k2>b2-b1){break;}
		}
	}

	std::cout<<ans<<std::endl;*/

	return 0;
}