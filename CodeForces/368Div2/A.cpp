#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
// #include <unordered_map>

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
	int n,m;
	std::cin>>n>>m;

	// std::unordered_map<char,int> map;

	bool isColor=false;
	
	for(int i=0;i<n;++i )
	{
		for(int j=0;j<m;++j)
		{
			char c;
			std::cin>>c;

			if(c=='C' || c=='M' || c=='Y')
			{
				isColor=true;
			}
		}
	}

	if(isColor)
	{
		std::cout<<"#Color"<<std::endl;
	}
	else
	{
		std::cout<<"#Black&White"<<std::endl;
	}
	return 0;
}