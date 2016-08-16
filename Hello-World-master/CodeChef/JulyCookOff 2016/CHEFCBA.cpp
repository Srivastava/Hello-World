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

	ll a,b,c,d;
	std::cin>>a>>b>>c>>d;

	if(a*d==b*c || a*b==c*d || a*c==b*d)
	{
		std::cout<<"Possible"<<std::endl;
	}
	else
	{
		std::cout<<"Impossible"<<std::endl;
	}

	return 0;
}