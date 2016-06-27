#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
// #include <unordered_map>

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

		double s=(a+b+c+d)/2;
		// s/=2;
		double area=sqrt((s-a)*(s-b)*(s-c)*(s-d));

		printf("%0.2lf\n",area);
	}

	return 0;
}