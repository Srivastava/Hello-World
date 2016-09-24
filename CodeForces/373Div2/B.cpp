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

	std::string r(n,'r'),b(n,'b');

	for(int i=1;i<n;++i)
	{
		if( i & 1)
		{
			r[i]='b';
			b[i]='r';
		}
	}

	// std::cout<<r<<std::endl;
	// std::cout<<b<<std::endl;

	if(str==r || str==b){std::cout<<0<<std::endl;return 0;}
	
	ll fr=0,sb=0;
	ll min1=1e8,min2=1e8;

	for(int i=0;i<n;++i)
	{
		if(str[i]!=r[i])
		{
			str[i]=='r' ? ++fr:++sb;
		}
	}
	min1=std::max(fr,sb);
	fr=0;sb=0;

	for(int i=0;i<n;++i)
	{
		if(str[i]!=b[i])
		{
			str[i]=='r' ? ++fr:++sb;
		}
	}

	min2=std::max(fr,sb);

	ll ans=std::min(min1,min2);
	std::cout<<ans<<std::endl;
	return 0;
}