#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

long long aux(std::vector<long long>& h,const long long& lo,const long long& hi)
{

	// std::cout<<" aux "<<std::endl;
	if(lo==hi){return h[lo];}
	long long mid = lo+(hi-lo)/2;

	// std::cout<<" aux * "<<lo<<" " <<mid <<" "<<hi<<std::endl;

	if(h[mid]!=-1){return h[mid];}
	h[mid]=std::min(mid-lo,hi-mid);

	long long maxL=aux(h,lo,mid);
	long long maxR=aux(h,mid,hi);

	// std::cout<<" aux  2 "<<std::endl;

	return (std::max(h[mid],std::max(maxR,maxL)));

}

long long binary(std::vector<long long>& h,const std::vector<long long>& d)
{
	long long temp=0,max=0;
	h[0]=0;h[1]=0;

	// std::cout<<" binary "<<std::endl;

	for(long long i=d[d.size()-1];i<h.size()-1;++i)
	{
		h[i+1]=h[i]+1;
	}

	for(long long i=d[0];i>=1;--i)
	{
		h[i-1]=h[i]-1;
	}

	for(long long i=0;i<d.size()+1;++i)
	{
		// std::cout<<" binary 2 "<< i <<std::endl;


		if(i==0)
		{
			temp = aux(h,1,d[i]);
		}
		else if(i==d.size())
		{
			temp=aux(h,d[i],h.size()-1);
		}

		else
		{
			temp=aux(h,d[i-1],d[i]);
		}

		(temp > max) ? max=temp : max=max;
	}

	return max;
}

int main()
{
	long long n,m;
	std::cin>>n>>m;

	std::vector<long long> h(n+1,-1);
	std::vector<long long> d;

	bool okay=true;
	while(m--)
	{
		long long day,val;
		std::cin>>day>>val;
		d.push_back(day);

		h[day]=val;
		if(h.size()>=2)
		if(std::abs(h[h.size()-2] - h[h.size()-1])>1)
		{
			std::cout<<"IMPOSSIBLE"<<std::endl;
			okay=false;
			break;

		}
	}

	if(okay)
	{
		
		// std::cout<<std::endl;

		std::cout<<binary(h,d)<<std::endl;
		// std::copy(h.begin(),h.end(),std::ostream_iterator<long long>(std::cout," "));
	}

	return 0;
}