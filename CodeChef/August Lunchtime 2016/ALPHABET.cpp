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

	for(int i=0;i<str.size();++i)
	{
		map[str[i]]++;
	}

	int n;
	std::cin>>n;

	while(n--)
	{
		std::string str1;
		std::cin>>str1;

		bool read=true;

		for(int i=0;i<str1.size();++i)
		{
			auto it = map.find(str1[i]);

			if(it==map.end())
			{
				read=false;
				break;
			}
		}

		if(read)
		{
			std::cout<<"Yes"<<std::endl;
		}
		else
		{
			std::cout<<"No"<<std::endl;
		}
	}

	return 0;
}