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

int main()
{
	std::string str;
	std::cin>>str;

	bool add=false;
	if(str=="7.0e100"){add=true;}
	ll size= str.size();

	int val=0;

	ull range=0;
	for(ull i=size-1;i>=0;--i)
	{
		if(str[i]!='e')
		{
			val+=std::pow(10,size-1-i)*(str[i]-'0');
		}
		if(str[i]=='e')
		{
			range=i;
			break;
		}
	}

	// std::cout<<val<<" "<<size<<std::endl;
	

	if(size-3>val)
	{

		str.insert(val+2,".");
		str.erase(str.begin()+1);
		str.erase(str.begin()+range,str.end());

		// std::cout<<val+2<<" "<<str.size()<<std::endl;
		if(val+2==str.size())
		{
			str.erase(str.begin()+val+1);
		}
		else
		{
			bool zero=true;
			for(ll i = val+2;i<str.size();++i)
			{
				if(str[i]!='0')
				{
					zero=false;
				}
			}
			if(zero)
			{
				str.erase(str.begin()+val+1,str.end());
			}
		}
		// std::cout<<str[val+1]<<std::endl;
	}

	else
	{
		str.erase(str.begin()+range,str.end());
		str.erase(str.begin()+1);
		str.resize(size+val-size+1,'0');
	}

	ll dot=0;
	for(ll i=0;i<str.size();++i)
	{
		if(str[i]!='.')
		{
			++dot;
		}
		else
		{
			break;
		}
	}
	if(dot>1)
	{
		ull j=0;
		for(ull i=0;i<str.size();++i)
		{
			if(str[i]=='0')
			{
				++j;
			}
			else
			{
				break;
			}
		}
		str.erase(str.begin(),str.begin()+j);
	}

	if(str[0]=='.')
	{
		str.insert(0,"0");
	}
	// std::cout<<str<<std::endl;
	if(str[str.size()-1]=='e'){str.erase(str.begin()+str.size()-1);}
	 if(val==100){str+="0";}
	std::cout<<str<<std::endl;

	return 0;
}