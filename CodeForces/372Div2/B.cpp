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

int main()
{
	std::string str;
	std::cin>>str;

	if(str.size()<26){std::cout<<-1<<std::endl;return 0;}

	int sz=str.size();
	bool ok=false;
	for(int i=0;i<=sz-26;++i)
	{
		std::unordered_map<char,int> map;
		// std::cout<<i<<" i "<<std::endl;
		vi pos;
		bool bad=false;
		for(int j=0;j<26;++j)
		{
			// std::cout<<i<<" "<<j<<std::endl;
			if(str[i+j]!='?')
			{
				map[str[i+j]]++;
				// std::cout<<str[i+j]<<" "<<j<<std::endl;
				if(map[str[i+j]]>1){bad=true;break;}
			}
			else{pos.push_back(i+j);}
		}

		if(!bad)
		{
			int k=0;
			for(char c = 'A';c<='Z';++c)
			{
				auto it=map.find(c);
				if(it==map.end())
				{
					// std::cout<<pos[k]<<" "<<k<<" "<<pos.size()<<std::endl;
					str[pos[k]]=c;
					++k;
				}
			}
			ok=true;
			break;
			// std::cout<<str<<std::endl;
			// return 0;
		}

	}

	if(ok)
	{
		for(int i=0;i<str.size();++i)
		{
			if(str[i]=='?'){str[i]='A';};
		}
	}
	if(ok)
	{
		std::cout<<str<<std::endl;
	}
	else
	{

		std::cout<<-1<<std::endl;
	}

	return 0;
}