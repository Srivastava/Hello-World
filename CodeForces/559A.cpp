#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

int main()
{
	int a1,a2,a3,a4,a5,a6;

	std::cin>>a1>>a2>>a3>>a4>>a5>>a6;

	unsigned long sum=a1+a2+a3;

	std::cout<<sum*sum - a1*a1 - a3*a3 - a5*a5<<std::endl;

	return 0;
}