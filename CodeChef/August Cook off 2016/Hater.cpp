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
	ll t;
	std::cin>>t;
	while(t--)
	{
		ll n;
		std::cin>>n;

		vll c(n,0);
		bool can=true;
		ll sum=0;
		for(int i=0;i<n;++i)
		{
			std::cin>>c[i];
			sum+=c[i];
			// std::cout<<c[i]<<" "<<n-i-1<<std::endl;
			if(c[i]>n-i-1)
			{
				can=false;
			}
		}

		if(!can)
		{
			std::cout<<0<<std::endl;
		}
		else
		{
			ll val = ((n)*(n-1))/2;
			ll diff = val - sum;
			ll maxDiff = val/2;

			// std::cout<<n<<" "<<val<<" "<<diff<<std::endl;
			if(diff==val || diff==0)
			{
				std::cout<<1<<std::endl;
			}
			else
			{
				vll arr(val+1,0);
				arr[0]=1;arr[val]=1;

				if(val%2!=0)
				{
					for(int i=2;i<=maxDiff;++i)
					{
						arr[i]=1+arr[i-1];
					}
					arr[maxDiff+1]=arr[maxDiff];
					for(int i=maxDiff+2;i<val;++i)
					{
						arr[i]=arr[maxDiff-(i-maxDiff-1)];
					}
				}

				else
				{
					for(int i=2;i<=maxDiff;++i)
					{
						arr[i]=1+arr[i-1];
					}
					
					for(int i=maxDiff+1;i<val;++i)
					{
						arr[i]=arr[maxDiff-(i-maxDiff)];
					}
				}

				// std::copy(arr.begin(),arr.end(),std::ostream_iterator<ll>(std::cout,","));
				// std::cout<<std::endl;
				std::cout<<arr[diff]%MOD<<std::endl;
			}
		}
	}
	return 0;
}