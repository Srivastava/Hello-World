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
/*						WILLIST                                                 */
/********************                 *******************************************
/***************************************************************/

int main()
{
	long long val;
	std::cin>>val;

	
	if(val<=1 || (val&(val-1))){std::cout<<"NIE"<<std::endl;}
	else
	{
		std::cout<<"TAK"<<std::endl;
	}
	return 0;
}