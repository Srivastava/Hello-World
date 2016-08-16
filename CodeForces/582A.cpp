#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <map>

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

int gcd(ull a,ull b)
{
	return b==0?a : gcd(b,b%a);
}

int main()
{
	ull n;
	std::cin>>n;

	int m=n*n;

	vull v;
	while(m--)
	{
		ull val;
		std::cin>>val;
		v.push_back(val);
	}

	std::sort(v.begin(),v.end());
	
	vull ans(n,0)
	;
	std::map<ull, int> num;

	for(int i=0;i<n*n;++i)
	{
		num[v[i]]++;
	}
	
	std::map<ull,int>::reverse_iterator it = num.rbegin();
	
	ll pos=n-1;
	ull count=0;

	std::map<ull,int>::iterator rit= num.begin();
	for(;rit!=num.end();++rit)
	{
		// if(n-pos==n+1){break;}
		// std::cout<<pos<<std::endl;
		while(rit->second>0)
		{
			ans[pos]=rit->first;
			++count;

			std::cout<<rit->second<<std::endl;
			--rit->second;
			// rit->second=rit->second-1;
			for(ll i = pos+1;i<n;++i)
			{
				std::cout<<i<<" " <<count<<" "<<pos<<std::endl;
				if(i<=-1){break;}
				// if(ans[pos]!=0)
				{
					
					ull temp= gcd(ans[pos],ans[i]);
					if(num.find(temp)!=num.end())
					{
						num[temp]=num[temp]-2;
					}
				}
			}
			pos--;
		}
	}

	// std::cout<<ans.size()<<std::endl;
	// for(int i=0;i<n;++i)
	// {
	// 	std::cout<<ans[i]<<" ";
	// }
	std::copy(ans.begin(),ans.end(),std::ostream_iterator<unsigned long long>(std::cout," "));
	std::cout<<std::endl;

		
}

// int main()
// {
// 	int n;
// 	std::cin>>n;

// 	int m=n*n;

// 	std::vector<ull> v;
// 	while(m--)
// 	{
// 		unsigned long long val;
// 		std::cin>>val;
// 		v.push_back(val);
// 	}

// 	std::sort(v.begin(),v.end());
	
// 	std::vector<unsigned long long> ans;

// 	int i=n*n-1;
// 	while(ans.size()!=n)
// 	{
// 		if(i==0 && ans.size()!=n)
// 		{
// 			int k=n-ans.size();
// 			for(int k=0;k<n-ans.size();++k)
// 			{
// 				ans.push_back(v[k]);
// 			}
// 			break;
// 		}

// 		if(i==n*n-1)
// 		{
// 			ans.push_back(v[i]);
// 			--i;
// 		}

// 		else
// 		{
// 			if(v[i]==v[i+1])
// 			{
// 				--i;
// 				continue;
// 			}
// 			else
// 			{
// 				ans.push_back(v[i]);
// 				--i;
// 			}
// 		}
			
// 	}

// 	std::copy(ans.begin(),ans.end(),std::ostream_iterator<unsigned long long>(std::cout," "));
// 	std::cout<<std::endl;


// 	return 0;
		
// }