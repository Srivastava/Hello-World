#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>

/***************************************************************
/********************                 *******************************************
/*						FTCRL2                                                   */
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
	
	int numofImputs;
	std::cin>>numofImputs;

	for(int i=0;i<numofImputs;++i)
	{
		int val;
		std::cin>>val;

		std::vector<int> ans=factorial(val);

		std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, ""));
		std::cout<<std::endl;

	}

	return 0;
}