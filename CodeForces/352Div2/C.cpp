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

bool compare(const std::pair<double, int>&i, const std::pair<double, int>&j)
{
    return i.first > j.first;
}

int main()
{
	int ax,ay,bx,by,tx,ty;
	std::cin>>ax>>ay>>bx>>by>>tx>>ty;

	int n;
	std::cin>>n;

	vll x(n,0),y(n,0);
	// std::vector<double> dist(n,0.0);

	std::vector<std::pair<double,double> > dist;
	
	double ans=0.0;

	for(int i=0;i<n;++i)
	{
		std::cin>>x[i]>>y[i];

		double temp= std::sqrt((tx-x[i])*(tx-x[i]) + (ty-y[i])*(ty-y[i]));
		
		ans+=2*temp;

		double temp1 = std::sqrt((ax-x[i])*(ax-x[i]) + (ay-y[i])*(ay-y[i]));
		temp1 = temp - temp1;

		double temp2 = std::sqrt((bx-x[i])*(bx-x[i]) + (by-y[i])*(by-y[i]));
		temp2 = temp - temp2;

		dist.push_back(std::make_pair(temp1,temp2));

	}

	double max = -1e10;

	std::sort(dist.begin(),dist.end());

	for(int i=n-1;i>=0;--i)
	{
		max=std::max(max,dist[i].first);
		max=std::max(max,dist[i].second);

		if(i==n-1)
		{
			max=std::max(max,dist[n-2].first+dist[i].second);
		}
		else
		{
			max=std::max(max,dist[n-1].first+dist[i].second);
		}

	}

	printf("%.12lf\n",ans-max);
	// std::cout<<ans<<std::endl;
	return 0;
}