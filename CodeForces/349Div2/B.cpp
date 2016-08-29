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
	int n;
	std::cin>>n;

	vll l(n,0);

	ll sum=0;
	for(int i=0;i<n;++i)
	{
		std::cin>>l[i];
		sum+=l[i];
	}

	std::sort(l.begin(),l.end());

	ll max = l[n-1];
	ll sec = sum-max;

	if(sec>max)
	{
		ll temp = max;
		max=sec;
		sec=temp;
	}

	ll min = max-sec+1;

	std::cout<<min<<std::endl;
	return 0;
}