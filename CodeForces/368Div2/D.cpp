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
	int n,m,q;
	std::cin>>n>>m>>q;

	std::vector<vi> query;

	for(int i=0;i<q;++i)
	{
		int a,b,c;
		std::cin>>a>>b;
		
		vi temp;

		temp.push_back(a);
		temp.push_back(b);
		
		if(a==1 || a==2)
		{
			std::cin>>c;
			temp.push_back(c);
		}

		query.push_back(temp);
	}

	


	return 0;
}