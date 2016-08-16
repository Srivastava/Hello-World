#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>


/***************************************************************
/********************                 *******************************************
/*						NHAY                                                   */
/********************                 *******************************************
/***************************************************************/

std::vector<int> createLPS(const std::string& str)
{
	std::vector<int> lps(str.size(),0);

	int j=0;
	for(int i=1;i<str.size();)
	{
		if(str[i]==str[j])
		{
			lps[i]=1+j;
			++i;
			++j;
		}

		else
		{
			int index= (j==0) ? 0:j-1;
			j=lps[index];
			if(j==0)
			{
				lps[i]=j;
				++i;
			}
		}
		// std::cout<<"j: "<<j<<" i: "<<i<<" str[i] & str[j]: "<<str[i]<<" "<<str[j]<<" lps "<<lps[j]<<std::endl;
	}
	// std::copy(lps.begin(),lps.end(),std::ostream_iterator<int>(std::cout,"*"));
	return lps;
}

std::vector<int> KMP(const std::string& needle,const std::string& hay)
{
	std::vector<int> lps=createLPS(needle);

	std::vector<int> indices;
	int j=0;
	for(int i=0;i<hay.size();)
	{
		// std::cout<<j<<" "<<i<<std::endl;
		if(hay[i]==needle[j])
		{
			++i;
			++j;
		}

		if(j==needle.size())
		{
			// std::cout<<i-j<<std::endl;
			indices.push_back(i-j);
			int index=(j==0) ? 0:j-1;
			j=lps[index];
			// j=0;
		}
		else if(hay[i]!=needle[j])
		{
			// int index=(j==0) ? 0:j-1;
			// j=lps[index];

			if(j!=0)
				j=lps[j-1];
			else
				++i;

			// if(j==0){++i;}
		}
	}
	// std::copy(lps.begin(),lps.end(),std::ostream_iterator<int>(std::cout,"*"));
	return indices;
}		


// void KMP(const std::string& needle,const char& c,const std::vector<int>& lps,unsigned long long& j,unsigned long long i)
// {
// 	// std::vector<int> lps=createLPS(needle);

// 	// std::vector<int> indices;
// 	// int j=0;
// 	// for(int i=0;i<hay.size();)
// 	{
// 		// std::cout<<j<<" "<<i<<std::endl;
// 		if(c==needle[j])
// 		{
// 			// ++i;
// 			++j;
// 		}

// 		if(j==needle.size())
// 		{
// 			// std::cout<<i-j<<std::endl;
// 			// indices.push_back(i-j);
// 			std::cout<<i-j<<std::endl;
// 			int index=(j==0) ? 0:j-1;
// 			j=lps[index];
// 			// j=0;
// 		}
// 		else if(c!=needle[j])
// 		{
// 			// int index=(j==0) ? 0:j-1;
// 			// j=lps[index];

// 			if(j!=0)
// 				j=lps[j-1];
// 			else
// 				++i;

// 			// if(j==0){++i;}
// 		}
// 	}
// 	// std::copy(lps.begin(),lps.end(),std::ostream_iterator<int>(std::cout,"*"));
// 	// return indices;
// }	


// int main()
// {
// 	int len;

// 	while(std::cin>>len)
// 	{
// 		// std::cout<<" while loop "<<std::endl;
// 		std::string needle;

// 		std::cin>>needle;
		
// 		std::vector<int> lps=createLPS(needle);
// 		char c;
// 		unsigned long long count=0,j=0;
// 		while(std::cin>>c)
// 		{
			
// 			KMP(needle,c,lps,j,count);
// 		}
// 		// std::cout<<" while loop 1 "<<std::endl;


// 		// std::cout<<" while loop 2"<<std::endl;

// 		// std::copy(ans.begin(),ans.end(),std::ostream_iterator<int>(std::cout," "));
// 		// std::cout<<std::endl;
// 	}

// 	return 0;
// }

int main()
{
	int len;

	while(std::cin>>len)
	{
		// std::cout<<" while loop "<<std::endl;
		std::string needle,hay;

		std::cin>>needle>>hay;

		// std::cout<<" while loop 1 "<<std::endl;

		std::vector<int> ans = KMP(needle,hay);

		// std::cout<<" while loop 2"<<std::endl;

		std::copy(ans.begin(),ans.end(),std::ostream_iterator<int>(std::cout," "));
		std::cout<<std::endl;
	}

	return 0;
}