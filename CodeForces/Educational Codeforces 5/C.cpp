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
#include <set>

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


int n,m;
int color[1005][1005]={0};

std::vector<std::string> vstr;

int sz[1005*1005];
int C=1;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool check(int x,int y)
{
	if(x<0 || y<0 || x>=n || y>=m || vstr[x][y]=='*'){return 0;}

	return 1;
}


void dfs(int x,int y)
{
	color[x][y]=C;
	sz[C]++;

	for(int i=0;i<4;++i)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];

		if(check(nx,ny) && color[nx][ny]==0)
		{
			dfs(nx,ny);
		}
	}
}

int main()
{
	std::cin>>n>>m;

	for(int i=0;i<n;++i)
	{
		std::string str;
		std::cin>>str;

		vstr.push_back(str);
	}

	std::vector<std::string> sol=vstr;

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(vstr[i][j]=='.' && color[i][j]==0)
			{
				dfs(i,j);
				++C;
			}
		}
	}

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			int ans=1;
			if(vstr[i][j]!='*')
			{
				continue;
			}

			std::set<int> S;
			for(int k=0;k<4;++k)
			{
				int nx=i+dx[k];
				int ny=j+dy[k];

				if(check(nx,ny))
				{
					S.insert(color[nx][ny]);
				}
			}

			for(auto it=S.begin();it!=S.end();++it)
			{
				ans+=sz[*it];
			}
			ans%=10;
			sol[i][j]=char('0'+ans);
		}
	}

	for(int i=0;i<n;++i)
	{
		std::cout<<sol[i]<<std::endl;
	}
	return 0;
}