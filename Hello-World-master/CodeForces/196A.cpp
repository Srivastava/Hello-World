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
	std::string str;
	std::cin>>str;

	char c=str[0];

	// std::sort(str.begin(),str.end());

	ll n=str.size();

	std::string ans;
	ans.push_back(str[n-1]);

	char curr=ans[0];
	for(ll i=n-2;i>=0;--i)
	{
		if(str[i]>=curr)
		{
			ans=str[i]+ans;
			curr=str[i];
		}
	}

	std::cout<<ans<<std::endl;
	return 0;
}