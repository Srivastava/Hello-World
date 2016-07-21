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

typedef std::string str;


int main()
{
	str a,b;

	std::cin>>a>>b;

	str c;

	bool test=true;
	// for(int i=0;i<a.size();++i)
	// {
	// 	int m=a[i]-'0',n=b[i]-'0';

	// 	if(m&n)
	// 	{

	// 		c.push_back(1+'0');
	// 	}
	// 	else
	// 	{
	// 		c.push_back(0+'0');
	// 	}
	// 	// if(c[i]!=b[i] && c[i]!=a[i]){test=false;}
	// 	// std::cout<<c[i]<<std::endl;
	// }
	// std::cout<<c<<std::endl;
	// if(a.size()==1){test=false;}
	// if(test){std::cout<<"YES"<<std::endl;}
	// else{std::cout<<"NO"<<std::endl;}



	// for(int i=0;i<a.size();i+=2)
	// {
	// 	int m=a[i]-'0',n=a[i+1]-'0';
	// 	if(m||n)
	// 	{
	// 		int p=b[i]-'0',q=b[i+1]-'0';

	// 		if(!(p||q))
	// 		{
	// 			test=false;
	// 			break;
	// 		}
	// 	}

	// 	else
	// 	{
	// 		int p=b[i]-'0',q=b[i+1]-'0';

	// 		if((p||q))
	// 		{
	// 			test=false;
	// 			break;
	// 		}
	// 	}

	// }
	
	// bool result;
	test=false;bool testB=false;

	if(a.size()==b.size())
	{
		for(int i=0;i<a.size();++i)
		{
			if(a[i]!='0'){test=true;}
			if(b[i]!='0'){testB=true;}
		}
		
	}

	if(a.size()==1)
	{
		test=false;
	}
	if(a==b)
	{
		testB=true;
		test=true;
	}

	if(test && testB)
	{
		std::cout<<"YES"<<std::endl;
	}
	else
	{
		std::cout<<"NO"<<std::endl;
	}

	return 0;
}