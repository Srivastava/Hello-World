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
	// std::cin>>str;

	// std::cin.ignore(1, '\n');
	/*std::cin.clear();
    std::cin.sync();*/

	std::getline(std::cin,str);
	// std::cout<<str<<" string "<<std::endl;
	bool num=true;

	std::vector<std::string> a,b;
	int left=0;
	for(int i=0;i<str.size();++i)
	{
		char c =str[i];

		if((c<'0' || c > '9') )
		{
			// std::cout<<c<<std::endl;
			if(c==',' || c==';')
			{
				// num=false;
			}
			else
			{
				num=false;
			}
		}
		if(i==0 &&(c==',' || c==';') ){b.push_back("");}
		// std::cout<<num<<" "<<i<<std::endl;
		if(c==',' || c==';' || i==str.size()-1)
		{
			std::string temp;
			// if((c==',' || c==';') && (i==temp.size()-1|| i==0 )){temp="";b.push_back(temp);break;}
			if(i==str.size()-1){i++;}
			
			if(i==left){temp="";num=false;}
			else if(i!=left)
			{
				
				temp=str.substr(left,i-left);
			}
			if(temp[0]=='0' && temp.size()>1){num=false;}
			if(temp[0]==';' || temp.size()==0){temp="";num=false;}
			if(num==true)
			{
				a.push_back(temp);
			}
			else if(num==false)
			{
				b.push_back(temp);
			}
			left=i+1;
			num=true;
		}

	}

	if(a.size()==0)
	{
		std::cout<<"-"<<std::endl;
	}
	else
	{
		std::cout<<"\"";
		for(int i=0;i<a.size();++i)
		{
			if(i==a.size()-1)
			{
				std::cout<<a[i];
			}
			else
			{
				
				std::cout<<a[i]<<",";
			}
		}
		std::cout<<"\"";
		std::cout<<std::endl;
	}

	if(b.size()==0)
	{
		std::cout<<"-"<<std::endl;
	}
	else
	{
		std::cout<<"\"";
		for(int i=0;i<b.size();++i)
		{
			if(i==b.size()-1)
			{
				std::cout<<b[i];
			}
			else
			{
				
				std::cout<<b[i]<<",";
			}
		}
		std::cout<<"\"";
		std::cout<<std::endl;
	}
	return 0;
}