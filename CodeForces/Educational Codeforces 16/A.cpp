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
	std::string str;
	std::cin>>str;

	int ans=8;

	if(str[0]=='a'&& (str[1]=='1' || str[1]=='8'))
	{
		ans=3;
	}

	else if(str[0]=='h'&& (str[1]=='1' || str[1]=='8'))
	{
		ans=3;
	}

	else
	{
		if(str[0]=='a' || str[0]=='h'|| str[1]=='8' || str[1]=='1')
		{
			ans=5;
		}
	}
	std::cout<<ans<<std::endl;
	return 0;
}