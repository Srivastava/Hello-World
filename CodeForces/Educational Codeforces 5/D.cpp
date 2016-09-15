#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <set>

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

const int N=1e6+100;

int main()
{
	int n,k;
	std::cin>>n>>k;

	


	vi a(n,0),cnt(N,0);
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}

	int x=0,y=0;
	int t=0,s=0;
	for(int i=0;i<n;++i)
	{
		if(cnt[a[i]]==0){++t;}
		cnt[a[i]]++;

		while(t>k)
		{
			cnt[a[s]]--;
			if(cnt[a[s]]==0){--t;}
			++s;
		}

		if(y-x<i-s)
		{
			y=i;
			x=s;
		}
	}
	
	std::cout<<x+1<<" "<<y+1<<std::endl;
	return 0;
}