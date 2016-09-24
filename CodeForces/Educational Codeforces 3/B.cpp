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
	std::unordered_map<ll,ll> map;

	int n,m;
	std::cin>>n>>m;

	vi a(n,0);
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
		map[a[i]]++;
	}

	std::sort(a.begin(),a.end());

	ll sol=0;
	int num=a[0],diff=0;
	for(int i=0;i<n;++i)
	{
		if(num!=a[i]){++diff;num=a[i];}
		if(diff==m){break;}

		// std::cout<<diff<<std::endl;
		// std::cout<<(n-i-1)-(map[a[i]]-1)<<std::endl;
		sol+=(n-i-1)-(map[a[i]]-1);
		map[a[i]]--;


	}
	std::cout<<sol<<std::endl;
	return 0;
}