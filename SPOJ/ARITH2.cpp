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

/***************************************************************
/********************                 *******************************************
/*						ARITH2                                                 */
/********************                 *******************************************
/***************************************************************/

int main()
{
	int nInputs;
	std::cin>>nInputs;

	while(nInputs)
	{
		std::string str;

		std::getline(std::cin,str);
		// std::cout<<str.size()<<std::endl;
		if(str.size()!=0)
		{
			--nInputs;
			std::cout<<str<<std::endl;
		}
		// std::cin>>str;

	}

	return 0;
}