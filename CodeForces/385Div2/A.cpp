#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <set>

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
	std::cin>>str;

	int len=str.size();
	str+=str;

	std::set<std::string> s;


	for(int i=0;i<str.size()-len;++i)
	{
		s.insert(str.substr(i,len));
	}

	// for(auto it=s.begin();it!=s.end();++it)
	// {
	// 	std::cout<<*it<<std::endl;
	// }
	std::cout<<s.size()<<std::endl;;

	return 0;
}