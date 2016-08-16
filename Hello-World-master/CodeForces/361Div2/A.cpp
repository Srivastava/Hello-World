#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>


bool check(const std::string& str)
{
	bool left=true,up=true,right=true,down=true;

	for(int i=0;i<str.size();++i)
	{
		int val=str[i]-'0';

		if(val ==1 || val==4 || val== 7 || val ==0)
		{
			left=false;
		}
	}

	if(left==true){return true;}

	for(int i=0;i<str.size();++i)
	{
		int val=str[i]-'0';

		if(val ==1 || val==2 || val== 3 )
		{
			up=false;
		}
	}

	if(up==true){return true;}

	for(int i=0;i<str.size();++i)
	{
		int val=str[i]-'0';

		if(val ==3 || val==6|| val== 9 || val ==0)
		{
			right=false;
		}
	}

	if(right==true){return true;}

	for(int i=0;i<str.size();++i)
	{
		int val=str[i]-'0';

		if(val ==7 || val==9 || val ==0)
		{
			down=false;
		}
	}

	if(down==true){return true;}
}

int main()
{
	int n;
	std::cin>>n;


	// while(n--)
	{
		std::string str;
		std::cin>>str;

		if(check(str))
		{
			std::cout<<"NO"<<std::endl;
		}
		else
		{
			std::cout<<"YES"<<std::endl;
		}
	}
	return 0;
}