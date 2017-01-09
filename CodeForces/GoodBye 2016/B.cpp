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

	int north=0;

	

	for(int i=0;i<n;++i)
	{
		int val;
		std::string str;
		std::cin>>val>>str;

		if(north==0 && str[0]!='S')
		{
			std::cout<<"NO"<<std::endl;
			return 0;
		}
		else if(north==20000 && str[0]!='N')
		{
			std::cout<<"NO"<<std::endl;
			return 0;
		}
		else if(str[0]=='N')
			north-=val;
		else if(str[0]=='S')
			north+=val;

		if(north>20000 || north<0){std::cout<<"NO"<<std::endl;return 0;}
	}
	if(north==0)
		std::cout<<"YES"<<std::endl;
	else
		std::cout<<"NO"<<std::endl;
	return 0;
}