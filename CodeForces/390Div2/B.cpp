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
	std::vector<std::vector<char> > board(4,std::vector<char>(4,'.'));

	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			std::cin>>board[i][j];
		}
	}

	bool win=false;
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			if(board[i][j]!='x'){continue;}
			int cntx=0,cnty=0;
			for(int k=1;k<=2 && i+k<4;++k)
			{
				if(board[i+k][j]=='x') 
					++cntx;
				else if(board[i+k][j]=='.')
					++cnty;
				else
					break;
			}
			if((cntx==2 && cnty==0) || (cntx==1 && cnty==1))
			{
				// std::cout<<i<<" "<<j<<" "<<cntx<<" "<<cnty<<std::endl;
				std::cout<<"YES"<<std::endl;
				return 0;
			}
			cntx=0;cnty=0;

			for(int k=1;k<=2 && i-k>=0;++k)
			{
				if(board[i-k][j]=='x') 
					++cntx;
				else if(board[i-k][j]=='.')
					++cnty;
				else
					break;
			}
			if((cntx==2 && cnty==0) || (cntx==1 && cnty==1))
			{
				// std::cout<<i<<" "<<j<<" "<<cntx<<" "<<cnty<<std::endl;
				std::cout<<"YES"<<std::endl;
				return 0;
			}
			cntx=0;cnty=0;

			for(int k=1;k<=2 && j+k<4;++k)
			{
				if(board[i][j+k]=='x') 
					++cntx;
				else if(board[i][j+k]=='.')
					++cnty;
				else
					break;
			}
			if((cntx==2 && cnty==0) || (cntx==1 && cnty==1))
			{
				std::cout<<"YES"<<std::endl;
				return 0;
			}
			cntx=0;cnty=0;
			for(int k=1;k<=2 && j-k>=0;++k)
			{
				if(board[i][j-k]=='x') 
					++cntx;
				else if(board[i][j-k]=='.')
					++cnty;
				else
					break;
			}
			if((cntx==2 && cnty==0) || (cntx==1 && cnty==1))
			{
				std::cout<<"YES"<<std::endl;
				return 0;
			}
			cntx=0;cnty=0;
			for(int k=1;k<=2 && (i+k<4 &&j+k<4) ;++k)
			{
				if(board[i+k][j+k]=='x') 
					++cntx;
				else if(board[i+k][j+k]=='.')
					++cnty;
				else
					break;
			}
			if((cntx==2 && cnty==0) || (cntx==1 && cnty==1))
			{
				std::cout<<"YES"<<std::endl;
				return 0;
			}
			cntx=0;cnty=0;
			for(int k=1;k<=2 && (i+k<4 &&j-k>=0) ;++k)
			{
				if(board[i+k][j-k]=='x') 
					++cntx;
				else if(board[i+k][j-k]=='.')
					++cnty;
				else
					break;
			}
			if((cntx==2 && cnty==0) || (cntx==1 && cnty==1))
			{
				std::cout<<"YES"<<std::endl;
				return 0;
			}
			cntx=0;cnty=0;

			for(int k=1;k<=2 && (i-k>=0 &&j+k<4) ;++k)
			{
				if(board[i-k][j+k]=='x') 
					++cntx;
				else if(board[i-k][j+k]=='.')
					++cnty;
				else
					break;
			}
			if((cntx==2 && cnty==0) || (cntx==1 && cnty==1))
			{
				std::cout<<"YES"<<std::endl;
				return 0;
			}
			cntx=0;cnty=0;

			for(int k=1;k<=2 && (i-k>=0 &&j-k>=0) ;++k)
			{
				if(board[i-k][j-k]=='x') 
					++cntx;
				else if(board[i-k][j-k]=='.')
					++cnty;
				else
					break;
			}
			if((cntx==2 && cnty==0) || (cntx==1 && cnty==1))
			{
				std::cout<<"YES"<<std::endl;
				return 0;
			}
			cntx=0;cnty=0;
		}
	}
	std::cout<<"NO"<<std::endl;
	return 0;
}

/*int main()
{
	std::vector<std::vector<char> > board(4,std::vector<char>(4,'.'));

	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			std::cin>>board[i][j];
		}
	}

	for(int )
	return 0;
}*/