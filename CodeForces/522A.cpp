#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <unordered_map>

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


/*ll solve(vvll& graph)
{
	vb visited(graph.size(),false);

	ll h=0;

	while(1)
	{
		++h;

		for(ll i=1;i<graph.size();++i)
		{
			for(ll j=1;j<graph[i])
		}
	}
}
*/
int main()
{
	ll n;
	std::cin>>n;

	// std::cout<<n<<std::endl;

	std::vector<std::string> vstr;
	vstr.reserve(n);

	// std::string req("reposted");

	std::unordered_map<std::string,ll> map;

	// map.insert({"polycarp",1});

	// vvll graph(2*n+1,vll(1,0));

	ll x=0;
	
	// std::string str;
	

	for(int i=1;i<=n;++i)
	{
	
		// std::cin>>str;
		std::string str,str1,str2;
		std::cin>>str>>str1>>str2;

		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

		map[str]=map[str2]+1;

		x=std::max(x,map[str]);

		// std::cout<<str1<<" "<<str2<<std::endl;

	}

	std::cout<<x+1<<std::endl;
	
	return 0;
}