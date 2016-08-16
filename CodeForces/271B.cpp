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
typedef std::vector<vi> vvi;
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

int main()
{
	std::unordered_map<int,int> map;
	
	int prev=100003;
	for(int i=99999;i>2;i=i-2)
	{
		map.insert({i+1,prev});
		bool isPrime=true;
		for(int j=3;j<std::sqrt(i)+1;j=j+2)
		{
			if(i%j==0)
			{
				isPrime=false;
			}
		}

		if(isPrime)
		{
			map.insert({i,i});
			prev=i;
		}
		else
		{
			map.insert({i,prev});
		}
	}
	map.insert({2,2});
	map.insert({1,2});
	
	/*for(std::unordered_map<int,int>::iterator it=map.begin();it!=map.end();++it)
	{
		std::cout<<it->first<<" "<<it->second<<std::endl;
	}*/

	int n,m;
	std::cin>>n>>m;

	vvi arr;
	
	for(int i=0;i<n;++i)
	{
		vi temp;
		
		for(int j=0;j<m;++j)
		{
			int val;
			std::cin>>val;
			
			std::unordered_map<int,int>::iterator it=map.find(val);
			temp.push_back(it->second-val);
			
		}
		
		arr.push_back(temp);
	}

	// for(int i=0;i<n;++i)
	// {
	// 	std::copy(arr[i].begin(),arr[i].end(),std::ostream_iterator<int>(std::cout,","));
	// 	std::cout<<std::endl;
	// }


	int min=1000000;

	for(int i=0;i<n;++i)
	{
		int sum=0;
		
		for(int j=0;j<m;++j)
		{
			sum+=arr[i][j];
		}
		// std::cout<<sum<<std::endl;
		if(sum==0){std::cout<<0<<std::endl;return 0;}
		min=std::min(min,sum);
	}

	for(int j=0;j<m;++j)
	{
		int sum=0;
		
		for(int i=0;i<n;++i)
		{
			sum+=arr[i][j];
		}
		// std::cout<<sum<<std::endl;
		if(sum==0){std::cout<<0<<std::endl;return 0;}
		min=std::min(min,sum);
	}

	std::cout<<min<<std::endl;
	return 0;
}