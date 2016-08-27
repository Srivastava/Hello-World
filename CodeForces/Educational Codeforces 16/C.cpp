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

	if(n==1){std::cout<<1<<std::endl;return 0;}

	std::vector<std::vector<int> > arr(n,std::vector<int> (n,0));
	
	int x=0,y=n/2,ox=0,oy=0;
	for(int i=1;i<=n*n;++i)
	{
		arr[x][y]=i;
		ox=x;
		oy=y;

		x--;
		if(x<0)
		{
			x=n-1;
		}
		y++;
		if(y>n-1)
		{
			y=0;
		}

		if(arr[x][y]!=0)
		{
			x=ox+1;
			y=oy;
		}
	}

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}


	return 0;
}