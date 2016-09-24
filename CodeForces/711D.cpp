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


int C=1;
const int N = 1e6 + 3;

vi visited(N,0);
vi cycles;
vll a(N,0);
int cyclecnt=0;

void dfs2(int u)
{
	cycles[cyclecnt]++;
	visited[u]=3;
	// std::cout<<u<<" ** "<<std::endl;

	if(visited[a[u]]==3){return;}
	dfs2(a[u]);
}

void dfs(int u)
{
	visited[u]=2;

	// std::cout<<u<<" * "<<std::endl;
	if(visited[a[u]]==0)
	{
		dfs(a[u]);
	}
	else if(visited[a[u]]==1)
	{
		visited[u]=1;
		return;
	}
	else
	{
		cycles.push_back(0);
		dfs2(u);
		cyclecnt++;
	}

	visited[u]=1;

}

int main()
{
	int n;
	std::cin>>n;

	// std::cout<<n<<std::endl;

	for(int i=1;i<=n;++i)
	{
		std::cin>>a[i];
		// std::cout<<i<<" "<<a[i]<<std::endl;
	}

	vll dp(n+1,0);

	dp[0]=1;
	for(int i=1;i<=n;++i)
	{
		dp[i]=(dp[i-1] * 2LL)%MOD;
	}

	ll ans =1;

	for(int i=1;i<=n;++i)
	{
		if(visited[i]==0)
		{
			dfs(i);
		}
	}

	ll cnt=n;

	for(int i=0;i< cycles.size();++i)
	{
		cnt-=cycles[i];
		// std::cout<<cycles[i]<<std::endl;
		ans=(ans*(dp[cycles[i]]-2+MOD))%MOD;
	}
	ans=(ans*dp[cnt])%MOD;
	// std::cout<<ans<<std::endl;
	if(ans<0){ans+=MOD;}
	std::cout<<ans<<std::endl;

	return 0;
}