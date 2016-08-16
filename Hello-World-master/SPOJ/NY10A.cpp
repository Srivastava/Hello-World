#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include <unordered_map>

/***************************************************************
/********************                 *******************************************
/*						NY10A                                                 */
/********************                 *******************************************
/***************************************************************/

int main()
{
	// TTT, TTH, THT, THH, HTT, HTH, HHT and HHH
	
	std::unordered_map<std::string,int> myMap;

	myMap.insert({"TTT",0});
	myMap.insert({"TTH",1});
	myMap.insert({"THT",2});
	myMap.insert({"THH",3});
	myMap.insert({"HTT",4});
	myMap.insert({"HTH",5});
	myMap.insert({"HHT",6});
	myMap.insert({"HHH",7});

	int nInputs;
	std::cin>>nInputs;

	// std::cout<<"Here E"<<std::endl;
	while(nInputs--)
	{
		int id;
		std::cin>>id;

		// std::cout<<"Here E 1"<<std::endl;

		std::string str;
		std::cin>>str;

		// std::cout<<"Here E 2"<<std::endl;
		
		std::vector<int> val(8,0);


		// std::cout<<"Here E 3 "<<str<<std::endl;

		for(int i=0;i<str.size()-2;++i)
		{
			std::string temp=str.substr(i,3);
			// std::cout<<i<<"*"<<temp<<" * ";
			int index=myMap[temp];

			val[index]+=1;
		}

		// std::cout<<"Here E 4"<<std::endl;
		std::cout<<id<<" ";
		std::copy(val.begin(), val.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout<<std::endl;
	}

	return 0;
}