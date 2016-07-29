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

/*ll solve(ll n, ll m,ll p)
{
	ll mul=1e15,add=1e15;

	if(n<=0){return 0;}
	if(n==m){return 0;}
	std::cout<<n<<" "<<m<<" "<<p<<std::endl;
	if(n>m)
	{

		if(n-1!=p)
		add=solve(n-1,m,p)+1;
		
		if(n*2!=p)
		mul=solve(n*2,m,p)+1;
	}

	else
	{
		if(n-1!=p)
		add=solve(n-1,m,p)+1;
		
		if(n*2!=p)
		mul=solve(n*2,m,p)+1;
	}

	return std::min(add,mul);
}
*/

ll solve(ll n,ll m)
{
	std::queue<ll> q;
	q.push(n);


	ll r=std::max(n,m);
	
	std::vector<bool> visited(20009+5,false);
	visited[n]=true;
	vll dist(20009+5,0);

	ll count=0;
	while(!q.empty())
	{
		ll top=q.front();
		q.pop();

		// std::cout<<top<<std::endl;
		if(top==m){break;}
		

		if(!visited[2*top] && 2*top<=20009+5)
		{
			visited[2*top]=true;
			dist[2*top]=dist[top]+1;
			q.push(2*top);
		}
		if(!visited[top-1] && top>=2)
		{
			visited[top-1]=true;
			dist[top-1]=dist[top]+1;
			q.push(top-1);
		}
	}
	return dist[m];
}
int main()
{
	ll n,m;
	std::cin>>n>>m;

	std::cout<<solve(n,m)<<std::endl;

	return 0;
}