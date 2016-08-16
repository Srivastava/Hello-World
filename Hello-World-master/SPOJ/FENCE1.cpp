#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>

#include <iomanip>

/***************************************************************
/********************                 *******************************************
/*						FENCE1                                                 */
/********************                 *******************************************
/***************************************************************/

const double PI=3.14159265359;
int main()
{
	
	while(1)
	{
		double val;
		std::cin>>val;
		if(val==0){break;}
		
		else
		{
			double r=val*val/(2*PI);
			// std::cout<<std::setprecision(2)<<val*val/(2*PI)<<std::endl;
			printf("%0.2f\n",r);
		}
	}
	return 0;
}