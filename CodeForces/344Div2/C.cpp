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


int main()
{
	int n,m;
	std::cin>>n>>m;

	// scanf("%d %d",&n,&m);
	vll a(n,0);

	std::cout<<n<<" "<<m<<std::endl;
	for(int i=0;i<n;++i)
	{
		std::cin>>a[i];

	}

	std::unordered_map<ll,ll> vi,iv,ori;
	int j=2e7;

	for(int i=0;i<m;++i)
	{
		int t,r;
		// std::cin>>t>>r;
		scanf("%d%d",&t,&r);
		r--;

		auto it=vi.find(r);
		if(it!=vi.end())
		{
			j=std::min(j,i);
		}
		vi[r]=i;
		ori[r]=t;
		iv[i]=r;

		std::cout<<i<<" -> "<<r<<std::endl;
	}
	if(j==2e7){j=0;}

	std::vector<int> temp;
	temp.reserve(n);

	for(auto it=vi.begin();it!=vi.end();++it)
	{
		temp.push_back(it->second);
	}
	std::sort(temp.begin(),temp.end());

	// std::cout<<"-----------"<<std::endl;
	for(int i=0;i<temp.size();++i)
	{
		int val=iv[temp[i]];
		int t=ori[val];
		if(t==1){
			std::sort(a.begin(),a.begin()+val+1);
		}
		else{
			std::sort(a.begin(),a.begin()+val+1,std::greater<ll>());
		}
		// std::cout<<val<<" "<<vi[val]<<" "<<i<<std::endl;
		/*if(vi[val]<=i)
		{
			int t=ori[val];
			// int p=vi[val];
			if(t==1)
				std::sort(a.begin(),a.begin()+val+1);
			else
				std::sort(a.begin(),a.begin()+val+1,std::greater<ll>());
			// std::copy(a.begin(),a.end(),std::ostream_iterator<ll>(std::cout," "));
			// std::cout<<" ----------- "<<std::endl;
		}*/
	}

	for(int i=0;i<n;++i)
	{
		printf("%I64",a[i]);
	}
	// std::copy(a.begin(),a.end(),std::ostream_iterator<ll>(std::cout," "));
	// std::cout<<std::endl;
	return 0;
}