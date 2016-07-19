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

// const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

int main()
{

	ll n;
	std::cin>>n;

	vll a(n,0);

	ll sum=0,max=0;
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
		sum+=a[i];
		if(a[i]>max)
		{
			max=a[i];
		}
	}

	// std::cout<<max<<" "<<sum<<" "<<(sum+1)/(n-1)<<std::endl;
	ll ans=std::ceil(1.*(sum)/(n-1));

	std::cout<<std::max(ans,max)<<std::endl;
	// std::sort(a.begin(),a.end());

	// ll minVal=a[1];
	// ll add=a[0] >= a[n-1]-minVal ? a[0]:a[n-1]-minVal;

	// ll count=0;
	// if(a[n-1]-minVal==0){++count;}
	// std::cout<<minVal+add-count<<std::endl; 
	// bool add=false;
	// for(int i=0;i<n;++i)
	// {
	// 	a[i]-=max;
	// 	if(a[i]>=-1 && i!=n-1)
	// 	{
	// 		add=true;
	// 	}
	// }


	// if(add)
	// {
	// 	std::cout<<max+1<<std::endl;
	// }
	// else
	// {
	// 	std::cout<<max<<std::endl;
	// }

	// std::cout<<max+1<<std::endl;
	return 0;
}