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
	ll a1,b1,a2,b2,k;
	std::cin>>a1>>b1>>a2>>b2>>k;

	if(a2>b1 || a1>b2){std::cout<<0<<std::endl;return 0;}

	ll time=0;
	ll upper=std::min(b1,b2);
	ll lower=std::max(a1,a2);

	time=upper-lower+1;
	if(k>=lower && k<=upper)
	{
		time--;
	}
	/*if(a2>=a1 && a2<=b1)
	{
		time=b1-a2+1;
		if(k>=a2 && k<=b1){--time;}
	}
	else if(a1>=a2 && a1<=b2)
	{
		time=b2-a1+1;
		if(k>=a1 && k<=b2){--time;}
	}*/

	std::cout<<time<<std::endl;
	return 0;
}