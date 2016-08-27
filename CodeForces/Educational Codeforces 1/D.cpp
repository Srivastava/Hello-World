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
	int n,m,k;
	std::cin>>n>>m>>k;

	std::vector<std::string> vstr;
	vstr.reserve(n);

	for(int i=0;i<n;++i)
	{
		std::string str;
		std::cin>>str;

		vstr.push_back(str);
	}

	int sol[n][m]={0};
	bool vism[n][m]={false};
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{

			int u=i,v=j;
			if(vstr[u][v]=='*'){continue;}
			
			std::queue<std::pair<int,int> >q;
			q.push(std::make_pair(u,v));

			ll ans=0;
			while(!q.empty())
			{
				std::pair<int,int> p=q.front();

				int f=p.first;
				int s=p.second;

				// std::cout<<f<<" "<<s<<std::endl;
				/*if(vism[f][s]==true)
				{
					q.pop();
					continue;
				}*/

				vism[f][s]=true;
				q.pop();
				
				if(vstr[f+1][s]=='.' && f!=n-1)
				{
					// std::cout<<"1"<<" "<<f+1<<" "<<s<<"*"<<ans<<std::endl;
					if(vism[f+1][s]==false)
					{
						q.push(std::make_pair(f+1,s));
						vism[f+1][s]=true;
					}
					else
					{
						ans+=sol[f+1][s];
					}
				}
				else if(f!=n-1 && vstr[f+1][s]=='*')
				{
					++ans;
				}

				if(vstr[f-1][s]=='.' && f!=0)
				{
					// std::cout<<"2"<<" "<<f-1<<" "<<s<<"*"<<ans<<std::endl;
					if(vism[f-1][s]==false)
					{
						q.push(std::make_pair(f-1,s));
						vism[f-1][s]=true;
					}
					else
					{
						ans+=sol[f-1][s];
					}
				}
				else if(f!=0 && vstr[f-1][s]=='*')
				{
					++ans;
				}


				if(vstr[f][s+1]=='.' && s!=m-1)
				{
					// std::cout<<"3"<<" "<<f<<" "<<s+1<<"*"<<ans<<std::endl;
					if(vism[f][s+1]==false)
					{
						q.push(std::make_pair(f,s+1));
						vism[f][s+1]=true;
					}
					else
					{
						ans+=sol[f][s+1];
					}
				}
				else if(s!=m-1 && vstr[f][s+1]=='*')
				{
					++ans;
				}

				if(vstr[f][s-1]=='.' && s!=0)
				{
					// std::cout<<"4"<<" "<<f<<" "<<s-1<<"*"<<ans<<std::endl;
					if(vism[f][s-1]==false)
					{
						q.push(std::make_pair(f,s-1));
						vism[f][s-1]=true;
					}
					else
					{
						ans+=sol[f][s-1];
					}
				}
				else if(s!=0 && vstr[f][s-1]=='*')
				{
					++ans;
				}
				// std::cout<<ans<<"***********"<<std::endl;
				sol[f][s]=ans;
			}
			// std::cout<<ans<<std::endl;
	
		}
	}
	while(k--)
	{
		int u,v;
		std::cin>>u>>v;

		u--;v--;
		std::cout<<sol[u][v]<<std::endl;
		/*u--;v--;
		std::queue<std::pair<int,int> >q;
		q.push(std::make_pair(u,v));

		ll ans=0;
		bool vism[n][m]={false};
		while(!q.empty())
		{
			std::pair<int,int> p=q.front();

			int f=p.first;
			int s=p.second;

			// std::cout<<f<<" "<<s<<std::endl;
			if(vism[f][s]==true)
			{
				q.pop();
				continue;
			}

			vism[f][s]=true;
			q.pop();
			
			if(vstr[f+1][s]=='.' && f!=n-1)
			{
				// std::cout<<"1"<<" "<<f+1<<" "<<s<<"*"<<ans<<std::endl;
				if(vism[f+1][s]==false)
				{
					q.push(std::make_pair(f+1,s));
					vism[f+1][s]=true;
				}
			}
			else if(f!=n-1 && vstr[f+1][s]=='*')
			{
				++ans;
			}

			if(vstr[f-1][s]=='.' && f!=0)
			{
				// std::cout<<"2"<<" "<<f-1<<" "<<s<<"*"<<ans<<std::endl;
				if(vism[f-1][s]==false)
				{
					q.push(std::make_pair(f-1,s));
					vism[f-1][s]=true;
				}
			}
			else if(f!=0 && vstr[f-1][s]=='*')
			{
				++ans;
			}


			if(vstr[f][s+1]=='.' && s!=m-1)
			{
				// std::cout<<"3"<<" "<<f<<" "<<s+1<<"*"<<ans<<std::endl;
				if(vism[f][s+1]==false)
				{
					q.push(std::make_pair(f,s+1));
					vism[f][s+1]=true;
				}
			}
			else if(s!=m-1 && vstr[f][s+1]=='*')
			{
				++ans;
			}

			if(vstr[f][s-1]=='.' && s!=0)
			{
				// std::cout<<"4"<<" "<<f<<" "<<s-1<<"*"<<ans<<std::endl;
				if(vism[f][s-1]==false)
				{
					q.push(std::make_pair(f,s-1));
					vism[f][s-1]=true;
				}
			}
			else if(s!=0 && vstr[f][s-1]=='*')
			{
				++ans;
			}
			// std::cout<<ans<<"***********"<<std::endl;
		}
		std::cout<<ans<<std::endl;*/

	}
	return 0;
}