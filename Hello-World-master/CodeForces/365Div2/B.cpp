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
	ll n,k;
	std::cin>>n>>k;
	vll c(n+1,0);

	// std::cout<<"here"<<std::endl;
	ll allsum=0;
	for(int i=1;i<=n;++i)
	{
		std::cin>>c[i];
		allsum+=c[i];
	}

	// std::cout<<"here 1"<<std::endl;

	vll cap(k+1,0);
	// vb test(n+1,false)
	ll revsum=0;
	for(int i=1;i<=k;++i)
	{
		std::cin>>cap[i];
		revsum+=c[i];
	}

	// std::cout<<"here 2"<<std::endl;
	ll sum=0;

	// std::cout<<"here 3"<<std::endl;
	for(int i=1;i<=n;++i)
	{
		if(i!=n)
		{
			sum+=c[i]*c[i+1];
		}

		else if(i==n)
		{
			sum+=c[i]*c[1];
		}
	}

	for(int i=1;i<=k;++i)
	{
		int city=cap[i];

		for(int j=1;j<=n;++j)
		{
			std::cout<<c[city]<<" "<<c[j]<<" "<<c[city]*c[j]<<std::endl;
			if(i>1)
			{

				if(i!=j && && i!=cap[i-1])
				sum+=c[city]*c[j];
			}
			else
			{
				if(i!=j)
				sum+=c[city]*c[j];
			}
		}
		if(i==1){sum-=c[city]*c[n];}
	}
	std::cout<<"here 4" <<sum<<" "<<revsum<<std::endl;

	/*revsum=0;
	for(int i=1;i<=k;++i )
	{
		int city=cap[i];

		if(city==1)
		{
			// std::cout<<allsum<<" "<<c[n]<<" "<<c[city+1]<<std::endl;
			sum+=c[city]*(allsum -c[city+1]-c[n]-c[city]-revsum); 
			// std::cout<<sum<<" * "<<(allsum -c[city+1]-c[n]-c[city])<<std::endl;
		}
		else if(city!=n)
		{
			// std::cout<<allsum<<" "<<c[city-1]<<" "<<c[city+1]<<std::endl;
			sum+=c[city]*(allsum -c[city+1]-c[city-1]-c[city]-revsum); 
		}
		else if(city==n)
		{
			// std::cout<<allsum<<" "<<c[city-1]<<" "<<c[city+1]<<std::endl;
			sum+=c[city]*(allsum-c[1]-c[city-1]-c[city]-revsum);
		}
		std::cout<<sum<<" "<<revsum<<std::endl;
		// revsum+=c[city];
	}

	for(int i=1;i<=k/2;++i)
	{
		for(int j=i+1;j<=k;++j)
		{
			sum-=c[cap[i]]*c[cap[j]];
		}
		
		std::cout<<sum<<std::endl;
	}
	// std::cout<<"here 5"<<std::endl;
	std::cout<<sum<<std::endl;*/
	return 0;
}