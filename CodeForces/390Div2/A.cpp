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



/*int main()
{
	int n;
	std::cin>>n;

	vi a(n,0);
	bool isZero=false;
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
		if(a[i]==0)
			isZero=true;
	}

	if(!isZero)
	{
		std::cout<<"YES"<<std::endl;
		for(int i=0;i<n;++i)
		{
			std::cout<<i+1<<" "<<i+1<<std::endl;
		}
		return 0;
	}
	else
	{

	}	
		
	return 0;
}*/

int main()
{
	int n;
	std::cin>>n;

	vi a(n,0);
	
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}

	int sum=0;
	int l=0,r=0;

	vpa ans;
	while(r<n)
	{
		sum+=a[r];
		if(sum==0 && a[r]!=0)
		{
			ans.push_back({l+1,r});
			sum=a[r];
			l=r;
		}
		++r;
	}
	if(sum==0 && r==n)
		std::cout<<"NO"<<std::endl;
	else
	{
		std::cout<<"YES"<<std::endl;
		ans.push_back({l+1,r});
		std::cout<<ans.size()<<std::endl;
		for(auto& i:ans)
		{
			std::cout<<i.first<<" "<<i.second<<std::endl;
		}
	}
	
	return 0;
}