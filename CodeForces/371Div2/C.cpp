#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <set>
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

ll conv(std::string s)
{
	ll t=0;
	for(int i=0;i<s.size();++i)
	{
		t=t*10+((s[i]-'0')&1);
	}
	return t;

}

int main()
{
	int n;
	std::cin>>n;
	std::unordered_map<ll,int> map;

	for(int i=0;i<n;++i)
	{
		char c;std::string s;
		std::cin>>c>>s;
		ll t=conv(s);

		// std::cout<<t<<std::endl;
		if(c=='+'){map[t]++;}
		else if(c=='-'){map[t]--;}
		else
		{
			std::cout<<map[t]<<std::endl;
		}
	}
	return 0;
}