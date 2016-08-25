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
	ll a00,a01,a10,a11;
	std::cin>>a00>>a01>>a10>>a11;

	ll sum=a00+a01+a10+a11;

	// std::cout<<sum<<" sum "<<std::endl;
	if(sum==0)
	{
		std::cout<<0<<std::endl;
		return 0;
	}

	ll nz=(1+std::sqrt(1+8*a00))/2;
	ll no=(1+std::sqrt(1+8*a11))/2;

	// std::cout<<nz<<" "<<no<<std::endl;
	if((nz*(nz-1))/2!=a00 || (no*(no-1))/2!=a11)
	{
		std::cout<<"Impossible"<<std::endl;
		return 0;
	}
	if(a01==0&&a10==0)
	{
		if(a11==sum)
		{
			std::string str(no,'1');
			std::cout<<str<<std::endl;
			return 0;
		}
		else if(a00==sum)
		{
			std::string str(nz,'0');
			std::cout<<str<<std::endl;
			return 0;
		}
	}

	if(a10+a01!=no*nz)
	{
		std::cout<<"Impossible"<<std::endl;
		return 0;
	}

	ll div=a01/no;
	ll left=a01-(no*div);
	// std::cout<<left<<"  left "<<div<<std::endl;
	std::string str(no,'1');
	std::string str1(nz,'0');

	str+=str1;
	// std::cout<<str<<" strreal"<<std::endl;

	if(div==0)
	{
		str[no]='1';
		str[no-a01]='0';
	}
	
	else
	{
		int i=0;
		while(i<div)
		{
			str[i]='0';
			str[no+i]='1';

			++i;
		}
		str[no+i]='1';
		str[no+i-left]='0';
	}

	std::cout<<str<<std::endl;

	return 0;
}