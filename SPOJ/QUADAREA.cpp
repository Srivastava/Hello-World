#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <unordered_map>

/***************************************************************
/********************                 *******************************************
/*						QUADAREA                                                   */
/********************                 *******************************************
/***************************************************************/

int main()
{

	int nInputs;
	std::cin>>nInputs;

	while(nInputs--)
	{
		double a,b,c,d;
		std::cin>>a>>b>>c>>d;

		double s=a+b+c+d;
		s/=2;
		std::cout<<sqrt((s-a)*(s-b)*(s-c)*(s-d))<<std::endl;
	}

	return 0;
}