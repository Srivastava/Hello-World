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
	// ll a, b;

	std::cin.sync_with_stdio(0);
	// scanf("%I64d %I64d",&a,&b);
	// std::cin>>a>>b;

	std::string a,b;
	std::cin>>a>>b;

	int j=-1;
	for(int i=0;i<a.size();++i)
	{
		if(a[i]!='0'){j=i;break;}
		if(a[i]=='0'){j=i;}
	}
	
	if(j!=-1)
		a.erase(0,j);

	j=-1;
	for(int i=0;i<b.size();++i)
	{
		if(b[i]!='0'){j=i;break;}
		if(b[i]=='0'){j=i;}
	}	
	// std::cout<<j<<std::endl;	
	if(j!=-1)
		b.erase(0,j);

	/*std::cout<<a<<std::endl;
	std::cout<<b<<std::endl;*/

	if(a.size()>b.size()){std::cout<<">"<<std::endl;}
	else if(b.size()>a.size()){std::cout<<"<"<<std::endl;}
	else
	{
		bool ais=false,bis=false;
		for(int i=0;i<a.size();++i)
		{
			if(a[i]>b[i]){ais=true;break;}
			else if(b[i]>a[i]){bis=true;break;}
		}
		if(ais){std::cout<<">"<<std::endl;}
		else if(bis){std::cout<<"<"<<std::endl;}
		else
		{
			std::cout<<"="<<std::endl;
		}
	}

	// if(a>b){/*printf("%c\n",'>');*/std::cout<<">"<<std::endl;}
	// if(a==b){printf("%c\n",'=');std::cout<<"="<<std::endl;}
	// if(a<b){/*printf("%c\n",'<');*/std::cout<<"<"<<std::endl;}
	// printf("%I64d %I64d\n",a,b );
	// std::cout<<a<<" "<<b<<std::endl;
	return 0;
}