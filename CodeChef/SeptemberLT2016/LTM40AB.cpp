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
	int t;
	std::cin>>t;

	while(t--)
	{
		ll a,b,c,d;
		std::cin>>a>>b>>c>>d;

		int r;
		if(b<c){r=0;}
		else{r=b-c+1;}
		// int r=std::min(b,c);
		// if(r==c){b=r-1;}

		ll x=(b-a+1);
		ll y = (d-c+1);

		std::cout<<x<<" "<<y<<" "<<r<<std::endl;

		ll n=r*(r-1);
		// ll ans=((n-1)*n)/2;

		std::cout<<r<<" "<<r-1<<" "<<(x*y-r*((r-1)/2))/2<<std::endl;
		std::cout<<n<<std::endl;
	}
	return 0;
}