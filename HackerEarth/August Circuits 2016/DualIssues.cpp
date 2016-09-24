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


bool isPrime(int val)
{
	if(val==2 || val == 3){return true;}
	if(val==1){return false;}

	if(val%2==0){return false;}

	for(int i=3;i<std::sqrt(val)+1;++i)
	{
		if(val%i==0){return false;}
	}

	return true;
}

int main()
{
	int t;
	std::cin>>t;

	while(t--)
	{
		int n;
		std::cin>>n;
		// vi a(n,0);
		vi a;
		a.reserve(n);

		for(int i=0,val;i<n;++i)
		{
			std::cin>>val;
			if(isPrime(val))
			{
				a.push_back(val);
			}
		}

		if(a.size()==0)
		{
			std::cout<<-1<<std::endl;
			continue;
		}

		int ans=0;
		for(int i=0;i<a.size();++i)
		{
			ans=std::max(ans,a[i]*a[i]);
		}
		std::cout<<ans<<std::endl;
	}
	return 0;
}