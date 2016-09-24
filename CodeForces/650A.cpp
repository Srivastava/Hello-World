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
#include <set>
#include <map>

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<int,int> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;

/*bool sortx(const std::pair<pa,int>& a, const std::pair<pa,int>& b )
{
	pa p=a.first;
	pa q=b.first;

	return p.first < q.first;
}

bool sorty(const std::pair<pa,int>& a, const std::pair<pa,int>& b )
{
	pa p=a.first;
	pa q=b.first;

	return p.second < q.second;
}
*/
bool sortx(const pa& p,const pa& q)
{
	return p.first < q.first;
}

bool sorty(const pa& p,const pa& q)
{
	return p.second < q.second;
}

int main()
{
	int n;
	std::cin>>n;

	// std::vector<std::pair<pa,int> > md;
	vpa md;
	md.reserve(n);

	std::unordered_map<int,int> a,b;
	// std::unordered_map<std::pair<int,int>,int> dup;

	std::map<pa,int> dup;

	std::set<pa> s;

	vb visit(n,false);

	ll ans=0;
	for(int i=0;i<n;++i)
	{
		int x,y;
		std::cin>>x>>y;
		a[x]++;
		b[y]++;

		// pa test({x,y});

		dup[{x,y}]++;
		
		// dup[std::make_pair(x,y)]++;
	}

	
	
	for(auto it=a.begin();it!=a.end();++it)
	{
		ll k=it->second;
		ans+=(k*(k-1))/2;
	}

	for(auto it=b.begin();it!=b.end();++it)
	{
		ll k=it->second;
		ans+=(k*(k-1))/2;
	}

	for(auto k:dup)
	{
		ll j=k.second;
		
		if(j>1){ans-=(j*(j-1))/2;}
	}
	std::cout<<ans<<std::endl;
	return 0;
}