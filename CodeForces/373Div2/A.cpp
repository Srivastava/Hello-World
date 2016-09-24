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
	int n;
	std::cin>>n;

	vi a(n,0);
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}

	if(n==1 && a[0]==0){std::cout<<"UP"<<std::endl;return 0;}
	if(n==1 && (a[0]!=0 && a[0]!=15)){std::cout<<-1<<std::endl;return 0;}
	if(n==1 && a[0]==15){std::cout<<"DOWN"<<std::endl;return 0;}

	if(a[n-1]==15){std::cout<<"DOWN"<<std::endl;return 0;}
	if(a[n-1]==0){std::cout<<"UP"<<std::endl;return 0;}

	std::string ans;
	
	a[n-1]>a[n-2] ? ans="UP" : ans ="DOWN";

	std::cout<<ans<<std::endl;

	return 0;
}