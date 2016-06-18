#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>

/***************************************************************
/********************                 *******************************************
/*						PT07Y                                                 */
/********************                 *******************************************
/***************************************************************/
bool existCycle(const std::multimap<int, int>& map)
{
	auto it=map.begin();

	int first=it->first;
	int second=it->second;

	int val=second;
	while(1)
	{
		auto search=map.find(val);

		if(search!=map.end())
		{
			val=search->second;
		}
		else
		{
			return false;
		}
		if(search->first==first && search->second==second){return true; break;}
		// int exist=map[second];

	}
}

bool isConnected(const std::multimap<int, int>& map)
{
	std::unordered_map<int, bool> visited;

	for( const auto& n : map ) 
	{
        // std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
        auto it = visited.find(n.first);
        if(it==visited.end())
        visited.insert({n.first,false});
    }
	
	auto it=map.begin();

	int first=it->first;
	int second=it->second;

	int val=second;

	visited[first]=true;;
	while(1)
	{
		auto search=map.find(val);
		

		// visited.insert({search.first,true});

		if(search!=map.end())
		{
			if(visited[search->first]==true){break;}
			val=search->second;
			visited[search->first]=true;
		}
		
		else
		{
			break;
		}
		// if(search.first==first && search.second==second){return true; break;}
		// int exist=map[second];

	}

	for( const auto& n : visited ) 
	{
        // std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
        if(n.second==false){return false;}
    }


}

int main()
{
	int v,e;
	std::cin>>v>>e;

	std::multimap<int, int> map;

	for(int i=0;i<e;++i)
	{
		int u,v;
		std::cin>>u>>v;
		map.insert({u,v});
		map.insert({v,u});
	}

	bool cycle = existCycle(map);
	bool connect=false;
	// bool connect = isConnected(map);

	std::cout<<"CYCLE: "<<cycle<<" CONNECT: "<<connect<<std::endl;

	if(cycle==false && connect==true){std::cout<<"yes"<<std::endl;}
	else{std::cout<<"no"<<std::endl;}

	return 0;
}