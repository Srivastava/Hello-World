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


int GCD(int a,int b)
{
	return b==0 ? a : GCD(b,a%b);
}

std::pair<int,int> extendedGCD(int a, int b)
{
	if(a%b==0)
	{
		return {0,1};
	}
	else
	{
		std::pair<int,int> p=extendedGCD(b,a%b);
		return {p.second,p.first-(p.second*(a/b))};
	}
}

int main()
{
	// std::cout<<GCD(6,2)<<std::endl;
	int n,p,q;
	std::cin>>n>>p>>q;

	int gcd=GCD(p,q);

	bool div=true;
	if(n%gcd!=0){div=false;}




	std::string str;
	std::cin>>str;

	if(n%p==0 || n%q == 0 || n%(p+q) == 0 || div)
	{
		std::vector<std::string> ans;

		if(n%p==0)
		{
			for(int i=0;i<n;i+=p)
			{
				std::string temp=str.substr(i,p);
				ans.push_back(temp);
			}
		}
		else if(n%q==0)
		{

			for(int i=0;i<n;i+=q)
			{
				std::string temp=str.substr(i,q);
				ans.push_back(temp);
			}
		}
		else if(n%(p+q)==0)
		{
			for(int i=0;i<n;i+=p+q)
			{
				std::string temp=str.substr(i,p);
				std::string temp1=str.substr(i+p,q);
				ans.push_back(temp);
				ans.push_back(temp1);
			}
		}
		else if(div)
		{
			int x=1e7,y=1e7;
			for(int i=1;i<=n/p;++i)
			{
				if((n-p*i)%q==0)
				{
					y=(n-p*i)/q;
					x=i;
				}
			}
			
			// std::cout<<x<<" "<<y<<std::endl;
			if(x==1e7 || y==1e7)
			{
				std::cout<<-1<<std::endl;
				return 0;
			}
			for(int i=0;i<p*x;i+=p)
			{
				std::string temp=str.substr(i,p);
				// std::cout<<temp<<" * "<<std::endl;
				ans.push_back(temp);
				
			}
			for(int i=p*x;i<p*x+q*y;i+=q)
			{
				std::string temp=str.substr(i,q);
				// std::cout<<temp<<" ** "<<q<<std::endl;
				ans.push_back(temp);
				
			}

			
		}

		std::cout<<ans.size()<<std::endl;
		for(int i=0;i<ans.size();++i)
		{
			std::cout<<ans[i]<<std::endl;
		}
	}
	else
	{
		std::cout<<-1<<std::endl;
	}

	return 0;
}