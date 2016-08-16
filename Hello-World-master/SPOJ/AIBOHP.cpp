#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
// #include <map>

/***************************************************************
/********************                 *******************************************
/*						AIBOHP                                                   */
/********************                 *******************************************
/***************************************************************/


int aux(const std::string& str,const std::string& str1)
{
	std::vector<std::vector<unsigned long> > num(str1.size()+1,std::vector<unsigned long> (str.size()+1,0));

	for(int i=0;i<str1.size();++i)
	{
		for(int j=0;j<str.size();++j)
		{
			if(str1[i]==str[j])
			{
				num[i+1][j+1]=num[i][j]+1;
			}
			else
			{
				num[i+1][j+1]=std::max(num[i][j+1],num[i+1][j]);
			}
		}
	}

	// for(int i=0;i<str1.size()+1;++i)
	// {
	// 	for(int j=0;j<str.size()+1;++j)
	// 	{
	// 		std::cout<<num[i][j]<<",";
	// 	}
	// 	std::cout<<std::endl;
	// }

	return num[str1.size()][str.size()];
}

int LCS(const std::string& str)
{
	std::string temp=str;

	std::reverse(temp.begin(),temp.end());

	int val=aux(str,temp);

	return str.size()-val;
}


// int LCS(const std::string& str,const std::string& str2)
// {
// 	std::string temp=str;

// 	std::reverse(temp.begin(),temp.end());

// 	int val=aux(str,str2);

// 	return val;
// }

int main()
{
	int nInputs;
	std::cin>>nInputs;

	while(nInputs--)
	{
		std::string str,str1;

		std::cin>>str;//>>str1;

		std::cout<<LCS(str)<<std::endl;
	}

	return 0;
}