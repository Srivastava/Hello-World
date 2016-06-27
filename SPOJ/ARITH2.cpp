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
#include <sstream>

/***************************************************************
/********************                 *******************************************
/*						ARITH2                                                 */
/********************                 *******************************************
/***************************************************************/

// unsigned long long add(const int& n1,const int& n2)
// {
// 	return n1+n2;
// }

// int mul(const int& n1,const int& n2)
// {
// 	return n1*n2;
// }
// int divi(const int& n1,const int& n2)
// {
// 	return (double)n1/n2;
// }
// int sub(const int& n1,const int& n2)
// {
// 	return n1-n2;
// }

// int result(const std::string& str)
// {
// 	// std::string temp="";
// 	int prev=str[0]-'0',curr=0,count=0,val=0;
// 	char prevC;
// 	for(int i=0;i<str.size();++i)
// 	{
// 		char c=str[i];

// 		std::cout<<prev<<std::endl;

// 		switch(c)
// 		{
// 			case '+' :
// 				// prevC=c;
// 				++i;
// 				curr=str[i]-'0';
// 				prev=add(prev,curr);
// 				// ++count;
// 				// temp="";
// 				break;
// 			case '*' :
// 				++i;
// 				curr=str[i]-'0';
// 				//if(count==0){prev=1;}
// 				prev=mul(prev,curr);
// 				// ++count;temp="";
// 				break;
// 			case '-' :
// 				++i;
// 				curr=str[i]-'0';
// 				prev=sub(prev,curr);
// 				// ++count;temp="";
// 				break;
// 			case '/' :
// 				++i;
// 				curr=str[i]-'0';
// 				//if(count==0){prev=1;}
// 				prev=divi(prev,curr);
// 				// ++count;temp="";
// 				break;
// 			case '=':
// 				break;
// 			default:
// 				// temp+=c;
// 				break;
// 		}
			

// 			c=str[i];
// 			if(c=='='){break;}
		

// 	}
// 	return prev;
// }
// int main()
// {
// 	int nInputs;
// 	std::cin>>nInputs;

// 	while(nInputs)
// 	{
// 		std::string str;

// 		std::getline(std::cin,str);
// 		// std::cout<<str.size()<<std::endl;
// 		if(str.size()!=0)
// 		{
// 			--nInputs;
// 			std::cout<<str<<std::endl;
// 			std::vector<int> input;
// 			std::istringstream is( str );
// 	    	int n;
// 		    while( is >> n ) 
// 		    {
//          		input.push_back(n);

// 		    }
// 			str.erase(std::remove(str.begin(),str.end(),' '),str.end());
// 			std::cout<<str<<std::endl;

// 		    std::copy(input.begin(),input.end(),std::ostream_iterator<int>(std::cout," "));

// 			// std::cout<<result(str)<<std::endl;
// 		}


// 		// std::cin>>str;

// 	}

// 	return 0;
// }


int main()
{
	unsigned long long nInputs;
	std::cin>>nInputs;

	while(nInputs--)
	{
		unsigned long long num;
		std::cin>>num;

		char oper;
		while(1)
		{
			std::cin>>oper;
			if(oper=='='){break;}

			unsigned long long n;
			std::cin>>n;

			switch(oper)
			{
				case '+':
				num+=n;
				break;

				case '*':
				num*=n;
				break;

				case '-':
				num-=n;
				break;

				case '/':
				num/=n;
				break;

			}
		}
		std::cout<<num<<std::endl;
	}
}