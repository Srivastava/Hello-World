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
/*						CANTON                                                 */
/********************                 *******************************************
/***************************************************************/

std::pair<long long,long long> cantor(const long long& num)
{

	long i=floor(sqrt(num))+1;

	long index=0;
	while(1)
	{
		if(i*(i+1)/2>=num){index=i;break;}
		++i;
	}

	long diff=(i*(i+1)/2)-num;
	
	long numerator=index-diff;
	long denominator=1+diff;

	if(index%2!=0){return std::make_pair(denominator,numerator);}
	else{return std::make_pair(numerator,denominator);}

}

int main()
{
	int numofInputs;
	int i=0;

	std::cin>>numofInputs;
	while(i<numofInputs)
	{
		long long val;
		std::cin>>val;
		
		++i;
		// std::cout<<i<<" I "<<std::endl;

		if(val==1){std::cout<<"TERM "<<val<<" IS "<<"1/1"<<std::endl;continue;}
		if(val==2){std::cout<<"TERM "<<val<<" IS "<<"1/2"<<std::endl;continue;}		
		if(val==3){std::cout<<"TERM "<<val<<" IS "<<"2/1"<<std::endl;continue;}
		
		std::pair<long long,long long> ans=cantor(val);

		std::cout<<"TERM "<<val<<" IS "<<ans.first<<"/"<<ans.second<<std::endl;
		
	}

	long num;
	return 0;
}