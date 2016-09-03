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

typedef std::vector<long long>::iterator itr;

long long merge(itr left,itr mid,itr right)
{
	
	std::vector<long long> temp(std::make_move_iterator(left),std::make_move_iterator(right));

	itr begin=std::begin(temp);
	itr end=std::end(temp);
	
	std::size_t middle=std::distance(begin,end)/2;
	itr midPoint = std::next(begin,middle);
	
	itr l =begin;
	itr r=midPoint;

	itr i = left;

	long long inv=0;

	while(l<midPoint && r <end)
	{
		// *i=std::move((*l<*r) ? *l++ :*r++);
		// ++i;

		if(*l<*r)
		{
			*i++=std::move(*l++);
		}
		else
		{
			inv+=std::distance(l,midPoint);
			*i=std::move(*r++);
			++i;
		}
		
	}
	

	while(l<midPoint)
	{
		*i=std::move(*l++);
		++i;
	}
	

	while(r<end)
	{
		*i=std::move(*r++);
		++i;
	}

	return inv;
	
}

long long mergeSort(itr left,itr right)
{
	
	long long len=std::distance(left,right);
	
	if(len<=1){return 0;}

	
	std::size_t mid=len/2;
	
	itr midpoint=std::next(left,mid);
	

	
	long long leftInv=mergeSort(left,midpoint);
	long long rightInv=mergeSort(midpoint,right);
	
	
	long long mergeInv=merge(left,midpoint,right);
	
	return leftInv+rightInv+mergeInv;

}


int main()
{
	int t;
	std::cin>>t;

	while(t--)
	{
		int n;
		std::cin>>n;

		std::vector<std::string> vstr;
		vstr.reserve(n);

		for(int i=0;i<n;++i)
		{
			std::string str;
			std::cin>>str;
			vstr.push_back(str);
		}

		std::unordered_map<std::string,int> map;
		for(int i=1;i<=n;++i)
		{
			std::string str;
			std::cin>>str;

			map[str]=i;
		}

		std::vector<ll> arr(n,0);
		for(int i=0;i<n;++i)
		{
			arr[i]=map[vstr[i]];
		}

		std::cout<<mergeSort(arr.begin(),arr.end())<<std::endl;


	}
	return 0;
}