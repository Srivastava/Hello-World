#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <iomanip>

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

const double PI = 3.1415926535897932384;

int main()
{
	double d,h,v,e;
	std::cin>>d>>h>>v>>e;

	double t = (PI*d*d*h)/(4*v-PI*d*d*e);


	if(t<0){std::cout<<"NO"<<std::endl;}
	else
	{
		std::cout<<"YES"<<std::endl;
		std::cout<<std::setprecision(13)<<t<<std::endl;
	}


	return 0;
}