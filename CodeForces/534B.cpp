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
	int v1,v2;
	std::cin>>v1>>v2;

	int t,d;
	std::cin>>t>>d;

	vi b(t,0);

	for(int i=t-1;i>=0;--i)
	{
		b[i]=v2+(t-i-1)*d;
	}

	int sum=v1,index=0;
	bool mid=false;
	for(int i=1;i<t;++i)
	{
		int val=v1+i*d;
		if(val <=b[i])
		{
			sum+=val;
		}
		else
		{
			mid=true;
			index=i;
			break;
			// int diff=val-b[i];

		}
	}
	if(mid)
	{
		for(int i=index;i<t;++i)
		{
			sum+=b[i];
		}
	}
		
	std::cout<<sum<<std::endl;
	return 0;
}