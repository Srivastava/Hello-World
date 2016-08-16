#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_map>

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
	int n,k;
	// std::cin>>n>>k;
	scanf("%d%d",&n,&k);
	// printf("%d %d\n",n,k );
	vi a(n,0);

	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}

	int l=0,r=0,x=0,y=0,temp=0;

	std::unordered_map<int,int> map;
	for(int i=0;i<n;++i)
	{
		l=i;

		while(r<n)
		{
			map[a[r]]++;


			// if(map.size()==k)
			// {
			// 	if(r-l+1>temp)
			// 	{
			// 		temp=r-l+1;
			// 		x=l;
			// 		y=r;
			// 	}	
			// }

			if(map.size()>k)
			{
				auto it = map.find(a[i]);
				if(it!=map.end())
				{
					
					map.erase(it);
				}
				// map[a[i]]--;
				break;
			}
			++r;
			// std::cout<<i<<" "<<r<<std::endl;
		}

		if(r-i>temp)
		{
			temp=r-i;
			x=i;
			y=r;
		}
	}

	std::cout<<x+1<<" "<<y<<std::endl;
	// std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout,","));
	// std::cout<<std::endl;

	return 0;
}

