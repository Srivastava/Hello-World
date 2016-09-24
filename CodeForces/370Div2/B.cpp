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
	/*std::unordered_map<char,std::pair<int,int> > map;

	map['L']=std::pair<int,int>(-1,0);
	map['R']=std::pair<int,int>(1,0);
	map['U']=std::pair<int,int>(0,1);
	map['D']=std::pair<int,int>(0,-1);*/

	std::string str;
	std::cin>>str;

	if(str.size()%2!=0){std::cout<<-1<<std::endl;return 0;}

	int hor=0,ver=0;
	for(int i=0;i<str.size();++i)
	{
		char c=str[i];
		
		if(c=='L'){hor--;}
		if(c=='R'){hor++;}
		if(c=='U'){ver--;}
		if(c=='D'){ver++;}
	}

	std::cout<<(std::abs(hor)+std::abs(ver))/2<<std::endl;

	/*int ind=0;

	std::pair<int,int> cnt(0,0);
	for(int i=0;i<str.size();++i)
	{
		char c=str[i];
		std::pair<int,int> coor=map[c];
		cnt.first+=coor.first;
		cnt.second+=coor.second;

		if(cnt.first==0 && cnt.second==0)
		{
			ind=i;
		}
	}

	// std::cout<<ind<<std::endl;
	if(ind==0){ind=-1;}
	int chag=str.size()-(ind+1);
	std::cout<<chag<<" "<<ind<<std::endl;
	std::cout<<chag/2<<std::endl;*/

	return 0;
}