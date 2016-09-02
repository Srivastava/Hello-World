#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <stack>

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

const int maxn=20005;

vi s(maxn,0);
vll size(maxn,0);

int find(int x)
{
	return x==s[x] ? x :s[x]=find(s[x]);
}

void join(int x,int y)
{
	// int u=find(x);int v=find(y);
	if(size[x]>size[y])
	{

		s[y]=s[x];
		size[x]+=size[y];
	}
	else
	{
		s[x]=s[y];
		size[y]+=size[x];
	}
}


int main()
{
	int t;
	std::cin>>t;

	while(t--)
	{
		int n;
		std::cin>>n;

		// std::cout<<n<<" NNN "<<std::endl;
		vb visit(n+1,false);

		for(int i=0;i<=n;++i)
		{
			s[i]=i;
			size[i]=1;
		}

		std::vector<std::pair<int,int> > edge;
		edge.push_back(std::make_pair(0,0));
		for(int i=0;i<n-1;++i)
		{
			int u,v;
			std::cin>>u>>v;
			edge.push_back(std::make_pair(u,v));
		}
		std::stack<std::pair<char,int> > s;

		int m;
		std::cin>>m;
		for(int i=0;i<m;++i)
		{
			char c;
			std::cin>>c;

			
			if(c=='Q')
			{

				s.push(std::make_pair(c,0));
			}
			else
			{
				int u;
				std::cin>>u;
				
				visit[u]=true;
				s.push(std::make_pair(c,u));
			}

		}

		ll ans=(n*(n-1))/2;

		for(int i=1;i<=m;++i)
		{
			if(!visit[i])
			{
				int u=find(edge[i].first);
				int v=find(edge[i].second);
				if(u!=v)
				{
					ans=ans-(size[u]*size[v]);
					join(u,v);
					
				}
			}
		}

		std::stack<ll> sol;
		while(!s.empty())
		{
			std::pair<char,int> v=s.top();
			s.pop();

			if(v.first=='Q')
			{
				sol.push(ans);
				// std::cout<<ans<<std::endl;
			}
			else
			{
				int u=find(edge[v.second].first);
				int w=find(edge[v.second].second);
				if(u!=w)
				{
					ans=ans-(size[u]*size[w]);
					join(u,w);
					
				}
			}
			// std::cout<<v.first<<" "<<v.second<<std::endl;
		}
		while(!sol.empty())
		{
			int val=sol.top();
			sol.pop();

			std::cout<<val<<std::endl;
		}

	}
	return 0;
}