#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>

/***************************************************************
/********************                 *******************************************
/*						SAMER08F                                                  */
/********************                 *******************************************
/***************************************************************/

int SoQ(const int& n)
{
	return n*(n+1)*(2*n+1)/6;
}

int main()
{

	while(1)
	{
		int val;
		std::cin>>val;
		if(val==0){break;}

		std::cout<<SoQ(val)<<std::endl;

	}

	return 0;
}