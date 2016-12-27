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
	int n,g,b,k;
	std::cin>>n>>k>>g>>b;

	bool gbig= g>b ? true:false;
	bool bbig= b>g ? true:false;

	if(g==b)
	{
		std::string str="GB";
		std::string ans="";
		for(int i=0;i<n/2;++i)
		{
			ans+=str;
		}
		std::cout<<ans<<std::endl;
		return 0;
	}

	if(bbig)
	{
		int i=0;
		for(i=1;i<1e6;++i)
		{
			if(b-k*i<g){break;}
		}

		if(b-k*i<0)
		{
			std::cout<<"NO"<<std::endl;
			return 0;
		}
		else
		{
			std::cout<<"here fk "<<i<<std::endl;
			std::string green(g-(b-k*i),'G'),black(k,'B');
			std::cout<<"here"<<std::endl;
			std::cout<<green.size()<<" *"<<std::endl;
			std::cout<<b-k*i<<" "<<g-green.size()*i<<std::endl; 
			std::string combi=std::string(b-k*i,'B')+std::string(g-green.size()*i,'G');
			std::string ans="";

			for(int j=0;j<i;++j)
			{
				ans+=black+green;
			}
			// std::cout<<i<<" "<<val<<" "<<g<<" "<<b<<std::endl;
			// std::cout<<g-k*i<<std::endl;
			// if(g-k*i >0){
			// 	ans+=green;
			// }
			std::cout<<ans<<std::endl;
			for(int j=0;j<b-k*i;++j)
			{
				ans+=combi;
			}
			std::cout<<ans<<std::endl;
			return 0;


		}
	}
	else
	{
		// std::cout<<"here"<<std::endl;
		int i=0;
		for(i=1;i<1e6;++i)
		{
			if(g-k*i<b){break;}
		}
		// std::cout<<"here 1"<<std::endl;
		if(g-k*i<0)
		{
			std::cout<<"NO"<<std::endl;
			return 0;
		}
		else
		{
			// int val=std::min(b-(g-k*i),g-k*i);
			std::string black(b-(g-k*i),'B'),green(k,'G');

			std::string combi=std::string(g-k*i,'G')+std::string(b-black.size()*i,'B');
			std::string ans="";

			for(int j=0;j<i;++j)
			{
				ans+=green+black;
			}
			// std::cout<<i<<" "<<val<<" "<<g<<" "<<b<<std::endl;
			// std::cout<<g-k*i<<std::endl;
			// if(g-k*i >0){
			// 	ans+=green;
			// }
			std::cout<<ans<<std::endl;
			for(int j=0;j<g-k*i;++j)
			{
				ans+=combi;
			}
			std::cout<<ans<<std::endl;
			return 0;

		}
	}
	return 0;
}