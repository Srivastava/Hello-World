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

/***************************************************************
/********************                 *******************************************
/*						ARITH2                                                 */
/********************                 *******************************************
/***************************************************************/

int add(const int& n1,const int& n2)
{
	return n1+n2;
}

int mul(const int& n1,const int& n2)
{
	return n1*n2;
}
int divi(const int& n1,const int& n2)
{
	return n1/n2;
}
int sub(const int& n1,const int& n2)
{
	return n1-n2;
}

int result(const std::string& str)
{
	std::string temp="";
	int prev=0,curr=0,count=0,val=0;
	for(int i=0;i<str.size();++i)
	{
		char c=str[i];


		switch(c)
		{
			case '+' :
				curr=std::stoi(temp);
				prev=add(prev,curr);
				++count;temp="";
				break;
			case '*' :
				curr=std::stoi(temp);
				if(count==0){prev=1;}
				prev=mul(prev,curr);
				++count;temp="";
				break;
			case '-' :
				curr=std::stoi(temp);
				prev=sub(prev,curr);
				++count;temp="";
				break;
			case '/' :
				curr=std::stoi(temp);
				if(count==0){prev=1;}
				prev=divi(prev,curr);
				++count;temp="";
				break;
			case '=':
				break;
			default:
				temp+=c;
				break;
		}
			

			c=str[i];
			if(c=='='){break;}
		

	}
	return prev;
}
int main()
{
	int nInputs;
	std::cin>>nInputs;

	while(nInputs)
	{
		std::string str;

		std::getline(std::cin,str);
		// std::cout<<str.size()<<std::endl;
		if(str.size()!=0)
		{
			--nInputs;
			std::cout<<str<<std::endl;
			str.erase(std::remove(str.begin(),str.end(),' '),str.end());
			std::cout<<str<<std::endl;
			std::cout<<result(str)<<std::endl;
		}


		// std::cin>>str;

	}

	return 0;
}