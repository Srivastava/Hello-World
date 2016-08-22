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
	// int n;
	// std::cin>>n;

	std::string str;
	std::cin>>str;

	int m;
	std::cin>>m;

	for(int i=0;i<m;++i)
	{
		int u,v,n;
		std::cin>>u>>v>>n;

		u--;
		v--;

		std::string str1=str.substr(u,v-u+1);

		n=n%(v-u+1);
		// std::cout<<str1<<std::endl;
		while(n--)
		{
			char c = str1[str1.size()-1];
			str1.erase(str1.begin()+str1.size()-1);
			str1=c+str1;
		}
		// std::cout<<str1<<std::endl;
		str.replace(u,v-u+1,str1);
	}
	std::cout<<str<<std::endl;
	return 0;
}