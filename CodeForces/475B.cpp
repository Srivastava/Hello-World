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
	ll n,m;
	std::cin>>n>>m;

	vvll map(n+1,vll(m+1,0));

	std::string str,str1;
	std::cin>>str>>str1;

	std::string str3 = {str.front(),str.back(),str1.front(),str1.back()};

	std::cout<< (str3=="<>v^" || str3=="><^v" ? "YES" : "NO");
	return 0;
}