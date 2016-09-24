#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <stack>

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
std::string str;
int n;
int s[120005];

int combine(int a, int b, int l, int r)
{
	// std::cout<<a<<" "<<b<<" "<<l<<" "<<r<<std::endl;
	if(a==1 && b==1){return 1;}
	else if(a==0 && b==1){return 0;}
	else if(a==1 && b==0){return 0;}
	else if(a==0 && b==0)
	{
		std::stack<char> st;
		st.push(str[l]);

		if(str[l]==')'){return 0;}

		for(int i=l+1;i<r;++i)
		{
			if(i==n){continue;}
			char c=str[i];
			char t=st.top();

			if(c==')' && t =='(')
			{
				st.pop();
			}
			else
			{
				st.push(c);
			}
		}

		if(st.empty()){return 1;}
		else{return 0;}
	}
}

void build(int id=1,int l=0,int r=n)
{
	if(r-l<2){s[id]=0;}

	else
	{
		int mid = (l+r)/2;
		
		build(id*2,l,mid);
		build(id*2+1,mid,r);

		// std::cout<<"build "<<id<<std::endl;
		s[id]=combine(s[id*2],s[id*2+1],l,r);		
	}
}

void replace(int p,int id=1,int l=0,int r=n)
{
	int mid=(l+r)/2;

	if(r-l<2)
	{
		// if(str[p]=='('
		str[p]=str[p]=='(' ? ')' : '(';
		s[id]=0;
		return;
	}
	if(p<mid)
	{
		replace(p,id*2,l,mid);
	}
	else
	{
		replace(p,id*2+1,mid,r);
	}
	s[id]=combine(s[id*2],s[id*2+1],l,r);
}


int main()
{
	// int n;
	for(int i=1;i<=10;++i)
	{
		
		std::cin>>n;

		std::cin>>str;

		int t;
		std::cin>>t;

		build();
		std::cout<<"TEST "<<i<<":"<<std::endl;
		/*for(int i=0;i<4*n;++i)
		{
			std::cout<<s[i]<<",";
		}
		std::cout<<std::endl;*/
		while(t--)
		{

			int u;
			std::cin>>u;

			if(u==0)
			{
				if(s[1]){std::cout<<"YES"<<std::endl;}
				else{std::cout<<"NO"<<std::endl;}
				// std::cout<<s[1]<<std::endl;
			}
			else
			{
				replace(u-1);
			}

		}
	}
	return 0;
}