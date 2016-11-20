#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

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

	std::string s;
	std::cin>>s;
	if(n==0){std::cout<<s<<std::endl;return 0;}

	std::string str="go";

	std::string res="";
	for(int i=0;i<n;++i)
	{
		bool found=false;
		if(s[i]!='o')
		{
			res+=s[i];
		}
		else
		{
			if(i+2<n)
			{
				std::string temp=s.substr(i+1,2);
				if(temp==str)
				{
					while(temp==str && i+2<n)
					{
						i+=2;
						temp=s.substr(i+1,2);
					}
					res+="***";
					continue;
				}
				res+=s[i];
				continue;

			}
			else
			{
				res+=s[i];
				continue;
			}
		}

	}

	std::cout<<res<<std::endl;
	return 0;
}