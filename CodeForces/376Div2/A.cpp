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
	std::unordered_map<char,int> map;
	
	int cnt=1;
	for(char c='z';c>='o';--c)
	{
		map[c]=cnt;
		++cnt;
	}
	cnt=0;
	for(char c='a';c<='n';++c)
	{
		map[c]=cnt;
		++cnt;
	}
	/*for(auto it=map.begin();it!=map.end();++it)
	{
		std::cout<<it->first<<" "<<it->second<<std::endl;
	}*/

	std::string str;
	std::cin>>str;
	int ans=std::abs(map[str[0]]);

	// std::cout<<ans<<std::endl;
	for(int i=1;i<str.size();++i)
	{
		int val=std::abs(map[str[i-1]])+map[str[i]];
		int val2=std::abs(str[i]-str[i-1]);
		// std::cout<<val<<" "<<val2<<std::endl;
		ans+=std::min(val,val2);
		// std::cout<<ans<<std::endl;
	}

	std::cout<<ans<<std::endl;
	return 0;
}
