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
	int n,m,k;
	std::cin>>n>>m>>k;

	// vll mat(n,vll(m,0));

	vll a(n,0),b(m,0);
	// vpa r,c;
	std::unordered_map<ll,ll> row,col;

	for(int i=0;i<k;++i)
	{
		ll p,q,r;
		std::cin>>p>>q>>r;

		q--;
		// r--;
		if(p==1)
		{
			a[q] = r;
			row[q]=i;
		}
		if(p==2)
		{
			b[q] = r;
			col[q]=i;
		}
	}
	
	vvll mat;
	mat.reserve(n);

	for(int i=0;i<n;++i)
	{
		int val=a[i];
		vll temp(m,val);

		mat.push_back(temp);

	}

	for(int j=0;j<m;++j)
	{
		int val=b[j];

		if(val==0){continue;}
		for(int i=0;i<n;++i)
		{
			int ind=mat[i][j];
			if(mat[i][j]!=0)
			{
				row[i] > col[j] ? mat[i][j]=mat[i][j] :mat[i][j]=val;
			}
			else
			{
				mat[i][j]=val;
			}
		}

	}

	for(int i=0;i<n;++i)
	{
		std::copy(mat[i].begin(),mat[i].end(),std::ostream_iterator<ll>(std::cout," "));
		std::cout<<std::endl;
	}

	return 0;
}