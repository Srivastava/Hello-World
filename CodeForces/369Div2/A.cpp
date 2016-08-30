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
	int n;
	std::cin>>n;
	std::vector<std::string> tstr;

	int x=0,y=0;
	bool seats=false;
	std::string f="OO";
	for(int i=0;i<n;++i)
	{
		std::string temp;
		std::getline(std::cin,temp);

		
		if(temp.size()==0){--i;continue;}
		
		std::size_t found = temp.find(f);
		//
		if (found!=std::string::npos)
		{
			x=i;y=found;
			seats=true;
		}
		tstr.push_back(temp);
	}

	
	if(seats)
	{
		tstr[x][y]='+';
		tstr[x][y+1]='+';

		std::cout<<"YES"<<std::endl;
		for(int i=0;i<n;++i)
		{
			std::cout<<tstr[i]<<std::endl;
		}
	}
	else
	{
		std::cout<<"NO"<<std::endl;
		
	}
	return 0;
}