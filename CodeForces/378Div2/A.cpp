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
	map['A']++;
	map['E']++;
	map['I']++;
	map['O']++;
	map['U']++;
	map['Y']++;

	std::string str;
	std::cin>>str;

	int ans=0;

	int sz=str.size();

	int prev=-1;
	for(int i=0;i<sz;++i)
	{
		if(map.find(str[i])!=map.end())
		{
			ans=std::max(ans,i-prev);
			prev=i;
		}
	}


	ans=std::max(ans,sz-prev);
	std::cout<<ans<<std::endl;

	return 0;
}