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

	vvll g(n,vll(n,0));

	int ai=-1,aj=-1;

	if(n==1){std::cout<<1<<std::endl;return 0;}
	// vll sumrows(n,0);
	ll sum1=0;bool notequal=false;
	for(int i=0;i<n;++i)
	{
		ll sum2=0;
		for(int j=0;j<n;++j)
		{
			std::cin>>g[i][j];
			sum2+=g[i][j];
			if(g[i][j]==0){ai=i;aj=j;}
		}
		/*if(ai==-1 && sum1==0)
		{
			sum1=sum2;
		}
		if(ai!=-1 && sum1!=0)
		{
			if(i!=ai && sum2!=0)
			{
				if(sum1!=sum2){notequal=true;}
			}
		}*/
	}

	if(notequal){std::cout<<-1<<std::endl;return 0;}



	int x = ai==n-1 ? 0 : ai+1;
	int y = aj==n-1 ? 0 : aj+1;

	ll sumr=0;
	for(int i=0;i<n;++i)
	{
		sumr+=g[x][i];
	}

	ll sumc=0;
	for(int i=0;i<n;++i)
	{
		sumc+=g[i][y];
	}
	if(sumc!=sumr)
	{
		std::cout<<-1<<std::endl;
		return 0;
	}

	for(int j=0;j<n;++j)
	{
		
		ll sumcheck=0;
		int i=0;
		for(;i<n;++i)
		{
			sumcheck+=g[i][j];
		}
		if(j!=aj)
		{
			if(sumcheck!=sumc){notequal=true;break;}
		}
	}

	if(notequal){std::cout<<-1<<std::endl;return 0;}

	for(int j=0;j<n;++j)
	{
		
		ll sumcheck=0;
		int i=0;
		for(;i<n;++i)
		{
			sumcheck+=g[j][i];
		}
		if(j!=ai)
		{
			if(sumcheck!=sumr){notequal=true;break;}
		}
	}
	if(notequal){std::cout<<-1<<std::endl;return 0;}

	ll sumtr=0,sumtc=0;

	for(int i=0;i<n;++i)
	{
		sumtr+=g[ai][i];
	}
	for(int i=0;i<n;++i)
	{
		sumtc+=g[i][aj];
	}

	ll sumdl=0,sumdr=0;

	bool mdl=false,mdr=false;

	for(int i=0;i<n;++i)
	{
		sumdl+=g[i][i];
		if(ai==i && aj==i)
		{
			mdl=true;
		}
	}

	for(int i=0;i<n;++i)
	{
		sumdr+=g[i][n-i-1];
		if(ai==i && aj==n-i-1)
		{
			mdr=true;
		}
	}

	if(!mdr && !mdl)
	{
		if(sumr!=sumdl || sumr!=sumdr || sumc!=sumdr || sumc!=sumdl)
		{
			std::cout<<-1<<std::endl;
			return 0;
		}
	}
	
	if(mdr && !mdl)
	{
		if(sumr!=sumdl || sumc!=sumdl)
		{
			std::cout<<-1<<std::endl;
			return 0;
		}
	}

	if(mdl && !mdr)
	{
		if(sumr!=sumdr || sumc!=sumdr)
		{
			std::cout<<-1<<std::endl;
			return 0;
		}
	}	
	

	ll ans = sumr-sumtr;
	if(ans<=0){std::cout<<-1<<std::endl;return 0;}
	// std::cout<<ans<<" "<<sumr<<" "<<sumdr<<" "<<sumdl<<std::endl;
	if(ans==sumc-sumtc)
	{
		if(!mdl && !mdr )
		{
			if(sumtr+ans==sumdr && sumtr+ans==sumdl){
				std::cout<<ans<<std::endl;return 0;
			}
			else
			{
				std::cout<<-1<<std::endl;
				return 0;
			}
		}
		
		else
		{
			if(mdr && !mdl)
			{
				if(sumtr+ans==sumdr+ans)
				{
					std::cout<<ans<<std::endl;return 0;
				}
				else
				{
					std::cout<<-1<<std::endl;
					return 0;
				}

			}

			if(mdl && !mdr)
			{
				if(sumtr+ans==sumdl+ans)
				{
					std::cout<<ans<<std::endl;return 0;
				}
				else
				{
					std::cout<<-1<<std::endl;
					return 0;
				}

			}
			else
			{
				if(sumtr+ans==sumdl+ans && sumtr+ans==sumdr+ans)
				{
					std::cout<<ans<<std::endl;return 0;
				}
				else
				{
					std::cout<<-1<<std::endl;
					return 0;
				}

			}
		}
	}
	else
	{
		std::cout<<-1<<std::endl;
	}

	/*for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			std::cout<<g[i][j]<<" ";
		}
		std::cout<<std::endl;
	}*/
	return 0;
}

/*7 	12 	1 	14
2 	13 	8 	11
16 	3 	10 	5
9 	6 	16 	0*/