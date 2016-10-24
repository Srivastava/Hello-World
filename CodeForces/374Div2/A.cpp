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

	std::string str;
	std::cin>>str;

	vi ans;

	int count=0;
	for(char c:str)
	{
		if(c=='B')
		{
			++count;
		}
		else
		{
			if(count>0){ans.push_back(count);}
			count=0;
		}
	}

	if(count>0){ans.push_back(count);count=0;}
	std::cout<<ans.size()<<std::endl;
	if(ans.size()>0)
	{
		std::copy(ans.begin(),ans.end(),std::ostream_iterator<int>(std::cout," "));
		std::cout<<std::endl;
		
	}

	return 0;
}