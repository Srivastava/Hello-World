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

	int mi=0,ch=0;

	for(int i=0;i<n;++i)
	{
		int u,v;
		std::cin>>u>>v;

		if(u>v){++mi;}
		else if(v>u){++ch;}
		// u>v?++mi:++ch;
	}

	if(mi>ch){std::cout<<"Mishka"<<std::endl;}
	else if(mi<ch){std::cout<<"Chris"<<std::endl;}
	else if(mi==ch){std::cout<<"Friendship is magic!^^"<<std::endl;}

	return 0;
}