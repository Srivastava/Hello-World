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
	ll n;
	std::cin>>n;

	vll a(n,0);

	int sum=0;
	bool ans=true;
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
		if(a[i]==0 && sum%2==1)
		{
			ans=false;
		}
		sum+=a[i];
	}

	if(sum%2==1){ans=false;}

	if(ans)
	{
		std::cout<<"YES"<<std::endl;
	}
	else
	{
		std::cout<<"NO"<<std::endl;
	}

	return 0;
}