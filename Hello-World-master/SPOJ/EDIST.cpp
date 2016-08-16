#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
// #include <map>

// #define unsigned long ul
/***************************************************************
/********************                 *******************************************
/*						EDIST                                                   */
/********************                 *******************************************
/***************************************************************/



unsigned long levenshtein (const std::string& str1,const std::string& str2)
{

	int len1=str1.size();
	int len2=str2.size();
	// int len=len1>=len2 ? len2: len1;
	
	std::vector<std::vector<unsigned long> > num(len1+1,std::vector<unsigned long> (len2+1,0));

	for(int i=0;i<len1+1;++i)
	{
		num[i][0]=i;
	}

	for(int i=0;i<len2+1;++i)
	{
		num[0][i]=i;
	}

	int cost=0;
	for(int j=1;j<len2+1;++j)
	{
		for(int i=1;i<len1+1;++i)
		{
			if(str1[i-1]==str2[j-1])
			{
				cost=0;
			}
			else
			{
				cost=1;
			}

			num[i][j]=std::min(num[i-1][j]+1,std::min(num[i][j-1]+1,num[i-1][j-1]+cost));
		}
	}

	// for(int i=0;i<num.size();++i)
	// {
	// 	for(int j=0;j<num[i].size();++j)
	// 	{
	// 		std::cout<<num[i][j]<<",";
	// 	}
	// 	std::cout<<std::endl;
	// }
	return num[len1][len2];
}


int main()
{
	int nInputs;
	std::cin>>nInputs;

	while(nInputs--)
	{
		std::string strA,strB;
		std::cin>>strA>>strB;
		std::cout<<levenshtein(strA,strB)<<std::endl;
	}

	return 0;
}