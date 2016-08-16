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

int main()
{
	int t;
	std::cin>>t;

	while(t--)
	{
		int n;
		std::cin>>n;

		std::vector<int> val(n,0);
		double sum=0;
		bool sti=true;

		for(int i=0;i<n;++i)
		{
			std::cin>>val[i];
			sum+=val[i];
			if(val[i]<=2){sti=false;}
		}

		if(sti==false){std::cout<<"No"<<std::endl;continue;}
		if(sum/n < 4.0)
		{
			sti=false;
		}
		if(sti==false){std::cout<<"No"<<std::endl;continue;}
		else
		{
			std::cout<<"Yes"<<std::endl;
		}
	}
	return 0;
}