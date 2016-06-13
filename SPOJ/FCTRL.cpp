#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>


// SPOJ FTCRL

/***************************************************************
/********************                 *******************************************
/*						FTCRL                                                    */
/********************                 *******************************************
/***************************************************************/

int Z(int n)
{
	int z=0;

	int count=1;

	int val = n;

	while(val>=5)
	{
		z+=val/5;
		val/=5;
	}

	return z;
}

int main()
{
	double numofInput;
	std::cin>>numofInput;

	std::vector<double> inputs;
	inputs.reserve(numofInput);

	for(int i =0;i<numofInput;++i)
	{
		double val;
		std::cin>>val;

		inputs.push_back(val);
	}

	for(int i=0;i<inputs.size();++i)
	{
		std::cout<<Z(inputs[i])<<std::endl;
	}

	return 0;
}