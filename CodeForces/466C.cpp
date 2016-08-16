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

	vll a(n,0);
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}
	if(n<3){std::cout<<0<<std::endl;return 0;}

	ll sum=0,revsum=0;
	vll fsum(n,0),rsum(n,0);
	for(int i=0;i<n;++i)
	{
		fsum[i]=sum+a[i];
		rsum[n-i-1]=revsum+a[n-i-1];

		sum+=a[i];
		revsum+=a[n-i-1];
	}
		// std::cout<<sum<<" sum "<<std::endl;

	if(sum%3!=0){std::cout<<0<<std::endl;return 0;}
	// std::copy(fsum.begin(),fsum.end(),std::ostream_iterator<int>(std::cout,","));
	// std::cout<<std::endl;
	ll target = sum/3;
	// std::cout<<target<<std::endl;
	// std::copy(rsum.begin(),rsum.end(),std::ostream_iterator<int>(std::cout,","));
	// std::cout<<std::endl;


	vll count(n,0);
	ll lsum=0;
	for(int i=n-1;i>=0;--i)
	{
		if(rsum[i]==target)
		{
			++lsum;
			count[i]=lsum;

		}
		// std::cout<<lsum<<"*"<<std::endl;
		count[i]=lsum;
		
		
	}
	// count[n-1]=lsum;count[n-2]=lsum;
	ll nW=0;
	// std::copy(count.begin(),count.end(),std::ostream_iterator<ll>(std::cout,","));
	// std::cout<<std::endl;

	for(int i=0;i<n-2;++i)
	{
		// for(int j=i;j<n;++j)
		if(fsum[i]==target)
		{
			nW+=count[i+2];
		}
	}
	std::cout<<nW<<std::endl;
	return 0;
}