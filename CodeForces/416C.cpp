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

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<std::pair<ull,ull> > pvull;
typedef std::vector<std::pair<ll,ll> > pvll;

ull maxVal(pvull& cp,const pvull& sp)
{
	// ull team[k].first;

	ull l=0,r=0;
	for(int i=1;i<cp.size();++i)
	{
		// std::cout<<"here "<<l<<" "<<r<<" "<<i<<" "<<cp[i].first<<" "<<cp[i-1].first<<std::endl;
		if(cp[i].first==cp[i-1].first && i!=cp.size()-1)
		{
			// ++r;
		}

		else
		{
			if(cp[cp.size()-1].first>=cp[cp.size()-2].first)
			{
				
				i==cp.size()-1 ? i=cp.size() :i=i;
			}
			std::sort(cp.begin()+l, cp.begin()+i, [](const std::pair<ull,ull> &left, const std::pair<ull,ull> &right) {return left.first < right.first;});
			l=i;
		}

	}

	ull val=0; pvull match;

	for(int i=0;i<cp.size();++i)
	{
		if(cp[i].first>sp[sp.size()-1])
		{
			continue;
		}
		else
		{
			for(int j=sp.size()-1;j>=0;++j)
			{
				if(cp[i].first>sp[j].first)
				{
					if(j!=sp.size()-1)
					{
						if(cp[i].first==sp[j].first)
						{
							val+=cp[i].first;
							
						}
					}
				}
			}
		}
	}


}

int main()
{
	ull n;
	std::cin>>n;

	pvull cp;
	cp.reserve(n);

	for(int i=0;i<n;++i)
	{
		ull val,val1;
		std::cin>>val>>val1;

		cp.push_back(std::make_pair(val,val1));
	}

 	std::sort(cp.begin(), cp.end(), [](const std::pair<ull,ull> &left, const std::pair<ull,ull> &right) {return left.second > right.second;});

	ull k;
	std::cin>>k;

	pvull sp;
	sp.reserve(k);

	for(int i=0;i<k;++i)
	{
		ull val;
		std::cin>>val;
		std::cin>>sp(std::make_pair(val,i+1));
	}
 	std::sort(cp.begin(), cp.end(), [](const std::pair<ull,ull> &left, const std::pair<ull,ull> &right) {return left.first > right.first;});

	std::cout<<maxVal(cp,sp)<<std::endl;

	return 0;
}