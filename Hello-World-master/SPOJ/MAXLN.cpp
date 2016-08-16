#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>

/***************************************************************
/********************                 *******************************************
/*						MAXLN                                                   */
/********************                 *******************************************
/***************************************************************/

int main()
{

    // std::cout.sync_with_stdio(false);
    
	unsigned long long nInputs;
	std::cin>>nInputs;

	// std::vector<unsigned long long> elements;
	// elements.reserve(nInputs);

	int i=1;
	while(i<nInputs+1)
	{
		unsigned long long radius;
		std::cin>>radius;
		
		double result=4*radius*radius+0.25;
		
		std::cout<<"Case "<<i<<": ";
		printf("%0.2f\n", result);
		++i;
	}
	return 0;
}