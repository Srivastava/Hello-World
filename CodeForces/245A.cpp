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

	int ra=0,rb=0,la=0,lb=0;
	int comm;
	for(int i=0;i<n;++i)
	{
		std::cin>>comm;
		int a,b;

		if(comm==1)
		{
			std::cin>>a>>b;
			ra+=a;
			la+=b;
		}

		if(comm==2)
		{
			std::cin>>a>>b;
			rb+=a;
			lb+=b;
		}

	}

	int suma=ra+la;
	int sumb=rb+lb;

	if(ra>=suma/2){std::cout<<"LIVE"<<std::endl;}
	else{std::cout<<"DEAD"<<std::endl;}


	if(rb>=sumb/2){std::cout<<"LIVE"<<std::endl;}
	else{std::cout<<"DEAD"<<std::endl;}

	return 0;
}