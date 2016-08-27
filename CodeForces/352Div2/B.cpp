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
	int n;
	std::cin>>n>>str;

	if(n>26){std::cout<<-1<<std::endl;return 0;}
	std::unordered_map<char,int> map;

	for(int i=0;i<n;++i)
	{
		map[str[i]]++;
	}

	ll sum=0;
	// std::cout<<map.size()<<std::endl;
	for(auto it=map.begin();it!=map.end();++it)
	{
		sum+=it->second-1;
		// std::cout<<it->second<<" "<<it->first<<std::endl;
	}

	std::cout<<sum<<std::endl;

	return 0;
}