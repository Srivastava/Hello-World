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

int main()
{
	ll n,m;
	std::cin>>n>>m;

	ll k=n*n;

	// std::unordered_map<std::pair<ll,ll>,bool> hmap,vmap;

	if(m==1)
	{
		ll x,y;
		std::cin>>x>>y;
		
		std::cout<<k-(std::abs(1-x)+std::abs(n-x)+std::abs(1-y)+std::abs(n-y))-1<<std::endl;
		return 0;
	}
	
	std::unordered_map<ll,ll> h,v;
	bool subx=false,suby=false;
	// // std::cout<<n<<m<<std::endl;
	for(ll it=0;it<m;++it)
	{
		ll x,y;
		std::cin>>x>>y;

		ll ans=2*n-1;
		// std::cout<<ans<<std::endl;

		auto p =h.find(x);
		if(p!=h.end())
		{
			ans-=n;
			subx=true;
		}

		p=v.find(y);
		if(p!=v.end())
		{
			ans-=n;
			suby=true;
		}
		// for(auto i=h.begin();i!=h.end();++i)
		// {
		// 	if(x==*i)
		// 	{
				
		// 		break;
		// 	}
		// }

		// std::cout<<ans<<std::endl;
		
		// for(auto i=v.begin();i!=v.end();++i)
		// {
		// 	if(y==*i)
		// 	{
		// 		ans-=n;
		// 		suby=true;
		// 		break;
		// 	}
		// }
		
		// std::cout<<ans<<std::endl;

		if(!subx && suby)
		{
			ans=ans-v.size()+1;
		}
		// std::cout<<ans<<std::endl;

		if(!suby && subx)
		{
			ans=ans-h.size()+1;
		}
		// std::cout<<ans<<std::endl;

		if(!subx)
		{	
			h.insert(std::make_pair(x,0LL));
		}


		if(!suby)
		{	
			v.insert(std::make_pair(y,0LL));
		}


		if((!subx&&!suby) && it>0)
		{
			// std::cout<<h.size()-1<<" *** "<<v.size()-1<<std::endl;
			ans=ans-h.size()-v.size()+2;
		}

		subx=false,suby=false;
		// std::cout<<ans<<std::endl;
		if(ans<0){ans=0;}
		k-=ans;
		std::cout<<k<<" ";
		
	}
	
	// b.clear();
	
	return 0;
}