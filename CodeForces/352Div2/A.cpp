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
	std::string str="";

	for(int i=1;i<=1999;++i)
	{
		str+=std::to_string(i);
	}
/*
	for(int i=100;i<=199;++i)
	{
		str+=std::to_string(i);
	}

	for(int i=1000;i<=1999;++i)
	{
		str+=std::to_string(i);
	}
	// std::cout<<str<<std::endl;*/

	int n;
	std::cin>>n;

	std::cout<<str[n-1]<<std::endl;

	return 0;
}