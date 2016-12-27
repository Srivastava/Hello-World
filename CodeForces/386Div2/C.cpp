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


int main()
{
	double a,b,p1,p2,p3,s;
	int d;
	std::cin>>s>>p2>>p3>>a>>b>>p1>>d;

	if(d==1 && p3>p2)
	{
		double k=((p2*(1.0/a) -p1*(1.0/b))/(b-a))*(a*b);
		double t= ((p2-p1)/(b-a))*(a*b);

		if(k>p3)
		{
			std::cout<<(p3-p2)*b<<std::endl;
		}
		else
		{
			double val1= t+(p3-k)*a,val2=(p3-p2)*b;

			std::cout<<std::min(val1,val2)<<std::endl;
		}
	}
	else if(d==1 && p3<p2)
	{

		double k=((p2*(1.0/a) +p1*(1.0/b))/(b+a))*(a*b);
		double t= ((p2-p1)/(b+a))*(a*b);

		if(p3>k)
		{
			std::cout<<(p2-p3)*b<<std::endl;
		}
		else
		{
			double val1= t+(s-k)*a+(s-p3)*a,val2=(p2-p3)*b;

			std::cout<<std::min(val1,val2)<<std::endl;
		}
	}
	else if(d==-1 && p3<p2)
	{
		double k=((p2*(1.0/a) -p1*(1.0/b))/(b+a))*(a*b);
		double t= ((p2+p1)/(b+a))*(a*b);

		if(k<p3)
		{
			std::cout<<(p2-p3)*b<<std::endl;
		}
		else
		{
			double val1= t+(s-k)*a+(s-p3)*a,val2=(p2-p3)*b;

			std::cout<<std::min(val1,val2)<<std::endl;
		}

	}
	else if(d==-1 && p3>p2)
	{
		double k=((p2*(1.0/a) +p1*(1.0/b))/(b-a))*(a*b);
		double t= ((p2+p1)/(b-a))*(a*b);

		if(p3<k)
		{
			std::cout<<(p3-p2)*b<<std::endl;
		}
		else
		{
			double val1= t+(p3-k)*a,val2=(p3-p2)*b;

			std::cout<<std::min(val1,val2)<<std::endl;
		}
	}
	return 0;
}