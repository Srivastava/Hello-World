#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <stack>

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
	int n;
	std::cin>>n;

	std::string str;
	std::cin>>str;

	int ans=0;
	std::stack<char> su,sr;
	for(auto &c:str)
	{
		if(c=='L' || c=='R')
		{
			if(sr.empty()){sr.push(c);}
			else
			{
				if(sr.top()!=c)
				{
					while(!sr.empty())
					{
						sr.pop();
					}
					while(!su.empty())
					{
						su.pop();
					}
					sr.push(c);++ans;
				}
			}
		}

		if(c=='U' || c=='D')
		{
			if(su.empty()){su.push(c);}
			else
			{
				if(su.top()!=c)
				{
					while(!sr.empty())
					{
						sr.pop();
					}
					while(!su.empty())
					{
						su.pop();
					}

					su.push(c);
					++ans;
				}
			}
		}
	}
	std::cout<<ans+1<<std::endl;
	return 0;
}