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

		if(n==1)
		{
			std::cout<<"0 0 1 1"<<std::endl;
			std::cout<<"0 1 1 0"<<std::endl;
			continue;
		}

		std::cout<<n<<" "<<0<<" "<<n-1<<" "<<n<<std::endl;
		std::cout<<0<<" "<<n<<" "<<n<<" "<<n-1<<std::endl;

		for(int i=0,j=n-1;i<n && j>0;i+=2,j-=2)
		{
			std::cout<<i<<" "<<0<<" "<<n<<" "<<j<<std::endl;
		}

		for(int i=1,j=n-2;i<n && j>0;i+=2,j-=2)
		{
			std::cout<<0<<" "<<i<<" "<<j<<" "<<n<<std::endl;
		}
	}
	return 0;
}