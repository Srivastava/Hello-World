#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <map>

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<int,int> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;
typedef std::vector<vi> vvi;

int main()
{

	int n,m;
	scanf("%d%d",&n,&m);
	// std::cin>>n>>m;

	vvi matrix(n,vi(m,0));

	std::map<int,pa> row,col;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			scanf("%d",&matrix[i][j]);
			// std::cin>>matrix[i][j];
			if(matrix[i][j]==1)
			{
				if(row.find(i)==row.end())
				{
					row[i]={j,j};
				}
				else
				{
					
					pa temp=row[i];
					
					if(temp.first>j){temp.first=j;}
					if(temp.second<j){temp.second=j;}
					row[i]=temp;
				}

				if(col.find(j)==col.end())
				{
					col[j]={i,i};
				}
				else
				{
					pa temp=col[j];
					if(temp.first>i){temp.first=i;}
					if(temp.second<i){temp.second=i;}
					col[j]=temp;
				}
			}
		}
	}

	
	// vvi upm(n,vi(m,0));
	// vvi downm(n,vi(m,0));
	// vvi leftm(n,vi(m,0));
	// vvi rightm(n,vi(m,0));

	// for(int i=0;i<n;++i)
	// {
	// 	for(int j=0;j<m;++j)
	// 	{
	// 		if(matrix[i][j]==1)
	// 		{
	// 			if(row.find(i)==row.end())
	// 			{
	// 				row[i]={j,j};
	// 			}
	// 			else
	// 			{
	// 				// std::cout<<"here"<<i<<" "<<j<<std::endl;
	// 				pa temp=row[i];
	// 				// std::cout<<"here"<<temp.first<<" "<<temp.second<<std::endl;
	// 				if(temp.first>j){temp.first=j;}
	// 				if(temp.second<j){temp.second=j;}
	// 				row[i]=temp;
	// 			}

	// 			if(col.find(j)==col.end())
	// 			{
	// 				col[j]={i,i};
	// 			}
	// 			else
	// 			{
	// 				pa temp=col[j];
	// 				if(temp.first>i){temp.first=i;}
	// 				if(temp.second<i){temp.second=i;}
	// 				col[j]=temp;
	// 			}
	// 		}
			
	// 	}
	// }

	// act=0;

	// int act=0;
	// for(int i=0;i<n;++i)
	// {
	// 	for(int j=0;j<m;++j)
	// 	{
	// 		if(matrix[i][j]==1){act=1;}
	// 		leftm[i][j]=act;
	// 	}
	// 	act=0;
	// }

	// act=0;
	// for(int i=0;i<n;++i)
	// {
	// 	for(int j=m-1;j>=0;--j)
	// 	{
	// 		if(matrix[i][j]==1){act=1;}
	// 		rightm[i][j]=act;
	// 	}
	// 	act=0;
	// }
	// act=0;
	// for(int j=0;j<m;++j)
	// {
	// 	for(int i=0;i<n;++i)
	// 	{
	// 		if(matrix[i][j]==1){act=1;}
	// 		upm[i][j]=act;
	// 	}
	// 	act=0;
	// }
	// act=0;
	// for(int j=0;j<m;++j)
	// {
	// 	for(int i=n-1;i>=0;--i)
	// 	{
	// 		if(matrix[i][j]==1){act=1;}
	// 		downm[i][j]=act;
	// 	}
	// 	act=0;
	// }
	
	ll ans=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(matrix[i][j]==0)
			{
				if(row.find(i)!=row.end())
				{
					pa rowT=row[i];
					ans+=j>rowT.first ? 1:0;
					ans+=j<rowT.second ? 1:0;
					// std::cout<<rowT.first<<" ROW "<<rowT.second<<std::endl;
				}
				if(col.find(j)!=col.end())
				{
					pa colT=col[j];
					ans+=i>colT.first ? 1:0;
					ans+=i<colT.second ? 1:0;
					// std::cout<<colT.first<<" COL "<<colT.second<<std::endl;

				}
				
				// std::cout<<i<<" "<<j<<std::endl;
				
								
				
				// std::cout<<ans<<std::endl;
			}
		}
	}

	printf("%d\n",ans );
	// std::cout<<ans<<std::endl;
	return 0;
}