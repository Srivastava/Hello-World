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
// typedef std::vector<int>::iterator it;

vi a;

int solve(int target)
{
	int l=-1,r=a.size(),m=0;

	// std::cout<<a.size()<<" target"<<std::endl;
	while(r-l>1)
	{
		m=(r+l)/2;
		// std::cout<<l<<" "<<m<<" "<<r<<std::endl;

		if(a[m]<target)
		{
			l=m;
		}
		else
		{
			r=m;
		}
	}
	return r;
}

int main()
{
	int n;
	std::cin>>n;

	// vi a(n,0),l(n,0),r(n,0);
	a.resize(n,0);

	// l[0]=1;

	ll sum=0;

	for(int i=0;i<n;++i)
	{
		int k;
		std::cin>>k;
		sum+=k;
		
		a[i]=sum;

		// std::cout<<a[i]<<std::endl;
		
	}


	int m;
	std::cin>>m;

	vi q(m,0);
	
	for(int i=0;i<m;++i)
	{
		int val;
		std::cin>>val;
		// std::cin>>q[m];

		std::cout<<solve(val)+1<<std::endl;
	}



	return 0;
}