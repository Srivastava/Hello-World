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


int f(vi& d,vi& a,int mid)
{
	int n=d.size(),m=a.size();
	vi mark(m,0),cnt(2e5,0);

	// std::cout<<n<<" "<<m<<" "<<mid<<std::endl;
	vi temp=d;
	for(int i=mid-1;i>=0;--i)
	{
		// std::cout<<i<<" "<<temp[i]<<std::endl;
		if(temp[i]==0){continue;}
		if(cnt[temp[i]]){temp[i]=0;}
		cnt[temp[i]]++;
	}

	int ex=0;
	for(int i=0;i<mid;++i)
	{
		// std::cout<<i<<" "<<temp[i]<<" *"<<std::endl;
		if(temp[i]==0){++ex;}
		else
		{
			int need=a[temp[i]-1];
			// std::cout<<ex<<" "<<need<<" need"<<std::endl;
			if(ex<need){return 0;}
			ex-=need;
			mark[temp[i]-1]=1;
		}
	}

	for(int i=0;i<m;++i)
	{
		if(!mark[i]){return 0;}
	}
	return 1;
}

int binaryS(vi& d,vi& a,int l,int r)
{
	// std::cout<<"*********** "<<l<<" "<<r<<std::endl;
	if(l>r){return -1;}
	if(l==r)
	{
		if(f(d,a,l)){return l;}
		return -1;
	}
	if(l+1==r)
	{
		if(f(d,a,l)){return l;}
		if(f(d,a,r)){return r;}
		return -1;
	}

	int mid=(l+r)/2;

	if(f(d,a,mid)){return binaryS(d,a,l,mid);}
	return binaryS(d,a,mid+1,r);

}


int main()
{
	int n,m;
	std::cin>>n>>m;

	vi d(n,0);
	for(int i=0;i<n;++i)
	{
		std::cin>>d[i];
	}

	vi a(m,0);
	ll sum=0;
	for(int i=0;i<m;++i)
	{
		std::cin>>a[i];
		sum+=a[i];
	}

	std::cout<<binaryS(d,a,sum+m,n)<<std::endl;

	return 0;
}