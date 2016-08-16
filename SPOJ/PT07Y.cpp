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

// struct Node
// {
// 	int v;
// 	int index;
// };

// class Graph
// {
// 	int V;
// 	Node node;
// 	std::list<Node> *adj;

// 	void dfs(Node node, bool visited[]);
// 	bool isCycle(Node node, bool visited[],Node parent);

// public:
// 	Graph(int V);
// 	void addEdge(Node n1,Node n2);
// 	bool isTree(Node n1);
// 	void dfsPrint(Node n1);
// 	// void print()

// };

// Graph::Graph(int V)
// {
// 	this->V=V;
// 	adj=new std::list<int>[V];
// }

// void Graph::addEdge(Node n1,Node n2)
// {
// 	adj[n1.index].push_back(n2);
// 	adj[n2.index].push_back(n1);
// }

// void Graph::dfs(Node n1, bool visited[])
// {
// 	visited[n1.index]=true;
// 	std::cout<<n1.v<<"*";

// 	std::list<Node>::iterator it;

// 	for(it=adj[n1.index].begin();it!=adj[n1.index].end();++it)
// 	{
// 		if(!visited[*it.index])
// 		{
// 			dfs(*it,visited);
// 		}
// 	}
// }

// void Graph::dfsPrint(Node n1)
// {
// 	bool *visited=new bool[V];

//  	std::cout<<V<<" * "<<std::endl;
// 	for (int i = 0; i < V; ++i)
// 	{
// 		visited[i]=false;
// 	}

// 	std::cout<<V<<" ** "<<std::endl;

// 	dfs(n1,visited);
// }

// bool Graph::isCycle(Node n1,bool visited[],Node parent)
// {
// 	visited[n1.index]=true;

// 	std::list<Node>::iterator it;

// 	for(it=adj[n1.index].begin();it!=adj[n1.index].end();++it)
// 	{
// 		if(!visited[*it])
// 		{
// 			if(isCycle(*it,visited,n1))
// 			{
// 				return true;
// 			}
// 		}

// 		else if(*it.v!=parent.v)
// 		{
// 			return true;
// 		}
// 	}
// 	return false;
// }

// bool Graph::isTree(Node n1)
// {
// 	bool *visited=new bool[V];


// 	for(int i=0;i<V;++i)
// 	{
// 		visited[i]=false;
// 	}
	
// 	Node parent;
// 	parent.v=-1;
// 	parent.index=-1;
// 	if(isCycle(n1,visited,parent))
// 	{
// 		return false;
// 	}

// 	for(int i=0;i<V;++i)
// 	{
// 		if(!visited[i])
// 		{
// 			return false;
// 		}
// 	}
// 	return true;
// }

// int main()
// {
// 	int V,E;
// 	std::cin>>V>>E;

// 	// std::multimap<int, int> map;

// 	Graph g(V);
// 	int lastV;
// 	for(int i=0;i<E;++i)
// 	{
// 		int u,v;

// 		std::cin>>u>>v;
		
// 		Node n1,n2;
// 		n1.v=u;
// 		n1.index=

// 		if(i==0){lastV=u;}
// 		g.addEdge(u,v);
// 	}

// 	g.dfsPrint(lastV);

// 	// std::cout<<g.isTree(lastV)<<std::endl;

// 	// bool cycle = existCycle(map);
// 	// bool connect=false;
// 	// // bool connect = isConnected(map);

// 	// std::cout<<"CYCLE: "<<cycle<<" CONNECT: "<<connect<<std::endl;

// 	// if(cycle==false && connect==true){std::cout<<"yes"<<std::endl;}
// 	// else{std::cout<<"no"<<std::endl;}

// 	return 0;
// }


bool dfs(const std::vector<std::vector<int> >& graph,const int& index)
{
	std::vector<bool> visited(graph.size(),false);
	
	std::stack<int> nodes;
	nodes.push(graph[index][0]);
	// visited[index]=true;

	int temp;
	while(!nodes.empty())
	{
		temp=nodes.top();

		nodes.pop();

		// std::cout<<temp<<"*"<<std::endl;

		if(visited[temp])
		{
			return false;
		}

		visited[temp]=true;
		// std::cout<<temp<<" TEMP"<<std::endl;
		// std::cout<<graph[temp].size()<<" graph Size"<<std::endl;
		for(int i=1;i<graph[temp].size();++i)
		{
			nodes.push(graph[temp][i]);
		}
	}

	// std::cout<<"Here"<<std::endl;
	for(int i=1;i<visited.size();++i)
	{
		if(visited[i]==false)
		{
			return false;
		}
	}

	return true;
	
}

int main()
{
	int v,e;
	std::cin>>v>>e;


	std::vector<std::vector<int> > graph(v+1,std::vector<int> (1,0));

	int i=0;
	while(i<e)
	{
		int u,v;
		std::cin>>u>>v;

		graph[u][0]=u;
		graph[v][0]=v;
		graph[u].push_back(v);
		// graph[v]
		++i;
	}	

	// for(int i=0;i<graph.size();++i)
	// {
	// 	for(int j=0;j<graph[i].size();++j)
	// 	{
	// 		std::cout<<graph[i][j]<<",";
	// 	}
	// 	std::cout<<std::endl;
	// }

	if(dfs(graph,1) && e+1==v)
	{
		std::cout<<"YES"<<std::endl;
	}

	else
	{
		std::cout<<"NO"<<std::endl;
	}

	return 0;
}