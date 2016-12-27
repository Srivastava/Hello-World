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
	int n;
	std::string str;
	std::cin>>n>>str;

	std::string odd="",even="";

	for(int i=0;i<str.size();i+=2)
	{
		odd+=str[i];
	}

	for(int i=1;i<str.size();i+=2)
	{
		even+=str[i];
	}

	if(n%2==0){
		std::reverse(odd.begin(),odd.end());
		std::cout<<odd+even<<std::endl;
	}
	else{
		std::reverse(even.begin(),even.end());
		std::cout<<even+odd<<std::endl;
	}
	
	return 0;
}