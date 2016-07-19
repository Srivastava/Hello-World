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
	ll t,s,x;
	std::cin>>t>>s>>x;

	if(x<t){std::cout<<"NO"<<std::endl;}
	else
	{
		// std::cout<<x<<" "<<t<<" "<<s<<std::endl;
		// std::cout<<(x-t)%s<<" "<<(x-t-1)%s<<std::endl;

		if(((x-t)%s==0 &&(x-t)>=0) || ((x-t-1)%s==0 && x>t+1)  )
		{
			std::cout<<"YES"<<std::endl;
		}
		else
		{
			std::cout<<"NO"<<std::endl;
		}
	}

	/// std::cout<< t << " "<<s<<" "<<x<<" "<<x-t-1<<" "<<x-t<<std::endl;
	// if(x-t-1 !=0)
	// {
	// }

	return 0;
}

0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000