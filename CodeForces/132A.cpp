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

vi binary(int a,int& val)
{
	val=0;
	vi temp(8,0);
	// std::cout<<a<<" ";
	int i=0;
	do
	{
		temp[i]=(a%2);
		++i;
	}
	while(a/=2);


	std::reverse(temp.begin(),temp.end());
	
	for(int i=0;i<temp.size();++i)
	{
		val+=temp[i]*std::pow(2,i);
	}
	// std::cout<<val<<" ** "<<std::endl;
	return temp;
}

int main()
{
	/*vi b = binary(64);

	std::copy(b.begin(),b.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;
*/
	std::string str;
	std::getline(std::cin,str);
	// std::cin>>str;

	int prev=0;
	for(int i=0;i<str.size();++i)
	{
		int a = str[i];
		int revVal=0;

		vi b = binary(a,revVal);

		int ith = (prev - revVal + 256)%256;

		// if(ith<0){ith=256+ith;}
		// std::cout<<a<<" "<<prev<<" "<<ith<<" "<<revVal<<" "<<str[i]<<std::endl;

		// b = binary(ith,prev);
		// prev=238;
		std::cout<<ith<<std::endl;
		prev=revVal;
	}

	return 0;
}