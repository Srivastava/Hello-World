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


// ll n;
vll p(1000,0);
vll g(1000,0);

// vvll a(1000,vll(1000,0));

ll find(ll i)
{
	if(i==g[i]) return i;
	
	return g[i]=find(g[i]);
}

void un(ll i , ll j)
{
	i = find(i);
	j = find(j);

	if(i!=j)
	{
		g[i]=j;
	}
}

int main()
{
	
	ll n;
	std::cin>>n;

	for(ll i=1;i<=n;++i){g[i]=i;}

	for(ll i=1;i<=n;++i)
	{
		std::cin>>p[i];
	}

	for(ll i=1;i<=n;++i)
	{
		std::string str;
		std::cin>>str;

		for(int j=0;j<n;++j)
		{
			if(str[j]-'0')
			{
				un(i,j+1);
			}
		}
	}

	for(int i=1;i<=n;++i)
	{
		vi s,d;

		for(int j=1;j<=n;++j)
		{
			if(find(j)==find(i))
			{
				s.push_back(p[j]);
				d.push_back(j);
			}
		}

		std::sort(s.begin(),s.end());

		for(int j=0;j<d.size();++j)
		{
			p[d[j]]=s[j];
		}
	}

	std::copy(p.begin()+1,p.begin()+n+1,std::ostream_iterator<ll>(std::cout," "));
	std::cout<<std::endl;
	/*vi pos[1000];


	for(ll i=1;i<=n;++i)
	{
		pos[find(i)].push_back(p[i]);
	}

	for(int i=1;i<=n;++i)
	{
		std::sort(pos[i].begin(),pos[i].end());
	}
*/
	// for(int i=1;i<=n;++i)
	// {
	// 	int m=find(i);
	// 	std::copy(pos[m].begin(),pos[m].end(),std::ostream_iterator<ll>(std::cout," "));
	// 	std::cout<<std::endl;
	// }

	// std::copy(ans.begin()+1,ans.end(),std::ostream_iterator<ll>(std::cout," "));
	// std::cout<<std::endl;

	return 0;
}