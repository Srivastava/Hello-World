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
	std::string a,b;
	std::cin>>a>>b;

	ll sum=0;
	bool add=false;

	if(a==b){std::cout<<0<<std::endl;}
	else
	{	
		ll f=0,s=0;
		for(int i=0;i<a.size();++i)
		{
			if(a[i]!=b[i])
			{
				a[i]=='4' ? ++f:++s;
			}
		}

		std::cout<<std::max(f,s)<<std::endl;
	}

	return 0;
}