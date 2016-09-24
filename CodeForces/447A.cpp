#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_map>

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
	int n,p;
	std::cin>>p>>n;

	// std::cout<<n<<" "<<p<<std::endl;
	vll arr(n+1,0);

	for(int i=0;i<n;++i)
	{
		ll a;
		std::cin>>a;
		// ll mod=a%p;

		if(arr[a%p]==1){std::cout<<i+1<<std::endl;return 0;}
		arr[a%p]=1;
	}

	std::cout<<-1<<std::endl;
	return 0;
}