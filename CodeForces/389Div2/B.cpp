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
	std::string s1,s2;
	std::cin>>s1>>s2;

	std::unordered_map<char,char> map,map1;
	for(int i=0;i<s1.size();++i)
	{
		if(s1[i]==s2[i]){continue;}
		if(map1.find(s2[i])==map1.end() && map.find(s1[i])==map.end() )
		{
			if(map1.find(s1[i])!=map1.end())
			{
				continue;
			}
			map[s1[i]]=s2[i];
			map1[s2[i]]=s1[i];
			// map1[s1[i]]=s2[i];
		}
	}

	std::string ans="";

	for(auto& c:s1)
	{
		if(map.find(c)!=map.end())
			ans+=map[c];
		else if(map1.find(c)!=map1.end())
			ans+=map1[c];
		else
			ans+=c;
	}

	// std::cout<<ans<<std::endl;
	if(ans==s2)
	{
		std::cout<<map.size()<<std::endl;
		for(auto it=map.begin();it!=map.end();++it)
		{
			std::cout<<it->first<<" "<<it->second<<std::endl;
		}
	}
	else
	{
		std::cout<<-1<<std::endl;
		return 0;
	}
	return 0;
}