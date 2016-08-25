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
	std::unordered_map<char,char> map;
	map['a']='z';
	char c='a';

	for(char d='b';d<='z';++d)
	{
		map[d]=c;
		++c;
	}

	// std::cout<<map['a']<<" "<<map['o']<<std::endl;

	std::string str;
	std::cin>>str;

	int l=-1,r=0;
	bool left=false;
	for(int i=0;i<str.size();++i)
	{
		if(map[str[i]]<str[i])
		{
			// std::cout<<map[str[i]]<<" if "<<str[i]<<std::endl;
			if(!left)
			{
				l=i;
				left=true;
			}
				
		}

		else
		{
			// std::cout<<map[str[i]]<<" else "<<str[i]<<std::endl;
			if(left)
			{
				r=i-1;
				break;
			}
		}
		if(left)
		{
			r=i;
		}
	}


	if(l==-1)
	{
		str[str.size()-1]=map[str[str.size()-1]];
	}
	for(int i=l;i<=r && i>=0;++i)
	{
		str[i]=map[str[i]];
	}
	std::cout<<str<<std::endl;
	return 0;
}