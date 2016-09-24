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
	int t;
	std::cin>>t;

	while(t--)
	{
		int n;
		std::cin>>n;
		std::string str;
		std::cin>>str;

		vi a(n,0);
		for(int i=0;i<n;++i)
		{
			std::cin>>a[i];
		}

		if(n==1 && str=="Dee")
		{
			if(a[0]%2==0)
				std::cout<<str<<std::endl;
			else
			{
				std::cout<<"Dum"<<std::endl;
			}
		}
		else
		{
			std::cout<<"Dum"<<std::endl;
		}
	}
	return 0;
}