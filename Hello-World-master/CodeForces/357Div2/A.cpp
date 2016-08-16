#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <ctype.h>
#include <sstream>

typedef long long ll;
typedef unsigned long long ull;


typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

int main()
{
	ll n;
	std::cin>>n;

	bool p=false;

	for(int i=0;i<n;++i)
	{
		// for(int j=0;j<3;++j)
		// {
			std::string str;
			std::cin>>str;

			ll a,b;
			std::cin>>b>>a;
			// std::cout<<a<<" "<<b;

			if(b>=2400 && a-b>0)
			{
				p=true;
			}
		// }
	}
	

	if(p)
	{
		std::cout<<"YES"<<std::endl;
	}
	else
	{
		std::cout<<"NO"<<std::endl;
	}
	return 0;
}