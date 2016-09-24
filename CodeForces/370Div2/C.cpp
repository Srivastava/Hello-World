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
	int x,y;
	std::cin>>x>>y;

	std::vector<int> v(3,0);
	v[0]=y;
	v[1]=y;
	v[2]=y;

	int count=0;
	while(true)
	{
		if(v[0]>=x && v[1]>=x && v[2]>=x)
		{
			std::cout<<count<<std::endl;
			break;
		}
		++count;
		if(count%3==1)
		{
			v[0]=v[1]+v[2]-1;
		}
		if(count%3==2)
		{
			v[1]=v[0]+v[2]-1;
		}
		if(count%3==0)
		{
			v[2]=v[0]+v[1]-1;
		}
	}
	
	// std::cout<<count<<std::endl;
	return 0;
}