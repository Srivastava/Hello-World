#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <map>

/***************************************************************
/********************                 *******************************************
/*						PALIN                                                   */
/********************                 *******************************************
/***************************************************************/

std::string toString (const int& num)
{
	std::string str;
	int n=num;

	while(n!=0)
	{
		str.push_back(n%10+'0');
		n=n/10;
		// std::cout<<n<<std::endl;
	}

	std::reverse(str.begin(),str.end());

	return str;
}


// int nextPalin(const int& num)
// {
// 	int next=0;

// 	std::string str=toString(num);

// 	int size=str.size();

// 	// std::cout<<str<<" "<<size<<" string"<<std::endl;

// 	bool odd=false;

// 	if(size%2!=0){odd=true;}

// 	if(odd)
// 	{
// 		for(int i=0;i<size/2;++i)
// 		{
// 			if(str[size/2-i-1]<str[size/2+i+1])
// 			{
// 				str[size/2-i-1]+=1;
// 				str[size/2+i+1]=str[size/2-i-1];
// 			}
// 			else
// 			{
// 				str[size/2+i+1]=str[size/2-i-1];
// 			}

// 		}
// 	}
// 	else
// 	{
// 		for(int i=0;i<=size/2;++i)
// 		{
// 			if(str[size/2-i-1]<str[size/2+i])
// 			{
// 				str[size/2-i-1]+=1;
// 				str[size/2+i]=str[size/2-i-1];
// 			}
// 			else
// 			{
// 				str[size/2+i]=str[size/2-i-1];
// 			}

// 		}

// 	}
		

// 	for(int i=size-1;i>=0;--i)
// 	{
// 		char c = str[i];

// 		next+=(c-'0')*std::pow(10,size-1-i);

// 	}


// 	return next;
// }

int nextPalin(const int& num)
{
	int next=0;

	std::string str=toString(num);

	int size=str.size();

	// std::cout<<str<<" "<<size<<" string"<<std::endl;

	std::vector<std::string> strvec;
	std::vector<int> intvec;

	bool odd=false;

	if(size%2!=0){odd=true;}

	if(odd)
	{
		
		// std::cout<<" Here odd"<<std::endl;

		std::string str1=str.substr(0,size/2);
		

		std::string str3=str1;
		std::reverse(str1.begin(),str1.end());

		str1=str3+str[size/2]+str1;
		strvec.push_back(str1);
		
		str1[size/2]+=1;
		strvec.push_back(str1);

		str1=str.substr(size/2+1,size/2);
		str3=str1;
		std::reverse(str1.begin(),str1.end());

		str1=str1+str[size/2]+str3;
		strvec.push_back(str1);
		
		str1[size/2]+=1;
		strvec.push_back(str1);

		for(int i=0;i<str.size();++i)
		{
			std::string str2(size,str[i]);
			strvec.push_back(str2);
		}


	}

	else
	{
		// std::cout<<" Here Even"<<std::endl;

		std::string str1=str.substr(0,size/2);
		
		std::string str3=str1;
		std::reverse(str1.begin(),str1.end());

		str1=str3+str1;
		strvec.push_back(str1);
		
		str1[size/2]+=1;
		str1[size/2-1]+=1;
		strvec.push_back(str1);

		str1=str.substr(size/2,size/2);
		str3=str1;
		std::reverse(str1.begin(),str1.end());
		str1=str1+str3;
		strvec.push_back(str1);
		
		str1[size/2]+=1;
		str1[size/2-1]+=1;

		strvec.push_back(str1);

		for(int i=0;i<str.size();++i)
		{
			std::string str2(size,str[i]);
			strvec.push_back(str2);
		}
		

	}
		

	for(int j=0;j<strvec.size();++j)
	{
		std::string tempStr=strvec[j];
		int temp=0;
		for(int i=size-1;i>=0;--i)
		{
			char c = tempStr[i];

			temp+=(c-'0')*std::pow(10,size-1-i);

		}
		intvec.push_back(temp);
	}

	std::sort(intvec.begin(),intvec.end());

	for(int i=0;i<intvec.size();++i)
	{
		if(intvec[i]>num)
		{
			next=intvec[i];
			break;
		}
	}
	
	std::copy(intvec.begin(), intvec.end(), std::ostream_iterator<int>(std::cout, " * "));
	return next;
}


int main()
{
	int testCases;
	std::cin>>testCases;

	int i=0;

	while(i<testCases)
	{
		int num;
		std::cin>>num;

		if(num<=10){std::cout<<11<<std::endl;continue;}
		std::cout<<nextPalin(num)<<std::endl;
		++i;
	}
	
	
	return 0;
}