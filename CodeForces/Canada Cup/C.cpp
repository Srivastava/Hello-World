#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
// #include <unordered_map>

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


/*int main()
{
	std::string str;
	std::cin>>str;

	std::unordered_map<char,int> map;

	int ind=0;
	for(int i=0;i<str.size();++i)
	{
		if(i>0)
		{
			if(str[i]==str[i-1])
			{
				std::cout<<"Impossible"<<std::endl;
				return 0;
			}
		}
		map[str[i]]++;
		if(map[str[i]]>1){ind=i;}
	}

	// std::string str1,str2;
	if(ind<=13)
	{
		std::string str1=str.substr(0,ind)+str.substr(ind+1,13-ind);
		std::string str2=str.substr(14);

		std::reverse(str2.begin(),str2.end());
		std::cout<<str1<<"\n"<<str2<<std::endl;
	}

	else
	{
		std::string str1=str.substr(0,13);
		std::string str2=str.substr(13,ind-13)+str.substr(ind+1);

		std::reverse(str2.begin(),str2.end());
		
		std::cout<<str1<<"\n"<<str2<<std::endl;
	}
	
	return 0;
}*/

int main()
{
	std::string str;
	std::cin>>str;

	vi index(26,-1);

	int first=-1,second=-1;

	for(int i=0;i<str.size();++i)
	{
		int ind=str[i]-'A';

		if(index[ind]==-1)
		{
			index[ind]=i;
		}
		else
		{
			first=index[ind];
			second=i;
			index[ind]=i;

		}

	}

	std::vector<std::string> vstr;
	std::string temp(13,'A');
	// std::cout<<temp<<std::endl;
	vstr.push_back(temp);
	vstr.push_back(temp);

	// std::cout<<first<<" "<<second<<std::endl;
	if(second==first+1)
	{
		std::cout<<"Impossible"<<std::endl;
		return 0;
	}
	else
	{
		int n=second-first;

		std::string a,b,c,d;

		if(n%2)
		{
			a=str.substr(first,n/2+1);
			b=str.substr(first+n/2+1,n/2);
		}
		else
		{
			a=str.substr(first,n/2);
			b=str.substr(first+n/2,n/2);	
		}

		c=str.substr(second+1,str.size()-1-second) + str.substr(0,first);

		int sz=13-b.size();

		b+=c.substr(0,sz);
		a=c.substr(sz,c.size()-sz)+a;

		std::reverse(b.begin(),b.end());
		std::cout<<a<<std::endl;
		std::cout<<b<<std::endl;
	}

	// std::cout<<vstr[0]<<"\n"<<vstr[1]<<std::endl;
	return 0;
}