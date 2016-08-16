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


typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

int main()
{
	ll n;
	std::cin>>n;
	
	std::string str;
	std::cin>>str;

	ll count=str.size();

	for(ll i=1;i<str.size();++i)
	{
		if(str[i]==str[i-1])
		{
			--count;
		}
	}

	std::cout<<n-count<<std::endl;
	return 0;
}