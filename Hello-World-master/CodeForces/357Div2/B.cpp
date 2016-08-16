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

int main()
{
	ll n;
	std::cin>>n;

	// std::cout<<n<<std::endl;
	ll m=n;

	ll a =1234567,b=123456,c=1234;

	ll p=n/a,q=n/b,r=n/c;

	bool perf=false;

	// std::cout<<p<<" "<<q<<" "<<r<<std::endl;
	// for(ll i =0;i<=p;++i)
	// {
	// 	for(ll j=(m-i*a)/b;j<=q;++j)
	// 	{
	// 		if(i*a+j*b>m){break;}
	// 		for( ll k=(m-i*a-j*b)/c;k<=r;++k)
	// 		{
	// 			if(i*a+j*b+c*k>m){break;}

	// 			// std::cout<<i*a+j*b+c*k<<std::endl;
	// 			if(i*a+j*b+c*k==m)
	// 			{
	// 				perf=true;
	// 				break;
	// 			}
	// 		}
	// 	}
	// }

	for(ll i=0;i<=n;i+=a)
	{
		for(ll j=0;j<=n-i;j+=b)
		{
			if((n-i-j)%1234==0)
			{
				std::cout<<"YES"<<std::endl;
				return 0;
			}
		}
	}

	std::cout<<"NO"<<std::endl;
	// while(n>=c)
	// {
	// 	n-=c;
	// 	++r;
	// }
	
	// while(n>=b)
	// {
	// 	n-=b;
	// 	++q;
	// }

	// while(n>=a)
	// {
	// 	n-=a;
	// 	++p;
	// }

	// std::cout<<p*a+q*b+r*c<<" "<<p<<" "<<q<<" "<<r<<std::endl;
	// if(n==0 && p*a+q*b+r*c==m)
	// if(perf)
	// {
	// 	std::cout<<"YES"<<std::endl;
	// }

	// else
	// {
	// 	std::cout<<"NO"<<std::endl;
	// }

	return 0;
}