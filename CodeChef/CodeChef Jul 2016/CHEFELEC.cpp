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
	ll t;
	std::cin>>t;

	while(t--)
	{
		int n;
		std::cin>>n;

		// vll elec(n,0);
		vll v(n,0);

		std::string elec;
		std::cin>>elec;
		
		for(int i=0;i<n;++i)
		{
			std::cin>>v[i];
		}
		ll len=0,left=0,right=0;

		for(int i=0;i<n;++i)
		{
			right=i;
			ll count=0;
			// std::cout<<left<<" "<<right<<std::endl;
			if(elec[i]-'0'==1)
			{
				if(elec[left]-'0'==1)
				{
					for(int k=left;k<right;++k)
					{
						ll temp=std::min(v[k]-v[left],v[right]-v[k]);
						// std::cout<<count<<" "<<temp<<" ** "<<k<<std::endl;
						if(count>=temp && count!=0)
						{
							len+=count+temp;
							break;
						}
						count=temp;
						if(k==right-1)
						{
							len+=temp;
						}
					}
					left=i;
				}
				else
				{
					// std::cout<<"Here"<<std::endl;
					len+=v[i]-v[left];
					left=i;
				}
			}

			if(i==n-1 && elec[i]-'0'==0)
			{
				len+=v[i]-v[left];
				left=i;
			}
			else if(elec[left]==0 && elec[i]-'0'==1)
			{
				len+=v[i]-v[left];
				left=i;
			}
		}
		
		// for(int i=0;i<n;++i)
		// {
		// 	if(elec[i]-'0'==1 )
		// 	{
		// 		// std::cout<<elec[left]<<" "<<i<<std::endl;
		// 		if(elec[left]-'0'==1)
		// 		{
		// 			int mid=(i-left+1)/2;
		// 			// std::cout<<mid<<std::endl;
		// 			len+=v[mid]-v[left];
		// 			len+=v[i]-v[mid+1];
		// 			left=i;
		// 		}

		// 		else
		// 		{
		// 			// std::cout<<"Here"<<std::endl;
		// 			len+=v[i]-v[left];
		// 			left=i;
		// 		}
		// 	}
		// 	if(i==n-1 && elec[i]-'0'==0)
		// 	{
		// 		len+=v[i]-v[left];
		// 		left=i;
		// 	}
		// 	else if(elec[left]==0 && elec[i]-'0'==1)
		// 	{
		// 		len+=v[i]-v[left];
		// 		left=i;
		// 	}
		// }
			// std::cout<<left<<std::endl;
		// if(left<n-1){len+=v[n-1]-v[left];}
		std::cout<<len<<std::endl;

	}
	return 0;
}