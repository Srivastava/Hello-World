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
	int n;
	std::cin>>n;

	std::string str;
	std::cin>>str;

	vi left(n,0),right(n,0);
	
	for(int i=0;i<n;++i)
	{
		if(str[i]=='<')
		{
			if(i==0){left[0]=-1;}
			else
			{
				left[i]=left[i-1]-1;
			}
		}
	}

	for(int i=n-1;i>=0;--i)
	{
		if(str[i]=='>')
		{
			if(i==n-1){right[n-1]=1;}
			else
			{
				right[i]=right[i+1]+1;
			}
		}
	}

	/*std::copy(left.begin(),left.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;

	std::copy(right.begin(),right.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;
*/
	
	int ans=0;
	for(int i=0;i<n;++i)
	{
		if(left[i]+i<0){++ans;}
		if(right[i]+i>n-1){++ans;}
	}
	std::cout<<ans<<std::endl;
	return 0;
}