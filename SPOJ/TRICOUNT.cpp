#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>

long long nTri(const long long& level)
{

	return floor(level*(level+2)*(2*level+1)/8);
}

int main()
{

	long long numofInputs;
	std::cin>>numofInputs;
	
	long long i=0;
	while(i<numofInputs)
	{
		++i;

		long long level;
		std::cin>>level;

		std::cout<<nTri(level)<<std::endl;
	}

	return 0;
}