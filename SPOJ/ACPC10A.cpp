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
/*						ACPC10A                                                  */
/********************                 *******************************************
/***************************************************************/

double nextNum(const int& b,const int& c,const bool& AP)
{
	if(AP)
	{
		int diff= c-b;
		return c+diff;
	}

	else
	{
		double ratio = double(c)/double(b);
		return c*ratio;
	}
}

int main()
{

	while(1)
	{
		int a,b,c;
		std::cin>>a>>b>>c;
		if(a==0 && b==0 && c==0){break;}

		else if(2*b==a+c){std::cout<<"AP"<<" "<<nextNum(b,c,true)<<std::endl;}
		else if(b*b==a*c){std::cout<<"GP"<<" "<<nextNum(b,c,false)<<std::endl;}

	}

	return 0;
}