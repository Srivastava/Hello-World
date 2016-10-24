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
	int n,k;
	std::cin>>n>>k;

	vi a(n,0),b(n,0);
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}

	b[0]=a[0];
	int ans=0;
	for(int i=1;i<n;++i)
	{
		int val=a[i]+a[i-1];

		val<k ? ans+=k-val,a[i]=k-val+a[i] : ans+=0;

	}
	std::cout<<ans<<std::endl;
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;
	return 0;
}