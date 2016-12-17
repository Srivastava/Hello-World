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


/*int main()
{
	int n,m;
	std::cin>>n>>m;

	std::vector<std::vector<char>> mat;
	mat.reserve(n);

	int l=1000,r=0,t=1000,b=0;

	bool isX=false;

	for(int i=0;i<n;++i)
	{
		std::vector<char> temp;
		temp.reserve(m);

		
		for(int j=0;j<m;++j)
		{
			char c;
			std::cin>>c;
			temp.push_back(c);

			if(c=='X')
			{
				isX=true;
				l=std::min(l,j);
				r=std::max(r,j);
				t=std::min(t,i);
				b=std::max(b,i);
			}

		}
		mat.push_back(temp);
	}

	// for(int i=0;i<n;++i)
	// {
	// 	for(int j=0;j<m;++j)
	// 	{
	// 		std::cout<<mat[i][j]<<",";
	// 	}
	// 	std::cout<<std::endl;
	// }

	if(!isX){std::cout<<"NO"<<std::endl;return 0;}

	for(int i=t;i<=b;++i)
	{
		for(int j=l;j<=r;++j)
		{
			if(mat[i][j]=='.')
			{
				std::cout<<"NO"<<std::endl;
				return 0;
			}
		}
	}

	std::cout<<"YES"<<std::endl;

	return 0;
}*/

int gcd(int a,int b)
{
	return b==0 ? a:gcd(b,a%b);
}

int main()
{
	int n,m;
	std::cin>>n>>m;

	// std::vector<std::vector<char>> mat(n,std::vector<char>(m,'.'));
	bool isX=false;
	
	int numX=0;
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			char c;
			std::cin>>c;
			if(c=='X'){
				++numX;
				isX=true;
			}
		}
	}

	if(!isX){std::cout<<"NO"<<std::endl;return 0;}

	if(numX==1){std::cout<<"YES"<<std::endl; return 0;}

	if(numX<=n || numX<=m || numX==n*m){std::cout<<"YES"<<std::endl;return 0;}

	int max=std::max(n,m);

	for(int i=2;i<=max;++i)
	{
		if(numX%i==0)
		{
			int val=numX/i;
			if(val<=n && i<=m){
				std::cout<<"YES"<<std::endl;
				return 0;
			}
			if(val<=m && i<=n){
				std::cout<<"YES"<<std::endl;
				return 0;
			}
		}
	}
	// int dim=n*m;

	// int gc=gcd(numX,dim);

	// if(gc!=1)
	// 	std::cout<<"YES"<<std::endl;
	// else
	// 	std::cout<<"NO"<<std::endl;

	std::cout<<"NO"<<std::endl;

	return 0;
}