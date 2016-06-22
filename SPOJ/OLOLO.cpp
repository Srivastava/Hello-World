#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>

/***************************************************************
/********************                 *******************************************
/*						OLOLO                                                   */
/********************                 *******************************************
/***************************************************************/

int main()
{

    std::cout.sync_with_stdio(false);
    
	unsigned long long nInputs;
	std::cin>>nInputs;

	// std::vector<unsigned long long> elements;
	// elements.reserve(nInputs);

	unsigned long long pyani;
	std::cin>>pyani;
	

	nInputs-=1;
	while(nInputs--)
	{
		unsigned long long pyani1;
		std::cin>>pyani1;
		pyani^=pyani1;

	}
	std::cout<<pyani<<std::endl;
	return 0;
}