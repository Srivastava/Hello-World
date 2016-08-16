#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>

/***************************************************************
/********************                 *******************************************
/*						BISHOPS                                                   */
/********************                 *******************************************
/***************************************************************/

void mulitply(const int& x, std::vector<int>& num)
{
	int size=num.size();

	int carry=0;

	for(int i=0;i<size;++i)
	{
		int mul=num[i] * x + carry;
		num[i]=mul%10;
		carry=mul/10;
	}

	while(carry)
	{
		num.push_back(carry%10);
		carry/=10;
	}

}


void subtract(const int& x, std::vector<int>& num)
{
	int size=num.size();

	int carry=0;

	for(int i=0;i<size;++i)
	{
		int sub=0;
		if(num[i]>=x+carry)
		{
			sub=num[i]-x-carry;
			carry=0;
		}
		else
		{
			sub=10+num[i]-x-carry;
			carry=-1;
		}
		// int sub=num[i] * x + carry;
		num[i]=sub;
		if(carry==0){break;}
		// carry=mul/10;
	}

	std::reverse(num.begin(),num.end());

	for(int i=0;i<size;++i)
	{
		if(num[i]==0){num.erase(num.begin()+i);}
		else{break;}
	}
	// for(int i=size-1;i>=0;--i)
	// {
	// 	if(num[i]==0)
	// 	{
	// 		num.erase(num.begin()+i);
	// 	}
	// }
	// while(carry)
	// {
	// 	num.push_back(carry%10);
	// 	carry/=10;
	// }

}

std::vector<int> factorial(const int& n)

{	std::vector<int> num;
	num.reserve(100);
	num.push_back(1);

	for(int i = 1;i<=n;++i)
	{
		mulitply(i,num);
	}
	std::reverse(num.begin(),num.end());
	return num;
}

int main()
{
	
	while(1)
	{

		std::string input;
		
		std::getline(std::cin,input);
		// std::cin>>input;

		if(std::cin.eof())
		{
			break;
		}

		std::vector<int> num(input.size(),0);
		// std::cout<<input.size()<<" SIZE "<<std::endl;

		if(input.size()==1 && input[0]=='0'){std::cout<<0<<std::endl;}
		else if(input.size()==1 && input[0]=='1'){std::cout<<1<<std::endl;}
		else
		{
			for(int i=0;i<input.size();++i)
			{
				num[i]=input[i]-'0';
			}

			// std::copy(num.begin(), num.end(), std::ostream_iterator<int>(std::cout, ""));

			std::reverse(num.begin(),num.end());
			
			mulitply(2,num);
			subtract(2,num);
			
			// std::reverse(num.begin(),num.end());


			// num[num.size()-1]-=2;
			std::copy(num.begin(), num.end(), std::ostream_iterator<int>(std::cout, ""));
			
			std::cout<<std::endl;
			
		}


	}


	// for(int i=0;i<numofImputs;++i)
	// {
	// 	int val;
	// 	std::cin>>val;

	// 	std::vector<int> ans=factorial(val);

	// 	std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, ""));
	// 	std::cout<<std::endl;

	// }

	return 0;
}