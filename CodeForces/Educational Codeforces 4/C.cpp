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
	std::string str;
	std::cin>>str;

	std::stack<char> s;
	int ans=0;
	for(int i=0;i<str.size();++i)
	{
		char c=str[i];

		if(c=='<' || c=='(' || c=='{' || c=='[')
		{
			s.push(c);
		}
		else
		{
			if(s.empty())
			{
				std::cout<<"Impossible"<<std::endl;
				return 0;
			}

			char t=s.top();
			s.pop();

			// std::cout<<c<<" "<<t<<std::endl;
			if((c=='>' && t!='<'))
			{
				++ans;
			}
			else if((c==']' && t!='['))
			{
				++ans;
			}
			else if((c==')' && t!='('))
			{
				++ans;
			}
			else if((c=='}' && t!='{'))
			{
				++ans;
			}
		}
	}
	if(!s.empty()){std::cout<<"Impossible"<<std::endl;return 0;}
	std::cout<<ans<<std::endl;

	return 0;
}