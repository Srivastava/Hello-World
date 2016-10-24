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
	
	std::string str;
	std::cin>>str;

	// std::cout<<str<<std::endl;
	ll n=0;
	for(int i=0;i<str.size()-1;++i)
	{
		n=n*10+(str[i]-'0');
	}
	char c=str[str.size()-1];

	ll m=n;
	if(m%2==0){m=m-1;}

	int atten=0;

	if((m-1)%4==0){atten=1;}
	else{atten=2;}

	ll time=0;
	if(atten==1)
	{
		time=((m-1)/2)*6;
		if(n%2==0){time+=6;}

		if(n%2==0){time+=n-1;}
		else
		{
			time+=n-1;
		}
	}
	else
	{
		time=((m-3)/2)*6;
		if(n%2==0){time+=6;}

		if(n%2==0){time+=n-3;}
		else
		{
			time+=n-3;
		}
	}
	
	if(c=='a')
	{
		time+=4;
	}
	else if(c=='b')
	{
		time+=5;
	}
	else if(c=='c')
	{
		time+=6;
	}
	else if(c=='d')
	{
		time+=3;
	}
	else if(c=='e')
	{
		time+=2;
	}
	else if(c=='f')
	{
		time+=1;
	}

	std::cout<<time<<std::endl;

	return 0;
}