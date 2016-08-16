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
	ll n,h,k;
	std::cin>>n>>h>>k;

	vll a(n,0);

	for(ll i=0;i<n;++i)
	{
		std::cin>>a[i];
	}


	ll sum=0,time=0,i=0;

	while(i<n)
	{
		// std::cin>>a[i];
		// std::cout<<"HERE SUM<0"<<" "<<i<<std::endl;

		// std::cout<<sum<<std::endl;
		if(sum+a[i]<=h)
		{
			sum+=a[i];
			++i;
		}
		else if(sum<=k)
		{
			sum=0;
			++time;
		}
		else
		{
			time+=sum/k;
			sum=sum%k;
		}
		sum<0?sum=0:sum=sum;
	}

	while(sum>0)
	{
		// std::cout<<"HERE SUM>0"<<std::endl;

		if(sum<=k)
		{
			sum=0;
			++time;
			break;
		}
		time+=sum/k;
		sum=sum%k;
	}
	std::cout<<time<<std::endl;
	/*for(int i=0;i<n;++i)
	{
		if(sum+a[i]<h)
		{
			sum+=a[i];
		}
		else
		{

		}
	}*/

	return 0;
}