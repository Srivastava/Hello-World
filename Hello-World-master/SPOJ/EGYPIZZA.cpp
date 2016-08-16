#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include <string>
#include <set>

/***************************************************************
/********************                 *******************************************
/*						EGYPIZZA                                                 */
/********************                 *******************************************
/***************************************************************/

int numPizza(const std::vector<std::string>& vstr)
{
	std::vector<double> pizzas(vstr.size(),1);
	std::vector<double> temp(vstr.size(),0);

	for(int i=0;i<vstr.size();++i)
	{
		std::string c=vstr[i];
		double val;
		if(c=="1/4")
		{
			val=0.25;
		}
		else if(c=="1/2")
		{
			val=0.5;
		}
		else
		{
			val=0.75;
		}

		// std::cout<<val<<std::endl;
		temp[i]=val;

	}

	std::sort(temp.begin(),temp.end());
	std::reverse(temp.begin(),temp.end());

	// std::copy(temp.begin(), temp.end(), std::ostream_iterator<double>(std::cout, " "));
	// std::cout<<std::endl;

	for(int i =0;i<temp.size();++i)
	{
		double val=temp[i];
		bool found=false;
		for(int j=0;j<i;++j)
		{
			if(pizzas[j]>=val && pizzas[j]!=1)
			{
				pizzas[j]-=val;
				found=true;
				break;
			}
		}
		if(!found)
		{
			pizzas[i]-=val;
		}
	}

	// std::copy(pizzas.begin(), pizzas.end(), std::ostream_iterator<double>(std::cout, " "));
	// std::cout<<std::endl;

	int count=1;
	for(int i=0;i<pizzas.size();++i)
	{
		if(pizzas[i]<1)
		{
			++count;
		}
	}

	return count;

}

int main()
{
	int nInputs;

	std::cin>>nInputs;
	
	std::vector<std::string> vstr;
	while(nInputs--)
	{
		std::string str;
		std::cin>>str;

		vstr.push_back(str);
	}

	std::cout<<numPizza(vstr)<<std::endl;

	return 0;
}