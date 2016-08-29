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

std::set<std::string> set;
int dp[10005][2];
void solve(std::string str,std::string prev,int i)
{
	// std::cout<<str<<" "<<prev<<i<<std::endl;
	int ind=prev.size()==2 ? 0:1;

	if(dp[i][ind]!=0)
	{
		return;
	}

	dp[i][ind]=1;
	if(i<=5){return;}
	if(i-2>=5)
	{
		std::string two=str.substr(i-2,2);
		// std::cout<<two<<std::endl;
		if(two!=prev)
		{
			set.insert(two);
			solve(str,two,i-2);
		}
			
	}
	if(i-3>=5)
	{

		std::string three=str.substr(i-3,3);
		if(three!=prev)
		{
			set.insert(three);
			solve(str,three,i-3);
		}
	}

}

int main()
{
	std::string str;
	std::cin>>str;

	if(str.size()<=5)
	{
		std::cout<<0<<std::endl;
		return 0;
	}



	std::string prev="";
	solve(str,prev,str.size());

	std::cout<<set.size()<<std::endl;

	for (auto it = set.begin(); it != set.end(); ++it)
	{
	    std::cout << *it << "\n";
	}
		
	return 0;
}