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
typedef std::pair<int,int> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;


vi s(101,0);

int find(int x)
{
	s[x]==x ? x :s[x]=find(s[x]);
}
void join(int x,int y)
{
	s[find(y)]=find(x);
}


vi edges[111];
bool vis[111];

int main()
{
	int n;
	std::cin>>n;

	vi x(n+1,0),y(n+1,0);

	int ind=1;
	for(int k=0;k<n;++k)
	{
		int t,a,b;
		std::cin>>t>>a>>b;

		if(t==1)
		{
			x[ind]=a;
			y[ind]=b;

			for(int i=1;i<ind;++i)
			{
				if (x[i] < a && a < y[i] || x[i] < b && b < y[i])
					edges[cnt].push_back(i);

				if (a < x[i] && x[i] < b || a < y[i] && y[i] < b)
					edges[i].push_back(cnt);
			}

		}
	}
	
	return 0;
}