#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_map>

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

	std::unordered_map<char,int> map;

	for(char i='0';i<='9';++i)
	{
		map.insert({i,map.size()});
	}
	for(char i='A';i<='Z';++i)
	{
		map.insert({i,map.size()});
	}
	for(char i='a';i<='z';++i)
	{
		map.insert({i,map.size()});
	}

	map.insert({'-',map.size()});
	map.insert({'_',map.size()});

	ll ans=1;
	for(ll i=0;i<str.size();++i)
	{
		ll index=map[str[i]];

		for(ll j=0;j<6;++j)
		{
			if ((index&(1<<j))==0)
			{
				ans=(ans*3)%MOD;
			}

		}
	}

	std::cout<<ans<<std::endl;

	return 0;
}