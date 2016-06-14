#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>

/***************************************************************
/********************                 *******************************************
/*						ONP                                                   */
/********************                 *******************************************
/***************************************************************/

/* Using Shutting Yard Algorithm */

bool isOper(const char& c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void addOpertoVar(std::stack<char>& oper, std::queue<char>& queue)
{
	while(!oper.empty())
	{
		char c = oper.top();

		if(c=='('){oper.pop();break;}

		queue.push(c);
		oper.pop();
	}
}

std::string reversePolish(const std::string& str)
{
	std::string reverse;
	std::stack<char> oper;
	std::queue<char> var;

	int size=str.size();
	
	for(int i=0;i<size;++i)
	{
		if(str[i]=='(' || isOper(str[i]))
		{
			oper.push(str[i]);
		}

		else if(str[i]==')')
		{
			addOpertoVar(oper,var);
		}

		else
		{
			var.push(str[i]);
		}
	}

	addOpertoVar(oper,var);

	while(!var.empty())
	{
		reverse+=var.front();
		var.pop();
	}

	return reverse;
}

int main()
{
	int numofInputs;

	std::cin>>numofInputs;

	int i=0;
	while(i<numofInputs)
	{
		std::string str;

		std::cin>>str;

		std::string ans=reversePolish(str);

		std::cout<<ans<<std::endl;
		++i;
	}

}