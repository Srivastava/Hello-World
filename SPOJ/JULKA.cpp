#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>

/***************************************************************
/********************                 *******************************************
/*						JULKA                                                   */
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

std::vector<int> subtract(const std::string& str, const std::string& str2)
{
	int carry=0;
	std::vector<int> result;

	std::cout<<str.size()<<" "<<result.size()<<" Size"<<std::endl;
	for(int i=0;i<str2.size();++i)
	{
		int val=(str[i]-'0')+carry;
		int val2=str2[i]-'0';

		std::cout<<val<<" "<<val2<<" Val"<<std::endl;


		if(val>=val2)
		{
			carry=0;
			result.push_back(val-val2);
		}

		else
		{
			result.push_back(10+val-val2);
			carry=-1;
		}

	}

	int i = str2.size();
	while(carry!=0)
	{
		std::cout<<carry<<" "<<i<<" carry"<<std::endl;

		int val=(str[i]-'0')+carry;

		if(val>=0){carry=0;result.push_back(val);++i;break;}
		else
		{
			result.push_back(10+val); ++i;carry=-1;
		}

	}

	while(i<str.size())
	{
		int val=str[i]-'0';
		if(i==str.size()-1 && val==0){break;}
		result.push_back(val);
		++i;
	}

	if(result[result.size()-1]==0){result.erase(result.begin()+result.size()-1);}

	std::reverse(result.begin(),result.end());
	
	return result;
}

// std::vector<int> numApples(const std::string& str, const std::string& more)
// {

// 	for(int i=0;i<more.size;++i)
// 	{

// 	}
// }

int main()
{
	

	for(int i=0;i<10;++i)
	{
		std::string numofApples;
		std::cin>>numofApples;

		std::string more;
		std::cin>>more;

		// numApples(numofApples,more);
		std::reverse(numofApples.begin(),numofApples.end());
		std::reverse(more.begin(),more.end());

		std::vector<int> ans=subtract(numofApples,more);
		
		mulitply(5,ans);
		// ans.erase(ans.begin()+ans.size()-1);
		std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, ""));
		std::cout<<std::endl;

	}

	return 0;
}