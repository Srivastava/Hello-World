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


bool pred(vll& s, ll mid, ll k)
{
	bool ans=true;

	ll count=0,num=0;
	while(num<s.size()-2)
	{
		if(count==k){break;}
		if(s[num]+s[num+1] > mid)
		{
			// std::cout<<num<<" **** "<<s.size()-1<<std::endl;
			ans=false;
			break;
		}
		++num;
		++count;
	}

	if(s.size()==2){if(s[0]+s[1]>mid){ans=false;}}
	return ans;
}

ll solve(vll& s, ll a,ll b, ll k)
{
	while(b>a)
	{
		// std::cout<<b<<" "<<a<<std::endl;
		ll mid = a+(b-a)/2;
		// std::cout<<mid<<std::endl;
		if(pred(s,mid,k))
		{
			b=mid;
		}
		else
		{
			a=mid+1;
		}
	}

	return a;
}


int main()
{
	ll n,k;
	std::cin>>n>>k;

	vll s(n,0);
	for(int i=0;i<n;++i)
	{
		std::cin>>s[i];
	}

	// std::copy(s.begin(),s.end(),std::ostream_iterator<ll>(std::cout,"*"));
	// std::cout<<std::endl;
	if(n==k){std::cout<<s[n-1]<<std::endl;return 0;}

	int leave=std::abs(n-(2*k));
	ll max=s[n-1];
	for(int i=0;i<n-k;++i)
	{
		max=std::max(max,s[i]+s[2*(n-k)-i-1]);
	}
	std::cout<<max<<std::endl;
	// std::cout<<solve(s,s[n-1],s[n-1]+s[n-2]+1,k)<<std::endl;

	return 0;
}