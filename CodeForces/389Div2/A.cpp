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
	ll n,m,k;
	std::cin>>n>>m>>k;

	ll lane = std::ceil(k/(double)(2*m));

	ll num=(lane-1)*m*2;

	// std::cout<<num<<std::endl;

	ll row=std::ceil((k-num)/2.0);

	char c = k%2==0 ? 'R':'L';

	std::cout<<lane<<" "<<row<<" "<<c<<std::endl;
	return 0; 
	return 0;
}