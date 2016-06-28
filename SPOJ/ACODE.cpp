#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
// #include <map>

// /***************************************************************
// /********************                 *******************************************
// /*						ACODE                                                   */
// /********************                 *******************************************
// /***************************************************************/

// bool validNum(const char& a, const char& b)
// {
// 	int val=a-'0';
// 	int val1=b-'0';

// 	// if(a=='0'){return false;}
// 	if(val==0 && val1==0){return false;}
// 	int num=val*10+val1;
// 	return num<27;
// }

// int numWays(const std::string& str)
// {
// 	int size=str.size();
// 	std::vector<int> vec(size,0);

// 	vec[0]=1;
	

// 	for(int i=1;i<size;++i)
// 	{
		

// 		if(str[i-1]=='0'){continue;}
// 		vec[i]=vec[i-1];
// 		if(validNum(str[i-1],str[i]))
// 		{
// 			if(i-2>0)
// 			vec[i]+=vec[i-2];

// 			else
// 			vec[i]+=1;
// 		}
// 	}

// 	return vec[vec.size()-1];
// }

// int main()
// {


// 	while(1)
// 	{
// 		std::string input;
// 		std::cin>>input;
		
// 		if(input[0]=='0'){break;}

// 		std::cout<<numWays(input)<<std::endl;
// 	}
		
// 	return 0;
// }

bool validNum(const char& a,const char& b)
{
	int num=(a-'0')*10 + (b-'0');

	if(a=='0'){return false;}

	return (num>0 && num<=26);
}

unsigned long numWays(const std::string& str)
{
	std::vector<unsigned long> num(str.size()+1,0);

	num[0]=1;
	num[1]=1;

	char prev=str[0];


	for(unsigned long i=1;i<str.size();++i)
	{
		// std::cout<<prev<<" "<<str[i]<<std::endl;

		if(validNum(prev,str[i]))
		{
			// std::cout<<"Here"<<std::endl;
			if(str[i]=='0')
			{
				num[i+1]=num[i-1];
				
				if(num[i+1]==0)
				{
					num[i+1]=1;
				}
			}
			
			else{num[i+1]=num[i]+num[i-1];}
		}
		else
		{
			num[i+1]=num[i];
			if(str[i]=='0'){num[i+1]=0;}
		}

		prev=str[i];
	}

	// std::copy(num.begin(),num.end(),std::ostream_iterator<unsigned long>(std::cout," "));
	// std::cout<<std::endl;
	return num[str.size()];
}

int main()
{
	while(1)
	{
		std::string str;
		std::cin>>str;
		if(str=="0"){break;}

		std::cout<<numWays(str)<<std::endl;
	}
	return 0;
}