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

// const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;


ull val(const ull& l )
{
	ull ans =0;

	for(ull i=2;i * i*i <=l;++i)
	{
		ans+=l/(i*i*i);
	}
	return ans;
}

int main()
{
	ll m,n=-1;

	std::cin>>m;

	ll l=0,r=1e18;
	while(l<r)
	{
		ll mid=(l+r)/2;

		if(val(mid)<m){l=mid+1;}
		else{r=mid;}
	}

	if(val(l)==m){n=l;}
	
	std::cout<<n<<std::endl;
	return 0;
}