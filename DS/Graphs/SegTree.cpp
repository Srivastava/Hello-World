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

vi s(100,0);
vi a(100,0);
int n;

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){	//	l + 1 == r
		s[id] = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s[id] = s[id * 2] + s[id * 2 + 1];
}

void modify(int p,int x,int id=1,int l=0,int r=n)
{
	s[id]+=x-a[p];

	if(r-l<2)
	{
		a[p]+=x;
		return;
	}

	int mid = (l+r)/2;
	if(p<mid)
	{
		modify(p,x,id*2,l,mid);
	}
	else
	{
		modify(p,x,id*2+1,mid,r);
	}
}

int sum(int x,int y,int id=1,int l=0,int r=n)
{
	if(x>=r || l>=y){return 0;}
	if(x<=l && r<=y){return s[id];}

	int mid=(l+r)/2;

	return sum(x,y,id*2,l,mid) + sum(x,y,id*2+1,mid,r);

}

/*int sum(int x,int y,int id = 1,int l = 0,int r = n){
	if(x >= r or l >= y)	return 0;
	if(x <= l && r <= y)	return s[id];
	int mid = (l+r)/2;
	return sum(x, y, id * 2, l, mid) +
	       sum(x, y, id * 2 + 1, mid, r);
}*/

int main()
{
	// int n;
	std::cin>>n;

	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];
	}

	build();

	// std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));
	// std::cout<<std::endl;

	std::copy(s.begin(),s.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;

	int t;
	std::cin>>t;

	while(t--)
	{
		int u,v;
		std::cin>>u>>v;
		std::cout<<sum(u,v)<<std::endl;
	}

	return 0;
}