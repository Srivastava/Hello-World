#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <set>
#include <stack>

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


int main()
{
	int n;
	std::cin>>n;

	vi t(n+1,0);
	for(int i=1;i<=n;++i)
	{
		std::cin>>t[i];
	}

	std::set<pa> ans;

	std::pair<pa,char> value;
	std::queue<std::pair<pa,char> > s;
	s.push({{-t[1]+1,0},'N'});

	for(int i=0;i<t[1];++i)
	{
		ans.insert({-i,0});
	}

	int ind=1;
	int val=0;
	while(!s.empty() && ind<=n)
	{
		if(val==0){val=s.size();++ind;}
		if(ind>n){break;}
		value=s.front();
		s.pop();
		--val;

		pa coord=value.first;
		char dir=value.second;

		int chan=t[ind];
		// std::cout<<chan<<std::endl;
		if(dir=='N')
		{
			int i=coord.first,j=coord.second;
			int cnt=0;
			// std::cout<<i<<" ------- "<<j<<std::endl;
			while(cnt<chan)
			{
				++cnt;
				i--;
				j--;
				// std::cout<<i<<" "<<j<<std::endl;
				ans.insert({i,j});
			}
			// std::cout<<i<<" * "<<j<<std::endl;
			s.push({{i,j},'B'});
			i=coord.first;j=coord.second;
			cnt=0;
			// std::cout<<i<<" -------- "<<j<<std::endl;
			while(cnt<chan)
			{
				++cnt;
				i--;
				j++;
				// std::cout<<i<<" "<<j<<std::endl;
				ans.insert({i,j});
			}
			// std::cout<<i<<" "<<j<<std::endl;
			s.push({{i,j},'A'});
		}
		else if(dir=='E')
		{
			int i=coord.first,j=coord.second;
			int cnt=0;
			while(cnt<chan)
			{
				++cnt;
				i--;
				j++;
				ans.insert({i,j});
			}
			s.push({{i,j},'A'});
			i=coord.first;j=coord.second;
			cnt=0;

			while(cnt<chan)
			{
				++cnt;
				i++;
				j++;
				ans.insert({i,j});
			}
			s.push({{i,j},'D'});
		}
		else if(dir=='S')
		{
			int i=coord.first,j=coord.second;
			int cnt=0;
			while(cnt<chan)
			{
				++cnt;
				i++;
				j++;
				ans.insert({i,j});
			}
			s.push({{i,j},'D'});
			i=coord.first;j=coord.second;
			cnt=0;

			while(cnt<chan)
			{
				++cnt;
				i++;
				j--;
				ans.insert({i,j});
			}
			s.push({{i,j},'C'});
		}
		else if(dir=='W')
		{
			int i=coord.first,j=coord.second;
			int cnt=0;
			while(cnt<chan)
			{
				++cnt;
				i++;
				j--;
				ans.insert({i,j});
			}
			s.push({{i,j},'C'});
			i=coord.first;j=coord.second;
			cnt=0;

			while(cnt<chan)
			{
				++cnt;
				i--;
				j--;
				ans.insert({i,j});
			}
			s.push({{i,j},'B'});
		}
		else if(dir=='A')
		{
			int i=coord.first,j=coord.second;
			int cnt=0;
			// std::cout<<i<<" ---- "<<j<<std::endl;
			while(cnt<chan)
			{
				++cnt;
				i--;
				j;
				ans.insert({i,j});
			}
			// std::cout<<i<<" * "<<j<<std::endl;
			s.push({{i,j},'N'});
			i=coord.first;j=coord.second;
			cnt=0;
			// std::cout<<i<<" ---- "<<j<<std::endl;
			while(cnt<chan)
			{
				++cnt;
				i;
				j++;
				ans.insert({i,j});
			}
			// std::cout<<i<<" * "<<j<<std::endl;
			s.push({{i,j},'E'});
		}
		else if(dir=='B')
		{
			int i=coord.first,j=coord.second;
			int cnt=0;
			// std::cout<<i<<"---- "<<j<<std::endl;
			while(cnt<chan)
			{
				++cnt;
				i--;
				j;
				ans.insert({i,j});
			}
			// std::cout<<i<<" * "<<j<<std::endl;
			s.push({{i,j},'N'});
			i=coord.first;j=coord.second;
			cnt=0;

			while(cnt<chan)
			{
				++cnt;
				i;
				j--;
				ans.insert({i,j});
			}
			// std::cout<<i<<" * "<<j<<std::endl;
			s.push({{i,j},'W'});
		}
		else if(dir=='C')
		{
			int i=coord.first,j=coord.second;
			int cnt=0;
			while(cnt<chan)
			{
				++cnt;
				i++;
				j;
				ans.insert({i,j});
			}
			s.push({{i,j},'S'});
			i=coord.first;j=coord.second;
			cnt=0;

			while(cnt<chan)
			{
				++cnt;
				i;
				j--;
				ans.insert({i,j});
			}
			s.push({{i,j},'W'});
		}
		else if(dir=='D')
		{
			int i=coord.first,j=coord.second;
			int cnt=0;
			while(cnt<chan)
			{
				++cnt;
				i++;
				j;
				ans.insert({i,j});
			}
			s.push({{i,j},'S'});
			i=coord.first;j=coord.second;
			cnt=0;

			while(cnt<chan)
			{
				++cnt;
				i;
				j++;
				ans.insert({i,j});
			}
			s.push({{i,j},'E'});
		}

	}
	
	/*std::cout<<"------------"<<std::endl;
	for(auto it=ans.begin();it!=ans.end();++it)
	{
		std::cout<<(*it).first<<" "<<(*it).second<<std::endl;
	}*/
	std::cout<<ans.size()<<std::endl;
	return 0;
}