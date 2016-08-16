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

	ll n;
	std::cin>>n;

	std::string str;
	std::cin>>str;

	ll left=0,right=1;
	ll ans=0;

	if(n==1)
	{
		std::cout<<1<<std::endl;
		return 0;
	}
	while(1 && right<n)
	{
		// std::cout<<left<<" * "<<right<<std::endl;
		ll pos=left;
		if(right==n-1)
		{
			ans=right-left+1;

			while(left!=right && left<n && right>=left)
			{
				if(str[left]==str[right])
				{
					// std::cout<<left<<" ** "<<right<<std::endl;
					--right;
					left=pos;
					ans=right-left+1;
				}
				++left;

			}
			break;
		}

		if(str[left]==str[right] && left!=right)
		{
			// std::cout<<left<<" "<<right<<std::endl;
			if(right-left==1)
			{
				left=right;
			}
			else
			{
				++left;
				--right;
			}
		}

		else
		{

			++right;
		}
	}
	std::cout<<ans<<std::endl;

	return 0;
}