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

int main()
{

	int a,b,n;
	std::cin>>a>>b>>n;

	while(n--)
	{
		int l,t,m;
		std::cin>>l>>t>>m;

		int left=l,right=l+m;

		while(left<right)
		{
			// if(left==l && right!=l+m){break;}
			int mid=(left+right)/2;
			int height=a+(mid-1)*b;
			// if(mid==left){break;}
			std::cout<<left<<" "<<mid<<" "<<right<<" "<<height<<std::endl;
			if(height<t){left=mid+1;}
			// else if(height==t){left=mid;break;}
			else{right=mid;}
			if(right-left==1)
			{
				height=a+(left-1)*b;
				int heightR=a+(right-1)*b;

				if(heightR>t){left=left;}
				else {left=right;}
				break;
			}
			std::cout<<left<<" "<<right<<" "<<height<<std::endl;

		}

		// std::cout<<a+(left-1)*b<<std::endl;
		if(left==l){if(a+(left-1)*b > t){left=-1;}}
		std::cout<<left<<std::endl;
	}
	return 0;
}