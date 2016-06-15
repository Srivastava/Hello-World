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
/*						AE00                                                 */
/********************                 *******************************************
/***************************************************************/

int main()
{

	int N;
	std::cin>>N;

	int i=1;

	int sum=0;
	while(floor(double(N)/i) - i + 1>0)
	{
		sum+=floor(double(N)/i) - i + 1;
		++i;
	}
	std::cout<<sum<<std::endl;
	return 0;

}