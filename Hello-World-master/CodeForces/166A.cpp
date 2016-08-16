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

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<std::pair<ull,ull> > pvull;
typedef std::vector<std::pair<ll,ll> > pvll;

ull nTeams(pvull& teams,const int& k)
{
	// ull team[k].first;

	ull l=0,r=0;
	for(int i=1;i<teams.size();++i)
	{
		// std::cout<<"here "<<l<<" "<<r<<" "<<i<<" "<<teams[i].first<<" "<<teams[i-1].first<<std::endl;
		if(teams[i].first==teams[i-1].first && i!=teams.size()-1)
		{
			// ++r;
		}

		else
		{
			if(teams[teams.size()-1].first>=teams[teams.size()-2].first)
			{
				
				i==teams.size()-1 ? i=teams.size() :i=i;
			}
			std::sort(teams.begin()+l, teams.begin()+i, [](const std::pair<ull,ull> &left, const std::pair<ull,ull> &right) {return left.second < right.second;});
			l=i;
		}

	}

	// for(int i=0;i<teams.size();++i)
 // 	{
 // 		std::cout<<teams[i].first <<" * "<<teams[i].second<<std::endl;
 // 	}

	l=k;r=k;

	ull count=0;
	// std::cout<<"HERE"<<std::endl;
	for(int i=k-1;i>=1;--i)
	{
		// std::cout<<"here "<<l<<" "<<r<<" "<<i<<" "<<teams[i].first<<" "<<teams[i].second<<std::endl;
		if(teams[i].first == teams[i-1].first && teams[i].second==teams[i-1].second)
		{
			++count;
		}
		else
		{
			l=i;
			break;
		}

	}

	// std::cout<<"right"<<std::endl;
	for(int i=k-1;i<teams.size()-1;++i)
	{
		if(teams[i].first == teams[i+1].first && teams[i].second==teams[i+1].second)
		{
			++count;
		}
		else
		{
			r=i;
			break;
		}

	}

	return count+1;	
}

int main()
{
 	ull n,k;
 	std::cin>>n>>k;

 	pvull team;
 	team.reserve(n);

 	for(int i =0;i<n;++i)
 	{
 		ull val,val1;
 		std::cin>>val>>val1;
 		// std::cout<<val<<val1<<std::endl;
 		team.push_back(std::make_pair(val,val1));
 	}
 	std::sort(team.begin(), team.end(), [](const std::pair<ull,ull> &left, const std::pair<ull,ull> &right) {return left.first > right.first;});

 	// for(int i=0;i<n;++i)
 	// {
 	// 	std::cout<<team[i].first <<"**"<<team[i].second<<std::endl;
 	// }
 	std::cout<<nTeams(team,k)<<std::endl;
	return 0;
}