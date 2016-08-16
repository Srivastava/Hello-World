#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
// #include <map>

/***************************************************************
/********************                 *******************************************
/*						B                                                 */
/********************                 *******************************************
/***************************************************************/

int main()
{
	std::string n;
	std::cin>>n;

	std::string temp=n;
	std::reverse(n.begin(),n.end());

	temp+=n;
	std::cout<<temp<<std::endl;


	return 0;
}