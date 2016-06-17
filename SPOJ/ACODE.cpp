#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <map>

/***************************************************************
/********************                 *******************************************
/*						ACODE                                                   */
/********************                 *******************************************
/***************************************************************/

bool validNum(const char& a, const char& b)
{
	int val=a-'0';
	int val1=b-'0';

	// if(a=='0'){return false;}
	if(val==0 && val1==0){return false;}
	int num=val*10+val1;
	return num<27;
}

int numWays(const std::string& str)
{
	int size=str.size();
	std::vector<int> vec(size,0);

	vec[0]=1;
	

	for(int i=1;i<size;++i)
	{
		

		if(str[i-1]=='0'){continue;}
		vec[i]=vec[i-1];
		if(validNum(str[i-1],str[i]))
		{
			if(i-2>0)
			vec[i]+=vec[i-2];

			else
			vec[i]+=1;
		}
	}

	return vec[vec.size()-1];
}

int main()
{


	while(1)
	{
		std::string input;
		std::cin>>input;
		
		if(input[0]=='0'){break;}

		std::cout<<numWays(input)<<std::endl;
	}
		
	return 0;
}