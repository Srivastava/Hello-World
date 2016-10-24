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

	// std::vector<std::string> vstr;
	std::vector<int> vstr;

	std::string pass;
	for(int i=0;i<n;++i)
	{
		std::string v;
		std::cin>>v;
		vstr.push_back(v.size());
	}

	std::cin>>pass;
	std::sort(vstr.begin(),vstr.end());

	auto it=std::lower_bound(vstr.begin(),vstr.end(),pass.size());
	auto it1=std::upper_bound(vstr.begin(),vstr.end(),pass.size());


	int sz=it-vstr.begin();
	int val=sz/k;
	int mintime=sz+val*5+1;

	int sz1=it1-vstr.begin()-1;
	int val1=sz1/k;
	int maxtime=sz1+val1*5+1;

	// std::cout<<sz<<" "<<sz1<<" ** "<<std::endl;
	std::cout<<mintime<<" "<<maxtime<<std::endl;

	return 0;
}