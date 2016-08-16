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
/*						A                                                   */
/********************                 *******************************************
/***************************************************************/

int main()
{
	int nOppo,nDays;
	std::cin>>nOppo>>nDays;

	int days=nDays;

	int count=0,max=0;
	
	while(days--)
	{
		std::string str;
		std::cin>>str;

		int i=0;
		for(i=0;i<str.size();++i)
		{
			if(str[i]-'0'==0)
			{
				++count;
				break;
			}
		}

		if(i==str.size()){count=0;}
		if(count>max)
		{
			max=count;
		}
	}

	std::cout<<max<<std::endl;

	return 0;
}