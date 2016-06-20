#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>
// #include <unordered_map>
// #include <map>
#include <list>

/***************************************************************
/********************                 *******************************************
/*						PT07Y                                                 */
/********************                 *******************************************
/***************************************************************/

// bool existCycle(const std::multimap<int, int>& map)
// {
// 	auto it=map.begin();

// 	int first=it->first;
// 	int second=it->second;

// 	int val=second;
// 	while(1)
// 	{
// 		auto search=map.find(val);

// 		if(search!=map.end())
// 		{
// 			val=search->second;
// 		}
// 		else
// 		{
// 			return false;
// 		}
// 		if(search->first==first && search->second==second){return true; break;}
// 		// int exist=map[second];

// 	}
// }

// bool isConnected(const std::multimap<int, int>& map)
// {
// 	std::unordered_map<int, bool> visited;

// 	for( const auto& n : map ) 
// 	{
//         // std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
//         auto it = visited.find(n.first);
//         if(it==visited.end())
//         visited.insert({n.first,false});
//     }
	
// 	auto it=map.begin();

// 	int first=it->first;
// 	int second=it->second;

// 	int val=second;

// 	visited[first]=true;;
// 	while(1)
// 	{
// 		auto search=map.find(val);
		

// 		// visited.insert({search.first,true});

// 		if(search!=map.end())
// 		{
// 			if(visited[search->first]==true){break;}
// 			val=search->second;
// 			visited[search->first]=true;
// 		}
		
// 		else
// 		{
// 			break;
// 		}
// 		// if(search.first==first && search.second==second){return true; break;}
// 		// int exist=map[second];

// 	}

// 	for( const auto& n : visited ) 
// 	{
//         // std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
//         if(n.second==false){return false;}
//     }


// }

// int main()
// {
// 	int v,e;
// 	std::cin>>v>>e;

// 	std::multimap<int, int> map;

// 	for(int i=0;i<e;++i)
// 	{
// 		int u,v;
// 		std::cin>>u>>v;
// 		map.insert({u,v});
// 		map.insert({v,u});
// 	}

// 	bool cycle = existCycle(map);
// 	bool connect=false;
// 	// bool connect = isConnected(map);

// 	std::cout<<"CYCLE: "<<cycle<<" CONNECT: "<<connect<<std::endl;

// 	if(cycle==false && connect==true){std::cout<<"yes"<<std::endl;}
// 	else{std::cout<<"no"<<std::endl;}

// 	return 0;
// }


class Graph
{
	int V;
	std::list<int> *adj;

	void dfs(int v, bool visited[]);
	bool isCycle(int v, bool visited[],int parent);

public:
	Graph(int V);
	void addEdge(int v,int w);
	bool isTree(int v);
	void dfsPrint(int v);
	// void print()

};

Graph::Graph(int V)
{
	this->V=V;
	adj=new std::list<int>[V];
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::dfs(int v, bool visited[])
{
	visited[v-1]=true;
	std::cout<<v<<"*";

	std::list<int>::iterator it;

	for(it=adj[v-1].begin();it!=adj[v-1].end();++it)
	{
		if(!visited[*it])
		{
			dfs(*it,visited);
		}
	}
}

void Graph::dfsPrint(int v)
{
	bool *visited=new bool[V];

 	std::cout<<V<<" * "<<std::endl;
	for (int i = 0; i < V; ++i)
	{
		visited[i]=false;
	}

	std::cout<<V<<" ** "<<std::endl;

	dfs(v,visited);
}

bool Graph::isCycle(int v,bool visited[],int parent)
{
	visited[v]=true;

	std::list<int>::iterator it;

	for(it=adj[v].begin();it!=adj[v].end();++it)
	{
		if(!visited[*it])
		{
			if(isCycle(*it,visited,v))
			{
				return true;
			}
		}

		else if(*it!=parent)
		{
			return true;
		}
	}
	return false;
}

bool Graph::isTree(int v)
{
	bool *visited=new bool[V];


	for(int i=0;i<V;++i)
	{
		visited[i]=false;
	}
	
	if(isCycle(v,visited,-1))
	{
		return false;
	}

	for(int i=0;i<V;++i)
	{
		if(!visited[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int V,E;
	std::cin>>V>>E;

	// std::multimap<int, int> map;

	Graph g(V);
	int lastV;
	for(int i=0;i<E;++i)
	{
		int u,v;
		std::cin>>u>>v;
		
		if(i==0){lastV=u;}
		g.addEdge(u,v);
	}

	g.dfsPrint(lastV);

	// std::cout<<g.isTree(lastV)<<std::endl;

	// bool cycle = existCycle(map);
	// bool connect=false;
	// // bool connect = isConnected(map);

	// std::cout<<"CYCLE: "<<cycle<<" CONNECT: "<<connect<<std::endl;

	// if(cycle==false && connect==true){std::cout<<"yes"<<std::endl;}
	// else{std::cout<<"no"<<std::endl;}

	return 0;
}