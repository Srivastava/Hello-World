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


int gcd(int a, int b)
{
	return b==0 ? a : gcd(b,a%b);
}

int main()
{
	int t;
	std::cin>>t;

	while(t--)
	{
		int n,m;
		std::cin>>n>>m;

		int num=9*m;
		int deno=m+8*n;

		int g=gcd(num,deno);

		std::cout<<num/g<<"/"<<deno/g<<std::endl;
	}
	return 0;
}