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

	int ind=0;
	for(int i=0;i<str.size();++i)
	{
		if(i>0)
		{
			if(str[i]==str[i-1])
			{
				std::cout<<"Impossible"<<std::endl;
				return 0;
			}
		}
		map[str[i]]++;
		if(map[str[i]]>1){ind=i;}
	}

	// std::string str1,str2;
	if(ind<=13)
	{
		std::string str1=str.substr(0,ind)+str.substr(ind+1,13-ind);
		std::string str2=str.substr(14);

		std::reverse(str2.begin(),str2.end());
		std::cout<<str1<<"\n"<<str2<<std::endl;
	}

	else
	{
		std::string str1=str.substr(0,13);
		std::string str2=str.substr(13,ind-13)+str.substr(ind+1);

		std::reverse(str2.begin(),str2.end());
		
		std::cout<<str1<<"\n"<<str2<<std::endl;
	}
	
	return 0;
}