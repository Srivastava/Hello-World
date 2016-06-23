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
/*						EASYPROB                                                 */
/********************                 *******************************************
/***************************************************************/

std::string ConvertToBinary(unsigned int n)
{
	std::string str="";
    if (n / 2 != 0) {
        str+=ConvertToBinary(n / 2);
    }

    str+='0'+ n%2;
    return str;
    // printf("%d", n % 2);
}

std::string result(std::string str)
{
	std::string temp;
	if(str=="1")
	{
		return "0";
	}

	else if(str=="10")
	{
		return "2";
	}

	else if(str=="11")
	{
		return "2+2(0)";
	}
	else if(str=="0")
	{
		return "";
	}
	else
	{

		int count=str.size()-1;
		for(int i=0;i<str.size();++i)
		{
			count=str.size()-1-i;
			if(i==str.size()-1){count=1;}
			int val=count*(str[i]-'0');

			if(val>0)
			{
				//temp+='+';
				temp+='0'+ 2;
				if(i==str.size()-2){temp+='+';continue;}
				// temp+='+';
				if(temp[temp.size()-1]=='+'){temp.erase(temp.begin()+temp.size()-1);}
				temp+='('+result(ConvertToBinary(val));
				if(temp[temp.size()-1]=='+'){temp.erase(temp.begin()+temp.size()-1);}
				temp+= ')';
				temp+='+';
				if(i==str.size()-1){temp.erase(temp.begin()+temp.size()-1);}
			}
		}
	}
	if(temp[temp.size()-1]=='+'){temp.erase(temp.begin()+temp.size()-1);}
	return temp;
}

int main()
{
	std::vector<int> input({137,1315,73,136,255,1384,16385});
	
	for(int i=0;i<input.size();++i)
	{

		std::cout<<input[i]<<"="<<result(ConvertToBinary(input[i]))<<std::endl;
	}
	std::copy(input.begin(),input.end(),std::ostream_iterator<int>(std::cout," "));
	return 0;
}