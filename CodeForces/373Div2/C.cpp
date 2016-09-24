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
	ll n,t;
	std::cin>>n>>t;

	std::string str;
	std::cin>>str;

	int pt=-1;

	for(int i=0;i<n;++i)
	{
		if(str[i]=='.'){pt=i;break;}
	}

	if(pt==-1){std::cout<<str<<std::endl;return 0;}

	while(t--)
	{
		std::cout<<pt<<" "<<"here"<<std::endl;
		int ind=-1;
		for(int i=pt+1;i<n;++i)
		{
			int val=str[i]-'0';
			if(val>=5){ind=i;break;}
		}
		if(ind==-1){if(str[n-1]=='.'){str.erase(str.begin()+n-1);}std::cout<<str<<std::endl;return 0;}
		
		std::cout<<ind<<" index "<<std::endl;

		bool cy=false;
		int count=0;
		bool dot=false;
		char add='0';

		str[ind]='0';
		str.erase(str.begin()+ind);
		ind--;

		std::cout<<str<<" index next "<<std::endl;
		while(ind>0)
		{
			if(ind<0){break;}
			
			std::cout<<ind<<" index  1"<<std::endl;
			
			if(cy==false && count!=0){break;}

			if(str[ind]=='.'){ind--;}
			if(str[ind]=='9')
			{
				cy=true;
				str[ind]='0';
				// str.erase(str.begin()+ind);
				std::cout<<str<<" ** "<<std::endl;
				--ind;
			}
			else
			{

				cy=false;
				int val=str[ind]-'0';

				++val;
				str[ind]='0'+val;
				
				--ind;
			}
			++count;
		}

		n=str.size();
		if(cy){std::string tmp(1,'1');str=tmp+str;n=str.size();}


	}

	n=str.size();
	if(str[n-1]=='.'){str.erase(str.begin()+n-1);}

	std::cout<<str<<std::endl;


	return 0;
}