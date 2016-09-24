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

int n;
int a[50010];
// vi a(50001,0);
// vll s(4*50001,0);


struct data
{
	ll sum,pref,suff,ans;
};

data s[200000];

data combine(data l,data r)
{
	data res;

	res.sum=l.sum+r.sum;
	res.pref=std::max(l.pref,l.sum+r.pref);
	res.suff = std::max(r.suff,r.sum+l.suff);
	res.ans=std::max(std::max(l.ans,r.ans),l.suff+r.pref);

	return res;
}

data make_data(ll val)
{
	data res;
	res.sum=val;
	res.pref=res.suff=res.ans=std::max(-1000000000LL,val);
	return res;
}

data build(int id,int l,int r)
{
	if(l==r)
	{
		s[id]= make_data(a[l]);
	}
	else
	{
		int mid = (l+r)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);

		s[id]=combine(s[id*2],s[id*2+1]);
	}

}

data query(int x,int y,int id,int l,int r)
{
	if(x==l && y==r){return s[id];}

	int mid=(l+r)/2;

	if(x>mid)
	{
		return query(x,y,id*2+1,mid+1,r);
	}
	if(y<=mid)
	{
		return query(x,y,id*2,l,mid);
	}

	return combine(query(x,mid,id*2,l,mid),query(mid+1,y,id*2+1,mid+1,r));
}

/*
void build(int id=1,int l=0,int r=n)
{
	if(r-l<2)
	{
		s[id]=a[l];
		// std::cout<<a[l]<<std::endl;
		return;
	}

	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid,r);

	s[id]=s[id*2]+s[id*2+1];
	// s[id] = std::max(s[id * 2] + s[id * 2 + 1],std::max(s[id*2],s[id*2+1]));
}

ll sum(int x,int y,int id=1,int l=0,int r=n)
{
	if(x>=r || l>=y){return 0;}
	if(x<=l && r<=y){return s[id];}

	int mid=(l+r)/2;

	return std::max(sum(x,y,id*2,l,mid) + sum(x,y,id*2+1,mid,r),std::max(sum(x,y,id*2,l,mid),sum(x,y,id*2+1,mid,r)));

}
*/
int main()
{
	
	// std::cin>>n;

	scanf("%d",&n);
	// std::cout<<n<<std::endl;
	for(int i=0;i<n;++i)
	{
		// std::cin>>a[i];
		scanf("%d",&a[i+1]);
		// std::cout<<a[i]<<std::endl;
	}

	build(1,1,n+1);
	int m;
	scanf("%d",&m);
	// std::cout<<m<<" m "<<std::endl;
	// std::cin>>m;
/*
	for(int i=0;i<4*n;++i)
	{
		std::cout<<s[i].ans<<",";
	}
	std::cout<<std::endl;*/

	for(int i=0;i<m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		// std::cin>>u>>v;

		printf("%lld\n",query(u,v,1,1,n+1).ans);
		// std::cout<<sum(u,v)<<std::endl;
	}
	return 0;
}